/* op_id.l: Lex program to identify operators and identifiers */
%{
#include <stdio.h>
%}

OPERATOR   (<=|>=|==|!=|[+\-*/=<>])
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+

%%
{WHITESPACE} { /* Ignore whitespace */ }
{OPERATOR}   { printf("Operator: %s\n", yytext); }
{IDENTIFIER} { printf("Identifier: %s\n", yytext); }
.            { printf("Unrecognized character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    return 0;
}

