#pragma once

#include <list>
#include <string>

#include "node.h"

class Parser {

public:
    Parser();
    ~Parser();

    void Parse(std::list<std::string>& tokens);
    void PrintTree();

protected:
    Node Atom(const std::string& token);
    void TreeDescent(Node& tree, int level = 0);

    /*
     * functions to determine the type of the token
     */
    uint64_t* ParseNumber(const std::string& token);

    std::string token_pattern_;

    Node tree_;
    Node* current_level_;
};
