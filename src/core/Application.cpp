#include "Application.h"

Tapp::Tapp() {}

Tapp::~Tapp() {
  for (const auto &sound : soundFX_) {
    UnloadSound(sound);
  }
}

bool Tapp::init() {
  if (!initCore() || !initUtil()) {
    return false;
  }
  SetTargetFPS(60);
  return true;
}

int Tapp::exec() {
  Map::Grid grid;

  while (!WindowShouldClose()) {
    Draw::start(grid);
    Logic::start(soundFX_);
  }

  return 0;
}

bool Tapp::initCore() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  InitAudioDevice();
  if (!IsWindowReady() || !IsAudioDeviceReady()) {
    return false;
  }
  return true;
}

bool Tapp::initUtil() {
  soundFX_.push_back(LoadSound("../assets/audio/X-Mode.mp3"));
  soundFX_.push_back(LoadSound("../assets/audio/Big-O.mp3"));
  return true;
}