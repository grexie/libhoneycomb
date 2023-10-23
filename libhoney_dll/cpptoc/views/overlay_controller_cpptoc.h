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
// $hash=8d50609d2e79539752a8118f831e853b845892f4$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CPPTOC_VIEWS_OVERLAY_CONTROLLER_CPPTOC_H_
#define HONEYCOMB_LIBHONEY_DLL_CPPTOC_VIEWS_OVERLAY_CONTROLLER_CPPTOC_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/views/honey_overlay_controller_capi.h"
#include "include/capi/views/honey_view_capi.h"
#include "include/capi/views/honey_window_capi.h"
#include "include/views/honey_overlay_controller.h"
#include "include/views/honey_view.h"
#include "include/views/honey_window.h"
#include "libhoney_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class HoneycombOverlayControllerCppToC
    : public HoneycombCppToCRefCounted<HoneycombOverlayControllerCppToC,
                                 HoneycombOverlayController,
                                 honey_overlay_controller_t> {
 public:
  HoneycombOverlayControllerCppToC();
  virtual ~HoneycombOverlayControllerCppToC();
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CPPTOC_VIEWS_OVERLAY_CONTROLLER_CPPTOC_H_