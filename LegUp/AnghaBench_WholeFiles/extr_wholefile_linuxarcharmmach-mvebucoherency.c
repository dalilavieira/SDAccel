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
typedef  int /*<<< orphan*/  u32 ;
struct notifier_block {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 unsigned long BUS_NOTIFY_ADD_DEVICE ; 
 int /*<<< orphan*/  CPU_CONFIG_SHARED_L2 ; 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 int /*<<< orphan*/  arm_coherent_dma_ops ; 
 int /*<<< orphan*/  cpu_config_base ; 
 int /*<<< orphan*/  readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_dma_ops (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int mvebu_get_soc_id(u32 *dev, u32 *rev)
{
	return -1;
}

__attribute__((used)) static void armada_xp_clear_shared_l2(void)
{
	u32 reg;

	if (!cpu_config_base)
		return;

	reg = readl(cpu_config_base);
	reg &= ~CPU_CONFIG_SHARED_L2;
	writel(reg, cpu_config_base);
}

__attribute__((used)) static int mvebu_hwcc_notifier(struct notifier_block *nb,
			       unsigned long event, void *__dev)
{
	struct device *dev = __dev;

	if (event != BUS_NOTIFY_ADD_DEVICE)
		return NOTIFY_DONE;
	set_dma_ops(dev, &arm_coherent_dma_ops);

	return NOTIFY_OK;
}

__attribute__((used)) static int armada_xp_clear_l2_starting(unsigned int cpu)
{
	armada_xp_clear_shared_l2();
	return 0;
}

