#pragma once

#include <list>
#include <string>

#include "node.h"

class Parser {

public:
    Parser();
    ~Parser();

    void Parse(std::list<std::string>& tokens);
    Node Atom(const std::string& token);

protected:

    std::string token_pattern_;

    Node tree_;
    Node* current_level_;
};
