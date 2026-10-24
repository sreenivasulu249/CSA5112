
#include <stdio.h>
#include <stdint.h>

int main()
{
    int shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    uint64_t encryptionKeys[16];
    uint64_t decryptionKeys[16];

  
    for (int i = 0; i < 16; i++)
        encryptionKeys[i] = i + 1;

    for (int i = 0; i < 16; i++)
        decryptionKeys[i] = encryptionKeys[15 - i];

    printf("DES decryption key order:\n");
    for (int i = 0; i < 16; i++)
        printf("K%d = %llu\n", 16 - i,
               (unsigned long long)decryptionKeys[i]);

    printf("\nDES encryption shift schedule:\n");
    for (int i = 0; i < 16; i++)
        printf("%d ", shifts[i]);

    printf("\n");
    return 0;
}
