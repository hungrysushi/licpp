#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string& token_regex)
    : token_regex_(token_regex) {
    
    //
}

Tokenizer::~Tokenizer() {

    // nothing to clean up
}

std::list<std::string> Tokenizer::Tokenize(std::string line) {

    std::smatch match;
    std::list<std::string> tokens;

    while (std::regex_search(line, match, token_regex_)) {

        // TODO figure out why the regex is matching twice
        tokens_.push_back(match[1]);
        tokens.push_back(match[1]);

        line = match.suffix().str();
    }

    return tokens;
}

void Tokenizer::PrintTokens() {
    
    for (auto & it : tokens_) {
        std::cout << it << std::endl;
    }
}
