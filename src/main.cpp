#include "main.h"

#include <editline/readline.h>
#include <iostream>
#include <string>

#include "parser.h"
#include "tokenizer.h"

int main()
{
    repl();

    return 0;
}

void repl()
{
    char* line;

    // got token regex from https://github.com/kanaka/mal/blob/master/process/guide.md#step0
    Tokenizer tokenizer(R"regex([\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"|;.*|[^\s\[\]{}('"`,;)]+))regex");
    Parser parser;

    while ((line = readline("licpp> ")) != nullptr) {
        std::cout << line << std::endl;

        if (*line) {
            add_history(line);
        }

        std::string line_str(line);
        std::list<std::string> tokens = tokenizer.Tokenize(line_str);

        parser.Parse(tokens);
        parser.PrintTree();
        parser.ClearTree();

        free(line);
    }
}

