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
// $hash=f8ac1c909cbcf2dfa78c14cfc790b5ea01b11dde$
//

#include "libhoneycomb_dll/ctocpp/request_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/post_data_ctocpp.h"
#include "libhoneycomb_dll/transfer_util.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") HoneycombRefPtr<HoneycombRequest> HoneycombRequest::Create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_request_t* _retval = honey_request_create();

  // Return type: refptr_same
  return HoneycombRequestCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool HoneycombRequestCToCpp::IsReadOnly() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_read_only)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_read_only(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombRequestCToCpp::GetURL() {
  honey_request_t* _struct = GetStruct();
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

NO_SANITIZE("cfi-icall") void HoneycombRequestCToCpp::SetURL(const HoneycombString& url) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_url)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty()) {
    return;
  }

  // Execute
  _struct->set_url(_struct, url.GetStruct());
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombRequestCToCpp::GetMethod() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_method)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_method(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetMethod(const HoneycombString& method) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_method)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: method; type: string_byref_const
  DCHECK(!method.empty());
  if (method.empty()) {
    return;
  }

  // Execute
  _struct->set_method(_struct, method.GetStruct());
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetReferrer(const HoneycombString& referrer_url,
                                   ReferrerPolicy policy) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_referrer)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: referrer_url

  // Execute
  _struct->set_referrer(_struct, referrer_url.GetStruct(), policy);
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombRequestCToCpp::GetReferrerURL() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_referrer_url)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_referrer_url(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
HoneycombRequest::ReferrerPolicy HoneycombRequestCToCpp::GetReferrerPolicy() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_referrer_policy)) {
    return REFERRER_POLICY_DEFAULT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_referrer_policy_t _retval = _struct->get_referrer_policy(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombPostData> HoneycombRequestCToCpp::GetPostData() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_post_data)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_post_data_t* _retval = _struct->get_post_data(_struct);

  // Return type: refptr_same
  return HoneycombPostDataCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetPostData(HoneycombRefPtr<HoneycombPostData> postData) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_post_data)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: postData; type: refptr_same
  DCHECK(postData.get());
  if (!postData.get()) {
    return;
  }

  // Execute
  _struct->set_post_data(_struct, HoneycombPostDataCToCpp::Unwrap(postData));
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::GetHeaderMap(HeaderMap& headerMap) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_header_map)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: headerMap; type: string_map_multi_byref
  honey_string_multimap_t headerMapMultimap = honey_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->get_header_map(_struct, headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref
  if (headerMapMultimap) {
    headerMap.clear();
    transfer_string_multimap_contents(headerMapMultimap, headerMap);
    honey_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetHeaderMap(const HeaderMap& headerMap) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_header_map)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: headerMap; type: string_map_multi_byref_const
  honey_string_multimap_t headerMapMultimap = honey_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->set_header_map(_struct, headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref_const
  if (headerMapMultimap) {
    honey_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall")
HoneycombString HoneycombRequestCToCpp::GetHeaderByName(const HoneycombString& name) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_header_by_name)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return HoneycombString();
  }

  // Execute
  honey_string_userfree_t _retval =
      _struct->get_header_by_name(_struct, name.GetStruct());

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetHeaderByName(const HoneycombString& name,
                                       const HoneycombString& value,
                                       bool overwrite) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_header_by_name)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return;
  }
  // Unverified params: value

  // Execute
  _struct->set_header_by_name(_struct, name.GetStruct(), value.GetStruct(),
                              overwrite);
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::Set(const HoneycombString& url,
                           const HoneycombString& method,
                           HoneycombRefPtr<HoneycombPostData> postData,
                           const HeaderMap& headerMap) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty()) {
    return;
  }
  // Verify param: method; type: string_byref_const
  DCHECK(!method.empty());
  if (method.empty()) {
    return;
  }
  // Unverified params: postData

  // Translate param: headerMap; type: string_map_multi_byref_const
  honey_string_multimap_t headerMapMultimap = honey_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->set(_struct, url.GetStruct(), method.GetStruct(),
               HoneycombPostDataCToCpp::Unwrap(postData), headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref_const
  if (headerMapMultimap) {
    honey_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall") int HoneycombRequestCToCpp::GetFlags() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_flags)) {
    return UR_FLAG_NONE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_flags(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void HoneycombRequestCToCpp::SetFlags(int flags) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_flags)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_flags(_struct, flags);
}

NO_SANITIZE("cfi-icall") HoneycombString HoneycombRequestCToCpp::GetFirstPartyForCookies() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_first_party_for_cookies)) {
    return HoneycombString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_string_userfree_t _retval = _struct->get_first_party_for_cookies(_struct);

  // Return type: string
  HoneycombString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestCToCpp::SetFirstPartyForCookies(const HoneycombString& url) {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_first_party_for_cookies)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: url

  // Execute
  _struct->set_first_party_for_cookies(_struct, url.GetStruct());
}

NO_SANITIZE("cfi-icall")
HoneycombRequest::ResourceType HoneycombRequestCToCpp::GetResourceType() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_resource_type)) {
    return RT_SUB_RESOURCE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_resource_type_t _retval = _struct->get_resource_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
HoneycombRequest::TransitionType HoneycombRequestCToCpp::GetTransitionType() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_transition_type)) {
    return TT_EXPLICIT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_transition_type_t _retval = _struct->get_transition_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") uint64_t HoneycombRequestCToCpp::GetIdentifier() {
  honey_request_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_identifier)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  uint64_t _retval = _struct->get_identifier(_struct);

  // Return type: simple
  return _retval;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombRequestCToCpp::HoneycombRequestCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombRequestCToCpp::~HoneycombRequestCToCpp() {}

template <>
honey_request_t*
HoneycombCToCppRefCounted<HoneycombRequestCToCpp, HoneycombRequest, honey_request_t>::UnwrapDerived(
    HoneycombWrapperType type,
    HoneycombRequest* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombRequestCToCpp,
                                   HoneycombRequest,
                                   honey_request_t>::kWrapperType = WT_REQUEST;
