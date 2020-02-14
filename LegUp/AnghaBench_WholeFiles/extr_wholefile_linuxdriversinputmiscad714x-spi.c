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
typedef  int /*<<< orphan*/  xfer ;
typedef  int /*<<< orphan*/  u8 ;
struct spi_transfer {int len; void** rx_buf; void** tx_buf; } ;
struct spi_message {int dummy; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct ad714x_chip {int /*<<< orphan*/  dev; void** xfer_buf; } ;

/* Variables and functions */
 unsigned short AD714x_SPI_CMD_PREFIX ; 
 unsigned short AD714x_SPI_READ ; 
 int /*<<< orphan*/  BUS_SPI ; 
 scalar_t__ IS_ERR (struct ad714x_chip*) ; 
 int PTR_ERR (struct ad714x_chip*) ; 
 struct ad714x_chip* ad714x_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct ad714x_chip*,unsigned short,unsigned short*,size_t),int (*) (struct ad714x_chip*,unsigned short,unsigned short)) ; 
 unsigned short be16_to_cpu (void*) ; 
 void* cpu_to_be16 (unsigned short) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  memset (struct spi_transfer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ad714x_chip*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_write (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 struct spi_device* to_spi_device (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int ad714x_spi_read(struct ad714x_chip *chip,
			   unsigned short reg, unsigned short *data, size_t len)
{
	struct spi_device *spi = to_spi_device(chip->dev);
	struct spi_message message;
	struct spi_transfer xfer[2];
	int i;
	int error;

	spi_message_init(&message);
	memset(xfer, 0, sizeof(xfer));

	chip->xfer_buf[0] = cpu_to_be16(AD714x_SPI_CMD_PREFIX |
					AD714x_SPI_READ | reg);
	xfer[0].tx_buf = &chip->xfer_buf[0];
	xfer[0].len = sizeof(chip->xfer_buf[0]);
	spi_message_add_tail(&xfer[0], &message);

	xfer[1].rx_buf = &chip->xfer_buf[1];
	xfer[1].len = sizeof(chip->xfer_buf[1]) * len;
	spi_message_add_tail(&xfer[1], &message);

	error = spi_sync(spi, &message);
	if (unlikely(error)) {
		dev_err(chip->dev, "SPI read error: %d\n", error);
		return error;
	}

	for (i = 0; i < len; i++)
		data[i] = be16_to_cpu(chip->xfer_buf[i + 1]);

	return 0;
}

__attribute__((used)) static int ad714x_spi_write(struct ad714x_chip *chip,
			    unsigned short reg, unsigned short data)
{
	struct spi_device *spi = to_spi_device(chip->dev);
	int error;

	chip->xfer_buf[0] = cpu_to_be16(AD714x_SPI_CMD_PREFIX | reg);
	chip->xfer_buf[1] = cpu_to_be16(data);

	error = spi_write(spi, (u8 *)chip->xfer_buf,
			  2 * sizeof(*chip->xfer_buf));
	if (unlikely(error)) {
		dev_err(chip->dev, "SPI write error: %d\n", error);
		return error;
	}

	return 0;
}

__attribute__((used)) static int ad714x_spi_probe(struct spi_device *spi)
{
	struct ad714x_chip *chip;
	int err;

	spi->bits_per_word = 8;
	err = spi_setup(spi);
	if (err < 0)
		return err;

	chip = ad714x_probe(&spi->dev, BUS_SPI, spi->irq,
			    ad714x_spi_read, ad714x_spi_write);
	if (IS_ERR(chip))
		return PTR_ERR(chip);

	spi_set_drvdata(spi, chip);

	return 0;
}

