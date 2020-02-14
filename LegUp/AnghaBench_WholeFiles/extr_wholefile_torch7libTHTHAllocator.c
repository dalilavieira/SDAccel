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
typedef  int /*<<< orphan*/  ptrdiff_t ;
typedef  int /*<<< orphan*/  THMapAllocatorContext ;

/* Variables and functions */
 void* THAlloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THError (char*) ; 
 int /*<<< orphan*/  THFree (void*) ; 
 void* THRealloc (void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *THDefaultAllocator_alloc(void* ctx, ptrdiff_t size) {
  return THAlloc(size);
}

__attribute__((used)) static void *THDefaultAllocator_realloc(void* ctx, void* ptr, ptrdiff_t size) {
  return THRealloc(ptr, size);
}

__attribute__((used)) static void THDefaultAllocator_free(void* ctx, void* ptr) {
  THFree(ptr);
}

THMapAllocatorContext *THMapAllocatorContext_new(const char *filename, int flags) {
  THError("file mapping not supported on your system");
  return NULL;
}

void THMapAllocatorContext_free(THMapAllocatorContext *ctx) {
  THError("file mapping not supported on your system");
}

__attribute__((used)) static void *THMapAllocator_alloc(void* ctx_, ptrdiff_t size) {
  THError("file mapping not supported on your system");
  return NULL;
}

__attribute__((used)) static void *THMapAllocator_realloc(void* ctx, void* ptr, ptrdiff_t size) {
  THError("file mapping not supported on your system");
  return NULL;
}

__attribute__((used)) static void THMapAllocator_free(void* ctx, void* data) {
  THError("file mapping not supported on your system");
}

__attribute__((used)) static void * THRefcountedMapAllocator_alloc(void *ctx, ptrdiff_t size) {
  THError("refcounted file mapping not supported on your system");
  return NULL;
}

__attribute__((used)) static void *THRefcountedMapAllocator_realloc(void* ctx, void* ptr, ptrdiff_t size) {
  THError("refcounted file mapping not supported on your system");
  return NULL;
}

__attribute__((used)) static void THRefcountedMapAllocator_free(void* ctx_, void* data) {
  THError("refcounted file mapping not supported on your system");
}

void THRefcountedMapAllocator_incref(THMapAllocatorContext *ctx, void *data)
{
  THError("refcounted file mapping not supported on your system");
}

int THRefcountedMapAllocator_decref(THMapAllocatorContext *ctx, void *data)
{
  THError("refcounted file mapping not supported on your system");
  return 0;
}

