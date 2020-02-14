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
typedef  void* u8 ;
struct spi_transfer {int* rx_buf; int len; void** tx_buf; } ;
struct spi_device_id {int /*<<< orphan*/  name; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct mpl115_spi_buf {int* rx; void** tx; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* MPL115_SPI_READ (void*) ; 
 void* MPL115_SPI_WRITE (void*) ; 
 struct mpl115_spi_buf* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int mpl115_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpl115_spi_ops ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct mpl115_spi_buf* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct mpl115_spi_buf*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int mpl115_spi_init(struct device *dev)
{
	struct spi_device *spi = to_spi_device(dev);
	struct mpl115_spi_buf *buf;

	buf = devm_kzalloc(dev, sizeof(*buf), GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	spi_set_drvdata(spi, buf);

	return 0;
}

__attribute__((used)) static int mpl115_spi_read(struct device *dev, u8 address)
{
	struct spi_device *spi = to_spi_device(dev);
	struct mpl115_spi_buf *buf = spi_get_drvdata(spi);
	struct spi_transfer xfer = {
		.tx_buf = buf->tx,
		.rx_buf = buf->rx,
		.len = 4,
	};
	int ret;

	buf->tx[0] = MPL115_SPI_READ(address);
	buf->tx[2] = MPL115_SPI_READ(address + 1);

	ret = spi_sync_transfer(spi, &xfer, 1);
	if (ret)
		return ret;

	return (buf->rx[1] << 8) | buf->rx[3];
}

__attribute__((used)) static int mpl115_spi_write(struct device *dev, u8 address, u8 value)
{
	struct spi_device *spi = to_spi_device(dev);
	struct mpl115_spi_buf *buf = spi_get_drvdata(spi);
	struct spi_transfer xfer = {
		.tx_buf = buf->tx,
		.len = 2,
	};

	buf->tx[0] = MPL115_SPI_WRITE(address);
	buf->tx[1] = value;

	return spi_sync_transfer(spi, &xfer, 1);
}

__attribute__((used)) static int mpl115_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);

	return mpl115_probe(&spi->dev, id->name, &mpl115_spi_ops);
}

