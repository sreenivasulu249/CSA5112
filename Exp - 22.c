
#include <stdio.h>

int encrypt(int p, int k) {
    return p ^ k;
}

int decrypt(int c, int k) {
    return c ^ k;
}

int main() {
    int key = 0x7D;
    int iv = 0xAA;
    int p[] = {0x01, 0x23};
    int c[2], d[2];
    int i;

    for(i = 0; i < 2; i++) {
        c[i] = encrypt(p[i] ^ iv, key);
        iv = c[i];
    }

    printf("Encrypted: ");
    for(i = 0; i < 2; i++)
        printf("%02X ", c[i]);

    iv = 0xAA;

    for(i = 0; i < 2; i++) {
        d[i] = decrypt(c[i], key) ^ iv;
        iv = c[i];
    }

    printf("\nDecrypted: ");
    for(i = 0; i < 2; i++)
        printf("%02X ", d[i]);

    return 0;
}
