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
typedef  unsigned long u32 ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {struct rtc_time time; } ;
struct pcap_rtc {int /*<<< orphan*/  pcap; int /*<<< orphan*/  rtc; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int PCAP_IRQ_1HZ ; 
 int PCAP_IRQ_TODA ; 
 int /*<<< orphan*/  PCAP_REG_RTC_DAY ; 
 int /*<<< orphan*/  PCAP_REG_RTC_DAYA ; 
 int /*<<< orphan*/  PCAP_REG_RTC_TOD ; 
 int /*<<< orphan*/  PCAP_REG_RTC_TODA ; 
 unsigned long PCAP_RTC_DAY_MASK ; 
 unsigned long PCAP_RTC_TOD_MASK ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 unsigned long RTC_UF ; 
 unsigned long SEC_PER_DAY ; 
 struct pcap_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 int /*<<< orphan*/  ezx_pcap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  ezx_pcap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int pcap_to_irq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned long,struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,unsigned long) ; 

__attribute__((used)) static irqreturn_t pcap_rtc_irq(int irq, void *_pcap_rtc)
{
	struct pcap_rtc *pcap_rtc = _pcap_rtc;
	unsigned long rtc_events;

	if (irq == pcap_to_irq(pcap_rtc->pcap, PCAP_IRQ_1HZ))
		rtc_events = RTC_IRQF | RTC_UF;
	else if (irq == pcap_to_irq(pcap_rtc->pcap, PCAP_IRQ_TODA))
		rtc_events = RTC_IRQF | RTC_AF;
	else
		rtc_events = 0;

	rtc_update_irq(pcap_rtc->rtc, 1, rtc_events);
	return IRQ_HANDLED;
}

__attribute__((used)) static int pcap_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pcap_rtc *pcap_rtc = dev_get_drvdata(dev);
	struct rtc_time *tm = &alrm->time;
	unsigned long secs;
	u32 tod;	/* time of day, seconds since midnight */
	u32 days;	/* days since 1/1/1970 */

	ezx_pcap_read(pcap_rtc->pcap, PCAP_REG_RTC_TODA, &tod);
	secs = tod & PCAP_RTC_TOD_MASK;

	ezx_pcap_read(pcap_rtc->pcap, PCAP_REG_RTC_DAYA, &days);
	secs += (days & PCAP_RTC_DAY_MASK) * SEC_PER_DAY;

	rtc_time_to_tm(secs, tm);

	return 0;
}

__attribute__((used)) static int pcap_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct pcap_rtc *pcap_rtc = dev_get_drvdata(dev);
	struct rtc_time *tm = &alrm->time;
	unsigned long secs;
	u32 tod, days;

	rtc_tm_to_time(tm, &secs);

	tod = secs % SEC_PER_DAY;
	ezx_pcap_write(pcap_rtc->pcap, PCAP_REG_RTC_TODA, tod);

	days = secs / SEC_PER_DAY;
	ezx_pcap_write(pcap_rtc->pcap, PCAP_REG_RTC_DAYA, days);

	return 0;
}

__attribute__((used)) static int pcap_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct pcap_rtc *pcap_rtc = dev_get_drvdata(dev);
	unsigned long secs;
	u32 tod, days;

	ezx_pcap_read(pcap_rtc->pcap, PCAP_REG_RTC_TOD, &tod);
	secs = tod & PCAP_RTC_TOD_MASK;

	ezx_pcap_read(pcap_rtc->pcap, PCAP_REG_RTC_DAY, &days);
	secs += (days & PCAP_RTC_DAY_MASK) * SEC_PER_DAY;

	rtc_time_to_tm(secs, tm);

	return 0;
}

__attribute__((used)) static int pcap_rtc_set_mmss(struct device *dev, unsigned long secs)
{
	struct pcap_rtc *pcap_rtc = dev_get_drvdata(dev);
	u32 tod, days;

	tod = secs % SEC_PER_DAY;
	ezx_pcap_write(pcap_rtc->pcap, PCAP_REG_RTC_TOD, tod);

	days = secs / SEC_PER_DAY;
	ezx_pcap_write(pcap_rtc->pcap, PCAP_REG_RTC_DAY, days);

	return 0;
}

__attribute__((used)) static int pcap_rtc_irq_enable(struct device *dev, int pirq, unsigned int en)
{
	struct pcap_rtc *pcap_rtc = dev_get_drvdata(dev);

	if (en)
		enable_irq(pcap_to_irq(pcap_rtc->pcap, pirq));
	else
		disable_irq(pcap_to_irq(pcap_rtc->pcap, pirq));

	return 0;
}

__attribute__((used)) static int pcap_rtc_alarm_irq_enable(struct device *dev, unsigned int en)
{
	return pcap_rtc_irq_enable(dev, PCAP_IRQ_TODA, en);
}

