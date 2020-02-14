#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void* (* customAlloc ) (int /*<<< orphan*/ ,size_t) ;int /*<<< orphan*/  opaque; int /*<<< orphan*/  (* customFree ) (int /*<<< orphan*/ ,void*) ;} ;
typedef  TYPE_1__ ZSTD_customMem ;
typedef  int /*<<< orphan*/  ZSTD_ErrorCode ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_getErrorCode (size_t) ; 
 char const* ERR_getErrorName (size_t) ; 
 char const* ERR_getErrorString (int /*<<< orphan*/ ) ; 
 int ERR_isError (size_t) ; 
 int ZSTD_VERSION_NUMBER ; 
 char const* ZSTD_VERSION_STRING ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int) ; 
 int /*<<< orphan*/  memset (void* const,int /*<<< orphan*/ ,size_t) ; 
 void* stub1 (int /*<<< orphan*/ ,size_t) ; 
 void* stub2 (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static void ZSTD_copy8(void* dst, const void* src) { memcpy(dst, src, 8); }

unsigned ZSTD_versionNumber(void) { return ZSTD_VERSION_NUMBER; }

const char* ZSTD_versionString(void) { return ZSTD_VERSION_STRING; }

unsigned ZSTD_isError(size_t code) { return ERR_isError(code); }

const char* ZSTD_getErrorName(size_t code) { return ERR_getErrorName(code); }

ZSTD_ErrorCode ZSTD_getErrorCode(size_t code) { return ERR_getErrorCode(code); }

const char* ZSTD_getErrorString(ZSTD_ErrorCode code) { return ERR_getErrorString(code); }

void* ZSTD_malloc(size_t size, ZSTD_customMem customMem)
{
    return customMem.customAlloc(customMem.opaque, size);
}

void* ZSTD_calloc(size_t size, ZSTD_customMem customMem)
{
    /* calloc implemented as malloc+memset;
        * not as efficient as calloc, but next best guess for custom malloc */
    void* const ptr = customMem.customAlloc(customMem.opaque, size);
    memset(ptr, 0, size);
    return ptr;
}

void ZSTD_free(void* ptr, ZSTD_customMem customMem)
{
    if (ptr!=NULL)
        customMem.customFree(customMem.opaque, ptr);
}

