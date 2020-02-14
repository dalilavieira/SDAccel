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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_device_id {struct dw_mci_drv_data* data; } ;
struct mmc_ios {int dummy; } ;
struct dw_mci_drv_data {int dummy; } ;
struct dw_mci {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLUEFIELD_UHS_REG_EXT_DRIVE ; 
 int /*<<< orphan*/  BLUEFIELD_UHS_REG_EXT_SAMPLE ; 
 int /*<<< orphan*/  FIELD_PREP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UHS_REG_EXT ; 
 int /*<<< orphan*/  UHS_REG_EXT_DRIVE_MASK ; 
 int /*<<< orphan*/  UHS_REG_EXT_SAMPLE_MASK ; 
 int /*<<< orphan*/  dw_mci_bluefield_match ; 
 int dw_mci_pltfm_register (struct platform_device*,struct dw_mci_drv_data const*) ; 
 int /*<<< orphan*/  mci_readl (struct dw_mci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mci_writel (struct dw_mci*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void dw_mci_bluefield_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
	u32 reg;

	/* Update the Drive and Sample fields in register UHS_REG_EXT. */
	reg = mci_readl(host, UHS_REG_EXT);
	reg &= ~UHS_REG_EXT_SAMPLE_MASK;
	reg |= FIELD_PREP(UHS_REG_EXT_SAMPLE_MASK,
			  BLUEFIELD_UHS_REG_EXT_SAMPLE);
	reg &= ~UHS_REG_EXT_DRIVE_MASK;
	reg |= FIELD_PREP(UHS_REG_EXT_DRIVE_MASK, BLUEFIELD_UHS_REG_EXT_DRIVE);
	mci_writel(host, UHS_REG_EXT, reg);
}

__attribute__((used)) static int dw_mci_bluefield_probe(struct platform_device *pdev)
{
	const struct dw_mci_drv_data *drv_data = NULL;
	const struct of_device_id *match;

	if (pdev->dev.of_node) {
		match = of_match_node(dw_mci_bluefield_match,
				      pdev->dev.of_node);
		drv_data = match->data;
	}

	return dw_mci_pltfm_register(pdev, drv_data);
}

