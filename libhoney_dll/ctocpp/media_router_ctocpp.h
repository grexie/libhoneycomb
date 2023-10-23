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
// $hash=ef079450730cdf1b8720a84d83b361c6423a091a$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CTOCPP_MEDIA_ROUTER_CTOCPP_H_
#define HONEYCOMB_LIBHONEY_DLL_CTOCPP_MEDIA_ROUTER_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_media_router_capi.h"
#include "include/honey_media_router.h"
#include "libhoney_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombMediaRouterCToCpp : public HoneycombCToCppRefCounted<HoneycombMediaRouterCToCpp,
                                                        HoneycombMediaRouter,
                                                        honey_media_router_t> {
 public:
  HoneycombMediaRouterCToCpp();
  virtual ~HoneycombMediaRouterCToCpp();

  // HoneycombMediaRouter methods.
  HoneycombRefPtr<HoneycombRegistration> AddObserver(
      HoneycombRefPtr<HoneycombMediaObserver> observer) override;
  HoneycombRefPtr<HoneycombMediaSource> GetSource(const HoneycombString& urn) override;
  void NotifyCurrentSinks() override;
  void CreateRoute(HoneycombRefPtr<HoneycombMediaSource> source,
                   HoneycombRefPtr<HoneycombMediaSink> sink,
                   HoneycombRefPtr<HoneycombMediaRouteCreateCallback> callback) override;
  void NotifyCurrentRoutes() override;
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CTOCPP_MEDIA_ROUTER_CTOCPP_H_