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
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {struct rtc_time time; } ;
struct pl030_rtc {scalar_t__ base; int /*<<< orphan*/  rtc; } ;
struct device {int dummy; } ;
struct amba_id {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  start; } ;
struct amba_device {int /*<<< orphan*/ * irq; int /*<<< orphan*/  dev; TYPE_1__ res; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ RTC_CR ; 
 scalar_t__ RTC_DR ; 
 scalar_t__ RTC_EOI ; 
 scalar_t__ RTC_LR ; 
 scalar_t__ RTC_MR ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,scalar_t__) ; 
 struct pl030_rtc* amba_get_drvdata (struct amba_device*) ; 
 int /*<<< orphan*/  amba_release_regions (struct amba_device*) ; 
 int amba_request_regions (struct amba_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  amba_set_drvdata (struct amba_device*,struct pl030_rtc*) ; 
 struct pl030_rtc* dev_get_drvdata (struct device*) ; 
 struct pl030_rtc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct pl030_rtc*) ; 
 scalar_t__ ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  pl030_ops ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct pl030_rtc*) ; 
 int /*<<< orphan*/  resource_size (TYPE_1__*) ; 
 int /*<<< orphan*/  rtc_device_register (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_device_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_time_to_tm (int /*<<< orphan*/ ,struct rtc_time*) ; 
 int rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int rtc_valid_tm (struct rtc_time*) ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static irqreturn_t pl030_interrupt(int irq, void *dev_id)
{
	struct pl030_rtc *rtc = dev_id;
	writel(0, rtc->base + RTC_EOI);
	return IRQ_HANDLED;
}

__attribute__((used)) static int pl030_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pl030_rtc *rtc = dev_get_drvdata(dev);

	rtc_time_to_tm(readl(rtc->base + RTC_MR), &alrm->time);
	return 0;
}

__attribute__((used)) static int pl030_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pl030_rtc *rtc = dev_get_drvdata(dev);
	unsigned long time;
	int ret;

	/*
	 * At the moment, we can only deal with non-wildcarded alarm times.
	 */
	ret = rtc_valid_tm(&alrm->time);
	if (ret == 0)
		ret = rtc_tm_to_time(&alrm->time, &time);
	if (ret == 0)
		writel(time, rtc->base + RTC_MR);
	return ret;
}

__attribute__((used)) static int pl030_read_time(struct device *dev, struct rtc_time *tm)
{
	struct pl030_rtc *rtc = dev_get_drvdata(dev);

	rtc_time_to_tm(readl(rtc->base + RTC_DR), tm);

	return 0;
}

__attribute__((used)) static int pl030_set_time(struct device *dev, struct rtc_time *tm)
{
	struct pl030_rtc *rtc = dev_get_drvdata(dev);
	unsigned long time;
	int ret;

	ret = rtc_tm_to_time(tm, &time);
	if (ret == 0)
		writel(time + 1, rtc->base + RTC_LR);

	return ret;
}

__attribute__((used)) static int pl030_probe(struct amba_device *dev, const struct amba_id *id)
{
	struct pl030_rtc *rtc;
	int ret;

	ret = amba_request_regions(dev, NULL);
	if (ret)
		goto err_req;

	rtc = devm_kzalloc(&dev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc) {
		ret = -ENOMEM;
		goto err_rtc;
	}

	rtc->base = ioremap(dev->res.start, resource_size(&dev->res));
	if (!rtc->base) {
		ret = -ENOMEM;
		goto err_rtc;
	}

	__raw_writel(0, rtc->base + RTC_CR);
	__raw_writel(0, rtc->base + RTC_EOI);

	amba_set_drvdata(dev, rtc);

	ret = request_irq(dev->irq[0], pl030_interrupt, 0,
			  "rtc-pl030", rtc);
	if (ret)
		goto err_irq;

	rtc->rtc = rtc_device_register("pl030", &dev->dev, &pl030_ops,
				       THIS_MODULE);
	if (IS_ERR(rtc->rtc)) {
		ret = PTR_ERR(rtc->rtc);
		goto err_reg;
	}

	return 0;

 err_reg:
	free_irq(dev->irq[0], rtc);
 err_irq:
	iounmap(rtc->base);
 err_rtc:
	amba_release_regions(dev);
 err_req:
	return ret;
}

__attribute__((used)) static int pl030_remove(struct amba_device *dev)
{
	struct pl030_rtc *rtc = amba_get_drvdata(dev);

	writel(0, rtc->base + RTC_CR);

	free_irq(dev->irq[0], rtc);
	rtc_device_unregister(rtc->rtc);
	iounmap(rtc->base);
	amba_release_regions(dev);

	return 0;
}

