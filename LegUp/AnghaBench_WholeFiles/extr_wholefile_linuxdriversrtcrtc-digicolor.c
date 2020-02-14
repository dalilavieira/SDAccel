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
typedef  int const u8 ;
typedef  unsigned long u32 ;
typedef  unsigned long time64_t ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int pending; void* enabled; struct rtc_time time; } ;
struct device {int dummy; } ;
struct dc_rtc {int /*<<< orphan*/  rtc_dev; scalar_t__ regs; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ARRAY_SIZE (int const*) ; 
 int /*<<< orphan*/  CMD_DELAY_US ; 
#define  CMD_NOP 131 
#define  CMD_READ 130 
#define  CMD_RESET 129 
 int /*<<< orphan*/  CMD_TIMEOUT_US ; 
#define  CMD_WRITE 128 
 scalar_t__ DC_RTC_ALARM ; 
 int const DC_RTC_CMD_MASK ; 
 scalar_t__ DC_RTC_CONTROL ; 
 int const DC_RTC_GO_BUSY ; 
 scalar_t__ DC_RTC_INTENABLE ; 
 scalar_t__ DC_RTC_INTFLAG_CLEAR ; 
 scalar_t__ DC_RTC_REFERENCE ; 
 scalar_t__ DC_RTC_TIME ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 struct dc_rtc* dev_get_drvdata (struct device*) ; 
 int readb_relaxed_poll_timeout (scalar_t__,int const,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (unsigned long,struct rtc_time*) ; 
 unsigned long rtc_tm_to_time64 (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  writeb_relaxed (int const,scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static int dc_rtc_cmds(struct dc_rtc *rtc, const u8 *cmds, int len)
{
	u8 val;
	int i, ret;

	for (i = 0; i < len; i++) {
		writeb_relaxed((cmds[i] & DC_RTC_CMD_MASK) | DC_RTC_GO_BUSY,
			       rtc->regs + DC_RTC_CONTROL);
		ret = readb_relaxed_poll_timeout(
			rtc->regs + DC_RTC_CONTROL, val,
			!(val & DC_RTC_GO_BUSY), CMD_DELAY_US, CMD_TIMEOUT_US);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int dc_rtc_read(struct dc_rtc *rtc, unsigned long *val)
{
	static const u8 read_cmds[] = {CMD_READ, CMD_NOP};
	u32 reference, time1, time2;
	int ret;

	ret = dc_rtc_cmds(rtc, read_cmds, ARRAY_SIZE(read_cmds));
	if (ret < 0)
		return ret;

	reference = readl_relaxed(rtc->regs + DC_RTC_REFERENCE);
	time1 = readl_relaxed(rtc->regs + DC_RTC_TIME);
	/* Read twice to ensure consistency */
	while (1) {
		time2 = readl_relaxed(rtc->regs + DC_RTC_TIME);
		if (time1 == time2)
			break;
		time1 = time2;
	}

	*val = reference + time1;
	return 0;
}

__attribute__((used)) static int dc_rtc_write(struct dc_rtc *rtc, u32 val)
{
	static const u8 write_cmds[] = {CMD_WRITE, CMD_NOP, CMD_RESET, CMD_NOP};

	writel_relaxed(val, rtc->regs + DC_RTC_REFERENCE);
	return dc_rtc_cmds(rtc, write_cmds, ARRAY_SIZE(write_cmds));
}

__attribute__((used)) static int dc_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct dc_rtc *rtc = dev_get_drvdata(dev);
	unsigned long now;
	int ret;

	ret = dc_rtc_read(rtc, &now);
	if (ret < 0)
		return ret;
	rtc_time64_to_tm(now, tm);

	return 0;
}

__attribute__((used)) static int dc_rtc_set_mmss(struct device *dev, unsigned long secs)
{
	struct dc_rtc *rtc = dev_get_drvdata(dev);

	return dc_rtc_write(rtc, secs);
}

__attribute__((used)) static int dc_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct dc_rtc *rtc = dev_get_drvdata(dev);
	u32 alarm_reg, reference;
	unsigned long now;
	int ret;

	alarm_reg = readl_relaxed(rtc->regs + DC_RTC_ALARM);
	reference = readl_relaxed(rtc->regs + DC_RTC_REFERENCE);
	rtc_time64_to_tm(reference + alarm_reg, &alarm->time);

	ret = dc_rtc_read(rtc, &now);
	if (ret < 0)
		return ret;

	alarm->pending = alarm_reg + reference > now;
	alarm->enabled = readl_relaxed(rtc->regs + DC_RTC_INTENABLE);

	return 0;
}

__attribute__((used)) static int dc_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct dc_rtc *rtc = dev_get_drvdata(dev);
	time64_t alarm_time;
	u32 reference;

	alarm_time = rtc_tm_to_time64(&alarm->time);

	reference = readl_relaxed(rtc->regs + DC_RTC_REFERENCE);
	writel_relaxed(alarm_time - reference, rtc->regs + DC_RTC_ALARM);

	writeb_relaxed(!!alarm->enabled, rtc->regs + DC_RTC_INTENABLE);

	return 0;
}

__attribute__((used)) static int dc_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct dc_rtc *rtc = dev_get_drvdata(dev);

	writeb_relaxed(!!enabled, rtc->regs + DC_RTC_INTENABLE);

	return 0;
}

__attribute__((used)) static irqreturn_t dc_rtc_irq(int irq, void *dev_id)
{
	struct dc_rtc *rtc = dev_id;

	writeb_relaxed(1, rtc->regs + DC_RTC_INTFLAG_CLEAR);
	rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);

	return IRQ_HANDLED;
}

