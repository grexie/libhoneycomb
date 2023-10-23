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
// $hash=675f5f8b6e0738bb12326d53e3e8bfbb3e645f9b$
//

#include "libhoneycomb_dll/cpptoc/dialog_handler_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/file_dialog_callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
dialog_handler_on_file_dialog(struct _honey_dialog_handler_t* self,
                              honey_browser_t* browser,
                              honey_file_dialog_mode_t mode,
                              const honey_string_t* title,
                              const honey_string_t* default_file_path,
                              honey_string_list_t accept_filters,
                              honey_file_dialog_callback_t* callback) {
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
  // Unverified params: title, default_file_path, accept_filters

  // Translate param: accept_filters; type: string_vec_byref_const
  std::vector<HoneycombString> accept_filtersList;
  transfer_string_list_contents(accept_filters, accept_filtersList);

  // Execute
  bool _retval = HoneycombDialogHandlerCppToC::Get(self)->OnFileDialog(
      HoneycombBrowserCToCpp::Wrap(browser), mode, HoneycombString(title),
      HoneycombString(default_file_path), accept_filtersList,
      HoneycombFileDialogCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDialogHandlerCppToC::HoneycombDialogHandlerCppToC() {
  GetStruct()->on_file_dialog = dialog_handler_on_file_dialog;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDialogHandlerCppToC::~HoneycombDialogHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDialogHandler> HoneycombCppToCRefCounted<
    HoneycombDialogHandlerCppToC,
    HoneycombDialogHandler,
    honey_dialog_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                         honey_dialog_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombDialogHandlerCppToC,
                                   HoneycombDialogHandler,
                                   honey_dialog_handler_t>::kWrapperType =
    WT_DIALOG_HANDLER;
