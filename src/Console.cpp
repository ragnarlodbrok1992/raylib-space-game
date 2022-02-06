#include "Console.h"


Console::Console(float x, float y, float width, float height) {
  this->rect = {x, y, width, height};
};

Console::~Console() {};

void Console::render(bool should_render) {
  WriteMessage("Render time: ", this->render_time, 20, 300);
  WriteMessage("Should render: ", should_render, 20, 320);

  // Actual render code goes here
  if (should_render) {
    // Increment counter
    this->render_time++;

    // Render console proper
    DrawRectangleRec(this->rect, this->blue_soft_transparent);
  } else {
    this->render_time = 0;
  }

};
