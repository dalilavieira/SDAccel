#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; int tm_wday; int tm_hour; int tm_min; int tm_sec; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct TYPE_5__ {struct device* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct max8907_rtc {int irq; int /*<<< orphan*/  rtc_dev; int /*<<< orphan*/  regmap; struct max8907* max8907; } ;
struct max8907 {int /*<<< orphan*/  irqc_rtc; int /*<<< orphan*/  regmap_rtc; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HOUR_12 ; 
 int HOUR_AM_PM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX8907_IRQ_RTC_ALARM0 ; 
 int /*<<< orphan*/  MAX8907_REG_ALARM0_CNTL ; 
 int /*<<< orphan*/  MAX8907_REG_ALARM0_SEC ; 
 int /*<<< orphan*/  MAX8907_REG_RTC_SEC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 size_t RTC_DATE ; 
 size_t RTC_HOUR ; 
 int RTC_IRQF ; 
 size_t RTC_MIN ; 
 size_t RTC_MONTH ; 
 size_t RTC_SEC ; 
 size_t RTC_WEEKDAY ; 
 size_t RTC_YEAR1 ; 
 size_t RTC_YEAR2 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int TIME_NUM ; 
 int bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 struct max8907_rtc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct max8907_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (TYPE_1__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max8907_rtc_ops ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max8907_rtc*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static irqreturn_t max8907_irq_handler(int irq, void *data)
{
	struct max8907_rtc *rtc = data;

	regmap_write(rtc->regmap, MAX8907_REG_ALARM0_CNTL, 0);

	rtc_update_irq(rtc->rtc_dev, 1, RTC_IRQF | RTC_AF);

	return IRQ_HANDLED;
}

__attribute__((used)) static void regs_to_tm(u8 *regs, struct rtc_time *tm)
{
	tm->tm_year = bcd2bin(regs[RTC_YEAR2]) * 100 +
		bcd2bin(regs[RTC_YEAR1]) - 1900;
	tm->tm_mon = bcd2bin(regs[RTC_MONTH] & 0x1f) - 1;
	tm->tm_mday = bcd2bin(regs[RTC_DATE] & 0x3f);
	tm->tm_wday = (regs[RTC_WEEKDAY] & 0x07);
	if (regs[RTC_HOUR] & HOUR_12) {
		tm->tm_hour = bcd2bin(regs[RTC_HOUR] & 0x01f);
		if (tm->tm_hour == 12)
			tm->tm_hour = 0;
		if (regs[RTC_HOUR] & HOUR_AM_PM)
			tm->tm_hour += 12;
	} else {
		tm->tm_hour = bcd2bin(regs[RTC_HOUR] & 0x03f);
	}
	tm->tm_min = bcd2bin(regs[RTC_MIN] & 0x7f);
	tm->tm_sec = bcd2bin(regs[RTC_SEC] & 0x7f);
}

__attribute__((used)) static void tm_to_regs(struct rtc_time *tm, u8 *regs)
{
	u8 high, low;

	high = (tm->tm_year + 1900) / 100;
	low = tm->tm_year % 100;
	regs[RTC_YEAR2] = bin2bcd(high);
	regs[RTC_YEAR1] = bin2bcd(low);
	regs[RTC_MONTH] = bin2bcd(tm->tm_mon + 1);
	regs[RTC_DATE] = bin2bcd(tm->tm_mday);
	regs[RTC_WEEKDAY] = tm->tm_wday;
	regs[RTC_HOUR] = bin2bcd(tm->tm_hour);
	regs[RTC_MIN] = bin2bcd(tm->tm_min);
	regs[RTC_SEC] = bin2bcd(tm->tm_sec);
}

__attribute__((used)) static int max8907_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct max8907_rtc *rtc = dev_get_drvdata(dev);
	u8 regs[TIME_NUM];
	int ret;

	ret = regmap_bulk_read(rtc->regmap, MAX8907_REG_RTC_SEC, regs,
			       TIME_NUM);
	if (ret < 0)
		return ret;

	regs_to_tm(regs, tm);

	return 0;
}

__attribute__((used)) static int max8907_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct max8907_rtc *rtc = dev_get_drvdata(dev);
	u8 regs[TIME_NUM];

	tm_to_regs(tm, regs);

	return regmap_bulk_write(rtc->regmap, MAX8907_REG_RTC_SEC, regs,
				 TIME_NUM);
}

__attribute__((used)) static int max8907_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct max8907_rtc *rtc = dev_get_drvdata(dev);
	u8 regs[TIME_NUM];
	unsigned int val;
	int ret;

	ret = regmap_bulk_read(rtc->regmap, MAX8907_REG_ALARM0_SEC, regs,
			       TIME_NUM);
	if (ret < 0)
		return ret;

	regs_to_tm(regs, &alrm->time);

	ret = regmap_read(rtc->regmap, MAX8907_REG_ALARM0_CNTL, &val);
	if (ret < 0)
		return ret;

	alrm->enabled = !!(val & 0x7f);

	return 0;
}

__attribute__((used)) static int max8907_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct max8907_rtc *rtc = dev_get_drvdata(dev);
	u8 regs[TIME_NUM];
	int ret;

	tm_to_regs(&alrm->time, regs);

	/* Disable alarm while we update the target time */
	ret = regmap_write(rtc->regmap, MAX8907_REG_ALARM0_CNTL, 0);
	if (ret < 0)
		return ret;

	ret = regmap_bulk_write(rtc->regmap, MAX8907_REG_ALARM0_SEC, regs,
				TIME_NUM);
	if (ret < 0)
		return ret;

	if (alrm->enabled)
		ret = regmap_write(rtc->regmap, MAX8907_REG_ALARM0_CNTL, 0x77);

	return ret;
}

__attribute__((used)) static int max8907_rtc_probe(struct platform_device *pdev)
{
	struct max8907 *max8907 = dev_get_drvdata(pdev->dev.parent);
	struct max8907_rtc *rtc;
	int ret;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;
	platform_set_drvdata(pdev, rtc);

	rtc->max8907 = max8907;
	rtc->regmap = max8907->regmap_rtc;

	rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, "max8907-rtc",
					&max8907_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc->rtc_dev)) {
		ret = PTR_ERR(rtc->rtc_dev);
		dev_err(&pdev->dev, "Failed to register RTC device: %d\n", ret);
		return ret;
	}

	rtc->irq = regmap_irq_get_virq(max8907->irqc_rtc,
				       MAX8907_IRQ_RTC_ALARM0);
	if (rtc->irq < 0)
		return rtc->irq;

	ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
				max8907_irq_handler,
				IRQF_ONESHOT, "max8907-alarm0", rtc);
	if (ret < 0)
		dev_err(&pdev->dev, "Failed to request IRQ%d: %d\n",
			rtc->irq, ret);

	return ret;
}

