
#include <stdio.h>

long long power(int a, int x, int q) {
    long long r = 1;
    while(x > 0) {
        r = (r * a) % q;
        x--;
    }
    return r;
}

int main() {
    int q = 23, a = 5;
    int x, y;
    long long A, B, key1, key2;

    printf("Enter Alice's secret number: ");
    scanf("%d", &x);

    printf("Enter Bob's secret number: ");
    scanf("%d", &y);

    A = power(a, x, q);
    B = power(a, y, q);

    key1 = power(B, x, q);
    key2 = power(A, y, q);

    printf("Alice sends: %lld\n", A);
    printf("Bob sends: %lld\n", B);
    printf("Alice's shared key: %lld\n", key1);
    printf("Bob's shared key: %lld\n", key2);

    return 0;
}
