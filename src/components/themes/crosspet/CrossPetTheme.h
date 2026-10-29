#pragma once

#include "components/themes/lyra/LyraTheme.h"

// CrossPet theme metrics — minimal header, generous list rows, card-first layout
namespace CrossPetMetrics {
constexpr ThemeMetrics values = {.batteryWidth = StatusBarMetrics::batteryWidth,
                                 .batteryHeight = StatusBarMetrics::batteryHeight,
                                 .topPadding = 5,
                                 .batteryBarHeight = 20,
                                 .headerHeight = 44,
                                 .verticalSpacing = 12,
                                 .previewPadding = 12,
                                 .previewHeightPercent = 30,
                                 .contentSidePadding = 14,
                                 .listRowHeight = 44,
                                 .listWithSubtitleRowHeight = 60,
                                 .listRowGap = 0,
                                 .listRowRadius = 6,
                                 .listInset = 20,
                                 .listSidePadding = 8,
                                 .listSelectionStyle = 1,
                                 .listScrollWidth = 4,
                                 .listScrollSide = 0,
                                 .listTitleBold = false,
                                 .headerSidePadding = 18,
                                 .headerUnderlineSize = 3,
                                 .headerTitleAlign = 0,
                                 .headerBatterySide = 0,
                                 .headerBatteryDetached = true,
                                 .menuRowHeight = 56,
                                 .menuSpacing = 8,
                                 .tabSpacing = 8,
                                 .tabBarHeight = 36,
                                 .tabBarAppearance = ThemeTabBarAppearance::Pill,
                                 .scrollBarWidth = 4,
                                 .scrollBarRightOffset = 5,
                                 .homeTopPadding = 56,
                                 .homeCoverHeight = 226,
                                 .homeCoverTileHeight = 242,
                                 .homeRecentBooksCount = 1,
                                 .homeContinueReadingInMenu = false,
                                 .homeMenuTopOffset = 16,
                                 .buttonHintsHeight = 40,
                                 .sideButtonHintsWidth = 30,
                                 .progressBarHeight = 8,
                                 .progressBarMarginTop = 1,
                                 .statusBarHorizontalMargin = 5,
                                 .statusBarVerticalMargin = 19};
}

// CrossPet design language: card-first, soft selection (LightGray), thin headers,
// geometric button hints, rounded popups. Inherits LyraTheme and overrides visuals.
class CrossPetTheme : public LyraTheme {
 public:
  void drawHeader(const GfxRenderer& renderer, Rect rect, const char* title,
                  const char* subtitle = nullptr, bool readerContext = false,
                  bool showStatus = true) const override;
  void drawSubHeader(const GfxRenderer& renderer, Rect rect, const char* label,
                     const char* rightLabel = nullptr) const override;
  void drawTabBar(const GfxRenderer& renderer, Rect rect, const std::vector<TabInfo>& tabs,
                  bool selected) const override;
  void drawList(const GfxRenderer& renderer, Rect rect, int itemCount, int selectedIndex,
                const std::function<std::string(int index)>& rowTitle,
                const std::function<std::string(int index)>& rowSubtitle = nullptr,
                const std::function<UIIcon(int index)>& rowIcon = nullptr,
                const std::function<std::string(int index)>& rowValue = nullptr,
                bool highlightValue = false,
                const std::function<bool(int index)>& rowDimmed = nullptr,
                const std::function<bool(int index)>& isHeader = nullptr,
                int rowHeightScale = 1, bool showSelection = true) const override;
  void drawButtonMenu(GfxRenderer& renderer, Rect rect, int buttonCount, int selectedIndex,
                      const std::function<const char*(int index)>& buttonLabel,
                      const std::function<UIIcon(int index)>& rowIcon) const override;
  void drawButtonHints(GfxRenderer& renderer, const char* btn1, const char* btn2, const char* btn3,
                       const char* btn4, bool allowInvertedText = false) const override;
  Rect drawPopup(const GfxRenderer& renderer, const char* message, bool preserveBackdrop = false) const override;
  // Two-button confirm dialog: white card, 1px border, title + body + Cancel/Confirm
  virtual void drawConfirmDialog(const GfxRenderer& renderer, const char* title,
                                 const char* body, const char* cancelLabel,
                                 const char* confirmLabel, bool confirmSelected) const;
};
