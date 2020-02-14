#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
typedef  int u32 ;
struct TYPE_6__ {void* tm_year; void* tm_mon; void* tm_mday; void* tm_hour; void* tm_min; scalar_t__ tm_sec; } ;
struct rtc_wkalrm {int enabled; TYPE_1__ time; } ;
struct rtc_time {void* tm_year; void* tm_mon; void* tm_mday; void* tm_wday; void* tm_hour; void* tm_min; void* tm_sec; } ;
struct rc5t583_rtc {TYPE_2__* rtc; } ;
struct rc5t583_platform_data {int irq_base; } ;
struct rc5t583 {int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;
struct device {struct device* parent; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {struct device dev; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENOMEM ; 
 int GET_YAL_STATUS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (TYPE_2__*) ; 
 int NUM_TIME_REGS ; 
 int NUM_YAL_REGS ; 
 int PTR_ERR (TYPE_2__*) ; 
 scalar_t__ RC5T583_IRQ_YALE ; 
 int /*<<< orphan*/  RC5T583_RTC_ADJ ; 
 int /*<<< orphan*/  RC5T583_RTC_AY_MIN ; 
 int /*<<< orphan*/  RC5T583_RTC_CTL1 ; 
 int /*<<< orphan*/  RC5T583_RTC_CTL2 ; 
 int /*<<< orphan*/  RC5T583_RTC_SEC ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 int SET_YAL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (unsigned char) ; 
 unsigned char bin2bcd (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 struct rc5t583_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct rc5t583_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct device*) ; 
 TYPE_2__* devm_rtc_device_register (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct rc5t583_rtc* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rc5t583_rtc*) ; 
 int /*<<< orphan*/  rc5t583_rtc_ops ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_2__*,int,unsigned long) ; 

__attribute__((used)) static int rc5t583_rtc_alarm_irq_enable(struct device *dev, unsigned enabled)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	u8 val;

	/* Set Y-Alarm, based on 'enabled' */
	val = enabled ? SET_YAL : 0;

	return regmap_update_bits(rc5t583->regmap, RC5T583_RTC_CTL1, SET_YAL,
		val);
}

__attribute__((used)) static int rc5t583_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	u8 rtc_data[NUM_TIME_REGS];
	int ret;

	ret = regmap_bulk_read(rc5t583->regmap, RC5T583_RTC_SEC, rtc_data,
		NUM_TIME_REGS);
	if (ret < 0) {
		dev_err(dev, "RTC read time failed with err:%d\n", ret);
		return ret;
	}

	tm->tm_sec = bcd2bin(rtc_data[0]);
	tm->tm_min = bcd2bin(rtc_data[1]);
	tm->tm_hour = bcd2bin(rtc_data[2]);
	tm->tm_wday = bcd2bin(rtc_data[3]);
	tm->tm_mday = bcd2bin(rtc_data[4]);
	tm->tm_mon = bcd2bin(rtc_data[5]) - 1;
	tm->tm_year = bcd2bin(rtc_data[6]) + 100;

	return ret;
}

__attribute__((used)) static int rc5t583_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	unsigned char rtc_data[NUM_TIME_REGS];
	int ret;

	rtc_data[0] = bin2bcd(tm->tm_sec);
	rtc_data[1] = bin2bcd(tm->tm_min);
	rtc_data[2] = bin2bcd(tm->tm_hour);
	rtc_data[3] = bin2bcd(tm->tm_wday);
	rtc_data[4] = bin2bcd(tm->tm_mday);
	rtc_data[5] = bin2bcd(tm->tm_mon + 1);
	rtc_data[6] = bin2bcd(tm->tm_year - 100);

	ret = regmap_bulk_write(rc5t583->regmap, RC5T583_RTC_SEC, rtc_data,
		NUM_TIME_REGS);
	if (ret < 0) {
		dev_err(dev, "RTC set time failed with error %d\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int rc5t583_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	unsigned char alarm_data[NUM_YAL_REGS];
	u32 interrupt_enable;
	int ret;

	ret = regmap_bulk_read(rc5t583->regmap, RC5T583_RTC_AY_MIN, alarm_data,
		NUM_YAL_REGS);
	if (ret < 0) {
		dev_err(dev, "rtc_read_alarm error %d\n", ret);
		return ret;
	}

	alm->time.tm_sec = 0;
	alm->time.tm_min = bcd2bin(alarm_data[0]);
	alm->time.tm_hour = bcd2bin(alarm_data[1]);
	alm->time.tm_mday = bcd2bin(alarm_data[2]);
	alm->time.tm_mon = bcd2bin(alarm_data[3]) - 1;
	alm->time.tm_year = bcd2bin(alarm_data[4]) + 100;

	ret = regmap_read(rc5t583->regmap, RC5T583_RTC_CTL1, &interrupt_enable);
	if (ret < 0)
		return ret;

	/* check if YALE is set */
	if (interrupt_enable & SET_YAL)
		alm->enabled = 1;

	return ret;
}

__attribute__((used)) static int rc5t583_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	unsigned char alarm_data[NUM_YAL_REGS];
	int ret;

	ret = rc5t583_rtc_alarm_irq_enable(dev, 0);
	if (ret)
		return ret;

	alarm_data[0] = bin2bcd(alm->time.tm_min);
	alarm_data[1] = bin2bcd(alm->time.tm_hour);
	alarm_data[2] = bin2bcd(alm->time.tm_mday);
	alarm_data[3] = bin2bcd(alm->time.tm_mon + 1);
	alarm_data[4] = bin2bcd(alm->time.tm_year - 100);

	ret = regmap_bulk_write(rc5t583->regmap, RC5T583_RTC_AY_MIN, alarm_data,
		NUM_YAL_REGS);
	if (ret) {
		dev_err(dev, "rtc_set_alarm error %d\n", ret);
		return ret;
	}

	if (alm->enabled)
		ret = rc5t583_rtc_alarm_irq_enable(dev, 1);

	return ret;
}

__attribute__((used)) static irqreturn_t rc5t583_rtc_interrupt(int irq, void *rtc)
{
	struct device *dev = rtc;
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev->parent);
	struct rc5t583_rtc *rc5t583_rtc = dev_get_drvdata(dev);
	unsigned long events = 0;
	int ret;
	u32 rtc_reg;

	ret = regmap_read(rc5t583->regmap, RC5T583_RTC_CTL2, &rtc_reg);
	if (ret < 0)
		return IRQ_NONE;

	if (rtc_reg & GET_YAL_STATUS) {
		events = RTC_IRQF | RTC_AF;
		/* clear pending Y-alarm interrupt bit */
		rtc_reg &= ~GET_YAL_STATUS;
	}

	ret = regmap_write(rc5t583->regmap, RC5T583_RTC_CTL2, rtc_reg);
	if (ret)
		return IRQ_NONE;

	/* Notify RTC core on event */
	rtc_update_irq(rc5t583_rtc->rtc, 1, events);

	return IRQ_HANDLED;
}

__attribute__((used)) static int rc5t583_rtc_probe(struct platform_device *pdev)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(pdev->dev.parent);
	struct rc5t583_rtc *ricoh_rtc;
	struct rc5t583_platform_data *pmic_plat_data;
	int ret;
	int irq;

	ricoh_rtc = devm_kzalloc(&pdev->dev, sizeof(struct rc5t583_rtc),
			GFP_KERNEL);
	if (!ricoh_rtc)
		return -ENOMEM;

	platform_set_drvdata(pdev, ricoh_rtc);

	/* Clear pending interrupts */
	ret = regmap_write(rc5t583->regmap, RC5T583_RTC_CTL2, 0);
	if (ret < 0)
		return ret;

	/* clear RTC Adjust register */
	ret = regmap_write(rc5t583->regmap, RC5T583_RTC_ADJ, 0);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to program rtc_adjust reg\n");
		return -EBUSY;
	}

	pmic_plat_data = dev_get_platdata(rc5t583->dev);
	irq = pmic_plat_data->irq_base;
	if (irq <= 0) {
		dev_warn(&pdev->dev, "Wake up is not possible as irq = %d\n",
			irq);
		return ret;
	}

	irq += RC5T583_IRQ_YALE;
	ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
		rc5t583_rtc_interrupt, IRQF_TRIGGER_LOW,
		"rtc-rc5t583", &pdev->dev);
	if (ret < 0) {
		dev_err(&pdev->dev, "IRQ is not free.\n");
		return ret;
	}
	device_init_wakeup(&pdev->dev, 1);

	ricoh_rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
		&rc5t583_rtc_ops, THIS_MODULE);
	if (IS_ERR(ricoh_rtc->rtc)) {
		ret = PTR_ERR(ricoh_rtc->rtc);
		dev_err(&pdev->dev, "RTC device register: err %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int rc5t583_rtc_remove(struct platform_device *pdev)
{
	struct rc5t583_rtc *rc5t583_rtc = platform_get_drvdata(pdev);

	rc5t583_rtc_alarm_irq_enable(&rc5t583_rtc->rtc->dev, 0);
	return 0;
}

