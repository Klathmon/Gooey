// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "gooey/gooey_app.h"

#include <string>

#include "gooey/gooey_handler.h"
#include "gooey/util.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"

GooeyApp::GooeyApp() {
}

void GooeyApp::OnContextInitialized() {
  REQUIRE_UI_THREAD();

  // Information used when creating the native window.
  CefWindowInfo window_info;

#if defined(OS_WIN)
  // On Windows we need to specify certain flags that will be passed to
  // CreateWindowEx().
  window_info.SetAsPopup(NULL, "gooey");
#endif

  // SimpleHandler implements browser-level callbacks.
  CefRefPtr<GooeyHandler> handler(new GooeyHandler());

  // Specify CEF browser settings here.
  CefBrowserSettings browser_settings;

  std::string url;

  // Check if a "--url=" value was provided via the command-line. If so, use
  // that instead of the default URL.
  CefRefPtr<CefCommandLine> command_line =
      CefCommandLine::GetGlobalCommandLine();
  url = command_line->GetSwitchValue("url");
  if (url.empty())
    url = "http://localhost:8532/index.php";

  // Create the first browser window.
  CefBrowserHost::CreateBrowserSync(window_info, handler.get(), url,
                                    browser_settings, NULL);
}
