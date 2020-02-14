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
typedef  int mem_size_t ;

/* Variables and functions */
 void* ExAllocatePoolWithTag (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LWIP_TAG ; 
 int /*<<< orphan*/  NonPagedPool ; 
 int /*<<< orphan*/  RtlCopyMemory (void*,void*,size_t) ; 
 int /*<<< orphan*/  RtlZeroMemory (void*,int) ; 

void *
malloc(mem_size_t size)
{
    return ExAllocatePoolWithTag(NonPagedPool, size, LWIP_TAG);
}

void *
calloc(mem_size_t count, mem_size_t size)
{
    void *mem = malloc(count * size);
    
    if (!mem) return NULL;
    
    RtlZeroMemory(mem, count * size);
    
    return mem;
}

void
free(void *mem)
{
    ExFreePoolWithTag(mem, LWIP_TAG);
}

void *
realloc(void *mem, size_t size)
{
    void* new_mem;
    
    /* realloc() with a NULL mem pointer acts like a call to malloc() */
    if (mem == NULL) {
        return malloc(size);
    }
    
    /* realloc() with a size 0 acts like a call to free() */
    if (size == 0) {
        free(mem);
        return NULL;
    }
    
    /* Allocate the new buffer first */
    new_mem = malloc(size);
    if (new_mem == NULL) {
        /* The old buffer is still intact */
        return NULL;
    }
    
    /* Copy the data over */
    RtlCopyMemory(new_mem, mem, size);
    
    /* Deallocate the old buffer */
    free(mem);

    /* Return the newly allocated block */
    return new_mem;
}

