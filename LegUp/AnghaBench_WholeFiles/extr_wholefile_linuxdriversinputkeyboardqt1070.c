#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct qt1070_data {int last_keys; struct input_dev* input; int /*<<< orphan*/ * keycodes; scalar_t__ irq; struct i2c_client* client; } ;
struct TYPE_8__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_7__ {TYPE_5__* parent; } ;
struct input_dev {char* name; int keycodesize; int keycodemax; int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/ * keycode; TYPE_2__ id; TYPE_1__ dev; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_11__ {TYPE_3__* driver; } ;
struct i2c_client {scalar_t__ irq; TYPE_5__ dev; TYPE_4__* adapter; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int CALIBRATE_CMD ; 
 int CHIP_ID ; 
 int DET_STATUS ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int FW_VERSION ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_NONE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int KEY_STATUS ; 
 int /*<<< orphan*/  QT1070_CAL_TIME ; 
 int QT1070_CHIP_ID ; 
 int /*<<< orphan*/  QT1070_RESET_TIME ; 
 int RESET ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_driver_string (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct qt1070_data*) ; 
 int i2c_check_functionality (TYPE_4__*,int /*<<< orphan*/ ) ; 
 struct qt1070_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct qt1070_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct qt1070_data*) ; 
 struct qt1070_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * qt1070_key2code ; 
 int request_threaded_irq (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct qt1070_data*) ; 

__attribute__((used)) static int qt1070_read(struct i2c_client *client, u8 reg)
{
	int ret;

	ret = i2c_smbus_read_byte_data(client, reg);
	if (ret < 0)
		dev_err(&client->dev,
			"can not read register, returned %d\n", ret);

	return ret;
}

__attribute__((used)) static int qt1070_write(struct i2c_client *client, u8 reg, u8 data)
{
	int ret;

	ret = i2c_smbus_write_byte_data(client, reg, data);
	if (ret < 0)
		dev_err(&client->dev,
			"can not write register, returned %d\n", ret);

	return ret;
}

__attribute__((used)) static bool qt1070_identify(struct i2c_client *client)
{
	int id, ver;

	/* Read Chip ID */
	id = qt1070_read(client, CHIP_ID);
	if (id != QT1070_CHIP_ID) {
		dev_err(&client->dev, "ID %d not supported\n", id);
		return false;
	}

	/* Read firmware version */
	ver = qt1070_read(client, FW_VERSION);
	if (ver < 0) {
		dev_err(&client->dev, "could not read the firmware version\n");
		return false;
	}

	dev_info(&client->dev, "AT42QT1070 firmware version %x\n", ver);

	return true;
}

__attribute__((used)) static irqreturn_t qt1070_interrupt(int irq, void *dev_id)
{
	struct qt1070_data *data = dev_id;
	struct i2c_client *client = data->client;
	struct input_dev *input = data->input;
	int i;
	u8 new_keys, keyval, mask = 0x01;

	/* Read the detected status register, thus clearing interrupt */
	qt1070_read(client, DET_STATUS);

	/* Read which key changed */
	new_keys = qt1070_read(client, KEY_STATUS);

	for (i = 0; i < ARRAY_SIZE(qt1070_key2code); i++) {
		keyval = new_keys & mask;
		if ((data->last_keys & mask) != keyval)
			input_report_key(input, data->keycodes[i], keyval);
		mask <<= 1;
	}
	input_sync(input);

	data->last_keys = new_keys;
	return IRQ_HANDLED;
}

__attribute__((used)) static int qt1070_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct qt1070_data *data;
	struct input_dev *input;
	int i;
	int err;

	err = i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE);
	if (!err) {
		dev_err(&client->dev, "%s adapter not supported\n",
			dev_driver_string(&client->adapter->dev));
		return -ENODEV;
	}

	if (!client->irq) {
		dev_err(&client->dev, "please assign the irq to this device\n");
		return -EINVAL;
	}

	/* Identify the qt1070 chip */
	if (!qt1070_identify(client))
		return -ENODEV;

	data = kzalloc(sizeof(struct qt1070_data), GFP_KERNEL);
	input = input_allocate_device();
	if (!data || !input) {
		dev_err(&client->dev, "insufficient memory\n");
		err = -ENOMEM;
		goto err_free_mem;
	}

	data->client = client;
	data->input = input;
	data->irq = client->irq;

	input->name = "AT42QT1070 QTouch Sensor";
	input->dev.parent = &client->dev;
	input->id.bustype = BUS_I2C;

	/* Add the keycode */
	input->keycode = data->keycodes;
	input->keycodesize = sizeof(data->keycodes[0]);
	input->keycodemax = ARRAY_SIZE(qt1070_key2code);

	__set_bit(EV_KEY, input->evbit);

	for (i = 0; i < ARRAY_SIZE(qt1070_key2code); i++) {
		data->keycodes[i] = qt1070_key2code[i];
		__set_bit(qt1070_key2code[i], input->keybit);
	}

	/* Calibrate device */
	qt1070_write(client, CALIBRATE_CMD, 1);
	msleep(QT1070_CAL_TIME);

	/* Soft reset */
	qt1070_write(client, RESET, 1);
	msleep(QT1070_RESET_TIME);

	err = request_threaded_irq(client->irq, NULL, qt1070_interrupt,
				   IRQF_TRIGGER_NONE | IRQF_ONESHOT,
				   client->dev.driver->name, data);
	if (err) {
		dev_err(&client->dev, "fail to request irq\n");
		goto err_free_mem;
	}

	/* Register the input device */
	err = input_register_device(data->input);
	if (err) {
		dev_err(&client->dev, "Failed to register input device\n");
		goto err_free_irq;
	}

	i2c_set_clientdata(client, data);

	/* Read to clear the chang line */
	qt1070_read(client, DET_STATUS);

	return 0;

err_free_irq:
	free_irq(client->irq, data);
err_free_mem:
	input_free_device(input);
	kfree(data);
	return err;
}

__attribute__((used)) static int qt1070_remove(struct i2c_client *client)
{
	struct qt1070_data *data = i2c_get_clientdata(client);

	/* Release IRQ */
	free_irq(client->irq, data);

	input_unregister_device(data->input);
	kfree(data);

	return 0;
}

