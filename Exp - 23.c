
#include <stdio.h>

int encrypt(int p, int k) {
    return p ^ k;
}

int main() {
    int key = 0x7D;
    int counter = 0;
    int p[] = {0x01, 0x02, 0x04};
    int c[3], d[3];
    int i;

    for(i = 0; i < 3; i++) {
        c[i] = p[i] ^ encrypt(counter, key);
        counter++;
    }

    printf("Encrypted: ");
    for(i = 0; i < 3; i++)
        printf("%02X ", c[i]);

    counter = 0;

    for(i = 0; i < 3; i++) {
        d[i] = c[i] ^ encrypt(counter, key);
        counter++;
    }

    printf("\nDecrypted: ");
    for(i = 0; i < 3; i++)
        printf("%02X ", d[i]);

    return 0;
}
