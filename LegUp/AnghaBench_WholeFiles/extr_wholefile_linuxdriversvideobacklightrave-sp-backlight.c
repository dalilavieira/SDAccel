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
typedef  int u8 ;
struct rave_sp {int dummy; } ;
struct device {int /*<<< orphan*/ * parent; } ;
struct platform_device {int /*<<< orphan*/  name; struct device dev; } ;
struct backlight_properties {scalar_t__ power; int brightness; } ;
struct backlight_device {int /*<<< orphan*/  dev; struct backlight_properties props; } ;
typedef  int /*<<< orphan*/  cmd ;

/* Variables and functions */
 scalar_t__ FB_BLANK_UNBLANK ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int const RAVE_SP_BACKLIGHT_LCD_EN ; 
 int RAVE_SP_CMD_SET_BACKLIGHT ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct rave_sp* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct backlight_device* devm_backlight_device_register (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct rave_sp*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rave_sp_backlight_ops ; 
 int /*<<< orphan*/  rave_sp_backlight_props ; 
 int rave_sp_exec (struct rave_sp*,int*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rave_sp_backlight_update_status(struct backlight_device *bd)
{
	const struct backlight_properties *p = &bd->props;
	const u8 intensity =
		(p->power == FB_BLANK_UNBLANK) ? p->brightness : 0;
	struct rave_sp *sp = dev_get_drvdata(&bd->dev);
	u8 cmd[] = {
		[0] = RAVE_SP_CMD_SET_BACKLIGHT,
		[1] = 0,
		[2] = intensity ? RAVE_SP_BACKLIGHT_LCD_EN | intensity : 0,
		[3] = 0,
		[4] = 0,
	};

	return rave_sp_exec(sp, cmd, sizeof(cmd), NULL, 0);
}

__attribute__((used)) static int rave_sp_backlight_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct backlight_device *bd;

	bd = devm_backlight_device_register(dev, pdev->name, dev->parent,
					    dev_get_drvdata(dev->parent),
					    &rave_sp_backlight_ops,
					    &rave_sp_backlight_props);
	if (IS_ERR(bd))
		return PTR_ERR(bd);

	backlight_update_status(bd);

	return 0;
}

