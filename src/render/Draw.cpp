#include "Draw.h"

namespace Draw {
void start(const Map &map) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  map.draw();
  EndDrawing();
}
}  // namespace Draw