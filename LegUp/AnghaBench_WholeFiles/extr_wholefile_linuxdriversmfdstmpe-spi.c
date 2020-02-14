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
typedef  int u16 ;
struct stmpe {TYPE_1__* variant; struct spi_device* client; } ;
struct spi_device_id {int /*<<< orphan*/  driver_data; } ;
struct spi_device {int bits_per_word; int mode; int max_speed_hz; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct TYPE_5__ {int /*<<< orphan*/ * dev; struct spi_device* client; int /*<<< orphan*/  irq; } ;
struct TYPE_4__ {int id_val; } ;

/* Variables and functions */
 int EINVAL ; 
 int READ_CMD ; 
 int STMPE811_REG_SPI_CFG ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 TYPE_2__ spi_ci ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct stmpe* spi_get_drvdata (struct spi_device*) ; 
 scalar_t__ spi_setup (struct spi_device*) ; 
 int spi_w8r16 (struct spi_device*,int) ; 
 int spi_write (struct spi_device*,int const*,int) ; 
 int stmpe_probe (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int stmpe_remove (struct stmpe*) ; 

__attribute__((used)) static inline void stmpe_dump_bytes(const char *str, const void *buf,
				    size_t len)
{
}

__attribute__((used)) static int spi_reg_read(struct stmpe *stmpe, u8 reg)
{
	struct spi_device *spi = stmpe->client;
	int status = spi_w8r16(spi, reg | READ_CMD);

	return (status < 0) ? status : status >> 8;
}

__attribute__((used)) static int spi_reg_write(struct stmpe *stmpe, u8 reg, u8 val)
{
	struct spi_device *spi = stmpe->client;
	u16 cmd = (val << 8) | reg;

	return spi_write(spi, (const u8 *)&cmd, 2);
}

__attribute__((used)) static int spi_block_read(struct stmpe *stmpe, u8 reg, u8 length, u8 *values)
{
	int ret, i;

	for (i = 0; i < length; i++) {
		ret = spi_reg_read(stmpe, reg + i);
		if (ret < 0)
			return ret;
		*(values + i) = ret;
	}

	return 0;
}

__attribute__((used)) static int spi_block_write(struct stmpe *stmpe, u8 reg, u8 length,
		const u8 *values)
{
	int ret = 0, i;

	for (i = length; i > 0; i--, reg++) {
		ret = spi_reg_write(stmpe, reg, *(values + i - 1));
		if (ret < 0)
			return ret;
	}

	return ret;
}

__attribute__((used)) static void spi_init(struct stmpe *stmpe)
{
	struct spi_device *spi = stmpe->client;

	spi->bits_per_word = 8;

	/* This register is only present for stmpe811 */
	if (stmpe->variant->id_val == 0x0811)
		spi_reg_write(stmpe, STMPE811_REG_SPI_CFG, spi->mode);

	if (spi_setup(spi) < 0)
		dev_dbg(&spi->dev, "spi_setup failed\n");
}

__attribute__((used)) static int
stmpe_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);

	/* don't exceed max specified rate - 1MHz - Limitation of STMPE */
	if (spi->max_speed_hz > 1000000) {
		dev_dbg(&spi->dev, "f(sample) %d KHz?\n",
				(spi->max_speed_hz/1000));
		return -EINVAL;
	}

	spi_ci.irq = spi->irq;
	spi_ci.client = spi;
	spi_ci.dev = &spi->dev;

	return stmpe_probe(&spi_ci, id->driver_data);
}

__attribute__((used)) static int stmpe_spi_remove(struct spi_device *spi)
{
	struct stmpe *stmpe = spi_get_drvdata(spi);

	return stmpe_remove(stmpe);
}

