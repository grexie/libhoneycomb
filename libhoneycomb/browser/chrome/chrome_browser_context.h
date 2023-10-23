// Copyright 2020 The Honeycomb Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_BROWSER_CONTEXT_H_
#define HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_BROWSER_CONTEXT_H_
#pragma once

#include "libhoneycomb/browser/browser_context.h"

#include "base/memory/weak_ptr.h"
#include "chrome/browser/profiles/profile_manager.h"
#include "chrome/browser/profiles/profile_observer.h"

class ScopedProfileKeepAlive;

// See HoneycombBrowserContext documentation for usage. Only accessed on the UI thread
// unless otherwise indicated.
class ChromeBrowserContext : public HoneycombBrowserContext, public ProfileObserver {
 public:
  explicit ChromeBrowserContext(const HoneycombRequestContextSettings& settings);

  ChromeBrowserContext(const ChromeBrowserContext&) = delete;
  ChromeBrowserContext& operator=(const ChromeBrowserContext&) = delete;

  void InitializeAsync(base::OnceClosure initialized_cb);

  // HoneycombBrowserContext overrides.
  content::BrowserContext* AsBrowserContext() override;
  Profile* AsProfile() override;
  bool IsInitialized() const override;
  void StoreOrTriggerInitCallback(base::OnceClosure callback) override;
  void Shutdown() override;

  // ProfileObserver overrides.
  void OnProfileWillBeDestroyed(Profile* profile) override;

 private:
  ~ChromeBrowserContext() override;

  void ProfileCreated(Profile::CreateStatus status, Profile* profile);

  base::OnceClosure initialized_cb_;
  Profile* profile_ = nullptr;
  bool should_destroy_ = false;

  bool destroyed_ = false;
  std::unique_ptr<ScopedProfileKeepAlive> profile_keep_alive_;

  std::vector<base::OnceClosure> init_callbacks_;

  base::WeakPtrFactory<ChromeBrowserContext> weak_ptr_factory_;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_BROWSER_CONTEXT_H_
