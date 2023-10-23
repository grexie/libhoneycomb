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
// $hash=067877a410a4ae9d7d671d5826a5c93eb6cdad37$
//

#include "libhoney_dll/ctocpp/media_sink_device_info_callback_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombMediaSinkDeviceInfoCallbackCToCpp::OnMediaSinkDeviceInfo(
    const HoneycombMediaSinkDeviceInfo& device_info) {
  shutdown_checker::AssertNotShutdown();

  honey_media_sink_device_info_callback_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_media_sink_device_info)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->on_media_sink_device_info(_struct, &device_info);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombMediaSinkDeviceInfoCallbackCToCpp::HoneycombMediaSinkDeviceInfoCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombMediaSinkDeviceInfoCallbackCToCpp::~HoneycombMediaSinkDeviceInfoCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_media_sink_device_info_callback_t*
HoneycombCToCppRefCounted<HoneycombMediaSinkDeviceInfoCallbackCToCpp,
                    HoneycombMediaSinkDeviceInfoCallback,
                    honey_media_sink_device_info_callback_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombMediaSinkDeviceInfoCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCToCppRefCounted<HoneycombMediaSinkDeviceInfoCallbackCToCpp,
                        HoneycombMediaSinkDeviceInfoCallback,
                        honey_media_sink_device_info_callback_t>::kWrapperType =
        WT_MEDIA_SINK_DEVICE_INFO_CALLBACK;