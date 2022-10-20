#include "draw.h"

namespace Draw {
void start(const Map::Grid &grid) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  grid.draw();
  EndDrawing();
}
}  // namespace Draw