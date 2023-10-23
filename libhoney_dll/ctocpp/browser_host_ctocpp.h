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
// $hash=b4e11c91197cd5d6ccbe3a0d96aaae3792a6e05c$
//

#ifndef HONEYCOMB_LIBHONEY_DLL_CTOCPP_BROWSER_HOST_CTOCPP_H_
#define HONEYCOMB_LIBHONEY_DLL_CTOCPP_BROWSER_HOST_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_HONEYCOMB_SHARED)
#error This file can be included wrapper-side only
#endif

#include <vector>
#include "include/capi/honey_browser_capi.h"
#include "include/capi/honey_client_capi.h"
#include "include/honey_browser.h"
#include "include/honey_client.h"
#include "libhoney_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class HoneycombBrowserHostCToCpp : public HoneycombCToCppRefCounted<HoneycombBrowserHostCToCpp,
                                                        HoneycombBrowserHost,
                                                        honey_browser_host_t> {
 public:
  HoneycombBrowserHostCToCpp();
  virtual ~HoneycombBrowserHostCToCpp();

  // HoneycombBrowserHost methods.
  HoneycombRefPtr<HoneycombBrowser> GetBrowser() override;
  void CloseBrowser(bool force_close) override;
  bool TryCloseBrowser() override;
  void SetFocus(bool focus) override;
  HoneycombWindowHandle GetWindowHandle() override;
  HoneycombWindowHandle GetOpenerWindowHandle() override;
  bool HasView() override;
  HoneycombRefPtr<HoneycombClient> GetClient() override;
  HoneycombRefPtr<HoneycombRequestContext> GetRequestContext() override;
  bool CanZoom(honey_zoom_command_t command) override;
  void Zoom(honey_zoom_command_t command) override;
  double GetDefaultZoomLevel() override;
  double GetZoomLevel() override;
  void SetZoomLevel(double zoomLevel) override;
  void RunFileDialog(FileDialogMode mode,
                     const HoneycombString& title,
                     const HoneycombString& default_file_path,
                     const std::vector<HoneycombString>& accept_filters,
                     HoneycombRefPtr<HoneycombRunFileDialogCallback> callback) override;
  void StartDownload(const HoneycombString& url) override;
  void DownloadImage(const HoneycombString& image_url,
                     bool is_favicon,
                     uint32_t max_image_size,
                     bool bypass_cache,
                     HoneycombRefPtr<HoneycombDownloadImageCallback> callback) override;
  void Print() override;
  void PrintToPDF(const HoneycombString& path,
                  const HoneycombPdfPrintSettings& settings,
                  HoneycombRefPtr<HoneycombPdfPrintCallback> callback) override;
  void Find(const HoneycombString& searchText,
            bool forward,
            bool matchCase,
            bool findNext) override;
  void StopFinding(bool clearSelection) override;
  void ShowDevTools(const HoneycombWindowInfo& windowInfo,
                    HoneycombRefPtr<HoneycombClient> client,
                    const HoneycombBrowserSettings& settings,
                    const HoneycombPoint& inspect_element_at) override;
  void CloseDevTools() override;
  bool HasDevTools() override;
  bool SendDevToolsMessage(const void* message, size_t message_size) override;
  int ExecuteDevToolsMethod(int message_id,
                            const HoneycombString& method,
                            HoneycombRefPtr<HoneycombDictionaryValue> params) override;
  HoneycombRefPtr<HoneycombRegistration> AddDevToolsMessageObserver(
      HoneycombRefPtr<HoneycombDevToolsMessageObserver> observer) override;
  void GetNavigationEntries(HoneycombRefPtr<HoneycombNavigationEntryVisitor> visitor,
                            bool current_only) override;
  void ReplaceMisspelling(const HoneycombString& word) override;
  void AddWordToDictionary(const HoneycombString& word) override;
  bool IsWindowRenderingDisabled() override;
  void WasResized() override;
  void WasHidden(bool hidden) override;
  void NotifyScreenInfoChanged() override;
  void Invalidate(PaintElementType type) override;
  void SendExternalBeginFrame() override;
  void SendKeyEvent(const HoneycombKeyEvent& event) override;
  void SendMouseClickEvent(const HoneycombMouseEvent& event,
                           MouseButtonType type,
                           bool mouseUp,
                           int clickCount) override;
  void SendMouseMoveEvent(const HoneycombMouseEvent& event, bool mouseLeave) override;
  void SendMouseWheelEvent(const HoneycombMouseEvent& event,
                           int deltaX,
                           int deltaY) override;
  void SendTouchEvent(const HoneycombTouchEvent& event) override;
  void SendCaptureLostEvent() override;
  void NotifyMoveOrResizeStarted() override;
  int GetWindowlessFrameRate() override;
  void SetWindowlessFrameRate(int frame_rate) override;
  void ImeSetComposition(const HoneycombString& text,
                         const std::vector<HoneycombCompositionUnderline>& underlines,
                         const HoneycombRange& replacement_range,
                         const HoneycombRange& selection_range) override;
  void ImeCommitText(const HoneycombString& text,
                     const HoneycombRange& replacement_range,
                     int relative_cursor_pos) override;
  void ImeFinishComposingText(bool keep_selection) override;
  void ImeCancelComposition() override;
  void DragTargetDragEnter(HoneycombRefPtr<HoneycombDragData> drag_data,
                           const HoneycombMouseEvent& event,
                           DragOperationsMask allowed_ops) override;
  void DragTargetDragOver(const HoneycombMouseEvent& event,
                          DragOperationsMask allowed_ops) override;
  void DragTargetDragLeave() override;
  void DragTargetDrop(const HoneycombMouseEvent& event) override;
  void DragSourceEndedAt(int x, int y, DragOperationsMask op) override;
  void DragSourceSystemDragEnded() override;
  HoneycombRefPtr<HoneycombNavigationEntry> GetVisibleNavigationEntry() override;
  void SetAccessibilityState(honey_state_t accessibility_state) override;
  void SetAutoResizeEnabled(bool enabled,
                            const HoneycombSize& min_size,
                            const HoneycombSize& max_size) override;
  HoneycombRefPtr<HoneycombExtension> GetExtension() override;
  bool IsBackgroundHost() override;
  void SetAudioMuted(bool mute) override;
  bool IsAudioMuted() override;
};

#endif  // HONEYCOMB_LIBHONEY_DLL_CTOCPP_BROWSER_HOST_CTOCPP_H_