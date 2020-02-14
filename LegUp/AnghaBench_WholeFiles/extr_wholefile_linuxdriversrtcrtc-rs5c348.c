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
typedef  int /*<<< orphan*/  txbuf ;
struct device {struct rs5c348_plat_data* platform_data; } ;
struct spi_device {int max_speed_hz; struct device dev; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_device {int dummy; } ;
struct rs5c348_plat_data {int rtc_24h; struct rtc_device* rtc; } ;
typedef  int /*<<< orphan*/  rxbuf ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {TYPE_1__ driver; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int PTR_ERR (struct rtc_device*) ; 
 int RS5C348_BIT_24H ; 
 int RS5C348_BIT_PM ; 
 int RS5C348_BIT_VDET ; 
 int RS5C348_BIT_XSTP ; 
 int RS5C348_BIT_Y2K ; 
 int RS5C348_CMD_MR (size_t) ; 
 int RS5C348_CMD_MW (size_t) ; 
 int RS5C348_CMD_R (size_t) ; 
 int RS5C348_CMD_W (size_t) ; 
 int RS5C348_DAY_MASK ; 
 int RS5C348_HOURS_MASK ; 
 int RS5C348_MINS_MASK ; 
 int RS5C348_MONTH_MASK ; 
 size_t RS5C348_REG_CTL1 ; 
 size_t RS5C348_REG_CTL2 ; 
 size_t RS5C348_REG_DAY ; 
 size_t RS5C348_REG_HOURS ; 
 size_t RS5C348_REG_MINS ; 
 size_t RS5C348_REG_MONTH ; 
 size_t RS5C348_REG_SECS ; 
 size_t RS5C348_REG_WDAY ; 
 size_t RS5C348_REG_YEAR ; 
 int RS5C348_SECS_MASK ; 
 int RS5C348_WDAY_MASK ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct rs5c348_plat_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct rs5c348_plat_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct rtc_device* devm_rtc_device_register (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__ rs5c348_driver ; 
 int /*<<< orphan*/  rs5c348_rtc_ops ; 
 int /*<<< orphan*/  rtc_time_to_tm (int /*<<< orphan*/ ,struct rtc_time*) ; 
 int spi_w8r8 (struct spi_device*,int) ; 
 int spi_write_then_read (struct spi_device*,int*,int,int*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int
rs5c348_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	struct rs5c348_plat_data *pdata = dev_get_platdata(&spi->dev);
	u8 txbuf[5+7], *txp;
	int ret;

	/* Transfer 5 bytes before writing SEC.  This gives 31us for carry. */
	txp = txbuf;
	txbuf[0] = RS5C348_CMD_R(RS5C348_REG_CTL2); /* cmd, ctl2 */
	txbuf[1] = 0;	/* dummy */
	txbuf[2] = RS5C348_CMD_R(RS5C348_REG_CTL2); /* cmd, ctl2 */
	txbuf[3] = 0;	/* dummy */
	txbuf[4] = RS5C348_CMD_MW(RS5C348_REG_SECS); /* cmd, sec, ... */
	txp = &txbuf[5];
	txp[RS5C348_REG_SECS] = bin2bcd(tm->tm_sec);
	txp[RS5C348_REG_MINS] = bin2bcd(tm->tm_min);
	if (pdata->rtc_24h) {
		txp[RS5C348_REG_HOURS] = bin2bcd(tm->tm_hour);
	} else {
		/* hour 0 is AM12, noon is PM12 */
		txp[RS5C348_REG_HOURS] = bin2bcd((tm->tm_hour + 11) % 12 + 1) |
			(tm->tm_hour >= 12 ? RS5C348_BIT_PM : 0);
	}
	txp[RS5C348_REG_WDAY] = bin2bcd(tm->tm_wday);
	txp[RS5C348_REG_DAY] = bin2bcd(tm->tm_mday);
	txp[RS5C348_REG_MONTH] = bin2bcd(tm->tm_mon + 1) |
		(tm->tm_year >= 100 ? RS5C348_BIT_Y2K : 0);
	txp[RS5C348_REG_YEAR] = bin2bcd(tm->tm_year % 100);
	/* write in one transfer to avoid data inconsistency */
	ret = spi_write_then_read(spi, txbuf, sizeof(txbuf), NULL, 0);
	udelay(62);	/* Tcsr 62us */
	return ret;
}

__attribute__((used)) static int
rs5c348_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct spi_device *spi = to_spi_device(dev);
	struct rs5c348_plat_data *pdata = dev_get_platdata(&spi->dev);
	u8 txbuf[5], rxbuf[7];
	int ret;

	/* Transfer 5 byte befores reading SEC.  This gives 31us for carry. */
	txbuf[0] = RS5C348_CMD_R(RS5C348_REG_CTL2); /* cmd, ctl2 */
	txbuf[1] = 0;	/* dummy */
	txbuf[2] = RS5C348_CMD_R(RS5C348_REG_CTL2); /* cmd, ctl2 */
	txbuf[3] = 0;	/* dummy */
	txbuf[4] = RS5C348_CMD_MR(RS5C348_REG_SECS); /* cmd, sec, ... */

	/* read in one transfer to avoid data inconsistency */
	ret = spi_write_then_read(spi, txbuf, sizeof(txbuf),
				  rxbuf, sizeof(rxbuf));
	udelay(62);	/* Tcsr 62us */
	if (ret < 0)
		return ret;

	tm->tm_sec = bcd2bin(rxbuf[RS5C348_REG_SECS] & RS5C348_SECS_MASK);
	tm->tm_min = bcd2bin(rxbuf[RS5C348_REG_MINS] & RS5C348_MINS_MASK);
	tm->tm_hour = bcd2bin(rxbuf[RS5C348_REG_HOURS] & RS5C348_HOURS_MASK);
	if (!pdata->rtc_24h) {
		if (rxbuf[RS5C348_REG_HOURS] & RS5C348_BIT_PM) {
			tm->tm_hour -= 20;
			tm->tm_hour %= 12;
			tm->tm_hour += 12;
		} else
			tm->tm_hour %= 12;
	}
	tm->tm_wday = bcd2bin(rxbuf[RS5C348_REG_WDAY] & RS5C348_WDAY_MASK);
	tm->tm_mday = bcd2bin(rxbuf[RS5C348_REG_DAY] & RS5C348_DAY_MASK);
	tm->tm_mon =
		bcd2bin(rxbuf[RS5C348_REG_MONTH] & RS5C348_MONTH_MASK) - 1;
	/* year is 1900 + tm->tm_year */
	tm->tm_year = bcd2bin(rxbuf[RS5C348_REG_YEAR]) +
		((rxbuf[RS5C348_REG_MONTH] & RS5C348_BIT_Y2K) ? 100 : 0);

	return 0;
}

__attribute__((used)) static int rs5c348_probe(struct spi_device *spi)
{
	int ret;
	struct rtc_device *rtc;
	struct rs5c348_plat_data *pdata;

	pdata = devm_kzalloc(&spi->dev, sizeof(struct rs5c348_plat_data),
				GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;
	spi->dev.platform_data = pdata;

	/* Check D7 of SECOND register */
	ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_SECS));
	if (ret < 0 || (ret & 0x80)) {
		dev_err(&spi->dev, "not found.\n");
		goto kfree_exit;
	}

	dev_info(&spi->dev, "spiclk %u KHz.\n",
		 (spi->max_speed_hz + 500) / 1000);

	/* turn RTC on if it was not on */
	ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_CTL2));
	if (ret < 0)
		goto kfree_exit;
	if (ret & (RS5C348_BIT_XSTP | RS5C348_BIT_VDET)) {
		u8 buf[2];
		struct rtc_time tm;
		if (ret & RS5C348_BIT_VDET)
			dev_warn(&spi->dev, "voltage-low detected.\n");
		if (ret & RS5C348_BIT_XSTP)
			dev_warn(&spi->dev, "oscillator-stop detected.\n");
		rtc_time_to_tm(0, &tm);	/* 1970/1/1 */
		ret = rs5c348_rtc_set_time(&spi->dev, &tm);
		if (ret < 0)
			goto kfree_exit;
		buf[0] = RS5C348_CMD_W(RS5C348_REG_CTL2);
		buf[1] = 0;
		ret = spi_write_then_read(spi, buf, sizeof(buf), NULL, 0);
		if (ret < 0)
			goto kfree_exit;
	}

	ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_CTL1));
	if (ret < 0)
		goto kfree_exit;
	if (ret & RS5C348_BIT_24H)
		pdata->rtc_24h = 1;

	rtc = devm_rtc_device_register(&spi->dev, rs5c348_driver.driver.name,
				  &rs5c348_rtc_ops, THIS_MODULE);

	if (IS_ERR(rtc)) {
		ret = PTR_ERR(rtc);
		goto kfree_exit;
	}

	pdata->rtc = rtc;

	return 0;
 kfree_exit:
	return ret;
}

