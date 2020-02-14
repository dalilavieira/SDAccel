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
struct resource {int dummy; } ;
struct TYPE_5__ {void* platform_data; } ;
struct TYPE_6__ {int num_resources; TYPE_1__ dev; struct resource* resource; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  DAVINCI_SYSTEM_MODULE_BASE ; 
 TYPE_2__ davinci_gpio_device ; 
 int /*<<< orphan*/  davinci_sysmod_base ; 
 TYPE_2__ davinci_wdt_device ; 
 int /*<<< orphan*/  ioremap_nocache (int /*<<< orphan*/ ,int) ; 
 int platform_device_register (TYPE_2__*) ; 

void davinci_map_sysmod(void)
{
	davinci_sysmod_base = ioremap_nocache(DAVINCI_SYSTEM_MODULE_BASE,
					      0x800);
	/*
	 * Throw a bug since a lot of board initialization code depends
	 * on system module availability. ioremap() failing this early
	 * need careful looking into anyway.
	 */
	BUG_ON(!davinci_sysmod_base);
}

int davinci_init_wdt(void)
{
	return platform_device_register(&davinci_wdt_device);
}

int davinci_gpio_register(struct resource *res, int size, void *pdata)
{
	davinci_gpio_device.resource = res;
	davinci_gpio_device.num_resources = size;
	davinci_gpio_device.dev.platform_data = pdata;
	return platform_device_register(&davinci_gpio_device);
}

