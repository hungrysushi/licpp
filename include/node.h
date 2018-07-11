#pragma once

#include <ostream>
#include <vector>

#include "types.h"

class Node {
public:
    Node(const NodeType& type, Node* parent);
    Node(const NodeType& type, void* data, int64_t size, Node* parent);
    ~Node();

    friend std::ostream& operator<< (std::ostream& os, const Node& node);

    NodeType type_;
    uint8_t* buffer_ = nullptr;
    int64_t data_;

    Node* parent_ = nullptr;
    std::vector<Node> leaves_;
};
