// Copyright (c) 2023 Marshall A. Greenblatt. All rights reserved.
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
// This file was generated by the Honeycomb translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=1c3c3dfb4bde6cd45278c6a80fbc53f624017c44$
//

#ifndef HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_REQUEST_CONTEXT_CAPI_H_
#define HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_REQUEST_CONTEXT_CAPI_H_
#pragma once

#include "include/capi/honey_callback_capi.h"
#include "include/capi/honey_cookie_capi.h"
#include "include/capi/honey_extension_capi.h"
#include "include/capi/honey_extension_handler_capi.h"
#include "include/capi/honey_media_router_capi.h"
#include "include/capi/honey_preference_capi.h"
#include "include/capi/honey_values_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _honey_request_context_handler_t;
struct _honey_scheme_handler_factory_t;

///
/// Callback structure for honey_request_context_t::ResolveHost.
///
typedef struct _honey_resolve_callback_t {
  ///
  /// Base structure.
  ///
  honey_base_ref_counted_t base;

  ///
  /// Called on the UI thread after the ResolveHost request has completed.
  /// |result| will be the result code. |resolved_ips| will be the list of
  /// resolved IP addresses or NULL if the resolution failed.
  ///
  void(HONEYCOMB_CALLBACK* on_resolve_completed)(struct _honey_resolve_callback_t* self,
                                           honey_errorcode_t result,
                                           honey_string_list_t resolved_ips);
} honey_resolve_callback_t;

///
/// A request context provides request handling for a set of related browser or
/// URL request objects. A request context can be specified when creating a new
/// browser via the honey_browser_host_t static factory functions or when creating
/// a new URL request via the honey_urlrequest_t static factory functions. Browser
/// objects with different request contexts will never be hosted in the same
/// render process. Browser objects with the same request context may or may not
/// be hosted in the same render process depending on the process model. Browser
/// objects created indirectly via the JavaScript window.open function or
/// targeted links will share the same render process and the same request
/// context as the source browser. When running in single-process mode there is
/// only a single render process (the main process) and so all browsers created
/// in single-process mode will share the same request context. This will be the
/// first request context passed into a honey_browser_host_t static factory
/// function and all other request context objects will be ignored.
///
typedef struct _honey_request_context_t {
  ///
  /// Base structure.
  ///
  honey_preference_manager_t base;

  ///
  /// Returns true (1) if this object is pointing to the same context as |that|
  /// object.
  ///
  int(HONEYCOMB_CALLBACK* is_same)(struct _honey_request_context_t* self,
                             struct _honey_request_context_t* other);

  ///
  /// Returns true (1) if this object is sharing the same storage as |that|
  /// object.
  ///
  int(HONEYCOMB_CALLBACK* is_sharing_with)(struct _honey_request_context_t* self,
                                     struct _honey_request_context_t* other);

  ///
  /// Returns true (1) if this object is the global context. The global context
  /// is used by default when creating a browser or URL request with a NULL
  /// context argument.
  ///
  int(HONEYCOMB_CALLBACK* is_global)(struct _honey_request_context_t* self);

  ///
  /// Returns the handler for this context if any.
  ///
  struct _honey_request_context_handler_t*(HONEYCOMB_CALLBACK* get_handler)(
      struct _honey_request_context_t* self);

  ///
  /// Returns the cache path for this object. If NULL an "incognito mode" in-
  /// memory cache is being used.
  ///
  // The resulting string must be freed by calling honey_string_userfree_free().
  honey_string_userfree_t(HONEYCOMB_CALLBACK* get_cache_path)(
      struct _honey_request_context_t* self);

  ///
  /// Returns the cookie manager for this object. If |callback| is non-NULL it
  /// will be executed asnychronously on the UI thread after the manager's
  /// storage has been initialized.
  ///
  struct _honey_cookie_manager_t*(HONEYCOMB_CALLBACK* get_cookie_manager)(
      struct _honey_request_context_t* self,
      struct _honey_completion_callback_t* callback);

  ///
  /// Register a scheme handler factory for the specified |scheme_name| and
  /// optional |domain_name|. An NULL |domain_name| value for a standard scheme
  /// will cause the factory to match all domain names. The |domain_name| value
  /// will be ignored for non-standard schemes. If |scheme_name| is a built-in
  /// scheme and no handler is returned by |factory| then the built-in scheme
  /// handler factory will be called. If |scheme_name| is a custom scheme then
  /// you must also implement the honey_app_t::on_register_custom_schemes()
  /// function in all processes. This function may be called multiple times to
  /// change or remove the factory that matches the specified |scheme_name| and
  /// optional |domain_name|. Returns false (0) if an error occurs. This
  /// function may be called on any thread in the browser process.
  ///
  int(HONEYCOMB_CALLBACK* register_scheme_handler_factory)(
      struct _honey_request_context_t* self,
      const honey_string_t* scheme_name,
      const honey_string_t* domain_name,
      struct _honey_scheme_handler_factory_t* factory);

  ///
  /// Clear all registered scheme handler factories. Returns false (0) on error.
  /// This function may be called on any thread in the browser process.
  ///
  int(HONEYCOMB_CALLBACK* clear_scheme_handler_factories)(
      struct _honey_request_context_t* self);

  ///
  /// Clears all certificate exceptions that were added as part of handling
  /// honey_request_handler_t::on_certificate_error(). If you call this it is
  /// recommended that you also call close_all_connections() or you risk not
  /// being prompted again for server certificates if you reconnect quickly. If
  /// |callback| is non-NULL it will be executed on the UI thread after
  /// completion.
  ///
  void(HONEYCOMB_CALLBACK* clear_certificate_exceptions)(
      struct _honey_request_context_t* self,
      struct _honey_completion_callback_t* callback);

  ///
  /// Clears all HTTP authentication credentials that were added as part of
  /// handling GetAuthCredentials. If |callback| is non-NULL it will be executed
  /// on the UI thread after completion.
  ///
  void(HONEYCOMB_CALLBACK* clear_http_auth_credentials)(
      struct _honey_request_context_t* self,
      struct _honey_completion_callback_t* callback);

  ///
  /// Clears all active and idle connections that Chromium currently has. This
  /// is only recommended if you have released all other Honeycomb objects but don't
  /// yet want to call honey_shutdown(). If |callback| is non-NULL it will be
  /// executed on the UI thread after completion.
  ///
  void(HONEYCOMB_CALLBACK* close_all_connections)(
      struct _honey_request_context_t* self,
      struct _honey_completion_callback_t* callback);

  ///
  /// Attempts to resolve |origin| to a list of associated IP addresses.
  /// |callback| will be executed on the UI thread after completion.
  ///
  void(HONEYCOMB_CALLBACK* resolve_host)(struct _honey_request_context_t* self,
                                   const honey_string_t* origin,
                                   struct _honey_resolve_callback_t* callback);

  ///
  /// Load an extension.
  ///
  /// If extension resources will be read from disk using the default load
  /// implementation then |root_directory| should be the absolute path to the
  /// extension resources directory and |manifest| should be NULL. If extension
  /// resources will be provided by the client (e.g. via honey_request_handler_t
  /// and/or honey_extension_handler_t) then |root_directory| should be a path
  /// component unique to the extension (if not absolute this will be internally
  /// prefixed with the PK_DIR_RESOURCES path) and |manifest| should contain the
  /// contents that would otherwise be read from the "manifest.json" file on
  /// disk.
  ///
  /// The loaded extension will be accessible in all contexts sharing the same
  /// storage (HasExtension returns true (1)). However, only the context on
  /// which this function was called is considered the loader (DidLoadExtension
  /// returns true (1)) and only the loader will receive
  /// honey_request_context_handler_t callbacks for the extension.
  ///
  /// honey_extension_handler_t::OnExtensionLoaded will be called on load success
  /// or honey_extension_handler_t::OnExtensionLoadFailed will be called on load
  /// failure.
  ///
  /// If the extension specifies a background script via the "background"
  /// manifest key then honey_extension_handler_t::OnBeforeBackgroundBrowser will
  /// be called to create the background browser. See that function for
  /// additional information about background scripts.
  ///
  /// For visible extension views the client application should evaluate the
  /// manifest to determine the correct extension URL to load and then pass that
  /// URL to the honey_browser_host_t::CreateBrowser* function after the extension
  /// has loaded. For example, the client can look for the "browser_action"
  /// manifest key as documented at
  /// https://developer.chrome.com/extensions/browserAction. Extension URLs take
  /// the form "chrome-extension://<extension_id>/<path>".
  ///
  /// Browsers that host extensions differ from normal browsers as follows:
  ///  - Can access chrome.* JavaScript APIs if allowed by the manifest. Visit
  ///    chrome://extensions-support for the list of extension APIs currently
  ///    supported by Honeycomb.
  ///  - Main frame navigation to non-extension content is blocked.
  ///  - Pinch-zooming is disabled.
  ///  - HoneycombBrowserHost::GetExtension returns the hosted extension.
  ///  - HoneycombBrowserHost::IsBackgroundHost returns true for background hosts.
  ///
  /// See https://developer.chrome.com/extensions for extension implementation
  /// and usage documentation.
  ///
  void(HONEYCOMB_CALLBACK* load_extension)(struct _honey_request_context_t* self,
                                     const honey_string_t* root_directory,
                                     struct _honey_dictionary_value_t* manifest,
                                     struct _honey_extension_handler_t* handler);

  ///
  /// Returns true (1) if this context was used to load the extension identified
  /// by |extension_id|. Other contexts sharing the same storage will also have
  /// access to the extension (see HasExtension). This function must be called
  /// on the browser process UI thread.
  ///
  int(HONEYCOMB_CALLBACK* did_load_extension)(struct _honey_request_context_t* self,
                                        const honey_string_t* extension_id);

  ///
  /// Returns true (1) if this context has access to the extension identified by
  /// |extension_id|. This may not be the context that was used to load the
  /// extension (see DidLoadExtension). This function must be called on the
  /// browser process UI thread.
  ///
  int(HONEYCOMB_CALLBACK* has_extension)(struct _honey_request_context_t* self,
                                   const honey_string_t* extension_id);

  ///
  /// Retrieve the list of all extensions that this context has access to (see
  /// HasExtension). |extension_ids| will be populated with the list of
  /// extension ID values. Returns true (1) on success. This function must be
  /// called on the browser process UI thread.
  ///
  int(HONEYCOMB_CALLBACK* get_extensions)(struct _honey_request_context_t* self,
                                    honey_string_list_t extension_ids);

  ///
  /// Returns the extension matching |extension_id| or NULL if no matching
  /// extension is accessible in this context (see HasExtension). This function
  /// must be called on the browser process UI thread.
  ///
  struct _honey_extension_t*(HONEYCOMB_CALLBACK* get_extension)(
      struct _honey_request_context_t* self,
      const honey_string_t* extension_id);

  ///
  /// Returns the MediaRouter object associated with this context.  If
  /// |callback| is non-NULL it will be executed asnychronously on the UI thread
  /// after the manager's context has been initialized.
  ///
  struct _honey_media_router_t*(HONEYCOMB_CALLBACK* get_media_router)(
      struct _honey_request_context_t* self,
      struct _honey_completion_callback_t* callback);

  ///
  /// Returns the current value for |content_type| that applies for the
  /// specified URLs. If both URLs are NULL the default value will be returned.
  /// Returns nullptr if no value is configured. Must be called on the browser
  /// process UI thread.
  ///
  struct _honey_value_t*(HONEYCOMB_CALLBACK* get_website_setting)(
      struct _honey_request_context_t* self,
      const honey_string_t* requesting_url,
      const honey_string_t* top_level_url,
      honey_content_setting_types_t content_type);

  ///
  /// Sets the current value for |content_type| for the specified URLs in the
  /// default scope. If both URLs are NULL, and the context is not incognito,
  /// the default value will be set. Pass nullptr for |value| to remove the
  /// default value for this content type.
  ///
  /// WARNING: Incorrect usage of this function may cause instability or
  /// security issues in Chromium. Make sure that you first understand the
  /// potential impact of any changes to |content_type| by reviewing the related
  /// source code in Chromium. For example, if you plan to modify
  /// HONEYCOMB_CONTENT_SETTING_TYPE_POPUPS, first review and understand the usage of
  /// ContentSettingsType::POPUPS in Chromium:
  /// https://source.chromium.org/search?q=ContentSettingsType::POPUPS
  ///
  void(HONEYCOMB_CALLBACK* set_website_setting)(
      struct _honey_request_context_t* self,
      const honey_string_t* requesting_url,
      const honey_string_t* top_level_url,
      honey_content_setting_types_t content_type,
      struct _honey_value_t* value);

  ///
  /// Returns the current value for |content_type| that applies for the
  /// specified URLs. If both URLs are NULL the default value will be returned.
  /// Returns HONEYCOMB_CONTENT_SETTING_VALUE_DEFAULT if no value is configured. Must
  /// be called on the browser process UI thread.
  ///
  honey_content_setting_values_t(HONEYCOMB_CALLBACK* get_content_setting)(
      struct _honey_request_context_t* self,
      const honey_string_t* requesting_url,
      const honey_string_t* top_level_url,
      honey_content_setting_types_t content_type);

  ///
  /// Sets the current value for |content_type| for the specified URLs in the
  /// default scope. If both URLs are NULL, and the context is not incognito,
  /// the default value will be set. Pass HONEYCOMB_CONTENT_SETTING_VALUE_DEFAULT for
  /// |value| to use the default value for this content type.
  ///
  /// WARNING: Incorrect usage of this function may cause instability or
  /// security issues in Chromium. Make sure that you first understand the
  /// potential impact of any changes to |content_type| by reviewing the related
  /// source code in Chromium. For example, if you plan to modify
  /// HONEYCOMB_CONTENT_SETTING_TYPE_POPUPS, first review and understand the usage of
  /// ContentSettingsType::POPUPS in Chromium:
  /// https://source.chromium.org/search?q=ContentSettingsType::POPUPS
  ///
  void(HONEYCOMB_CALLBACK* set_content_setting)(
      struct _honey_request_context_t* self,
      const honey_string_t* requesting_url,
      const honey_string_t* top_level_url,
      honey_content_setting_types_t content_type,
      honey_content_setting_values_t value);
} honey_request_context_t;

///
/// Returns the global context object.
///
HONEYCOMB_EXPORT honey_request_context_t* honey_request_context_get_global_context(void);

///
/// Creates a new context object with the specified |settings| and optional
/// |handler|.
///
HONEYCOMB_EXPORT honey_request_context_t* honey_request_context_create_context(
    const struct _honey_request_context_settings_t* settings,
    struct _honey_request_context_handler_t* handler);

///
/// Creates a new context object that shares storage with |other| and uses an
/// optional |handler|.
///
HONEYCOMB_EXPORT honey_request_context_t* honey_create_context_shared(
    honey_request_context_t* other,
    struct _honey_request_context_handler_t* handler);

#ifdef __cplusplus
}
#endif

#endif  // HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_REQUEST_CONTEXT_CAPI_H_
