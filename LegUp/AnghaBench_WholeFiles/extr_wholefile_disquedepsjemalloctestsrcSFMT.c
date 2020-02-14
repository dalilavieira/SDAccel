#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  w128_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
struct TYPE_16__ {int initialized; int idx; TYPE_3__* sfmt; } ;
typedef  TYPE_1__ sfmt_t ;
struct TYPE_17__ {int* u; } ;

/* Variables and functions */
 char const* IDSTR ; 
 int KQU (int) ; 
 int N ; 
 int N32 ; 
 int N64 ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  gen_rand_all (TYPE_1__*) ; 
 int /*<<< orphan*/  gen_rand_array (TYPE_1__*,int /*<<< orphan*/ *,int) ; 
 size_t idxof (int) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int,int) ; 
 int* parity ; 
 scalar_t__ posix_memalign (void**,int,int) ; 

__attribute__((used)) static uint32_t func1(uint32_t x) {
    return (x ^ (x >> 27)) * (uint32_t)1664525UL;
}

__attribute__((used)) static uint32_t func2(uint32_t x) {
    return (x ^ (x >> 27)) * (uint32_t)1566083941UL;
}

__attribute__((used)) static void period_certification(sfmt_t *ctx) {
    int inner = 0;
    int i, j;
    uint32_t work;
    uint32_t *psfmt32 = &ctx->sfmt[0].u[0];

    for (i = 0; i < 4; i++)
	inner ^= psfmt32[idxof(i)] & parity[i];
    for (i = 16; i > 0; i >>= 1)
	inner ^= inner >> i;
    inner &= 1;
    /* check OK */
    if (inner == 1) {
	return;
    }
    /* check NG, and modification */
    for (i = 0; i < 4; i++) {
	work = 1;
	for (j = 0; j < 32; j++) {
	    if ((work & parity[i]) != 0) {
		psfmt32[idxof(i)] ^= work;
		return;
	    }
	    work = work << 1;
	}
    }
}

const char *get_idstring(void) {
    return IDSTR;
}

int get_min_array_size32(void) {
    return N32;
}

int get_min_array_size64(void) {
    return N64;
}

uint32_t gen_rand32(sfmt_t *ctx) {
    uint32_t r;
    uint32_t *psfmt32 = &ctx->sfmt[0].u[0];

    assert(ctx->initialized);
    if (ctx->idx >= N32) {
	gen_rand_all(ctx);
	ctx->idx = 0;
    }
    r = psfmt32[ctx->idx++];
    return r;
}

uint32_t gen_rand32_range(sfmt_t *ctx, uint32_t limit) {
    uint32_t ret, above;

    above = 0xffffffffU - (0xffffffffU % limit);
    while (1) {
	ret = gen_rand32(ctx);
	if (ret < above) {
	    ret %= limit;
	    break;
	}
    }
    return ret;
}

uint64_t gen_rand64(sfmt_t *ctx) {
#if defined(BIG_ENDIAN64) && !defined(ONLY64)
    uint32_t r1, r2;
    uint32_t *psfmt32 = &ctx->sfmt[0].u[0];
#else
    uint64_t r;
    uint64_t *psfmt64 = (uint64_t *)&ctx->sfmt[0].u[0];
#endif

    assert(ctx->initialized);
    assert(ctx->idx % 2 == 0);

    if (ctx->idx >= N32) {
	gen_rand_all(ctx);
	ctx->idx = 0;
    }
#if defined(BIG_ENDIAN64) && !defined(ONLY64)
    r1 = psfmt32[ctx->idx];
    r2 = psfmt32[ctx->idx + 1];
    ctx->idx += 2;
    return ((uint64_t)r2 << 32) | r1;
#else
    r = psfmt64[ctx->idx / 2];
    ctx->idx += 2;
    return r;
#endif
}

uint64_t gen_rand64_range(sfmt_t *ctx, uint64_t limit) {
    uint64_t ret, above;

    above = KQU(0xffffffffffffffff) - (KQU(0xffffffffffffffff) % limit);
    while (1) {
	ret = gen_rand64(ctx);
	if (ret < above) {
	    ret %= limit;
	    break;
	}
    }
    return ret;
}

void fill_array32(sfmt_t *ctx, uint32_t *array, int size) {
    assert(ctx->initialized);
    assert(ctx->idx == N32);
    assert(size % 4 == 0);
    assert(size >= N32);

    gen_rand_array(ctx, (w128_t *)array, size / 4);
    ctx->idx = N32;
}

void fill_array64(sfmt_t *ctx, uint64_t *array, int size) {
    assert(ctx->initialized);
    assert(ctx->idx == N32);
    assert(size % 2 == 0);
    assert(size >= N64);

    gen_rand_array(ctx, (w128_t *)array, size / 2);
    ctx->idx = N32;

#if defined(BIG_ENDIAN64) && !defined(ONLY64)
    swap((w128_t *)array, size /2);
#endif
}

sfmt_t *init_gen_rand(uint32_t seed) {
    void *p;
    sfmt_t *ctx;
    int i;
    uint32_t *psfmt32;

    if (posix_memalign(&p, sizeof(w128_t), sizeof(sfmt_t)) != 0) {
	return NULL;
    }
    ctx = (sfmt_t *)p;
    psfmt32 = &ctx->sfmt[0].u[0];

    psfmt32[idxof(0)] = seed;
    for (i = 1; i < N32; i++) {
	psfmt32[idxof(i)] = 1812433253UL * (psfmt32[idxof(i - 1)] 
					    ^ (psfmt32[idxof(i - 1)] >> 30))
	    + i;
    }
    ctx->idx = N32;
    period_certification(ctx);
    ctx->initialized = 1;

    return ctx;
}

sfmt_t *init_by_array(uint32_t *init_key, int key_length) {
    void *p;
    sfmt_t *ctx;
    int i, j, count;
    uint32_t r;
    int lag;
    int mid;
    int size = N * 4;
    uint32_t *psfmt32;

    if (posix_memalign(&p, sizeof(w128_t), sizeof(sfmt_t)) != 0) {
	return NULL;
    }
    ctx = (sfmt_t *)p;
    psfmt32 = &ctx->sfmt[0].u[0];

    if (size >= 623) {
	lag = 11;
    } else if (size >= 68) {
	lag = 7;
    } else if (size >= 39) {
	lag = 5;
    } else {
	lag = 3;
    }
    mid = (size - lag) / 2;

    memset(ctx->sfmt, 0x8b, sizeof(ctx->sfmt));
    if (key_length + 1 > N32) {
	count = key_length + 1;
    } else {
	count = N32;
    }
    r = func1(psfmt32[idxof(0)] ^ psfmt32[idxof(mid)] 
	      ^ psfmt32[idxof(N32 - 1)]);
    psfmt32[idxof(mid)] += r;
    r += key_length;
    psfmt32[idxof(mid + lag)] += r;
    psfmt32[idxof(0)] = r;

    count--;
    for (i = 1, j = 0; (j < count) && (j < key_length); j++) {
	r = func1(psfmt32[idxof(i)] ^ psfmt32[idxof((i + mid) % N32)] 
		  ^ psfmt32[idxof((i + N32 - 1) % N32)]);
	psfmt32[idxof((i + mid) % N32)] += r;
	r += init_key[j] + i;
	psfmt32[idxof((i + mid + lag) % N32)] += r;
	psfmt32[idxof(i)] = r;
	i = (i + 1) % N32;
    }
    for (; j < count; j++) {
	r = func1(psfmt32[idxof(i)] ^ psfmt32[idxof((i + mid) % N32)] 
		  ^ psfmt32[idxof((i + N32 - 1) % N32)]);
	psfmt32[idxof((i + mid) % N32)] += r;
	r += i;
	psfmt32[idxof((i + mid + lag) % N32)] += r;
	psfmt32[idxof(i)] = r;
	i = (i + 1) % N32;
    }
    for (j = 0; j < N32; j++) {
	r = func2(psfmt32[idxof(i)] + psfmt32[idxof((i + mid) % N32)] 
		  + psfmt32[idxof((i + N32 - 1) % N32)]);
	psfmt32[idxof((i + mid) % N32)] ^= r;
	r -= i;
	psfmt32[idxof((i + mid + lag) % N32)] ^= r;
	psfmt32[idxof(i)] = r;
	i = (i + 1) % N32;
    }

    ctx->idx = N32;
    period_certification(ctx);
    ctx->initialized = 1;

    return ctx;
}

void fini_gen_rand(sfmt_t *ctx) {
    assert(ctx != NULL);

    ctx->initialized = 0;
    free(ctx);
}

