
#include <stdio.h>

int gcd(int a, int b) {
    while(b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b, i;
    char text[100];

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if(gcd(a, 26) != 1) {
        printf("Invalid key: Encryption is not one-to-one.\n");
        return 0;
    }

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Encrypted text: ");
    for(i = 0; text[i]; i++)
        printf("%c", ((a * (text[i] - 'A') + b) % 26) + 'A');

    return 0;
}
