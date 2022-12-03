#include "logic.h"

namespace Logic {
void start(Map::Grid &grid, const std::vector<Sound> &soundFX) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gridMouseClick(grid, soundFX);
  }
  // TODO: Validate win
}

bool isMouseInTileArea(const int &MX, const int &MY, const int &row, const int &col) {
  return MX > 50 + (180 * col) && MX < 230 + (180 * col) && MY > 30 + (145 * row) &&
         MY < 165 + (145 * row);
}

void gridMouseClick(Map::Grid &grid, const std::vector<Sound> &soundFX) {
  const int MX = GetMouseX();
  const int MY = GetMouseY();

  static int turn = 1;

  Map::Tile** tiles = grid.getTiles();

  assert(tiles != nullptr);

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (isMouseInTileArea(MX, MY, row, col)) {
        if (tiles[row][col].isNotTaken()) {
          PlaySound((turn % 2 == 0) ? soundFX.at(1) : soundFX.at(0));
          tiles[row][col].setUser((turn % 2 == 0) ? 'O' : 'X');
          ++turn;
        }
      }
    }
  }
}
}  // namespace Logic