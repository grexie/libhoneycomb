// Copyright (c) 2010 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include <algorithm>

#include "include/internal/honey_string_types.h"

#include "base/i18n/case_conversion.h"
#include "base/logging.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"

namespace {

void string_wide_dtor(wchar_t* str) {
  delete[] str;
}

void string_utf8_dtor(char* str) {
  delete[] str;
}

void string_utf16_dtor(char16_t* str) {
  delete[] str;
}

// Originally from base/strings/utf_string_conversions.cc
std::wstring ASCIIToWide(const base::StringPiece& ascii) {
  DCHECK(base::IsStringASCII(ascii)) << ascii;
  return std::wstring(ascii.begin(), ascii.end());
}

}  // namespace

HONEYCOMB_EXPORT int honey_string_wide_set(const wchar_t* src,
                                   size_t src_len,
                                   honey_string_wide_t* output,
                                   int copy) {
  honey_string_wide_clear(output);

  if (copy) {
    if (src && src_len > 0) {
      output->str = new wchar_t[src_len + 1];
      if (!output->str) {
        return 0;
      }

      memcpy(output->str, src, src_len * sizeof(wchar_t));
      output->str[src_len] = 0;
      output->length = src_len;
      output->dtor = string_wide_dtor;
    }
  } else {
    output->str = const_cast<wchar_t*>(src);
    output->length = src_len;
    output->dtor = nullptr;
  }
  return 1;
}

HONEYCOMB_EXPORT int honey_string_utf8_set(const char* src,
                                   size_t src_len,
                                   honey_string_utf8_t* output,
                                   int copy) {
  honey_string_utf8_clear(output);
  if (copy) {
    if (src && src_len > 0) {
      output->str = new char[src_len + 1];
      if (!output->str) {
        return 0;
      }

      memcpy(output->str, src, src_len * sizeof(char));
      output->str[src_len] = 0;
      output->length = src_len;
      output->dtor = string_utf8_dtor;
    }
  } else {
    output->str = const_cast<char*>(src);
    output->length = src_len;
    output->dtor = nullptr;
  }
  return 1;
}

HONEYCOMB_EXPORT int honey_string_utf16_set(const char16_t* src,
                                    size_t src_len,
                                    honey_string_utf16_t* output,
                                    int copy) {
  honey_string_utf16_clear(output);

  if (copy) {
    if (src && src_len > 0) {
      output->str = new char16_t[src_len + 1];
      if (!output->str) {
        return 0;
      }

      memcpy(output->str, src, src_len * sizeof(char16_t));
      output->str[src_len] = 0;
      output->length = src_len;
      output->dtor = string_utf16_dtor;
    }
  } else {
    output->str = const_cast<char16_t*>(src);
    output->length = src_len;
    output->dtor = nullptr;
  }
  return 1;
}

HONEYCOMB_EXPORT void honey_string_wide_clear(honey_string_wide_t* str) {
  DCHECK(str != nullptr);
  if (str->dtor && str->str) {
    str->dtor(str->str);
  }

  str->str = nullptr;
  str->length = 0;
  str->dtor = nullptr;
}

HONEYCOMB_EXPORT void honey_string_utf8_clear(honey_string_utf8_t* str) {
  DCHECK(str != nullptr);
  if (str->dtor && str->str) {
    str->dtor(str->str);
  }

  str->str = nullptr;
  str->length = 0;
  str->dtor = nullptr;
}

HONEYCOMB_EXPORT void honey_string_utf16_clear(honey_string_utf16_t* str) {
  DCHECK(str != nullptr);
  if (str->dtor && str->str) {
    str->dtor(str->str);
  }

  str->str = nullptr;
  str->length = 0;
  str->dtor = nullptr;
}

HONEYCOMB_EXPORT int honey_string_wide_cmp(const honey_string_wide_t* str1,
                                   const honey_string_wide_t* str2) {
  if (str1->length == 0 && str2->length == 0) {
    return 0;
  }
  int r = wcsncmp(str1->str, str2->str, std::min(str1->length, str2->length));
  if (r == 0) {
    if (str1->length > str2->length) {
      return 1;
    } else if (str1->length < str2->length) {
      return -1;
    }
  }
  return r;
}

HONEYCOMB_EXPORT int honey_string_utf8_cmp(const honey_string_utf8_t* str1,
                                   const honey_string_utf8_t* str2) {
  if (str1->length == 0 && str2->length == 0) {
    return 0;
  }
  int r = strncmp(str1->str, str2->str, std::min(str1->length, str2->length));
  if (r == 0) {
    if (str1->length > str2->length) {
      return 1;
    } else if (str1->length < str2->length) {
      return -1;
    }
  }
  return r;
}

HONEYCOMB_EXPORT int honey_string_utf16_cmp(const honey_string_utf16_t* str1,
                                    const honey_string_utf16_t* str2) {
  if (str1->length == 0 && str2->length == 0) {
    return 0;
  }
#if defined(WCHAR_T_IS_UTF32)
  int r = std::char_traits<std::u16string::value_type>::compare(
      reinterpret_cast<std::u16string::value_type*>(str1->str),
      reinterpret_cast<std::u16string::value_type*>(str2->str),
      std::min(str1->length, str2->length));
#else
  int r = wcsncmp(reinterpret_cast<wchar_t*>(str1->str),
                  reinterpret_cast<wchar_t*>(str2->str),
                  std::min(str1->length, str2->length));
#endif
  if (r == 0) {
    if (str1->length > str2->length) {
      return 1;
    } else if (str1->length < str2->length) {
      return -1;
    }
  }
  return r;
}

HONEYCOMB_EXPORT int honey_string_wide_to_utf8(const wchar_t* src,
                                       size_t src_len,
                                       honey_string_utf8_t* output) {
  std::string str;
  bool ret = base::WideToUTF8(src, src_len, &str);
  if (!honey_string_utf8_set(str.c_str(), str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_utf8_to_wide(const char* src,
                                       size_t src_len,
                                       honey_string_wide_t* output) {
  std::wstring str;
  bool ret = base::UTF8ToWide(src, src_len, &str);
  if (!honey_string_wide_set(str.c_str(), str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_wide_to_utf16(const wchar_t* src,
                                        size_t src_len,
                                        honey_string_utf16_t* output) {
  std::u16string str;
  bool ret = base::WideToUTF16(src, src_len, &str);
  if (!honey_string_utf16_set(reinterpret_cast<const char16_t*>(str.c_str()),
                            str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_utf16_to_wide(const char16_t* src,
                                        size_t src_len,
                                        honey_string_wide_t* output) {
  std::wstring str;
  bool ret = base::UTF16ToWide(
      reinterpret_cast<const std::u16string::value_type*>(src), src_len, &str);
  if (!honey_string_wide_set(str.c_str(), str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_utf8_to_utf16(const char* src,
                                        size_t src_len,
                                        honey_string_utf16_t* output) {
  std::u16string str;
  bool ret = base::UTF8ToUTF16(src, src_len, &str);
  if (!honey_string_utf16_set(reinterpret_cast<const char16_t*>(str.c_str()),
                            str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_utf16_to_utf8(const char16_t* src,
                                        size_t src_len,
                                        honey_string_utf8_t* output) {
  std::string str;
  bool ret = base::UTF16ToUTF8(
      reinterpret_cast<const std::u16string::value_type*>(src), src_len, &str);
  if (!honey_string_utf8_set(str.c_str(), str.length(), output, true)) {
    return false;
  }
  return ret;
}

HONEYCOMB_EXPORT int honey_string_ascii_to_wide(const char* src,
                                        size_t src_len,
                                        honey_string_wide_t* output) {
  const std::wstring& str = ASCIIToWide(std::string(src, src_len));
  return honey_string_wide_set(str.c_str(), str.length(), output, true);
}

HONEYCOMB_EXPORT int honey_string_ascii_to_utf16(const char* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output) {
  const std::u16string& str = base::ASCIIToUTF16(std::string(src, src_len));
  return honey_string_utf16_set(reinterpret_cast<const char16_t*>(str.c_str()),
                              str.length(), output, true);
}

HONEYCOMB_EXPORT honey_string_userfree_wide_t honey_string_userfree_wide_alloc() {
  honey_string_wide_t* s = new honey_string_wide_t;
  memset(s, 0, sizeof(honey_string_wide_t));
  return s;
}

HONEYCOMB_EXPORT honey_string_userfree_utf8_t honey_string_userfree_utf8_alloc() {
  honey_string_utf8_t* s = new honey_string_utf8_t;
  memset(s, 0, sizeof(honey_string_utf8_t));
  return s;
}

HONEYCOMB_EXPORT honey_string_userfree_utf16_t honey_string_userfree_utf16_alloc() {
  honey_string_utf16_t* s = new honey_string_utf16_t;
  memset(s, 0, sizeof(honey_string_utf16_t));
  return s;
}

HONEYCOMB_EXPORT void honey_string_userfree_wide_free(honey_string_userfree_wide_t str) {
  honey_string_wide_clear(str);
  delete str;
}

HONEYCOMB_EXPORT void honey_string_userfree_utf8_free(honey_string_userfree_utf8_t str) {
  honey_string_utf8_clear(str);
  delete str;
}

HONEYCOMB_EXPORT void honey_string_userfree_utf16_free(
    honey_string_userfree_utf16_t str) {
  honey_string_utf16_clear(str);
  delete str;
}

HONEYCOMB_EXPORT int honey_string_utf16_to_lower(const char16_t* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output) {
  const std::u16string& str = base::i18n::ToLower(std::u16string(
      reinterpret_cast<const std::u16string::value_type*>(src), src_len));
  return honey_string_utf16_set(reinterpret_cast<const char16_t*>(str.c_str()),
                              str.length(), output, true);
}

HONEYCOMB_EXPORT int honey_string_utf16_to_upper(const char16_t* src,
                                         size_t src_len,
                                         honey_string_utf16_t* output) {
  const std::u16string& str = base::i18n::ToUpper(std::u16string(
      reinterpret_cast<const std::u16string::value_type*>(src), src_len));
  return honey_string_utf16_set(reinterpret_cast<const char16_t*>(str.c_str()),
                              str.length(), output, true);
}
