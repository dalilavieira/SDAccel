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
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  propbit; TYPE_2__ dev; TYPE_1__ id; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  adapter; } ;
struct ar1021_i2c {int* data; struct input_dev* input; struct i2c_client* client; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  cmd_enable_touch ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
#define  AR1021_CMD 129 
#define  AR1021_CMD_ENABLE_TOUCH 128 
 int /*<<< orphan*/  AR1021_MAX_X ; 
 int /*<<< orphan*/  AR1021_MAX_Y ; 
 int BIT (int) ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int /*<<< orphan*/  INPUT_PROP_DIRECT ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 struct ar1021_i2c* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct ar1021_i2c*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int const*,int) ; 
 struct ar1021_i2c* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct ar1021_i2c*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 

__attribute__((used)) static irqreturn_t ar1021_i2c_irq(int irq, void *dev_id)
{
	struct ar1021_i2c *ar1021 = dev_id;
	struct input_dev *input = ar1021->input;
	u8 *data = ar1021->data;
	unsigned int x, y, button;
	int retval;

	retval = i2c_master_recv(ar1021->client,
				 ar1021->data, sizeof(ar1021->data));
	if (retval != sizeof(ar1021->data))
		goto out;

	/* sync bit set ? */
	if (!(data[0] & BIT(7)))
		goto out;

	button = data[0] & BIT(0);
	x = ((data[2] & 0x1f) << 7) | (data[1] & 0x7f);
	y = ((data[4] & 0x1f) << 7) | (data[3] & 0x7f);

	input_report_abs(input, ABS_X, x);
	input_report_abs(input, ABS_Y, y);
	input_report_key(input, BTN_TOUCH, button);
	input_sync(input);

out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int ar1021_i2c_open(struct input_dev *dev)
{
	static const u8 cmd_enable_touch[] = {
		AR1021_CMD,
		0x01, /* number of bytes after this */
		AR1021_CMD_ENABLE_TOUCH
	};
	struct ar1021_i2c *ar1021 = input_get_drvdata(dev);
	struct i2c_client *client = ar1021->client;
	int error;

	error = i2c_master_send(ar1021->client, cmd_enable_touch,
				sizeof(cmd_enable_touch));
	if (error < 0)
		return error;

	enable_irq(client->irq);

	return 0;
}

__attribute__((used)) static void ar1021_i2c_close(struct input_dev *dev)
{
	struct ar1021_i2c *ar1021 = input_get_drvdata(dev);
	struct i2c_client *client = ar1021->client;

	disable_irq(client->irq);
}

__attribute__((used)) static int ar1021_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct ar1021_i2c *ar1021;
	struct input_dev *input;
	int error;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c_check_functionality error\n");
		return -ENXIO;
	}

	ar1021 = devm_kzalloc(&client->dev, sizeof(*ar1021), GFP_KERNEL);
	if (!ar1021)
		return -ENOMEM;

	input = devm_input_allocate_device(&client->dev);
	if (!input)
		return -ENOMEM;

	ar1021->client = client;
	ar1021->input = input;

	input->name = "ar1021 I2C Touchscreen";
	input->id.bustype = BUS_I2C;
	input->dev.parent = &client->dev;
	input->open = ar1021_i2c_open;
	input->close = ar1021_i2c_close;

	__set_bit(INPUT_PROP_DIRECT, input->propbit);
	input_set_capability(input, EV_KEY, BTN_TOUCH);
	input_set_abs_params(input, ABS_X, 0, AR1021_MAX_X, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, AR1021_MAX_Y, 0, 0);

	input_set_drvdata(input, ar1021);

	error = devm_request_threaded_irq(&client->dev, client->irq,
					  NULL, ar1021_i2c_irq,
					  IRQF_ONESHOT,
					  "ar1021_i2c", ar1021);
	if (error) {
		dev_err(&client->dev,
			"Failed to enable IRQ, error: %d\n", error);
		return error;
	}

	/* Disable the IRQ, we'll enable it in ar1021_i2c_open() */
	disable_irq(client->irq);

	error = input_register_device(ar1021->input);
	if (error) {
		dev_err(&client->dev,
			"Failed to register input device, error: %d\n", error);
		return error;
	}

	return 0;
}

