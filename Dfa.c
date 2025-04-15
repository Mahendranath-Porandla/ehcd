#include <stdio.h>

int main() {
    char input[100];
    int a_mod = 0, b_mod = 0; // Track remainders of a's and b's

    printf("Enter string (only a and b): ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            a_mod = (a_mod + 1) % 3;
        } else if (input[i] == 'b') {
            b_mod = (b_mod + 1) % 2;
        } else {
            printf("Invalid character '%c'. Only 'a' and 'b' allowed.\n", input[i]);
            return 1;
        }
    }

    if (a_mod == 0 && b_mod == 0) {
        printf("Accepted: number of a's divisible by 3 and b's divisible by 2.\n");
    } else {
        printf("Rejected: conditions not satisfied.\n");
    }

    return 0;
}
