#include "Parser.h"

// DEBUG
#include <iostream>

Parser::Parser() {
    Initialize();
};

Parser::~Parser() {

};

void Parser::Initialize() {
    s_mapStringValue["EXIT"] = evExit;
    s_mapStringValue["RESTART"] = evRestart;
    s_mapStringValue["CREATESERVER"] = evCreateServer;
};

bool Parser::parse_command(std::string command) {
    // For now
    std::cout << "Parsing command: " << command << std::endl;

    Upper(command);
    std::cout << "Capitalize command: " << command << std::endl;

    // For now parsing command changes global variables searching through switch statement
    // TODO(ragnar): Find better way to control engine using command than this
    switch(s_mapStringValue[command])
    {
        case evExit:
            parsed_command = Command::EXIT;
            break;
        case evCreateServer:
            parsed_command = Command::CREATESERVER;
            break;
        case evRestart:
            parsed_command = Command::RESTART;
            break;
        default:
            std::cout << "Wrong command!" << std::endl;
            break;
    }

    return false;
};
