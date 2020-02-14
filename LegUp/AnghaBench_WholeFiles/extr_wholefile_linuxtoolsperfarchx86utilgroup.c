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
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ sysctl__read_int (char*,int*) ; 

bool arch_topdown_check_group(bool *warn)
{
	int n;

	if (sysctl__read_int("kernel/nmi_watchdog", &n) < 0)
		return false;
	if (n > 0) {
		*warn = true;
		return false;
	}
	return true;
}

void arch_topdown_group_warn(void)
{
	fprintf(stderr,
		"nmi_watchdog enabled with topdown. May give wrong results.\n"
		"Disable with echo 0 > /proc/sys/kernel/nmi_watchdog\n");
}

