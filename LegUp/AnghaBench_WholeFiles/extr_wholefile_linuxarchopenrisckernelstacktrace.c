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
struct stack_trace {scalar_t__ skip; scalar_t__ nr_entries; scalar_t__ max_entries; unsigned long* entries; } ;
struct pt_regs {scalar_t__ sp; } ;

/* Variables and functions */
 scalar_t__ KSTK_ESP (struct task_struct*) ; 
 struct task_struct* current ; 
 scalar_t__ in_sched_functions (unsigned long) ; 
 int /*<<< orphan*/  unwind_stack (struct stack_trace*,unsigned long*,void (*) (void*,unsigned long,int)) ; 

__attribute__((used)) static void
save_stack_address(void *data, unsigned long addr, int reliable)
{
	struct stack_trace *trace = data;

	if (!reliable)
		return;

	if (trace->skip > 0) {
		trace->skip--;
		return;
	}

	if (trace->nr_entries < trace->max_entries)
		trace->entries[trace->nr_entries++] = addr;
}

void save_stack_trace(struct stack_trace *trace)
{
	unwind_stack(trace, (unsigned long *) &trace, save_stack_address);
}

__attribute__((used)) static void
save_stack_address_nosched(void *data, unsigned long addr, int reliable)
{
	struct stack_trace *trace = (struct stack_trace *)data;

	if (!reliable)
		return;

	if (in_sched_functions(addr))
		return;

	if (trace->skip > 0) {
		trace->skip--;
		return;
	}

	if (trace->nr_entries < trace->max_entries)
		trace->entries[trace->nr_entries++] = addr;
}

void save_stack_trace_tsk(struct task_struct *tsk, struct stack_trace *trace)
{
	unsigned long *sp = NULL;

	if (tsk == current)
		sp = (unsigned long *) &sp;
	else
		sp = (unsigned long *) KSTK_ESP(tsk);

	unwind_stack(trace, sp, save_stack_address_nosched);
}

void
save_stack_trace_regs(struct pt_regs *regs, struct stack_trace *trace)
{
	unwind_stack(trace, (unsigned long *) regs->sp,
		     save_stack_address_nosched);
}

