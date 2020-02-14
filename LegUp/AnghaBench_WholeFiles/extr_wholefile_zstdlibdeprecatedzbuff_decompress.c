#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {size_t pos; size_t size; void* dst; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_6__ {size_t pos; size_t size; void const* src; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int /*<<< orphan*/  ZSTD_customMem ;
typedef  int /*<<< orphan*/  ZBUFF_DCtx ;

/* Variables and functions */
 size_t ZSTD_DStreamInSize () ; 
 size_t ZSTD_DStreamOutSize () ; 
 int /*<<< orphan*/ * ZSTD_createDStream () ; 
 int /*<<< orphan*/ * ZSTD_createDStream_advanced (int /*<<< orphan*/ ) ; 
 size_t ZSTD_decompressStream (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*) ; 
 size_t ZSTD_freeDStream (int /*<<< orphan*/ *) ; 
 size_t ZSTD_initDStream (int /*<<< orphan*/ *) ; 
 size_t ZSTD_initDStream_usingDict (int /*<<< orphan*/ *,void const*,size_t) ; 

ZBUFF_DCtx* ZBUFF_createDCtx(void)
{
    return ZSTD_createDStream();
}

ZBUFF_DCtx* ZBUFF_createDCtx_advanced(ZSTD_customMem customMem)
{
    return ZSTD_createDStream_advanced(customMem);
}

size_t ZBUFF_freeDCtx(ZBUFF_DCtx* zbd)
{
    return ZSTD_freeDStream(zbd);
}

size_t ZBUFF_decompressInitDictionary(ZBUFF_DCtx* zbd, const void* dict, size_t dictSize)
{
    return ZSTD_initDStream_usingDict(zbd, dict, dictSize);
}

size_t ZBUFF_decompressInit(ZBUFF_DCtx* zbd)
{
    return ZSTD_initDStream(zbd);
}

size_t ZBUFF_decompressContinue(ZBUFF_DCtx* zbd,
                                void* dst, size_t* dstCapacityPtr,
                          const void* src, size_t* srcSizePtr)
{
    ZSTD_outBuffer outBuff;
    ZSTD_inBuffer inBuff;
    size_t result;
    outBuff.dst  = dst;
    outBuff.pos  = 0;
    outBuff.size = *dstCapacityPtr;
    inBuff.src  = src;
    inBuff.pos  = 0;
    inBuff.size = *srcSizePtr;
    result = ZSTD_decompressStream(zbd, &outBuff, &inBuff);
    *dstCapacityPtr = outBuff.pos;
    *srcSizePtr = inBuff.pos;
    return result;
}

size_t ZBUFF_recommendedDInSize(void)  { return ZSTD_DStreamInSize(); }

size_t ZBUFF_recommendedDOutSize(void) { return ZSTD_DStreamOutSize(); }

