#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int keyLen, j = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%s", key);

    keyLen = strlen(key);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';

            text[i] = (text[i] - base +
                       toupper(key[j % keyLen]) - 'A') % 26 + base;

            j++;
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
