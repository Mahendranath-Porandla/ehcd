%{
#include <stdio.h>
#include <string.h>

char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "while", "for", "return", "void", NULL
};

int is_keyword(char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}
%}

/* Regular expressions */
NUMBER      [0-9]+(\.[0-9]+)?   /* Matches integers and floats */
INTEGER     [0-9]+
FLOAT       [0-9]+\.[0-9]+

IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE  [ \t\n]+

%%
{WHITESPACE}   { /* skip whitespace */ }

{FLOAT}        { printf("Number: %s\n", yytext); }
{INTEGER}      { printf("Number: %s\n", yytext); }

{IDENTIFIER}   {
                  if (is_keyword(yytext))
                      printf("Keyword: %s\n", yytext);
                  else
                      printf("Identifier: %s\n", yytext);
               }

.              { printf("Unrecognized character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter code (Ctrl+D to end):\n");
    yylex();
    return 0;
}


