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
// $hash=acc845289f80273062c7fde7d81e0c034a80f4e1$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_RUN_QUICK_MENU_CALLBACK_CPPTOC_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_RUN_QUICK_MENU_CALLBACK_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_context_menu_handler_capi.h"
#include "include/honey_context_menu_handler.h"
#include "libhoneycomb_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombRunQuickMenuCallbackCppToC
    : public HoneycombCppToCRefCounted<HoneycombRunQuickMenuCallbackCppToC,
                                 HoneycombRunQuickMenuCallback,
                                 honey_run_quick_menu_callback_t> {
 public:
  HoneycombRunQuickMenuCallbackCppToC();
  virtual ~HoneycombRunQuickMenuCallbackCppToC();
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_RUN_QUICK_MENU_CALLBACK_CPPTOC_H_
