// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_BROWSER_UI_TRAY_ICON_COCOA_H_
#define ELECTRON_SHELL_BROWSER_UI_TRAY_ICON_COCOA_H_

#import <Cocoa/Cocoa.h>

#include <string>

#include "shell/browser/ui/tray_icon.h"

@class ElectronMenuController;
@class StatusItemView;

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace electron {

class TrayIconCocoa : public TrayIcon {
 public:
  TrayIconCocoa();
  ~TrayIconCocoa() override;

  void SetImage(const gfx::Image& image) override;
  void SetPressedImage(const gfx::Image& image) override;
  void SetToolTip(const std::string& tool_tip) override;
  void SetTitle(const std::string& title, const TitleOptions& options) override;
  std::string GetTitle() override;
  void SetIgnoreDoubleClickEvents(bool ignore) override;
  bool GetIgnoreDoubleClickEvents() override;
  void PopUpOnUI(ElectronMenuModel* menu_model);
  void PopUpContextMenu(const gfx::Point& pos,
                        raw_ptr<ElectronMenuModel>) override;
  void CloseContextMenu() override;
  void SetContextMenu(raw_ptr<ElectronMenuModel>) override;
  gfx::Rect GetBounds() override;

 private:
  // Electron custom view for NSStatusItem.
  StatusItemView* __strong status_item_view_;

  // Status menu shown when right-clicking the system icon.
  ElectronMenuController* __strong menu_;

  base::WeakPtrFactory<TrayIconCocoa> weak_factory_{this};
};

}  // namespace electron

#endif  // ELECTRON_SHELL_BROWSER_UI_TRAY_ICON_COCOA_H_
