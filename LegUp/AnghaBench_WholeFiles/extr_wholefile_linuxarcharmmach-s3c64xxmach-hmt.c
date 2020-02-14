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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  S3C64XX_GPB (int) ; 
 int gpio_direction_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int hmt_bl_init(struct device *dev)
{
	int ret;

	ret = gpio_request(S3C64XX_GPB(4), "lcd backlight enable");
	if (!ret)
		ret = gpio_direction_output(S3C64XX_GPB(4), 0);

	return ret;
}

__attribute__((used)) static int hmt_bl_notify(struct device *dev, int brightness)
{
	/*
	 * translate from CIELUV/CIELAB L*->brightness, E.G. from
	 * perceived luminance to light output. Assumes range 0..25600
	 */
	if (brightness < 0x800) {
		/* Y = Yn * L / 903.3 */
		brightness = (100*256 * brightness + 231245/2) / 231245;
	} else {
		/* Y = Yn * ((L + 16) / 116 )^3 */
		int t = (brightness*4 + 16*1024 + 58)/116;
		brightness = 25 * ((t * t * t + 0x100000/2) / 0x100000);
	}

	gpio_set_value(S3C64XX_GPB(4), brightness);

	return brightness;
}

__attribute__((used)) static void hmt_bl_exit(struct device *dev)
{
	gpio_free(S3C64XX_GPB(4));
}

