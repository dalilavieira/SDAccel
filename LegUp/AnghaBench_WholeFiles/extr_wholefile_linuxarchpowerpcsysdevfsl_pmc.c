#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ suspend_state_t ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  pmcsr; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int PMCSR_SLP ; 
 scalar_t__ PM_SUSPEND_STANDBY ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int in_be32 (int /*<<< orphan*/ *) ; 
 TYPE_1__* of_iomap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__* pmc_dev ; 
 TYPE_1__* pmc_regs ; 
 int /*<<< orphan*/  pmc_suspend_ops ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,int) ; 
 scalar_t__ spin_event_timeout (int,int,int) ; 
 int /*<<< orphan*/  suspend_set_ops (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pmc_suspend_enter(suspend_state_t state)
{
	int ret;

	setbits32(&pmc_regs->pmcsr, PMCSR_SLP);
	/* At this point, the CPU is asleep. */

	/* Upon resume, wait for SLP bit to be clear. */
	ret = spin_event_timeout((in_be32(&pmc_regs->pmcsr) & PMCSR_SLP) == 0,
				 10000, 10) ? 0 : -ETIMEDOUT;
	if (ret)
		dev_err(pmc_dev, "tired waiting for SLP bit to clear\n");
	return ret;
}

__attribute__((used)) static int pmc_suspend_valid(suspend_state_t state)
{
	if (state != PM_SUSPEND_STANDBY)
		return 0;
	return 1;
}

__attribute__((used)) static int pmc_probe(struct platform_device *ofdev)
{
	pmc_regs = of_iomap(ofdev->dev.of_node, 0);
	if (!pmc_regs)
		return -ENOMEM;

	pmc_dev = &ofdev->dev;
	suspend_set_ops(&pmc_suspend_ops);
	return 0;
}

