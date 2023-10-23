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
// $hash=e18e48353500f27c27160812032cadc398fe00f9$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_RESOURCE_BUNDLE_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_RESOURCE_BUNDLE_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_resource_bundle_capi.h"
#include "include/honey_resource_bundle.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombResourceBundleCToCpp
    : public HoneycombCToCppRefCounted<HoneycombResourceBundleCToCpp,
                                 HoneycombResourceBundle,
                                 honey_resource_bundle_t> {
 public:
  HoneycombResourceBundleCToCpp();
  virtual ~HoneycombResourceBundleCToCpp();

  // HoneycombResourceBundle methods.
  HoneycombString GetLocalizedString(int string_id) override;
  HoneycombRefPtr<HoneycombBinaryValue> GetDataResource(int resource_id) override;
  HoneycombRefPtr<HoneycombBinaryValue> GetDataResourceForScale(
      int resource_id,
      ScaleFactor scale_factor) override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_RESOURCE_BUNDLE_CTOCPP_H_
