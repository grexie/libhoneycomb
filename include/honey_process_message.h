// Copyright (c) 2012 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// The contents of this file must follow a specific format in order to
// support the Honeycomb translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef HONEYCOMB_INCLUDE_HONEYCOMB_MESSAGE_H_
#define HONEYCOMB_INCLUDE_HONEYCOMB_MESSAGE_H_
#pragma once

#include "include/honey_base.h"
#include "include/honey_shared_memory_region.h"
#include "include/honey_values.h"

typedef honey_process_id_t HoneycombProcessId;

///
/// Class representing a message. Can be used on any process and thread.
///
/*--honey(source=library)--*/
class HoneycombProcessMessage : public virtual HoneycombBaseRefCounted {
 public:
  ///
  /// Create a new HoneycombProcessMessage object with the specified name.
  ///
  /*--honey()--*/
  static HoneycombRefPtr<HoneycombProcessMessage> Create(const HoneycombString& name);

  ///
  /// Returns true if this object is valid. Do not call any other methods if
  /// this function returns false.
  ///
  /*--honey()--*/
  virtual bool IsValid() = 0;

  ///
  /// Returns true if the values of this object are read-only. Some APIs may
  /// expose read-only objects.
  ///
  /*--honey()--*/
  virtual bool IsReadOnly() = 0;

  ///
  /// Returns a writable copy of this object.
  /// Returns nullptr when message contains a shared memory region.
  ///
  /*--honey()--*/
  virtual HoneycombRefPtr<HoneycombProcessMessage> Copy() = 0;

  ///
  /// Returns the message name.
  ///
  /*--honey()--*/
  virtual HoneycombString GetName() = 0;

  ///
  /// Returns the list of arguments.
  /// Returns nullptr when message contains a shared memory region.
  ///
  /*--honey()--*/
  virtual HoneycombRefPtr<HoneycombListValue> GetArgumentList() = 0;

  ///
  /// Returns the shared memory region.
  /// Returns nullptr when message contains an argument list.
  ///
  /*--honey()--*/
  virtual HoneycombRefPtr<HoneycombSharedMemoryRegion> GetSharedMemoryRegion() = 0;
};

#endif  // HONEYCOMB_INCLUDE_HONEYCOMB_MESSAGE_H_
