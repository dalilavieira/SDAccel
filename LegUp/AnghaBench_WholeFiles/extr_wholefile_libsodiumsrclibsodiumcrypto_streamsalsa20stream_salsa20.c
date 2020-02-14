#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint64_t ;
struct TYPE_3__ {int (* stream ) (unsigned char*,unsigned long long,unsigned char const*,unsigned char const*) ;int (* stream_xor_ic ) (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned int,unsigned char const*) ;} ;

/* Variables and functions */
 size_t crypto_stream_salsa20_KEYBYTES ; 
 size_t crypto_stream_salsa20_MESSAGEBYTES_MAX ; 
 size_t crypto_stream_salsa20_NONCEBYTES ; 
 TYPE_1__ crypto_stream_salsa20_ref_implementation ; 
 TYPE_1__* implementation ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 
 int stub1 (unsigned char*,unsigned long long,unsigned char const*,unsigned char const*) ; 
 int stub2 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned int,unsigned char const*) ; 
 int stub3 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned int,unsigned char const*) ; 

size_t
crypto_stream_salsa20_keybytes(void)
{
    return crypto_stream_salsa20_KEYBYTES;
}

size_t
crypto_stream_salsa20_noncebytes(void)
{
    return crypto_stream_salsa20_NONCEBYTES;
}

size_t
crypto_stream_salsa20_messagebytes_max(void)
{
    return crypto_stream_salsa20_MESSAGEBYTES_MAX;
}

int
crypto_stream_salsa20(unsigned char *c, unsigned long long clen,
                      const unsigned char *n, const unsigned char *k)
{
    return implementation->stream(c, clen, n, k);
}

int
crypto_stream_salsa20_xor_ic(unsigned char *c, const unsigned char *m,
                             unsigned long long mlen,
                             const unsigned char *n, uint64_t ic,
                             const unsigned char *k)
{
    return implementation->stream_xor_ic(c, m, mlen, n, ic, k);
}

int
crypto_stream_salsa20_xor(unsigned char *c, const unsigned char *m,
                          unsigned long long mlen, const unsigned char *n,
                          const unsigned char *k)
{
    return implementation->stream_xor_ic(c, m, mlen, n, 0U, k);
}

void
crypto_stream_salsa20_keygen(unsigned char k[crypto_stream_salsa20_KEYBYTES])
{
    randombytes_buf(k, crypto_stream_salsa20_KEYBYTES);
}

int
_crypto_stream_salsa20_pick_best_implementation(void)
{
#ifdef HAVE_AMD64_ASM
    implementation = &crypto_stream_salsa20_xmm6_implementation;
#else
    implementation = &crypto_stream_salsa20_ref_implementation;
#endif

#if defined(HAVE_AVX2INTRIN_H) && defined(HAVE_EMMINTRIN_H) && \
    defined(HAVE_TMMINTRIN_H) && defined(HAVE_SMMINTRIN_H)
    if (sodium_runtime_has_avx2()) {
        implementation = &crypto_stream_salsa20_xmm6int_avx2_implementation;
        return 0;
    }
#endif
#if !defined(HAVE_AMD64_ASM) && defined(HAVE_EMMINTRIN_H)
    if (sodium_runtime_has_sse2()) {
        implementation = &crypto_stream_salsa20_xmm6int_sse2_implementation;
        return 0;
    }
#endif
    return 0; /* LCOV_EXCL_LINE */
}

