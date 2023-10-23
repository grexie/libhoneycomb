// Copyright (c) 2015 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "tests/honeyclient/browser/root_window.h"

#include "include/base/honey_callback_helpers.h"

#include "tests/honeyclient/browser/main_context.h"
#include "tests/honeyclient/browser/root_window_manager.h"

namespace client {

RootWindowConfig::RootWindowConfig() : url(MainContext::Get()->GetMainURL()) {}

RootWindow::RootWindow() : delegate_(nullptr) {}

RootWindow::~RootWindow() {}

// static
scoped_refptr<RootWindow> RootWindow::GetForBrowser(int browser_id) {
  return MainContext::Get()->GetRootWindowManager()->GetWindowForBrowser(
      browser_id);
}

void RootWindow::OnExtensionsChanged(const ExtensionSet& extensions) {
  REQUIRE_MAIN_THREAD();
  DCHECK(delegate_);
  DCHECK(!WithExtension());

  if (extensions.empty()) {
    return;
  }

  ExtensionSet::const_iterator it = extensions.begin();
  for (; it != extensions.end(); ++it) {
    delegate_->CreateExtensionWindow(*it, HoneycombRect(), nullptr, base::DoNothing(),
                                     WithWindowlessRendering());
  }
}

}  // namespace client
