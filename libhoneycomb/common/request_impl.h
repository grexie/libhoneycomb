// Copyright (c) 2012 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEYCOMB_COMMON_REQUEST_IMPL_H_
#define HONEYCOMB_LIBHONEYCOMB_COMMON_REQUEST_IMPL_H_
#pragma once

#include <stdint.h>

#include <memory>

#include "include/honey_request.h"

#include "base/synchronization/lock.h"
#include "honey/libhoneycomb/common/mojom/honey.mojom.h"
#include "net/cookies/site_for_cookies.h"
#include "services/network/public/mojom/referrer_policy.mojom-shared.h"
#include "url/gurl.h"

namespace blink {
class WebURLRequest;
}  // namespace blink

namespace content {
class NavigationHandle;
}  // namespace content

namespace net {
class HttpRequestHeaders;
struct RedirectInfo;
}  // namespace net

namespace network {
class DataElement;
struct ResourceRequest;
class ResourceRequestBody;
}  // namespace network

// Implementation of HoneycombRequest
class HoneycombRequestImpl : public HoneycombRequest {
 public:
  enum Changes {
    kChangedNone = 0,
    kChangedUrl = 1 << 0,
    kChangedMethod = 1 << 1,
    kChangedReferrer = 1 << 2,
    kChangedPostData = 1 << 3,
    kChangedHeaderMap = 1 << 4,
    kChangedFlags = 1 << 5,
    kChangedSiteForCookies = 1 << 6,
  };

  HoneycombRequestImpl();

  bool IsReadOnly() override;
  HoneycombString GetURL() override;
  void SetURL(const HoneycombString& url) override;
  HoneycombString GetMethod() override;
  void SetMethod(const HoneycombString& method) override;
  void SetReferrer(const HoneycombString& referrer_url,
                   ReferrerPolicy policy) override;
  HoneycombString GetReferrerURL() override;
  ReferrerPolicy GetReferrerPolicy() override;
  HoneycombRefPtr<HoneycombPostData> GetPostData() override;
  void SetPostData(HoneycombRefPtr<HoneycombPostData> postData) override;
  void GetHeaderMap(HeaderMap& headerMap) override;
  void SetHeaderMap(const HeaderMap& headerMap) override;
  HoneycombString GetHeaderByName(const HoneycombString& name) override;
  void SetHeaderByName(const HoneycombString& name,
                       const HoneycombString& value,
                       bool overwrite) override;
  void Set(const HoneycombString& url,
           const HoneycombString& method,
           HoneycombRefPtr<HoneycombPostData> postData,
           const HeaderMap& headerMap) override;
  int GetFlags() override;
  void SetFlags(int flags) override;
  HoneycombString GetFirstPartyForCookies() override;
  void SetFirstPartyForCookies(const HoneycombString& url) override;
  ResourceType GetResourceType() override;
  TransitionType GetTransitionType() override;
  uint64_t GetIdentifier() override;

  // Populate this object from the ResourceRequest object.
  void Set(const network::ResourceRequest* request, uint64_t identifier);

  // Populate the ResourceRequest object from this object.
  // If |changed_only| is true then only the changed fields will be updated.
  void Get(network::ResourceRequest* request, bool changed_only) const;

  // Populate this object from the RedirectInfo object.
  void Set(const net::RedirectInfo& redirect_info);

  // Populate this object from the HttpRequestHeaders object.
  void Set(const net::HttpRequestHeaders& headers);

  // Populate this object from the NavigationParams object.
  // Called from throttle_handler.cc NavigationOnUIThread().
  void Set(content::NavigationHandle* navigation_handle);

  // Populate the WebURLRequest object based on the contents of |params|.
  // Called from HoneycombBrowserImpl::LoadRequest().
  static void Get(const honey::mojom::RequestParamsPtr& params,
                  blink::WebURLRequest& request);

  // Populate the RequestParams object from this object.
  // Called from HoneycombFrameHostImpl::LoadRequest().
  void Get(honey::mojom::RequestParamsPtr& params) const;

  void SetReadOnly(bool read_only);

  // Enable or disable tracking of changes. If |track_changes| is true the
  // status of changes will be tracked, and retrievable via GetChanges(). If
  // |backup_on_change| is true the original value will be backed up before the
  // first change. The original values can later be restored by calling
  // RevertChanges() before calling SetTrackChanges(false).
  void SetTrackChanges(bool track_changes, bool backup_on_change = false);
  void RevertChanges();
  void DiscardChanges();
  uint8_t GetChanges() const;

  static network::mojom::ReferrerPolicy NetReferrerPolicyToBlinkReferrerPolicy(
      honey_referrer_policy_t net_policy);
  static honey_referrer_policy_t BlinkReferrerPolicyToNetReferrerPolicy(
      network::mojom::ReferrerPolicy blink_policy);

 private:
  // Mark values as changed. Must be called before the new values are assigned.
  void Changed(uint8_t changes);

  // Used with the Set() methods that export data to other object types. Returns
  // true if the values should be set on the export object. If |changed_only| is
  // true then only return true if the value has been changed in combination
  // with track changes.
  bool ShouldSet(uint8_t changes, bool changed_only) const;

  void Reset();

  GURL url_;
  std::string method_;
  GURL referrer_url_;
  ReferrerPolicy referrer_policy_;
  HoneycombRefPtr<HoneycombPostData> postdata_;
  HeaderMap headermap_;
  ResourceType resource_type_;
  TransitionType transition_type_;
  uint64_t identifier_;

  // The below members are used by HoneycombURLRequest.
  int flags_;
  net::SiteForCookies site_for_cookies_;

  // Stores backup of values for use with track changes.
  struct Backup {
    // Bitmask of values that have been backed up.
    uint8_t backups_ = kChangedNone;

    GURL url_;
    std::string method_;
    GURL referrer_url_;
    ReferrerPolicy referrer_policy_;
    HoneycombRefPtr<HoneycombPostData> postdata_;
    std::unique_ptr<HeaderMap> headermap_;
    int flags_;
    net::SiteForCookies site_for_cookies_;
  };
  std::unique_ptr<Backup> backup_;

  // True if this object is read-only.
  bool read_only_ = false;

  // True if this object should track changes.
  bool track_changes_ = false;

  // True if original values should be backed up when |track_changes_| is true.
  bool backup_on_change_ = false;

  // Bitmask of |Changes| values which indicate which fields have changed.
  uint8_t changes_ = kChangedNone;

  mutable base::Lock lock_;

  IMPLEMENT_REFCOUNTING(HoneycombRequestImpl);
};

// Implementation of HoneycombPostData
class HoneycombPostDataImpl : public HoneycombPostData {
 public:
  HoneycombPostDataImpl();

  bool IsReadOnly() override;
  bool HasExcludedElements() override;
  size_t GetElementCount() override;
  void GetElements(ElementVector& elements) override;
  bool RemoveElement(HoneycombRefPtr<HoneycombPostDataElement> element) override;
  bool AddElement(HoneycombRefPtr<HoneycombPostDataElement> element) override;
  void RemoveElements() override;

  void Set(const network::ResourceRequestBody& body);
  scoped_refptr<network::ResourceRequestBody> GetBody() const;

  void SetReadOnly(bool read_only);

  void SetTrackChanges(bool track_changes);
  bool HasChanges() const;

 private:
  void Changed();

  ElementVector elements_;

  // True if this object is read-only.
  bool read_only_;

  // True if this object has excluded elements.
  bool has_excluded_elements_;

  // True if this object should track changes.
  bool track_changes_;

  // True if this object has changes.
  bool has_changes_;

  mutable base::Lock lock_;

  IMPLEMENT_REFCOUNTING(HoneycombPostDataImpl);
};

// Implementation of HoneycombPostDataElement
class HoneycombPostDataElementImpl : public HoneycombPostDataElement {
 public:
  HoneycombPostDataElementImpl();
  ~HoneycombPostDataElementImpl() override;

  bool IsReadOnly() override;
  void SetToEmpty() override;
  void SetToFile(const HoneycombString& fileName) override;
  void SetToBytes(size_t size, const void* bytes) override;
  Type GetType() override;
  HoneycombString GetFile() override;
  size_t GetBytesCount() override;
  size_t GetBytes(size_t size, void* bytes) override;

  void* GetBytes() { return data_.bytes.bytes; }

  void Set(const network::DataElement& element);
  void Get(network::ResourceRequestBody& body) const;

  void SetReadOnly(bool read_only);

  void SetTrackChanges(bool track_changes);
  bool HasChanges() const;

 private:
  void Changed();
  void Cleanup();

  Type type_;
  union {
    struct {
      void* bytes;
      size_t size;
    } bytes;
    honey_string_t filename;
  } data_;

  // True if this object is read-only.
  bool read_only_;

  // True if this object should track changes.
  bool track_changes_;

  // True if this object has changes.
  bool has_changes_;

  mutable base::Lock lock_;

  IMPLEMENT_REFCOUNTING(HoneycombPostDataElementImpl);
};

#endif  // HONEYCOMB_LIBHONEYCOMB_COMMON_REQUEST_IMPL_H_
