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
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct otm3225a_spi_instruction {unsigned char reg; int value; scalar_t__ delay; } ;
struct otm3225a_data {int power; struct lcd_device* ld; struct spi_device* spi; } ;
struct lcd_device {int dummy; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct otm3225a_spi_instruction*) ; 
 int ENOMEM ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 unsigned char OTM3225A_DATA_REG ; 
 unsigned char OTM3225A_INDEX_REG ; 
 int PTR_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct otm3225a_data*) ; 
 struct otm3225a_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (struct device*,int /*<<< orphan*/ ,struct device*,struct otm3225a_data*,int /*<<< orphan*/ *) ; 
 struct otm3225a_spi_instruction* display_enable_rgb_interface ; 
 struct otm3225a_spi_instruction* display_init ; 
 struct otm3225a_spi_instruction* display_off ; 
 struct otm3225a_spi_instruction* display_on ; 
 struct otm3225a_data* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  msleep (scalar_t__) ; 
 int /*<<< orphan*/  otm3225a_ops ; 
 int /*<<< orphan*/  spi_write (struct spi_device*,unsigned char*,int) ; 

__attribute__((used)) static void otm3225a_write(struct spi_device *spi,
			   struct otm3225a_spi_instruction *instruction,
			   unsigned int count)
{
	unsigned char buf[3];

	while (count--) {
		/* address register using index register */
		buf[0] = OTM3225A_INDEX_REG;
		buf[1] = 0x00;
		buf[2] = instruction->reg;
		spi_write(spi, buf, 3);

		/* write data to addressed register */
		buf[0] = OTM3225A_DATA_REG;
		buf[1] = (instruction->value >> 8) & 0xff;
		buf[2] = instruction->value & 0xff;
		spi_write(spi, buf, 3);

		/* execute delay if any */
		if (instruction->delay)
			msleep(instruction->delay);
		instruction++;
	}
}

__attribute__((used)) static int otm3225a_set_power(struct lcd_device *ld, int power)
{
	struct otm3225a_data *dd = lcd_get_data(ld);

	if (power == dd->power)
		return 0;

	if (power > FB_BLANK_UNBLANK)
		otm3225a_write(dd->spi, display_off, ARRAY_SIZE(display_off));
	else
		otm3225a_write(dd->spi, display_on, ARRAY_SIZE(display_on));
	dd->power = power;

	return 0;
}

__attribute__((used)) static int otm3225a_get_power(struct lcd_device *ld)
{
	struct otm3225a_data *dd = lcd_get_data(ld);

	return dd->power;
}

__attribute__((used)) static int otm3225a_probe(struct spi_device *spi)
{
	struct otm3225a_data *dd;
	struct lcd_device *ld;
	struct device *dev = &spi->dev;

	dd = devm_kzalloc(dev, sizeof(struct otm3225a_data), GFP_KERNEL);
	if (dd == NULL)
		return -ENOMEM;

	ld = devm_lcd_device_register(dev, dev_name(dev), dev, dd,
				      &otm3225a_ops);
	if (IS_ERR(ld))
		return PTR_ERR(ld);

	dd->spi = spi;
	dd->ld = ld;
	dev_set_drvdata(dev, dd);

	dev_info(dev, "Initializing and switching to RGB interface");
	otm3225a_write(spi, display_init, ARRAY_SIZE(display_init));
	otm3225a_write(spi, display_enable_rgb_interface,
		       ARRAY_SIZE(display_enable_rgb_interface));
	return 0;
}

