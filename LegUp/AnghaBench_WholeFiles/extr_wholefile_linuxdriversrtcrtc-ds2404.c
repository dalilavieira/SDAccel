#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct rtc_time {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct ds2404_platform_data {int /*<<< orphan*/  gpio_dq; int /*<<< orphan*/  gpio_clk; int /*<<< orphan*/  gpio_rst; } ;
struct ds2404 {TYPE_1__* ops; int /*<<< orphan*/  rtc; TYPE_2__* gpio; } ;
struct TYPE_5__ {int /*<<< orphan*/  gpio; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int (* map_io ) (struct ds2404*,struct platform_device*,struct ds2404_platform_data*) ;int /*<<< orphan*/  (* unmap_io ) (struct ds2404*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 size_t DS2404_CLK ; 
 int DS2404_COPY_SCRATCHPAD_CMD ; 
 size_t DS2404_DQ ; 
 int DS2404_READ_MEMORY_CMD ; 
 int DS2404_READ_SCRATCHPAD_CMD ; 
 size_t DS2404_RST ; 
 int DS2404_WRITE_SCRATCHPAD_CMD ; 
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  cpu_to_le32 (unsigned long) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct ds2404_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ds2404* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__* ds2404_gpio ; 
 TYPE_1__ ds2404_gpio_ops ; 
 int /*<<< orphan*/  ds2404_rtc_ops ; 
 int /*<<< orphan*/  gpio_direction_input (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_direction_output (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 unsigned long le32_to_cpu (unsigned long) ; 
 struct ds2404* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ds2404*) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned long,struct rtc_time*) ; 
 int stub1 (struct ds2404*,struct platform_device*,struct ds2404_platform_data*) ; 
 int /*<<< orphan*/  stub2 (struct ds2404*) ; 
 int /*<<< orphan*/  stub3 (struct ds2404*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int ds2404_gpio_map(struct ds2404 *chip, struct platform_device *pdev,
			  struct ds2404_platform_data *pdata)
{
	int i, err;

	ds2404_gpio[DS2404_RST].gpio = pdata->gpio_rst;
	ds2404_gpio[DS2404_CLK].gpio = pdata->gpio_clk;
	ds2404_gpio[DS2404_DQ].gpio = pdata->gpio_dq;

	for (i = 0; i < ARRAY_SIZE(ds2404_gpio); i++) {
		err = gpio_request(ds2404_gpio[i].gpio, ds2404_gpio[i].name);
		if (err) {
			dev_err(&pdev->dev, "error mapping gpio %s: %d\n",
				ds2404_gpio[i].name, err);
			goto err_request;
		}
		if (i != DS2404_DQ)
			gpio_direction_output(ds2404_gpio[i].gpio, 1);
	}

	chip->gpio = ds2404_gpio;
	return 0;

err_request:
	while (--i >= 0)
		gpio_free(ds2404_gpio[i].gpio);
	return err;
}

__attribute__((used)) static void ds2404_gpio_unmap(struct ds2404 *chip)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(ds2404_gpio); i++)
		gpio_free(ds2404_gpio[i].gpio);
}

__attribute__((used)) static void ds2404_reset(struct device *dev)
{
	gpio_set_value(ds2404_gpio[DS2404_RST].gpio, 0);
	udelay(1000);
	gpio_set_value(ds2404_gpio[DS2404_RST].gpio, 1);
	gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
	gpio_direction_output(ds2404_gpio[DS2404_DQ].gpio, 0);
	udelay(10);
}

__attribute__((used)) static void ds2404_write_byte(struct device *dev, u8 byte)
{
	int i;

	gpio_direction_output(ds2404_gpio[DS2404_DQ].gpio, 1);
	for (i = 0; i < 8; i++) {
		gpio_set_value(ds2404_gpio[DS2404_DQ].gpio, byte & (1 << i));
		udelay(10);
		gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 1);
		udelay(10);
		gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
		udelay(10);
	}
}

__attribute__((used)) static u8 ds2404_read_byte(struct device *dev)
{
	int i;
	u8 ret = 0;

	gpio_direction_input(ds2404_gpio[DS2404_DQ].gpio);

	for (i = 0; i < 8; i++) {
		gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
		udelay(10);
		if (gpio_get_value(ds2404_gpio[DS2404_DQ].gpio))
			ret |= 1 << i;
		gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 1);
		udelay(10);
	}
	return ret;
}

__attribute__((used)) static void ds2404_read_memory(struct device *dev, u16 offset,
			       int length, u8 *out)
{
	ds2404_reset(dev);
	ds2404_write_byte(dev, DS2404_READ_MEMORY_CMD);
	ds2404_write_byte(dev, offset & 0xff);
	ds2404_write_byte(dev, (offset >> 8) & 0xff);
	while (length--)
		*out++ = ds2404_read_byte(dev);
}

__attribute__((used)) static void ds2404_write_memory(struct device *dev, u16 offset,
				int length, u8 *out)
{
	int i;
	u8 ta01, ta02, es;

	ds2404_reset(dev);
	ds2404_write_byte(dev, DS2404_WRITE_SCRATCHPAD_CMD);
	ds2404_write_byte(dev, offset & 0xff);
	ds2404_write_byte(dev, (offset >> 8) & 0xff);

	for (i = 0; i < length; i++)
		ds2404_write_byte(dev, out[i]);

	ds2404_reset(dev);
	ds2404_write_byte(dev, DS2404_READ_SCRATCHPAD_CMD);

	ta01 = ds2404_read_byte(dev);
	ta02 = ds2404_read_byte(dev);
	es = ds2404_read_byte(dev);

	for (i = 0; i < length; i++) {
		if (out[i] != ds2404_read_byte(dev)) {
			dev_err(dev, "read invalid data\n");
			return;
		}
	}

	ds2404_reset(dev);
	ds2404_write_byte(dev, DS2404_COPY_SCRATCHPAD_CMD);
	ds2404_write_byte(dev, ta01);
	ds2404_write_byte(dev, ta02);
	ds2404_write_byte(dev, es);

	gpio_direction_input(ds2404_gpio[DS2404_DQ].gpio);
	while (gpio_get_value(ds2404_gpio[DS2404_DQ].gpio))
		;
}

__attribute__((used)) static void ds2404_enable_osc(struct device *dev)
{
	u8 in[1] = { 0x10 }; /* enable oscillator */
	ds2404_write_memory(dev, 0x201, 1, in);
}

__attribute__((used)) static int ds2404_read_time(struct device *dev, struct rtc_time *dt)
{
	unsigned long time = 0;

	ds2404_read_memory(dev, 0x203, 4, (u8 *)&time);
	time = le32_to_cpu(time);

	rtc_time_to_tm(time, dt);
	return 0;
}

__attribute__((used)) static int ds2404_set_mmss(struct device *dev, unsigned long secs)
{
	u32 time = cpu_to_le32(secs);
	ds2404_write_memory(dev, 0x203, 4, (u8 *)&time);
	return 0;
}

__attribute__((used)) static int rtc_probe(struct platform_device *pdev)
{
	struct ds2404_platform_data *pdata = dev_get_platdata(&pdev->dev);
	struct ds2404 *chip;
	int retval = -EBUSY;

	chip = devm_kzalloc(&pdev->dev, sizeof(struct ds2404), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	chip->ops = &ds2404_gpio_ops;

	retval = chip->ops->map_io(chip, pdev, pdata);
	if (retval)
		goto err_chip;

	dev_info(&pdev->dev, "using GPIOs RST:%d, CLK:%d, DQ:%d\n",
		 chip->gpio[DS2404_RST].gpio, chip->gpio[DS2404_CLK].gpio,
		 chip->gpio[DS2404_DQ].gpio);

	platform_set_drvdata(pdev, chip);

	chip->rtc = devm_rtc_device_register(&pdev->dev, "ds2404",
					&ds2404_rtc_ops, THIS_MODULE);
	if (IS_ERR(chip->rtc)) {
		retval = PTR_ERR(chip->rtc);
		goto err_io;
	}

	ds2404_enable_osc(&pdev->dev);
	return 0;

err_io:
	chip->ops->unmap_io(chip);
err_chip:
	return retval;
}

__attribute__((used)) static int rtc_remove(struct platform_device *dev)
{
	struct ds2404 *chip = platform_get_drvdata(dev);

	chip->ops->unmap_io(chip);

	return 0;
}

