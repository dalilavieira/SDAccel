#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {struct device* parent; } ;
struct platform_device {TYPE_3__ dev; int /*<<< orphan*/  name; } ;
struct pcf50633_platform_data {struct pcf50633_bl_platform_data* backlight_data; } ;
struct pcf50633_bl_platform_data {int default_brightness; unsigned int default_brightness_limit; int ramp_time; } ;
struct pcf50633_bl {unsigned int brightness_limit; unsigned int brightness; TYPE_4__* bl; int /*<<< orphan*/  pcf; } ;
struct pcf50633 {int /*<<< orphan*/  bl_pdev; } ;
struct device {int dummy; } ;
struct backlight_properties {int max_brightness; int brightness; scalar_t__ power; int /*<<< orphan*/  type; } ;
struct TYPE_10__ {int state; scalar_t__ power; unsigned int brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  int /*<<< orphan*/  bl_props ;
struct TYPE_11__ {int brightness; } ;
struct TYPE_13__ {TYPE_2__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (TYPE_4__*) ; 
 int /*<<< orphan*/  PCF50633_REG_LEDDIM ; 
 int /*<<< orphan*/  PCF50633_REG_LEDENA ; 
 int /*<<< orphan*/  PCF50633_REG_LEDOUT ; 
 int PTR_ERR (TYPE_4__*) ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_4__*) ; 
 struct pcf50633_bl* bl_get_data (struct backlight_device*) ; 
 struct pcf50633_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_to_pcf50633 (struct device*) ; 
 TYPE_4__* devm_backlight_device_register (TYPE_3__*,int /*<<< orphan*/ ,TYPE_3__*,struct pcf50633_bl*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct pcf50633_bl* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pcf50633_bl_ops ; 
 int /*<<< orphan*/  pcf50633_reg_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct pcf50633_bl* platform_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pcf50633_bl*) ; 

int pcf50633_bl_set_brightness_limit(struct pcf50633 *pcf, unsigned int limit)
{
	struct pcf50633_bl *pcf_bl = platform_get_drvdata(pcf->bl_pdev);

	if (!pcf_bl)
		return -ENODEV;

	pcf_bl->brightness_limit = limit & 0x3f;
	backlight_update_status(pcf_bl->bl);

	return 0;
}

__attribute__((used)) static int pcf50633_bl_update_status(struct backlight_device *bl)
{
	struct pcf50633_bl *pcf_bl = bl_get_data(bl);
	unsigned int new_brightness;


	if (bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK) ||
		bl->props.power != FB_BLANK_UNBLANK)
		new_brightness = 0;
	else if (bl->props.brightness < pcf_bl->brightness_limit)
		new_brightness = bl->props.brightness;
	else
		new_brightness = pcf_bl->brightness_limit;


	if (pcf_bl->brightness == new_brightness)
		return 0;

	if (new_brightness) {
		pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDOUT,
					new_brightness);
		if (!pcf_bl->brightness)
			pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDENA, 1);
	} else {
		pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDENA, 0);
	}

	pcf_bl->brightness = new_brightness;

	return 0;
}

__attribute__((used)) static int pcf50633_bl_get_brightness(struct backlight_device *bl)
{
	struct pcf50633_bl *pcf_bl = bl_get_data(bl);

	return pcf_bl->brightness;
}

__attribute__((used)) static int pcf50633_bl_probe(struct platform_device *pdev)
{
	struct pcf50633_bl *pcf_bl;
	struct device *parent = pdev->dev.parent;
	struct pcf50633_platform_data *pcf50633_data = dev_get_platdata(parent);
	struct pcf50633_bl_platform_data *pdata = pcf50633_data->backlight_data;
	struct backlight_properties bl_props;

	pcf_bl = devm_kzalloc(&pdev->dev, sizeof(*pcf_bl), GFP_KERNEL);
	if (!pcf_bl)
		return -ENOMEM;

	memset(&bl_props, 0, sizeof(bl_props));
	bl_props.type = BACKLIGHT_RAW;
	bl_props.max_brightness = 0x3f;
	bl_props.power = FB_BLANK_UNBLANK;

	if (pdata) {
		bl_props.brightness = pdata->default_brightness;
		pcf_bl->brightness_limit = pdata->default_brightness_limit;
	} else {
		bl_props.brightness = 0x3f;
		pcf_bl->brightness_limit = 0x3f;
	}

	pcf_bl->pcf = dev_to_pcf50633(pdev->dev.parent);

	pcf_bl->bl = devm_backlight_device_register(&pdev->dev, pdev->name,
						&pdev->dev, pcf_bl,
						&pcf50633_bl_ops, &bl_props);

	if (IS_ERR(pcf_bl->bl))
		return PTR_ERR(pcf_bl->bl);

	platform_set_drvdata(pdev, pcf_bl);

	pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDDIM, pdata->ramp_time);

	/*
	 * Should be different from bl_props.brightness, so we do not exit
	 * update_status early the first time it's called
	 */
	pcf_bl->brightness = pcf_bl->bl->props.brightness + 1;

	backlight_update_status(pcf_bl->bl);

	return 0;
}

