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
typedef  int u32 ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int CPU0_DBG_SRST_REQ_EN ; 
 int CPU0_HPM_SRST_REQ_EN ; 
 int CPU0_NEON_SRST_REQ_EN ; 
 int CPU0_SRST_REQ_EN ; 
 int CPU0_WFI_MASK_CFG ; 
 int CPU2_ISO_CTRL ; 
 int CRG20_CPU1_RESET ; 
 int ENOENT ; 
 int ENOMEM ; 
 scalar_t__ ERROR_CTRL ; 
 scalar_t__ HI3620_CTRL ; 
 scalar_t__ HIP01_PERI9 ; 
 scalar_t__ HIX5HD2_PERI_CRG20 ; 
 scalar_t__ HIX5HD2_PERI_PMC0 ; 
 unsigned int PERI9_CPU1_RESET ; 
 int PMC0_CPU1_PMC_ENABLE ; 
 int PMC0_CPU1_POWERDOWN ; 
 int PMC0_CPU1_WAIT_MTCOMS_ACK ; 
 scalar_t__ SCCPUCOREDIS ; 
 scalar_t__ SCCPUCOREEN ; 
 scalar_t__ SCCPURSTDIS ; 
 scalar_t__ SCCPURSTEN ; 
 scalar_t__ SCISODIS ; 
 scalar_t__ SCISOEN ; 
 scalar_t__ SCPERCTRL0 ; 
 scalar_t__ SCPERPWRDIS ; 
 scalar_t__ SCPERPWREN ; 
 scalar_t__ ctrl_base ; 
 int /*<<< orphan*/  flush_cache_all () ; 
 scalar_t__ id ; 
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 void* readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned int,scalar_t__) ; 

__attribute__((used)) static void set_cpu_hi3620(int cpu, bool enable)
{
	u32 val = 0;

	if (enable) {
		/* MTCMOS set */
		if ((cpu == 2) || (cpu == 3))
			writel_relaxed(CPU2_ISO_CTRL << (cpu - 2),
				       ctrl_base + SCPERPWREN);
		udelay(100);

		/* Enable core */
		writel_relaxed(0x01 << cpu, ctrl_base + SCCPUCOREEN);

		/* unreset */
		val = CPU0_DBG_SRST_REQ_EN | CPU0_NEON_SRST_REQ_EN
			| CPU0_SRST_REQ_EN;
		writel_relaxed(val << cpu, ctrl_base + SCCPURSTDIS);
		/* reset */
		val |= CPU0_HPM_SRST_REQ_EN;
		writel_relaxed(val << cpu, ctrl_base + SCCPURSTEN);

		/* ISO disable */
		if ((cpu == 2) || (cpu == 3))
			writel_relaxed(CPU2_ISO_CTRL << (cpu - 2),
				       ctrl_base + SCISODIS);
		udelay(1);

		/* WFI Mask */
		val = readl_relaxed(ctrl_base + SCPERCTRL0);
		val &= ~(CPU0_WFI_MASK_CFG << cpu);
		writel_relaxed(val, ctrl_base + SCPERCTRL0);

		/* Unreset */
		val = CPU0_DBG_SRST_REQ_EN | CPU0_NEON_SRST_REQ_EN
			| CPU0_SRST_REQ_EN | CPU0_HPM_SRST_REQ_EN;
		writel_relaxed(val << cpu, ctrl_base + SCCPURSTDIS);
	} else {
		/* wfi mask */
		val = readl_relaxed(ctrl_base + SCPERCTRL0);
		val |= (CPU0_WFI_MASK_CFG << cpu);
		writel_relaxed(val, ctrl_base + SCPERCTRL0);

		/* disable core*/
		writel_relaxed(0x01 << cpu, ctrl_base + SCCPUCOREDIS);

		if ((cpu == 2) || (cpu == 3)) {
			/* iso enable */
			writel_relaxed(CPU2_ISO_CTRL << (cpu - 2),
				       ctrl_base + SCISOEN);
			udelay(1);
		}

		/* reset */
		val = CPU0_DBG_SRST_REQ_EN | CPU0_NEON_SRST_REQ_EN
			| CPU0_SRST_REQ_EN | CPU0_HPM_SRST_REQ_EN;
		writel_relaxed(val << cpu, ctrl_base + SCCPURSTEN);

		if ((cpu == 2) || (cpu == 3)) {
			/* MTCMOS unset */
			writel_relaxed(CPU2_ISO_CTRL << (cpu - 2),
				       ctrl_base + SCPERPWRDIS);
			udelay(100);
		}
	}
}

__attribute__((used)) static int hi3xxx_hotplug_init(void)
{
	struct device_node *node;

	node = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
	if (!node) {
		id = ERROR_CTRL;
		return -ENOENT;
	}

	ctrl_base = of_iomap(node, 0);
	of_node_put(node);
	if (!ctrl_base) {
		id = ERROR_CTRL;
		return -ENOMEM;
	}

	id = HI3620_CTRL;
	return 0;
}

void hi3xxx_set_cpu(int cpu, bool enable)
{
	if (!ctrl_base) {
		if (hi3xxx_hotplug_init() < 0)
			return;
	}

	if (id == HI3620_CTRL)
		set_cpu_hi3620(cpu, enable);
}

__attribute__((used)) static bool hix5hd2_hotplug_init(void)
{
	struct device_node *np;

	np = of_find_compatible_node(NULL, NULL, "hisilicon,cpuctrl");
	if (!np)
		return false;

	ctrl_base = of_iomap(np, 0);
	of_node_put(np);
	if (!ctrl_base)
		return false;

	return true;
}

void hix5hd2_set_cpu(int cpu, bool enable)
{
	u32 val = 0;

	if (!ctrl_base)
		if (!hix5hd2_hotplug_init())
			BUG();

	if (enable) {
		/* power on cpu1 */
		val = readl_relaxed(ctrl_base + HIX5HD2_PERI_PMC0);
		val &= ~(PMC0_CPU1_WAIT_MTCOMS_ACK | PMC0_CPU1_POWERDOWN);
		val |= PMC0_CPU1_PMC_ENABLE;
		writel_relaxed(val, ctrl_base + HIX5HD2_PERI_PMC0);
		/* unreset */
		val = readl_relaxed(ctrl_base + HIX5HD2_PERI_CRG20);
		val &= ~CRG20_CPU1_RESET;
		writel_relaxed(val, ctrl_base + HIX5HD2_PERI_CRG20);
	} else {
		/* power down cpu1 */
		val = readl_relaxed(ctrl_base + HIX5HD2_PERI_PMC0);
		val |= PMC0_CPU1_PMC_ENABLE | PMC0_CPU1_POWERDOWN;
		val &= ~PMC0_CPU1_WAIT_MTCOMS_ACK;
		writel_relaxed(val, ctrl_base + HIX5HD2_PERI_PMC0);

		/* reset */
		val = readl_relaxed(ctrl_base + HIX5HD2_PERI_CRG20);
		val |= CRG20_CPU1_RESET;
		writel_relaxed(val, ctrl_base + HIX5HD2_PERI_CRG20);
	}
}

void hip01_set_cpu(int cpu, bool enable)
{
	unsigned int temp;
	struct device_node *np;

	if (!ctrl_base) {
		np = of_find_compatible_node(NULL, NULL, "hisilicon,hip01-sysctrl");
		BUG_ON(!np);
		ctrl_base = of_iomap(np, 0);
		of_node_put(np);
		BUG_ON(!ctrl_base);
	}

	if (enable) {
		/* reset on CPU1  */
		temp = readl_relaxed(ctrl_base + HIP01_PERI9);
		temp |= PERI9_CPU1_RESET;
		writel_relaxed(temp, ctrl_base + HIP01_PERI9);

		udelay(50);

		/* unreset on CPU1 */
		temp = readl_relaxed(ctrl_base + HIP01_PERI9);
		temp &= ~PERI9_CPU1_RESET;
		writel_relaxed(temp, ctrl_base + HIP01_PERI9);
	}
}

__attribute__((used)) static inline void cpu_enter_lowpower(void)
{
	unsigned int v;

	flush_cache_all();

	/*
	 * Turn off coherency and L1 D-cache
	 */
	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 1\n"
	"	bic	%0, %0, #0x40\n"
	"	mcr	p15, 0, %0, c1, c0, 1\n"
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	bic	%0, %0, #0x04\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	  : "=&r" (v)
	  : "r" (0)
	  : "cc");
}

