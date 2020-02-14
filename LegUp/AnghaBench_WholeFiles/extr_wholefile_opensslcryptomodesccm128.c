#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  mlen ;
typedef  int /*<<< orphan*/  (* ccm128_f ) (unsigned char const*,unsigned char*,size_t,void*,int*,int*) ;
typedef  int /*<<< orphan*/  (* block128_f ) (int*,int*,void*) ;
typedef  int /*<<< orphan*/  alen ;
struct TYPE_13__ {int* c; int* u; } ;
struct TYPE_12__ {int* c; scalar_t__* u; } ;
struct TYPE_14__ {int blocks; void* key; TYPE_2__ cmac; TYPE_1__ nonce; int /*<<< orphan*/  (* block ) (int*,int*,void*) ;} ;
typedef  TYPE_3__ CCM128_CONTEXT ;

/* Variables and functions */
 int U64 (int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,unsigned int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub10 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub11 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub12 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub13 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub14 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub15 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub16 (unsigned char const*,unsigned char*,size_t,void*,int*,int*) ; 
 int /*<<< orphan*/  stub17 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub18 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub19 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub2 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub20 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub21 (unsigned char const*,unsigned char*,size_t,void*,int*,int*) ; 
 int /*<<< orphan*/  stub22 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub23 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub24 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub3 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub4 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub5 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub6 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub7 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub8 (int*,int*,void*) ; 
 int /*<<< orphan*/  stub9 (int*,int*,void*) ; 

void CRYPTO_ccm128_init(CCM128_CONTEXT *ctx,
                        unsigned int M, unsigned int L, void *key,
                        block128_f block)
{
    memset(ctx->nonce.c, 0, sizeof(ctx->nonce.c));
    ctx->nonce.c[0] = ((u8)(L - 1) & 7) | (u8)(((M - 2) / 2) & 7) << 3;
    ctx->blocks = 0;
    ctx->block = block;
    ctx->key = key;
}

int CRYPTO_ccm128_setiv(CCM128_CONTEXT *ctx,
                        const unsigned char *nonce, size_t nlen, size_t mlen)
{
    unsigned int L = ctx->nonce.c[0] & 7; /* the L parameter */

    if (nlen < (14 - L))
        return -1;              /* nonce is too short */

    if (sizeof(mlen) == 8 && L >= 3) {
        ctx->nonce.c[8] = (u8)(mlen >> (56 % (sizeof(mlen) * 8)));
        ctx->nonce.c[9] = (u8)(mlen >> (48 % (sizeof(mlen) * 8)));
        ctx->nonce.c[10] = (u8)(mlen >> (40 % (sizeof(mlen) * 8)));
        ctx->nonce.c[11] = (u8)(mlen >> (32 % (sizeof(mlen) * 8)));
    } else
        ctx->nonce.u[1] = 0;

    ctx->nonce.c[12] = (u8)(mlen >> 24);
    ctx->nonce.c[13] = (u8)(mlen >> 16);
    ctx->nonce.c[14] = (u8)(mlen >> 8);
    ctx->nonce.c[15] = (u8)mlen;

    ctx->nonce.c[0] &= ~0x40;   /* clear Adata flag */
    memcpy(&ctx->nonce.c[1], nonce, 14 - L);

    return 0;
}

void CRYPTO_ccm128_aad(CCM128_CONTEXT *ctx,
                       const unsigned char *aad, size_t alen)
{
    unsigned int i;
    block128_f block = ctx->block;

    if (alen == 0)
        return;

    ctx->nonce.c[0] |= 0x40;    /* set Adata flag */
    (*block) (ctx->nonce.c, ctx->cmac.c, ctx->key), ctx->blocks++;

    if (alen < (0x10000 - 0x100)) {
        ctx->cmac.c[0] ^= (u8)(alen >> 8);
        ctx->cmac.c[1] ^= (u8)alen;
        i = 2;
    } else if (sizeof(alen) == 8
               && alen >= (size_t)1 << (32 % (sizeof(alen) * 8))) {
        ctx->cmac.c[0] ^= 0xFF;
        ctx->cmac.c[1] ^= 0xFF;
        ctx->cmac.c[2] ^= (u8)(alen >> (56 % (sizeof(alen) * 8)));
        ctx->cmac.c[3] ^= (u8)(alen >> (48 % (sizeof(alen) * 8)));
        ctx->cmac.c[4] ^= (u8)(alen >> (40 % (sizeof(alen) * 8)));
        ctx->cmac.c[5] ^= (u8)(alen >> (32 % (sizeof(alen) * 8)));
        ctx->cmac.c[6] ^= (u8)(alen >> 24);
        ctx->cmac.c[7] ^= (u8)(alen >> 16);
        ctx->cmac.c[8] ^= (u8)(alen >> 8);
        ctx->cmac.c[9] ^= (u8)alen;
        i = 10;
    } else {
        ctx->cmac.c[0] ^= 0xFF;
        ctx->cmac.c[1] ^= 0xFE;
        ctx->cmac.c[2] ^= (u8)(alen >> 24);
        ctx->cmac.c[3] ^= (u8)(alen >> 16);
        ctx->cmac.c[4] ^= (u8)(alen >> 8);
        ctx->cmac.c[5] ^= (u8)alen;
        i = 6;
    }

    do {
        for (; i < 16 && alen; ++i, ++aad, --alen)
            ctx->cmac.c[i] ^= *aad;
        (*block) (ctx->cmac.c, ctx->cmac.c, ctx->key), ctx->blocks++;
        i = 0;
    } while (alen);
}

__attribute__((used)) static void ctr64_inc(unsigned char *counter)
{
    unsigned int n = 8;
    u8 c;

    counter += 8;
    do {
        --n;
        c = counter[n];
        ++c;
        counter[n] = c;
        if (c)
            return;
    } while (n);
}

int CRYPTO_ccm128_encrypt(CCM128_CONTEXT *ctx,
                          const unsigned char *inp, unsigned char *out,
                          size_t len)
{
    size_t n;
    unsigned int i, L;
    unsigned char flags0 = ctx->nonce.c[0];
    block128_f block = ctx->block;
    void *key = ctx->key;
    union {
        u64 u[2];
        u8 c[16];
    } scratch;

    if (!(flags0 & 0x40))
        (*block) (ctx->nonce.c, ctx->cmac.c, key), ctx->blocks++;

    ctx->nonce.c[0] = L = flags0 & 7;
    for (n = 0, i = 15 - L; i < 15; ++i) {
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
    }
    n |= ctx->nonce.c[15];      /* reconstructed length */
    ctx->nonce.c[15] = 1;

    if (n != len)
        return -1;              /* length mismatch */

    ctx->blocks += ((len + 15) >> 3) | 1;
    if (ctx->blocks > (U64(1) << 61))
        return -2;              /* too much data */

    while (len >= 16) {
#if defined(STRICT_ALIGNMENT)
        union {
            u64 u[2];
            u8 c[16];
        } temp;

        memcpy(temp.c, inp, 16);
        ctx->cmac.u[0] ^= temp.u[0];
        ctx->cmac.u[1] ^= temp.u[1];
#else
        ctx->cmac.u[0] ^= ((u64 *)inp)[0];
        ctx->cmac.u[1] ^= ((u64 *)inp)[1];
#endif
        (*block) (ctx->cmac.c, ctx->cmac.c, key);
        (*block) (ctx->nonce.c, scratch.c, key);
        ctr64_inc(ctx->nonce.c);
#if defined(STRICT_ALIGNMENT)
        temp.u[0] ^= scratch.u[0];
        temp.u[1] ^= scratch.u[1];
        memcpy(out, temp.c, 16);
#else
        ((u64 *)out)[0] = scratch.u[0] ^ ((u64 *)inp)[0];
        ((u64 *)out)[1] = scratch.u[1] ^ ((u64 *)inp)[1];
#endif
        inp += 16;
        out += 16;
        len -= 16;
    }

    if (len) {
        for (i = 0; i < len; ++i)
            ctx->cmac.c[i] ^= inp[i];
        (*block) (ctx->cmac.c, ctx->cmac.c, key);
        (*block) (ctx->nonce.c, scratch.c, key);
        for (i = 0; i < len; ++i)
            out[i] = scratch.c[i] ^ inp[i];
    }

    for (i = 15 - L; i < 16; ++i)
        ctx->nonce.c[i] = 0;

    (*block) (ctx->nonce.c, scratch.c, key);
    ctx->cmac.u[0] ^= scratch.u[0];
    ctx->cmac.u[1] ^= scratch.u[1];

    ctx->nonce.c[0] = flags0;

    return 0;
}

int CRYPTO_ccm128_decrypt(CCM128_CONTEXT *ctx,
                          const unsigned char *inp, unsigned char *out,
                          size_t len)
{
    size_t n;
    unsigned int i, L;
    unsigned char flags0 = ctx->nonce.c[0];
    block128_f block = ctx->block;
    void *key = ctx->key;
    union {
        u64 u[2];
        u8 c[16];
    } scratch;

    if (!(flags0 & 0x40))
        (*block) (ctx->nonce.c, ctx->cmac.c, key);

    ctx->nonce.c[0] = L = flags0 & 7;
    for (n = 0, i = 15 - L; i < 15; ++i) {
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
    }
    n |= ctx->nonce.c[15];      /* reconstructed length */
    ctx->nonce.c[15] = 1;

    if (n != len)
        return -1;

    while (len >= 16) {
#if defined(STRICT_ALIGNMENT)
        union {
            u64 u[2];
            u8 c[16];
        } temp;
#endif
        (*block) (ctx->nonce.c, scratch.c, key);
        ctr64_inc(ctx->nonce.c);
#if defined(STRICT_ALIGNMENT)
        memcpy(temp.c, inp, 16);
        ctx->cmac.u[0] ^= (scratch.u[0] ^= temp.u[0]);
        ctx->cmac.u[1] ^= (scratch.u[1] ^= temp.u[1]);
        memcpy(out, scratch.c, 16);
#else
        ctx->cmac.u[0] ^= (((u64 *)out)[0] = scratch.u[0] ^ ((u64 *)inp)[0]);
        ctx->cmac.u[1] ^= (((u64 *)out)[1] = scratch.u[1] ^ ((u64 *)inp)[1]);
#endif
        (*block) (ctx->cmac.c, ctx->cmac.c, key);

        inp += 16;
        out += 16;
        len -= 16;
    }

    if (len) {
        (*block) (ctx->nonce.c, scratch.c, key);
        for (i = 0; i < len; ++i)
            ctx->cmac.c[i] ^= (out[i] = scratch.c[i] ^ inp[i]);
        (*block) (ctx->cmac.c, ctx->cmac.c, key);
    }

    for (i = 15 - L; i < 16; ++i)
        ctx->nonce.c[i] = 0;

    (*block) (ctx->nonce.c, scratch.c, key);
    ctx->cmac.u[0] ^= scratch.u[0];
    ctx->cmac.u[1] ^= scratch.u[1];

    ctx->nonce.c[0] = flags0;

    return 0;
}

__attribute__((used)) static void ctr64_add(unsigned char *counter, size_t inc)
{
    size_t n = 8, val = 0;

    counter += 8;
    do {
        --n;
        val += counter[n] + (inc & 0xff);
        counter[n] = (unsigned char)val;
        val >>= 8;              /* carry bit */
        inc >>= 8;
    } while (n && (inc || val));
}

int CRYPTO_ccm128_encrypt_ccm64(CCM128_CONTEXT *ctx,
                                const unsigned char *inp, unsigned char *out,
                                size_t len, ccm128_f stream)
{
    size_t n;
    unsigned int i, L;
    unsigned char flags0 = ctx->nonce.c[0];
    block128_f block = ctx->block;
    void *key = ctx->key;
    union {
        u64 u[2];
        u8 c[16];
    } scratch;

    if (!(flags0 & 0x40))
        (*block) (ctx->nonce.c, ctx->cmac.c, key), ctx->blocks++;

    ctx->nonce.c[0] = L = flags0 & 7;
    for (n = 0, i = 15 - L; i < 15; ++i) {
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
    }
    n |= ctx->nonce.c[15];      /* reconstructed length */
    ctx->nonce.c[15] = 1;

    if (n != len)
        return -1;              /* length mismatch */

    ctx->blocks += ((len + 15) >> 3) | 1;
    if (ctx->blocks > (U64(1) << 61))
        return -2;              /* too much data */

    if ((n = len / 16)) {
        (*stream) (inp, out, n, key, ctx->nonce.c, ctx->cmac.c);
        n *= 16;
        inp += n;
        out += n;
        len -= n;
        if (len)
            ctr64_add(ctx->nonce.c, n / 16);
    }

    if (len) {
        for (i = 0; i < len; ++i)
            ctx->cmac.c[i] ^= inp[i];
        (*block) (ctx->cmac.c, ctx->cmac.c, key);
        (*block) (ctx->nonce.c, scratch.c, key);
        for (i = 0; i < len; ++i)
            out[i] = scratch.c[i] ^ inp[i];
    }

    for (i = 15 - L; i < 16; ++i)
        ctx->nonce.c[i] = 0;

    (*block) (ctx->nonce.c, scratch.c, key);
    ctx->cmac.u[0] ^= scratch.u[0];
    ctx->cmac.u[1] ^= scratch.u[1];

    ctx->nonce.c[0] = flags0;

    return 0;
}

int CRYPTO_ccm128_decrypt_ccm64(CCM128_CONTEXT *ctx,
                                const unsigned char *inp, unsigned char *out,
                                size_t len, ccm128_f stream)
{
    size_t n;
    unsigned int i, L;
    unsigned char flags0 = ctx->nonce.c[0];
    block128_f block = ctx->block;
    void *key = ctx->key;
    union {
        u64 u[2];
        u8 c[16];
    } scratch;

    if (!(flags0 & 0x40))
        (*block) (ctx->nonce.c, ctx->cmac.c, key);

    ctx->nonce.c[0] = L = flags0 & 7;
    for (n = 0, i = 15 - L; i < 15; ++i) {
        n |= ctx->nonce.c[i];
        ctx->nonce.c[i] = 0;
        n <<= 8;
    }
    n |= ctx->nonce.c[15];      /* reconstructed length */
    ctx->nonce.c[15] = 1;

    if (n != len)
        return -1;

    if ((n = len / 16)) {
        (*stream) (inp, out, n, key, ctx->nonce.c, ctx->cmac.c);
        n *= 16;
        inp += n;
        out += n;
        len -= n;
        if (len)
            ctr64_add(ctx->nonce.c, n / 16);
    }

    if (len) {
        (*block) (ctx->nonce.c, scratch.c, key);
        for (i = 0; i < len; ++i)
            ctx->cmac.c[i] ^= (out[i] = scratch.c[i] ^ inp[i]);
        (*block) (ctx->cmac.c, ctx->cmac.c, key);
    }

    for (i = 15 - L; i < 16; ++i)
        ctx->nonce.c[i] = 0;

    (*block) (ctx->nonce.c, scratch.c, key);
    ctx->cmac.u[0] ^= scratch.u[0];
    ctx->cmac.u[1] ^= scratch.u[1];

    ctx->nonce.c[0] = flags0;

    return 0;
}

size_t CRYPTO_ccm128_tag(CCM128_CONTEXT *ctx, unsigned char *tag, size_t len)
{
    unsigned int M = (ctx->nonce.c[0] >> 3) & 7; /* the M parameter */

    M *= 2;
    M += 2;
    if (len != M)
        return 0;
    memcpy(tag, ctx->cmac.c, M);
    return M;
}

