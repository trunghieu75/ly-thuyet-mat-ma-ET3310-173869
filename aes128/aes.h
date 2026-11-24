#ifndef AES_H
#define AES_H
#include <stdint.h>
void aes_key_expand(const uint8_t key[16], uint8_t keys[176]);
void aes_encrypt(const uint8_t input[16], uint8_t output[16],const uint8_t keys[176], int trace);
void aes_decrypt(const uint8_t input[16], uint8_t output[16],const uint8_t keys[176], int trace);
#endif