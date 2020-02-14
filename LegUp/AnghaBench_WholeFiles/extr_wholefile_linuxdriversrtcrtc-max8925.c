#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct rtc_time {unsigned char tm_year; unsigned char tm_mon; unsigned char tm_mday; unsigned char tm_wday; unsigned char tm_hour; unsigned char tm_min; unsigned char tm_sec; } ;
struct rtc_wkalrm {int enabled; int pending; struct rtc_time time; } ;
struct TYPE_7__ {struct device* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct max8925_rtc_info {int /*<<< orphan*/  rtc_dev; int /*<<< orphan*/  irq; TYPE_1__* dev; int /*<<< orphan*/  rtc; struct max8925_chip* chip; } ;
struct max8925_chip {int /*<<< orphan*/  dev; int /*<<< orphan*/  rtc; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ALARM0_IRQ ; 
 int ALARM0_STATUS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned char HOUR_12 ; 
 unsigned char HOUR_AM_PM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX8925_ALARM0_CNTL ; 
 int /*<<< orphan*/  MAX8925_ALARM0_SEC ; 
 int /*<<< orphan*/  MAX8925_RTC_IRQ_MASK ; 
 int /*<<< orphan*/  MAX8925_RTC_SEC ; 
 int /*<<< orphan*/  MAX8925_RTC_STATUS ; 
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
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_1__*,struct max8925_rtc_info*) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_1__*,int) ; 
 struct max8925_rtc_info* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct max8925_rtc_info*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (TYPE_1__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int max8925_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int max8925_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int max8925_reg_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int max8925_reg_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  max8925_rtc_ops ; 
 int /*<<< orphan*/  max8925_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max8925_rtc_info*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static irqreturn_t rtc_update_handler(int irq, void *data)
{
	struct max8925_rtc_info *info = (struct max8925_rtc_info *)data;

	/* disable ALARM0 except for 1SEC alarm */
	max8925_set_bits(info->rtc, MAX8925_ALARM0_CNTL, 0x7f, 0);
	rtc_update_irq(info->rtc_dev, 1, RTC_IRQF | RTC_AF);
	return IRQ_HANDLED;
}

__attribute__((used)) static int tm_calc(struct rtc_time *tm, unsigned char *buf, int len)
{
	if (len < TIME_NUM)
		return -EINVAL;
	tm->tm_year = (buf[RTC_YEAR2] >> 4) * 1000
			+ (buf[RTC_YEAR2] & 0xf) * 100
			+ (buf[RTC_YEAR1] >> 4) * 10
			+ (buf[RTC_YEAR1] & 0xf);
	tm->tm_year -= 1900;
	tm->tm_mon = ((buf[RTC_MONTH] >> 4) & 0x01) * 10
			+ (buf[RTC_MONTH] & 0x0f);
	tm->tm_mday = ((buf[RTC_DATE] >> 4) & 0x03) * 10
			+ (buf[RTC_DATE] & 0x0f);
	tm->tm_wday = buf[RTC_WEEKDAY] & 0x07;
	if (buf[RTC_HOUR] & HOUR_12) {
		tm->tm_hour = ((buf[RTC_HOUR] >> 4) & 0x1) * 10
				+ (buf[RTC_HOUR] & 0x0f);
		if (buf[RTC_HOUR] & HOUR_AM_PM)
			tm->tm_hour += 12;
	} else
		tm->tm_hour = ((buf[RTC_HOUR] >> 4) & 0x03) * 10
				+ (buf[RTC_HOUR] & 0x0f);
	tm->tm_min = ((buf[RTC_MIN] >> 4) & 0x7) * 10
			+ (buf[RTC_MIN] & 0x0f);
	tm->tm_sec = ((buf[RTC_SEC] >> 4) & 0x7) * 10
			+ (buf[RTC_SEC] & 0x0f);
	return 0;
}

__attribute__((used)) static int data_calc(unsigned char *buf, struct rtc_time *tm, int len)
{
	unsigned char high, low;

	if (len < TIME_NUM)
		return -EINVAL;

	high = (tm->tm_year + 1900) / 1000;
	low = (tm->tm_year + 1900) / 100;
	low = low - high * 10;
	buf[RTC_YEAR2] = (high << 4) + low;
	high = (tm->tm_year + 1900) / 10;
	low = tm->tm_year + 1900;
	low = low - high * 10;
	high = high - (high / 10) * 10;
	buf[RTC_YEAR1] = (high << 4) + low;
	high = tm->tm_mon / 10;
	low = tm->tm_mon;
	low = low - high * 10;
	buf[RTC_MONTH] = (high << 4) + low;
	high = tm->tm_mday / 10;
	low = tm->tm_mday;
	low = low - high * 10;
	buf[RTC_DATE] = (high << 4) + low;
	buf[RTC_WEEKDAY] = tm->tm_wday;
	high = tm->tm_hour / 10;
	low = tm->tm_hour;
	low = low - high * 10;
	buf[RTC_HOUR] = (high << 4) + low;
	high = tm->tm_min / 10;
	low = tm->tm_min;
	low = low - high * 10;
	buf[RTC_MIN] = (high << 4) + low;
	high = tm->tm_sec / 10;
	low = tm->tm_sec;
	low = low - high * 10;
	buf[RTC_SEC] = (high << 4) + low;
	return 0;
}

__attribute__((used)) static int max8925_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct max8925_rtc_info *info = dev_get_drvdata(dev);
	unsigned char buf[TIME_NUM];
	int ret;

	ret = max8925_bulk_read(info->rtc, MAX8925_RTC_SEC, TIME_NUM, buf);
	if (ret < 0)
		goto out;
	ret = tm_calc(tm, buf, TIME_NUM);
out:
	return ret;
}

__attribute__((used)) static int max8925_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct max8925_rtc_info *info = dev_get_drvdata(dev);
	unsigned char buf[TIME_NUM];
	int ret;

	ret = data_calc(buf, tm, TIME_NUM);
	if (ret < 0)
		goto out;
	ret = max8925_bulk_write(info->rtc, MAX8925_RTC_SEC, TIME_NUM, buf);
out:
	return ret;
}

__attribute__((used)) static int max8925_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct max8925_rtc_info *info = dev_get_drvdata(dev);
	unsigned char buf[TIME_NUM];
	int ret;

	ret = max8925_bulk_read(info->rtc, MAX8925_ALARM0_SEC, TIME_NUM, buf);
	if (ret < 0)
		goto out;
	ret = tm_calc(&alrm->time, buf, TIME_NUM);
	if (ret < 0)
		goto out;
	ret = max8925_reg_read(info->rtc, MAX8925_RTC_IRQ_MASK);
	if (ret < 0)
		goto out;
	if (ret & ALARM0_IRQ) {
		alrm->enabled = 0;
	} else {
		ret = max8925_reg_read(info->rtc, MAX8925_ALARM0_CNTL);
		if (ret < 0)
			goto out;
		if (!ret)
			alrm->enabled = 0;
		else
			alrm->enabled = 1;
	}
	ret = max8925_reg_read(info->rtc, MAX8925_RTC_STATUS);
	if (ret < 0)
		goto out;
	if (ret & ALARM0_STATUS)
		alrm->pending = 1;
	else
		alrm->pending = 0;
	return 0;
out:
	return ret;
}

__attribute__((used)) static int max8925_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct max8925_rtc_info *info = dev_get_drvdata(dev);
	unsigned char buf[TIME_NUM];
	int ret;

	ret = data_calc(buf, &alrm->time, TIME_NUM);
	if (ret < 0)
		goto out;
	ret = max8925_bulk_write(info->rtc, MAX8925_ALARM0_SEC, TIME_NUM, buf);
	if (ret < 0)
		goto out;
	if (alrm->enabled)
		/* only enable alarm on year/month/day/hour/min/sec */
		ret = max8925_reg_write(info->rtc, MAX8925_ALARM0_CNTL, 0x77);
	else
		ret = max8925_reg_write(info->rtc, MAX8925_ALARM0_CNTL, 0x0);
out:
	return ret;
}

__attribute__((used)) static int max8925_rtc_probe(struct platform_device *pdev)
{
	struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct max8925_rtc_info *info;
	int ret;

	info = devm_kzalloc(&pdev->dev, sizeof(struct max8925_rtc_info),
			    GFP_KERNEL);
	if (!info)
		return -ENOMEM;
	info->chip = chip;
	info->rtc = chip->rtc;
	info->dev = &pdev->dev;
	info->irq = platform_get_irq(pdev, 0);

	ret = devm_request_threaded_irq(&pdev->dev, info->irq, NULL,
					rtc_update_handler, IRQF_ONESHOT,
					"rtc-alarm0", info);
	if (ret < 0) {
		dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
			info->irq, ret);
		return ret;
	}

	dev_set_drvdata(&pdev->dev, info);
	/* XXX - isn't this redundant? */
	platform_set_drvdata(pdev, info);

	device_init_wakeup(&pdev->dev, 1);

	info->rtc_dev = devm_rtc_device_register(&pdev->dev, "max8925-rtc",
					&max8925_rtc_ops, THIS_MODULE);
	ret = PTR_ERR(info->rtc_dev);
	if (IS_ERR(info->rtc_dev)) {
		dev_err(&pdev->dev, "Failed to register RTC device: %d\n", ret);
		return ret;
	}

	return 0;
}

