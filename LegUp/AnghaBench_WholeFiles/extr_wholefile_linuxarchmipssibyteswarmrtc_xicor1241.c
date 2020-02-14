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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  time64_t ;
struct rtc_time {int tm_year; int tm_sec; int tm_min; int tm_mday; int tm_mon; int tm_hour; } ;

/* Variables and functions */
 int M_SMB_BUSY ; 
 int M_SMB_ERROR ; 
 int /*<<< orphan*/  R_SMB_CMD ; 
 int /*<<< orphan*/  R_SMB_DATA ; 
 int /*<<< orphan*/  R_SMB_START ; 
 int /*<<< orphan*/  R_SMB_STATUS ; 
 int /*<<< orphan*/  SMB_CSR (int /*<<< orphan*/ ) ; 
 int V_SMB_ADDR (int /*<<< orphan*/ ) ; 
 int V_SMB_TT_RD1BYTE ; 
 int V_SMB_TT_WR2BYTE ; 
 int V_SMB_TT_WR3BYTE ; 
 int X1241REG_DT ; 
 int X1241REG_HR ; 
 int X1241REG_HR_MIL ; 
 int X1241REG_MN ; 
 int X1241REG_MO ; 
 int X1241REG_SC ; 
 int X1241REG_SR ; 
 int X1241REG_SR_RWEL ; 
 int X1241REG_SR_WEL ; 
 int X1241REG_Y2K ; 
 int X1241REG_YR ; 
 int /*<<< orphan*/  X1241_CCR_ADDRESS ; 
 int __raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeq (int,int /*<<< orphan*/ ) ; 
 unsigned int bcd2bin (unsigned int) ; 
 void* bin2bcd (int) ; 
 int /*<<< orphan*/  mktime64 (unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  rtc_lock ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int /*<<< orphan*/ ,struct rtc_time*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int xicor_read(uint8_t addr)
{
	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq((addr >> 8) & 0x7, SMB_CSR(R_SMB_CMD));
	__raw_writeq(addr & 0xff, SMB_CSR(R_SMB_DATA));
	__raw_writeq(V_SMB_ADDR(X1241_CCR_ADDRESS) | V_SMB_TT_WR2BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq(V_SMB_ADDR(X1241_CCR_ADDRESS) | V_SMB_TT_RD1BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	if (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_ERROR) {
		/* Clear error bit by writing a 1 */
		__raw_writeq(M_SMB_ERROR, SMB_CSR(R_SMB_STATUS));
		return -1;
	}

	return __raw_readq(SMB_CSR(R_SMB_DATA)) & 0xff;
}

__attribute__((used)) static int xicor_write(uint8_t addr, int b)
{
	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq(addr, SMB_CSR(R_SMB_CMD));
	__raw_writeq((addr & 0xff) | ((b & 0xff) << 8), SMB_CSR(R_SMB_DATA));
	__raw_writeq(V_SMB_ADDR(X1241_CCR_ADDRESS) | V_SMB_TT_WR3BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	if (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_ERROR) {
		/* Clear error bit by writing a 1 */
		__raw_writeq(M_SMB_ERROR, SMB_CSR(R_SMB_STATUS));
		return -1;
	} else {
		return 0;
	}
}

int xicor_set_time(time64_t t)
{
	struct rtc_time tm;
	int tmp;
	unsigned long flags;

	rtc_time64_to_tm(t, &tm);
	tm.tm_year += 1900;

	spin_lock_irqsave(&rtc_lock, flags);
	/* unlock writes to the CCR */
	xicor_write(X1241REG_SR, X1241REG_SR_WEL);
	xicor_write(X1241REG_SR, X1241REG_SR_WEL | X1241REG_SR_RWEL);

	/* trivial ones */
	tm.tm_sec = bin2bcd(tm.tm_sec);
	xicor_write(X1241REG_SC, tm.tm_sec);

	tm.tm_min = bin2bcd(tm.tm_min);
	xicor_write(X1241REG_MN, tm.tm_min);

	tm.tm_mday = bin2bcd(tm.tm_mday);
	xicor_write(X1241REG_DT, tm.tm_mday);

	/* tm_mon starts from 0, *ick* */
	tm.tm_mon ++;
	tm.tm_mon = bin2bcd(tm.tm_mon);
	xicor_write(X1241REG_MO, tm.tm_mon);

	/* year is split */
	tmp = tm.tm_year / 100;
	tm.tm_year %= 100;
	xicor_write(X1241REG_YR, tm.tm_year);
	xicor_write(X1241REG_Y2K, tmp);

	/* hour is the most tricky one */
	tmp = xicor_read(X1241REG_HR);
	if (tmp & X1241REG_HR_MIL) {
		/* 24 hour format */
		tm.tm_hour = bin2bcd(tm.tm_hour);
		tmp = (tmp & ~0x3f) | (tm.tm_hour & 0x3f);
	} else {
		/* 12 hour format, with 0x2 for pm */
		tmp = tmp & ~0x3f;
		if (tm.tm_hour >= 12) {
			tmp |= 0x20;
			tm.tm_hour -= 12;
		}
		tm.tm_hour = bin2bcd(tm.tm_hour);
		tmp |= tm.tm_hour;
	}
	xicor_write(X1241REG_HR, tmp);

	xicor_write(X1241REG_SR, 0);
	spin_unlock_irqrestore(&rtc_lock, flags);

	return 0;
}

time64_t xicor_get_time(void)
{
	unsigned int year, mon, day, hour, min, sec, y2k;
	unsigned long flags;

	spin_lock_irqsave(&rtc_lock, flags);
	sec = xicor_read(X1241REG_SC);
	min = xicor_read(X1241REG_MN);
	hour = xicor_read(X1241REG_HR);

	if (hour & X1241REG_HR_MIL) {
		hour &= 0x3f;
	} else {
		if (hour & 0x20)
			hour = (hour & 0xf) + 0x12;
	}

	day = xicor_read(X1241REG_DT);
	mon = xicor_read(X1241REG_MO);
	year = xicor_read(X1241REG_YR);
	y2k = xicor_read(X1241REG_Y2K);
	spin_unlock_irqrestore(&rtc_lock, flags);

	sec = bcd2bin(sec);
	min = bcd2bin(min);
	hour = bcd2bin(hour);
	day = bcd2bin(day);
	mon = bcd2bin(mon);
	year = bcd2bin(year);
	y2k = bcd2bin(y2k);

	year += (y2k * 100);

	return mktime64(year, mon, day, hour, min, sec);
}

int xicor_probe(void)
{
	return xicor_read(X1241REG_SC) != -1;
}

