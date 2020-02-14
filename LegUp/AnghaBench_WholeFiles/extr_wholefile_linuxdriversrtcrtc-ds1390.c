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
typedef  unsigned char u8 ;
typedef  int u32 ;
struct device {scalar_t__ of_node; } ;
struct spi_device {int bits_per_word; struct device dev; int /*<<< orphan*/  mode; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct ds1390 {unsigned char* txrx_buf; int /*<<< orphan*/  rtc; } ;

/* Variables and functions */
 int DS1390_REG_SECONDS ; 
 unsigned char DS1390_REG_TRICKLE ; 
 unsigned char DS1390_TRICKLE_CHARGER_250_OHM ; 
 unsigned char DS1390_TRICKLE_CHARGER_2K_OHM ; 
 unsigned char DS1390_TRICKLE_CHARGER_4K_OHM ; 
 unsigned char DS1390_TRICKLE_CHARGER_DIODE ; 
 unsigned char DS1390_TRICKLE_CHARGER_ENABLE ; 
 unsigned char DS1390_TRICKLE_CHARGER_NO_DIODE ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ds1390* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 struct ds1390* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ds1390_rtc_ops ; 
 scalar_t__ of_property_read_bool (scalar_t__,char*) ; 
 scalar_t__ of_property_read_u32 (scalar_t__,char*,int*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ds1390*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int /*<<< orphan*/  spi_write (struct spi_device*,unsigned char*,int) ; 
 int spi_write_then_read (struct spi_device*,unsigned char*,int,unsigned char*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static void ds1390_set_reg(struct device *dev, unsigned char address,
			   unsigned char data)
{
	struct spi_device *spi = to_spi_device(dev);
	unsigned char buf[2];

	/* MSB must be '1' to write */
	buf[0] = address | 0x80;
	buf[1] = data;

	spi_write(spi, buf, 2);
}

__attribute__((used)) static int ds1390_get_reg(struct device *dev, unsigned char address,
				unsigned char *data)
{
	struct spi_device *spi = to_spi_device(dev);
	struct ds1390 *chip = dev_get_drvdata(dev);
	int status;

	if (!data)
		return -EINVAL;

	/* Clear MSB to indicate read */
	chip->txrx_buf[0] = address & 0x7f;
	/* do the i/o */
	status = spi_write_then_read(spi, chip->txrx_buf, 1, chip->txrx_buf, 1);
	if (status != 0)
		return status;

	*data = chip->txrx_buf[0];

	return 0;
}

__attribute__((used)) static void ds1390_trickle_of_init(struct spi_device *spi)
{
	u32 ohms = 0;
	u8 value;

	if (of_property_read_u32(spi->dev.of_node, "trickle-resistor-ohms",
				 &ohms))
		goto out;

	/* Enable charger */
	value = DS1390_TRICKLE_CHARGER_ENABLE;
	if (of_property_read_bool(spi->dev.of_node, "trickle-diode-disable"))
		value |= DS1390_TRICKLE_CHARGER_NO_DIODE;
	else
		value |= DS1390_TRICKLE_CHARGER_DIODE;

	/* Resistor select */
	switch (ohms) {
	case 250:
		value |= DS1390_TRICKLE_CHARGER_250_OHM;
		break;
	case 2000:
		value |= DS1390_TRICKLE_CHARGER_2K_OHM;
		break;
	case 4000:
		value |= DS1390_TRICKLE_CHARGER_4K_OHM;
		break;
	default:
		dev_warn(&spi->dev,
			 "Unsupported ohm value %02ux in dt\n", ohms);
		return;
	}

	ds1390_set_reg(&spi->dev, DS1390_REG_TRICKLE, value);

out:
	return;
}

__attribute__((used)) static int ds1390_read_time(struct device *dev, struct rtc_time *dt)
{
	struct spi_device *spi = to_spi_device(dev);
	struct ds1390 *chip = dev_get_drvdata(dev);
	int status;

	/* build the message */
	chip->txrx_buf[0] = DS1390_REG_SECONDS;

	/* do the i/o */
	status = spi_write_then_read(spi, chip->txrx_buf, 1, chip->txrx_buf, 8);
	if (status != 0)
		return status;

	/* The chip sends data in this order:
	 * Seconds, Minutes, Hours, Day, Date, Month / Century, Year */
	dt->tm_sec	= bcd2bin(chip->txrx_buf[0]);
	dt->tm_min	= bcd2bin(chip->txrx_buf[1]);
	dt->tm_hour	= bcd2bin(chip->txrx_buf[2]);
	dt->tm_wday	= bcd2bin(chip->txrx_buf[3]);
	dt->tm_mday	= bcd2bin(chip->txrx_buf[4]);
	/* mask off century bit */
	dt->tm_mon	= bcd2bin(chip->txrx_buf[5] & 0x7f) - 1;
	/* adjust for century bit */
	dt->tm_year = bcd2bin(chip->txrx_buf[6]) + ((chip->txrx_buf[5] & 0x80) ? 100 : 0);

	return 0;
}

__attribute__((used)) static int ds1390_set_time(struct device *dev, struct rtc_time *dt)
{
	struct spi_device *spi = to_spi_device(dev);
	struct ds1390 *chip = dev_get_drvdata(dev);

	/* build the message */
	chip->txrx_buf[0] = DS1390_REG_SECONDS | 0x80;
	chip->txrx_buf[1] = bin2bcd(dt->tm_sec);
	chip->txrx_buf[2] = bin2bcd(dt->tm_min);
	chip->txrx_buf[3] = bin2bcd(dt->tm_hour);
	chip->txrx_buf[4] = bin2bcd(dt->tm_wday);
	chip->txrx_buf[5] = bin2bcd(dt->tm_mday);
	chip->txrx_buf[6] = bin2bcd(dt->tm_mon + 1) |
				((dt->tm_year > 99) ? 0x80 : 0x00);
	chip->txrx_buf[7] = bin2bcd(dt->tm_year % 100);

	/* do the i/o */
	return spi_write_then_read(spi, chip->txrx_buf, 8, NULL, 0);
}

__attribute__((used)) static int ds1390_probe(struct spi_device *spi)
{
	unsigned char tmp;
	struct ds1390 *chip;
	int res;

	spi->mode = SPI_MODE_3;
	spi->bits_per_word = 8;
	spi_setup(spi);

	chip = devm_kzalloc(&spi->dev, sizeof(*chip), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	spi_set_drvdata(spi, chip);

	res = ds1390_get_reg(&spi->dev, DS1390_REG_SECONDS, &tmp);
	if (res != 0) {
		dev_err(&spi->dev, "unable to read device\n");
		return res;
	}

	if (spi->dev.of_node)
		ds1390_trickle_of_init(spi);

	chip->rtc = devm_rtc_device_register(&spi->dev, "ds1390",
					&ds1390_rtc_ops, THIS_MODULE);
	if (IS_ERR(chip->rtc)) {
		dev_err(&spi->dev, "unable to register device\n");
		res = PTR_ERR(chip->rtc);
	}

	return res;
}

