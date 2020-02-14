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
struct spi_device_id {int /*<<< orphan*/  name; int /*<<< orphan*/  driver_data; } ;
struct spi_device {int max_speed_hz; int bits_per_word; int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 int hmc5843_common_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int hmc5843_common_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hmc5843_spi_regmap_config ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_setup (struct spi_device*) ; 

__attribute__((used)) static int hmc5843_spi_probe(struct spi_device *spi)
{
	int ret;
	const struct spi_device_id *id = spi_get_device_id(spi);

	spi->mode = SPI_MODE_3;
	spi->max_speed_hz = 8000000;
	spi->bits_per_word = 8;
	ret = spi_setup(spi);
	if (ret)
		return ret;

	return hmc5843_common_probe(&spi->dev,
			devm_regmap_init_spi(spi, &hmc5843_spi_regmap_config),
			id->driver_data, id->name);
}

__attribute__((used)) static int hmc5843_spi_remove(struct spi_device *spi)
{
	return hmc5843_common_remove(&spi->dev);
}

