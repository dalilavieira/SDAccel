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
 size_t crypto_stream_KEYBYTES ; 
 size_t crypto_stream_MESSAGEBYTES_MAX ; 
 size_t crypto_stream_NONCEBYTES ; 
 char const* crypto_stream_PRIMITIVE ; 
 int crypto_stream_xsalsa20 (unsigned char*,unsigned long long,unsigned char const*,unsigned char const*) ; 
 int crypto_stream_xsalsa20_xor (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_stream_keybytes(void)
{
    return crypto_stream_KEYBYTES;
}

size_t
crypto_stream_noncebytes(void)
{
    return crypto_stream_NONCEBYTES;
}

size_t
crypto_stream_messagebytes_max(void)
{
    return crypto_stream_MESSAGEBYTES_MAX;
}

const char *
crypto_stream_primitive(void)
{
    return crypto_stream_PRIMITIVE;
}

int
crypto_stream(unsigned char *c, unsigned long long clen,
              const unsigned char *n, const unsigned char *k)
{
    return crypto_stream_xsalsa20(c, clen, n, k);
}

int
crypto_stream_xor(unsigned char *c, const unsigned char *m,
                  unsigned long long mlen, const unsigned char *n,
                  const unsigned char *k)
{
    return crypto_stream_xsalsa20_xor(c, m, mlen, n, k);
}

void
crypto_stream_keygen(unsigned char k[crypto_stream_KEYBYTES])
{
    randombytes_buf(k, crypto_stream_KEYBYTES);
}

