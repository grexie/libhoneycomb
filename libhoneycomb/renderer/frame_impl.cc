// Copyright (c) 2012 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "libhoneycomb/renderer/frame_impl.h"

#include "build/build_config.h"

// Enable deprecation warnings on Windows. See http://crbug.com/585142.
#if BUILDFLAG(IS_WIN)
#if defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic error "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(default : 4996)
#endif
#endif

#include "include/honey_urlrequest.h"
#include "libhoneycomb/common/app_manager.h"
#include "libhoneycomb/common/frame_util.h"
#include "libhoneycomb/common/net/http_header_utils.h"
#include "libhoneycomb/common/process_message_impl.h"
#include "libhoneycomb/common/process_message_smr_impl.h"
#include "libhoneycomb/common/request_impl.h"
#include "libhoneycomb/common/string_util.h"
#include "libhoneycomb/renderer/blink_glue.h"
#include "libhoneycomb/renderer/browser_impl.h"
#include "libhoneycomb/renderer/dom_document_impl.h"
#include "libhoneycomb/renderer/render_frame_util.h"
#include "libhoneycomb/renderer/thread_util.h"
#include "libhoneycomb/renderer/v8_impl.h"

#include "base/strings/stringprintf.h"
#include "base/strings/utf_string_conversions.h"
#include "content/renderer/render_frame_impl.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/lifecycle.mojom-blink.h"
#include "third_party/blink/public/platform/web_data.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/platform/web_url.h"
#include "third_party/blink/public/web/blink.h"
#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_document_loader.h"
#include "third_party/blink/public/web/web_frame_content_dumper.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_navigation_control.h"
#include "third_party/blink/public/web/web_script_source.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace {

// Maximum number of times to retry the browser connection.
constexpr size_t kConnectionRetryMaxCt = 3U;

// Length of time to wait before initiating a browser connection retry.
constexpr auto kConnectionRetryDelay = base::Seconds(1);

// Length of time to wait for the browser connection ACK before timing out.
constexpr auto kConnectionTimeout = base::Seconds(10);

}  // namespace

HoneycombFrameImpl::HoneycombFrameImpl(HoneycombBrowserImpl* browser,
                           blink::WebLocalFrame* frame,
                           int64_t frame_id)
    : browser_(browser), frame_(frame), frame_id_(frame_id) {}

HoneycombFrameImpl::~HoneycombFrameImpl() {}

bool HoneycombFrameImpl::IsValid() {
  HONEYCOMB_REQUIRE_RT_RETURN(false);

  return (frame_ != nullptr);
}

void HoneycombFrameImpl::Undo() {
  SendCommand("Undo");
}

void HoneycombFrameImpl::Redo() {
  SendCommand("Redo");
}

void HoneycombFrameImpl::Cut() {
  SendCommand("Cut");
}

void HoneycombFrameImpl::Copy() {
  SendCommand("Copy");
}

void HoneycombFrameImpl::Paste() {
  SendCommand("Paste");
}

void HoneycombFrameImpl::Delete() {
  SendCommand("Delete");
}

void HoneycombFrameImpl::SelectAll() {
  SendCommand("SelectAll");
}

void HoneycombFrameImpl::ViewSource() {
  DCHECK(false) << "ViewSource cannot be called from the renderer process";
}

void HoneycombFrameImpl::GetSource(HoneycombRefPtr<HoneycombStringVisitor> visitor) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();
  if (frame_) {
    HoneycombString content;
    string_util::GetHoneycombString(blink_glue::DumpDocumentMarkup(frame_), content);
    visitor->Visit(content);
  }
}

void HoneycombFrameImpl::GetText(HoneycombRefPtr<HoneycombStringVisitor> visitor) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();
  if (frame_) {
    HoneycombString content;
    string_util::GetHoneycombString(blink_glue::DumpDocumentText(frame_), content);
    visitor->Visit(content);
  }
}

void HoneycombFrameImpl::LoadRequest(HoneycombRefPtr<HoneycombRequest> request) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();

  if (!frame_) {
    return;
  }

  auto params = honey::mojom::RequestParams::New();
  static_cast<HoneycombRequestImpl*>(request.get())->Get(params);
  LoadRequest(std::move(params));
}

void HoneycombFrameImpl::LoadURL(const HoneycombString& url) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();

  if (!frame_) {
    return;
  }

  auto params = honey::mojom::RequestParams::New();
  params->url = GURL(url.ToString());
  params->method = "GET";
  LoadRequest(std::move(params));
}

void HoneycombFrameImpl::ExecuteJavaScript(const HoneycombString& jsCode,
                                     const HoneycombString& scriptUrl,
                                     int startLine) {
  SendJavaScript(jsCode, scriptUrl, startLine);
}

bool HoneycombFrameImpl::IsMain() {
  HONEYCOMB_REQUIRE_RT_RETURN(false);

  if (frame_) {
    return (frame_->Parent() == nullptr);
  }
  return false;
}

bool HoneycombFrameImpl::IsFocused() {
  HONEYCOMB_REQUIRE_RT_RETURN(false);

  if (frame_ && frame_->View()) {
    return (frame_->View()->FocusedFrame() == frame_);
  }
  return false;
}

HoneycombString HoneycombFrameImpl::GetName() {
  HoneycombString name;
  HONEYCOMB_REQUIRE_RT_RETURN(name);

  if (frame_) {
    name = render_frame_util::GetName(frame_);
  }
  return name;
}

int64_t HoneycombFrameImpl::GetIdentifier() {
  HONEYCOMB_REQUIRE_RT_RETURN(0);

  return frame_id_;
}

HoneycombRefPtr<HoneycombFrame> HoneycombFrameImpl::GetParent() {
  HONEYCOMB_REQUIRE_RT_RETURN(nullptr);

  if (frame_) {
    blink::WebFrame* parent = frame_->Parent();
    if (parent && parent->IsWebLocalFrame()) {
      return browser_->GetWebFrameImpl(parent->ToWebLocalFrame()).get();
    }
  }

  return nullptr;
}

HoneycombString HoneycombFrameImpl::GetURL() {
  HoneycombString url;
  HONEYCOMB_REQUIRE_RT_RETURN(url);

  if (frame_) {
    GURL gurl = frame_->GetDocument().Url();
    url = gurl.spec();
  }
  return url;
}

HoneycombRefPtr<HoneycombBrowser> HoneycombFrameImpl::GetBrowser() {
  HONEYCOMB_REQUIRE_RT_RETURN(nullptr);

  return browser_;
}

HoneycombRefPtr<HoneycombV8Context> HoneycombFrameImpl::GetV8Context() {
  HONEYCOMB_REQUIRE_RT_RETURN(nullptr);

  if (frame_) {
    v8::Isolate* isolate = blink::MainThreadIsolate();
    v8::HandleScope handle_scope(isolate);
    return new HoneycombV8ContextImpl(isolate, frame_->MainWorldScriptContext());
  } else {
    return nullptr;
  }
}

void HoneycombFrameImpl::VisitDOM(HoneycombRefPtr<HoneycombDOMVisitor> visitor) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();

  if (!frame_) {
    return;
  }

  // Create a HoneycombDOMDocumentImpl object that is valid only for the scope of this
  // method.
  HoneycombRefPtr<HoneycombDOMDocumentImpl> documentImpl;
  const blink::WebDocument& document = frame_->GetDocument();
  if (!document.IsNull()) {
    documentImpl = new HoneycombDOMDocumentImpl(browser_, frame_);
  }

  visitor->Visit(documentImpl.get());

  if (documentImpl.get()) {
    documentImpl->Detach();
  }
}

HoneycombRefPtr<HoneycombURLRequest> HoneycombFrameImpl::CreateURLRequest(
    HoneycombRefPtr<HoneycombRequest> request,
    HoneycombRefPtr<HoneycombURLRequestClient> client) {
  DCHECK(false) << "CreateURLRequest cannot be called from the render process";
  return nullptr;
}

void HoneycombFrameImpl::SendProcessMessage(HoneycombProcessId target_process,
                                      HoneycombRefPtr<HoneycombProcessMessage> message) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();
  DCHECK_EQ(PID_BROWSER, target_process);
  DCHECK(message && message->IsValid());
  if (!message || !message->IsValid()) {
    return;
  }

  if (message->GetArgumentList() != nullptr) {
    // Invalidate the message object immediately by taking the argument list.
    auto argument_list =
        static_cast<HoneycombProcessMessageImpl*>(message.get())->TakeArgumentList();
    SendToBrowserFrame(
        __FUNCTION__,
        base::BindOnce(
            [](const HoneycombString& name, base::Value::List argument_list,
               const BrowserFrameType& render_frame) {
              render_frame->SendMessage(name, std::move(argument_list));
            },
            message->GetName(), std::move(argument_list)));
  } else {
    auto region =
        static_cast<HoneycombProcessMessageSMRImpl*>(message.get())->TakeRegion();
    SendToBrowserFrame(
        __FUNCTION__,
        base::BindOnce(
            [](const HoneycombString& name, base::WritableSharedMemoryRegion region,
               const BrowserFrameType& render_frame) {
              render_frame->SendSharedMemoryRegion(name, std::move(region));
            },
            message->GetName(), std::move(region)));
  }
}

void HoneycombFrameImpl::OnAttached() {
  // Called indirectly from RenderFrameCreated.
  ConnectBrowserFrame(ConnectReason::RENDER_FRAME_CREATED);
}

void HoneycombFrameImpl::OnWasShown() {
  if (browser_connection_state_ == ConnectionState::DISCONNECTED) {
    // Reconnect a frame that has exited the bfcache.
    ConnectBrowserFrame(ConnectReason::WAS_SHOWN);
  }
}

void HoneycombFrameImpl::OnDidCommitProvisionalLoad() {
  did_commit_provisional_load_ = true;
  MaybeInitializeScriptContext();
}

void HoneycombFrameImpl::OnDidFinishLoad() {
  // Ignore notifications from the embedded frame hosting a mime-type plugin.
  // We'll eventually receive a notification from the owner frame.
  if (blink_glue::HasPluginFrameOwner(frame_)) {
    return;
  }

  if (!blink::RuntimeEnabledFeatures::BackForwardCacheEnabled() && IsMain()) {
    // Refresh draggable regions. Otherwise, we may not receive updated regions
    // after navigation because LocalFrameView::UpdateDocumentAnnotatedRegion
    // lacks sufficient context. When bfcache is disabled we use this method
    // instead of DidStopLoading() because it provides more accurate timing.
    OnDraggableRegionsChanged();
  }

  blink::WebDocumentLoader* dl = frame_->GetDocumentLoader();
  const int http_status_code = dl->GetWebResponse().HttpStatusCode();

  HoneycombRefPtr<HoneycombApp> app = HoneycombAppManager::Get()->GetApplication();
  if (app) {
    HoneycombRefPtr<HoneycombRenderProcessHandler> handler = app->GetRenderProcessHandler();
    if (handler) {
      HoneycombRefPtr<HoneycombLoadHandler> load_handler = handler->GetLoadHandler();
      if (load_handler) {
        load_handler->OnLoadEnd(browser_, this, http_status_code);
      }
    }
  }
}

void HoneycombFrameImpl::OnDraggableRegionsChanged() {
  // Match the behavior in ChromeRenderFrameObserver::DraggableRegionsChanged.
  // Only the main frame is allowed to control draggable regions, to avoid other
  // frames manipulate the regions in the browser process.
  if (frame_->Parent() != nullptr) {
    return;
  }

  blink::WebVector<blink::WebDraggableRegion> webregions =
      frame_->GetDocument().DraggableRegions();
  std::vector<honey::mojom::DraggableRegionEntryPtr> regions;
  if (!webregions.empty()) {
    auto render_frame = content::RenderFrameImpl::FromWebFrame(frame_);

    regions.reserve(webregions.size());
    for (const auto& webregion : webregions) {
      auto region = honey::mojom::DraggableRegionEntry::New(webregion.bounds,
                                                          webregion.draggable);
      render_frame->ConvertViewportToWindow(&region->bounds);
      regions.push_back(std::move(region));
    }
  }

  using RegionsArg =
      absl::optional<std::vector<honey::mojom::DraggableRegionEntryPtr>>;
  RegionsArg regions_arg =
      regions.empty() ? absl::nullopt : absl::make_optional(std::move(regions));

  SendToBrowserFrame(
      __FUNCTION__,
      base::BindOnce(
          [](RegionsArg regions_arg, const BrowserFrameType& browser_frame) {
            browser_frame->UpdateDraggableRegions(std::move(regions_arg));
          },
          std::move(regions_arg)));
}

void HoneycombFrameImpl::OnContextCreated(v8::Local<v8::Context> context) {
  context_created_ = true;

  CHECK(frame_);
  while (!queued_context_actions_.empty()) {
    auto& action = queued_context_actions_.front();
    std::move(action.second).Run(frame_);
    queued_context_actions_.pop();
  }

  execution_context_lifecycle_state_observer_ =
      blink_glue::RegisterExecutionContextLifecycleStateObserver(context, this);
}

void HoneycombFrameImpl::OnContextReleased() {
  execution_context_lifecycle_state_observer_.reset();
}

void HoneycombFrameImpl::OnDetached() {
  // Called when this frame has been detached from the view. This *will* be
  // called for child frames when a parent frame is detached.
  // The browser may hold the last reference to |this|. Take a reference here to
  // keep |this| alive until after this method returns.
  HoneycombRefPtr<HoneycombFrameImpl> self = this;

  frame_ = nullptr;

  browser_->FrameDetached(frame_id_);

  OnDisconnect(DisconnectReason::DETACHED);

  browser_ = nullptr;

  // In case we never attached.
  while (!queued_browser_actions_.empty()) {
    auto& action = queued_browser_actions_.front();
    LOG(WARNING) << action.first << " sent to detached " << GetDebugString()
                 << " will be ignored";
    queued_browser_actions_.pop();
  }

  // In case we're destroyed without the context being created.
  while (!queued_context_actions_.empty()) {
    auto& action = queued_context_actions_.front();
    LOG(WARNING) << action.first << " sent to detached " << GetDebugString()
                 << " will be ignored";
    queued_context_actions_.pop();
  }
}

void HoneycombFrameImpl::ExecuteOnLocalFrame(const std::string& function_name,
                                       LocalFrameAction action) {
  HONEYCOMB_REQUIRE_RT_RETURN_VOID();

  if (!context_created_) {
    queued_context_actions_.push(
        std::make_pair(function_name, std::move(action)));
    MaybeInitializeScriptContext();
    return;
  }

  if (frame_) {
    std::move(action).Run(frame_);
  } else {
    LOG(WARNING) << function_name << " sent to detached " << GetDebugString()
                 << " will be ignored";
  }
}

void HoneycombFrameImpl::ConnectBrowserFrame(ConnectReason reason) {
  DCHECK(browser_connection_state_ == ConnectionState::DISCONNECTED ||
         browser_connection_state_ == ConnectionState::RECONNECT_PENDING);

  if (VLOG_IS_ON(1)) {
    std::string reason_str;
    switch (reason) {
      case ConnectReason::RENDER_FRAME_CREATED:
        reason_str = "RENDER_FRAME_CREATED";
        break;
      case ConnectReason::WAS_SHOWN:
        reason_str = "WAS_SHOWN";
        break;
      case ConnectReason::RETRY:
        reason_str = base::StringPrintf(
            "RETRY %zu/%zu", browser_connect_retry_ct_, kConnectionRetryMaxCt);
        break;
    }
    VLOG(1) << GetDebugString() << " connection request (reason=" << reason_str
            << ")";
  }

  // Don't attempt to connect an invalid or bfcache'd frame. If a bfcache'd
  // frame returns to active status a reconnect will be triggered via
  // OnWasShown().
  if (!frame_ || blink_glue::IsInBackForwardCache(frame_)) {
    browser_connection_state_ = ConnectionState::DISCONNECTED;
    browser_connect_timer_.Stop();
    VLOG(1) << GetDebugString() << " connection retry canceled (reason="
            << (frame_ ? "BFCACHED" : "INVALID") << ")";
    return;
  }

  browser_connection_state_ = ConnectionState::CONNECTION_PENDING;
  browser_connect_timer_.Start(FROM_HERE, kConnectionTimeout, this,
                               &HoneycombFrameImpl::OnBrowserFrameTimeout);

  auto& browser_frame = GetBrowserFrame(/*expect_acked=*/false);
  CHECK(browser_frame);

  // True if this connection is a retry or if the frame just exited the
  // BackForwardCache.
  const bool reattached =
      browser_connect_retry_ct_ > 0 || reason == ConnectReason::WAS_SHOWN;

  // If the channel is working we should get a call to FrameAttachedAck().
  // Otherwise, OnDisconnect() should be called to retry the
  // connection.
  browser_frame->FrameAttached(receiver_.BindNewPipeAndPassRemote(),
                               reattached);
  receiver_.set_disconnect_handler(
      base::BindOnce(&HoneycombFrameImpl::OnDisconnect, this,
                     DisconnectReason::RENDER_FRAME_DISCONNECT));
}

const mojo::Remote<honey::mojom::BrowserFrame>& HoneycombFrameImpl::GetBrowserFrame(
    bool expect_acked) {
  DCHECK_EQ(expect_acked,
            browser_connection_state_ == ConnectionState::CONNECTION_ACKED);

  if (!browser_frame_.is_bound()) {
    auto render_frame = content::RenderFrameImpl::FromWebFrame(frame_);
    if (render_frame) {
      // Triggers creation of a HoneycombBrowserFrame in the browser process.
      render_frame->GetBrowserInterfaceBroker()->GetInterface(
          browser_frame_.BindNewPipeAndPassReceiver());
      browser_frame_.set_disconnect_handler(
          base::BindOnce(&HoneycombFrameImpl::OnDisconnect, this,
                         DisconnectReason::BROWSER_FRAME_DISCONNECT));
    }
  }
  return browser_frame_;
}

void HoneycombFrameImpl::OnBrowserFrameTimeout() {
  LOG(ERROR) << GetDebugString() << " connection timeout";
  OnDisconnect(DisconnectReason::CONNECT_TIMEOUT);
}

void HoneycombFrameImpl::OnDisconnect(DisconnectReason reason) {
  // Ignore multiple calls in close proximity (which may occur if both
  // |browser_frame_| and |receiver_| disconnect). |frame_| will be nullptr
  // when called from/after OnDetached().
  if (frame_ &&
      browser_connection_state_ == ConnectionState::RECONNECT_PENDING) {
    return;
  }

  if (VLOG_IS_ON(1)) {
    std::string reason_str;
    switch (reason) {
      case DisconnectReason::DETACHED:
        reason_str = "DETACHED";
        break;
      case DisconnectReason::BROWSER_FRAME_DETACHED:
        reason_str = "BROWSER_FRAME_DETACHED";
        break;
      case DisconnectReason::CONNECT_TIMEOUT:
        reason_str = "CONNECT_TIMEOUT";
        break;
      case DisconnectReason::RENDER_FRAME_DISCONNECT:
        reason_str = "RENDER_FRAME_DISCONNECT";
        break;
      case DisconnectReason::BROWSER_FRAME_DISCONNECT:
        reason_str = "BROWSER_FRAME_DISCONNECT";
        break;
    };

    std::string state_str;
    switch (browser_connection_state_) {
      case ConnectionState::DISCONNECTED:
        state_str = "DISCONNECTED";
        break;
      case ConnectionState::CONNECTION_PENDING:
        state_str = "CONNECTION_PENDING";
        break;
      case ConnectionState::CONNECTION_ACKED:
        state_str = "CONNECTION_ACKED";
        break;
      case ConnectionState::RECONNECT_PENDING:
        state_str = "RECONNECT_PENDING";
        break;
    }

    if (!frame_) {
      state_str += ", FRAME_INVALID";
    }

    VLOG(1) << GetDebugString() << " disconnected (reason=" << reason_str
            << ", current_state=" << state_str << ")";
  }

  browser_frame_.reset();
  receiver_.reset();
  browser_connection_state_ = ConnectionState::DISCONNECTED;
  browser_connect_timer_.Stop();

  // Only retry if the frame is still valid and the browser process has not
  // intentionally detached.
  if (frame_ && reason != DisconnectReason::BROWSER_FRAME_DETACHED) {
    if (browser_connect_retry_ct_++ < kConnectionRetryMaxCt) {
      VLOG(1) << GetDebugString() << " connection retry scheduled";

      // Retry after a delay in case the frame is currently navigating, being
      // destroyed, or entering the bfcache. In the navigation case the retry
      // will likely succeed. In the destruction case the retry will be
      // ignored/canceled due to OnDetached(). In the bfcache case the status
      // may not be updated immediately, so we allow the reconnect timer to
      // trigger and check the status in ConnectBrowserFrame() instead.
      browser_connection_state_ = ConnectionState::RECONNECT_PENDING;
      browser_connect_timer_.Start(
          FROM_HERE, kConnectionRetryDelay,
          base::BindOnce(&HoneycombFrameImpl::ConnectBrowserFrame, this,
                         ConnectReason::RETRY));
    } else {
      // Trigger a crash in official builds.
      LOG(FATAL) << GetDebugString() << " connection retry failed";
    }
  }
}

void HoneycombFrameImpl::SendToBrowserFrame(const std::string& function_name,
                                      BrowserFrameAction action) {
  if (!frame_) {
    // We've been detached.
    LOG(WARNING) << function_name << " sent to detached " << GetDebugString()
                 << " will be ignored";
    return;
  }

  if (browser_connection_state_ != ConnectionState::CONNECTION_ACKED) {
    // Queue actions until we're notified by the browser that it's ready to
    // handle them.
    queued_browser_actions_.push(
        std::make_pair(function_name, std::move(action)));
    return;
  }

  auto& browser_frame = GetBrowserFrame();
  CHECK(browser_frame);

  std::move(action).Run(browser_frame);
}

void HoneycombFrameImpl::MaybeInitializeScriptContext() {
  if (did_initialize_script_context_) {
    return;
  }

  if (!did_commit_provisional_load_) {
    // Too soon for context initialization.
    return;
  }

  if (queued_context_actions_.empty()) {
    // Don't need early context initialization. Avoid it due to performance
    // consequences.
    return;
  }

  did_initialize_script_context_ = true;

  // Explicitly force creation of the script context. This occurred implicitly
  // via DidCommitProvisionalLoad prior to https://crrev.com/5150754880a.
  // Otherwise, a script context may never be created for a frame that doesn't
  // contain JS code.
  v8::HandleScope handle_scope(blink::MainThreadIsolate());
  frame_->MainWorldScriptContext();
}

void HoneycombFrameImpl::FrameAttachedAck() {
  // Sent from the browser process in response to ConnectBrowserFrame() sending
  // FrameAttached().
  CHECK_EQ(ConnectionState::CONNECTION_PENDING, browser_connection_state_);
  browser_connection_state_ = ConnectionState::CONNECTION_ACKED;
  browser_connect_retry_ct_ = 0;
  browser_connect_timer_.Stop();

  auto& browser_frame = GetBrowserFrame();
  CHECK(browser_frame);

  while (!queued_browser_actions_.empty()) {
    std::move(queued_browser_actions_.front().second).Run(browser_frame);
    queued_browser_actions_.pop();
  }
}

void HoneycombFrameImpl::FrameDetached() {
  // Sent from the browser process in response to HoneycombFrameHostImpl::Detach().
  CHECK_EQ(ConnectionState::CONNECTION_ACKED, browser_connection_state_);
  OnDisconnect(DisconnectReason::BROWSER_FRAME_DETACHED);
}

void HoneycombFrameImpl::SendMessage(const std::string& name,
                               base::Value::List arguments) {
  if (auto app = HoneycombAppManager::Get()->GetApplication()) {
    if (auto handler = app->GetRenderProcessHandler()) {
      HoneycombRefPtr<HoneycombProcessMessageImpl> message(
          new HoneycombProcessMessageImpl(name, std::move(arguments),
                                    /*read_only=*/true));
      handler->OnProcessMessageReceived(browser_, this, PID_BROWSER,
                                        message.get());
    }
  }
}

void HoneycombFrameImpl::SendSharedMemoryRegion(
    const std::string& name,
    base::WritableSharedMemoryRegion region) {
  if (auto app = HoneycombAppManager::Get()->GetApplication()) {
    if (auto handler = app->GetRenderProcessHandler()) {
      HoneycombRefPtr<HoneycombProcessMessage> message(
          new HoneycombProcessMessageSMRImpl(name, std::move(region)));
      handler->OnProcessMessageReceived(browser_, this, PID_BROWSER, message);
    }
  }
}

void HoneycombFrameImpl::SendCommand(const std::string& command) {
  ExecuteOnLocalFrame(
      __FUNCTION__,
      base::BindOnce(
          [](const std::string& command, blink::WebLocalFrame* frame) {
            frame->ExecuteCommand(blink::WebString::FromUTF8(command));
          },
          command));
}

void HoneycombFrameImpl::SendCommandWithResponse(
    const std::string& command,
    honey::mojom::RenderFrame::SendCommandWithResponseCallback callback) {
  ExecuteOnLocalFrame(
      __FUNCTION__,
      base::BindOnce(
          [](const std::string& command,
             honey::mojom::RenderFrame::SendCommandWithResponseCallback callback,
             blink::WebLocalFrame* frame) {
            blink::WebString response;

            if (base::EqualsCaseInsensitiveASCII(command, "getsource")) {
              response = blink_glue::DumpDocumentMarkup(frame);
            } else if (base::EqualsCaseInsensitiveASCII(command, "gettext")) {
              response = blink_glue::DumpDocumentText(frame);
            }

            std::move(callback).Run(
                string_util::CreateSharedMemoryRegion(response));
          },
          command, std::move(callback)));
}

void HoneycombFrameImpl::SendJavaScript(const std::u16string& jsCode,
                                  const std::string& scriptUrl,
                                  int32_t startLine) {
  ExecuteOnLocalFrame(
      __FUNCTION__,
      base::BindOnce(
          [](const std::u16string& jsCode, const std::string& scriptUrl,
             blink::WebLocalFrame* frame) {
            frame->ExecuteScript(blink::WebScriptSource(
                blink::WebString::FromUTF16(jsCode), GURL(scriptUrl)));
          },
          jsCode, scriptUrl));
}

void HoneycombFrameImpl::LoadRequest(honey::mojom::RequestParamsPtr params) {
  ExecuteOnLocalFrame(
      __FUNCTION__,
      base::BindOnce(
          [](honey::mojom::RequestParamsPtr params, blink::WebLocalFrame* frame) {
            blink::WebURLRequest request;
            HoneycombRequestImpl::Get(params, request);
            blink_glue::StartNavigation(frame, request);
          },
          std::move(params)));
}

void HoneycombFrameImpl::DidStopLoading() {
  // We should only receive this notification for the highest-level LocalFrame
  // in this frame's in-process subtree. If there are multiple of these for
  // the same browser then the other occurrences will be discarded in
  // OnLoadingStateChange.
  browser_->OnLoadingStateChange(false);

  if (blink::RuntimeEnabledFeatures::BackForwardCacheEnabled()) {
    // Refresh draggable regions. Otherwise, we may not receive updated regions
    // after navigation because LocalFrameView::UpdateDocumentAnnotatedRegion
    // lacks sufficient context. When bfcache is enabled we can't rely on
    // OnDidFinishLoad() as the frame may not actually be reloaded.
    OnDraggableRegionsChanged();
  }
}

void HoneycombFrameImpl::MoveOrResizeStarted() {
  if (frame_) {
    auto web_view = frame_->View();
    if (web_view) {
      web_view->CancelPagePopup();
    }
  }
}

void HoneycombFrameImpl::ContextLifecycleStateChanged(
    blink::mojom::blink::FrameLifecycleState state) {
  if (state == blink::mojom::FrameLifecycleState::kFrozen && IsMain() &&
      blink_glue::IsInBackForwardCache(frame_)) {
    browser_->OnEnterBFCache();
  }
}

std::string HoneycombFrameImpl::GetDebugString() const {
  return "frame " + frame_util::GetFrameDebugString(frame_id_);
}

// Enable deprecation warnings on Windows. See http://crbug.com/585142.
#if BUILDFLAG(IS_WIN)
#if defined(__clang__)
#pragma GCC diagnostic pop
#else
#pragma warning(pop)
#endif
#endif
