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
// $hash=82e87e32f0c6e2da2ae52a8f3af76e22790ee911$
//

#include "libhoneycomb_dll/ctocpp/sslstatus_ctocpp.h"
#include "libhoneycomb_dll/ctocpp/x509certificate_ctocpp.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool HoneycombSSLStatusCToCpp::IsSecureConnection() {
  shutdown_checker::AssertNotShutdown();

  honey_sslstatus_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, is_secure_connection)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_secure_connection(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") honey_cert_status_t HoneycombSSLStatusCToCpp::GetCertStatus() {
  shutdown_checker::AssertNotShutdown();

  honey_sslstatus_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_cert_status)) {
    return CERT_STATUS_NONE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_cert_status_t _retval = _struct->get_cert_status(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") honey_ssl_version_t HoneycombSSLStatusCToCpp::GetSSLVersion() {
  shutdown_checker::AssertNotShutdown();

  honey_sslstatus_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_sslversion)) {
    return SSL_CONNECTION_VERSION_UNKNOWN;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_ssl_version_t _retval = _struct->get_sslversion(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
honey_ssl_content_status_t HoneycombSSLStatusCToCpp::GetContentStatus() {
  shutdown_checker::AssertNotShutdown();

  honey_sslstatus_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_content_status)) {
    return SSL_CONTENT_NORMAL_CONTENT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_ssl_content_status_t _retval = _struct->get_content_status(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombX509Certificate> HoneycombSSLStatusCToCpp::GetX509Certificate() {
  shutdown_checker::AssertNotShutdown();

  honey_sslstatus_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_x509certificate)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  honey_x509certificate_t* _retval = _struct->get_x509certificate(_struct);

  // Return type: refptr_same
  return HoneycombX509CertificateCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombSSLStatusCToCpp::HoneycombSSLStatusCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombSSLStatusCToCpp::~HoneycombSSLStatusCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_sslstatus_t*
HoneycombCToCppRefCounted<HoneycombSSLStatusCToCpp, HoneycombSSLStatus, honey_sslstatus_t>::
    UnwrapDerived(HoneycombWrapperType type, HoneycombSSLStatus* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombSSLStatusCToCpp,
                                   HoneycombSSLStatus,
                                   honey_sslstatus_t>::kWrapperType =
    WT_SSLSTATUS;
