#include "application.h"

Tapp::Tapp() {}

Tapp::~Tapp() {
  for (const auto &sound : soundFX_) {
    UnloadSound(sound);
  }
}

bool Tapp::init() {
  InitWindow(Utility::WIN_WIDTH, Utility::WIN_HEIGHT, "Tic Tac TWO");
  InitAudioDevice();
  if (!IsWindowReady() || !IsAudioDeviceReady()) {
    return false;
  }

  soundFX_.push_back(LoadSound("../assets/audio/X-Mode.mp3"));
  soundFX_.push_back(LoadSound("../assets/audio/Big-O.mp3"));

  SetTargetFPS(60);
  return true;
}

int Tapp::exec() {
  Map::Grid grid;

  while (!WindowShouldClose()) {
    if (!gameOver_) {
      Draw::start(grid);
      Logic::start(gameOver_, grid, soundFX_);
    } else {
      Draw::restart(grid);
      Logic::restart();
    }
  }

  return 0;
}

int main() {
  Tapp app;
  if (!app.init()) {
    return EXIT_FAILED;
  }
  return app.exec();
}