#include "Application.h"

int main() {
  InitWindow(640, 480, "Tic Tac Toe");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  return 0;
}
