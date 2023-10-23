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
// $hash=7a7900759a192fa0586d1ab7e2706c513ed9b715$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_TEST_TRANSLATOR_TEST_SCOPED_CLIENT_CHILD_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_TEST_TRANSLATOR_TEST_SCOPED_CLIENT_CHILD_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/test/honey_translator_test_capi.h"
#include "include/test/honey_translator_test.h"
#include "libhoney_dll/cpptoc/cpptoc_scoped.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombTranslatorTestScopedClientChildCppToC
    : public HoneycombCppToCScoped<HoneycombTranslatorTestScopedClientChildCppToC,
                             HoneycombTranslatorTestScopedClientChild,
                             honey_translator_test_scoped_client_child_t> {
 public:
  HoneycombTranslatorTestScopedClientChildCppToC();
  virtual ~HoneycombTranslatorTestScopedClientChildCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_TEST_TRANSLATOR_TEST_SCOPED_CLIENT_CHILD_CPPTOC_H_