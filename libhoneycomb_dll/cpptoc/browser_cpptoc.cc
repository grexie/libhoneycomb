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
// $hash=095894b34598f0352049ba3d8a56a80b9b2ad68e$
//

#include "libhoneycomb_dll/cpptoc/browser_cpptoc.h"
#include <algorithm>
#include "libhoneycomb_dll/cpptoc/browser_host_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/frame_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK browser_is_valid(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

struct _honey_browser_host_t* HONEYCOMB_CALLBACK
browser_get_host(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombBrowserHost> _retval = HoneycombBrowserCppToC::Get(self)->GetHost();

  // Return type: refptr_same
  return HoneycombBrowserHostCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK browser_can_go_back(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->CanGoBack();

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK browser_go_back(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->GoBack();
}

int HONEYCOMB_CALLBACK browser_can_go_forward(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->CanGoForward();

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK browser_go_forward(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->GoForward();
}

int HONEYCOMB_CALLBACK browser_is_loading(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->IsLoading();

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK browser_reload(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->Reload();
}

void HONEYCOMB_CALLBACK browser_reload_ignore_cache(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->ReloadIgnoreCache();
}

void HONEYCOMB_CALLBACK browser_stop_load(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->StopLoad();
}

int HONEYCOMB_CALLBACK browser_get_identifier(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombBrowserCppToC::Get(self)->GetIdentifier();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK browser_is_same(struct _honey_browser_t* self,
                                 struct _honey_browser_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombBrowserCppToC::Get(self)->IsSame(HoneycombBrowserCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK browser_is_popup(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->IsPopup();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK browser_has_document(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserCppToC::Get(self)->HasDocument();

  // Return type: bool
  return _retval;
}

struct _honey_frame_t* HONEYCOMB_CALLBACK
browser_get_main_frame(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombFrame> _retval = HoneycombBrowserCppToC::Get(self)->GetMainFrame();

  // Return type: refptr_same
  return HoneycombFrameCppToC::Wrap(_retval);
}

struct _honey_frame_t* HONEYCOMB_CALLBACK
browser_get_focused_frame(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombFrame> _retval = HoneycombBrowserCppToC::Get(self)->GetFocusedFrame();

  // Return type: refptr_same
  return HoneycombFrameCppToC::Wrap(_retval);
}

struct _honey_frame_t* HONEYCOMB_CALLBACK
browser_get_frame_byident(struct _honey_browser_t* self, int64_t identifier) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombFrame> _retval =
      HoneycombBrowserCppToC::Get(self)->GetFrame(identifier);

  // Return type: refptr_same
  return HoneycombFrameCppToC::Wrap(_retval);
}

struct _honey_frame_t* HONEYCOMB_CALLBACK browser_get_frame(struct _honey_browser_t* self,
                                                    const honey_string_t* name) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Unverified params: name

  // Execute
  HoneycombRefPtr<HoneycombFrame> _retval =
      HoneycombBrowserCppToC::Get(self)->GetFrame(HoneycombString(name));

  // Return type: refptr_same
  return HoneycombFrameCppToC::Wrap(_retval);
}

size_t HONEYCOMB_CALLBACK browser_get_frame_count(struct _honey_browser_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombBrowserCppToC::Get(self)->GetFrameCount();

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK browser_get_frame_identifiers(struct _honey_browser_t* self,
                                                size_t* identifiersCount,
                                                int64_t* identifiers) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: identifiers; type: simple_vec_byref
  DCHECK(identifiersCount && (*identifiersCount == 0 || identifiers));
  if (!identifiersCount || (*identifiersCount > 0 && !identifiers)) {
    return;
  }

  // Translate param: identifiers; type: simple_vec_byref
  std::vector<int64_t> identifiersList;
  if (identifiersCount && *identifiersCount > 0 && identifiers) {
    for (size_t i = 0; i < *identifiersCount; ++i) {
      identifiersList.push_back(identifiers[i]);
    }
  }

  // Execute
  HoneycombBrowserCppToC::Get(self)->GetFrameIdentifiers(identifiersList);

  // Restore param: identifiers; type: simple_vec_byref
  if (identifiersCount && identifiers) {
    *identifiersCount = std::min(identifiersList.size(), *identifiersCount);
    if (*identifiersCount > 0) {
      for (size_t i = 0; i < *identifiersCount; ++i) {
        identifiers[i] = identifiersList[i];
      }
    }
  }
}

void HONEYCOMB_CALLBACK browser_get_frame_names(struct _honey_browser_t* self,
                                          honey_string_list_t names) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: names; type: string_vec_byref
  DCHECK(names);
  if (!names) {
    return;
  }

  // Translate param: names; type: string_vec_byref
  std::vector<HoneycombString> namesList;
  transfer_string_list_contents(names, namesList);

  // Execute
  HoneycombBrowserCppToC::Get(self)->GetFrameNames(namesList);

  // Restore param: names; type: string_vec_byref
  honey_string_list_clear(names);
  transfer_string_list_contents(namesList, names);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombBrowserCppToC::HoneycombBrowserCppToC() {
  GetStruct()->is_valid = browser_is_valid;
  GetStruct()->get_host = browser_get_host;
  GetStruct()->can_go_back = browser_can_go_back;
  GetStruct()->go_back = browser_go_back;
  GetStruct()->can_go_forward = browser_can_go_forward;
  GetStruct()->go_forward = browser_go_forward;
  GetStruct()->is_loading = browser_is_loading;
  GetStruct()->reload = browser_reload;
  GetStruct()->reload_ignore_cache = browser_reload_ignore_cache;
  GetStruct()->stop_load = browser_stop_load;
  GetStruct()->get_identifier = browser_get_identifier;
  GetStruct()->is_same = browser_is_same;
  GetStruct()->is_popup = browser_is_popup;
  GetStruct()->has_document = browser_has_document;
  GetStruct()->get_main_frame = browser_get_main_frame;
  GetStruct()->get_focused_frame = browser_get_focused_frame;
  GetStruct()->get_frame_byident = browser_get_frame_byident;
  GetStruct()->get_frame = browser_get_frame;
  GetStruct()->get_frame_count = browser_get_frame_count;
  GetStruct()->get_frame_identifiers = browser_get_frame_identifiers;
  GetStruct()->get_frame_names = browser_get_frame_names;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombBrowserCppToC::~HoneycombBrowserCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombBrowser>
HoneycombCppToCRefCounted<HoneycombBrowserCppToC, HoneycombBrowser, honey_browser_t>::UnwrapDerived(
    HoneycombWrapperType type,
    honey_browser_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombBrowserCppToC,
                                   HoneycombBrowser,
                                   honey_browser_t>::kWrapperType = WT_BROWSER;
