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
typedef  int /*<<< orphan*/  buf ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {TYPE_1__ driver; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int M41T93_FLAG_BL ; 
 int M41T93_FLAG_HT ; 
 int M41T93_FLAG_OF ; 
 int M41T93_FLAG_ST ; 
 size_t M41T93_REG_ALM_HOUR_HT ; 
 size_t M41T93_REG_CENT_HOUR ; 
 size_t M41T93_REG_DAY ; 
 size_t M41T93_REG_FLAGS ; 
 size_t M41T93_REG_MIN ; 
 size_t M41T93_REG_MON ; 
 size_t M41T93_REG_SSEC ; 
 size_t M41T93_REG_ST_SEC ; 
 size_t M41T93_REG_WDAY ; 
 size_t M41T93_REG_YEAR ; 
 int PTR_ERR (struct rtc_device*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct rtc_device* devm_rtc_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__ m41t93_driver ; 
 int /*<<< orphan*/  m41t93_rtc_ops ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct rtc_device*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int spi_w8r8 (struct spi_device*,size_t) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int spi_write_then_read (struct spi_device*,int const*,int,int*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static inline int m41t93_set_reg(struct spi_device *spi, u8 addr, u8 data)
{
	u8 buf[2];

	/* MSB must be '1' to write */
	buf[0] = addr | 0x80;
	buf[1] = data;

	return spi_write(spi, buf, sizeof(buf));
}

__attribute__((used)) static int m41t93_set_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	int tmp;
	u8 buf[9] = {0x80};        /* write cmd + 8 data bytes */
	u8 * const data = &buf[1]; /* ptr to first data byte */

	dev_dbg(dev, "%s secs=%d, mins=%d, "
		"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
		"write", tm->tm_sec, tm->tm_min,
		tm->tm_hour, tm->tm_mday,
		tm->tm_mon, tm->tm_year, tm->tm_wday);

	if (tm->tm_year < 100) {
		dev_warn(&spi->dev, "unsupported date (before 2000-01-01).\n");
		return -EINVAL;
	}

	tmp = spi_w8r8(spi, M41T93_REG_FLAGS);
	if (tmp < 0)
		return tmp;

	if (tmp & M41T93_FLAG_OF) {
		dev_warn(&spi->dev, "OF bit is set, resetting.\n");
		m41t93_set_reg(spi, M41T93_REG_FLAGS, tmp & ~M41T93_FLAG_OF);

		tmp = spi_w8r8(spi, M41T93_REG_FLAGS);
		if (tmp < 0) {
			return tmp;
		} else if (tmp & M41T93_FLAG_OF) {
			/* OF cannot be immediately reset: oscillator has to be
			 * restarted. */
			u8 reset_osc = buf[M41T93_REG_ST_SEC] | M41T93_FLAG_ST;

			dev_warn(&spi->dev,
				 "OF bit is still set, kickstarting clock.\n");
			m41t93_set_reg(spi, M41T93_REG_ST_SEC, reset_osc);
			reset_osc &= ~M41T93_FLAG_ST;
			m41t93_set_reg(spi, M41T93_REG_ST_SEC, reset_osc);
		}
	}

	data[M41T93_REG_SSEC]		= 0;
	data[M41T93_REG_ST_SEC]		= bin2bcd(tm->tm_sec);
	data[M41T93_REG_MIN]		= bin2bcd(tm->tm_min);
	data[M41T93_REG_CENT_HOUR]	= bin2bcd(tm->tm_hour) |
						((tm->tm_year/100-1) << 6);
	data[M41T93_REG_DAY]		= bin2bcd(tm->tm_mday);
	data[M41T93_REG_WDAY]		= bin2bcd(tm->tm_wday + 1);
	data[M41T93_REG_MON]		= bin2bcd(tm->tm_mon + 1);
	data[M41T93_REG_YEAR]		= bin2bcd(tm->tm_year % 100);

	return spi_write(spi, buf, sizeof(buf));
}

__attribute__((used)) static int m41t93_get_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	const u8 start_addr = 0;
	u8 buf[8];
	int century_after_1900;
	int tmp;
	int ret = 0;

	/* Check status of clock. Two states must be considered:
	   1. halt bit (HT) is set: the clock is running but update of readout
	      registers has been disabled due to power failure. This is normal
	      case after poweron. Time is valid after resetting HT bit.
	   2. oscillator fail bit (OF) is set: time is invalid.
	*/
	tmp = spi_w8r8(spi, M41T93_REG_ALM_HOUR_HT);
	if (tmp < 0)
		return tmp;

	if (tmp & M41T93_FLAG_HT) {
		dev_dbg(&spi->dev, "HT bit is set, reenable clock update.\n");
		m41t93_set_reg(spi, M41T93_REG_ALM_HOUR_HT,
			       tmp & ~M41T93_FLAG_HT);
	}

	tmp = spi_w8r8(spi, M41T93_REG_FLAGS);
	if (tmp < 0)
		return tmp;

	if (tmp & M41T93_FLAG_OF) {
		ret = -EINVAL;
		dev_warn(&spi->dev, "OF bit is set, write time to restart.\n");
	}

	if (tmp & M41T93_FLAG_BL)
		dev_warn(&spi->dev, "BL bit is set, replace battery.\n");

	/* read actual time/date */
	tmp = spi_write_then_read(spi, &start_addr, 1, buf, sizeof(buf));
	if (tmp < 0)
		return tmp;

	tm->tm_sec	= bcd2bin(buf[M41T93_REG_ST_SEC]);
	tm->tm_min	= bcd2bin(buf[M41T93_REG_MIN]);
	tm->tm_hour	= bcd2bin(buf[M41T93_REG_CENT_HOUR] & 0x3f);
	tm->tm_mday	= bcd2bin(buf[M41T93_REG_DAY]);
	tm->tm_mon	= bcd2bin(buf[M41T93_REG_MON]) - 1;
	tm->tm_wday	= bcd2bin(buf[M41T93_REG_WDAY] & 0x0f) - 1;

	century_after_1900 = (buf[M41T93_REG_CENT_HOUR] >> 6) + 1;
	tm->tm_year = bcd2bin(buf[M41T93_REG_YEAR]) + century_after_1900 * 100;

	dev_dbg(dev, "%s secs=%d, mins=%d, "
		"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
		"read", tm->tm_sec, tm->tm_min,
		tm->tm_hour, tm->tm_mday,
		tm->tm_mon, tm->tm_year, tm->tm_wday);

	return ret;
}

__attribute__((used)) static int m41t93_probe(struct spi_device *spi)
{
	struct rtc_device *rtc;
	int res;

	spi->bits_per_word = 8;
	spi_setup(spi);

	res = spi_w8r8(spi, M41T93_REG_WDAY);
	if (res < 0 || (res & 0xf8) != 0) {
		dev_err(&spi->dev, "not found 0x%x.\n", res);
		return -ENODEV;
	}

	rtc = devm_rtc_device_register(&spi->dev, m41t93_driver.driver.name,
					&m41t93_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	spi_set_drvdata(spi, rtc);

	return 0;
}

