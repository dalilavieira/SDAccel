#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  crypto_auth_hmacsha512_state ;
typedef  int /*<<< orphan*/  crypto_auth_hmacsha512256_state ;

/* Variables and functions */
 size_t crypto_auth_hmacsha512256_BYTES ; 
 size_t crypto_auth_hmacsha512256_KEYBYTES ; 
 int /*<<< orphan*/  crypto_auth_hmacsha512_final (int /*<<< orphan*/ *,unsigned char*) ; 
 int crypto_auth_hmacsha512_init (int /*<<< orphan*/ *,unsigned char const*,size_t) ; 
 int crypto_auth_hmacsha512_update (int /*<<< orphan*/ *,unsigned char const*,unsigned long long) ; 
 int crypto_verify_32 (unsigned char const*,unsigned char*) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 
 int sodium_memcmp (unsigned char*,unsigned char const*,int) ; 

size_t
crypto_auth_hmacsha512256_bytes(void)
{
    return crypto_auth_hmacsha512256_BYTES;
}

size_t
crypto_auth_hmacsha512256_keybytes(void)
{
    return crypto_auth_hmacsha512256_KEYBYTES;
}

size_t
crypto_auth_hmacsha512256_statebytes(void)
{
    return sizeof(crypto_auth_hmacsha512256_state);
}

void
crypto_auth_hmacsha512256_keygen(
    unsigned char k[crypto_auth_hmacsha512256_KEYBYTES])
{
    randombytes_buf(k, crypto_auth_hmacsha512256_KEYBYTES);
}

int
crypto_auth_hmacsha512256_init(crypto_auth_hmacsha512256_state *state,
                               const unsigned char *key, size_t keylen)
{
    return crypto_auth_hmacsha512_init((crypto_auth_hmacsha512_state *) state,
                                       key, keylen);
}

int
crypto_auth_hmacsha512256_update(crypto_auth_hmacsha512256_state *state,
                                 const unsigned char             *in,
                                 unsigned long long               inlen)
{
    return crypto_auth_hmacsha512_update((crypto_auth_hmacsha512_state *) state,
                                         in, inlen);
}

int
crypto_auth_hmacsha512256_final(crypto_auth_hmacsha512256_state *state,
                                unsigned char                   *out)
{
    unsigned char out0[64];

    crypto_auth_hmacsha512_final((crypto_auth_hmacsha512_state *) state, out0);
    memcpy(out, out0, 32);

    return 0;
}

int
crypto_auth_hmacsha512256(unsigned char *out, const unsigned char *in,
                          unsigned long long inlen, const unsigned char *k)
{
    crypto_auth_hmacsha512256_state state;

    crypto_auth_hmacsha512256_init(&state, k,
                                   crypto_auth_hmacsha512256_KEYBYTES);
    crypto_auth_hmacsha512256_update(&state, in, inlen);
    crypto_auth_hmacsha512256_final(&state, out);

    return 0;
}

int
crypto_auth_hmacsha512256_verify(const unsigned char *h,
                                 const unsigned char *in,
                                 unsigned long long   inlen,
                                 const unsigned char *k)
{
    unsigned char correct[32];

    crypto_auth_hmacsha512256(correct, in, inlen, k);

    return crypto_verify_32(h, correct) | (-(h == correct)) |
           sodium_memcmp(correct, h, 32);
}

