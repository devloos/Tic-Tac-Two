#include "logic.h"

namespace Logic {
void start(bool &gameover, Map::Grid &grid, const std::vector<Sound> &soundFX) {
  if (winnerExist(grid)) {
    gameover = true;
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gridMouseClick(grid, soundFX);
  }
}

bool winnerExist(Map::Grid &grid) {
  Map::Tile** tiles = grid.getTiles();

  assert(tiles != nullptr);

  auto isWinner = [](const char &pos1, const char &pos2, const char &pos3) {
    if (pos1 == Map::NA || pos2 == Map::NA || pos3 == Map::NA) {
      return false;
    }

    if (pos1 == pos2 && pos2 == pos3) {
      return true;
    }

    return false;
  };

  // Row Check
  for (int row = 0; row < Map::GRID_SIZE; row++) {
    if (isWinner(
            tiles[row][0].getUser(), tiles[row][1].getUser(), tiles[row][2].getUser())) {
      return true;
    }
  }

  // Col Check
  for (int col = 0; col < Map::GRID_SIZE; col++) {
    if (isWinner(
            tiles[0][col].getUser(), tiles[1][col].getUser(), tiles[2][col].getUser())) {
      return true;
    }
  }

  // Diagonal check
  if (isWinner(tiles[0][0].getUser(), tiles[1][1].getUser(), tiles[2][2].getUser())) {
    return true;
  }

  // Diagonal check
  if (isWinner(tiles[0][2].getUser(), tiles[1][1].getUser(), tiles[2][0].getUser())) {
    return true;
  }

  return false;
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