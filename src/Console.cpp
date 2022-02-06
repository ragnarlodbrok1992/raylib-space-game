#include "Console.h"

// TEMP include
#include <iostream>

Console::Console(int x, int y, int width, int height) {

};

Console::~Console() {};

void Console::render(bool should_render) {

  // Temp debug code
  // std::cout << "Render time: " << this->render_time << std::endl;
  WriteMessage("Render time: ", this->render_time, 20, 300);

};
