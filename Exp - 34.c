
#include <stdio.h>

int main() {
    int p[20], ecb[20], cbc[20], cfb[20];
    int n, key = 7, iv = 5, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter plaintext blocks: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++) {
        ecb[i] = p[i] ^ key;

        cbc[i] = (p[i] ^ iv) ^ key;
        iv = cbc[i];
    }

    iv = 5;

    for(i = 0; i < n; i++) {
        cfb[i] = p[i] ^ (iv ^ key);
        iv = cfb[i];
    }

    printf("ECB: ");
    for(i = 0; i < n; i++)
        printf("%d ", ecb[i]);

    printf("\nCBC: ");
    for(i = 0; i < n; i++)
        printf("%d ", cbc[i]);

    printf("\nCFB: ");
    for(i = 0; i < n; i++)
        printf("%d ", cfb[i]);

    return 0;
}
