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
typedef  int u32 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_2__ {scalar_t__ rev_id; scalar_t__ dev_id; scalar_t__ system_soft_reset_offset; int /*<<< orphan*/  system_soft_reset; scalar_t__ rstoutn_mask_offset; int /*<<< orphan*/  rstoutn_mask_reset_out_en; } ;

/* Variables and functions */
 int ENODEV ; 
 TYPE_1__* mvebu_sc ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int readl (scalar_t__) ; 
 scalar_t__ system_controller_base ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline int mvebu_get_soc_id(u32 *dev, u32 *rev)
{
	return -1;
}

void mvebu_restart(enum reboot_mode mode, const char *cmd)
{
	if (!system_controller_base) {
		pr_err("Cannot restart, system-controller not available: check the device tree\n");
	} else {
		/*
		 * Enable soft reset to assert RSTOUTn.
		 */
		writel(mvebu_sc->rstoutn_mask_reset_out_en,
			system_controller_base +
			mvebu_sc->rstoutn_mask_offset);
		/*
		 * Assert soft reset.
		 */
		writel(mvebu_sc->system_soft_reset,
			system_controller_base +
			mvebu_sc->system_soft_reset_offset);
	}

	while (1)
		;
}

int mvebu_system_controller_get_soc_id(u32 *dev, u32 *rev)
{
	if (of_machine_is_compatible("marvell,armada380") &&
		system_controller_base) {
		*dev = readl(system_controller_base + mvebu_sc->dev_id) >> 16;
		*rev = (readl(system_controller_base + mvebu_sc->rev_id) >> 8)
			& 0xF;
		return 0;
	} else
		return -ENODEV;
}

