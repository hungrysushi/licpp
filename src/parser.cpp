#include "parser.h"

#include <iostream>

#include "types.h"

Parser::Parser()
    : tree_(NodeType::LIST) {

    //
    current_level_ = &tree_;
}

Parser::~Parser() {

}

void Parser::Parse(std::list<std::string>& tokens) {

    if (tokens.size() == 0) {
        // unexpected EOF
        return;
    }

    // look at first token to see what to do
    std::string token = tokens.front();
    tokens.pop_front();

    if (token == "(") {  // begin new list
        
        // begin new list in tree
        std::cout << "begin list" << std::endl;
        current_level_->leaves_.emplace_back(NodeType::LIST);
        current_level_ = &(current_level_->leaves_.back());

    } else if (token == ")") {  // end this list
        
        // end the list and move back up to the parent
        std::cout << "ending list" << std::endl;
        
        if (current_level_->parent_) {
            current_level_ = current_level_->parent_;
        } else {
            // we are back at the parent level
        }

    } else {

        Node node = Atom(token);
        current_level_->leaves_.push_back(node);
    }

    Parse(tokens);
    return;
}

Node Parser::Atom(const std::string& token) {

    std::cout << "token: " << token << std::endl;

    NodeType type = GetType(token);

    // TODO parse token into data and put in node
    return Node(type);
}

NodeType Parser::GetType(const std::string& token) {

    if (IsNumber(token)) {
        return NodeType::NUMBER;
    }

    if (IsSymbol(token)) {
        return NodeType::SYMBOL;
    }

    return NodeType::UNIMPLEMENTED;
}

bool Parser::IsNumber(const std::string& token) {

    // TODO
    return false;
}

bool Parser::IsSymbol(const std::string& token) {

    // TODO
    return false;
}
