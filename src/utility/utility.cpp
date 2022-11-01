#include "utility.h"

namespace Utility {
Exception::Exception(const std::string &msg) : msg_(msg) {}
}  // namespace Utility

namespace Raylib {
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

void DrawModelO(const float &centerX, const float &centerY, const Color &color) {
  DrawCircle(centerX, centerY, 50, BLACK);
  DrawCircle(centerX, centerY, 42, RAYWHITE);
}
}  // namespace Raylib