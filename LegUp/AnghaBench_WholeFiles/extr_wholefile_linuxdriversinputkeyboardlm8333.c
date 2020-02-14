#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct lm8333_platform_data {int active_time; int debounce_time; int /*<<< orphan*/  matrix_data; } ;
struct lm8333 {struct input_dev* input; int /*<<< orphan*/ * keycodes; struct i2c_client* client; } ;
struct TYPE_4__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct input_dev {TYPE_2__ id; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int LM8333_ACTIVE ; 
 int LM8333_DEBOUNCE ; 
 int LM8333_ERROR_FIFOOVR ; 
 int LM8333_ERROR_IRQ ; 
 int LM8333_ERROR_KEYOVR ; 
 int LM8333_FIFO_READ ; 
 int LM8333_FIFO_TRANSFER_SIZE ; 
 int LM8333_KEYPAD_IRQ ; 
 int /*<<< orphan*/  LM8333_NUM_COLS ; 
 int /*<<< orphan*/  LM8333_NUM_ROWS ; 
 int LM8333_READ_ERROR ; 
 int LM8333_READ_INT ; 
 int /*<<< orphan*/  LM8333_READ_RETRIES ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct lm8333_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct lm8333*) ; 
 struct lm8333* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lm8333*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct lm8333*) ; 
 struct lm8333* kzalloc (int,int /*<<< orphan*/ ) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct input_dev*) ; 
 int request_threaded_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct lm8333*) ; 

int lm8333_read8(struct lm8333 *lm8333, u8 cmd)
{
	int retries = 0, ret;

	do {
		ret = i2c_smbus_read_byte_data(lm8333->client, cmd);
	} while (ret < 0 && retries++ < LM8333_READ_RETRIES);

	return ret;
}

int lm8333_write8(struct lm8333 *lm8333, u8 cmd, u8 val)
{
	int retries = 0, ret;

	do {
		ret = i2c_smbus_write_byte_data(lm8333->client, cmd, val);
	} while (ret < 0 && retries++ < LM8333_READ_RETRIES);

	return ret;
}

int lm8333_read_block(struct lm8333 *lm8333, u8 cmd, u8 len, u8 *buf)
{
	int retries = 0, ret;

	do {
		ret = i2c_smbus_read_i2c_block_data(lm8333->client,
						    cmd, len, buf);
	} while (ret < 0 && retries++ < LM8333_READ_RETRIES);

	return ret;
}

__attribute__((used)) static void lm8333_key_handler(struct lm8333 *lm8333)
{
	struct input_dev *input = lm8333->input;
	u8 keys[LM8333_FIFO_TRANSFER_SIZE];
	u8 code, pressed;
	int i, ret;

	ret = lm8333_read_block(lm8333, LM8333_FIFO_READ,
				LM8333_FIFO_TRANSFER_SIZE, keys);
	if (ret != LM8333_FIFO_TRANSFER_SIZE) {
		dev_err(&lm8333->client->dev,
			"Error %d while reading FIFO\n", ret);
		return;
	}

	for (i = 0; i < LM8333_FIFO_TRANSFER_SIZE && keys[i]; i++) {
		pressed = keys[i] & 0x80;
		code = keys[i] & 0x7f;

		input_event(input, EV_MSC, MSC_SCAN, code);
		input_report_key(input, lm8333->keycodes[code], pressed);
	}

	input_sync(input);
}

__attribute__((used)) static irqreturn_t lm8333_irq_thread(int irq, void *data)
{
	struct lm8333 *lm8333 = data;
	u8 status = lm8333_read8(lm8333, LM8333_READ_INT);

	if (!status)
		return IRQ_NONE;

	if (status & LM8333_ERROR_IRQ) {
		u8 err = lm8333_read8(lm8333, LM8333_READ_ERROR);

		if (err & (LM8333_ERROR_KEYOVR | LM8333_ERROR_FIFOOVR)) {
			u8 dummy[LM8333_FIFO_TRANSFER_SIZE];

			lm8333_read_block(lm8333, LM8333_FIFO_READ,
					LM8333_FIFO_TRANSFER_SIZE, dummy);
		}
		dev_err(&lm8333->client->dev, "Got error %02x\n", err);
	}

	if (status & LM8333_KEYPAD_IRQ)
		lm8333_key_handler(lm8333);

	return IRQ_HANDLED;
}

__attribute__((used)) static int lm8333_probe(struct i2c_client *client,
				  const struct i2c_device_id *id)
{
	const struct lm8333_platform_data *pdata =
			dev_get_platdata(&client->dev);
	struct lm8333 *lm8333;
	struct input_dev *input;
	int err, active_time;

	if (!pdata)
		return -EINVAL;

	active_time = pdata->active_time ?: 500;
	if (active_time / 3 <= pdata->debounce_time / 3) {
		dev_err(&client->dev, "Active time not big enough!\n");
		return -EINVAL;
	}

	lm8333 = kzalloc(sizeof(*lm8333), GFP_KERNEL);
	input = input_allocate_device();
	if (!lm8333 || !input) {
		err = -ENOMEM;
		goto free_mem;
	}

	lm8333->client = client;
	lm8333->input = input;

	input->name = client->name;
	input->dev.parent = &client->dev;
	input->id.bustype = BUS_I2C;

	input_set_capability(input, EV_MSC, MSC_SCAN);

	err = matrix_keypad_build_keymap(pdata->matrix_data, NULL,
					 LM8333_NUM_ROWS, LM8333_NUM_COLS,
					 lm8333->keycodes, input);
	if (err)
		goto free_mem;

	if (pdata->debounce_time) {
		err = lm8333_write8(lm8333, LM8333_DEBOUNCE,
				    pdata->debounce_time / 3);
		if (err)
			dev_warn(&client->dev, "Unable to set debounce time\n");
	}

	if (pdata->active_time) {
		err = lm8333_write8(lm8333, LM8333_ACTIVE,
				    pdata->active_time / 3);
		if (err)
			dev_warn(&client->dev, "Unable to set active time\n");
	}

	err = request_threaded_irq(client->irq, NULL, lm8333_irq_thread,
				   IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				   "lm8333", lm8333);
	if (err)
		goto free_mem;

	err = input_register_device(input);
	if (err)
		goto free_irq;

	i2c_set_clientdata(client, lm8333);
	return 0;

 free_irq:
	free_irq(client->irq, lm8333);
 free_mem:
	input_free_device(input);
	kfree(lm8333);
	return err;
}

__attribute__((used)) static int lm8333_remove(struct i2c_client *client)
{
	struct lm8333 *lm8333 = i2c_get_clientdata(client);

	free_irq(client->irq, lm8333);
	input_unregister_device(lm8333->input);
	kfree(lm8333);

	return 0;
}

