#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    char text[100];
    int a, b;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid value of a.\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int p = text[i] - base;

            text[i] = (a * p + b) % 26 + base;
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
