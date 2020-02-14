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
struct st_sensor_data {int dummy; } ;
struct iio_dev {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 struct st_sensor_data* iio_priv (struct iio_dev*) ; 
 int st_magn_common_probe (struct iio_dev*) ; 
 int /*<<< orphan*/  st_magn_common_remove (struct iio_dev*) ; 
 int /*<<< orphan*/  st_magn_of_match ; 
 int /*<<< orphan*/  st_sensors_i2c_configure (struct iio_dev*,struct i2c_client*,struct st_sensor_data*) ; 
 int /*<<< orphan*/  st_sensors_of_name_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int st_magn_probe_trigger(struct iio_dev *indio_dev, int irq)
{
	return 0;
}

__attribute__((used)) static inline void st_magn_remove_trigger(struct iio_dev *indio_dev, int irq)
{
	return;
}

__attribute__((used)) static inline int st_magn_allocate_ring(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static inline void st_magn_deallocate_ring(struct iio_dev *indio_dev)
{
}

__attribute__((used)) static int st_magn_i2c_probe(struct i2c_client *client,
						const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct st_sensor_data *mdata;
	int err;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*mdata));
	if (!indio_dev)
		return -ENOMEM;

	mdata = iio_priv(indio_dev);
	st_sensors_of_name_probe(&client->dev, st_magn_of_match,
				 client->name, sizeof(client->name));

	st_sensors_i2c_configure(indio_dev, client, mdata);

	err = st_magn_common_probe(indio_dev);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int st_magn_i2c_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	st_magn_common_remove(indio_dev);

	return 0;
}

