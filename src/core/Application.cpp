#include "Application.h"

int main() {
  InitWindow(640, 480, "Tic Tac TWO");
  Map map;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    map.draw();
    EndDrawing();
  }
  return 0;
}
