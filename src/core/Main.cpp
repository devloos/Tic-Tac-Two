#include "Application.h"

#define EXIT_FAILED -1

int main() {
  Tapp app;
  if (!app.init()) {
    return EXIT_FAILED;
  }
  return app.exec();
}
