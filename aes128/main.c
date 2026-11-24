#include "aes.h"
#include <stdio.h>
#include <string.h>

static void print_hex(const char *name, const uint8_t a[16]) {
    printf("%-10s: ", name);
    for (int i = 0; i < 16; i++) printf("%02X", (unsigned)a[i]);
    putchar('\n');
}

int main(void) {
    const uint8_t plain[16] = {
        0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
        0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
    };
    const uint8_t key[16] = {
        0x0f,0x15,0x71,0xc9,0x47,0xd9,0xe8,0x59,
        0x0c,0xb7,0xad,0xd6,0xaf,0x7f,0x67,0x98
    };
    const uint8_t expected[16] = {
        0xff,0x0b,0x84,0x4a,0x08,0x53,0xbf,0x7c,
        0x69,0x34,0xab,0x43,0x64,0x14,0x8f,0xb9
    };
    uint8_t keys[176], cipher[16], recovered[16];

    aes_key_expand(key, keys);
    const uint8_t expected_k1[16] = {
    0xdc,0x90,0x37,0xb0,0x9b,0x49,0xdf,0xe9,
    0x97,0xfe,0x72,0x3f,0x38,0x81,0x15,0xa7
};
int key_ok = memcmp(keys + 16, expected_k1, 16) == 0;
printf("Kiem tra khoa vong 1: %s\n", key_ok ? "PASS" : "FAIL");
    puts("MA HOA");
    aes_encrypt(plain, cipher, keys, 1);
    puts("\nGIAI MA");
    aes_decrypt(cipher, recovered, keys, 1);

    puts("");
    print_hex("Plaintext", plain);
    print_hex("Key", key);
    print_hex("Expected", expected);
    print_hex("Ciphertext", cipher);
    print_hex("Recovered", recovered);

    int enc_ok = memcmp(cipher, expected, 16) == 0;
    int dec_ok = memcmp(recovered, plain, 16) == 0;
    printf("Ma hoa: %s\n", enc_ok ? "PASS" : "FAIL");
    printf("Giai ma: %s\n", dec_ok ? "PASS" : "FAIL");
    return key_ok && enc_ok && dec_ok ? 0 : 1;
}