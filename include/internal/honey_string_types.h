// Copyright (c) 2010 Marshall A. Greenblatt. All rights reserved.
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

#ifndef HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_STRING_TYPES_H_
#define HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_STRING_TYPES_H_
#pragma once

#include <stddef.h>

#ifdef __clang__
// On macOS, <uchar.h> is only available with Xcode 14.3+.
#if __has_include(<uchar.h>)
#include <uchar.h>
#elif !defined(__cplusplus)
#include <stdint.h>
typedef uint_least16_t char16_t;
#endif
#else
#include <uchar.h>
#endif

#include "include/internal/honey_export.h"

///
/// \file
/// Honeycomb provides functions for converting between UTF-8, -16 and -32 strings.
/// Honeycomb string types are safe for reading from multiple threads but not for
/// modification. It is the user's responsibility to provide synchronization if
/// modifying Honeycomb strings from multiple threads.
///

#ifdef __cplusplus
extern "C" {
#endif

///
/// Honeycomb string type definitions. Whomever allocates |str| is responsible for
/// providing an appropriate |dtor| implementation that will free the string in
/// the same memory space. When reusing an existing string structure make sure
/// to call |dtor| for the old value before assigning new |str| and |dtor|
/// values. Static strings will have a NULL |dtor| value. Using the below
/// functions if you want this managed for you.
///

typedef struct _honey_string_wide_t {
  wchar_t* str;
  size_t length;
  void (*dtor)(wchar_t* str);
} honey_string_wide_t;

typedef struct _honey_string_utf8_t {
  char* str;
  size_t length;
  void (*dtor)(char* str);
} honey_string_utf8_t;

typedef struct _honey_string_utf16_t {
  char16_t* str;
  size_t length;
  void (*dtor)(char16_t* str);
} honey_string_utf16_t;

///
/// These functions set string values. If |copy| is true (1) the value will be
/// copied instead of referenced. It is up to the user to properly manage
/// the lifespan of references.
///

HONEYCOMB_EXPORT int honey_string_wide_set(const wchar_t* src,
                                   size_t src_len,
                                   honey_string_wide_t* output,
                                   int copy);
HONEYCOMB_EXPORT int honey_string_utf8_set(const char* src,
                                   size_t src_len,
                                   honey_string_utf8_t* output,
                                   int copy);
HONEYCOMB_EXPORT int honey_string_utf16_set(const char16_t* src,
                                    size_t src_len,
                                    honey_string_utf16_t* output,
                                    int copy);

///
/// Convenience macros for copying values.
///

#define honey_string_wide_copy(src, src_len, output) \
  honey_string_wide_set(src, src_len, output, true)
#define honey_string_utf8_copy(src, src_len, output) \
  honey_string_utf8_set(src, src_len, output, true)
#define honey_string_utf16_copy(src, src_len, output) \
  honey_string_utf16_set(src, src_len, output, true)

///
/// These functions clear string values. The structure itself is not freed.
///

HONEYCOMB_EXPORT void honey_string_wide_clear(honey_string_wide_t* str);
HONEYCOMB_EXPORT void honey_string_utf8_clear(honey_string_utf8_t* str);
HONEYCOMB_EXPORT void honey_string_utf16_clear(honey_string_utf16_t* str);

///
/// These functions compare two string values with the same results as strcmp().
///

HONEYCOMB_EXPORT int honey_string_wide_cmp(const honey_string_wide_t* str1,
                                   const honey_string_wide_t* str2);
HONEYCOMB_EXPORT int honey_string_utf8_cmp(const honey_string_utf8_t* str1,
                                   const honey_string_utf8_t* str2);
HONEYCOMB_EXPORT int honey_string_utf16_cmp(const honey_string_utf16_t* str1,
                                    const honey_string_utf16_t* str2);

///
/// These functions convert between UTF-8, -16, and -32 strings. They are
/// potentially slow so unnecessary conversions should be avoided. The best
/// possible result will always be written to |output| with the boolean return
/// value indicating whether the conversion is 100% valid.
///

HONEYCOMB_EXPORT int honey_string_wide_to_utf8(const wchar_t* src,
                                       size_t src_len,
                                       honey_string_utf8_t* output);
HONEYCOMB_EXPORT int honey_string_utf8_to_wide(const char* src,
                                       size_t src_len,
                                       honey_string_wide_t* output);

HONEYCOMB_EXPORT int honey_string_wide_to_utf16(const wchar_t* src,
                                        size_t src_len,
                                        honey_string_utf16_t* output);
HONEYCOMB_EXPORT int honey_string_utf16_to_wide(const char16_t* src,
                                        size_t src_len,
                                        honey_string_wide_t* output);

HONEYCOMB_EXPORT int honey_string_utf8_to_utf16(const char* src,
                                        size_t src_len,
                                        honey_string_utf16_t* output);
HONEYCOMB_EXPORT int honey_string_utf16_to_utf8(const char16_t* src,
                                        size_t src_len,
                                        honey_string_utf8_t* output);

///
/// These functions convert an ASCII string, typically a hardcoded constant, to
/// a Wide/UTF16 string. Use instead of the UTF8 conversion routines if you know
/// the string is ASCII.
///

HONEYCOMB_EXPORT int honey_string_ascii_to_wide(const char* src,
                                        size_t src_len,
                                        honey_string_wide_t* output);
HONEYCOMB_EXPORT int honey_string_ascii_to_utf16(const char* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output);

///
/// It is sometimes necessary for the system to allocate string structures with
/// the expectation that the user will free them. The userfree types act as a
/// hint that the user is responsible for freeing the structure.
///

typedef honey_string_wide_t* honey_string_userfree_wide_t;
typedef honey_string_utf8_t* honey_string_userfree_utf8_t;
typedef honey_string_utf16_t* honey_string_userfree_utf16_t;

///
/// These functions allocate a new string structure. They must be freed by
/// calling the associated free function.
///

HONEYCOMB_EXPORT honey_string_userfree_wide_t honey_string_userfree_wide_alloc(void);
HONEYCOMB_EXPORT honey_string_userfree_utf8_t honey_string_userfree_utf8_alloc(void);
HONEYCOMB_EXPORT honey_string_userfree_utf16_t honey_string_userfree_utf16_alloc(void);

///
/// These functions free the string structure allocated by the associated
/// alloc function. Any string contents will first be cleared.
///

HONEYCOMB_EXPORT void honey_string_userfree_wide_free(honey_string_userfree_wide_t str);
HONEYCOMB_EXPORT void honey_string_userfree_utf8_free(honey_string_userfree_utf8_t str);
HONEYCOMB_EXPORT void honey_string_userfree_utf16_free(honey_string_userfree_utf16_t str);

///
/// These functions convert utf16 string case using the current ICU locale. This
/// may change the length of the string in some cases.
///

HONEYCOMB_EXPORT int honey_string_utf16_to_lower(const char16_t* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output);
HONEYCOMB_EXPORT int honey_string_utf16_to_upper(const char16_t* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output);

#ifdef __cplusplus
}
#endif

#endif  // HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_STRING_TYPES_H_
