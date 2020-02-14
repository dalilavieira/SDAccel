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
typedef  unsigned int u8 ;
struct max7301_platform_data {int input_pullup_active; int base; } ;
struct gpio_chip {int base; int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int can_sleep; int /*<<< orphan*/  owner; struct device* parent; int /*<<< orphan*/  ngpio; int /*<<< orphan*/  label; } ;
struct max7301 {unsigned int* port_config; int input_pullup_active; int (* write ) (struct device*,int,unsigned int) ;int out_level; int (* read ) (struct device*,int) ;int /*<<< orphan*/  lock; struct gpio_chip chip; struct device* dev; } ;
struct device {TYPE_1__* driver; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENODEV ; 
#define  PIN_CONFIG_IN_PULLUP 130 
#define  PIN_CONFIG_IN_WO_PULLUP 129 
 unsigned int PIN_CONFIG_MASK ; 
#define  PIN_CONFIG_OUT 128 
 int /*<<< orphan*/  PIN_NUMBER ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct max7301* dev_get_drvdata (struct device*) ; 
 struct max7301_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct max7301*) ; 
 int gpiochip_add_data (struct gpio_chip*,struct max7301*) ; 
 struct max7301* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (struct gpio_chip*) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct device*,int,unsigned int) ; 
 int stub2 (struct device*,int,int) ; 
 int stub3 (struct device*,int,int) ; 
 int stub4 (struct device*,int,unsigned int) ; 
 int stub5 (struct device*,int) ; 
 int stub6 (struct device*,int,int) ; 
 int stub7 (struct device*,int,int) ; 

__attribute__((used)) static int max7301_direction_input(struct gpio_chip *chip, unsigned offset)
{
	struct max7301 *ts = gpiochip_get_data(chip);
	u8 *config;
	u8 offset_bits, pin_config;
	int ret;

	/* First 4 pins are unused in the controller */
	offset += 4;
	offset_bits = (offset & 3) << 1;

	config = &ts->port_config[offset >> 2];

	if (ts->input_pullup_active & BIT(offset))
		pin_config = PIN_CONFIG_IN_PULLUP;
	else
		pin_config = PIN_CONFIG_IN_WO_PULLUP;

	mutex_lock(&ts->lock);

	*config = (*config & ~(PIN_CONFIG_MASK << offset_bits))
			   | (pin_config << offset_bits);

	ret = ts->write(ts->dev, 0x08 + (offset >> 2), *config);

	mutex_unlock(&ts->lock);

	return ret;
}

__attribute__((used)) static int __max7301_set(struct max7301 *ts, unsigned offset, int value)
{
	if (value) {
		ts->out_level |= 1 << offset;
		return ts->write(ts->dev, 0x20 + offset, 0x01);
	} else {
		ts->out_level &= ~(1 << offset);
		return ts->write(ts->dev, 0x20 + offset, 0x00);
	}
}

__attribute__((used)) static int max7301_direction_output(struct gpio_chip *chip, unsigned offset,
				    int value)
{
	struct max7301 *ts = gpiochip_get_data(chip);
	u8 *config;
	u8 offset_bits;
	int ret;

	/* First 4 pins are unused in the controller */
	offset += 4;
	offset_bits = (offset & 3) << 1;

	config = &ts->port_config[offset >> 2];

	mutex_lock(&ts->lock);

	*config = (*config & ~(PIN_CONFIG_MASK << offset_bits))
			   | (PIN_CONFIG_OUT << offset_bits);

	ret = __max7301_set(ts, offset, value);

	if (!ret)
		ret = ts->write(ts->dev, 0x08 + (offset >> 2), *config);

	mutex_unlock(&ts->lock);

	return ret;
}

__attribute__((used)) static int max7301_get(struct gpio_chip *chip, unsigned offset)
{
	struct max7301 *ts = gpiochip_get_data(chip);
	int config, level = -EINVAL;

	/* First 4 pins are unused in the controller */
	offset += 4;

	mutex_lock(&ts->lock);

	config = (ts->port_config[offset >> 2] >> ((offset & 3) << 1))
			& PIN_CONFIG_MASK;

	switch (config) {
	case PIN_CONFIG_OUT:
		/* Output: return cached level */
		level =  !!(ts->out_level & (1 << offset));
		break;
	case PIN_CONFIG_IN_WO_PULLUP:
	case PIN_CONFIG_IN_PULLUP:
		/* Input: read out */
		level = ts->read(ts->dev, 0x20 + offset) & 0x01;
	}
	mutex_unlock(&ts->lock);

	return level;
}

__attribute__((used)) static void max7301_set(struct gpio_chip *chip, unsigned offset, int value)
{
	struct max7301 *ts = gpiochip_get_data(chip);

	/* First 4 pins are unused in the controller */
	offset += 4;

	mutex_lock(&ts->lock);

	__max7301_set(ts, offset, value);

	mutex_unlock(&ts->lock);
}

int __max730x_probe(struct max7301 *ts)
{
	struct device *dev = ts->dev;
	struct max7301_platform_data *pdata;
	int i, ret;

	pdata = dev_get_platdata(dev);

	mutex_init(&ts->lock);
	dev_set_drvdata(dev, ts);

	/* Power up the chip and disable IRQ output */
	ts->write(dev, 0x04, 0x01);

	if (pdata) {
		ts->input_pullup_active = pdata->input_pullup_active;
		ts->chip.base = pdata->base;
	} else {
		ts->chip.base = -1;
	}
	ts->chip.label = dev->driver->name;

	ts->chip.direction_input = max7301_direction_input;
	ts->chip.get = max7301_get;
	ts->chip.direction_output = max7301_direction_output;
	ts->chip.set = max7301_set;

	ts->chip.ngpio = PIN_NUMBER;
	ts->chip.can_sleep = true;
	ts->chip.parent = dev;
	ts->chip.owner = THIS_MODULE;

	ret = gpiochip_add_data(&ts->chip, ts);
	if (ret)
		goto exit_destroy;

	/*
	 * initialize pullups according to platform data and cache the
	 * register values for later use.
	 */
	for (i = 1; i < 8; i++) {
		int j;
		/*
		 * initialize port_config with "0xAA", which means
		 * input with internal pullup disabled. This is needed
		 * to avoid writing zeros (in the inner for loop),
		 * which is not allowed according to the datasheet.
		 */
		ts->port_config[i] = 0xAA;
		for (j = 0; j < 4; j++) {
			int offset = (i - 1) * 4 + j;
			ret = max7301_direction_input(&ts->chip, offset);
			if (ret)
				goto exit_destroy;
		}
	}

	return ret;

exit_destroy:
	mutex_destroy(&ts->lock);
	return ret;
}

int __max730x_remove(struct device *dev)
{
	struct max7301 *ts = dev_get_drvdata(dev);

	if (ts == NULL)
		return -ENODEV;

	/* Power down the chip and disable IRQ output */
	ts->write(dev, 0x04, 0x00);
	gpiochip_remove(&ts->chip);
	mutex_destroy(&ts->lock);
	return 0;
}

