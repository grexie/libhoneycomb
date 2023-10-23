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
// $hash=edf9787173ef035101e1d1805f2926b6028530f8$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_SERVER_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_SERVER_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_server_capi.h"
#include "include/honey_server.h"
#include "libhoney_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombServerCppToC
    : public HoneycombCppToCRefCounted<HoneycombServerCppToC, HoneycombServer, honey_server_t> {
 public:
  HoneycombServerCppToC();
  virtual ~HoneycombServerCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_SERVER_CPPTOC_H_