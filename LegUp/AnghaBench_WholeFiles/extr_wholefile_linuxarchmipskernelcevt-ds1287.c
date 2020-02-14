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
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int CMOS_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CMOS_WRITE (int,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int RTC_PF ; 
 int RTC_PIE ; 
 int RTC_REF_CLCK_32KHZ ; 
 int /*<<< orphan*/  RTC_REG_A ; 
 int /*<<< orphan*/  RTC_REG_B ; 
 int /*<<< orphan*/  RTC_REG_C ; 
 struct clock_event_device ds1287_clockevent ; 
 int /*<<< orphan*/  rtc_lock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

int ds1287_timer_state(void)
{
	return (CMOS_READ(RTC_REG_C) & RTC_PF) != 0;
}

int ds1287_set_base_clock(unsigned int hz)
{
	u8 rate;

	switch (hz) {
	case 128:
		rate = 0x9;
		break;
	case 256:
		rate = 0x8;
		break;
	case 1024:
		rate = 0x6;
		break;
	default:
		return -EINVAL;
	}

	CMOS_WRITE(RTC_REF_CLCK_32KHZ | rate, RTC_REG_A);

	return 0;
}

__attribute__((used)) static int ds1287_set_next_event(unsigned long delta,
				 struct clock_event_device *evt)
{
	return -EINVAL;
}

__attribute__((used)) static int ds1287_shutdown(struct clock_event_device *evt)
{
	u8 val;

	spin_lock(&rtc_lock);

	val = CMOS_READ(RTC_REG_B);
	val &= ~RTC_PIE;
	CMOS_WRITE(val, RTC_REG_B);

	spin_unlock(&rtc_lock);
	return 0;
}

__attribute__((used)) static int ds1287_set_periodic(struct clock_event_device *evt)
{
	u8 val;

	spin_lock(&rtc_lock);

	val = CMOS_READ(RTC_REG_B);
	val |= RTC_PIE;
	CMOS_WRITE(val, RTC_REG_B);

	spin_unlock(&rtc_lock);
	return 0;
}

__attribute__((used)) static void ds1287_event_handler(struct clock_event_device *dev)
{
}

__attribute__((used)) static irqreturn_t ds1287_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *cd = &ds1287_clockevent;

	/* Ack the RTC interrupt. */
	CMOS_READ(RTC_REG_C);

	cd->event_handler(cd);

	return IRQ_HANDLED;
}

