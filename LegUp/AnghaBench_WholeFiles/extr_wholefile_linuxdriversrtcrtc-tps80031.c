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
typedef  int /*<<< orphan*/  u8 ;
struct tps80031_rtc {int /*<<< orphan*/  irq; int /*<<< orphan*/  rtc; } ;
struct TYPE_2__ {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_wkalrm {unsigned int enabled; TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
typedef  int irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ALARM_INT_STATUS ; 
 int /*<<< orphan*/  ENABLE_ALARM_INT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int RTC_YEAR_OFFSET ; 
 int /*<<< orphan*/  STOP_RTC ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  TPS80031_ALARM_SECONDS_REG ; 
 int TPS80031_RTC_ALARM_NUM_REGS ; 
 int /*<<< orphan*/  TPS80031_RTC_CTRL_REG ; 
 int /*<<< orphan*/  TPS80031_RTC_INTERRUPTS_REG ; 
 int TPS80031_RTC_POR_DAY ; 
 int TPS80031_RTC_POR_MONTH ; 
 int TPS80031_RTC_POR_YEAR ; 
 int /*<<< orphan*/  TPS80031_RTC_STATUS_REG ; 
 int TPS80031_RTC_TIME_NUM_REGS ; 
 int /*<<< orphan*/  TPS80031_SECONDS_REG ; 
 int /*<<< orphan*/  TPS80031_SLAVE_ID1 ; 
 void* bcd2bin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 struct tps80031_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (struct device*,int) ; 
 struct tps80031_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct tps80031_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps80031_rtc*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int tps80031_clr_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tps80031_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int tps80031_reads (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tps80031_rtc_ops ; 
 int tps80031_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tps80031_writes (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int tps80031_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	u8 buff[TPS80031_RTC_TIME_NUM_REGS];
	int ret;

	ret = tps80031_reads(dev->parent, TPS80031_SLAVE_ID1,
			TPS80031_SECONDS_REG, TPS80031_RTC_TIME_NUM_REGS, buff);
	if (ret < 0) {
		dev_err(dev, "reading RTC_SECONDS_REG failed, err = %d\n", ret);
		return ret;
	}

	tm->tm_sec = bcd2bin(buff[0]);
	tm->tm_min = bcd2bin(buff[1]);
	tm->tm_hour = bcd2bin(buff[2]);
	tm->tm_mday = bcd2bin(buff[3]);
	tm->tm_mon = bcd2bin(buff[4]) - 1;
	tm->tm_year = bcd2bin(buff[5]) + RTC_YEAR_OFFSET;
	tm->tm_wday = bcd2bin(buff[6]);
	return 0;
}

__attribute__((used)) static int tps80031_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	u8 buff[7];
	int ret;

	buff[0] = bin2bcd(tm->tm_sec);
	buff[1] = bin2bcd(tm->tm_min);
	buff[2] = bin2bcd(tm->tm_hour);
	buff[3] = bin2bcd(tm->tm_mday);
	buff[4] = bin2bcd(tm->tm_mon + 1);
	buff[5] = bin2bcd(tm->tm_year % RTC_YEAR_OFFSET);
	buff[6] = bin2bcd(tm->tm_wday);

	/* Stop RTC while updating the RTC time registers */
	ret = tps80031_clr_bits(dev->parent, TPS80031_SLAVE_ID1,
				TPS80031_RTC_CTRL_REG, STOP_RTC);
	if (ret < 0) {
		dev_err(dev->parent, "Stop RTC failed, err = %d\n", ret);
		return ret;
	}

	ret = tps80031_writes(dev->parent, TPS80031_SLAVE_ID1,
			TPS80031_SECONDS_REG,
			TPS80031_RTC_TIME_NUM_REGS, buff);
	if (ret < 0) {
		dev_err(dev, "writing RTC_SECONDS_REG failed, err %d\n", ret);
		return ret;
	}

	ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
				TPS80031_RTC_CTRL_REG, STOP_RTC);
	if (ret < 0)
		dev_err(dev->parent, "Start RTC failed, err = %d\n", ret);
	return ret;
}

__attribute__((used)) static int tps80031_rtc_alarm_irq_enable(struct device *dev,
					 unsigned int enable)
{
	int ret;

	if (enable)
		ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
				TPS80031_RTC_INTERRUPTS_REG, ENABLE_ALARM_INT);
	else
		ret = tps80031_clr_bits(dev->parent, TPS80031_SLAVE_ID1,
				TPS80031_RTC_INTERRUPTS_REG, ENABLE_ALARM_INT);
	if (ret < 0) {
		dev_err(dev, "Update on RTC_INT failed, err = %d\n", ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static int tps80031_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	u8 buff[TPS80031_RTC_ALARM_NUM_REGS];
	int ret;

	buff[0] = bin2bcd(alrm->time.tm_sec);
	buff[1] = bin2bcd(alrm->time.tm_min);
	buff[2] = bin2bcd(alrm->time.tm_hour);
	buff[3] = bin2bcd(alrm->time.tm_mday);
	buff[4] = bin2bcd(alrm->time.tm_mon + 1);
	buff[5] = bin2bcd(alrm->time.tm_year % RTC_YEAR_OFFSET);
	ret = tps80031_writes(dev->parent, TPS80031_SLAVE_ID1,
			TPS80031_ALARM_SECONDS_REG,
			TPS80031_RTC_ALARM_NUM_REGS, buff);
	if (ret < 0) {
		dev_err(dev, "Writing RTC_ALARM failed, err %d\n", ret);
		return ret;
	}
	return tps80031_rtc_alarm_irq_enable(dev, alrm->enabled);
}

__attribute__((used)) static int tps80031_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	u8 buff[6];
	int ret;

	ret = tps80031_reads(dev->parent, TPS80031_SLAVE_ID1,
			TPS80031_ALARM_SECONDS_REG,
			TPS80031_RTC_ALARM_NUM_REGS, buff);
	if (ret < 0) {
		dev_err(dev->parent,
			"reading RTC_ALARM failed, err = %d\n", ret);
		return ret;
	}

	alrm->time.tm_sec = bcd2bin(buff[0]);
	alrm->time.tm_min = bcd2bin(buff[1]);
	alrm->time.tm_hour = bcd2bin(buff[2]);
	alrm->time.tm_mday = bcd2bin(buff[3]);
	alrm->time.tm_mon = bcd2bin(buff[4]) - 1;
	alrm->time.tm_year = bcd2bin(buff[5]) + RTC_YEAR_OFFSET;
	return 0;
}

__attribute__((used)) static int clear_alarm_int_status(struct device *dev, struct tps80031_rtc *rtc)
{
	int ret;
	u8 buf;

	/**
	 * As per datasheet, A dummy read of this  RTC_STATUS_REG register
	 * is necessary before each I2C read in order to update the status
	 * register value.
	 */
	ret = tps80031_read(dev->parent, TPS80031_SLAVE_ID1,
				TPS80031_RTC_STATUS_REG, &buf);
	if (ret < 0) {
		dev_err(dev, "reading RTC_STATUS failed. err = %d\n", ret);
		return ret;
	}

	/* clear Alarm status bits.*/
	ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
			TPS80031_RTC_STATUS_REG, ALARM_INT_STATUS);
	if (ret < 0) {
		dev_err(dev, "clear Alarm INT failed, err = %d\n", ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static irqreturn_t tps80031_rtc_irq(int irq, void *data)
{
	struct device *dev = data;
	struct tps80031_rtc *rtc = dev_get_drvdata(dev);
	int ret;

	ret = clear_alarm_int_status(dev, rtc);
	if (ret < 0)
		return ret;

	rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
	return IRQ_HANDLED;
}

__attribute__((used)) static int tps80031_rtc_probe(struct platform_device *pdev)
{
	struct tps80031_rtc *rtc;
	struct rtc_time tm;
	int ret;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->irq = platform_get_irq(pdev, 0);
	platform_set_drvdata(pdev, rtc);

	/* Start RTC */
	ret = tps80031_set_bits(pdev->dev.parent, TPS80031_SLAVE_ID1,
			TPS80031_RTC_CTRL_REG, STOP_RTC);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to start RTC. err = %d\n", ret);
		return ret;
	}

	/* If RTC have POR values, set time 01:01:2000 */
	tps80031_rtc_read_time(&pdev->dev, &tm);
	if ((tm.tm_year == RTC_YEAR_OFFSET + TPS80031_RTC_POR_YEAR) &&
		(tm.tm_mon == (TPS80031_RTC_POR_MONTH - 1)) &&
		(tm.tm_mday == TPS80031_RTC_POR_DAY)) {
		tm.tm_year = 2000;
		tm.tm_mday = 1;
		tm.tm_mon = 1;
		ret = tps80031_rtc_set_time(&pdev->dev, &tm);
		if (ret < 0) {
			dev_err(&pdev->dev,
				"RTC set time failed, err = %d\n", ret);
			return ret;
		}
	}

	/* Clear alarm intretupt status if it is there */
	ret = clear_alarm_int_status(&pdev->dev, rtc);
	if (ret < 0) {
		dev_err(&pdev->dev, "Clear alarm int failed, err = %d\n", ret);
		return ret;
	}

	rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
			       &tps80031_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc->rtc)) {
		ret = PTR_ERR(rtc->rtc);
		dev_err(&pdev->dev, "RTC registration failed, err %d\n", ret);
		return ret;
	}

	ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
			tps80031_rtc_irq,
			IRQF_ONESHOT,
			dev_name(&pdev->dev), rtc);
	if (ret < 0) {
		dev_err(&pdev->dev, "request IRQ:%d failed, err = %d\n",
			 rtc->irq, ret);
		return ret;
	}
	device_set_wakeup_capable(&pdev->dev, 1);
	return 0;
}

