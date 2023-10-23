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
// $hash=01b28525b4e9c9d1245d7d910f1a45716ade9963$
//

#include "libhoney_dll/cpptoc/stream_writer_cpptoc.h"
#include "libhoney_dll/ctocpp/write_handler_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_stream_writer_t* honey_stream_writer_create_for_file(
    const honey_string_t* fileName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: fileName; type: string_byref_const
  DCHECK(fileName);
  if (!fileName) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombStreamWriter> _retval =
      HoneycombStreamWriter::CreateForFile(HoneycombString(fileName));

  // Return type: refptr_same
  return HoneycombStreamWriterCppToC::Wrap(_retval);
}

HONEYCOMB_EXPORT honey_stream_writer_t* honey_stream_writer_create_for_handler(
    honey_write_handler_t* handler) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: handler; type: refptr_diff
  DCHECK(handler);
  if (!handler) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombStreamWriter> _retval =
      HoneycombStreamWriter::CreateForHandler(HoneycombWriteHandlerCToCpp::Wrap(handler));

  // Return type: refptr_same
  return HoneycombStreamWriterCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

size_t HONEYCOMB_CALLBACK stream_writer_write(struct _honey_stream_writer_t* self,
                                        const void* ptr,
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
  size_t _retval = HoneycombStreamWriterCppToC::Get(self)->Write(ptr, size, n);

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK stream_writer_seek(struct _honey_stream_writer_t* self,
                                    int64_t offset,
                                    int whence) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombStreamWriterCppToC::Get(self)->Seek(offset, whence);

  // Return type: simple
  return _retval;
}

int64_t HONEYCOMB_CALLBACK stream_writer_tell(struct _honey_stream_writer_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int64_t _retval = HoneycombStreamWriterCppToC::Get(self)->Tell();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK stream_writer_flush(struct _honey_stream_writer_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombStreamWriterCppToC::Get(self)->Flush();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK stream_writer_may_block(struct _honey_stream_writer_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombStreamWriterCppToC::Get(self)->MayBlock();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombStreamWriterCppToC::HoneycombStreamWriterCppToC() {
  GetStruct()->write = stream_writer_write;
  GetStruct()->seek = stream_writer_seek;
  GetStruct()->tell = stream_writer_tell;
  GetStruct()->flush = stream_writer_flush;
  GetStruct()->may_block = stream_writer_may_block;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombStreamWriterCppToC::~HoneycombStreamWriterCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombStreamWriter> HoneycombCppToCRefCounted<
    HoneycombStreamWriterCppToC,
    HoneycombStreamWriter,
    honey_stream_writer_t>::UnwrapDerived(HoneycombWrapperType type,
                                        honey_stream_writer_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombStreamWriterCppToC,
                                   HoneycombStreamWriter,
                                   honey_stream_writer_t>::kWrapperType =
    WT_STREAM_WRITER;