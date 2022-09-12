#include "Map.h"

void Map::draw() const {
  DrawLineEx(Vector2{210, 0}, Vector2{210, 480}, 5.0, BLACK);
  DrawLineEx(Vector2{640 - 210, 0}, Vector2{640 - 210, 480}, 5.0, BLACK);
  DrawLineEx(Vector2{0, 150}, Vector2{640, 150}, 5.0, BLACK);
  DrawLineEx(Vector2{0, 480 - 150}, Vector2{640, 480 - 150}, 5.0, BLACK);
}

Map::Map() {}