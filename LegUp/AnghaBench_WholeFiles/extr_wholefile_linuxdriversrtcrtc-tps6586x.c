#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u8 ;
typedef  unsigned long time64_t ;
struct tps6586x_rtc {int irq_en; TYPE_1__* rtc; int /*<<< orphan*/  irq; struct device* dev; } ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {unsigned int enabled; struct rtc_time time; } ;
struct device {struct device* parent; } ;
struct platform_device {struct device dev; } ;
typedef  int /*<<< orphan*/  rbuff ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  buff ;
struct TYPE_6__ {unsigned long long range_max; int set_start_time; int /*<<< orphan*/  start_secs; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 unsigned long ALM1_VALID_RANGE_IN_SEC ; 
 int CL_SEL_MASK ; 
 int CL_SEL_POS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (TYPE_1__*) ; 
 int OSC_SRC_SEL ; 
 int PRE_BYPASS ; 
 int PTR_ERR (TYPE_1__*) ; 
 int RTC_AF ; 
 int /*<<< orphan*/  RTC_ALARM1_HI ; 
 int /*<<< orphan*/  RTC_COUNT4 ; 
 int /*<<< orphan*/  RTC_COUNT4_DUMMYREAD ; 
 int /*<<< orphan*/  RTC_CTRL ; 
 int RTC_ENABLE ; 
 int RTC_IRQF ; 
 int TPS6586X_RTC_CL_SEL_1_5PF ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct tps6586x_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct tps6586x_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct tps6586x_rtc*) ; 
 TYPE_1__* devm_rtc_allocate_device (struct device*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mktime64 (int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps6586x_rtc*) ; 
 int rtc_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (unsigned long,struct rtc_time*) ; 
 unsigned long rtc_tm_to_time64 (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_1__*,int,int) ; 
 int tps6586x_clr_bits (struct device*,int /*<<< orphan*/ ,int) ; 
 int tps6586x_reads (struct device*,int /*<<< orphan*/ ,int,unsigned long long*) ; 
 int /*<<< orphan*/  tps6586x_rtc_ops ; 
 int tps6586x_set_bits (struct device*,int /*<<< orphan*/ ,int) ; 
 int tps6586x_update (struct device*,int /*<<< orphan*/ ,int,int) ; 
 int tps6586x_writes (struct device*,int /*<<< orphan*/ ,int,unsigned long long*) ; 

__attribute__((used)) static inline struct device *to_tps6586x_dev(struct device *dev)
{
	return dev->parent;
}

__attribute__((used)) static int tps6586x_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct device *tps_dev = to_tps6586x_dev(dev);
	unsigned long long ticks = 0;
	time64_t seconds;
	u8 buff[6];
	int ret;
	int i;

	ret = tps6586x_reads(tps_dev, RTC_COUNT4_DUMMYREAD, sizeof(buff), buff);
	if (ret < 0) {
		dev_err(dev, "read counter failed with err %d\n", ret);
		return ret;
	}

	for (i = 1; i < sizeof(buff); i++) {
		ticks <<= 8;
		ticks |= buff[i];
	}

	seconds = ticks >> 10;
	rtc_time64_to_tm(seconds, tm);

	return 0;
}

__attribute__((used)) static int tps6586x_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct device *tps_dev = to_tps6586x_dev(dev);
	unsigned long long ticks;
	time64_t seconds;
	u8 buff[5];
	int ret;

	seconds = rtc_tm_to_time64(tm);

	ticks = (unsigned long long)seconds << 10;
	buff[0] = (ticks >> 32) & 0xff;
	buff[1] = (ticks >> 24) & 0xff;
	buff[2] = (ticks >> 16) & 0xff;
	buff[3] = (ticks >> 8) & 0xff;
	buff[4] = ticks & 0xff;

	/* Disable RTC before changing time */
	ret = tps6586x_clr_bits(tps_dev, RTC_CTRL, RTC_ENABLE);
	if (ret < 0) {
		dev_err(dev, "failed to clear RTC_ENABLE\n");
		return ret;
	}

	ret = tps6586x_writes(tps_dev, RTC_COUNT4, sizeof(buff), buff);
	if (ret < 0) {
		dev_err(dev, "failed to program new time\n");
		return ret;
	}

	/* Enable RTC */
	ret = tps6586x_set_bits(tps_dev, RTC_CTRL, RTC_ENABLE);
	if (ret < 0) {
		dev_err(dev, "failed to set RTC_ENABLE\n");
		return ret;
	}
	return 0;
}

__attribute__((used)) static int tps6586x_rtc_alarm_irq_enable(struct device *dev,
			 unsigned int enabled)
{
	struct tps6586x_rtc *rtc = dev_get_drvdata(dev);

	if (enabled && !rtc->irq_en) {
		enable_irq(rtc->irq);
		rtc->irq_en = true;
	} else if (!enabled && rtc->irq_en)  {
		disable_irq(rtc->irq);
		rtc->irq_en = false;
	}
	return 0;
}

__attribute__((used)) static int tps6586x_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct device *tps_dev = to_tps6586x_dev(dev);
	time64_t seconds;
	unsigned long ticks;
	unsigned long rtc_current_time;
	unsigned long long rticks = 0;
	u8 buff[3];
	u8 rbuff[6];
	int ret;
	int i;

	seconds = rtc_tm_to_time64(&alrm->time);

	ret = tps6586x_rtc_alarm_irq_enable(dev, alrm->enabled);
	if (ret < 0) {
		dev_err(dev, "can't set alarm irq, err %d\n", ret);
		return ret;
	}

	ret = tps6586x_reads(tps_dev, RTC_COUNT4_DUMMYREAD,
			sizeof(rbuff), rbuff);
	if (ret < 0) {
		dev_err(dev, "read counter failed with err %d\n", ret);
		return ret;
	}

	for (i = 1; i < sizeof(rbuff); i++) {
		rticks <<= 8;
		rticks |= rbuff[i];
	}

	rtc_current_time = rticks >> 10;
	if ((seconds - rtc_current_time) > ALM1_VALID_RANGE_IN_SEC)
		seconds = rtc_current_time - 1;

	ticks = (unsigned long long)seconds << 10;
	buff[0] = (ticks >> 16) & 0xff;
	buff[1] = (ticks >> 8) & 0xff;
	buff[2] = ticks & 0xff;

	ret = tps6586x_writes(tps_dev, RTC_ALARM1_HI, sizeof(buff), buff);
	if (ret)
		dev_err(dev, "programming alarm failed with err %d\n", ret);

	return ret;
}

__attribute__((used)) static int tps6586x_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct device *tps_dev = to_tps6586x_dev(dev);
	unsigned long ticks;
	time64_t seconds;
	u8 buff[3];
	int ret;

	ret = tps6586x_reads(tps_dev, RTC_ALARM1_HI, sizeof(buff), buff);
	if (ret) {
		dev_err(dev, "read RTC_ALARM1_HI failed with err %d\n", ret);
		return ret;
	}

	ticks = (buff[0] << 16) | (buff[1] << 8) | buff[2];
	seconds = ticks >> 10;

	rtc_time64_to_tm(seconds, &alrm->time);
	return 0;
}

__attribute__((used)) static irqreturn_t tps6586x_rtc_irq(int irq, void *data)
{
	struct tps6586x_rtc *rtc = data;

	rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
	return IRQ_HANDLED;
}

__attribute__((used)) static int tps6586x_rtc_probe(struct platform_device *pdev)
{
	struct device *tps_dev = to_tps6586x_dev(&pdev->dev);
	struct tps6586x_rtc *rtc;
	int ret;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->dev = &pdev->dev;
	rtc->irq = platform_get_irq(pdev, 0);

	/* 1 kHz tick mode, enable tick counting */
	ret = tps6586x_update(tps_dev, RTC_CTRL,
		RTC_ENABLE | OSC_SRC_SEL |
		((TPS6586X_RTC_CL_SEL_1_5PF << CL_SEL_POS) & CL_SEL_MASK),
		RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to start counter\n");
		return ret;
	}

	device_init_wakeup(&pdev->dev, 1);

	platform_set_drvdata(pdev, rtc);
	rtc->rtc = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(rtc->rtc)) {
		ret = PTR_ERR(rtc->rtc);
		dev_err(&pdev->dev, "RTC allocate device: ret %d\n", ret);
		goto fail_rtc_register;
	}

	rtc->rtc->ops = &tps6586x_rtc_ops;
	rtc->rtc->range_max = (1ULL << 30) - 1; /* 30-bit seconds */
	rtc->rtc->start_secs = mktime64(2009, 1, 1, 0, 0, 0);
	rtc->rtc->set_start_time = true;

	ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
				tps6586x_rtc_irq,
				IRQF_ONESHOT,
				dev_name(&pdev->dev), rtc);
	if (ret < 0) {
		dev_err(&pdev->dev, "request IRQ(%d) failed with ret %d\n",
				rtc->irq, ret);
		goto fail_rtc_register;
	}
	disable_irq(rtc->irq);

	ret = rtc_register_device(rtc->rtc);
	if (ret) {
		dev_err(&pdev->dev, "RTC device register: ret %d\n", ret);
		goto fail_rtc_register;
	}

	return 0;

fail_rtc_register:
	tps6586x_update(tps_dev, RTC_CTRL, 0,
		RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
	return ret;
}

__attribute__((used)) static int tps6586x_rtc_remove(struct platform_device *pdev)
{
	struct device *tps_dev = to_tps6586x_dev(&pdev->dev);

	tps6586x_update(tps_dev, RTC_CTRL, 0,
		RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
	return 0;
}

