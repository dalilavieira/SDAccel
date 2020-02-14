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
typedef  int /*<<< orphan*/  crypto_generichash_state ;
typedef  int /*<<< orphan*/  crypto_generichash_blake2b_state ;

/* Variables and functions */
 size_t crypto_generichash_BYTES ; 
 size_t crypto_generichash_BYTES_MAX ; 
 size_t crypto_generichash_BYTES_MIN ; 
 size_t crypto_generichash_KEYBYTES ; 
 size_t crypto_generichash_KEYBYTES_MAX ; 
 size_t crypto_generichash_KEYBYTES_MIN ; 
 char const* crypto_generichash_PRIMITIVE ; 
 int crypto_generichash_blake2b (unsigned char*,size_t,unsigned char const*,unsigned long long,unsigned char const*,size_t) ; 
 int crypto_generichash_blake2b_final (int /*<<< orphan*/ *,unsigned char*,size_t const) ; 
 int crypto_generichash_blake2b_init (int /*<<< orphan*/ *,unsigned char const*,size_t const,size_t const) ; 
 int crypto_generichash_blake2b_update (int /*<<< orphan*/ *,unsigned char const*,unsigned long long) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_generichash_bytes_min(void)
{
    return crypto_generichash_BYTES_MIN;
}

size_t
crypto_generichash_bytes_max(void)
{
    return crypto_generichash_BYTES_MAX;
}

size_t
crypto_generichash_bytes(void)
{
    return crypto_generichash_BYTES;
}

size_t
crypto_generichash_keybytes_min(void)
{
    return crypto_generichash_KEYBYTES_MIN;
}

size_t
crypto_generichash_keybytes_max(void)
{
    return crypto_generichash_KEYBYTES_MAX;
}

size_t
crypto_generichash_keybytes(void)
{
    return crypto_generichash_KEYBYTES;
}

const char *
crypto_generichash_primitive(void)
{
    return crypto_generichash_PRIMITIVE;
}

size_t
crypto_generichash_statebytes(void)
{
    return (sizeof(crypto_generichash_state) + (size_t) 63U) & ~(size_t) 63U;
}

int
crypto_generichash(unsigned char *out, size_t outlen, const unsigned char *in,
                   unsigned long long inlen, const unsigned char *key,
                   size_t keylen)
{
    return crypto_generichash_blake2b(out, outlen, in, inlen, key, keylen);
}

int
crypto_generichash_init(crypto_generichash_state *state,
                        const unsigned char *key,
                        const size_t keylen, const size_t outlen)
{
    return crypto_generichash_blake2b_init
        ((crypto_generichash_blake2b_state *) state, key, keylen, outlen);
}

int
crypto_generichash_update(crypto_generichash_state *state,
                          const unsigned char *in,
                          unsigned long long inlen)
{
    return crypto_generichash_blake2b_update
        ((crypto_generichash_blake2b_state *) state, in, inlen);
}

int
crypto_generichash_final(crypto_generichash_state *state,
                         unsigned char *out, const size_t outlen)
{
    return crypto_generichash_blake2b_final
        ((crypto_generichash_blake2b_state *) state, out, outlen);
}

void
crypto_generichash_keygen(unsigned char k[crypto_generichash_KEYBYTES])
{
    randombytes_buf(k, crypto_generichash_KEYBYTES);
}

