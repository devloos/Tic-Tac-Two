#ifndef UTILITY_H_
#define UTILITY_H_
#include <raylib.h>

#include <string>

namespace Utility {
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

class Exception {
 public:
  Exception(const std::string &msg);

 private:
  std::string msg_;
};
}  // namespace Utility

namespace Raylib {
void DrawModelX(
    const float &centerX, const float &centerY, const float &thickness,
    const Color &color);
void DrawModelO(const float &centerX, const float &centerY, const Color &color);
}  // namespace Raylib

#endif  // UTILITY_H_