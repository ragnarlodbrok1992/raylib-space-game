#ifndef H_CONSOLE
#define H_CONSOLE

#include "Utils.h"

class Console {
  public:
    // Console colors and stuff
    Color blue_soft_transparent = {0, 121, 241, 127};

    // Console geometry
    Rectangle rect = {};
    unsigned int render_time = 0;
    Console(float x,
            float y,
            float width,
            float height);
    ~Console();

    void render(bool should_render);
};

#endif /* H_CONSOLE */

