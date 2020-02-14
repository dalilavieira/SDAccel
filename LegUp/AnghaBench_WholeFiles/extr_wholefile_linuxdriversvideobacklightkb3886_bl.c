#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct kb3886bl_machinfo {int limit_mask; int /*<<< orphan*/  default_intensity; int /*<<< orphan*/  max_intensity; int /*<<< orphan*/  (* set_bl_intensity ) (int) ;} ;
struct backlight_properties {int /*<<< orphan*/  max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_9__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; } ;
struct backlight_device {TYPE_1__ props; } ;
struct TYPE_10__ {int /*<<< orphan*/  brightness; scalar_t__ power; } ;
struct TYPE_11__ {TYPE_2__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 int KB3886BL_SUSPENDED ; 
 int KB3886_ADC_DAC_PWM ; 
 int /*<<< orphan*/  KB3886_IO ; 
 int /*<<< orphan*/  KB3886_PARENT ; 
 int KB3886_PWM0_WRITE ; 
 int PTR_ERR (TYPE_3__*) ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_3__*) ; 
 struct kb3886bl_machinfo* bl_machinfo ; 
 int /*<<< orphan*/  bl_mutex ; 
 struct kb3886bl_machinfo* dev_get_platdata (int /*<<< orphan*/ *) ; 
 TYPE_3__* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 TYPE_3__* kb3886_backlight_device ; 
 int kb3886bl_flags ; 
 int kb3886bl_intensity ; 
 int /*<<< orphan*/  kb3886bl_ops ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,TYPE_3__*) ; 
 int /*<<< orphan*/  stub1 (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void kb3886_bl_set_intensity(int intensity)
{
	mutex_lock(&bl_mutex);
	intensity = intensity&0xff;
	outb(KB3886_ADC_DAC_PWM, KB3886_PARENT);
	usleep_range(10000, 11000);
	outb(KB3886_PWM0_WRITE, KB3886_IO);
	usleep_range(10000, 11000);
	outb(intensity, KB3886_IO);
	mutex_unlock(&bl_mutex);
}

__attribute__((used)) static int kb3886bl_send_intensity(struct backlight_device *bd)
{
	int intensity = bd->props.brightness;

	if (bd->props.power != FB_BLANK_UNBLANK)
		intensity = 0;
	if (bd->props.fb_blank != FB_BLANK_UNBLANK)
		intensity = 0;
	if (kb3886bl_flags & KB3886BL_SUSPENDED)
		intensity = 0;

	bl_machinfo->set_bl_intensity(intensity);

	kb3886bl_intensity = intensity;
	return 0;
}

__attribute__((used)) static int kb3886bl_get_intensity(struct backlight_device *bd)
{
	return kb3886bl_intensity;
}

__attribute__((used)) static int kb3886bl_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	struct kb3886bl_machinfo *machinfo = dev_get_platdata(&pdev->dev);

	bl_machinfo = machinfo;
	if (!machinfo->limit_mask)
		machinfo->limit_mask = -1;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = machinfo->max_intensity;
	kb3886_backlight_device = devm_backlight_device_register(&pdev->dev,
							"kb3886-bl", &pdev->dev,
							NULL, &kb3886bl_ops,
							&props);
	if (IS_ERR(kb3886_backlight_device))
		return PTR_ERR(kb3886_backlight_device);

	platform_set_drvdata(pdev, kb3886_backlight_device);

	kb3886_backlight_device->props.power = FB_BLANK_UNBLANK;
	kb3886_backlight_device->props.brightness = machinfo->default_intensity;
	backlight_update_status(kb3886_backlight_device);

	return 0;
}

