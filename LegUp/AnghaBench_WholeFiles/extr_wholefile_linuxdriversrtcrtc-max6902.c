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
struct device {int dummy; } ;
struct spi_device {int bits_per_word; struct device dev; int /*<<< orphan*/  mode; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_wday; int tm_year; } ;
struct rtc_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 unsigned char MAX6902_REG_CENTURY ; 
 unsigned char MAX6902_REG_CONTROL ; 
 unsigned char MAX6902_REG_DATE ; 
 unsigned char MAX6902_REG_DAY ; 
 unsigned char MAX6902_REG_HOURS ; 
 unsigned char MAX6902_REG_MINUTES ; 
 unsigned char MAX6902_REG_MONTH ; 
 unsigned char MAX6902_REG_SECONDS ; 
 unsigned char MAX6902_REG_YEAR ; 
 int PTR_ERR (struct rtc_device*) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int bcd2bin (unsigned char) ; 
 unsigned char bin2bcd (int) ; 
 struct rtc_device* devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max6902_rtc_ops ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct rtc_device*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int spi_write_then_read (struct spi_device*,unsigned char*,int,unsigned char*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int max6902_set_reg(struct device *dev, unsigned char address,
				unsigned char data)
{
	struct spi_device *spi = to_spi_device(dev);
	unsigned char buf[2];

	/* MSB must be '0' to write */
	buf[0] = address & 0x7f;
	buf[1] = data;

	return spi_write_then_read(spi, buf, 2, NULL, 0);
}

__attribute__((used)) static int max6902_get_reg(struct device *dev, unsigned char address,
				unsigned char *data)
{
	struct spi_device *spi = to_spi_device(dev);

	/* Set MSB to indicate read */
	*data = address | 0x80;

	return spi_write_then_read(spi, data, 1, data, 1);
}

__attribute__((used)) static int max6902_read_time(struct device *dev, struct rtc_time *dt)
{
	int err, century;
	struct spi_device *spi = to_spi_device(dev);
	unsigned char buf[8];

	buf[0] = 0xbf;	/* Burst read */

	err = spi_write_then_read(spi, buf, 1, buf, 8);
	if (err != 0)
		return err;

	/* The chip sends data in this order:
	 * Seconds, Minutes, Hours, Date, Month, Day, Year */
	dt->tm_sec	= bcd2bin(buf[0]);
	dt->tm_min	= bcd2bin(buf[1]);
	dt->tm_hour	= bcd2bin(buf[2]);
	dt->tm_mday	= bcd2bin(buf[3]);
	dt->tm_mon	= bcd2bin(buf[4]) - 1;
	dt->tm_wday	= bcd2bin(buf[5]);
	dt->tm_year	= bcd2bin(buf[6]);

	/* Read century */
	err = max6902_get_reg(dev, MAX6902_REG_CENTURY, &buf[0]);
	if (err != 0)
		return err;

	century = bcd2bin(buf[0]) * 100;

	dt->tm_year += century;
	dt->tm_year -= 1900;

	return 0;
}

__attribute__((used)) static int max6902_set_time(struct device *dev, struct rtc_time *dt)
{
	dt->tm_year = dt->tm_year + 1900;

	/* Remove write protection */
	max6902_set_reg(dev, MAX6902_REG_CONTROL, 0);

	max6902_set_reg(dev, MAX6902_REG_SECONDS, bin2bcd(dt->tm_sec));
	max6902_set_reg(dev, MAX6902_REG_MINUTES, bin2bcd(dt->tm_min));
	max6902_set_reg(dev, MAX6902_REG_HOURS, bin2bcd(dt->tm_hour));

	max6902_set_reg(dev, MAX6902_REG_DATE, bin2bcd(dt->tm_mday));
	max6902_set_reg(dev, MAX6902_REG_MONTH, bin2bcd(dt->tm_mon + 1));
	max6902_set_reg(dev, MAX6902_REG_DAY, bin2bcd(dt->tm_wday));
	max6902_set_reg(dev, MAX6902_REG_YEAR, bin2bcd(dt->tm_year % 100));
	max6902_set_reg(dev, MAX6902_REG_CENTURY, bin2bcd(dt->tm_year / 100));

	/* Compulab used a delay here. However, the datasheet
	 * does not mention a delay being required anywhere... */
	/* delay(2000); */

	/* Write protect */
	max6902_set_reg(dev, MAX6902_REG_CONTROL, 0x80);

	return 0;
}

__attribute__((used)) static int max6902_probe(struct spi_device *spi)
{
	struct rtc_device *rtc;
	unsigned char tmp;
	int res;

	spi->mode = SPI_MODE_3;
	spi->bits_per_word = 8;
	spi_setup(spi);

	res = max6902_get_reg(&spi->dev, MAX6902_REG_SECONDS, &tmp);
	if (res != 0)
		return res;

	rtc = devm_rtc_device_register(&spi->dev, "max6902",
				&max6902_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	spi_set_drvdata(spi, rtc);
	return 0;
}

