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
// $hash=3e078458c9ec423ac8ea129888485e600896e03f$
//

#include "libhoney_dll/ctocpp/scheme_handler_factory_ctocpp.h"
#include "libhoney_dll/cpptoc/browser_cpptoc.h"
#include "libhoney_dll/cpptoc/frame_cpptoc.h"
#include "libhoney_dll/cpptoc/request_cpptoc.h"
#include "libhoney_dll/ctocpp/resource_handler_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombResourceHandler> HoneycombSchemeHandlerFactoryCToCpp::Create(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    const HoneycombString& scheme_name,
    HoneycombRefPtr<HoneycombRequest> request) {
  honey_scheme_handler_factory_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, create)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: scheme_name; type: string_byref_const
  DCHECK(!scheme_name.empty());
  if (scheme_name.empty()) {
    return nullptr;
  }
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get()) {
    return nullptr;
  }
  // Unverified params: browser, frame

  // Execute
  honey_resource_handler_t* _retval = _struct->create(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      scheme_name.GetStruct(), HoneycombRequestCppToC::Wrap(request));

  // Return type: refptr_same
  return HoneycombResourceHandlerCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombSchemeHandlerFactoryCToCpp::HoneycombSchemeHandlerFactoryCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombSchemeHandlerFactoryCToCpp::~HoneycombSchemeHandlerFactoryCToCpp() {}

template <>
honey_scheme_handler_factory_t* HoneycombCToCppRefCounted<
    HoneycombSchemeHandlerFactoryCToCpp,
    HoneycombSchemeHandlerFactory,
    honey_scheme_handler_factory_t>::UnwrapDerived(HoneycombWrapperType type,
                                                 HoneycombSchemeHandlerFactory* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombSchemeHandlerFactoryCToCpp,
                                   HoneycombSchemeHandlerFactory,
                                   honey_scheme_handler_factory_t>::kWrapperType =
    WT_SCHEME_HANDLER_FACTORY;