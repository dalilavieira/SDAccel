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
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  p1275_cmd_direct (unsigned long*) ; 

__attribute__((used)) static int prom_service_exists(const char *service_name)
{
	unsigned long args[5];

	args[0] = (unsigned long) "test";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) service_name;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	if (args[4])
		return 0;
	return 1;
}

void prom_sun4v_guest_soft_state(void)
{
	const char *svc = "SUNW,soft-state-supported";
	unsigned long args[3];

	if (!prom_service_exists(svc))
		return;
	args[0] = (unsigned long) svc;
	args[1] = 0;
	args[2] = 0;
	p1275_cmd_direct(args);
}

void prom_reboot(const char *bcommand)
{
	unsigned long args[4];

#ifdef CONFIG_SUN_LDOMS
	if (ldom_domaining_enabled)
		ldom_reboot(bcommand);
#endif
	args[0] = (unsigned long) "boot";
	args[1] = 1;
	args[2] = 0;
	args[3] = (unsigned long) bcommand;

	p1275_cmd_direct(args);
}

void prom_feval(const char *fstring)
{
	unsigned long args[5];

	if (!fstring || fstring[0] == 0)
		return;
	args[0] = (unsigned long) "interpret";
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned long) fstring;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);
}

void prom_cmdline(void)
{
	unsigned long args[3];
	unsigned long flags;

	local_irq_save(flags);

#ifdef CONFIG_SMP
	smp_capture();
#endif

	args[0] = (unsigned long) "enter";
	args[1] = 0;
	args[2] = 0;

	p1275_cmd_direct(args);

#ifdef CONFIG_SMP
	smp_release();
#endif

	local_irq_restore(flags);
}

