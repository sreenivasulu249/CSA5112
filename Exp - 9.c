#include <stdio.h>
#include <string.h>

char key[5][5] = {
    {'P','L','A','Y','F'},
    {'I','R','E','X','B'},
    {'C','D','G','H','K'},
    {'M','N','O','Q','S'},
    {'T','U','V','W','Z'}
};

char cipher[] =
"KXJEYUREBEZWEHEWRYTUHEYFS"
"KREHEGOYFIWTTTUOLKSYCAJPO"
"BOTEIZONTXBYBNTGONEYCUZWR"
"GDSONSXBOUYWRHEBAAHYUSEDQ";

void decrypt(char a, char b)
{
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    int i, j;

    if (a == 'J') a = 'I';
    if (b == 'J') b = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            if (key[i][j] == a) {
                r1 = i;
                c1 = j;
            }
            if (key[i][j] == b) {
                r2 = i;
                c2 = j;
            }
        }

    if (r1 == r2)
        printf("%c%c", key[r1][(c1 + 4) % 5],
                        key[r2][(c2 + 4) % 5]);
    else if (c1 == c2)
        printf("%c%c", key[(r1 + 4) % 5][c1],
                        key[(r2 + 4) % 5][c2]);
    else
        printf("%c%c", key[r1][c2], key[r2][c1]);
}

int main()
{
    int i;

    for (i = 0; cipher[i] && cipher[i + 1]; i += 2)
        decrypt(cipher[i], cipher[i + 1]);

    printf("\n");

    return 0;
}
