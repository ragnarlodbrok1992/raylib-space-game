#include "Console.h"

// DEBUG INCLUDES
#include <iostream>

Console::Console(float x, float y, float width, float height) {
  // Create parser object
  this->parser = new Parser();

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

Console::~Console() {
  delete this->parser;
};

void Console::render(bool should_render) {
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
  char key_char_event = GetCharPressed();

  // Early break from processing input if keys are console controls
  if (key_code_event == KEY_GRAVE) return;

  if (key_code_event == KEY_LEFT) {
      if (this->cursor_placement > 0) this->cursor_placement--;
      return;
    }
  if (key_code_event == KEY_RIGHT) {
      if (this->cursor_placement < this->cursor_max_placement) this->cursor_placement++;
      return;
    }
  if (key_code_event == KEY_BACKSPACE) {
      bool should_erase = false;
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

    if (this->cursor_placement == this->cursor_max_placement) {
      return;
    } else {
      command_buffer.erase(command_buffer.begin() + cursor_placement);
      this->cursor_max_placement--;
    }
    return;
  }

  // Check press enter
  if (key_code_event == KEY_ENTER) {
    this->parser->parse_command(std::string(this->command_buffer.begin(), this->command_buffer.end()));

    // Cleaning buffer
    this->clear_cmd_buf();
  }

  if (key_char_event >= 21 && key_char_event <= 126) {
    this->command_buffer.insert(this->command_buffer.begin() + this->cursor_placement, key_char_event);
    
    this->cursor_placement += 1;
    this->cursor_max_placement += 1;
  }

  // Rendering command on console
  const std::string cmd_buf(this->command_buffer.begin(), this->command_buffer.end());
  const char* text = cmd_buf.c_str();

  const std::string cursor_pos_buf(this->command_buffer.begin(), this->command_buffer.begin() + this->cursor_placement);
  const char* cursor_pos = cursor_pos_buf.c_str();
  int cursor_pos_measurement = MeasureText(cursor_pos, 12);

  this->cursor.x = this->cursor_start_point.x + static_cast<float>(cursor_pos_measurement) + 1.0f;

  WriteMessage(cmd_buf, this->cursor_start_point.x, this->cursor_start_point.y); // Some offset to put the font down
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