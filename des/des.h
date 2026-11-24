#ifndef DES_H
#define DES_H
#include <stdint.h>

/* Tao 16 khoa con, moi khoa dung 48 bit. */
void des_key_schedule(uint64_t key, uint64_t subkeys[16]);
/* Ma hoa mot khoi 64 bit; trace = 1 de in cac buoc. */
uint64_t des_encrypt(uint64_t plaintext,const uint64_t subkeys[16],int trace);
/* Giai ma bang cach su dung khoa con theo thu tu nguoc. */
uint64_t des_decrypt(uint64_t ciphertext,const uint64_t subkeys[16],int trace);

#endif