#ifndef MAP_H_
#define MAP_H_
#include <raylib.h>

#include <array>
#include <iostream>
#include <utility>
#include <vector>

#include "../utility/utility.h"

static const float LINE_THICKNESS = 8.0;

// Handles vertical inner line start and end positions
static const Vector2 VLINE_INNER_START_POS = Vector2{230, 30};
static const Vector2 VLINE_INNER_END_POS = Vector2{230, Utility::WIN_HEIGHT - 30};

// Handles vertical outer line start and end positions
static const Vector2 VLINE_OUTER_START_POS = Vector2{Utility::WIN_WIDTH - 230, 30};
static const Vector2 VLINE_OUTER_END_POS =
    Vector2{Utility::WIN_WIDTH - 230, Utility::WIN_HEIGHT - 30};

// Horizontal top line start and end positions
static const Vector2 HLINE_TOP_START_POS = Vector2{50, 165};
static const Vector2 HLINE_TOP_END_POS = Vector2{Utility::WIN_WIDTH - 50, 165};

// Horizontal bottom line start and end positions
static const Vector2 HLINE_BOTTOM_START_POS = Vector2{50, Utility::WIN_HEIGHT - 165};
static const Vector2 HLINE_BOTTOM_END_POS =
    Vector2{Utility::WIN_WIDTH - 50, Utility::WIN_HEIGHT - 165};

namespace Map {
class Tile {
 private:
  double centerX_ = 0;
  double centerY_ = 0;
  short int index_ = 0;
  char user_ = 'N';

 public:
  Tile();
  Tile(const int &centerX, const int &centerY, const short int &index);

 public:
  double getCenterX() const;
  double getCenterY() const;
  short int getIndex() const;

  char getUser() const;
  void setUser(const char &user);

 public:
  bool notTaken() const;
};

// Center coords for each tile
static std::array<Tile, 9> tiles = {
    Tile(140.0f, 100.0f, 1), Tile(320.0f, 100.0f, 2), Tile(500.0f, 100.0f, 3),
    Tile(140.0f, 240.0f, 4), Tile(320.0f, 240.0f, 5), Tile(500.0f, 240.0f, 6),
    Tile(140.0f, 380.0f, 7), Tile(320.0f, 380.0f, 8), Tile(500.0f, 380.0f, 9)};

class Grid {
 public:
  Grid();
  void draw() const;

 private:
  void drawGrid() const;
  void drawFilledTiles() const;
};
}  // namespace Map

#endif  // MAP_H_