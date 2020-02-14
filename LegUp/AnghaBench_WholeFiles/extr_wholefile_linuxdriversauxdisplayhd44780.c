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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct hd44780 {void** pins; } ;
struct charlcd {int height; int width; int bwidth; int ifwidth; int /*<<< orphan*/ * ops; struct hd44780* drvdata; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 size_t PIN_CTRL_BL ; 
 size_t PIN_CTRL_E ; 
 size_t PIN_CTRL_RS ; 
 size_t PIN_CTRL_RW ; 
 unsigned int PIN_DATA0 ; 
 size_t PIN_DATA4 ; 
 int PTR_ERR (void*) ; 
 struct charlcd* charlcd_alloc (int) ; 
 int charlcd_register (struct charlcd*) ; 
 int /*<<< orphan*/  charlcd_unregister (struct charlcd*) ; 
 int device_property_read_u32 (struct device*,char*,int*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_gpiod_get_index (struct device*,char*,unsigned int,int /*<<< orphan*/ ) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 int gpiod_count (struct device*,char*) ; 
 int /*<<< orphan*/  gpiod_set_array_value_cansleep (unsigned int,void**,int*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  hd44780_ops_gpio4 ; 
 int /*<<< orphan*/  hd44780_ops_gpio8 ; 
 int /*<<< orphan*/  kfree (struct charlcd*) ; 
 struct charlcd* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct charlcd*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void hd44780_backlight(struct charlcd *lcd, int on)
{
	struct hd44780 *hd = lcd->drvdata;

	if (hd->pins[PIN_CTRL_BL])
		gpiod_set_value_cansleep(hd->pins[PIN_CTRL_BL], on);
}

__attribute__((used)) static void hd44780_strobe_gpio(struct hd44780 *hd)
{
	/* Maintain the data during 20 us before the strobe */
	udelay(20);

	gpiod_set_value_cansleep(hd->pins[PIN_CTRL_E], 1);

	/* Maintain the strobe during 40 us */
	udelay(40);

	gpiod_set_value_cansleep(hd->pins[PIN_CTRL_E], 0);
}

__attribute__((used)) static void hd44780_write_gpio8(struct hd44780 *hd, u8 val, unsigned int rs)
{
	int values[10];	/* for DATA[0-7], RS, RW */
	unsigned int i, n;

	for (i = 0; i < 8; i++)
		values[PIN_DATA0 + i] = !!(val & BIT(i));
	values[PIN_CTRL_RS] = rs;
	n = 9;
	if (hd->pins[PIN_CTRL_RW]) {
		values[PIN_CTRL_RW] = 0;
		n++;
	}

	/* Present the data to the port */
	gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA0], values);

	hd44780_strobe_gpio(hd);
}

__attribute__((used)) static void hd44780_write_gpio4(struct hd44780 *hd, u8 val, unsigned int rs)
{
	int values[10];	/* for DATA[0-7], RS, RW, but DATA[0-3] is unused */
	unsigned int i, n;

	/* High nibble + RS, RW */
	for (i = 4; i < 8; i++)
		values[PIN_DATA0 + i] = !!(val & BIT(i));
	values[PIN_CTRL_RS] = rs;
	n = 5;
	if (hd->pins[PIN_CTRL_RW]) {
		values[PIN_CTRL_RW] = 0;
		n++;
	}

	/* Present the data to the port */
	gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
				       &values[PIN_DATA4]);

	hd44780_strobe_gpio(hd);

	/* Low nibble */
	for (i = 0; i < 4; i++)
		values[PIN_DATA4 + i] = !!(val & BIT(i));

	/* Present the data to the port */
	gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
				       &values[PIN_DATA4]);

	hd44780_strobe_gpio(hd);
}

__attribute__((used)) static void hd44780_write_cmd_gpio8(struct charlcd *lcd, int cmd)
{
	struct hd44780 *hd = lcd->drvdata;

	hd44780_write_gpio8(hd, cmd, 0);

	/* The shortest command takes at least 120 us */
	udelay(120);
}

__attribute__((used)) static void hd44780_write_data_gpio8(struct charlcd *lcd, int data)
{
	struct hd44780 *hd = lcd->drvdata;

	hd44780_write_gpio8(hd, data, 1);

	/* The shortest data takes at least 45 us */
	udelay(45);
}

__attribute__((used)) static void hd44780_write_cmd_gpio4(struct charlcd *lcd, int cmd)
{
	struct hd44780 *hd = lcd->drvdata;

	hd44780_write_gpio4(hd, cmd, 0);

	/* The shortest command takes at least 120 us */
	udelay(120);
}

__attribute__((used)) static void hd44780_write_cmd_raw_gpio4(struct charlcd *lcd, int cmd)
{
	int values[10];	/* for DATA[0-7], RS, RW, but DATA[0-3] is unused */
	struct hd44780 *hd = lcd->drvdata;
	unsigned int i, n;

	/* Command nibble + RS, RW */
	for (i = 0; i < 4; i++)
		values[PIN_DATA4 + i] = !!(cmd & BIT(i));
	values[PIN_CTRL_RS] = 0;
	n = 5;
	if (hd->pins[PIN_CTRL_RW]) {
		values[PIN_CTRL_RW] = 0;
		n++;
	}

	/* Present the data to the port */
	gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
				       &values[PIN_DATA4]);

	hd44780_strobe_gpio(hd);
}

__attribute__((used)) static void hd44780_write_data_gpio4(struct charlcd *lcd, int data)
{
	struct hd44780 *hd = lcd->drvdata;

	hd44780_write_gpio4(hd, data, 1);

	/* The shortest data takes at least 45 us */
	udelay(45);
}

__attribute__((used)) static int hd44780_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	unsigned int i, base;
	struct charlcd *lcd;
	struct hd44780 *hd;
	int ifwidth, ret;

	/* Required pins */
	ifwidth = gpiod_count(dev, "data");
	if (ifwidth < 0)
		return ifwidth;

	switch (ifwidth) {
	case 4:
		base = PIN_DATA4;
		break;
	case 8:
		base = PIN_DATA0;
		break;
	default:
		return -EINVAL;
	}

	lcd = charlcd_alloc(sizeof(struct hd44780));
	if (!lcd)
		return -ENOMEM;

	hd = lcd->drvdata;

	for (i = 0; i < ifwidth; i++) {
		hd->pins[base + i] = devm_gpiod_get_index(dev, "data", i,
							  GPIOD_OUT_LOW);
		if (IS_ERR(hd->pins[base + i])) {
			ret = PTR_ERR(hd->pins[base + i]);
			goto fail;
		}
	}

	hd->pins[PIN_CTRL_E] = devm_gpiod_get(dev, "enable", GPIOD_OUT_LOW);
	if (IS_ERR(hd->pins[PIN_CTRL_E])) {
		ret = PTR_ERR(hd->pins[PIN_CTRL_E]);
		goto fail;
	}

	hd->pins[PIN_CTRL_RS] = devm_gpiod_get(dev, "rs", GPIOD_OUT_HIGH);
	if (IS_ERR(hd->pins[PIN_CTRL_RS])) {
		ret = PTR_ERR(hd->pins[PIN_CTRL_RS]);
		goto fail;
	}

	/* Optional pins */
	hd->pins[PIN_CTRL_RW] = devm_gpiod_get_optional(dev, "rw",
							GPIOD_OUT_LOW);
	if (IS_ERR(hd->pins[PIN_CTRL_RW])) {
		ret = PTR_ERR(hd->pins[PIN_CTRL_RW]);
		goto fail;
	}

	hd->pins[PIN_CTRL_BL] = devm_gpiod_get_optional(dev, "backlight",
							GPIOD_OUT_LOW);
	if (IS_ERR(hd->pins[PIN_CTRL_BL])) {
		ret = PTR_ERR(hd->pins[PIN_CTRL_BL]);
		goto fail;
	}

	/* Required properties */
	ret = device_property_read_u32(dev, "display-height-chars",
				       &lcd->height);
	if (ret)
		goto fail;
	ret = device_property_read_u32(dev, "display-width-chars", &lcd->width);
	if (ret)
		goto fail;

	/*
	 * On displays with more than two rows, the internal buffer width is
	 * usually equal to the display width
	 */
	if (lcd->height > 2)
		lcd->bwidth = lcd->width;

	/* Optional properties */
	device_property_read_u32(dev, "internal-buffer-width", &lcd->bwidth);

	lcd->ifwidth = ifwidth;
	lcd->ops = ifwidth == 8 ? &hd44780_ops_gpio8 : &hd44780_ops_gpio4;

	ret = charlcd_register(lcd);
	if (ret)
		goto fail;

	platform_set_drvdata(pdev, lcd);
	return 0;

fail:
	kfree(lcd);
	return ret;
}

__attribute__((used)) static int hd44780_remove(struct platform_device *pdev)
{
	struct charlcd *lcd = platform_get_drvdata(pdev);

	charlcd_unregister(lcd);

	kfree(lcd);
	return 0;
}

