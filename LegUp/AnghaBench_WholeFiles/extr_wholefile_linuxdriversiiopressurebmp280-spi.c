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
struct spi_device_id {int driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct regmap_config {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
#define  BME280_CHIP_ID 130 
#define  BMP180_CHIP_ID 129 
#define  BMP280_CHIP_ID 128 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 struct regmap_config bmp180_regmap_config ; 
 int bmp280_common_probe (int /*<<< orphan*/ *,struct regmap*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bmp280_common_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bmp280_regmap_bus ; 
 struct regmap_config bmp280_regmap_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct regmap* devm_regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regmap_config const*) ; 
 int /*<<< orphan*/  memcpy (int*,void const*,int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_write_then_read (struct spi_device*,void const*,size_t,void*,size_t) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int bmp280_regmap_spi_write(void *context, const void *data,
                                   size_t count)
{
	struct device *dev = context;
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[2];

	memcpy(buf, data, 2);
	/*
	 * The SPI register address (= full register address without bit 7) and
	 * the write command (bit7 = RW = '0')
	 */
	buf[0] &= ~0x80;

	return spi_write_then_read(spi, buf, 2, NULL, 0);
}

__attribute__((used)) static int bmp280_regmap_spi_read(void *context, const void *reg,
                                  size_t reg_size, void *val, size_t val_size)
{
	struct device *dev = context;
	struct spi_device *spi = to_spi_device(dev);

	return spi_write_then_read(spi, reg, reg_size, val, val_size);
}

__attribute__((used)) static int bmp280_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct regmap *regmap;
	const struct regmap_config *regmap_config;
	int ret;

	spi->bits_per_word = 8;
	ret = spi_setup(spi);
	if (ret < 0) {
		dev_err(&spi->dev, "spi_setup failed!\n");
		return ret;
	}

	switch (id->driver_data) {
	case BMP180_CHIP_ID:
		regmap_config = &bmp180_regmap_config;
		break;
	case BMP280_CHIP_ID:
	case BME280_CHIP_ID:
		regmap_config = &bmp280_regmap_config;
		break;
	default:
		return -EINVAL;
	}

	regmap = devm_regmap_init(&spi->dev,
				  &bmp280_regmap_bus,
				  &spi->dev,
				  regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&spi->dev, "failed to allocate register map\n");
		return PTR_ERR(regmap);
	}

	return bmp280_common_probe(&spi->dev,
				   regmap,
				   id->driver_data,
				   id->name,
				   spi->irq);
}

__attribute__((used)) static int bmp280_spi_remove(struct spi_device *spi)
{
	return bmp280_common_remove(&spi->dev);
}

