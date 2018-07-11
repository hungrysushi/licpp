#include "node.h"

#include <cstdint>

Node::Node(const NodeType& type, int64_t data, Node* parent)
    : type_(type),
      data_(data),
      parent_(parent) {

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
}

std::ostream& operator<< (std::ostream& os, const Node& node) {
    os << node.type_ << ": ";

    switch (node.type_) {
        case NodeType::NUMBER:
                                os << node.data_;
                                break;
        default:
                                break;
    }

    return os;
}
