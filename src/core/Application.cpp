#include "Application.h"

int main() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  Map map;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    map.draw();
    EndDrawing();
  }
  return 0;
}
