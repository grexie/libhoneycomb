// Copyright (c) 2023 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the Honeycomb translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=d7bbbf41f806f415ac983a9a9f9475ab7783cb10$
//

#include "libhoney_dll/cpptoc/cookie_access_filter_cpptoc.h"
#include "libhoney_dll/ctocpp/browser_ctocpp.h"
#include "libhoney_dll/ctocpp/frame_ctocpp.h"
#include "libhoney_dll/ctocpp/request_ctocpp.h"
#include "libhoney_dll/ctocpp/response_ctocpp.h"
#include "libhoney_dll/template_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
cookie_access_filter_can_send_cookie(struct _honey_cookie_access_filter_t* self,
                                     honey_browser_t* browser,
                                     honey_frame_t* frame,
                                     honey_request_t* request,
                                     const struct _honey_cookie_t* cookie) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request) {
    return 0;
  }
  // Verify param: cookie; type: struct_byref_const
  DCHECK(cookie);
  if (!cookie) {
    return 0;
  }
  if (!template_util::has_valid_size(cookie)) {
    DCHECK(false) << "invalid cookie->[base.]size";
    return 0;
  }
  // Unverified params: browser, frame

  // Translate param: cookie; type: struct_byref_const
  HoneycombCookie cookieObj;
  if (cookie) {
    cookieObj.Set(*cookie, false);
  }

  // Execute
  bool _retval = HoneycombCookieAccessFilterCppToC::Get(self)->CanSendCookie(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombRequestCToCpp::Wrap(request), cookieObj);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
cookie_access_filter_can_save_cookie(struct _honey_cookie_access_filter_t* self,
                                     honey_browser_t* browser,
                                     honey_frame_t* frame,
                                     honey_request_t* request,
                                     struct _honey_response_t* response,
                                     const struct _honey_cookie_t* cookie) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request) {
    return 0;
  }
  // Verify param: response; type: refptr_diff
  DCHECK(response);
  if (!response) {
    return 0;
  }
  // Verify param: cookie; type: struct_byref_const
  DCHECK(cookie);
  if (!cookie) {
    return 0;
  }
  if (!template_util::has_valid_size(cookie)) {
    DCHECK(false) << "invalid cookie->[base.]size";
    return 0;
  }
  // Unverified params: browser, frame

  // Translate param: cookie; type: struct_byref_const
  HoneycombCookie cookieObj;
  if (cookie) {
    cookieObj.Set(*cookie, false);
  }

  // Execute
  bool _retval = HoneycombCookieAccessFilterCppToC::Get(self)->CanSaveCookie(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombRequestCToCpp::Wrap(request), HoneycombResponseCToCpp::Wrap(response),
      cookieObj);

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombCookieAccessFilterCppToC::HoneycombCookieAccessFilterCppToC() {
  GetStruct()->can_send_cookie = cookie_access_filter_can_send_cookie;
  GetStruct()->can_save_cookie = cookie_access_filter_can_save_cookie;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombCookieAccessFilterCppToC::~HoneycombCookieAccessFilterCppToC() {}

template <>
HoneycombRefPtr<HoneycombCookieAccessFilter> HoneycombCppToCRefCounted<
    HoneycombCookieAccessFilterCppToC,
    HoneycombCookieAccessFilter,
    honey_cookie_access_filter_t>::UnwrapDerived(HoneycombWrapperType type,
                                               honey_cookie_access_filter_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombCookieAccessFilterCppToC,
                                   HoneycombCookieAccessFilter,
                                   honey_cookie_access_filter_t>::kWrapperType =
    WT_COOKIE_ACCESS_FILTER;