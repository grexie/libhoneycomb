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
// $hash=743f5b5893055b96eb373b93368c727b3d36d3c6$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_
#define HONEYCOMB_LIBHONEY_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/honey_download_handler_capi.h"
#include "include/honey_download_handler.h"
#include "libhoney_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombBeforeDownloadCallbackCToCpp
    : public HoneycombCToCppRefCounted<HoneycombBeforeDownloadCallbackCToCpp,
                                 HoneycombBeforeDownloadCallback,
                                 honey_before_download_callback_t> {
 public:
  HoneycombBeforeDownloadCallbackCToCpp();
  virtual ~HoneycombBeforeDownloadCallbackCToCpp();

  // HoneycombBeforeDownloadCallback methods.
  void Continue(const HoneycombString& download_path, bool show_dialog) override;
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CTOCPP_BEFORE_DOWNLOAD_CALLBACK_CTOCPP_H_