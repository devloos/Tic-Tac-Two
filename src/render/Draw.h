#ifndef DRAW_H_
#define DRAW_H_
#include <raylib.h>

#include "../map/Map.h"

namespace Draw {
void start(const Map::Grid &grid);
}

#endif  // DRAW_H_