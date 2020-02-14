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
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {unsigned int pending; unsigned int enabled; struct rtc_time time; } ;
struct platform_device {int dummy; } ;
struct device {int dummy; } ;
struct coh901331_port {int /*<<< orphan*/  clk; scalar_t__ virtbase; int /*<<< orphan*/  rtc; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 scalar_t__ COH901331_ALARM ; 
 scalar_t__ COH901331_CUR_TIME ; 
 scalar_t__ COH901331_IRQ_EVENT ; 
 scalar_t__ COH901331_IRQ_MASK ; 
 scalar_t__ COH901331_SET_TIME ; 
 scalar_t__ COH901331_VALID ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  RTC_AF ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 struct coh901331_port* dev_get_drvdata (struct device*) ; 
 struct coh901331_port* platform_get_drvdata (struct platform_device*) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned int,struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static irqreturn_t coh901331_interrupt(int irq, void *data)
{
	struct coh901331_port *rtap = data;

	clk_enable(rtap->clk);
	/* Ack IRQ */
	writel(1, rtap->virtbase + COH901331_IRQ_EVENT);
	/*
	 * Disable the interrupt. This is necessary because
	 * the RTC lives on a lower-clocked line and will
	 * not release the IRQ line until after a few (slower)
	 * clock cycles. The interrupt will be re-enabled when
	 * a new alarm is set anyway.
	 */
	writel(0, rtap->virtbase + COH901331_IRQ_MASK);
	clk_disable(rtap->clk);

	/* Set alarm flag */
	rtc_update_irq(rtap->rtc, 1, RTC_AF);

	return IRQ_HANDLED;
}

__attribute__((used)) static int coh901331_read_time(struct device *dev, struct rtc_time *tm)
{
	struct coh901331_port *rtap = dev_get_drvdata(dev);

	clk_enable(rtap->clk);
	/* Check if the time is valid */
	if (readl(rtap->virtbase + COH901331_VALID)) {
		rtc_time_to_tm(readl(rtap->virtbase + COH901331_CUR_TIME), tm);
		clk_disable(rtap->clk);
		return 0;
	}
	clk_disable(rtap->clk);
	return -EINVAL;
}

__attribute__((used)) static int coh901331_set_mmss(struct device *dev, unsigned long secs)
{
	struct coh901331_port *rtap = dev_get_drvdata(dev);

	clk_enable(rtap->clk);
	writel(secs, rtap->virtbase + COH901331_SET_TIME);
	clk_disable(rtap->clk);

	return 0;
}

__attribute__((used)) static int coh901331_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct coh901331_port *rtap = dev_get_drvdata(dev);

	clk_enable(rtap->clk);
	rtc_time_to_tm(readl(rtap->virtbase + COH901331_ALARM), &alarm->time);
	alarm->pending = readl(rtap->virtbase + COH901331_IRQ_EVENT) & 1U;
	alarm->enabled = readl(rtap->virtbase + COH901331_IRQ_MASK) & 1U;
	clk_disable(rtap->clk);

	return 0;
}

__attribute__((used)) static int coh901331_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct coh901331_port *rtap = dev_get_drvdata(dev);
	unsigned long time;

	rtc_tm_to_time(&alarm->time, &time);
	clk_enable(rtap->clk);
	writel(time, rtap->virtbase + COH901331_ALARM);
	writel(alarm->enabled, rtap->virtbase + COH901331_IRQ_MASK);
	clk_disable(rtap->clk);

	return 0;
}

__attribute__((used)) static int coh901331_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct coh901331_port *rtap = dev_get_drvdata(dev);

	clk_enable(rtap->clk);
	if (enabled)
		writel(1, rtap->virtbase + COH901331_IRQ_MASK);
	else
		writel(0, rtap->virtbase + COH901331_IRQ_MASK);
	clk_disable(rtap->clk);

	return 0;
}

__attribute__((used)) static void coh901331_shutdown(struct platform_device *pdev)
{
	struct coh901331_port *rtap = platform_get_drvdata(pdev);

	clk_enable(rtap->clk);
	writel(0, rtap->virtbase + COH901331_IRQ_MASK);
	clk_disable_unprepare(rtap->clk);
}

