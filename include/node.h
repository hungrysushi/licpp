#pragma once

#include <ostream>
#include <vector>

#include "types.h"

class Node {
public:
    Node(const NodeType& type, void* data, Node* parent);
    ~Node();

    friend std::ostream& operator<< (std::ostream& os, const Node& node);

    NodeType type_;
    void* buffer_ = nullptr;

    Node* parent_ = nullptr;
    std::vector<Node> leaves_;
};
