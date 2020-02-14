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
 scalar_t__ ESPFIX_BASE_ADDR ; 
 int ESPFIX_PAGE_SPACE ; 
 unsigned int ESPFIX_STACKS_PER_PAGE ; 
 unsigned long ESPFIX_STACK_SIZE ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  arch_get_random_long (unsigned long*) ; 
 unsigned int page_random ; 
 unsigned long rdtsc () ; 
 unsigned int slot_random ; 

__attribute__((used)) static inline unsigned long espfix_base_addr(unsigned int cpu)
{
	unsigned long page, slot;
	unsigned long addr;

	page = (cpu / ESPFIX_STACKS_PER_PAGE) ^ page_random;
	slot = (cpu + slot_random) % ESPFIX_STACKS_PER_PAGE;
	addr = (page << PAGE_SHIFT) + (slot * ESPFIX_STACK_SIZE);
	addr = (addr & 0xffffUL) | ((addr & ~0xffffUL) << 16);
	addr += ESPFIX_BASE_ADDR;
	return addr;
}

__attribute__((used)) static void init_espfix_random(void)
{
	unsigned long rand;

	/*
	 * This is run before the entropy pools are initialized,
	 * but this is hopefully better than nothing.
	 */
	if (!arch_get_random_long(&rand)) {
		/* The constant is an arbitrary large prime */
		rand = rdtsc();
		rand *= 0xc345c6b72fd16123UL;
	}

	slot_random = rand % ESPFIX_STACKS_PER_PAGE;
	page_random = (rand / ESPFIX_STACKS_PER_PAGE)
		& (ESPFIX_PAGE_SPACE - 1);
}

