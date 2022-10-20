#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include <iostream>
#include <vector>

#include "../map/map.h"

namespace Logic {
void start(Map::Grid &grid, const std::vector<Sound> &soundFX);
void gridMouseClick(Map::Grid &grid, const std::vector<Sound> &soundFX);
}  // namespace Logic

#endif  // LOGIC_H_