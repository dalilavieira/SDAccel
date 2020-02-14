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

/* Variables and functions */
 size_t crypto_shorthash_BYTES ; 
 size_t crypto_shorthash_KEYBYTES ; 
 char const* crypto_shorthash_PRIMITIVE ; 
 int crypto_shorthash_siphash24 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_shorthash_bytes(void)
{
    return crypto_shorthash_BYTES;
}

size_t
crypto_shorthash_keybytes(void)
{
    return crypto_shorthash_KEYBYTES;
}

const char *
crypto_shorthash_primitive(void)
{
    return crypto_shorthash_PRIMITIVE;
}

int
crypto_shorthash(unsigned char *out, const unsigned char *in,
                 unsigned long long inlen, const unsigned char *k)
{
    return crypto_shorthash_siphash24(out, in, inlen, k);
}

void
crypto_shorthash_keygen(unsigned char k[crypto_shorthash_KEYBYTES])
{
    randombytes_buf(k, crypto_shorthash_KEYBYTES);
}

