
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char plain[] = "ABCDEFGH";
    unsigned char cipher[8], recovered[8];
    unsigned char key = 0x5A;

    for (int i = 0; i < 8; i++)
        cipher[i] = plain[i] ^ key;

    printf("ECB ciphertext blocks:\n");
    for (int i = 0; i < 8; i++)
        printf("%02X ", cipher[i]);

    printf("\n");

    /* Simulate a one-bit error in ciphertext block 1 */
    cipher[0] ^= 1;

    for (int i = 0; i < 8; i++)
        recovered[i] = cipher[i] ^ key;

    printf("Recovered plaintext after error:\n");
    for (int i = 0; i < 8; i++)
        printf("%c", recovered[i]);

    printf("\n");
    return 0;
}
