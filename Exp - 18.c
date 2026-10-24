
#include <stdio.h>
#include <stdint.h>

uint32_t rotate28(uint32_t x, int n)
{
    x &= 0x0FFFFFFF;
    return ((x << n) | (x >> (28 - n))) & 0x0FFFFFFF;
}

int main()
{
    uint32_t C = 0x0ABCDEF;
    uint32_t D = 0x0123456;

    int shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    printf("Round   C (28 bits)   D (28 bits)\n");

    for (int i = 0; i < 16; i++) {
        C = rotate28(C, shifts[i]);
        D = rotate28(D, shifts[i]);

        printf("%2d      %07X       %07X\n",
               i + 1, C, D);
    }

    return 0;
}
