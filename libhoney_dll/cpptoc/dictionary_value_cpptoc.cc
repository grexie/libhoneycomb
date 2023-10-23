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
// $hash=ed7d4723843c212ea634d3d9fe3121591de1c71d$
//

#include "libhoney_dll/cpptoc/dictionary_value_cpptoc.h"
#include "libhoney_dll/cpptoc/binary_value_cpptoc.h"
#include "libhoney_dll/cpptoc/list_value_cpptoc.h"
#include "libhoney_dll/cpptoc/value_cpptoc.h"
#include "libhoney_dll/shutdown_checker.h"
#include "libhoney_dll/transfer_util.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_dictionary_value_t* honey_dictionary_value_create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  HoneycombRefPtr<HoneycombDictionaryValue> _retval = HoneycombDictionaryValue::Create();

  // Return type: refptr_same
  return HoneycombDictionaryValueCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK
dictionary_value_is_valid(struct _honey_dictionary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_is_owned(struct _honey_dictionary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->IsOwned();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_is_read_only(struct _honey_dictionary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_is_same(struct _honey_dictionary_value_t* self,
                         struct _honey_dictionary_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->IsSame(
      HoneycombDictionaryValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_is_equal(struct _honey_dictionary_value_t* self,
                          struct _honey_dictionary_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->IsEqual(
      HoneycombDictionaryValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _honey_dictionary_value_t* HONEYCOMB_CALLBACK
dictionary_value_copy(struct _honey_dictionary_value_t* self,
                      int exclude_empty_children) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDictionaryValue> _retval =
      HoneycombDictionaryValueCppToC::Get(self)->Copy(exclude_empty_children ? true
                                                                       : false);

  // Return type: refptr_same
  return HoneycombDictionaryValueCppToC::Wrap(_retval);
}

size_t HONEYCOMB_CALLBACK
dictionary_value_get_size(struct _honey_dictionary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombDictionaryValueCppToC::Get(self)->GetSize();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_clear(struct _honey_dictionary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->Clear();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_has_key(struct _honey_dictionary_value_t* self,
                                          const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->HasKey(HoneycombString(key));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_get_keys(struct _honey_dictionary_value_t* self,
                                           honey_string_list_t keys) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: keys; type: string_vec_byref
  DCHECK(keys);
  if (!keys) {
    return 0;
  }

  // Translate param: keys; type: string_vec_byref
  std::vector<HoneycombString> keysList;
  transfer_string_list_contents(keys, keysList);

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->GetKeys(keysList);

  // Restore param: keys; type: string_vec_byref
  honey_string_list_clear(keys);
  transfer_string_list_contents(keysList, keys);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_remove(struct _honey_dictionary_value_t* self,
                                         const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->Remove(HoneycombString(key));

  // Return type: bool
  return _retval;
}

honey_value_type_t HONEYCOMB_CALLBACK
dictionary_value_get_type(struct _honey_dictionary_value_t* self,
                          const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return VTYPE_INVALID;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return VTYPE_INVALID;
  }

  // Execute
  honey_value_type_t _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetType(HoneycombString(key));

  // Return type: simple
  return _retval;
}

honey_value_t* HONEYCOMB_CALLBACK
dictionary_value_get_value(struct _honey_dictionary_value_t* self,
                           const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombValue> _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetValue(HoneycombString(key));

  // Return type: refptr_same
  return HoneycombValueCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK dictionary_value_get_bool(struct _honey_dictionary_value_t* self,
                                           const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->GetBool(HoneycombString(key));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_get_int(struct _honey_dictionary_value_t* self,
                                          const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  int _retval = HoneycombDictionaryValueCppToC::Get(self)->GetInt(HoneycombString(key));

  // Return type: simple
  return _retval;
}

double HONEYCOMB_CALLBACK
dictionary_value_get_double(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  double _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetDouble(HoneycombString(key));

  // Return type: simple
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
dictionary_value_get_string(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return NULL;
  }

  // Execute
  HoneycombString _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetString(HoneycombString(key));

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_binary_value_t* HONEYCOMB_CALLBACK
dictionary_value_get_binary(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombBinaryValue> _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetBinary(HoneycombString(key));

  // Return type: refptr_same
  return HoneycombBinaryValueCppToC::Wrap(_retval);
}

struct _honey_dictionary_value_t* HONEYCOMB_CALLBACK
dictionary_value_get_dictionary(struct _honey_dictionary_value_t* self,
                                const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDictionaryValue> _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetDictionary(HoneycombString(key));

  // Return type: refptr_same
  return HoneycombDictionaryValueCppToC::Wrap(_retval);
}

struct _honey_list_value_t* HONEYCOMB_CALLBACK
dictionary_value_get_list(struct _honey_dictionary_value_t* self,
                          const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombListValue> _retval =
      HoneycombDictionaryValueCppToC::Get(self)->GetList(HoneycombString(key));

  // Return type: refptr_same
  return HoneycombListValueCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK
dictionary_value_set_value(struct _honey_dictionary_value_t* self,
                           const honey_string_t* key,
                           honey_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetValue(
      HoneycombString(key), HoneycombValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_set_null(struct _honey_dictionary_value_t* self,
                                           const honey_string_t* key) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetNull(HoneycombString(key));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_set_bool(struct _honey_dictionary_value_t* self,
                                           const honey_string_t* key,
                                           int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetBool(
      HoneycombString(key), value ? true : false);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_set_int(struct _honey_dictionary_value_t* self,
                                          const honey_string_t* key,
                                          int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombDictionaryValueCppToC::Get(self)->SetInt(HoneycombString(key), value);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_set_double(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key,
                            double value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombDictionaryValueCppToC::Get(self)->SetDouble(HoneycombString(key), value);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_set_string(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key,
                            const honey_string_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }
  // Unverified params: value

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetString(
      HoneycombString(key), HoneycombString(value));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_set_binary(struct _honey_dictionary_value_t* self,
                            const honey_string_t* key,
                            honey_binary_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetBinary(
      HoneycombString(key), HoneycombBinaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
dictionary_value_set_dictionary(struct _honey_dictionary_value_t* self,
                                const honey_string_t* key,
                                struct _honey_dictionary_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetDictionary(
      HoneycombString(key), HoneycombDictionaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK dictionary_value_set_list(struct _honey_dictionary_value_t* self,
                                           const honey_string_t* key,
                                           struct _honey_list_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key) {
    return 0;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDictionaryValueCppToC::Get(self)->SetList(
      HoneycombString(key), HoneycombListValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDictionaryValueCppToC::HoneycombDictionaryValueCppToC() {
  GetStruct()->is_valid = dictionary_value_is_valid;
  GetStruct()->is_owned = dictionary_value_is_owned;
  GetStruct()->is_read_only = dictionary_value_is_read_only;
  GetStruct()->is_same = dictionary_value_is_same;
  GetStruct()->is_equal = dictionary_value_is_equal;
  GetStruct()->copy = dictionary_value_copy;
  GetStruct()->get_size = dictionary_value_get_size;
  GetStruct()->clear = dictionary_value_clear;
  GetStruct()->has_key = dictionary_value_has_key;
  GetStruct()->get_keys = dictionary_value_get_keys;
  GetStruct()->remove = dictionary_value_remove;
  GetStruct()->get_type = dictionary_value_get_type;
  GetStruct()->get_value = dictionary_value_get_value;
  GetStruct()->get_bool = dictionary_value_get_bool;
  GetStruct()->get_int = dictionary_value_get_int;
  GetStruct()->get_double = dictionary_value_get_double;
  GetStruct()->get_string = dictionary_value_get_string;
  GetStruct()->get_binary = dictionary_value_get_binary;
  GetStruct()->get_dictionary = dictionary_value_get_dictionary;
  GetStruct()->get_list = dictionary_value_get_list;
  GetStruct()->set_value = dictionary_value_set_value;
  GetStruct()->set_null = dictionary_value_set_null;
  GetStruct()->set_bool = dictionary_value_set_bool;
  GetStruct()->set_int = dictionary_value_set_int;
  GetStruct()->set_double = dictionary_value_set_double;
  GetStruct()->set_string = dictionary_value_set_string;
  GetStruct()->set_binary = dictionary_value_set_binary;
  GetStruct()->set_dictionary = dictionary_value_set_dictionary;
  GetStruct()->set_list = dictionary_value_set_list;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDictionaryValueCppToC::~HoneycombDictionaryValueCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDictionaryValue> HoneycombCppToCRefCounted<
    HoneycombDictionaryValueCppToC,
    HoneycombDictionaryValue,
    honey_dictionary_value_t>::UnwrapDerived(HoneycombWrapperType type,
                                           honey_dictionary_value_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombDictionaryValueCppToC,
                                   HoneycombDictionaryValue,
                                   honey_dictionary_value_t>::kWrapperType =
    WT_DICTIONARY_VALUE;