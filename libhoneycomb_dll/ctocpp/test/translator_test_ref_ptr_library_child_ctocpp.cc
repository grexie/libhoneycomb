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
// $hash=cd059e94feaa5f002332fcb6fac40fcd1cb14dca$
//

#include "libhoneycomb_dll/ctocpp/test/translator_test_ref_ptr_library_child_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/test/translator_test_ref_ptr_library_child_child_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombTranslatorTestRefPtrLibraryChild>
HoneycombTranslatorTestRefPtrLibraryChild::Create(int value, int other_value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_translator_test_ref_ptr_library_child_t* _retval =
      honey_translator_test_ref_ptr_library_child_create(value, other_value);

  // Return type: refptr_same
  return HoneycombTranslatorTestRefPtrLibraryChildCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
int HoneycombTranslatorTestRefPtrLibraryChildCToCpp::GetOtherValue() {
  shutdown_checker::AssertNotShutdown();

  honey_translator_test_ref_ptr_library_child_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_other_value)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_other_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void HoneycombTranslatorTestRefPtrLibraryChildCToCpp::SetOtherValue(int value) {
  shutdown_checker::AssertNotShutdown();

  honey_translator_test_ref_ptr_library_child_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_other_value)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int HoneycombTranslatorTestRefPtrLibraryChildCToCpp::GetValue() {
  shutdown_checker::AssertNotShutdown();

  honey_translator_test_ref_ptr_library_t* _struct =
      reinterpret_cast<honey_translator_test_ref_ptr_library_t*>(GetStruct());
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_value)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void HoneycombTranslatorTestRefPtrLibraryChildCToCpp::SetValue(int value) {
  shutdown_checker::AssertNotShutdown();

  honey_translator_test_ref_ptr_library_t* _struct =
      reinterpret_cast<honey_translator_test_ref_ptr_library_t*>(GetStruct());
  if (HONEYCOMB_MEMBER_MISSING(_struct, set_value)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value(_struct, value);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestRefPtrLibraryChildCToCpp::
    HoneycombTranslatorTestRefPtrLibraryChildCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestRefPtrLibraryChildCToCpp::
    ~HoneycombTranslatorTestRefPtrLibraryChildCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_translator_test_ref_ptr_library_child_t*
HoneycombCToCppRefCounted<HoneycombTranslatorTestRefPtrLibraryChildCToCpp,
                    HoneycombTranslatorTestRefPtrLibraryChild,
                    honey_translator_test_ref_ptr_library_child_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombTranslatorTestRefPtrLibraryChild* c) {
  if (type == WT_TRANSLATOR_TEST_REF_PTR_LIBRARY_CHILD_CHILD) {
    return reinterpret_cast<honey_translator_test_ref_ptr_library_child_t*>(
        HoneycombTranslatorTestRefPtrLibraryChildChildCToCpp::Unwrap(
            reinterpret_cast<HoneycombTranslatorTestRefPtrLibraryChildChild*>(c)));
  }
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<
    HoneycombTranslatorTestRefPtrLibraryChildCToCpp,
    HoneycombTranslatorTestRefPtrLibraryChild,
    honey_translator_test_ref_ptr_library_child_t>::kWrapperType =
    WT_TRANSLATOR_TEST_REF_PTR_LIBRARY_CHILD;
