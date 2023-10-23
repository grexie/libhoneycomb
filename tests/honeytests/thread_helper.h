// Copyright (c) 2013 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef HONEYCOMB_TESTS_HONEYCOMBTESTS_THREAD_HELPER_H_
#define HONEYCOMB_TESTS_HONEYCOMBTESTS_THREAD_HELPER_H_
#pragma once

#include "include/base/honey_callback.h"
#include "include/honey_task.h"
#include "include/honey_waitable_event.h"

// Helper for signaling |event|.
void SignalEvent(HoneycombRefPtr<HoneycombWaitableEvent> event);

// Post a task to the specified thread and wait for the task to execute as
// indication that all previously pending tasks on that thread have completed.
void WaitForThread(HoneycombThreadId thread_id, int64_t delay_ms = 0);
void WaitForThread(HoneycombRefPtr<HoneycombTaskRunner> task_runner, int64_t delay_ms = 0);

#define WaitForIOThread() WaitForThread(TID_IO)
#define WaitForUIThread() WaitForThread(TID_UI)
#define WaitForFILEThread() WaitForThread(TID_FILE_USER_VISIBLE)
#define WaitForIOThreadWithDelay(delay_ms) WaitForThread(TID_IO, delay_ms)
#define WaitForUIThreadWithDelay(delay_ms) WaitForThread(TID_UI, delay_ms)
#define WaitForFILEThreadWithDelay(delay_ms) \
  WaitForThread(TID_FILE_USER_VISIBLE, delay_ms)

// Assert that execution is occuring on the named thread.
#define EXPECT_UI_THREAD() EXPECT_TRUE(HoneycombCurrentlyOn(TID_UI));
#define EXPECT_IO_THREAD() EXPECT_TRUE(HoneycombCurrentlyOn(TID_IO));
#define EXPECT_FILE_THREAD() EXPECT_TRUE(HoneycombCurrentlyOn(TID_FILE_USER_VISIBLE));
#define EXPECT_RENDERER_THREAD() EXPECT_TRUE(HoneycombCurrentlyOn(TID_RENDERER));

// Executes |test_impl| on the specified |thread_id|. |event| will be signaled
// once execution is complete.
void RunOnThread(HoneycombThreadId thread_id,
                 base::OnceClosure test_impl,
                 HoneycombRefPtr<HoneycombWaitableEvent> event);

#define NAMED_THREAD_TEST(thread_id, test_case_name, test_name)     \
  TEST(test_case_name, test_name) {                                 \
    HoneycombRefPtr<HoneycombWaitableEvent> event =                             \
        HoneycombWaitableEvent::CreateWaitableEvent(true, false);         \
    RunOnThread(thread_id, base::BindOnce(test_name##Impl), event); \
    event->Wait();                                                  \
  }

// Execute "test_case_name.test_name" test on the named thread. The test
// implementation is "void test_nameImpl()".
#define UI_THREAD_TEST(test_case_name, test_name) \
  NAMED_THREAD_TEST(TID_UI, test_case_name, test_name)

// Like RunOnThread() but |test_impl| is responsible for signaling |event|.
void RunOnThreadAsync(
    HoneycombThreadId thread_id,
    base::OnceCallback<void(HoneycombRefPtr<HoneycombWaitableEvent>)> test_impl,
    HoneycombRefPtr<HoneycombWaitableEvent>);

#define NAMED_THREAD_TEST_ASYNC(thread_id, test_case_name, test_name)    \
  TEST(test_case_name, test_name) {                                      \
    HoneycombRefPtr<HoneycombWaitableEvent> event =                                  \
        HoneycombWaitableEvent::CreateWaitableEvent(true, false);              \
    RunOnThreadAsync(thread_id, base::BindOnce(test_name##Impl), event); \
    event->Wait();                                                       \
  }

// Execute "test_case_name.test_name" test on the named thread. The test
// implementation is "void test_nameImpl(HoneycombRefPtr<HoneycombWaitableEvent> event)".
#define UI_THREAD_TEST_ASYNC(test_case_name, test_name) \
  NAMED_THREAD_TEST_ASYNC(TID_UI, test_case_name, test_name)

#endif  // HONEYCOMB_TESTS_HONEYCOMBTESTS_THREAD_HELPER_H_