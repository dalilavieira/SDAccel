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
struct max11801_data {struct input_dev* input_dev; struct i2c_client* client; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; TYPE_2__ dev; TYPE_1__ id; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int APERTURE_CONF_REG ; 
 int AUTO_MODE_TIME_CONF_REG ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int ENOMEM ; 
#define  EVENT_FIFO_END 131 
#define  EVENT_INIT 130 
#define  EVENT_MIDDLE 129 
#define  EVENT_RELEASE 128 
 int EVENT_TAG_MASK ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  FIFO_RD_CMD ; 
 int GENERNAL_STATUS_REG ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int MAX11801_FIFO_INT ; 
 int MAX11801_FIFO_OVERFLOW ; 
 int /*<<< orphan*/  MAX11801_MAX_X ; 
 int /*<<< orphan*/  MAX11801_MAX_Y ; 
 int MEASURE_TAG_MASK ; 
 int MEASURE_X_TAG ; 
 int MEASURE_Y_TAG ; 
 int MESURE_AVER_CONF_REG ; 
 int OP_MODE_CONF_REG ; 
 int PANEL_SETUPTIME_CONF_REG ; 
 int TOUCH_DETECT_PULLUP_CONF_REG ; 
 int XY_BUFSIZE ; 
 int XY_BUF_OFFSET ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 struct max11801_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct max11801_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 

__attribute__((used)) static u8 read_register(struct i2c_client *client, int addr)
{
	/* XXX: The chip ignores LSB of register address */
	return i2c_smbus_read_byte_data(client, addr << 1);
}

__attribute__((used)) static int max11801_write_reg(struct i2c_client *client, int addr, int data)
{
	/* XXX: The chip ignores LSB of register address */
	return i2c_smbus_write_byte_data(client, addr << 1, data);
}

__attribute__((used)) static irqreturn_t max11801_ts_interrupt(int irq, void *dev_id)
{
	struct max11801_data *data = dev_id;
	struct i2c_client *client = data->client;
	int status, i, ret;
	u8 buf[XY_BUFSIZE];
	int x = -1;
	int y = -1;

	status = read_register(data->client, GENERNAL_STATUS_REG);

	if (status & (MAX11801_FIFO_INT | MAX11801_FIFO_OVERFLOW)) {
		status = read_register(data->client, GENERNAL_STATUS_REG);

		ret = i2c_smbus_read_i2c_block_data(client, FIFO_RD_CMD,
						    XY_BUFSIZE, buf);

		/*
		 * We should get 4 bytes buffer that contains X,Y
		 * and event tag
		 */
		if (ret < XY_BUFSIZE)
			goto out;

		for (i = 0; i < XY_BUFSIZE; i += XY_BUFSIZE / 2) {
			if ((buf[i + 1] & MEASURE_TAG_MASK) == MEASURE_X_TAG)
				x = (buf[i] << XY_BUF_OFFSET) +
				    (buf[i + 1] >> XY_BUF_OFFSET);
			else if ((buf[i + 1] & MEASURE_TAG_MASK) == MEASURE_Y_TAG)
				y = (buf[i] << XY_BUF_OFFSET) +
				    (buf[i + 1] >> XY_BUF_OFFSET);
		}

		if ((buf[1] & EVENT_TAG_MASK) != (buf[3] & EVENT_TAG_MASK))
			goto out;

		switch (buf[1] & EVENT_TAG_MASK) {
		case EVENT_INIT:
			/* fall through */
		case EVENT_MIDDLE:
			input_report_abs(data->input_dev, ABS_X, x);
			input_report_abs(data->input_dev, ABS_Y, y);
			input_event(data->input_dev, EV_KEY, BTN_TOUCH, 1);
			input_sync(data->input_dev);
			break;

		case EVENT_RELEASE:
			input_event(data->input_dev, EV_KEY, BTN_TOUCH, 0);
			input_sync(data->input_dev);
			break;

		case EVENT_FIFO_END:
			break;
		}
	}
out:
	return IRQ_HANDLED;
}

__attribute__((used)) static void max11801_ts_phy_init(struct max11801_data *data)
{
	struct i2c_client *client = data->client;

	/* Average X,Y, take 16 samples, average eight media sample */
	max11801_write_reg(client, MESURE_AVER_CONF_REG, 0xff);
	/* X,Y panel setup time set to 20us */
	max11801_write_reg(client, PANEL_SETUPTIME_CONF_REG, 0x11);
	/* Rough pullup time (2uS), Fine pullup time (10us)  */
	max11801_write_reg(client, TOUCH_DETECT_PULLUP_CONF_REG, 0x10);
	/* Auto mode init period = 5ms , scan period = 5ms*/
	max11801_write_reg(client, AUTO_MODE_TIME_CONF_REG, 0xaa);
	/* Aperture X,Y set to +- 4LSB */
	max11801_write_reg(client, APERTURE_CONF_REG, 0x33);
	/* Enable Power, enable Automode, enable Aperture, enable Average X,Y */
	max11801_write_reg(client, OP_MODE_CONF_REG, 0x36);
}

__attribute__((used)) static int max11801_ts_probe(struct i2c_client *client,
				       const struct i2c_device_id *id)
{
	struct max11801_data *data;
	struct input_dev *input_dev;
	int error;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	input_dev = devm_input_allocate_device(&client->dev);
	if (!data || !input_dev) {
		dev_err(&client->dev, "Failed to allocate memory\n");
		return -ENOMEM;
	}

	data->client = client;
	data->input_dev = input_dev;

	input_dev->name = "max11801_ts";
	input_dev->id.bustype = BUS_I2C;
	input_dev->dev.parent = &client->dev;

	__set_bit(EV_ABS, input_dev->evbit);
	__set_bit(EV_KEY, input_dev->evbit);
	__set_bit(BTN_TOUCH, input_dev->keybit);
	input_set_abs_params(input_dev, ABS_X, 0, MAX11801_MAX_X, 0, 0);
	input_set_abs_params(input_dev, ABS_Y, 0, MAX11801_MAX_Y, 0, 0);

	max11801_ts_phy_init(data);

	error = devm_request_threaded_irq(&client->dev, client->irq, NULL,
					  max11801_ts_interrupt,
					  IRQF_TRIGGER_LOW | IRQF_ONESHOT,
					  "max11801_ts", data);
	if (error) {
		dev_err(&client->dev, "Failed to register interrupt\n");
		return error;
	}

	error = input_register_device(data->input_dev);
	if (error)
		return error;

	return 0;
}

