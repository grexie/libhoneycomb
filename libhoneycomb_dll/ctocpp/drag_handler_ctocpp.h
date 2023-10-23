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
// $hash=a8523e82439b30828b0774d2eff240ea215b96d6$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_DRAG_HANDLER_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_DRAG_HANDLER_CTOCPP_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include <vector>
#include "include/capi/honey_drag_handler_capi.h"
#include "include/honey_drag_handler.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class HoneycombDragHandlerCToCpp : public HoneycombCToCppRefCounted<HoneycombDragHandlerCToCpp,
                                                        HoneycombDragHandler,
                                                        honey_drag_handler_t> {
 public:
  HoneycombDragHandlerCToCpp();
  virtual ~HoneycombDragHandlerCToCpp();

  // HoneycombDragHandler methods.
  bool OnDragEnter(HoneycombRefPtr<HoneycombBrowser> browser,
                   HoneycombRefPtr<HoneycombDragData> dragData,
                   DragOperationsMask mask) override;
  void OnDraggableRegionsChanged(
      HoneycombRefPtr<HoneycombBrowser> browser,
      HoneycombRefPtr<HoneycombFrame> frame,
      const std::vector<HoneycombDraggableRegion>& regions) override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_DRAG_HANDLER_CTOCPP_H_
