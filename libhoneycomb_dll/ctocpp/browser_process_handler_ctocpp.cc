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
// $hash=533775387bf1001675aeb94a62bc4ece1eb11125$
//

#include "libhoneycomb_dll/ctocpp/browser_process_handler_ctocpp.h"
#include "libhoneycomb_dll/cpptoc/command_line_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/preference_registrar_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/client_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombBrowserProcessHandlerCToCpp::OnRegisterCustomPreferences(
    honey_preferences_type_t type,
    HoneycombRawPtr<HoneycombPreferenceRegistrar> registrar) {
  honey_browser_process_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_register_custom_preferences)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: registrar; type: rawptr_diff
  DCHECK(registrar);
  if (!registrar) {
    return;
  }

  // Translate param: registrar; type: rawptr_diff
  HoneycombOwnPtr<HoneycombPreferenceRegistrarCppToC> registrarPtr(
      HoneycombPreferenceRegistrarCppToC::WrapRaw(registrar));

  // Execute
  _struct->on_register_custom_preferences(_struct, type,
                                          registrarPtr->GetStruct());
}

NO_SANITIZE("cfi-icall")
void HoneycombBrowserProcessHandlerCToCpp::OnContextInitialized() {
  honey_browser_process_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_context_initialized)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->on_context_initialized(_struct);
}

NO_SANITIZE("cfi-icall")
void HoneycombBrowserProcessHandlerCToCpp::OnBeforeChildProcessLaunch(
    HoneycombRefPtr<HoneycombCommandLine> command_line) {
  honey_browser_process_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_before_child_process_launch)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: command_line; type: refptr_diff
  DCHECK(command_line.get());
  if (!command_line.get()) {
    return;
  }

  // Execute
  _struct->on_before_child_process_launch(
      _struct, HoneycombCommandLineCppToC::Wrap(command_line));
}

NO_SANITIZE("cfi-icall")
void HoneycombBrowserProcessHandlerCToCpp::OnScheduleMessagePumpWork(
    int64_t delay_ms) {
  honey_browser_process_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_schedule_message_pump_work)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->on_schedule_message_pump_work(_struct, delay_ms);
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombClient> HoneycombBrowserProcessHandlerCToCpp::GetDefaultClient() {
  honey_browser_process_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_default_client)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_client_t* _retval = _struct->get_default_client(_struct);

  // Return type: refptr_same
  return HoneycombClientCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombBrowserProcessHandlerCToCpp::HoneycombBrowserProcessHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombBrowserProcessHandlerCToCpp::~HoneycombBrowserProcessHandlerCToCpp() {}

template <>
honey_browser_process_handler_t* HoneycombCToCppRefCounted<
    HoneycombBrowserProcessHandlerCToCpp,
    HoneycombBrowserProcessHandler,
    honey_browser_process_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                                  HoneycombBrowserProcessHandler* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCToCppRefCounted<HoneycombBrowserProcessHandlerCToCpp,
                        HoneycombBrowserProcessHandler,
                        honey_browser_process_handler_t>::kWrapperType =
        WT_BROWSER_PROCESS_HANDLER;
