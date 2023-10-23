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
// $hash=acd29552be49802a4b18bbce49109ac8df466e88$
//

#include "libhoney_dll/cpptoc/context_menu_handler_cpptoc.h"
#include "libhoney_dll/ctocpp/browser_ctocpp.h"
#include "libhoney_dll/ctocpp/context_menu_params_ctocpp.h"
#include "libhoney_dll/ctocpp/frame_ctocpp.h"
#include "libhoney_dll/ctocpp/menu_model_ctocpp.h"
#include "libhoney_dll/ctocpp/run_context_menu_callback_ctocpp.h"
#include "libhoney_dll/ctocpp/run_quick_menu_callback_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK context_menu_handler_on_before_context_menu(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame,
    struct _honey_context_menu_params_t* params,
    struct _honey_menu_model_t* model) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params) {
    return;
  }
  // Verify param: model; type: refptr_diff
  DCHECK(model);
  if (!model) {
    return;
  }

  // Execute
  HoneycombContextMenuHandlerCppToC::Get(self)->OnBeforeContextMenu(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombContextMenuParamsCToCpp::Wrap(params),
      HoneycombMenuModelCToCpp::Wrap(model));
}

int HONEYCOMB_CALLBACK context_menu_handler_run_context_menu(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame,
    struct _honey_context_menu_params_t* params,
    struct _honey_menu_model_t* model,
    honey_run_context_menu_callback_t* callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params) {
    return 0;
  }
  // Verify param: model; type: refptr_diff
  DCHECK(model);
  if (!model) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombContextMenuHandlerCppToC::Get(self)->RunContextMenu(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombContextMenuParamsCToCpp::Wrap(params), HoneycombMenuModelCToCpp::Wrap(model),
      HoneycombRunContextMenuCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK context_menu_handler_on_context_menu_command(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame,
    struct _honey_context_menu_params_t* params,
    int command_id,
    honey_event_flags_t event_flags) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombContextMenuHandlerCppToC::Get(self)->OnContextMenuCommand(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombContextMenuParamsCToCpp::Wrap(params), command_id, event_flags);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK context_menu_handler_on_context_menu_dismissed(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }

  // Execute
  HoneycombContextMenuHandlerCppToC::Get(self)->OnContextMenuDismissed(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame));
}

int HONEYCOMB_CALLBACK context_menu_handler_run_quick_menu(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame,
    const honey_point_t* location,
    const honey_size_t* size,
    honey_quick_menu_edit_state_flags_t edit_state_flags,
    honey_run_quick_menu_callback_t* callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }
  // Verify param: location; type: simple_byref_const
  DCHECK(location);
  if (!location) {
    return 0;
  }
  // Verify param: size; type: simple_byref_const
  DCHECK(size);
  if (!size) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Translate param: location; type: simple_byref_const
  HoneycombPoint locationVal = location ? *location : HoneycombPoint();
  // Translate param: size; type: simple_byref_const
  HoneycombSize sizeVal = size ? *size : HoneycombSize();

  // Execute
  bool _retval = HoneycombContextMenuHandlerCppToC::Get(self)->RunQuickMenu(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame), locationVal,
      sizeVal, edit_state_flags, HoneycombRunQuickMenuCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK context_menu_handler_on_quick_menu_command(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame,
    int command_id,
    honey_event_flags_t event_flags) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombContextMenuHandlerCppToC::Get(self)->OnQuickMenuCommand(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame), command_id,
      event_flags);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK context_menu_handler_on_quick_menu_dismissed(
    struct _honey_context_menu_handler_t* self,
    honey_browser_t* browser,
    struct _honey_frame_t* frame) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }

  // Execute
  HoneycombContextMenuHandlerCppToC::Get(self)->OnQuickMenuDismissed(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombContextMenuHandlerCppToC::HoneycombContextMenuHandlerCppToC() {
  GetStruct()->on_before_context_menu =
      context_menu_handler_on_before_context_menu;
  GetStruct()->run_context_menu = context_menu_handler_run_context_menu;
  GetStruct()->on_context_menu_command =
      context_menu_handler_on_context_menu_command;
  GetStruct()->on_context_menu_dismissed =
      context_menu_handler_on_context_menu_dismissed;
  GetStruct()->run_quick_menu = context_menu_handler_run_quick_menu;
  GetStruct()->on_quick_menu_command =
      context_menu_handler_on_quick_menu_command;
  GetStruct()->on_quick_menu_dismissed =
      context_menu_handler_on_quick_menu_dismissed;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombContextMenuHandlerCppToC::~HoneycombContextMenuHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombContextMenuHandler> HoneycombCppToCRefCounted<
    HoneycombContextMenuHandlerCppToC,
    HoneycombContextMenuHandler,
    honey_context_menu_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                               honey_context_menu_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombContextMenuHandlerCppToC,
                                   HoneycombContextMenuHandler,
                                   honey_context_menu_handler_t>::kWrapperType =
    WT_CONTEXT_MENU_HANDLER;