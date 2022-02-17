#include "Console.h"

// DEBUG INCLUDES
#include <iostream>

Console::Console(float x, float y, float width, float height) {
  // Assume font is 20 px in height
  this->rect = {x, y, width, height};
  float input_rect_x = x + (width * 0.01f);
  float input_rect_y = y + height - 16.0f;
  this->input_rect = {input_rect_x, input_rect_y, width * 0.98f, 14};
  this->cursor = {input_rect_x + 1, input_rect_y + 1, 8, 12};  // 8 px width for cursor
  this->cursor_start_point.x = this->cursor.x;
  this->cursor_start_point.y = this->cursor.y;
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

  // Early break from processing input if keys are console controls
  if (key_code_event == KEY_GRAVE) return;
  if (key_code_event != 0) {
    // DEBUG
    std::cout << "Key code event: " << key_code_event << std::endl;

    // Store input into console command buffer
    char kce = static_cast<char>(key_code_event);
    int char_measurement = MeasureText(&kce, 12);
    std::cout << "Char width is: " << char_measurement << std::endl;
    this->command_buffer.push_back(kce);
    this->cmd_char_size.push_back(MeasureText(&kce, 12));

    // Move cursor forward
    // TODO/FIXME(ragnar): This is almost done but there is some error that is going on here
    this->cursor.x += static_cast<float>(char_measurement) + 1.0f;
    //this->cursor.x += this->cursor.width;
  }

  // Rendering command on console
  std::string cmd_buf(this->command_buffer.begin(), this->command_buffer.end());
  // TODO(ragnar): This should be WriteMessage but console function to render commands
  // TODO(ragnar): Use MeasureText for checking render option
  WriteMessage(cmd_buf, this->cursor_start_point.x, this->cursor_start_point.y); // Some offset to put the font down
}

void Console::clear_cmd_buf() {
  this->command_buffer.clear();

  // Move cursor back to start
  this->cursor.x = this->cursor_start_point.x;
  this->cursor.y = this->cursor_start_point.y;
}