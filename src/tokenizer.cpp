#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string& token_regex)
    : token_regex_(token_regex) {
    
    //
}

Tokenizer::~Tokenizer() {

    // nothing to clean up
}

void Tokenizer::Tokenize(std::string line) {

    std::smatch match;

    while (std::regex_search(line, match, token_regex_)) {

        // TODO figure out why the regex is matching twice
        tokens_.push_back(match[1]);

        line = match.suffix().str();
    }
}

void Tokenizer::PrintTokens() {
    
    for (auto & it : tokens_) {
        std::cout << it << std::endl;
    }
}
