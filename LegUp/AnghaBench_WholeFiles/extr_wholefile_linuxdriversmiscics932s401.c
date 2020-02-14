#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  attrs; } ;
struct ics932s401_data {unsigned long sensors_last_updated; int sensors_valid; int* regs; TYPE_1__ attrs; int /*<<< orphan*/  lock; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int name; TYPE_3__ dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {TYPE_3__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int BASE_CLOCK ; 
 int /*<<< orphan*/  BUG () ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int ICS932S401_CFG1_SPREAD ; 
 int ICS932S401_CPU_ALT ; 
 size_t ICS932S401_CPU_DIVISOR_SHIFT ; 
 int ICS932S401_DEVICE ; 
 int ICS932S401_FS_MASK ; 
 int ICS932S401_MN_ENABLED ; 
 int ICS932S401_M_MASK ; 
 size_t ICS932S401_PCI_DIVISOR_SHIFT ; 
 size_t ICS932S401_REG_CFG2 ; 
 size_t ICS932S401_REG_CFG7 ; 
 size_t ICS932S401_REG_CPU_DIVISOR ; 
 size_t ICS932S401_REG_CPU_M_CTRL ; 
 size_t ICS932S401_REG_CPU_N_CTRL ; 
 int ICS932S401_REG_CPU_SPREAD1 ; 
 size_t ICS932S401_REG_CTRL ; 
 size_t ICS932S401_REG_DEVICE ; 
 size_t ICS932S401_REG_PCISRC_DIVISOR ; 
 size_t ICS932S401_REG_SRC_M_CTRL ; 
 size_t ICS932S401_REG_SRC_N_CTRL ; 
 int ICS932S401_REG_SRC_SPREAD1 ; 
 size_t ICS932S401_REG_VENDOR_REV ; 
 int ICS932S401_REV ; 
 int ICS932S401_REV_SHIFT ; 
 unsigned long ICS932S401_SPREAD_MASK ; 
 int ICS932S401_SRC_ALT ; 
 size_t ICS932S401_SRC_DIVISOR_MASK ; 
 int ICS932S401_VENDOR ; 
 int ICS932S401_VENDOR_MASK ; 
 int NUM_MIRRORED_REGS ; 
 scalar_t__ SENSOR_REFRESH_INTERVAL ; 
 struct device_attribute dev_attr_cpu_spread ; 
 struct device_attribute dev_attr_ref_clock ; 
 struct device_attribute dev_attr_src_spread ; 
 struct device_attribute dev_attr_usb_clock ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,int) ; 
 int* divisors ; 
 int* fs_speeds ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct ics932s401_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ics932s401_data*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,size_t) ; 
 int /*<<< orphan*/  ics932s401_attr ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kfree (struct ics932s401_data*) ; 
 struct ics932s401_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 size_t* regs_to_copy ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ time_before (unsigned long,scalar_t__) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static struct ics932s401_data *ics932s401_update_device(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct ics932s401_data *data = i2c_get_clientdata(client);
	unsigned long local_jiffies = jiffies;
	int i, temp;

	mutex_lock(&data->lock);
	if (time_before(local_jiffies, data->sensors_last_updated +
		SENSOR_REFRESH_INTERVAL)
		&& data->sensors_valid)
		goto out;

	/*
	 * Each register must be read as a word and then right shifted 8 bits.
	 * Not really sure why this is; setting the "byte count programming"
	 * register to 1 does not fix this problem.
	 */
	for (i = 0; i < NUM_MIRRORED_REGS; i++) {
		temp = i2c_smbus_read_word_data(client, regs_to_copy[i]);
		data->regs[regs_to_copy[i]] = temp >> 8;
	}

	data->sensors_last_updated = local_jiffies;
	data->sensors_valid = 1;

out:
	mutex_unlock(&data->lock);
	return data;
}

__attribute__((used)) static ssize_t show_spread_enabled(struct device *dev,
				   struct device_attribute *devattr,
				   char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);

	if (data->regs[ICS932S401_REG_CFG2] & ICS932S401_CFG1_SPREAD)
		return sprintf(buf, "1\n");

	return sprintf(buf, "0\n");
}

__attribute__((used)) static int calculate_cpu_freq(struct ics932s401_data *data)
{
	int m, n, freq;

	m = data->regs[ICS932S401_REG_CPU_M_CTRL] & ICS932S401_M_MASK;
	n = data->regs[ICS932S401_REG_CPU_N_CTRL];

	/* Pull in bits 8 & 9 from the M register */
	n |= ((int)data->regs[ICS932S401_REG_CPU_M_CTRL] & 0x80) << 1;
	n |= ((int)data->regs[ICS932S401_REG_CPU_M_CTRL] & 0x40) << 3;

	freq = BASE_CLOCK * (n + 8) / (m + 2);
	freq /= divisors[data->regs[ICS932S401_REG_CPU_DIVISOR] >>
			 ICS932S401_CPU_DIVISOR_SHIFT];

	return freq;
}

__attribute__((used)) static ssize_t show_cpu_clock(struct device *dev,
			      struct device_attribute *devattr,
			      char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);

	return sprintf(buf, "%d\n", calculate_cpu_freq(data));
}

__attribute__((used)) static ssize_t show_cpu_clock_sel(struct device *dev,
				  struct device_attribute *devattr,
				  char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);
	int freq;

	if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
		freq = calculate_cpu_freq(data);
	else {
		/* Freq is neatly wrapped up for us */
		int fid = data->regs[ICS932S401_REG_CFG7] & ICS932S401_FS_MASK;

		freq = fs_speeds[fid];
		if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_CPU_ALT) {
			switch (freq) {
			case 166666:
				freq = 160000;
				break;
			case 333333:
				freq = 320000;
				break;
			}
		}
	}

	return sprintf(buf, "%d\n", freq);
}

__attribute__((used)) static int calculate_src_freq(struct ics932s401_data *data)
{
	int m, n, freq;

	m = data->regs[ICS932S401_REG_SRC_M_CTRL] & ICS932S401_M_MASK;
	n = data->regs[ICS932S401_REG_SRC_N_CTRL];

	/* Pull in bits 8 & 9 from the M register */
	n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x80) << 1;
	n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x40) << 3;

	freq = BASE_CLOCK * (n + 8) / (m + 2);
	freq /= divisors[data->regs[ICS932S401_REG_PCISRC_DIVISOR] &
			 ICS932S401_SRC_DIVISOR_MASK];

	return freq;
}

__attribute__((used)) static ssize_t show_src_clock(struct device *dev,
			      struct device_attribute *devattr,
			      char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);

	return sprintf(buf, "%d\n", calculate_src_freq(data));
}

__attribute__((used)) static ssize_t show_src_clock_sel(struct device *dev,
				  struct device_attribute *devattr,
				  char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);
	int freq;

	if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
		freq = calculate_src_freq(data);
	else
		/* Freq is neatly wrapped up for us */
		if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_CPU_ALT &&
		    data->regs[ICS932S401_REG_CTRL] & ICS932S401_SRC_ALT)
			freq = 96000;
		else
			freq = 100000;

	return sprintf(buf, "%d\n", freq);
}

__attribute__((used)) static int calculate_pci_freq(struct ics932s401_data *data)
{
	int m, n, freq;

	m = data->regs[ICS932S401_REG_SRC_M_CTRL] & ICS932S401_M_MASK;
	n = data->regs[ICS932S401_REG_SRC_N_CTRL];

	/* Pull in bits 8 & 9 from the M register */
	n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x80) << 1;
	n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x40) << 3;

	freq = BASE_CLOCK * (n + 8) / (m + 2);
	freq /= divisors[data->regs[ICS932S401_REG_PCISRC_DIVISOR] >>
			 ICS932S401_PCI_DIVISOR_SHIFT];

	return freq;
}

__attribute__((used)) static ssize_t show_pci_clock(struct device *dev,
			      struct device_attribute *devattr,
			      char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);

	return sprintf(buf, "%d\n", calculate_pci_freq(data));
}

__attribute__((used)) static ssize_t show_pci_clock_sel(struct device *dev,
				  struct device_attribute *devattr,
				  char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);
	int freq;

	if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
		freq = calculate_pci_freq(data);
	else
		freq = 33333;

	return sprintf(buf, "%d\n", freq);
}

__attribute__((used)) static ssize_t show_value(struct device *dev,
			  struct device_attribute *devattr,
			  char *buf)
{
	int x;

	if (devattr == &dev_attr_usb_clock)
		x = 48000;
	else if (devattr == &dev_attr_ref_clock)
		x = BASE_CLOCK;
	else
		BUG();

	return sprintf(buf, "%d\n", x);
}

__attribute__((used)) static ssize_t show_spread(struct device *dev,
			   struct device_attribute *devattr,
			   char *buf)
{
	struct ics932s401_data *data = ics932s401_update_device(dev);
	int reg;
	unsigned long val;

	if (!(data->regs[ICS932S401_REG_CFG2] & ICS932S401_CFG1_SPREAD))
		return sprintf(buf, "0%%\n");

	if (devattr == &dev_attr_src_spread)
		reg = ICS932S401_REG_SRC_SPREAD1;
	else if (devattr == &dev_attr_cpu_spread)
		reg = ICS932S401_REG_CPU_SPREAD1;
	else
		BUG();

	val = data->regs[reg] | (data->regs[reg + 1] << 8);
	val &= ICS932S401_SPREAD_MASK;

	/* Scale 0..2^14 to -0.5. */
	val = 500000 * val / 16384;
	return sprintf(buf, "-0.%lu%%\n", val);
}

__attribute__((used)) static int ics932s401_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int vendor, device, revision;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	vendor = i2c_smbus_read_word_data(client, ICS932S401_REG_VENDOR_REV);
	vendor >>= 8;
	revision = vendor >> ICS932S401_REV_SHIFT;
	vendor &= ICS932S401_VENDOR_MASK;
	if (vendor != ICS932S401_VENDOR)
		return -ENODEV;

	device = i2c_smbus_read_word_data(client, ICS932S401_REG_DEVICE);
	device >>= 8;
	if (device != ICS932S401_DEVICE)
		return -ENODEV;

	if (revision != ICS932S401_REV)
		dev_info(&adapter->dev, "Unknown revision %d\n", revision);

	strlcpy(info->type, "ics932s401", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int ics932s401_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct ics932s401_data *data;
	int err;

	data = kzalloc(sizeof(struct ics932s401_data), GFP_KERNEL);
	if (!data) {
		err = -ENOMEM;
		goto exit;
	}

	i2c_set_clientdata(client, data);
	mutex_init(&data->lock);

	dev_info(&client->dev, "%s chip found\n", client->name);

	/* Register sysfs hooks */
	data->attrs.attrs = ics932s401_attr;
	err = sysfs_create_group(&client->dev.kobj, &data->attrs);
	if (err)
		goto exit_free;

	return 0;

exit_free:
	kfree(data);
exit:
	return err;
}

__attribute__((used)) static int ics932s401_remove(struct i2c_client *client)
{
	struct ics932s401_data *data = i2c_get_clientdata(client);

	sysfs_remove_group(&client->dev.kobj, &data->attrs);
	kfree(data);
	return 0;
}

