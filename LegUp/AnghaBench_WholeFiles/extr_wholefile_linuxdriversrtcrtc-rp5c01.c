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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; unsigned int tm_wday; int tm_mon; int tm_year; } ;
struct rp5c01_priv {int /*<<< orphan*/  lock; int /*<<< orphan*/ * regs; } ;
struct device {int dummy; } ;

/* Variables and functions */
 unsigned int RP5C01_10_DAY ; 
 unsigned int RP5C01_10_HOUR ; 
 unsigned int RP5C01_10_MINUTE ; 
 unsigned int RP5C01_10_MONTH ; 
 unsigned int RP5C01_10_SECOND ; 
 unsigned int RP5C01_10_YEAR ; 
 unsigned int RP5C01_1_DAY ; 
 unsigned int RP5C01_1_HOUR ; 
 unsigned int RP5C01_1_MINUTE ; 
 unsigned int RP5C01_1_MONTH ; 
 unsigned int RP5C01_1_SECOND ; 
 unsigned int RP5C01_1_YEAR ; 
 unsigned int RP5C01_DAY_OF_WEEK ; 
 unsigned int RP5C01_MODE ; 
 unsigned int RP5C01_MODE_MODE00 ; 
 unsigned int RP5C01_MODE_MODE01 ; 
 unsigned int RP5C01_MODE_RAM_BLOCK10 ; 
 unsigned int RP5C01_MODE_RAM_BLOCK11 ; 
 unsigned int RP5C01_MODE_TIMER_EN ; 
 int __raw_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ *) ; 
 struct rp5c01_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned int rp5c01_read(struct rp5c01_priv *priv,
				       unsigned int reg)
{
	return __raw_readl(&priv->regs[reg]) & 0xf;
}

__attribute__((used)) static inline void rp5c01_write(struct rp5c01_priv *priv, unsigned int val,
				unsigned int reg)
{
	__raw_writel(val, &priv->regs[reg]);
}

__attribute__((used)) static void rp5c01_lock(struct rp5c01_priv *priv)
{
	rp5c01_write(priv, RP5C01_MODE_MODE00, RP5C01_MODE);
}

__attribute__((used)) static void rp5c01_unlock(struct rp5c01_priv *priv)
{
	rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
		     RP5C01_MODE);
}

__attribute__((used)) static int rp5c01_read_time(struct device *dev, struct rtc_time *tm)
{
	struct rp5c01_priv *priv = dev_get_drvdata(dev);

	spin_lock_irq(&priv->lock);
	rp5c01_lock(priv);

	tm->tm_sec  = rp5c01_read(priv, RP5C01_10_SECOND) * 10 +
		      rp5c01_read(priv, RP5C01_1_SECOND);
	tm->tm_min  = rp5c01_read(priv, RP5C01_10_MINUTE) * 10 +
		      rp5c01_read(priv, RP5C01_1_MINUTE);
	tm->tm_hour = rp5c01_read(priv, RP5C01_10_HOUR) * 10 +
		      rp5c01_read(priv, RP5C01_1_HOUR);
	tm->tm_mday = rp5c01_read(priv, RP5C01_10_DAY) * 10 +
		      rp5c01_read(priv, RP5C01_1_DAY);
	tm->tm_wday = rp5c01_read(priv, RP5C01_DAY_OF_WEEK);
	tm->tm_mon  = rp5c01_read(priv, RP5C01_10_MONTH) * 10 +
		      rp5c01_read(priv, RP5C01_1_MONTH) - 1;
	tm->tm_year = rp5c01_read(priv, RP5C01_10_YEAR) * 10 +
		      rp5c01_read(priv, RP5C01_1_YEAR);
	if (tm->tm_year <= 69)
		tm->tm_year += 100;

	rp5c01_unlock(priv);
	spin_unlock_irq(&priv->lock);

	return 0;
}

__attribute__((used)) static int rp5c01_set_time(struct device *dev, struct rtc_time *tm)
{
	struct rp5c01_priv *priv = dev_get_drvdata(dev);

	spin_lock_irq(&priv->lock);
	rp5c01_lock(priv);

	rp5c01_write(priv, tm->tm_sec / 10, RP5C01_10_SECOND);
	rp5c01_write(priv, tm->tm_sec % 10, RP5C01_1_SECOND);
	rp5c01_write(priv, tm->tm_min / 10, RP5C01_10_MINUTE);
	rp5c01_write(priv, tm->tm_min % 10, RP5C01_1_MINUTE);
	rp5c01_write(priv, tm->tm_hour / 10, RP5C01_10_HOUR);
	rp5c01_write(priv, tm->tm_hour % 10, RP5C01_1_HOUR);
	rp5c01_write(priv, tm->tm_mday / 10, RP5C01_10_DAY);
	rp5c01_write(priv, tm->tm_mday % 10, RP5C01_1_DAY);
	if (tm->tm_wday != -1)
		rp5c01_write(priv, tm->tm_wday, RP5C01_DAY_OF_WEEK);
	rp5c01_write(priv, (tm->tm_mon + 1) / 10, RP5C01_10_MONTH);
	rp5c01_write(priv, (tm->tm_mon + 1) % 10, RP5C01_1_MONTH);
	if (tm->tm_year >= 100)
		tm->tm_year -= 100;
	rp5c01_write(priv, tm->tm_year / 10, RP5C01_10_YEAR);
	rp5c01_write(priv, tm->tm_year % 10, RP5C01_1_YEAR);

	rp5c01_unlock(priv);
	spin_unlock_irq(&priv->lock);
	return 0;
}

__attribute__((used)) static int rp5c01_nvram_read(void *_priv, unsigned int pos, void *val,
			     size_t bytes)
{
	struct rp5c01_priv *priv = _priv;
	u8 *buf = val;

	spin_lock_irq(&priv->lock);

	for (; bytes; bytes--) {
		u8 data;

		rp5c01_write(priv,
			     RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK10,
			     RP5C01_MODE);
		data = rp5c01_read(priv, pos) << 4;
		rp5c01_write(priv,
			     RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK11,
			     RP5C01_MODE);
		data |= rp5c01_read(priv, pos++);
		rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
			     RP5C01_MODE);
		*buf++ = data;
	}

	spin_unlock_irq(&priv->lock);
	return 0;
}

__attribute__((used)) static int rp5c01_nvram_write(void *_priv, unsigned int pos, void *val,
			      size_t bytes)
{
	struct rp5c01_priv *priv = _priv;
	u8 *buf = val;

	spin_lock_irq(&priv->lock);

	for (; bytes; bytes--) {
		u8 data = *buf++;

		rp5c01_write(priv,
			     RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK10,
			     RP5C01_MODE);
		rp5c01_write(priv, data >> 4, pos);
		rp5c01_write(priv,
			     RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK11,
			     RP5C01_MODE);
		rp5c01_write(priv, data & 0xf, pos++);
		rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
			     RP5C01_MODE);
	}

	spin_unlock_irq(&priv->lock);
	return 0;
}

