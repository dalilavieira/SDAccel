#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct max6875_data {int* data; int valid; int /*<<< orphan*/  fake_client; int /*<<< orphan*/  update_lock; int /*<<< orphan*/ * last_updated; } ;
struct kobject {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int addr; TYPE_1__ dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct file {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  size_t loff_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_READ_BYTE ; 
 int I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
 int /*<<< orphan*/  MAX6875_CMD_BLK_READ ; 
 int SLICE_BITS ; 
 int SLICE_SIZE ; 
 int USER_EEPROM_BASE ; 
 int USER_EEPROM_SLICES ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 scalar_t__ i2c_check_functionality (struct i2c_adapter*,int) ; 
 struct max6875_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_new_dummy (struct i2c_adapter*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max6875_data*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int*) ; 
 scalar_t__ i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  kfree (struct max6875_data*) ; 
 struct i2c_client* kobj_to_i2c_client (struct kobject*) ; 
 struct max6875_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int*,size_t) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  user_eeprom_attr ; 

__attribute__((used)) static void max6875_update_slice(struct i2c_client *client, int slice)
{
	struct max6875_data *data = i2c_get_clientdata(client);
	int i, j, addr;
	u8 *buf;

	if (slice >= USER_EEPROM_SLICES)
		return;

	mutex_lock(&data->update_lock);

	buf = &data->data[slice << SLICE_BITS];

	if (!(data->valid & (1 << slice)) ||
	    time_after(jiffies, data->last_updated[slice])) {

		dev_dbg(&client->dev, "Starting update of slice %u\n", slice);

		data->valid &= ~(1 << slice);

		addr = USER_EEPROM_BASE + (slice << SLICE_BITS);

		/* select the eeprom address */
		if (i2c_smbus_write_byte_data(client, addr >> 8, addr & 0xFF)) {
			dev_err(&client->dev, "address set failed\n");
			goto exit_up;
		}

		if (i2c_check_functionality(client->adapter,
					    I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
			if (i2c_smbus_read_i2c_block_data(client,
							  MAX6875_CMD_BLK_READ,
							  SLICE_SIZE,
							  buf) != SLICE_SIZE) {
				goto exit_up;
			}
		} else {
			for (i = 0; i < SLICE_SIZE; i++) {
				j = i2c_smbus_read_byte(client);
				if (j < 0) {
					goto exit_up;
				}
				buf[i] = j;
			}
		}
		data->last_updated[slice] = jiffies;
		data->valid |= (1 << slice);
	}
exit_up:
	mutex_unlock(&data->update_lock);
}

__attribute__((used)) static ssize_t max6875_read(struct file *filp, struct kobject *kobj,
			    struct bin_attribute *bin_attr,
			    char *buf, loff_t off, size_t count)
{
	struct i2c_client *client = kobj_to_i2c_client(kobj);
	struct max6875_data *data = i2c_get_clientdata(client);
	int slice, max_slice;

	/* refresh slices which contain requested bytes */
	max_slice = (off + count - 1) >> SLICE_BITS;
	for (slice = (off >> SLICE_BITS); slice <= max_slice; slice++)
		max6875_update_slice(client, slice);

	memcpy(buf, &data->data[off], count);

	return count;
}

__attribute__((used)) static int max6875_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct max6875_data *data;
	int err;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WRITE_BYTE_DATA
				     | I2C_FUNC_SMBUS_READ_BYTE))
		return -ENODEV;

	/* Only bind to even addresses */
	if (client->addr & 1)
		return -ENODEV;

	data = kzalloc(sizeof(struct max6875_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	/* A fake client is created on the odd address */
	data->fake_client = i2c_new_dummy(client->adapter, client->addr + 1);
	if (!data->fake_client) {
		err = -ENOMEM;
		goto exit_kfree;
	}

	/* Init real i2c_client */
	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	err = sysfs_create_bin_file(&client->dev.kobj, &user_eeprom_attr);
	if (err)
		goto exit_remove_fake;

	return 0;

exit_remove_fake:
	i2c_unregister_device(data->fake_client);
exit_kfree:
	kfree(data);
	return err;
}

__attribute__((used)) static int max6875_remove(struct i2c_client *client)
{
	struct max6875_data *data = i2c_get_clientdata(client);

	i2c_unregister_device(data->fake_client);

	sysfs_remove_bin_file(&client->dev.kobj, &user_eeprom_attr);
	kfree(data);

	return 0;
}

