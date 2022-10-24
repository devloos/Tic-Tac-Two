#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <raylib.h>

#include <iostream>
#include <vector>

#include "../logic/logic.h"
#include "../map/map.h"
#include "../render/draw.h"
#include "../utility/utility.h"

#define EXIT_FAILED -1

class Tapp {
 public:
  // Constructors
  Tapp();
  ~Tapp();

  // Methods
  bool init();
  int exec();

 private:
  std::vector<Sound> soundFX_;
};

#endif  // APPLICATION_H_