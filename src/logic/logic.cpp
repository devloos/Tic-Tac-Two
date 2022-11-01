#include "logic.h"

namespace Logic {
void start(Map::Grid &grid, const std::vector<Sound> &soundFX) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gridMouseClick(grid, soundFX);
  }
  // TODO: Validate win
}

void gridMouseClick(Map::Grid &grid, const std::vector<Sound> &soundFX) {
  const int MX = GetMouseX();
  const int MY = GetMouseY();

  static int turn = 1;

  int i = 0;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      bool inTileArea = MX > 50 + (180 * col) && MX < 230 + (180 * col) &&
                        MY > 30 + (145 * row) && MY < 165 + (145 * row);
      if (inTileArea) {
        if (Map::tiles[i].notTaken()) {
          PlaySound((turn % 2 == 0) ? soundFX.at(1) : soundFX.at(0));
          Map::tiles[i].setUser((turn % 2 == 0) ? 'O' : 'X');
          std::cout << "USER: " << Map::tiles[i].getUser() << "\n";
          std::cout << "CENTER X: " << Map::tiles[i].getCenterX() << "\n";
          std::cout << "CENTER Y: " << Map::tiles[i].getCenterY() << "\n";
          ++turn;
        }
      }
      ++i;
    }
    ++i;
  }
}
}  // namespace Logic