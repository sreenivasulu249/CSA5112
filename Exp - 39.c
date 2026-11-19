
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int i, shift;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(shift = 0; shift < 26; shift++) {
        printf("\nShift %d: ", shift);

        for(i = 0; text[i]; i++) {
            if(text[i] >= 'A' && text[i] <= 'Z')
                putchar((text[i] - 'A' - shift + 26) % 26 + 'A');
            else if(text[i] >= 'a' && text[i] <= 'z')
                putchar((text[i] - 'a' - shift + 26) % 26 + 'a');
            else
                putchar(text[i]);
        }
    }

    return 0;
}
