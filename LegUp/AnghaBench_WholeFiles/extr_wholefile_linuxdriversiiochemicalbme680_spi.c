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
struct spi_device_id {int /*<<< orphan*/  name; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; } ;
struct regmap {int dummy; } ;
struct bme680_spi_bus_context {int current_page; struct spi_device* spi; } ;

/* Variables and functions */
 int BME680_REG_STATUS ; 
 int BME680_SPI_MEM_PAGE_BIT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int bme680_core_probe (int /*<<< orphan*/ *,struct regmap*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bme680_regmap_bus ; 
 int /*<<< orphan*/  bme680_regmap_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct bme680_spi_bus_context* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct bme680_spi_bus_context*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int*,void const*,int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int spi_write_then_read (struct spi_device*,int*,int,void*,size_t) ; 

__attribute__((used)) static int bme680_regmap_spi_select_page(
	struct bme680_spi_bus_context *ctx, u8 reg)
{
	struct spi_device *spi = ctx->spi;
	int ret;
	u8 buf[2];
	u8 page = (reg & 0x80) ? 0 : 1; /* Page "1" is low range */

	if (page == ctx->current_page)
		return 0;

	/*
	 * Data sheet claims we're only allowed to change bit 4, so we must do
	 * a read-modify-write on each and every page select
	 */
	buf[0] = BME680_REG_STATUS;
	ret = spi_write_then_read(spi, buf, 1, buf + 1, 1);
	if (ret < 0) {
		dev_err(&spi->dev, "failed to set page %u\n", page);
		return ret;
	}

	buf[0] = BME680_REG_STATUS;
	if (page)
		buf[1] |= BME680_SPI_MEM_PAGE_BIT;
	else
		buf[1] &= ~BME680_SPI_MEM_PAGE_BIT;

	ret = spi_write(spi, buf, 2);
	if (ret < 0) {
		dev_err(&spi->dev, "failed to set page %u\n", page);
		return ret;
	}

	ctx->current_page = page;

	return 0;
}

__attribute__((used)) static int bme680_regmap_spi_write(void *context, const void *data,
				   size_t count)
{
	struct bme680_spi_bus_context *ctx = context;
	struct spi_device *spi = ctx->spi;
	int ret;
	u8 buf[2];

	memcpy(buf, data, 2);

	ret = bme680_regmap_spi_select_page(ctx, buf[0]);
	if (ret)
		return ret;

	/*
	 * The SPI register address (= full register address without bit 7)
	 * and the write command (bit7 = RW = '0')
	 */
	buf[0] &= ~0x80;

	return spi_write(spi, buf, 2);
}

__attribute__((used)) static int bme680_regmap_spi_read(void *context, const void *reg,
				  size_t reg_size, void *val, size_t val_size)
{
	struct bme680_spi_bus_context *ctx = context;
	struct spi_device *spi = ctx->spi;
	int ret;
	u8 addr = *(const u8 *)reg;

	ret = bme680_regmap_spi_select_page(ctx, addr);
	if (ret)
		return ret;

	addr |= 0x80; /* bit7 = RW = '1' */

	return spi_write_then_read(spi, &addr, 1, val, val_size);
}

__attribute__((used)) static int bme680_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct bme680_spi_bus_context *bus_context;
	struct regmap *regmap;
	int ret;

	spi->bits_per_word = 8;
	ret = spi_setup(spi);
	if (ret < 0) {
		dev_err(&spi->dev, "spi_setup failed!\n");
		return ret;
	}

	bus_context = devm_kzalloc(&spi->dev, sizeof(*bus_context), GFP_KERNEL);
	if (!bus_context)
		return -ENOMEM;

	bus_context->spi = spi;
	bus_context->current_page = 0xff; /* Undefined on warm boot */

	regmap = devm_regmap_init(&spi->dev, &bme680_regmap_bus,
				  bus_context, &bme680_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&spi->dev, "Failed to register spi regmap %d\n",
				(int)PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	return bme680_core_probe(&spi->dev, regmap, id->name);
}

