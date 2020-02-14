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
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; } ;
struct rtc_device {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned char*) ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int PTR_ERR (struct rtc_device*) ; 
 unsigned char R100CNT ; 
 unsigned char RDAYCNT ; 
 unsigned char RHRCNT ; 
 unsigned char RMINCNT ; 
 unsigned char RMONCNT ; 
 unsigned char RSECCNT ; 
 int RWKCNT ; 
 unsigned char RYRCNT ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (unsigned char) ; 
 unsigned char bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 struct rtc_device* devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct rtc_time*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r9701_rtc_ops ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct rtc_device*) ; 
 int spi_write (struct spi_device*,unsigned char*,int) ; 
 int spi_write_then_read (struct spi_device*,unsigned char*,int,unsigned char*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int write_reg(struct device *dev, int address, unsigned char data)
{
	struct spi_device *spi = to_spi_device(dev);
	unsigned char buf[2];

	buf[0] = address & 0x7f;
	buf[1] = data;

	return spi_write(spi, buf, ARRAY_SIZE(buf));
}

__attribute__((used)) static int read_regs(struct device *dev, unsigned char *regs, int no_regs)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 txbuf[1], rxbuf[1];
	int k, ret;

	ret = 0;

	for (k = 0; ret == 0 && k < no_regs; k++) {
		txbuf[0] = 0x80 | regs[k];
		ret = spi_write_then_read(spi, txbuf, 1, rxbuf, 1);
		regs[k] = rxbuf[0];
	}

	return ret;
}

__attribute__((used)) static int r9701_get_datetime(struct device *dev, struct rtc_time *dt)
{
	int ret;
	unsigned char buf[] = { RSECCNT, RMINCNT, RHRCNT,
				RDAYCNT, RMONCNT, RYRCNT };

	ret = read_regs(dev, buf, ARRAY_SIZE(buf));
	if (ret)
		return ret;

	memset(dt, 0, sizeof(*dt));

	dt->tm_sec = bcd2bin(buf[0]); /* RSECCNT */
	dt->tm_min = bcd2bin(buf[1]); /* RMINCNT */
	dt->tm_hour = bcd2bin(buf[2]); /* RHRCNT */

	dt->tm_mday = bcd2bin(buf[3]); /* RDAYCNT */
	dt->tm_mon = bcd2bin(buf[4]) - 1; /* RMONCNT */
	dt->tm_year = bcd2bin(buf[5]) + 100; /* RYRCNT */

	/* the rtc device may contain illegal values on power up
	 * according to the data sheet. make sure they are valid.
	 */

	return 0;
}

__attribute__((used)) static int r9701_set_datetime(struct device *dev, struct rtc_time *dt)
{
	int ret, year;

	year = dt->tm_year + 1900;
	if (year >= 2100 || year < 2000)
		return -EINVAL;

	ret = write_reg(dev, RHRCNT, bin2bcd(dt->tm_hour));
	ret = ret ? ret : write_reg(dev, RMINCNT, bin2bcd(dt->tm_min));
	ret = ret ? ret : write_reg(dev, RSECCNT, bin2bcd(dt->tm_sec));
	ret = ret ? ret : write_reg(dev, RDAYCNT, bin2bcd(dt->tm_mday));
	ret = ret ? ret : write_reg(dev, RMONCNT, bin2bcd(dt->tm_mon + 1));
	ret = ret ? ret : write_reg(dev, RYRCNT, bin2bcd(dt->tm_year - 100));
	ret = ret ? ret : write_reg(dev, RWKCNT, 1 << dt->tm_wday);

	return ret;
}

__attribute__((used)) static int r9701_probe(struct spi_device *spi)
{
	struct rtc_device *rtc;
	struct rtc_time dt;
	unsigned char tmp;
	int res;

	tmp = R100CNT;
	res = read_regs(&spi->dev, &tmp, 1);
	if (res || tmp != 0x20) {
		dev_err(&spi->dev, "cannot read RTC register\n");
		return -ENODEV;
	}

	/*
	 * The device seems to be present. Now check if the registers
	 * contain invalid values. If so, try to write a default date:
	 * 2000/1/1 00:00:00
	 */
	if (r9701_get_datetime(&spi->dev, &dt)) {
		dev_info(&spi->dev, "trying to repair invalid date/time\n");
		dt.tm_sec  = 0;
		dt.tm_min  = 0;
		dt.tm_hour = 0;
		dt.tm_mday = 1;
		dt.tm_mon  = 0;
		dt.tm_year = 100;

		if (r9701_set_datetime(&spi->dev, &dt) ||
				r9701_get_datetime(&spi->dev, &dt)) {
			dev_err(&spi->dev, "cannot repair RTC register\n");
			return -ENODEV;
		}
	}

	rtc = devm_rtc_device_register(&spi->dev, "r9701",
				&r9701_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	spi_set_drvdata(spi, rtc);

	return 0;
}

