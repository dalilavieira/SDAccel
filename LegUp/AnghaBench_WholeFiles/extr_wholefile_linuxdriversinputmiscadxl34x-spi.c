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
struct spi_device {scalar_t__ max_speed_hz; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct adxl34x {int dummy; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 unsigned char ADXL34X_READCMD (unsigned char) ; 
 unsigned char ADXL34X_READMB_CMD (unsigned char) ; 
 unsigned char ADXL34X_WRITECMD (unsigned char) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct adxl34x*) ; 
 scalar_t__ MAX_FREQ_NO_FIFODELAY ; 
 scalar_t__ MAX_SPI_FREQ_HZ ; 
 int PTR_ERR (struct adxl34x*) ; 
 struct adxl34x* adxl34x_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int adxl34x_remove (struct adxl34x*) ; 
 int /*<<< orphan*/  adxl34x_spi_bops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,scalar_t__) ; 
 struct adxl34x* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct adxl34x*) ; 
 int spi_w8r8 (struct spi_device*,unsigned char) ; 
 int spi_write (struct spi_device*,unsigned char*,int) ; 
 scalar_t__ spi_write_then_read (struct spi_device*,unsigned char*,int,void*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int adxl34x_spi_read(struct device *dev, unsigned char reg)
{
	struct spi_device *spi = to_spi_device(dev);
	unsigned char cmd;

	cmd = ADXL34X_READCMD(reg);

	return spi_w8r8(spi, cmd);
}

__attribute__((used)) static int adxl34x_spi_write(struct device *dev,
			     unsigned char reg, unsigned char val)
{
	struct spi_device *spi = to_spi_device(dev);
	unsigned char buf[2];

	buf[0] = ADXL34X_WRITECMD(reg);
	buf[1] = val;

	return spi_write(spi, buf, sizeof(buf));
}

__attribute__((used)) static int adxl34x_spi_read_block(struct device *dev,
				  unsigned char reg, int count,
				  void *buf)
{
	struct spi_device *spi = to_spi_device(dev);
	ssize_t status;

	reg = ADXL34X_READMB_CMD(reg);
	status = spi_write_then_read(spi, &reg, 1, buf, count);

	return (status < 0) ? status : 0;
}

__attribute__((used)) static int adxl34x_spi_probe(struct spi_device *spi)
{
	struct adxl34x *ac;

	/* don't exceed max specified SPI CLK frequency */
	if (spi->max_speed_hz > MAX_SPI_FREQ_HZ) {
		dev_err(&spi->dev, "SPI CLK %d Hz too fast\n", spi->max_speed_hz);
		return -EINVAL;
	}

	ac = adxl34x_probe(&spi->dev, spi->irq,
			   spi->max_speed_hz > MAX_FREQ_NO_FIFODELAY,
			   &adxl34x_spi_bops);

	if (IS_ERR(ac))
		return PTR_ERR(ac);

	spi_set_drvdata(spi, ac);

	return 0;
}

__attribute__((used)) static int adxl34x_spi_remove(struct spi_device *spi)
{
	struct adxl34x *ac = spi_get_drvdata(spi);

	return adxl34x_remove(ac);
}

