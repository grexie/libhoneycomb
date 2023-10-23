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
// $hash=870f78147369bc35912730714caef7559fa41c99$
//

#include "libhoneycomb_dll/ctocpp/end_tracing_callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombEndTracingCallbackCToCpp::OnEndTracingComplete(
    const HoneycombString& tracing_file) {
  shutdown_checker::AssertNotShutdown();

  honey_end_tracing_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_end_tracing_complete)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: tracing_file; type: string_byref_const
  DCHECK(!tracing_file.empty());
  if (tracing_file.empty()) {
    return;
  }

  // Execute
  _struct->on_end_tracing_complete(_struct, tracing_file.GetStruct());
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombEndTracingCallbackCToCpp::HoneycombEndTracingCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombEndTracingCallbackCToCpp::~HoneycombEndTracingCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_end_tracing_callback_t* HoneycombCToCppRefCounted<
    HoneycombEndTracingCallbackCToCpp,
    HoneycombEndTracingCallback,
    honey_end_tracing_callback_t>::UnwrapDerived(HoneycombWrapperType type,
                                               HoneycombEndTracingCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombEndTracingCallbackCToCpp,
                                   HoneycombEndTracingCallback,
                                   honey_end_tracing_callback_t>::kWrapperType =
    WT_END_TRACING_CALLBACK;
