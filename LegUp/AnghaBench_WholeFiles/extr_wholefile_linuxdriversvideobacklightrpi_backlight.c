#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct rpi_backlight {int /*<<< orphan*/  fw; TYPE_2__* dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct device_node {int dummy; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_7__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; int state; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  int /*<<< orphan*/  props ;
typedef  int /*<<< orphan*/  brightness ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 int EAGAIN ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  RPI_FIRMWARE_FRAMEBUFFER_SET_BACKLIGHT ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct rpi_backlight* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_2__*,int /*<<< orphan*/ ,TYPE_2__*,struct rpi_backlight*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct rpi_backlight* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct device_node* of_parse_phandle (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 
 int /*<<< orphan*/  rpi_backlight_ops ; 
 int /*<<< orphan*/  rpi_firmware_get (struct device_node*) ; 
 int rpi_firmware_property (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 

__attribute__((used)) static int rpi_backlight_update_status(struct backlight_device *bl)
{
	struct rpi_backlight *gbl = bl_get_data(bl);
	int brightness = bl->props.brightness;
	int ret;

	if (bl->props.power != FB_BLANK_UNBLANK ||
	    bl->props.fb_blank != FB_BLANK_UNBLANK ||
	    bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
		brightness = 0;

	ret = rpi_firmware_property(gbl->fw,
			RPI_FIRMWARE_FRAMEBUFFER_SET_BACKLIGHT,
			&brightness, sizeof(brightness));
	if (ret) {
		dev_err(gbl->dev, "Failed to set brightness\n");
		return ret;
	}

	if (brightness < 0) {
		dev_err(gbl->dev, "Backlight change failed\n");
		return -EAGAIN;
	}

	return 0;
}

__attribute__((used)) static int rpi_backlight_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	struct backlight_device *bl;
	struct rpi_backlight *gbl;
	struct device_node *fw_node;

	gbl = devm_kzalloc(&pdev->dev, sizeof(*gbl), GFP_KERNEL);
	if (gbl == NULL)
		return -ENOMEM;

	gbl->dev = &pdev->dev;

	fw_node = of_parse_phandle(pdev->dev.of_node, "firmware", 0);
	if (!fw_node) {
		dev_err(&pdev->dev, "Missing firmware node\n");
		return -ENOENT;
	}

	gbl->fw = rpi_firmware_get(fw_node);
	if (!gbl->fw)
		return -EPROBE_DEFER;

	memset(&props, 0, sizeof(props));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = 255;
	bl = devm_backlight_device_register(&pdev->dev, dev_name(&pdev->dev),
					&pdev->dev, gbl, &rpi_backlight_ops,
					&props);
	if (IS_ERR(bl)) {
		dev_err(&pdev->dev, "failed to register backlight\n");
		return PTR_ERR(bl);
	}

	bl->props.brightness = 255;
	backlight_update_status(bl);

	platform_set_drvdata(pdev, bl);
	return 0;
}

