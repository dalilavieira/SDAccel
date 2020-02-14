#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct device {int dummy; } ;
struct spi_device {int mode; int bits_per_word; scalar_t__ irq; struct device dev; } ;
struct TYPE_13__ {scalar_t__ tm_sec; scalar_t__ tm_min; scalar_t__ tm_hour; scalar_t__ tm_mday; } ;
struct rtc_wkalrm {int enabled; int pending; TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct regmap_config {int reg_bits; int val_bits; int write_flag_mask; } ;
struct nvmem_config {char* name; int word_size; int stride; int (* reg_read ) (void*,unsigned int,void*,size_t) ;int (* reg_write ) (void*,unsigned int,void*,size_t) ;struct ds1343_priv* priv; int /*<<< orphan*/  size; } ;
struct ds1343_priv {int alarm_sec; int irqen; int alarm_min; int alarm_hour; int alarm_mday; scalar_t__ irq; int /*<<< orphan*/  mutex; TYPE_2__* rtc; TYPE_2__* map; struct spi_device* spi; } ;
struct device_attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_14__ {int nvram_old_abi; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 unsigned int DS1343_A0IE ; 
 unsigned int DS1343_A1IE ; 
 int /*<<< orphan*/  DS1343_ALM0_SEC_REG ; 
 int /*<<< orphan*/  DS1343_CONTROL_REG ; 
 int /*<<< orphan*/  DS1343_DATE_REG ; 
 int /*<<< orphan*/  DS1343_DAY_REG ; 
 int DS1343_EGFIL ; 
 unsigned int DS1343_EOSC ; 
 int /*<<< orphan*/  DS1343_HOURS_REG ; 
 unsigned int DS1343_INTCN ; 
 unsigned int DS1343_IRQF0 ; 
 unsigned int DS1343_IRQF1 ; 
 int /*<<< orphan*/  DS1343_MINUTES_REG ; 
 int /*<<< orphan*/  DS1343_MONTH_REG ; 
 scalar_t__ DS1343_NVRAM ; 
 int /*<<< orphan*/  DS1343_NVRAM_LEN ; 
 unsigned int DS1343_OSF ; 
 int /*<<< orphan*/  DS1343_SECONDS_REG ; 
 int /*<<< orphan*/  DS1343_STATUS_REG ; 
#define  DS1343_TRICKLE_1K 131 
#define  DS1343_TRICKLE_2K 130 
#define  DS1343_TRICKLE_4K 129 
#define  DS1343_TRICKLE_DS1 128 
 int DS1343_TRICKLE_MAGIC ; 
 int /*<<< orphan*/  DS1343_TRICKLE_REG ; 
 int /*<<< orphan*/  DS1343_YEAR_REG ; 
 size_t EINVAL ; 
 int ENOIOCTLCMD ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (TYPE_2__*) ; 
 int PTR_ERR (TYPE_2__*) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int RTC_UF ; 
 int SPI_CS_HIGH ; 
 int SPI_MODE_3 ; 
 void* bcd2bin (unsigned char) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_attr_glitch_filter ; 
 int /*<<< orphan*/  dev_attr_trickle_charger ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ds1343_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_pm_clear_wake_irq (struct device*) ; 
 int /*<<< orphan*/  dev_pm_set_wake_irq (struct device*,scalar_t__) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_free_irq (struct device*,scalar_t__,struct ds1343_priv*) ; 
 struct ds1343_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 TYPE_2__* devm_regmap_init_spi (struct spi_device*,struct regmap_config*) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct ds1343_priv*) ; 
 TYPE_2__* devm_rtc_allocate_device (struct device*) ; 
 int /*<<< orphan*/  ds1343_rtc_ops ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (TYPE_2__*,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_bulk_write (TYPE_2__*,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int regmap_read (TYPE_2__*,int /*<<< orphan*/ ,...) ; 
 int regmap_write (TYPE_2__*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  rtc_nvmem_register (TYPE_2__*,struct nvmem_config*) ; 
 int rtc_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_2__*,int,int) ; 
 struct ds1343_priv* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ds1343_priv*) ; 
 int spi_setup (struct spi_device*) ; 
 size_t sprintf (char*,char*,...) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 

__attribute__((used)) static int ds1343_ioctl(struct device *dev, unsigned int cmd, unsigned long arg)
{
	switch (cmd) {
#ifdef RTC_SET_CHARGE
	case RTC_SET_CHARGE:
	{
		int val;

		if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
			return -EFAULT;

		return regmap_write(priv->map, DS1343_TRICKLE_REG, val);
	}
	break;
#endif
	}

	return -ENOIOCTLCMD;
}

__attribute__((used)) static ssize_t ds1343_show_glitchfilter(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int glitch_filt_status, data;

	regmap_read(priv->map, DS1343_CONTROL_REG, &data);

	glitch_filt_status = !!(data & DS1343_EGFIL);

	if (glitch_filt_status)
		return sprintf(buf, "enabled\n");
	else
		return sprintf(buf, "disabled\n");
}

__attribute__((used)) static ssize_t ds1343_store_glitchfilter(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int data;

	regmap_read(priv->map, DS1343_CONTROL_REG, &data);

	if (strncmp(buf, "enabled", 7) == 0)
		data |= DS1343_EGFIL;

	else if (strncmp(buf, "disabled", 8) == 0)
		data &= ~(DS1343_EGFIL);

	else
		return -EINVAL;

	regmap_write(priv->map, DS1343_CONTROL_REG, data);

	return count;
}

__attribute__((used)) static int ds1343_nvram_write(void *priv, unsigned int off, void *val,
			      size_t bytes)
{
	struct ds1343_priv *ds1343 = priv;

	return regmap_bulk_write(ds1343->map, DS1343_NVRAM + off, val, bytes);
}

__attribute__((used)) static int ds1343_nvram_read(void *priv, unsigned int off, void *val,
			     size_t bytes)
{
	struct ds1343_priv *ds1343 = priv;

	return regmap_bulk_read(ds1343->map, DS1343_NVRAM + off, val, bytes);
}

__attribute__((used)) static ssize_t ds1343_show_tricklecharger(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int data;
	char *diodes = "disabled", *resistors = " ";

	regmap_read(priv->map, DS1343_TRICKLE_REG, &data);

	if ((data & 0xf0) == DS1343_TRICKLE_MAGIC) {
		switch (data & 0x0c) {
		case DS1343_TRICKLE_DS1:
			diodes = "one diode,";
			break;

		default:
			diodes = "no diode,";
			break;
		}

		switch (data & 0x03) {
		case DS1343_TRICKLE_1K:
			resistors = "1k Ohm";
			break;

		case DS1343_TRICKLE_2K:
			resistors = "2k Ohm";
			break;

		case DS1343_TRICKLE_4K:
			resistors = "4k Ohm";
			break;

		default:
			diodes = "disabled";
			break;
		}
	}

	return sprintf(buf, "%s %s\n", diodes, resistors);
}

__attribute__((used)) static int ds1343_sysfs_register(struct device *dev)
{
	int err;

	err = device_create_file(dev, &dev_attr_glitch_filter);
	if (err)
		return err;

	err = device_create_file(dev, &dev_attr_trickle_charger);
	if (!err)
		return 0;

	device_remove_file(dev, &dev_attr_glitch_filter);

	return err;
}

__attribute__((used)) static void ds1343_sysfs_unregister(struct device *dev)
{
	device_remove_file(dev, &dev_attr_glitch_filter);
	device_remove_file(dev, &dev_attr_trickle_charger);
}

__attribute__((used)) static int ds1343_read_time(struct device *dev, struct rtc_time *dt)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	unsigned char buf[7];
	int res;

	res = regmap_bulk_read(priv->map, DS1343_SECONDS_REG, buf, 7);
	if (res)
		return res;

	dt->tm_sec	= bcd2bin(buf[0]);
	dt->tm_min	= bcd2bin(buf[1]);
	dt->tm_hour	= bcd2bin(buf[2] & 0x3F);
	dt->tm_wday	= bcd2bin(buf[3]) - 1;
	dt->tm_mday	= bcd2bin(buf[4]);
	dt->tm_mon	= bcd2bin(buf[5] & 0x1F) - 1;
	dt->tm_year	= bcd2bin(buf[6]) + 100; /* year offset from 1900 */

	return 0;
}

__attribute__((used)) static int ds1343_set_time(struct device *dev, struct rtc_time *dt)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int res;

	res = regmap_write(priv->map, DS1343_SECONDS_REG,
				bin2bcd(dt->tm_sec));
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_MINUTES_REG,
				bin2bcd(dt->tm_min));
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_HOURS_REG,
				bin2bcd(dt->tm_hour) & 0x3F);
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_DAY_REG,
				bin2bcd(dt->tm_wday + 1));
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_DATE_REG,
				bin2bcd(dt->tm_mday));
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_MONTH_REG,
				bin2bcd(dt->tm_mon + 1));
	if (res)
		return res;

	dt->tm_year %= 100;

	res = regmap_write(priv->map, DS1343_YEAR_REG,
				bin2bcd(dt->tm_year));
	if (res)
		return res;

	return 0;
}

__attribute__((used)) static int ds1343_update_alarm(struct device *dev)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	unsigned int control, stat;
	unsigned char buf[4];
	int res = 0;

	res = regmap_read(priv->map, DS1343_CONTROL_REG, &control);
	if (res)
		return res;

	res = regmap_read(priv->map, DS1343_STATUS_REG, &stat);
	if (res)
		return res;

	control &= ~(DS1343_A0IE);
	stat &= ~(DS1343_IRQF0);

	res = regmap_write(priv->map, DS1343_CONTROL_REG, control);
	if (res)
		return res;

	res = regmap_write(priv->map, DS1343_STATUS_REG, stat);
	if (res)
		return res;

	buf[0] = priv->alarm_sec < 0 || (priv->irqen & RTC_UF) ?
		0x80 : bin2bcd(priv->alarm_sec) & 0x7F;
	buf[1] = priv->alarm_min < 0 || (priv->irqen & RTC_UF) ?
		0x80 : bin2bcd(priv->alarm_min) & 0x7F;
	buf[2] = priv->alarm_hour < 0 || (priv->irqen & RTC_UF) ?
		0x80 : bin2bcd(priv->alarm_hour) & 0x3F;
	buf[3] = priv->alarm_mday < 0 || (priv->irqen & RTC_UF) ?
		0x80 : bin2bcd(priv->alarm_mday) & 0x7F;

	res = regmap_bulk_write(priv->map, DS1343_ALM0_SEC_REG, buf, 4);
	if (res)
		return res;

	if (priv->irqen) {
		control |= DS1343_A0IE;
		res = regmap_write(priv->map, DS1343_CONTROL_REG, control);
	}

	return res;
}

__attribute__((used)) static int ds1343_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int res = 0;
	unsigned int stat;

	if (priv->irq <= 0)
		return -EINVAL;

	mutex_lock(&priv->mutex);

	res = regmap_read(priv->map, DS1343_STATUS_REG, &stat);
	if (res)
		goto out;

	alarm->enabled = !!(priv->irqen & RTC_AF);
	alarm->pending = !!(stat & DS1343_IRQF0);

	alarm->time.tm_sec = priv->alarm_sec < 0 ? 0 : priv->alarm_sec;
	alarm->time.tm_min = priv->alarm_min < 0 ? 0 : priv->alarm_min;
	alarm->time.tm_hour = priv->alarm_hour < 0 ? 0 : priv->alarm_hour;
	alarm->time.tm_mday = priv->alarm_mday < 0 ? 0 : priv->alarm_mday;

out:
	mutex_unlock(&priv->mutex);
	return res;
}

__attribute__((used)) static int ds1343_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int res = 0;

	if (priv->irq <= 0)
		return -EINVAL;

	mutex_lock(&priv->mutex);

	priv->alarm_sec = alarm->time.tm_sec;
	priv->alarm_min = alarm->time.tm_min;
	priv->alarm_hour = alarm->time.tm_hour;
	priv->alarm_mday = alarm->time.tm_mday;

	if (alarm->enabled)
		priv->irqen |= RTC_AF;

	res = ds1343_update_alarm(dev);

	mutex_unlock(&priv->mutex);

	return res;
}

__attribute__((used)) static int ds1343_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct ds1343_priv *priv = dev_get_drvdata(dev);
	int res = 0;

	if (priv->irq <= 0)
		return -EINVAL;

	mutex_lock(&priv->mutex);

	if (enabled)
		priv->irqen |= RTC_AF;
	else
		priv->irqen &= ~RTC_AF;

	res = ds1343_update_alarm(dev);

	mutex_unlock(&priv->mutex);

	return res;
}

__attribute__((used)) static irqreturn_t ds1343_thread(int irq, void *dev_id)
{
	struct ds1343_priv *priv = dev_id;
	unsigned int stat, control;
	int res = 0;

	mutex_lock(&priv->mutex);

	res = regmap_read(priv->map, DS1343_STATUS_REG, &stat);
	if (res)
		goto out;

	if (stat & DS1343_IRQF0) {
		stat &= ~DS1343_IRQF0;
		regmap_write(priv->map, DS1343_STATUS_REG, stat);

		res = regmap_read(priv->map, DS1343_CONTROL_REG, &control);
		if (res)
			goto out;

		control &= ~DS1343_A0IE;
		regmap_write(priv->map, DS1343_CONTROL_REG, control);

		rtc_update_irq(priv->rtc, 1, RTC_AF | RTC_IRQF);
	}

out:
	mutex_unlock(&priv->mutex);
	return IRQ_HANDLED;
}

__attribute__((used)) static int ds1343_probe(struct spi_device *spi)
{
	struct ds1343_priv *priv;
	struct regmap_config config = { .reg_bits = 8, .val_bits = 8,
					.write_flag_mask = 0x80, };
	unsigned int data;
	int res;
	struct nvmem_config nvmem_cfg = {
		.name = "ds1343-",
		.word_size = 1,
		.stride = 1,
		.size = DS1343_NVRAM_LEN,
		.reg_read = ds1343_nvram_read,
		.reg_write = ds1343_nvram_write,
	};

	priv = devm_kzalloc(&spi->dev, sizeof(struct ds1343_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->spi = spi;
	mutex_init(&priv->mutex);

	/* RTC DS1347 works in spi mode 3 and
	 * its chip select is active high
	 */
	spi->mode = SPI_MODE_3 | SPI_CS_HIGH;
	spi->bits_per_word = 8;
	res = spi_setup(spi);
	if (res)
		return res;

	spi_set_drvdata(spi, priv);

	priv->map = devm_regmap_init_spi(spi, &config);

	if (IS_ERR(priv->map)) {
		dev_err(&spi->dev, "spi regmap init failed for rtc ds1343\n");
		return PTR_ERR(priv->map);
	}

	res = regmap_read(priv->map, DS1343_SECONDS_REG, &data);
	if (res)
		return res;

	regmap_read(priv->map, DS1343_CONTROL_REG, &data);
	data |= DS1343_INTCN;
	data &= ~(DS1343_EOSC | DS1343_A1IE | DS1343_A0IE);
	regmap_write(priv->map, DS1343_CONTROL_REG, data);

	regmap_read(priv->map, DS1343_STATUS_REG, &data);
	data &= ~(DS1343_OSF | DS1343_IRQF1 | DS1343_IRQF0);
	regmap_write(priv->map, DS1343_STATUS_REG, data);

	priv->rtc = devm_rtc_allocate_device(&spi->dev);
	if (IS_ERR(priv->rtc))
		return PTR_ERR(priv->rtc);

	priv->rtc->nvram_old_abi = true;
	priv->rtc->ops = &ds1343_rtc_ops;

	res = rtc_register_device(priv->rtc);
	if (res)
		return res;

	nvmem_cfg.priv = priv;
	rtc_nvmem_register(priv->rtc, &nvmem_cfg);

	priv->irq = spi->irq;

	if (priv->irq >= 0) {
		res = devm_request_threaded_irq(&spi->dev, spi->irq, NULL,
						ds1343_thread, IRQF_ONESHOT,
						"ds1343", priv);
		if (res) {
			priv->irq = -1;
			dev_err(&spi->dev,
				"unable to request irq for rtc ds1343\n");
		} else {
			device_init_wakeup(&spi->dev, true);
			dev_pm_set_wake_irq(&spi->dev, spi->irq);
		}
	}

	res = ds1343_sysfs_register(&spi->dev);
	if (res)
		dev_err(&spi->dev,
			"unable to create sysfs entries for rtc ds1343\n");

	return 0;
}

__attribute__((used)) static int ds1343_remove(struct spi_device *spi)
{
	struct ds1343_priv *priv = spi_get_drvdata(spi);

	if (spi->irq) {
		mutex_lock(&priv->mutex);
		priv->irqen &= ~RTC_AF;
		mutex_unlock(&priv->mutex);

		dev_pm_clear_wake_irq(&spi->dev);
		device_init_wakeup(&spi->dev, false);
		devm_free_irq(&spi->dev, spi->irq, priv);
	}

	spi_set_drvdata(spi, NULL);

	ds1343_sysfs_unregister(&spi->dev);

	return 0;
}

