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
// $hash=af612f99d0ccc287b152a20b3e9956af223f82e0$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLSTATUS_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLSTATUS_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_ssl_status_capi.h"
#include "include/honey_ssl_status.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombSSLStatusCToCpp : public HoneycombCToCppRefCounted<HoneycombSSLStatusCToCpp,
                                                      HoneycombSSLStatus,
                                                      honey_sslstatus_t> {
 public:
  HoneycombSSLStatusCToCpp();
  virtual ~HoneycombSSLStatusCToCpp();

  // HoneycombSSLStatus methods.
  bool IsSecureConnection() override;
  honey_cert_status_t GetCertStatus() override;
  honey_ssl_version_t GetSSLVersion() override;
  honey_ssl_content_status_t GetContentStatus() override;
  HoneycombRefPtr<HoneycombX509Certificate> GetX509Certificate() override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_SSLSTATUS_CTOCPP_H_
