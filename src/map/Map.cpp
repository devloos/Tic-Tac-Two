#include "Map.h"

Map::Grid::Grid() {}

void Map::Grid::draw() const {
  this->drawGrid();
  this->drawFilledTiles();
}

void Map::Grid::drawGrid() const {
  DrawLineEx(VLINE_INNER_START_POS, VLINE_INNER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(VLINE_OUTER_START_POS, VLINE_OUTER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_TOP_START_POS, HLINE_TOP_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_BOTTOM_START_POS, HLINE_BOTTOM_END_POS, LINE_THICKNESS, BLACK);
}
void Map::Grid::drawFilledTiles() const {
  for (int i = 1; i <= 9; i++) {
    LosRaylib::DrawModelO(
        TILES_MAP_COOR.at(static_cast<Tile>(i)).first,
        TILES_MAP_COOR.at(static_cast<Tile>(i)).second, RAYWHITE);
    LosRaylib::DrawModelX(
        TILES_MAP_COOR.at(static_cast<Tile>(i)).first,
        TILES_MAP_COOR.at(static_cast<Tile>(i)).second, 8.0, BLACK);
    //           if (tile is filled) {
    //     switch (who) {
    //       case X:
    //         LosRaylib::DrawModelX(
    //             TILES_MAP_COOR.at(static_cast<Tile>(i)).first,
    //             TILES_MAP_COOR.at(static_cast<Tile>(i)).second, 7.0, BLACK);
    //         break;
    //       case O:
    //         DrawCircleLines(
    //             TILES_MAP_COOR.at(static_cast<Tile>(i)).first,
    //             TILES_MAP_COOR.at(static_cast<Tile>(i)).second, 50, BLACK);
    //         break;
    //     }
    //   }
  }
}