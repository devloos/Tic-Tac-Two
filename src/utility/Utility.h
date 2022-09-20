#ifndef UTILITY_H_
#define UTILITY_H_
#include <raylib.h>

namespace Utility {
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;
}  // namespace Utility

namespace LosRaylib {
void DrawModelX(
    const float &centerX, const float &centerY, const float &thickness,
    const Color &color);
}  // namespace LosRaylib

#endif  // UTILITY_H_