// Copyright (c) 2012 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "tests/honeyclient/browser/dialog_test.h"

#include <string>

#include "include/honey_browser.h"
#include "include/wrapper/honey_helpers.h"
#include "tests/honeyclient/browser/test_runner.h"
#include "tests/shared/browser/file_util.h"

namespace client {
namespace dialog_test {

namespace {

const char kTestUrlPath[] = "/dialogs";
const char kFileOpenPngMessageName[] = "DialogTest.FileOpenPng";
const char kFileOpenImageMessageName[] = "DialogTest.FileOpenImage";
const char kFileOpenMultipleMessageName[] = "DialogTest.FileOpenMultiple";
const char kFileOpenFolderMessageName[] = "DialogTest.FileOpenFolder";
const char kFileSaveMessageName[] = "DialogTest.FileSave";

// Store persistent dialog state information.
class DialogState : public base::RefCountedThreadSafe<DialogState> {
 public:
  DialogState() : mode_(FILE_DIALOG_OPEN), pending_(false) {}

  honey_file_dialog_mode_t mode_;
  HoneycombString last_file_;
  bool pending_;

  DISALLOW_COPY_AND_ASSIGN(DialogState);
};

// Callback executed when the file dialog is dismissed.
class DialogCallback : public HoneycombRunFileDialogCallback {
 public:
  DialogCallback(
      HoneycombRefPtr<HoneycombMessageRouterBrowserSide::Callback> router_callback,
      scoped_refptr<DialogState> dialog_state)
      : router_callback_(router_callback), dialog_state_(dialog_state) {}

  virtual void OnFileDialogDismissed(
      const std::vector<HoneycombString>& file_paths) override {
    HONEYCOMB_REQUIRE_UI_THREAD();
    DCHECK(dialog_state_->pending_);

    if (!file_paths.empty()) {
      dialog_state_->last_file_ = file_paths[0];
      if (dialog_state_->mode_ == FILE_DIALOG_OPEN_FOLDER) {
        std::string last_file = dialog_state_->last_file_;
        if (last_file[last_file.length() - 1] != file_util::kPathSep) {
          // Add a trailing slash so we know it's a directory. Otherwise, file
          // dialogs will think the last path component is a file name.
          last_file += file_util::kPathSep;
          dialog_state_->last_file_ = last_file;
        }
      }
    }

    // Send a message back to the render process with the list of file paths.
    std::string response;
    for (int i = 0; i < static_cast<int>(file_paths.size()); ++i) {
      if (!response.empty()) {
        response += "|";  // Use a delimiter disallowed in file paths.
      }
      response += file_paths[i];
    }

    router_callback_->Success(response);
    router_callback_ = nullptr;

    dialog_state_->pending_ = false;
    dialog_state_ = nullptr;
  }

 private:
  HoneycombRefPtr<HoneycombMessageRouterBrowserSide::Callback> router_callback_;
  scoped_refptr<DialogState> dialog_state_;

  IMPLEMENT_REFCOUNTING(DialogCallback);
  DISALLOW_COPY_AND_ASSIGN(DialogCallback);
};

// Handle messages in the browser process.
class Handler : public HoneycombMessageRouterBrowserSide::Handler {
 public:
  Handler() {}

  // Called due to honeyQuery execution in dialogs.html.
  virtual bool OnQuery(HoneycombRefPtr<HoneycombBrowser> browser,
                       HoneycombRefPtr<HoneycombFrame> frame,
                       int64_t query_id,
                       const HoneycombString& request,
                       bool persistent,
                       HoneycombRefPtr<Callback> callback) override {
    HONEYCOMB_REQUIRE_UI_THREAD();

    // Only handle messages from the test URL.
    const std::string& url = frame->GetURL();
    if (!test_runner::IsTestURL(url, kTestUrlPath)) {
      return false;
    }

    if (!dialog_state_.get()) {
      dialog_state_ = new DialogState;
    }

    // Make sure we're only running one dialog at a time.
    DCHECK(!dialog_state_->pending_);

    std::vector<HoneycombString> accept_filters;
    std::string title;

    const std::string& message_name = request;
    if (message_name == kFileOpenPngMessageName) {
      dialog_state_->mode_ = FILE_DIALOG_OPEN;
      title = "My Open PNG Dialog";
      accept_filters.push_back(".png");
    } else if (message_name == kFileOpenImageMessageName) {
      dialog_state_->mode_ = FILE_DIALOG_OPEN;
      title = "My Open Image Dialog";
      accept_filters.push_back("image/*");
    } else if (message_name == kFileOpenMultipleMessageName) {
      dialog_state_->mode_ = FILE_DIALOG_OPEN_MULTIPLE;
      title = "My Open MultiType Dialog";
    } else if (message_name == kFileOpenFolderMessageName) {
      dialog_state_->mode_ = FILE_DIALOG_OPEN_FOLDER;
      title = "My Open Folder Dialog";
    } else if (message_name == kFileSaveMessageName) {
      dialog_state_->mode_ = FILE_DIALOG_SAVE;
      title = "My Save Dialog";
    } else {
      NOTREACHED();
      return true;
    }

    if (accept_filters.empty() &&
        dialog_state_->mode_ != FILE_DIALOG_OPEN_FOLDER) {
      // Build filters based on mime time.
      accept_filters.push_back("text/*");

      // Build filters based on file extension.
      accept_filters.push_back(".log");
      accept_filters.push_back(".patch");

      // Add specific filters as-is.
      accept_filters.push_back("Document Files|.doc;.odt");
      accept_filters.push_back("Image Files|.png;.jpg;.gif");
      accept_filters.push_back("PDF Files|.pdf");
    }

    dialog_state_->pending_ = true;

    browser->GetHost()->RunFileDialog(
        dialog_state_->mode_, title, dialog_state_->last_file_, accept_filters,
        new DialogCallback(callback, dialog_state_));

    return true;
  }

 private:
  scoped_refptr<DialogState> dialog_state_;

  DISALLOW_COPY_AND_ASSIGN(Handler);
};

}  // namespace

void CreateMessageHandlers(test_runner::MessageHandlerSet& handlers) {
  handlers.insert(new Handler());
}

}  // namespace dialog_test
}  // namespace client