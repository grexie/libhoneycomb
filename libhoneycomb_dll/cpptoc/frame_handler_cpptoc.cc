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
// $hash=73bfc92f74c8cd32ae894b99710c1de5bd5099a0$
//

#include "libhoneycomb_dll/cpptoc/frame_handler_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/frame_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
frame_handler_on_frame_created(struct _honey_frame_handler_t* self,
                               honey_browser_t* browser,
                               honey_frame_t* frame) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }

  // Execute
  HoneycombFrameHandlerCppToC::Get(self)->OnFrameCreated(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame));
}

void HONEYCOMB_CALLBACK
frame_handler_on_frame_attached(struct _honey_frame_handler_t* self,
                                honey_browser_t* browser,
                                honey_frame_t* frame,
                                int reattached) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }

  // Execute
  HoneycombFrameHandlerCppToC::Get(self)->OnFrameAttached(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      reattached ? true : false);
}

void HONEYCOMB_CALLBACK
frame_handler_on_frame_detached(struct _honey_frame_handler_t* self,
                                honey_browser_t* browser,
                                honey_frame_t* frame) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }

  // Execute
  HoneycombFrameHandlerCppToC::Get(self)->OnFrameDetached(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame));
}

void HONEYCOMB_CALLBACK
frame_handler_on_main_frame_changed(struct _honey_frame_handler_t* self,
                                    honey_browser_t* browser,
                                    honey_frame_t* old_frame,
                                    honey_frame_t* new_frame) {
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
  // Unverified params: old_frame, new_frame

  // Execute
  HoneycombFrameHandlerCppToC::Get(self)->OnMainFrameChanged(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(old_frame),
      HoneycombFrameCToCpp::Wrap(new_frame));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombFrameHandlerCppToC::HoneycombFrameHandlerCppToC() {
  GetStruct()->on_frame_created = frame_handler_on_frame_created;
  GetStruct()->on_frame_attached = frame_handler_on_frame_attached;
  GetStruct()->on_frame_detached = frame_handler_on_frame_detached;
  GetStruct()->on_main_frame_changed = frame_handler_on_main_frame_changed;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombFrameHandlerCppToC::~HoneycombFrameHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombFrameHandler> HoneycombCppToCRefCounted<
    HoneycombFrameHandlerCppToC,
    HoneycombFrameHandler,
    honey_frame_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                        honey_frame_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombFrameHandlerCppToC,
                                   HoneycombFrameHandler,
                                   honey_frame_handler_t>::kWrapperType =
    WT_FRAME_HANDLER;
