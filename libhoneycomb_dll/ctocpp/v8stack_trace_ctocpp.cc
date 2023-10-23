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
// $hash=f35d094b71513d6d1201e53eda87148b415d286d$
//

#include "libhoneycomb_dll/ctocpp/v8stack_trace_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/v8stack_frame_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombV8StackTrace> HoneycombV8StackTrace::GetCurrent(int frame_limit) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_v8stack_trace_t* _retval = honey_v8stack_trace_get_current(frame_limit);

  // Return type: refptr_same
  return HoneycombV8StackTraceCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool HoneycombV8StackTraceCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  honey_v8stack_trace_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_valid)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") int HoneycombV8StackTraceCToCpp::GetFrameCount() {
  shutdown_checker::AssertNotShutdown();

  honey_v8stack_trace_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_frame_count)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_frame_count(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombV8StackFrame> HoneycombV8StackTraceCToCpp::GetFrame(int index) {
  shutdown_checker::AssertNotShutdown();

  honey_v8stack_trace_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_frame)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_v8stack_frame_t* _retval = _struct->get_frame(_struct, index);

  // Return type: refptr_same
  return HoneycombV8StackFrameCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombV8StackTraceCToCpp::HoneycombV8StackTraceCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombV8StackTraceCToCpp::~HoneycombV8StackTraceCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_v8stack_trace_t*
HoneycombCToCppRefCounted<HoneycombV8StackTraceCToCpp,
                    HoneycombV8StackTrace,
                    honey_v8stack_trace_t>::UnwrapDerived(HoneycombWrapperType type,
                                                        HoneycombV8StackTrace* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombV8StackTraceCToCpp,
                                   HoneycombV8StackTrace,
                                   honey_v8stack_trace_t>::kWrapperType =
    WT_V8STACK_TRACE;
