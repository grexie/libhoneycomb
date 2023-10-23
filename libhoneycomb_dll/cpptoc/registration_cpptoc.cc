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
// $hash=b8ae4bec56faeb74fd5ddad0cacb053a17babc08$
//

#include "libhoneycomb_dll/cpptoc/registration_cpptoc.h"
#include "libhoneycomb_dll/shutdown_checker.h"

// CONSTRUCTOR - Do not edit by hand.

HoneycombRegistrationCppToC::HoneycombRegistrationCppToC() {}

// DESTRUCTOR - Do not edit by hand.

HoneycombRegistrationCppToC::~HoneycombRegistrationCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
HoneycombRefPtr<HoneycombRegistration>
HoneycombCppToCRefCounted<HoneycombRegistrationCppToC,
                    HoneycombRegistration,
                    honey_registration_t>::UnwrapDerived(HoneycombWrapperType type,
                                                       honey_registration_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
HoneycombWrapperType HoneycombCppToCRefCounted<HoneycombRegistrationCppToC,
                                   HoneycombRegistration,
                                   honey_registration_t>::kWrapperType =
    WT_REGISTRATION;
