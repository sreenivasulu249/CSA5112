#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024
#define MAX_SYM 128

struct Mapping {
    char cipher;
    char plain;
} map[] = {
    {'8', 'e'}, {';', 't'}, {'4', 'h'}, {'‡', 'o'}, {')', 's'},
    {'*', 'n'}, {'5', 'a'}, {'6', 'i'}, {'(', 'r'}, {'†', 'd'},
    {'1', 'f'}, {'0', 'l'}, {'2', 'b'}, {'3', 'g'}, {':', 'y'},
    {'?', 'u'}, {'¶', 'v'}, {'9', 'm'}, {'.', 'p'}, {'-', 'c'},
    {']', 'w'}, {'\0', '\0'}
};

char decrypt_char(char c) {
    for (int i = 0; map[i].cipher != '\0'; i++) {
        if (map[i].cipher == c)
            return map[i].plain;
    }
    return c;
}

int main(void) {
    const char *ciphertext =
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    int freq[MAX_SYM] = {0};
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        unsigned char c = ciphertext[i];
        if (c < MAX_SYM)
            freq[c]++;
    }

    printf("=== Frequency Analysis (most → least frequent) ===\n");
    for (int pass = 0; pass < 40; pass++) {
        int max = 0, max_idx = -1;
        for (int i = 0; i < MAX_SYM; i++) {
            if (freq[i] > max) {
                max = freq[i];
                max_idx 
