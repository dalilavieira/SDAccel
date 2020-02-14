#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char uint8_t ;
typedef  int uint64_t ;
struct TYPE_7__ {size_t hash_size; int v1; int crounds; int drounds; int len; size_t total_inlen; int v0; int v2; int v3; unsigned char const* leavings; } ;
typedef  TYPE_1__ SIPHASH ;

/* Variables and functions */
 int SIPHASH_BLOCK_SIZE ; 
 int SIPHASH_C_ROUNDS ; 
 int SIPHASH_D_ROUNDS ; 
 size_t SIPHASH_MAX_DIGEST_SIZE ; 
 size_t SIPHASH_MIN_DIGEST_SIZE ; 
 int /*<<< orphan*/  SIPROUND ; 
 int /*<<< orphan*/  U64TO8_LE (unsigned char*,int) ; 
 int U8TO64_LE (unsigned char const*) ; 
 int /*<<< orphan*/  memcpy (unsigned char const*,unsigned char const*,int) ; 

size_t SipHash_ctx_size(void)
{
    return sizeof(SIPHASH);
}

size_t SipHash_hash_size(SIPHASH *ctx)
{
    return ctx->hash_size;
}

__attribute__((used)) static size_t siphash_adjust_hash_size(size_t hash_size)
{
    if (hash_size == 0)
        hash_size = SIPHASH_MAX_DIGEST_SIZE;
    return hash_size;
}

int SipHash_set_hash_size(SIPHASH *ctx, size_t hash_size)
{
    hash_size = siphash_adjust_hash_size(hash_size);
    if (hash_size != SIPHASH_MIN_DIGEST_SIZE
        && hash_size != SIPHASH_MAX_DIGEST_SIZE)
        return 0;

    /*
     * It's possible that the key was set first.  If the hash size changes,
     * we need to adjust v1 (see SipHash_Init().
     */

    /* Start by adjusting the stored size, to make things easier */
    ctx->hash_size = siphash_adjust_hash_size(ctx->hash_size);

    /* Now, adjust ctx->v1 if the old and the new size differ */
    if ((size_t)ctx->hash_size != hash_size) {
        ctx->v1 ^= 0xee;
        ctx->hash_size = hash_size;
    }
    return 1;
}

int SipHash_Init(SIPHASH *ctx, const unsigned char *k, int crounds, int drounds)
{
    uint64_t k0 = U8TO64_LE(k);
    uint64_t k1 = U8TO64_LE(k + 8);

    /* If the hash size wasn't set, i.e. is zero */
    ctx->hash_size = siphash_adjust_hash_size(ctx->hash_size);

    if (drounds == 0)
        drounds = SIPHASH_D_ROUNDS;
    if (crounds == 0)
        crounds = SIPHASH_C_ROUNDS;

    ctx->crounds = crounds;
    ctx->drounds = drounds;

    ctx->len = 0;
    ctx->total_inlen = 0;

    ctx->v0 = 0x736f6d6570736575ULL ^ k0;
    ctx->v1 = 0x646f72616e646f6dULL ^ k1;
    ctx->v2 = 0x6c7967656e657261ULL ^ k0;
    ctx->v3 = 0x7465646279746573ULL ^ k1;

    if (ctx->hash_size == SIPHASH_MAX_DIGEST_SIZE)
        ctx->v1 ^= 0xee;

    return 1;
}

void SipHash_Update(SIPHASH *ctx, const unsigned char *in, size_t inlen)
{
    uint64_t m;
    const uint8_t *end;
    int left;
    int i;
    uint64_t v0 = ctx->v0;
    uint64_t v1 = ctx->v1;
    uint64_t v2 = ctx->v2;
    uint64_t v3 = ctx->v3;

    ctx->total_inlen += inlen;

    if (ctx->len) {
        /* deal with leavings */
        size_t available = SIPHASH_BLOCK_SIZE - ctx->len;

        /* not enough to fill leavings */
        if (inlen < available) {
            memcpy(&ctx->leavings[ctx->len], in, inlen);
            ctx->len += inlen;
            return;
        }

        /* copy data into leavings and reduce input */
        memcpy(&ctx->leavings[ctx->len], in, available);
        inlen -= available;
        in += available;

        /* process leavings */
        m = U8TO64_LE(ctx->leavings);
        v3 ^= m;
        for (i = 0; i < ctx->crounds; ++i)
            SIPROUND;
        v0 ^= m;
    }
    left = inlen & (SIPHASH_BLOCK_SIZE-1); /* gets put into leavings */
    end = in + inlen - left;

    for (; in != end; in += 8) {
        m = U8TO64_LE(in);
        v3 ^= m;
        for (i = 0; i < ctx->crounds; ++i)
            SIPROUND;
        v0 ^= m;
    }

    /* save leavings and other ctx */
    if (left)
        memcpy(ctx->leavings, end, left);
    ctx->len = left;

    ctx->v0 = v0;
    ctx->v1 = v1;
    ctx->v2 = v2;
    ctx->v3 = v3;
}

int SipHash_Final(SIPHASH *ctx, unsigned char *out, size_t outlen)
{
    /* finalize hash */
    int i;
    uint64_t b = ctx->total_inlen << 56;
    uint64_t v0 = ctx->v0;
    uint64_t v1 = ctx->v1;
    uint64_t v2 = ctx->v2;
    uint64_t v3 = ctx->v3;

    if (outlen != (size_t)ctx->hash_size)
        return 0;

    switch (ctx->len) {
    case 7:
        b |= ((uint64_t)ctx->leavings[6]) << 48;
        /* fall thru */
    case 6:
        b |= ((uint64_t)ctx->leavings[5]) << 40;
        /* fall thru */
    case 5:
        b |= ((uint64_t)ctx->leavings[4]) << 32;
        /* fall thru */
    case 4:
        b |= ((uint64_t)ctx->leavings[3]) << 24;
        /* fall thru */
    case 3:
        b |= ((uint64_t)ctx->leavings[2]) << 16;
        /* fall thru */
    case 2:
        b |= ((uint64_t)ctx->leavings[1]) <<  8;
        /* fall thru */
    case 1:
        b |= ((uint64_t)ctx->leavings[0]);
    case 0:
        break;
    }

    v3 ^= b;
    for (i = 0; i < ctx->crounds; ++i)
        SIPROUND;
    v0 ^= b;
    if (ctx->hash_size == SIPHASH_MAX_DIGEST_SIZE)
        v2 ^= 0xee;
    else
        v2 ^= 0xff;
    for (i = 0; i < ctx->drounds; ++i)
        SIPROUND;
    b = v0 ^ v1 ^ v2  ^ v3;
    U64TO8_LE(out, b);
    if (ctx->hash_size == SIPHASH_MIN_DIGEST_SIZE)
        return 1;
    v1 ^= 0xdd;
    for (i = 0; i < ctx->drounds; ++i)
        SIPROUND;
    b = v0 ^ v1 ^ v2  ^ v3;
    U64TO8_LE(out + 8, b);
    return 1;
}

