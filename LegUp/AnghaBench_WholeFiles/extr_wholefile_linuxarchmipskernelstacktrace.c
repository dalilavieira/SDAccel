#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned long reg29; int /*<<< orphan*/  reg31; } ;
struct task_struct {TYPE_1__ thread; } ;
struct stack_trace {scalar_t__ skip; unsigned long* entries; scalar_t__ nr_entries; scalar_t__ max_entries; } ;
struct pt_regs {unsigned long* regs; int /*<<< orphan*/  cp0_epc; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ __kernel_text_address (unsigned long) ; 
 struct task_struct* current ; 
 int /*<<< orphan*/  in_sched_functions (unsigned long) ; 
 int /*<<< orphan*/  kstack_end (unsigned long*) ; 
 int /*<<< orphan*/  prepare_frametrace (struct pt_regs*) ; 
 void save_stack_trace_tsk (struct task_struct*,struct stack_trace*) ; 

__attribute__((used)) static void save_raw_context_stack(struct stack_trace *trace,
	unsigned long reg29, int savesched)
{
	unsigned long *sp = (unsigned long *)reg29;
	unsigned long addr;

	while (!kstack_end(sp)) {
		addr = *sp++;
		if (__kernel_text_address(addr) &&
		    (savesched || !in_sched_functions(addr))) {
			if (trace->skip > 0)
				trace->skip--;
			else
				trace->entries[trace->nr_entries++] = addr;
			if (trace->nr_entries >= trace->max_entries)
				break;
		}
	}
}

__attribute__((used)) static void save_context_stack(struct stack_trace *trace,
	struct task_struct *tsk, struct pt_regs *regs, int savesched)
{
	unsigned long sp = regs->regs[29];
#ifdef CONFIG_KALLSYMS
	unsigned long ra = regs->regs[31];
	unsigned long pc = regs->cp0_epc;

	if (raw_show_trace || !__kernel_text_address(pc)) {
		unsigned long stack_page =
			(unsigned long)task_stack_page(tsk);
		if (stack_page && sp >= stack_page &&
		    sp <= stack_page + THREAD_SIZE - 32)
			save_raw_context_stack(trace, sp, savesched);
		return;
	}
	do {
		if (savesched || !in_sched_functions(pc)) {
			if (trace->skip > 0)
				trace->skip--;
			else
				trace->entries[trace->nr_entries++] = pc;
			if (trace->nr_entries >= trace->max_entries)
				break;
		}
		pc = unwind_stack(tsk, &sp, pc, &ra);
	} while (pc);
#else
	save_raw_context_stack(trace, sp, savesched);
#endif
}

void save_stack_trace(struct stack_trace *trace)
{
	save_stack_trace_tsk(current, trace);
}

void save_stack_trace_tsk(struct task_struct *tsk, struct stack_trace *trace)
{
	struct pt_regs dummyregs;
	struct pt_regs *regs = &dummyregs;

	WARN_ON(trace->nr_entries || !trace->max_entries);

	if (tsk != current) {
		regs->regs[29] = tsk->thread.reg29;
		regs->regs[31] = 0;
		regs->cp0_epc = tsk->thread.reg31;
	} else
		prepare_frametrace(regs);
	save_context_stack(trace, tsk, regs, tsk == current);
}

