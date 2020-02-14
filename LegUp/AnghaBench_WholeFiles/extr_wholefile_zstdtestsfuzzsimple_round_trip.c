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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  FUZZ_ASSERT (int) ; 
 int /*<<< orphan*/  FUZZ_ASSERT_MSG (int,char*) ; 
 int /*<<< orphan*/  FUZZ_ZASSERT (size_t const) ; 
 int FUZZ_rand (int /*<<< orphan*/ *) ; 
 scalar_t__ FUZZ_rand32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FUZZ_seed (int /*<<< orphan*/  const**,size_t*) ; 
 int /*<<< orphan*/  FUZZ_setRandomParameters (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ *) ; 
 size_t ZSTD_compress2 (int /*<<< orphan*/ *,void*,size_t,void const*,size_t) ; 
 size_t ZSTD_compressBound (size_t) ; 
 size_t ZSTD_compressCCtx (int /*<<< orphan*/ *,void*,size_t,void const*,size_t,int const) ; 
 int /*<<< orphan*/ * ZSTD_createCCtx () ; 
 int /*<<< orphan*/ * ZSTD_createDCtx () ; 
 size_t ZSTD_decompressDCtx (int /*<<< orphan*/ *,void*,size_t,void*,size_t) ; 
 int /*<<< orphan*/  ZSTD_freeCCtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_freeDCtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * cctx ; 
 int /*<<< orphan*/ * dctx ; 
 int /*<<< orphan*/  free (void*) ; 
 int kMaxClevel ; 
 void* malloc (size_t const) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/  const*,void*,size_t) ; 
 int /*<<< orphan*/  seed ; 

__attribute__((used)) static size_t roundTripTest(void *result, size_t resultCapacity,
                            void *compressed, size_t compressedCapacity,
                            const void *src, size_t srcSize)
{
    size_t cSize;
    if (FUZZ_rand(&seed) & 1) {
        FUZZ_setRandomParameters(cctx, srcSize, &seed);
        cSize = ZSTD_compress2(cctx, compressed, compressedCapacity, src, srcSize);
    } else {
        int const cLevel = FUZZ_rand(&seed) % kMaxClevel;
        cSize = ZSTD_compressCCtx(
            cctx, compressed, compressedCapacity, src, srcSize, cLevel);
    }
    FUZZ_ZASSERT(cSize);
    return ZSTD_decompressDCtx(dctx, result, resultCapacity, compressed, cSize);
}

int LLVMFuzzerTestOneInput(const uint8_t *src, size_t size)
{
    size_t const rBufSize = size;
    void* rBuf = malloc(rBufSize);
    size_t cBufSize = ZSTD_compressBound(size);
    void* cBuf;

    seed = FUZZ_seed(&src, &size);
    /* Half of the time fuzz with a 1 byte smaller output size.
     * This will still succeed because we don't use a dictionary, so the dictID
     * field is empty, giving us 4 bytes of overhead.
     */
    cBufSize -= FUZZ_rand32(&seed, 0, 1);
    cBuf = malloc(cBufSize);

    FUZZ_ASSERT(cBuf && rBuf);

    if (!cctx) {
        cctx = ZSTD_createCCtx();
        FUZZ_ASSERT(cctx);
    }
    if (!dctx) {
        dctx = ZSTD_createDCtx();
        FUZZ_ASSERT(dctx);
    }

    {
        size_t const result =
            roundTripTest(rBuf, rBufSize, cBuf, cBufSize, src, size);
        FUZZ_ZASSERT(result);
        FUZZ_ASSERT_MSG(result == size, "Incorrect regenerated size");
        FUZZ_ASSERT_MSG(!memcmp(src, rBuf, size), "Corruption!");
    }
    free(rBuf);
    free(cBuf);
#ifndef STATEFUL_FUZZING
    ZSTD_freeCCtx(cctx); cctx = NULL;
    ZSTD_freeDCtx(dctx); dctx = NULL;
#endif
    return 0;
}

