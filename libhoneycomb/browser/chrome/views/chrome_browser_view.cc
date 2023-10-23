// Copyright 2021 The Honeycomb Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#include "libhoneycomb/browser/chrome/views/chrome_browser_view.h"

#include "libhoneycomb/browser/chrome/views/chrome_browser_frame.h"
#include "libhoneycomb/browser/views/browser_view_impl.h"

ChromeBrowserView::ChromeBrowserView(HoneycombBrowserViewImpl* honey_browser_view)
    : ParentClass(honey_browser_view->delegate()),
      honey_browser_view_(honey_browser_view) {}

void ChromeBrowserView::InitBrowser(std::unique_ptr<Browser> browser) {
  DCHECK(!web_view_);

  // Initialize the BrowserFrame and BrowserView.
  auto chrome_widget = static_cast<ChromeBrowserFrame*>(GetWidget());
  chrome_widget->Init(this, std::move(browser));

  // Retrieve the views::WebView that was created by the above initializations.
  web_view_ = honey_browser_view_->web_view();
  DCHECK(web_view_);

  ParentClass::AddedToWidget();
}

void ChromeBrowserView::Destroyed() {
  DCHECK(!destroyed_);
  destroyed_ = true;
  web_view_ = nullptr;
}

void ChromeBrowserView::ViewHierarchyChanged(
    const views::ViewHierarchyChangedDetails& details) {
  ParentClass::ViewHierarchyChanged(details);
  if (details.is_add && details.child == this) {
    gfx::Size size = GetPreferredSize();
    if (size.IsEmpty()) {
      // No size was provided for this View. Size it to the parent by default
      // or, depending on the Layout, the browser may be initially 0x0 size and
      // will not display until the parent is next resized (resulting in a call
      // to WebView::OnBoundsChanged). For example, this can happen when adding
      // this View to a HoneycombWindow with FillLayout and then calling
      // HoneycombWindow::Show() without first resizing the HoneycombWindow.
      size = details.parent->GetPreferredSize();
      if (!size.IsEmpty()) {
        SetSize(size);
      }
    }
  }
}

void ChromeBrowserView::AddedToWidget() {
  // Results in a call to InitBrowser which calls ParentClass::AddedToWidget.
  honey_browser_view_->OnBrowserViewAdded();
}

void ChromeBrowserView::OnBoundsChanged(const gfx::Rect& previous_bounds) {
  ParentClass::OnBoundsChanged(previous_bounds);
  honey_browser_view_->OnBoundsChanged();
}

void ChromeBrowserView::OnGestureEvent(ui::GestureEvent* event) {
  if (honey_browser_view_->OnGestureEvent(event)) {
    return;
  }
  ParentClass::OnGestureEvent(event);
}

ToolbarView* ChromeBrowserView::OverrideCreateToolbar() {
  if (honey_delegate()) {
    auto toolbar_type = honey_delegate()->GetChromeToolbarType(honey_browser_view_);
    absl::optional<ToolbarView::DisplayMode> display_mode;
    switch (toolbar_type) {
      case HONEYCOMB_CTT_NORMAL:
        display_mode = ToolbarView::DisplayMode::NORMAL;
        break;
      case HONEYCOMB_CTT_LOCATION:
        display_mode = ToolbarView::DisplayMode::LOCATION;
        break;
      default:
        break;
    }
    if (display_mode) {
      honey_toolbar_ =
          HoneycombToolbarViewImpl::Create(nullptr, browser(), this, display_mode);
      // Ownership will be taken by BrowserView.
      view_util::PassOwnership(honey_toolbar_).release();
      return honey_toolbar_->root_view();
    }
  }

  return nullptr;
}
