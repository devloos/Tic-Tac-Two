#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include <iostream>
#include <vector>

namespace Logic {
void start(const std::vector<Sound> &soundFX);
void gridMouseClick(const std::vector<Sound> &soundFX);
}  // namespace Logic

#endif  // LOGIC_H_