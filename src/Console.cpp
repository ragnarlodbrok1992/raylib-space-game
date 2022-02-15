#include "Console.h"

// DEBUG INCLUDES
#include <iostream>

Console::Console(float x, float y, float width, float height) {
  // Assume font is 20 px in height
  this->rect = {x, y, width, height};
  float input_rect_x = x + (width * 0.01f);
  float input_rect_y = y + height - 25.0f;
  this->input_rect = {input_rect_x, input_rect_y, width * 0.98f, 22};
  this->cursor = {input_rect_x + 1, input_rect_y + 1, 8, 20};  // 8 px width for cursor
  // Font in raylib by default (I think) are 7 px width for capital and 6 px width for normal
};

Console::~Console() {};

void Console::render(bool should_render) {
  // Debug messages
  WriteMessage("Render time: ", this->render_time, 20, 300);
  WriteMessage("Should render: ", should_render, 20, 320);
  WriteMessage("Should anim: ", this->should_anim, 20, 340);
  WriteMessage("Full open: ", this->full_open, 20, 360);

  // Actual render code goes here
  if (should_render) {
    // Inside render counter for animations
    if (this->render_time == 0) {
      this->should_anim = true;
    }

    // Stop animation after a period of time
    if (this->render_time >= 60) {
        this->should_anim = false;

    } else {
        // Increment counter
        this->render_time++;
    }

    // Render console proper
    if (this->should_anim) {
      // Full openness
      this->full_open = false;

      // Calculate colors
      this->blue_soft_transparent.a = static_cast<int>(127.0f * ((float)this->render_time / 60.0f));
      this->blue_soft_less_transparent.a = static_cast<int>(177.0f * ((float)this->render_time / 60.0f));

      // Draw elements
      DrawRectangleRec(this->rect, this->blue_soft_transparent);
      DrawRectangleRec(this->input_rect, this->blue_soft_less_transparent);
    } else {
      this->full_open = true;

      DrawRectangleRec(this->rect, this->blue_soft_transparent);
      DrawRectangleRec(this->input_rect, this->blue_soft_less_transparent);

      this->render_cursor();
    }
  } else {
    this->full_open = false;
    this->render_time = 0;
  }

};

inline void Console::render_cursor() {
  // Debug messages
  WriteMessage("Rendering cursor!", 20, 380);

  // Control statements
  this->cursor_blink++;
  if (this->cursor_blink >= 60) { this->cursor_blink = 0; }

  // Proper render
  if (this->cursor_blink < 30) {
    DrawRectangleRec(this->cursor, this->cursor_color);
    } else {
      // Pass
    }
  
};

void Console::process_input() {
  // DEBUG
  WriteMessage("I am processing console input!", 20, 400);

  // Get input chars
  // Calling once per frame, the key are getting stored
  // in a queue hidden in RayLib implementation
  int key_code_event = GetKeyPressed();
  if (key_code_event != 0) {
    // DEBUG

    // Store input into console command buffer
    this->command_buffer.push_back(static_cast<char>(key_code_event));

    // Move cursor
  }

  // Rendering command on console
  std::string cmd_buf(this->command_buffer.begin(), this->command_buffer.end());
  WriteMessage(cmd_buf, 20, 420);
}

void Console::clear_cmd_buf() {
  this->command_buffer.clear();
}