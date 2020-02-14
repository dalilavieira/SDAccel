#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct rtc_time {int tm_year; int tm_wday; int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; int /*<<< orphan*/  tm_yday; } ;
struct rtc_wkalrm {unsigned long pending; unsigned long enabled; struct rtc_time time; } ;
struct rtc_class_ops {int /*<<< orphan*/ * alarm_irq_enable; int /*<<< orphan*/ * set_alarm; int /*<<< orphan*/ * read_alarm; } ;
struct pl031_vendor_data {int /*<<< orphan*/  irqflags; scalar_t__ st_weekday; scalar_t__ clockwatch; int /*<<< orphan*/  ops; } ;
struct pl031_local {int /*<<< orphan*/  rtc; scalar_t__ base; struct pl031_vendor_data* vendor; } ;
struct device {int dummy; } ;
struct amba_id {struct pl031_vendor_data* data; } ;
struct TYPE_2__ {int /*<<< orphan*/  start; } ;
struct amba_device {scalar_t__* irq; struct device dev; TYPE_1__ res; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_BIT_AI ; 
 scalar_t__ RTC_CR ; 
 unsigned long RTC_CR_CWEN ; 
 unsigned long RTC_CR_EN ; 
 scalar_t__ RTC_DR ; 
 unsigned long RTC_HOUR_MASK ; 
 int RTC_HOUR_SHIFT ; 
 scalar_t__ RTC_ICR ; 
 scalar_t__ RTC_IMSC ; 
 unsigned long RTC_IRQF ; 
 scalar_t__ RTC_LR ; 
 unsigned long RTC_MDAY_MASK ; 
 int RTC_MDAY_SHIFT ; 
 unsigned long RTC_MIN_MASK ; 
 int RTC_MIN_SHIFT ; 
 scalar_t__ RTC_MIS ; 
 unsigned long RTC_MON_MASK ; 
 int RTC_MON_SHIFT ; 
 scalar_t__ RTC_MR ; 
 scalar_t__ RTC_RIS ; 
 unsigned long RTC_SEC_MASK ; 
 int RTC_SEC_SHIFT ; 
 unsigned long RTC_WDAY_MASK ; 
 int RTC_WDAY_SHIFT ; 
 scalar_t__ RTC_YDR ; 
 scalar_t__ RTC_YLR ; 
 scalar_t__ RTC_YMR ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  amba_manf (struct amba_device*) ; 
 int /*<<< orphan*/  amba_release_regions (struct amba_device*) ; 
 int amba_request_regions (struct amba_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  amba_rev (struct amba_device*) ; 
 int /*<<< orphan*/  amba_set_drvdata (struct amba_device*,struct pl031_local*) ; 
 int bcd2bin (unsigned long) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct pl031_local* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_pm_clear_wake_irq (struct device*) ; 
 int /*<<< orphan*/  dev_pm_set_wake_irq (struct device*,scalar_t__) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rtc_class_ops* devm_kmemdup (struct device*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct pl031_local* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct pl031_local*) ; 
 int readl (scalar_t__) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct pl031_local*) ; 
 int /*<<< orphan*/  resource_size (TYPE_1__*) ; 
 int /*<<< orphan*/  rtc_device_register (char*,struct device*,struct rtc_class_ops*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_device_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_time_to_tm (int,struct rtc_time*) ; 
 int rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,unsigned long) ; 
 int rtc_valid_tm (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_year_days (unsigned long,unsigned long,int) ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static int pl031_alarm_irq_enable(struct device *dev,
	unsigned int enabled)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);
	unsigned long imsc;

	/* Clear any pending alarm interrupts. */
	writel(RTC_BIT_AI, ldata->base + RTC_ICR);

	imsc = readl(ldata->base + RTC_IMSC);

	if (enabled == 1)
		writel(imsc | RTC_BIT_AI, ldata->base + RTC_IMSC);
	else
		writel(imsc & ~RTC_BIT_AI, ldata->base + RTC_IMSC);

	return 0;
}

__attribute__((used)) static int pl031_stv2_tm_to_time(struct device *dev,
				 struct rtc_time *tm, unsigned long *st_time,
	unsigned long *bcd_year)
{
	int year = tm->tm_year + 1900;
	int wday = tm->tm_wday;

	/* wday masking is not working in hardware so wday must be valid */
	if (wday < -1 || wday > 6) {
		dev_err(dev, "invalid wday value %d\n", tm->tm_wday);
		return -EINVAL;
	} else if (wday == -1) {
		/* wday is not provided, calculate it here */
		unsigned long time;
		struct rtc_time calc_tm;

		rtc_tm_to_time(tm, &time);
		rtc_time_to_tm(time, &calc_tm);
		wday = calc_tm.tm_wday;
	}

	*bcd_year = (bin2bcd(year % 100) | bin2bcd(year / 100) << 8);

	*st_time = ((tm->tm_mon + 1) << RTC_MON_SHIFT)
			|	(tm->tm_mday << RTC_MDAY_SHIFT)
			|	((wday + 1) << RTC_WDAY_SHIFT)
			|	(tm->tm_hour << RTC_HOUR_SHIFT)
			|	(tm->tm_min << RTC_MIN_SHIFT)
			|	(tm->tm_sec << RTC_SEC_SHIFT);

	return 0;
}

__attribute__((used)) static int pl031_stv2_time_to_tm(unsigned long st_time, unsigned long bcd_year,
	struct rtc_time *tm)
{
	tm->tm_year = bcd2bin(bcd_year) + (bcd2bin(bcd_year >> 8) * 100);
	tm->tm_mon  = ((st_time & RTC_MON_MASK) >> RTC_MON_SHIFT) - 1;
	tm->tm_mday = ((st_time & RTC_MDAY_MASK) >> RTC_MDAY_SHIFT);
	tm->tm_wday = ((st_time & RTC_WDAY_MASK) >> RTC_WDAY_SHIFT) - 1;
	tm->tm_hour = ((st_time & RTC_HOUR_MASK) >> RTC_HOUR_SHIFT);
	tm->tm_min  = ((st_time & RTC_MIN_MASK) >> RTC_MIN_SHIFT);
	tm->tm_sec  = ((st_time & RTC_SEC_MASK) >> RTC_SEC_SHIFT);

	tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
	tm->tm_year -= 1900;

	return 0;
}

__attribute__((used)) static int pl031_stv2_read_time(struct device *dev, struct rtc_time *tm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);

	pl031_stv2_time_to_tm(readl(ldata->base + RTC_DR),
			readl(ldata->base + RTC_YDR), tm);

	return 0;
}

__attribute__((used)) static int pl031_stv2_set_time(struct device *dev, struct rtc_time *tm)
{
	unsigned long time;
	unsigned long bcd_year;
	struct pl031_local *ldata = dev_get_drvdata(dev);
	int ret;

	ret = pl031_stv2_tm_to_time(dev, tm, &time, &bcd_year);
	if (ret == 0) {
		writel(bcd_year, ldata->base + RTC_YLR);
		writel(time, ldata->base + RTC_LR);
	}

	return ret;
}

__attribute__((used)) static int pl031_stv2_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);
	int ret;

	ret = pl031_stv2_time_to_tm(readl(ldata->base + RTC_MR),
			readl(ldata->base + RTC_YMR), &alarm->time);

	alarm->pending = readl(ldata->base + RTC_RIS) & RTC_BIT_AI;
	alarm->enabled = readl(ldata->base + RTC_IMSC) & RTC_BIT_AI;

	return ret;
}

__attribute__((used)) static int pl031_stv2_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);
	unsigned long time;
	unsigned long bcd_year;
	int ret;

	/* At the moment, we can only deal with non-wildcarded alarm times. */
	ret = rtc_valid_tm(&alarm->time);
	if (ret == 0) {
		ret = pl031_stv2_tm_to_time(dev, &alarm->time,
					    &time, &bcd_year);
		if (ret == 0) {
			writel(bcd_year, ldata->base + RTC_YMR);
			writel(time, ldata->base + RTC_MR);

			pl031_alarm_irq_enable(dev, alarm->enabled);
		}
	}

	return ret;
}

__attribute__((used)) static irqreturn_t pl031_interrupt(int irq, void *dev_id)
{
	struct pl031_local *ldata = dev_id;
	unsigned long rtcmis;
	unsigned long events = 0;

	rtcmis = readl(ldata->base + RTC_MIS);
	if (rtcmis & RTC_BIT_AI) {
		writel(RTC_BIT_AI, ldata->base + RTC_ICR);
		events |= (RTC_AF | RTC_IRQF);
		rtc_update_irq(ldata->rtc, 1, events);

		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static int pl031_read_time(struct device *dev, struct rtc_time *tm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);

	rtc_time_to_tm(readl(ldata->base + RTC_DR), tm);

	return 0;
}

__attribute__((used)) static int pl031_set_time(struct device *dev, struct rtc_time *tm)
{
	unsigned long time;
	struct pl031_local *ldata = dev_get_drvdata(dev);
	int ret;

	ret = rtc_tm_to_time(tm, &time);

	if (ret == 0)
		writel(time, ldata->base + RTC_LR);

	return ret;
}

__attribute__((used)) static int pl031_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);

	rtc_time_to_tm(readl(ldata->base + RTC_MR), &alarm->time);

	alarm->pending = readl(ldata->base + RTC_RIS) & RTC_BIT_AI;
	alarm->enabled = readl(ldata->base + RTC_IMSC) & RTC_BIT_AI;

	return 0;
}

__attribute__((used)) static int pl031_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct pl031_local *ldata = dev_get_drvdata(dev);
	unsigned long time;
	int ret;

	/* At the moment, we can only deal with non-wildcarded alarm times. */
	ret = rtc_valid_tm(&alarm->time);
	if (ret == 0) {
		ret = rtc_tm_to_time(&alarm->time, &time);
		if (ret == 0) {
			writel(time, ldata->base + RTC_MR);
			pl031_alarm_irq_enable(dev, alarm->enabled);
		}
	}

	return ret;
}

__attribute__((used)) static int pl031_remove(struct amba_device *adev)
{
	struct pl031_local *ldata = dev_get_drvdata(&adev->dev);

	dev_pm_clear_wake_irq(&adev->dev);
	device_init_wakeup(&adev->dev, false);
	if (adev->irq[0])
		free_irq(adev->irq[0], ldata);
	rtc_device_unregister(ldata->rtc);
	amba_release_regions(adev);

	return 0;
}

__attribute__((used)) static int pl031_probe(struct amba_device *adev, const struct amba_id *id)
{
	int ret;
	struct pl031_local *ldata;
	struct pl031_vendor_data *vendor = id->data;
	struct rtc_class_ops *ops;
	unsigned long time, data;

	ret = amba_request_regions(adev, NULL);
	if (ret)
		goto err_req;

	ldata = devm_kzalloc(&adev->dev, sizeof(struct pl031_local),
			     GFP_KERNEL);
	ops = devm_kmemdup(&adev->dev, &vendor->ops, sizeof(vendor->ops),
			   GFP_KERNEL);
	if (!ldata || !ops) {
		ret = -ENOMEM;
		goto out;
	}

	ldata->vendor = vendor;
	ldata->base = devm_ioremap(&adev->dev, adev->res.start,
				   resource_size(&adev->res));
	if (!ldata->base) {
		ret = -ENOMEM;
		goto out;
	}

	amba_set_drvdata(adev, ldata);

	dev_dbg(&adev->dev, "designer ID = 0x%02x\n", amba_manf(adev));
	dev_dbg(&adev->dev, "revision = 0x%01x\n", amba_rev(adev));

	data = readl(ldata->base + RTC_CR);
	/* Enable the clockwatch on ST Variants */
	if (vendor->clockwatch)
		data |= RTC_CR_CWEN;
	else
		data |= RTC_CR_EN;
	writel(data, ldata->base + RTC_CR);

	/*
	 * On ST PL031 variants, the RTC reset value does not provide correct
	 * weekday for 2000-01-01. Correct the erroneous sunday to saturday.
	 */
	if (vendor->st_weekday) {
		if (readl(ldata->base + RTC_YDR) == 0x2000) {
			time = readl(ldata->base + RTC_DR);
			if ((time &
			     (RTC_MON_MASK | RTC_MDAY_MASK | RTC_WDAY_MASK))
			    == 0x02120000) {
				time = time | (0x7 << RTC_WDAY_SHIFT);
				writel(0x2000, ldata->base + RTC_YLR);
				writel(time, ldata->base + RTC_LR);
			}
		}
	}

	if (!adev->irq[0]) {
		/* When there's no interrupt, no point in exposing the alarm */
		ops->read_alarm = NULL;
		ops->set_alarm = NULL;
		ops->alarm_irq_enable = NULL;
	}

	device_init_wakeup(&adev->dev, true);
	ldata->rtc = rtc_device_register("pl031", &adev->dev, ops,
					THIS_MODULE);
	if (IS_ERR(ldata->rtc)) {
		ret = PTR_ERR(ldata->rtc);
		goto out;
	}

	if (adev->irq[0]) {
		ret = request_irq(adev->irq[0], pl031_interrupt,
				  vendor->irqflags, "rtc-pl031", ldata);
		if (ret)
			goto out_no_irq;
		dev_pm_set_wake_irq(&adev->dev, adev->irq[0]);
	}
	return 0;

out_no_irq:
	rtc_device_unregister(ldata->rtc);
out:
	amba_release_regions(adev);
err_req:

	return ret;
}

