// Copyright (c) 2008-2009 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include <algorithm>
#include <limits>
#include <string>
#include <utility>
#include <vector>

#include "libhoney/common/net/http_header_utils.h"
#include "libhoney/common/net_service/net_service_util.h"
#include "libhoney/common/request_impl.h"

#include "base/command_line.h"
#include "base/logging.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/navigation_handle.h"
#include "content/public/common/content_switches.h"
#include "net/base/elements_upload_data_stream.h"
#include "net/base/load_flags.h"
#include "net/base/upload_bytes_element_reader.h"
#include "net/base/upload_data_stream.h"
#include "net/base/upload_element_reader.h"
#include "net/base/upload_file_element_reader.h"
#include "net/http/http_request_headers.h"
#include "net/http/http_util.h"
#include "net/url_request/redirect_info.h"
#include "net/url_request/referrer_policy.h"
#include "services/network/public/cpp/data_element.h"
#include "services/network/public/cpp/network_switches.h"
#include "services/network/public/cpp/resource_request.h"
#include "services/network/public/cpp/resource_request_body.h"
#include "third_party/blink/public/mojom/fetch/fetch_api_request.mojom-shared.h"
#include "third_party/blink/public/platform/web_http_body.h"
#include "third_party/blink/public/platform/web_security_origin.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/platform/web_url.h"
#include "third_party/blink/public/platform/web_url_error.h"
#include "third_party/blink/public/platform/web_url_request.h"
#include "third_party/blink/public/platform/web_url_request_util.h"
#include "third_party/blink/public/web/web_security_policy.h"

namespace {

const char kCacheControlDirectiveNoCache[] = "no-cache";
const char kCacheControlDirectiveNoStore[] = "no-store";
const char kCacheControlDirectiveOnlyIfCached[] = "only-if-cached";

// Mask of values that configure the cache policy.
const int kURCachePolicyMask =
    (UR_FLAG_SKIP_CACHE | UR_FLAG_ONLY_FROM_CACHE | UR_FLAG_DISABLE_CACHE);

// Returns the honey_urlrequest_flags_t policy specified by the Cache-Control
// request header directives, if any. The directives are case-insensitive and
// some have an optional argument. Multiple directives are comma-separated.
// See https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Cache-Control
// for details.
int GetCacheControlHeaderPolicy(HoneycombRequest::HeaderMap headerMap) {
  std::string line;

  // Extract the Cache-Control header line.
  {
    HoneycombRequest::HeaderMap::const_iterator it = headerMap.begin();
    for (; it != headerMap.end(); ++it) {
      if (base::EqualsCaseInsensitiveASCII(
              it->first.ToString(), net::HttpRequestHeaders::kCacheControl)) {
        line = it->second;
        break;
      }
    }
  }

  int flags = 0;

  if (!line.empty()) {
    HttpHeaderUtils::MakeASCIILower(&line);

    std::vector<base::StringPiece> pieces = base::SplitStringPiece(
        line, ",", base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
    for (const auto& piece : pieces) {
      if (base::EqualsCaseInsensitiveASCII(piece,
                                           kCacheControlDirectiveNoCache)) {
        flags |= UR_FLAG_SKIP_CACHE;
      } else if (base::EqualsCaseInsensitiveASCII(
                     piece, kCacheControlDirectiveOnlyIfCached)) {
        flags |= UR_FLAG_ONLY_FROM_CACHE;
      } else if (base::EqualsCaseInsensitiveASCII(
                     piece, kCacheControlDirectiveNoStore)) {
        flags |= UR_FLAG_DISABLE_CACHE;
      }
    }
  }

  return flags;
}

// Convert honey_urlrequest_flags_t to blink::WebCachePolicy.
blink::mojom::FetchCacheMode GetFetchCacheMode(int ur_flags) {
  const bool skip_cache{!!(ur_flags & UR_FLAG_SKIP_CACHE)};
  const bool only_from_cache{!!(ur_flags & UR_FLAG_ONLY_FROM_CACHE)};
  const bool disable_cache{!!(ur_flags & UR_FLAG_DISABLE_CACHE)};
  if (only_from_cache && (skip_cache || disable_cache)) {
    // The request will always fail because only_from_cache and
    // skip_cache/disable_cache are mutually exclusive.
    return blink::mojom::FetchCacheMode::kUnspecifiedForceCacheMiss;
  } else if (disable_cache) {
    // This additionally implies the skip_cache behavior.
    return blink::mojom::FetchCacheMode::kNoStore;
  } else if (skip_cache) {
    return blink::mojom::FetchCacheMode::kBypassCache;
  } else if (only_from_cache) {
    return blink::mojom::FetchCacheMode::kOnlyIfCached;
  }
  return blink::mojom::FetchCacheMode::kDefault;
}

// Read |headers| into |map|.
void GetHeaderMap(const net::HttpRequestHeaders& headers,
                  HoneycombRequest::HeaderMap& map) {
  map.clear();

  if (headers.IsEmpty()) {
    return;
  }

  net::HttpRequestHeaders::Iterator it(headers);
  while (it.GetNext()) {
    const std::string& name = it.name();

    // Do not include Referer in the header map.
    if (!base::EqualsCaseInsensitiveASCII(name,
                                          net::HttpRequestHeaders::kReferer)) {
      map.insert(std::make_pair(name, it.value()));
    }
  };
}

// Read |source| into |map|.
void GetHeaderMap(const HoneycombRequest::HeaderMap& source,
                  HoneycombRequest::HeaderMap& map) {
  map.clear();

  HoneycombRequest::HeaderMap::const_iterator it = source.begin();
  for (; it != source.end(); ++it) {
    const HoneycombString& name = it->first;

    // Do not include Referer in the header map.
    if (!base::EqualsCaseInsensitiveASCII(name.ToString(),
                                          net::HttpRequestHeaders::kReferer)) {
      map.insert(std::make_pair(name, it->second));
    }
  }
}

}  // namespace

#define CHECK_READONLY_RETURN(val)          \
  if (read_only_) {                         \
    DCHECK(false) << "object is read only"; \
    return val;                             \
  }

#define CHECK_READONLY_RETURN_VOID()        \
  if (read_only_) {                         \
    DCHECK(false) << "object is read only"; \
    return;                                 \
  }

#define SETBOOLFLAG(obj, flags, method, FLAG) \
  obj.method((flags & (FLAG)) == (FLAG))

// HoneycombRequest -----------------------------------------------------------------

// static
HoneycombRefPtr<HoneycombRequest> HoneycombRequest::Create() {
  HoneycombRefPtr<HoneycombRequest> request(new HoneycombRequestImpl());
  return request;
}

// HoneycombRequestImpl -------------------------------------------------------------

HoneycombRequestImpl::HoneycombRequestImpl() {
  // Verify that our enum matches Chromium's values.
  static_assert(static_cast<int>(REFERRER_POLICY_LAST_VALUE) ==
                    static_cast<int>(net::ReferrerPolicy::MAX),
                "enum mismatch");

  base::AutoLock lock_scope(lock_);
  Reset();
}

bool HoneycombRequestImpl::IsReadOnly() {
  base::AutoLock lock_scope(lock_);
  return read_only_;
}

HoneycombString HoneycombRequestImpl::GetURL() {
  base::AutoLock lock_scope(lock_);
  return url_.spec();
}

void HoneycombRequestImpl::SetURL(const HoneycombString& url) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  const GURL& new_url = GURL(url.ToString());
  if (url_ != new_url) {
    Changed(kChangedUrl);
    url_ = new_url;
  }
}

HoneycombString HoneycombRequestImpl::GetMethod() {
  base::AutoLock lock_scope(lock_);
  return method_;
}

void HoneycombRequestImpl::SetMethod(const HoneycombString& method) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  const std::string& new_method = method;
  if (method_ != new_method) {
    Changed(kChangedMethod);
    method_ = new_method;
  }
}

void HoneycombRequestImpl::SetReferrer(const HoneycombString& referrer_url,
                                 ReferrerPolicy policy) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  const auto& sanitized_referrer = content::Referrer::SanitizeForRequest(
      url_, content::Referrer(GURL(referrer_url.ToString()),
                              NetReferrerPolicyToBlinkReferrerPolicy(policy)));
  const auto sanitized_policy =
      BlinkReferrerPolicyToNetReferrerPolicy(sanitized_referrer.policy);

  if (referrer_url_ != sanitized_referrer.url ||
      referrer_policy_ != sanitized_policy) {
    Changed(kChangedReferrer);
    referrer_url_ = sanitized_referrer.url;
    referrer_policy_ = sanitized_policy;
  }
}

HoneycombString HoneycombRequestImpl::GetReferrerURL() {
  base::AutoLock lock_scope(lock_);
  return referrer_url_.spec();
}

HoneycombRequestImpl::ReferrerPolicy HoneycombRequestImpl::GetReferrerPolicy() {
  base::AutoLock lock_scope(lock_);
  return referrer_policy_;
}

HoneycombRefPtr<HoneycombPostData> HoneycombRequestImpl::GetPostData() {
  base::AutoLock lock_scope(lock_);
  return postdata_;
}

void HoneycombRequestImpl::SetPostData(HoneycombRefPtr<HoneycombPostData> postData) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  Changed(kChangedPostData);
  postdata_ = postData;
}

void HoneycombRequestImpl::GetHeaderMap(HeaderMap& headerMap) {
  base::AutoLock lock_scope(lock_);
  headerMap = headermap_;
}

void HoneycombRequestImpl::SetHeaderMap(const HeaderMap& headerMap) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  Changed(kChangedHeaderMap);
  ::GetHeaderMap(headerMap, headermap_);
}

HoneycombString HoneycombRequestImpl::GetHeaderByName(const HoneycombString& name) {
  base::AutoLock lock_scope(lock_);

  std::string nameLower = name;
  HttpHeaderUtils::MakeASCIILower(&nameLower);

  auto it = HttpHeaderUtils::FindHeaderInMap(nameLower, headermap_);
  if (it != headermap_.end()) {
    return it->second;
  }

  return HoneycombString();
}

void HoneycombRequestImpl::SetHeaderByName(const HoneycombString& name,
                                     const HoneycombString& value,
                                     bool overwrite) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  const std::string& nameStr = name;

  // Do not include Referer in the header map.
  if (base::EqualsCaseInsensitiveASCII(nameStr,
                                       net::HttpRequestHeaders::kReferer)) {
    return;
  }

  Changed(kChangedHeaderMap);

  // There may be multiple values, so remove any first.
  for (auto it = headermap_.begin(); it != headermap_.end();) {
    if (base::EqualsCaseInsensitiveASCII(it->first.ToString(), nameStr)) {
      if (!overwrite) {
        return;
      }
      it = headermap_.erase(it);
    } else {
      ++it;
    }
  }

  headermap_.insert(std::make_pair(name, value));
}

void HoneycombRequestImpl::Set(const HoneycombString& url,
                         const HoneycombString& method,
                         HoneycombRefPtr<HoneycombPostData> postData,
                         const HeaderMap& headerMap) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  const GURL& new_url = GURL(url.ToString());
  if (url_ != new_url) {
    Changed(kChangedUrl);
    url_ = new_url;
  }
  const std::string& new_method = method;
  if (method_ != new_method) {
    Changed(kChangedMethod);
    method_ = new_method;
  }
  if (postdata_ != postData) {
    Changed(kChangedPostData);
    postdata_ = postData;
  }
  Changed(kChangedHeaderMap);
  ::GetHeaderMap(headerMap, headermap_);
}

int HoneycombRequestImpl::GetFlags() {
  base::AutoLock lock_scope(lock_);
  return flags_;
}

void HoneycombRequestImpl::SetFlags(int flags) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  if (flags_ != flags) {
    Changed(kChangedFlags);
    flags_ = flags;
  }
}

HoneycombString HoneycombRequestImpl::GetFirstPartyForCookies() {
  base::AutoLock lock_scope(lock_);
  return site_for_cookies_.RepresentativeUrl().spec();
}

void HoneycombRequestImpl::SetFirstPartyForCookies(const HoneycombString& url) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  auto new_site = net::SiteForCookies::FromUrl(GURL(url.ToString()));
  if (!new_site.IsEquivalent(site_for_cookies_)) {
    Changed(kChangedSiteForCookies);
    site_for_cookies_ = new_site;
  }
}

HoneycombRequestImpl::ResourceType HoneycombRequestImpl::GetResourceType() {
  base::AutoLock lock_scope(lock_);
  return resource_type_;
}

HoneycombRequestImpl::TransitionType HoneycombRequestImpl::GetTransitionType() {
  base::AutoLock lock_scope(lock_);
  return transition_type_;
}

uint64_t HoneycombRequestImpl::GetIdentifier() {
  base::AutoLock lock_scope(lock_);
  return identifier_;
}

void HoneycombRequestImpl::Set(const network::ResourceRequest* request,
                         uint64_t identifier) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  Reset();

  url_ = request->url;
  method_ = request->method;
  identifier_ = identifier;

  if (request->referrer.is_valid()) {
    const auto& sanitized_referrer = content::Referrer::SanitizeForRequest(
        request->url,
        content::Referrer(
            request->referrer,
            NetReferrerPolicyToBlinkReferrerPolicy(
                static_cast<honey_referrer_policy_t>(request->referrer_policy))));
    referrer_url_ = sanitized_referrer.url;
    referrer_policy_ =
        BlinkReferrerPolicyToNetReferrerPolicy(sanitized_referrer.policy);
  }

  // Transfer request headers.
  ::GetHeaderMap(request->headers, headermap_);

  // Transfer post data, if any.
  if (request->request_body) {
    postdata_ = HoneycombPostData::Create();
    static_cast<HoneycombPostDataImpl*>(postdata_.get())->Set(*request->request_body);
  }

  site_for_cookies_ = request->site_for_cookies;

  resource_type_ = static_cast<honey_resource_type_t>(request->resource_type);
  transition_type_ =
      static_cast<honey_transition_type_t>(request->transition_type);
}

void HoneycombRequestImpl::Get(network::ResourceRequest* request,
                         bool changed_only) const {
  base::AutoLock lock_scope(lock_);

  if (ShouldSet(kChangedUrl, changed_only)) {
    request->url = url_;
  }

  if (ShouldSet(kChangedMethod, changed_only)) {
    request->method = method_;
  }

  if (ShouldSet(kChangedReferrer, changed_only)) {
    request->referrer = referrer_url_;
    request->referrer_policy =
        static_cast<net::ReferrerPolicy>(referrer_policy_);
  }

  if (ShouldSet(kChangedHeaderMap, changed_only)) {
    net::HttpRequestHeaders headers;
    headers.AddHeadersFromString(HttpHeaderUtils::GenerateHeaders(headermap_));
    request->headers.Swap(&headers);
  }

  if (ShouldSet(kChangedPostData, changed_only)) {
    if (postdata_.get()) {
      request->request_body =
          static_cast<HoneycombPostDataImpl*>(postdata_.get())->GetBody();
    } else if (request->request_body) {
      request->request_body = nullptr;
    }
  }

  if (!site_for_cookies_.IsNull() &&
      ShouldSet(kChangedSiteForCookies, changed_only)) {
    request->site_for_cookies = site_for_cookies_;
  }

  if (ShouldSet(kChangedFlags, changed_only)) {
    int flags = flags_;
    if (!(flags & kURCachePolicyMask)) {
      // Only consider the Cache-Control directives when a cache policy is not
      // explicitly set on the request.
      flags |= GetCacheControlHeaderPolicy(headermap_);
    }

    int net_flags = 0;

    if (flags & UR_FLAG_SKIP_CACHE) {
      net_flags |= net::LOAD_BYPASS_CACHE;
    }
    if (flags & UR_FLAG_ONLY_FROM_CACHE) {
      net_flags |= net::LOAD_ONLY_FROM_CACHE | net::LOAD_SKIP_CACHE_VALIDATION;
    }
    if (flags & UR_FLAG_DISABLE_CACHE) {
      net_flags |= net::LOAD_DISABLE_CACHE;
    }

    if (!(flags & UR_FLAG_ALLOW_STORED_CREDENTIALS)) {
      // This will disable all credentials including cookies, auth tokens, etc.
      request->credentials_mode = network::mojom::CredentialsMode::kOmit;
    }

    request->load_flags = net_flags;
  }
}

void HoneycombRequestImpl::Set(const net::RedirectInfo& redirect_info) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  url_ = redirect_info.new_url;
  method_ = redirect_info.new_method;
  site_for_cookies_ = redirect_info.new_site_for_cookies;

  const auto& sanitized_referrer = content::Referrer::SanitizeForRequest(
      redirect_info.new_url,
      content::Referrer(GURL(redirect_info.new_referrer),
                        NetReferrerPolicyToBlinkReferrerPolicy(
                            static_cast<honey_referrer_policy_t>(
                                redirect_info.new_referrer_policy))));
  referrer_url_ = sanitized_referrer.url;
  referrer_policy_ =
      BlinkReferrerPolicyToNetReferrerPolicy(sanitized_referrer.policy);
}

void HoneycombRequestImpl::Set(const net::HttpRequestHeaders& headers) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  ::GetHeaderMap(headers, headermap_);
}

void HoneycombRequestImpl::Set(content::NavigationHandle* navigation_handle) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  Reset();

  url_ = navigation_handle->GetURL();
  method_ = navigation_handle->IsPost() ? "POST" : "GET";

  const auto& sanitized_referrer = content::Referrer::SanitizeForRequest(
      navigation_handle->GetURL(), navigation_handle->GetReferrer());
  referrer_url_ = sanitized_referrer->url;
  referrer_policy_ =
      BlinkReferrerPolicyToNetReferrerPolicy(sanitized_referrer->policy);

  resource_type_ =
      navigation_handle->IsInMainFrame() ? RT_MAIN_FRAME : RT_SUB_FRAME;
  transition_type_ = static_cast<honey_transition_type_t>(
      navigation_handle->GetPageTransition());
}

// static
void HoneycombRequestImpl::Get(const honey::mojom::RequestParamsPtr& params,
                         blink::WebURLRequest& request) {
  request.SetUrl(params->url);
  request.SetRequestorOrigin(blink::WebSecurityOrigin::Create(params->url));
  if (!params->method.empty()) {
    request.SetHttpMethod(blink::WebString::FromASCII(params->method));
  }

  if (params->referrer && params->referrer->url.is_valid()) {
    const blink::WebString& referrer =
        blink::WebSecurityPolicy::GenerateReferrerHeader(
            params->referrer->policy, params->url,
            blink::WebString::FromUTF8(params->referrer->url.spec()));
    if (!referrer.IsEmpty()) {
      request.SetReferrerString(referrer);
      request.SetReferrerPolicy(params->referrer->policy);
    }
  }

  HoneycombRequest::HeaderMap headerMap;
  if (!params->headers.empty()) {
    for (net::HttpUtil::HeadersIterator i(params->headers.begin(),
                                          params->headers.end(), "\n\r");
         i.GetNext();) {
      request.AddHttpHeaderField(blink::WebString::FromUTF8(i.name()),
                                 blink::WebString::FromUTF8(i.values()));
      headerMap.insert(std::make_pair(i.name(), i.values()));
    }
  }

  if (params->upload_data) {
    const std::u16string& method = request.HttpMethod().Utf16();
    if (method == u"GET" || method == u"HEAD") {
      request.SetHttpMethod(blink::WebString::FromASCII("POST"));
    }

    // The comparison performed by httpHeaderField() is case insensitive.
    if (request
            .HttpHeaderField(blink::WebString::FromASCII(
                net::HttpRequestHeaders::kContentType))
            .length() == 0) {
      request.SetHttpHeaderField(
          blink::WebString::FromASCII(net::HttpRequestHeaders::kContentType),
          blink::WebString::FromASCII(
              net_service::kContentTypeApplicationFormURLEncoded));
    }

    request.SetHttpBody(
        blink::GetWebHTTPBodyForRequestBody(*params->upload_data));
  }

  if (!params->site_for_cookies.IsNull()) {
    request.SetSiteForCookies(params->site_for_cookies);
  }

  int flags = params->load_flags;
  if (!(flags & kURCachePolicyMask)) {
    // Only consider the Cache-Control directives when a cache policy is not
    // explicitly set on the request.
    flags |= GetCacheControlHeaderPolicy(headerMap);
  }
  request.SetCacheMode(GetFetchCacheMode(flags));

  SETBOOLFLAG(request, params->load_flags, SetAllowStoredCredentials,
              UR_FLAG_ALLOW_STORED_CREDENTIALS);
  SETBOOLFLAG(request, params->load_flags, SetReportUploadProgress,
              UR_FLAG_REPORT_UPLOAD_PROGRESS);
}

void HoneycombRequestImpl::Get(honey::mojom::RequestParamsPtr& params) const {
  base::AutoLock lock_scope(lock_);

  params->url = url_;
  params->method = method_;

  // Referrer policy will be applied later in the request pipeline.
  params->referrer = blink::mojom::Referrer::New(
      referrer_url_, NetReferrerPolicyToBlinkReferrerPolicy(referrer_policy_));

  if (!headermap_.empty()) {
    params->headers = HttpHeaderUtils::GenerateHeaders(headermap_);
  }

  if (postdata_) {
    HoneycombPostDataImpl* impl = static_cast<HoneycombPostDataImpl*>(postdata_.get());
    params->upload_data = impl->GetBody();
  }

  params->site_for_cookies = site_for_cookies_;
  params->load_flags = flags_;
}

void HoneycombRequestImpl::SetReadOnly(bool read_only) {
  base::AutoLock lock_scope(lock_);
  if (read_only_ == read_only) {
    return;
  }

  read_only_ = read_only;

  if (postdata_.get()) {
    static_cast<HoneycombPostDataImpl*>(postdata_.get())->SetReadOnly(read_only);
  }
}

void HoneycombRequestImpl::SetTrackChanges(bool track_changes,
                                     bool backup_on_change) {
  base::AutoLock lock_scope(lock_);
  if (track_changes_ == track_changes) {
    return;
  }

  if (!track_changes && backup_on_change_) {
    backup_.reset();
  }

  track_changes_ = track_changes;
  backup_on_change_ = track_changes ? backup_on_change : false;
  changes_ = kChangedNone;

  if (postdata_.get()) {
    static_cast<HoneycombPostDataImpl*>(postdata_.get())
        ->SetTrackChanges(track_changes);
  }
}

void HoneycombRequestImpl::RevertChanges() {
  base::AutoLock lock_scope(lock_);
  DCHECK(!read_only_);
  DCHECK(track_changes_);
  DCHECK(backup_on_change_);
  if (!backup_) {
    return;
  }

  // Restore the original values if a backup exists.
  if (backup_->backups_ & kChangedUrl) {
    url_ = backup_->url_;
  }
  if (backup_->backups_ & kChangedMethod) {
    method_ = backup_->method_;
  }
  if (backup_->backups_ & kChangedReferrer) {
    referrer_url_ = backup_->referrer_url_;
    referrer_policy_ = backup_->referrer_policy_;
  }
  if (backup_->backups_ & kChangedPostData) {
    postdata_ = backup_->postdata_;
  }
  if (backup_->backups_ & kChangedHeaderMap) {
    DCHECK(backup_->headermap_);
    headermap_.swap(*backup_->headermap_);
  }
  if (backup_->backups_ & kChangedFlags) {
    flags_ = backup_->flags_;
  }
  if (backup_->backups_ & kChangedSiteForCookies) {
    site_for_cookies_ = backup_->site_for_cookies_;
  }

  backup_.reset();
}

void HoneycombRequestImpl::DiscardChanges() {
  base::AutoLock lock_scope(lock_);
  DCHECK(track_changes_);
  DCHECK(backup_on_change_);
  backup_.reset();
}

uint8_t HoneycombRequestImpl::GetChanges() const {
  base::AutoLock lock_scope(lock_);

  uint8_t changes = changes_;
  if (postdata_.get() &&
      static_cast<HoneycombPostDataImpl*>(postdata_.get())->HasChanges()) {
    changes |= kChangedPostData;
  }
  return changes;
}

// From content/child/web_url_loader_impl.cc
// static
network::mojom::ReferrerPolicy
HoneycombRequestImpl::NetReferrerPolicyToBlinkReferrerPolicy(
    honey_referrer_policy_t net_policy) {
  switch (net_policy) {
    case REFERRER_POLICY_CLEAR_REFERRER_ON_TRANSITION_FROM_SECURE_TO_INSECURE:
      return network::mojom::ReferrerPolicy::kNoReferrerWhenDowngrade;
    case REFERRER_POLICY_REDUCE_REFERRER_GRANULARITY_ON_TRANSITION_CROSS_ORIGIN:
      return network::mojom::ReferrerPolicy::kStrictOriginWhenCrossOrigin;
    case REFERRER_POLICY_ORIGIN_ONLY_ON_TRANSITION_CROSS_ORIGIN:
      return network::mojom::ReferrerPolicy::kOriginWhenCrossOrigin;
    case REFERRER_POLICY_NEVER_CLEAR_REFERRER:
      return network::mojom::ReferrerPolicy::kAlways;
    case REFERRER_POLICY_ORIGIN:
      return network::mojom::ReferrerPolicy::kOrigin;
    case REFERRER_POLICY_CLEAR_REFERRER_ON_TRANSITION_CROSS_ORIGIN:
      return network::mojom::ReferrerPolicy::kSameOrigin;
    case REFERRER_POLICY_ORIGIN_CLEAR_ON_TRANSITION_FROM_SECURE_TO_INSECURE:
      return network::mojom::ReferrerPolicy::kStrictOrigin;
    case REFERRER_POLICY_NO_REFERRER:
      return network::mojom::ReferrerPolicy::kNever;
  }
  DCHECK(false);
  return network::mojom::ReferrerPolicy::kDefault;
}

// static
honey_referrer_policy_t HoneycombRequestImpl::BlinkReferrerPolicyToNetReferrerPolicy(
    network::mojom::ReferrerPolicy blink_policy) {
  switch (blink_policy) {
    case network::mojom::ReferrerPolicy::kNoReferrerWhenDowngrade:
      return REFERRER_POLICY_CLEAR_REFERRER_ON_TRANSITION_FROM_SECURE_TO_INSECURE;
    case network::mojom::ReferrerPolicy::kStrictOriginWhenCrossOrigin:
      return REFERRER_POLICY_REDUCE_REFERRER_GRANULARITY_ON_TRANSITION_CROSS_ORIGIN;
    case network::mojom::ReferrerPolicy::kOriginWhenCrossOrigin:
      return REFERRER_POLICY_ORIGIN_ONLY_ON_TRANSITION_CROSS_ORIGIN;
    case network::mojom::ReferrerPolicy::kAlways:
      return REFERRER_POLICY_NEVER_CLEAR_REFERRER;
    case network::mojom::ReferrerPolicy::kOrigin:
      return REFERRER_POLICY_ORIGIN;
    case network::mojom::ReferrerPolicy::kSameOrigin:
      return REFERRER_POLICY_CLEAR_REFERRER_ON_TRANSITION_CROSS_ORIGIN;
    case network::mojom::ReferrerPolicy::kStrictOrigin:
      return REFERRER_POLICY_ORIGIN_CLEAR_ON_TRANSITION_FROM_SECURE_TO_INSECURE;
    case network::mojom::ReferrerPolicy::kNever:
      return REFERRER_POLICY_NO_REFERRER;
    case network::mojom::ReferrerPolicy::kDefault:
      return REFERRER_POLICY_DEFAULT;
  }
  DCHECK(false);
  return REFERRER_POLICY_DEFAULT;
}

void HoneycombRequestImpl::Changed(uint8_t changes) {
  lock_.AssertAcquired();
  if (!track_changes_) {
    return;
  }

  if (backup_on_change_) {
    if (!backup_) {
      backup_.reset(new Backup());
    }

    // Set the backup values if not already set.
    if ((changes & kChangedUrl) && !(backup_->backups_ & kChangedUrl)) {
      backup_->url_ = url_;
      backup_->backups_ |= kChangedUrl;
    }
    if ((changes & kChangedMethod) && !(backup_->backups_ & kChangedMethod)) {
      backup_->method_ = method_;
      backup_->backups_ |= kChangedMethod;
    }
    if ((changes & kChangedReferrer) &&
        !(backup_->backups_ & kChangedReferrer)) {
      backup_->referrer_url_ = referrer_url_;
      backup_->referrer_policy_ = referrer_policy_;
      backup_->backups_ |= kChangedReferrer;
    }
    if ((changes & kChangedPostData) &&
        !(backup_->backups_ & kChangedPostData)) {
      backup_->postdata_ = postdata_;
      backup_->backups_ |= kChangedPostData;
    }
    if ((changes & kChangedHeaderMap) &&
        !(backup_->backups_ & kChangedHeaderMap)) {
      backup_->headermap_.reset(new HeaderMap());
      if (!headermap_.empty()) {
        backup_->headermap_->insert(headermap_.begin(), headermap_.end());
      }
      backup_->backups_ |= kChangedHeaderMap;
    }
    if ((changes & kChangedFlags) && !(backup_->backups_ & kChangedFlags)) {
      backup_->flags_ = flags_;
      backup_->backups_ |= kChangedFlags;
    }
    if ((changes & kChangedSiteForCookies) &&
        !(backup_->backups_ & kChangedSiteForCookies)) {
      backup_->site_for_cookies_ = site_for_cookies_;
      backup_->backups_ |= kChangedSiteForCookies;
    }
  }

  changes_ |= changes;
}

bool HoneycombRequestImpl::ShouldSet(uint8_t changes, bool changed_only) const {
  lock_.AssertAcquired();

  // Always change if changes are not being tracked.
  if (!track_changes_) {
    return true;
  }

  // Always change if changed-only was not requested.
  if (!changed_only) {
    return true;
  }

  // Change if the |changes| bit flag has been set.
  if ((changes_ & changes) == changes) {
    return true;
  }

  if ((changes & kChangedPostData) == kChangedPostData) {
    // Change if the post data object was modified directly.
    if (postdata_.get() &&
        static_cast<HoneycombPostDataImpl*>(postdata_.get())->HasChanges()) {
      return true;
    }
  }

  return false;
}

void HoneycombRequestImpl::Reset() {
  lock_.AssertAcquired();
  DCHECK(!read_only_);

  url_ = GURL();
  method_ = "GET";
  referrer_url_ = GURL();
  referrer_policy_ = REFERRER_POLICY_DEFAULT;
  postdata_ = nullptr;
  headermap_.clear();
  resource_type_ = RT_SUB_RESOURCE;
  transition_type_ = TT_EXPLICIT;
  identifier_ = 0U;
  flags_ = UR_FLAG_NONE;
  site_for_cookies_ = net::SiteForCookies();

  changes_ = kChangedNone;
}

// HoneycombPostData ----------------------------------------------------------------

// static
HoneycombRefPtr<HoneycombPostData> HoneycombPostData::Create() {
  HoneycombRefPtr<HoneycombPostData> postdata(new HoneycombPostDataImpl());
  return postdata;
}

// HoneycombPostDataImpl ------------------------------------------------------------

HoneycombPostDataImpl::HoneycombPostDataImpl()
    : read_only_(false),
      has_excluded_elements_(false),
      track_changes_(false),
      has_changes_(false) {}

bool HoneycombPostDataImpl::IsReadOnly() {
  base::AutoLock lock_scope(lock_);
  return read_only_;
}

bool HoneycombPostDataImpl::HasExcludedElements() {
  base::AutoLock lock_scope(lock_);
  return has_excluded_elements_;
}

size_t HoneycombPostDataImpl::GetElementCount() {
  base::AutoLock lock_scope(lock_);
  return elements_.size();
}

void HoneycombPostDataImpl::GetElements(ElementVector& elements) {
  base::AutoLock lock_scope(lock_);
  elements = elements_;
}

bool HoneycombPostDataImpl::RemoveElement(HoneycombRefPtr<HoneycombPostDataElement> element) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN(false);

  ElementVector::iterator it = elements_.begin();
  for (; it != elements_.end(); ++it) {
    if (it->get() == element.get()) {
      elements_.erase(it);
      Changed();
      return true;
    }
  }

  return false;
}

bool HoneycombPostDataImpl::AddElement(HoneycombRefPtr<HoneycombPostDataElement> element) {
  bool found = false;

  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN(false);

  // check that the element isn't already in the list before adding
  ElementVector::const_iterator it = elements_.begin();
  for (; it != elements_.end(); ++it) {
    if (it->get() == element.get()) {
      found = true;
      break;
    }
  }

  if (!found) {
    elements_.push_back(element);
    Changed();
  }

  return !found;
}

void HoneycombPostDataImpl::RemoveElements() {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();
  elements_.clear();
  Changed();
}

void HoneycombPostDataImpl::Set(const network::ResourceRequestBody& body) {
  {
    base::AutoLock lock_scope(lock_);
    CHECK_READONLY_RETURN_VOID();
  }

  HoneycombRefPtr<HoneycombPostDataElement> postelem;

  for (const auto& element : *body.elements()) {
    postelem = HoneycombPostDataElement::Create();
    static_cast<HoneycombPostDataElementImpl*>(postelem.get())->Set(element);
    AddElement(postelem);
  }
}

scoped_refptr<network::ResourceRequestBody> HoneycombPostDataImpl::GetBody() const {
  base::AutoLock lock_scope(lock_);

  scoped_refptr<network::ResourceRequestBody> body =
      new network::ResourceRequestBody();
  for (const auto& element : elements_) {
    static_cast<HoneycombPostDataElementImpl*>(element.get())->Get(*body);
  }
  return body;
}

void HoneycombPostDataImpl::SetReadOnly(bool read_only) {
  base::AutoLock lock_scope(lock_);
  if (read_only_ == read_only) {
    return;
  }

  read_only_ = read_only;

  ElementVector::const_iterator it = elements_.begin();
  for (; it != elements_.end(); ++it) {
    static_cast<HoneycombPostDataElementImpl*>(it->get())->SetReadOnly(read_only);
  }
}

void HoneycombPostDataImpl::SetTrackChanges(bool track_changes) {
  base::AutoLock lock_scope(lock_);
  if (track_changes_ == track_changes) {
    return;
  }

  track_changes_ = track_changes;
  has_changes_ = false;

  ElementVector::const_iterator it = elements_.begin();
  for (; it != elements_.end(); ++it) {
    static_cast<HoneycombPostDataElementImpl*>(it->get())->SetTrackChanges(
        track_changes);
  }
}

bool HoneycombPostDataImpl::HasChanges() const {
  base::AutoLock lock_scope(lock_);
  if (has_changes_) {
    return true;
  }

  ElementVector::const_iterator it = elements_.begin();
  for (; it != elements_.end(); ++it) {
    if (static_cast<HoneycombPostDataElementImpl*>(it->get())->HasChanges()) {
      return true;
    }
  }

  return false;
}

void HoneycombPostDataImpl::Changed() {
  lock_.AssertAcquired();
  if (track_changes_ && !has_changes_) {
    has_changes_ = true;
  }
}

// HoneycombPostDataElement ---------------------------------------------------------

// static
HoneycombRefPtr<HoneycombPostDataElement> HoneycombPostDataElement::Create() {
  HoneycombRefPtr<HoneycombPostDataElement> element(new HoneycombPostDataElementImpl());
  return element;
}

// HoneycombPostDataElementImpl -----------------------------------------------------

HoneycombPostDataElementImpl::HoneycombPostDataElementImpl()
    : type_(PDE_TYPE_EMPTY),
      read_only_(false),
      track_changes_(false),
      has_changes_(false) {
  memset(&data_, 0, sizeof(data_));
}

HoneycombPostDataElementImpl::~HoneycombPostDataElementImpl() {
  Cleanup();
}

bool HoneycombPostDataElementImpl::IsReadOnly() {
  base::AutoLock lock_scope(lock_);
  return read_only_;
}

void HoneycombPostDataElementImpl::SetToEmpty() {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  Cleanup();
  Changed();
}

void HoneycombPostDataElementImpl::SetToFile(const HoneycombString& fileName) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  // Clear any data currently in the element
  Cleanup();

  // Assign the new data
  type_ = PDE_TYPE_FILE;
  honey_string_copy(fileName.c_str(), fileName.length(), &data_.filename);

  Changed();
}

void HoneycombPostDataElementImpl::SetToBytes(size_t size, const void* bytes) {
  base::AutoLock lock_scope(lock_);
  CHECK_READONLY_RETURN_VOID();

  // Clear any data currently in the element
  Cleanup();

  // Assign the new data
  void* data = malloc(size);
  DCHECK(data != nullptr);
  if (data == nullptr) {
    return;
  }

  memcpy(data, bytes, size);

  type_ = PDE_TYPE_BYTES;
  data_.bytes.bytes = data;
  data_.bytes.size = size;

  Changed();
}

HoneycombPostDataElement::Type HoneycombPostDataElementImpl::GetType() {
  base::AutoLock lock_scope(lock_);
  return type_;
}

HoneycombString HoneycombPostDataElementImpl::GetFile() {
  base::AutoLock lock_scope(lock_);
  DCHECK(type_ == PDE_TYPE_FILE);
  HoneycombString filename;
  if (type_ == PDE_TYPE_FILE) {
    filename.FromString(data_.filename.str, data_.filename.length, false);
  }
  return filename;
}

size_t HoneycombPostDataElementImpl::GetBytesCount() {
  base::AutoLock lock_scope(lock_);
  DCHECK(type_ == PDE_TYPE_BYTES);
  size_t size = 0;
  if (type_ == PDE_TYPE_BYTES) {
    size = data_.bytes.size;
  }
  return size;
}

size_t HoneycombPostDataElementImpl::GetBytes(size_t size, void* bytes) {
  base::AutoLock lock_scope(lock_);
  DCHECK(type_ == PDE_TYPE_BYTES);
  size_t rv = 0;
  if (type_ == PDE_TYPE_BYTES) {
    rv = (size < data_.bytes.size ? size : data_.bytes.size);
    memcpy(bytes, data_.bytes.bytes, rv);
  }
  return rv;
}

void HoneycombPostDataElementImpl::Set(const network::DataElement& element) {
  {
    base::AutoLock lock_scope(lock_);
    CHECK_READONLY_RETURN_VOID();
  }

  if (element.type() == network::DataElement::Tag::kBytes) {
    const auto& bytes_element = element.As<network::DataElementBytes>();
    const auto& bytes = bytes_element.bytes();
    SetToBytes(bytes.size(), bytes.data());
  } else if (element.type() == network::DataElement::Tag::kFile) {
    const auto& file_element = element.As<network::DataElementFile>();
    SetToFile(file_element.path().value());
  }
}

void HoneycombPostDataElementImpl::Get(network::ResourceRequestBody& body) const {
  base::AutoLock lock_scope(lock_);

  if (type_ == PDE_TYPE_BYTES) {
    body.AppendBytes(static_cast<char*>(data_.bytes.bytes), data_.bytes.size);
  } else if (type_ == PDE_TYPE_FILE) {
    base::FilePath path = base::FilePath(HoneycombString(&data_.filename));
    body.AppendFileRange(path, 0, std::numeric_limits<uint64_t>::max(),
                         base::Time());
  } else {
    DCHECK(false);
  }
}

void HoneycombPostDataElementImpl::SetReadOnly(bool read_only) {
  base::AutoLock lock_scope(lock_);
  if (read_only_ == read_only) {
    return;
  }

  read_only_ = read_only;
}

void HoneycombPostDataElementImpl::SetTrackChanges(bool track_changes) {
  base::AutoLock lock_scope(lock_);
  if (track_changes_ == track_changes) {
    return;
  }

  track_changes_ = track_changes;
  has_changes_ = false;
}

bool HoneycombPostDataElementImpl::HasChanges() const {
  base::AutoLock lock_scope(lock_);
  return has_changes_;
}

void HoneycombPostDataElementImpl::Changed() {
  lock_.AssertAcquired();
  if (track_changes_ && !has_changes_) {
    has_changes_ = true;
  }
}

void HoneycombPostDataElementImpl::Cleanup() {
  if (type_ == PDE_TYPE_EMPTY) {
    return;
  }

  if (type_ == PDE_TYPE_BYTES) {
    free(data_.bytes.bytes);
  } else if (type_ == PDE_TYPE_FILE) {
    honey_string_clear(&data_.filename);
  }
  type_ = PDE_TYPE_EMPTY;
  memset(&data_, 0, sizeof(data_));
}