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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;

/* Variables and functions */
 int M41T81REG_DT ; 
 int M41T81REG_DY ; 
 int M41T81REG_HR ; 
 int M41T81REG_MN ; 
 int M41T81REG_MO ; 
 int M41T81REG_SC ; 
 int M41T81REG_YR ; 
 int /*<<< orphan*/  M41T81_CCR_ADDRESS ; 
 int M_SMB_BUSY ; 
 int M_SMB_ERROR ; 
 int /*<<< orphan*/  R_SMB_CMD ; 
 int /*<<< orphan*/  R_SMB_DATA ; 
 int /*<<< orphan*/  R_SMB_START ; 
 int /*<<< orphan*/  R_SMB_STATUS ; 
 int /*<<< orphan*/  SMB_CSR (int /*<<< orphan*/ ) ; 
 int V_SMB_ADDR (int /*<<< orphan*/ ) ; 
 int V_SMB_TT_RD1BYTE ; 
 int V_SMB_TT_WR1BYTE ; 
 int V_SMB_TT_WR2BYTE ; 
 int __raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeq (int,int /*<<< orphan*/ ) ; 
 unsigned int bcd2bin (unsigned int) ; 
 void* bin2bcd (int) ; 
 int /*<<< orphan*/  mktime64 (unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  rtc_lock ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int /*<<< orphan*/ ,struct rtc_time*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int m41t81_read(uint8_t addr)
{
	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq(addr & 0xff, SMB_CSR(R_SMB_CMD));
	__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_WR1BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_RD1BYTE,
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

__attribute__((used)) static int m41t81_write(uint8_t addr, int b)
{
	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	__raw_writeq(addr & 0xff, SMB_CSR(R_SMB_CMD));
	__raw_writeq(b & 0xff, SMB_CSR(R_SMB_DATA));
	__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_WR2BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	if (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_ERROR) {
		/* Clear error bit by writing a 1 */
		__raw_writeq(M_SMB_ERROR, SMB_CSR(R_SMB_STATUS));
		return -1;
	}

	/* read the same byte again to make sure it is written */
	__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_RD1BYTE,
		     SMB_CSR(R_SMB_START));

	while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
		;

	return 0;
}

int m41t81_set_time(time64_t t)
{
	struct rtc_time tm;
	unsigned long flags;

	/* Note we don't care about the century */
	rtc_time64_to_tm(t, &tm);

	/*
	 * Note the write order matters as it ensures the correctness.
	 * When we write sec, 10th sec is clear.  It is reasonable to
	 * believe we should finish writing min within a second.
	 */

	spin_lock_irqsave(&rtc_lock, flags);
	tm.tm_sec = bin2bcd(tm.tm_sec);
	m41t81_write(M41T81REG_SC, tm.tm_sec);

	tm.tm_min = bin2bcd(tm.tm_min);
	m41t81_write(M41T81REG_MN, tm.tm_min);

	tm.tm_hour = bin2bcd(tm.tm_hour);
	tm.tm_hour = (tm.tm_hour & 0x3f) | (m41t81_read(M41T81REG_HR) & 0xc0);
	m41t81_write(M41T81REG_HR, tm.tm_hour);

	/* tm_wday starts from 0 to 6 */
	if (tm.tm_wday == 0) tm.tm_wday = 7;
	tm.tm_wday = bin2bcd(tm.tm_wday);
	m41t81_write(M41T81REG_DY, tm.tm_wday);

	tm.tm_mday = bin2bcd(tm.tm_mday);
	m41t81_write(M41T81REG_DT, tm.tm_mday);

	/* tm_mon starts from 0, *ick* */
	tm.tm_mon ++;
	tm.tm_mon = bin2bcd(tm.tm_mon);
	m41t81_write(M41T81REG_MO, tm.tm_mon);

	/* we don't do century, everything is beyond 2000 */
	tm.tm_year %= 100;
	tm.tm_year = bin2bcd(tm.tm_year);
	m41t81_write(M41T81REG_YR, tm.tm_year);
	spin_unlock_irqrestore(&rtc_lock, flags);

	return 0;
}

time64_t m41t81_get_time(void)
{
	unsigned int year, mon, day, hour, min, sec;
	unsigned long flags;

	/*
	 * min is valid if two reads of sec are the same.
	 */
	for (;;) {
		spin_lock_irqsave(&rtc_lock, flags);
		sec = m41t81_read(M41T81REG_SC);
		min = m41t81_read(M41T81REG_MN);
		if (sec == m41t81_read(M41T81REG_SC)) break;
		spin_unlock_irqrestore(&rtc_lock, flags);
	}
	hour = m41t81_read(M41T81REG_HR) & 0x3f;
	day = m41t81_read(M41T81REG_DT);
	mon = m41t81_read(M41T81REG_MO);
	year = m41t81_read(M41T81REG_YR);
	spin_unlock_irqrestore(&rtc_lock, flags);

	sec = bcd2bin(sec);
	min = bcd2bin(min);
	hour = bcd2bin(hour);
	day = bcd2bin(day);
	mon = bcd2bin(mon);
	year = bcd2bin(year);

	year += 2000;

	return mktime64(year, mon, day, hour, min, sec);
}

int m41t81_probe(void)
{
	unsigned int tmp;

	/* enable chip if it is not enabled yet */
	tmp = m41t81_read(M41T81REG_SC);
	m41t81_write(M41T81REG_SC, tmp & 0x7f);

	return m41t81_read(M41T81REG_SC) != -1;
}

