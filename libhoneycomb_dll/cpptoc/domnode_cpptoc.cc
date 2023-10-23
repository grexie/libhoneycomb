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
// $hash=a9a7b8c8b2cb46d6bd2bb9a8883909ebbde803d7$
//

#include "libhoneycomb_dll/cpptoc/domnode_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/domdocument_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

honey_dom_node_type_t HONEYCOMB_CALLBACK domnode_get_type(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return DOM_NODE_TYPE_UNSUPPORTED;
  }

  // Execute
  honey_dom_node_type_t _retval = HoneycombDOMNodeCppToC::Get(self)->GetType();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK domnode_is_text(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->IsText();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK domnode_is_element(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->IsElement();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK domnode_is_editable(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->IsEditable();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK domnode_is_form_control_element(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->IsFormControlElement();

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_form_control_element_type(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetFormControlElementType();

  // Return type: string
  return _retval.DetachToUserFree();
}

int HONEYCOMB_CALLBACK domnode_is_same(struct _honey_domnode_t* self,
                                 struct _honey_domnode_t* that) {
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
  bool _retval =
      HoneycombDOMNodeCppToC::Get(self)->IsSame(HoneycombDOMNodeCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_name(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetName();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_value(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetValue();

  // Return type: string
  return _retval.DetachToUserFree();
}

int HONEYCOMB_CALLBACK domnode_set_value(struct _honey_domnode_t* self,
                                   const honey_string_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: value; type: string_byref_const
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->SetValue(HoneycombString(value));

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_as_markup(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetAsMarkup();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_domdocument_t* HONEYCOMB_CALLBACK
domnode_get_document(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMDocument> _retval =
      HoneycombDOMNodeCppToC::Get(self)->GetDocument();

  // Return type: refptr_same
  return HoneycombDOMDocumentCppToC::Wrap(_retval);
}

struct _honey_domnode_t* HONEYCOMB_CALLBACK
domnode_get_parent(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMNode> _retval = HoneycombDOMNodeCppToC::Get(self)->GetParent();

  // Return type: refptr_same
  return HoneycombDOMNodeCppToC::Wrap(_retval);
}

struct _honey_domnode_t* HONEYCOMB_CALLBACK
domnode_get_previous_sibling(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMNode> _retval =
      HoneycombDOMNodeCppToC::Get(self)->GetPreviousSibling();

  // Return type: refptr_same
  return HoneycombDOMNodeCppToC::Wrap(_retval);
}

struct _honey_domnode_t* HONEYCOMB_CALLBACK
domnode_get_next_sibling(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMNode> _retval = HoneycombDOMNodeCppToC::Get(self)->GetNextSibling();

  // Return type: refptr_same
  return HoneycombDOMNodeCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK domnode_has_children(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->HasChildren();

  // Return type: bool
  return _retval;
}

struct _honey_domnode_t* HONEYCOMB_CALLBACK
domnode_get_first_child(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMNode> _retval = HoneycombDOMNodeCppToC::Get(self)->GetFirstChild();

  // Return type: refptr_same
  return HoneycombDOMNodeCppToC::Wrap(_retval);
}

struct _honey_domnode_t* HONEYCOMB_CALLBACK
domnode_get_last_child(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDOMNode> _retval = HoneycombDOMNodeCppToC::Get(self)->GetLastChild();

  // Return type: refptr_same
  return HoneycombDOMNodeCppToC::Wrap(_retval);
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_element_tag_name(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetElementTagName();

  // Return type: string
  return _retval.DetachToUserFree();
}

int HONEYCOMB_CALLBACK domnode_has_element_attributes(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->HasElementAttributes();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK domnode_has_element_attribute(struct _honey_domnode_t* self,
                                               const honey_string_t* attrName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: attrName; type: string_byref_const
  DCHECK(attrName);
  if (!attrName) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombDOMNodeCppToC::Get(self)->HasElementAttribute(HoneycombString(attrName));

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_element_attribute(struct _honey_domnode_t* self,
                              const honey_string_t* attrName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: attrName; type: string_byref_const
  DCHECK(attrName);
  if (!attrName) {
    return NULL;
  }

  // Execute
  HoneycombString _retval =
      HoneycombDOMNodeCppToC::Get(self)->GetElementAttribute(HoneycombString(attrName));

  // Return type: string
  return _retval.DetachToUserFree();
}

void HONEYCOMB_CALLBACK domnode_get_element_attributes(struct _honey_domnode_t* self,
                                                 honey_string_map_t attrMap) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: attrMap; type: string_map_single_byref
  DCHECK(attrMap);
  if (!attrMap) {
    return;
  }

  // Translate param: attrMap; type: string_map_single_byref
  std::map<HoneycombString, HoneycombString> attrMapMap;
  transfer_string_map_contents(attrMap, attrMapMap);

  // Execute
  HoneycombDOMNodeCppToC::Get(self)->GetElementAttributes(attrMapMap);

  // Restore param: attrMap; type: string_map_single_byref
  honey_string_map_clear(attrMap);
  transfer_string_map_contents(attrMapMap, attrMap);
}

int HONEYCOMB_CALLBACK domnode_set_element_attribute(struct _honey_domnode_t* self,
                                               const honey_string_t* attrName,
                                               const honey_string_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: attrName; type: string_byref_const
  DCHECK(attrName);
  if (!attrName) {
    return 0;
  }
  // Verify param: value; type: string_byref_const
  DCHECK(value);
  if (!value) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDOMNodeCppToC::Get(self)->SetElementAttribute(
      HoneycombString(attrName), HoneycombString(value));

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
domnode_get_element_inner_text(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDOMNodeCppToC::Get(self)->GetElementInnerText();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_rect_t HONEYCOMB_CALLBACK
domnode_get_element_bounds(struct _honey_domnode_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombRect();
  }

  // Execute
  honey_rect_t _retval = HoneycombDOMNodeCppToC::Get(self)->GetElementBounds();

  // Return type: simple
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDOMNodeCppToC::HoneycombDOMNodeCppToC() {
  GetStruct()->get_type = domnode_get_type;
  GetStruct()->is_text = domnode_is_text;
  GetStruct()->is_element = domnode_is_element;
  GetStruct()->is_editable = domnode_is_editable;
  GetStruct()->is_form_control_element = domnode_is_form_control_element;
  GetStruct()->get_form_control_element_type =
      domnode_get_form_control_element_type;
  GetStruct()->is_same = domnode_is_same;
  GetStruct()->get_name = domnode_get_name;
  GetStruct()->get_value = domnode_get_value;
  GetStruct()->set_value = domnode_set_value;
  GetStruct()->get_as_markup = domnode_get_as_markup;
  GetStruct()->get_document = domnode_get_document;
  GetStruct()->get_parent = domnode_get_parent;
  GetStruct()->get_previous_sibling = domnode_get_previous_sibling;
  GetStruct()->get_next_sibling = domnode_get_next_sibling;
  GetStruct()->has_children = domnode_has_children;
  GetStruct()->get_first_child = domnode_get_first_child;
  GetStruct()->get_last_child = domnode_get_last_child;
  GetStruct()->get_element_tag_name = domnode_get_element_tag_name;
  GetStruct()->has_element_attributes = domnode_has_element_attributes;
  GetStruct()->has_element_attribute = domnode_has_element_attribute;
  GetStruct()->get_element_attribute = domnode_get_element_attribute;
  GetStruct()->get_element_attributes = domnode_get_element_attributes;
  GetStruct()->set_element_attribute = domnode_set_element_attribute;
  GetStruct()->get_element_inner_text = domnode_get_element_inner_text;
  GetStruct()->get_element_bounds = domnode_get_element_bounds;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDOMNodeCppToC::~HoneycombDOMNodeCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDOMNode>
HoneycombCppToCRefCounted<HoneycombDOMNodeCppToC, HoneycombDOMNode, honey_domnode_t>::UnwrapDerived(
    HoneycombWrapperType type,
    honey_domnode_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombDOMNodeCppToC,
                                   HoneycombDOMNode,
                                   honey_domnode_t>::kWrapperType = WT_DOMNODE;
