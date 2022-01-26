#ifndef H_CONSOLE
#define H_CONSOLE

#include "Utils.h"

class Console {
  public:
    int x, y, width, height;
    unsigned int render_time = 0;
    Console(int x,
            int y,
            int width,
            int height);
    ~Console();

    void render(bool should_render);
};

#endif /* H_CONSOLE */

