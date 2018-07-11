#pragma once

#include <ostream>

enum class NodeType {
    NUMBER,
    STRING,
    SYMBOL,
    KEYWORD,
    LIST,
    UNIMPLEMENTED,
};

inline std::ostream& operator<< (std::ostream& os, const NodeType type) {

    switch (type) {
        case NodeType::NUMBER:
                                os << "NUMBER";
                                break;
        case NodeType::STRING:
                                os << "STRING";
                                break;
        case NodeType::SYMBOL:
                                os << "SYMBOL";
                                break;
        case NodeType::KEYWORD:
                                os << "KEYWORD";
                                break;
        case NodeType::LIST:
                                os << "LIST";
                                break;
        case NodeType::UNIMPLEMENTED:
                                os << "UNIMPLEMENTED";
                                break;
    }

    return os;
}
