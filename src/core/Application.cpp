#include "Application.h"

Tapp::Tapp() {}

bool Tapp::init() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  if (!IsWindowReady()) return false;
  InitAudioDevice();
  if (!IsAudioDeviceReady()) return false;
  SetTargetFPS(60);
  return true;
}

int Tapp::exec() {
  Map map;
  Sound btnClickX = LoadSound("../assets/audio/X-Mode.mp3");
  Sound btnClickO = LoadSound("../assets/audio/Big-O.mp3");

  while (!WindowShouldClose()) {
    Draw::start(map);
    Logic::start(btnClickX, btnClickO);
  }

  UnloadSound(btnClickX);
  UnloadSound(btnClickO);
  return 0;
}
