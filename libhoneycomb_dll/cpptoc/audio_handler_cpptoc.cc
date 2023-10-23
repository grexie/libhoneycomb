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
// $hash=b4b1529613a3609c6d5eee063c2f633475e0c68c$
//

#include "libhoneycomb_dll/cpptoc/audio_handler_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
audio_handler_get_audio_parameters(struct _honey_audio_handler_t* self,
                                   struct _honey_browser_t* browser,
                                   honey_audio_parameters_t* params) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: params; type: simple_byref
  DCHECK(params);
  if (!params) {
    return 0;
  }

  // Translate param: params; type: simple_byref
  HoneycombAudioParameters paramsVal = params ? *params : HoneycombAudioParameters();

  // Execute
  bool _retval = HoneycombAudioHandlerCppToC::Get(self)->GetAudioParameters(
      HoneycombBrowserCToCpp::Wrap(browser), paramsVal);

  // Restore param: params; type: simple_byref
  if (params) {
    *params = paramsVal;
  }

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
audio_handler_on_audio_stream_started(struct _honey_audio_handler_t* self,
                                      struct _honey_browser_t* browser,
                                      const honey_audio_parameters_t* params,
                                      int channels) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: params; type: simple_byref_const
  DCHECK(params);
  if (!params) {
    return;
  }

  // Translate param: params; type: simple_byref_const
  HoneycombAudioParameters paramsVal = params ? *params : HoneycombAudioParameters();

  // Execute
  HoneycombAudioHandlerCppToC::Get(self)->OnAudioStreamStarted(
      HoneycombBrowserCToCpp::Wrap(browser), paramsVal, channels);
}

void HONEYCOMB_CALLBACK
audio_handler_on_audio_stream_packet(struct _honey_audio_handler_t* self,
                                     struct _honey_browser_t* browser,
                                     const float** data,
                                     int frames,
                                     int64_t pts) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data) {
    return;
  }

  // Execute
  HoneycombAudioHandlerCppToC::Get(self)->OnAudioStreamPacket(
      HoneycombBrowserCToCpp::Wrap(browser), data, frames, pts);
}

void HONEYCOMB_CALLBACK
audio_handler_on_audio_stream_stopped(struct _honey_audio_handler_t* self,
                                      struct _honey_browser_t* browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  HoneycombAudioHandlerCppToC::Get(self)->OnAudioStreamStopped(
      HoneycombBrowserCToCpp::Wrap(browser));
}

void HONEYCOMB_CALLBACK
audio_handler_on_audio_stream_error(struct _honey_audio_handler_t* self,
                                    struct _honey_browser_t* browser,
                                    const honey_string_t* message) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: message; type: string_byref_const
  DCHECK(message);
  if (!message) {
    return;
  }

  // Execute
  HoneycombAudioHandlerCppToC::Get(self)->OnAudioStreamError(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(message));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombAudioHandlerCppToC::HoneycombAudioHandlerCppToC() {
  GetStruct()->get_audio_parameters = audio_handler_get_audio_parameters;
  GetStruct()->on_audio_stream_started = audio_handler_on_audio_stream_started;
  GetStruct()->on_audio_stream_packet = audio_handler_on_audio_stream_packet;
  GetStruct()->on_audio_stream_stopped = audio_handler_on_audio_stream_stopped;
  GetStruct()->on_audio_stream_error = audio_handler_on_audio_stream_error;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombAudioHandlerCppToC::~HoneycombAudioHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombAudioHandler> HoneycombCppToCRefCounted<
    HoneycombAudioHandlerCppToC,
    HoneycombAudioHandler,
    honey_audio_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                        honey_audio_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombAudioHandlerCppToC,
                                   HoneycombAudioHandler,
                                   honey_audio_handler_t>::kWrapperType =
    WT_AUDIO_HANDLER;
