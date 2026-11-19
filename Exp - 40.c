
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, map[26], i, j, max;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i]; i++)
        if(text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;

    for(i = 0; i < 26; i++) {
        max = -1;
        map[i] = -1;

        for(j = 0; j < 26; j++)
            if(count[j] > max) {
                max = count[j];
                map[i] = j;
            }

        if(map[i] != -1)
            count[map[i]] = -1;
    }

    printf("Possible plaintext:\n");

    for(i = 0; text[i]; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            putchar(freq[0]);
        else
            putchar(text[i]);
    }

    printf("\nFrequency order: %s\n", freq);

    return 0;
}
