#include <stdio.h>
#include <stdint.h>
#include "gf_mul.h"
int main(void) {
    uint8_t a = 0x08;
    uint8_t b = 0x02;
    uint8_t result = gf4_mul(a, b);

    printf("GF(2^4)\n");
    printf("A = 0x%X\n", (unsigned)a);
    printf("B = 0x%X\n", (unsigned)b);
    printf("Ket qua = 0x%X\n", (unsigned)result);
    
    uint8_t a8 = 0x26;
    uint8_t b8 = 0x9E;
    uint8_t result8 = gf8_mul(a8, b8);

    printf("\nGF(2^8)\n");
    printf("A = 0x%X\n", (unsigned)a8);
    printf("B = 0x%X\n", (unsigned)b8);
    printf("Ket qua = 0x%X\n", (unsigned)result8);
    return 0;
}
