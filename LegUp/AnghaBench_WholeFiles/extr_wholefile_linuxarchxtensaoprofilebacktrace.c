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
struct stackframe {int /*<<< orphan*/  pc; } ;
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  oprofile_add_trace (int /*<<< orphan*/ ) ; 
 scalar_t__ user_mode (struct pt_regs* const) ; 
 int /*<<< orphan*/  xtensa_backtrace_kernel (struct pt_regs* const,unsigned int,int (*) (struct stackframe*,void*),int (*) (struct stackframe*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xtensa_backtrace_user (struct pt_regs* const,unsigned int,int (*) (struct stackframe*,void*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static int xtensa_backtrace_cb(struct stackframe *frame, void *data)
{
	oprofile_add_trace(frame->pc);
	return 0;
}

void xtensa_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	if (user_mode(regs))
		xtensa_backtrace_user(regs, depth, xtensa_backtrace_cb, NULL);
	else
		xtensa_backtrace_kernel(regs, depth, xtensa_backtrace_cb,
					xtensa_backtrace_cb, NULL);
}

