#include <stdio.h>
#include "parser.tab.h"

extern int yylex();

int main() {
    int token;
    while ((token = yylex()) != 0) {
        switch (token) {
            case IF:
                printf("IF\n");
                break;
            case ELSE:
                printf("ELSE\n");
                break;
            // Add cases for other tokens
            default:
                printf("Token: %d\n", token);
                break;
        }
    }

    return 0;
}
