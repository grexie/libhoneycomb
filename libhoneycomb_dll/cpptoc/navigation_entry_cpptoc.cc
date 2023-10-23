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
// $hash=72992a0b2546d13e29617ad20d69c31243b68305$
//

#include "libhoneycomb_dll/cpptoc/navigation_entry_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/sslstatus_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
navigation_entry_is_valid(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombNavigationEntryCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
navigation_entry_get_url(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombNavigationEntryCppToC::Get(self)->GetURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
navigation_entry_get_display_url(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombNavigationEntryCppToC::Get(self)->GetDisplayURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
navigation_entry_get_original_url(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombNavigationEntryCppToC::Get(self)->GetOriginalURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
navigation_entry_get_title(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombNavigationEntryCppToC::Get(self)->GetTitle();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_transition_type_t HONEYCOMB_CALLBACK
navigation_entry_get_transition_type(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return TT_EXPLICIT;
  }

  // Execute
  honey_transition_type_t _retval =
      HoneycombNavigationEntryCppToC::Get(self)->GetTransitionType();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
navigation_entry_has_post_data(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombNavigationEntryCppToC::Get(self)->HasPostData();

  // Return type: bool
  return _retval;
}

honey_basetime_t HONEYCOMB_CALLBACK
navigation_entry_get_completion_time(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombBaseTime();
  }

  // Execute
  honey_basetime_t _retval =
      HoneycombNavigationEntryCppToC::Get(self)->GetCompletionTime();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
navigation_entry_get_http_status_code(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombNavigationEntryCppToC::Get(self)->GetHttpStatusCode();

  // Return type: simple
  return _retval;
}

struct _honey_sslstatus_t* HONEYCOMB_CALLBACK
navigation_entry_get_sslstatus(struct _honey_navigation_entry_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombSSLStatus> _retval =
      HoneycombNavigationEntryCppToC::Get(self)->GetSSLStatus();

  // Return type: refptr_same
  return HoneycombSSLStatusCppToC::Wrap(_retval);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombNavigationEntryCppToC::HoneycombNavigationEntryCppToC() {
  GetStruct()->is_valid = navigation_entry_is_valid;
  GetStruct()->get_url = navigation_entry_get_url;
  GetStruct()->get_display_url = navigation_entry_get_display_url;
  GetStruct()->get_original_url = navigation_entry_get_original_url;
  GetStruct()->get_title = navigation_entry_get_title;
  GetStruct()->get_transition_type = navigation_entry_get_transition_type;
  GetStruct()->has_post_data = navigation_entry_has_post_data;
  GetStruct()->get_completion_time = navigation_entry_get_completion_time;
  GetStruct()->get_http_status_code = navigation_entry_get_http_status_code;
  GetStruct()->get_sslstatus = navigation_entry_get_sslstatus;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombNavigationEntryCppToC::~HoneycombNavigationEntryCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombNavigationEntry> HoneycombCppToCRefCounted<
    HoneycombNavigationEntryCppToC,
    HoneycombNavigationEntry,
    honey_navigation_entry_t>::UnwrapDerived(HoneycombWrapperType type,
                                           honey_navigation_entry_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombNavigationEntryCppToC,
                                   HoneycombNavigationEntry,
                                   honey_navigation_entry_t>::kWrapperType =
    WT_NAVIGATION_ENTRY;
