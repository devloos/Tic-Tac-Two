#include "Application.h"

int main() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  InitAudioDevice();
  SetTargetFPS(60);
  Map map;
  Sound btnClickX = LoadSound("../assets/audio/X-Mode.mp3");
  Sound btnClickO = LoadSound("../assets/audio/Big-O.mp3");

  while (!WindowShouldClose()) {
    Draw::start(map);
    Logic::start(btnClickX, btnClickO);
  }

  UnloadSound(btnClickX);
  return 0;
}
