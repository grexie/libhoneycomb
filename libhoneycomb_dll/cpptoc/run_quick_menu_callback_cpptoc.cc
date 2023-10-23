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
// $hash=005e5ae02a04bc6fdd626063b1f83e465e21e498$
//

#include "libhoneycomb_dll/cpptoc/run_quick_menu_callback_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
run_quick_menu_callback_cont(struct _honey_run_quick_menu_callback_t* self,
                             int command_id,
                             honey_event_flags_t event_flags) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombRunQuickMenuCallbackCppToC::Get(self)->Continue(command_id, event_flags);
}

void HONEYCOMB_CALLBACK
run_quick_menu_callback_cancel(struct _honey_run_quick_menu_callback_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombRunQuickMenuCallbackCppToC::Get(self)->Cancel();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombRunQuickMenuCallbackCppToC::HoneycombRunQuickMenuCallbackCppToC() {
  GetStruct()->cont = run_quick_menu_callback_cont;
  GetStruct()->cancel = run_quick_menu_callback_cancel;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombRunQuickMenuCallbackCppToC::~HoneycombRunQuickMenuCallbackCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombRunQuickMenuCallback> HoneycombCppToCRefCounted<
    HoneycombRunQuickMenuCallbackCppToC,
    HoneycombRunQuickMenuCallback,
    honey_run_quick_menu_callback_t>::UnwrapDerived(HoneycombWrapperType type,
                                                  honey_run_quick_menu_callback_t*
                                                      s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCppToCRefCounted<HoneycombRunQuickMenuCallbackCppToC,
                        HoneycombRunQuickMenuCallback,
                        honey_run_quick_menu_callback_t>::kWrapperType =
        WT_RUN_QUICK_MENU_CALLBACK;
