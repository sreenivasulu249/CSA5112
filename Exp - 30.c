
#include <stdio.h>

int main() {
    int K, X, T, C1, C2;

    printf("Enter key: ");
    scanf("%d", &K);

    printf("Enter one-block message X: ");
    scanf("%d", &X);

    C1 = X ^ K;
    T = C1;

    C2 = (X ^ T) ^ K;

    printf("MAC of X: %d\n", T);
    printf("Second block: %d\n", X ^ T);
    printf("CBC-MAC of X || (X XOR T): %d\n", C2);

    return 0;
}
