
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    unsigned char key[24] =
        "12345678901234567890123";
    unsigned char iv[8] = "1234567";
    unsigned char plaintext[] = "HELLO CBC MODE";
    unsigned char ciphertext[128];

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len = 0, total = 0;

    if (!ctx) {
        printf("Context creation failed\n");
        return 1;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(),
                          NULL, key, iv) != 1) {
        printf("Encryption initialization failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    if (EVP_EncryptUpdate(ctx, ciphertext, &len,
                          plaintext, strlen((char *)plaintext)) != 1) {
        printf("Encryption failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    total = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + total, &len) != 1) {
        printf("Final encryption failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    total += len;

    printf("Ciphertext (hex): ");
    for (int i = 0; i < total; i++)
        printf("%02X", ciphertext[i]);
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);
    return 0;
}
