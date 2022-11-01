#include "map.h"

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
  for (const auto &tile : tiles_) {
    switch (tile.getUser()) {
      case 'X': {
        Raylib::DrawModelX(tile.getCenterX(), tile.getCenterY(), LINE_THICKNESS, BLACK);
        break;
      }
      case 'O': {
        Raylib::DrawModelO(tile.getCenterX(), tile.getCenterY(), BLACK);
        break;
      }
      case NA: {
        break;
      }
    }
  }
}

std::array<Map::Tile, Map::GRID_SIZE> Map::Grid::getTiles() const {
  return tiles_;
}

void Map::Grid::setTiles(const std::array<Tile, Map::GRID_SIZE> &tiles) {
  tiles_ = tiles;
}

Map::Tile::Tile() {}
Map::Tile::Tile(const int &centerX, const int &centerY, const short int &index)
    : centerX_(centerX), centerY_(centerY), index_(index), user_(NA) {}

double Map::Tile::getCenterX() const {
  return centerX_;
}

double Map::Tile::getCenterY() const {
  return centerY_;
}

short int Map::Tile::getIndex() const {
  return index_;
}

char Map::Tile::getUser() const {
  return user_;
}

void Map::Tile::setUser(const char &user) {
  user_ = user;
}

bool Map::Tile::isNotTaken() const {
  return user_ == NA;
}