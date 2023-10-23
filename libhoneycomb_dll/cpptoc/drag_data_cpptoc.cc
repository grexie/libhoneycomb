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
// $hash=14322f994bd6eb8732honey20a3a70fc8ebbf32dea$
//

#include "libhoneycomb_dll/cpptoc/drag_data_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/image_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/stream_writer_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"
#include "libhoneycomb_dll/transfer_util.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_drag_data_t* honey_drag_data_create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  HoneycombRefPtr<HoneycombDragData> _retval = HoneycombDragData::Create();

  // Return type: refptr_same
  return HoneycombDragDataCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

struct _honey_drag_data_t* HONEYCOMB_CALLBACK
drag_data_clone(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombDragData> _retval = HoneycombDragDataCppToC::Get(self)->Clone();

  // Return type: refptr_same
  return HoneycombDragDataCppToC::Wrap(_retval);
}

int HONEYCOMB_CALLBACK drag_data_is_read_only(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK drag_data_is_link(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->IsLink();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK drag_data_is_fragment(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->IsFragment();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK drag_data_is_file(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->IsFile();

  // Return type: bool
  return _retval;
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_link_url(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetLinkURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_link_title(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetLinkTitle();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_link_metadata(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetLinkMetadata();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_fragment_text(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetFragmentText();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_fragment_html(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetFragmentHtml();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_fragment_base_url(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetFragmentBaseURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

honey_string_userfree_t HONEYCOMB_CALLBACK
drag_data_get_file_name(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombString _retval = HoneycombDragDataCppToC::Get(self)->GetFileName();

  // Return type: string
  return _retval.DetachToUserFree();
}

size_t HONEYCOMB_CALLBACK
drag_data_get_file_contents(struct _honey_drag_data_t* self,
                            struct _honey_stream_writer_t* writer) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Unverified params: writer

  // Execute
  size_t _retval = HoneycombDragDataCppToC::Get(self)->GetFileContents(
      HoneycombStreamWriterCppToC::Unwrap(writer));

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK drag_data_get_file_names(struct _honey_drag_data_t* self,
                                          honey_string_list_t names) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: names; type: string_vec_byref
  DCHECK(names);
  if (!names) {
    return 0;
  }

  // Translate param: names; type: string_vec_byref
  std::vector<HoneycombString> namesList;
  transfer_string_list_contents(names, namesList);

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->GetFileNames(namesList);

  // Restore param: names; type: string_vec_byref
  honey_string_list_clear(names);
  transfer_string_list_contents(namesList, names);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK
drag_data_get_file_paths(struct _honey_drag_data_t* self,
                         honey_string_list_t paths) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: paths; type: string_vec_byref
  DCHECK(paths);
  if (!paths) {
    return 0;
  }

  // Translate param: paths; type: string_vec_byref
  std::vector<HoneycombString> pathsList;
  transfer_string_list_contents(paths, pathsList);

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->GetFilePaths(pathsList);

  // Restore param: paths; type: string_vec_byref
  honey_string_list_clear(paths);
  transfer_string_list_contents(pathsList, paths);

  // Return type: bool
  return _retval;
}

void HONEYCOMB_CALLBACK drag_data_set_link_url(struct _honey_drag_data_t* self,
                                         const honey_string_t* url) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: url

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetLinkURL(HoneycombString(url));
}

void HONEYCOMB_CALLBACK drag_data_set_link_title(struct _honey_drag_data_t* self,
                                           const honey_string_t* title) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: title

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetLinkTitle(HoneycombString(title));
}

void HONEYCOMB_CALLBACK drag_data_set_link_metadata(struct _honey_drag_data_t* self,
                                              const honey_string_t* data) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: data

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetLinkMetadata(HoneycombString(data));
}

void HONEYCOMB_CALLBACK drag_data_set_fragment_text(struct _honey_drag_data_t* self,
                                              const honey_string_t* text) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: text

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetFragmentText(HoneycombString(text));
}

void HONEYCOMB_CALLBACK drag_data_set_fragment_html(struct _honey_drag_data_t* self,
                                              const honey_string_t* html) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: html

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetFragmentHtml(HoneycombString(html));
}

void HONEYCOMB_CALLBACK
drag_data_set_fragment_base_url(struct _honey_drag_data_t* self,
                                const honey_string_t* base_url) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: base_url

  // Execute
  HoneycombDragDataCppToC::Get(self)->SetFragmentBaseURL(HoneycombString(base_url));
}

void HONEYCOMB_CALLBACK drag_data_reset_file_contents(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombDragDataCppToC::Get(self)->ResetFileContents();
}

void HONEYCOMB_CALLBACK drag_data_add_file(struct _honey_drag_data_t* self,
                                     const honey_string_t* path,
                                     const honey_string_t* display_name) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: path; type: string_byref_const
  DCHECK(path);
  if (!path) {
    return;
  }
  // Unverified params: display_name

  // Execute
  HoneycombDragDataCppToC::Get(self)->AddFile(HoneycombString(path),
                                        HoneycombString(display_name));
}

void HONEYCOMB_CALLBACK drag_data_clear_filenames(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  HoneycombDragDataCppToC::Get(self)->ClearFilenames();
}

struct _honey_image_t* HONEYCOMB_CALLBACK
drag_data_get_image(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombImage> _retval = HoneycombDragDataCppToC::Get(self)->GetImage();

  // Return type: refptr_same
  return HoneycombImageCppToC::Wrap(_retval);
}

honey_point_t HONEYCOMB_CALLBACK
drag_data_get_image_hotspot(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return HoneycombPoint();
  }

  // Execute
  honey_point_t _retval = HoneycombDragDataCppToC::Get(self)->GetImageHotspot();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK drag_data_has_image(struct _honey_drag_data_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombDragDataCppToC::Get(self)->HasImage();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombDragDataCppToC::HoneycombDragDataCppToC() {
  GetStruct()->clone = drag_data_clone;
  GetStruct()->is_read_only = drag_data_is_read_only;
  GetStruct()->is_link = drag_data_is_link;
  GetStruct()->is_fragment = drag_data_is_fragment;
  GetStruct()->is_file = drag_data_is_file;
  GetStruct()->get_link_url = drag_data_get_link_url;
  GetStruct()->get_link_title = drag_data_get_link_title;
  GetStruct()->get_link_metadata = drag_data_get_link_metadata;
  GetStruct()->get_fragment_text = drag_data_get_fragment_text;
  GetStruct()->get_fragment_html = drag_data_get_fragment_html;
  GetStruct()->get_fragment_base_url = drag_data_get_fragment_base_url;
  GetStruct()->get_file_name = drag_data_get_file_name;
  GetStruct()->get_file_contents = drag_data_get_file_contents;
  GetStruct()->get_file_names = drag_data_get_file_names;
  GetStruct()->get_file_paths = drag_data_get_file_paths;
  GetStruct()->set_link_url = drag_data_set_link_url;
  GetStruct()->set_link_title = drag_data_set_link_title;
  GetStruct()->set_link_metadata = drag_data_set_link_metadata;
  GetStruct()->set_fragment_text = drag_data_set_fragment_text;
  GetStruct()->set_fragment_html = drag_data_set_fragment_html;
  GetStruct()->set_fragment_base_url = drag_data_set_fragment_base_url;
  GetStruct()->reset_file_contents = drag_data_reset_file_contents;
  GetStruct()->add_file = drag_data_add_file;
  GetStruct()->clear_filenames = drag_data_clear_filenames;
  GetStruct()->get_image = drag_data_get_image;
  GetStruct()->get_image_hotspot = drag_data_get_image_hotspot;
  GetStruct()->has_image = drag_data_has_image;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombDragDataCppToC::~HoneycombDragDataCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombDragData>
HoneycombCppToCRefCounted<HoneycombDragDataCppToC, HoneycombDragData, honey_drag_data_t>::
    UnwrapDerived(HoneycombWrapperType type, honey_drag_data_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombDragDataCppToC,
                                   HoneycombDragData,
                                   honey_drag_data_t>::kWrapperType =
    WT_DRAG_DATA;
