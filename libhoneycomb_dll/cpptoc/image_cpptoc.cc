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
// $hash=beb7882398ddea540b847e5c9fb44ed19f91f125$
//

#include "libhoneycomb_dll/cpptoc/image_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/binary_value_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

HONEYCOMB_EXPORT honey_image_t* honey_image_create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  HoneycombRefPtr<HoneycombImage> _retval = HoneycombImage::CreateImage();

  // Return type: refptr_same
  return HoneycombImageCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK image_is_empty(struct _honey_image_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->IsEmpty();

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_is_same(struct _honey_image_t* self,
                               struct _honey_image_t* that) {
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
      HoneycombImageCppToC::Get(self)->IsSame(HoneycombImageCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_add_bitmap(struct _honey_image_t* self,
                                  float scale_factor,
                                  int pixel_width,
                                  int pixel_height,
                                  honey_color_type_t color_type,
                                  honey_alpha_type_t alpha_type,
                                  const void* pixel_data,
                                  size_t pixel_data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: pixel_data; type: simple_byaddr
  DCHECK(pixel_data);
  if (!pixel_data) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->AddBitmap(
      scale_factor, pixel_width, pixel_height, color_type, alpha_type,
      pixel_data, pixel_data_size);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_add_png(struct _honey_image_t* self,
                               float scale_factor,
                               const void* png_data,
                               size_t png_data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: png_data; type: simple_byaddr
  DCHECK(png_data);
  if (!png_data) {
    return 0;
  }

  // Execute
  bool _retval =
      HoneycombImageCppToC::Get(self)->AddPNG(scale_factor, png_data, png_data_size);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_add_jpeg(struct _honey_image_t* self,
                                float scale_factor,
                                const void* jpeg_data,
                                size_t jpeg_data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: jpeg_data; type: simple_byaddr
  DCHECK(jpeg_data);
  if (!jpeg_data) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->AddJPEG(scale_factor, jpeg_data,
                                                    jpeg_data_size);

  // Return type: bool
  return _retval;
}

size_t HONEYCOMB_CALLBACK image_get_width(struct _honey_image_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombImageCppToC::Get(self)->GetWidth();

  // Return type: simple
  return _retval;
}

size_t HONEYCOMB_CALLBACK image_get_height(struct _honey_image_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  size_t _retval = HoneycombImageCppToC::Get(self)->GetHeight();

  // Return type: simple
  return _retval;
}

int HONEYCOMB_CALLBACK image_has_representation(struct _honey_image_t* self,
                                          float scale_factor) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->HasRepresentation(scale_factor);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_remove_representation(struct _honey_image_t* self,
                                             float scale_factor) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->RemoveRepresentation(scale_factor);

  // Return type: bool
  return _retval;
}

int HONEYCOMB_CALLBACK image_get_representation_info(struct _honey_image_t* self,
                                               float scale_factor,
                                               float* actual_scale_factor,
                                               int* pixel_width,
                                               int* pixel_height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: actual_scale_factor; type: simple_byref
  DCHECK(actual_scale_factor);
  if (!actual_scale_factor) {
    return 0;
  }
  // Verify param: pixel_width; type: simple_byref
  DCHECK(pixel_width);
  if (!pixel_width) {
    return 0;
  }
  // Verify param: pixel_height; type: simple_byref
  DCHECK(pixel_height);
  if (!pixel_height) {
    return 0;
  }

  // Translate param: actual_scale_factor; type: simple_byref
  float actual_scale_factorVal = actual_scale_factor ? *actual_scale_factor : 0;
  // Translate param: pixel_width; type: simple_byref
  int pixel_widthVal = pixel_width ? *pixel_width : 0;
  // Translate param: pixel_height; type: simple_byref
  int pixel_heightVal = pixel_height ? *pixel_height : 0;

  // Execute
  bool _retval = HoneycombImageCppToC::Get(self)->GetRepresentationInfo(
      scale_factor, actual_scale_factorVal, pixel_widthVal, pixel_heightVal);

  // Restore param: actual_scale_factor; type: simple_byref
  if (actual_scale_factor) {
    *actual_scale_factor = actual_scale_factorVal;
  }
  // Restore param: pixel_width; type: simple_byref
  if (pixel_width) {
    *pixel_width = pixel_widthVal;
  }
  // Restore param: pixel_height; type: simple_byref
  if (pixel_height) {
    *pixel_height = pixel_heightVal;
  }

  // Return type: bool
  return _retval;
}

struct _honey_binary_value_t* HONEYCOMB_CALLBACK
image_get_as_bitmap(struct _honey_image_t* self,
                    float scale_factor,
                    honey_color_type_t color_type,
                    honey_alpha_type_t alpha_type,
                    int* pixel_width,
                    int* pixel_height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: pixel_width; type: simple_byref
  DCHECK(pixel_width);
  if (!pixel_width) {
    return NULL;
  }
  // Verify param: pixel_height; type: simple_byref
  DCHECK(pixel_height);
  if (!pixel_height) {
    return NULL;
  }

  // Translate param: pixel_width; type: simple_byref
  int pixel_widthVal = pixel_width ? *pixel_width : 0;
  // Translate param: pixel_height; type: simple_byref
  int pixel_heightVal = pixel_height ? *pixel_height : 0;

  // Execute
  HoneycombRefPtr<HoneycombBinaryValue> _retval = HoneycombImageCppToC::Get(self)->GetAsBitmap(
      scale_factor, color_type, alpha_type, pixel_widthVal, pixel_heightVal);

  // Restore param: pixel_width; type: simple_byref
  if (pixel_width) {
    *pixel_width = pixel_widthVal;
  }
  // Restore param: pixel_height; type: simple_byref
  if (pixel_height) {
    *pixel_height = pixel_heightVal;
  }

  // Return type: refptr_same
  return HoneycombBinaryValueCppToC::Wrap(_retval);
}

struct _honey_binary_value_t* HONEYCOMB_CALLBACK
image_get_as_png(struct _honey_image_t* self,
                 float scale_factor,
                 int with_transparency,
                 int* pixel_width,
                 int* pixel_height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: pixel_width; type: simple_byref
  DCHECK(pixel_width);
  if (!pixel_width) {
    return NULL;
  }
  // Verify param: pixel_height; type: simple_byref
  DCHECK(pixel_height);
  if (!pixel_height) {
    return NULL;
  }

  // Translate param: pixel_width; type: simple_byref
  int pixel_widthVal = pixel_width ? *pixel_width : 0;
  // Translate param: pixel_height; type: simple_byref
  int pixel_heightVal = pixel_height ? *pixel_height : 0;

  // Execute
  HoneycombRefPtr<HoneycombBinaryValue> _retval = HoneycombImageCppToC::Get(self)->GetAsPNG(
      scale_factor, with_transparency ? true : false, pixel_widthVal,
      pixel_heightVal);

  // Restore param: pixel_width; type: simple_byref
  if (pixel_width) {
    *pixel_width = pixel_widthVal;
  }
  // Restore param: pixel_height; type: simple_byref
  if (pixel_height) {
    *pixel_height = pixel_heightVal;
  }

  // Return type: refptr_same
  return HoneycombBinaryValueCppToC::Wrap(_retval);
}

struct _honey_binary_value_t* HONEYCOMB_CALLBACK
image_get_as_jpeg(struct _honey_image_t* self,
                  float scale_factor,
                  int quality,
                  int* pixel_width,
                  int* pixel_height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }
  // Verify param: pixel_width; type: simple_byref
  DCHECK(pixel_width);
  if (!pixel_width) {
    return NULL;
  }
  // Verify param: pixel_height; type: simple_byref
  DCHECK(pixel_height);
  if (!pixel_height) {
    return NULL;
  }

  // Translate param: pixel_width; type: simple_byref
  int pixel_widthVal = pixel_width ? *pixel_width : 0;
  // Translate param: pixel_height; type: simple_byref
  int pixel_heightVal = pixel_height ? *pixel_height : 0;

  // Execute
  HoneycombRefPtr<HoneycombBinaryValue> _retval = HoneycombImageCppToC::Get(self)->GetAsJPEG(
      scale_factor, quality, pixel_widthVal, pixel_heightVal);

  // Restore param: pixel_width; type: simple_byref
  if (pixel_width) {
    *pixel_width = pixel_widthVal;
  }
  // Restore param: pixel_height; type: simple_byref
  if (pixel_height) {
    *pixel_height = pixel_heightVal;
  }

  // Return type: refptr_same
  return HoneycombBinaryValueCppToC::Wrap(_retval);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombImageCppToC::HoneycombImageCppToC() {
  GetStruct()->is_empty = image_is_empty;
  GetStruct()->is_same = image_is_same;
  GetStruct()->add_bitmap = image_add_bitmap;
  GetStruct()->add_png = image_add_png;
  GetStruct()->add_jpeg = image_add_jpeg;
  GetStruct()->get_width = image_get_width;
  GetStruct()->get_height = image_get_height;
  GetStruct()->has_representation = image_has_representation;
  GetStruct()->remove_representation = image_remove_representation;
  GetStruct()->get_representation_info = image_get_representation_info;
  GetStruct()->get_as_bitmap = image_get_as_bitmap;
  GetStruct()->get_as_png = image_get_as_png;
  GetStruct()->get_as_jpeg = image_get_as_jpeg;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombImageCppToC::~HoneycombImageCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombImage>
HoneycombCppToCRefCounted<HoneycombImageCppToC, HoneycombImage, honey_image_t>::UnwrapDerived(
    HoneycombWrapperType type,
    honey_image_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType
    HoneycombCppToCRefCounted<HoneycombImageCppToC, HoneycombImage, honey_image_t>::kWrapperType =
        WT_IMAGE;
