#ifndef MAP_H_
#define MAP_H_
#include <raylib.h>

#include "../utility/Utility.h"

static const float LINE_THICKNESS = 5.0;
static const float VLINE_X_POS = 230;
static const float HLINE_Y_POS = 165;
static const float BOUNDARY = 50;

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
static const Vector2 HLINE_TOP_START_POS = Vector2{BOUNDARY, HLINE_Y_POS};
static const Vector2 HLINE_TOP_END_POS =
    Vector2{Utility::WIN_WIDTH - BOUNDARY, HLINE_Y_POS};

// Horizontal bottom line start and end positions
static const Vector2 HLINE_BOTTOM_START_POS =
    Vector2{BOUNDARY, Utility::WIN_HEIGHT - HLINE_Y_POS};
static const Vector2 HLINE_BOTTOM_END_POS =
    Vector2{Utility::WIN_WIDTH - BOUNDARY, Utility::WIN_HEIGHT - HLINE_Y_POS};

class Map {
 public:
  Map();
  void draw() const;
};

#endif  // MAP_H_