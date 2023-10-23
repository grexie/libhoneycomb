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
// $hash=d08212eed1df4078ed5bb72dd7fc6d478f476ecb$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLINFO_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLINFO_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_ssl_info_capi.h"
#include "include/honey_ssl_info.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombSSLInfoCToCpp
    : public HoneycombCToCppRefCounted<HoneycombSSLInfoCToCpp, HoneycombSSLInfo, honey_sslinfo_t> {
 public:
  HoneycombSSLInfoCToCpp();
  virtual ~HoneycombSSLInfoCToCpp();

  // HoneycombSSLInfo methods.
  honey_cert_status_t GetCertStatus() override;
  HoneycombRefPtr<HoneycombX509Certificate> GetX509Certificate() override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLINFO_CTOCPP_H_
