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
// $hash=f82440b30a75049733b4dd200494ab06d52c68b3$
//

#include "libhoneycomb_dll/cpptoc/views/browser_view_delegate_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/client_cpptoc.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/views/browser_view_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/views/view_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/template_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK browser_view_delegate_on_browser_created(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view,
    honey_browser_t* browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(self)->OnBrowserCreated(
      HoneycombBrowserViewCToCpp::Wrap(browser_view),
      HoneycombBrowserCToCpp::Wrap(browser));
}

void HONEYCOMB_CALLBACK browser_view_delegate_on_browser_destroyed(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view,
    honey_browser_t* browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(self)->OnBrowserDestroyed(
      HoneycombBrowserViewCToCpp::Wrap(browser_view),
      HoneycombBrowserCToCpp::Wrap(browser));
}

honey_browser_view_delegate_t* HONEYCOMB_CALLBACK
browser_view_delegate_get_delegate_for_popup_browser_view(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view,
    const struct _honey_browser_settings_t* settings,
    honey_client_t* client,
    int is_devtools) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return NULL;
  }
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings) {
    return NULL;
  }
  if (!template_util::has_valid_size(settings)) {
    DCHECK(false) << "invalid settings->[base.]size";
    return NULL;
  }
  // Unverified params: client

  // Translate param: settings; type: struct_byref_const
  HoneycombBrowserSettings settingsObj;
  if (settings) {
    settingsObj.Set(*settings, false);
  }

  // Execute
  HoneycombRefPtr<HoneycombBrowserViewDelegate> _retval =
      HoneycombBrowserViewDelegateCppToC::Get(self)->GetDelegateForPopupBrowserView(
          HoneycombBrowserViewCToCpp::Wrap(browser_view), settingsObj,
          HoneycombClientCppToC::Unwrap(client), is_devtools ? true : false);

  // Return type: refptr_same
  return HoneycombBrowserViewDelegateCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK browser_view_delegate_on_popup_browser_view_created(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view,
    honey_browser_view_t* popup_browser_view,
    int is_devtools) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return 0;
  }
  // Verify param: popup_browser_view; type: refptr_diff
  DCHECK(popup_browser_view);
  if (!popup_browser_view) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombBrowserViewDelegateCppToC::Get(self)->OnPopupBrowserViewCreated(
          HoneycombBrowserViewCToCpp::Wrap(browser_view),
          HoneycombBrowserViewCToCpp::Wrap(popup_browser_view),
          is_devtools ? true : false);

  // Return type: bool
  return _retval;
}

honey_chrome_toolbar_type_t HONEYCOMB_CALLBACK
browser_view_delegate_get_chrome_toolbar_type(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HONEYCOMB_CTT_NONE;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return HONEYCOMB_CTT_NONE;
  }

  // Execute
  honey_chrome_toolbar_type_t _retval =
      HoneycombBrowserViewDelegateCppToC::Get(self)->GetChromeToolbarType(
          HoneycombBrowserViewCToCpp::Wrap(browser_view));

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
browser_view_delegate_use_frameless_window_for_picture_in_picture(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserViewDelegateCppToC::Get(self)
                     ->UseFramelessWindowForPictureInPicture(
                         HoneycombBrowserViewCToCpp::Wrap(browser_view));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK browser_view_delegate_on_gesture_command(
    struct _honey_browser_view_delegate_t* self,
    honey_browser_view_t* browser_view,
    honey_gesture_command_t gesture_command) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser_view; type: refptr_diff
  DCHECK(browser_view);
  if (!browser_view) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombBrowserViewDelegateCppToC::Get(self)->OnGestureCommand(
      HoneycombBrowserViewCToCpp::Wrap(browser_view), gesture_command);

  // Return type: bool
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
browser_view_delegate_get_preferred_size(struct _honey_view_delegate_t* self,
                                         honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombSize();
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return HoneycombSize();
  }

  // Execute
  honey_size_t _retval = HoneycombBrowserViewDelegateCppToC::Get(
                           reinterpret_cast<honey_browser_view_delegate_t*>(self))
                           ->GetPreferredSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
browser_view_delegate_get_minimum_size(struct _honey_view_delegate_t* self,
                                       honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombSize();
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return HoneycombSize();
  }

  // Execute
  honey_size_t _retval = HoneycombBrowserViewDelegateCppToC::Get(
                           reinterpret_cast<honey_browser_view_delegate_t*>(self))
                           ->GetMinimumSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
browser_view_delegate_get_maximum_size(struct _honey_view_delegate_t* self,
                                       honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombSize();
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return HoneycombSize();
  }

  // Execute
  honey_size_t _retval = HoneycombBrowserViewDelegateCppToC::Get(
                           reinterpret_cast<honey_browser_view_delegate_t*>(self))
                           ->GetMaximumSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
browser_view_delegate_get_height_for_width(struct _honey_view_delegate_t* self,
                                           honey_view_t* view,
                                           int width) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return 0;
  }

  // Execute
  int _retval = HoneycombBrowserViewDelegateCppToC::Get(
                    reinterpret_cast<honey_browser_view_delegate_t*>(self))
                    ->GetHeightForWidth(HoneycombViewCToCpp::Wrap(view), width);

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_parent_view_changed(struct _honey_view_delegate_t* self,
                                             honey_view_t* view,
                                             int added,
                                             honey_view_t* parent) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }
  // Verify param: parent; type: refptr_diff
  DCHECK(parent);
  if (!parent) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnParentViewChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false,
                            HoneycombViewCToCpp::Wrap(parent));
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_child_view_changed(struct _honey_view_delegate_t* self,
                                            honey_view_t* view,
                                            int added,
                                            honey_view_t* child) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }
  // Verify param: child; type: refptr_diff
  DCHECK(child);
  if (!child) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnChildViewChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false,
                           HoneycombViewCToCpp::Wrap(child));
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_window_changed(struct _honey_view_delegate_t* self,
                                        honey_view_t* view,
                                        int added) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnWindowChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false);
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_layout_changed(struct _honey_view_delegate_t* self,
                                        honey_view_t* view,
                                        const honey_rect_t* new_bounds) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }
  // Verify param: new_bounds; type: simple_byref_const
  DCHECK(new_bounds);
  if (!new_bounds) {
    return;
  }

  // Translate param: new_bounds; type: simple_byref_const
  HoneycombRect new_boundsVal = new_bounds ? *new_bounds : HoneycombRect();

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnLayoutChanged(HoneycombViewCToCpp::Wrap(view), new_boundsVal);
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_focus(struct _honey_view_delegate_t* self,
                               honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnFocus(HoneycombViewCToCpp::Wrap(view));
}

void HONEYCOMB_CALLBACK
browser_view_delegate_on_blur(struct _honey_view_delegate_t* self,
                              honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view) {
    return;
  }

  // Execute
  HoneycombBrowserViewDelegateCppToC::Get(
      reinterpret_cast<honey_browser_view_delegate_t*>(self))
      ->OnBlur(HoneycombViewCToCpp::Wrap(view));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombBrowserViewDelegateCppToC::HoneycombBrowserViewDelegateCppToC() {
  GetStruct()->on_browser_created = browser_view_delegate_on_browser_created;
  GetStruct()->on_browser_destroyed =
      browser_view_delegate_on_browser_destroyed;
  GetStruct()->get_delegate_for_popup_browser_view =
      browser_view_delegate_get_delegate_for_popup_browser_view;
  GetStruct()->on_popup_browser_view_created =
      browser_view_delegate_on_popup_browser_view_created;
  GetStruct()->get_chrome_toolbar_type =
      browser_view_delegate_get_chrome_toolbar_type;
  GetStruct()->use_frameless_window_for_picture_in_picture =
      browser_view_delegate_use_frameless_window_for_picture_in_picture;
  GetStruct()->on_gesture_command = browser_view_delegate_on_gesture_command;
  GetStruct()->base.get_preferred_size =
      browser_view_delegate_get_preferred_size;
  GetStruct()->base.get_minimum_size = browser_view_delegate_get_minimum_size;
  GetStruct()->base.get_maximum_size = browser_view_delegate_get_maximum_size;
  GetStruct()->base.get_height_for_width =
      browser_view_delegate_get_height_for_width;
  GetStruct()->base.on_parent_view_changed =
      browser_view_delegate_on_parent_view_changed;
  GetStruct()->base.on_child_view_changed =
      browser_view_delegate_on_child_view_changed;
  GetStruct()->base.on_window_changed = browser_view_delegate_on_window_changed;
  GetStruct()->base.on_layout_changed = browser_view_delegate_on_layout_changed;
  GetStruct()->base.on_focus = browser_view_delegate_on_focus;
  GetStruct()->base.on_blur = browser_view_delegate_on_blur;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombBrowserViewDelegateCppToC::~HoneycombBrowserViewDelegateCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombBrowserViewDelegate> HoneycombCppToCRefCounted<
    HoneycombBrowserViewDelegateCppToC,
    HoneycombBrowserViewDelegate,
    honey_browser_view_delegate_t>::UnwrapDerived(HoneycombWrapperType type,
                                                honey_browser_view_delegate_t*
                                                    s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombBrowserViewDelegateCppToC,
                                   HoneycombBrowserViewDelegate,
                                   honey_browser_view_delegate_t>::kWrapperType =
    WT_BROWSER_VIEW_DELEGATE;
