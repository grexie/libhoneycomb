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
// $hash=f734e948a17b74234c1b1bc294b8856ce58ff49e$
//

#include "libhoney_dll/ctocpp/menu_model_delegate_ctocpp.h"
#include "libhoney_dll/cpptoc/menu_model_cpptoc.h"
#include "libhoney_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::ExecuteCommand(
    HoneycombRefPtr<HoneycombMenuModel> menu_model,
    int command_id,
    honey_event_flags_t event_flags) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, execute_command)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->execute_command(_struct, HoneycombMenuModelCppToC::Wrap(menu_model),
                           command_id, event_flags);
}

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::MouseOutsideMenu(
    HoneycombRefPtr<HoneycombMenuModel> menu_model,
    const HoneycombPoint& screen_point) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, mouse_outside_menu)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->mouse_outside_menu(_struct, HoneycombMenuModelCppToC::Wrap(menu_model),
                              &screen_point);
}

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::UnhandledOpenSubmenu(
    HoneycombRefPtr<HoneycombMenuModel> menu_model,
    bool is_rtl) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, unhandled_open_submenu)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->unhandled_open_submenu(_struct, HoneycombMenuModelCppToC::Wrap(menu_model),
                                  is_rtl);
}

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::UnhandledCloseSubmenu(
    HoneycombRefPtr<HoneycombMenuModel> menu_model,
    bool is_rtl) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, unhandled_close_submenu)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->unhandled_close_submenu(
      _struct, HoneycombMenuModelCppToC::Wrap(menu_model), is_rtl);
}

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::MenuWillShow(
    HoneycombRefPtr<HoneycombMenuModel> menu_model) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, menu_will_show)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->menu_will_show(_struct, HoneycombMenuModelCppToC::Wrap(menu_model));
}

NO_SANITIZE("cfi-icall")
void HoneycombMenuModelDelegateCToCpp::MenuClosed(
    HoneycombRefPtr<HoneycombMenuModel> menu_model) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, menu_closed)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->menu_closed(_struct, HoneycombMenuModelCppToC::Wrap(menu_model));
}

NO_SANITIZE("cfi-icall")
bool HoneycombMenuModelDelegateCToCpp::FormatLabel(HoneycombRefPtr<HoneycombMenuModel> menu_model,
                                             HoneycombString& label) {
  shutdown_checker::AssertNotShutdown();

  honey_menu_model_delegate_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, format_label)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_diff
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->format_label(
      _struct, HoneycombMenuModelCppToC::Wrap(menu_model), label.GetWritableStruct());

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombMenuModelDelegateCToCpp::HoneycombMenuModelDelegateCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombMenuModelDelegateCToCpp::~HoneycombMenuModelDelegateCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_menu_model_delegate_t* HoneycombCToCppRefCounted<
    HoneycombMenuModelDelegateCToCpp,
    HoneycombMenuModelDelegate,
    honey_menu_model_delegate_t>::UnwrapDerived(HoneycombWrapperType type,
                                              HoneycombMenuModelDelegate* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombMenuModelDelegateCToCpp,
                                   HoneycombMenuModelDelegate,
                                   honey_menu_model_delegate_t>::kWrapperType =
    WT_MENU_MODEL_DELEGATE;