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
typedef  unsigned int u64 ;
struct hw_perf_event {int config; } ;
struct TYPE_2__ {int num_events; } ;

/* Variables and functions */
 unsigned int CCBR_CIT_MASK ; 
 int CCBR_CMDS ; 
 unsigned int CCBR_DUC ; 
 int CCBR_PPCE ; 
 unsigned int PMCAT_CLR0 ; 
 unsigned int PMCAT_CLR1 ; 
 unsigned int PMCAT_EMU_CLR_MASK ; 
 int /*<<< orphan*/  PPC_CCBR (int) ; 
 int /*<<< orphan*/  PPC_PMCAT ; 
 int /*<<< orphan*/  PPC_PMCTR (int) ; 
 unsigned int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ ) ; 
 int* sh4a_general_events ; 
 TYPE_1__ sh4a_pmu ; 

__attribute__((used)) static int sh4a_event_map(int event)
{
	return sh4a_general_events[event];
}

__attribute__((used)) static u64 sh4a_pmu_read(int idx)
{
	return __raw_readl(PPC_PMCTR(idx));
}

__attribute__((used)) static void sh4a_pmu_disable(struct hw_perf_event *hwc, int idx)
{
	unsigned int tmp;

	tmp = __raw_readl(PPC_CCBR(idx));
	tmp &= ~(CCBR_CIT_MASK | CCBR_DUC);
	__raw_writel(tmp, PPC_CCBR(idx));
}

__attribute__((used)) static void sh4a_pmu_enable(struct hw_perf_event *hwc, int idx)
{
	unsigned int tmp;

	tmp = __raw_readl(PPC_PMCAT);
	tmp &= ~PMCAT_EMU_CLR_MASK;
	tmp |= idx ? PMCAT_CLR1 : PMCAT_CLR0;
	__raw_writel(tmp, PPC_PMCAT);

	tmp = __raw_readl(PPC_CCBR(idx));
	tmp |= (hwc->config << 6) | CCBR_CMDS | CCBR_PPCE;
	__raw_writel(tmp, PPC_CCBR(idx));

	__raw_writel(__raw_readl(PPC_CCBR(idx)) | CCBR_DUC, PPC_CCBR(idx));
}

__attribute__((used)) static void sh4a_pmu_disable_all(void)
{
	int i;

	for (i = 0; i < sh4a_pmu.num_events; i++)
		__raw_writel(__raw_readl(PPC_CCBR(i)) & ~CCBR_DUC, PPC_CCBR(i));
}

__attribute__((used)) static void sh4a_pmu_enable_all(void)
{
	int i;

	for (i = 0; i < sh4a_pmu.num_events; i++)
		__raw_writel(__raw_readl(PPC_CCBR(i)) | CCBR_DUC, PPC_CCBR(i));
}

