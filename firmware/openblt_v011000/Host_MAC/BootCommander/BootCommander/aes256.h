//
//  aes256.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        uint8_t key[32];
        uint8_t enckey[32];
        uint8_t deckey[32];
    } aes256_context;


    void aes256_init(aes256_context *, uint8_t const * /* key */);
    void aes256_done(aes256_context *);
    void aes256_encrypt_ecb(aes256_context *, uint8_t * /* plaintext */);
    void aes256_decrypt_ecb(aes256_context *, uint8_t * /* cipertext */);

#ifdef __cplusplus
}
#endif
