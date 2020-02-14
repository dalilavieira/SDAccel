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
typedef  unsigned long time64_t ;
struct timespec64 {unsigned long tv_sec; scalar_t__ tv_nsec; } ;
struct TYPE_2__ {unsigned long* reg; unsigned long* data_reg; unsigned long rst; unsigned long clk; unsigned long data; int huge_delay; int data_read_shift; scalar_t__ data_reversed; } ;

/* Variables and functions */
 unsigned int READ_TIME_CMD ; 
 unsigned int SET_TIME_CMD ; 
 unsigned int TRIMMER_DEFAULT ; 
 unsigned int TRIMMER_DISABLE_RTC ; 
 unsigned int TRIMMER_SET_CMD ; 
 unsigned int TRIMMER_SHIFT ; 
 unsigned int TRIMMER_VALUE_MASK ; 
 TYPE_1__* ds1603 ; 
 int /*<<< orphan*/  lasat_ndelay (int) ; 
 int /*<<< orphan*/  rtc_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void rtc_reg_write(unsigned long val)
{
	*ds1603->reg = val;
}

__attribute__((used)) static unsigned long rtc_reg_read(void)
{
	unsigned long tmp = *ds1603->reg;
	return tmp;
}

__attribute__((used)) static unsigned long rtc_datareg_read(void)
{
	unsigned long tmp = *ds1603->data_reg;
	return tmp;
}

__attribute__((used)) static void rtc_nrst_high(void)
{
	rtc_reg_write(rtc_reg_read() | ds1603->rst);
}

__attribute__((used)) static void rtc_nrst_low(void)
{
	rtc_reg_write(rtc_reg_read() & ~ds1603->rst);
}

__attribute__((used)) static void rtc_cycle_clock(unsigned long data)
{
	data |= ds1603->clk;
	rtc_reg_write(data);
	lasat_ndelay(250);
	if (ds1603->data_reversed)
		data &= ~ds1603->data;
	else
		data |= ds1603->data;
	data &= ~ds1603->clk;
	rtc_reg_write(data);
	lasat_ndelay(250 + ds1603->huge_delay);
}

__attribute__((used)) static void rtc_write_databit(unsigned int bit)
{
	unsigned long data = rtc_reg_read();
	if (ds1603->data_reversed)
		bit = !bit;
	if (bit)
		data |= ds1603->data;
	else
		data &= ~ds1603->data;

	rtc_reg_write(data);
	lasat_ndelay(50 + ds1603->huge_delay);
	rtc_cycle_clock(data);
}

__attribute__((used)) static unsigned int rtc_read_databit(void)
{
	unsigned int data;

	data = (rtc_datareg_read() & (1 << ds1603->data_read_shift))
		>> ds1603->data_read_shift;
	rtc_cycle_clock(rtc_reg_read());
	return data;
}

__attribute__((used)) static void rtc_write_byte(unsigned int byte)
{
	int i;

	for (i = 0; i <= 7; i++) {
		rtc_write_databit(byte & 1L);
		byte >>= 1;
	}
}

__attribute__((used)) static void rtc_write_word(unsigned long word)
{
	int i;

	for (i = 0; i <= 31; i++) {
		rtc_write_databit(word & 1L);
		word >>= 1;
	}
}

__attribute__((used)) static unsigned long rtc_read_word(void)
{
	int i;
	unsigned long word = 0;
	unsigned long shift = 0;

	for (i = 0; i <= 31; i++) {
		word |= rtc_read_databit() << shift;
		shift++;
	}
	return word;
}

__attribute__((used)) static void rtc_init_op(void)
{
	rtc_nrst_high();

	rtc_reg_write(rtc_reg_read() & ~ds1603->clk);

	lasat_ndelay(50);
}

__attribute__((used)) static void rtc_end_op(void)
{
	rtc_nrst_low();
	lasat_ndelay(1000);
}

void read_persistent_clock64(struct timespec64 *ts)
{
	unsigned long word;
	unsigned long flags;

	spin_lock_irqsave(&rtc_lock, flags);
	rtc_init_op();
	rtc_write_byte(READ_TIME_CMD);
	word = rtc_read_word();
	rtc_end_op();
	spin_unlock_irqrestore(&rtc_lock, flags);

	ts->tv_sec = word;
	ts->tv_nsec = 0;
}

int update_persistent_clock64(struct timespec64 now)
{
	time64_t time = now.tv_sec;
	unsigned long flags;

	spin_lock_irqsave(&rtc_lock, flags);
	rtc_init_op();
	rtc_write_byte(SET_TIME_CMD);
	/*
	 * Due to the hardware limitation, we cast to 'unsigned long' type,
	 * so it will overflow in year 2106 on 32-bit machine.
	 */
	rtc_write_word((unsigned long)time);
	rtc_end_op();
	spin_unlock_irqrestore(&rtc_lock, flags);

	return 0;
}

void ds1603_set_trimmer(unsigned int trimval)
{
	rtc_init_op();
	rtc_write_byte(((trimval << TRIMMER_SHIFT) & TRIMMER_VALUE_MASK)
			| (TRIMMER_SET_CMD));
	rtc_end_op();
}

void ds1603_disable(void)
{
	ds1603_set_trimmer(TRIMMER_DISABLE_RTC);
}

void ds1603_enable(void)
{
	ds1603_set_trimmer(TRIMMER_DEFAULT);
}

