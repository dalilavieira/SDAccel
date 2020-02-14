#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct ts4800_ts {int pendown; int /*<<< orphan*/  phys; struct device* dev; struct input_polled_dev* poll_dev; scalar_t__ base; int /*<<< orphan*/  bit; int /*<<< orphan*/  reg; scalar_t__ regmap; void* debounce; } ;
struct resource {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct input_polled_dev {void (* open ) (struct input_polled_dev*) ;void (* close ) (struct input_polled_dev*) ;void (* poll ) (struct input_polled_dev*) ;struct input_dev* input; int /*<<< orphan*/  poll_interval; struct ts4800_ts* private; } ;
struct input_dev {char* name; int /*<<< orphan*/  phys; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 void* DEBOUNCE_COUNT ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int MAX_12BIT ; 
 int PENDOWN_MASK ; 
 int /*<<< orphan*/  POLL_INTERVAL ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ X_OFFSET ; 
 scalar_t__ Y_OFFSET ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 char* dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct input_polled_dev* devm_input_allocate_polled_device (struct device*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct ts4800_ts* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int input_register_polled_device (struct input_polled_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,int /*<<< orphan*/ *) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readw (scalar_t__) ; 
 int regmap_update_bits (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 scalar_t__ syscon_node_to_regmap (struct device_node*) ; 

__attribute__((used)) static void ts4800_ts_open(struct input_polled_dev *dev)
{
	struct ts4800_ts *ts = dev->private;
	int ret;

	ts->pendown = false;
	ts->debounce = DEBOUNCE_COUNT;

	ret = regmap_update_bits(ts->regmap, ts->reg, ts->bit, ts->bit);
	if (ret)
		dev_warn(ts->dev, "Failed to enable touchscreen\n");
}

__attribute__((used)) static void ts4800_ts_close(struct input_polled_dev *dev)
{
	struct ts4800_ts *ts = dev->private;
	int ret;

	ret = regmap_update_bits(ts->regmap, ts->reg, ts->bit, 0);
	if (ret)
		dev_warn(ts->dev, "Failed to disable touchscreen\n");

}

__attribute__((used)) static void ts4800_ts_poll(struct input_polled_dev *dev)
{
	struct input_dev *input_dev = dev->input;
	struct ts4800_ts *ts = dev->private;
	u16 last_x = readw(ts->base + X_OFFSET);
	u16 last_y = readw(ts->base + Y_OFFSET);
	bool pendown = last_x & PENDOWN_MASK;

	if (pendown) {
		if (ts->debounce) {
			ts->debounce--;
			return;
		}

		if (!ts->pendown) {
			input_report_key(input_dev, BTN_TOUCH, 1);
			ts->pendown = true;
		}

		last_x = ((~last_x) >> 4) & MAX_12BIT;
		last_y = ((~last_y) >> 4) & MAX_12BIT;

		input_report_abs(input_dev, ABS_X, last_x);
		input_report_abs(input_dev, ABS_Y, last_y);
		input_sync(input_dev);
	} else if (ts->pendown) {
		ts->pendown = false;
		ts->debounce = DEBOUNCE_COUNT;
		input_report_key(input_dev, BTN_TOUCH, 0);
		input_sync(input_dev);
	}
}

__attribute__((used)) static int ts4800_parse_dt(struct platform_device *pdev,
			   struct ts4800_ts *ts)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct device_node *syscon_np;
	u32 reg, bit;
	int error;

	syscon_np = of_parse_phandle(np, "syscon", 0);
	if (!syscon_np) {
		dev_err(dev, "no syscon property\n");
		return -ENODEV;
	}

	ts->regmap = syscon_node_to_regmap(syscon_np);
	of_node_put(syscon_np);
	if (IS_ERR(ts->regmap)) {
		dev_err(dev, "cannot get parent's regmap\n");
		return PTR_ERR(ts->regmap);
	}

	error = of_property_read_u32_index(np, "syscon", 1, &reg);
	if (error < 0) {
		dev_err(dev, "no offset in syscon\n");
		return error;
	}

	ts->reg = reg;

	error = of_property_read_u32_index(np, "syscon", 2, &bit);
	if (error < 0) {
		dev_err(dev, "no bit in syscon\n");
		return error;
	}

	ts->bit = BIT(bit);

	return 0;
}

__attribute__((used)) static int ts4800_ts_probe(struct platform_device *pdev)
{
	struct input_polled_dev *poll_dev;
	struct ts4800_ts *ts;
	struct resource *res;
	int error;

	ts = devm_kzalloc(&pdev->dev, sizeof(*ts), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	error = ts4800_parse_dt(pdev, ts);
	if (error)
		return error;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ts->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ts->base))
		return PTR_ERR(ts->base);

	poll_dev = devm_input_allocate_polled_device(&pdev->dev);
	if (!poll_dev)
		return -ENOMEM;

	snprintf(ts->phys, sizeof(ts->phys), "%s/input0", dev_name(&pdev->dev));
	ts->poll_dev = poll_dev;
	ts->dev = &pdev->dev;

	poll_dev->private = ts;
	poll_dev->poll_interval = POLL_INTERVAL;
	poll_dev->open = ts4800_ts_open;
	poll_dev->close = ts4800_ts_close;
	poll_dev->poll = ts4800_ts_poll;

	poll_dev->input->name = "TS-4800 Touchscreen";
	poll_dev->input->phys = ts->phys;

	input_set_capability(poll_dev->input, EV_KEY, BTN_TOUCH);
	input_set_abs_params(poll_dev->input, ABS_X, 0, MAX_12BIT, 0, 0);
	input_set_abs_params(poll_dev->input, ABS_Y, 0, MAX_12BIT, 0, 0);

	error = input_register_polled_device(poll_dev);
	if (error) {
		dev_err(&pdev->dev,
			"Unabled to register polled input device (%d)\n",
			error);
		return error;
	}

	return 0;
}

