#pragma once

#include <iostream>
#include <regex>
#include <vector>
#include <list>

class Tokenizer {

public:
    Tokenizer(const std::string& token_regex);
    ~Tokenizer();

    std::list<std::string> Tokenize(std::string line);
    void PrintTokens();

protected:

    const std::regex token_regex_;
    std::vector<std::string> tokens_;
};
