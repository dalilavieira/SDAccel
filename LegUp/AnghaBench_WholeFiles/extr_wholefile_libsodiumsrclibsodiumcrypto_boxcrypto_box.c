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
 size_t crypto_box_BEFORENMBYTES ; 
 size_t crypto_box_BOXZEROBYTES ; 
 size_t crypto_box_MACBYTES ; 
 size_t crypto_box_MESSAGEBYTES_MAX ; 
 size_t crypto_box_NONCEBYTES ; 
 char const* crypto_box_PRIMITIVE ; 
 size_t crypto_box_PUBLICKEYBYTES ; 
 size_t crypto_box_SECRETKEYBYTES ; 
 size_t crypto_box_SEEDBYTES ; 
 size_t crypto_box_ZEROBYTES ; 
 int crypto_box_curve25519xsalsa20poly1305 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*,unsigned char const*) ; 
 int crypto_box_curve25519xsalsa20poly1305_afternm (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*) ; 
 int crypto_box_curve25519xsalsa20poly1305_beforenm (unsigned char*,unsigned char const*,unsigned char const*) ; 
 int crypto_box_curve25519xsalsa20poly1305_keypair (unsigned char*,unsigned char*) ; 
 int crypto_box_curve25519xsalsa20poly1305_open (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*,unsigned char const*) ; 
 int crypto_box_curve25519xsalsa20poly1305_open_afternm (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*) ; 
 int crypto_box_curve25519xsalsa20poly1305_seed_keypair (unsigned char*,unsigned char*,unsigned char const*) ; 

size_t
crypto_box_seedbytes(void)
{
    return crypto_box_SEEDBYTES;
}

size_t
crypto_box_publickeybytes(void)
{
    return crypto_box_PUBLICKEYBYTES;
}

size_t
crypto_box_secretkeybytes(void)
{
    return crypto_box_SECRETKEYBYTES;
}

size_t
crypto_box_beforenmbytes(void)
{
    return crypto_box_BEFORENMBYTES;
}

size_t
crypto_box_noncebytes(void)
{
    return crypto_box_NONCEBYTES;
}

size_t
crypto_box_zerobytes(void)
{
    return crypto_box_ZEROBYTES;
}

size_t
crypto_box_boxzerobytes(void)
{
    return crypto_box_BOXZEROBYTES;
}

size_t
crypto_box_macbytes(void)
{
    return crypto_box_MACBYTES;
}

size_t
crypto_box_messagebytes_max(void)
{
    return crypto_box_MESSAGEBYTES_MAX;
}

const char *
crypto_box_primitive(void)
{
    return crypto_box_PRIMITIVE;
}

int
crypto_box_seed_keypair(unsigned char *pk, unsigned char *sk,
                        const unsigned char *seed)
{
    return crypto_box_curve25519xsalsa20poly1305_seed_keypair(pk, sk, seed);
}

int
crypto_box_keypair(unsigned char *pk, unsigned char *sk)
{
    return crypto_box_curve25519xsalsa20poly1305_keypair(pk, sk);
}

int
crypto_box_beforenm(unsigned char *k, const unsigned char *pk,
                    const unsigned char *sk)
{
    return crypto_box_curve25519xsalsa20poly1305_beforenm(k, pk, sk);
}

int
crypto_box_afternm(unsigned char *c, const unsigned char *m,
                   unsigned long long mlen, const unsigned char *n,
                   const unsigned char *k)
{
    return crypto_box_curve25519xsalsa20poly1305_afternm(c, m, mlen, n, k);
}

int
crypto_box_open_afternm(unsigned char *m, const unsigned char *c,
                        unsigned long long clen, const unsigned char *n,
                        const unsigned char *k)
{
    return crypto_box_curve25519xsalsa20poly1305_open_afternm(m, c, clen, n, k);
}

int
crypto_box(unsigned char *c, const unsigned char *m,
           unsigned long long mlen, const unsigned char *n,
           const unsigned char *pk, const unsigned char *sk)
{
    return crypto_box_curve25519xsalsa20poly1305(c, m, mlen, n, pk, sk);
}

int
crypto_box_open(unsigned char *m, const unsigned char *c,
                unsigned long long clen, const unsigned char *n,
                const unsigned char *pk, const unsigned char *sk)
{
    return crypto_box_curve25519xsalsa20poly1305_open(m, c, clen, n, pk, sk);
}

