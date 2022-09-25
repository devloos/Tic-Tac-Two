#include "Logic.h"

namespace Logic {
void start(const std::vector<Sound> &soundFX) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gridMouseClick(soundFX);
  }
}

void gridMouseClick(const std::vector<Sound> &soundFX) {
  const int MX = GetMouseX();
  const int MY = GetMouseY();

  static int turn = 1;
  int tile = 0;
  bool inTileArea = false;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      inTileArea = MX > 50 + (180 * col) && MX < 230 + (180 * col) &&
                   MY > 30 + (145 * row) && MY < 165 + (145 * row);
      if (inTileArea) {
        PlaySound((turn % 2 == 0) ? soundFX.at(1) : soundFX.at(0));
        turn++;
      }
    }
    tile++;
  }
}
}  // namespace Logic