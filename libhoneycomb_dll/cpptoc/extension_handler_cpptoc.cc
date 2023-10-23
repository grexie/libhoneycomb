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
// $hash=268a62ebd9b7d8b14dc1510af1d395768d24e20f$
//

#include "libhoneycomb_dll/cpptoc/extension_handler_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/client_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/extension_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/get_extension_resource_callback_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/template_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK extension_handler_on_extension_load_failed(
    struct _honey_extension_handler_t* self,
    honey_errorcode_t result) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombExtensionHandlerCppToC::Get(self)->OnExtensionLoadFailed(result);
}

void HONEYCOMB_CALLBACK
extension_handler_on_extension_loaded(struct _honey_extension_handler_t* self,
                                      honey_extension_t* extension) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return;
  }

  // Execute
  HoneycombExtensionHandlerCppToC::Get(self)->OnExtensionLoaded(
      HoneycombExtensionCToCpp::Wrap(extension));
}

void HONEYCOMB_CALLBACK
extension_handler_on_extension_unloaded(struct _honey_extension_handler_t* self,
                                        honey_extension_t* extension) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return;
  }

  // Execute
  HoneycombExtensionHandlerCppToC::Get(self)->OnExtensionUnloaded(
      HoneycombExtensionCToCpp::Wrap(extension));
}

int HONEYCOMB_CALLBACK extension_handler_on_before_background_browser(
    struct _honey_extension_handler_t* self,
    honey_extension_t* extension,
    const honey_string_t* url,
    honey_client_t** client,
    struct _honey_browser_settings_t* settings) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return 0;
  }
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url) {
    return 0;
  }
  // Verify param: client; type: refptr_same_byref
  DCHECK(client);
  if (!client) {
    return 0;
  }
  // Verify param: settings; type: struct_byref
  DCHECK(settings);
  if (!settings) {
    return 0;
  }
  if (!template_util::has_valid_size(settings)) {
    DCHECK(false) << "invalid settings->[base.]size";
    return 0;
  }

  // Translate param: client; type: refptr_same_byref
  HoneycombRefPtr<HoneycombClient> clientPtr;
  if (client && *client) {
    clientPtr = HoneycombClientCppToC::Unwrap(*client);
  }
  HoneycombClient* clientOrig = clientPtr.get();
  // Translate param: settings; type: struct_byref
  HoneycombBrowserSettings settingsObj;
  if (settings) {
    settingsObj.AttachTo(*settings);
  }

  // Execute
  bool _retval =
      HoneycombExtensionHandlerCppToC::Get(self)->OnBeforeBackgroundBrowser(
          HoneycombExtensionCToCpp::Wrap(extension), HoneycombString(url), clientPtr,
          settingsObj);

  // Restore param: client; type: refptr_same_byref
  if (client) {
    if (clientPtr.get()) {
      if (clientPtr.get() != clientOrig) {
        *client = HoneycombClientCppToC::Wrap(clientPtr);
      }
    } else {
      *client = nullptr;
    }
  }
  // Restore param: settings; type: struct_byref
  if (settings) {
    settingsObj.DetachTo(*settings);
  }

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
extension_handler_on_before_browser(struct _honey_extension_handler_t* self,
                                    honey_extension_t* extension,
                                    honey_browser_t* browser,
                                    honey_browser_t* active_browser,
                                    int index,
                                    const honey_string_t* url,
                                    int active,
                                    honey_window_info_t* windowInfo,
                                    honey_client_t** client,
                                    struct _honey_browser_settings_t* settings) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: active_browser; type: refptr_diff
  DCHECK(active_browser);
  if (!active_browser) {
    return 0;
  }
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url) {
    return 0;
  }
  // Verify param: windowInfo; type: struct_byref
  DCHECK(windowInfo);
  if (!windowInfo) {
    return 0;
  }
  if (!template_util::has_valid_size(windowInfo)) {
    DCHECK(false) << "invalid windowInfo->[base.]size";
    return 0;
  }
  // Verify param: client; type: refptr_same_byref
  DCHECK(client);
  if (!client) {
    return 0;
  }
  // Verify param: settings; type: struct_byref
  DCHECK(settings);
  if (!settings) {
    return 0;
  }
  if (!template_util::has_valid_size(settings)) {
    DCHECK(false) << "invalid settings->[base.]size";
    return 0;
  }

  // Translate param: windowInfo; type: struct_byref
  HoneycombWindowInfo windowInfoObj;
  if (windowInfo) {
    windowInfoObj.AttachTo(*windowInfo);
  }
  // Translate param: client; type: refptr_same_byref
  HoneycombRefPtr<HoneycombClient> clientPtr;
  if (client && *client) {
    clientPtr = HoneycombClientCppToC::Unwrap(*client);
  }
  HoneycombClient* clientOrig = clientPtr.get();
  // Translate param: settings; type: struct_byref
  HoneycombBrowserSettings settingsObj;
  if (settings) {
    settingsObj.AttachTo(*settings);
  }

  // Execute
  bool _retval = HoneycombExtensionHandlerCppToC::Get(self)->OnBeforeBrowser(
      HoneycombExtensionCToCpp::Wrap(extension), HoneycombBrowserCToCpp::Wrap(browser),
      HoneycombBrowserCToCpp::Wrap(active_browser), index, HoneycombString(url),
      active ? true : false, windowInfoObj, clientPtr, settingsObj);

  // Restore param: windowInfo; type: struct_byref
  if (windowInfo) {
    windowInfoObj.DetachTo(*windowInfo);
  }
  // Restore param: client; type: refptr_same_byref
  if (client) {
    if (clientPtr.get()) {
      if (clientPtr.get() != clientOrig) {
        *client = HoneycombClientCppToC::Wrap(clientPtr);
      }
    } else {
      *client = nullptr;
    }
  }
  // Restore param: settings; type: struct_byref
  if (settings) {
    settingsObj.DetachTo(*settings);
  }

  // Return type: bool
  return _retval;
}

honey_browser_t* HONEYCOMB_CALLBACK
extension_handler_get_active_browser(struct _honey_extension_handler_t* self,
                                     honey_extension_t* extension,
                                     honey_browser_t* browser,
                                     int include_incognito) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return NULL;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombBrowser> _retval =
      HoneycombExtensionHandlerCppToC::Get(self)->GetActiveBrowser(
          HoneycombExtensionCToCpp::Wrap(extension), HoneycombBrowserCToCpp::Wrap(browser),
          include_incognito ? true : false);

  // Return type: refptr_diff
  return HoneycombBrowserCToCpp::Unwrap(_retval);
}

int HONEYCOMB_CALLBACK
extension_handler_can_access_browser(struct _honey_extension_handler_t* self,
                                     honey_extension_t* extension,
                                     honey_browser_t* browser,
                                     int include_incognito,
                                     honey_browser_t* target_browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: target_browser; type: refptr_diff
  DCHECK(target_browser);
  if (!target_browser) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombExtensionHandlerCppToC::Get(self)->CanAccessBrowser(
      HoneycombExtensionCToCpp::Wrap(extension), HoneycombBrowserCToCpp::Wrap(browser),
      include_incognito ? true : false, HoneycombBrowserCToCpp::Wrap(target_browser));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK extension_handler_get_extension_resource(
    struct _honey_extension_handler_t* self,
    honey_extension_t* extension,
    honey_browser_t* browser,
    const honey_string_t* file,
    honey_get_extension_resource_callback_t* callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: extension; type: refptr_diff
  DCHECK(extension);
  if (!extension) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: file; type: string_byref_const
  DCHECK(file);
  if (!file) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombExtensionHandlerCppToC::Get(self)->GetExtensionResource(
      HoneycombExtensionCToCpp::Wrap(extension), HoneycombBrowserCToCpp::Wrap(browser),
      HoneycombString(file), HoneycombGetExtensionResourceCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombExtensionHandlerCppToC::HoneycombExtensionHandlerCppToC() {
  GetStruct()->on_extension_load_failed =
      extension_handler_on_extension_load_failed;
  GetStruct()->on_extension_loaded = extension_handler_on_extension_loaded;
  GetStruct()->on_extension_unloaded = extension_handler_on_extension_unloaded;
  GetStruct()->on_before_background_browser =
      extension_handler_on_before_background_browser;
  GetStruct()->on_before_browser = extension_handler_on_before_browser;
  GetStruct()->get_active_browser = extension_handler_get_active_browser;
  GetStruct()->can_access_browser = extension_handler_can_access_browser;
  GetStruct()->get_extension_resource =
      extension_handler_get_extension_resource;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombExtensionHandlerCppToC::~HoneycombExtensionHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombExtensionHandler> HoneycombCppToCRefCounted<
    HoneycombExtensionHandlerCppToC,
    HoneycombExtensionHandler,
    honey_extension_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                            honey_extension_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombExtensionHandlerCppToC,
                                   HoneycombExtensionHandler,
                                   honey_extension_handler_t>::kWrapperType =
    WT_EXTENSION_HANDLER;
