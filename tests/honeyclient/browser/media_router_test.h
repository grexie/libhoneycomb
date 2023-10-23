// Copyright (c) 2020 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_MEDIA_ROUTER_TEST_H_
#define HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_MEDIA_ROUTER_TEST_H_
#pragma once

#include "tests/honeyclient/browser/test_runner.h"

namespace client {
namespace media_router_test {

// Create message handlers. Called from test_runner.cc.
void CreateMessageHandlers(test_runner::MessageHandlerSet& handlers);

}  // namespace media_router_test
}  // namespace client

#endif  // HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_MEDIA_ROUTER_TEST_H_
