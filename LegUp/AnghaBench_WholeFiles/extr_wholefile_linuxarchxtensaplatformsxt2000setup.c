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
 scalar_t__ XT2000_LED_ADDR ; 
 int /*<<< orphan*/  cpu_reset () ; 
 int /*<<< orphan*/  local_irq_disable () ; 

__attribute__((used)) static void led_print (int f, char *s)
{
	unsigned long* led_addr = (unsigned long*) (XT2000_LED_ADDR + 0xE0) + f;
	int i;
	for (i = f; i < 8; i++)
		if ((*led_addr++ = *s++) == 0)
		    break;
}

void platform_halt(void)
{
	led_print (0, "  HALT  ");
	local_irq_disable();
	while (1);
}

void platform_power_off(void)
{
	led_print (0, "POWEROFF");
	local_irq_disable();
	while (1);
}

void platform_restart(void)
{
	/* Flush and reset the mmu, simulate a processor reset, and
	 * jump to the reset vector. */
	cpu_reset();
	/* control never gets here */
}

