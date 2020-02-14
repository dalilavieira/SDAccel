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
struct TYPE_7__ {void* ptr; char* end; } ;
typedef  TYPE_1__ ZSTD_stack ;
struct TYPE_8__ {void* (* member_0 ) (void*,size_t) ;void (* member_1 ) (void*,void*) ;void* member_2; void* (* customAlloc ) (int /*<<< orphan*/ ,size_t) ;int /*<<< orphan*/  opaque; int /*<<< orphan*/  (* customFree ) (int /*<<< orphan*/ ,void*) ;} ;
typedef  TYPE_2__ ZSTD_customMem ;
typedef  int /*<<< orphan*/  const BYTE ;

/* Variables and functions */
 void* ZSTD_PTR_ALIGN (void*) ; 
 void* ZSTD_stackAlloc (void*,size_t) ; 
 void ZSTD_stackFree (void*,void*) ; 
 void* stack_push (TYPE_1__*,size_t) ; 
 void* stub1 (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,void*) ; 

ZSTD_customMem ZSTD_initStack(void *workspace, size_t workspaceSize)
{
	ZSTD_customMem stackMem = {ZSTD_stackAlloc, ZSTD_stackFree, workspace};
	ZSTD_stack *stack = (ZSTD_stack *)workspace;
	/* Verify preconditions */
	if (!workspace || workspaceSize < sizeof(ZSTD_stack) || workspace != ZSTD_PTR_ALIGN(workspace)) {
		ZSTD_customMem error = {NULL, NULL, NULL};
		return error;
	}
	/* Initialize the stack */
	stack->ptr = workspace;
	stack->end = (char *)workspace + workspaceSize;
	stack_push(stack, sizeof(ZSTD_stack));
	return stackMem;
}

void *ZSTD_stackAllocAll(void *opaque, size_t *size)
{
	ZSTD_stack *stack = (ZSTD_stack *)opaque;
	*size = (BYTE const *)stack->end - (BYTE *)ZSTD_PTR_ALIGN(stack->ptr);
	return stack_push(stack, *size);
}

void *ZSTD_stackAlloc(void *opaque, size_t size)
{
	ZSTD_stack *stack = (ZSTD_stack *)opaque;
	return stack_push(stack, size);
}

void ZSTD_stackFree(void *opaque, void *address)
{
	(void)opaque;
	(void)address;
}

void *ZSTD_malloc(size_t size, ZSTD_customMem customMem) { return customMem.customAlloc(customMem.opaque, size); }

void ZSTD_free(void *ptr, ZSTD_customMem customMem)
{
	if (ptr != NULL)
		customMem.customFree(customMem.opaque, ptr);
}

