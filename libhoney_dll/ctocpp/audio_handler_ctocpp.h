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
// $hash=93c0cae17d2e380e7a0268ba658b1449cc0bc71c$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CTOCPP_AUDIO_HANDLER_CTOCPP_H_
#define HONEYCOMB_LIBHONEY_DLL_CTOCPP_AUDIO_HANDLER_CTOCPP_H_
#pragma once

#if !defined(BUILDING_HONEYCOMB_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/honey_audio_handler_capi.h"
#include "include/honey_audio_handler.h"
#include "libhoney_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class HoneycombAudioHandlerCToCpp : public HoneycombCToCppRefCounted<HoneycombAudioHandlerCToCpp,
                                                         HoneycombAudioHandler,
                                                         honey_audio_handler_t> {
 public:
  HoneycombAudioHandlerCToCpp();
  virtual ~HoneycombAudioHandlerCToCpp();

  // HoneycombAudioHandler methods.
  bool GetAudioParameters(HoneycombRefPtr<HoneycombBrowser> browser,
                          HoneycombAudioParameters& params) override;
  void OnAudioStreamStarted(HoneycombRefPtr<HoneycombBrowser> browser,
                            const HoneycombAudioParameters& params,
                            int channels) override;
  void OnAudioStreamPacket(HoneycombRefPtr<HoneycombBrowser> browser,
                           const float** data,
                           int frames,
                           int64_t pts) override;
  void OnAudioStreamStopped(HoneycombRefPtr<HoneycombBrowser> browser) override;
  void OnAudioStreamError(HoneycombRefPtr<HoneycombBrowser> browser,
                          const HoneycombString& message) override;
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CTOCPP_AUDIO_HANDLER_CTOCPP_H_