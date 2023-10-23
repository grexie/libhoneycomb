// Copyright (c) 2016 Marshall A. Greenblatt. All rights reserved.
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
// The contents of this file must follow a specific format in order to
// support the Honeycomb translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef HONEYCOMB_INCLUDE_VIEWS_HONEYCOMB_MENU_BUTTON_DELEGATE_H_
#define HONEYCOMB_INCLUDE_VIEWS_HONEYCOMB_MENU_BUTTON_DELEGATE_H_
#pragma once

#include "include/views/honey_button_delegate.h"

class HoneycombMenuButton;

///
/// MenuButton pressed lock is released when this object is destroyed.
///
/*--honey(source=library)--*/
class HoneycombMenuButtonPressedLock : public HoneycombBaseRefCounted {};

///
/// Implement this interface to handle MenuButton events. The methods of this
/// class will be called on the browser process UI thread unless otherwise
/// indicated.
///
/*--honey(source=client)--*/
class HoneycombMenuButtonDelegate : public HoneycombButtonDelegate {
 public:
  ///
  /// Called when |button| is pressed. Call HoneycombMenuButton::ShowMenu() to show a
  /// popup menu at |screen_point|. When showing a custom popup such as a window
  /// keep a reference to |button_pressed_lock| until the popup is hidden to
  /// maintain the pressed button state.
  ///
  /*--honey()--*/
  virtual void OnMenuButtonPressed(
      HoneycombRefPtr<HoneycombMenuButton> menu_button,
      const HoneycombPoint& screen_point,
      HoneycombRefPtr<HoneycombMenuButtonPressedLock> button_pressed_lock) = 0;
};

#endif  // HONEYCOMB_INCLUDE_VIEWS_HONEYCOMB_MENU_BUTTON_DELEGATE_H_
