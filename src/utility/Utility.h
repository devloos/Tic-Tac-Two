#ifndef UTILITY_H_
#define UTILITY_H_
#include <raylib.h>

namespace Utility {
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;
}  // namespace Utility

namespace Raylib {
/**
 * @brief
 *
 * @param centerX
 * @param centerY
 * @param thickness
 * @param color
 */
void DrawModelX(
    const float &centerX, const float &centerY, const float &thickness,
    const Color &color);
void DrawModelO(const float &centerX, const float &centerY, const Color &color);
}  // namespace Raylib

#endif  // UTILITY_H_