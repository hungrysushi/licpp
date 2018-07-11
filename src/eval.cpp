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
                return a / b;
            };
}

Eval::~Eval() {

}

bool Eval::EvaluateAst(const Node& tree) {

    // TODO

/*     switch (tree.type_) { */
/*         case NodeType::LIST: */
/*             break; */
/*         default: */
/*             break; */
/*     } */

    for (auto & leaf : tree.leaves_) {

        std::cout << "Eval: " << leaf.type_ << std::endl;

        switch ()
    }

    return false;
}

bool Eval::Evaluate(const std::string& symbol, int64_t a, int64_t b, int64_t& result) {

    if (eval_map_.count(symbol)) {
        result = eval_map_[symbol](a, b);
        return true;
    }

    return false;
}
