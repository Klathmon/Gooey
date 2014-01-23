// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "gooey/gooey_handler.h"

#include <string>
#include <windows.h>

#include "gooey/util.h"
#include "include/cef_browser.h"

void GooeyHandler::OnTitleChange(CefRefPtr<CefBrowser> browser,
                                  const CefString& title) {
  REQUIRE_UI_THREAD();

  CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
  SetWindowText(hwnd, std::wstring(title).c_str());
}
