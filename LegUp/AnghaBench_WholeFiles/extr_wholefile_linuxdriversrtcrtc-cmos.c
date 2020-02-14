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
typedef  int u8 ;
typedef  scalar_t__ time64_t ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; scalar_t__ pending; } ;
struct platform_device {int dummy; } ;
struct device {int dummy; } ;
struct cmos_rtc {unsigned int day_alrm; unsigned int mon_alrm; void* rtc; unsigned int century; void* alarm_expires; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  (* wake_off ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* wake_on ) (int /*<<< orphan*/ ) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_handler_t ;
struct TYPE_2__ {int suspend_ctrl; } ;

/* Variables and functions */
 int CMOS_READ (unsigned int) ; 
 int /*<<< orphan*/  CMOS_WRITE (int,unsigned int) ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ NVRAM_OFFSET ; 
 unsigned char RTC_AIE ; 
 scalar_t__ RTC_ALWAYS_BCD ; 
 unsigned int RTC_CONTROL ; 
 unsigned char RTC_DM_BINARY ; 
 unsigned int RTC_HOURS_ALARM ; 
 unsigned int RTC_INTR_FLAGS ; 
 int RTC_IRQF ; 
 int RTC_IRQMASK ; 
 unsigned int RTC_MINUTES_ALARM ; 
 unsigned int RTC_SECONDS_ALARM ; 
 int bcd2bin (int) ; 
 int bin2bcd (unsigned char) ; 
 scalar_t__ can_bank2 ; 
 TYPE_1__ cmos_rtc ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct cmos_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  is_valid_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mc146818_get_time (struct rtc_time*) ; 
 int mc146818_set_time (struct rtc_time*) ; 
 int /*<<< orphan*/  pm_trace_rtc_valid () ; 
 int /*<<< orphan*/  rtc_lock ; 
 int rtc_month_days (int,int) ; 
 void* rtc_tm_to_time64 (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_update_irq (void*,int,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int cmos_use_acpi_alarm(void)
{
	return 0;
}

__attribute__((used)) static inline int is_intr(u8 rtc_intr)
{
	if (!(rtc_intr & RTC_IRQF))
		return 0;
	return rtc_intr & RTC_IRQMASK;
}

__attribute__((used)) static inline int is_hpet_enabled(void)
{
	return 0;
}

__attribute__((used)) static inline int hpet_mask_rtc_irq_bit(unsigned long mask)
{
	return 0;
}

__attribute__((used)) static inline int hpet_set_rtc_irq_bit(unsigned long mask)
{
	return 0;
}

__attribute__((used)) static inline int
hpet_set_alarm_time(unsigned char hrs, unsigned char min, unsigned char sec)
{
	return 0;
}

__attribute__((used)) static inline int hpet_set_periodic_freq(unsigned long freq)
{
	return 0;
}

__attribute__((used)) static inline int hpet_rtc_dropped_irq(void)
{
	return 0;
}

__attribute__((used)) static inline int hpet_rtc_timer_init(void)
{
	return 0;
}

__attribute__((used)) static inline int hpet_register_irq_handler(irq_handler_t handler)
{
	return 0;
}

__attribute__((used)) static inline int hpet_unregister_irq_handler(irq_handler_t handler)
{
	return 0;
}

__attribute__((used)) static inline int use_hpet_alarm(void)
{
	return is_hpet_enabled() && !cmos_use_acpi_alarm();
}

__attribute__((used)) static inline unsigned char cmos_read_bank2(unsigned char addr)
{
	return 0;
}

__attribute__((used)) static inline void cmos_write_bank2(unsigned char val, unsigned char addr)
{
}

__attribute__((used)) static int cmos_read_time(struct device *dev, struct rtc_time *t)
{
	/*
	 * If pm_trace abused the RTC for storage, set the timespec to 0,
	 * which tells the caller that this RTC value is unusable.
	 */
	if (!pm_trace_rtc_valid())
		return -EIO;

	/* REVISIT:  if the clock has a "century" register, use
	 * that instead of the heuristic in mc146818_get_time().
	 * That'll make Y3K compatility (year > 2070) easy!
	 */
	mc146818_get_time(t);
	return 0;
}

__attribute__((used)) static int cmos_set_time(struct device *dev, struct rtc_time *t)
{
	/* REVISIT:  set the "century" register if available
	 *
	 * NOTE: this ignores the issue whereby updating the seconds
	 * takes effect exactly 500ms after we write the register.
	 * (Also queueing and other delays before we get this far.)
	 */
	return mc146818_set_time(t);
}

__attribute__((used)) static int cmos_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
	struct cmos_rtc	*cmos = dev_get_drvdata(dev);
	unsigned char	rtc_control;

	/* This not only a rtc_op, but also called directly */
	if (!is_valid_irq(cmos->irq))
		return -EIO;

	/* Basic alarms only support hour, minute, and seconds fields.
	 * Some also support day and month, for alarms up to a year in
	 * the future.
	 */

	spin_lock_irq(&rtc_lock);
	t->time.tm_sec = CMOS_READ(RTC_SECONDS_ALARM);
	t->time.tm_min = CMOS_READ(RTC_MINUTES_ALARM);
	t->time.tm_hour = CMOS_READ(RTC_HOURS_ALARM);

	if (cmos->day_alrm) {
		/* ignore upper bits on readback per ACPI spec */
		t->time.tm_mday = CMOS_READ(cmos->day_alrm) & 0x3f;
		if (!t->time.tm_mday)
			t->time.tm_mday = -1;

		if (cmos->mon_alrm) {
			t->time.tm_mon = CMOS_READ(cmos->mon_alrm);
			if (!t->time.tm_mon)
				t->time.tm_mon = -1;
		}
	}

	rtc_control = CMOS_READ(RTC_CONTROL);
	spin_unlock_irq(&rtc_lock);

	if (!(rtc_control & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
		if (((unsigned)t->time.tm_sec) < 0x60)
			t->time.tm_sec = bcd2bin(t->time.tm_sec);
		else
			t->time.tm_sec = -1;
		if (((unsigned)t->time.tm_min) < 0x60)
			t->time.tm_min = bcd2bin(t->time.tm_min);
		else
			t->time.tm_min = -1;
		if (((unsigned)t->time.tm_hour) < 0x24)
			t->time.tm_hour = bcd2bin(t->time.tm_hour);
		else
			t->time.tm_hour = -1;

		if (cmos->day_alrm) {
			if (((unsigned)t->time.tm_mday) <= 0x31)
				t->time.tm_mday = bcd2bin(t->time.tm_mday);
			else
				t->time.tm_mday = -1;

			if (cmos->mon_alrm) {
				if (((unsigned)t->time.tm_mon) <= 0x12)
					t->time.tm_mon = bcd2bin(t->time.tm_mon)-1;
				else
					t->time.tm_mon = -1;
			}
		}
	}

	t->enabled = !!(rtc_control & RTC_AIE);
	t->pending = 0;

	return 0;
}

__attribute__((used)) static void cmos_checkintr(struct cmos_rtc *cmos, unsigned char rtc_control)
{
	unsigned char	rtc_intr;

	/* NOTE after changing RTC_xIE bits we always read INTR_FLAGS;
	 * allegedly some older rtcs need that to handle irqs properly
	 */
	rtc_intr = CMOS_READ(RTC_INTR_FLAGS);

	if (use_hpet_alarm())
		return;

	rtc_intr &= (rtc_control & RTC_IRQMASK) | RTC_IRQF;
	if (is_intr(rtc_intr))
		rtc_update_irq(cmos->rtc, 1, rtc_intr);
}

__attribute__((used)) static void cmos_irq_enable(struct cmos_rtc *cmos, unsigned char mask)
{
	unsigned char	rtc_control;

	/* flush any pending IRQ status, notably for update irqs,
	 * before we enable new IRQs
	 */
	rtc_control = CMOS_READ(RTC_CONTROL);
	cmos_checkintr(cmos, rtc_control);

	rtc_control |= mask;
	CMOS_WRITE(rtc_control, RTC_CONTROL);
	if (use_hpet_alarm())
		hpet_set_rtc_irq_bit(mask);

	if ((mask & RTC_AIE) && cmos_use_acpi_alarm()) {
		if (cmos->wake_on)
			cmos->wake_on(cmos->dev);
	}

	cmos_checkintr(cmos, rtc_control);
}

__attribute__((used)) static void cmos_irq_disable(struct cmos_rtc *cmos, unsigned char mask)
{
	unsigned char	rtc_control;

	rtc_control = CMOS_READ(RTC_CONTROL);
	rtc_control &= ~mask;
	CMOS_WRITE(rtc_control, RTC_CONTROL);
	if (use_hpet_alarm())
		hpet_mask_rtc_irq_bit(mask);

	if ((mask & RTC_AIE) && cmos_use_acpi_alarm()) {
		if (cmos->wake_off)
			cmos->wake_off(cmos->dev);
	}

	cmos_checkintr(cmos, rtc_control);
}

__attribute__((used)) static int cmos_validate_alarm(struct device *dev, struct rtc_wkalrm *t)
{
	struct cmos_rtc *cmos = dev_get_drvdata(dev);
	struct rtc_time now;

	cmos_read_time(dev, &now);

	if (!cmos->day_alrm) {
		time64_t t_max_date;
		time64_t t_alrm;

		t_max_date = rtc_tm_to_time64(&now);
		t_max_date += 24 * 60 * 60 - 1;
		t_alrm = rtc_tm_to_time64(&t->time);
		if (t_alrm > t_max_date) {
			dev_err(dev,
				"Alarms can be up to one day in the future\n");
			return -EINVAL;
		}
	} else if (!cmos->mon_alrm) {
		struct rtc_time max_date = now;
		time64_t t_max_date;
		time64_t t_alrm;
		int max_mday;

		if (max_date.tm_mon == 11) {
			max_date.tm_mon = 0;
			max_date.tm_year += 1;
		} else {
			max_date.tm_mon += 1;
		}
		max_mday = rtc_month_days(max_date.tm_mon, max_date.tm_year);
		if (max_date.tm_mday > max_mday)
			max_date.tm_mday = max_mday;

		t_max_date = rtc_tm_to_time64(&max_date);
		t_max_date -= 1;
		t_alrm = rtc_tm_to_time64(&t->time);
		if (t_alrm > t_max_date) {
			dev_err(dev,
				"Alarms can be up to one month in the future\n");
			return -EINVAL;
		}
	} else {
		struct rtc_time max_date = now;
		time64_t t_max_date;
		time64_t t_alrm;
		int max_mday;

		max_date.tm_year += 1;
		max_mday = rtc_month_days(max_date.tm_mon, max_date.tm_year);
		if (max_date.tm_mday > max_mday)
			max_date.tm_mday = max_mday;

		t_max_date = rtc_tm_to_time64(&max_date);
		t_max_date -= 1;
		t_alrm = rtc_tm_to_time64(&t->time);
		if (t_alrm > t_max_date) {
			dev_err(dev,
				"Alarms can be up to one year in the future\n");
			return -EINVAL;
		}
	}

	return 0;
}

__attribute__((used)) static int cmos_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
	struct cmos_rtc	*cmos = dev_get_drvdata(dev);
	unsigned char mon, mday, hrs, min, sec, rtc_control;
	int ret;

	/* This not only a rtc_op, but also called directly */
	if (!is_valid_irq(cmos->irq))
		return -EIO;

	ret = cmos_validate_alarm(dev, t);
	if (ret < 0)
		return ret;

	mon = t->time.tm_mon + 1;
	mday = t->time.tm_mday;
	hrs = t->time.tm_hour;
	min = t->time.tm_min;
	sec = t->time.tm_sec;

	rtc_control = CMOS_READ(RTC_CONTROL);
	if (!(rtc_control & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
		/* Writing 0xff means "don't care" or "match all".  */
		mon = (mon <= 12) ? bin2bcd(mon) : 0xff;
		mday = (mday >= 1 && mday <= 31) ? bin2bcd(mday) : 0xff;
		hrs = (hrs < 24) ? bin2bcd(hrs) : 0xff;
		min = (min < 60) ? bin2bcd(min) : 0xff;
		sec = (sec < 60) ? bin2bcd(sec) : 0xff;
	}

	spin_lock_irq(&rtc_lock);

	/* next rtc irq must not be from previous alarm setting */
	cmos_irq_disable(cmos, RTC_AIE);

	/* update alarm */
	CMOS_WRITE(hrs, RTC_HOURS_ALARM);
	CMOS_WRITE(min, RTC_MINUTES_ALARM);
	CMOS_WRITE(sec, RTC_SECONDS_ALARM);

	/* the system may support an "enhanced" alarm */
	if (cmos->day_alrm) {
		CMOS_WRITE(mday, cmos->day_alrm);
		if (cmos->mon_alrm)
			CMOS_WRITE(mon, cmos->mon_alrm);
	}

	if (use_hpet_alarm()) {
		/*
		 * FIXME the HPET alarm glue currently ignores day_alrm
		 * and mon_alrm ...
		 */
		hpet_set_alarm_time(t->time.tm_hour, t->time.tm_min,
				    t->time.tm_sec);
	}

	if (t->enabled)
		cmos_irq_enable(cmos, RTC_AIE);

	spin_unlock_irq(&rtc_lock);

	cmos->alarm_expires = rtc_tm_to_time64(&t->time);

	return 0;
}

__attribute__((used)) static int cmos_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct cmos_rtc	*cmos = dev_get_drvdata(dev);
	unsigned long	flags;

	spin_lock_irqsave(&rtc_lock, flags);

	if (enabled)
		cmos_irq_enable(cmos, RTC_AIE);
	else
		cmos_irq_disable(cmos, RTC_AIE);

	spin_unlock_irqrestore(&rtc_lock, flags);
	return 0;
}

__attribute__((used)) static int cmos_nvram_read(void *priv, unsigned int off, void *val,
			   size_t count)
{
	unsigned char *buf = val;
	int	retval;

	off += NVRAM_OFFSET;
	spin_lock_irq(&rtc_lock);
	for (retval = 0; count; count--, off++, retval++) {
		if (off < 128)
			*buf++ = CMOS_READ(off);
		else if (can_bank2)
			*buf++ = cmos_read_bank2(off);
		else
			break;
	}
	spin_unlock_irq(&rtc_lock);

	return retval;
}

__attribute__((used)) static int cmos_nvram_write(void *priv, unsigned int off, void *val,
			    size_t count)
{
	struct cmos_rtc	*cmos = priv;
	unsigned char	*buf = val;
	int		retval;

	/* NOTE:  on at least PCs and Ataris, the boot firmware uses a
	 * checksum on part of the NVRAM data.  That's currently ignored
	 * here.  If userspace is smart enough to know what fields of
	 * NVRAM to update, updating checksums is also part of its job.
	 */
	off += NVRAM_OFFSET;
	spin_lock_irq(&rtc_lock);
	for (retval = 0; count; count--, off++, retval++) {
		/* don't trash RTC registers */
		if (off == cmos->day_alrm
				|| off == cmos->mon_alrm
				|| off == cmos->century)
			buf++;
		else if (off < 128)
			CMOS_WRITE(*buf++, off);
		else if (can_bank2)
			cmos_write_bank2(*buf++, off);
		else
			break;
	}
	spin_unlock_irq(&rtc_lock);

	return retval;
}

__attribute__((used)) static irqreturn_t cmos_interrupt(int irq, void *p)
{
	u8		irqstat;
	u8		rtc_control;

	spin_lock(&rtc_lock);

	/* When the HPET interrupt handler calls us, the interrupt
	 * status is passed as arg1 instead of the irq number.  But
	 * always clear irq status, even when HPET is in the way.
	 *
	 * Note that HPET and RTC are almost certainly out of phase,
	 * giving different IRQ status ...
	 */
	irqstat = CMOS_READ(RTC_INTR_FLAGS);
	rtc_control = CMOS_READ(RTC_CONTROL);
	if (use_hpet_alarm())
		irqstat = (unsigned long)irq & 0xF0;

	/* If we were suspended, RTC_CONTROL may not be accurate since the
	 * bios may have cleared it.
	 */
	if (!cmos_rtc.suspend_ctrl)
		irqstat &= (rtc_control & RTC_IRQMASK) | RTC_IRQF;
	else
		irqstat &= (cmos_rtc.suspend_ctrl & RTC_IRQMASK) | RTC_IRQF;

	/* All Linux RTC alarms should be treated as if they were oneshot.
	 * Similar code may be needed in system wakeup paths, in case the
	 * alarm woke the system.
	 */
	if (irqstat & RTC_AIE) {
		cmos_rtc.suspend_ctrl &= ~RTC_AIE;
		rtc_control &= ~RTC_AIE;
		CMOS_WRITE(rtc_control, RTC_CONTROL);
		if (use_hpet_alarm())
			hpet_mask_rtc_irq_bit(RTC_AIE);
		CMOS_READ(RTC_INTR_FLAGS);
	}
	spin_unlock(&rtc_lock);

	if (is_intr(irqstat)) {
		rtc_update_irq(p, 1, irqstat);
		return IRQ_HANDLED;
	} else
		return IRQ_NONE;
}

__attribute__((used)) static void cmos_wake_setup(struct device *dev)
{
}

__attribute__((used)) static void cmos_check_acpi_rtc_status(struct device *dev,
				       unsigned char *rtc_control)
{
}

__attribute__((used)) static inline void cmos_of_init(struct platform_device *pdev) {}

