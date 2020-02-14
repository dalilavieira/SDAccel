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
typedef  int u8 ;
typedef  int u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int brightness; int power; int fb_blank; scalar_t__ max_brightness; } ;
struct lcd_device {TYPE_1__ props; } ;
struct cr_panel {struct lcd_device* cr_lcd_device; struct lcd_device* cr_backlight_device; } ;
struct backlight_properties {int /*<<< orphan*/  type; } ;
struct backlight_device {TYPE_1__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int CRVML_BACKLIGHT_OFF ; 
 int /*<<< orphan*/  CRVML_DEVICE_LPC ; 
 int CRVML_GPIOEN_BIT ; 
 int CRVML_LVDS_ON ; 
 int CRVML_PANEL_ON ; 
 int CRVML_PANEL_PORT ; 
 int /*<<< orphan*/  CRVML_REG_GPIOBAR ; 
 int /*<<< orphan*/  CRVML_REG_GPIOEN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  PCI_VENDOR_ID_INTEL ; 
 int PTR_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  cr_backlight_ops ; 
 int /*<<< orphan*/  cr_lcd_ops ; 
 struct lcd_device* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct cr_panel* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int gpio_bar ; 
 int inl (int) ; 
 int /*<<< orphan*/  lpc_dev ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outl (int,int) ; 
 int /*<<< orphan*/  pci_dev_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_get_device (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_read_config_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_read_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct cr_panel* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cr_panel*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  schedule_timeout (int) ; 

__attribute__((used)) static int cr_backlight_set_intensity(struct backlight_device *bd)
{
	int intensity = bd->props.brightness;
	u32 addr = gpio_bar + CRVML_PANEL_PORT;
	u32 cur = inl(addr);

	if (bd->props.power == FB_BLANK_UNBLANK)
		intensity = FB_BLANK_UNBLANK;
	if (bd->props.fb_blank == FB_BLANK_UNBLANK)
		intensity = FB_BLANK_UNBLANK;
	if (bd->props.power == FB_BLANK_POWERDOWN)
		intensity = FB_BLANK_POWERDOWN;
	if (bd->props.fb_blank == FB_BLANK_POWERDOWN)
		intensity = FB_BLANK_POWERDOWN;

	if (intensity == FB_BLANK_UNBLANK) { /* FULL ON */
		cur &= ~CRVML_BACKLIGHT_OFF;
		outl(cur, addr);
	} else if (intensity == FB_BLANK_POWERDOWN) { /* OFF */
		cur |= CRVML_BACKLIGHT_OFF;
		outl(cur, addr);
	} /* anything else, don't bother */

	return 0;
}

__attribute__((used)) static int cr_backlight_get_intensity(struct backlight_device *bd)
{
	u32 addr = gpio_bar + CRVML_PANEL_PORT;
	u32 cur = inl(addr);
	u8 intensity;

	if (cur & CRVML_BACKLIGHT_OFF)
		intensity = FB_BLANK_POWERDOWN;
	else
		intensity = FB_BLANK_UNBLANK;

	return intensity;
}

__attribute__((used)) static void cr_panel_on(void)
{
	u32 addr = gpio_bar + CRVML_PANEL_PORT;
	u32 cur = inl(addr);

	if (!(cur & CRVML_PANEL_ON)) {
		/* Make sure LVDS controller is down. */
		if (cur & 0x00000001) {
			cur &= ~CRVML_LVDS_ON;
			outl(cur, addr);
		}
		/* Power up Panel */
		schedule_timeout(HZ / 10);
		cur |= CRVML_PANEL_ON;
		outl(cur, addr);
	}

	/* Power up LVDS controller */

	if (!(cur & CRVML_LVDS_ON)) {
		schedule_timeout(HZ / 10);
		outl(cur | CRVML_LVDS_ON, addr);
	}
}

__attribute__((used)) static void cr_panel_off(void)
{
	u32 addr = gpio_bar + CRVML_PANEL_PORT;
	u32 cur = inl(addr);

	/* Power down LVDS controller first to avoid high currents */
	if (cur & CRVML_LVDS_ON) {
		cur &= ~CRVML_LVDS_ON;
		outl(cur, addr);
	}
	if (cur & CRVML_PANEL_ON) {
		schedule_timeout(HZ / 10);
		outl(cur & ~CRVML_PANEL_ON, addr);
	}
}

__attribute__((used)) static int cr_lcd_set_power(struct lcd_device *ld, int power)
{
	if (power == FB_BLANK_UNBLANK)
		cr_panel_on();
	if (power == FB_BLANK_POWERDOWN)
		cr_panel_off();

	return 0;
}

__attribute__((used)) static int cr_backlight_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	struct backlight_device *bdp;
	struct lcd_device *ldp;
	struct cr_panel *crp;
	u8 dev_en;

	lpc_dev = pci_get_device(PCI_VENDOR_ID_INTEL,
					CRVML_DEVICE_LPC, NULL);
	if (!lpc_dev) {
		pr_err("INTEL CARILLO RANCH LPC not found.\n");
		return -ENODEV;
	}

	pci_read_config_byte(lpc_dev, CRVML_REG_GPIOEN, &dev_en);
	if (!(dev_en & CRVML_GPIOEN_BIT)) {
		pr_err("Carillo Ranch GPIO device was not enabled.\n");
		pci_dev_put(lpc_dev);
		return -ENODEV;
	}

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	bdp = devm_backlight_device_register(&pdev->dev, "cr-backlight",
					&pdev->dev, NULL, &cr_backlight_ops,
					&props);
	if (IS_ERR(bdp)) {
		pci_dev_put(lpc_dev);
		return PTR_ERR(bdp);
	}

	ldp = devm_lcd_device_register(&pdev->dev, "cr-lcd", &pdev->dev, NULL,
					&cr_lcd_ops);
	if (IS_ERR(ldp)) {
		pci_dev_put(lpc_dev);
		return PTR_ERR(ldp);
	}

	pci_read_config_dword(lpc_dev, CRVML_REG_GPIOBAR,
			      &gpio_bar);
	gpio_bar &= ~0x3F;

	crp = devm_kzalloc(&pdev->dev, sizeof(*crp), GFP_KERNEL);
	if (!crp) {
		pci_dev_put(lpc_dev);
		return -ENOMEM;
	}

	crp->cr_backlight_device = bdp;
	crp->cr_lcd_device = ldp;
	crp->cr_backlight_device->props.power = FB_BLANK_UNBLANK;
	crp->cr_backlight_device->props.brightness = 0;
	cr_backlight_set_intensity(crp->cr_backlight_device);
	cr_lcd_set_power(crp->cr_lcd_device, FB_BLANK_UNBLANK);

	platform_set_drvdata(pdev, crp);

	return 0;
}

__attribute__((used)) static int cr_backlight_remove(struct platform_device *pdev)
{
	struct cr_panel *crp = platform_get_drvdata(pdev);

	crp->cr_backlight_device->props.power = FB_BLANK_POWERDOWN;
	crp->cr_backlight_device->props.brightness = 0;
	crp->cr_backlight_device->props.max_brightness = 0;
	cr_backlight_set_intensity(crp->cr_backlight_device);
	cr_lcd_set_power(crp->cr_lcd_device, FB_BLANK_POWERDOWN);
	pci_dev_put(lpc_dev);

	return 0;
}

