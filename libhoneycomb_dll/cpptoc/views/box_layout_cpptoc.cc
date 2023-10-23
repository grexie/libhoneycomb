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
// $hash=909f89cc8243a1438a31bc2d5e0957c18b65a9b0$
//

#include "libhoneycomb_dll/cpptoc/views/box_layout_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/views/fill_layout_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/views/view_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void HONEYCOMB_CALLBACK box_layout_set_flex_for_view(struct _honey_box_layout_t* self,
                                               struct _honey_view_t* view,
                                               int flex) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view) {
    return;
  }

  // Execute
  HoneycombBoxLayoutCppToC::Get(self)->SetFlexForView(HoneycombViewCppToC::Unwrap(view),
                                                flex);
}

void HONEYCOMB_CALLBACK box_layout_clear_flex_for_view(struct _honey_box_layout_t* self,
                                                 struct _honey_view_t* view) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view) {
    return;
  }

  // Execute
  HoneycombBoxLayoutCppToC::Get(self)->ClearFlexForView(HoneycombViewCppToC::Unwrap(view));
}

honey_box_layout_t* HONEYCOMB_CALLBACK
box_layout_as_box_layout(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombBoxLayout> _retval =
      HoneycombBoxLayoutCppToC::Get(reinterpret_cast<honey_box_layout_t*>(self))
          ->AsBoxLayout();

  // Return type: refptr_same
  return HoneycombBoxLayoutCppToC::Wrap(_retval);
}

honey_fill_layout_t* HONEYCOMB_CALLBACK
box_layout_as_fill_layout(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombFillLayout> _retval =
      HoneycombBoxLayoutCppToC::Get(reinterpret_cast<honey_box_layout_t*>(self))
          ->AsFillLayout();

  // Return type: refptr_same
  return HoneycombFillLayoutCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK box_layout_is_valid(struct _honey_layout_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombBoxLayoutCppToC::Get(reinterpret_cast<honey_box_layout_t*>(self))
          ->IsValid();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombBoxLayoutCppToC::HoneycombBoxLayoutCppToC() {
  GetStruct()->set_flex_for_view = box_layout_set_flex_for_view;
  GetStruct()->clear_flex_for_view = box_layout_clear_flex_for_view;
  GetStruct()->base.as_box_layout = box_layout_as_box_layout;
  GetStruct()->base.as_fill_layout = box_layout_as_fill_layout;
  GetStruct()->base.is_valid = box_layout_is_valid;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombBoxLayoutCppToC::~HoneycombBoxLayoutCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombBoxLayout>
HoneycombCppToCRefCounted<HoneycombBoxLayoutCppToC, HoneycombBoxLayout, honey_box_layout_t>::
    UnwrapDerived(HoneycombWrapperType type, honey_box_layout_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombBoxLayoutCppToC,
                                   HoneycombBoxLayout,
                                   honey_box_layout_t>::kWrapperType =
    WT_BOX_LAYOUT;
