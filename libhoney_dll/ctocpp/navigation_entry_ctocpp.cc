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
// $hash=4adb66632fea25a6f73e03ee839cc77567841db2$
//

#include "libhoney_dll/ctocpp/navigation_entry_ctocpp.h"
#include "libhoney_dll/ctocpp/sslstatus_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool HoneycombNavigationEntryCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_valid)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombNavigationEntryCToCpp::GetURL() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_url)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_url(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombNavigationEntryCToCpp::GetDisplayURL() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_display_url)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_display_url(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombNavigationEntryCToCpp::GetOriginalURL() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_original_url)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_original_url(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombNavigationEntryCToCpp::GetTitle() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_title)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_title(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
HoneycombNavigationEntry::TransitionType
HoneycombNavigationEntryCToCpp::GetTransitionType() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_transition_type)) {
    return TT_EXPLICIT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_transition_type_t _retval = _struct->get_transition_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool HoneycombNavigationEntryCToCpp::HasPostData() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, has_post_data)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->has_post_data(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
HoneycombBaseTime HoneycombNavigationEntryCToCpp::GetCompletionTime() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_completion_time)) {
    return HoneycombBaseTime();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_basetime_t _retval = _struct->get_completion_time(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int HoneycombNavigationEntryCToCpp::GetHttpStatusCode() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_http_status_code)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_http_status_code(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombSSLStatus> HoneycombNavigationEntryCToCpp::GetSSLStatus() {
  shutdown_checker::AssertNotShutdown();

  honey_navigation_entry_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_sslstatus)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_sslstatus_t* _retval = _struct->get_sslstatus(_struct);

  // Return type: refptr_same
  return HoneycombSSLStatusCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombNavigationEntryCToCpp::HoneycombNavigationEntryCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombNavigationEntryCToCpp::~HoneycombNavigationEntryCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_navigation_entry_t* HoneycombCToCppRefCounted<
    HoneycombNavigationEntryCToCpp,
    HoneycombNavigationEntry,
    honey_navigation_entry_t>::UnwrapDerived(HoneycombWrapperType type,
                                           HoneycombNavigationEntry* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombNavigationEntryCToCpp,
                                   HoneycombNavigationEntry,
                                   honey_navigation_entry_t>::kWrapperType =
    WT_NAVIGATION_ENTRY;