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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  pr_emerg (char*,long) ; 
 int /*<<< orphan*/  show_regs (struct pt_regs*) ; 

void df_debug(struct pt_regs *regs, long error_code)
{
	pr_emerg("PANIC: double fault, error_code: 0x%lx\n", error_code);
	show_regs(regs);
	panic("Machine halted.");
}

