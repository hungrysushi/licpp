#pragma once

#include <list>
#include <string>

#include "node.h"

class Parser {

public:
    Parser();
    ~Parser();

    void Parse(std::list<std::string>& tokens);

protected:
    Node Atom(const std::string& token);

    /*
     * functions to determine the type of the token
     */
    NodeType GetType(const std::string& token);
    bool IsNumber(const std::string& token);
    bool IsSymbol(const std::string& token);

    std::string token_pattern_;

    Node tree_;
    Node* current_level_;
};
