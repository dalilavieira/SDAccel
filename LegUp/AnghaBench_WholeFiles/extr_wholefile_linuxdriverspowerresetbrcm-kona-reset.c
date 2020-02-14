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
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int NOTIFY_DONE ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ RSTMGR_REG_CHIP_SOFT_RST_OFFSET ; 
 scalar_t__ RSTMGR_REG_WR_ACCESS_OFFSET ; 
 int RSTMGR_WR_ACCESS_ENABLE ; 
 int RSTMGR_WR_PASSWORD ; 
 int RSTMGR_WR_PASSWORD_SHIFT ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 scalar_t__ kona_reset_base ; 
 int /*<<< orphan*/  kona_reset_nb ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int register_restart_handler (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int kona_reset_handler(struct notifier_block *this,
				unsigned long mode, void *cmd)
{
	/*
	 * A soft reset is triggered by writing a 0 to bit 0 of the soft reset
	 * register. To write to that register we must first write the password
	 * and the enable bit in the write access enable register.
	 */
	writel((RSTMGR_WR_PASSWORD << RSTMGR_WR_PASSWORD_SHIFT) |
		RSTMGR_WR_ACCESS_ENABLE,
		kona_reset_base + RSTMGR_REG_WR_ACCESS_OFFSET);
	writel(0, kona_reset_base + RSTMGR_REG_CHIP_SOFT_RST_OFFSET);

	return NOTIFY_DONE;
}

__attribute__((used)) static int kona_reset_probe(struct platform_device *pdev)
{
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	kona_reset_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(kona_reset_base))
		return PTR_ERR(kona_reset_base);

	return register_restart_handler(&kona_reset_nb);
}

