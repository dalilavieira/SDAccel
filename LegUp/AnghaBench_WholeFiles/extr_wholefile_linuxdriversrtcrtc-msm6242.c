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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; unsigned int tm_wday; int tm_mon; int tm_year; } ;
struct msm6242_priv {int /*<<< orphan*/ * regs; } ;
struct device {int dummy; } ;

/* Variables and functions */
 unsigned int MSM6242_CD ; 
 int MSM6242_CD_BUSY ; 
 unsigned int MSM6242_CD_HOLD ; 
 unsigned int MSM6242_CF ; 
 int MSM6242_CF_24H ; 
 unsigned int MSM6242_DAY1 ; 
 unsigned int MSM6242_DAY10 ; 
 unsigned int MSM6242_HOUR1 ; 
 int MSM6242_HOUR10 ; 
 int MSM6242_HOUR10_PM ; 
 unsigned int MSM6242_MINUTE1 ; 
 unsigned int MSM6242_MINUTE10 ; 
 unsigned int MSM6242_MONTH1 ; 
 unsigned int MSM6242_MONTH10 ; 
 unsigned int MSM6242_SECOND1 ; 
 unsigned int MSM6242_SECOND10 ; 
 unsigned int MSM6242_WEEK ; 
 unsigned int MSM6242_YEAR1 ; 
 unsigned int MSM6242_YEAR10 ; 
 int __raw_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ *) ; 
 struct msm6242_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  pr_warn (char*,unsigned int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline unsigned int msm6242_read(struct msm6242_priv *priv,
				       unsigned int reg)
{
	return __raw_readl(&priv->regs[reg]) & 0xf;
}

__attribute__((used)) static inline void msm6242_write(struct msm6242_priv *priv, unsigned int val,
				unsigned int reg)
{
	__raw_writel(val, &priv->regs[reg]);
}

__attribute__((used)) static inline void msm6242_set(struct msm6242_priv *priv, unsigned int val,
			       unsigned int reg)
{
	msm6242_write(priv, msm6242_read(priv, reg) | val, reg);
}

__attribute__((used)) static inline void msm6242_clear(struct msm6242_priv *priv, unsigned int val,
				 unsigned int reg)
{
	msm6242_write(priv, msm6242_read(priv, reg) & ~val, reg);
}

__attribute__((used)) static void msm6242_lock(struct msm6242_priv *priv)
{
	int cnt = 5;

	msm6242_set(priv, MSM6242_CD_HOLD, MSM6242_CD);

	while ((msm6242_read(priv, MSM6242_CD) & MSM6242_CD_BUSY) && cnt) {
		msm6242_clear(priv, MSM6242_CD_HOLD, MSM6242_CD);
		udelay(70);
		msm6242_set(priv, MSM6242_CD_HOLD, MSM6242_CD);
		cnt--;
	}

	if (!cnt)
		pr_warn("timed out waiting for RTC (0x%x)\n",
			msm6242_read(priv, MSM6242_CD));
}

__attribute__((used)) static void msm6242_unlock(struct msm6242_priv *priv)
{
	msm6242_clear(priv, MSM6242_CD_HOLD, MSM6242_CD);
}

__attribute__((used)) static int msm6242_read_time(struct device *dev, struct rtc_time *tm)
{
	struct msm6242_priv *priv = dev_get_drvdata(dev);

	msm6242_lock(priv);

	tm->tm_sec  = msm6242_read(priv, MSM6242_SECOND10) * 10 +
		      msm6242_read(priv, MSM6242_SECOND1);
	tm->tm_min  = msm6242_read(priv, MSM6242_MINUTE10) * 10 +
		      msm6242_read(priv, MSM6242_MINUTE1);
	tm->tm_hour = (msm6242_read(priv, MSM6242_HOUR10 & 3)) * 10 +
		      msm6242_read(priv, MSM6242_HOUR1);
	tm->tm_mday = msm6242_read(priv, MSM6242_DAY10) * 10 +
		      msm6242_read(priv, MSM6242_DAY1);
	tm->tm_wday = msm6242_read(priv, MSM6242_WEEK);
	tm->tm_mon  = msm6242_read(priv, MSM6242_MONTH10) * 10 +
		      msm6242_read(priv, MSM6242_MONTH1) - 1;
	tm->tm_year = msm6242_read(priv, MSM6242_YEAR10) * 10 +
		      msm6242_read(priv, MSM6242_YEAR1);
	if (tm->tm_year <= 69)
		tm->tm_year += 100;

	if (!(msm6242_read(priv, MSM6242_CF) & MSM6242_CF_24H)) {
		unsigned int pm = msm6242_read(priv, MSM6242_HOUR10) &
				  MSM6242_HOUR10_PM;
		if (!pm && tm->tm_hour == 12)
			tm->tm_hour = 0;
		else if (pm && tm->tm_hour != 12)
			tm->tm_hour += 12;
	}

	msm6242_unlock(priv);

	return 0;
}

__attribute__((used)) static int msm6242_set_time(struct device *dev, struct rtc_time *tm)
{
	struct msm6242_priv *priv = dev_get_drvdata(dev);

	msm6242_lock(priv);

	msm6242_write(priv, tm->tm_sec / 10, MSM6242_SECOND10);
	msm6242_write(priv, tm->tm_sec % 10, MSM6242_SECOND1);
	msm6242_write(priv, tm->tm_min / 10, MSM6242_MINUTE10);
	msm6242_write(priv, tm->tm_min % 10, MSM6242_MINUTE1);
	if (msm6242_read(priv, MSM6242_CF) & MSM6242_CF_24H)
		msm6242_write(priv, tm->tm_hour / 10, MSM6242_HOUR10);
	else if (tm->tm_hour >= 12)
		msm6242_write(priv, MSM6242_HOUR10_PM + (tm->tm_hour - 12) / 10,
			      MSM6242_HOUR10);
	else
		msm6242_write(priv, tm->tm_hour / 10, MSM6242_HOUR10);
	msm6242_write(priv, tm->tm_hour % 10, MSM6242_HOUR1);
	msm6242_write(priv, tm->tm_mday / 10, MSM6242_DAY10);
	msm6242_write(priv, tm->tm_mday % 10, MSM6242_DAY1);
	if (tm->tm_wday != -1)
		msm6242_write(priv, tm->tm_wday, MSM6242_WEEK);
	msm6242_write(priv, (tm->tm_mon + 1) / 10, MSM6242_MONTH10);
	msm6242_write(priv, (tm->tm_mon + 1) % 10, MSM6242_MONTH1);
	if (tm->tm_year >= 100)
		tm->tm_year -= 100;
	msm6242_write(priv, tm->tm_year / 10, MSM6242_YEAR10);
	msm6242_write(priv, tm->tm_year % 10, MSM6242_YEAR1);

	msm6242_unlock(priv);
	return 0;
}

