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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; void* tm_hour; void* tm_min; void* tm_sec; } ;
struct rtc_wkalrm {int pending; int enabled; struct rtc_time time; } ;
struct device {int dummy; } ;
struct davinci_rtc {int base; int /*<<< orphan*/  rtc; } ;
typedef  int irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOIOCTLCMD ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 int PRTCIF_CTLR ; 
 int PRTCIF_CTLR_BENL_LSB ; 
 int PRTCIF_CTLR_BUSY ; 
 int PRTCIF_CTLR_DIR ; 
 int PRTCIF_INTFLG ; 
 int PRTCIF_INTFLG_RTCSS ; 
 int PRTCIF_LDATA ; 
 int PRTCSS_RTC_ADAY0 ; 
 int PRTCSS_RTC_ADAY1 ; 
 int PRTCSS_RTC_AHOUR ; 
 int PRTCSS_RTC_AMIN ; 
 int PRTCSS_RTC_CCTRL ; 
 int PRTCSS_RTC_CCTRL_AIEN ; 
 int PRTCSS_RTC_CCTRL_ALMFLG ; 
 int PRTCSS_RTC_CCTRL_CAEN ; 
 int PRTCSS_RTC_CCTRL_CALBUSY ; 
 int PRTCSS_RTC_CCTRL_DAEN ; 
 int PRTCSS_RTC_CCTRL_HAEN ; 
 int PRTCSS_RTC_CCTRL_MAEN ; 
 int PRTCSS_RTC_CTRL ; 
 int PRTCSS_RTC_CTRL_TMRFLG ; 
 int PRTCSS_RTC_CTRL_WDTFLG ; 
 int PRTCSS_RTC_CTRL_WEN ; 
 int PRTCSS_RTC_DAY0 ; 
 int PRTCSS_RTC_DAY1 ; 
 int PRTCSS_RTC_HOUR ; 
 int PRTCSS_RTC_MIN ; 
 int PRTCSS_RTC_SEC ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 unsigned long RTC_PF ; 
#define  RTC_WIE_OFF 129 
#define  RTC_WIE_ON 128 
 void* bcd2bin (int) ; 
 unsigned long bin2bcd (void*) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  davinci_rtc_lock ; 
 struct davinci_rtc* dev_get_drvdata (struct device*) ; 
 scalar_t__ device_may_wakeup (struct device*) ; 
 int readl (int) ; 
 int rtc_month_days (int,int) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned long,struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,unsigned long) ; 
 int rtc_year_days (int,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline void rtcif_write(struct davinci_rtc *davinci_rtc,
			       u32 val, u32 addr)
{
	writel(val, davinci_rtc->base + addr);
}

__attribute__((used)) static inline u32 rtcif_read(struct davinci_rtc *davinci_rtc, u32 addr)
{
	return readl(davinci_rtc->base + addr);
}

__attribute__((used)) static inline void rtcif_wait(struct davinci_rtc *davinci_rtc)
{
	while (rtcif_read(davinci_rtc, PRTCIF_CTLR) & PRTCIF_CTLR_BUSY)
		cpu_relax();
}

__attribute__((used)) static inline void rtcss_write(struct davinci_rtc *davinci_rtc,
			       unsigned long val, u8 addr)
{
	rtcif_wait(davinci_rtc);

	rtcif_write(davinci_rtc, PRTCIF_CTLR_BENL_LSB | addr, PRTCIF_CTLR);
	rtcif_write(davinci_rtc, val, PRTCIF_LDATA);

	rtcif_wait(davinci_rtc);
}

__attribute__((used)) static inline u8 rtcss_read(struct davinci_rtc *davinci_rtc, u8 addr)
{
	rtcif_wait(davinci_rtc);

	rtcif_write(davinci_rtc, PRTCIF_CTLR_DIR | PRTCIF_CTLR_BENL_LSB | addr,
		    PRTCIF_CTLR);

	rtcif_wait(davinci_rtc);

	return rtcif_read(davinci_rtc, PRTCIF_LDATA);
}

__attribute__((used)) static inline void davinci_rtcss_calendar_wait(struct davinci_rtc *davinci_rtc)
{
	while (rtcss_read(davinci_rtc, PRTCSS_RTC_CCTRL) &
	       PRTCSS_RTC_CCTRL_CALBUSY)
		cpu_relax();
}

__attribute__((used)) static irqreturn_t davinci_rtc_interrupt(int irq, void *class_dev)
{
	struct davinci_rtc *davinci_rtc = class_dev;
	unsigned long events = 0;
	u32 irq_flg;
	u8 alm_irq, tmr_irq;
	u8 rtc_ctrl, rtc_cctrl;
	int ret = IRQ_NONE;

	irq_flg = rtcif_read(davinci_rtc, PRTCIF_INTFLG) &
		  PRTCIF_INTFLG_RTCSS;

	alm_irq = rtcss_read(davinci_rtc, PRTCSS_RTC_CCTRL) &
		  PRTCSS_RTC_CCTRL_ALMFLG;

	tmr_irq = rtcss_read(davinci_rtc, PRTCSS_RTC_CTRL) &
		  PRTCSS_RTC_CTRL_TMRFLG;

	if (irq_flg) {
		if (alm_irq) {
			events |= RTC_IRQF | RTC_AF;
			rtc_cctrl = rtcss_read(davinci_rtc, PRTCSS_RTC_CCTRL);
			rtc_cctrl |=  PRTCSS_RTC_CCTRL_ALMFLG;
			rtcss_write(davinci_rtc, rtc_cctrl, PRTCSS_RTC_CCTRL);
		} else if (tmr_irq) {
			events |= RTC_IRQF | RTC_PF;
			rtc_ctrl = rtcss_read(davinci_rtc, PRTCSS_RTC_CTRL);
			rtc_ctrl |=  PRTCSS_RTC_CTRL_TMRFLG;
			rtcss_write(davinci_rtc, rtc_ctrl, PRTCSS_RTC_CTRL);
		}

		rtcif_write(davinci_rtc, PRTCIF_INTFLG_RTCSS,
				    PRTCIF_INTFLG);
		rtc_update_irq(davinci_rtc->rtc, 1, events);

		ret = IRQ_HANDLED;
	}

	return ret;
}

__attribute__((used)) static int
davinci_rtc_ioctl(struct device *dev, unsigned int cmd, unsigned long arg)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	u8 rtc_ctrl;
	unsigned long flags;
	int ret = 0;

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	rtc_ctrl = rtcss_read(davinci_rtc, PRTCSS_RTC_CTRL);

	switch (cmd) {
	case RTC_WIE_ON:
		rtc_ctrl |= PRTCSS_RTC_CTRL_WEN | PRTCSS_RTC_CTRL_WDTFLG;
		break;
	case RTC_WIE_OFF:
		rtc_ctrl &= ~PRTCSS_RTC_CTRL_WEN;
		break;
	default:
		ret = -ENOIOCTLCMD;
	}

	rtcss_write(davinci_rtc, rtc_ctrl, PRTCSS_RTC_CTRL);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);

	return ret;
}

__attribute__((used)) static int convertfromdays(u16 days, struct rtc_time *tm)
{
	int tmp_days, year, mon;

	for (year = 2000;; year++) {
		tmp_days = rtc_year_days(1, 12, year);
		if (days >= tmp_days)
			days -= tmp_days;
		else {
			for (mon = 0;; mon++) {
				tmp_days = rtc_month_days(mon, year);
				if (days >= tmp_days) {
					days -= tmp_days;
				} else {
					tm->tm_year = year - 1900;
					tm->tm_mon = mon;
					tm->tm_mday = days + 1;
					break;
				}
			}
			break;
		}
	}
	return 0;
}

__attribute__((used)) static int convert2days(u16 *days, struct rtc_time *tm)
{
	int i;
	*days = 0;

	/* epoch == 1900 */
	if (tm->tm_year < 100 || tm->tm_year > 199)
		return -EINVAL;

	for (i = 2000; i < 1900 + tm->tm_year; i++)
		*days += rtc_year_days(1, 12, i);

	*days += rtc_year_days(tm->tm_mday, tm->tm_mon, 1900 + tm->tm_year);

	return 0;
}

__attribute__((used)) static int davinci_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	u16 days = 0;
	u8 day0, day1;
	unsigned long flags;

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	davinci_rtcss_calendar_wait(davinci_rtc);
	tm->tm_sec = bcd2bin(rtcss_read(davinci_rtc, PRTCSS_RTC_SEC));

	davinci_rtcss_calendar_wait(davinci_rtc);
	tm->tm_min = bcd2bin(rtcss_read(davinci_rtc, PRTCSS_RTC_MIN));

	davinci_rtcss_calendar_wait(davinci_rtc);
	tm->tm_hour = bcd2bin(rtcss_read(davinci_rtc, PRTCSS_RTC_HOUR));

	davinci_rtcss_calendar_wait(davinci_rtc);
	day0 = rtcss_read(davinci_rtc, PRTCSS_RTC_DAY0);

	davinci_rtcss_calendar_wait(davinci_rtc);
	day1 = rtcss_read(davinci_rtc, PRTCSS_RTC_DAY1);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);

	days |= day1;
	days <<= 8;
	days |= day0;

	if (convertfromdays(days, tm) < 0)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int davinci_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	u16 days;
	u8 rtc_cctrl;
	unsigned long flags;

	if (convert2days(&days, tm) < 0)
		return -EINVAL;

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, bin2bcd(tm->tm_sec), PRTCSS_RTC_SEC);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, bin2bcd(tm->tm_min), PRTCSS_RTC_MIN);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, bin2bcd(tm->tm_hour), PRTCSS_RTC_HOUR);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, days & 0xFF, PRTCSS_RTC_DAY0);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, (days & 0xFF00) >> 8, PRTCSS_RTC_DAY1);

	rtc_cctrl = rtcss_read(davinci_rtc, PRTCSS_RTC_CCTRL);
	rtc_cctrl |= PRTCSS_RTC_CCTRL_CAEN;
	rtcss_write(davinci_rtc, rtc_cctrl, PRTCSS_RTC_CCTRL);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);

	return 0;
}

__attribute__((used)) static int davinci_rtc_alarm_irq_enable(struct device *dev,
					unsigned int enabled)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	unsigned long flags;
	u8 rtc_cctrl = rtcss_read(davinci_rtc, PRTCSS_RTC_CCTRL);

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	if (enabled)
		rtc_cctrl |= PRTCSS_RTC_CCTRL_DAEN |
			     PRTCSS_RTC_CCTRL_HAEN |
			     PRTCSS_RTC_CCTRL_MAEN |
			     PRTCSS_RTC_CCTRL_ALMFLG |
			     PRTCSS_RTC_CCTRL_AIEN;
	else
		rtc_cctrl &= ~PRTCSS_RTC_CCTRL_AIEN;

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, rtc_cctrl, PRTCSS_RTC_CCTRL);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);

	return 0;
}

__attribute__((used)) static int davinci_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	u16 days = 0;
	u8 day0, day1;
	unsigned long flags;

	alm->time.tm_sec = 0;

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	davinci_rtcss_calendar_wait(davinci_rtc);
	alm->time.tm_min = bcd2bin(rtcss_read(davinci_rtc, PRTCSS_RTC_AMIN));

	davinci_rtcss_calendar_wait(davinci_rtc);
	alm->time.tm_hour = bcd2bin(rtcss_read(davinci_rtc, PRTCSS_RTC_AHOUR));

	davinci_rtcss_calendar_wait(davinci_rtc);
	day0 = rtcss_read(davinci_rtc, PRTCSS_RTC_ADAY0);

	davinci_rtcss_calendar_wait(davinci_rtc);
	day1 = rtcss_read(davinci_rtc, PRTCSS_RTC_ADAY1);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);
	days |= day1;
	days <<= 8;
	days |= day0;

	if (convertfromdays(days, &alm->time) < 0)
		return -EINVAL;

	alm->pending = !!(rtcss_read(davinci_rtc,
			  PRTCSS_RTC_CCTRL) &
			PRTCSS_RTC_CCTRL_AIEN);
	alm->enabled = alm->pending && device_may_wakeup(dev);

	return 0;
}

__attribute__((used)) static int davinci_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct davinci_rtc *davinci_rtc = dev_get_drvdata(dev);
	unsigned long flags;
	u16 days;

	if (alm->time.tm_mday <= 0 && alm->time.tm_mon < 0
	    && alm->time.tm_year < 0) {
		struct rtc_time tm;
		unsigned long now, then;

		davinci_rtc_read_time(dev, &tm);
		rtc_tm_to_time(&tm, &now);

		alm->time.tm_mday = tm.tm_mday;
		alm->time.tm_mon = tm.tm_mon;
		alm->time.tm_year = tm.tm_year;
		rtc_tm_to_time(&alm->time, &then);

		if (then < now) {
			rtc_time_to_tm(now + 24 * 60 * 60, &tm);
			alm->time.tm_mday = tm.tm_mday;
			alm->time.tm_mon = tm.tm_mon;
			alm->time.tm_year = tm.tm_year;
		}
	}

	if (convert2days(&days, &alm->time) < 0)
		return -EINVAL;

	spin_lock_irqsave(&davinci_rtc_lock, flags);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, bin2bcd(alm->time.tm_min), PRTCSS_RTC_AMIN);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, bin2bcd(alm->time.tm_hour), PRTCSS_RTC_AHOUR);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, days & 0xFF, PRTCSS_RTC_ADAY0);

	davinci_rtcss_calendar_wait(davinci_rtc);
	rtcss_write(davinci_rtc, (days & 0xFF00) >> 8, PRTCSS_RTC_ADAY1);

	spin_unlock_irqrestore(&davinci_rtc_lock, flags);

	return 0;
}

