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
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  opal_trace_depth ; 
 int /*<<< orphan*/  opal_tracepoint_refcount ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 unsigned int* this_cpu_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_opal_entry (unsigned long,unsigned long*) ; 
 int /*<<< orphan*/  trace_opal_exit (long,unsigned long) ; 

int opal_tracepoint_regfunc(void)
{
	opal_tracepoint_refcount++;
	return 0;
}

void opal_tracepoint_unregfunc(void)
{
	opal_tracepoint_refcount--;
}

void __trace_opal_entry(unsigned long opcode, unsigned long *args)
{
	unsigned long flags;
	unsigned int *depth;

	local_irq_save(flags);

	depth = this_cpu_ptr(&opal_trace_depth);

	if (*depth)
		goto out;

	(*depth)++;
	preempt_disable();
	trace_opal_entry(opcode, args);
	(*depth)--;

out:
	local_irq_restore(flags);
}

void __trace_opal_exit(long opcode, unsigned long retval)
{
	unsigned long flags;
	unsigned int *depth;

	local_irq_save(flags);

	depth = this_cpu_ptr(&opal_trace_depth);

	if (*depth)
		goto out;

	(*depth)++;
	trace_opal_exit(opcode, retval);
	preempt_enable();
	(*depth)--;

out:
	local_irq_restore(flags);
}

