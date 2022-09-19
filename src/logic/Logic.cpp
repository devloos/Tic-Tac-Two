#include "Logic.h"

namespace Logic {
void start() {
  if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
    return;
  }

  const int MX = GetMouseX();
  const int MY = GetMouseY();

  int i = 1;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      bool inRectangleArea = MX > 50 + (180 * col) && MX < 230 + (180 * col) &&
                             MY > 50 + (115 * row) && MY < 165 + (115 * row);
      if (inRectangleArea) {
        std::cout << "IN BOX GRID: " << i << "\n";
      }
      i++;
    }
  }
}
}  // namespace Logic