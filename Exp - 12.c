
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char msg[] = "meet me at the usual place at ten rather than eight oclock";
    char p[200], c[200], d[200];
    int n = 0;

    for (int i = 0; msg[i]; i++)
        if (isalpha((unsigned char)msg[i]))
            p[n++] = toupper((unsigned char)msg[i]);

    if (n % 2)
        p[n++] = 'X';
    p[n] = '\0';

    for (int i = 0; i < n; i += 2) {
        int x = p[i] - 'A';
        int y = p[i + 1] - 'A';

        c[i]     = (9 * x + 4 * y) % 26 + 'A';
        c[i + 1] = (5 * x + 7 * y) % 26 + 'A';
    }
    c[n] = '\0';

    for (int i = 0; i < n; i += 2) {
        int x = c[i] - 'A';
        int y = c[i + 1] - 'A';

        d[i]     = (5 * x + 12 * y) % 26 + 'A';
        d[i + 1] = (15 * x + 25 * y) % 26 + 'A';
    }
    d[n] = '\0';

    printf("Plaintext : %s\n", p);
    printf("Ciphertext: %s\n", c);
    printf("Decrypted : %s\n", d);

    return 0;
}
