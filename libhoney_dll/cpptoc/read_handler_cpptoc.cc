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
// $hash=297d49ea4c02ae7ca19359c30bdcac380a45d95c$
//

#include "libhoney_dll/cpptoc/read_handler_cpptoc.h"
#include "libhoney_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

size_t HONEYCOMB_CALLBACK read_handler_read(struct _honey_read_handler_t* self,
                                      void* ptr,
                                      size_t size,
                                      size_t n) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombReadHandlerCppToC::Get(self)->Read(ptr, size, n);

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK read_handler_seek(struct _honey_read_handler_t* self,
                                   int64_t offset,
                                   int whence) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombReadHandlerCppToC::Get(self)->Seek(offset, whence);

  // Return type: simple
  return _retval;
}

int64_t HONEYCOMB_CALLBACK read_handler_tell(struct _honey_read_handler_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int64_t _retval = HoneycombReadHandlerCppToC::Get(self)->Tell();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK read_handler_eof(struct _honey_read_handler_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombReadHandlerCppToC::Get(self)->Eof();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK read_handler_may_block(struct _honey_read_handler_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombReadHandlerCppToC::Get(self)->MayBlock();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombReadHandlerCppToC::HoneycombReadHandlerCppToC() {
  GetStruct()->read = read_handler_read;
  GetStruct()->seek = read_handler_seek;
  GetStruct()->tell = read_handler_tell;
  GetStruct()->eof = read_handler_eof;
  GetStruct()->may_block = read_handler_may_block;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombReadHandlerCppToC::~HoneycombReadHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombReadHandler>
HoneycombCppToCRefCounted<HoneycombReadHandlerCppToC, HoneycombReadHandler, honey_read_handler_t>::
    UnwrapDerived(HoneycombWrapperType type, honey_read_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombReadHandlerCppToC,
                                   HoneycombReadHandler,
                                   honey_read_handler_t>::kWrapperType =
    WT_READ_HANDLER;