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
struct arch_hw_breakpoint {int len; int type; unsigned long address; } ;
struct TYPE_2__ {int num_events; } ;

/* Variables and functions */
 int /*<<< orphan*/  UBC_CAR (int) ; 
 int /*<<< orphan*/  UBC_CBR (int) ; 
 int UBC_CBR_CE ; 
 int /*<<< orphan*/  UBC_CCMFR ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 
 TYPE_1__ sh4a_ubc ; 

__attribute__((used)) static void sh4a_ubc_enable(struct arch_hw_breakpoint *info, int idx)
{
	__raw_writel(UBC_CBR_CE | info->len | info->type, UBC_CBR(idx));
	__raw_writel(info->address, UBC_CAR(idx));
}

__attribute__((used)) static void sh4a_ubc_disable(struct arch_hw_breakpoint *info, int idx)
{
	__raw_writel(0, UBC_CBR(idx));
	__raw_writel(0, UBC_CAR(idx));
}

__attribute__((used)) static void sh4a_ubc_enable_all(unsigned long mask)
{
	int i;

	for (i = 0; i < sh4a_ubc.num_events; i++)
		if (mask & (1 << i))
			__raw_writel(__raw_readl(UBC_CBR(i)) | UBC_CBR_CE,
				     UBC_CBR(i));
}

__attribute__((used)) static void sh4a_ubc_disable_all(void)
{
	int i;

	for (i = 0; i < sh4a_ubc.num_events; i++)
		__raw_writel(__raw_readl(UBC_CBR(i)) & ~UBC_CBR_CE,
			     UBC_CBR(i));
}

__attribute__((used)) static unsigned long sh4a_ubc_active_mask(void)
{
	unsigned long active = 0;
	int i;

	for (i = 0; i < sh4a_ubc.num_events; i++)
		if (__raw_readl(UBC_CBR(i)) & UBC_CBR_CE)
			active |= (1 << i);

	return active;
}

__attribute__((used)) static unsigned long sh4a_ubc_triggered_mask(void)
{
	return __raw_readl(UBC_CCMFR);
}

__attribute__((used)) static void sh4a_ubc_clear_triggered_mask(unsigned long mask)
{
	__raw_writel(__raw_readl(UBC_CCMFR) & ~mask, UBC_CCMFR);
}

