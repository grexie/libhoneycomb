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
// $hash=b13f9e52b84e1d9be3f7a43927002ae2e57d4636$
//

#include "libhoneycomb_dll/ctocpp/read_handler_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
size_t HoneycombReadHandlerCToCpp::Read(void* ptr, size_t size, size_t n) {
  shutdown_checker::AssertNotShutdown();

  honey_read_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, read)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr) {
    return 0;
  }

  // Execute
  size_t _retval = _struct->read(_struct, ptr, size, n);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
int HoneycombReadHandlerCToCpp::Seek(int64_t offset, int whence) {
  shutdown_checker::AssertNotShutdown();

  honey_read_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, seek)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->seek(_struct, offset, whence);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int64_t HoneycombReadHandlerCToCpp::Tell() {
  shutdown_checker::AssertNotShutdown();

  honey_read_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, tell)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int64_t _retval = _struct->tell(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int HoneycombReadHandlerCToCpp::Eof() {
  shutdown_checker::AssertNotShutdown();

  honey_read_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, eof)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->eof(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool HoneycombReadHandlerCToCpp::MayBlock() {
  shutdown_checker::AssertNotShutdown();

  honey_read_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, may_block)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->may_block(_struct);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombReadHandlerCToCpp::HoneycombReadHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombReadHandlerCToCpp::~HoneycombReadHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_read_handler_t*
HoneycombCToCppRefCounted<HoneycombReadHandlerCToCpp, HoneycombReadHandler, honey_read_handler_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombReadHandler* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombReadHandlerCToCpp,
                                   HoneycombReadHandler,
                                   honey_read_handler_t>::kWrapperType =
    WT_READ_HANDLER;
