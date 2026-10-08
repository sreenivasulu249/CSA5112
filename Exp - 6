#include <stdio.h>

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main()
{
    int p1 = 4, c1 = 1;
    int p2 = 19, c2 = 20;

    int diffP = (p2 - p1 + 26) % 26;
    int diffC = (c2 - c1 + 26) % 26;

    int inverse = modInverse(diffP, 26);

    if (inverse == -1)
    {
        printf("No modular inverse exists.\n");
        return 1;
    }

    int a = (diffC * inverse) % 26;
    int b = (c1 - a * p1) % 26;

    if (b < 0)
        b += 26;

    int aInverse = modInverse(a, 26);

    printf("Affine Cipher Key:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nDecryption Formula:\n");
    printf("P = %d * (C - %d) mod 26\n", aInverse, b);

    printf("\nCiphertext -> Plaintext\n");

    for (int c = 0; c < 26; c++)
    {
        int p = (aInverse * (c - b + 26)) % 26;
        printf("%c -> %c\n", 'A' + c, 'A' + p);
    }

    return 0;
}
