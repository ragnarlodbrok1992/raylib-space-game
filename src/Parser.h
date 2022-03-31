#ifndef H_PARSER
#define H_PARSER

#include "Utils.h"

#include <vector>
#include <string>
#include <map>

// Variables used in command console
namespace command {
extern bool _EXIT;
}

class Parser {
private:
    enum StringValue { evNonDefined,
                       evExit };
    std::map<std::string, StringValue> s_mapStringValue;
    void Initialize();
public:
    // Command stash    
    std::vector<std::string> command_history;
    std::string current_command;

    //Const
    Parser();

    //Deconst
    ~Parser();

    //Methods
    bool parse_command(std::string command);
};

#endif /* H_PARSER */
