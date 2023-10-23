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
// $hash=f6e9e2a12912ea7b9ab5060481e323c180698725$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_RESOURCE_BUNDLE_HANDLER_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_RESOURCE_BUNDLE_HANDLER_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_resource_bundle_handler_capi.h"
#include "include/honey_resource_bundle_handler.h"
#include "libhoney_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombResourceBundleHandlerCppToC
    : public HoneycombCppToCRefCounted<HoneycombResourceBundleHandlerCppToC,
                                 HoneycombResourceBundleHandler,
                                 honey_resource_bundle_handler_t> {
 public:
  HoneycombResourceBundleHandlerCppToC();
  virtual ~HoneycombResourceBundleHandlerCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_RESOURCE_BUNDLE_HANDLER_CPPTOC_H_