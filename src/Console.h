#ifndef H_CONSOLE
#define H_CONSOLE

#include "Utils.h"
#include <vector>

class Console {
  public:
    // Console colors and stuff
    Color blue_soft_transparent = {0, 121, 241, 127};
    Color blue_soft_less_transparent = {5, 56, 107, 177};
    Color cursor_color = {26, 8, 87, 200};

    // Console geometry
    Rectangle rect = {};
    Rectangle input_rect = {};
    Rectangle cursor = {};
    Vector2 cursor_start_point = {};
    unsigned int render_time = 0;
    unsigned int cursor_blink = 0;
    unsigned int cursor_placement = 0;
    unsigned int cursor_max_placement = 0;
    bool should_anim = false;
    bool full_open = false;
    Console(float x,
            float y,
            float width,
            float height);
    ~Console();

    // Console command buffer
    std::vector<char> command_buffer;

    void render(bool should_render);
    void clear_cmd_buf();
    inline void render_cursor();

    // Working logic for text inputing
    void process_input();

    // Logic for parsing command

};

#endif /* H_CONSOLE */

