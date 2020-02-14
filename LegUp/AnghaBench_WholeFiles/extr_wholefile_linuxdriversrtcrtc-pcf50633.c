#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_wkalrm {unsigned int enabled; int pending; struct rtc_time time; } ;
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct pcf50633_time {int* time; } ;
struct pcf50633_rtc {unsigned int alarm_enabled; int alarm_pending; int /*<<< orphan*/  pcf; int /*<<< orphan*/  rtc_dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCF50633_IRQ_ALARM ; 
 int /*<<< orphan*/  PCF50633_REG_RTCSC ; 
 int /*<<< orphan*/  PCF50633_REG_RTCSCA ; 
 size_t PCF50633_TI_DAY ; 
 int PCF50633_TI_EXTENT ; 
 size_t PCF50633_TI_HOUR ; 
 size_t PCF50633_TI_MIN ; 
 size_t PCF50633_TI_MONTH ; 
 size_t PCF50633_TI_SEC ; 
 size_t PCF50633_TI_WKDAY ; 
 size_t PCF50633_TI_YEAR ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 void* bin2bcd (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct pcf50633_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_to_pcf50633 (int /*<<< orphan*/ ) ; 
 struct pcf50633_rtc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_rtc_device_register (TYPE_1__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcf50633_free_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcf50633_irq_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcf50633_irq_mask_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcf50633_irq_unmask (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcf50633_read_block (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  pcf50633_register_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int,void*),struct pcf50633_rtc*) ; 
 int /*<<< orphan*/  pcf50633_rtc_ops ; 
 int pcf50633_write_block (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*) ; 
 struct pcf50633_rtc* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pcf50633_rtc*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int rtc_valid_tm (struct rtc_time*) ; 

__attribute__((used)) static void pcf2rtc_time(struct rtc_time *rtc, struct pcf50633_time *pcf)
{
	rtc->tm_sec = bcd2bin(pcf->time[PCF50633_TI_SEC]);
	rtc->tm_min = bcd2bin(pcf->time[PCF50633_TI_MIN]);
	rtc->tm_hour = bcd2bin(pcf->time[PCF50633_TI_HOUR]);
	rtc->tm_wday = bcd2bin(pcf->time[PCF50633_TI_WKDAY]);
	rtc->tm_mday = bcd2bin(pcf->time[PCF50633_TI_DAY]);
	rtc->tm_mon = bcd2bin(pcf->time[PCF50633_TI_MONTH]) - 1;
	rtc->tm_year = bcd2bin(pcf->time[PCF50633_TI_YEAR]) + 100;
}

__attribute__((used)) static void rtc2pcf_time(struct pcf50633_time *pcf, struct rtc_time *rtc)
{
	pcf->time[PCF50633_TI_SEC] = bin2bcd(rtc->tm_sec);
	pcf->time[PCF50633_TI_MIN] = bin2bcd(rtc->tm_min);
	pcf->time[PCF50633_TI_HOUR] = bin2bcd(rtc->tm_hour);
	pcf->time[PCF50633_TI_WKDAY] = bin2bcd(rtc->tm_wday);
	pcf->time[PCF50633_TI_DAY] = bin2bcd(rtc->tm_mday);
	pcf->time[PCF50633_TI_MONTH] = bin2bcd(rtc->tm_mon + 1);
	pcf->time[PCF50633_TI_YEAR] = bin2bcd(rtc->tm_year % 100);
}

__attribute__((used)) static int
pcf50633_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct pcf50633_rtc *rtc = dev_get_drvdata(dev);
	int err;

	if (enabled)
		err = pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);
	else
		err = pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);

	if (err < 0)
		return err;

	rtc->alarm_enabled = enabled;

	return 0;
}

__attribute__((used)) static int pcf50633_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct pcf50633_rtc *rtc;
	struct pcf50633_time pcf_tm;
	int ret;

	rtc = dev_get_drvdata(dev);

	ret = pcf50633_read_block(rtc->pcf, PCF50633_REG_RTCSC,
					    PCF50633_TI_EXTENT,
					    &pcf_tm.time[0]);
	if (ret != PCF50633_TI_EXTENT) {
		dev_err(dev, "Failed to read time\n");
		return -EIO;
	}

	dev_dbg(dev, "PCF_TIME: %02x.%02x.%02x %02x:%02x:%02x\n",
		pcf_tm.time[PCF50633_TI_DAY],
		pcf_tm.time[PCF50633_TI_MONTH],
		pcf_tm.time[PCF50633_TI_YEAR],
		pcf_tm.time[PCF50633_TI_HOUR],
		pcf_tm.time[PCF50633_TI_MIN],
		pcf_tm.time[PCF50633_TI_SEC]);

	pcf2rtc_time(tm, &pcf_tm);

	dev_dbg(dev, "RTC_TIME: %u.%u.%u %u:%u:%u\n",
		tm->tm_mday, tm->tm_mon, tm->tm_year,
		tm->tm_hour, tm->tm_min, tm->tm_sec);

	return 0;
}

__attribute__((used)) static int pcf50633_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct pcf50633_rtc *rtc;
	struct pcf50633_time pcf_tm;
	int alarm_masked, ret = 0;

	rtc = dev_get_drvdata(dev);

	dev_dbg(dev, "RTC_TIME: %u.%u.%u %u:%u:%u\n",
		tm->tm_mday, tm->tm_mon, tm->tm_year,
		tm->tm_hour, tm->tm_min, tm->tm_sec);

	rtc2pcf_time(&pcf_tm, tm);

	dev_dbg(dev, "PCF_TIME: %02x.%02x.%02x %02x:%02x:%02x\n",
		pcf_tm.time[PCF50633_TI_DAY],
		pcf_tm.time[PCF50633_TI_MONTH],
		pcf_tm.time[PCF50633_TI_YEAR],
		pcf_tm.time[PCF50633_TI_HOUR],
		pcf_tm.time[PCF50633_TI_MIN],
		pcf_tm.time[PCF50633_TI_SEC]);


	alarm_masked = pcf50633_irq_mask_get(rtc->pcf, PCF50633_IRQ_ALARM);

	if (!alarm_masked)
		pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);

	/* Returns 0 on success */
	ret = pcf50633_write_block(rtc->pcf, PCF50633_REG_RTCSC,
					     PCF50633_TI_EXTENT,
					     &pcf_tm.time[0]);

	if (!alarm_masked)
		pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);

	return ret;
}

__attribute__((used)) static int pcf50633_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pcf50633_rtc *rtc;
	struct pcf50633_time pcf_tm;
	int ret = 0;

	rtc = dev_get_drvdata(dev);

	alrm->enabled = rtc->alarm_enabled;
	alrm->pending = rtc->alarm_pending;

	ret = pcf50633_read_block(rtc->pcf, PCF50633_REG_RTCSCA,
				PCF50633_TI_EXTENT, &pcf_tm.time[0]);
	if (ret != PCF50633_TI_EXTENT) {
		dev_err(dev, "Failed to read time\n");
		return -EIO;
	}

	pcf2rtc_time(&alrm->time, &pcf_tm);

	return rtc_valid_tm(&alrm->time);
}

__attribute__((used)) static int pcf50633_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pcf50633_rtc *rtc;
	struct pcf50633_time pcf_tm;
	int alarm_masked, ret = 0;

	rtc = dev_get_drvdata(dev);

	rtc2pcf_time(&pcf_tm, &alrm->time);

	/* do like mktime does and ignore tm_wday */
	pcf_tm.time[PCF50633_TI_WKDAY] = 7;

	alarm_masked = pcf50633_irq_mask_get(rtc->pcf, PCF50633_IRQ_ALARM);

	/* disable alarm interrupt */
	if (!alarm_masked)
		pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);

	/* Returns 0 on success */
	ret = pcf50633_write_block(rtc->pcf, PCF50633_REG_RTCSCA,
				PCF50633_TI_EXTENT, &pcf_tm.time[0]);
	if (!alrm->enabled)
		rtc->alarm_pending = 0;

	if (!alarm_masked || alrm->enabled)
		pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);
	rtc->alarm_enabled = alrm->enabled;

	return ret;
}

__attribute__((used)) static void pcf50633_rtc_irq(int irq, void *data)
{
	struct pcf50633_rtc *rtc = data;

	rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);
	rtc->alarm_pending = 1;
}

__attribute__((used)) static int pcf50633_rtc_probe(struct platform_device *pdev)
{
	struct pcf50633_rtc *rtc;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->pcf = dev_to_pcf50633(pdev->dev.parent);
	platform_set_drvdata(pdev, rtc);
	rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, "pcf50633-rtc",
				&pcf50633_rtc_ops, THIS_MODULE);

	if (IS_ERR(rtc->rtc_dev))
		return PTR_ERR(rtc->rtc_dev);

	pcf50633_register_irq(rtc->pcf, PCF50633_IRQ_ALARM,
					pcf50633_rtc_irq, rtc);
	return 0;
}

__attribute__((used)) static int pcf50633_rtc_remove(struct platform_device *pdev)
{
	struct pcf50633_rtc *rtc;

	rtc = platform_get_drvdata(pdev);
	pcf50633_free_irq(rtc->pcf, PCF50633_IRQ_ALARM);

	return 0;
}

