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
struct cpulaunch {int flags; unsigned long pc; unsigned long gp; unsigned long sp; unsigned long a0; } ;

/* Variables and functions */
 scalar_t__ CKSEG0ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CPULAUNCH ; 
 int LAUNCH_FGO ; 
 int LAUNCH_FGONE ; 
 int LAUNCH_FREADY ; 
 int NCPULAUNCH ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  smp_rmb () ; 
 int /*<<< orphan*/  smp_wmb () ; 

int amon_cpu_avail(int cpu)
{
	struct cpulaunch *launch = (struct cpulaunch *)CKSEG0ADDR(CPULAUNCH);

	if (cpu < 0 || cpu >= NCPULAUNCH) {
		pr_debug("avail: cpu%d is out of range\n", cpu);
		return 0;
	}

	launch += cpu;
	if (!(launch->flags & LAUNCH_FREADY)) {
		pr_debug("avail: cpu%d is not ready\n", cpu);
		return 0;
	}
	if (launch->flags & (LAUNCH_FGO|LAUNCH_FGONE)) {
		pr_debug("avail: too late.. cpu%d is already gone\n", cpu);
		return 0;
	}

	return 1;
}

int amon_cpu_start(int cpu,
		    unsigned long pc, unsigned long sp,
		    unsigned long gp, unsigned long a0)
{
	volatile struct cpulaunch *launch =
		(struct cpulaunch  *)CKSEG0ADDR(CPULAUNCH);

	if (!amon_cpu_avail(cpu))
		return -1;
	if (cpu == smp_processor_id()) {
		pr_debug("launch: I am cpu%d!\n", cpu);
		return -1;
	}
	launch += cpu;

	pr_debug("launch: starting cpu%d\n", cpu);

	launch->pc = pc;
	launch->gp = gp;
	launch->sp = sp;
	launch->a0 = a0;

	smp_wmb();		/* Target must see parameters before go */
	launch->flags |= LAUNCH_FGO;
	smp_wmb();		/* Target must see go before we poll  */

	while ((launch->flags & LAUNCH_FGONE) == 0)
		;
	smp_rmb();	/* Target will be updating flags soon */
	pr_debug("launch: cpu%d gone!\n", cpu);

	return 0;
}

