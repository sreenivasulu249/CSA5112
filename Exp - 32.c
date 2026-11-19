
#include <stdio.h>

int main() {
    int p = 23, q = 11, g = 2;
    int x = 3, k1 = 4, k2 = 7;
    int h = 5, r1, r2, s1, s2;

    int y = 1;
    for(int i = 0; i < x; i++)
        y = (y * g) % p;

    r1 = 1;
    for(int i = 0; i < k1; i++)
        r1 = (r1 * g) % p;
    r1 %= q;

    r2 = 1;
    for(int i = 0; i < k2; i++)
        r2 = (r2 * g) % p;
    r2 %= q;

    s1 = (h + x * r1) % q;
    s2 = (h + x * r2) % q;

    printf("Public Key: %d\n", y);
    printf("Signature 1: (%d, %d)\n", r1, s1);
    printf("Signature 2: (%d, %d)\n", r2, s2);

    return 0;
}
