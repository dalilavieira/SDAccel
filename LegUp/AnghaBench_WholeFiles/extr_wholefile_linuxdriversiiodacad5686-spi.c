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
typedef  int u8 ;
typedef  int u16 ;
struct spi_transfer {int* tx_buf; int len; int cs_change; int* rx_buf; } ;
struct spi_device_id {int /*<<< orphan*/  name; int /*<<< orphan*/  driver_data; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct ad5686_state {TYPE_2__* data; TYPE_1__* chip_info; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int* d8; void* d32; } ;
struct TYPE_3__ {int regmap_type; } ;

/* Variables and functions */
 int AD5683_DATA (int) ; 
#define  AD5683_REGMAP 129 
 int AD5686_ADDR (int) ; 
 int AD5686_CMD (int) ; 
 int AD5686_CMD_NOOP ; 
 int AD5686_CMD_READBACK_ENABLE ; 
 int AD5686_CMD_READBACK_ENABLE_V2 ; 
#define  AD5686_REGMAP 128 
 int /*<<< orphan*/  ARRAY_SIZE (struct spi_transfer*) ; 
 int EINVAL ; 
 int ad5686_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct ad5686_state*,int,int,int),int (*) (struct ad5686_state*,int)) ; 
 int ad5686_remove (int /*<<< orphan*/ *) ; 
 int be32_to_cpu (void*) ; 
 void* cpu_to_be32 (int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int /*<<< orphan*/ ) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 struct spi_device* to_spi_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ad5686_spi_write(struct ad5686_state *st,
			    u8 cmd, u8 addr, u16 val)
{
	struct spi_device *spi = to_spi_device(st->dev);
	u8 tx_len, *buf;

	switch (st->chip_info->regmap_type) {
	case AD5683_REGMAP:
		st->data[0].d32 = cpu_to_be32(AD5686_CMD(cmd) |
					      AD5683_DATA(val));
		buf = &st->data[0].d8[1];
		tx_len = 3;
		break;
	case AD5686_REGMAP:
		st->data[0].d32 = cpu_to_be32(AD5686_CMD(cmd) |
					      AD5686_ADDR(addr) |
					      val);
		buf = &st->data[0].d8[1];
		tx_len = 3;
		break;
	default:
		return -EINVAL;
	}

	return spi_write(spi, buf, tx_len);
}

__attribute__((used)) static int ad5686_spi_read(struct ad5686_state *st, u8 addr)
{
	struct spi_transfer t[] = {
		{
			.tx_buf = &st->data[0].d8[1],
			.len = 3,
			.cs_change = 1,
		}, {
			.tx_buf = &st->data[1].d8[1],
			.rx_buf = &st->data[2].d8[1],
			.len = 3,
		},
	};
	struct spi_device *spi = to_spi_device(st->dev);
	u8 cmd = 0;
	int ret;

	if (st->chip_info->regmap_type == AD5686_REGMAP)
		cmd = AD5686_CMD_READBACK_ENABLE;
	else if (st->chip_info->regmap_type == AD5683_REGMAP)
		cmd = AD5686_CMD_READBACK_ENABLE_V2;

	st->data[0].d32 = cpu_to_be32(AD5686_CMD(cmd) |
				      AD5686_ADDR(addr));
	st->data[1].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_NOOP));

	ret = spi_sync_transfer(spi, t, ARRAY_SIZE(t));
	if (ret < 0)
		return ret;

	return be32_to_cpu(st->data[2].d32);
}

__attribute__((used)) static int ad5686_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);

	return ad5686_probe(&spi->dev, id->driver_data, id->name,
			    ad5686_spi_write, ad5686_spi_read);
}

__attribute__((used)) static int ad5686_spi_remove(struct spi_device *spi)
{
	return ad5686_remove(&spi->dev);
}

