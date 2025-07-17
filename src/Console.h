#ifndef H_CONSOLE
#define H_CONSOLE

#include "Parser.h"
#include "globals.h"

#include <unordered_map>
#include <functional>

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
    bool is_active = false;
    Console(); //uses predefined size of console
    Console(float x,
            float y,
            float width,
            float height);
    ~Console();

    // Console command buffer
    std::vector<char> command_buffer;
    
    // Callbacks register
    std::unordered_map<Command, std::function<void()>> callbacks;

    // Register function
    void register_callbacks();

    // Methods
    void render();
    void clear_cmd_buf();
    inline void render_cursor();

    // Working logic for text inputing
    void process_input();

    // Running callbacks
    void commands_callbacks(Command command); 

};

#endif /* H_CONSOLE */

