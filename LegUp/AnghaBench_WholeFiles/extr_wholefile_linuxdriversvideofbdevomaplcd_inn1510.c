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
 int /*<<< orphan*/  OMAP1510_FPGA_LCD_PANEL_CONTROL ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  innovator1510_panel ; 
 int /*<<< orphan*/  omapfb_register_panel (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int innovator1510_panel_enable(struct lcd_panel *panel)
{
	__raw_writeb(0x7, OMAP1510_FPGA_LCD_PANEL_CONTROL);
	return 0;
}

__attribute__((used)) static void innovator1510_panel_disable(struct lcd_panel *panel)
{
	__raw_writeb(0x0, OMAP1510_FPGA_LCD_PANEL_CONTROL);
}

__attribute__((used)) static int innovator1510_panel_probe(struct platform_device *pdev)
{
	omapfb_register_panel(&innovator1510_panel);
	return 0;
}

