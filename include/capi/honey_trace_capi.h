// Copyright (c) 2023 Marshall A. Greenblatt. All rights reserved.
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
// This file was generated by the Honeycomb translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=28e2d2d86dffdfdad0f275a444656a0638b44d0e$
//

#ifndef HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_TRACE_CAPI_H_
#define HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_TRACE_CAPI_H_
#pragma once

#include "include/capi/honey_base_capi.h"
#include "include/capi/honey_callback_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// Implement this structure to receive notification when tracing has completed.
/// The functions of this structure will be called on the browser process UI
/// thread.
///
typedef struct _honey_end_tracing_callback_t {
  ///
  /// Base structure.
  ///
  honey_base_ref_counted_t base;

  ///
  /// Called after all processes have sent their trace data. |tracing_file| is
  /// the path at which tracing data was written. The client is responsible for
  /// deleting |tracing_file|.
  ///
  void(HONEYCOMB_CALLBACK* on_end_tracing_complete)(
      struct _honey_end_tracing_callback_t* self,
      const honey_string_t* tracing_file);
} honey_end_tracing_callback_t;

///
/// Start tracing events on all processes. Tracing is initialized asynchronously
/// and |callback| will be executed on the UI thread after initialization is
/// complete.
///
/// If HoneycombBeginTracing was called previously, or if a HoneycombEndTracingAsync call is
/// pending, HoneycombBeginTracing will fail and return false (0).
///
/// |categories| is a comma-delimited list of category wildcards. A category can
/// have an optional '-' prefix to make it an excluded category. Having both
/// included and excluded categories in the same list is not supported.
///
/// Examples: - "test_MyTest*" - "test_MyTest*,test_OtherStuff" -
/// "-excluded_category1,-excluded_category2"
///
/// This function must be called on the browser process UI thread.
///
HONEYCOMB_EXPORT int honey_begin_tracing(const honey_string_t* categories,
                                 struct _honey_completion_callback_t* callback);

///
/// Stop tracing events on all processes.
///
/// This function will fail and return false (0) if a previous call to
/// HoneycombEndTracingAsync is already pending or if HoneycombBeginTracing was not called.
///
/// |tracing_file| is the path at which tracing data will be written and
/// |callback| is the callback that will be executed once all processes have
/// sent their trace data. If |tracing_file| is NULL a new temporary file path
/// will be used. If |callback| is NULL no trace data will be written.
///
/// This function must be called on the browser process UI thread.
///
HONEYCOMB_EXPORT int honey_end_tracing(const honey_string_t* tracing_file,
                               honey_end_tracing_callback_t* callback);

///
/// Returns the current system trace time or, if none is defined, the current
/// high-res time. Can be used by clients to synchronize with the time
/// information in trace events.
///
HONEYCOMB_EXPORT int64_t honey_now_from_system_trace_time(void);

#ifdef __cplusplus
}
#endif

#endif  // HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_TRACE_CAPI_H_