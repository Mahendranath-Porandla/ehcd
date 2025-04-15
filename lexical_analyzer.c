#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *keywords[] = {
    "int", "float", "if", "else", "while", "return", "for"
}; // Using fewer keywords for simplicity

int is_keyword(const char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[100], word[50];
    int i = 0, j = 0;
    int keywords_count = 0, identifiers = 0, numbers = 0, operators = 0;

    printf("Enter code: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier or keyword
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (is_keyword(word))
                keywords_count++;
            else
                identifiers++;
        }

        // Number
        else if (isdigit(input[i])) {
            while (isdigit(input[i])) i++;
            numbers++;
        }

        // Operator
        else if (strchr("+-*/=<>", input[i])) {
            operators++;
            i++;
        }

        // Skip any other characters
        else {
            i++;
        }
    }

    printf("\nSummary:\n");
    printf("Keywords   : %d\n", keywords_count);
    printf("Identifiers: %d\n", identifiers);
    printf("Numbers    : %d\n", numbers);
    printf("Operators  : %d\n", operators);

    return 0;
}
