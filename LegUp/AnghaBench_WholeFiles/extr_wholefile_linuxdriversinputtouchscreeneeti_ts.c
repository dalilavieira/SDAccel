#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned int u16 ;
struct TYPE_2__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;TYPE_1__ id; int /*<<< orphan*/  name; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  irq; struct device dev; } ;
struct eeti_ts {int running; scalar_t__ attn_gpio; struct input_dev* input; struct i2c_client* client; int /*<<< orphan*/  props; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int EETI_MAXVAL ; 
 unsigned int EETI_TS_BITDEPTH ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int REPORT_BIT_AD0 ; 
 int REPORT_BIT_AD1 ; 
 int REPORT_BIT_HAS_PRESSURE ; 
 int REPORT_BIT_PRESSED ; 
 unsigned int REPORT_RES_BITS (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 scalar_t__ devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 struct eeti_ts* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct eeti_ts*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 unsigned int get_unaligned_be16 (int*) ; 
 scalar_t__ gpiod_get_value_cansleep (scalar_t__) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct eeti_ts*) ; 
 struct eeti_ts* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct eeti_ts*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  touchscreen_parse_properties (struct input_dev*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  touchscreen_report_pos (struct input_dev*,int /*<<< orphan*/ *,unsigned int,unsigned int,int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static void eeti_ts_report_event(struct eeti_ts *eeti, u8 *buf)
{
	unsigned int res;
	u16 x, y;

	res = REPORT_RES_BITS(buf[0] & (REPORT_BIT_AD0 | REPORT_BIT_AD1));

	x = get_unaligned_be16(&buf[1]);
	y = get_unaligned_be16(&buf[3]);

	/* fix the range to 11 bits */
	x >>= res - EETI_TS_BITDEPTH;
	y >>= res - EETI_TS_BITDEPTH;

	if (buf[0] & REPORT_BIT_HAS_PRESSURE)
		input_report_abs(eeti->input, ABS_PRESSURE, buf[5]);

	touchscreen_report_pos(eeti->input, &eeti->props, x, y, false);
	input_report_key(eeti->input, BTN_TOUCH, buf[0] & REPORT_BIT_PRESSED);
	input_sync(eeti->input);
}

__attribute__((used)) static irqreturn_t eeti_ts_isr(int irq, void *dev_id)
{
	struct eeti_ts *eeti = dev_id;
	int len;
	int error;
	char buf[6];

	do {
		len = i2c_master_recv(eeti->client, buf, sizeof(buf));
		if (len != sizeof(buf)) {
			error = len < 0 ? len : -EIO;
			dev_err(&eeti->client->dev,
				"failed to read touchscreen data: %d\n",
				error);
			break;
		}

		if (buf[0] & 0x80) {
			/* Motion packet */
			eeti_ts_report_event(eeti, buf);
		}
	} while (eeti->running &&
		 eeti->attn_gpio && gpiod_get_value_cansleep(eeti->attn_gpio));

	return IRQ_HANDLED;
}

__attribute__((used)) static void eeti_ts_start(struct eeti_ts *eeti)
{
	eeti->running = true;
	wmb();
	enable_irq(eeti->client->irq);
}

__attribute__((used)) static void eeti_ts_stop(struct eeti_ts *eeti)
{
	eeti->running = false;
	wmb();
	disable_irq(eeti->client->irq);
}

__attribute__((used)) static int eeti_ts_open(struct input_dev *dev)
{
	struct eeti_ts *eeti = input_get_drvdata(dev);

	eeti_ts_start(eeti);

	return 0;
}

__attribute__((used)) static void eeti_ts_close(struct input_dev *dev)
{
	struct eeti_ts *eeti = input_get_drvdata(dev);

	eeti_ts_stop(eeti);
}

__attribute__((used)) static int eeti_ts_probe(struct i2c_client *client,
			 const struct i2c_device_id *idp)
{
	struct device *dev = &client->dev;
	struct eeti_ts *eeti;
	struct input_dev *input;
	int error;

	/*
	 * In contrast to what's described in the datasheet, there seems
	 * to be no way of probing the presence of that device using I2C
	 * commands. So we need to blindly believe it is there, and wait
	 * for interrupts to occur.
	 */

	eeti = devm_kzalloc(dev, sizeof(*eeti), GFP_KERNEL);
	if (!eeti) {
		dev_err(dev, "failed to allocate driver data\n");
		return -ENOMEM;
	}

	input = devm_input_allocate_device(dev);
	if (!input) {
		dev_err(dev, "Failed to allocate input device.\n");
		return -ENOMEM;
	}

	input_set_capability(input, EV_KEY, BTN_TOUCH);

	input_set_abs_params(input, ABS_X, 0, EETI_MAXVAL, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, EETI_MAXVAL, 0, 0);
	input_set_abs_params(input, ABS_PRESSURE, 0, 0xff, 0, 0);

	touchscreen_parse_properties(input, false, &eeti->props);

	input->name = client->name;
	input->id.bustype = BUS_I2C;
	input->open = eeti_ts_open;
	input->close = eeti_ts_close;

	eeti->client = client;
	eeti->input = input;

	eeti->attn_gpio = devm_gpiod_get_optional(dev, "attn", GPIOD_IN);
	if (IS_ERR(eeti->attn_gpio))
		return PTR_ERR(eeti->attn_gpio);

	i2c_set_clientdata(client, eeti);
	input_set_drvdata(input, eeti);

	error = devm_request_threaded_irq(dev, client->irq,
					  NULL, eeti_ts_isr,
					  IRQF_ONESHOT,
					  client->name, eeti);
	if (error) {
		dev_err(dev, "Unable to request touchscreen IRQ: %d\n",
			error);
		return error;
	}

	/*
	 * Disable the device for now. It will be enabled once the
	 * input device is opened.
	 */
	eeti_ts_stop(eeti);

	error = input_register_device(input);
	if (error)
		return error;

	return 0;
}

