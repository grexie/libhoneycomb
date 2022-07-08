// Copyright (c) 2022 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=e902fe011f8667b64989e57ad9e72aec74b22015$
//

#ifndef CEF_INCLUDE_CAPI_CEF_PERMISSION_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_PERMISSION_HANDLER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_browser_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Callback structure used for asynchronous continuation of media access
// permission requests.
///
typedef struct _cef_media_access_callback_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Call to allow or deny media access. If this callback was initiated in
  // response to a getUserMedia (indicated by
  // CEF_MEDIA_PERMISSION_DEVICE_AUDIO_CAPTURE and/or
  // CEF_MEDIA_PERMISSION_DEVICE_VIDEO_CAPTURE being set) then
  // |allowed_permissions| must match |required_permissions| passed to
  // OnRequestMediaAccessPermission.
  ///
  void(CEF_CALLBACK* cont)(struct _cef_media_access_callback_t* self,
                           uint32 allowed_permissions);

  ///
  // Cancel the media access request.
  ///
  void(CEF_CALLBACK* cancel)(struct _cef_media_access_callback_t* self);
} cef_media_access_callback_t;

///
// Callback structure used for asynchronous continuation of permission prompts.
///
typedef struct _cef_permission_prompt_callback_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Complete the permissions request with the specified |result|.
  ///
  void(CEF_CALLBACK* cont)(struct _cef_permission_prompt_callback_t* self,
                           cef_permission_request_result_t result);
} cef_permission_prompt_callback_t;

///
// Implement this structure to handle events related to permission requests. The
// functions of this structure will be called on the browser process UI thread.
///
typedef struct _cef_permission_handler_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Called when a page requests permission to access media. |requesting_origin|
  // is the URL origin requesting permission. |requested_permissions| is a
  // combination of values from cef_media_access_permission_types_t that
  // represent the requested permissions. Return true (1) and call
  // cef_media_access_callback_t functions either in this function or at a later
  // time to continue or cancel the request. Return false (0) to proceed with
  // default handling. With the Chrome runtime, default handling will display
  // the permission request UI. With the Alloy runtime, default handling will
  // deny the request. This function will not be called if the "--enable-media-
  // stream" command-line switch is used to grant all permissions.
  ///
  int(CEF_CALLBACK* on_request_media_access_permission)(
      struct _cef_permission_handler_t* self,
      struct _cef_browser_t* browser,
      struct _cef_frame_t* frame,
      const cef_string_t* requesting_origin,
      uint32 requested_permissions,
      struct _cef_media_access_callback_t* callback);

  ///
  // Called when a page should show a permission prompt. |prompt_id| uniquely
  // identifies the prompt. |requesting_origin| is the URL origin requesting
  // permission. |requested_permissions| is a combination of values from
  // cef_permission_request_types_t that represent the requested permissions.
  // Return true (1) and call cef_permission_prompt_callback_t::Continue either
  // in this function or at a later time to continue or cancel the request.
  // Return false (0) to proceed with default handling. With the Chrome runtime,
  // default handling will display the permission prompt UI. With the Alloy
  // runtime, default handling is CEF_PERMISSION_RESULT_IGNORE.
  ///
  int(CEF_CALLBACK* on_show_permission_prompt)(
      struct _cef_permission_handler_t* self,
      struct _cef_browser_t* browser,
      uint64 prompt_id,
      const cef_string_t* requesting_origin,
      uint32 requested_permissions,
      struct _cef_permission_prompt_callback_t* callback);

  ///
  // Called when a permission prompt handled via OnShowPermissionPrompt is
  // dismissed. |prompt_id| will match the value that was passed to
  // OnShowPermissionPrompt. |result| will be the value passed to
  // cef_permission_prompt_callback_t::Continue or CEF_PERMISSION_RESULT_IGNORE
  // if the dialog was dismissed for other reasons such as navigation, browser
  // closure, etc. This function will not be called if OnShowPermissionPrompt
  // returned false (0) for |prompt_id|.
  ///
  void(CEF_CALLBACK* on_dismiss_permission_prompt)(
      struct _cef_permission_handler_t* self,
      struct _cef_browser_t* browser,
      uint64 prompt_id,
      cef_permission_request_result_t result);
} cef_permission_handler_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_PERMISSION_HANDLER_CAPI_H_
