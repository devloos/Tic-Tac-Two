#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include "../map/map.h"

namespace Logic {
void start(bool &gameover, Map::Grid &grid, const std::vector<Sound> &soundFX);
void gridMouseClick(Map::Grid &grid, const std::vector<Sound> &soundFX);
bool winnerExist(Map::Grid &grid);
}  // namespace Logic

#endif  // LOGIC_H_