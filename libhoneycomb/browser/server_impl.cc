// Copyright (c) 2017 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "libhoneycomb/browser/server_impl.h"

#include "libhoneycomb/browser/thread_util.h"
#include "libhoneycomb/common/request_impl.h"
#include "libhoneycomb/common/task_runner_impl.h"

#include "base/format_macros.h"
#include "base/functional/bind.h"
#include "base/memory/ptr_util.h"
#include "base/strings/stringprintf.h"
#include "base/task/thread_pool.h"
#include "base/threading/thread.h"
#include "net/base/net_errors.h"
#include "net/http/http_request_headers.h"
#include "net/server/http_server_request_info.h"
#include "net/server/http_server_response_info.h"
#include "net/socket/server_socket.h"
#include "net/socket/tcp_server_socket.h"
#include "net/traffic_annotation/network_traffic_annotation.h"

#define HONEYCOMB_CURRENTLY_ON_HT() CurrentlyOnHandlerThread()
#define HONEYCOMB_REQUIRE_HT() DCHECK(HONEYCOMB_CURRENTLY_ON_HT())

#define HONEYCOMB_REQUIRE_HT_RETURN(var)               \
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {                  \
    DCHECK(false) << "called on invalid thread"; \
    return var;                                  \
  }

#define HONEYCOMB_REQUIRE_HT_RETURN_VOID()             \
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {                  \
    DCHECK(false) << "called on invalid thread"; \
    return;                                      \
  }

#define HONEYCOMB_POST_TASK_HT(task) task_runner_->PostTask(FROM_HERE, task);

namespace {

// Wrap a string in a unique_ptr to avoid extra copies.
std::unique_ptr<std::string> CreateUniqueString(const void* data,
                                                size_t data_size) {
  std::unique_ptr<std::string> ptr;
  if (data && data_size > 0) {
    ptr.reset(new std::string(static_cast<const char*>(data), data_size));
  } else {
    ptr.reset(new std::string());
  }
  return ptr;
}

HoneycombRefPtr<HoneycombRequest> CreateRequest(const std::string& address,
                                    const net::HttpServerRequestInfo& info,
                                    bool is_websocket) {
  DCHECK(!address.empty());
  DCHECK(!info.method.empty());
  DCHECK(!info.path.empty());

  HoneycombRefPtr<HoneycombPostData> post_data;
  if (!info.data.empty()) {
    post_data = HoneycombPostData::Create();
    HoneycombRefPtr<HoneycombPostDataElement> post_element = HoneycombPostDataElement::Create();
    post_element->SetToBytes(info.data.size(), info.data.data());
    post_data->AddElement(post_element);
  }

  std::string referer;

  HoneycombRequest::HeaderMap header_map;
  if (!info.headers.empty()) {
    net::HttpServerRequestInfo::HeadersMap::const_iterator it =
        info.headers.begin();
    for (; it != info.headers.end(); ++it) {
      // Don't include Referer in the header map.
      if (base::EqualsCaseInsensitiveASCII(it->first,
                                           net::HttpRequestHeaders::kReferer)) {
        referer = it->second;
      } else {
        header_map.insert(std::make_pair(it->first, it->second));
      }
    }
  }

  HoneycombRefPtr<HoneycombRequestImpl> request = new HoneycombRequestImpl();
  request->Set((is_websocket ? "ws://" : "http://") + address + info.path,
               info.method, post_data, header_map);
  if (!referer.empty()) {
    request->SetReferrer(referer, REFERRER_POLICY_DEFAULT);
  }
  request->SetReadOnly(true);
  return request;
}

// Callback implementation for WebSocket acceptance. Always executes on the UI
// thread so we can avoid multiple execution by clearing the |impl_| reference.
class AcceptWebSocketCallback : public HoneycombCallback {
 public:
  AcceptWebSocketCallback(HoneycombRefPtr<HoneycombServerImpl> impl,
                          int connection_id,
                          net::HttpServerRequestInfo request_info)
      : impl_(impl),
        connection_id_(connection_id),
        request_info_(request_info) {}

  AcceptWebSocketCallback(const AcceptWebSocketCallback&) = delete;
  AcceptWebSocketCallback& operator=(const AcceptWebSocketCallback&) = delete;

  ~AcceptWebSocketCallback() override {
    if (impl_) {
      impl_->ContinueWebSocketRequest(connection_id_, request_info_, false);
    }
  }

  void Continue() override {
    if (!HONEYCOMB_CURRENTLY_ON_UIT()) {
      HONEYCOMB_POST_TASK(HONEYCOMB_UIT,
                    base::BindOnce(&AcceptWebSocketCallback::Continue, this));
      return;
    }
    if (!impl_) {
      return;
    }
    impl_->ContinueWebSocketRequest(connection_id_, request_info_, true);
    impl_ = nullptr;
  }

  void Cancel() override {
    if (!HONEYCOMB_CURRENTLY_ON_UIT()) {
      HONEYCOMB_POST_TASK(HONEYCOMB_UIT,
                    base::BindOnce(&AcceptWebSocketCallback::Cancel, this));
      return;
    }
    if (!impl_) {
      return;
    }
    impl_->ContinueWebSocketRequest(connection_id_, request_info_, false);
    impl_ = nullptr;
  }

 private:
  HoneycombRefPtr<HoneycombServerImpl> impl_;
  int connection_id_;
  net::HttpServerRequestInfo request_info_;

  IMPLEMENT_REFCOUNTING_DELETE_ON_UIT(AcceptWebSocketCallback);
};

}  // namespace

// HoneycombServer

// static
void HoneycombServer::CreateServer(const HoneycombString& address,
                             uint16_t port,
                             int backlog,
                             HoneycombRefPtr<HoneycombServerHandler> handler) {
  HoneycombRefPtr<HoneycombServerImpl> server(new HoneycombServerImpl(handler));
  server->Start(address, port, backlog);
}

// HoneycombServerImpl

struct HoneycombServerImpl::ConnectionInfo {
  ConnectionInfo() : is_websocket(false), is_websocket_pending(false) {}

  // True if this connection is a WebSocket connection.
  bool is_websocket;
  bool is_websocket_pending;
};

HoneycombServerImpl::HoneycombServerImpl(HoneycombRefPtr<HoneycombServerHandler> handler)
    : handler_(handler) {
  DCHECK(handler_);
}

void HoneycombServerImpl::Start(const std::string& address,
                          uint16_t port,
                          int backlog) {
  DCHECK(!address.empty());
  HONEYCOMB_POST_TASK(HONEYCOMB_UIT, base::BindOnce(&HoneycombServerImpl::StartOnUIThread, this,
                                        address, port, backlog));
}

HoneycombRefPtr<HoneycombTaskRunner> HoneycombServerImpl::GetTaskRunner() {
  if (task_runner_) {
    return new HoneycombTaskRunnerImpl(task_runner_);
  }
  return nullptr;
}

void HoneycombServerImpl::Shutdown() {
  HONEYCOMB_POST_TASK_HT(
      base::BindOnce(&HoneycombServerImpl::ShutdownOnHandlerThread, this));
}

bool HoneycombServerImpl::IsRunning() {
  HONEYCOMB_REQUIRE_HT_RETURN(false);
  return !!server_.get();
}

HoneycombString HoneycombServerImpl::GetAddress() {
  return address_;
}

bool HoneycombServerImpl::HasConnection() {
  HONEYCOMB_REQUIRE_HT_RETURN(false);
  return !connection_info_map_.empty();
}

bool HoneycombServerImpl::IsValidConnection(int connection_id) {
  HONEYCOMB_REQUIRE_HT_RETURN(false);
  return connection_info_map_.find(connection_id) != connection_info_map_.end();
}

void HoneycombServerImpl::SendHttp200Response(int connection_id,
                                        const HoneycombString& content_type,
                                        const void* data,
                                        size_t data_size) {
  SendHttp200ResponseInternal(connection_id, content_type,
                              CreateUniqueString(data, data_size));
}

void HoneycombServerImpl::SendHttp404Response(int connection_id) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::SendHttp404Response, this,
                                    connection_id));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  if (info->is_websocket) {
    LOG(ERROR) << "Invalid attempt to send HTTP response for connection_id "
               << connection_id;
    return;
  }

  server_->Send404(connection_id, MISSING_TRAFFIC_ANNOTATION);
  server_->Close(connection_id);
}

void HoneycombServerImpl::SendHttp500Response(int connection_id,
                                        const HoneycombString& error_message) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::SendHttp500Response, this,
                                    connection_id, error_message));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  if (info->is_websocket) {
    LOG(ERROR) << "Invalid attempt to send HTTP response for connection_id "
               << connection_id;
    return;
  }

  server_->Send500(connection_id, error_message, MISSING_TRAFFIC_ANNOTATION);
  server_->Close(connection_id);
}

void HoneycombServerImpl::SendHttpResponse(int connection_id,
                                     int response_code,
                                     const HoneycombString& content_type,
                                     int64_t content_length,
                                     const HeaderMap& extra_headers) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::SendHttpResponse, this,
                                    connection_id, response_code, content_type,
                                    content_length, extra_headers));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  if (info->is_websocket) {
    LOG(ERROR) << "Invalid attempt to send HTTP response for connection_id "
               << connection_id;
    return;
  }

  net::HttpServerResponseInfo response(
      static_cast<net::HttpStatusCode>(response_code));

  HeaderMap::const_iterator it = extra_headers.begin();
  for (; it != extra_headers.end(); ++it) {
    response.AddHeader(it->first, it->second);
  }

  response.AddHeader(net::HttpRequestHeaders::kContentType, content_type);
  if (content_length >= 0) {
    response.AddHeader(
        net::HttpRequestHeaders::kContentLength,
        base::StringPrintf("%" PRIuS, static_cast<size_t>(content_length)));
  }

  server_->SendResponse(connection_id, response, MISSING_TRAFFIC_ANNOTATION);
  if (content_length == 0) {
    server_->Close(connection_id);
  }
}

void HoneycombServerImpl::SendRawData(int connection_id,
                                const void* data,
                                size_t data_size) {
  if (!data || data_size == 0) {
    return;
  }
  SendRawDataInternal(connection_id, CreateUniqueString(data, data_size));
}

void HoneycombServerImpl::CloseConnection(int connection_id) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(
        base::BindOnce(&HoneycombServerImpl::CloseConnection, this, connection_id));
    return;
  }

  if (ValidateServer() && GetConnectionInfo(connection_id)) {
    server_->Close(connection_id);
  }
}

void HoneycombServerImpl::SendWebSocketMessage(int connection_id,
                                         const void* data,
                                         size_t data_size) {
  if (!data || data_size == 0) {
    return;
  }
  SendWebSocketMessageInternal(connection_id,
                               CreateUniqueString(data, data_size));
}

void HoneycombServerImpl::ContinueWebSocketRequest(
    int connection_id,
    const net::HttpServerRequestInfo& request_info,
    bool allow) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::ContinueWebSocketRequest,
                                    this, connection_id, request_info, allow));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  DCHECK(info);
  if (!info) {
    return;
  }

  DCHECK(info->is_websocket);
  DCHECK(info->is_websocket_pending);
  if (!info->is_websocket || !info->is_websocket_pending) {
    return;
  }

  info->is_websocket_pending = false;

  if (allow) {
    server_->AcceptWebSocket(connection_id, request_info,
                             MISSING_TRAFFIC_ANNOTATION);
    handler_->OnWebSocketConnected(this, connection_id);
  } else {
    server_->Close(connection_id);
  }
}

void HoneycombServerImpl::SendHttp200ResponseInternal(
    int connection_id,
    const HoneycombString& content_type,
    std::unique_ptr<std::string> data) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::SendHttp200ResponseInternal,
                                    this, connection_id, content_type,
                                    std::move(data)));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  if (info->is_websocket) {
    LOG(ERROR) << "Invalid attempt to send HTTP response for connection_id "
               << connection_id;
    return;
  }

  server_->Send200(connection_id, *data, content_type,
                   MISSING_TRAFFIC_ANNOTATION);
  server_->Close(connection_id);
}

void HoneycombServerImpl::SendRawDataInternal(int connection_id,
                                        std::unique_ptr<std::string> data) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::SendRawDataInternal, this,
                                    connection_id, std::move(data)));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  if (!GetConnectionInfo(connection_id)) {
    return;
  }

  server_->SendRaw(connection_id, *data, MISSING_TRAFFIC_ANNOTATION);
}

void HoneycombServerImpl::SendWebSocketMessageInternal(
    int connection_id,
    std::unique_ptr<std::string> data) {
  if (!HONEYCOMB_CURRENTLY_ON_HT()) {
    HONEYCOMB_POST_TASK_HT(
        base::BindOnce(&HoneycombServerImpl::SendWebSocketMessageInternal, this,
                       connection_id, std::move(data)));
    return;
  }

  if (!ValidateServer()) {
    return;
  }

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  if (!info->is_websocket || info->is_websocket_pending) {
    LOG(ERROR) << "Invalid attempt to send WebSocket message for connection_id "
               << connection_id;
    return;
  }

  server_->SendOverWebSocket(connection_id, *data, MISSING_TRAFFIC_ANNOTATION);
}

void HoneycombServerImpl::OnConnect(int connection_id) {
  HONEYCOMB_REQUIRE_HT();

  CreateConnectionInfo(connection_id);
  handler_->OnClientConnected(this, connection_id);
}

void HoneycombServerImpl::OnHttpRequest(
    int connection_id,
    const net::HttpServerRequestInfo& request_info) {
  HONEYCOMB_REQUIRE_HT();

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  DCHECK(info);
  if (!info) {
    return;
  }

  DCHECK(!info->is_websocket);

  handler_->OnHttpRequest(this, connection_id, request_info.peer.ToString(),
                          CreateRequest(address_, request_info, false));
}

void HoneycombServerImpl::OnWebSocketRequest(
    int connection_id,
    const net::HttpServerRequestInfo& request_info) {
  HONEYCOMB_REQUIRE_HT();

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  DCHECK(info);
  if (!info) {
    return;
  }

  DCHECK(!info->is_websocket);
  info->is_websocket = true;
  info->is_websocket_pending = true;

  // Will eventually result in a call to ContinueWebSocketRequest.
  HoneycombRefPtr<HoneycombCallback> callback =
      new AcceptWebSocketCallback(this, connection_id, request_info);
  handler_->OnWebSocketRequest(
      this, connection_id, request_info.peer.ToString(),
      CreateRequest(address_, request_info, true), callback);
}

void HoneycombServerImpl::OnWebSocketMessage(int connection_id, std::string data) {
  HONEYCOMB_REQUIRE_HT();

  ConnectionInfo* info = GetConnectionInfo(connection_id);
  if (!info) {
    return;
  }

  DCHECK(info->is_websocket);
  DCHECK(!info->is_websocket_pending);

  handler_->OnWebSocketMessage(this, connection_id, data.data(), data.size());
}

void HoneycombServerImpl::OnClose(int connection_id) {
  HONEYCOMB_REQUIRE_HT();

  RemoveConnectionInfo(connection_id);
  handler_->OnClientDisconnected(this, connection_id);
}

void HoneycombServerImpl::StartOnUIThread(const std::string& address,
                                    uint16_t port,
                                    int backlog) {
  HONEYCOMB_REQUIRE_UIT();
  DCHECK(!thread_);

  std::unique_ptr<base::Thread> thread(
      new base::Thread(base::StringPrintf("%s:%d", address.c_str(), port)));
  base::Thread::Options options;
  options.message_pump_type = base::MessagePumpType::IO;
  if (thread->StartWithOptions(std::move(options))) {
    // Add a reference that will be released in ShutdownOnUIThread().
    AddRef();

    thread_ = std::move(thread);
    task_runner_ = thread_->task_runner();

    HONEYCOMB_POST_TASK_HT(base::BindOnce(&HoneycombServerImpl::StartOnHandlerThread, this,
                                    address, port, backlog));
  }
}

void HoneycombServerImpl::StartOnHandlerThread(const std::string& address,
                                         uint16_t port,
                                         int backlog) {
  HONEYCOMB_REQUIRE_HT();

  std::unique_ptr<net::ServerSocket> socket(
      new net::TCPServerSocket(nullptr, net::NetLogSource()));
  if (socket->ListenWithAddressAndPort(address, port, backlog) == net::OK) {
    server_.reset(new net::HttpServer(std::move(socket), this));

    net::IPEndPoint ip_address;
    if (server_->GetLocalAddress(&ip_address) == net::OK) {
      address_ = ip_address.ToString();
    }
  }

  handler_->OnServerCreated(this);

  if (!server_) {
    // Server failed to start.
    handler_->OnServerDestroyed(this);

    HONEYCOMB_POST_TASK(HONEYCOMB_UIT,
                  base::BindOnce(&HoneycombServerImpl::ShutdownOnUIThread, this));
  }
}

void HoneycombServerImpl::ShutdownOnHandlerThread() {
  HONEYCOMB_REQUIRE_HT();

  if (server_) {
    // Stop the server.
    server_.reset();

    if (!connection_info_map_.empty()) {
      // Clear |connection_info_map_| first so any calls from
      // OnClientDisconnected will fail as expected.
      ConnectionInfoMap temp_map;
      temp_map.swap(connection_info_map_);

      // OnClose won't be called for clients that are connected when the server
      // shuts down, so send the disconnected notification here.
      ConnectionInfoMap::const_iterator it = temp_map.begin();
      for (; it != temp_map.end(); ++it) {
        handler_->OnClientDisconnected(this, it->first);
      }
    }

    handler_->OnServerDestroyed(this);
  }

  HONEYCOMB_POST_TASK(HONEYCOMB_UIT,
                base::BindOnce(&HoneycombServerImpl::ShutdownOnUIThread, this));
}

void HoneycombServerImpl::ShutdownOnUIThread() {
  HONEYCOMB_REQUIRE_UIT();

  handler_ = nullptr;

  if (thread_) {
    // Stop the handler thread as a background task so the UI thread isn't
    // blocked.
    auto task = base::BindOnce(
        [](std::unique_ptr<base::Thread> thread) {
          // Calling PlatformThread::Join() on the UI thread is otherwise
          // disallowed.
          base::ScopedAllowBaseSyncPrimitivesForTesting
              scoped_allow_sync_primitives;
          thread.reset();
        },
        std::move(thread_));

    // Make sure the task is executed on shutdown. Otherwise, |thread| might
    // be released outside of the correct scope.
    base::ThreadPool::PostTask(
        FROM_HERE,
        {base::TaskPriority::BEST_EFFORT,
         base::TaskShutdownBehavior::BLOCK_SHUTDOWN, base::MayBlock()},
        std::move(task));

    // Release the reference that was added in StartupOnUIThread().
    Release();
  }
}

bool HoneycombServerImpl::ValidateServer() const {
  HONEYCOMB_REQUIRE_HT();
  if (!server_) {
    LOG(ERROR) << "Server is not running";
    return false;
  }
  return true;
}

HoneycombServerImpl::ConnectionInfo* HoneycombServerImpl::CreateConnectionInfo(
    int connection_id) {
  HONEYCOMB_REQUIRE_HT();

#if DCHECK_IS_ON()
  ConnectionInfoMap::const_iterator it =
      connection_info_map_.find(connection_id);
  DCHECK(it == connection_info_map_.end());
#endif

  ConnectionInfo* info = new ConnectionInfo();
  connection_info_map_.insert(
      std::make_pair(connection_id, base::WrapUnique(info)));
  return info;
}

HoneycombServerImpl::ConnectionInfo* HoneycombServerImpl::GetConnectionInfo(
    int connection_id) const {
  HONEYCOMB_REQUIRE_HT();
  ConnectionInfoMap::const_iterator it =
      connection_info_map_.find(connection_id);
  if (it != connection_info_map_.end()) {
    return it->second.get();
  }

  LOG(ERROR) << "Invalid connection_id " << connection_id;
  return nullptr;
}

void HoneycombServerImpl::RemoveConnectionInfo(int connection_id) {
  HONEYCOMB_REQUIRE_HT();
  ConnectionInfoMap::iterator it = connection_info_map_.find(connection_id);
  DCHECK(it != connection_info_map_.end());
  if (it != connection_info_map_.end()) {
    connection_info_map_.erase(it);
  }
}

bool HoneycombServerImpl::CurrentlyOnHandlerThread() const {
  return task_runner_ && task_runner_->BelongsToCurrentThread();
}
