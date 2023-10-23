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
// $hash=c52f8327259f74779b2bb7e16a84b5c245da482b$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_TEST_TEST_SERVER_HANDLER_CPPTOC_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_TEST_TEST_SERVER_HANDLER_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/test/honey_test_server_capi.h"
#include "include/test/honey_test_server.h"
#include "libhoneycomb_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombTestServerHandlerCppToC
    : public HoneycombCppToCRefCounted<HoneycombTestServerHandlerCppToC,
                                 HoneycombTestServerHandler,
                                 honey_test_server_handler_t> {
 public:
  HoneycombTestServerHandlerCppToC();
  virtual ~HoneycombTestServerHandlerCppToC();
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CPPTOC_TEST_TEST_SERVER_HANDLER_CPPTOC_H_
