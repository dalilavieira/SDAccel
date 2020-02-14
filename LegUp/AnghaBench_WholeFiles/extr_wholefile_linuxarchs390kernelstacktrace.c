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
struct TYPE_2__ {unsigned long ksp; } ;
struct task_struct {TYPE_1__ thread; } ;
struct stack_trace {scalar_t__ skip; scalar_t__ nr_entries; scalar_t__ max_entries; unsigned long* entries; } ;
struct pt_regs {int dummy; } ;

/* Variables and functions */
 void* ULONG_MAX ; 
 struct task_struct* current ; 
 unsigned long current_stack_pointer () ; 
 int /*<<< orphan*/  dump_trace (int (*) (void*,unsigned long,int),struct stack_trace*,struct task_struct*,unsigned long) ; 
 scalar_t__ in_sched_functions (unsigned long) ; 
 unsigned long kernel_stack_pointer (struct pt_regs*) ; 

__attribute__((used)) static int __save_address(void *data, unsigned long address, int nosched)
{
	struct stack_trace *trace = data;

	if (nosched && in_sched_functions(address))
		return 0;
	if (trace->skip > 0) {
		trace->skip--;
		return 0;
	}
	if (trace->nr_entries < trace->max_entries) {
		trace->entries[trace->nr_entries++] = address;
		return 0;
	}
	return 1;
}

__attribute__((used)) static int save_address(void *data, unsigned long address, int reliable)
{
	return __save_address(data, address, 0);
}

__attribute__((used)) static int save_address_nosched(void *data, unsigned long address, int reliable)
{
	return __save_address(data, address, 1);
}

void save_stack_trace(struct stack_trace *trace)
{
	unsigned long sp;

	sp = current_stack_pointer();
	dump_trace(save_address, trace, NULL, sp);
	if (trace->nr_entries < trace->max_entries)
		trace->entries[trace->nr_entries++] = ULONG_MAX;
}

void save_stack_trace_tsk(struct task_struct *tsk, struct stack_trace *trace)
{
	unsigned long sp;

	sp = tsk->thread.ksp;
	if (tsk == current)
		sp = current_stack_pointer();
	dump_trace(save_address_nosched, trace, tsk, sp);
	if (trace->nr_entries < trace->max_entries)
		trace->entries[trace->nr_entries++] = ULONG_MAX;
}

void save_stack_trace_regs(struct pt_regs *regs, struct stack_trace *trace)
{
	unsigned long sp;

	sp = kernel_stack_pointer(regs);
	dump_trace(save_address, trace, NULL, sp);
	if (trace->nr_entries < trace->max_entries)
		trace->entries[trace->nr_entries++] = ULONG_MAX;
}

