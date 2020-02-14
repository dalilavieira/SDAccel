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
typedef  int u32 ;
typedef  int u16 ;
struct spi_transfer {int* tx_buf; int bits_per_word; int len; int* rx_buf; } ;
struct spi_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct iio_dev {int dummy; } ;
struct device {int dummy; } ;
struct ade7854_state {int* tx; int* rx; int (* read_reg ) (struct device*,int,int*,int) ;int (* write_reg ) (struct device*,int,int,int) ;struct spi_device* spi; int /*<<< orphan*/  irq; int /*<<< orphan*/  buf_lock; } ;
typedef  int /*<<< orphan*/  __be32 ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int ADE7854_READ_REG ; 
 int ADE7854_WRITE_REG ; 
 int ARRAY_SIZE (struct spi_transfer*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ade7854_probe (struct iio_dev*,int /*<<< orphan*/ *) ; 
 int be16_to_cpup (int /*<<< orphan*/  const*) ; 
 int be32_to_cpup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct ade7854_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 

__attribute__((used)) static int ade7854_spi_write_reg(struct device *dev,
				 u16 reg_address,
				 u32 val,
				 int bits)
{
	int ret;
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ade7854_state *st = iio_priv(indio_dev);
	struct spi_transfer xfer = {
		.tx_buf = st->tx,
		.bits_per_word = 8,
		.len = 4,
	};

	mutex_lock(&st->buf_lock);
	st->tx[0] = ADE7854_WRITE_REG;
	st->tx[1] = (reg_address >> 8) & 0xFF;
	st->tx[2] = reg_address & 0xFF;
	switch (bits) {
	case 8:
		st->tx[3] = val & 0xFF;
		break;
	case 16:
		xfer.len = 5;
		st->tx[3] = (val >> 8) & 0xFF;
		st->tx[4] = val & 0xFF;
		break;
	case 24:
		xfer.len = 6;
		st->tx[3] = (val >> 16) & 0xFF;
		st->tx[4] = (val >> 8) & 0xFF;
		st->tx[5] = val & 0xFF;
		break;
	case 32:
		xfer.len = 7;
		st->tx[3] = (val >> 24) & 0xFF;
		st->tx[4] = (val >> 16) & 0xFF;
		st->tx[5] = (val >> 8) & 0xFF;
		st->tx[6] = val & 0xFF;
		break;
	default:
		ret = -EINVAL;
		goto unlock;
	}

	ret = spi_sync_transfer(st->spi, &xfer, 1);
unlock:
	mutex_unlock(&st->buf_lock);

	return ret;
}

__attribute__((used)) static int ade7854_spi_read_reg(struct device *dev,
				u16 reg_address,
				u32 *val,
				int bits)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ade7854_state *st = iio_priv(indio_dev);
	int ret;
	struct spi_transfer xfers[] = {
		{
			.tx_buf = st->tx,
			.bits_per_word = 8,
			.len = 3,
		}, {
			.rx_buf = st->rx,
			.bits_per_word = 8,
			.len = bits,
		}
	};

	mutex_lock(&st->buf_lock);

	st->tx[0] = ADE7854_READ_REG;
	st->tx[1] = (reg_address >> 8) & 0xFF;
	st->tx[2] = reg_address & 0xFF;

	ret = spi_sync_transfer(st->spi, xfers, ARRAY_SIZE(xfers));
	if (ret < 0) {
		dev_err(&st->spi->dev, "problem when reading register 0x%02X",
			reg_address);
		goto unlock;
	}

	switch (bits) {
	case 8:
		*val = st->rx[0];
		break;
	case 16:
		*val = be16_to_cpup((const __be16 *)st->rx);
		break;
	case 24:
		*val = (st->rx[0] << 16) | (st->rx[1] << 8) | st->rx[2];
		break;
	case 32:
		*val = be32_to_cpup((const __be32 *)st->rx);
		break;
	}

unlock:
	mutex_unlock(&st->buf_lock);
	return ret;
}

__attribute__((used)) static int ade7854_spi_probe(struct spi_device *spi)
{
	struct ade7854_state *st;
	struct iio_dev *indio_dev;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	st = iio_priv(indio_dev);
	spi_set_drvdata(spi, indio_dev);
	st->read_reg = ade7854_spi_read_reg;
	st->write_reg = ade7854_spi_write_reg;
	st->irq = spi->irq;
	st->spi = spi;

	return ade7854_probe(indio_dev, &spi->dev);
}

