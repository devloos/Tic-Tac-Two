#ifndef MAP_H_
#define MAP_H_
#include <raylib.h>

#include <array>
#include <iostream>
#include <utility>
#include <vector>

#include "../utility/utility.h"

const float LINE_THICKNESS = 8.0;

// Handles vertical inner line start and end positions
const Vector2 VLINE_INNER_START_POS = Vector2{230, 30};
const Vector2 VLINE_INNER_END_POS = Vector2{230, Utility::WIN_HEIGHT - 30};

// Handles vertical outer line start and end positions
const Vector2 VLINE_OUTER_START_POS = Vector2{Utility::WIN_WIDTH - 230, 30};
const Vector2 VLINE_OUTER_END_POS =
    Vector2{Utility::WIN_WIDTH - 230, Utility::WIN_HEIGHT - 30};

// Horizontal top line start and end positions
const Vector2 HLINE_TOP_START_POS = Vector2{50, 165};
const Vector2 HLINE_TOP_END_POS = Vector2{Utility::WIN_WIDTH - 50, 165};

// Horizontal bottom line start and end positions
const Vector2 HLINE_BOTTOM_START_POS = Vector2{50, Utility::WIN_HEIGHT - 165};
const Vector2 HLINE_BOTTOM_END_POS =
    Vector2{Utility::WIN_WIDTH - 50, Utility::WIN_HEIGHT - 165};

namespace Map {
const short int GRID_SIZE = 3;
const char NA = 'N';

class Tile {
 public:
  Tile();
  Tile(const int &centerX, const int &centerY);

 public:
  double getCenterX() const;
  double getCenterY() const;

  char getUser() const;
  void setUser(const char &user);

 public:
  bool isNotTaken() const;
  void reset() noexcept;

 private:
  double centerX_ = 0.0;
  double centerY_ = 0.0;
  char user_ = NA;
};

class Grid {
 public:
  Grid();
  ~Grid() noexcept;

 public:
  Tile** getTiles();

 public:
  void draw() const;
  void clearBoard() noexcept;

 private:
  void drawGrid() const;
  void drawFilledTiles() const;

 private:
  Grid(const Grid &other) = delete;
  Grid(Grid &&other) = delete;
  Grid &operator=(const Grid &other) = delete;
  Grid &operator=(Grid &&other) = delete;

 private:
  Tile** tiles_ = nullptr;
};
}  // namespace Map

#endif  // MAP_H_