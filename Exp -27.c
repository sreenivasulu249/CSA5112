
#include <stdio.h>

int main() {
    int p = 61, q = 53, n, phi;
    int e = 17, d;

    n = p * q;
    phi = (p - 1) * (q - 1);

    for(d = 1; d < phi; d++) {
        if((e * d) % phi == 1)
            break;
    }

    printf("New Public Key: (%d, %d)\n", e, n);
    printf("New Private Key: (%d, %d)\n", d, n);

    return 0;
}
