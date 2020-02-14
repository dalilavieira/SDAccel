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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct spi_device {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int AD7310_COMMAND (int) ; 
 int ADT7310_CMD_READ ; 
 int /*<<< orphan*/  adt7310_spi_ops ; 
 int adt7x10_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int adt7x10_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_unaligned_be16 (int /*<<< orphan*/ ,int*) ; 
 TYPE_1__* spi_get_device_id (struct spi_device*) ; 
 int spi_w8r16be (struct spi_device*,int) ; 
 int spi_w8r8 (struct spi_device*,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int adt7310_spi_read_word(struct device *dev, u8 reg)
{
	struct spi_device *spi = to_spi_device(dev);

	return spi_w8r16be(spi, AD7310_COMMAND(reg) | ADT7310_CMD_READ);
}

__attribute__((used)) static int adt7310_spi_write_word(struct device *dev, u8 reg, u16 data)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[3];

	buf[0] = AD7310_COMMAND(reg);
	put_unaligned_be16(data, &buf[1]);

	return spi_write(spi, buf, sizeof(buf));
}

__attribute__((used)) static int adt7310_spi_read_byte(struct device *dev, u8 reg)
{
	struct spi_device *spi = to_spi_device(dev);

	return spi_w8r8(spi, AD7310_COMMAND(reg) | ADT7310_CMD_READ);
}

__attribute__((used)) static int adt7310_spi_write_byte(struct device *dev, u8 reg,
	u8 data)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[2];

	buf[0] = AD7310_COMMAND(reg);
	buf[1] = data;

	return spi_write(spi, buf, sizeof(buf));
}

__attribute__((used)) static int adt7310_spi_probe(struct spi_device *spi)
{
	return adt7x10_probe(&spi->dev, spi_get_device_id(spi)->name, spi->irq,
			&adt7310_spi_ops);
}

__attribute__((used)) static int adt7310_spi_remove(struct spi_device *spi)
{
	return adt7x10_remove(&spi->dev, spi->irq);
}

