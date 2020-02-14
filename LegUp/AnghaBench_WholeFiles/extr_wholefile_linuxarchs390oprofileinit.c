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
struct pt_regs {int /*<<< orphan*/ * gprs; } ;

/* Variables and functions */
 int /*<<< orphan*/  dump_trace (int (*) (void*,unsigned long,int),unsigned int*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oprofile_add_trace (unsigned long) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 

__attribute__((used)) static int __s390_backtrace(void *data, unsigned long address, int reliable)
{
	unsigned int *depth = data;

	if (*depth == 0)
		return 1;
	(*depth)--;
	oprofile_add_trace(address);
	return 0;
}

__attribute__((used)) static void s390_backtrace(struct pt_regs *regs, unsigned int depth)
{
	if (user_mode(regs))
		return;
	dump_trace(__s390_backtrace, &depth, NULL, regs->gprs[15]);
}

