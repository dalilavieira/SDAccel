#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct rtc_time {int tm_mday; int tm_mon; int tm_year; int tm_sec; int tm_min; int tm_hour; } ;
struct rtc_wkalrm {struct rtc_time time; } ;
struct nuc900_rtc {scalar_t__ rtc_reg; int /*<<< orphan*/  rtcdev; } ;
struct nuc900_bcd_time {int bcd_mday; int bcd_mon; int bcd_year; int bcd_sec; int bcd_min; int bcd_hour; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned long AERPOWERON ; 
 unsigned long AERRWENB ; 
 unsigned long ALARMINTENB ; 
 int /*<<< orphan*/  EPERM ; 
 int* ERR_PTR (int /*<<< orphan*/ ) ; 
 unsigned long INIRRESET ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int*) ; 
 int PTR_ERR (int*) ; 
 scalar_t__ REG_RTC_AER ; 
 scalar_t__ REG_RTC_CAR ; 
 scalar_t__ REG_RTC_CLR ; 
 scalar_t__ REG_RTC_INIR ; 
 scalar_t__ REG_RTC_RIER ; 
 scalar_t__ REG_RTC_RIIR ; 
 scalar_t__ REG_RTC_TAR ; 
 scalar_t__ REG_RTC_TLR ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 unsigned long RTC_UF ; 
 unsigned long TICKINTENB ; 
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 void* bcd2bin (unsigned int) ; 
 int bin2bcd (int) ; 
 struct nuc900_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,unsigned long) ; 
 int rtc_valid_tm (struct rtc_time*) ; 

__attribute__((used)) static irqreturn_t nuc900_rtc_interrupt(int irq, void *_rtc)
{
	struct nuc900_rtc *rtc = _rtc;
	unsigned long events = 0, rtc_irq;

	rtc_irq = __raw_readl(rtc->rtc_reg + REG_RTC_RIIR);

	if (rtc_irq & ALARMINTENB) {
		rtc_irq &= ~ALARMINTENB;
		__raw_writel(rtc_irq, rtc->rtc_reg + REG_RTC_RIIR);
		events |= RTC_AF | RTC_IRQF;
	}

	if (rtc_irq & TICKINTENB) {
		rtc_irq &= ~TICKINTENB;
		__raw_writel(rtc_irq, rtc->rtc_reg + REG_RTC_RIIR);
		events |= RTC_UF | RTC_IRQF;
	}

	rtc_update_irq(rtc->rtcdev, 1, events);

	return IRQ_HANDLED;
}

__attribute__((used)) static int *check_rtc_access_enable(struct nuc900_rtc *nuc900_rtc)
{
	unsigned int timeout = 0x1000;
	__raw_writel(INIRRESET, nuc900_rtc->rtc_reg + REG_RTC_INIR);

	mdelay(10);

	__raw_writel(AERPOWERON, nuc900_rtc->rtc_reg + REG_RTC_AER);

	while (!(__raw_readl(nuc900_rtc->rtc_reg + REG_RTC_AER) & AERRWENB)
								&& --timeout)
		mdelay(1);

	if (!timeout)
		return ERR_PTR(-EPERM);

	return NULL;
}

__attribute__((used)) static void nuc900_rtc_bcd2bin(unsigned int timereg,
			       unsigned int calreg, struct rtc_time *tm)
{
	tm->tm_mday	= bcd2bin(calreg >> 0);
	tm->tm_mon	= bcd2bin(calreg >> 8);
	tm->tm_year	= bcd2bin(calreg >> 16) + 100;

	tm->tm_sec	= bcd2bin(timereg >> 0);
	tm->tm_min	= bcd2bin(timereg >> 8);
	tm->tm_hour	= bcd2bin(timereg >> 16);
}

__attribute__((used)) static void nuc900_rtc_bin2bcd(struct device *dev, struct rtc_time *settm,
						struct nuc900_bcd_time *gettm)
{
	gettm->bcd_mday = bin2bcd(settm->tm_mday) << 0;
	gettm->bcd_mon  = bin2bcd(settm->tm_mon) << 8;

	if (settm->tm_year < 100) {
		dev_warn(dev, "The year will be between 1970-1999, right?\n");
		gettm->bcd_year = bin2bcd(settm->tm_year) << 16;
	} else {
		gettm->bcd_year = bin2bcd(settm->tm_year - 100) << 16;
	}

	gettm->bcd_sec  = bin2bcd(settm->tm_sec) << 0;
	gettm->bcd_min  = bin2bcd(settm->tm_min) << 8;
	gettm->bcd_hour = bin2bcd(settm->tm_hour) << 16;
}

__attribute__((used)) static int nuc900_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct nuc900_rtc *rtc = dev_get_drvdata(dev);

	if (enabled)
		__raw_writel(__raw_readl(rtc->rtc_reg + REG_RTC_RIER)|
				(ALARMINTENB), rtc->rtc_reg + REG_RTC_RIER);
	else
		__raw_writel(__raw_readl(rtc->rtc_reg + REG_RTC_RIER)&
				(~ALARMINTENB), rtc->rtc_reg + REG_RTC_RIER);

	return 0;
}

__attribute__((used)) static int nuc900_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct nuc900_rtc *rtc = dev_get_drvdata(dev);
	unsigned int timeval, clrval;

	timeval = __raw_readl(rtc->rtc_reg + REG_RTC_TLR);
	clrval	= __raw_readl(rtc->rtc_reg + REG_RTC_CLR);

	nuc900_rtc_bcd2bin(timeval, clrval, tm);

	return 0;
}

__attribute__((used)) static int nuc900_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct nuc900_rtc *rtc = dev_get_drvdata(dev);
	struct nuc900_bcd_time gettm;
	unsigned long val;
	int *err;

	nuc900_rtc_bin2bcd(dev, tm, &gettm);

	err = check_rtc_access_enable(rtc);
	if (IS_ERR(err))
		return PTR_ERR(err);

	val = gettm.bcd_mday | gettm.bcd_mon | gettm.bcd_year;
	__raw_writel(val, rtc->rtc_reg + REG_RTC_CLR);

	val = gettm.bcd_sec | gettm.bcd_min | gettm.bcd_hour;
	__raw_writel(val, rtc->rtc_reg + REG_RTC_TLR);

	return 0;
}

__attribute__((used)) static int nuc900_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct nuc900_rtc *rtc = dev_get_drvdata(dev);
	unsigned int timeval, carval;

	timeval = __raw_readl(rtc->rtc_reg + REG_RTC_TAR);
	carval	= __raw_readl(rtc->rtc_reg + REG_RTC_CAR);

	nuc900_rtc_bcd2bin(timeval, carval, &alrm->time);

	return rtc_valid_tm(&alrm->time);
}

__attribute__((used)) static int nuc900_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct nuc900_rtc *rtc = dev_get_drvdata(dev);
	struct nuc900_bcd_time tm;
	unsigned long val;
	int *err;

	nuc900_rtc_bin2bcd(dev, &alrm->time, &tm);

	err = check_rtc_access_enable(rtc);
	if (IS_ERR(err))
		return PTR_ERR(err);

	val = tm.bcd_mday | tm.bcd_mon | tm.bcd_year;
	__raw_writel(val, rtc->rtc_reg + REG_RTC_CAR);

	val = tm.bcd_sec | tm.bcd_min | tm.bcd_hour;
	__raw_writel(val, rtc->rtc_reg + REG_RTC_TAR);

	return 0;
}

