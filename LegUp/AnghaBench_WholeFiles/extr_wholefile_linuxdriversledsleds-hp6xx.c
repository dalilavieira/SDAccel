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
typedef  int u16 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct led_classdev {int dummy; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int /*<<< orphan*/  HD64461_GPBDR ; 
 int HD64461_GPBDR_LED_RED ; 
 int /*<<< orphan*/  PKDR ; 
 int PKDR_LED_GREEN ; 
 int devm_led_classdev_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hp6xx_green_led ; 
 int /*<<< orphan*/  hp6xx_red_led ; 
 int inb (int /*<<< orphan*/ ) ; 
 int inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outw (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hp6xxled_green_set(struct led_classdev *led_cdev,
			       enum led_brightness value)
{
	u8 v8;

	v8 = inb(PKDR);
	if (value)
		outb(v8 & (~PKDR_LED_GREEN), PKDR);
	else
		outb(v8 | PKDR_LED_GREEN, PKDR);
}

__attribute__((used)) static void hp6xxled_red_set(struct led_classdev *led_cdev,
			     enum led_brightness value)
{
	u16 v16;

	v16 = inw(HD64461_GPBDR);
	if (value)
		outw(v16 & (~HD64461_GPBDR_LED_RED), HD64461_GPBDR);
	else
		outw(v16 | HD64461_GPBDR_LED_RED, HD64461_GPBDR);
}

__attribute__((used)) static int hp6xxled_probe(struct platform_device *pdev)
{
	int ret;

	ret = devm_led_classdev_register(&pdev->dev, &hp6xx_red_led);
	if (ret < 0)
		return ret;

	return devm_led_classdev_register(&pdev->dev, &hp6xx_green_led);
}

