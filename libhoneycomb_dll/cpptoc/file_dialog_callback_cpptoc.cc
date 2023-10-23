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
// $hash=e203837c6db2beb403d762b9edef23817da8eefc$
//

#include "libhoneycomb_dll/cpptoc/file_dialog_callback_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
file_dialog_callback_cont(struct _honey_file_dialog_callback_t* self,
                          honey_string_list_t file_paths) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: file_paths

  // Translate param: file_paths; type: string_vec_byref_const
  std::vector<HoneycombString> file_pathsList;
  transfer_string_list_contents(file_paths, file_pathsList);

  // Execute
  HoneycombFileDialogCallbackCppToC::Get(self)->Continue(file_pathsList);
}

void HONEYCOMB_CALLBACK
file_dialog_callback_cancel(struct _honey_file_dialog_callback_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombFileDialogCallbackCppToC::Get(self)->Cancel();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombFileDialogCallbackCppToC::HoneycombFileDialogCallbackCppToC() {
  GetStruct()->cont = file_dialog_callback_cont;
  GetStruct()->cancel = file_dialog_callback_cancel;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombFileDialogCallbackCppToC::~HoneycombFileDialogCallbackCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombFileDialogCallback> HoneycombCppToCRefCounted<
    HoneycombFileDialogCallbackCppToC,
    HoneycombFileDialogCallback,
    honey_file_dialog_callback_t>::UnwrapDerived(HoneycombWrapperType type,
                                               honey_file_dialog_callback_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombFileDialogCallbackCppToC,
                                   HoneycombFileDialogCallback,
                                   honey_file_dialog_callback_t>::kWrapperType =
    WT_FILE_DIALOG_CALLBACK;
