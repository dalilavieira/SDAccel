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
typedef  int /*<<< orphan*/  u8 ;
struct spi_device {int /*<<< orphan*/  modalias; int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ad7314_data {struct spi_device* spi_dev; int /*<<< orphan*/  rx; } ;
typedef  int ssize_t ;
typedef  int s16 ;
struct TYPE_2__ {int driver_data; } ;

/* Variables and functions */
 int AD7314_TEMP_MASK ; 
 int AD7314_TEMP_SHIFT ; 
 int ADT7301_TEMP_MASK ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
#define  ad7314 130 
 int /*<<< orphan*/  ad7314_groups ; 
#define  adt7301 129 
#define  adt7302 128 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct ad7314_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct ad7314_data*,int /*<<< orphan*/ ) ; 
 struct ad7314_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int sign_extend32 (int,int) ; 
 TYPE_1__* spi_get_device_id (struct spi_device*) ; 
 int spi_read (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 int sprintf (char*,char*,int) ; 

__attribute__((used)) static int ad7314_spi_read(struct ad7314_data *chip)
{
	int ret;

	ret = spi_read(chip->spi_dev, (u8 *)&chip->rx, sizeof(chip->rx));
	if (ret < 0) {
		dev_err(&chip->spi_dev->dev, "SPI read error\n");
		return ret;
	}

	return be16_to_cpu(chip->rx);
}

__attribute__((used)) static ssize_t ad7314_show_temperature(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct ad7314_data *chip = dev_get_drvdata(dev);
	s16 data;
	int ret;

	ret = ad7314_spi_read(chip);
	if (ret < 0)
		return ret;
	switch (spi_get_device_id(chip->spi_dev)->driver_data) {
	case ad7314:
		data = (ret & AD7314_TEMP_MASK) >> AD7314_TEMP_SHIFT;
		data = sign_extend32(data, 9);

		return sprintf(buf, "%d\n", 250 * data);
	case adt7301:
	case adt7302:
		/*
		 * Documented as a 13 bit twos complement register
		 * with a sign bit - which is a 14 bit 2's complement
		 * register.  1lsb - 31.25 milli degrees centigrade
		 */
		data = ret & ADT7301_TEMP_MASK;
		data = sign_extend32(data, 13);

		return sprintf(buf, "%d\n",
			       DIV_ROUND_CLOSEST(data * 3125, 100));
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int ad7314_probe(struct spi_device *spi_dev)
{
	struct ad7314_data *chip;
	struct device *hwmon_dev;

	chip = devm_kzalloc(&spi_dev->dev, sizeof(*chip), GFP_KERNEL);
	if (chip == NULL)
		return -ENOMEM;

	chip->spi_dev = spi_dev;
	hwmon_dev = devm_hwmon_device_register_with_groups(&spi_dev->dev,
							   spi_dev->modalias,
							   chip, ad7314_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

