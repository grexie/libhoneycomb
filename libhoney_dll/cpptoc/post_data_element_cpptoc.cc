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
// $hash=28878433f4b543be6353184d8f930099ea0c9f41$
//

#include "libhoney_dll/cpptoc/post_data_element_cpptoc.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_post_data_element_t* honey_post_data_element_create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  HoneycombRefPtr<HoneycombPostDataElement> _retval = HoneycombPostDataElement::Create();

  // Return type: refptr_same
  return HoneycombPostDataElementCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
post_data_element_is_read_only(struct _honey_post_data_element_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombPostDataElementCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK
post_data_element_set_to_empty(struct _honey_post_data_element_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombPostDataElementCppToC::Get(self)->SetToEmpty();
}

void HONEYCOMB_CALLBACK
post_data_element_set_to_file(struct _honey_post_data_element_t* self,
                              const honey_string_t* fileName) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: fileName; type: string_byref_const
  DCHECK(fileName);
  if (!fileName) {
    return;
  }

  // Execute
  HoneycombPostDataElementCppToC::Get(self)->SetToFile(HoneycombString(fileName));
}

void HONEYCOMB_CALLBACK
post_data_element_set_to_bytes(struct _honey_post_data_element_t* self,
                               size_t size,
                               const void* bytes) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: bytes; type: simple_byaddr
  DCHECK(bytes);
  if (!bytes) {
    return;
  }

  // Execute
  HoneycombPostDataElementCppToC::Get(self)->SetToBytes(size, bytes);
}

honey_postdataelement_type_t HONEYCOMB_CALLBACK
post_data_element_get_type(struct _honey_post_data_element_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return PDE_TYPE_EMPTY;
  }

  // Execute
  honey_postdataelement_type_t _retval =
      HoneycombPostDataElementCppToC::Get(self)->GetType();

  // Return type: simple
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
post_data_element_get_file(struct _honey_post_data_element_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombPostDataElementCppToC::Get(self)->GetFile();

  // Return type: string
  return _retval.DetachToUserFree();
}

size_t HONEYCOMB_CALLBACK
post_data_element_get_bytes_count(struct _honey_post_data_element_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombPostDataElementCppToC::Get(self)->GetBytesCount();

  // Return type: simple
  return _retval;
}

size_t HONEYCOMB_CALLBACK
post_data_element_get_bytes(struct _honey_post_data_element_t* self,
                            size_t size,
                            void* bytes) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: bytes; type: simple_byaddr
  DCHECK(bytes);
  if (!bytes) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombPostDataElementCppToC::Get(self)->GetBytes(size, bytes);

  // Return type: simple
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombPostDataElementCppToC::HoneycombPostDataElementCppToC() {
  GetStruct()->is_read_only = post_data_element_is_read_only;
  GetStruct()->set_to_empty = post_data_element_set_to_empty;
  GetStruct()->set_to_file = post_data_element_set_to_file;
  GetStruct()->set_to_bytes = post_data_element_set_to_bytes;
  GetStruct()->get_type = post_data_element_get_type;
  GetStruct()->get_file = post_data_element_get_file;
  GetStruct()->get_bytes_count = post_data_element_get_bytes_count;
  GetStruct()->get_bytes = post_data_element_get_bytes;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombPostDataElementCppToC::~HoneycombPostDataElementCppToC() {}

template <>
HoneycombRefPtr<HoneycombPostDataElement> HoneycombCppToCRefCounted<
    HoneycombPostDataElementCppToC,
    HoneycombPostDataElement,
    honey_post_data_element_t>::UnwrapDerived(HoneycombWrapperType type,
                                            honey_post_data_element_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombPostDataElementCppToC,
                                   HoneycombPostDataElement,
                                   honey_post_data_element_t>::kWrapperType =
    WT_POST_DATA_ELEMENT;