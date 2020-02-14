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
struct fb_var_screeninfo {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irq_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_AND_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_BL_POWER ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_BL_POWER2 ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_CABLE_INSERTED ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_CABLE_TYPE ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_FLASH_VPP ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_LCD_POWER ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_NICD_CHARGE ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_TOPPOLY_POWER ; 
 int /*<<< orphan*/  GPIO104_MAGICIAN_LCD_VOFF_EN ; 
 int /*<<< orphan*/  GPIO105_MAGICIAN_LCD_VON_EN ; 
 int /*<<< orphan*/  GPIO106_MAGICIAN_LCD_DCDC_NRESET ; 
 int /*<<< orphan*/  GPIO75_MAGICIAN_SAMSUNG_POWER ; 
 int /*<<< orphan*/  IRQ_MAGICIAN_SD ; 
 int PDA_POWER_CHARGE_AC ; 
 int PDA_POWER_CHARGE_USB ; 
 int PXA2XX_UDC_CMD_CONNECT ; 
 int PXA2XX_UDC_CMD_DISCONNECT ; 
 int UP2OCR ; 
 int UP2OCR_DPPUBE ; 
 int UP2OCR_DPPUE ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,void*) ; 
 int gpio_direction_output (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int gpio_request_array (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  magician_bl_gpios ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,void*) ; 
 int system_rev ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void toppoly_lcd_power(int on, struct fb_var_screeninfo *si)
{
	pr_debug("Toppoly LCD power: %s\n", on ? "on" : "off");

	if (on) {
		gpio_set_value(EGPIO_MAGICIAN_TOPPOLY_POWER, 1);
		gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 1);
		udelay(2000);
		gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
		udelay(2000);
		/* FIXME: enable LCDC here */
		udelay(2000);
		gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 1);
		udelay(2000);
		gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 1);
	} else {
		msleep(15);
		gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 0);
		udelay(500);
		gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 0);
		udelay(1000);
		gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 0);
		gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 0);
	}
}

__attribute__((used)) static void samsung_lcd_power(int on, struct fb_var_screeninfo *si)
{
	pr_debug("Samsung LCD power: %s\n", on ? "on" : "off");

	if (on) {
		if (system_rev < 3)
			gpio_set_value(GPIO75_MAGICIAN_SAMSUNG_POWER, 1);
		else
			gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
		mdelay(6);
		gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 1);
		mdelay(6);	/* Avdd -> Voff >5ms */
		gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 1);
		mdelay(16);	/* Voff -> Von >(5+10)ms */
		gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 1);
	} else {
		gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 0);
		mdelay(16);
		gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 0);
		mdelay(6);
		gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 0);
		mdelay(6);
		if (system_rev < 3)
			gpio_set_value(GPIO75_MAGICIAN_SAMSUNG_POWER, 0);
		else
			gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 0);
	}
}

__attribute__((used)) static int magician_backlight_init(struct device *dev)
{
	return gpio_request_array(ARRAY_AND_SIZE(magician_bl_gpios));
}

__attribute__((used)) static int magician_backlight_notify(struct device *dev, int brightness)
{
	pr_debug("Brightness = %i\n", brightness);
	gpio_set_value(EGPIO_MAGICIAN_BL_POWER, brightness);
	if (brightness >= 200) {
		gpio_set_value(EGPIO_MAGICIAN_BL_POWER2, 1);
		return brightness - 72;
	} else {
		gpio_set_value(EGPIO_MAGICIAN_BL_POWER2, 0);
		return brightness;
	}
}

__attribute__((used)) static void magician_backlight_exit(struct device *dev)
{
	gpio_free_array(ARRAY_AND_SIZE(magician_bl_gpios));
}

__attribute__((used)) static void magician_udc_command(int cmd)
{
	if (cmd == PXA2XX_UDC_CMD_CONNECT)
		UP2OCR |= UP2OCR_DPPUE | UP2OCR_DPPUBE;
	else if (cmd == PXA2XX_UDC_CMD_DISCONNECT)
		UP2OCR &= ~(UP2OCR_DPPUE | UP2OCR_DPPUBE);
}

__attribute__((used)) static int magician_supply_init(struct device *dev)
{
	int ret = -1;

	ret = gpio_request(EGPIO_MAGICIAN_CABLE_TYPE, "Cable is AC charger");
	if (ret) {
		pr_err("Cannot request AC/USB charger GPIO (%i)\n", ret);
		goto err_ac;
	}

	ret = gpio_request(EGPIO_MAGICIAN_CABLE_INSERTED, "Cable inserted");
	if (ret) {
		pr_err("Cannot request cable detection GPIO (%i)\n", ret);
		goto err_usb;
	}

	return 0;

err_usb:
	gpio_free(EGPIO_MAGICIAN_CABLE_TYPE);
err_ac:
	return ret;
}

__attribute__((used)) static void magician_set_charge(int flags)
{
	if (flags & PDA_POWER_CHARGE_AC) {
		pr_debug("Charging from AC\n");
		gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 1);
	} else if (flags & PDA_POWER_CHARGE_USB) {
		pr_debug("Charging from USB\n");
		gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 1);
	} else {
		pr_debug("Charging disabled\n");
		gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 0);
	}
}

__attribute__((used)) static int magician_is_ac_online(void)
{
	return gpio_get_value(EGPIO_MAGICIAN_CABLE_INSERTED) &&
		gpio_get_value(EGPIO_MAGICIAN_CABLE_TYPE); /* AC=1 */
}

__attribute__((used)) static int magician_is_usb_online(void)
{
	return gpio_get_value(EGPIO_MAGICIAN_CABLE_INSERTED) &&
		(!gpio_get_value(EGPIO_MAGICIAN_CABLE_TYPE)); /* USB=0 */
}

__attribute__((used)) static void magician_supply_exit(struct device *dev)
{
	gpio_free(EGPIO_MAGICIAN_CABLE_INSERTED);
	gpio_free(EGPIO_MAGICIAN_CABLE_TYPE);
}

__attribute__((used)) static int magician_mci_init(struct device *dev,
	irq_handler_t detect_irq, void *data)
{
	return request_irq(IRQ_MAGICIAN_SD, detect_irq, 0,
		"mmc card detect", data);
}

__attribute__((used)) static void magician_mci_exit(struct device *dev, void *data)
{
	free_irq(IRQ_MAGICIAN_SD, data);
}

__attribute__((used)) static int magician_flash_init(struct platform_device *pdev)
{
	int ret = gpio_request(EGPIO_MAGICIAN_FLASH_VPP, "flash Vpp enable");

	if (ret) {
		pr_err("Cannot request flash enable GPIO (%i)\n", ret);
		return ret;
	}

	ret = gpio_direction_output(EGPIO_MAGICIAN_FLASH_VPP, 1);
	if (ret) {
		pr_err("Cannot set direction for flash enable (%i)\n", ret);
		gpio_free(EGPIO_MAGICIAN_FLASH_VPP);
	}

	return ret;
}

__attribute__((used)) static void magician_set_vpp(struct platform_device *pdev, int vpp)
{
	gpio_set_value(EGPIO_MAGICIAN_FLASH_VPP, vpp);
}

__attribute__((used)) static void magician_flash_exit(struct platform_device *pdev)
{
	gpio_free(EGPIO_MAGICIAN_FLASH_VPP);
}

