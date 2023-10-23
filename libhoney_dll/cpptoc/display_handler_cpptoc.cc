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
// $hash=c0ff4cb4baaaeb981c9c143e6379a7ae1927c51e$
//

#include "libhoney_dll/cpptoc/display_handler_cpptoc.h"
#include "libhoney_dll/ctocpp/browser_ctocpp.h"
#include "libhoney_dll/ctocpp/frame_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"
#include "libhoney_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
display_handler_on_address_change(struct _honey_display_handler_t* self,
                                  honey_browser_t* browser,
                                  struct _honey_frame_t* frame,
                                  const honey_string_t* url) {
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
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url) {
    return;
  }

  // Execute
  HoneycombDisplayHandlerCppToC::Get(self)->OnAddressChange(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombFrameCToCpp::Wrap(frame),
      HoneycombString(url));
}

void HONEYCOMB_CALLBACK
display_handler_on_title_change(struct _honey_display_handler_t* self,
                                honey_browser_t* browser,
                                const honey_string_t* title) {
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
  // Unverified params: title

  // Execute
  HoneycombDisplayHandlerCppToC::Get(self)->OnTitleChange(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(title));
}

void HONEYCOMB_CALLBACK
display_handler_on_favicon_urlchange(struct _honey_display_handler_t* self,
                                     honey_browser_t* browser,
                                     honey_string_list_t icon_urls) {
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
  // Unverified params: icon_urls

  // Translate param: icon_urls; type: string_vec_byref_const
  std::vector<HoneycombString> icon_urlsList;
  transfer_string_list_contents(icon_urls, icon_urlsList);

  // Execute
  HoneycombDisplayHandlerCppToC::Get(self)->OnFaviconURLChange(
      HoneycombBrowserCToCpp::Wrap(browser), icon_urlsList);
}

void HONEYCOMB_CALLBACK
display_handler_on_fullscreen_mode_change(struct _honey_display_handler_t* self,
                                          honey_browser_t* browser,
                                          int fullscreen) {
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
  HoneycombDisplayHandlerCppToC::Get(self)->OnFullscreenModeChange(
      HoneycombBrowserCToCpp::Wrap(browser), fullscreen ? true : false);
}

int HONEYCOMB_CALLBACK display_handler_on_tooltip(struct _honey_display_handler_t* self,
                                            honey_browser_t* browser,
                                            honey_string_t* text) {
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
  // Unverified params: text

  // Translate param: text; type: string_byref
  HoneycombString textStr(text);

  // Execute
  bool _retval = HoneycombDisplayHandlerCppToC::Get(self)->OnTooltip(
      HoneycombBrowserCToCpp::Wrap(browser), textStr);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
display_handler_on_status_message(struct _honey_display_handler_t* self,
                                  honey_browser_t* browser,
                                  const honey_string_t* value) {
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
  // Unverified params: value

  // Execute
  HoneycombDisplayHandlerCppToC::Get(self)->OnStatusMessage(
      HoneycombBrowserCToCpp::Wrap(browser), HoneycombString(value));
}

int HONEYCOMB_CALLBACK
display_handler_on_console_message(struct _honey_display_handler_t* self,
                                   honey_browser_t* browser,
                                   honey_log_severity_t level,
                                   const honey_string_t* message,
                                   const honey_string_t* source,
                                   int line) {
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
  // Unverified params: message, source

  // Execute
  bool _retval = HoneycombDisplayHandlerCppToC::Get(self)->OnConsoleMessage(
      HoneycombBrowserCToCpp::Wrap(browser), level, HoneycombString(message),
      HoneycombString(source), line);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
display_handler_on_auto_resize(struct _honey_display_handler_t* self,
                               honey_browser_t* browser,
                               const honey_size_t* new_size) {
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
  // Verify param: new_size; type: simple_byref_const
  DCHECK(new_size);
  if (!new_size) {
    return 0;
  }

  // Translate param: new_size; type: simple_byref_const
  HoneycombSize new_sizeVal = new_size ? *new_size : HoneycombSize();

  // Execute
  bool _retval = HoneycombDisplayHandlerCppToC::Get(self)->OnAutoResize(
      HoneycombBrowserCToCpp::Wrap(browser), new_sizeVal);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
display_handler_on_loading_progress_change(struct _honey_display_handler_t* self,
                                           honey_browser_t* browser,
                                           double progress) {
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
  HoneycombDisplayHandlerCppToC::Get(self)->OnLoadingProgressChange(
      HoneycombBrowserCToCpp::Wrap(browser), progress);
}

int HONEYCOMB_CALLBACK
display_handler_on_cursor_change(struct _honey_display_handler_t* self,
                                 honey_browser_t* browser,
                                 honey_cursor_handle_t cursor,
                                 honey_cursor_type_t type,
                                 const honey_cursor_info_t* custom_cursor_info) {
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
  // Verify param: custom_cursor_info; type: simple_byref_const
  DCHECK(custom_cursor_info);
  if (!custom_cursor_info) {
    return 0;
  }

  // Translate param: custom_cursor_info; type: simple_byref_const
  HoneycombCursorInfo custom_cursor_infoVal =
      custom_cursor_info ? *custom_cursor_info : HoneycombCursorInfo();

  // Execute
  bool _retval = HoneycombDisplayHandlerCppToC::Get(self)->OnCursorChange(
      HoneycombBrowserCToCpp::Wrap(browser), cursor, type, custom_cursor_infoVal);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
display_handler_on_media_access_change(struct _honey_display_handler_t* self,
                                       honey_browser_t* browser,
                                       int has_video_access,
                                       int has_audio_access) {
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
  HoneycombDisplayHandlerCppToC::Get(self)->OnMediaAccessChange(
      HoneycombBrowserCToCpp::Wrap(browser), has_video_access ? true : false,
      has_audio_access ? true : false);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDisplayHandlerCppToC::HoneycombDisplayHandlerCppToC() {
  GetStruct()->on_address_change = display_handler_on_address_change;
  GetStruct()->on_title_change = display_handler_on_title_change;
  GetStruct()->on_favicon_urlchange = display_handler_on_favicon_urlchange;
  GetStruct()->on_fullscreen_mode_change =
      display_handler_on_fullscreen_mode_change;
  GetStruct()->on_tooltip = display_handler_on_tooltip;
  GetStruct()->on_status_message = display_handler_on_status_message;
  GetStruct()->on_console_message = display_handler_on_console_message;
  GetStruct()->on_auto_resize = display_handler_on_auto_resize;
  GetStruct()->on_loading_progress_change =
      display_handler_on_loading_progress_change;
  GetStruct()->on_cursor_change = display_handler_on_cursor_change;
  GetStruct()->on_media_access_change = display_handler_on_media_access_change;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDisplayHandlerCppToC::~HoneycombDisplayHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDisplayHandler> HoneycombCppToCRefCounted<
    HoneycombDisplayHandlerCppToC,
    HoneycombDisplayHandler,
    honey_display_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                          honey_display_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombDisplayHandlerCppToC,
                                   HoneycombDisplayHandler,
                                   honey_display_handler_t>::kWrapperType =
    WT_DISPLAY_HANDLER;