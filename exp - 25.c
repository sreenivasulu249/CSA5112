
#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, e, m, g;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter public key e: ");
    scanf("%d", &e);

    printf("Enter plaintext block: ");
    scanf("%d", &m);

    g = gcd(m, n);

    if(g > 1 && g < n) {
        printf("Common factor found: %d\n", g);
        printf("Other factor: %d\n", n / g);
        printf("RSA modulus is factored successfully.\n");
    }
    else {
        printf("No non-trivial common factor found.\n");
    }

    return 0;
}
