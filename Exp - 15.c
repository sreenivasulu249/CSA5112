
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main()
{
    char cipher[MAX];
    double freq[26] = {
        8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,
        0.2,0.8,4.0,2.4,6.7,7.5,1.9,0.1,6.0,
        6.3,9.1,2.8,1.0,2.4,0.2,2.0,0.1
    };
    double score[26];
    char result[26][MAX];
    int top;

    printf("Enter ciphertext: ");
    fgets(cipher, MAX, stdin);

    printf("How many top plaintexts? ");
    scanf("%d", &top);

    if (top < 1) top = 1;
    if (top > 26) top = 26;

    for (int k = 0; k < 26; k++) {
        score[k] = 0;
        int n = 0;

        for (int i = 0; cipher[i]; i++) {
            if (isalpha((unsigned char)cipher[i])) {
                int c = toupper((unsigned char)cipher[i]) - 'A';
                int p = (c - k + 26) % 26;

                result[k][n++] = p + 'A';
                score[k] += freq[p];
            } else {
                result[k][n++] = cipher[i];
            }
        }

        result[k][n] = '\0';
    }

    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
            if (score[j] > score[i]) {
                double temp = score[i];
                score[i] = score[j];
                score[j] = temp;

                char s[MAX];
                strcpy(s, result[i]);
                strcpy(result[i], result[j]);
                strcpy(result[j], s);
            }

    printf("\nPossible plaintexts:\n");
    for (int i = 0; i < top; i++)
        printf("%2d. %s\n", i + 1, result[i]);

    return 0;
}
