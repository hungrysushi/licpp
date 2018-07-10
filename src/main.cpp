#include "main.h"

#include <editline/readline.h>
#include <iostream>
#include <string>

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

    while ((line = readline("licpp> ")) != nullptr) {
        std::cout << line << std::endl;

        if (*line) {
            add_history(line);
        }

        std::string line_str(line);
        tokenizer.Tokenize(line_str);
        std::cout << "Tokens: " << std::endl;
        tokenizer.PrintTokens();

        free(line);
    }
}

