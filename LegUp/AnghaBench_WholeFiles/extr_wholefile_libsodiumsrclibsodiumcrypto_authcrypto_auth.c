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
 size_t crypto_auth_BYTES ; 
 size_t crypto_auth_KEYBYTES ; 
 char const* crypto_auth_PRIMITIVE ; 
 int crypto_auth_hmacsha512256 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*) ; 
 int crypto_auth_hmacsha512256_verify (unsigned char const*,unsigned char const*,unsigned long long,unsigned char const*) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_auth_bytes(void)
{
    return crypto_auth_BYTES;
}

size_t
crypto_auth_keybytes(void)
{
    return crypto_auth_KEYBYTES;
}

const char *
crypto_auth_primitive(void)
{
    return crypto_auth_PRIMITIVE;
}

int
crypto_auth(unsigned char *out, const unsigned char *in,
            unsigned long long inlen, const unsigned char *k)
{
    return crypto_auth_hmacsha512256(out, in, inlen, k);
}

int
crypto_auth_verify(const unsigned char *h, const unsigned char *in,
                   unsigned long long inlen,const unsigned char *k)
{
    return crypto_auth_hmacsha512256_verify(h, in, inlen, k);
}

void
crypto_auth_keygen(unsigned char k[crypto_auth_KEYBYTES])
{
    randombytes_buf(k, crypto_auth_KEYBYTES);
}

