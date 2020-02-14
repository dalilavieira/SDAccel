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
 int /*<<< orphan*/  __vmstop () ; 
 int /*<<< orphan*/  smp_send_stop () ; 

void machine_power_off(void)
{
	smp_send_stop();
	__vmstop();
}

void machine_halt(void)
{
}

void machine_restart(char *cmd)
{
}

