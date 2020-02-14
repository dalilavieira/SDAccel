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
typedef  unsigned int u8 ;
struct rtc_time {unsigned int tm_sec; unsigned int tm_min; unsigned int tm_hour; unsigned int tm_mday; int tm_wday; int tm_mon; int tm_year; int tm_yday; int tm_isdst; } ;
struct rtc_wkalrm {int enabled; int pending; struct rtc_time time; } ;
struct TYPE_2__ {struct device* parent; } ;
struct rtc_device {TYPE_1__ dev; } ;
struct rtc7301_priv {unsigned int bank; scalar_t__ irq; int /*<<< orphan*/  lock; int /*<<< orphan*/  regmap; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int EINVAL ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int RTC7301_1000_YEAR ; 
 unsigned int RTC7301_100_YEAR ; 
 unsigned int RTC7301_10_DAY ; 
 unsigned int RTC7301_10_HOUR ; 
 unsigned int RTC7301_10_MIN ; 
 unsigned int RTC7301_10_MONTH ; 
 unsigned int RTC7301_10_SEC ; 
 unsigned int RTC7301_10_YEAR ; 
 unsigned int RTC7301_1_DAY ; 
 unsigned int RTC7301_1_HOUR ; 
 unsigned int RTC7301_1_MIN ; 
 unsigned int RTC7301_1_MONTH ; 
 unsigned int RTC7301_1_SEC ; 
 unsigned int RTC7301_1_YEAR ; 
 int RTC7301_AE ; 
 unsigned int RTC7301_ALARM_CONTROL ; 
 unsigned int RTC7301_ALARM_CONTROL_AF ; 
 unsigned int RTC7301_ALARM_CONTROL_AIE ; 
 unsigned int RTC7301_CONTROL ; 
 unsigned int RTC7301_CONTROL_BANK_SEL_0 ; 
 unsigned int RTC7301_CONTROL_BANK_SEL_1 ; 
 unsigned int RTC7301_CONTROL_BUSY ; 
 unsigned int RTC7301_CONTROL_STOP ; 
 unsigned int RTC7301_DAY_OF_WEEK ; 
 unsigned int RTC7301_TIMER_CONTROL ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 struct rtc7301_priv* dev_get_drvdata (struct device*) ; 
 int regmap_get_reg_stride (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  rtc_update_irq (struct rtc_device*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static u8 rtc7301_read(struct rtc7301_priv *priv, unsigned int reg)
{
	int reg_stride = regmap_get_reg_stride(priv->regmap);
	unsigned int val;

	regmap_read(priv->regmap, reg_stride * reg, &val);

	return val & 0xf;
}

__attribute__((used)) static void rtc7301_write(struct rtc7301_priv *priv, u8 val, unsigned int reg)
{
	int reg_stride = regmap_get_reg_stride(priv->regmap);

	regmap_write(priv->regmap, reg_stride * reg, val);
}

__attribute__((used)) static void rtc7301_update_bits(struct rtc7301_priv *priv, unsigned int reg,
				u8 mask, u8 val)
{
	int reg_stride = regmap_get_reg_stride(priv->regmap);

	regmap_update_bits(priv->regmap, reg_stride * reg, mask, val);
}

__attribute__((used)) static int rtc7301_wait_while_busy(struct rtc7301_priv *priv)
{
	int retries = 100;

	while (retries-- > 0) {
		u8 val;

		val = rtc7301_read(priv, RTC7301_CONTROL);
		if (!(val & RTC7301_CONTROL_BUSY))
			return 0;

		udelay(300);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static void rtc7301_stop(struct rtc7301_priv *priv)
{
	rtc7301_update_bits(priv, RTC7301_CONTROL, RTC7301_CONTROL_STOP,
			    RTC7301_CONTROL_STOP);
}

__attribute__((used)) static void rtc7301_start(struct rtc7301_priv *priv)
{
	rtc7301_update_bits(priv, RTC7301_CONTROL, RTC7301_CONTROL_STOP, 0);
}

__attribute__((used)) static void rtc7301_select_bank(struct rtc7301_priv *priv, u8 bank)
{
	u8 val = 0;

	if (bank == priv->bank)
		return;

	if (bank & BIT(0))
		val |= RTC7301_CONTROL_BANK_SEL_0;
	if (bank & BIT(1))
		val |= RTC7301_CONTROL_BANK_SEL_1;

	rtc7301_update_bits(priv, RTC7301_CONTROL,
			    RTC7301_CONTROL_BANK_SEL_0 |
			    RTC7301_CONTROL_BANK_SEL_1, val);

	priv->bank = bank;
}

__attribute__((used)) static void rtc7301_get_time(struct rtc7301_priv *priv, struct rtc_time *tm,
			     bool alarm)
{
	int year;

	tm->tm_sec = rtc7301_read(priv, RTC7301_1_SEC);
	tm->tm_sec += (rtc7301_read(priv, RTC7301_10_SEC) & ~RTC7301_AE) * 10;
	tm->tm_min = rtc7301_read(priv, RTC7301_1_MIN);
	tm->tm_min += (rtc7301_read(priv, RTC7301_10_MIN) & ~RTC7301_AE) * 10;
	tm->tm_hour = rtc7301_read(priv, RTC7301_1_HOUR);
	tm->tm_hour += (rtc7301_read(priv, RTC7301_10_HOUR) & ~RTC7301_AE) * 10;
	tm->tm_mday = rtc7301_read(priv, RTC7301_1_DAY);
	tm->tm_mday += (rtc7301_read(priv, RTC7301_10_DAY) & ~RTC7301_AE) * 10;

	if (alarm) {
		tm->tm_wday = -1;
		tm->tm_mon = -1;
		tm->tm_year = -1;
		tm->tm_yday = -1;
		tm->tm_isdst = -1;
		return;
	}

	tm->tm_wday = (rtc7301_read(priv, RTC7301_DAY_OF_WEEK) & ~RTC7301_AE);
	tm->tm_mon = rtc7301_read(priv, RTC7301_10_MONTH) * 10 +
		     rtc7301_read(priv, RTC7301_1_MONTH) - 1;
	year = rtc7301_read(priv, RTC7301_1000_YEAR) * 1000 +
	       rtc7301_read(priv, RTC7301_100_YEAR) * 100 +
	       rtc7301_read(priv, RTC7301_10_YEAR) * 10 +
	       rtc7301_read(priv, RTC7301_1_YEAR);

	tm->tm_year = year - 1900;
}

__attribute__((used)) static void rtc7301_write_time(struct rtc7301_priv *priv, struct rtc_time *tm,
			       bool alarm)
{
	int year;

	rtc7301_write(priv, tm->tm_sec % 10, RTC7301_1_SEC);
	rtc7301_write(priv, tm->tm_sec / 10, RTC7301_10_SEC);

	rtc7301_write(priv, tm->tm_min % 10, RTC7301_1_MIN);
	rtc7301_write(priv, tm->tm_min / 10, RTC7301_10_MIN);

	rtc7301_write(priv, tm->tm_hour % 10, RTC7301_1_HOUR);
	rtc7301_write(priv, tm->tm_hour / 10, RTC7301_10_HOUR);

	rtc7301_write(priv, tm->tm_mday % 10, RTC7301_1_DAY);
	rtc7301_write(priv, tm->tm_mday / 10, RTC7301_10_DAY);

	/* Don't care for alarm register */
	rtc7301_write(priv, alarm ? RTC7301_AE : tm->tm_wday,
		      RTC7301_DAY_OF_WEEK);

	if (alarm)
		return;

	rtc7301_write(priv, (tm->tm_mon + 1) % 10, RTC7301_1_MONTH);
	rtc7301_write(priv, (tm->tm_mon + 1) / 10, RTC7301_10_MONTH);

	year = tm->tm_year + 1900;

	rtc7301_write(priv, year % 10, RTC7301_1_YEAR);
	rtc7301_write(priv, (year / 10) % 10, RTC7301_10_YEAR);
	rtc7301_write(priv, (year / 100) % 10, RTC7301_100_YEAR);
	rtc7301_write(priv, year / 1000, RTC7301_1000_YEAR);
}

__attribute__((used)) static void rtc7301_alarm_irq(struct rtc7301_priv *priv, unsigned int enabled)
{
	rtc7301_update_bits(priv, RTC7301_ALARM_CONTROL,
			    RTC7301_ALARM_CONTROL_AF |
			    RTC7301_ALARM_CONTROL_AIE,
			    enabled ? RTC7301_ALARM_CONTROL_AIE : 0);
}

__attribute__((used)) static int rtc7301_read_time(struct device *dev, struct rtc_time *tm)
{
	struct rtc7301_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;
	int err;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 0);

	err = rtc7301_wait_while_busy(priv);
	if (!err)
		rtc7301_get_time(priv, tm, false);

	spin_unlock_irqrestore(&priv->lock, flags);

	return err;
}

__attribute__((used)) static int rtc7301_set_time(struct device *dev, struct rtc_time *tm)
{
	struct rtc7301_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_stop(priv);
	udelay(300);
	rtc7301_select_bank(priv, 0);
	rtc7301_write_time(priv, tm, false);
	rtc7301_start(priv);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

__attribute__((used)) static int rtc7301_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct rtc7301_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;
	u8 alrm_ctrl;

	if (priv->irq <= 0)
		return -EINVAL;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 1);
	rtc7301_get_time(priv, &alarm->time, true);

	alrm_ctrl = rtc7301_read(priv, RTC7301_ALARM_CONTROL);

	alarm->enabled = !!(alrm_ctrl & RTC7301_ALARM_CONTROL_AIE);
	alarm->pending = !!(alrm_ctrl & RTC7301_ALARM_CONTROL_AF);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

__attribute__((used)) static int rtc7301_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct rtc7301_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;

	if (priv->irq <= 0)
		return -EINVAL;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 1);
	rtc7301_write_time(priv, &alarm->time, true);
	rtc7301_alarm_irq(priv, alarm->enabled);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

__attribute__((used)) static int rtc7301_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct rtc7301_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;

	if (priv->irq <= 0)
		return -EINVAL;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 1);
	rtc7301_alarm_irq(priv, enabled);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

__attribute__((used)) static irqreturn_t rtc7301_irq_handler(int irq, void *dev_id)
{
	struct rtc_device *rtc = dev_id;
	struct rtc7301_priv *priv = dev_get_drvdata(rtc->dev.parent);
	unsigned long flags;
	irqreturn_t ret = IRQ_NONE;
	u8 alrm_ctrl;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 1);

	alrm_ctrl = rtc7301_read(priv, RTC7301_ALARM_CONTROL);
	if (alrm_ctrl & RTC7301_ALARM_CONTROL_AF) {
		ret = IRQ_HANDLED;
		rtc7301_alarm_irq(priv, false);
		rtc_update_irq(rtc, 1, RTC_IRQF | RTC_AF);
	}

	spin_unlock_irqrestore(&priv->lock, flags);

	return ret;
}

__attribute__((used)) static void rtc7301_init(struct rtc7301_priv *priv)
{
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	rtc7301_select_bank(priv, 2);
	rtc7301_write(priv, 0, RTC7301_TIMER_CONTROL);

	spin_unlock_irqrestore(&priv->lock, flags);
}

