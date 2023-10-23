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
// $hash=2249e1f0ad86dad3cfac6755c79e3a114d11f4f9$
//

#include "libhoneycomb_dll/cpptoc/print_handler_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/print_dialog_callback_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/print_job_callback_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/print_settings_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
print_handler_on_print_start(struct _honey_print_handler_t* self,
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
  HoneycombPrintHandlerCppToC::Get(self)->OnPrintStart(
      HoneycombBrowserCToCpp::Wrap(browser));
}

void HONEYCOMB_CALLBACK
print_handler_on_print_settings(struct _honey_print_handler_t* self,
                                honey_browser_t* browser,
                                struct _honey_print_settings_t* settings,
                                int get_defaults) {
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
  // Verify param: settings; type: refptr_diff
  DCHECK(settings);
  if (!settings) {
    return;
  }

  // Execute
  HoneycombPrintHandlerCppToC::Get(self)->OnPrintSettings(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombPrintSettingsCToCpp::Wrap(settings),
      get_defaults ? true : false);
}

int HONEYCOMB_CALLBACK
print_handler_on_print_dialog(struct _honey_print_handler_t* self,
                              honey_browser_t* browser,
                              int has_selection,
                              honey_print_dialog_callback_t* callback) {
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

  // Execute
  bool _retval = HoneycombPrintHandlerCppToC::Get(self)->OnPrintDialog(
      HoneycombBrowserCToCpp::Wrap(browser), has_selection ? true : false,
      HoneycombPrintDialogCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
print_handler_on_print_job(struct _honey_print_handler_t* self,
                           honey_browser_t* browser,
                           const honey_string_t* document_name,
                           const honey_string_t* pdf_file_path,
                           honey_print_job_callback_t* callback) {
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
  // Verify param: document_name; type: string_byref_const
  DCHECK(document_name);
  if (!document_name) {
    return 0;
  }
  // Verify param: pdf_file_path; type: string_byref_const
  DCHECK(pdf_file_path);
  if (!pdf_file_path) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombPrintHandlerCppToC::Get(self)->OnPrintJob(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(document_name),
      HoneycombString(pdf_file_path), HoneycombPrintJobCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
print_handler_on_print_reset(struct _honey_print_handler_t* self,
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
  HoneycombPrintHandlerCppToC::Get(self)->OnPrintReset(
      HoneycombBrowserCToCpp::Wrap(browser));
}

honey_size_t HONEYCOMB_CALLBACK
print_handler_get_pdf_paper_size(struct _honey_print_handler_t* self,
                                 honey_browser_t* browser,
                                 int device_units_per_inch) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombSize();
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return HoneycombSize();
  }

  // Execute
  honey_size_t _retval = HoneycombPrintHandlerCppToC::Get(self)->GetPdfPaperSize(
      HoneycombBrowserCToCpp::Wrap(browser), device_units_per_inch);

  // Return type: simple
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombPrintHandlerCppToC::HoneycombPrintHandlerCppToC() {
  GetStruct()->on_print_start = print_handler_on_print_start;
  GetStruct()->on_print_settings = print_handler_on_print_settings;
  GetStruct()->on_print_dialog = print_handler_on_print_dialog;
  GetStruct()->on_print_job = print_handler_on_print_job;
  GetStruct()->on_print_reset = print_handler_on_print_reset;
  GetStruct()->get_pdf_paper_size = print_handler_get_pdf_paper_size;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombPrintHandlerCppToC::~HoneycombPrintHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombPrintHandler> HoneycombCppToCRefCounted<
    HoneycombPrintHandlerCppToC,
    HoneycombPrintHandler,
    honey_print_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                        honey_print_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombPrintHandlerCppToC,
                                   HoneycombPrintHandler,
                                   honey_print_handler_t>::kWrapperType =
    WT_PRINT_HANDLER;
