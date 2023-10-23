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
//
// ---------------------------------------------------------------------------
//
// This file was generated by the Honeycomb translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=9b523fbf312a8a0cb1c743a3c8aca7bc9cc22bbc$
//

#ifndef HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_APP_CAPI_H_
#define HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_APP_CAPI_H_
#pragma once

#include "include/capi/honey_base_capi.h"
#include "include/capi/honey_browser_process_handler_capi.h"
#include "include/capi/honey_command_line_capi.h"
#include "include/capi/honey_render_process_handler_capi.h"
#include "include/capi/honey_resource_bundle_handler_capi.h"
#include "include/capi/honey_scheme_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _honey_app_t;

///
/// Implement this structure to provide handler implementations. Methods will be
/// called by the process and/or thread indicated.
///
typedef struct _honey_app_t {
  ///
  /// Base structure.
  ///
  honey_base_ref_counted_t base;

  ///
  /// Provides an opportunity to view and/or modify command-line arguments
  /// before processing by Honeycomb and Chromium. The |process_type| value will be
  /// NULL for the browser process. Do not keep a reference to the
  /// honey_command_line_t object passed to this function. The
  /// honey_settings_t.command_line_args_disabled value can be used to start with
  /// an NULL command-line object. Any values specified in HoneycombSettings that
  /// equate to command-line arguments will be set before this function is
  /// called. Be cautious when using this function to modify command-line
  /// arguments for non-browser processes as this may result in undefined
  /// behavior including crashes.
  ///
  void(HONEYCOMB_CALLBACK* on_before_command_line_processing)(
      struct _honey_app_t* self,
      const honey_string_t* process_type,
      struct _honey_command_line_t* command_line);

  ///
  /// Provides an opportunity to register custom schemes. Do not keep a
  /// reference to the |registrar| object. This function is called on the main
  /// thread for each process and the registered schemes should be the same
  /// across all processes.
  ///
  void(HONEYCOMB_CALLBACK* on_register_custom_schemes)(
      struct _honey_app_t* self,
      struct _honey_scheme_registrar_t* registrar);

  ///
  /// Return the handler for resource bundle events. If
  /// honey_settings_t.pack_loading_disabled is true (1) a handler must be
  /// returned. If no handler is returned resources will be loaded from pack
  /// files. This function is called by the browser and render processes on
  /// multiple threads.
  ///
  struct _honey_resource_bundle_handler_t*(
      HONEYCOMB_CALLBACK* get_resource_bundle_handler)(struct _honey_app_t* self);

  ///
  /// Return the handler for functionality specific to the browser process. This
  /// function is called on multiple threads in the browser process.
  ///
  struct _honey_browser_process_handler_t*(
      HONEYCOMB_CALLBACK* get_browser_process_handler)(struct _honey_app_t* self);

  ///
  /// Return the handler for functionality specific to the render process. This
  /// function is called on the render process main thread.
  ///
  struct _honey_render_process_handler_t*(
      HONEYCOMB_CALLBACK* get_render_process_handler)(struct _honey_app_t* self);
} honey_app_t;

///
/// This function should be called from the application entry point function to
/// execute a secondary process. It can be used to run secondary processes from
/// the browser client executable (default behavior) or from a separate
/// executable specified by the honey_settings_t.browser_subprocess_path value. If
/// called for the browser process (identified by no "type" command-line value)
/// it will return immediately with a value of -1. If called for a recognized
/// secondary process it will block until the process should exit and then
/// return the process exit code. The |application| parameter may be NULL. The
/// |windows_sandbox_info| parameter is only used on Windows and may be NULL
/// (see honey_sandbox_win.h for details).
///
HONEYCOMB_EXPORT int honey_execute_process(const honey_main_args_t* args,
                                   honey_app_t* application,
                                   void* windows_sandbox_info);

///
/// This function should be called on the main application thread to initialize
/// the Honeycomb browser process. The |application| parameter may be NULL. A return
/// value of true (1) indicates that it succeeded and false (0) indicates that
/// it failed. The |windows_sandbox_info| parameter is only used on Windows and
/// may be NULL (see honey_sandbox_win.h for details).
///
HONEYCOMB_EXPORT int honey_initialize(const honey_main_args_t* args,
                              const struct _honey_settings_t* settings,
                              honey_app_t* application,
                              void* windows_sandbox_info);

///
/// This function should be called on the main application thread to shut down
/// the Honeycomb browser process before the application exits.
///
HONEYCOMB_EXPORT void honey_shutdown(void);

///
/// Perform a single iteration of Honeycomb message loop processing. This function is
/// provided for cases where the Honeycomb message loop must be integrated into an
/// existing application message loop. Use of this function is not recommended
/// for most users; use either the honey_run_message_loop() function or
/// honey_settings_t.multi_threaded_message_loop if possible. When using this
/// function care must be taken to balance performance against excessive CPU
/// usage. It is recommended to enable the honey_settings_t.external_message_pump
/// option when using this function so that
/// honey_browser_process_handler_t::on_schedule_message_pump_work() callbacks can
/// facilitate the scheduling process. This function should only be called on
/// the main application thread and only if honey_initialize() is called with a
/// honey_settings_t.multi_threaded_message_loop value of false (0). This function
/// will not block.
///
HONEYCOMB_EXPORT void honey_do_message_loop_work(void);

///
/// Run the Honeycomb message loop. Use this function instead of an application-
/// provided message loop to get the best balance between performance and CPU
/// usage. This function should only be called on the main application thread
/// and only if honey_initialize() is called with a
/// honey_settings_t.multi_threaded_message_loop value of false (0). This function
/// will block until a quit message is received by the system.
///
HONEYCOMB_EXPORT void honey_run_message_loop(void);

///
/// Quit the Honeycomb message loop that was started by calling
/// honey_run_message_loop(). This function should only be called on the main
/// application thread and only if honey_run_message_loop() was used.
///
HONEYCOMB_EXPORT void honey_quit_message_loop(void);

#ifdef __cplusplus
}
#endif

#endif  // HONEYCOMB_INCLUDE_CAPI_HONEYCOMB_APP_CAPI_H_
