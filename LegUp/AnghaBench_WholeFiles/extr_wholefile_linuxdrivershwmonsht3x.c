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
typedef  size_t u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct sht3x_platform_data {int blocking_io; int high_precision; } ;
struct sht3x_limit_commands {char* read_command; int /*<<< orphan*/  write_command; } ;
struct sht3x_data {size_t mode; char* command; int wait_time; int temperature; int humidity; int* temperature_limits; int* humidity_limits; int /*<<< orphan*/  data_lock; int /*<<< orphan*/  i2c_lock; scalar_t__ platform_data; struct sht3x_platform_data setup; struct i2c_client* client; void* last_update; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct i2c_client {int /*<<< orphan*/  name; struct sht3x_data dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {size_t mode; char* command; int wait_time; int temperature; int humidity; int* temperature_limits; int* humidity_limits; int /*<<< orphan*/  data_lock; int /*<<< orphan*/  i2c_lock; scalar_t__ platform_data; struct sht3x_platform_data setup; struct i2c_client* client; void* last_update; } ;
struct attribute_group {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  buffer ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_2__ {size_t index; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (scalar_t__*) ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct sht3x_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 scalar_t__ IS_ERR (struct sht3x_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct sht3x_data*) ; 
 int PTR_ERR_OR_ZERO (struct sht3x_data*) ; 
 int SHT3X_CMD_LENGTH ; 
 int /*<<< orphan*/  SHT3X_CRC8_INIT ; 
 int SHT3X_CRC8_LEN ; 
 int /*<<< orphan*/  SHT3X_CRC8_POLYNOMIAL ; 
 int /*<<< orphan*/  SHT3X_MAX_HUMIDITY ; 
 int /*<<< orphan*/  SHT3X_MAX_TEMPERATURE ; 
 int /*<<< orphan*/  SHT3X_MIN_HUMIDITY ; 
 int /*<<< orphan*/  SHT3X_MIN_TEMPERATURE ; 
 int SHT3X_NONBLOCKING_WAIT_TIME_HPM ; 
 int SHT3X_NONBLOCKING_WAIT_TIME_LPM ; 
 size_t SHT3X_NUM_LIMIT_CMD ; 
 int SHT3X_RESPONSE_LENGTH ; 
 int SHT3X_WORD_LEN ; 
 scalar_t__ be16_to_cpup (int /*<<< orphan*/ *) ; 
 int clamp_val (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be16 (scalar_t__) ; 
 char crc8 (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crc8_populate_msb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct sht3x_data*,char*) ; 
 struct sht3x_data* dev_get_drvdata (struct sht3x_data*) ; 
 struct sht3x_data* devm_hwmon_device_register_with_groups (struct sht3x_data*,int /*<<< orphan*/ ,struct sht3x_data*,struct attribute_group const**) ; 
 struct sht3x_data* devm_kzalloc (struct sht3x_data*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int i2c_master_send (struct i2c_client*,char const*,int) ; 
 void* jiffies ; 
 int kstrtobool (char const*,int*) ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 int kstrtou16 (char const*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int kstrtou32 (char const*,int /*<<< orphan*/ ,int*) ; 
 struct sht3x_limit_commands* limit_commands ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__* mode_to_update_interval ; 
 void* msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 char** periodic_measure_commands_hpm ; 
 char** periodic_measure_commands_lpm ; 
 int scnprintf (char*,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 char const* sht3x_cmd_break ; 
 char const* sht3x_cmd_clear_status_reg ; 
 int /*<<< orphan*/  sht3x_cmd_heater_off ; 
 int /*<<< orphan*/  sht3x_cmd_heater_on ; 
 char* sht3x_cmd_measure_blocking_hpm ; 
 char* sht3x_cmd_measure_blocking_lpm ; 
 char* sht3x_cmd_measure_nonblocking_hpm ; 
 char* sht3x_cmd_measure_nonblocking_lpm ; 
 char* sht3x_cmd_measure_periodic_mode ; 
 char* sht3x_cmd_read_status_reg ; 
 int /*<<< orphan*/  sht3x_crc8_table ; 
 struct attribute_group** sht3x_groups ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ sts3x ; 
 struct attribute_group** sts3x_groups ; 
 scalar_t__ time_after (void*,void*) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static u8 get_mode_from_update_interval(u16 value)
{
	size_t index;
	u8 number_of_modes = ARRAY_SIZE(mode_to_update_interval);

	if (value == 0)
		return 0;

	/* find next faster update interval */
	for (index = 1; index < number_of_modes; index++) {
		if (mode_to_update_interval[index] <= value)
			return index;
	}

	return number_of_modes - 1;
}

__attribute__((used)) static int sht3x_read_from_command(struct i2c_client *client,
				   struct sht3x_data *data,
				   const char *command,
				   char *buf, int length, u32 wait_time)
{
	int ret;

	mutex_lock(&data->i2c_lock);
	ret = i2c_master_send(client, command, SHT3X_CMD_LENGTH);

	if (ret != SHT3X_CMD_LENGTH) {
		ret = ret < 0 ? ret : -EIO;
		goto out;
	}

	if (wait_time)
		usleep_range(wait_time, wait_time + 1000);

	ret = i2c_master_recv(client, buf, length);
	if (ret != length) {
		ret = ret < 0 ? ret : -EIO;
		goto out;
	}

	ret = 0;
out:
	mutex_unlock(&data->i2c_lock);
	return ret;
}

__attribute__((used)) static int sht3x_extract_temperature(u16 raw)
{
	/*
	 * From datasheet:
	 * T = -45 + 175 * ST / 2^16
	 * Adapted for integer fixed point (3 digit) arithmetic.
	 */
	return ((21875 * (int)raw) >> 13) - 45000;
}

__attribute__((used)) static u32 sht3x_extract_humidity(u16 raw)
{
	/*
	 * From datasheet:
	 * RH = 100 * SRH / 2^16
	 * Adapted for integer fixed point (3 digit) arithmetic.
	 */
	return (12500 * (u32)raw) >> 13;
}

__attribute__((used)) static struct sht3x_data *sht3x_update_client(struct device *dev)
{
	struct sht3x_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u16 interval_ms = mode_to_update_interval[data->mode];
	unsigned long interval_jiffies = msecs_to_jiffies(interval_ms);
	unsigned char buf[SHT3X_RESPONSE_LENGTH];
	u16 val;
	int ret = 0;

	mutex_lock(&data->data_lock);
	/*
	 * Only update cached readings once per update interval in periodic
	 * mode. In single shot mode the sensor measures values on demand, so
	 * every time the sysfs interface is called, a measurement is triggered.
	 * In periodic mode however, the measurement process is handled
	 * internally by the sensor and reading out sensor values only makes
	 * sense if a new reading is available.
	 */
	if (time_after(jiffies, data->last_update + interval_jiffies)) {
		ret = sht3x_read_from_command(client, data, data->command, buf,
					      sizeof(buf), data->wait_time);
		if (ret)
			goto out;

		val = be16_to_cpup((__be16 *)buf);
		data->temperature = sht3x_extract_temperature(val);
		val = be16_to_cpup((__be16 *)(buf + 3));
		data->humidity = sht3x_extract_humidity(val);
		data->last_update = jiffies;
	}

out:
	mutex_unlock(&data->data_lock);
	if (ret)
		return ERR_PTR(ret);

	return data;
}

__attribute__((used)) static ssize_t temp1_input_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct sht3x_data *data = sht3x_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temperature);
}

__attribute__((used)) static ssize_t humidity1_input_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	struct sht3x_data *data = sht3x_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%u\n", data->humidity);
}

__attribute__((used)) static int limits_update(struct sht3x_data *data)
{
	int ret;
	u8 index;
	int temperature;
	u32 humidity;
	u16 raw;
	char buffer[SHT3X_RESPONSE_LENGTH];
	const struct sht3x_limit_commands *commands;
	struct i2c_client *client = data->client;

	for (index = 0; index < SHT3X_NUM_LIMIT_CMD; index++) {
		commands = &limit_commands[index];
		ret = sht3x_read_from_command(client, data,
					      commands->read_command, buffer,
					      SHT3X_RESPONSE_LENGTH, 0);

		if (ret)
			return ret;

		raw = be16_to_cpup((__be16 *)buffer);
		temperature = sht3x_extract_temperature((raw & 0x01ff) << 7);
		humidity = sht3x_extract_humidity(raw & 0xfe00);
		data->temperature_limits[index] = temperature;
		data->humidity_limits[index] = humidity;
	}

	return ret;
}

__attribute__((used)) static ssize_t temp1_limit_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	struct sht3x_data *data = dev_get_drvdata(dev);
	u8 index = to_sensor_dev_attr(attr)->index;
	int temperature_limit = data->temperature_limits[index];

	return scnprintf(buf, PAGE_SIZE, "%d\n", temperature_limit);
}

__attribute__((used)) static ssize_t humidity1_limit_show(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct sht3x_data *data = dev_get_drvdata(dev);
	u8 index = to_sensor_dev_attr(attr)->index;
	u32 humidity_limit = data->humidity_limits[index];

	return scnprintf(buf, PAGE_SIZE, "%u\n", humidity_limit);
}

__attribute__((used)) static size_t limit_store(struct device *dev,
			  size_t count,
			  u8 index,
			  int temperature,
			  u32 humidity)
{
	char buffer[SHT3X_CMD_LENGTH + SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
	char *position = buffer;
	int ret;
	u16 raw;
	struct sht3x_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	const struct sht3x_limit_commands *commands;

	commands = &limit_commands[index];

	memcpy(position, commands->write_command, SHT3X_CMD_LENGTH);
	position += SHT3X_CMD_LENGTH;
	/*
	 * ST = (T + 45) / 175 * 2^16
	 * SRH = RH / 100 * 2^16
	 * adapted for fixed point arithmetic and packed the same as
	 * in limit_show()
	 */
	raw = ((u32)(temperature + 45000) * 24543) >> (16 + 7);
	raw |= ((humidity * 42950) >> 16) & 0xfe00;

	*((__be16 *)position) = cpu_to_be16(raw);
	position += SHT3X_WORD_LEN;
	*position = crc8(sht3x_crc8_table,
			 position - SHT3X_WORD_LEN,
			 SHT3X_WORD_LEN,
			 SHT3X_CRC8_INIT);

	mutex_lock(&data->i2c_lock);
	ret = i2c_master_send(client, buffer, sizeof(buffer));
	mutex_unlock(&data->i2c_lock);

	if (ret != sizeof(buffer))
		return ret < 0 ? ret : -EIO;

	data->temperature_limits[index] = temperature;
	data->humidity_limits[index] = humidity;
	return count;
}

__attribute__((used)) static ssize_t temp1_limit_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf,
				 size_t count)
{
	int temperature;
	int ret;
	struct sht3x_data *data = dev_get_drvdata(dev);
	u8 index = to_sensor_dev_attr(attr)->index;

	ret = kstrtoint(buf, 0, &temperature);
	if (ret)
		return ret;

	temperature = clamp_val(temperature, SHT3X_MIN_TEMPERATURE,
				SHT3X_MAX_TEMPERATURE);
	mutex_lock(&data->data_lock);
	ret = limit_store(dev, count, index, temperature,
			  data->humidity_limits[index]);
	mutex_unlock(&data->data_lock);

	return ret;
}

__attribute__((used)) static ssize_t humidity1_limit_store(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf,
				     size_t count)
{
	u32 humidity;
	int ret;
	struct sht3x_data *data = dev_get_drvdata(dev);
	u8 index = to_sensor_dev_attr(attr)->index;

	ret = kstrtou32(buf, 0, &humidity);
	if (ret)
		return ret;

	humidity = clamp_val(humidity, SHT3X_MIN_HUMIDITY, SHT3X_MAX_HUMIDITY);
	mutex_lock(&data->data_lock);
	ret = limit_store(dev, count, index, data->temperature_limits[index],
			  humidity);
	mutex_unlock(&data->data_lock);

	return ret;
}

__attribute__((used)) static void sht3x_select_command(struct sht3x_data *data)
{
	/*
	 * In blocking mode (clock stretching mode) the I2C bus
	 * is blocked for other traffic, thus the call to i2c_master_recv()
	 * will wait until the data is ready. For non blocking mode, we
	 * have to wait ourselves.
	 */
	if (data->mode > 0) {
		data->command = sht3x_cmd_measure_periodic_mode;
		data->wait_time = 0;
	} else if (data->setup.blocking_io) {
		data->command = data->setup.high_precision ?
				sht3x_cmd_measure_blocking_hpm :
				sht3x_cmd_measure_blocking_lpm;
		data->wait_time = 0;
	} else {
		if (data->setup.high_precision) {
			data->command = sht3x_cmd_measure_nonblocking_hpm;
			data->wait_time = SHT3X_NONBLOCKING_WAIT_TIME_HPM;
		} else {
			data->command = sht3x_cmd_measure_nonblocking_lpm;
			data->wait_time = SHT3X_NONBLOCKING_WAIT_TIME_LPM;
		}
	}
}

__attribute__((used)) static int status_register_read(struct device *dev,
				struct device_attribute *attr,
				char *buffer, int length)
{
	int ret;
	struct sht3x_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	ret = sht3x_read_from_command(client, data, sht3x_cmd_read_status_reg,
				      buffer, length, 0);

	return ret;
}

__attribute__((used)) static ssize_t temp1_alarm_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
	int ret;

	ret = status_register_read(dev, attr, buffer,
				   SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
	if (ret)
		return ret;

	return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x04));
}

__attribute__((used)) static ssize_t humidity1_alarm_show(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
	int ret;

	ret = status_register_read(dev, attr, buffer,
				   SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
	if (ret)
		return ret;

	return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x08));
}

__attribute__((used)) static ssize_t heater_enable_show(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
	int ret;

	ret = status_register_read(dev, attr, buffer,
				   SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
	if (ret)
		return ret;

	return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x20));
}

__attribute__((used)) static ssize_t heater_enable_store(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf,
				   size_t count)
{
	struct sht3x_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int ret;
	bool status;

	ret = kstrtobool(buf, &status);
	if (ret)
		return ret;

	mutex_lock(&data->i2c_lock);

	if (status)
		ret = i2c_master_send(client, (char *)&sht3x_cmd_heater_on,
				      SHT3X_CMD_LENGTH);
	else
		ret = i2c_master_send(client, (char *)&sht3x_cmd_heater_off,
				      SHT3X_CMD_LENGTH);

	mutex_unlock(&data->i2c_lock);

	return ret;
}

__attribute__((used)) static ssize_t update_interval_show(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct sht3x_data *data = dev_get_drvdata(dev);

	return scnprintf(buf, PAGE_SIZE, "%u\n",
			 mode_to_update_interval[data->mode]);
}

__attribute__((used)) static ssize_t update_interval_store(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf,
				     size_t count)
{
	u16 update_interval;
	u8 mode;
	int ret;
	const char *command;
	struct sht3x_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	ret = kstrtou16(buf, 0, &update_interval);
	if (ret)
		return ret;

	mode = get_mode_from_update_interval(update_interval);

	mutex_lock(&data->data_lock);
	/* mode did not change */
	if (mode == data->mode) {
		mutex_unlock(&data->data_lock);
		return count;
	}

	mutex_lock(&data->i2c_lock);
	/*
	 * Abort periodic measure mode.
	 * To do any changes to the configuration while in periodic mode, we
	 * have to send a break command to the sensor, which then falls back
	 * to single shot (mode = 0).
	 */
	if (data->mode > 0) {
		ret = i2c_master_send(client, sht3x_cmd_break,
				      SHT3X_CMD_LENGTH);
		if (ret != SHT3X_CMD_LENGTH)
			goto out;
		data->mode = 0;
	}

	if (mode > 0) {
		if (data->setup.high_precision)
			command = periodic_measure_commands_hpm[mode - 1];
		else
			command = periodic_measure_commands_lpm[mode - 1];

		/* select mode */
		ret = i2c_master_send(client, command, SHT3X_CMD_LENGTH);
		if (ret != SHT3X_CMD_LENGTH)
			goto out;
	}

	/* select mode and command */
	data->mode = mode;
	sht3x_select_command(data);

out:
	mutex_unlock(&data->i2c_lock);
	mutex_unlock(&data->data_lock);
	if (ret != SHT3X_CMD_LENGTH)
		return ret < 0 ? ret : -EIO;

	return count;
}

__attribute__((used)) static int sht3x_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	int ret;
	struct sht3x_data *data;
	struct device *hwmon_dev;
	struct i2c_adapter *adap = client->adapter;
	struct device *dev = &client->dev;
	const struct attribute_group **attribute_groups;

	/*
	 * we require full i2c support since the sht3x uses multi-byte read and
	 * writes as well as multi-byte commands which are not supported by
	 * the smbus protocol
	 */
	if (!i2c_check_functionality(adap, I2C_FUNC_I2C))
		return -ENODEV;

	ret = i2c_master_send(client, sht3x_cmd_clear_status_reg,
			      SHT3X_CMD_LENGTH);
	if (ret != SHT3X_CMD_LENGTH)
		return ret < 0 ? ret : -ENODEV;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->setup.blocking_io = false;
	data->setup.high_precision = true;
	data->mode = 0;
	data->last_update = jiffies - msecs_to_jiffies(3000);
	data->client = client;
	crc8_populate_msb(sht3x_crc8_table, SHT3X_CRC8_POLYNOMIAL);

	if (client->dev.platform_data)
		data->setup = *(struct sht3x_platform_data *)dev->platform_data;

	sht3x_select_command(data);

	mutex_init(&data->i2c_lock);
	mutex_init(&data->data_lock);

	/*
	 * An attempt to read limits register too early
	 * causes a NACK response from the chip.
	 * Waiting for an empirical delay of 500 us solves the issue.
	 */
	usleep_range(500, 600);

	ret = limits_update(data);
	if (ret)
		return ret;

	if (id->driver_data == sts3x)
		attribute_groups = sts3x_groups;
	else
		attribute_groups = sht3x_groups;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev,
							   client->name,
							   data,
							   attribute_groups);

	if (IS_ERR(hwmon_dev))
		dev_dbg(dev, "unable to register hwmon device\n");

	return PTR_ERR_OR_ZERO(hwmon_dev);
}

