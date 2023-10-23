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
// $hash=5a17c94ca2e63c936ad570de435893b55326df42$
//

#include "libhoneycomb_dll/ctocpp/waitable_event_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombWaitableEvent> HoneycombWaitableEvent::CreateWaitableEvent(
    bool automatic_reset,
    bool initially_signaled) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_waitable_event_t* _retval =
      honey_waitable_event_create(automatic_reset, initially_signaled);

  // Return type: refptr_same
  return HoneycombWaitableEventCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") void HoneycombWaitableEventCToCpp::Reset() {
  shutdown_checker::AssertNotShutdown();

  honey_waitable_event_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, reset)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->reset(_struct);
}

NO_SANITIZE("cfi-icall") void HoneycombWaitableEventCToCpp::Signal() {
  shutdown_checker::AssertNotShutdown();

  honey_waitable_event_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, signal)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->signal(_struct);
}

NO_SANITIZE("cfi-icall") bool HoneycombWaitableEventCToCpp::IsSignaled() {
  shutdown_checker::AssertNotShutdown();

  honey_waitable_event_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_signaled)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_signaled(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") void HoneycombWaitableEventCToCpp::Wait() {
  shutdown_checker::AssertNotShutdown();

  honey_waitable_event_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, wait)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->wait(_struct);
}

NO_SANITIZE("cfi-icall")
bool HoneycombWaitableEventCToCpp::TimedWait(int64_t max_ms) {
  shutdown_checker::AssertNotShutdown();

  honey_waitable_event_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, timed_wait)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->timed_wait(_struct, max_ms);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombWaitableEventCToCpp::HoneycombWaitableEventCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombWaitableEventCToCpp::~HoneycombWaitableEventCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_waitable_event_t*
HoneycombCToCppRefCounted<HoneycombWaitableEventCToCpp,
                    HoneycombWaitableEvent,
                    honey_waitable_event_t>::UnwrapDerived(HoneycombWrapperType type,
                                                         HoneycombWaitableEvent* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombWaitableEventCToCpp,
                                   HoneycombWaitableEvent,
                                   honey_waitable_event_t>::kWrapperType =
    WT_WAITABLE_EVENT;
