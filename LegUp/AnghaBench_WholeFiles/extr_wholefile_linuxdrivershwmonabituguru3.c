#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct sensor_device_attribute_2 {size_t index; int nr; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct device_attribute {int dummy; } ;
struct abituguru3_sensor_info {size_t port; int multiplier; int divisor; int offset; scalar_t__ type; char* name; } ;
struct abituguru3_data {int** settings; int* value; int* alarms; char* sysfs_names; int valid; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; TYPE_5__* sysfs_attr; int /*<<< orphan*/  hwmon_dev; struct abituguru3_sensor_info* sensors; scalar_t__ addr; } ;
typedef  int ssize_t ;
struct TYPE_14__ {int id; struct abituguru3_sensor_info* sensors; } ;
struct TYPE_9__ {char* name; } ;
struct TYPE_11__ {TYPE_1__ attr; } ;
struct TYPE_13__ {TYPE_3__ dev_attr; } ;
struct TYPE_12__ {int index; TYPE_3__ dev_attr; } ;
struct TYPE_10__ {scalar_t__ start; } ;

/* Variables and functions */
 int ABIT_UGURU3_ALARMS_START ; 
 int ABIT_UGURU3_BOARD_ID ; 
 scalar_t__ ABIT_UGURU3_CMD ; 
 scalar_t__ ABIT_UGURU3_DATA ; 
 int /*<<< orphan*/  ABIT_UGURU3_DEBUG (char*,int,...) ; 
 int ABIT_UGURU3_MAX_NO_SENSORS ; 
 int ABIT_UGURU3_MISC_BANK ; 
 char* ABIT_UGURU3_NAME ; 
 int ABIT_UGURU3_SENSORS_BANK ; 
 int ABIT_UGURU3_SETTINGS_BANK ; 
 int ABIT_UGURU3_SETTINGS_START ; 
 int ABIT_UGURU3_STATUS_BUSY ; 
 int ABIT_UGURU3_STATUS_READY_FOR_READ ; 
 int ABIT_UGURU3_SUCCESS ; 
 int ABIT_UGURU3_SYNCHRONIZE_TIMEOUT ; 
 int ABIT_UGURU3_SYSFS_NAMES_LENGTH ; 
 scalar_t__ ABIT_UGURU3_TEMP_SENSOR ; 
 int ABIT_UGURU3_VALUES_START ; 
 int ABIT_UGURU3_WAIT_TIMEOUT ; 
 int ARRAY_SIZE (TYPE_6__*) ; 
 int EIO ; 
 int ENAMETOOLONG ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_7__* abituguru3_motherboards ; 
 TYPE_6__* abituguru3_sysfs_attr ; 
 TYPE_5__** abituguru3_sysfs_templ ; 
static  struct abituguru3_data* abituguru3_update_device (struct device*) ; 
 struct abituguru3_data* dev_get_drvdata (struct device*) ; 
 scalar_t__ device_create_file (struct device*,TYPE_3__*) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,TYPE_3__*) ; 
 struct abituguru3_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hwmon_device_register (struct device*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int inb_p (scalar_t__) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int never_happen ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 struct abituguru3_data* platform_get_drvdata (struct platform_device*) ; 
 TYPE_2__* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct abituguru3_data*) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned int) ; 
 int /*<<< orphan*/  report_this ; 
 int snprintf (char*,int,char*,int) ; 
 int sprintf (char*,char*,...) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static int abituguru3_wait_while_busy(struct abituguru3_data *data)
{
	u8 x;
	int timeout = ABIT_UGURU3_WAIT_TIMEOUT;

	while ((x = inb_p(data->addr + ABIT_UGURU3_DATA)) &
			ABIT_UGURU3_STATUS_BUSY) {
		timeout--;
		if (timeout == 0)
			return x;
		/*
		 * sleep a bit before our last try, to give the uGuru3 one
		 * last chance to respond.
		 */
		if (timeout == 1)
			msleep(1);
	}
	return ABIT_UGURU3_SUCCESS;
}

__attribute__((used)) static int abituguru3_wait_for_read(struct abituguru3_data *data)
{
	u8 x;
	int timeout = ABIT_UGURU3_WAIT_TIMEOUT;

	while (!((x = inb_p(data->addr + ABIT_UGURU3_DATA)) &
			ABIT_UGURU3_STATUS_READY_FOR_READ)) {
		timeout--;
		if (timeout == 0)
			return x;
		/*
		 * sleep a bit before our last try, to give the uGuru3 one
		 * last chance to respond.
		 */
		if (timeout == 1)
			msleep(1);
	}
	return ABIT_UGURU3_SUCCESS;
}

__attribute__((used)) static int abituguru3_synchronize(struct abituguru3_data *data)
{
	int x, timeout = ABIT_UGURU3_SYNCHRONIZE_TIMEOUT;

	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("synchronize timeout during initial busy "
			"wait, status: 0x%02x\n", x);
		return -EIO;
	}

	outb(0x20, data->addr + ABIT_UGURU3_DATA);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("synchronize timeout after sending 0x20, "
			"status: 0x%02x\n", x);
		return -EIO;
	}

	outb(0x10, data->addr + ABIT_UGURU3_CMD);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("synchronize timeout after sending 0x10, "
			"status: 0x%02x\n", x);
		return -EIO;
	}

	outb(0x00, data->addr + ABIT_UGURU3_CMD);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("synchronize timeout after sending 0x00, "
			"status: 0x%02x\n", x);
		return -EIO;
	}

	x = abituguru3_wait_for_read(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("synchronize timeout waiting for read, "
			"status: 0x%02x\n", x);
		return -EIO;
	}

	while ((x = inb(data->addr + ABIT_UGURU3_CMD)) != 0xAC) {
		timeout--;
		if (timeout == 0) {
			ABIT_UGURU3_DEBUG("synchronize timeout cmd does not "
				"hold 0xAC after synchronize, cmd: 0x%02x\n",
				x);
			return -EIO;
		}
		msleep(1);
	}
	return 0;
}

__attribute__((used)) static int abituguru3_read(struct abituguru3_data *data, u8 bank, u8 offset,
	u8 count, u8 *buf)
{
	int i, x;

	x = abituguru3_synchronize(data);
	if (x)
		return x;

	outb(0x1A, data->addr + ABIT_UGURU3_DATA);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("read from 0x%02x:0x%02x timed out after "
			"sending 0x1A, status: 0x%02x\n", (unsigned int)bank,
			(unsigned int)offset, x);
		return -EIO;
	}

	outb(bank, data->addr + ABIT_UGURU3_CMD);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("read from 0x%02x:0x%02x timed out after "
			"sending the bank, status: 0x%02x\n",
			(unsigned int)bank, (unsigned int)offset, x);
		return -EIO;
	}

	outb(offset, data->addr + ABIT_UGURU3_CMD);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("read from 0x%02x:0x%02x timed out after "
			"sending the offset, status: 0x%02x\n",
			(unsigned int)bank, (unsigned int)offset, x);
		return -EIO;
	}

	outb(count, data->addr + ABIT_UGURU3_CMD);
	x = abituguru3_wait_while_busy(data);
	if (x != ABIT_UGURU3_SUCCESS) {
		ABIT_UGURU3_DEBUG("read from 0x%02x:0x%02x timed out after "
			"sending the count, status: 0x%02x\n",
			(unsigned int)bank, (unsigned int)offset, x);
		return -EIO;
	}

	for (i = 0; i < count; i++) {
		x = abituguru3_wait_for_read(data);
		if (x != ABIT_UGURU3_SUCCESS) {
			ABIT_UGURU3_DEBUG("timeout reading byte %d from "
				"0x%02x:0x%02x, status: 0x%02x\n", i,
				(unsigned int)bank, (unsigned int)offset, x);
			break;
		}
		buf[i] = inb(data->addr + ABIT_UGURU3_CMD);
	}
	return i;
}

__attribute__((used)) static int abituguru3_read_increment_offset(struct abituguru3_data *data,
					    u8 bank, u8 offset, u8 count,
					    u8 *buf, int offset_count)
{
	int i, x;

	for (i = 0; i < offset_count; i++) {
		x = abituguru3_read(data, bank, offset + i, count,
				    buf + i * count);
		if (x != count) {
			if (x < 0)
				return x;
			return i * count + x;
		}
	}

	return i * count;
}

__attribute__((used)) static ssize_t show_value(struct device *dev,
	struct device_attribute *devattr, char *buf)
{
	int value;
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct abituguru3_data *data = abituguru3_update_device(dev);
	const struct abituguru3_sensor_info *sensor;

	if (!data)
		return -EIO;

	sensor = &data->sensors[attr->index];

	/* are we reading a setting, or is this a normal read? */
	if (attr->nr)
		value = data->settings[sensor->port][attr->nr];
	else
		value = data->value[sensor->port];

	/* convert the value */
	value = (value * sensor->multiplier) / sensor->divisor +
		sensor->offset;

	/*
	 * alternatively we could update the sensors settings struct for this,
	 * but then its contents would differ from the windows sw ini files
	 */
	if (sensor->type == ABIT_UGURU3_TEMP_SENSOR)
		value *= 1000;

	return sprintf(buf, "%d\n", value);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev,
	struct device_attribute *devattr, char *buf)
{
	int port;
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct abituguru3_data *data = abituguru3_update_device(dev);

	if (!data)
		return -EIO;

	port = data->sensors[attr->index].port;

	/*
	 * See if the alarm bit for this sensor is set and if a bitmask is
	 * given in attr->nr also check if the alarm matches the type of alarm
	 * we're looking for (for volt it can be either low or high). The type
	 * is stored in a few readonly bits in the settings of the sensor.
	 */
	if ((data->alarms[port / 8] & (0x01 << (port % 8))) &&
			(!attr->nr || (data->settings[port][0] & attr->nr)))
		return sprintf(buf, "1\n");
	else
		return sprintf(buf, "0\n");
}

__attribute__((used)) static ssize_t show_mask(struct device *dev,
	struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct abituguru3_data *data = dev_get_drvdata(dev);

	if (data->settings[data->sensors[attr->index].port][0] & attr->nr)
		return sprintf(buf, "1\n");
	else
		return sprintf(buf, "0\n");
}

__attribute__((used)) static ssize_t show_label(struct device *dev,
	struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct abituguru3_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%s\n", data->sensors[attr->index].name);
}

__attribute__((used)) static ssize_t show_name(struct device *dev,
	struct device_attribute *devattr, char *buf)
{
	return sprintf(buf, "%s\n", ABIT_UGURU3_NAME);
}

__attribute__((used)) static int abituguru3_probe(struct platform_device *pdev)
{
	const int no_sysfs_attr[3] = { 10, 8, 7 };
	int sensor_index[3] = { 0, 1, 1 };
	struct abituguru3_data *data;
	int i, j, type, used, sysfs_names_free, sysfs_attr_i, res = -ENODEV;
	char *sysfs_filename;
	u8 buf[2];
	u16 id;

	data = devm_kzalloc(&pdev->dev, sizeof(struct abituguru3_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
	mutex_init(&data->update_lock);
	platform_set_drvdata(pdev, data);

	/* Read the motherboard ID */
	i = abituguru3_read(data, ABIT_UGURU3_MISC_BANK, ABIT_UGURU3_BOARD_ID,
			    2, buf);
	if (i != 2)
		goto abituguru3_probe_error;

	/* Completely read the uGuru to see if one really is there */
	if (!abituguru3_update_device(&pdev->dev))
		goto abituguru3_probe_error;

	/* lookup the ID in our motherboard table */
	id = ((u16)buf[0] << 8) | (u16)buf[1];
	for (i = 0; abituguru3_motherboards[i].id; i++)
		if (abituguru3_motherboards[i].id == id)
			break;
	if (!abituguru3_motherboards[i].id) {
		pr_err("error unknown motherboard ID: %04X. %s\n",
		       (unsigned int)id, report_this);
		goto abituguru3_probe_error;
	}
	data->sensors = abituguru3_motherboards[i].sensors;

	pr_info("found Abit uGuru3, motherboard ID: %04X\n", (unsigned int)id);

	/* Fill the sysfs attr array */
	sysfs_attr_i = 0;
	sysfs_filename = data->sysfs_names;
	sysfs_names_free = ABIT_UGURU3_SYSFS_NAMES_LENGTH;
	for (i = 0; data->sensors[i].name; i++) {
		/* Fail safe check, this should never happen! */
		if (i >= ABIT_UGURU3_MAX_NO_SENSORS) {
			pr_err("Fatal error motherboard has more sensors then ABIT_UGURU3_MAX_NO_SENSORS. %s %s\n",
			       never_happen, report_this);
			res = -ENAMETOOLONG;
			goto abituguru3_probe_error;
		}
		type = data->sensors[i].type;
		for (j = 0; j < no_sysfs_attr[type]; j++) {
			used = snprintf(sysfs_filename, sysfs_names_free,
				abituguru3_sysfs_templ[type][j].dev_attr.attr.
				name, sensor_index[type]) + 1;
			data->sysfs_attr[sysfs_attr_i] =
				abituguru3_sysfs_templ[type][j];
			data->sysfs_attr[sysfs_attr_i].dev_attr.attr.name =
				sysfs_filename;
			data->sysfs_attr[sysfs_attr_i].index = i;
			sysfs_filename += used;
			sysfs_names_free -= used;
			sysfs_attr_i++;
		}
		sensor_index[type]++;
	}
	/* Fail safe check, this should never happen! */
	if (sysfs_names_free < 0) {
		pr_err("Fatal error ran out of space for sysfs attr names. %s %s\n",
		       never_happen, report_this);
		res = -ENAMETOOLONG;
		goto abituguru3_probe_error;
	}

	/* Register sysfs hooks */
	for (i = 0; i < sysfs_attr_i; i++)
		if (device_create_file(&pdev->dev,
				&data->sysfs_attr[i].dev_attr))
			goto abituguru3_probe_error;
	for (i = 0; i < ARRAY_SIZE(abituguru3_sysfs_attr); i++)
		if (device_create_file(&pdev->dev,
				&abituguru3_sysfs_attr[i].dev_attr))
			goto abituguru3_probe_error;

	data->hwmon_dev = hwmon_device_register(&pdev->dev);
	if (IS_ERR(data->hwmon_dev)) {
		res = PTR_ERR(data->hwmon_dev);
		goto abituguru3_probe_error;
	}

	return 0; /* success */

abituguru3_probe_error:
	for (i = 0; data->sysfs_attr[i].dev_attr.attr.name; i++)
		device_remove_file(&pdev->dev, &data->sysfs_attr[i].dev_attr);
	for (i = 0; i < ARRAY_SIZE(abituguru3_sysfs_attr); i++)
		device_remove_file(&pdev->dev,
			&abituguru3_sysfs_attr[i].dev_attr);
	return res;
}

__attribute__((used)) static int abituguru3_remove(struct platform_device *pdev)
{
	int i;
	struct abituguru3_data *data = platform_get_drvdata(pdev);

	hwmon_device_unregister(data->hwmon_dev);
	for (i = 0; data->sysfs_attr[i].dev_attr.attr.name; i++)
		device_remove_file(&pdev->dev, &data->sysfs_attr[i].dev_attr);
	for (i = 0; i < ARRAY_SIZE(abituguru3_sysfs_attr); i++)
		device_remove_file(&pdev->dev,
			&abituguru3_sysfs_attr[i].dev_attr);
	return 0;
}

__attribute__((used)) static struct abituguru3_data *abituguru3_update_device(struct device *dev)
{
	int i;
	struct abituguru3_data *data = dev_get_drvdata(dev);

	mutex_lock(&data->update_lock);
	if (!data->valid || time_after(jiffies, data->last_updated + HZ)) {
		/* Clear data->valid while updating */
		data->valid = 0;
		/* Read alarms */
		if (abituguru3_read_increment_offset(data,
				ABIT_UGURU3_SETTINGS_BANK,
				ABIT_UGURU3_ALARMS_START,
				1, data->alarms, 48/8) != (48/8))
			goto LEAVE_UPDATE;
		/* Read in and temp sensors (3 byte settings / sensor) */
		for (i = 0; i < 32; i++) {
			if (abituguru3_read(data, ABIT_UGURU3_SENSORS_BANK,
					ABIT_UGURU3_VALUES_START + i,
					1, &data->value[i]) != 1)
				goto LEAVE_UPDATE;
			if (abituguru3_read_increment_offset(data,
					ABIT_UGURU3_SETTINGS_BANK,
					ABIT_UGURU3_SETTINGS_START + i * 3,
					1,
					data->settings[i], 3) != 3)
				goto LEAVE_UPDATE;
		}
		/* Read temp sensors (2 byte settings / sensor) */
		for (i = 0; i < 16; i++) {
			if (abituguru3_read(data, ABIT_UGURU3_SENSORS_BANK,
					ABIT_UGURU3_VALUES_START + 32 + i,
					1, &data->value[32 + i]) != 1)
				goto LEAVE_UPDATE;
			if (abituguru3_read_increment_offset(data,
					ABIT_UGURU3_SETTINGS_BANK,
					ABIT_UGURU3_SETTINGS_START + 32 * 3 +
						i * 2, 1,
					data->settings[32 + i], 2) != 2)
				goto LEAVE_UPDATE;
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}
LEAVE_UPDATE:
	mutex_unlock(&data->update_lock);
	if (data->valid)
		return data;
	else
		return NULL;
}

