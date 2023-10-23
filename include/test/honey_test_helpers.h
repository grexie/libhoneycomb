// Copyright (c) 2017 Marshall A. Greenblatt. All rights reserved.
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
// THIS FILE IS FOR TESTING PURPOSES ONLY.
//
// The APIs defined in this file are for testing purposes only. They should only
// be included from unit test targets.
//

#ifndef HONEYCOMB_INCLUDE_TEST_HONEYCOMB_TEST_HELPERS_H_
#define HONEYCOMB_INCLUDE_TEST_HONEYCOMB_TEST_HELPERS_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED) && !defined(WRAPPING_HONEYCOMB_SHARED) && \
    !defined(UNIT_TEST)
#error This file can be included for unit tests only
#endif

#include "include/honey_frame.h"

///
/// Execute JavaScript with a user gesture to trigger functionality like
/// onbeforeunload handlers that will otherwise be blocked.
///
/*--honey(optional_param=javascript)--*/
void HoneycombExecuteJavaScriptWithUserGestureForTests(HoneycombRefPtr<HoneycombFrame> frame,
                                                 const HoneycombString& javascript);

///
/// Set the DIR_SRC_TEST_DATA_ROOT directory used to load test data. Must be
/// configured when running from a Honeycomb binary distribution. Defaults to the
/// "chromium/src" directory when running from a local Honeycomb build. |dir|
/// must be an absolute path.
///
/*--honey()--*/
void HoneycombSetDataDirectoryForTests(const HoneycombString& dir);

#endif  // HONEYCOMB_INCLUDE_TEST_HONEYCOMB_TEST_HELPERS_H_
