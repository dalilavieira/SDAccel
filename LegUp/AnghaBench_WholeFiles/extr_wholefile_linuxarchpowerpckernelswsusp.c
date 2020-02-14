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
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  flush_all_to_thread (int /*<<< orphan*/ ) ; 

void save_processor_state(void)
{
	/*
	 * flush out all the special registers so we don't need
	 * to save them in the snapshot
	 */
	flush_all_to_thread(current);

#ifdef CONFIG_PPC64
	hard_irq_disable();
#endif

}

void restore_processor_state(void)
{
#ifdef CONFIG_PPC32
	switch_mmu_context(current->active_mm, current->active_mm, NULL);
#endif
}

