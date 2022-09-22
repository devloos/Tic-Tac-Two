#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <raylib.h>

#include <iostream>

#include "../logic/Logic.h"
#include "../map/Map.h"
#include "../render/Draw.h"
#include "../utility/Utility.h"

class Tapp {
 public:
  /**
   * @brief Construct a new Tapp object
   *
   */
  Tapp();

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool init();

  /**
   * @brief
   *
   * @return int
   */
  int exec();
};

#endif  // APPLICATION_H_
