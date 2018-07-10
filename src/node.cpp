#include "node.h"

Node::Node(const NodeType& type)
    : type_(type) {

}

Node::~Node() {
    /* delete buffer_; */
}
