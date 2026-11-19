
#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t L, K1, K2;

    printf("Enter 64-bit hexadecimal value L: ");
    scanf("%llx", (unsigned long long *)&L);

    K1 = L << 1;

    if(L & 0x8000000000000000ULL)
        K1 ^= 0x1B;

    K2 = K1 << 1;

    if(K1 & 0x8000000000000000ULL)
        K2 ^= 0x1B;

    printf("K1 = %016llX\n", (unsigned long long)K1);
    printf("K2 = %016llX\n", (unsigned long long)K2);

    printf("For 128-bit blocks, the constant is ");
    printf("0x87.\n");

    return 0;
}
