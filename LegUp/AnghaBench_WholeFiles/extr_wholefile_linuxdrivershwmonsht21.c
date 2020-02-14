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
struct sht21 {int valid; int temperature; int humidity; int /*<<< orphan*/  lock; struct i2c_client* client; scalar_t__* eic; scalar_t__ last_update; } ;
struct i2c_msg {int len; int* buf; int /*<<< orphan*/  flags; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int SHT21_READ_SNAC_CMD1 ; 
 int SHT21_READ_SNAC_CMD2 ; 
 int SHT21_READ_SNB_CMD1 ; 
 int SHT21_READ_SNB_CMD2 ; 
 int /*<<< orphan*/  SHT21_TRIG_RH_MEASUREMENT_HM ; 
 int /*<<< orphan*/  SHT21_TRIG_T_MEASUREMENT_HM ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct sht21* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct sht21*,int /*<<< orphan*/ ) ; 
 struct sht21* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memcpy (char*,scalar_t__*,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sht21_groups ; 
 int snprintf (scalar_t__*,int,char*,int,int,int,int,int,int,int,int) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline int sht21_temp_ticks_to_millicelsius(int ticks)
{
	ticks &= ~0x0003; /* clear status bits */
	/*
	 * Formula T = -46.85 + 175.72 * ST / 2^16 from data sheet 6.2,
	 * optimized for integer fixed point (3 digits) arithmetic
	 */
	return ((21965 * ticks) >> 13) - 46850;
}

__attribute__((used)) static inline int sht21_rh_ticks_to_per_cent_mille(int ticks)
{
	ticks &= ~0x0003; /* clear status bits */
	/*
	 * Formula RH = -6 + 125 * SRH / 2^16 from data sheet 6.1,
	 * optimized for integer fixed point (3 digits) arithmetic
	 */
	return ((15625 * ticks) >> 13) - 6000;
}

__attribute__((used)) static int sht21_update_measurements(struct device *dev)
{
	int ret = 0;
	struct sht21 *sht21 = dev_get_drvdata(dev);
	struct i2c_client *client = sht21->client;

	mutex_lock(&sht21->lock);
	/*
	 * Data sheet 2.4:
	 * SHT2x should not be active for more than 10% of the time - e.g.
	 * maximum two measurements per second at 12bit accuracy shall be made.
	 */
	if (time_after(jiffies, sht21->last_update + HZ / 2) || !sht21->valid) {
		ret = i2c_smbus_read_word_swapped(client,
						  SHT21_TRIG_T_MEASUREMENT_HM);
		if (ret < 0)
			goto out;
		sht21->temperature = sht21_temp_ticks_to_millicelsius(ret);
		ret = i2c_smbus_read_word_swapped(client,
						  SHT21_TRIG_RH_MEASUREMENT_HM);
		if (ret < 0)
			goto out;
		sht21->humidity = sht21_rh_ticks_to_per_cent_mille(ret);
		sht21->last_update = jiffies;
		sht21->valid = 1;
	}
out:
	mutex_unlock(&sht21->lock);

	return ret >= 0 ? 0 : ret;
}

__attribute__((used)) static ssize_t sht21_show_temperature(struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	struct sht21 *sht21 = dev_get_drvdata(dev);
	int ret;

	ret = sht21_update_measurements(dev);
	if (ret < 0)
		return ret;
	return sprintf(buf, "%d\n", sht21->temperature);
}

__attribute__((used)) static ssize_t sht21_show_humidity(struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	struct sht21 *sht21 = dev_get_drvdata(dev);
	int ret;

	ret = sht21_update_measurements(dev);
	if (ret < 0)
		return ret;
	return sprintf(buf, "%d\n", sht21->humidity);
}

__attribute__((used)) static ssize_t eic_read(struct sht21 *sht21)
{
	struct i2c_client *client = sht21->client;
	u8 tx[2];
	u8 rx[8];
	u8 eic[8];
	struct i2c_msg msgs[2] = {
		{
			.addr = client->addr,
			.flags = 0,
			.len = 2,
			.buf = tx,
		},
		{
			.addr = client->addr,
			.flags = I2C_M_RD,
			.len = 8,
			.buf = rx,
		},
	};
	int ret;

	tx[0] = SHT21_READ_SNB_CMD1;
	tx[1] = SHT21_READ_SNB_CMD2;
	ret = i2c_transfer(client->adapter, msgs, 2);
	if (ret < 0)
		goto out;
	eic[2] = rx[0];
	eic[3] = rx[2];
	eic[4] = rx[4];
	eic[5] = rx[6];

	tx[0] = SHT21_READ_SNAC_CMD1;
	tx[1] = SHT21_READ_SNAC_CMD2;
	msgs[1].len = 6;
	ret = i2c_transfer(client->adapter, msgs, 2);
	if (ret < 0)
		goto out;
	eic[0] = rx[3];
	eic[1] = rx[4];
	eic[6] = rx[0];
	eic[7] = rx[1];

	ret = snprintf(sht21->eic, sizeof(sht21->eic),
		       "%02x%02x%02x%02x%02x%02x%02x%02x\n",
		       eic[0], eic[1], eic[2], eic[3],
		       eic[4], eic[5], eic[6], eic[7]);
out:
	if (ret < 0)
		sht21->eic[0] = 0;

	return ret;
}

__attribute__((used)) static ssize_t eic_show(struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	struct sht21 *sht21 = dev_get_drvdata(dev);
	int ret;

	ret = sizeof(sht21->eic) - 1;
	mutex_lock(&sht21->lock);
	if (!sht21->eic[0])
		ret = eic_read(sht21);
	if (ret > 0)
		memcpy(buf, sht21->eic, ret);
	mutex_unlock(&sht21->lock);
	return ret;
}

__attribute__((used)) static int sht21_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct sht21 *sht21;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_WORD_DATA)) {
		dev_err(&client->dev,
			"adapter does not support SMBus word transactions\n");
		return -ENODEV;
	}

	sht21 = devm_kzalloc(dev, sizeof(*sht21), GFP_KERNEL);
	if (!sht21)
		return -ENOMEM;

	sht21->client = client;

	mutex_init(&sht21->lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   sht21, sht21_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

