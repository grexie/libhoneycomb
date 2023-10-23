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
// $hash=19152f67304ceaf2d54f0b8133f317974145d40e$
//

#include "libhoney_dll/ctocpp/request_handler_ctocpp.h"
#include "libhoney_dll/cpptoc/auth_callback_cpptoc.h"
#include "libhoney_dll/cpptoc/browser_cpptoc.h"
#include "libhoney_dll/cpptoc/callback_cpptoc.h"
#include "libhoney_dll/cpptoc/frame_cpptoc.h"
#include "libhoney_dll/cpptoc/request_cpptoc.h"
#include "libhoney_dll/cpptoc/select_client_certificate_callback_cpptoc.h"
#include "libhoney_dll/cpptoc/sslinfo_cpptoc.h"
#include "libhoney_dll/cpptoc/x509certificate_cpptoc.h"
#include "libhoney_dll/ctocpp/resource_request_handler_ctocpp.h"
#include "libhoney_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool HoneycombRequestHandlerCToCpp::OnBeforeBrowse(HoneycombRefPtr<HoneycombBrowser> browser,
                                             HoneycombRefPtr<HoneycombFrame> frame,
                                             HoneycombRefPtr<HoneycombRequest> request,
                                             bool user_gesture,
                                             bool is_redirect) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_before_browse)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->on_before_browse(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      HoneycombRequestCppToC::Wrap(request), user_gesture, is_redirect);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombRequestHandlerCToCpp::OnOpenURLFromTab(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    const HoneycombString& target_url,
    WindowOpenDisposition target_disposition,
    bool user_gesture) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_open_urlfrom_tab)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return false;
  }
  // Verify param: target_url; type: string_byref_const
  DCHECK(!target_url.empty());
  if (target_url.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->on_open_urlfrom_tab(
      _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
      target_url.GetStruct(), target_disposition, user_gesture);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
HoneycombRefPtr<HoneycombResourceRequestHandler>
HoneycombRequestHandlerCToCpp::GetResourceRequestHandler(
    HoneycombRefPtr<HoneycombBrowser> browser,
    HoneycombRefPtr<HoneycombFrame> frame,
    HoneycombRefPtr<HoneycombRequest> request,
    bool is_navigation,
    bool is_download,
    const HoneycombString& request_initiator,
    bool& disable_default_handling) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_resource_request_handler)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return nullptr;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return nullptr;
  }
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get()) {
    return nullptr;
  }
  // Unverified params: request_initiator

  // Translate param: disable_default_handling; type: bool_byref
  int disable_default_handlingInt = disable_default_handling;

  // Execute
  honey_resource_request_handler_t* _retval =
      _struct->get_resource_request_handler(
          _struct, HoneycombBrowserCppToC::Wrap(browser), HoneycombFrameCppToC::Wrap(frame),
          HoneycombRequestCppToC::Wrap(request), is_navigation, is_download,
          request_initiator.GetStruct(), &disable_default_handlingInt);

  // Restore param:disable_default_handling; type: bool_byref
  disable_default_handling = disable_default_handlingInt ? true : false;

  // Return type: refptr_same
  return HoneycombResourceRequestHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool HoneycombRequestHandlerCToCpp::GetAuthCredentials(
    HoneycombRefPtr<HoneycombBrowser> browser,
    const HoneycombString& origin_url,
    bool isProxy,
    const HoneycombString& host,
    int port,
    const HoneycombString& realm,
    const HoneycombString& scheme,
    HoneycombRefPtr<HoneycombAuthCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, get_auth_credentials)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: origin_url; type: string_byref_const
  DCHECK(!origin_url.empty());
  if (origin_url.empty()) {
    return false;
  }
  // Verify param: host; type: string_byref_const
  DCHECK(!host.empty());
  if (host.empty()) {
    return false;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get()) {
    return false;
  }
  // Unverified params: realm, scheme

  // Execute
  int _retval = _struct->get_auth_credentials(
      _struct, HoneycombBrowserCppToC::Wrap(browser), origin_url.GetStruct(), isProxy,
      host.GetStruct(), port, realm.GetStruct(), scheme.GetStruct(),
      HoneycombAuthCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombRequestHandlerCToCpp::OnCertificateError(
    HoneycombRefPtr<HoneycombBrowser> browser,
    honey_errorcode_t cert_error,
    const HoneycombString& request_url,
    HoneycombRefPtr<HoneycombSSLInfo> ssl_info,
    HoneycombRefPtr<HoneycombCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_certificate_error)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: request_url; type: string_byref_const
  DCHECK(!request_url.empty());
  if (request_url.empty()) {
    return false;
  }
  // Verify param: ssl_info; type: refptr_diff
  DCHECK(ssl_info.get());
  if (!ssl_info.get()) {
    return false;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->on_certificate_error(
      _struct, HoneycombBrowserCppToC::Wrap(browser), cert_error,
      request_url.GetStruct(), HoneycombSSLInfoCppToC::Wrap(ssl_info),
      HoneycombCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool HoneycombRequestHandlerCToCpp::OnSelectClientCertificate(
    HoneycombRefPtr<HoneycombBrowser> browser,
    bool isProxy,
    const HoneycombString& host,
    int port,
    const X509CertificateList& certificates,
    HoneycombRefPtr<HoneycombSelectClientCertificateCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_select_client_certificate)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return false;
  }
  // Verify param: host; type: string_byref_const
  DCHECK(!host.empty());
  if (host.empty()) {
    return false;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get()) {
    return false;
  }

  // Translate param: certificates; type: refptr_vec_diff_byref_const
  const size_t certificatesCount = certificates.size();
  honey_x509certificate_t** certificatesList = NULL;
  if (certificatesCount > 0) {
    certificatesList = new honey_x509certificate_t*[certificatesCount];
    DCHECK(certificatesList);
    if (certificatesList) {
      for (size_t i = 0; i < certificatesCount; ++i) {
        certificatesList[i] = HoneycombX509CertificateCppToC::Wrap(certificates[i]);
      }
    }
  }

  // Execute
  int _retval = _struct->on_select_client_certificate(
      _struct, HoneycombBrowserCppToC::Wrap(browser), isProxy, host.GetStruct(), port,
      certificatesCount, certificatesList,
      HoneycombSelectClientCertificateCallbackCppToC::Wrap(callback));

  // Restore param:certificates; type: refptr_vec_diff_byref_const
  if (certificatesList) {
    delete[] certificatesList;
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestHandlerCToCpp::OnRenderViewReady(HoneycombRefPtr<HoneycombBrowser> browser) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_render_view_ready)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }

  // Execute
  _struct->on_render_view_ready(_struct, HoneycombBrowserCppToC::Wrap(browser));
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestHandlerCToCpp::OnRenderProcessTerminated(
    HoneycombRefPtr<HoneycombBrowser> browser,
    TerminationStatus status) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_render_process_terminated)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }

  // Execute
  _struct->on_render_process_terminated(
      _struct, HoneycombBrowserCppToC::Wrap(browser), status);
}

NO_SANITIZE("cfi-icall")
void HoneycombRequestHandlerCToCpp::OnDocumentAvailableInMainFrame(
    HoneycombRefPtr<HoneycombBrowser> browser) {
  shutdown_checker::AssertNotShutdown();

  honey_request_handler_t* _struct = GetStruct();
  if (HONEYCOMB_MEMBER_MISSING(_struct, on_document_available_in_main_frame)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }

  // Execute
  _struct->on_document_available_in_main_frame(_struct,
                                               HoneycombBrowserCppToC::Wrap(browser));
}

// CONSTRUCTOR - Do not edit by hand.

HoneycombRequestHandlerCToCpp::HoneycombRequestHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombRequestHandlerCToCpp::~HoneycombRequestHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
honey_request_handler_t* HoneycombCToCppRefCounted<
    HoneycombRequestHandlerCToCpp,
    HoneycombRequestHandler,
    honey_request_handler_t>::UnwrapDerived(HoneycombWrapperType type,
                                          HoneycombRequestHandler* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCToCppRefCounted<HoneycombRequestHandlerCToCpp,
                                   HoneycombRequestHandler,
                                   honey_request_handler_t>::kWrapperType =
    WT_REQUEST_HANDLER;