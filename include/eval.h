#pragma once

#include <functional>
#include <map>
#include <string>

#include "node.h"

class Eval {
public:
    Eval();
    ~Eval();

    bool EvaluateAst(const Node& tree);
    bool Evaluate(const std::string& symbol, int64_t a, int64_t b, int64_t& result);

protected:

    std::map<std::string, std::function<int64_t (int64_t, int64_t)>> eval_map_;
};
