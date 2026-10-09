#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generate_cipher(const char *keyword, char cipher[27]) {
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; keyword[i] != '\0'; i++) {
        char c = toupper(keyword[i]);
        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            cipher[idx++] = c;
            used[c - 'A'] = 1;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            cipher[idx++] = c;
        }
    }
    cipher[26] = '\0';
}

char encrypt_char(char c, const char cipher[27]) {
    if (c >= 'a' && c <= 'z')
        return tolower(cipher[c - 'a']);
    if (c >= 'A' && c <= 'Z')
        return cipher[c - 'A'];
    return c;
}

char decrypt_char(char c, const char cipher[27]) {
    char upper = toupper(c);
    for (int i = 0; i < 26; i++) {
        if (cipher[i] == upper) {
            if (c >= 'a' && c <= 'z')
                return 'a' + i;
            if (c >= 'A' && c <= 'Z')
                return 'A' + i;
        }
    }
    return c;
}

int main(void) {
    char keyword[100];
    char plaintext[500];
    char cipher[27];

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    generate_cipher(keyword, cipher);

    printf("\nPlain : ");
    for (char c = 'a'; c <= 'z'; c++)
        printf("%c ", c);
    printf("\nCipher: ");
    for (int i = 0; i < 26; i++)
        printf("%c ", cipher[i]);
    printf("\n\n");

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("\nEncrypted: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
        putchar(encrypt_char(plaintext[i], cipher));
    printf("\n");

    printf("Decrypted: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char enc = encrypt_char(plaintext[i], cipher);
        putchar(decrypt_char(enc, cipher));
    }
    printf("\n");

    return 0;
}
