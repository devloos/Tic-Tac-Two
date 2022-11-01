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
  for (const auto &tile : filledTiles_) {
    switch (tile.second) {
      case 'X': {
        Raylib::DrawModelX(
            TILES_MAP_COOR.at(tile.first).first, TILES_MAP_COOR.at(tile.first).second,
            8.0, BLACK);
        break;
      }
      case 'O': {
        Raylib::DrawModelO(
            TILES_MAP_COOR.at(tile.first).first, TILES_MAP_COOR.at(tile.first).second,
            RAYWHITE);
        break;
      }
    }
  }
}

bool Map::Grid::isTileAvailable(const Tile &tile) const {
  auto result = std::find(availableTiles_.begin(), availableTiles_.end(), tile);
  return (result != std::end(availableTiles_)) ? true : false;
}

void Map::Grid::setFilledTile(const Tile &tile, const char user) {
  std::vector<Tile>::iterator it =
      std::find(availableTiles_.begin(), availableTiles_.end(), tile);

  if (it == std::end(availableTiles_)) {
    throw Utility::Exception("Setting filed tile that is already taken.");
  }

  availableTiles_.erase(it);
  filledTiles_.push_back(std::make_pair(tile, user));
}

Map::Tile &Map::operator++(Map::Tile &tile) {
  int i = static_cast<int>(tile);
  tile = static_cast<Map::Tile>(++i);
  return tile;
}

Map::Tile &Map::operator--(Map::Tile &tile) {
  int i = static_cast<int>(tile);
  tile = static_cast<Map::Tile>(++i);
  return tile;
}