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
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {scalar_t__ platform_data; } ;
struct spi_device {TYPE_2__ dev; } ;
struct ksz_device {scalar_t__ pdata; struct spi_device* priv; int /*<<< orphan*/  reg_mutex; TYPE_1__* ops; } ;
struct TYPE_3__ {int (* read8 ) (struct ksz_device*,int,int*) ;int (* read16 ) (struct ksz_device*,int,int /*<<< orphan*/ *) ;int (* read24 ) (struct ksz_device*,int,int*) ;int (* read32 ) (struct ksz_device*,int,int*) ;int (* write8 ) (struct ksz_device*,int,int) ;int (* write16 ) (struct ksz_device*,int,int /*<<< orphan*/ ) ;int (* write24 ) (struct ksz_device*,int,int) ;int (* write32 ) (struct ksz_device*,int,int) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 int KS_SPIOP_RD ; 
 int KS_SPIOP_WR ; 
 int PORT_CTRL_ADDR (int,int) ; 
 int SPI_ADDR_MASK ; 
 int SPI_ADDR_SHIFT ; 
 int SPI_TURNAROUND_SHIFT ; 
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int) ; 
 int /*<<< orphan*/  cpu_to_be16 (int /*<<< orphan*/ ) ; 
 int cpu_to_be32 (int) ; 
 int /*<<< orphan*/  ksz_spi_ops ; 
 struct ksz_device* ksz_switch_alloc (TYPE_2__*,int /*<<< orphan*/ *,struct spi_device*) ; 
 int ksz_switch_register (struct ksz_device*) ; 
 int /*<<< orphan*/  ksz_switch_remove (struct ksz_device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ksz_device* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ksz_device*) ; 
 int spi_write (struct spi_device*,int**,int) ; 
 int spi_write_then_read (struct spi_device*,int*,int,int*,unsigned int) ; 
 int stub1 (struct ksz_device*,int,int*) ; 
 int stub2 (struct ksz_device*,int,int /*<<< orphan*/ *) ; 
 int stub3 (struct ksz_device*,int,int*) ; 
 int stub4 (struct ksz_device*,int,int*) ; 
 int stub5 (struct ksz_device*,int,int) ; 
 int stub6 (struct ksz_device*,int,int /*<<< orphan*/ ) ; 
 int stub7 (struct ksz_device*,int,int) ; 
 int stub8 (struct ksz_device*,int,int) ; 

__attribute__((used)) static inline int ksz_read8(struct ksz_device *dev, u32 reg, u8 *val)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->read8(dev, reg, val);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_read16(struct ksz_device *dev, u32 reg, u16 *val)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->read16(dev, reg, val);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_read24(struct ksz_device *dev, u32 reg, u32 *val)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->read24(dev, reg, val);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_read32(struct ksz_device *dev, u32 reg, u32 *val)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->read32(dev, reg, val);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_write8(struct ksz_device *dev, u32 reg, u8 value)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->write8(dev, reg, value);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_write16(struct ksz_device *dev, u32 reg, u16 value)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->write16(dev, reg, value);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_write24(struct ksz_device *dev, u32 reg, u32 value)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->write24(dev, reg, value);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline int ksz_write32(struct ksz_device *dev, u32 reg, u32 value)
{
	int ret;

	mutex_lock(&dev->reg_mutex);
	ret = dev->ops->write32(dev, reg, value);
	mutex_unlock(&dev->reg_mutex);

	return ret;
}

__attribute__((used)) static inline void ksz_pread8(struct ksz_device *dev, int port, int offset,
			      u8 *data)
{
	ksz_read8(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static inline void ksz_pread16(struct ksz_device *dev, int port, int offset,
			       u16 *data)
{
	ksz_read16(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static inline void ksz_pread32(struct ksz_device *dev, int port, int offset,
			       u32 *data)
{
	ksz_read32(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static inline void ksz_pwrite8(struct ksz_device *dev, int port, int offset,
			       u8 data)
{
	ksz_write8(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static inline void ksz_pwrite16(struct ksz_device *dev, int port, int offset,
				u16 data)
{
	ksz_write16(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static inline void ksz_pwrite32(struct ksz_device *dev, int port, int offset,
				u32 data)
{
	ksz_write32(dev, PORT_CTRL_ADDR(port, offset), data);
}

__attribute__((used)) static int ksz_spi_read_reg(struct spi_device *spi, u32 reg, u8 *val,
			    unsigned int len)
{
	u32 txbuf;
	int ret;

	txbuf = reg & SPI_ADDR_MASK;
	txbuf |= KS_SPIOP_RD << SPI_ADDR_SHIFT;
	txbuf <<= SPI_TURNAROUND_SHIFT;
	txbuf = cpu_to_be32(txbuf);

	ret = spi_write_then_read(spi, &txbuf, 4, val, len);
	return ret;
}

__attribute__((used)) static int ksz_spi_read(struct ksz_device *dev, u32 reg, u8 *data,
			unsigned int len)
{
	struct spi_device *spi = dev->priv;

	return ksz_spi_read_reg(spi, reg, data, len);
}

__attribute__((used)) static int ksz_spi_read8(struct ksz_device *dev, u32 reg, u8 *val)
{
	return ksz_spi_read(dev, reg, val, 1);
}

__attribute__((used)) static int ksz_spi_read16(struct ksz_device *dev, u32 reg, u16 *val)
{
	int ret = ksz_spi_read(dev, reg, (u8 *)val, 2);

	if (!ret)
		*val = be16_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int ksz_spi_read24(struct ksz_device *dev, u32 reg, u32 *val)
{
	int ret;

	*val = 0;
	ret = ksz_spi_read(dev, reg, (u8 *)val, 3);
	if (!ret) {
		*val = be32_to_cpu(*val);
		/* convert to 24bit */
		*val >>= 8;
	}

	return ret;
}

__attribute__((used)) static int ksz_spi_read32(struct ksz_device *dev, u32 reg, u32 *val)
{
	int ret = ksz_spi_read(dev, reg, (u8 *)val, 4);

	if (!ret)
		*val = be32_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int ksz_spi_write_reg(struct spi_device *spi, u32 reg, u8 *val,
			     unsigned int len)
{
	u32 txbuf;
	u8 data[12];
	int i;

	txbuf = reg & SPI_ADDR_MASK;
	txbuf |= (KS_SPIOP_WR << SPI_ADDR_SHIFT);
	txbuf <<= SPI_TURNAROUND_SHIFT;
	txbuf = cpu_to_be32(txbuf);

	data[0] = txbuf & 0xFF;
	data[1] = (txbuf & 0xFF00) >> 8;
	data[2] = (txbuf & 0xFF0000) >> 16;
	data[3] = (txbuf & 0xFF000000) >> 24;
	for (i = 0; i < len; i++)
		data[i + 4] = val[i];

	return spi_write(spi, &data, 4 + len);
}

__attribute__((used)) static int ksz_spi_write8(struct ksz_device *dev, u32 reg, u8 value)
{
	struct spi_device *spi = dev->priv;

	return ksz_spi_write_reg(spi, reg, &value, 1);
}

__attribute__((used)) static int ksz_spi_write16(struct ksz_device *dev, u32 reg, u16 value)
{
	struct spi_device *spi = dev->priv;

	value = cpu_to_be16(value);
	return ksz_spi_write_reg(spi, reg, (u8 *)&value, 2);
}

__attribute__((used)) static int ksz_spi_write24(struct ksz_device *dev, u32 reg, u32 value)
{
	struct spi_device *spi = dev->priv;

	/* make it to big endian 24bit from MSB */
	value <<= 8;
	value = cpu_to_be32(value);
	return ksz_spi_write_reg(spi, reg, (u8 *)&value, 3);
}

__attribute__((used)) static int ksz_spi_write32(struct ksz_device *dev, u32 reg, u32 value)
{
	struct spi_device *spi = dev->priv;

	value = cpu_to_be32(value);
	return ksz_spi_write_reg(spi, reg, (u8 *)&value, 4);
}

__attribute__((used)) static int ksz_spi_probe(struct spi_device *spi)
{
	struct ksz_device *dev;
	int ret;

	dev = ksz_switch_alloc(&spi->dev, &ksz_spi_ops, spi);
	if (!dev)
		return -ENOMEM;

	if (spi->dev.platform_data)
		dev->pdata = spi->dev.platform_data;

	ret = ksz_switch_register(dev);
	if (ret)
		return ret;

	spi_set_drvdata(spi, dev);

	return 0;
}

__attribute__((used)) static int ksz_spi_remove(struct spi_device *spi)
{
	struct ksz_device *dev = spi_get_drvdata(spi);

	if (dev)
		ksz_switch_remove(dev);

	return 0;
}

