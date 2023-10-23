// Copyright (c) 2012 The Honeycomb Authors.
// Portions copyright (c) 2011 The Chromium Authors and 2016 the CEF Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEYCOMB_RENDERER_BLINK_GLUE_H_
#define HONEYCOMB_LIBHONEYCOMB_RENDERER_BLINK_GLUE_H_

#include <stdint.h>

#include <memory>
#include <string>

#include "include/internal/honey_types.h"

#include "third_party/blink/public/mojom/frame/lifecycle.mojom-blink-forward.h"
#include "third_party/blink/public/platform/web_common.h"
#include "v8/include/v8.h"

namespace blink {
class WebElement;
class WebLocalFrame;
class WebNode;
class WebString;
class WebURLRequest;
class WebURLResponse;
class WebView;
}  // namespace blink

namespace blink_glue {

BLINK_EXPORT extern const int64_t kInvalidFrameId;

BLINK_EXPORT bool CanGoBack(blink::WebView* view);
BLINK_EXPORT bool CanGoForward(blink::WebView* view);
BLINK_EXPORT void GoBack(blink::WebView* view);
BLINK_EXPORT void GoForward(blink::WebView* view);

BLINK_EXPORT bool IsInBackForwardCache(blink::WebLocalFrame* frame);

// Returns the text of the document element.
BLINK_EXPORT blink::WebString DumpDocumentText(blink::WebLocalFrame* frame);
// Returns the markup of the document element.
BLINK_EXPORT blink::WebString DumpDocumentMarkup(blink::WebLocalFrame* frame);

// Expose additional actions on WebNode.
BLINK_EXPORT honey_dom_node_type_t GetNodeType(const blink::WebNode& node);
BLINK_EXPORT blink::WebString GetNodeName(const blink::WebNode& node);
BLINK_EXPORT blink::WebString CreateNodeMarkup(const blink::WebNode& node);
BLINK_EXPORT bool SetNodeValue(blink::WebNode& node,
                               const blink::WebString& value);

BLINK_EXPORT bool IsTextControlElement(const blink::WebElement& element);

BLINK_EXPORT v8::MaybeLocal<v8::Value> CallV8Function(
    v8::Local<v8::Context> context,
    v8::Local<v8::Function> function,
    v8::Local<v8::Object> receiver,
    int argc,
    v8::Local<v8::Value> args[],
    v8::Isolate* isolate);

BLINK_EXPORT v8::Local<v8::Value> ExecuteV8ScriptAndReturnValue(
    const blink::WebString& source,
    const blink::WebString& source_url,
    int start_line,
    v8::Local<v8::Context> context,
    v8::TryCatch& tryCatch);

BLINK_EXPORT v8::MicrotaskQueue* GetMicrotaskQueue(
    v8::Local<v8::Context> context);

BLINK_EXPORT bool IsScriptForbidden();

class BLINK_EXPORT HoneycombObserverRegistration {
 public:
  HoneycombObserverRegistration() = default;

  HoneycombObserverRegistration(const HoneycombObserverRegistration&) = delete;
  HoneycombObserverRegistration& operator=(const HoneycombObserverRegistration&) = delete;

  virtual ~HoneycombObserverRegistration() = default;
};

class BLINK_EXPORT HoneycombExecutionContextLifecycleStateObserver {
 public:
  virtual void ContextLifecycleStateChanged(
      blink::mojom::blink::FrameLifecycleState state) {}

 protected:
  virtual ~HoneycombExecutionContextLifecycleStateObserver() = default;
};

// Register an ExecutionContextLifecycleStateObserver. Remains registered until
// the returned object is destroyed.
BLINK_EXPORT std::unique_ptr<HoneycombObserverRegistration>
RegisterExecutionContextLifecycleStateObserver(
    v8::Local<v8::Context> context,
    HoneycombExecutionContextLifecycleStateObserver* observer);

BLINK_EXPORT void RegisterURLSchemeAsSupportingFetchAPI(
    const blink::WebString& scheme);

// Wrapper for blink::ScriptForbiddenScope.
class BLINK_EXPORT HoneycombScriptForbiddenScope final {
 public:
  HoneycombScriptForbiddenScope();

  HoneycombScriptForbiddenScope(const HoneycombScriptForbiddenScope&) = delete;
  HoneycombScriptForbiddenScope& operator=(const HoneycombScriptForbiddenScope&) = delete;

  ~HoneycombScriptForbiddenScope();

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

BLINK_EXPORT bool ResponseWasCached(const blink::WebURLResponse& response);

// Returns true if the frame owner is a plugin.
BLINK_EXPORT bool HasPluginFrameOwner(blink::WebLocalFrame* frame);

BLINK_EXPORT void StartNavigation(blink::WebLocalFrame* frame,
                                  const blink::WebURLRequest& request);

}  // namespace blink_glue

#endif  // HONEYCOMB_LIBHONEYCOMB_RENDERER_BLINK_GLUE_H_
