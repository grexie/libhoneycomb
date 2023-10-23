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
// $hash=8c0bc19bcd5b9f53b0ee556fb0117e9a6115eb7f$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_MENU_BUTTON_PRESSED_LOCK_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_MENU_BUTTON_PRESSED_LOCK_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/views/honey_menu_button_capi.h"
#include "include/capi/views/honey_menu_button_delegate_capi.h"
#include "include/views/honey_menu_button.h"
#include "include/views/honey_menu_button_delegate.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombMenuButtonPressedLockCToCpp
    : public HoneycombCToCppRefCounted<HoneycombMenuButtonPressedLockCToCpp,
                                 HoneycombMenuButtonPressedLock,
                                 honey_menu_button_pressed_lock_t> {
 public:
  HoneycombMenuButtonPressedLockCToCpp();
  virtual ~HoneycombMenuButtonPressedLockCToCpp();

  // HoneycombMenuButtonPressedLock methods.
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_MENU_BUTTON_PRESSED_LOCK_CTOCPP_H_
