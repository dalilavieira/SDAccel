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
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  cpu_reset () ; 
 int /*<<< orphan*/  lcd_disp_at_pos (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_disable () ; 

void platform_halt(void)
{
	lcd_disp_at_pos(" HALT ", 0);
	local_irq_disable();
	while (1)
		cpu_relax();
}

void platform_power_off(void)
{
	lcd_disp_at_pos("POWEROFF", 0);
	local_irq_disable();
	while (1)
		cpu_relax();
}

void platform_restart(void)
{
	/* Flush and reset the mmu, simulate a processor reset, and
	 * jump to the reset vector. */
	cpu_reset();
	/* control never gets here */
}

