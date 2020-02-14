#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct seq_file {int dummy; } ;
struct TYPE_8__ {int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; } ;
struct rtc_wkalrm {int enabled; int pending; TYPE_1__ time; } ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; unsigned char tm_wday; int tm_mon; int tm_year; } ;
struct mutex {int dummy; } ;
struct m41t80_data {int features; TYPE_2__* rtc; struct i2c_client* client; } ;
struct i2c_device_id {unsigned long driver_data; } ;
struct device {scalar_t__ of_node; int /*<<< orphan*/  parent; } ;
struct i2c_client {scalar_t__ irq; struct device dev; int /*<<< orphan*/  adapter; } ;
struct i2c_adapter {struct device dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_10__ {int (* read_alarm ) (struct device*,struct rtc_wkalrm*) ;int (* set_alarm ) (struct device*,struct rtc_wkalrm*) ;int (* alarm_irq_enable ) (struct device*,unsigned int) ;} ;
struct TYPE_9__ {int uie_unsupported; TYPE_4__* ops; struct mutex ops_lock; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (TYPE_2__*) ; 
 int M41T80_ALHOUR_HT ; 
 int M41T80_ALMON_AFE ; 
 int M41T80_ALMON_SQWE ; 
 int M41T80_FEATURE_BL ; 
 int M41T80_FEATURE_HT ; 
 int M41T80_FEATURE_SQ_ALT ; 
 int M41T80_FLAGS_AF ; 
 int M41T80_FLAGS_BATT_LOW ; 
 int M41T80_FLAGS_OF ; 
 size_t M41T80_REG_ALARM_HOUR ; 
 size_t M41T80_REG_ALARM_MON ; 
 size_t M41T80_REG_DAY ; 
 size_t M41T80_REG_FLAGS ; 
 size_t M41T80_REG_HOUR ; 
 size_t M41T80_REG_MIN ; 
 size_t M41T80_REG_MON ; 
 size_t M41T80_REG_SEC ; 
 size_t M41T80_REG_SSEC ; 
 size_t M41T80_REG_WDAY ; 
 size_t M41T80_REG_YEAR ; 
 int M41T80_SEC_ST ; 
 int PTR_ERR (TYPE_2__*) ; 
 unsigned long RTC_AF ; 
 void* bcd2bin (int) ; 
 void* bin2bcd (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct m41t80_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct i2c_client*) ; 
 TYPE_2__* devm_rtc_allocate_device (struct device*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 struct m41t80_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct m41t80_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,size_t) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,size_t,int,...) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,size_t,int) ; 
 int i2c_smbus_write_i2c_block_data (struct i2c_client*,size_t,int,...) ; 
 TYPE_4__ m41t80_rtc_ops ; 
 int /*<<< orphan*/  mutex_lock (struct mutex*) ; 
 int /*<<< orphan*/  mutex_unlock (struct mutex*) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 int rtc_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_2__*,int,unsigned long) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*) ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static irqreturn_t m41t80_handle_irq(int irq, void *dev_id)
{
	struct i2c_client *client = dev_id;
	struct m41t80_data *m41t80 = i2c_get_clientdata(client);
	struct mutex *lock = &m41t80->rtc->ops_lock;
	unsigned long events = 0;
	int flags, flags_afe;

	mutex_lock(lock);

	flags_afe = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
	if (flags_afe < 0) {
		mutex_unlock(lock);
		return IRQ_NONE;
	}

	flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
	if (flags <= 0) {
		mutex_unlock(lock);
		return IRQ_NONE;
	}

	if (flags & M41T80_FLAGS_AF) {
		flags &= ~M41T80_FLAGS_AF;
		flags_afe &= ~M41T80_ALMON_AFE;
		events |= RTC_AF;
	}

	if (events) {
		rtc_update_irq(m41t80->rtc, 1, events);
		i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS, flags);
		i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
					  flags_afe);
	}

	mutex_unlock(lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static int m41t80_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct i2c_client *client = to_i2c_client(dev);
	unsigned char buf[8];
	int err, flags;

	flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
	if (flags < 0)
		return flags;

	if (flags & M41T80_FLAGS_OF) {
		dev_err(&client->dev, "Oscillator failure, data is invalid.\n");
		return -EINVAL;
	}

	err = i2c_smbus_read_i2c_block_data(client, M41T80_REG_SSEC,
					    sizeof(buf), buf);
	if (err < 0) {
		dev_err(&client->dev, "Unable to read date\n");
		return -EIO;
	}

	tm->tm_sec = bcd2bin(buf[M41T80_REG_SEC] & 0x7f);
	tm->tm_min = bcd2bin(buf[M41T80_REG_MIN] & 0x7f);
	tm->tm_hour = bcd2bin(buf[M41T80_REG_HOUR] & 0x3f);
	tm->tm_mday = bcd2bin(buf[M41T80_REG_DAY] & 0x3f);
	tm->tm_wday = buf[M41T80_REG_WDAY] & 0x07;
	tm->tm_mon = bcd2bin(buf[M41T80_REG_MON] & 0x1f) - 1;

	/* assume 20YY not 19YY, and ignore the Century Bit */
	tm->tm_year = bcd2bin(buf[M41T80_REG_YEAR]) + 100;
	return 0;
}

__attribute__((used)) static int m41t80_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct m41t80_data *clientdata = i2c_get_clientdata(client);
	unsigned char buf[8];
	int err, flags;

	if (tm->tm_year < 100 || tm->tm_year > 199)
		return -EINVAL;

	buf[M41T80_REG_SSEC] = 0;
	buf[M41T80_REG_SEC] = bin2bcd(tm->tm_sec);
	buf[M41T80_REG_MIN] = bin2bcd(tm->tm_min);
	buf[M41T80_REG_HOUR] = bin2bcd(tm->tm_hour);
	buf[M41T80_REG_DAY] = bin2bcd(tm->tm_mday);
	buf[M41T80_REG_MON] = bin2bcd(tm->tm_mon + 1);
	buf[M41T80_REG_YEAR] = bin2bcd(tm->tm_year - 100);
	buf[M41T80_REG_WDAY] = tm->tm_wday;

	/* If the square wave output is controlled in the weekday register */
	if (clientdata->features & M41T80_FEATURE_SQ_ALT) {
		int val;

		val = i2c_smbus_read_byte_data(client, M41T80_REG_WDAY);
		if (val < 0)
			return val;

		buf[M41T80_REG_WDAY] |= (val & 0xf0);
	}

	err = i2c_smbus_write_i2c_block_data(client, M41T80_REG_SSEC,
					     sizeof(buf), buf);
	if (err < 0) {
		dev_err(&client->dev, "Unable to write to date registers\n");
		return err;
	}

	/* Clear the OF bit of Flags Register */
	flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
	if (flags < 0)
		return flags;

	if (i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS,
				      flags & ~M41T80_FLAGS_OF)) {
		dev_err(&client->dev, "Unable to write flags register\n");
		return -EIO;
	}

	return err;
}

__attribute__((used)) static int m41t80_rtc_proc(struct device *dev, struct seq_file *seq)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct m41t80_data *clientdata = i2c_get_clientdata(client);
	u8 reg;

	if (clientdata->features & M41T80_FEATURE_BL) {
		reg = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
		seq_printf(seq, "battery\t\t: %s\n",
			   (reg & M41T80_FLAGS_BATT_LOW) ? "exhausted" : "ok");
	}
	return 0;
}

__attribute__((used)) static int m41t80_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct i2c_client *client = to_i2c_client(dev);
	int flags, retval;

	flags = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
	if (flags < 0)
		return flags;

	if (enabled)
		flags |= M41T80_ALMON_AFE;
	else
		flags &= ~M41T80_ALMON_AFE;

	retval = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON, flags);
	if (retval < 0) {
		dev_err(dev, "Unable to enable alarm IRQ %d\n", retval);
		return retval;
	}
	return 0;
}

__attribute__((used)) static int m41t80_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct i2c_client *client = to_i2c_client(dev);
	u8 alarmvals[5];
	int ret, err;

	alarmvals[0] = bin2bcd(alrm->time.tm_mon + 1);
	alarmvals[1] = bin2bcd(alrm->time.tm_mday);
	alarmvals[2] = bin2bcd(alrm->time.tm_hour);
	alarmvals[3] = bin2bcd(alrm->time.tm_min);
	alarmvals[4] = bin2bcd(alrm->time.tm_sec);

	/* Clear AF and AFE flags */
	ret = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
	if (ret < 0)
		return ret;
	err = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
					ret & ~(M41T80_ALMON_AFE));
	if (err < 0) {
		dev_err(dev, "Unable to clear AFE bit\n");
		return err;
	}

	/* Keep SQWE bit value */
	alarmvals[0] |= (ret & M41T80_ALMON_SQWE);

	ret = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
	if (ret < 0)
		return ret;

	err = i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS,
					ret & ~(M41T80_FLAGS_AF));
	if (err < 0) {
		dev_err(dev, "Unable to clear AF bit\n");
		return err;
	}

	/* Write the alarm */
	err = i2c_smbus_write_i2c_block_data(client, M41T80_REG_ALARM_MON,
					     5, alarmvals);
	if (err)
		return err;

	/* Enable the alarm interrupt */
	if (alrm->enabled) {
		alarmvals[0] |= M41T80_ALMON_AFE;
		err = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
						alarmvals[0]);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int m41t80_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct i2c_client *client = to_i2c_client(dev);
	u8 alarmvals[5];
	int flags, ret;

	ret = i2c_smbus_read_i2c_block_data(client, M41T80_REG_ALARM_MON,
					    5, alarmvals);
	if (ret != 5)
		return ret < 0 ? ret : -EIO;

	flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
	if (flags < 0)
		return flags;

	alrm->time.tm_sec  = bcd2bin(alarmvals[4] & 0x7f);
	alrm->time.tm_min  = bcd2bin(alarmvals[3] & 0x7f);
	alrm->time.tm_hour = bcd2bin(alarmvals[2] & 0x3f);
	alrm->time.tm_mday = bcd2bin(alarmvals[1] & 0x3f);
	alrm->time.tm_mon  = bcd2bin(alarmvals[0] & 0x3f) - 1;

	alrm->enabled = !!(alarmvals[0] & M41T80_ALMON_AFE);
	alrm->pending = (flags & M41T80_FLAGS_AF) && alrm->enabled;

	return 0;
}

__attribute__((used)) static int m41t80_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	int rc = 0;
	struct rtc_time tm;
	struct m41t80_data *m41t80_data = NULL;
	bool wakeup_source = false;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_I2C_BLOCK |
				     I2C_FUNC_SMBUS_BYTE_DATA)) {
		dev_err(&adapter->dev, "doesn't support I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_I2C_BLOCK\n");
		return -ENODEV;
	}

	m41t80_data = devm_kzalloc(&client->dev, sizeof(*m41t80_data),
				   GFP_KERNEL);
	if (!m41t80_data)
		return -ENOMEM;

	m41t80_data->client = client;
	if (client->dev.of_node)
		m41t80_data->features = (unsigned long)
			of_device_get_match_data(&client->dev);
	else
		m41t80_data->features = id->driver_data;
	i2c_set_clientdata(client, m41t80_data);

	m41t80_data->rtc =  devm_rtc_allocate_device(&client->dev);
	if (IS_ERR(m41t80_data->rtc))
		return PTR_ERR(m41t80_data->rtc);

#ifdef CONFIG_OF
	wakeup_source = of_property_read_bool(client->dev.of_node,
					      "wakeup-source");
#endif
	if (client->irq > 0) {
		rc = devm_request_threaded_irq(&client->dev, client->irq,
					       NULL, m41t80_handle_irq,
					       IRQF_TRIGGER_LOW | IRQF_ONESHOT,
					       "m41t80", client);
		if (rc) {
			dev_warn(&client->dev, "unable to request IRQ, alarms disabled\n");
			client->irq = 0;
			wakeup_source = false;
		}
	}
	if (client->irq > 0 || wakeup_source) {
		m41t80_rtc_ops.read_alarm = m41t80_read_alarm;
		m41t80_rtc_ops.set_alarm = m41t80_set_alarm;
		m41t80_rtc_ops.alarm_irq_enable = m41t80_alarm_irq_enable;
		/* Enable the wakealarm */
		device_init_wakeup(&client->dev, true);
	}

	m41t80_data->rtc->ops = &m41t80_rtc_ops;

	if (client->irq <= 0) {
		/* We cannot support UIE mode if we do not have an IRQ line */
		m41t80_data->rtc->uie_unsupported = 1;
	}

	/* Make sure HT (Halt Update) bit is cleared */
	rc = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_HOUR);

	if (rc >= 0 && rc & M41T80_ALHOUR_HT) {
		if (m41t80_data->features & M41T80_FEATURE_HT) {
			m41t80_rtc_read_time(&client->dev, &tm);
			dev_info(&client->dev, "HT bit was set!\n");
			dev_info(&client->dev,
				 "Power Down at %04i-%02i-%02i %02i:%02i:%02i\n",
				 tm.tm_year + 1900,
				 tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
				 tm.tm_min, tm.tm_sec);
		}
		rc = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_HOUR,
					       rc & ~M41T80_ALHOUR_HT);
	}

	if (rc < 0) {
		dev_err(&client->dev, "Can't clear HT bit\n");
		return rc;
	}

	/* Make sure ST (stop) bit is cleared */
	rc = i2c_smbus_read_byte_data(client, M41T80_REG_SEC);

	if (rc >= 0 && rc & M41T80_SEC_ST)
		rc = i2c_smbus_write_byte_data(client, M41T80_REG_SEC,
					       rc & ~M41T80_SEC_ST);
	if (rc < 0) {
		dev_err(&client->dev, "Can't clear ST bit\n");
		return rc;
	}

#ifdef CONFIG_RTC_DRV_M41T80_WDT
	if (m41t80_data->features & M41T80_FEATURE_HT) {
		save_client = client;
		rc = misc_register(&wdt_dev);
		if (rc)
			return rc;
		rc = register_reboot_notifier(&wdt_notifier);
		if (rc) {
			misc_deregister(&wdt_dev);
			return rc;
		}
	}
#endif
#ifdef CONFIG_COMMON_CLK
	if (m41t80_data->features & M41T80_FEATURE_SQ)
		m41t80_sqw_register_clk(m41t80_data);
#endif

	rc = rtc_register_device(m41t80_data->rtc);
	if (rc)
		return rc;

	return 0;
}

__attribute__((used)) static int m41t80_remove(struct i2c_client *client)
{
#ifdef CONFIG_RTC_DRV_M41T80_WDT
	struct m41t80_data *clientdata = i2c_get_clientdata(client);

	if (clientdata->features & M41T80_FEATURE_HT) {
		misc_deregister(&wdt_dev);
		unregister_reboot_notifier(&wdt_notifier);
	}
#endif

	return 0;
}

