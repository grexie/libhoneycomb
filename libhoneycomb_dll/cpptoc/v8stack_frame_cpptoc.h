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
// $hash=a804ebb160de9a40b1e8ce65e1dfca67e5ffb658$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_V8STACK_FRAME_CPPTOC_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_V8STACK_FRAME_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_v8_capi.h"
#include "include/honey_v8.h"
#include "libhoneycomb_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombV8StackFrameCppToC : public HoneycombCppToCRefCounted<HoneycombV8StackFrameCppToC,
                                                         HoneycombV8StackFrame,
                                                         honey_v8stack_frame_t> {
 public:
  HoneycombV8StackFrameCppToC();
  virtual ~HoneycombV8StackFrameCppToC();
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_V8STACK_FRAME_CPPTOC_H_
