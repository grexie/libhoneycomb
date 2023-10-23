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
// $hash=0ce373fa99a3d48d9a512355dfc4d3c26aa18f87$
//

#include "libhoneycomb_dll/ctocpp/test/translator_test_scoped_client_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/test/translator_test_scoped_client_child_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") int HoneycombTranslatorTestScopedClientCToCpp::GetValue() {
  honey_translator_test_scoped_client_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_value)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value(_struct);

  // Return type: simple
  return _retval;
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestScopedClientCToCpp::HoneycombTranslatorTestScopedClientCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombTranslatorTestScopedClientCToCpp::~HoneycombTranslatorTestScopedClientCToCpp() {}

template <>
honey_translator_test_scoped_client_t*
HoneycombCToCppScoped<HoneycombTranslatorTestScopedClientCToCpp,
                HoneycombTranslatorTestScopedClient,
                honey_translator_test_scoped_client_t>::
    UnwrapDerivedOwn(HoneycombWrapperType type,
                     HoneycombOwnPtr<HoneycombTranslatorTestScopedClient> c) {
  if (type == WT_TRANSLATOR_TEST_SCOPED_CLIENT_CHILD) {
    return reinterpret_cast<honey_translator_test_scoped_client_t*>(
        HoneycombTranslatorTestScopedClientChildCToCpp::UnwrapOwn(
            HoneycombOwnPtr<HoneycombTranslatorTestScopedClientChild>(
                reinterpret_cast<HoneycombTranslatorTestScopedClientChild*>(
                    c.release()))));
  }
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
honey_translator_test_scoped_client_t*
HoneycombCToCppScoped<HoneycombTranslatorTestScopedClientCToCpp,
                HoneycombTranslatorTestScopedClient,
                honey_translator_test_scoped_client_t>::
    UnwrapDerivedRaw(HoneycombWrapperType type,
                     HoneycombRawPtr<HoneycombTranslatorTestScopedClient> c) {
  if (type == WT_TRANSLATOR_TEST_SCOPED_CLIENT_CHILD) {
    return reinterpret_cast<honey_translator_test_scoped_client_t*>(
        HoneycombTranslatorTestScopedClientChildCToCpp::UnwrapRaw(
            HoneycombRawPtr<HoneycombTranslatorTestScopedClientChild>(
                reinterpret_cast<HoneycombTranslatorTestScopedClientChild*>(c))));
  }
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCToCppScoped<HoneycombTranslatorTestScopedClientCToCpp,
                    HoneycombTranslatorTestScopedClient,
                    honey_translator_test_scoped_client_t>::kWrapperType =
        WT_TRANSLATOR_TEST_SCOPED_CLIENT;
