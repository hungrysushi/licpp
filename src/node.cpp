#include "node.h"

#include <cstdint>

Node::Node(const NodeType& type, void* data, Node* parent)
    : type_(type),
      buffer_(data),
      parent_(parent) {

}

Node::~Node() {
    /* delete buffer_; */
    switch (type_) {
        case NodeType::NUMBER:
                                delete (int64_t*) buffer_;
                                break;
        default:
                                break;
    }
}

std::ostream& operator<< (std::ostream& os, const Node& node) {
    os << node.type_ << ": ";

    switch (node.type_) {
        case NodeType::NUMBER:
                                os << *((uint64_t*) node.buffer_);
                                break;
        default:
                                break;
    }

    return os;
}
