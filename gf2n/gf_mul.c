#include "gf_mul.h"
uint8_t gf4_mul(uint8_t a, uint8_t b) {
    uint8_t result = 0;
for (int i = 0; i < 4; i++) {
    if (b & 1) {
            result ^= a;
        }
uint8_t carry = a & 0x08;
       a <<= 1;
if (carry) {
        a ^= 0x13;
        }
        b >>= 1;
    }
 return result;
}

uint8_t gf8_mul(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            result ^= a;
        }

        uint8_t carry = a & 0x80;

        a <<= 1;

        if (carry) {
            a ^= 0x1B;
        }

        b >>= 1;
    }
return result;
}
