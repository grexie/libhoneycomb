// Copyright (c) 2023 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_TYPES_CONTENT_SETTINGS_H_
#define HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_TYPES_CONTENT_SETTINGS_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///
/// Supported content setting types. Some types are platform-specific or only
/// supported with the Chrome runtime. Should be kept in sync with Chromium's
/// ContentSettingsType type.
///
typedef enum {
  // This setting governs whether cookies are enabled by the user in the
  /// provided context. However, it may be overridden by other settings. This
  /// enum should NOT be read directly to determine whether cookies are enabled;
  /// the client should instead rely on the CookieSettings API.
  HONEYCOMB_CONTENT_SETTING_TYPE_COOKIES = 0,
  HONEYCOMB_CONTENT_SETTING_TYPE_IMAGES,
  HONEYCOMB_CONTENT_SETTING_TYPE_JAVASCRIPT,

  /// This setting governs both popups and unwanted redirects like tab-unders
  /// and framebusting.
  HONEYCOMB_CONTENT_SETTING_TYPE_POPUPS,

  HONEYCOMB_CONTENT_SETTING_TYPE_GEOLOCATION,
  HONEYCOMB_CONTENT_SETTING_TYPE_NOTIFICATIONS,
  HONEYCOMB_CONTENT_SETTING_TYPE_AUTO_SELECT_CERTIFICATE,
  HONEYCOMB_CONTENT_SETTING_TYPE_MIXEDSCRIPT,
  HONEYCOMB_CONTENT_SETTING_TYPE_MEDIASTREAM_MIC,
  HONEYCOMB_CONTENT_SETTING_TYPE_MEDIASTREAM_CAMERA,
  HONEYCOMB_CONTENT_SETTING_TYPE_PROTOCOL_HANDLERS,
  HONEYCOMB_CONTENT_SETTING_TYPE_DEPRECATED_PPAPI_BROKER,
  HONEYCOMB_CONTENT_SETTING_TYPE_AUTOMATIC_DOWNLOADS,

  /// Advanced device-specific functions on MIDI devices. MIDI-SysEx
  /// communications can be used for changing the MIDI device's persistent state
  /// such as firmware.
  HONEYCOMB_CONTENT_SETTING_TYPE_MIDI_SYSEX,

  HONEYCOMB_CONTENT_SETTING_TYPE_SSL_CERT_DECISIONS,
  HONEYCOMB_CONTENT_SETTING_TYPE_PROTECTED_MEDIA_IDENTIFIER,
  HONEYCOMB_CONTENT_SETTING_TYPE_APP_BANNER,
  HONEYCOMB_CONTENT_SETTING_TYPE_SITE_ENGAGEMENT,
  HONEYCOMB_CONTENT_SETTING_TYPE_DURABLE_STORAGE,
  HONEYCOMB_CONTENT_SETTING_TYPE_USB_CHOOSER_DATA,
  HONEYCOMB_CONTENT_SETTING_TYPE_BLUETOOTH_GUARD,
  HONEYCOMB_CONTENT_SETTING_TYPE_BACKGROUND_SYNC,
  HONEYCOMB_CONTENT_SETTING_TYPE_AUTOPLAY,
  HONEYCOMB_CONTENT_SETTING_TYPE_IMPORTANT_SITE_INFO,
  HONEYCOMB_CONTENT_SETTING_TYPE_PERMISSION_AUTOBLOCKER_DATA,
  HONEYCOMB_CONTENT_SETTING_TYPE_ADS,

  /// Website setting which stores metadata for the subresource filter to aid in
  /// decisions for whether or not to show the UI.
  HONEYCOMB_CONTENT_SETTING_TYPE_ADS_DATA,

  /// MIDI stands for Musical Instrument Digital Interface. It is a standard
  /// that allows electronic musical instruments, computers, and other devices
  /// to communicate with each other.
  HONEYCOMB_CONTENT_SETTING_TYPE_MIDI,

  /// This content setting type is for caching password protection service's
  /// verdicts of each origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_PASSWORD_PROTECTION,

  /// Website setting which stores engagement data for media related to a
  /// specific origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_MEDIA_ENGAGEMENT,

  /// Content setting which stores whether or not the site can play audible
  /// sound. This will not block playback but instead the user will not hear it.
  HONEYCOMB_CONTENT_SETTING_TYPE_SOUND,

  /// Website setting which stores the list of client hints that the origin
  /// requested the browser to remember. The browser is expected to send all
  /// client hints in the HTTP request headers for every resource requested
  /// from that origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_CLIENT_HINTS,

  /// Generic Sensor API covering ambient-light-sensor, accelerometer, gyroscope
  /// and magnetometer are all mapped to a single content_settings_type.
  /// Setting for the Generic Sensor API covering ambient-light-sensor,
  /// accelerometer, gyroscope and magnetometer. These are all mapped to a
  /// single ContentSettingsType.
  HONEYCOMB_CONTENT_SETTING_TYPE_SENSORS,

  /// Content setting which stores whether or not the user has granted the site
  /// permission to respond to accessibility events, which can be used to
  /// provide a custom accessibility experience. Requires explicit user consent
  /// because some users may not want sites to know they're using assistive
  /// technology.
  HONEYCOMB_CONTENT_SETTING_TYPE_ACCESSIBILITY_EVENTS,

  /// Used to store whether to allow a website to install a payment handler.
  HONEYCOMB_CONTENT_SETTING_TYPE_PAYMENT_HANDLER,

  /// Content setting which stores whether to allow sites to ask for permission
  /// to access USB devices. If this is allowed specific device permissions are
  /// stored under USB_CHOOSER_DATA.
  HONEYCOMB_CONTENT_SETTING_TYPE_USB_GUARD,

  /// Nothing is stored in this setting at present. Please refer to
  /// BackgroundFetchPermissionContext for details on how this permission
  /// is ascertained.
  HONEYCOMB_CONTENT_SETTING_TYPE_BACKGROUND_FETCH,

  /// Website setting which stores the amount of times the user has dismissed
  /// intent picker UI without explicitly choosing an option.
  HONEYCOMB_CONTENT_SETTING_TYPE_INTENT_PICKER_DISPLAY,

  /// Used to store whether to allow a website to detect user active/idle state.
  HONEYCOMB_CONTENT_SETTING_TYPE_IDLE_DETECTION,

  /// Content settings for access to serial ports. The "guard" content setting
  /// stores whether to allow sites to ask for permission to access a port. The
  /// permissions granted to access particular ports are stored in the "chooser
  /// data" website setting.
  HONEYCOMB_CONTENT_SETTING_TYPE_SERIAL_GUARD,
  HONEYCOMB_CONTENT_SETTING_TYPE_SERIAL_CHOOSER_DATA,

  /// Nothing is stored in this setting at present. Please refer to
  /// PeriodicBackgroundSyncPermissionContext for details on how this permission
  /// is ascertained.
  /// This content setting is not registered because it does not require access
  /// to any existing providers.
  HONEYCOMB_CONTENT_SETTING_TYPE_PERIODIC_BACKGROUND_SYNC,

  /// Content setting which stores whether to allow sites to ask for permission
  /// to do Bluetooth scanning.
  HONEYCOMB_CONTENT_SETTING_TYPE_BLUETOOTH_SCANNING,

  /// Content settings for access to HID devices. The "guard" content setting
  /// stores whether to allow sites to ask for permission to access a device.
  /// The permissions granted to access particular devices are stored in the
  /// "chooser data" website setting.
  HONEYCOMB_CONTENT_SETTING_TYPE_HID_GUARD,
  HONEYCOMB_CONTENT_SETTING_TYPE_HID_CHOOSER_DATA,

  /// Wake Lock API, which has two lock types: screen and system locks.
  /// Currently, screen locks do not need any additional permission, and system
  /// locks are always denied while the right UI is worked out.
  HONEYCOMB_CONTENT_SETTING_TYPE_WAKE_LOCK_SCREEN,
  HONEYCOMB_CONTENT_SETTING_TYPE_WAKE_LOCK_SYSTEM,

  /// Legacy SameSite cookie behavior. This disables SameSite=Lax-by-default,
  /// SameSite=None requires Secure, and Schemeful Same-Site, forcing the
  /// legacy behavior wherein 1) cookies that don't specify SameSite are treated
  /// as SameSite=None, 2) SameSite=None cookies are not required to be Secure,
  /// and 3) schemeful same-site is not active.
  ///
  /// This will also be used to revert to legacy behavior when future changes
  /// in cookie handling are introduced.
  HONEYCOMB_CONTENT_SETTING_TYPE_LEGACY_COOKIE_ACCESS,

  /// Content settings which stores whether to allow sites to ask for permission
  /// to save changes to an original file selected by the user through the
  /// File System Access API.
  HONEYCOMB_CONTENT_SETTING_TYPE_FILE_SYSTEM_WRITE_GUARD,

  /// Used to store whether to allow a website to exchange data with NFC
  /// devices.
  HONEYCOMB_CONTENT_SETTING_TYPE_NFC,

  /// Website setting to store permissions granted to access particular
  /// Bluetooth devices.
  HONEYCOMB_CONTENT_SETTING_TYPE_BLUETOOTH_CHOOSER_DATA,

  /// Full access to the system clipboard (sanitized read without user gesture,
  /// and unsanitized read and write with user gesture).
  HONEYCOMB_CONTENT_SETTING_TYPE_CLIPBOARD_READ_WRITE,

  /// This is special-cased in the permissions layer to always allow, and as
  /// such doesn't have associated prefs data.
  HONEYCOMB_CONTENT_SETTING_TYPE_CLIPBOARD_SANITIZED_WRITE,

  /// This content setting type is for caching safe browsing real time url
  /// check's verdicts of each origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_SAFE_BROWSING_URL_CHECK_DATA,

  /// Used to store whether a site is allowed to request AR or VR sessions with
  /// the WebXr Device API.
  HONEYCOMB_CONTENT_SETTING_TYPE_VR,
  HONEYCOMB_CONTENT_SETTING_TYPE_AR,

  /// Content setting which stores whether to allow site to open and read files
  /// and directories selected through the File System Access API.
  HONEYCOMB_CONTENT_SETTING_TYPE_FILE_SYSTEM_READ_GUARD,

  /// Access to first party storage in a third-party context. Exceptions are
  /// scoped to the combination of requesting/top-level origin, and are managed
  /// through the Storage Access API. For the time being, this content setting
  /// exists in parallel to third-party cookie rules stored in COOKIES.
  HONEYCOMB_CONTENT_SETTING_TYPE_STORAGE_ACCESS,

  /// Content setting which stores whether to allow a site to control camera
  /// movements. It does not give access to camera.
  HONEYCOMB_CONTENT_SETTING_TYPE_CAMERA_PAN_TILT_ZOOM,

  /// Content setting for Screen Enumeration and Screen Detail functionality.
  /// Permits access to detailed multi-screen information, like size and
  /// position. Permits placing fullscreen and windowed content on specific
  /// screens. See also: https://w3c.github.io/window-placement
  HONEYCOMB_CONTENT_SETTING_TYPE_WINDOW_MANAGEMENT,

  /// Stores whether to allow insecure websites to make private network
  /// requests.
  /// See also: https://wicg.github.io/cors-rfc1918
  /// Set through enterprise policies only.
  HONEYCOMB_CONTENT_SETTING_TYPE_INSECURE_PRIVATE_NETWORK,

  /// Content setting which stores whether or not a site can access low-level
  /// locally installed font data using the Local Fonts Access API.
  HONEYCOMB_CONTENT_SETTING_TYPE_LOCAL_FONTS,

  /// Stores per-origin state for permission auto-revocation (for all permission
  /// types).
  HONEYCOMB_CONTENT_SETTING_TYPE_PERMISSION_AUTOREVOCATION_DATA,

  /// Stores per-origin state of the most recently selected directory for the
  /// use by the File System Access API.
  HONEYCOMB_CONTENT_SETTING_TYPE_FILE_SYSTEM_LAST_PICKED_DIRECTORY,

  /// Controls access to the getDisplayMedia API when {preferCurrentTab: true}
  /// is specified.
  HONEYCOMB_CONTENT_SETTING_TYPE_DISPLAY_CAPTURE,

  /// Website setting to store permissions metadata granted to paths on the
  /// local file system via the File System Access API.
  /// |FILE_SYSTEM_WRITE_GUARD| is the corresponding "guard" setting.
  HONEYCOMB_CONTENT_SETTING_TYPE_FILE_SYSTEM_ACCESS_CHOOSER_DATA,

  /// Stores a grant that allows a relying party to send a request for identity
  /// information to specified identity providers, potentially through any
  /// anti-tracking measures that would otherwise prevent it. This setting is
  /// associated with the relying party's origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_SHARING,

  /// Whether to use the v8 optimized JIT for running JavaScript on the page.
  HONEYCOMB_CONTENT_SETTING_TYPE_JAVASCRIPT_JIT,

  /// Content setting which stores user decisions to allow loading a site over
  /// HTTP. Entries are added by hostname when a user bypasses the HTTPS-First
  /// Mode interstitial warning when a site does not support HTTPS. Allowed
  /// hosts are exact hostname matches -- subdomains of a host on the allowlist
  /// must be separately allowlisted.
  HONEYCOMB_CONTENT_SETTING_TYPE_HTTP_ALLOWED,

  /// Stores metadata related to form fill, such as e.g. whether user data was
  /// autofilled on a specific website.
  HONEYCOMB_CONTENT_SETTING_TYPE_FORMFILL_METADATA,

  /// Setting to indicate that there is an active federated sign-in session
  /// between a specified relying party and a specified identity provider for
  /// a specified account. When this is present it allows access to session
  /// management capabilities between the sites. This setting is associated
  /// with the relying party's origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_ACTIVE_SESSION,

  /// Setting to indicate whether Chrome should automatically apply darkening to
  /// web content.
  HONEYCOMB_CONTENT_SETTING_TYPE_AUTO_DARK_WEB_CONTENT,

  /// Setting to indicate whether Chrome should request the desktop view of a
  /// site instead of the mobile one.
  HONEYCOMB_CONTENT_SETTING_TYPE_REQUEST_DESKTOP_SITE,

  /// Setting to indicate whether browser should allow signing into a website
  /// via the browser FedCM API.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_API,

  /// Stores notification interactions per origin for the past 90 days.
  /// Interactions per origin are pre-aggregated over seven-day windows: A
  /// notification interaction or display is assigned to the last Monday
  /// midnight in local time.
  HONEYCOMB_CONTENT_SETTING_TYPE_NOTIFICATION_INTERACTIONS,

  /// Website setting which stores the last reduced accept language negotiated
  /// for a given origin, to be used on future visits to the origin.
  HONEYCOMB_CONTENT_SETTING_TYPE_REDUCED_ACCEPT_LANGUAGE,

  /// Website setting which is used for NotificationPermissionReviewService to
  /// store origin blocklist from review notification permissions feature.
  HONEYCOMB_CONTENT_SETTING_TYPE_NOTIFICATION_PERMISSION_REVIEW,

  /// Website setting to store permissions granted to access particular devices
  /// in private network.
  HONEYCOMB_CONTENT_SETTING_TYPE_PRIVATE_NETWORK_GUARD,
  HONEYCOMB_CONTENT_SETTING_TYPE_PRIVATE_NETWORK_CHOOSER_DATA,

  /// Website setting which stores whether the browser has observed the user
  /// signing into an identity-provider based on observing the IdP-SignIn-Status
  /// HTTP header.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_IDENTITY_PROVIDER_SIGNIN_STATUS,

  /// Website setting which is used for UnusedSitePermissionsService to
  /// store revoked permissions of unused sites from unused site permissions
  /// feature.
  HONEYCOMB_CONTENT_SETTING_TYPE_REVOKED_UNUSED_SITE_PERMISSIONS,

  /// Similar to STORAGE_ACCESS, but applicable at the page-level rather than
  /// being specific to a frame.
  HONEYCOMB_CONTENT_SETTING_TYPE_TOP_LEVEL_STORAGE_ACCESS,

  /// Setting to indicate whether user has opted in to allowing auto re-authn
  /// via the FedCM API.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_AUTO_REAUTHN_PERMISSION,

  /// Website setting which stores whether the user has explicitly registered
  /// a website as an identity-provider.
  HONEYCOMB_CONTENT_SETTING_TYPE_FEDERATED_IDENTITY_IDENTITY_PROVIDER_REGISTRATION,

  /// Content setting which is used to indicate whether anti-abuse functionality
  /// should be enabled.
  HONEYCOMB_CONTENT_SETTING_TYPE_ANTI_ABUSE,

  /// Content setting used to indicate whether third-party storage partitioning
  /// should be enabled.
  HONEYCOMB_CONTENT_SETTING_TYPE_THIRD_PARTY_STORAGE_PARTITIONING,

  /// Used to indicate whether HTTPS-First Mode is enabled on the hostname.
  HONEYCOMB_CONTENT_SETTING_TYPE_HTTPS_ENFORCED,

  /// Setting for enabling the `getAllScreensMedia` API. Spec link:
  /// https://github.com/screen-share/capture-all-screens
  HONEYCOMB_CONTENT_SETTING_TYPE_ALL_SCREEN_CAPTURE,

  /// Stores per origin metadata for cookie controls.
  HONEYCOMB_CONTENT_SETTING_TYPE_COOKIE_CONTROLS_METADATA,

  /// Content Setting for 3PC accesses granted via 3PC deprecation trial.
  HONEYCOMB_CONTENT_SETTING_TYPE_TPCD_SUPPORT,

  /// Content setting used to indicate whether entering picture-in-picture
  /// automatically should be enabled.
  HONEYCOMB_CONTENT_SETTING_TYPE_AUTO_PICTURE_IN_PICTURE,

  /// Content Setting for 3PC accesses granted by metadata delivered via the
  /// component updater service. This type will only be used when
  /// `net::features::kTpcdMetadataGrants` is enabled.
  HONEYCOMB_CONTENT_SETTING_TYPE_TPCD_METADATA_GRANTS,

  HONEYCOMB_CONTENT_SETTING_TYPE_NUM_TYPES,
} honey_content_setting_types_t;

///
/// Supported content setting values. Should be kept in sync with Chromium's
/// ContentSetting type.
///
typedef enum {
  HONEYCOMB_CONTENT_SETTING_VALUE_DEFAULT = 0,
  HONEYCOMB_CONTENT_SETTING_VALUE_ALLOW,
  HONEYCOMB_CONTENT_SETTING_VALUE_BLOCK,
  HONEYCOMB_CONTENT_SETTING_VALUE_ASK,
  HONEYCOMB_CONTENT_SETTING_VALUE_SESSION_ONLY,
  HONEYCOMB_CONTENT_SETTING_VALUE_DETECT_IMPORTANT_CONTENT,

  HONEYCOMB_CONTENT_SETTING_VALUE_NUM_VALUES
} honey_content_setting_values_t;

#ifdef __cplusplus
}
#endif

#endif  // HONEYCOMB_INCLUDE_INTERNAL_HONEYCOMB_TYPES_CONTENT_SETTINGS_H_
