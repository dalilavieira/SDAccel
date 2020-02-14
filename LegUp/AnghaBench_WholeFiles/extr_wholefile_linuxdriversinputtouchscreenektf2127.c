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
struct input_mt_pos {int x; int y; } ;
struct TYPE_2__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;TYPE_1__ id; int /*<<< orphan*/  name; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  irq; struct device dev; } ;
struct ektf2127_ts {struct input_dev* input; int /*<<< orphan*/  prop; struct i2c_client* client; int /*<<< orphan*/  power_gpios; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_MT_POSITION_X ; 
 int /*<<< orphan*/  ABS_MT_POSITION_Y ; 
 int /*<<< orphan*/  BUS_I2C ; 
 int EINVAL ; 
 int EIO ; 
#define  EKTF2127_CALIB_DONE 131 
 char EKTF2127_ENV_NOISY ; 
 int EKTF2127_HEIGHT ; 
#define  EKTF2127_HELLO 130 
 int EKTF2127_MAX_TOUCHES ; 
#define  EKTF2127_NOISE 129 
#define  EKTF2127_REPORT 128 
 int EKTF2127_REQUEST ; 
 int EKTF2127_RESPONSE ; 
 int EKTF2127_TOUCH_REPORT_SIZE ; 
 int EKTF2127_WIDTH ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int INPUT_MT_DIRECT ; 
 int INPUT_MT_DROP_UNUSED ; 
 int INPUT_MT_TRACK ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MT_TOOL_FINGER ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 struct ektf2127_ts* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ektf2127_ts*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int i2c_master_recv (struct i2c_client*,...) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ektf2127_ts*) ; 
 struct ektf2127_ts* input_get_drvdata (struct input_dev*) ; 
 int /*<<< orphan*/  input_mt_assign_slots (struct input_dev*,int*,struct input_mt_pos*,unsigned int,int /*<<< orphan*/ ) ; 
 int input_mt_init_slots (struct input_dev*,int,int) ; 
 int /*<<< orphan*/  input_mt_report_slot_state (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_mt_slot (struct input_dev*,int) ; 
 int /*<<< orphan*/  input_mt_sync_frame (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct ektf2127_ts*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  touchscreen_parse_properties (struct input_dev*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  touchscreen_report_pos (struct input_dev*,int /*<<< orphan*/ *,int const,int const,int) ; 

__attribute__((used)) static void ektf2127_parse_coordinates(const u8* buf, unsigned int touch_count,
				       struct input_mt_pos *touches)
{
	int index = 0;
	int i;

	for (i = 0; i < touch_count; i++) {
		index = 2 + i * 3;

		touches[i].x = (buf[index] & 0x0f);
		touches[i].x <<= 8;
		touches[i].x |= buf[index + 2];

		touches[i].y = (buf[index] & 0xf0);
		touches[i].y <<= 4;
		touches[i].y |= buf[index + 1];
	}
}

__attribute__((used)) static void ektf2127_report_event(struct ektf2127_ts *ts, const u8 *buf)
{
	struct input_mt_pos touches[EKTF2127_MAX_TOUCHES];
	int slots[EKTF2127_MAX_TOUCHES];
	unsigned int touch_count, i;

	touch_count = buf[1] & 0x07;
	if (touch_count > EKTF2127_MAX_TOUCHES) {
		dev_err(&ts->client->dev,
			"Too many touches %d > %d\n",
			touch_count, EKTF2127_MAX_TOUCHES);
		touch_count = EKTF2127_MAX_TOUCHES;
	}

	ektf2127_parse_coordinates(buf, touch_count, touches);
	input_mt_assign_slots(ts->input, slots, touches,
			      touch_count, 0);

	for (i = 0; i < touch_count; i++) {
		input_mt_slot(ts->input, slots[i]);
		input_mt_report_slot_state(ts->input, MT_TOOL_FINGER, true);
		touchscreen_report_pos(ts->input, &ts->prop,
				       touches[i].x, touches[i].y, true);
	}

	input_mt_sync_frame(ts->input);
	input_sync(ts->input);
}

__attribute__((used)) static irqreturn_t ektf2127_irq(int irq, void *dev_id)
{
	struct ektf2127_ts *ts = dev_id;
	struct device *dev = &ts->client->dev;
	char buf[EKTF2127_TOUCH_REPORT_SIZE];
	int ret;

	ret = i2c_master_recv(ts->client, buf, EKTF2127_TOUCH_REPORT_SIZE);
	if (ret != EKTF2127_TOUCH_REPORT_SIZE) {
		dev_err(dev, "Error reading touch data: %d\n", ret);
		goto out;
	}

	switch (buf[0]) {
	case EKTF2127_REPORT:
		ektf2127_report_event(ts, buf);
		break;

	case EKTF2127_NOISE:
		if (buf[1] == EKTF2127_ENV_NOISY)
			dev_dbg(dev, "Environment is electrically noisy\n");
		break;

	case EKTF2127_HELLO:
	case EKTF2127_CALIB_DONE:
		break;

	default:
		dev_err(dev, "Unexpected packet header byte %#02x\n", buf[0]);
		break;
	}

out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int ektf2127_start(struct input_dev *dev)
{
	struct ektf2127_ts *ts = input_get_drvdata(dev);

	enable_irq(ts->client->irq);
	gpiod_set_value_cansleep(ts->power_gpios, 1);

	return 0;
}

__attribute__((used)) static void ektf2127_stop(struct input_dev *dev)
{
	struct ektf2127_ts *ts = input_get_drvdata(dev);

	disable_irq(ts->client->irq);
	gpiod_set_value_cansleep(ts->power_gpios, 0);
}

__attribute__((used)) static int ektf2127_query_dimension(struct i2c_client *client, bool width)
{
	struct device *dev = &client->dev;
	const char *what = width ? "width" : "height";
	u8 what_code = width ? EKTF2127_WIDTH : EKTF2127_HEIGHT;
	u8 buf[4];
	int ret;
	int error;

	/* Request dimension */
	buf[0] = EKTF2127_REQUEST;
	buf[1] = width ? EKTF2127_WIDTH : EKTF2127_HEIGHT;
	buf[2] = 0x00;
	buf[3] = 0x00;
	ret = i2c_master_send(client, buf, sizeof(buf));
	if (ret != sizeof(buf)) {
		error = ret < 0 ? ret : -EIO;
		dev_err(dev, "Failed to request %s: %d\n", what, error);
		return error;
	}

	msleep(20);

	/* Read response */
	ret = i2c_master_recv(client, buf, sizeof(buf));
	if (ret != sizeof(buf)) {
		error = ret < 0 ? ret : -EIO;
		dev_err(dev, "Failed to receive %s data: %d\n", what, error);
		return error;
	}

	if (buf[0] != EKTF2127_RESPONSE || buf[1] != what_code) {
		dev_err(dev, "Unexpected %s data: %#02x %#02x\n",
			what, buf[0], buf[1]);
		return -EIO;
	}

	return (((buf[3] & 0xf0) << 4) | buf[2]) - 1;
}

__attribute__((used)) static int ektf2127_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct ektf2127_ts *ts;
	struct input_dev *input;
	u8 buf[4];
	int max_x, max_y;
	int error;

	if (!client->irq) {
		dev_err(dev, "Error no irq specified\n");
		return -EINVAL;
	}

	ts = devm_kzalloc(dev, sizeof(*ts), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	/* This requests the gpio *and* turns on the touchscreen controller */
	ts->power_gpios = devm_gpiod_get(dev, "power", GPIOD_OUT_HIGH);
	if (IS_ERR(ts->power_gpios)) {
		error = PTR_ERR(ts->power_gpios);
		if (error != -EPROBE_DEFER)
			dev_err(dev, "Error getting power gpio: %d\n", error);
		return error;
	}

	input = devm_input_allocate_device(dev);
	if (!input)
		return -ENOMEM;

	input->name = client->name;
	input->id.bustype = BUS_I2C;
	input->open = ektf2127_start;
	input->close = ektf2127_stop;

	ts->client = client;

	/* Read hello (ignore result, depends on initial power state) */
	msleep(20);
	i2c_master_recv(ts->client, buf, sizeof(buf));

	/* Read resolution from chip */
	max_x = ektf2127_query_dimension(client, true);
	if (max_x < 0)
		return max_x;

	max_y = ektf2127_query_dimension(client, false);
	if (max_y < 0)
		return max_y;

	input_set_abs_params(input, ABS_MT_POSITION_X, 0, max_x, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y, 0, max_y, 0, 0);
	touchscreen_parse_properties(input, true, &ts->prop);

	error = input_mt_init_slots(input, EKTF2127_MAX_TOUCHES,
				    INPUT_MT_DIRECT |
					INPUT_MT_DROP_UNUSED |
					INPUT_MT_TRACK);
	if (error)
		return error;

	ts->input = input;
	input_set_drvdata(input, ts);

	error = devm_request_threaded_irq(dev, client->irq,
					  NULL, ektf2127_irq,
					  IRQF_ONESHOT, client->name, ts);
	if (error) {
		dev_err(dev, "Error requesting irq: %d\n", error);
		return error;
	}

	/* Stop device till opened */
	ektf2127_stop(ts->input);

	error = input_register_device(input);
	if (error)
		return error;

	i2c_set_clientdata(client, ts);

	return 0;
}

