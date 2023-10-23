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
// $hash=0e5888697a0b34492333d0e07af507ebedee4b3b$
//

#include "libhoney_dll/cpptoc/jsdialog_handler_cpptoc.h"
#include "libhoney_dll/ctocpp/browser_ctocpp.h"
#include "libhoney_dll/ctocpp/jsdialog_callback_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
jsdialog_handler_on_jsdialog(struct _honey_jsdialog_handler_t* self,
                             honey_browser_t* browser,
                             const honey_string_t* origin_url,
                             honey_jsdialog_type_t dialog_type,
                             const honey_string_t* message_text,
                             const honey_string_t* default_prompt_text,
                             honey_jsdialog_callback_t* callback,
                             int* suppress_message) {
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
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }
  // Verify param: suppress_message; type: bool_byref
  DCHECK(suppress_message);
  if (!suppress_message) {
    return 0;
  }
  // Unverified params: origin_url, message_text, default_prompt_text

  // Translate param: suppress_message; type: bool_byref
  bool suppress_messageBool =
      (suppress_message && *suppress_message) ? true : false;

  // Execute
  bool _retval = HoneycombJSDialogHandlerCppToC::Get(self)->OnJSDialog(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(origin_url), dialog_type,
      HoneycombString(message_text), HoneycombString(default_prompt_text),
      HoneycombJSDialogCallbackCToCpp::Wrap(callback), suppress_messageBool);

  // Restore param: suppress_message; type: bool_byref
  if (suppress_message) {
    *suppress_message = suppress_messageBool ? true : false;
  }

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
jsdialog_handler_on_before_unload_dialog(struct _honey_jsdialog_handler_t* self,
                                         honey_browser_t* browser,
                                         const honey_string_t* message_text,
                                         int is_reload,
                                         honey_jsdialog_callback_t* callback) {
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
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }
  // Unverified params: message_text

  // Execute
  bool _retval = HoneycombJSDialogHandlerCppToC::Get(self)->OnBeforeUnloadDialog(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(message_text),
      is_reload ? true : false, HoneycombJSDialogCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
jsdialog_handler_on_reset_dialog_state(struct _honey_jsdialog_handler_t* self,
                                       honey_browser_t* browser) {
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

  // Execute
  HoneycombJSDialogHandlerCppToC::Get(self)->OnResetDialogState(
      HoneycombBrowserCToCpp::Wrap(browser));
}

void HONEYCOMB_CALLBACK
jsdialog_handler_on_dialog_closed(struct _honey_jsdialog_handler_t* self,
                                  honey_browser_t* browser) {
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

  // Execute
  HoneycombJSDialogHandlerCppToC::Get(self)->OnDialogClosed(
      HoneycombBrowserCToCpp::Wrap(browser));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombJSDialogHandlerCppToC::HoneycombJSDialogHandlerCppToC() {
  GetStruct()->on_jsdialog = jsdialog_handler_on_jsdialog;
  GetStruct()->on_before_unload_dialog =
      jsdialog_handler_on_before_unload_dialog;
  GetStruct()->on_reset_dialog_state = jsdialog_handler_on_reset_dialog_state;
  GetStruct()->on_dialog_closed = jsdialog_handler_on_dialog_closed;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombJSDialogHandlerCppToC::~HoneycombJSDialogHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombJSDialogHandler> HoneycombCppToCRefCounted<
    HoneycombJSDialogHandlerCppToC,
    HoneycombJSDialogHandler,
    honey_jsdialog_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                           honey_jsdialog_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombJSDialogHandlerCppToC,
                                   HoneycombJSDialogHandler,
                                   honey_jsdialog_handler_t>::kWrapperType =
    WT_JSDIALOG_HANDLER;