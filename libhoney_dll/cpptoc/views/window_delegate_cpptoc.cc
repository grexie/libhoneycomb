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
// $hash=61afa22f2b3401bab08c3faeb872e3de7a99ca5b$
//

#include "libhoney_dll/cpptoc/views/window_delegate_cpptoc.h"
#include "libhoney_dll/ctocpp/views/view_ctocpp.h"
#include "libhoney_dll/ctocpp/views/window_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK
window_delegate_on_window_created(struct _honey_window_delegate_t* self,
                                  honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return;
  }

  // Execute
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowCreated(
      HoneycombWindowCToCpp::Wrap(window));
}

void HONEYCOMB_CALLBACK
window_delegate_on_window_closing(struct _honey_window_delegate_t* self,
                                  honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return;
  }

  // Execute
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowClosing(
      HoneycombWindowCToCpp::Wrap(window));
}

void HONEYCOMB_CALLBACK
window_delegate_on_window_destroyed(struct _honey_window_delegate_t* self,
                                    honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return;
  }

  // Execute
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowDestroyed(
      HoneycombWindowCToCpp::Wrap(window));
}

void HONEYCOMB_CALLBACK window_delegate_on_window_activation_changed(
    struct _honey_window_delegate_t* self,
    honey_window_t* window,
    int active) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return;
  }

  // Execute
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowActivationChanged(
      HoneycombWindowCToCpp::Wrap(window), active ? true : false);
}

void HONEYCOMB_CALLBACK
window_delegate_on_window_bounds_changed(struct _honey_window_delegate_t* self,
                                         honey_window_t* window,
                                         const honey_rect_t* new_bounds) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
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
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowBoundsChanged(
      HoneycombWindowCToCpp::Wrap(window), new_boundsVal);
}

void HONEYCOMB_CALLBACK window_delegate_on_window_fullscreen_transition(
    struct _honey_window_delegate_t* self,
    honey_window_t* window,
    int is_completed) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return;
  }

  // Execute
  HoneycombWindowDelegateCppToC::Get(self)->OnWindowFullscreenTransition(
      HoneycombWindowCToCpp::Wrap(window), is_completed ? true : false);
}

honey_window_t* HONEYCOMB_CALLBACK
window_delegate_get_parent_window(struct _honey_window_delegate_t* self,
                                  honey_window_t* window,
                                  int* is_menu,
                                  int* can_activate_menu) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return NULL;
  }
  // Verify param: is_menu; type: bool_byaddr
  DCHECK(is_menu);
  if (!is_menu) {
    return NULL;
  }
  // Verify param: can_activate_menu; type: bool_byaddr
  DCHECK(can_activate_menu);
  if (!can_activate_menu) {
    return NULL;
  }

  // Translate param: is_menu; type: bool_byaddr
  bool is_menuBool = (is_menu && *is_menu) ? true : false;
  // Translate param: can_activate_menu; type: bool_byaddr
  bool can_activate_menuBool =
      (can_activate_menu && *can_activate_menu) ? true : false;

  // Execute
  HoneycombRefPtr<HoneycombWindow> _retval =
      HoneycombWindowDelegateCppToC::Get(self)->GetParentWindow(
          HoneycombWindowCToCpp::Wrap(window), &is_menuBool, &can_activate_menuBool);

  // Restore param: is_menu; type: bool_byaddr
  if (is_menu) {
    *is_menu = is_menuBool ? true : false;
  }
  // Restore param: can_activate_menu; type: bool_byaddr
  if (can_activate_menu) {
    *can_activate_menu = can_activate_menuBool ? true : false;
  }

  // Return type: refptr_diff
  return HoneycombWindowCToCpp::Unwrap(_retval);
}

int HONEYCOMB_CALLBACK
window_delegate_is_window_modal_dialog(struct _honey_window_delegate_t* self,
                                       honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->IsWindowModalDialog(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

honey_rect_t HONEYCOMB_CALLBACK
window_delegate_get_initial_bounds(struct _honey_window_delegate_t* self,
                                   honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombRect();
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return HoneycombRect();
  }

  // Execute
  honey_rect_t _retval = HoneycombWindowDelegateCppToC::Get(self)->GetInitialBounds(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: simple
  return _retval;
}

honey_show_state_t HONEYCOMB_CALLBACK
window_delegate_get_initial_show_state(struct _honey_window_delegate_t* self,
                                       honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HONEYCOMB_SHOW_STATE_NORMAL;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return HONEYCOMB_SHOW_STATE_NORMAL;
  }

  // Execute
  honey_show_state_t _retval =
      HoneycombWindowDelegateCppToC::Get(self)->GetInitialShowState(
          HoneycombWindowCToCpp::Wrap(window));

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_is_frameless(struct _honey_window_delegate_t* self,
                             honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->IsFrameless(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK window_delegate_with_standard_window_buttons(
    struct _honey_window_delegate_t* self,
    honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->WithStandardWindowButtons(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_get_titlebar_height(struct _honey_window_delegate_t* self,
                                    honey_window_t* window,
                                    float* titlebar_height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }
  // Verify param: titlebar_height; type: simple_byaddr
  DCHECK(titlebar_height);
  if (!titlebar_height) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->GetTitlebarHeight(
      HoneycombWindowCToCpp::Wrap(window), titlebar_height);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK window_delegate_can_resize(struct _honey_window_delegate_t* self,
                                            honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->CanResize(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_can_maximize(struct _honey_window_delegate_t* self,
                             honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->CanMaximize(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_can_minimize(struct _honey_window_delegate_t* self,
                             honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->CanMinimize(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK window_delegate_can_close(struct _honey_window_delegate_t* self,
                                           honey_window_t* window) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->CanClose(
      HoneycombWindowCToCpp::Wrap(window));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_on_accelerator(struct _honey_window_delegate_t* self,
                               honey_window_t* window,
                               int command_id) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->OnAccelerator(
      HoneycombWindowCToCpp::Wrap(window), command_id);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_on_key_event(struct _honey_window_delegate_t* self,
                             honey_window_t* window,
                             const honey_key_event_t* event) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: window; type: refptr_diff
  DCHECK(window);
  if (!window) {
    return 0;
  }
  // Verify param: event; type: simple_byref_const
  DCHECK(event);
  if (!event) {
    return 0;
  }

  // Translate param: event; type: simple_byref_const
  HoneycombKeyEvent eventVal = event ? *event : HoneycombKeyEvent();

  // Execute
  bool _retval = HoneycombWindowDelegateCppToC::Get(self)->OnKeyEvent(
      HoneycombWindowCToCpp::Wrap(window), eventVal);

  // Return type: bool
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
window_delegate_get_preferred_size(struct _honey_view_delegate_t* self,
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
  honey_size_t _retval = HoneycombWindowDelegateCppToC::Get(
                           reinterpret_cast<honey_window_delegate_t*>(self))
                           ->GetPreferredSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
window_delegate_get_minimum_size(struct _honey_view_delegate_t* self,
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
  honey_size_t _retval = HoneycombWindowDelegateCppToC::Get(
                           reinterpret_cast<honey_window_delegate_t*>(self))
                           ->GetMinimumSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

honey_size_t HONEYCOMB_CALLBACK
window_delegate_get_maximum_size(struct _honey_view_delegate_t* self,
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
  honey_size_t _retval = HoneycombWindowDelegateCppToC::Get(
                           reinterpret_cast<honey_window_delegate_t*>(self))
                           ->GetMaximumSize(HoneycombViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK
window_delegate_get_height_for_width(struct _honey_view_delegate_t* self,
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
  int _retval = HoneycombWindowDelegateCppToC::Get(
                    reinterpret_cast<honey_window_delegate_t*>(self))
                    ->GetHeightForWidth(HoneycombViewCToCpp::Wrap(view), width);

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK
window_delegate_on_parent_view_changed(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnParentViewChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false,
                            HoneycombViewCToCpp::Wrap(parent));
}

void HONEYCOMB_CALLBACK
window_delegate_on_child_view_changed(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnChildViewChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false,
                           HoneycombViewCToCpp::Wrap(child));
}

void HONEYCOMB_CALLBACK
window_delegate_on_window_changed(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnWindowChanged(HoneycombViewCToCpp::Wrap(view), added ? true : false);
}

void HONEYCOMB_CALLBACK
window_delegate_on_layout_changed(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnLayoutChanged(HoneycombViewCToCpp::Wrap(view), new_boundsVal);
}

void HONEYCOMB_CALLBACK window_delegate_on_focus(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnFocus(HoneycombViewCToCpp::Wrap(view));
}

void HONEYCOMB_CALLBACK window_delegate_on_blur(struct _honey_view_delegate_t* self,
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
  HoneycombWindowDelegateCppToC::Get(reinterpret_cast<honey_window_delegate_t*>(self))
      ->OnBlur(HoneycombViewCToCpp::Wrap(view));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombWindowDelegateCppToC::HoneycombWindowDelegateCppToC() {
  GetStruct()->on_window_created = window_delegate_on_window_created;
  GetStruct()->on_window_closing = window_delegate_on_window_closing;
  GetStruct()->on_window_destroyed = window_delegate_on_window_destroyed;
  GetStruct()->on_window_activation_changed =
      window_delegate_on_window_activation_changed;
  GetStruct()->on_window_bounds_changed =
      window_delegate_on_window_bounds_changed;
  GetStruct()->on_window_fullscreen_transition =
      window_delegate_on_window_fullscreen_transition;
  GetStruct()->get_parent_window = window_delegate_get_parent_window;
  GetStruct()->is_window_modal_dialog = window_delegate_is_window_modal_dialog;
  GetStruct()->get_initial_bounds = window_delegate_get_initial_bounds;
  GetStruct()->get_initial_show_state = window_delegate_get_initial_show_state;
  GetStruct()->is_frameless = window_delegate_is_frameless;
  GetStruct()->with_standard_window_buttons =
      window_delegate_with_standard_window_buttons;
  GetStruct()->get_titlebar_height = window_delegate_get_titlebar_height;
  GetStruct()->can_resize = window_delegate_can_resize;
  GetStruct()->can_maximize = window_delegate_can_maximize;
  GetStruct()->can_minimize = window_delegate_can_minimize;
  GetStruct()->can_close = window_delegate_can_close;
  GetStruct()->on_accelerator = window_delegate_on_accelerator;
  GetStruct()->on_key_event = window_delegate_on_key_event;
  GetStruct()->base.base.get_preferred_size =
      window_delegate_get_preferred_size;
  GetStruct()->base.base.get_minimum_size = window_delegate_get_minimum_size;
  GetStruct()->base.base.get_maximum_size = window_delegate_get_maximum_size;
  GetStruct()->base.base.get_height_for_width =
      window_delegate_get_height_for_width;
  GetStruct()->base.base.on_parent_view_changed =
      window_delegate_on_parent_view_changed;
  GetStruct()->base.base.on_child_view_changed =
      window_delegate_on_child_view_changed;
  GetStruct()->base.base.on_window_changed = window_delegate_on_window_changed;
  GetStruct()->base.base.on_layout_changed = window_delegate_on_layout_changed;
  GetStruct()->base.base.on_focus = window_delegate_on_focus;
  GetStruct()->base.base.on_blur = window_delegate_on_blur;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombWindowDelegateCppToC::~HoneycombWindowDelegateCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombWindowDelegate> HoneycombCppToCRefCounted<
    HoneycombWindowDelegateCppToC,
    HoneycombWindowDelegate,
    honey_window_delegate_t>::UnwrapDerived(HoneycombWrapperType type,
                                          honey_window_delegate_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombWindowDelegateCppToC,
                                   HoneycombWindowDelegate,
                                   honey_window_delegate_t>::kWrapperType =
    WT_WINDOW_DELEGATE;