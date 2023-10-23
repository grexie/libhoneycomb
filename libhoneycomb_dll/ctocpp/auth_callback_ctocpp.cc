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
// $hash=b2c9b6c79bcd7f510d9cb521a15f761eda23e7ef$
//

#include "libhoneycomb_dll/ctocpp/auth_callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombAuthCallbackCToCpp::Continue(const HoneycombString& username,
                                     const HoneycombString& password) {
  shutdown_checker::AssertNotShutdown();

  honey_auth_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, cont)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: username, password

  // Execute
  _struct->cont(_struct, username.GetStruct(), password.GetStruct());
}

NO_SANITIZE("cfi-icall") void HoneycombAuthCallbackCToCpp::Cancel() {
  shutdown_checker::AssertNotShutdown();

  honey_auth_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, cancel)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cancel(_struct);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombAuthCallbackCToCpp::HoneycombAuthCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombAuthCallbackCToCpp::~HoneycombAuthCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_auth_callback_t*
HoneycombCToCppRefCounted<HoneycombAuthCallbackCToCpp,
                    HoneycombAuthCallback,
                    honey_auth_callback_t>::UnwrapDerived(HoneycombWrapperType type,
                                                        HoneycombAuthCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombAuthCallbackCToCpp,
                                   HoneycombAuthCallback,
                                   honey_auth_callback_t>::kWrapperType =
    WT_AUTH_CALLBACK;
