#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct pcf50633 {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct TYPE_6__ {TYPE_1__ dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__**) ; 
 int /*<<< orphan*/  GTA02_GPIO_AUX_LED ; 
 int /*<<< orphan*/  PCF50633_REG_OOCSHDWN ; 
 int /*<<< orphan*/  gpio_direction_output (int /*<<< orphan*/ ,char) ; 
 TYPE_2__** gta02_devices_pmu_children ; 
 struct pcf50633* gta02_pcf ; 
 int /*<<< orphan*/  pcf50633_reg_set_bit_mask (struct pcf50633*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  platform_add_devices (TYPE_2__**,int) ; 

__attribute__((used)) static long gta02_panic_blink(int state)
{
	long delay = 0;
	char led;

	led = (state) ? 1 : 0;
	gpio_direction_output(GTA02_GPIO_AUX_LED, led);

	return delay;
}

__attribute__((used)) static void gta02_pmu_attach_child_devices(struct pcf50633 *pcf)
{
	int n;

	/* Grab a copy of the now probed PMU pointer. */
	gta02_pcf = pcf;

	for (n = 0; n < ARRAY_SIZE(gta02_devices_pmu_children); n++)
		gta02_devices_pmu_children[n]->dev.parent = pcf->dev;

	platform_add_devices(gta02_devices_pmu_children,
			     ARRAY_SIZE(gta02_devices_pmu_children));
}

__attribute__((used)) static void gta02_poweroff(void)
{
	pcf50633_reg_set_bit_mask(gta02_pcf, PCF50633_REG_OOCSHDWN, 1, 1);
}

