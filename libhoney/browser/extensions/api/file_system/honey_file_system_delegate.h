// Copyright (c) 2012 The Chromium Authors and 2016 the CEF Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEY_BROWSER_EXTENSIONS_API_FILE_SYSTEM_FILE_SYSTEM_DELEGATE_H_
#define HONEYCOMB_LIBHONEY_BROWSER_EXTENSIONS_API_FILE_SYSTEM_FILE_SYSTEM_DELEGATE_H_

#include <memory>

#include "base/compiler_specific.h"
#include "base/functional/callback.h"
#include "base/memory/ref_counted.h"
#include "extensions/browser/api/execute_code_function.h"
#include "extensions/browser/api/file_system/file_system_delegate.h"
#include "extensions/browser/extension_function.h"

namespace content {
class WebContents;
}

namespace extensions {
namespace honey {

class HoneycombFileSystemDelegate : public FileSystemDelegate {
 public:
  HoneycombFileSystemDelegate();

  HoneycombFileSystemDelegate(const HoneycombFileSystemDelegate&) = delete;
  HoneycombFileSystemDelegate& operator=(const HoneycombFileSystemDelegate&) = delete;

  ~HoneycombFileSystemDelegate() override;

  // FileSystemDelegate
  base::FilePath GetDefaultDirectory() override;
  base::FilePath GetManagedSaveAsDirectory(
      content::BrowserContext* browser_context,
      const Extension& extension) override;
  bool ShowSelectFileDialog(
      scoped_refptr<ExtensionFunction> extension_function,
      ui::SelectFileDialog::Type type,
      const base::FilePath& default_path,
      const ui::SelectFileDialog::FileTypeInfo* file_types,
      FileSystemDelegate::FilesSelectedCallback files_selected_callback,
      base::OnceClosure file_selection_canceled_callback) override;
  void ConfirmSensitiveDirectoryAccess(bool has_write_permission,
                                       const std::u16string& app_name,
                                       content::WebContents* web_contents,
                                       base::OnceClosure on_accept,
                                       base::OnceClosure on_cancel) override;
  int GetDescriptionIdForAcceptType(const std::string& accept_type) override;
  SavedFilesServiceInterface* GetSavedFilesService(
      content::BrowserContext* browser_context) override;
};

}  // namespace honey
}  // namespace extensions

#endif  // HONEYCOMB_LIBHONEY_BROWSER_EXTENSIONS_API_FILE_SYSTEM_FILE_SYSTEM_DELEGATE_H_