#include <iostream>
#include <regex>
#include <vector>

class Tokenizer {

public:
    Tokenizer(const std::string& token_regex);
    ~Tokenizer();

    void Tokenize(std::string line);
    void PrintTokens();

protected:

    const std::regex token_regex_;
    std::vector<std::string> tokens_;
};
