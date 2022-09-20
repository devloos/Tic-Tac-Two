#include "Logic.h"

namespace Logic {
void start(const Sound &btnClickX, const Sound &btnClickO) {
  if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    return;
  }

  const int MX = GetMouseX();
  const int MY = GetMouseY();

  int i = 1;
  static int turn = 1;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      bool inRectangleArea = MX > 50 + (180 * col) && MX < 230 + (180 * col) &&
                             MY > 50 + (115 * row) && MY < 165 + (115 * row);
      if (inRectangleArea) {
        std::cout << "IN BOX GRID: " << i << "\n";
        PlaySound((turn % 2 == 0) ? btnClickO : btnClickX);
        turn++;
      }
      i++;
    }
  }
}
}  // namespace Logic