#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct usb_phy {int /*<<< orphan*/  dev; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_control {int /*<<< orphan*/  (* phy_wkup ) (struct phy_control*,scalar_t__,int) ;int /*<<< orphan*/  (* phy_power ) (struct phy_control*,scalar_t__,int,int) ;} ;
struct TYPE_4__ {int (* init ) (struct usb_phy*) ;void (* shutdown ) (struct usb_phy*) ;} ;
struct TYPE_5__ {TYPE_1__ phy; } ;
struct am335x_phy {scalar_t__ id; int dr_mode; TYPE_2__ usb_phy_gen; struct phy_control* phy_ctrl; } ;
typedef  enum usb_dr_mode { ____Placeholder_usb_dr_mode } usb_dr_mode ;

/* Variables and functions */
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct phy_control* am335x_get_phy_control (struct device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,scalar_t__) ; 
 struct am335x_phy* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 int /*<<< orphan*/  device_set_wakeup_enable (struct device*,int) ; 
 struct am335x_phy* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ of_alias_get_id (int /*<<< orphan*/ ,char*) ; 
 int of_usb_get_dr_mode_by_phy (int /*<<< orphan*/ ,int) ; 
 struct am335x_phy* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct am335x_phy*) ; 
 int /*<<< orphan*/  stub1 (struct phy_control*,scalar_t__,int,int) ; 
 int /*<<< orphan*/  stub2 (struct phy_control*,scalar_t__,int) ; 
 int usb_add_phy_dev (TYPE_1__*) ; 
 int usb_phy_gen_create_phy (struct device*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_remove_phy (TYPE_1__*) ; 

__attribute__((used)) static inline void phy_ctrl_power(struct phy_control *phy_ctrl, u32 id,
				enum usb_dr_mode dr_mode, bool on)
{
	phy_ctrl->phy_power(phy_ctrl, id, dr_mode, on);
}

__attribute__((used)) static inline void phy_ctrl_wkup(struct phy_control *phy_ctrl, u32 id, bool on)
{
	phy_ctrl->phy_wkup(phy_ctrl, id, on);
}

__attribute__((used)) static int am335x_init(struct usb_phy *phy)
{
	struct am335x_phy *am_phy = dev_get_drvdata(phy->dev);

	phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, am_phy->dr_mode, true);
	return 0;
}

__attribute__((used)) static void am335x_shutdown(struct usb_phy *phy)
{
	struct am335x_phy *am_phy = dev_get_drvdata(phy->dev);

	phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, am_phy->dr_mode, false);
}

__attribute__((used)) static int am335x_phy_probe(struct platform_device *pdev)
{
	struct am335x_phy *am_phy;
	struct device *dev = &pdev->dev;
	int ret;

	am_phy = devm_kzalloc(dev, sizeof(*am_phy), GFP_KERNEL);
	if (!am_phy)
		return -ENOMEM;

	am_phy->phy_ctrl = am335x_get_phy_control(dev);
	if (!am_phy->phy_ctrl)
		return -EPROBE_DEFER;

	am_phy->id = of_alias_get_id(pdev->dev.of_node, "phy");
	if (am_phy->id < 0) {
		dev_err(&pdev->dev, "Missing PHY id: %d\n", am_phy->id);
		return am_phy->id;
	}

	am_phy->dr_mode = of_usb_get_dr_mode_by_phy(pdev->dev.of_node, -1);

	ret = usb_phy_gen_create_phy(dev, &am_phy->usb_phy_gen, NULL);
	if (ret)
		return ret;

	am_phy->usb_phy_gen.phy.init = am335x_init;
	am_phy->usb_phy_gen.phy.shutdown = am335x_shutdown;

	platform_set_drvdata(pdev, am_phy);
	device_init_wakeup(dev, true);

	/*
	 * If we leave PHY wakeup enabled then AM33XX wakes up
	 * immediately from DS0. To avoid this we mark dev->power.can_wakeup
	 * to false. The same is checked in suspend routine to decide
	 * on whether to enable PHY wakeup or not.
	 * PHY wakeup works fine in standby mode, there by allowing us to
	 * handle remote wakeup, wakeup on disconnect and connect.
	 */

	device_set_wakeup_enable(dev, false);
	phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, am_phy->dr_mode, false);

	return usb_add_phy_dev(&am_phy->usb_phy_gen.phy);
}

__attribute__((used)) static int am335x_phy_remove(struct platform_device *pdev)
{
	struct am335x_phy *am_phy = platform_get_drvdata(pdev);

	usb_remove_phy(&am_phy->usb_phy_gen.phy);
	return 0;
}

