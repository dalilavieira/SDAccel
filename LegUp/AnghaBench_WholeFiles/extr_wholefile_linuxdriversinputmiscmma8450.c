#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct mma8450 {struct input_polled_dev* idev; struct i2c_client* client; } ;
struct input_polled_dev {void (* poll ) (struct input_polled_dev*) ;void (* open ) (struct input_polled_dev*) ;void (* close ) (struct input_polled_dev*) ;TYPE_2__* input; int /*<<< orphan*/  poll_interval_max; int /*<<< orphan*/  poll_interval; struct mma8450* private; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  scalar_t__ s8 ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_5__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_6__ {int /*<<< orphan*/  evbit; TYPE_1__ id; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  ABS_Z ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int MMA8450_CTRL_REG1 ; 
 unsigned int MMA8450_CTRL_REG2 ; 
 int /*<<< orphan*/  MMA8450_DRV_NAME ; 
 unsigned int MMA8450_OUT_X_LSB ; 
 unsigned int MMA8450_STATUS ; 
 int MMA8450_STATUS_ZXYDR ; 
 unsigned int MMA8450_XYZ_DATA_CFG ; 
 int /*<<< orphan*/  MODE_CHANGE_DELAY_MS ; 
 int /*<<< orphan*/  POLL_INTERVAL ; 
 int /*<<< orphan*/  POLL_INTERVAL_MAX ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct input_polled_dev* devm_input_allocate_polled_device (int /*<<< orphan*/ *) ; 
 struct mma8450* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,unsigned int,size_t,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned int,int) ; 
 int input_register_polled_device (struct input_polled_dev*) ; 
 int /*<<< orphan*/  input_report_abs (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (TYPE_2__*,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  input_sync (TYPE_2__*) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mma8450_read(struct mma8450 *m, unsigned off)
{
	struct i2c_client *c = m->client;
	int ret;

	ret = i2c_smbus_read_byte_data(c, off);
	if (ret < 0)
		dev_err(&c->dev,
			"failed to read register 0x%02x, error %d\n",
			off, ret);

	return ret;
}

__attribute__((used)) static int mma8450_write(struct mma8450 *m, unsigned off, u8 v)
{
	struct i2c_client *c = m->client;
	int error;

	error = i2c_smbus_write_byte_data(c, off, v);
	if (error < 0) {
		dev_err(&c->dev,
			"failed to write to register 0x%02x, error %d\n",
			off, error);
		return error;
	}

	return 0;
}

__attribute__((used)) static int mma8450_read_block(struct mma8450 *m, unsigned off,
			      u8 *buf, size_t size)
{
	struct i2c_client *c = m->client;
	int err;

	err = i2c_smbus_read_i2c_block_data(c, off, size, buf);
	if (err < 0) {
		dev_err(&c->dev,
			"failed to read block data at 0x%02x, error %d\n",
			MMA8450_OUT_X_LSB, err);
		return err;
	}

	return 0;
}

__attribute__((used)) static void mma8450_poll(struct input_polled_dev *dev)
{
	struct mma8450 *m = dev->private;
	int x, y, z;
	int ret;
	u8 buf[6];

	ret = mma8450_read(m, MMA8450_STATUS);
	if (ret < 0)
		return;

	if (!(ret & MMA8450_STATUS_ZXYDR))
		return;

	ret = mma8450_read_block(m, MMA8450_OUT_X_LSB, buf, sizeof(buf));
	if (ret < 0)
		return;

	x = ((int)(s8)buf[1] << 4) | (buf[0] & 0xf);
	y = ((int)(s8)buf[3] << 4) | (buf[2] & 0xf);
	z = ((int)(s8)buf[5] << 4) | (buf[4] & 0xf);

	input_report_abs(dev->input, ABS_X, x);
	input_report_abs(dev->input, ABS_Y, y);
	input_report_abs(dev->input, ABS_Z, z);
	input_sync(dev->input);
}

__attribute__((used)) static void mma8450_open(struct input_polled_dev *dev)
{
	struct mma8450 *m = dev->private;
	int err;

	/* enable all events from X/Y/Z, no FIFO */
	err = mma8450_write(m, MMA8450_XYZ_DATA_CFG, 0x07);
	if (err)
		return;

	/*
	 * Sleep mode poll rate - 50Hz
	 * System output data rate - 400Hz
	 * Full scale selection - Active, +/- 2G
	 */
	err = mma8450_write(m, MMA8450_CTRL_REG1, 0x01);
	if (err < 0)
		return;

	msleep(MODE_CHANGE_DELAY_MS);
}

__attribute__((used)) static void mma8450_close(struct input_polled_dev *dev)
{
	struct mma8450 *m = dev->private;

	mma8450_write(m, MMA8450_CTRL_REG1, 0x00);
	mma8450_write(m, MMA8450_CTRL_REG2, 0x01);
}

__attribute__((used)) static int mma8450_probe(struct i2c_client *c,
			 const struct i2c_device_id *id)
{
	struct input_polled_dev *idev;
	struct mma8450 *m;
	int err;

	m = devm_kzalloc(&c->dev, sizeof(*m), GFP_KERNEL);
	if (!m)
		return -ENOMEM;

	idev = devm_input_allocate_polled_device(&c->dev);
	if (!idev)
		return -ENOMEM;

	m->client = c;
	m->idev = idev;

	idev->private		= m;
	idev->input->name	= MMA8450_DRV_NAME;
	idev->input->id.bustype	= BUS_I2C;
	idev->poll		= mma8450_poll;
	idev->poll_interval	= POLL_INTERVAL;
	idev->poll_interval_max	= POLL_INTERVAL_MAX;
	idev->open		= mma8450_open;
	idev->close		= mma8450_close;

	__set_bit(EV_ABS, idev->input->evbit);
	input_set_abs_params(idev->input, ABS_X, -2048, 2047, 32, 32);
	input_set_abs_params(idev->input, ABS_Y, -2048, 2047, 32, 32);
	input_set_abs_params(idev->input, ABS_Z, -2048, 2047, 32, 32);

	err = input_register_polled_device(idev);
	if (err) {
		dev_err(&c->dev, "failed to register polled input device\n");
		return err;
	}

	return 0;
}

