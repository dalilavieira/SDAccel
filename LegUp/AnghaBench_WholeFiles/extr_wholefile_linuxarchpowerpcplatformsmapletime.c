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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; } ;

/* Variables and functions */
 scalar_t__ RTC_ALWAYS_BCD ; 
 int RTC_CONTROL ; 
 int RTC_DAY_OF_MONTH ; 
 unsigned char RTC_DIV_RESET2 ; 
 unsigned char RTC_DM_BINARY ; 
 int RTC_FREQ_SELECT ; 
 int RTC_HOURS ; 
 int RTC_MINUTES ; 
 int RTC_MONTH ; 
 int RTC_SECONDS ; 
 unsigned char RTC_SET ; 
 int RTC_YEAR ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int inb_p (scalar_t__) ; 
 scalar_t__ maple_rtc_addr ; 
 int /*<<< orphan*/  outb_p (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  rtc_lock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int maple_clock_read(int addr)
{
	outb_p(addr, maple_rtc_addr);
	return inb_p(maple_rtc_addr+1);
}

__attribute__((used)) static void maple_clock_write(unsigned long val, int addr)
{
	outb_p(addr, maple_rtc_addr);
	outb_p(val, maple_rtc_addr+1);
}

void maple_get_rtc_time(struct rtc_time *tm)
{
	do {
		tm->tm_sec = maple_clock_read(RTC_SECONDS);
		tm->tm_min = maple_clock_read(RTC_MINUTES);
		tm->tm_hour = maple_clock_read(RTC_HOURS);
		tm->tm_mday = maple_clock_read(RTC_DAY_OF_MONTH);
		tm->tm_mon = maple_clock_read(RTC_MONTH);
		tm->tm_year = maple_clock_read(RTC_YEAR);
	} while (tm->tm_sec != maple_clock_read(RTC_SECONDS));

	if (!(maple_clock_read(RTC_CONTROL) & RTC_DM_BINARY)
	    || RTC_ALWAYS_BCD) {
		tm->tm_sec = bcd2bin(tm->tm_sec);
		tm->tm_min = bcd2bin(tm->tm_min);
		tm->tm_hour = bcd2bin(tm->tm_hour);
		tm->tm_mday = bcd2bin(tm->tm_mday);
		tm->tm_mon = bcd2bin(tm->tm_mon);
		tm->tm_year = bcd2bin(tm->tm_year);
	  }
	if ((tm->tm_year + 1900) < 1970)
		tm->tm_year += 100;

	tm->tm_wday = -1;
}

int maple_set_rtc_time(struct rtc_time *tm)
{
	unsigned char save_control, save_freq_select;
	int sec, min, hour, mon, mday, year;

	spin_lock(&rtc_lock);

	save_control = maple_clock_read(RTC_CONTROL); /* tell the clock it's being set */

	maple_clock_write((save_control|RTC_SET), RTC_CONTROL);

	save_freq_select = maple_clock_read(RTC_FREQ_SELECT); /* stop and reset prescaler */

	maple_clock_write((save_freq_select|RTC_DIV_RESET2), RTC_FREQ_SELECT);

	sec = tm->tm_sec;
	min = tm->tm_min;
	hour = tm->tm_hour;
	mon = tm->tm_mon;
	mday = tm->tm_mday;
	year = tm->tm_year;

	if (!(save_control & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
		sec = bin2bcd(sec);
		min = bin2bcd(min);
		hour = bin2bcd(hour);
		mon = bin2bcd(mon);
		mday = bin2bcd(mday);
		year = bin2bcd(year);
	}
	maple_clock_write(sec, RTC_SECONDS);
	maple_clock_write(min, RTC_MINUTES);
	maple_clock_write(hour, RTC_HOURS);
	maple_clock_write(mon, RTC_MONTH);
	maple_clock_write(mday, RTC_DAY_OF_MONTH);
	maple_clock_write(year, RTC_YEAR);

	/* The following flags have to be released exactly in this order,
	 * otherwise the DS12887 (popular MC146818A clone with integrated
	 * battery and quartz) will not reset the oscillator and will not
	 * update precisely 500 ms later. You won't find this mentioned in
	 * the Dallas Semiconductor data sheets, but who believes data
	 * sheets anyway ...                           -- Markus Kuhn
	 */
	maple_clock_write(save_control, RTC_CONTROL);
	maple_clock_write(save_freq_select, RTC_FREQ_SELECT);

	spin_unlock(&rtc_lock);

	return 0;
}

