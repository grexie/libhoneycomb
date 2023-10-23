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
// $hash=3a3c2eee1765f8a1d86044eadc75eca9c6fae25f$
//

#ifndef HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_SCROLL_VIEW_CTOCPP_H_
#define HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_SCROLL_VIEW_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/views/honey_scroll_view_capi.h"
#include "include/views/honey_scroll_view.h"
#include "libhoneycomb_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombScrollViewCToCpp : public HoneycombCToCppRefCounted<HoneycombScrollViewCToCpp,
                                                       HoneycombScrollView,
                                                       honey_scroll_view_t> {
 public:
  HoneycombScrollViewCToCpp();
  virtual ~HoneycombScrollViewCToCpp();

  // HoneycombScrollView methods.
  void SetContentView(HoneycombRefPtr<HoneycombView> view) override;
  HoneycombRefPtr<HoneycombView> GetContentView() override;
  HoneycombRect GetVisibleContentRect() override;
  bool HasHorizontalScrollbar() override;
  int GetHorizontalScrollbarHeight() override;
  bool HasVerticalScrollbar() override;
  int GetVerticalScrollbarWidth() override;

  // HoneycombView methods.
  HoneycombRefPtr<HoneycombBrowserView> AsBrowserView() override;
  HoneycombRefPtr<HoneycombButton> AsButton() override;
  HoneycombRefPtr<HoneycombPanel> AsPanel() override;
  HoneycombRefPtr<HoneycombScrollView> AsScrollView() override;
  HoneycombRefPtr<HoneycombTextfield> AsTextfield() override;
  HoneycombString GetTypeString() override;
  HoneycombString ToString(bool include_children) override;
  bool IsValid() override;
  bool IsAttached() override;
  bool IsSame(HoneycombRefPtr<HoneycombView> that) override;
  HoneycombRefPtr<HoneycombViewDelegate> GetDelegate() override;
  HoneycombRefPtr<HoneycombWindow> GetWindow() override;
  int GetID() override;
  void SetID(int id) override;
  int GetGroupID() override;
  void SetGroupID(int group_id) override;
  HoneycombRefPtr<HoneycombView> GetParentView() override;
  HoneycombRefPtr<HoneycombView> GetViewForID(int id) override;
  void SetBounds(const HoneycombRect& bounds) override;
  HoneycombRect GetBounds() override;
  HoneycombRect GetBoundsInScreen() override;
  void SetSize(const HoneycombSize& size) override;
  HoneycombSize GetSize() override;
  void SetPosition(const HoneycombPoint& position) override;
  HoneycombPoint GetPosition() override;
  void SetInsets(const HoneycombInsets& insets) override;
  HoneycombInsets GetInsets() override;
  HoneycombSize GetPreferredSize() override;
  void SizeToPreferredSize() override;
  HoneycombSize GetMinimumSize() override;
  HoneycombSize GetMaximumSize() override;
  int GetHeightForWidth(int width) override;
  void InvalidateLayout() override;
  void SetVisible(bool visible) override;
  bool IsVisible() override;
  bool IsDrawn() override;
  void SetEnabled(bool enabled) override;
  bool IsEnabled() override;
  void SetFocusable(bool focusable) override;
  bool IsFocusable() override;
  bool IsAccessibilityFocusable() override;
  void RequestFocus() override;
  void SetBackgroundColor(honey_color_t color) override;
  honey_color_t GetBackgroundColor() override;
  bool ConvertPointToScreen(HoneycombPoint& point) override;
  bool ConvertPointFromScreen(HoneycombPoint& point) override;
  bool ConvertPointToWindow(HoneycombPoint& point) override;
  bool ConvertPointFromWindow(HoneycombPoint& point) override;
  bool ConvertPointToView(HoneycombRefPtr<HoneycombView> view, HoneycombPoint& point) override;
  bool ConvertPointFromView(HoneycombRefPtr<HoneycombView> view, HoneycombPoint& point) override;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_DLL_CTOCPP_VIEWS_SCROLL_VIEW_CTOCPP_H_
