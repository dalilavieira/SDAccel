#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct wm8350 {int /*<<< orphan*/  unlocked; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int readable; int writable; int vol; } ;

/* Variables and functions */
 unsigned int WM8350_BATTERY_CHARGER_CONTROL_1 ; 
 unsigned int WM8350_BATTERY_CHARGER_CONTROL_3 ; 
#define  WM8350_COMPARATOR_INT_STATUS 135 
 unsigned int WM8350_GPIO_FUNCTION_SELECT_1 ; 
 unsigned int WM8350_GPIO_FUNCTION_SELECT_4 ; 
#define  WM8350_GPIO_INT_STATUS 134 
#define  WM8350_INT_STATUS_1 133 
#define  WM8350_INT_STATUS_2 132 
#define  WM8350_OVER_CURRENT_INT_STATUS 131 
#define  WM8350_POWER_UP_INT_STATUS 130 
#define  WM8350_SYSTEM_INTERRUPTS 129 
#define  WM8350_UNDER_VOLTAGE_INT_STATUS 128 
 struct wm8350* dev_get_drvdata (struct device*) ; 
 TYPE_1__* wm8350_reg_io_map ; 

__attribute__((used)) static bool wm8350_readable(struct device *dev, unsigned int reg)
{
	return wm8350_reg_io_map[reg].readable;
}

__attribute__((used)) static bool wm8350_writeable(struct device *dev, unsigned int reg)
{
	struct wm8350 *wm8350 = dev_get_drvdata(dev);

	if (!wm8350->unlocked) {
		if ((reg >= WM8350_GPIO_FUNCTION_SELECT_1 &&
		     reg <= WM8350_GPIO_FUNCTION_SELECT_4) ||
		    (reg >= WM8350_BATTERY_CHARGER_CONTROL_1 &&
		     reg <= WM8350_BATTERY_CHARGER_CONTROL_3))
			return false;
	}

	return wm8350_reg_io_map[reg].writable;
}

__attribute__((used)) static bool wm8350_volatile(struct device *dev, unsigned int reg)
{
	return wm8350_reg_io_map[reg].vol;
}

__attribute__((used)) static bool wm8350_precious(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8350_SYSTEM_INTERRUPTS:
	case WM8350_INT_STATUS_1:
	case WM8350_INT_STATUS_2:
	case WM8350_POWER_UP_INT_STATUS:
	case WM8350_UNDER_VOLTAGE_INT_STATUS:
	case WM8350_OVER_CURRENT_INT_STATUS:
	case WM8350_GPIO_INT_STATUS:
	case WM8350_COMPARATOR_INT_STATUS:
		return true;

	default:
		return false;
	}
}

