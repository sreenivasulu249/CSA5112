
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, i, j;
    int used[26] = {0};

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i]; i++)
        if(text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;

    for(i = 0; i < 26; i++)
        for(j = i + 1; j < 26; j++)
            if(count[i] < count[j]) {
                int t = count[i];
                count[i] = count[j];
                count[j] = t;
                char c = text[0];
                (void)c;
            }

    printf("Frequency attack requires a substitution mapping.\n");
    printf("English frequency order: %s\n", freq);

    return 0;
}
