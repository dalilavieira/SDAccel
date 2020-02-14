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

/* Variables and functions */
 int /*<<< orphan*/  VALGRIND_FREELIKE_BLOCK (void*,size_t) ; 
 int /*<<< orphan*/  VALGRIND_MAKE_MEM_DEFINED (void*,size_t) ; 
 int /*<<< orphan*/  VALGRIND_MAKE_MEM_NOACCESS (void*,size_t) ; 
 int /*<<< orphan*/  VALGRIND_MAKE_MEM_UNDEFINED (void*,size_t) ; 

void
valgrind_make_mem_noaccess(void *ptr, size_t usize)
{

	VALGRIND_MAKE_MEM_NOACCESS(ptr, usize);
}

void
valgrind_make_mem_undefined(void *ptr, size_t usize)
{

	VALGRIND_MAKE_MEM_UNDEFINED(ptr, usize);
}

void
valgrind_make_mem_defined(void *ptr, size_t usize)
{

	VALGRIND_MAKE_MEM_DEFINED(ptr, usize);
}

void
valgrind_freelike_block(void *ptr, size_t usize)
{

	VALGRIND_FREELIKE_BLOCK(ptr, usize);
}

