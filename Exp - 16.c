
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5000

int main()
{
    char cipher[MAX], plain[MAX];
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0}, order[26], used[26] = {0};
    char map[26];
    int top;

    printf("Enter ciphertext:\n");
    fgets(cipher, MAX, stdin);

    printf("Number of candidates (1-10): ");
    scanf("%d", &top);

    if (top < 1) top = 1;
    if (top > 10) top = 10;

    for (int i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i]))
            count[toupper((unsigned char)cipher[i]) - 'A']++;

    for (int i = 0; i < 26; i++)
        order[i] = i;

    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
            if (count[order[j]] > count[order[i]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }

    for (int i = 0; i < 26; i++)
        map[i] = '?';

    for (int i = 0; i < 26; i++) {
        map[order[i]] = english[i];
        used[order[i]] = 1;
    }

    for (int shift = 0; shift < top; shift++) {
        for (int i = 0; i < 26; i++)
            map[order[i]] = english[(i + shift) % 26];

        for (int i = 0; cipher[i]; i++) {
            char ch = cipher[i];
            if (isalpha((unsigned char)ch)) {
                char out = map[toupper((unsigned char)ch) - 'A'];
                plain[i] = islower((unsigned char)ch)
                         ? tolower((unsigned char)out) : out;
            } else {
                plain[i] = ch;
            }
        }
        plain[strlen(cipher)] = '\0';

        printf("\nCandidate %d:\n%s\n", shift + 1, plain);
    }

    return 0;
}
