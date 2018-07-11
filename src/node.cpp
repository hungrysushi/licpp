#include "node.h"

#include <cstdint>
#include <cstring>

Node::Node(const NodeType& type, Node* parent)
    : type_(type),
      parent_(parent) {

}

Node::Node(const NodeType& type, void* data, int64_t size, Node* parent)
    : type_(type),
      parent_(parent) {

    buffer_ = new uint8_t[size];

    memcpy(buffer_, data, size * sizeof(uint8_t));
}

Node::~Node() {
    /* delete buffer_; */
    /* switch (type_) { */
    /*     case NodeType::NUMBER: */
    /*                             delete (int64_t*) buffer_; */
    /*                             break; */
    /*     default: */
    /*                             break; */
    /* } */
    /* delete[] buffer_; */
}

std::ostream& operator<< (std::ostream& os, const Node& node) {
    os << node.type_ << ": ";

    switch (node.type_) {
        case NodeType::NUMBER:
                                os << *((int64_t*) node.buffer_);
                                break;
        case NodeType::KEYWORD:
        case NodeType::SYMBOL:
        case NodeType::STRING:
                                os << ((char*) node.buffer_);
                                break;
        default:
                                break;
    }

    return os;
}
