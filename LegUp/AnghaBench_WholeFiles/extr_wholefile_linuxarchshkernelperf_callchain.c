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
struct pt_regs {unsigned long pc; } ;
struct perf_callchain_entry_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  callchain_ops ; 
 int /*<<< orphan*/  perf_callchain_store (struct perf_callchain_entry_ctx*,unsigned long) ; 
 int /*<<< orphan*/  unwind_stack (int /*<<< orphan*/ *,struct pt_regs*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct perf_callchain_entry_ctx*) ; 

__attribute__((used)) static int callchain_stack(void *data, char *name)
{
	return 0;
}

__attribute__((used)) static void callchain_address(void *data, unsigned long addr, int reliable)
{
	struct perf_callchain_entry_ctx *entry = data;

	if (reliable)
		perf_callchain_store(entry, addr);
}

void
perf_callchain_kernel(struct perf_callchain_entry_ctx *entry, struct pt_regs *regs)
{
	perf_callchain_store(entry, regs->pc);

	unwind_stack(NULL, regs, NULL, &callchain_ops, entry);
}

