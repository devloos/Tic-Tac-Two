#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <raylib.h>

#include <iostream>
#include <vector>

#include "../logic/logic.h"
#include "../map/map.h"
#include "../render/draw.h"
#include "../utility/utility.h"

class Tapp {
 public:
  /**
   * @brief Construct a new Tapp object
   *
   */
  Tapp();

  /**
   * @brief Destroy the Tapp object
   *
   */
  ~Tapp();

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

 private:
  bool initCore();
  bool initUtil();

 private:
  std::vector<Sound> soundFX_;
};

#endif  // APPLICATION_H_