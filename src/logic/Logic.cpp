#include "Logic.h"

namespace Logic {
void start(const Sound &btnClickX, const Sound &btnClickO) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gridMouseClick(btnClickX, btnClickO);
  }
}

void gridMouseClick(const Sound &btnClickX, const Sound &btnClickO) {
  const int MX = GetMouseX();
  const int MY = GetMouseY();

  static int turn = 1;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      bool inRectangleArea = MX > 50 + (180 * col) && MX < 230 + (180 * col) &&
                             MY > 30 + (145 * row) && MY < 165 + (145 * row);
      if (inRectangleArea) {
        PlaySound((turn % 2 == 0) ? btnClickO : btnClickX);
        turn++;
      }
    }
  }
}
}  // namespace Logic