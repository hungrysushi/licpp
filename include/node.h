#pragma once

#include <vector>

#include "types.h"

class Node {
public:
    Node(const NodeType& type);
    ~Node();

    NodeType type_;
    void* buffer_ = nullptr;

    Node* parent_ = nullptr;
    std::vector<Node> leaves_;
};
