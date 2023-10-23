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
// $hash=72ebc189ce2a4bcfc796b818409d3b742651fda9$
//

#include "libhoneycomb_dll/cpptoc/delete_cookies_callback_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
delete_cookies_callback_on_complete(struct _honey_delete_cookies_callback_t* self,
                                    int num_deleted) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombDeleteCookiesCallbackCppToC::Get(self)->OnComplete(num_deleted);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDeleteCookiesCallbackCppToC::HoneycombDeleteCookiesCallbackCppToC() {
  GetStruct()->on_complete = delete_cookies_callback_on_complete;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDeleteCookiesCallbackCppToC::~HoneycombDeleteCookiesCallbackCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDeleteCookiesCallback> HoneycombCppToCRefCounted<
    HoneycombDeleteCookiesCallbackCppToC,
    HoneycombDeleteCookiesCallback,
    honey_delete_cookies_callback_t>::UnwrapDerived(HoneycombWrapperType type,
                                                  honey_delete_cookies_callback_t*
                                                      s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCppToCRefCounted<HoneycombDeleteCookiesCallbackCppToC,
                        HoneycombDeleteCookiesCallback,
                        honey_delete_cookies_callback_t>::kWrapperType =
        WT_DELETE_COOKIES_CALLBACK;
