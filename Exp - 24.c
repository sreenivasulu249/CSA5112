
#include <stdio.h>

int main() {
    int e = 31, n = 3599;
    int p, q, phi, d, i;

    for(i = 2; i <= n; i++) {
        if(n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    phi = (p - 1) * (q - 1);

    for(d = 1; d < phi; d++) {
        if((e * d) % phi == 1)
            break;
    }

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("Phi(n) = %d\n", phi);
    printf("Public Key = (%d, %d)\n", e, n);
    printf("Private Key = (%d, %d)\n", d, n);

    return 0;
}
