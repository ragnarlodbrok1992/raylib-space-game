#ifndef H_PARSER
#define H_PARSER

#include "Utils.h"

#include <vector>
#include <string>
#include <map>

enum class Command
{
    NO_COMMAND,
    EXIT,
    RESTART,
    CREATESERVER
};

class Parser {
private:
    enum StringValue { evNonDefined,
                       evExit,
                       evRestart,
                       evCreateServer};
    std::map<std::string, StringValue> s_mapStringValue;
    void Initialize();
public:
    // Command stash    
    std::vector<std::string> command_history;
    std::string current_command;
    Command parsed_command;

    //Const
    Parser();

    //Deconst
    ~Parser();

    //Methods
    bool parse_command(std::string command);
};

#endif /* H_PARSER */
