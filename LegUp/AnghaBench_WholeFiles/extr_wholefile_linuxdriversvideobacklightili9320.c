#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct lcd_device {int dummy; } ;
struct ili9320_spi {unsigned char* buffer_addr; unsigned char* buffer_data; unsigned char id; int /*<<< orphan*/  message; TYPE_2__* xfer; struct spi_device* dev; } ;
struct ili9320_reg {unsigned int address; unsigned int value; } ;
struct ili9320_platdata {scalar_t__ hsize; scalar_t__ vsize; int /*<<< orphan*/  (* reset ) (int) ;} ;
struct ili9320_client {int (* init ) (struct ili9320*,struct ili9320_platdata*) ;int /*<<< orphan*/  name; } ;
struct TYPE_3__ {struct ili9320_spi spi; } ;
struct ili9320 {int (* write ) (struct ili9320*,unsigned int,unsigned int) ;int initialised; int display1; unsigned int power; struct lcd_device* lcd; struct ili9320_platdata* platdata; struct ili9320_client* client; struct device* dev; TYPE_1__ access; } ;
struct TYPE_4__ {unsigned char* tx_buf; int len; int bits_per_word; int cs_change; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 void* FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int ILI9320_DISPLAY1 ; 
 int ILI9320_DISPLAY1_BASEE ; 
 int ILI9320_DISPLAY1_D (int) ; 
 unsigned char ILI9320_SPI_DATA ; 
 int ILI9320_SPI_ID (int) ; 
 int ILI9320_SPI_IDCODE ; 
 unsigned char ILI9320_SPI_INDEX ; 
 unsigned char ILI9320_SPI_WRITE ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ili9320_platdata* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 struct ili9320* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (struct device*,char*,struct device*,struct ili9320*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ili9320_ops ; 
 struct ili9320* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  spi_message_add_tail (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_message_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ili9320*) ; 
 int spi_sync (struct spi_device*,int /*<<< orphan*/ *) ; 
 int stub1 (struct ili9320*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  stub2 (int) ; 
 int /*<<< orphan*/  stub3 (int) ; 
 int /*<<< orphan*/  stub4 (int) ; 
 int stub5 (struct ili9320*,struct ili9320_platdata*) ; 

__attribute__((used)) static inline int ili9320_write_spi(struct ili9320 *ili,
				    unsigned int reg,
				    unsigned int value)
{
	struct ili9320_spi *spi = &ili->access.spi;
	unsigned char *addr = spi->buffer_addr;
	unsigned char *data = spi->buffer_data;

	/* spi message consits of:
	 * first byte: ID and operation
	 */

	addr[0] = spi->id | ILI9320_SPI_INDEX | ILI9320_SPI_WRITE;
	addr[1] = reg >> 8;
	addr[2] = reg;

	/* second message is the data to transfer */

	data[0] = spi->id | ILI9320_SPI_DATA  | ILI9320_SPI_WRITE;
	data[1] = value >> 8;
	data[2] = value;

	return spi_sync(spi->dev, &spi->message);
}

int ili9320_write(struct ili9320 *ili, unsigned int reg, unsigned int value)
{
	dev_dbg(ili->dev, "write: reg=%02x, val=%04x\n", reg, value);
	return ili->write(ili, reg, value);
}

int ili9320_write_regs(struct ili9320 *ili,
		       const struct ili9320_reg *values,
		       int nr_values)
{
	int index;
	int ret;

	for (index = 0; index < nr_values; index++, values++) {
		ret = ili9320_write(ili, values->address, values->value);
		if (ret != 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static void ili9320_reset(struct ili9320 *lcd)
{
	struct ili9320_platdata *cfg = lcd->platdata;

	cfg->reset(1);
	mdelay(50);

	cfg->reset(0);
	mdelay(50);

	cfg->reset(1);
	mdelay(100);
}

__attribute__((used)) static inline int ili9320_init_chip(struct ili9320 *lcd)
{
	int ret;

	ili9320_reset(lcd);

	ret = lcd->client->init(lcd, lcd->platdata);
	if (ret != 0) {
		dev_err(lcd->dev, "failed to initialise display\n");
		return ret;
	}

	lcd->initialised = 1;
	return 0;
}

__attribute__((used)) static inline int ili9320_power_on(struct ili9320 *lcd)
{
	if (!lcd->initialised)
		ili9320_init_chip(lcd);

	lcd->display1 |= (ILI9320_DISPLAY1_D(3) | ILI9320_DISPLAY1_BASEE);
	ili9320_write(lcd, ILI9320_DISPLAY1, lcd->display1);

	return 0;
}

__attribute__((used)) static inline int ili9320_power_off(struct ili9320 *lcd)
{
	lcd->display1 &= ~(ILI9320_DISPLAY1_D(3) | ILI9320_DISPLAY1_BASEE);
	ili9320_write(lcd, ILI9320_DISPLAY1, lcd->display1);

	return 0;
}

__attribute__((used)) static int ili9320_power(struct ili9320 *lcd, int power)
{
	int ret = 0;

	dev_dbg(lcd->dev, "power %d => %d\n", lcd->power, power);

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
		ret = ili9320_power_on(lcd);
	else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
		ret = ili9320_power_off(lcd);

	if (ret == 0)
		lcd->power = power;
	else
		dev_warn(lcd->dev, "failed to set power mode %d\n", power);

	return ret;
}

__attribute__((used)) static inline struct ili9320 *to_our_lcd(struct lcd_device *lcd)
{
	return lcd_get_data(lcd);
}

__attribute__((used)) static int ili9320_set_power(struct lcd_device *ld, int power)
{
	struct ili9320 *lcd = to_our_lcd(ld);

	return ili9320_power(lcd, power);
}

__attribute__((used)) static int ili9320_get_power(struct lcd_device *ld)
{
	struct ili9320 *lcd = to_our_lcd(ld);

	return lcd->power;
}

__attribute__((used)) static void ili9320_setup_spi(struct ili9320 *ili,
					struct spi_device *dev)
{
	struct ili9320_spi *spi = &ili->access.spi;

	ili->write = ili9320_write_spi;
	spi->dev = dev;

	/* fill the two messages we are going to use to send the data
	 * with, the first the address followed by the data. The datasheet
	 * says they should be done as two distinct cycles of the SPI CS line.
	 */

	spi->xfer[0].tx_buf = spi->buffer_addr;
	spi->xfer[1].tx_buf = spi->buffer_data;
	spi->xfer[0].len = 3;
	spi->xfer[1].len = 3;
	spi->xfer[0].bits_per_word = 8;
	spi->xfer[1].bits_per_word = 8;
	spi->xfer[0].cs_change = 1;

	spi_message_init(&spi->message);
	spi_message_add_tail(&spi->xfer[0], &spi->message);
	spi_message_add_tail(&spi->xfer[1], &spi->message);
}

int ili9320_probe_spi(struct spi_device *spi,
				struct ili9320_client *client)
{
	struct ili9320_platdata *cfg = dev_get_platdata(&spi->dev);
	struct device *dev = &spi->dev;
	struct ili9320 *ili;
	struct lcd_device *lcd;
	int ret = 0;

	/* verify we where given some information */

	if (cfg == NULL) {
		dev_err(dev, "no platform data supplied\n");
		return -EINVAL;
	}

	if (cfg->hsize <= 0 || cfg->vsize <= 0 || cfg->reset == NULL) {
		dev_err(dev, "invalid platform data supplied\n");
		return -EINVAL;
	}

	/* allocate and initialse our state */

	ili = devm_kzalloc(&spi->dev, sizeof(struct ili9320), GFP_KERNEL);
	if (ili == NULL)
		return -ENOMEM;

	ili->access.spi.id = ILI9320_SPI_IDCODE | ILI9320_SPI_ID(1);

	ili->dev = dev;
	ili->client = client;
	ili->power = FB_BLANK_POWERDOWN;
	ili->platdata = cfg;

	spi_set_drvdata(spi, ili);

	ili9320_setup_spi(ili, spi);

	lcd = devm_lcd_device_register(&spi->dev, "ili9320", dev, ili,
					&ili9320_ops);
	if (IS_ERR(lcd)) {
		dev_err(dev, "failed to register lcd device\n");
		return PTR_ERR(lcd);
	}

	ili->lcd = lcd;

	dev_info(dev, "initialising %s\n", client->name);

	ret = ili9320_power(ili, FB_BLANK_UNBLANK);
	if (ret != 0) {
		dev_err(dev, "failed to set lcd power state\n");
		return ret;
	}

	return 0;
}

int ili9320_remove(struct ili9320 *ili)
{
	ili9320_power(ili, FB_BLANK_POWERDOWN);
	return 0;
}

void ili9320_shutdown(struct ili9320 *lcd)
{
	ili9320_power(lcd, FB_BLANK_POWERDOWN);
}

