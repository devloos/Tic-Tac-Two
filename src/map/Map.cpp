#include "Map.h"

void Map::draw() const {
  this->drawGrid();
  this->drawFilledTiles();
}

Map::Map() {}

void Map::drawGrid() const {
  DrawLineEx(VLINE_INNER_START_POS, VLINE_INNER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(VLINE_OUTER_START_POS, VLINE_OUTER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_TOP_START_POS, HLINE_TOP_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_BOTTOM_START_POS, HLINE_BOTTOM_END_POS, LINE_THICKNESS, BLACK);
}
void Map::drawFilledTiles() const {
  DrawCircleLines(640 / 2, 480 / 2, 50, BLACK);
  LosRaylib::DrawModelX(640 / 2, 480 / 2, 7.0, BLACK);
}