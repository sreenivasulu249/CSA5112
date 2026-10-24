#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPosition(char ch, int *row, int *col)
{
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (key[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

int main()
{
    char msg[] = "Must see you over Cadogan West. Coming at once.";
    char text[200], cipher[200];
    int n = 0, k = 0;

    for (int i = 0; msg[i]; i++) {
        if (isalpha((unsigned char)msg[i])) {
            char ch = toupper((unsigned char)msg[i]);
            if (ch == 'J')
                ch = 'I';
            text[n++] = ch;
        }
    }
    text[n] = '\0';

    for (int i = 0; i < n; i += 2) {
        char a = text[i];
        char b;

        if (i + 1 >= n) {
            b = 'X';
        } else if (a == text[i + 1]) {
            b = 'X';
            i--;
        } else {
            b = text[i + 1];
        }

        int r1, c1, r2, c2;
        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2) {
            cipher[k++] = key[r1][(c1 + 1) % 5];
            cipher[k++] = key[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher[k++] = key[(r1 + 1) % 5][c1];
            cipher[k++] = key[(r2 + 1) % 5][c2];
        } else {
            cipher[k++] = key[r1][c2];
            cipher[k++] = key[r2][c1];
        }
    }

    cipher[k] = '\0';

    printf("Plaintext: %s\n", msg);
    printf("Encrypted message: ");
    for (int i = 0; i < k; i++) {
        printf("%c", cipher[i]);
        if ((i + 1) % 5 == 0)
            printf(" ");
    }
    printf("\n");

    return 0;
}
