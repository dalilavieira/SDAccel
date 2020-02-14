#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct tps65910_rtc {int irq; TYPE_2__* rtc; } ;
struct tps65910 {int /*<<< orphan*/  regmap; } ;
struct TYPE_7__ {void* tm_year; void* tm_mon; void* tm_mday; void* tm_hour; void* tm_min; void* tm_sec; } ;
struct rtc_wkalrm {int enabled; TYPE_1__ time; } ;
struct rtc_time {void* tm_year; void* tm_mon; void* tm_mday; void* tm_hour; void* tm_min; void* tm_sec; } ;
struct device {struct device* parent; } ;
struct platform_device {struct device dev; } ;
typedef  int s64 ;
typedef  int s16 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_8__ {int /*<<< orphan*/  range_max; int /*<<< orphan*/  range_min; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 unsigned int DEVCTRL_RTC_PWDN_MASK ; 
 unsigned int DEVCTRL_RTC_PWDN_SHIFT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (TYPE_2__*) ; 
 long MAX_OFFSET ; 
 long MIN_OFFSET ; 
 int NUM_COMP_REGS ; 
 int NUM_TIME_REGS ; 
 long long PPB_MULT ; 
 int PTR_ERR (TYPE_2__*) ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 int /*<<< orphan*/  RTC_TIMESTAMP_BEGIN_2000 ; 
 int /*<<< orphan*/  RTC_TIMESTAMP_END_2099 ; 
 long long TICKS_PER_HOUR ; 
 int /*<<< orphan*/  TPS65910_ALARM_SECONDS ; 
 int /*<<< orphan*/  TPS65910_DEVCTRL ; 
 int /*<<< orphan*/  TPS65910_RTC_COMP_LSB ; 
 int /*<<< orphan*/  TPS65910_RTC_CTRL ; 
 unsigned int TPS65910_RTC_CTRL_AUTO_COMP ; 
 unsigned int TPS65910_RTC_CTRL_GET_TIME ; 
 unsigned int TPS65910_RTC_CTRL_STOP_RTC ; 
 int /*<<< orphan*/  TPS65910_RTC_INTERRUPTS ; 
 int TPS65910_RTC_INTERRUPTS_IT_ALARM ; 
 int /*<<< orphan*/  TPS65910_RTC_STATUS ; 
 int TPS65910_RTC_STATUS_ALARM ; 
 int /*<<< orphan*/  TPS65910_SECONDS ; 
 void* bcd2bin (unsigned char) ; 
 unsigned char bin2bcd (void*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (struct device*,int) ; 
 struct tps65910_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct device*) ; 
 TYPE_2__* devm_rtc_allocate_device (struct device*) ; 
 int div_s64 (int,long long) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65910_rtc*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int rtc_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_2__*,int,unsigned long) ; 
 int /*<<< orphan*/  tps65910_rtc_ops ; 

__attribute__((used)) static int tps65910_rtc_alarm_irq_enable(struct device *dev,
					 unsigned int enabled)
{
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	u8 val = 0;

	if (enabled)
		val = TPS65910_RTC_INTERRUPTS_IT_ALARM;

	return regmap_write(tps->regmap, TPS65910_RTC_INTERRUPTS, val);
}

__attribute__((used)) static int tps65910_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	unsigned char rtc_data[NUM_TIME_REGS];
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	int ret;

	/* Copy RTC counting registers to static registers or latches */
	ret = regmap_update_bits(tps->regmap, TPS65910_RTC_CTRL,
		TPS65910_RTC_CTRL_GET_TIME, TPS65910_RTC_CTRL_GET_TIME);
	if (ret < 0) {
		dev_err(dev, "RTC CTRL reg update failed with err:%d\n", ret);
		return ret;
	}

	ret = regmap_bulk_read(tps->regmap, TPS65910_SECONDS, rtc_data,
		NUM_TIME_REGS);
	if (ret < 0) {
		dev_err(dev, "reading from RTC failed with err:%d\n", ret);
		return ret;
	}

	tm->tm_sec = bcd2bin(rtc_data[0]);
	tm->tm_min = bcd2bin(rtc_data[1]);
	tm->tm_hour = bcd2bin(rtc_data[2]);
	tm->tm_mday = bcd2bin(rtc_data[3]);
	tm->tm_mon = bcd2bin(rtc_data[4]) - 1;
	tm->tm_year = bcd2bin(rtc_data[5]) + 100;

	return ret;
}

__attribute__((used)) static int tps65910_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	unsigned char rtc_data[NUM_TIME_REGS];
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	int ret;

	rtc_data[0] = bin2bcd(tm->tm_sec);
	rtc_data[1] = bin2bcd(tm->tm_min);
	rtc_data[2] = bin2bcd(tm->tm_hour);
	rtc_data[3] = bin2bcd(tm->tm_mday);
	rtc_data[4] = bin2bcd(tm->tm_mon + 1);
	rtc_data[5] = bin2bcd(tm->tm_year - 100);

	/* Stop RTC while updating the RTC time registers */
	ret = regmap_update_bits(tps->regmap, TPS65910_RTC_CTRL,
		TPS65910_RTC_CTRL_STOP_RTC, 0);
	if (ret < 0) {
		dev_err(dev, "RTC stop failed with err:%d\n", ret);
		return ret;
	}

	/* update all the time registers in one shot */
	ret = regmap_bulk_write(tps->regmap, TPS65910_SECONDS, rtc_data,
		NUM_TIME_REGS);
	if (ret < 0) {
		dev_err(dev, "rtc_set_time error %d\n", ret);
		return ret;
	}

	/* Start back RTC */
	ret = regmap_update_bits(tps->regmap, TPS65910_RTC_CTRL,
		TPS65910_RTC_CTRL_STOP_RTC, 1);
	if (ret < 0)
		dev_err(dev, "RTC start failed with err:%d\n", ret);

	return ret;
}

__attribute__((used)) static int tps65910_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	unsigned char alarm_data[NUM_TIME_REGS];
	u32 int_val;
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	int ret;

	ret = regmap_bulk_read(tps->regmap, TPS65910_SECONDS, alarm_data,
		NUM_TIME_REGS);
	if (ret < 0) {
		dev_err(dev, "rtc_read_alarm error %d\n", ret);
		return ret;
	}

	alm->time.tm_sec = bcd2bin(alarm_data[0]);
	alm->time.tm_min = bcd2bin(alarm_data[1]);
	alm->time.tm_hour = bcd2bin(alarm_data[2]);
	alm->time.tm_mday = bcd2bin(alarm_data[3]);
	alm->time.tm_mon = bcd2bin(alarm_data[4]) - 1;
	alm->time.tm_year = bcd2bin(alarm_data[5]) + 100;

	ret = regmap_read(tps->regmap, TPS65910_RTC_INTERRUPTS, &int_val);
	if (ret < 0)
		return ret;

	if (int_val & TPS65910_RTC_INTERRUPTS_IT_ALARM)
		alm->enabled = 1;

	return ret;
}

__attribute__((used)) static int tps65910_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	unsigned char alarm_data[NUM_TIME_REGS];
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	int ret;

	ret = tps65910_rtc_alarm_irq_enable(dev, 0);
	if (ret)
		return ret;

	alarm_data[0] = bin2bcd(alm->time.tm_sec);
	alarm_data[1] = bin2bcd(alm->time.tm_min);
	alarm_data[2] = bin2bcd(alm->time.tm_hour);
	alarm_data[3] = bin2bcd(alm->time.tm_mday);
	alarm_data[4] = bin2bcd(alm->time.tm_mon + 1);
	alarm_data[5] = bin2bcd(alm->time.tm_year - 100);

	/* update all the alarm registers in one shot */
	ret = regmap_bulk_write(tps->regmap, TPS65910_ALARM_SECONDS,
		alarm_data, NUM_TIME_REGS);
	if (ret) {
		dev_err(dev, "rtc_set_alarm error %d\n", ret);
		return ret;
	}

	if (alm->enabled)
		ret = tps65910_rtc_alarm_irq_enable(dev, 1);

	return ret;
}

__attribute__((used)) static int tps65910_rtc_set_calibration(struct device *dev, int calibration)
{
	unsigned char comp_data[NUM_COMP_REGS];
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	s16 value;
	int ret;

	/*
	 * TPS65910 uses two's complement 16 bit value for compensation for RTC
	 * crystal inaccuracies. One time every hour when seconds counter
	 * increments from 0 to 1 compensation value will be added to internal
	 * RTC counter value.
	 *
	 * Compensation value 0x7FFF is prohibited value.
	 *
	 * Valid range for compensation value: [-32768 .. 32766]
	 */
	if ((calibration < -32768) || (calibration > 32766)) {
		dev_err(dev, "RTC calibration value out of range: %d\n",
			calibration);
		return -EINVAL;
	}

	value = (s16)calibration;

	comp_data[0] = (u16)value & 0xFF;
	comp_data[1] = ((u16)value >> 8) & 0xFF;

	/* Update all the compensation registers in one shot */
	ret = regmap_bulk_write(tps->regmap, TPS65910_RTC_COMP_LSB,
		comp_data, NUM_COMP_REGS);
	if (ret < 0) {
		dev_err(dev, "rtc_set_calibration error: %d\n", ret);
		return ret;
	}

	/* Enable automatic compensation */
	ret = regmap_update_bits(tps->regmap, TPS65910_RTC_CTRL,
		TPS65910_RTC_CTRL_AUTO_COMP, TPS65910_RTC_CTRL_AUTO_COMP);
	if (ret < 0)
		dev_err(dev, "auto_comp enable failed with error: %d\n", ret);

	return ret;
}

__attribute__((used)) static int tps65910_rtc_get_calibration(struct device *dev, int *calibration)
{
	unsigned char comp_data[NUM_COMP_REGS];
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	unsigned int ctrl;
	u16 value;
	int ret;

	ret = regmap_read(tps->regmap, TPS65910_RTC_CTRL, &ctrl);
	if (ret < 0)
		return ret;

	/* If automatic compensation is not enabled report back zero */
	if (!(ctrl & TPS65910_RTC_CTRL_AUTO_COMP)) {
		*calibration = 0;
		return 0;
	}

	ret = regmap_bulk_read(tps->regmap, TPS65910_RTC_COMP_LSB, comp_data,
		NUM_COMP_REGS);
	if (ret < 0) {
		dev_err(dev, "rtc_get_calibration error: %d\n", ret);
		return ret;
	}

	value = (u16)comp_data[0] | ((u16)comp_data[1] << 8);

	*calibration = (s16)value;

	return 0;
}

__attribute__((used)) static int tps65910_read_offset(struct device *dev, long *offset)
{
	int calibration;
	s64 tmp;
	int ret;

	ret = tps65910_rtc_get_calibration(dev, &calibration);
	if (ret < 0)
		return ret;

	/* Convert from RTC calibration register format to ppb format */
	tmp = calibration * (s64)PPB_MULT;
	if (tmp < 0)
		tmp -= TICKS_PER_HOUR / 2LL;
	else
		tmp += TICKS_PER_HOUR / 2LL;
	tmp = div_s64(tmp, TICKS_PER_HOUR);

	/* Offset value operates in negative way, so swap sign */
	*offset = (long)-tmp;

	return 0;
}

__attribute__((used)) static int tps65910_set_offset(struct device *dev, long offset)
{
	int calibration;
	s64 tmp;
	int ret;

	/* Make sure offset value is within supported range */
	if (offset < MIN_OFFSET || offset > MAX_OFFSET)
		return -ERANGE;

	/* Convert from ppb format to RTC calibration register format */
	tmp = offset * (s64)TICKS_PER_HOUR;
	if (tmp < 0)
		tmp -= PPB_MULT / 2LL;
	else
		tmp += PPB_MULT / 2LL;
	tmp = div_s64(tmp, PPB_MULT);

	/* Offset value operates in negative way, so swap sign */
	calibration = (int)-tmp;

	ret = tps65910_rtc_set_calibration(dev, calibration);

	return ret;
}

__attribute__((used)) static irqreturn_t tps65910_rtc_interrupt(int irq, void *rtc)
{
	struct device *dev = rtc;
	unsigned long events = 0;
	struct tps65910 *tps = dev_get_drvdata(dev->parent);
	struct tps65910_rtc *tps_rtc = dev_get_drvdata(dev);
	int ret;
	u32 rtc_reg;

	ret = regmap_read(tps->regmap, TPS65910_RTC_STATUS, &rtc_reg);
	if (ret)
		return IRQ_NONE;

	if (rtc_reg & TPS65910_RTC_STATUS_ALARM)
		events = RTC_IRQF | RTC_AF;

	ret = regmap_write(tps->regmap, TPS65910_RTC_STATUS, rtc_reg);
	if (ret)
		return IRQ_NONE;

	/* Notify RTC core on event */
	rtc_update_irq(tps_rtc->rtc, 1, events);

	return IRQ_HANDLED;
}

__attribute__((used)) static int tps65910_rtc_probe(struct platform_device *pdev)
{
	struct tps65910 *tps65910 = NULL;
	struct tps65910_rtc *tps_rtc = NULL;
	int ret;
	int irq;
	u32 rtc_reg;

	tps65910 = dev_get_drvdata(pdev->dev.parent);

	tps_rtc = devm_kzalloc(&pdev->dev, sizeof(struct tps65910_rtc),
			GFP_KERNEL);
	if (!tps_rtc)
		return -ENOMEM;

	tps_rtc->rtc = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(tps_rtc->rtc))
		return PTR_ERR(tps_rtc->rtc);

	/* Clear pending interrupts */
	ret = regmap_read(tps65910->regmap, TPS65910_RTC_STATUS, &rtc_reg);
	if (ret < 0)
		return ret;

	ret = regmap_write(tps65910->regmap, TPS65910_RTC_STATUS, rtc_reg);
	if (ret < 0)
		return ret;

	dev_dbg(&pdev->dev, "Enabling rtc-tps65910.\n");

	/* Enable RTC digital power domain */
	ret = regmap_update_bits(tps65910->regmap, TPS65910_DEVCTRL,
		DEVCTRL_RTC_PWDN_MASK, 0 << DEVCTRL_RTC_PWDN_SHIFT);
	if (ret < 0)
		return ret;

	rtc_reg = TPS65910_RTC_CTRL_STOP_RTC;
	ret = regmap_write(tps65910->regmap, TPS65910_RTC_CTRL, rtc_reg);
	if (ret < 0)
		return ret;

	platform_set_drvdata(pdev, tps_rtc);

	irq  = platform_get_irq(pdev, 0);
	if (irq <= 0) {
		dev_warn(&pdev->dev, "Wake up is not possible as irq = %d\n",
			irq);
		return -ENXIO;
	}

	ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
		tps65910_rtc_interrupt, IRQF_TRIGGER_LOW,
		dev_name(&pdev->dev), &pdev->dev);
	if (ret < 0) {
		dev_err(&pdev->dev, "IRQ is not free.\n");
		return ret;
	}
	tps_rtc->irq = irq;
	device_set_wakeup_capable(&pdev->dev, 1);

	tps_rtc->rtc->ops = &tps65910_rtc_ops;
	tps_rtc->rtc->range_min = RTC_TIMESTAMP_BEGIN_2000;
	tps_rtc->rtc->range_max = RTC_TIMESTAMP_END_2099;

	ret = rtc_register_device(tps_rtc->rtc);
	if (ret) {
		dev_err(&pdev->dev, "RTC device register: err %d\n", ret);
		return ret;
	}

	return 0;
}

