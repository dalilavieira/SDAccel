#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ZSTD_parameters ;
struct TYPE_7__ {size_t pos; size_t size; void* dst; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_8__ {size_t pos; size_t size; void const* src; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int /*<<< orphan*/  ZSTD_customMem ;
typedef  int /*<<< orphan*/  ZBUFF_CCtx ;

/* Variables and functions */
 unsigned long long ZSTD_CONTENTSIZE_UNKNOWN ; 
 size_t ZSTD_CStreamInSize () ; 
 size_t ZSTD_CStreamOutSize () ; 
 size_t ZSTD_compressStream (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*) ; 
 int /*<<< orphan*/ * ZSTD_createCStream () ; 
 int /*<<< orphan*/ * ZSTD_createCStream_advanced (int /*<<< orphan*/ ) ; 
 size_t ZSTD_endStream (int /*<<< orphan*/ *,TYPE_1__*) ; 
 size_t ZSTD_flushStream (int /*<<< orphan*/ *,TYPE_1__*) ; 
 size_t ZSTD_freeCStream (int /*<<< orphan*/ *) ; 
 size_t ZSTD_initCStream (int /*<<< orphan*/ *,int) ; 
 size_t ZSTD_initCStream_advanced (int /*<<< orphan*/ *,void const*,size_t,int /*<<< orphan*/ ,unsigned long long) ; 
 size_t ZSTD_initCStream_usingDict (int /*<<< orphan*/ *,void const*,size_t,int) ; 

ZBUFF_CCtx* ZBUFF_createCCtx(void)
{
    return ZSTD_createCStream();
}

ZBUFF_CCtx* ZBUFF_createCCtx_advanced(ZSTD_customMem customMem)
{
    return ZSTD_createCStream_advanced(customMem);
}

size_t ZBUFF_freeCCtx(ZBUFF_CCtx* zbc)
{
    return ZSTD_freeCStream(zbc);
}

size_t ZBUFF_compressInit_advanced(ZBUFF_CCtx* zbc,
                                   const void* dict, size_t dictSize,
                                   ZSTD_parameters params, unsigned long long pledgedSrcSize)
{
    if (pledgedSrcSize==0) pledgedSrcSize = ZSTD_CONTENTSIZE_UNKNOWN;  /* preserve "0 == unknown" behavior */
    return ZSTD_initCStream_advanced(zbc, dict, dictSize, params, pledgedSrcSize);
}

size_t ZBUFF_compressInitDictionary(ZBUFF_CCtx* zbc, const void* dict, size_t dictSize, int compressionLevel)
{
    return ZSTD_initCStream_usingDict(zbc, dict, dictSize, compressionLevel);
}

size_t ZBUFF_compressInit(ZBUFF_CCtx* zbc, int compressionLevel)
{
    return ZSTD_initCStream(zbc, compressionLevel);
}

size_t ZBUFF_compressContinue(ZBUFF_CCtx* zbc,
                              void* dst, size_t* dstCapacityPtr,
                        const void* src, size_t* srcSizePtr)
{
    size_t result;
    ZSTD_outBuffer outBuff;
    ZSTD_inBuffer inBuff;
    outBuff.dst = dst;
    outBuff.pos = 0;
    outBuff.size = *dstCapacityPtr;
    inBuff.src = src;
    inBuff.pos = 0;
    inBuff.size = *srcSizePtr;
    result = ZSTD_compressStream(zbc, &outBuff, &inBuff);
    *dstCapacityPtr = outBuff.pos;
    *srcSizePtr = inBuff.pos;
    return result;
}

size_t ZBUFF_compressFlush(ZBUFF_CCtx* zbc, void* dst, size_t* dstCapacityPtr)
{
    size_t result;
    ZSTD_outBuffer outBuff;
    outBuff.dst = dst;
    outBuff.pos = 0;
    outBuff.size = *dstCapacityPtr;
    result = ZSTD_flushStream(zbc, &outBuff);
    *dstCapacityPtr = outBuff.pos;
    return result;
}

size_t ZBUFF_compressEnd(ZBUFF_CCtx* zbc, void* dst, size_t* dstCapacityPtr)
{
    size_t result;
    ZSTD_outBuffer outBuff;
    outBuff.dst = dst;
    outBuff.pos = 0;
    outBuff.size = *dstCapacityPtr;
    result = ZSTD_endStream(zbc, &outBuff);
    *dstCapacityPtr = outBuff.pos;
    return result;
}

size_t ZBUFF_recommendedCInSize(void)  { return ZSTD_CStreamInSize(); }

size_t ZBUFF_recommendedCOutSize(void) { return ZSTD_CStreamOutSize(); }

