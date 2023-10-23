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
// $hash=74736c3227b7b9961f04ab93f5644a16fe0a21b9$
//

#include "libhoneycomb_dll/ctocpp/thread_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/task_runner_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombThread> HoneycombThread::CreateThread(
    const HoneycombString& display_name,
    honey_thread_priority_t priority,
    honey_message_loop_type_t message_loop_type,
    bool stoppable,
    honey_com_init_mode_t com_init_mode) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: display_name

  // Execute
  honey_thread_t* _retval =
      honey_thread_create(display_name.GetStruct(), priority, message_loop_type,
                        stoppable, com_init_mode);

  // Return type: refptr_same
  return HoneycombThreadCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombTaskRunner> HoneycombThreadCToCpp::GetTaskRunner() {
  shutdown_checker::AssertNotShutdown();

  honey_thread_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_task_runner)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_task_runner_t* _retval = _struct->get_task_runner(_struct);

  // Return type: refptr_same
  return HoneycombTaskRunnerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
honey_platform_thread_id_t HoneycombThreadCToCpp::GetPlatformThreadId() {
  shutdown_checker::AssertNotShutdown();

  honey_thread_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_platform_thread_id)) {
    return kInvalidPlatformThreadId;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_platform_thread_id_t _retval = _struct->get_platform_thread_id(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void HoneycombThreadCToCpp::Stop() {
  shutdown_checker::AssertNotShutdown();

  honey_thread_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, stop)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->stop(_struct);
}

NO_SANITIZE("cfi-icall") bool HoneycombThreadCToCpp::IsRunning() {
  shutdown_checker::AssertNotShutdown();

  honey_thread_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_running)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_running(_struct);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombThreadCToCpp::HoneycombThreadCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombThreadCToCpp::~HoneycombThreadCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_thread_t*
HoneycombCToCppRefCounted<HoneycombThreadCToCpp, HoneycombThread, honey_thread_t>::UnwrapDerived(
    HoneycombWrapperType type,
    HoneycombThread* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombThreadCToCpp, HoneycombThread, honey_thread_t>::
    kWrapperType = WT_THREAD;
