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
typedef  int time64_t ;
struct rtc_time {int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; int tm_year; } ;
struct rtc_device {int /*<<< orphan*/  range_max; int /*<<< orphan*/  range_min; int /*<<< orphan*/ * ops; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int ETIMEDOUT ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int LS1X_DAY_OFFSET ; 
 int LS1X_HOUR_OFFSET ; 
 int LS1X_MIN_OFFSET ; 
 int LS1X_MONTH_OFFSET ; 
 int LS1X_SEC_OFFSET ; 
 int LS1X_YEAR_MASK ; 
 int PTR_ERR (struct rtc_device*) ; 
 unsigned long RTC_CNTR_OK ; 
 int /*<<< orphan*/  RTC_TIMESTAMP_BEGIN_1900 ; 
 int /*<<< orphan*/  RTC_TIMESTAMP_END_2099 ; 
 int SYS_CNTRL_TS ; 
 int SYS_CNTRL_TTS ; 
 int /*<<< orphan*/  SYS_COUNTER_CNTRL ; 
 int /*<<< orphan*/  SYS_TOYREAD0 ; 
 int /*<<< orphan*/  SYS_TOYREAD1 ; 
 int /*<<< orphan*/  SYS_TOYTRIM ; 
 int /*<<< orphan*/  SYS_TOYWRITE0 ; 
 int /*<<< orphan*/  SYS_TOYWRITE1 ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct rtc_device* devm_rtc_allocate_device (struct device*) ; 
 int /*<<< orphan*/  ls1x_get_day (unsigned long) ; 
 int /*<<< orphan*/  ls1x_get_hour (unsigned long) ; 
 int /*<<< orphan*/  ls1x_get_min (unsigned long) ; 
 int /*<<< orphan*/  ls1x_get_month (unsigned long) ; 
 int /*<<< orphan*/  ls1x_get_sec (unsigned long) ; 
 int /*<<< orphan*/  ls1x_rtc_ops ; 
 int /*<<< orphan*/  memset (struct rtc_time*,int /*<<< orphan*/ ,int) ; 
 int mktime64 (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rtc_device*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int rtc_register_device (struct rtc_device*) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int,struct rtc_time*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ls1x_rtc_read_time(struct device *dev, struct rtc_time *rtm)
{
	unsigned long v;
	time64_t t;

	v = readl(SYS_TOYREAD0);
	t = readl(SYS_TOYREAD1);

	memset(rtm, 0, sizeof(struct rtc_time));
	t  = mktime64((t & LS1X_YEAR_MASK), ls1x_get_month(v),
			ls1x_get_day(v), ls1x_get_hour(v),
			ls1x_get_min(v), ls1x_get_sec(v));
	rtc_time64_to_tm(t, rtm);

	return 0;
}

__attribute__((used)) static int ls1x_rtc_set_time(struct device *dev, struct  rtc_time *rtm)
{
	unsigned long v, t, c;
	int ret = -ETIMEDOUT;

	v = ((rtm->tm_mon + 1)  << LS1X_MONTH_OFFSET)
		| (rtm->tm_mday << LS1X_DAY_OFFSET)
		| (rtm->tm_hour << LS1X_HOUR_OFFSET)
		| (rtm->tm_min  << LS1X_MIN_OFFSET)
		| (rtm->tm_sec  << LS1X_SEC_OFFSET);

	writel(v, SYS_TOYWRITE0);
	c = 0x10000;
	/* add timeout check counter, for more safe */
	while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TS) && --c)
		usleep_range(1000, 3000);

	if (!c) {
		dev_err(dev, "set time timeout!\n");
		goto err;
	}

	t = rtm->tm_year + 1900;
	writel(t, SYS_TOYWRITE1);
	c = 0x10000;
	while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TS) && --c)
		usleep_range(1000, 3000);

	if (!c) {
		dev_err(dev, "set time timeout!\n");
		goto err;
	}
	return 0;
err:
	return ret;
}

__attribute__((used)) static int ls1x_rtc_probe(struct platform_device *pdev)
{
	struct rtc_device *rtcdev;
	unsigned long v;

	v = readl(SYS_COUNTER_CNTRL);
	if (!(v & RTC_CNTR_OK)) {
		dev_err(&pdev->dev, "rtc counters not working\n");
		return -ENODEV;
	}

	/* set to 1 HZ if needed */
	if (readl(SYS_TOYTRIM) != 32767) {
		v = 0x100000;
		while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TTS) && --v)
			usleep_range(1000, 3000);

		if (!v) {
			dev_err(&pdev->dev, "time out\n");
			return -ETIMEDOUT;
		}
		writel(32767, SYS_TOYTRIM);
	}
	/* this loop coundn't be endless */
	while (readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TTS)
		usleep_range(1000, 3000);

	rtcdev = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(rtcdev))
		return PTR_ERR(rtcdev);

	platform_set_drvdata(pdev, rtcdev);
	rtcdev->ops = &ls1x_rtc_ops;
	rtcdev->range_min = RTC_TIMESTAMP_BEGIN_1900;
	rtcdev->range_max = RTC_TIMESTAMP_END_2099;

	return rtc_register_device(rtcdev);
}

