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
// $hash=7f625b08e4c82a608dd7178b571f80fce5fe0d70$
//

#include "libhoneycomb_dll/cpptoc/resource_bundle_handler_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK resource_bundle_handler_get_localized_string(
    struct _honey_resource_bundle_handler_t* self,
    int string_id,
    honey_string_t* string) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: string; type: string_byref
  DCHECK(string);
  if (!string) {
    return 0;
  }

  // Translate param: string; type: string_byref
  HoneycombString stringStr(string);

  // Execute
  bool _retval = HoneycombResourceBundleHandlerCppToC::Get(self)->GetLocalizedString(
      string_id, stringStr);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK resource_bundle_handler_get_data_resource(
    struct _honey_resource_bundle_handler_t* self,
    int resource_id,
    void** data,
    size_t* data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: data; type: simple_byref
  DCHECK(data);
  if (!data) {
    return 0;
  }
  // Verify param: data_size; type: simple_byref
  DCHECK(data_size);
  if (!data_size) {
    return 0;
  }

  // Translate param: data; type: simple_byref
  void* dataVal = data ? *data : NULL;
  // Translate param: data_size; type: simple_byref
  size_t data_sizeVal = data_size ? *data_size : 0;

  // Execute
  bool _retval = HoneycombResourceBundleHandlerCppToC::Get(self)->GetDataResource(
      resource_id, dataVal, data_sizeVal);

  // Restore param: data; type: simple_byref
  if (data) {
    *data = dataVal;
  }
  // Restore param: data_size; type: simple_byref
  if (data_size) {
    *data_size = data_sizeVal;
  }

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK resource_bundle_handler_get_data_resource_for_scale(
    struct _honey_resource_bundle_handler_t* self,
    int resource_id,
    honey_scale_factor_t scale_factor,
    void** data,
    size_t* data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: data; type: simple_byref
  DCHECK(data);
  if (!data) {
    return 0;
  }
  // Verify param: data_size; type: simple_byref
  DCHECK(data_size);
  if (!data_size) {
    return 0;
  }

  // Translate param: data; type: simple_byref
  void* dataVal = data ? *data : NULL;
  // Translate param: data_size; type: simple_byref
  size_t data_sizeVal = data_size ? *data_size : 0;

  // Execute
  bool _retval =
      HoneycombResourceBundleHandlerCppToC::Get(self)->GetDataResourceForScale(
          resource_id, scale_factor, dataVal, data_sizeVal);

  // Restore param: data; type: simple_byref
  if (data) {
    *data = dataVal;
  }
  // Restore param: data_size; type: simple_byref
  if (data_size) {
    *data_size = data_sizeVal;
  }

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombResourceBundleHandlerCppToC::HoneycombResourceBundleHandlerCppToC() {
  GetStruct()->get_localized_string =
      resource_bundle_handler_get_localized_string;
  GetStruct()->get_data_resource = resource_bundle_handler_get_data_resource;
  GetStruct()->get_data_resource_for_scale =
      resource_bundle_handler_get_data_resource_for_scale;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombResourceBundleHandlerCppToC::~HoneycombResourceBundleHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombResourceBundleHandler> HoneycombCppToCRefCounted<
    HoneycombResourceBundleHandlerCppToC,
    HoneycombResourceBundleHandler,
    honey_resource_bundle_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                                  honey_resource_bundle_handler_t*
                                                      s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCppToCRefCounted<HoneycombResourceBundleHandlerCppToC,
                        HoneycombResourceBundleHandler,
                        honey_resource_bundle_handler_t>::kWrapperType =
        WT_RESOURCE_BUNDLE_HANDLER;
