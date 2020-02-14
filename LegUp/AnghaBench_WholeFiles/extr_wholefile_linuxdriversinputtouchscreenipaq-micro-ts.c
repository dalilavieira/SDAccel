#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_8__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct touchscreen_data {TYPE_1__* input; struct ipaq_micro* micro; } ;
struct TYPE_14__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_8__ dev; } ;
struct ipaq_micro {void (* ts ) (void*,int,unsigned char*) ;int /*<<< orphan*/  lock; struct touchscreen_data* ts_data; } ;
struct input_dev {int dummy; } ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_13__ {char* name; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  be16_to_cpup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_8__*,char*) ; 
 struct ipaq_micro* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (TYPE_8__*,char*) ; 
 TYPE_1__* devm_input_allocate_device (TYPE_8__*) ; 
 struct touchscreen_data* devm_kzalloc (TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 struct touchscreen_data* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  input_report_abs (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_report_key (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (TYPE_1__*,struct touchscreen_data*) ; 
 int /*<<< orphan*/  input_sync (TYPE_1__*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct touchscreen_data*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void micro_ts_receive(void *data, int len, unsigned char *msg)
{
	struct touchscreen_data *ts = data;

	if (len == 4) {
		input_report_abs(ts->input, ABS_X,
				 be16_to_cpup((__be16 *) &msg[2]));
		input_report_abs(ts->input, ABS_Y,
				 be16_to_cpup((__be16 *) &msg[0]));
		input_report_key(ts->input, BTN_TOUCH, 1);
		input_sync(ts->input);
	} else if (len == 0) {
		input_report_abs(ts->input, ABS_X, 0);
		input_report_abs(ts->input, ABS_Y, 0);
		input_report_key(ts->input, BTN_TOUCH, 0);
		input_sync(ts->input);
	}
}

__attribute__((used)) static void micro_ts_toggle_receive(struct touchscreen_data *ts, bool enable)
{
	struct ipaq_micro *micro = ts->micro;

	spin_lock_irq(&micro->lock);

	if (enable) {
		micro->ts = micro_ts_receive;
		micro->ts_data = ts;
	} else {
		micro->ts = NULL;
		micro->ts_data = NULL;
	}

	spin_unlock_irq(&ts->micro->lock);
}

__attribute__((used)) static int micro_ts_open(struct input_dev *input)
{
	struct touchscreen_data *ts = input_get_drvdata(input);

	micro_ts_toggle_receive(ts, true);

	return 0;
}

__attribute__((used)) static void micro_ts_close(struct input_dev *input)
{
	struct touchscreen_data *ts = input_get_drvdata(input);

	micro_ts_toggle_receive(ts, false);
}

__attribute__((used)) static int micro_ts_probe(struct platform_device *pdev)
{
	struct ipaq_micro *micro = dev_get_drvdata(pdev->dev.parent);
	struct touchscreen_data *ts;
	int error;

	ts = devm_kzalloc(&pdev->dev, sizeof(*ts), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	ts->micro = micro;

	ts->input = devm_input_allocate_device(&pdev->dev);
	if (!ts->input) {
		dev_err(&pdev->dev, "failed to allocate input device\n");
		return -ENOMEM;
	}

	ts->input->name = "ipaq micro ts";
	ts->input->open = micro_ts_open;
	ts->input->close = micro_ts_close;

	input_set_drvdata(ts->input, ts);

	input_set_capability(ts->input, EV_KEY, BTN_TOUCH);
	input_set_capability(ts->input, EV_ABS, ABS_X);
	input_set_capability(ts->input, EV_ABS, ABS_Y);
	input_set_abs_params(ts->input, ABS_X, 0, 1023, 0, 0);
	input_set_abs_params(ts->input, ABS_Y, 0, 1023, 0, 0);

	error = input_register_device(ts->input);
	if (error) {
		dev_err(&pdev->dev, "error registering touch input\n");
		return error;
	}

	platform_set_drvdata(pdev, ts);

	dev_info(&pdev->dev, "iPAQ micro touchscreen\n");

	return 0;
}

