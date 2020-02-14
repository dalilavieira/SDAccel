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
 int /*<<< orphan*/  pr_notice (char*) ; 

__attribute__((used)) static void gpio_system_reset(void)
{
	pr_notice("No reset GPIO present - halting!\n");
}

void of_platform_reset_gpio_probe(void)
{
	return;
}

void machine_restart(char *cmd)
{
	pr_notice("Machine restart...\n");
	gpio_system_reset();
	while (1)
		;
}

void machine_shutdown(void)
{
	pr_notice("Machine shutdown...\n");
	while (1)
		;
}

void machine_halt(void)
{
	pr_notice("Machine halt...\n");
	while (1)
		;
}

void machine_power_off(void)
{
	pr_notice("Machine power off...\n");
	while (1)
		;
}

