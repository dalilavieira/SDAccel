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
typedef  int uint8_t ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; TYPE_2__ dev; TYPE_1__ id; } ;
struct i2c_msg {int flags; int len; int* buf; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
struct as5011_platform_data {int xp; int xn; int yp; int yn; int axis_irq; int axis_irqflags; int /*<<< orphan*/  button_gpio; } ;
struct as5011_device {int axis_irq; int button_irq; struct input_dev* input_dev; int /*<<< orphan*/  button_gpio; struct i2c_client* i2c_client; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int AS5011_CTRL1 ; 
 int AS5011_CTRL1_INT_ACT_EN ; 
 int AS5011_CTRL1_LP_ACTIVE ; 
 int AS5011_CTRL1_LP_PULSED ; 
 int AS5011_CTRL1_SOFT_RST ; 
 int AS5011_CTRL2 ; 
 int AS5011_CTRL2_INV_SPINNING ; 
 int /*<<< orphan*/  AS5011_FLAT ; 
 int /*<<< orphan*/  AS5011_FUZZ ; 
 int /*<<< orphan*/  AS5011_MAX_AXIS ; 
 int /*<<< orphan*/  AS5011_MIN_AXIS ; 
 int AS5011_XN ; 
 int AS5011_XP ; 
 int AS5011_X_RES_INT ; 
 int AS5011_YN ; 
 int AS5011_YP ; 
 int AS5011_Y_RES_INT ; 
 int /*<<< orphan*/  BTN_JOYSTICK ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_NOSTART ; 
 int I2C_FUNC_PROTOCOL_MANGLING ; 
 int I2C_M_IGNORE_NAK ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 int I2C_M_REV_DIR_ADDR ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct as5011_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_irq (int,struct as5011_device*) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_get_value_cansleep (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int gpio_to_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 struct as5011_device* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct as5011_device*) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct as5011_device*) ; 
 struct as5011_device* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct as5011_device*) ; 

__attribute__((used)) static int as5011_i2c_write(struct i2c_client *client,
			    uint8_t aregaddr,
			    uint8_t avalue)
{
	uint8_t data[2] = { aregaddr, avalue };
	struct i2c_msg msg = {
		.addr = client->addr,
		.flags = I2C_M_IGNORE_NAK,
		.len = 2,
		.buf = (uint8_t *)data
	};
	int error;

	error = i2c_transfer(client->adapter, &msg, 1);
	return error < 0 ? error : 0;
}

__attribute__((used)) static int as5011_i2c_read(struct i2c_client *client,
			   uint8_t aregaddr, signed char *value)
{
	uint8_t data[2] = { aregaddr };
	struct i2c_msg msg_set[2] = {
		{
			.addr = client->addr,
			.flags = I2C_M_REV_DIR_ADDR,
			.len = 1,
			.buf = (uint8_t *)data
		},
		{
			.addr = client->addr,
			.flags = I2C_M_RD | I2C_M_NOSTART,
			.len = 1,
			.buf = (uint8_t *)data
		}
	};
	int error;

	error = i2c_transfer(client->adapter, msg_set, 2);
	if (error < 0)
		return error;

	*value = data[0] & 0x80 ? -1 * (1 + ~data[0]) : data[0];
	return 0;
}

__attribute__((used)) static irqreturn_t as5011_button_interrupt(int irq, void *dev_id)
{
	struct as5011_device *as5011 = dev_id;
	int val = gpio_get_value_cansleep(as5011->button_gpio);

	input_report_key(as5011->input_dev, BTN_JOYSTICK, !val);
	input_sync(as5011->input_dev);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t as5011_axis_interrupt(int irq, void *dev_id)
{
	struct as5011_device *as5011 = dev_id;
	int error;
	signed char x, y;

	error = as5011_i2c_read(as5011->i2c_client, AS5011_X_RES_INT, &x);
	if (error < 0)
		goto out;

	error = as5011_i2c_read(as5011->i2c_client, AS5011_Y_RES_INT, &y);
	if (error < 0)
		goto out;

	input_report_abs(as5011->input_dev, ABS_X, x);
	input_report_abs(as5011->input_dev, ABS_Y, y);
	input_sync(as5011->input_dev);

out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int as5011_configure_chip(struct as5011_device *as5011,
				const struct as5011_platform_data *plat_dat)
{
	struct i2c_client *client = as5011->i2c_client;
	int error;
	signed char value;

	/* chip soft reset */
	error = as5011_i2c_write(client, AS5011_CTRL1,
				 AS5011_CTRL1_SOFT_RST);
	if (error < 0) {
		dev_err(&client->dev, "Soft reset failed\n");
		return error;
	}

	mdelay(10);

	error = as5011_i2c_write(client, AS5011_CTRL1,
				 AS5011_CTRL1_LP_PULSED |
				 AS5011_CTRL1_LP_ACTIVE |
				 AS5011_CTRL1_INT_ACT_EN);
	if (error < 0) {
		dev_err(&client->dev, "Power config failed\n");
		return error;
	}

	error = as5011_i2c_write(client, AS5011_CTRL2,
				 AS5011_CTRL2_INV_SPINNING);
	if (error < 0) {
		dev_err(&client->dev, "Can't invert spinning\n");
		return error;
	}

	/* write threshold */
	error = as5011_i2c_write(client, AS5011_XP, plat_dat->xp);
	if (error < 0) {
		dev_err(&client->dev, "Can't write threshold\n");
		return error;
	}

	error = as5011_i2c_write(client, AS5011_XN, plat_dat->xn);
	if (error < 0) {
		dev_err(&client->dev, "Can't write threshold\n");
		return error;
	}

	error = as5011_i2c_write(client, AS5011_YP, plat_dat->yp);
	if (error < 0) {
		dev_err(&client->dev, "Can't write threshold\n");
		return error;
	}

	error = as5011_i2c_write(client, AS5011_YN, plat_dat->yn);
	if (error < 0) {
		dev_err(&client->dev, "Can't write threshold\n");
		return error;
	}

	/* to free irq gpio in chip */
	error = as5011_i2c_read(client, AS5011_X_RES_INT, &value);
	if (error < 0) {
		dev_err(&client->dev, "Can't read i2c X resolution value\n");
		return error;
	}

	return 0;
}

__attribute__((used)) static int as5011_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	const struct as5011_platform_data *plat_data;
	struct as5011_device *as5011;
	struct input_dev *input_dev;
	int irq;
	int error;

	plat_data = dev_get_platdata(&client->dev);
	if (!plat_data)
		return -EINVAL;

	if (!plat_data->axis_irq) {
		dev_err(&client->dev, "No axis IRQ?\n");
		return -EINVAL;
	}

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_NOSTART |
				     I2C_FUNC_PROTOCOL_MANGLING)) {
		dev_err(&client->dev,
			"need i2c bus that supports protocol mangling\n");
		return -ENODEV;
	}

	as5011 = kmalloc(sizeof(struct as5011_device), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!as5011 || !input_dev) {
		dev_err(&client->dev,
			"Can't allocate memory for device structure\n");
		error = -ENOMEM;
		goto err_free_mem;
	}

	as5011->i2c_client = client;
	as5011->input_dev = input_dev;
	as5011->button_gpio = plat_data->button_gpio;
	as5011->axis_irq = plat_data->axis_irq;

	input_dev->name = "Austria Microsystem as5011 joystick";
	input_dev->id.bustype = BUS_I2C;
	input_dev->dev.parent = &client->dev;

	input_set_capability(input_dev, EV_KEY, BTN_JOYSTICK);

	input_set_abs_params(input_dev, ABS_X,
		AS5011_MIN_AXIS, AS5011_MAX_AXIS, AS5011_FUZZ, AS5011_FLAT);
	input_set_abs_params(as5011->input_dev, ABS_Y,
		AS5011_MIN_AXIS, AS5011_MAX_AXIS, AS5011_FUZZ, AS5011_FLAT);

	error = gpio_request(as5011->button_gpio, "AS5011 button");
	if (error < 0) {
		dev_err(&client->dev, "Failed to request button gpio\n");
		goto err_free_mem;
	}

	irq = gpio_to_irq(as5011->button_gpio);
	if (irq < 0) {
		dev_err(&client->dev,
			"Failed to get irq number for button gpio\n");
		error = irq;
		goto err_free_button_gpio;
	}

	as5011->button_irq = irq;

	error = request_threaded_irq(as5011->button_irq,
				     NULL, as5011_button_interrupt,
				     IRQF_TRIGGER_RISING |
					IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				     "as5011_button", as5011);
	if (error < 0) {
		dev_err(&client->dev,
			"Can't allocate button irq %d\n", as5011->button_irq);
		goto err_free_button_gpio;
	}

	error = as5011_configure_chip(as5011, plat_data);
	if (error)
		goto err_free_button_irq;

	error = request_threaded_irq(as5011->axis_irq, NULL,
				     as5011_axis_interrupt,
				     plat_data->axis_irqflags | IRQF_ONESHOT,
				     "as5011_joystick", as5011);
	if (error) {
		dev_err(&client->dev,
			"Can't allocate axis irq %d\n", plat_data->axis_irq);
		goto err_free_button_irq;
	}

	error = input_register_device(as5011->input_dev);
	if (error) {
		dev_err(&client->dev, "Failed to register input device\n");
		goto err_free_axis_irq;
	}

	i2c_set_clientdata(client, as5011);

	return 0;

err_free_axis_irq:
	free_irq(as5011->axis_irq, as5011);
err_free_button_irq:
	free_irq(as5011->button_irq, as5011);
err_free_button_gpio:
	gpio_free(as5011->button_gpio);
err_free_mem:
	input_free_device(input_dev);
	kfree(as5011);

	return error;
}

__attribute__((used)) static int as5011_remove(struct i2c_client *client)
{
	struct as5011_device *as5011 = i2c_get_clientdata(client);

	free_irq(as5011->axis_irq, as5011);
	free_irq(as5011->button_irq, as5011);
	gpio_free(as5011->button_gpio);

	input_unregister_device(as5011->input_dev);
	kfree(as5011);

	return 0;
}

