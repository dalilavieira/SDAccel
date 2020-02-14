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
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_wday; int tm_year; } ;
struct rtc_device {int dummy; } ;
struct regmap_config {int reg_bits; int val_bits; int read_flag_mask; int max_register; int /*<<< orphan*/ * wr_table; } ;
typedef  struct rtc_device regmap ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  config ;

/* Variables and functions */
 int /*<<< orphan*/  DS1347_CLOCK_BURST ; 
 int /*<<< orphan*/  DS1347_CONTROL_REG ; 
 int /*<<< orphan*/  DS1347_SECONDS_REG ; 
 int /*<<< orphan*/  DS1347_STATUS_REG ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int PTR_ERR (struct rtc_device*) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (unsigned char) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,unsigned int) ; 
 struct rtc_device* devm_regmap_init_spi (struct spi_device*,struct regmap_config*) ; 
 struct rtc_device* devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ds1347_access_table ; 
 int /*<<< orphan*/  ds1347_rtc_ops ; 
 int /*<<< orphan*/  memset (struct regmap_config*,int /*<<< orphan*/ ,int) ; 
 int regmap_bulk_read (struct rtc_device*,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_bulk_write (struct rtc_device*,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_read (struct rtc_device*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_write (struct rtc_device*,int /*<<< orphan*/ ,unsigned int) ; 
 struct rtc_device* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct rtc_device*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int ds1347_read_time(struct device *dev, struct rtc_time *dt)
{
	struct spi_device *spi = to_spi_device(dev);
	struct regmap *map;
	int err;
	unsigned char buf[8];

	map = spi_get_drvdata(spi);

	err = regmap_bulk_read(map, DS1347_CLOCK_BURST, buf, 8);
	if (err)
		return err;

	dt->tm_sec = bcd2bin(buf[0]);
	dt->tm_min = bcd2bin(buf[1]);
	dt->tm_hour = bcd2bin(buf[2] & 0x3F);
	dt->tm_mday = bcd2bin(buf[3]);
	dt->tm_mon = bcd2bin(buf[4]) - 1;
	dt->tm_wday = bcd2bin(buf[5]) - 1;
	dt->tm_year = bcd2bin(buf[6]) + 100;

	return 0;
}

__attribute__((used)) static int ds1347_set_time(struct device *dev, struct rtc_time *dt)
{
	struct spi_device *spi = to_spi_device(dev);
	struct regmap *map;
	unsigned char buf[8];

	map = spi_get_drvdata(spi);

	buf[0] = bin2bcd(dt->tm_sec);
	buf[1] = bin2bcd(dt->tm_min);
	buf[2] = (bin2bcd(dt->tm_hour) & 0x3F);
	buf[3] = bin2bcd(dt->tm_mday);
	buf[4] = bin2bcd(dt->tm_mon + 1);
	buf[5] = bin2bcd(dt->tm_wday + 1);

	/* year in linux is from 1900 i.e in range of 100
	in rtc it is from 00 to 99 */
	dt->tm_year = dt->tm_year % 100;

	buf[6] = bin2bcd(dt->tm_year);
	buf[7] = bin2bcd(0x00);

	/* write the rtc settings */
	return regmap_bulk_write(map, DS1347_CLOCK_BURST, buf, 8);
}

__attribute__((used)) static int ds1347_probe(struct spi_device *spi)
{
	struct rtc_device *rtc;
	struct regmap_config config;
	struct regmap *map;
	unsigned int data;
	int res;

	memset(&config, 0, sizeof(config));
	config.reg_bits = 8;
	config.val_bits = 8;
	config.read_flag_mask = 0x80;
	config.max_register = 0x3F;
	config.wr_table = &ds1347_access_table;

	/* spi setup with ds1347 in mode 3 and bits per word as 8 */
	spi->mode = SPI_MODE_3;
	spi->bits_per_word = 8;
	spi_setup(spi);

	map = devm_regmap_init_spi(spi, &config);

	if (IS_ERR(map)) {
		dev_err(&spi->dev, "ds1347 regmap init spi failed\n");
		return PTR_ERR(map);
	}

	spi_set_drvdata(spi, map);

	/* RTC Settings */
	res = regmap_read(map, DS1347_SECONDS_REG, &data);
	if (res)
		return res;

	/* Disable the write protect of rtc */
	regmap_read(map, DS1347_CONTROL_REG, &data);
	data = data & ~(1<<7);
	regmap_write(map, DS1347_CONTROL_REG, data);

	/* Enable the oscillator , disable the oscillator stop flag,
	 and glitch filter to reduce current consumption */
	regmap_read(map, DS1347_STATUS_REG, &data);
	data = data & 0x1B;
	regmap_write(map, DS1347_STATUS_REG, data);

	/* display the settings */
	regmap_read(map, DS1347_CONTROL_REG, &data);
	dev_info(&spi->dev, "DS1347 RTC CTRL Reg = 0x%02x\n", data);

	regmap_read(map, DS1347_STATUS_REG, &data);
	dev_info(&spi->dev, "DS1347 RTC Status Reg = 0x%02x\n", data);

	rtc = devm_rtc_device_register(&spi->dev, "ds1347",
				&ds1347_rtc_ops, THIS_MODULE);

	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	return 0;
}

