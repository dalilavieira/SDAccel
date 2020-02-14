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
typedef  int /*<<< orphan*/  ZSTD_customMem ;
typedef  int /*<<< orphan*/  (* POOL_function ) (void*) ;
typedef  int /*<<< orphan*/  POOL_ctx ;

/* Variables and functions */
 int /*<<< orphan*/ * POOL_create_advanced (size_t,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZSTD_defaultCMem ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  g_ctx ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int) ; 

__attribute__((used)) static void ZSTD_copy8(void* dst, const void* src) { memcpy(dst, src, 8); }

POOL_ctx* POOL_create(size_t numThreads, size_t queueSize) {
    return POOL_create_advanced(numThreads, queueSize, ZSTD_defaultCMem);
}

POOL_ctx* POOL_create_advanced(size_t numThreads, size_t queueSize, ZSTD_customMem customMem) {
    (void)numThreads;
    (void)queueSize;
    (void)customMem;
    return &g_ctx;
}

void POOL_free(POOL_ctx* ctx) {
    assert(!ctx || ctx == &g_ctx);
    (void)ctx;
}

int POOL_resize(POOL_ctx* ctx, size_t numThreads) {
    (void)ctx; (void)numThreads;
    return 0;
}

void POOL_add(POOL_ctx* ctx, POOL_function function, void* opaque) {
    (void)ctx;
    function(opaque);
}

int POOL_tryAdd(POOL_ctx* ctx, POOL_function function, void* opaque) {
    (void)ctx;
    function(opaque);
    return 1;
}

size_t POOL_sizeof(POOL_ctx* ctx) {
    if (ctx==NULL) return 0;  /* supports sizeof NULL */
    assert(ctx == &g_ctx);
    return sizeof(*ctx);
}

