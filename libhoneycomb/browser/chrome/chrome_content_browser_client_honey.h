// Copyright 2020 The Honeycomb Authors.
// Portions copyright 2012 The Chromium Authors and 2016 the CEF Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_CONTENT_BROWSER_CLIENT_HONEYCOMB_
#define HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_CONTENT_BROWSER_CLIENT_HONEYCOMB_

#include <memory>

#include "libhoneycomb/browser/request_context_impl.h"

#include "chrome/browser/chrome_content_browser_client.h"

class ChromeBrowserMainExtraPartsHoneycomb;

// Honeycomb override of ChromeContentBrowserClient.
class ChromeContentBrowserClientHoneycomb : public ChromeContentBrowserClient {
 public:
  ChromeContentBrowserClientHoneycomb();

  ChromeContentBrowserClientHoneycomb(const ChromeContentBrowserClientHoneycomb&) = delete;
  ChromeContentBrowserClientHoneycomb& operator=(
      const ChromeContentBrowserClientHoneycomb&) = delete;

  ~ChromeContentBrowserClientHoneycomb() override;

  // ChromeContentBrowserClient overrides.
  std::unique_ptr<content::BrowserMainParts> CreateBrowserMainParts(
      bool is_integration_test) override;
  void AppendExtraCommandLineSwitches(base::CommandLine* command_line,
                                      int child_process_id) override;
  void RenderProcessWillLaunch(content::RenderProcessHost* host) override;
  void AllowCertificateError(
      content::WebContents* web_contents,
      int cert_error,
      const net::SSLInfo& ssl_info,
      const GURL& request_url,
      bool is_main_frame_request,
      bool strict_enforcement,
      base::OnceCallback<void(content::CertificateRequestResultType)> callback)
      override;
  bool CanCreateWindow(content::RenderFrameHost* opener,
                       const GURL& opener_url,
                       const GURL& opener_top_level_frame_url,
                       const url::Origin& source_origin,
                       content::mojom::WindowContainerType container_type,
                       const GURL& target_url,
                       const content::Referrer& referrer,
                       const std::string& frame_name,
                       WindowOpenDisposition disposition,
                       const blink::mojom::WindowFeatures& features,
                       bool user_gesture,
                       bool opener_suppressed,
                       bool* no_javascript_access) override;
  void OverrideWebkitPrefs(content::WebContents* web_contents,
                           blink::web_pref::WebPreferences* prefs) override;
  bool WillCreateURLLoaderFactory(
      content::BrowserContext* browser_context,
      content::RenderFrameHost* frame,
      int render_process_id,
      URLLoaderFactoryType type,
      const url::Origin& request_initiator,
      absl::optional<int64_t> navigation_id,
      ukm::SourceIdObj ukm_source_id,
      mojo::PendingReceiver<network::mojom::URLLoaderFactory>* factory_receiver,
      mojo::PendingRemote<network::mojom::TrustedURLLoaderHeaderClient>*
          header_client,
      bool* bypass_redirect_checks,
      bool* disable_secure_dns,
      network::mojom::URLLoaderFactoryOverridePtr* factory_override,
      scoped_refptr<base::SequencedTaskRunner> navigation_response_task_runner)
      override;
  bool HandleExternalProtocol(
      const GURL& url,
      content::WebContents::Getter web_contents_getter,
      int frame_tree_node_id,
      content::NavigationUIData* navigation_data,
      bool is_primary_main_frame,
      bool is_in_fenced_frame_tree,
      network::mojom::WebSandboxFlags sandbox_flags,
      ui::PageTransition page_transition,
      bool has_user_gesture,
      const absl::optional<url::Origin>& initiating_origin,
      content::RenderFrameHost* initiator_document,
      mojo::PendingRemote<network::mojom::URLLoaderFactory>* out_factory)
      override;
  bool HandleExternalProtocol(
      content::WebContents::Getter web_contents_getter,
      int frame_tree_node_id,
      content::NavigationUIData* navigation_data,
      bool is_primary_main_frame,
      bool is_in_fenced_frame_tree,
      network::mojom::WebSandboxFlags sandbox_flags,
      const network::ResourceRequest& request,
      const absl::optional<url::Origin>& initiating_origin,
      content::RenderFrameHost* initiator_document,
      mojo::PendingRemote<network::mojom::URLLoaderFactory>* out_factory)
      override;
  std::vector<std::unique_ptr<content::NavigationThrottle>>
  CreateThrottlesForNavigation(
      content::NavigationHandle* navigation_handle) override;
  bool ConfigureNetworkContextParams(
      content::BrowserContext* context,
      bool in_memory,
      const base::FilePath& relative_partition_path,
      network::mojom::NetworkContextParams* network_context_params,
      cert_verifier::mojom::CertVerifierCreationParams*
          cert_verifier_creation_params) override;
  std::unique_ptr<content::LoginDelegate> CreateLoginDelegate(
      const net::AuthChallengeInfo& auth_info,
      content::WebContents* web_contents,
      const content::GlobalRequestID& request_id,
      bool is_request_for_main_frame,
      const GURL& url,
      scoped_refptr<net::HttpResponseHeaders> response_headers,
      bool first_auth_attempt,
      LoginAuthRequiredCallback auth_required_callback) override;
  void BrowserURLHandlerCreated(content::BrowserURLHandler* handler) override;
  bool IsWebUIAllowedToMakeNetworkRequests(const url::Origin& origin) override;
  void ExposeInterfacesToRenderer(
      service_manager::BinderRegistry* registry,
      blink::AssociatedInterfaceRegistry* associated_registry,
      content::RenderProcessHost* render_process_host) override;
  void RegisterBrowserInterfaceBindersForFrame(
      content::RenderFrameHost* render_frame_host,
      mojo::BinderMapWithContext<content::RenderFrameHost*>* map) override;

  HoneycombRefPtr<HoneycombRequestContextImpl> request_context() const;

  scoped_refptr<base::SingleThreadTaskRunner> background_task_runner() const;
  scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner() const;
  scoped_refptr<base::SingleThreadTaskRunner> user_blocking_task_runner() const;

 private:
  ChromeBrowserMainExtraPartsHoneycomb* browser_main_parts_ = nullptr;
};

#endif  // HONEYCOMB_LIBHONEYCOMB_BROWSER_CHROME_CHROME_CONTENT_BROWSER_CLIENT_HONEYCOMB_
