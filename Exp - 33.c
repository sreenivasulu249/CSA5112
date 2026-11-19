
#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t data, key;

    printf("Enter 64-bit plaintext in hexadecimal: ");
    scanf("%llx", (unsigned long long *)&data);

    printf("Enter key in hexadecimal: ");
    scanf("%llx", (unsigned long long *)&key);

    data ^= key;

    printf("Encrypted data: %016llX\n",
           (unsigned long long)data);

    data ^= key;

    printf("Decrypted data: %016llX\n",
           (unsigned long long)data);

    return 0;
}
