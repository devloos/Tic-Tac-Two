#include "Application.h"

int main() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  SetTargetFPS(60);
  Map map;

  while (!WindowShouldClose()) {
    Draw::start(map);
    Logic::start();
  }
  return 0;
}
