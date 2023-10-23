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
// $hash=5c03427a3976bd488c9a90ca0456835b6582f59a$
//

#include "libhoneycomb_dll/cpptoc/sslstatus_cpptoc.h"
#include "libhoneycomb_dll/cpptoc/x509certificate_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int HONEYCOMB_CALLBACK sslstatus_is_secure_connection(struct _honey_sslstatus_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  bool _retval = HoneycombSSLStatusCppToC::Get(self)->IsSecureConnection();

  // Return type: bool
  return _retval;
}

honey_cert_status_t HONEYCOMB_CALLBACK
sslstatus_get_cert_status(struct _honey_sslstatus_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return CERT_STATUS_NONE;
  }

  // Execute
  honey_cert_status_t _retval = HoneycombSSLStatusCppToC::Get(self)->GetCertStatus();

  // Return type: simple
  return _retval;
}

honey_ssl_version_t HONEYCOMB_CALLBACK
sslstatus_get_sslversion(struct _honey_sslstatus_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return SSL_CONNECTION_VERSION_UNKNOWN;
  }

  // Execute
  honey_ssl_version_t _retval = HoneycombSSLStatusCppToC::Get(self)->GetSSLVersion();

  // Return type: simple
  return _retval;
}

honey_ssl_content_status_t HONEYCOMB_CALLBACK
sslstatus_get_content_status(struct _honey_sslstatus_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return SSL_CONTENT_NORMAL_CONTENT;
  }

  // Execute
  honey_ssl_content_status_t _retval =
      HoneycombSSLStatusCppToC::Get(self)->GetContentStatus();

  // Return type: simple
  return _retval;
}

struct _honey_x509certificate_t* HONEYCOMB_CALLBACK
sslstatus_get_x509certificate(struct _honey_sslstatus_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  HoneycombRefPtr<HoneycombX509Certificate> _retval =
      HoneycombSSLStatusCppToC::Get(self)->GetX509Certificate();

  // Return type: refptr_same
  return HoneycombX509CertificateCppToC::Wrap(_retval);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

HoneycombSSLStatusCppToC::HoneycombSSLStatusCppToC() {
  GetStruct()->is_secure_connection = sslstatus_is_secure_connection;
  GetStruct()->get_cert_status = sslstatus_get_cert_status;
  GetStruct()->get_sslversion = sslstatus_get_sslversion;
  GetStruct()->get_content_status = sslstatus_get_content_status;
  GetStruct()->get_x509certificate = sslstatus_get_x509certificate;
}

// DESTRUCTOR - Do not edit by hand.

HoneycombSSLStatusCppToC::~HoneycombSSLStatusCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombSSLStatus>
HoneycombCppToCRefCounted<HoneycombSSLStatusCppToC, HoneycombSSLStatus, honey_sslstatus_t>::
    UnwrapDerived(HoneycombWrapperType type, honey_sslstatus_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombSSLStatusCppToC,
                                   HoneycombSSLStatus,
                                   honey_sslstatus_t>::kWrapperType =
    WT_SSLSTATUS;
