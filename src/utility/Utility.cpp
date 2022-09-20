#include "Utility.h"

namespace LosRaylib {
void DrawModelX(
    const float &centerX, const float &centerY, const float &thickness,
    const Color &color) {
  DrawLineEx(
      Vector2{centerX, centerY}, Vector2{centerX + 40, centerY + 40}, thickness, color);
  DrawLineEx(
      Vector2{centerX, centerY}, Vector2{centerX - 40, centerY - 40}, thickness, color);
  DrawLineEx(
      Vector2{centerX, centerY}, Vector2{centerX + 40, centerY - 40}, thickness, color);
  DrawLineEx(
      Vector2{centerX, centerY}, Vector2{centerX - 40, centerY + 40}, thickness, color);
}
}  // namespace LosRaylib