#include "map.h"

namespace Map {
Grid::Grid() {
  tiles_ = new Tile*[GRID_SIZE];
  tiles_[0] = new Tile[GRID_SIZE]{
      Tile(140.0f, 100.0f), Tile(320.0f, 100.0f), Tile(500.0f, 100.0f)};
  tiles_[1] = new Tile[GRID_SIZE]{
      Tile(140.0f, 240.0f), Tile(320.0f, 240.0f), Tile(500.0f, 240.0f)};
  tiles_[2] = new Tile[GRID_SIZE]{
      Tile(140.0f, 380.0f), Tile(320.0f, 380.0f), Tile(500.0f, 380.0f)};
}

Grid::~Grid() noexcept {
  for (int i = 0; i < GRID_SIZE; i++) {
    delete[] tiles_[i];
  }
  delete[] tiles_;

  tiles_ = nullptr;
};

void Grid::draw() const {
  this->drawGrid();
  this->drawFilledTiles();
}

void Grid::drawGrid() const {
  DrawLineEx(VLINE_INNER_START_POS, VLINE_INNER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(VLINE_OUTER_START_POS, VLINE_OUTER_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_TOP_START_POS, HLINE_TOP_END_POS, LINE_THICKNESS, BLACK);
  DrawLineEx(HLINE_BOTTOM_START_POS, HLINE_BOTTOM_END_POS, LINE_THICKNESS, BLACK);
}

void Grid::drawFilledTiles() const {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      switch (tiles_[row][col].getUser()) {
        case 'X': {
          Raylib::DrawModelX(
              tiles_[row][col].getCenterX(), tiles_[row][col].getCenterY(),
              LINE_THICKNESS, BLACK);
          break;
        }
        case 'O': {
          Raylib::DrawModelO(
              tiles_[row][col].getCenterX(), tiles_[row][col].getCenterY(), BLACK);
          break;
        }
        case NA: {
          break;
        }
      }
    }
  }
}

void Grid::clearBoard() noexcept {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      tiles_[row][col].reset();
    }
  }
}

Tile** Grid::getTiles() {
  return tiles_;
}

Tile::Tile() {}

Tile::Tile(const int &centerX, const int &centerY)
    : centerX_(centerX), centerY_(centerY), user_(NA) {}

double Tile::getCenterX() const {
  return centerX_;
}

double Tile::getCenterY() const {
  return centerY_;
}

char Tile::getUser() const {
  return user_;
}

void Tile::setUser(const char &user) {
  user_ = user;
}

bool Tile::isNotTaken() const {
  return user_ == NA;
}

void Tile::reset() noexcept {
  user_ = NA;
}
}  // namespace Map