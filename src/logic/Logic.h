#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include <iostream>

namespace Logic {
/**
 * @brief
 *
 * @param btnClickX
 * @param btnClickO
 */
void start(const Sound &btnClickX, const Sound &btnClickO);
/**
 * @brief
 *
 * @param btnClickX
 * @param btnClickO
 */
void gridMouseClick(const Sound &btnClickX, const Sound &btnClickO);
}  // namespace Logic

#endif  // LOGIC_H_