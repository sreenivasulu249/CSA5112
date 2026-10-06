#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createMatrix(char key[], char matrix[5][5]) {
    int used[26] = {0};
    int row = 0, col = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char c = toupper(key[i]);

        if (c == 'J')
            c = 'I';

        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            matrix[row][col++] = c;
            used[c - 'A'] = 1;

            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J')
            continue;

        if (!used[c - 'A']) {
            matrix[row][col++] = c;
            used[c - 'A'] = 1;

            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

void findPosition(char matrix[5][5], char c, int *row, int *col) {
    if (c == 'J')
        c = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main() {
    char key[50], text[100];
    char matrix[5][5];

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    createMatrix(key, matrix);

    printf("\nPlayfair Matrix:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    int len = strlen(text);

    for (int i = 0; i < len; i++)
        text[i] = toupper(text[i]);

    if (len % 2 != 0) {
        text[len] = 'X';
        text[len + 1] = '\0';
        len++;
    }

    printf("\nCiphertext: ");

    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;

        findPosition(matrix, text[i], &r1, &c1);
        findPosition(matrix, text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        }
        else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }

    return 0;
}
