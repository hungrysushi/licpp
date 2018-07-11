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
    void ClearTree();

protected:
    Node Atom(const std::string& token);
    void TreeDescent(Node& tree, int level = 0);

    /*
     * functions to determine the type of the token
     */
    bool ParseNumber(const std::string& token, int64_t& value);
    bool ParseString(const std::string& token);

    std::string token_pattern_;

    Node tree_;
    Node* current_level_;
};
