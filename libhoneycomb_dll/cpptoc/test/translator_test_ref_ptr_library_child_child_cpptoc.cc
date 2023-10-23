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
// $hash=09d1f7c2030dd94ea04b11428eaa2820365c39b0$
//

#include "libhoneycomb_dll/cpptoc/test/translator_test_ref_ptr_library_child_child_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_translator_test_ref_ptr_library_child_child_t*
honey_translator_test_ref_ptr_library_child_child_create(int value,
                                                       int other_value,
                                                       int other_other_value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  HoneycombRefPtr<HoneycombTranslatorTestRefPtrLibraryChildChild> _retval =
      HoneycombTranslatorTestRefPtrLibraryChildChild::Create(value, other_value,
                                                       other_other_value);

  // Return type: refptr_same
  return HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
translator_test_ref_ptr_library_child_child_get_other_other_value(
    struct _honey_translator_test_ref_ptr_library_child_child_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval = HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(self)
                    ->GetOtherOtherValue();

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK
translator_test_ref_ptr_library_child_child_set_other_other_value(
    struct _honey_translator_test_ref_ptr_library_child_child_t* self,
    int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(self)->SetOtherOtherValue(
      value);
}

int HONEYCOMB_CALLBACK translator_test_ref_ptr_library_child_child_get_other_value(
    struct _honey_translator_test_ref_ptr_library_child_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(
          reinterpret_cast<honey_translator_test_ref_ptr_library_child_child_t*>(
              self))
          ->GetOtherValue();

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK translator_test_ref_ptr_library_child_child_set_other_value(
    struct _honey_translator_test_ref_ptr_library_child_t* self,
    int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(
      reinterpret_cast<honey_translator_test_ref_ptr_library_child_child_t*>(
          self))
      ->SetOtherValue(value);
}

int HONEYCOMB_CALLBACK translator_test_ref_ptr_library_child_child_get_value(
    struct _honey_translator_test_ref_ptr_library_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(
          reinterpret_cast<honey_translator_test_ref_ptr_library_child_child_t*>(
              self))
          ->GetValue();

  // Return type: simple
  return _retval;
}

void HONEYCOMB_CALLBACK translator_test_ref_ptr_library_child_child_set_value(
    struct _honey_translator_test_ref_ptr_library_t* self,
    int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::Get(
      reinterpret_cast<honey_translator_test_ref_ptr_library_child_child_t*>(
          self))
      ->SetValue(value);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::
    HoneycombTranslatorTestRefPtrLibraryChildChildCppToC() {
  GetStruct()->get_other_other_value =
      translator_test_ref_ptr_library_child_child_get_other_other_value;
  GetStruct()->set_other_other_value =
      translator_test_ref_ptr_library_child_child_set_other_other_value;
  GetStruct()->base.get_other_value =
      translator_test_ref_ptr_library_child_child_get_other_value;
  GetStruct()->base.set_other_value =
      translator_test_ref_ptr_library_child_child_set_other_value;
  GetStruct()->base.base.get_value =
      translator_test_ref_ptr_library_child_child_get_value;
  GetStruct()->base.base.set_value =
      translator_test_ref_ptr_library_child_child_set_value;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestRefPtrLibraryChildChildCppToC::
    ~HoneycombTranslatorTestRefPtrLibraryChildChildCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombTranslatorTestRefPtrLibraryChildChild>
HoneycombCppToCRefCounted<HoneycombTranslatorTestRefPtrLibraryChildChildCppToC,
                    HoneycombTranslatorTestRefPtrLibraryChildChild,
                    honey_translator_test_ref_ptr_library_child_child_t>::
    UnwrapDerived(HoneycombWrapperType type,
                  honey_translator_test_ref_ptr_library_child_child_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<
    HoneycombTranslatorTestRefPtrLibraryChildChildCppToC,
    HoneycombTranslatorTestRefPtrLibraryChildChild,
    honey_translator_test_ref_ptr_library_child_child_t>::kWrapperType =
    WT_TRANSLATOR_TEST_REF_PTR_LIBRARY_CHILD_CHILD;
