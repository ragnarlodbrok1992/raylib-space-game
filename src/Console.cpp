#include "Console.h"


Console::Console(int x, int y, int width, int height) {

};

Console::~Console() {};

void Console::render(bool should_render) {
  WriteMessage("Render time: ", this->render_time, 20, 300);

};