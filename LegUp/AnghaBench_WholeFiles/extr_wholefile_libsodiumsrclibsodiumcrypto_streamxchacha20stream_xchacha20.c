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
typedef  unsigned int uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  COMPILER_ASSERT (int) ; 
 int /*<<< orphan*/  crypto_core_hchacha20 (unsigned char*,unsigned char const*,unsigned char const*,int /*<<< orphan*/ *) ; 
 size_t crypto_core_hchacha20_INPUTBYTES ; 
 int crypto_core_hchacha20_OUTPUTBYTES ; 
 int crypto_stream_chacha20 (unsigned char*,unsigned long long,unsigned char const*,unsigned char*) ; 
 int crypto_stream_chacha20_KEYBYTES ; 
 size_t crypto_stream_chacha20_NONCEBYTES ; 
 int crypto_stream_chacha20_xor_ic (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned int,unsigned char*) ; 
 size_t crypto_stream_xchacha20_KEYBYTES ; 
 size_t crypto_stream_xchacha20_MESSAGEBYTES_MAX ; 
 size_t crypto_stream_xchacha20_NONCEBYTES ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_stream_xchacha20_keybytes(void)
{
    return crypto_stream_xchacha20_KEYBYTES;
}

size_t
crypto_stream_xchacha20_noncebytes(void)
{
    return crypto_stream_xchacha20_NONCEBYTES;
}

size_t
crypto_stream_xchacha20_messagebytes_max(void)
{
    return crypto_stream_xchacha20_MESSAGEBYTES_MAX;
}

int
crypto_stream_xchacha20(unsigned char *c, unsigned long long clen,
                        const unsigned char *n, const unsigned char *k)
{
    unsigned char k2[crypto_core_hchacha20_OUTPUTBYTES];

    crypto_core_hchacha20(k2, n, k, NULL);
    COMPILER_ASSERT(crypto_stream_chacha20_KEYBYTES <= sizeof k2);
    COMPILER_ASSERT(crypto_stream_chacha20_NONCEBYTES ==
                    crypto_stream_xchacha20_NONCEBYTES -
                        crypto_core_hchacha20_INPUTBYTES);

    return crypto_stream_chacha20(c, clen, n + crypto_core_hchacha20_INPUTBYTES,
                                  k2);
}

int
crypto_stream_xchacha20_xor_ic(unsigned char *c, const unsigned char *m,
                               unsigned long long mlen, const unsigned char *n,
                               uint64_t ic, const unsigned char *k)
{
    unsigned char k2[crypto_core_hchacha20_OUTPUTBYTES];

    crypto_core_hchacha20(k2, n, k, NULL);
    return crypto_stream_chacha20_xor_ic(
        c, m, mlen, n + crypto_core_hchacha20_INPUTBYTES, ic, k2);
}

int
crypto_stream_xchacha20_xor(unsigned char *c, const unsigned char *m,
                            unsigned long long mlen, const unsigned char *n,
                            const unsigned char *k)
{
    return crypto_stream_xchacha20_xor_ic(c, m, mlen, n, 0U, k);
}

void
crypto_stream_xchacha20_keygen(
    unsigned char k[crypto_stream_xchacha20_KEYBYTES])
{
    randombytes_buf(k, crypto_stream_xchacha20_KEYBYTES);
}

