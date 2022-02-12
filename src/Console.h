#ifndef H_CONSOLE
#define H_CONSOLE

#include "Utils.h"

class Console {
  public:
    // Console colors and stuff
    Color blue_soft_transparent = {0, 121, 241, 127};
    Color blue_soft_less_transparent = {5, 56, 107, 177};
    Color cursor_color = {26, 8, 87, 200};

    // Console geometry
    Rectangle rect = {};
    Rectangle input_rect = {}; // TODO: add constraints to whole console rect
    unsigned int render_time = 0;
    unsigned int cursor_blink = 0;
    bool should_anim = false;
    bool full_open = false;
    //unsigned int anim_time = 0;
    Console(float x,
            float y,
            float width,
            float height);
    ~Console();

    void render(bool should_render);
    inline void render_cursor();
};

#endif /* H_CONSOLE */

