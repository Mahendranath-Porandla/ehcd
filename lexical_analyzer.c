#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of C keywords
const char *keywords[34] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", 
    "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", 
    "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
    "union", "unsigned", "void", "volatile", "while"
};

// Function to check if the word is a keyword
int is_keyword(const char *str) {
    for (int i = 0; i < 34; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

// Function to check if the word is a valid identifier
int is_identifier(const char *str) {
    if (isalpha(str[0]) || str[0] == '_') {
        for (int i = 1; str[i]; i++) {
            if (!isalnum(str[i]) && str[i] != '_') return 0;
        }
        return 1;
    }
    return 0;
}

// Function to check if the word is a number
int is_number(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int main() {
    char input[1000], word[50];
    int i = 0, j = 0;

    int keyword_count = 0, identifier_count = 0, number_count = 0, operator_count = 0;

    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    while (input[i]) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Word: keyword or identifier
        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (is_keyword(word)) keyword_count++;
            else if (is_identifier(word)) identifier_count++;
        }

        // Number
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            if (is_number(word)) number_count++;
        }

        // Operator
        else {
            operator_count++;
            i++;
        }
    }

    printf("\nSummary:\n");
    printf("Keywords   : %d\n", keyword_count);
    printf("Identifiers: %d\n", identifier_count);
    printf("Numbers    : %d\n", number_count);
    printf("Operators  : %d\n", operator_count);

    return 0;
}