#include "eval.h"

#include <iostream>

Eval::Eval() {
        eval_map_["+"] = [](int64_t a, int64_t b)->int64_t {
                return a + b;
            };
        eval_map_["-"] = [](int64_t a, int64_t b)->int64_t {
                return a - b;
            };
        eval_map_["*"] = [](int64_t a, int64_t b)->int64_t {
                return a * b;
            };
        eval_map_["/"] = [](int64_t a, int64_t b)->int64_t {
                return (int64_t) a / b;
            };
}

Eval::~Eval() {

}

// evaluate a tree (ie a list with a nested list)
int64_t Eval::EvaluateAst(const Node& tree) {

    int64_t value;

    for (auto & leaf : tree.leaves_) {

        switch (leaf.type_) {
            case NodeType::LIST:
                return EvaluateAst(leaf);
                break;
            case NodeType::SYMBOL:
                return EvaluateList(tree);
                break;
            default:
                break;
        }
    }

    return value;
}

// evaluate a list. If there is a nested list, pass it to EvaluateAst
int64_t Eval::EvaluateList(const Node& eval_list) {

    std::function<int64_t(int64_t,int64_t)> eval_function = nullptr;

    int64_t value;
    int64_t expr_value;
    bool first_set = false;

    for (auto & leaf : eval_list.leaves_) {

        switch (leaf.type_) {
            case NodeType::SYMBOL:
                eval_function = eval_map_[std::string((char*)leaf.buffer_)];
                break;
            case NodeType::NUMBER:
                if (first_set) {
                    value = eval_function(value, *((int64_t*) leaf.buffer_));
                } else {
                    value = *((int64_t*) leaf.buffer_);
                    first_set = true;
                }
                break;
            case NodeType::LIST:
                expr_value = EvaluateAst(leaf);
                value = eval_function(value, expr_value);
                break;
            default:
                break;
        }
    }

    return value;
}

