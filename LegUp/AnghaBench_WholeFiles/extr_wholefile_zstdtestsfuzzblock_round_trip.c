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
typedef  int /*<<< orphan*/  ZSTD_parameters ;

/* Variables and functions */
 int /*<<< orphan*/  FUZZ_ASSERT (int) ; 
 int /*<<< orphan*/  FUZZ_ASSERT_MSG (int,char*) ; 
 int /*<<< orphan*/  FUZZ_ZASSERT (size_t const) ; 
 int FUZZ_rand (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FUZZ_seed (int /*<<< orphan*/  const**,size_t*) ; 
 size_t ZSTD_BLOCKSIZE_MAX ; 
 size_t ZSTD_compressBegin_advanced (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const,size_t) ; 
 size_t ZSTD_compressBlock (int /*<<< orphan*/ *,void*,size_t,void const*,size_t) ; 
 int /*<<< orphan*/ * ZSTD_createCCtx () ; 
 int /*<<< orphan*/ * ZSTD_createDCtx () ; 
 int /*<<< orphan*/  ZSTD_decompressBegin (int /*<<< orphan*/ *) ; 
 size_t ZSTD_decompressBlock (int /*<<< orphan*/ *,void*,size_t,void*,size_t) ; 
 int /*<<< orphan*/  ZSTD_freeCCtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_freeDCtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_getParams (int const,size_t,int /*<<< orphan*/ ) ; 
 size_t bufSize ; 
 void* cBuf ; 
 int /*<<< orphan*/ * cctx ; 
 int /*<<< orphan*/ * dctx ; 
 int /*<<< orphan*/  free (void*) ; 
 int kMaxClevel ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/  const*,void*,size_t) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,size_t) ; 
 void* rBuf ; 
 int /*<<< orphan*/  seed ; 

__attribute__((used)) static size_t roundTripTest(void *result, size_t resultCapacity,
                            void *compressed, size_t compressedCapacity,
                            const void *src, size_t srcSize)
{
    int const cLevel = FUZZ_rand(&seed) % kMaxClevel;
    ZSTD_parameters const params = ZSTD_getParams(cLevel, srcSize, 0);
    size_t ret = ZSTD_compressBegin_advanced(cctx, NULL, 0, params, srcSize);
    FUZZ_ZASSERT(ret);

    ret = ZSTD_compressBlock(cctx, compressed, compressedCapacity, src, srcSize);
    FUZZ_ZASSERT(ret);
    if (ret == 0) {
        FUZZ_ASSERT(resultCapacity >= srcSize);
        memcpy(result, src, srcSize);
        return srcSize;
    }
    ZSTD_decompressBegin(dctx);
    return ZSTD_decompressBlock(dctx, result, resultCapacity, compressed, ret);
}

int LLVMFuzzerTestOneInput(const uint8_t *src, size_t size)
{
    size_t neededBufSize;

    seed = FUZZ_seed(&src, &size);
    neededBufSize = size;
    if (size > ZSTD_BLOCKSIZE_MAX)
        return 0;

    /* Allocate all buffers and contexts if not already allocated */
    if (neededBufSize > bufSize || !cBuf || !rBuf) {
        free(cBuf);
        free(rBuf);
        cBuf = malloc(neededBufSize);
        rBuf = malloc(neededBufSize);
        bufSize = neededBufSize;
        FUZZ_ASSERT(cBuf && rBuf);
    }
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
            roundTripTest(rBuf, neededBufSize, cBuf, neededBufSize, src, size);
        FUZZ_ZASSERT(result);
        FUZZ_ASSERT_MSG(result == size, "Incorrect regenerated size");
        FUZZ_ASSERT_MSG(!memcmp(src, rBuf, size), "Corruption!");
    }
#ifndef STATEFUL_FUZZING
    ZSTD_freeCCtx(cctx); cctx = NULL;
    ZSTD_freeDCtx(dctx); dctx = NULL;
#endif
    return 0;
}

