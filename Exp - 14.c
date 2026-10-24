
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char p[] = "SEND MORE MONEY";
    char target[] = "CASH NOT NEEDED";
    int key[] = {9, 0, 1, 7, 23, 15, 21,
                 14, 11, 11, 2, 8, 9};
    char plain[100], cipher[100];
    int n = 0;

    for (int i = 0; p[i]; i++)
        if (isalpha((unsigned char)p[i]))
            plain[n++] = toupper((unsigned char)p[i]);

    for (int i = 0; i < n; i++)
        cipher[i] = (plain[i] - 'A' + key[i]) % 26 + 'A';
    cipher[n] = '\0';

    printf("Plaintext : %s\n", plain);
    printf("Ciphertext: %s\n", cipher);

    printf("Key for CASHNOTNEEDED:\n");
    for (int i = 0; i < n; i++) {
        int k = (cipher[i] - 'A'
               - (target[i] - 'A') + 26) % 26;
        printf("%d ", k);
    }

    printf("\n");
    return 0;
}
