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
struct platform_device {int dummy; } ;
struct lcd_panel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP_PWL_CLK_ENABLE ; 
 int /*<<< orphan*/  OMAP_PWL_ENABLE ; 
 int /*<<< orphan*/  PWL ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  omap_cfg_reg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omapfb_register_panel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  osk_panel ; 

__attribute__((used)) static int osk_panel_enable(struct lcd_panel *panel)
{
	/* configure PWL pin */
	omap_cfg_reg(PWL);

	/* Enable PWL unit */
	omap_writeb(0x01, OMAP_PWL_CLK_ENABLE);

	/* Set PWL level */
	omap_writeb(0xFF, OMAP_PWL_ENABLE);

	/* set GPIO2 high (lcd power enabled) */
	gpio_set_value(2, 1);

	return 0;
}

__attribute__((used)) static void osk_panel_disable(struct lcd_panel *panel)
{
	/* Set PWL level to zero */
	omap_writeb(0x00, OMAP_PWL_ENABLE);

	/* Disable PWL unit */
	omap_writeb(0x00, OMAP_PWL_CLK_ENABLE);

	/* set GPIO2 low */
	gpio_set_value(2, 0);
}

__attribute__((used)) static int osk_panel_probe(struct platform_device *pdev)
{
	omapfb_register_panel(&osk_panel);
	return 0;
}

