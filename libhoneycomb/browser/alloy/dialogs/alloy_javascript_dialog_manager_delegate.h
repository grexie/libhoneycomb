// Copyright 2022 The Honeycomb Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEYCOMB_BROWSER_ALLOY_DIALOGS_ALLOY_JAVASCRIPT_DIALOG_MANAGER_DELEGATE_H_
#define HONEYCOMB_LIBHONEYCOMB_BROWSER_ALLOY_DIALOGS_ALLOY_JAVASCRIPT_DIALOG_MANAGER_DELEGATE_H_

#include <memory>

#include "chrome/browser/ui/javascript_dialogs/javascript_tab_modal_dialog_manager_delegate_desktop.h"

// Creates a JavaScriptTabModalDialogManagerDelegateDesktop for the Chrome
// environment.
std::unique_ptr<JavaScriptTabModalDialogManagerDelegateDesktop>
CreateAlloyJavaScriptTabModalDialogManagerDelegateDesktop(
    content::WebContents* web_contents);

#endif  // HONEYCOMB_LIBHONEYCOMB_BROWSER_ALLOY_DIALOGS_ALLOY_JAVASCRIPT_DIALOG_MANAGER_DELEGATE_H_