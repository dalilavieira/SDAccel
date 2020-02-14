#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct st_sensor_transfer_buffer {int dummy; } ;
struct st_sensor_data {unsigned int (* get_irq_data_ready ) (struct iio_dev*) ;int /*<<< orphan*/ * tf; struct device* dev; } ;
struct TYPE_6__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; int /*<<< orphan*/  name; } ;
struct TYPE_7__ {unsigned int irq; } ;

/* Variables and functions */
 int ST_SENSORS_I2C_MULTIREAD ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (TYPE_2__*,int) ; 
 int i2c_smbus_read_i2c_block_data_or_emulated (TYPE_2__*,int,int,int*) ; 
 int i2c_smbus_write_byte_data (TYPE_2__*,int,int) ; 
 struct st_sensor_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  st_sensors_tf_i2c ; 
 TYPE_2__* to_i2c_client (struct device*) ; 

__attribute__((used)) static unsigned int st_sensors_i2c_get_irq(struct iio_dev *indio_dev)
{
	struct st_sensor_data *sdata = iio_priv(indio_dev);

	return to_i2c_client(sdata->dev)->irq;
}

__attribute__((used)) static int st_sensors_i2c_read_byte(struct st_sensor_transfer_buffer *tb,
				struct device *dev, u8 reg_addr, u8 *res_byte)
{
	int err;

	err = i2c_smbus_read_byte_data(to_i2c_client(dev), reg_addr);
	if (err < 0)
		goto st_accel_i2c_read_byte_error;

	*res_byte = err & 0xff;

st_accel_i2c_read_byte_error:
	return err < 0 ? err : 0;
}

__attribute__((used)) static int st_sensors_i2c_read_multiple_byte(
		struct st_sensor_transfer_buffer *tb, struct device *dev,
			u8 reg_addr, int len, u8 *data, bool multiread_bit)
{
	if (multiread_bit)
		reg_addr |= ST_SENSORS_I2C_MULTIREAD;

	return i2c_smbus_read_i2c_block_data_or_emulated(to_i2c_client(dev),
							 reg_addr, len, data);
}

__attribute__((used)) static int st_sensors_i2c_write_byte(struct st_sensor_transfer_buffer *tb,
				struct device *dev, u8 reg_addr, u8 data)
{
	return i2c_smbus_write_byte_data(to_i2c_client(dev), reg_addr, data);
}

void st_sensors_i2c_configure(struct iio_dev *indio_dev,
		struct i2c_client *client, struct st_sensor_data *sdata)
{
	i2c_set_clientdata(client, indio_dev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = client->name;

	sdata->dev = &client->dev;
	sdata->tf = &st_sensors_tf_i2c;
	sdata->get_irq_data_ready = st_sensors_i2c_get_irq;
}

