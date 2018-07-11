#include "parser.h"

#include <iostream>

#include "types.h"

Parser::Parser()
    : tree_(NodeType::LIST, nullptr, nullptr) {

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
        current_level_->leaves_.emplace_back(NodeType::LIST, nullptr, current_level_);
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

    void* data = nullptr;

    // try to parse a number first
    data = (void*) ParseNumber(token);
    if (data) {
        std::cout << "Parsed Number: " << *((uint64_t*) data) << std::endl;
        return Node(NodeType::NUMBER, data, current_level_);
    }

    // TODO parse token into data and put in node
    return Node(NodeType::UNIMPLEMENTED, nullptr, current_level_);
}

uint64_t* Parser::ParseNumber(const std::string& token) {

    char *endptr;
    uint64_t *number = new uint64_t;
    *number = strtol(token.c_str(), &endptr, 10);

    // if we haven't reached the null char, then there was some non-numerical data in the string
    if (*endptr != '\0') {
        delete number;
        return nullptr;
    } else {
        return number;
    }
}

void Parser::PrintTree() {
    TreeDescent(tree_, 1);
}

void Parser::TreeDescent(Node& tree, int level) {

    /* if (level == 0) { */
    /*     PrintTree(tree_, level + 1); */
    /* } */

    std::vector<Node> lists;
    for (auto & leaf : tree.leaves_) {
        std::cout << "Level " << level << ": ";
        std::cout << leaf << std::endl;

        if (leaf.type_ == NodeType::LIST) {
            lists.push_back(leaf);
        }
    }

    for (auto node : lists) {
        TreeDescent(node);
    }
}
