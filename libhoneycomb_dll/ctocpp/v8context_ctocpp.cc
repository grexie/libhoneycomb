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
// $hash=6bdcf32699e33c7e46b8b9ac67220a6edd0bd73a$
//

#include "libhoneycomb_dll/ctocpp/v8context_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/browser_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/frame_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/task_runner_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/v8exception_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/v8value_ctocpp.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombV8Context> HoneycombV8Context::GetCurrentContext() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_v8context_t* _retval = honey_v8context_get_current_context();

  // Return type: refptr_same
  return HoneycombV8ContextCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombV8Context> HoneycombV8Context::GetEnteredContext() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_v8context_t* _retval = honey_v8context_get_entered_context();

  // Return type: refptr_same
  return HoneycombV8ContextCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") bool HoneycombV8Context::InContext() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = honey_v8context_in_context();

  // Return type: bool
  return _retval ? true : false;
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombTaskRunner> HoneycombV8ContextCToCpp::GetTaskRunner() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_task_runner)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_task_runner_t* _retval = _struct->get_task_runner(_struct);

  // Return type: refptr_same
  return HoneycombTaskRunnerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") bool HoneycombV8ContextCToCpp::IsValid() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_valid)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombBrowser> HoneycombV8ContextCToCpp::GetBrowser() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_browser)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_browser_t* _retval = _struct->get_browser(_struct);

  // Return type: refptr_same
  return HoneycombBrowserCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") HoneycombRefPtr<HoneycombFrame> HoneycombV8ContextCToCpp::GetFrame() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_frame)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_frame_t* _retval = _struct->get_frame(_struct);

  // Return type: refptr_same
  return HoneycombFrameCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") HoneycombRefPtr<HoneycombV8Value> HoneycombV8ContextCToCpp::GetGlobal() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_global)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_v8value_t* _retval = _struct->get_global(_struct);

  // Return type: refptr_same
  return HoneycombV8ValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") bool HoneycombV8ContextCToCpp::Enter() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, enter)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->enter(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool HoneycombV8ContextCToCpp::Exit() {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, exit)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->exit(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombV8ContextCToCpp::IsSame(HoneycombRefPtr<HoneycombV8Context> that) {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_same)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->is_same(_struct, HoneycombV8ContextCToCpp::Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombV8ContextCToCpp::Eval(const HoneycombString& code,
                              const HoneycombString& script_url,
                              int start_line,
                              HoneycombRefPtr<HoneycombV8Value>& retval,
                              HoneycombRefPtr<HoneycombV8Exception>& exception) {
  honey_v8context_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, eval)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: code; type: string_byref_const
  DCHECK(!code.empty());
  if (code.empty()) {
    return false;
  }
  // Unverified params: script_url

  // Translate param: retval; type: refptr_same_byref
  honey_v8value_t* retvalStruct = NULL;
  if (retval.get()) {
    retvalStruct = HoneycombV8ValueCToCpp::Unwrap(retval);
  }
  honey_v8value_t* retvalOrig = retvalStruct;
  // Translate param: exception; type: refptr_same_byref
  honey_v8exception_t* exceptionStruct = NULL;
  if (exception.get()) {
    exceptionStruct = HoneycombV8ExceptionCToCpp::Unwrap(exception);
  }
  honey_v8exception_t* exceptionOrig = exceptionStruct;

  // Execute
  int _retval = _struct->eval(_struct, code.GetStruct(), script_url.GetStruct(),
                              start_line, &retvalStruct, &exceptionStruct);

  // Restore param:retval; type: refptr_same_byref
  if (retvalStruct) {
    if (retvalStruct != retvalOrig) {
      retval = HoneycombV8ValueCToCpp::Wrap(retvalStruct);
    }
  } else {
    retval = nullptr;
  }
  // Restore param:exception; type: refptr_same_byref
  if (exceptionStruct) {
    if (exceptionStruct != exceptionOrig) {
      exception = HoneycombV8ExceptionCToCpp::Wrap(exceptionStruct);
    }
  } else {
    exception = nullptr;
  }

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombV8ContextCToCpp::HoneycombV8ContextCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombV8ContextCToCpp::~HoneycombV8ContextCToCpp() {}

template <>
honey_v8context_t*
HoneycombCToCppRefCounted<HoneycombV8ContextCToCpp, HoneycombV8Context, honey_v8context_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombV8Context* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombV8ContextCToCpp,
                                   HoneycombV8Context,
                                   honey_v8context_t>::kWrapperType =
    WT_V8CONTEXT;
