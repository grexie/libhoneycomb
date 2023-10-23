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
// $hash=a41feff4617bc9beb0512a1350f3ac700b18ea2e$
//

#include "libhoneycomb_dll/ctocpp/callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") void HoneycombCallbackCToCpp::Continue() {
  shutdown_checker::AssertNotShutdown();

  honey_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, cont)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cont(_struct);
}

NO_SANITIZE("cfi-icall") void HoneycombCallbackCToCpp::Cancel() {
  shutdown_checker::AssertNotShutdown();

  honey_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, cancel)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cancel(_struct);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombCallbackCToCpp::HoneycombCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombCallbackCToCpp::~HoneycombCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_callback_t*
HoneycombCToCppRefCounted<HoneycombCallbackCToCpp, HoneycombCallback, honey_callback_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombCallbackCToCpp,
                                   HoneycombCallback,
                                   honey_callback_t>::kWrapperType = WT_CALLBACK;
