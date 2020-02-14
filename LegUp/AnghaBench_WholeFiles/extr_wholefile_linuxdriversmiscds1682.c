#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct sensor_device_attribute_2 {scalar_t__ index; size_t nr; } ;
struct kobject {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_2__ dev; int /*<<< orphan*/  adapter; } ;
struct file {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;
struct device_attribute {TYPE_1__ attr; } ;
struct device {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  scalar_t__ loff_t ;
typedef  scalar_t__ __le32 ;

/* Variables and functions */
 scalar_t__ DS1682_REG_EEPROM ; 
 scalar_t__ DS1682_REG_ELAPSED ; 
 size_t EINVAL ; 
 size_t EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_I2C_BLOCK ; 
 scalar_t__ cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  do_div (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ds1682_eeprom_attr ; 
 int /*<<< orphan*/  ds1682_group ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,scalar_t__,size_t,char*) ; 
 scalar_t__ i2c_smbus_write_i2c_block_data (struct i2c_client*,scalar_t__,size_t,char*) ; 
 struct i2c_client* kobj_to_i2c_client (struct kobject*) ; 
 int kstrtoull (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned long long le32_to_cpu (scalar_t__) ; 
 size_t sprintf (char*,char*,unsigned long long) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t ds1682_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
	struct i2c_client *client = to_i2c_client(dev);
	unsigned long long val, check;
	__le32 val_le = 0;
	int rc;

	dev_dbg(dev, "ds1682_show() called on %s\n", attr->attr.name);

	/* Read the register */
	rc = i2c_smbus_read_i2c_block_data(client, sattr->index, sattr->nr,
					   (u8 *)&val_le);
	if (rc < 0)
		return -EIO;

	val = le32_to_cpu(val_le);

	if (sattr->index == DS1682_REG_ELAPSED) {
		int retries = 5;

		/* Detect and retry when a tick occurs mid-read */
		do {
			rc = i2c_smbus_read_i2c_block_data(client, sattr->index,
							   sattr->nr,
							   (u8 *)&val_le);
			if (rc < 0 || retries <= 0)
				return -EIO;

			check = val;
			val = le32_to_cpu(val_le);
			retries--;
		} while (val != check && val != (check + 1));
	}

	/* Format the output string and return # of bytes
	 * Special case: the 32 bit regs are time values with 1/4s
	 * resolution, scale them up to milliseconds
	 */
	return sprintf(buf, "%llu\n", (sattr->nr == 4) ? (val * 250) : val);
}

__attribute__((used)) static ssize_t ds1682_store(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
	struct i2c_client *client = to_i2c_client(dev);
	u64 val;
	__le32 val_le;
	int rc;

	dev_dbg(dev, "ds1682_store() called on %s\n", attr->attr.name);

	/* Decode input */
	rc = kstrtoull(buf, 0, &val);
	if (rc < 0) {
		dev_dbg(dev, "input string not a number\n");
		return -EINVAL;
	}

	/* Special case: the 32 bit regs are time values with 1/4s
	 * resolution, scale input down to quarter-seconds */
	if (sattr->nr == 4)
		do_div(val, 250);

	/* write out the value */
	val_le = cpu_to_le32(val);
	rc = i2c_smbus_write_i2c_block_data(client, sattr->index, sattr->nr,
					    (u8 *) & val_le);
	if (rc < 0) {
		dev_err(dev, "register write failed; reg=0x%x, size=%i\n",
			sattr->index, sattr->nr);
		return -EIO;
	}

	return count;
}

__attribute__((used)) static ssize_t ds1682_eeprom_read(struct file *filp, struct kobject *kobj,
				  struct bin_attribute *attr,
				  char *buf, loff_t off, size_t count)
{
	struct i2c_client *client = kobj_to_i2c_client(kobj);
	int rc;

	dev_dbg(&client->dev, "ds1682_eeprom_read(p=%p, off=%lli, c=%zi)\n",
		buf, off, count);

	rc = i2c_smbus_read_i2c_block_data(client, DS1682_REG_EEPROM + off,
					   count, buf);
	if (rc < 0)
		return -EIO;

	return count;
}

__attribute__((used)) static ssize_t ds1682_eeprom_write(struct file *filp, struct kobject *kobj,
				   struct bin_attribute *attr,
				   char *buf, loff_t off, size_t count)
{
	struct i2c_client *client = kobj_to_i2c_client(kobj);

	dev_dbg(&client->dev, "ds1682_eeprom_write(p=%p, off=%lli, c=%zi)\n",
		buf, off, count);

	/* Write out to the device */
	if (i2c_smbus_write_i2c_block_data(client, DS1682_REG_EEPROM + off,
					   count, buf) < 0)
		return -EIO;

	return count;
}

__attribute__((used)) static int ds1682_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int rc;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_I2C_BLOCK)) {
		dev_err(&client->dev, "i2c bus does not support the ds1682\n");
		rc = -ENODEV;
		goto exit;
	}

	rc = sysfs_create_group(&client->dev.kobj, &ds1682_group);
	if (rc)
		goto exit;

	rc = sysfs_create_bin_file(&client->dev.kobj, &ds1682_eeprom_attr);
	if (rc)
		goto exit_bin_attr;

	return 0;

 exit_bin_attr:
	sysfs_remove_group(&client->dev.kobj, &ds1682_group);
 exit:
	return rc;
}

__attribute__((used)) static int ds1682_remove(struct i2c_client *client)
{
	sysfs_remove_bin_file(&client->dev.kobj, &ds1682_eeprom_attr);
	sysfs_remove_group(&client->dev.kobj, &ds1682_group);
	return 0;
}

