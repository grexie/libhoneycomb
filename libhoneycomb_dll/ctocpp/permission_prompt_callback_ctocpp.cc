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
// $hash=a84aa33807e480e03cc065b3b195d2fcf766cbfb$
//

#include "libhoneycomb_dll/ctocpp/permission_prompt_callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombPermissionPromptCallbackCToCpp::Continue(
    honey_permission_request_result_t result) {
  shutdown_checker::AssertNotShutdown();

  honey_permission_prompt_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, cont)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cont(_struct, result);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombPermissionPromptCallbackCToCpp::HoneycombPermissionPromptCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombPermissionPromptCallbackCToCpp::~HoneycombPermissionPromptCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_permission_prompt_callback_t*
HoneycombCToCppRefCounted<HoneycombPermissionPromptCallbackCToCpp,
                    HoneycombPermissionPromptCallback,
                    honey_permission_prompt_callback_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombPermissionPromptCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCToCppRefCounted<HoneycombPermissionPromptCallbackCToCpp,
                        HoneycombPermissionPromptCallback,
                        honey_permission_prompt_callback_t>::kWrapperType =
        WT_PERMISSION_PROMPT_CALLBACK;
