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
struct task_struct {int dummy; } ;

/* Variables and functions */
 int THREAD_SIZE ; 
 scalar_t__ check_kernel_text (unsigned long) ; 
 int kstack_depth_to_print ; 
 int /*<<< orphan*/  pr_cont (char*,unsigned long) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 

void show_stack(struct task_struct *task, unsigned long *esp)
{
	unsigned long *stack,  addr;
	int i;

	if (esp == NULL)
		esp = (unsigned long *) &esp;

	stack = esp;

	pr_info("Stack from %08lx:", (unsigned long)stack);
	for (i = 0; i < kstack_depth_to_print; i++) {
		if (((unsigned long)stack & (THREAD_SIZE - 1)) >=
		    THREAD_SIZE-4)
			break;
		if (i % 8 == 0)
			pr_info(" ");
		pr_cont(" %08lx", *stack++);
	}

	pr_info("\nCall Trace:\n");
	i = 0;
	stack = esp;
	while (((unsigned long)stack & (THREAD_SIZE - 1)) < THREAD_SIZE-4) {
		addr = *stack++;
		/*
		 * If the address is either in the text segment of the
		 * kernel, or in the region which contains vmalloc'ed
		 * memory, it *may* be the address of a calling
		 * routine; if so, print it so that someone tracing
		 * down the cause of the crash will be able to figure
		 * out the call path that was taken.
		 */
		if (check_kernel_text(addr)) {
			if (i % 4 == 0)
				pr_info("       ");
			pr_cont(" [<%08lx>]", addr);
			i++;
		}
	}
	pr_info("\n");
}

