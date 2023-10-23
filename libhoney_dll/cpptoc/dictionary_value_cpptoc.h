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
// $hash=dd73e5b97103c4ad27620af89886e49bfbdc8d21$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_DICTIONARY_VALUE_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_DICTIONARY_VALUE_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_values_capi.h"
#include "include/honey_values.h"
#include "libhoney_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombDictionaryValueCppToC
    : public HoneycombCppToCRefCounted<HoneycombDictionaryValueCppToC,
                                 HoneycombDictionaryValue,
                                 honey_dictionary_value_t> {
 public:
  HoneycombDictionaryValueCppToC();
  virtual ~HoneycombDictionaryValueCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_DICTIONARY_VALUE_CPPTOC_H_