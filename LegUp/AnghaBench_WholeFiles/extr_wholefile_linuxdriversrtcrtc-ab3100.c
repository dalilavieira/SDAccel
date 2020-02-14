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
typedef  int u64 ;
typedef  int time64_t ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; scalar_t__ pending; } ;
struct device {int dummy; } ;
typedef  unsigned char hw_counter ;

/* Variables and functions */
 int AB3100_AL0 ; 
 int AB3100_AL1 ; 
 int AB3100_AL2 ; 
 int AB3100_AL3 ; 
 int /*<<< orphan*/  AB3100_RTC ; 
 int AB3100_RTC_CLOCK_RATE ; 
 int AB3100_TI0 ; 
 int AB3100_TI1 ; 
 int AB3100_TI2 ; 
 int AB3100_TI3 ; 
 int AB3100_TI4 ; 
 int AB3100_TI5 ; 
 int EINVAL ; 
 int abx500_get_register_interruptible (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int abx500_get_register_page_interruptible (struct device*,int /*<<< orphan*/ ,int,int*,int) ; 
 int abx500_mask_and_set_register_interruptible (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int abx500_set_register_interruptible (struct device*,int /*<<< orphan*/ ,int,unsigned char) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int,struct rtc_time*) ; 
 int rtc_tm_to_time64 (struct rtc_time*) ; 
 int rtc_valid_tm (struct rtc_time*) ; 

__attribute__((used)) static int ab3100_rtc_set_mmss(struct device *dev, time64_t secs)
{
	u8 regs[] = {AB3100_TI0, AB3100_TI1, AB3100_TI2,
		     AB3100_TI3, AB3100_TI4, AB3100_TI5};
	unsigned char buf[6];
	u64 hw_counter = secs * AB3100_RTC_CLOCK_RATE * 2;
	int err = 0;
	int i;

	buf[0] = (hw_counter) & 0xFF;
	buf[1] = (hw_counter >> 8) & 0xFF;
	buf[2] = (hw_counter >> 16) & 0xFF;
	buf[3] = (hw_counter >> 24) & 0xFF;
	buf[4] = (hw_counter >> 32) & 0xFF;
	buf[5] = (hw_counter >> 40) & 0xFF;

	for (i = 0; i < 6; i++) {
		err = abx500_set_register_interruptible(dev, 0,
							regs[i], buf[i]);
		if (err)
			return err;
	}

	/* Set the flag to mark that the clock is now set */
	return abx500_mask_and_set_register_interruptible(dev, 0,
							  AB3100_RTC,
							  0x01, 0x01);

}

__attribute__((used)) static int ab3100_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	time64_t time;
	u8 rtcval;
	int err;

	err = abx500_get_register_interruptible(dev, 0,
						AB3100_RTC, &rtcval);
	if (err)
		return err;

	if (!(rtcval & 0x01)) {
		dev_info(dev, "clock not set (lost power)");
		return -EINVAL;
	} else {
		u64 hw_counter;
		u8 buf[6];

		/* Read out time registers */
		err = abx500_get_register_page_interruptible(dev, 0,
							     AB3100_TI0,
							     buf, 6);
		if (err != 0)
			return err;

		hw_counter = ((u64) buf[5] << 40) | ((u64) buf[4] << 32) |
			((u64) buf[3] << 24) | ((u64) buf[2] << 16) |
			((u64) buf[1] << 8) | (u64) buf[0];
		time = hw_counter / (u64) (AB3100_RTC_CLOCK_RATE * 2);
	}

	rtc_time64_to_tm(time, tm);

	return 0;
}

__attribute__((used)) static int ab3100_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	time64_t time;
	u64 hw_counter;
	u8 buf[6];
	u8 rtcval;
	int err;

	/* Figure out if alarm is enabled or not */
	err = abx500_get_register_interruptible(dev, 0,
						AB3100_RTC, &rtcval);
	if (err)
		return err;
	if (rtcval & 0x04)
		alarm->enabled = 1;
	else
		alarm->enabled = 0;
	/* No idea how this could be represented */
	alarm->pending = 0;
	/* Read out alarm registers, only 4 bytes */
	err = abx500_get_register_page_interruptible(dev, 0,
						     AB3100_AL0, buf, 4);
	if (err)
		return err;
	hw_counter = ((u64) buf[3] << 40) | ((u64) buf[2] << 32) |
		((u64) buf[1] << 24) | ((u64) buf[0] << 16);
	time = hw_counter / (u64) (AB3100_RTC_CLOCK_RATE * 2);

	rtc_time64_to_tm(time, &alarm->time);

	return rtc_valid_tm(&alarm->time);
}

__attribute__((used)) static int ab3100_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	u8 regs[] = {AB3100_AL0, AB3100_AL1, AB3100_AL2, AB3100_AL3};
	unsigned char buf[4];
	time64_t secs;
	u64 hw_counter;
	int err;
	int i;

	secs = rtc_tm_to_time64(&alarm->time);
	hw_counter = secs * AB3100_RTC_CLOCK_RATE * 2;
	buf[0] = (hw_counter >> 16) & 0xFF;
	buf[1] = (hw_counter >> 24) & 0xFF;
	buf[2] = (hw_counter >> 32) & 0xFF;
	buf[3] = (hw_counter >> 40) & 0xFF;

	/* Set the alarm */
	for (i = 0; i < 4; i++) {
		err = abx500_set_register_interruptible(dev, 0,
							regs[i], buf[i]);
		if (err)
			return err;
	}
	/* Then enable the alarm */
	return abx500_mask_and_set_register_interruptible(dev, 0,
							  AB3100_RTC, (1 << 2),
							  alarm->enabled << 2);
}

__attribute__((used)) static int ab3100_rtc_irq_enable(struct device *dev, unsigned int enabled)
{
	/*
	 * It's not possible to enable/disable the alarm IRQ for this RTC.
	 * It does not actually trigger any IRQ: instead its only function is
	 * to power up the system, if it wasn't on. This will manifest as
	 * a "power up cause" in the AB3100 power driver (battery charging etc)
	 * and need to be handled there instead.
	 */
	if (enabled)
		return abx500_mask_and_set_register_interruptible(dev, 0,
						    AB3100_RTC, (1 << 2),
						    1 << 2);
	else
		return abx500_mask_and_set_register_interruptible(dev, 0,
						    AB3100_RTC, (1 << 2),
						    0);
}

