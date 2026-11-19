
#include <stdio.h>

int main() {
    int p[2][2], c[2][2];
    int a, b, d, det, inv, i, j;

    printf("Enter plaintext matrix (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = (p[0][0] * p[1][1] - p[0][1] * p[1][0]) % 26;
    if(det < 0) det += 26;

    for(inv = 1; inv < 26; inv++)
        if((det * inv) % 26 == 1)
            break;

    if(inv == 26) {
        printf("Inverse does not exist.\n");
        return 0;
    }

    a = p[1][1] * inv % 26;
    b = -p[0][1] * inv % 26;
    d = -p[1][0] * inv % 26;

    printf("Key matrix can be calculated using C * inverse(P).\n");
    printf("Inverse determinant: %d\n", inv);

    printf("Key matrix:\n");
    printf("%d %d\n", (c[0][0] * a + c[0][1] * d) % 26,
                      (c[0][0] * b + c[0][1] * a) % 26);

    return 0;
}
