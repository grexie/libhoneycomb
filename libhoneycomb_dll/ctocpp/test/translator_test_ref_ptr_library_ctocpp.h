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
// $hash=9fa8897ee5081b7cd95a6cb791fb69871f61406e$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_TEST_TRANSLATOR_TEST_REF_PTR_LIBRARY_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_TEST_TRANSLATOR_TEST_REF_PTR_LIBRARY_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/test/honey_translator_test_capi.h"
#include "include/test/honey_translator_test.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombTranslatorTestRefPtrLibraryCToCpp
    : public HoneycombCToCppRefCounted<HoneycombTranslatorTestRefPtrLibraryCToCpp,
                                 HoneycombTranslatorTestRefPtrLibrary,
                                 honey_translator_test_ref_ptr_library_t> {
 public:
  HoneycombTranslatorTestRefPtrLibraryCToCpp();
  virtual ~HoneycombTranslatorTestRefPtrLibraryCToCpp();

  // HoneycombTranslatorTestRefPtrLibrary methods.
  int GetValue() override;
  void SetValue(int value) override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_TEST_TRANSLATOR_TEST_REF_PTR_LIBRARY_CTOCPP_H_
