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
// $hash=6369dff04489cebf256d28015e676f2a5c09f48e$
//

#include "libhoney_dll/cpptoc/views/layout_cpptoc.h"
#include "libhoney_dll/cpptoc/views/box_layout_cpptoc.h"
#include "libhoney_dll/cpptoc/views/fill_layout_cpptoc.h"
#include "libhoney_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

honey_box_layout_t* HONEYCOMB_CALLBACK
layout_as_box_layout(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombBoxLayout> _retval = HoneycombLayoutCppToC::Get(self)->AsBoxLayout();

  // Return type: refptr_same
  return HoneycombBoxLayoutCppToC::Wrap(_retval);
}

honey_fill_layout_t* HONEYCOMB_CALLBACK
layout_as_fill_layout(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombFillLayout> _retval = HoneycombLayoutCppToC::Get(self)->AsFillLayout();

  // Return type: refptr_same
  return HoneycombFillLayoutCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK layout_is_valid(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombLayoutCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombLayoutCppToC::HoneycombLayoutCppToC() {
  GetStruct()->as_box_layout = layout_as_box_layout;
  GetStruct()->as_fill_layout = layout_as_fill_layout;
  GetStruct()->is_valid = layout_is_valid;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombLayoutCppToC::~HoneycombLayoutCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombLayout>
HoneycombCppToCRefCounted<HoneycombLayoutCppToC, HoneycombLayout, honey_layout_t>::UnwrapDerived(
    HoneycombWrapperType type,
    honey_layout_t* s) {
  if (type == WT_BOX_LAYOUT) {
    return HoneycombBoxLayoutCppToC::Unwrap(reinterpret_cast<honey_box_layout_t*>(s));
  }
  if (type == WT_FILL_LAYOUT) {
    return HoneycombFillLayoutCppToC::Unwrap(reinterpret_cast<honey_fill_layout_t*>(s));
  }
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombLayoutCppToC, HoneycombLayout, honey_layout_t>::
    kWrapperType = WT_LAYOUT;