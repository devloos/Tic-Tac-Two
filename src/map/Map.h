#ifndef MAP_H_
#define MAP_H_
#include <raylib.h>

#include <unordered_map>
#include <utility>
#include <vector>

#include "../utility/Utility.h"

static const float LINE_THICKNESS = 8.0;
static const float VLINE_X_POS = 230;
static const float HLINE_Y_POS = 165;
static const float BOUNDARY = 30;

// Handles vertical inner line start and end positions
static const Vector2 VLINE_INNER_START_POS = Vector2{VLINE_X_POS, BOUNDARY};
static const Vector2 VLINE_INNER_END_POS =
    Vector2{VLINE_X_POS, Utility::WIN_HEIGHT - BOUNDARY};

// Handles vertical outer line start and end positions
static const Vector2 VLINE_OUTER_START_POS =
    Vector2{Utility::WIN_WIDTH - VLINE_X_POS, BOUNDARY};
static const Vector2 VLINE_OUTER_END_POS =
    Vector2{Utility::WIN_WIDTH - VLINE_X_POS, Utility::WIN_HEIGHT - BOUNDARY};

// Horizontal top line start and end positions
static const Vector2 HLINE_TOP_START_POS = Vector2{BOUNDARY + 20, HLINE_Y_POS};
static const Vector2 HLINE_TOP_END_POS =
    Vector2{Utility::WIN_WIDTH - BOUNDARY - 20, HLINE_Y_POS};

// Horizontal bottom line start and end positions
static const Vector2 HLINE_BOTTOM_START_POS =
    Vector2{BOUNDARY + 20, Utility::WIN_HEIGHT - HLINE_Y_POS};
static const Vector2 HLINE_BOTTOM_END_POS =
    Vector2{Utility::WIN_WIDTH - BOUNDARY - 20, Utility::WIN_HEIGHT - HLINE_Y_POS};

namespace Map {
enum struct Tile { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
const std::unordered_map<Tile, std::pair<double, double>> TILES_MAP_COOR = {
    {Tile::ONE, {140, 100}},   {Tile::TWO, {320, 100}},   {Tile::THREE, {500, 100.0}},
    {Tile::FOUR, {140, 240}},  {Tile::FIVE, {320, 240}},  {Tile::SIX, {500, 240}},
    {Tile::SEVEN, {140, 380}}, {Tile::EIGHT, {320, 380}}, {Tile::NINE, {500, 380}}};

class Grid {
 public:
  Grid();
  void draw() const;

  bool isTileAvailable(const Tile &tile) const;

 private:
  void drawGrid() const;
  void drawFilledTiles() const;
  std::vector<Tile> availableTiles_;
};

}  // namespace Map

#endif  // MAP_H_