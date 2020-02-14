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
typedef  int u32 ;
typedef  int u16 ;
struct iio_dev {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct device {int dummy; } ;
struct ade7854_state {int* tx; int* rx; int (* read_reg ) (struct device*,int,int*,int) ;int (* write_reg ) (struct device*,int,int,int) ;int /*<<< orphan*/  irq; struct i2c_client* i2c; int /*<<< orphan*/  buf_lock; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ade7854_probe (struct iio_dev*,int /*<<< orphan*/ *) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 struct ade7854_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ade7854_i2c_write_reg(struct device *dev,
				 u16 reg_address,
				 u32 val,
				 int bits)
{
	int ret;
	int count;
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ade7854_state *st = iio_priv(indio_dev);

	mutex_lock(&st->buf_lock);
	st->tx[0] = (reg_address >> 8) & 0xFF;
	st->tx[1] = reg_address & 0xFF;

	switch (bits) {
	case 8:
		st->tx[2] = val & 0xFF;
		count = 3;
		break;
	case 16:
		st->tx[2] = (val >> 8) & 0xFF;
		st->tx[3] = val & 0xFF;
		count = 4;
		break;
	case 24:
		st->tx[2] = (val >> 16) & 0xFF;
		st->tx[3] = (val >> 8) & 0xFF;
		st->tx[4] = val & 0xFF;
		count = 5;
		break;
	case 32:
		st->tx[2] = (val >> 24) & 0xFF;
		st->tx[3] = (val >> 16) & 0xFF;
		st->tx[4] = (val >> 8) & 0xFF;
		st->tx[5] = val & 0xFF;
		count = 6;
		break;
	default:
		ret = -EINVAL;
		goto unlock;
	}

	ret = i2c_master_send(st->i2c, st->tx, count);

unlock:
	mutex_unlock(&st->buf_lock);

	return ret < 0 ? ret : 0;
}

__attribute__((used)) static int ade7854_i2c_read_reg(struct device *dev,
				u16 reg_address,
				u32 *val,
				int bits)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ade7854_state *st = iio_priv(indio_dev);
	int ret;

	mutex_lock(&st->buf_lock);
	st->tx[0] = (reg_address >> 8) & 0xFF;
	st->tx[1] = reg_address & 0xFF;

	ret = i2c_master_send(st->i2c, st->tx, 2);
	if (ret < 0)
		goto unlock;

	ret = i2c_master_recv(st->i2c, st->rx, bits);
	if (ret < 0)
		goto unlock;

	switch (bits) {
	case 8:
		*val = st->rx[0];
		break;
	case 16:
		*val = (st->rx[0] << 8) | st->rx[1];
		break;
	case 24:
		*val = (st->rx[0] << 16) | (st->rx[1] << 8) | st->rx[2];
		break;
	case 32:
		*val = (st->rx[0] << 24) | (st->rx[1] << 16) |
			(st->rx[2] << 8) | st->rx[3];
		break;
	default:
		ret = -EINVAL;
		goto unlock;
	}

unlock:
	mutex_unlock(&st->buf_lock);
	return ret;
}

__attribute__((used)) static int ade7854_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct ade7854_state *st;
	struct iio_dev *indio_dev;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	st = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	st->read_reg = ade7854_i2c_read_reg;
	st->write_reg = ade7854_i2c_write_reg;
	st->i2c = client;
	st->irq = client->irq;

	return ade7854_probe(indio_dev, &client->dev);
}

