
#include <stdio.h>
#include <string.h>

#define MAX 100

void main() {
    int p[MAX], key = 101, iv = 55, n, i;
    int ecb[MAX], cbc[MAX], cfb[MAX];

    printf("Enter number of plaintext blocks: ");
    scanf("%d", &n);

    printf("Enter plaintext blocks: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++) {
        ecb[i] = p[i] ^ key;
        cbc[i] = p[i] ^ (i == 0 ? iv : cbc[i-1]);
        cbc[i] ^= key;
        cfb[i] = p[i] ^ (i == 0 ? iv : cfb[i-1]);
        cfb[i] ^= key;
    }

    printf("\nECB: ");
    for(i = 0; i < n; i++)
        printf("%d ", ecb[i]);

    printf("\nCBC: ");
    for(i = 0; i < n; i++)
        printf("%d ", cbc[i]);

    printf("\nCFB: ");
    for(i = 0; i < n; i++)
        printf("%d ", cfb[i]);
}
