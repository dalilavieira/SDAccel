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
 unsigned long OMAPFB_CAPS_SET_BACKLIGHT ; 
 int /*<<< orphan*/  omapfb_register_panel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  palmtt_panel ; 

__attribute__((used)) static unsigned long palmtt_panel_get_caps(struct lcd_panel *panel)
{
	return OMAPFB_CAPS_SET_BACKLIGHT;
}

__attribute__((used)) static int palmtt_panel_probe(struct platform_device *pdev)
{
	omapfb_register_panel(&palmtt_panel);
	return 0;
}

