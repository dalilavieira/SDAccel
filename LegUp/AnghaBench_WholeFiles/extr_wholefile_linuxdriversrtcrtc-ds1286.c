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
struct TYPE_2__ {int tm_min; int tm_hour; int tm_wday; unsigned char tm_sec; } ;
struct rtc_wkalrm {TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_device {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct ds1286_priv {struct rtc_device* rtc; int /*<<< orphan*/  lock; struct rtc_device* rtcregs; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int PTR_ERR (struct rtc_device*) ; 
 int RTC_CMD ; 
 int RTC_DATE ; 
 int RTC_DAY_ALARM ; 
 int RTC_HOURS ; 
 int RTC_HOURS_ALARM ; 
 int RTC_HUNDREDTH_SECOND ; 
 int RTC_MINUTES ; 
 int RTC_MINUTES_ALARM ; 
 int RTC_MONTH ; 
 int RTC_SECONDS ; 
 unsigned char RTC_TDM ; 
 int RTC_TE ; 
 int RTC_YEAR ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int __raw_readl (struct rtc_device*) ; 
 int /*<<< orphan*/  __raw_writel (int,struct rtc_device*) ; 
 int /*<<< orphan*/  barrier () ; 
 void* bcd2bin (int) ; 
 void* bin2bcd (unsigned char) ; 
 struct ds1286_priv* dev_get_drvdata (struct device*) ; 
 struct rtc_device* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct ds1286_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct rtc_device* devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ds1286_ops ; 
 unsigned long jiffies ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ds1286_priv*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 

__attribute__((used)) static inline u8 ds1286_rtc_read(struct ds1286_priv *priv, int reg)
{
	return __raw_readl(&priv->rtcregs[reg]) & 0xff;
}

__attribute__((used)) static inline void ds1286_rtc_write(struct ds1286_priv *priv, u8 data, int reg)
{
	__raw_writel(data, &priv->rtcregs[reg]);
}

__attribute__((used)) static int ds1286_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct ds1286_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;
	unsigned char val;

	/* Allow or mask alarm interrupts */
	spin_lock_irqsave(&priv->lock, flags);
	val = ds1286_rtc_read(priv, RTC_CMD);
	if (enabled)
		val &=  ~RTC_TDM;
	else
		val |=  RTC_TDM;
	ds1286_rtc_write(priv, val, RTC_CMD);
	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

__attribute__((used)) static int ds1286_read_time(struct device *dev, struct rtc_time *tm)
{
	struct ds1286_priv *priv = dev_get_drvdata(dev);
	unsigned char save_control;
	unsigned long flags;
	unsigned long uip_watchdog = jiffies;

	/*
	 * read RTC once any update in progress is done. The update
	 * can take just over 2ms. We wait 10 to 20ms. There is no need to
	 * to poll-wait (up to 1s - eeccch) for the falling edge of RTC_UIP.
	 * If you need to know *exactly* when a second has started, enable
	 * periodic update complete interrupts, (via ioctl) and then
	 * immediately read /dev/rtc which will block until you get the IRQ.
	 * Once the read clears, read the RTC time (again via ioctl). Easy.
	 */

	if (ds1286_rtc_read(priv, RTC_CMD) & RTC_TE)
		while (time_before(jiffies, uip_watchdog + 2*HZ/100))
			barrier();

	/*
	 * Only the values that we read from the RTC are set. We leave
	 * tm_wday, tm_yday and tm_isdst untouched. Even though the
	 * RTC has RTC_DAY_OF_WEEK, we ignore it, as it is only updated
	 * by the RTC when initially set to a non-zero value.
	 */
	spin_lock_irqsave(&priv->lock, flags);
	save_control = ds1286_rtc_read(priv, RTC_CMD);
	ds1286_rtc_write(priv, (save_control|RTC_TE), RTC_CMD);

	tm->tm_sec = ds1286_rtc_read(priv, RTC_SECONDS);
	tm->tm_min = ds1286_rtc_read(priv, RTC_MINUTES);
	tm->tm_hour = ds1286_rtc_read(priv, RTC_HOURS) & 0x3f;
	tm->tm_mday = ds1286_rtc_read(priv, RTC_DATE);
	tm->tm_mon = ds1286_rtc_read(priv, RTC_MONTH) & 0x1f;
	tm->tm_year = ds1286_rtc_read(priv, RTC_YEAR);

	ds1286_rtc_write(priv, save_control, RTC_CMD);
	spin_unlock_irqrestore(&priv->lock, flags);

	tm->tm_sec = bcd2bin(tm->tm_sec);
	tm->tm_min = bcd2bin(tm->tm_min);
	tm->tm_hour = bcd2bin(tm->tm_hour);
	tm->tm_mday = bcd2bin(tm->tm_mday);
	tm->tm_mon = bcd2bin(tm->tm_mon);
	tm->tm_year = bcd2bin(tm->tm_year);

	/*
	 * Account for differences between how the RTC uses the values
	 * and how they are defined in a struct rtc_time;
	 */
	if (tm->tm_year < 45)
		tm->tm_year += 30;
	tm->tm_year += 40;
	if (tm->tm_year < 70)
		tm->tm_year += 100;

	tm->tm_mon--;

	return 0;
}

__attribute__((used)) static int ds1286_set_time(struct device *dev, struct rtc_time *tm)
{
	struct ds1286_priv *priv = dev_get_drvdata(dev);
	unsigned char mon, day, hrs, min, sec;
	unsigned char save_control;
	unsigned int yrs;
	unsigned long flags;

	yrs = tm->tm_year + 1900;
	mon = tm->tm_mon + 1;   /* tm_mon starts at zero */
	day = tm->tm_mday;
	hrs = tm->tm_hour;
	min = tm->tm_min;
	sec = tm->tm_sec;

	if (yrs < 1970)
		return -EINVAL;

	yrs -= 1940;
	if (yrs > 255)    /* They are unsigned */
		return -EINVAL;

	if (yrs >= 100)
		yrs -= 100;

	sec = bin2bcd(sec);
	min = bin2bcd(min);
	hrs = bin2bcd(hrs);
	day = bin2bcd(day);
	mon = bin2bcd(mon);
	yrs = bin2bcd(yrs);

	spin_lock_irqsave(&priv->lock, flags);
	save_control = ds1286_rtc_read(priv, RTC_CMD);
	ds1286_rtc_write(priv, (save_control|RTC_TE), RTC_CMD);

	ds1286_rtc_write(priv, yrs, RTC_YEAR);
	ds1286_rtc_write(priv, mon, RTC_MONTH);
	ds1286_rtc_write(priv, day, RTC_DATE);
	ds1286_rtc_write(priv, hrs, RTC_HOURS);
	ds1286_rtc_write(priv, min, RTC_MINUTES);
	ds1286_rtc_write(priv, sec, RTC_SECONDS);
	ds1286_rtc_write(priv, 0, RTC_HUNDREDTH_SECOND);

	ds1286_rtc_write(priv, save_control, RTC_CMD);
	spin_unlock_irqrestore(&priv->lock, flags);
	return 0;
}

__attribute__((used)) static int ds1286_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct ds1286_priv *priv = dev_get_drvdata(dev);
	unsigned long flags;

	/*
	 * Only the values that we read from the RTC are set. That
	 * means only tm_wday, tm_hour, tm_min.
	 */
	spin_lock_irqsave(&priv->lock, flags);
	alm->time.tm_min = ds1286_rtc_read(priv, RTC_MINUTES_ALARM) & 0x7f;
	alm->time.tm_hour = ds1286_rtc_read(priv, RTC_HOURS_ALARM)  & 0x1f;
	alm->time.tm_wday = ds1286_rtc_read(priv, RTC_DAY_ALARM)    & 0x07;
	ds1286_rtc_read(priv, RTC_CMD);
	spin_unlock_irqrestore(&priv->lock, flags);

	alm->time.tm_min = bcd2bin(alm->time.tm_min);
	alm->time.tm_hour = bcd2bin(alm->time.tm_hour);
	alm->time.tm_sec = 0;
	return 0;
}

__attribute__((used)) static int ds1286_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
	struct ds1286_priv *priv = dev_get_drvdata(dev);
	unsigned char hrs, min, sec;

	hrs = alm->time.tm_hour;
	min = alm->time.tm_min;
	sec = alm->time.tm_sec;

	if (hrs >= 24)
		hrs = 0xff;

	if (min >= 60)
		min = 0xff;

	if (sec != 0)
		return -EINVAL;

	min = bin2bcd(min);
	hrs = bin2bcd(hrs);

	spin_lock(&priv->lock);
	ds1286_rtc_write(priv, hrs, RTC_HOURS_ALARM);
	ds1286_rtc_write(priv, min, RTC_MINUTES_ALARM);
	spin_unlock(&priv->lock);

	return 0;
}

__attribute__((used)) static int ds1286_probe(struct platform_device *pdev)
{
	struct rtc_device *rtc;
	struct resource *res;
	struct ds1286_priv *priv;

	priv = devm_kzalloc(&pdev->dev, sizeof(struct ds1286_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->rtcregs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->rtcregs))
		return PTR_ERR(priv->rtcregs);

	spin_lock_init(&priv->lock);
	platform_set_drvdata(pdev, priv);
	rtc = devm_rtc_device_register(&pdev->dev, "ds1286", &ds1286_ops,
					THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);
	priv->rtc = rtc;
	return 0;
}

