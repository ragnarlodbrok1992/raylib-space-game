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
  // Get input chars
  // Calling once per frame, the key are getting stored
  // in a queue hidden in RayLib implementation
  int key_code_event = GetKeyPressed();

  // Early break from processing input if keys are console controls
  if (key_code_event == KEY_GRAVE) return;

  if (key_code_event == KEY_LEFT) {
      std::cout << "You are pushing left arrow!" << std::endl;
      if (this->cursor_placement > 0) this->cursor_placement--;
      return;
    }
  if (key_code_event == KEY_RIGHT) {
      std::cout << "You are pushing right arrow!" << std::endl;
      if (this->cursor_placement < this->cursor_max_placement) this->cursor_placement++;
      return;
    }
  if (key_code_event == KEY_ENTER) {
      std::cout << "You are pushing enter!" << std::endl;
      return;
    }
  if (key_code_event == KEY_BACKSPACE) {
      std::cout << "You are pushing backspace!" << std::endl;
      bool should_erase = false;
      // TODO: modify code to be able to remove characters BEFORE cursor
      if (this->cursor_max_placement > 0 && !(this->cursor_placement == 0)) {
        this->cursor_max_placement--;
      }
      if (this->cursor_placement > 0) {
        this->cursor_placement--;
        should_erase = true;
      }
      if (should_erase) {
        command_buffer.erase(command_buffer.begin() + cursor_placement);
      }
      return;
    }

  if (key_code_event == KEY_DELETE) {
    std::cout << "You are pushing DELETE key!" << std::endl;

    if (this->cursor_placement == this->cursor_max_placement) {
      std::cout << "We are at the end of string!" << std::endl;
      return;
      // In this case there is nothing to delete
    } else {
      // We are not at the end of string so there is always something to delete
      // TODO: write code to delete character AFTER cursor
      // This kills the program xD <-- while deleting the last character of buffer
      command_buffer.erase(command_buffer.begin() + cursor_placement);
      this->cursor_max_placement--;
    }
    return;
  }

  // Check press enter
  if (key_code_event == KEY_ENTER) {
    std::cout << "Pressed enter!" << std::endl;

  }

  // TODO(ragnar): Restrict keypressed to only inputable characters
  if (key_code_event != 0) {
    char kce = static_cast<char>(key_code_event);
    this->command_buffer.insert(this->command_buffer.begin() + this->cursor_placement, kce);
    
    this->cursor_placement += 1;
    this->cursor_max_placement += 1;

    // DEBUG
    std::cout << "Key code event: " << key_code_event << std::endl;
    //std::cout << "Cursor placement is: " << this->cursor_placement << std::endl;
  }

  // Rendering command on console
  const std::string cmd_buf(this->command_buffer.begin(), this->command_buffer.end());
  const char* text = cmd_buf.c_str();

  const std::string cursor_pos_buf(this->command_buffer.begin(), this->command_buffer.begin() + this->cursor_placement);
  const char* cursor_pos = cursor_pos_buf.c_str();
  int cursor_pos_measurement = MeasureText(cursor_pos, 12);

  this->cursor.x = this->cursor_start_point.x + static_cast<float>(cursor_pos_measurement) + 1.0f;

  WriteMessage(cmd_buf, this->cursor_start_point.x, this->cursor_start_point.y); // Some offset to put the font down

  // Debug 
  WriteMessage("This->cursor_placement: ", this->cursor_placement, 20, 400);
  WriteMessage("This->cursor_max_placement: ", this->cursor_max_placement, 20, 420);
}

void Console::clear_cmd_buf() {
  // This is not being cleaned?
  this->command_buffer.clear();

  // Move cursor back to start
  this->cursor.x = this->cursor_start_point.x;
  this->cursor.y = this->cursor_start_point.y;

  // Reset cursor values
  this->cursor_max_placement = 0;
  this->cursor_placement = 0;
}