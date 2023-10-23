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
// $hash=2c8888f9fcfe40cf08eb2c9e4fff20a64c3ead7d$
//

#include "libhoneycomb_dll/ctocpp/context_menu_handler_ctocpp.h"
#include "libhoneycomb_dll/cpptoc/browser_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/context_menu_params_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/frame_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/menu_model_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/run_context_menu_callback_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/run_quick_menu_callback_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombContextMenuHandlerCToCpp::OnBeforeContextMenu(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    HoneycombRefPtr<HoneycombContextMenuParams> params,
    HoneycombRefPtr<HoneycombMenuModel> model) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_before_context_menu)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get()) {
    return;
  }
  // Verify param: model; type: refptr_diff
  DCHECK(model.get());
  if (!model.get()) {
    return;
  }

  // Execute
  _struct->on_before_context_menu(_struct, HoneycombBrowserCppToC::Wrap(browser),
                                  HoneycombFrameCppToC::Wrap(frame),
                                  HoneycombContextMenuParamsCppToC::Wrap(params),
                                  HoneycombMenuModelCppToC::Wrap(model));
}

NO_SANITIZE("cfi-icall")
bool HoneycombContextMenuHandlerCToCpp::RunContextMenu(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    HoneycombRefPtr<HoneycombContextMenuParams> params,
    HoneycombRefPtr<HoneycombMenuModel> model,
    HoneycombRefPtr<HoneycombRunContextMenuCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, run_context_menu)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get()) {
    return false;
  }
  // Verify param: model; type: refptr_diff
  DCHECK(model.get());
  if (!model.get()) {
    return false;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->run_context_menu(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      HoneycombContextMenuParamsCppToC::Wrap(params), HoneycombMenuModelCppToC::Wrap(model),
      HoneycombRunContextMenuCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombContextMenuHandlerCToCpp::OnContextMenuCommand(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    HoneycombRefPtr<HoneycombContextMenuParams> params,
    int command_id,
    EventFlags event_flags) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_context_menu_command)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->on_context_menu_command(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      HoneycombContextMenuParamsCppToC::Wrap(params), command_id, event_flags);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void HoneycombContextMenuHandlerCToCpp::OnContextMenuDismissed(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_context_menu_dismissed)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }

  // Execute
  _struct->on_context_menu_dismissed(_struct, HoneycombBrowserCppToC::Wrap(browser),
                                     HoneycombFrameCppToC::Wrap(frame));
}

NO_SANITIZE("cfi-icall")
bool HoneycombContextMenuHandlerCToCpp::RunQuickMenu(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    const HoneycombPoint& location,
    const HoneycombSize& size,
    QuickMenuEditStateFlags edit_state_flags,
    HoneycombRefPtr<HoneycombRunQuickMenuCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, run_quick_menu)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->run_quick_menu(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      &location, &size, edit_state_flags,
      HoneycombRunQuickMenuCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombContextMenuHandlerCToCpp::OnQuickMenuCommand(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    int command_id,
    EventFlags event_flags) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_quick_menu_command)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->on_quick_menu_command(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      command_id, event_flags);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void HoneycombContextMenuHandlerCToCpp::OnQuickMenuDismissed(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame) {
  shutdown_checker::AssertNotShutdown();

  honey_context_menu_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_quick_menu_dismissed)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }

  // Execute
  _struct->on_quick_menu_dismissed(_struct, HoneycombBrowserCppToC::Wrap(browser),
                                   HoneycombFrameCppToC::Wrap(frame));
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombContextMenuHandlerCToCpp::HoneycombContextMenuHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombContextMenuHandlerCToCpp::~HoneycombContextMenuHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_context_menu_handler_t* HoneycombCToCppRefCounted<
    HoneycombContextMenuHandlerCToCpp,
    HoneycombContextMenuHandler,
    honey_context_menu_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                               HoneycombContextMenuHandler* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombContextMenuHandlerCToCpp,
                                   HoneycombContextMenuHandler,
                                   honey_context_menu_handler_t>::kWrapperType =
    WT_CONTEXT_MENU_HANDLER;
