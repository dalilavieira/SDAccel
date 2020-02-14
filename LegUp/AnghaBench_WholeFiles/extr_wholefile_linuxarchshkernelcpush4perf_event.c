#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct hw_perf_event {unsigned int config; } ;
struct TYPE_2__ {int num_events; } ;

/* Variables and functions */
 int /*<<< orphan*/  PMCR (int) ; 
 unsigned int PMCR_PMCLR ; 
 unsigned int PMCR_PMEN ; 
 unsigned int PMCR_PMM_MASK ; 
 unsigned int PMCR_PMST ; 
 int /*<<< orphan*/  PMCTRH (int) ; 
 int /*<<< orphan*/  PMCTRL (int) ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 unsigned int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (unsigned int,int /*<<< orphan*/ ) ; 
 int* sh7750_general_events ; 
 TYPE_1__ sh7750_pmu ; 

__attribute__((used)) static int sh7750_event_map(int event)
{
	return sh7750_general_events[event];
}

__attribute__((used)) static u64 sh7750_pmu_read(int idx)
{
	return (u64)((u64)(__raw_readl(PMCTRH(idx)) & 0xffff) << 32) |
			   __raw_readl(PMCTRL(idx));
}

__attribute__((used)) static void sh7750_pmu_disable(struct hw_perf_event *hwc, int idx)
{
	unsigned int tmp;

	tmp = __raw_readw(PMCR(idx));
	tmp &= ~(PMCR_PMM_MASK | PMCR_PMEN);
	__raw_writew(tmp, PMCR(idx));
}

__attribute__((used)) static void sh7750_pmu_enable(struct hw_perf_event *hwc, int idx)
{
	__raw_writew(__raw_readw(PMCR(idx)) | PMCR_PMCLR, PMCR(idx));
	__raw_writew(hwc->config | PMCR_PMEN | PMCR_PMST, PMCR(idx));
}

__attribute__((used)) static void sh7750_pmu_disable_all(void)
{
	int i;

	for (i = 0; i < sh7750_pmu.num_events; i++)
		__raw_writew(__raw_readw(PMCR(i)) & ~PMCR_PMEN, PMCR(i));
}

__attribute__((used)) static void sh7750_pmu_enable_all(void)
{
	int i;

	for (i = 0; i < sh7750_pmu.num_events; i++)
		__raw_writew(__raw_readw(PMCR(i)) | PMCR_PMEN, PMCR(i));
}

