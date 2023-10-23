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
// $hash=68dd3aa1b0a216bdc63aa9ed3008b0b5815f8040$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_CONTEXT_MENU_HANDLER_CPPTOC_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_CONTEXT_MENU_HANDLER_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_context_menu_handler_capi.h"
#include "include/honey_context_menu_handler.h"
#include "libhoneycomb_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombContextMenuHandlerCppToC
    : public HoneycombCppToCRefCounted<HoneycombContextMenuHandlerCppToC,
                                 HoneycombContextMenuHandler,
                                 honey_context_menu_handler_t> {
 public:
  HoneycombContextMenuHandlerCppToC();
  virtual ~HoneycombContextMenuHandlerCppToC();
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_CONTEXT_MENU_HANDLER_CPPTOC_H_
