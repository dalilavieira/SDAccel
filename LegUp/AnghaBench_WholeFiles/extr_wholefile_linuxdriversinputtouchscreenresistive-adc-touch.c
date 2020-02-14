#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u16 ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_4__ {struct device* parent; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;TYPE_3__ id; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_channel {TYPE_2__* channel; scalar_t__ indio_dev; } ;
struct grts_state {int pressure; unsigned int pressure_min; struct iio_channel* iio_cb; struct input_dev* input; int /*<<< orphan*/  prop; struct iio_channel* iio_chans; } ;
struct TYPE_5__ {int /*<<< orphan*/  datasheet_name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int GRTS_DEFAULT_PRESSURE_MIN ; 
 int GRTS_MAX_POS_MASK ; 
 scalar_t__ IS_ERR (struct iio_channel*) ; 
 int PTR_ERR (struct iio_channel*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int device_property_read_u32 (struct device*,char*,unsigned int*) ; 
 int devm_add_action_or_reset (struct device*,void (*) (void*),struct iio_channel*) ; 
 struct iio_channel* devm_iio_channel_get_all (struct device*) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 struct grts_state* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct iio_channel* iio_channel_get_all_cb (struct device*,int (*) (void const*,void*),struct grts_state*) ; 
 int /*<<< orphan*/  iio_channel_release_all_cb (void*) ; 
 int iio_channel_start_all_cb (struct iio_channel*) ; 
 int /*<<< orphan*/  iio_channel_stop_all_cb (struct iio_channel*) ; 
 struct grts_state* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,unsigned int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct grts_state*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  touchscreen_parse_properties (struct input_dev*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  touchscreen_report_pos (struct input_dev*,int /*<<< orphan*/ *,unsigned int,unsigned int,int) ; 

__attribute__((used)) static int grts_cb(const void *data, void *private)
{
	const u16 *touch_info = data;
	struct grts_state *st = private;
	unsigned int x, y, press = 0x0;

	/* channel data coming in buffer in the order below */
	x = touch_info[0];
	y = touch_info[1];
	if (st->pressure)
		press = touch_info[2];

	if ((!x && !y) || (st->pressure && (press < st->pressure_min))) {
		/* report end of touch */
		input_report_key(st->input, BTN_TOUCH, 0);
		input_sync(st->input);
		return 0;
	}

	/* report proper touch to subsystem*/
	touchscreen_report_pos(st->input, &st->prop, x, y, false);
	if (st->pressure)
		input_report_abs(st->input, ABS_PRESSURE, press);
	input_report_key(st->input, BTN_TOUCH, 1);
	input_sync(st->input);

	return 0;
}

__attribute__((used)) static int grts_open(struct input_dev *dev)
{
	int error;
	struct grts_state *st = input_get_drvdata(dev);

	error = iio_channel_start_all_cb(st->iio_cb);
	if (error) {
		dev_err(dev->dev.parent, "failed to start callback buffer.\n");
		return error;
	}
	return 0;
}

__attribute__((used)) static void grts_close(struct input_dev *dev)
{
	struct grts_state *st = input_get_drvdata(dev);

	iio_channel_stop_all_cb(st->iio_cb);
}

__attribute__((used)) static void grts_disable(void *data)
{
	iio_channel_release_all_cb(data);
}

__attribute__((used)) static int grts_probe(struct platform_device *pdev)
{
	struct grts_state *st;
	struct input_dev *input;
	struct device *dev = &pdev->dev;
	struct iio_channel *chan;
	int error;

	st = devm_kzalloc(dev, sizeof(struct grts_state), GFP_KERNEL);
	if (!st)
		return -ENOMEM;

	/* get the channels from IIO device */
	st->iio_chans = devm_iio_channel_get_all(dev);
	if (IS_ERR(st->iio_chans)) {
		error = PTR_ERR(st->iio_chans);
		if (error != -EPROBE_DEFER)
			dev_err(dev, "can't get iio channels.\n");
		return error;
	}

	chan = &st->iio_chans[0];
	st->pressure = false;
	while (chan && chan->indio_dev) {
		if (!strcmp(chan->channel->datasheet_name, "pressure"))
			st->pressure = true;
		chan++;
	}

	if (st->pressure) {
		error = device_property_read_u32(dev,
						 "touchscreen-min-pressure",
						 &st->pressure_min);
		if (error) {
			dev_dbg(dev, "can't get touchscreen-min-pressure property.\n");
			st->pressure_min = GRTS_DEFAULT_PRESSURE_MIN;
		}
	}

	input = devm_input_allocate_device(dev);
	if (!input) {
		dev_err(dev, "failed to allocate input device.\n");
		return -ENOMEM;
	}

	input->name = DRIVER_NAME;
	input->id.bustype = BUS_HOST;
	input->open = grts_open;
	input->close = grts_close;

	input_set_abs_params(input, ABS_X, 0, GRTS_MAX_POS_MASK - 1, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, GRTS_MAX_POS_MASK - 1, 0, 0);
	if (st->pressure)
		input_set_abs_params(input, ABS_PRESSURE, st->pressure_min,
				     0xffff, 0, 0);

	input_set_capability(input, EV_KEY, BTN_TOUCH);

	/* parse optional device tree properties */
	touchscreen_parse_properties(input, false, &st->prop);

	st->input = input;
	input_set_drvdata(input, st);

	error = input_register_device(input);
	if (error) {
		dev_err(dev, "failed to register input device.");
		return error;
	}

	st->iio_cb = iio_channel_get_all_cb(dev, grts_cb, st);
	if (IS_ERR(st->iio_cb)) {
		dev_err(dev, "failed to allocate callback buffer.\n");
		return PTR_ERR(st->iio_cb);
	}

	error = devm_add_action_or_reset(dev, grts_disable, st->iio_cb);
	if (error) {
		dev_err(dev, "failed to add disable action.\n");
		return error;
	}

	return 0;
}

