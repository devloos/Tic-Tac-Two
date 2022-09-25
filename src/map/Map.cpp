#include "Map.h"

Map::Grid::Grid() {
  for (int tile = 1; tile <= 9; tile++) {
    tileAvailability_.emplace(
        static_cast<Tile>(tile), std::make_pair<bool, char>(true, 'N'));
  }
}

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
  for (int tile = 1; tile <= 9; tile++) {
    Raylib::DrawModelO(
        TILES_MAP_COOR.at(static_cast<Tile>(tile)).first,
        TILES_MAP_COOR.at(static_cast<Tile>(tile)).second, RAYWHITE);
    Raylib::DrawModelX(
        TILES_MAP_COOR.at(static_cast<Tile>(tile)).first,
        TILES_MAP_COOR.at(static_cast<Tile>(tile)).second, 8.0, BLACK);
    //           if (tile is filled) {
    //     switch (who) {
    //       case X:
    //         Raylib::DrawModelX(
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