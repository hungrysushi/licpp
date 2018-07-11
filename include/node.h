#pragma once

#include <ostream>
#include <vector>

#include "types.h"

class Node {
public:
    Node(const NodeType& type, int64_t data, Node* parent);
    ~Node();

    friend std::ostream& operator<< (std::ostream& os, const Node& node);

    NodeType type_;
    void* buffer_ = nullptr;
    int64_t data_;

    Node* parent_ = nullptr;
    std::vector<Node> leaves_;
};
