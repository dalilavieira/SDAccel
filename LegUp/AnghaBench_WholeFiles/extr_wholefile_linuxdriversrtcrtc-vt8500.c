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
typedef  int u32 ;
struct vt8500_rtc {int irq_alarm; scalar_t__ regbase; scalar_t__ rtc; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int tm_mday; int tm_hour; int tm_min; int tm_sec; } ;
struct rtc_wkalrm {int enabled; int pending; TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ALARM_DAY_MASK ; 
 int ALARM_DAY_S ; 
 int ALARM_ENABLE_MASK ; 
 int DATE_CENTURY_S ; 
 int DATE_DAY_MASK ; 
 int DATE_MONTH_MASK ; 
 int DATE_MONTH_S ; 
 int DATE_YEAR_MASK ; 
 int DATE_YEAR_S ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int TIME_DOW_MASK ; 
 int TIME_DOW_S ; 
 int TIME_HOUR_MASK ; 
 int TIME_HOUR_S ; 
 int TIME_MIN_MASK ; 
 int TIME_MIN_S ; 
 int TIME_SEC_MASK ; 
 scalar_t__ VT8500_RTC_AS ; 
 scalar_t__ VT8500_RTC_CR ; 
 unsigned long VT8500_RTC_CR_ENABLE ; 
 scalar_t__ VT8500_RTC_DR ; 
 scalar_t__ VT8500_RTC_DS ; 
 scalar_t__ VT8500_RTC_IS ; 
 int VT8500_RTC_IS_ALARM ; 
 scalar_t__ VT8500_RTC_TR ; 
 scalar_t__ VT8500_RTC_TS ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct vt8500_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct vt8500_rtc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct vt8500_rtc*) ; 
 scalar_t__ devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct vt8500_rtc* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct vt8500_rtc*) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  rtc_update_irq (scalar_t__,int,unsigned long) ; 
 int rtc_valid_tm (TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vt8500_rtc_ops ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static irqreturn_t vt8500_rtc_irq(int irq, void *dev_id)
{
	struct vt8500_rtc *vt8500_rtc = dev_id;
	u32 isr;
	unsigned long events = 0;

	spin_lock(&vt8500_rtc->lock);

	/* clear interrupt sources */
	isr = readl(vt8500_rtc->regbase + VT8500_RTC_IS);
	writel(isr, vt8500_rtc->regbase + VT8500_RTC_IS);

	spin_unlock(&vt8500_rtc->lock);

	if (isr & VT8500_RTC_IS_ALARM)
		events |= RTC_AF | RTC_IRQF;

	rtc_update_irq(vt8500_rtc->rtc, 1, events);

	return IRQ_HANDLED;
}

__attribute__((used)) static int vt8500_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
	u32 date, time;

	date = readl(vt8500_rtc->regbase + VT8500_RTC_DR);
	time = readl(vt8500_rtc->regbase + VT8500_RTC_TR);

	tm->tm_sec = bcd2bin(time & TIME_SEC_MASK);
	tm->tm_min = bcd2bin((time & TIME_MIN_MASK) >> TIME_MIN_S);
	tm->tm_hour = bcd2bin((time & TIME_HOUR_MASK) >> TIME_HOUR_S);
	tm->tm_mday = bcd2bin(date & DATE_DAY_MASK);
	tm->tm_mon = bcd2bin((date & DATE_MONTH_MASK) >> DATE_MONTH_S) - 1;
	tm->tm_year = bcd2bin((date & DATE_YEAR_MASK) >> DATE_YEAR_S)
			+ ((date >> DATE_CENTURY_S) & 1 ? 200 : 100);
	tm->tm_wday = (time & TIME_DOW_MASK) >> TIME_DOW_S;

	return 0;
}

__attribute__((used)) static int vt8500_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);

	if (tm->tm_year < 100) {
		dev_warn(dev, "Only years 2000-2199 are supported by the "
			      "hardware!\n");
		return -EINVAL;
	}

	writel((bin2bcd(tm->tm_year % 100) << DATE_YEAR_S)
		| (bin2bcd(tm->tm_mon + 1) << DATE_MONTH_S)
		| (bin2bcd(tm->tm_mday))
		| ((tm->tm_year >= 200) << DATE_CENTURY_S),
		vt8500_rtc->regbase + VT8500_RTC_DS);
	writel((bin2bcd(tm->tm_wday) << TIME_DOW_S)
		| (bin2bcd(tm->tm_hour) << TIME_HOUR_S)
		| (bin2bcd(tm->tm_min) << TIME_MIN_S)
		| (bin2bcd(tm->tm_sec)),
		vt8500_rtc->regbase + VT8500_RTC_TS);

	return 0;
}

__attribute__((used)) static int vt8500_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
	u32 isr, alarm;

	alarm = readl(vt8500_rtc->regbase + VT8500_RTC_AS);
	isr = readl(vt8500_rtc->regbase + VT8500_RTC_IS);

	alrm->time.tm_mday = bcd2bin((alarm & ALARM_DAY_MASK) >> ALARM_DAY_S);
	alrm->time.tm_hour = bcd2bin((alarm & TIME_HOUR_MASK) >> TIME_HOUR_S);
	alrm->time.tm_min = bcd2bin((alarm & TIME_MIN_MASK) >> TIME_MIN_S);
	alrm->time.tm_sec = bcd2bin((alarm & TIME_SEC_MASK));

	alrm->enabled = (alarm & ALARM_ENABLE_MASK) ? 1 : 0;
	alrm->pending = (isr & VT8500_RTC_IS_ALARM) ? 1 : 0;

	return rtc_valid_tm(&alrm->time);
}

__attribute__((used)) static int vt8500_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);

	writel((alrm->enabled ? ALARM_ENABLE_MASK : 0)
		| (bin2bcd(alrm->time.tm_mday) << ALARM_DAY_S)
		| (bin2bcd(alrm->time.tm_hour) << TIME_HOUR_S)
		| (bin2bcd(alrm->time.tm_min) << TIME_MIN_S)
		| (bin2bcd(alrm->time.tm_sec)),
		vt8500_rtc->regbase + VT8500_RTC_AS);

	return 0;
}

__attribute__((used)) static int vt8500_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
	unsigned long tmp = readl(vt8500_rtc->regbase + VT8500_RTC_AS);

	if (enabled)
		tmp |= ALARM_ENABLE_MASK;
	else
		tmp &= ~ALARM_ENABLE_MASK;

	writel(tmp, vt8500_rtc->regbase + VT8500_RTC_AS);
	return 0;
}

__attribute__((used)) static int vt8500_rtc_probe(struct platform_device *pdev)
{
	struct vt8500_rtc *vt8500_rtc;
	struct resource	*res;
	int ret;

	vt8500_rtc = devm_kzalloc(&pdev->dev,
			   sizeof(struct vt8500_rtc), GFP_KERNEL);
	if (!vt8500_rtc)
		return -ENOMEM;

	spin_lock_init(&vt8500_rtc->lock);
	platform_set_drvdata(pdev, vt8500_rtc);

	vt8500_rtc->irq_alarm = platform_get_irq(pdev, 0);
	if (vt8500_rtc->irq_alarm < 0) {
		dev_err(&pdev->dev, "No alarm IRQ resource defined\n");
		return vt8500_rtc->irq_alarm;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	vt8500_rtc->regbase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(vt8500_rtc->regbase))
		return PTR_ERR(vt8500_rtc->regbase);

	/* Enable RTC and set it to 24-hour mode */
	writel(VT8500_RTC_CR_ENABLE,
	       vt8500_rtc->regbase + VT8500_RTC_CR);

	vt8500_rtc->rtc = devm_rtc_device_register(&pdev->dev, "vt8500-rtc",
					      &vt8500_rtc_ops, THIS_MODULE);
	if (IS_ERR(vt8500_rtc->rtc)) {
		ret = PTR_ERR(vt8500_rtc->rtc);
		dev_err(&pdev->dev,
			"Failed to register RTC device -> %d\n", ret);
		goto err_return;
	}

	ret = devm_request_irq(&pdev->dev, vt8500_rtc->irq_alarm,
				vt8500_rtc_irq, 0, "rtc alarm", vt8500_rtc);
	if (ret < 0) {
		dev_err(&pdev->dev, "can't get irq %i, err %d\n",
			vt8500_rtc->irq_alarm, ret);
		goto err_return;
	}

	return 0;

err_return:
	return ret;
}

__attribute__((used)) static int vt8500_rtc_remove(struct platform_device *pdev)
{
	struct vt8500_rtc *vt8500_rtc = platform_get_drvdata(pdev);

	/* Disable alarm matching */
	writel(0, vt8500_rtc->regbase + VT8500_RTC_IS);

	return 0;
}

