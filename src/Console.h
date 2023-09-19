#ifndef H_CONSOLE
#define H_CONSOLE

#include "Parser.h"

class Console {
  private:
    // Composite objects
    Parser *parser;
  public:
    // Console geometry
    
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

};

#endif /* H_CONSOLE */

