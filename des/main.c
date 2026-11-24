#include "des.h"
#include <stdio.h>
#include <inttypes.h>

int main(void) {
    uint64_t key = UINT64_C(0x133457799BBCDFF1);
    uint64_t plain = UINT64_C(0x0123456789ABCDEF);
    uint64_t expected = UINT64_C(0x85E813540F0AB405);
    uint64_t keys[16];
    des_key_schedule(key, keys);
    printf("MA HOA\n");
    uint64_t cipher = des_encrypt(plain, keys, 1);
    printf("\nGIAI MA\n");
    uint64_t recovered = des_decrypt(cipher, keys, 1);
    printf("\nPlaintext : %016" PRIX64 "\n", plain);
    printf("Key       : %016" PRIX64 "\n", key);
    printf("Expected  : %016" PRIX64 "\n", expected);
    printf("Ciphertext: %016" PRIX64 "\n", cipher);
    printf("Recovered : %016" PRIX64 "\n", recovered);
    int ok = cipher == expected && recovered == plain;
    printf("Test: %s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}