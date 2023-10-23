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
// $hash=e51f496e40bd2b3b9573d2ca084e578bb1df1407$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_BROWSER_HOST_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_BROWSER_HOST_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_browser_capi.h"
#include "include/capi/honey_client_capi.h"
#include "include/honey_browser.h"
#include "include/honey_client.h"
#include "libhoney_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombBrowserHostCppToC : public HoneycombCppToCRefCounted<HoneycombBrowserHostCppToC,
                                                        HoneycombBrowserHost,
                                                        honey_browser_host_t> {
 public:
  HoneycombBrowserHostCppToC();
  virtual ~HoneycombBrowserHostCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_BROWSER_HOST_CPPTOC_H_