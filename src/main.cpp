#include "main.h"

#include <editline/readline.h>
#include <iostream>
#include <string>

int main()
{
    repl();

    return 0;
}

void repl()
{
    char* line;

    while ((line = readline("licpp> ")) != nullptr) {
        std::cout << line << std::endl;

        if (*line) {
            add_history(line);
        }

        free(line);
    }
}

