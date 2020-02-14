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
struct pt_regs {unsigned long* regs; } ;
struct perf_callchain_entry_ctx {scalar_t__ nr; scalar_t__ max_stack; } ;

/* Variables and functions */
 scalar_t__ __kernel_text_address (unsigned long) ; 
 int /*<<< orphan*/  kstack_end (unsigned long*) ; 
 int /*<<< orphan*/  perf_callchain_store (struct perf_callchain_entry_ctx*,unsigned long) ; 

__attribute__((used)) static void save_raw_perf_callchain(struct perf_callchain_entry_ctx *entry,
				    unsigned long reg29)
{
	unsigned long *sp = (unsigned long *)reg29;
	unsigned long addr;

	while (!kstack_end(sp)) {
		addr = *sp++;
		if (__kernel_text_address(addr)) {
			perf_callchain_store(entry, addr);
			if (entry->nr >= entry->max_stack)
				break;
		}
	}
}

void perf_callchain_kernel(struct perf_callchain_entry_ctx *entry,
			   struct pt_regs *regs)
{
	unsigned long sp = regs->regs[29];
#ifdef CONFIG_KALLSYMS
	unsigned long ra = regs->regs[31];
	unsigned long pc = regs->cp0_epc;

	if (raw_show_trace || !__kernel_text_address(pc)) {
		unsigned long stack_page =
			(unsigned long)task_stack_page(current);
		if (stack_page && sp >= stack_page &&
		    sp <= stack_page + THREAD_SIZE - 32)
			save_raw_perf_callchain(entry, sp);
		return;
	}
	do {
		perf_callchain_store(entry, pc);
		if (entry->nr >= entry->max_stack)
			break;
		pc = unwind_stack(current, &sp, pc, &ra);
	} while (pc);
#else
	save_raw_perf_callchain(entry, sp);
#endif
}

