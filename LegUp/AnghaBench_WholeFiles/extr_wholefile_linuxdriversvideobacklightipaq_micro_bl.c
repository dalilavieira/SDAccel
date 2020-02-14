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
struct TYPE_5__ {int /*<<< orphan*/ * parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct ipaq_micro_msg {int tx_len; int* tx_data; int /*<<< orphan*/  id; } ;
struct ipaq_micro {int dummy; } ;
struct TYPE_4__ {int brightness; scalar_t__ power; int state; } ;
struct backlight_device {TYPE_1__ props; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  MSG_BACKLIGHT ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct ipaq_micro* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_2__*,char*,TYPE_2__*,struct ipaq_micro*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ipaq_micro_tx_msg_sync (struct ipaq_micro*,struct ipaq_micro_msg*) ; 
 int /*<<< orphan*/  micro_bl_ops ; 
 int /*<<< orphan*/  micro_bl_props ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 

__attribute__((used)) static int micro_bl_update_status(struct backlight_device *bd)
{
	struct ipaq_micro *micro = dev_get_drvdata(&bd->dev);
	int intensity = bd->props.brightness;
	struct ipaq_micro_msg msg = {
		.id = MSG_BACKLIGHT,
		.tx_len = 3,
	};

	if (bd->props.power != FB_BLANK_UNBLANK)
		intensity = 0;
	if (bd->props.state & (BL_CORE_FBBLANK | BL_CORE_SUSPENDED))
		intensity = 0;

	/*
	 * Message format:
	 * Byte 0: backlight instance (usually 1)
	 * Byte 1: on/off
	 * Byte 2: intensity, 0-255
	 */
	msg.tx_data[0] = 0x01;
	msg.tx_data[1] = intensity > 0 ? 1 : 0;
	msg.tx_data[2] = intensity;
	return ipaq_micro_tx_msg_sync(micro, &msg);
}

__attribute__((used)) static int micro_backlight_probe(struct platform_device *pdev)
{
	struct backlight_device *bd;
	struct ipaq_micro *micro = dev_get_drvdata(pdev->dev.parent);

	bd = devm_backlight_device_register(&pdev->dev, "ipaq-micro-backlight",
					    &pdev->dev, micro, &micro_bl_ops,
					    &micro_bl_props);
	if (IS_ERR(bd))
		return PTR_ERR(bd);

	platform_set_drvdata(pdev, bd);
	backlight_update_status(bd);

	return 0;
}

