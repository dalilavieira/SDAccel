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
typedef  int umode_t ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  temp_buf ;
struct TYPE_2__ {int tm_sec; int tm_min; int tm_hour; int tm_mday; } ;
struct rtc_wkalrm {int enabled; int pending; TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct regmap {int dummy; } ;
struct mutex {int dummy; } ;
struct ds3232 {scalar_t__ irq; struct device* rtc; struct device* dev; struct regmap* regmap; } ;
struct device {struct mutex ops_lock; } ;
typedef  int s16 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_RTC_DRV_DS3232_HWMON ; 
 int /*<<< orphan*/  DS3232_REG_ALARM1 ; 
 int /*<<< orphan*/  DS3232_REG_CR ; 
 int DS3232_REG_CR_A1IE ; 
 int DS3232_REG_CR_A2IE ; 
 int DS3232_REG_CR_INTCN ; 
 int /*<<< orphan*/  DS3232_REG_SECONDS ; 
 int /*<<< orphan*/  DS3232_REG_SR ; 
 int DS3232_REG_SR_A1F ; 
 int DS3232_REG_SR_A2F ; 
 int DS3232_REG_SR_OSF ; 
 int /*<<< orphan*/  DS3232_REG_TEMPERATURE ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int PTR_ERR (struct device*) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct ds3232* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ds3232*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (struct device*,int /*<<< orphan*/ ) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,char const*,struct ds3232*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct ds3232* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char const*,struct device*) ; 
 struct device* devm_rtc_device_register (struct device*,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ds3232_hwmon_chip_info ; 
 int /*<<< orphan*/  ds3232_rtc_ops ; 
 int hwmon_temp ; 
#define  hwmon_temp_input 128 
 int /*<<< orphan*/  mutex_lock (struct mutex*) ; 
 int /*<<< orphan*/  mutex_unlock (struct mutex*) ; 
 int regmap_bulk_read (struct regmap*,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_bulk_write (struct regmap*,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtc_update_irq (struct device*,int,int) ; 

__attribute__((used)) static int ds3232_check_rtc_status(struct device *dev)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	int ret = 0;
	int control, stat;

	ret = regmap_read(ds3232->regmap, DS3232_REG_SR, &stat);
	if (ret)
		return ret;

	if (stat & DS3232_REG_SR_OSF)
		dev_warn(dev,
				"oscillator discontinuity flagged, "
				"time unreliable\n");

	stat &= ~(DS3232_REG_SR_OSF | DS3232_REG_SR_A1F | DS3232_REG_SR_A2F);

	ret = regmap_write(ds3232->regmap, DS3232_REG_SR, stat);
	if (ret)
		return ret;

	/* If the alarm is pending, clear it before requesting
	 * the interrupt, so an interrupt event isn't reported
	 * before everything is initialized.
	 */

	ret = regmap_read(ds3232->regmap, DS3232_REG_CR, &control);
	if (ret)
		return ret;

	control &= ~(DS3232_REG_CR_A1IE | DS3232_REG_CR_A2IE);
	control |= DS3232_REG_CR_INTCN;

	return regmap_write(ds3232->regmap, DS3232_REG_CR, control);
}

__attribute__((used)) static int ds3232_read_time(struct device *dev, struct rtc_time *time)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	int ret;
	u8 buf[7];
	unsigned int year, month, day, hour, minute, second;
	unsigned int week, twelve_hr, am_pm;
	unsigned int century, add_century = 0;

	ret = regmap_bulk_read(ds3232->regmap, DS3232_REG_SECONDS, buf, 7);
	if (ret)
		return ret;

	second = buf[0];
	minute = buf[1];
	hour = buf[2];
	week = buf[3];
	day = buf[4];
	month = buf[5];
	year = buf[6];

	/* Extract additional information for AM/PM and century */

	twelve_hr = hour & 0x40;
	am_pm = hour & 0x20;
	century = month & 0x80;

	/* Write to rtc_time structure */

	time->tm_sec = bcd2bin(second);
	time->tm_min = bcd2bin(minute);
	if (twelve_hr) {
		/* Convert to 24 hr */
		if (am_pm)
			time->tm_hour = bcd2bin(hour & 0x1F) + 12;
		else
			time->tm_hour = bcd2bin(hour & 0x1F);
	} else {
		time->tm_hour = bcd2bin(hour);
	}

	/* Day of the week in linux range is 0~6 while 1~7 in RTC chip */
	time->tm_wday = bcd2bin(week) - 1;
	time->tm_mday = bcd2bin(day);
	/* linux tm_mon range:0~11, while month range is 1~12 in RTC chip */
	time->tm_mon = bcd2bin(month & 0x7F) - 1;
	if (century)
		add_century = 100;

	time->tm_year = bcd2bin(year) + add_century;

	return 0;
}

__attribute__((used)) static int ds3232_set_time(struct device *dev, struct rtc_time *time)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	u8 buf[7];

	/* Extract time from rtc_time and load into ds3232*/

	buf[0] = bin2bcd(time->tm_sec);
	buf[1] = bin2bcd(time->tm_min);
	buf[2] = bin2bcd(time->tm_hour);
	/* Day of the week in linux range is 0~6 while 1~7 in RTC chip */
	buf[3] = bin2bcd(time->tm_wday + 1);
	buf[4] = bin2bcd(time->tm_mday); /* Date */
	/* linux tm_mon range:0~11, while month range is 1~12 in RTC chip */
	buf[5] = bin2bcd(time->tm_mon + 1);
	if (time->tm_year >= 100) {
		buf[5] |= 0x80;
		buf[6] = bin2bcd(time->tm_year - 100);
	} else {
		buf[6] = bin2bcd(time->tm_year);
	}

	return regmap_bulk_write(ds3232->regmap, DS3232_REG_SECONDS, buf, 7);
}

__attribute__((used)) static int ds3232_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	int control, stat;
	int ret;
	u8 buf[4];

	ret = regmap_read(ds3232->regmap, DS3232_REG_SR, &stat);
	if (ret)
		goto out;
	ret = regmap_read(ds3232->regmap, DS3232_REG_CR, &control);
	if (ret)
		goto out;
	ret = regmap_bulk_read(ds3232->regmap, DS3232_REG_ALARM1, buf, 4);
	if (ret)
		goto out;

	alarm->time.tm_sec = bcd2bin(buf[0] & 0x7F);
	alarm->time.tm_min = bcd2bin(buf[1] & 0x7F);
	alarm->time.tm_hour = bcd2bin(buf[2] & 0x7F);
	alarm->time.tm_mday = bcd2bin(buf[3] & 0x7F);

	alarm->enabled = !!(control & DS3232_REG_CR_A1IE);
	alarm->pending = !!(stat & DS3232_REG_SR_A1F);

	ret = 0;
out:
	return ret;
}

__attribute__((used)) static int ds3232_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	int control, stat;
	int ret;
	u8 buf[4];

	if (ds3232->irq <= 0)
		return -EINVAL;

	buf[0] = bin2bcd(alarm->time.tm_sec);
	buf[1] = bin2bcd(alarm->time.tm_min);
	buf[2] = bin2bcd(alarm->time.tm_hour);
	buf[3] = bin2bcd(alarm->time.tm_mday);

	/* clear alarm interrupt enable bit */
	ret = regmap_read(ds3232->regmap, DS3232_REG_CR, &control);
	if (ret)
		goto out;
	control &= ~(DS3232_REG_CR_A1IE | DS3232_REG_CR_A2IE);
	ret = regmap_write(ds3232->regmap, DS3232_REG_CR, control);
	if (ret)
		goto out;

	/* clear any pending alarm flag */
	ret = regmap_read(ds3232->regmap, DS3232_REG_SR, &stat);
	if (ret)
		goto out;
	stat &= ~(DS3232_REG_SR_A1F | DS3232_REG_SR_A2F);
	ret = regmap_write(ds3232->regmap, DS3232_REG_SR, stat);
	if (ret)
		goto out;

	ret = regmap_bulk_write(ds3232->regmap, DS3232_REG_ALARM1, buf, 4);
	if (ret)
		goto out;

	if (alarm->enabled) {
		control |= DS3232_REG_CR_A1IE;
		ret = regmap_write(ds3232->regmap, DS3232_REG_CR, control);
	}
out:
	return ret;
}

__attribute__((used)) static int ds3232_update_alarm(struct device *dev, unsigned int enabled)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	int control;
	int ret;

	ret = regmap_read(ds3232->regmap, DS3232_REG_CR, &control);
	if (ret)
		return ret;

	if (enabled)
		/* enable alarm1 interrupt */
		control |= DS3232_REG_CR_A1IE;
	else
		/* disable alarm1 interrupt */
		control &= ~(DS3232_REG_CR_A1IE);
	ret = regmap_write(ds3232->regmap, DS3232_REG_CR, control);

	return ret;
}

__attribute__((used)) static int ds3232_hwmon_read_temp(struct device *dev, long int *mC)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	u8 temp_buf[2];
	s16 temp;
	int ret;

	ret = regmap_bulk_read(ds3232->regmap, DS3232_REG_TEMPERATURE, temp_buf,
			       sizeof(temp_buf));
	if (ret < 0)
		return ret;

	/*
	 * Temperature is represented as a 10-bit code with a resolution of
	 * 0.25 degree celsius and encoded in two's complement format.
	 */
	temp = (temp_buf[0] << 8) | temp_buf[1];
	temp >>= 6;
	*mC = temp * 250;

	return 0;
}

__attribute__((used)) static umode_t ds3232_hwmon_is_visible(const void *data,
				       enum hwmon_sensor_types type,
				       u32 attr, int channel)
{
	if (type != hwmon_temp)
		return 0;

	switch (attr) {
	case hwmon_temp_input:
		return 0444;
	default:
		return 0;
	}
}

__attribute__((used)) static int ds3232_hwmon_read(struct device *dev,
			     enum hwmon_sensor_types type,
			     u32 attr, int channel, long *temp)
{
	int err;

	switch (attr) {
	case hwmon_temp_input:
		err = ds3232_hwmon_read_temp(dev, temp);
		break;
	default:
		err = -EOPNOTSUPP;
		break;
	}

	return err;
}

__attribute__((used)) static void ds3232_hwmon_register(struct device *dev, const char *name)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	struct device *hwmon_dev;

	if (!IS_ENABLED(CONFIG_RTC_DRV_DS3232_HWMON))
		return;

	hwmon_dev = devm_hwmon_device_register_with_info(dev, name, ds3232,
							&ds3232_hwmon_chip_info,
							NULL);
	if (IS_ERR(hwmon_dev)) {
		dev_err(dev, "unable to register hwmon device %ld\n",
			PTR_ERR(hwmon_dev));
	}
}

__attribute__((used)) static int ds3232_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct ds3232 *ds3232 = dev_get_drvdata(dev);

	if (ds3232->irq <= 0)
		return -EINVAL;

	return ds3232_update_alarm(dev, enabled);
}

__attribute__((used)) static irqreturn_t ds3232_irq(int irq, void *dev_id)
{
	struct device *dev = dev_id;
	struct ds3232 *ds3232 = dev_get_drvdata(dev);
	struct mutex *lock = &ds3232->rtc->ops_lock;
	int ret;
	int stat, control;

	mutex_lock(lock);

	ret = regmap_read(ds3232->regmap, DS3232_REG_SR, &stat);
	if (ret)
		goto unlock;

	if (stat & DS3232_REG_SR_A1F) {
		ret = regmap_read(ds3232->regmap, DS3232_REG_CR, &control);
		if (ret) {
			dev_warn(ds3232->dev,
				 "Read Control Register error %d\n", ret);
		} else {
			/* disable alarm1 interrupt */
			control &= ~(DS3232_REG_CR_A1IE);
			ret = regmap_write(ds3232->regmap, DS3232_REG_CR,
					   control);
			if (ret) {
				dev_warn(ds3232->dev,
					 "Write Control Register error %d\n",
					 ret);
				goto unlock;
			}

			/* clear the alarm pend flag */
			stat &= ~DS3232_REG_SR_A1F;
			ret = regmap_write(ds3232->regmap, DS3232_REG_SR, stat);
			if (ret) {
				dev_warn(ds3232->dev,
					 "Write Status Register error %d\n",
					 ret);
				goto unlock;
			}

			rtc_update_irq(ds3232->rtc, 1, RTC_AF | RTC_IRQF);
		}
	}

unlock:
	mutex_unlock(lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ds3232_probe(struct device *dev, struct regmap *regmap, int irq,
			const char *name)
{
	struct ds3232 *ds3232;
	int ret;

	ds3232 = devm_kzalloc(dev, sizeof(*ds3232), GFP_KERNEL);
	if (!ds3232)
		return -ENOMEM;

	ds3232->regmap = regmap;
	ds3232->irq = irq;
	ds3232->dev = dev;
	dev_set_drvdata(dev, ds3232);

	ret = ds3232_check_rtc_status(dev);
	if (ret)
		return ret;

	if (ds3232->irq > 0)
		device_init_wakeup(dev, 1);

	ds3232_hwmon_register(dev, name);

	ds3232->rtc = devm_rtc_device_register(dev, name, &ds3232_rtc_ops,
						THIS_MODULE);
	if (IS_ERR(ds3232->rtc))
		return PTR_ERR(ds3232->rtc);

	if (ds3232->irq > 0) {
		ret = devm_request_threaded_irq(dev, ds3232->irq, NULL,
						ds3232_irq,
						IRQF_SHARED | IRQF_ONESHOT,
						name, dev);
		if (ret) {
			device_set_wakeup_capable(dev, 0);
			ds3232->irq = 0;
			dev_err(dev, "unable to request IRQ\n");
		}
	}

	return 0;
}

__attribute__((used)) static int ds3232_register_driver(void)
{
	return 0;
}

__attribute__((used)) static void ds3232_unregister_driver(void)
{
}

__attribute__((used)) static int ds3234_register_driver(void)
{
	return 0;
}

__attribute__((used)) static void ds3234_unregister_driver(void)
{
}

