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
 int /*<<< orphan*/  pr_info (char*) ; 

void machine_halt(void)
{
	/* Halt the processor */
	__asm__ __volatile__("flag  1\n");
}

void machine_restart(char *__unused)
{
	/* Soft reset : jump to reset vector */
	pr_info("Put your restart handler here\n");
	machine_halt();
}

void machine_power_off(void)
{
	/* FIXME ::  power off ??? */
	machine_halt();
}

