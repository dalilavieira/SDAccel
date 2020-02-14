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
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; } ;
struct rtc_device {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {TYPE_1__ driver; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int M41T94_BIT_CB ; 
 int M41T94_BIT_CEB ; 
 int M41T94_BIT_HALT ; 
 int M41T94_BIT_STOP ; 
 size_t M41T94_REG_DAY ; 
 size_t M41T94_REG_HOURS ; 
 int M41T94_REG_HT ; 
 size_t M41T94_REG_MINUTES ; 
 size_t M41T94_REG_MONTH ; 
 int M41T94_REG_SECONDS ; 
 size_t M41T94_REG_WDAY ; 
 size_t M41T94_REG_YEAR ; 
 int PTR_ERR (struct rtc_device*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct rtc_device* devm_rtc_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__ m41t94_driver ; 
 int /*<<< orphan*/  m41t94_rtc_ops ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct rtc_device*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int spi_w8r8 (struct spi_device*,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int m41t94_set_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[8]; /* write cmd + 7 registers */

	dev_dbg(dev, "%s secs=%d, mins=%d, "
		"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
		"write", tm->tm_sec, tm->tm_min,
		tm->tm_hour, tm->tm_mday,
		tm->tm_mon, tm->tm_year, tm->tm_wday);

	buf[0] = 0x80 | M41T94_REG_SECONDS; /* write time + date */
	buf[M41T94_REG_SECONDS] = bin2bcd(tm->tm_sec);
	buf[M41T94_REG_MINUTES] = bin2bcd(tm->tm_min);
	buf[M41T94_REG_HOURS]   = bin2bcd(tm->tm_hour);
	buf[M41T94_REG_WDAY]    = bin2bcd(tm->tm_wday + 1);
	buf[M41T94_REG_DAY]     = bin2bcd(tm->tm_mday);
	buf[M41T94_REG_MONTH]   = bin2bcd(tm->tm_mon + 1);

	buf[M41T94_REG_HOURS] |= M41T94_BIT_CEB;
	if (tm->tm_year >= 100)
		buf[M41T94_REG_HOURS] |= M41T94_BIT_CB;
	buf[M41T94_REG_YEAR] = bin2bcd(tm->tm_year % 100);

	return spi_write(spi, buf, 8);
}

__attribute__((used)) static int m41t94_read_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[2];
	int ret, hour;

	/* clear halt update bit */
	ret = spi_w8r8(spi, M41T94_REG_HT);
	if (ret < 0)
		return ret;
	if (ret & M41T94_BIT_HALT) {
		buf[0] = 0x80 | M41T94_REG_HT;
		buf[1] = ret & ~M41T94_BIT_HALT;
		spi_write(spi, buf, 2);
	}

	/* clear stop bit */
	ret = spi_w8r8(spi, M41T94_REG_SECONDS);
	if (ret < 0)
		return ret;
	if (ret & M41T94_BIT_STOP) {
		buf[0] = 0x80 | M41T94_REG_SECONDS;
		buf[1] = ret & ~M41T94_BIT_STOP;
		spi_write(spi, buf, 2);
	}

	tm->tm_sec  = bcd2bin(spi_w8r8(spi, M41T94_REG_SECONDS));
	tm->tm_min  = bcd2bin(spi_w8r8(spi, M41T94_REG_MINUTES));
	hour = spi_w8r8(spi, M41T94_REG_HOURS);
	tm->tm_hour = bcd2bin(hour & 0x3f);
	tm->tm_wday = bcd2bin(spi_w8r8(spi, M41T94_REG_WDAY)) - 1;
	tm->tm_mday = bcd2bin(spi_w8r8(spi, M41T94_REG_DAY));
	tm->tm_mon  = bcd2bin(spi_w8r8(spi, M41T94_REG_MONTH)) - 1;
	tm->tm_year = bcd2bin(spi_w8r8(spi, M41T94_REG_YEAR));
	if ((hour & M41T94_BIT_CB) || !(hour & M41T94_BIT_CEB))
		tm->tm_year += 100;

	dev_dbg(dev, "%s secs=%d, mins=%d, "
		"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
		"read", tm->tm_sec, tm->tm_min,
		tm->tm_hour, tm->tm_mday,
		tm->tm_mon, tm->tm_year, tm->tm_wday);

	return 0;
}

__attribute__((used)) static int m41t94_probe(struct spi_device *spi)
{
	struct rtc_device *rtc;
	int res;

	spi->bits_per_word = 8;
	spi_setup(spi);

	res = spi_w8r8(spi, M41T94_REG_SECONDS);
	if (res < 0) {
		dev_err(&spi->dev, "not found.\n");
		return res;
	}

	rtc = devm_rtc_device_register(&spi->dev, m41t94_driver.driver.name,
					&m41t94_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	spi_set_drvdata(spi, rtc);

	return 0;
}

