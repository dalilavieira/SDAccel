#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct device {struct device_node* of_node; } ;
struct platform_device {int /*<<< orphan*/  name; struct device dev; } ;
struct input_polled_dev {void (* poll ) (struct input_polled_dev*) ;TYPE_3__* input; int /*<<< orphan*/  poll_interval; struct clps711x_keypad_data* private; } ;
struct device_node {int dummy; } ;
struct clps711x_keypad_data {int row_count; int /*<<< orphan*/  syscon; struct clps711x_gpio_data* gpio_data; int /*<<< orphan*/  row_shift; } ;
struct clps711x_gpio_data {int /*<<< orphan*/  desc; int /*<<< orphan*/  last_state; } ;
struct TYPE_9__ {int vendor; int product; int version; int /*<<< orphan*/  bustype; } ;
struct TYPE_8__ {struct device* parent; } ;
struct TYPE_10__ {unsigned short* keycode; int /*<<< orphan*/  evbit; TYPE_2__ id; TYPE_1__ dev; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int CLPS711X_KEYPAD_COL_COUNT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MATRIX_SCAN_CODE (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYSCON1_KBDSCAN (int) ; 
 int /*<<< orphan*/  SYSCON1_KBDSCAN_MASK ; 
 int /*<<< orphan*/  SYSCON_OFFSET ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  devm_gpiod_get_index (struct device*,char*,int,int /*<<< orphan*/ ) ; 
 struct clps711x_gpio_data* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct clps711x_keypad_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_count_order (int) ; 
 int gpiod_get_value_cansleep (int /*<<< orphan*/ ) ; 
 struct input_polled_dev* input_allocate_polled_device () ; 
 int /*<<< orphan*/  input_event (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_free_polled_device (struct input_polled_dev*) ; 
 int input_register_polled_device (struct input_polled_dev*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,unsigned short const,int) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  input_unregister_polled_device (struct input_polled_dev*) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int of_gpio_named_count (struct device_node*,char*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct input_polled_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct input_polled_dev*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_compatible (char*) ; 
 int test_bit (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void clps711x_keypad_poll(struct input_polled_dev *dev)
{
	const unsigned short *keycodes = dev->input->keycode;
	struct clps711x_keypad_data *priv = dev->private;
	bool sync = false;
	int col, row;

	for (col = 0; col < CLPS711X_KEYPAD_COL_COUNT; col++) {
		/* Assert column */
		regmap_update_bits(priv->syscon, SYSCON_OFFSET,
				   SYSCON1_KBDSCAN_MASK,
				   SYSCON1_KBDSCAN(8 + col));

		/* Scan rows */
		for (row = 0; row < priv->row_count; row++) {
			struct clps711x_gpio_data *data = &priv->gpio_data[row];
			bool state, state1;

			/* Read twice for protection against fluctuations */
			do {
				state = gpiod_get_value_cansleep(data->desc);
				cond_resched();
				state1 = gpiod_get_value_cansleep(data->desc);
			} while (state != state1);

			if (test_bit(col, data->last_state) != state) {
				int code = MATRIX_SCAN_CODE(row, col,
							    priv->row_shift);

				if (state) {
					set_bit(col, data->last_state);
					input_event(dev->input, EV_MSC,
						    MSC_SCAN, code);
				} else {
					clear_bit(col, data->last_state);
				}

				if (keycodes[code])
					input_report_key(dev->input,
							 keycodes[code], state);
				sync = true;
			}
		}

		/* Set all columns to low */
		regmap_update_bits(priv->syscon, SYSCON_OFFSET,
				   SYSCON1_KBDSCAN_MASK, SYSCON1_KBDSCAN(1));
	}

	if (sync)
		input_sync(dev->input);
}

__attribute__((used)) static int clps711x_keypad_probe(struct platform_device *pdev)
{
	struct clps711x_keypad_data *priv;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct input_polled_dev *poll_dev;
	u32 poll_interval;
	int i, err;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->syscon =
		syscon_regmap_lookup_by_compatible("cirrus,ep7209-syscon1");
	if (IS_ERR(priv->syscon))
		return PTR_ERR(priv->syscon);

	priv->row_count = of_gpio_named_count(np, "row-gpios");
	if (priv->row_count < 1)
		return -EINVAL;

	priv->gpio_data = devm_kcalloc(dev,
				priv->row_count, sizeof(*priv->gpio_data),
				GFP_KERNEL);
	if (!priv->gpio_data)
		return -ENOMEM;

	priv->row_shift = get_count_order(CLPS711X_KEYPAD_COL_COUNT);

	for (i = 0; i < priv->row_count; i++) {
		struct clps711x_gpio_data *data = &priv->gpio_data[i];

		data->desc = devm_gpiod_get_index(dev, "row", i, GPIOD_IN);
		if (IS_ERR(data->desc))
			return PTR_ERR(data->desc);
	}

	err = of_property_read_u32(np, "poll-interval", &poll_interval);
	if (err)
		return err;

	poll_dev = input_allocate_polled_device();
	if (!poll_dev)
		return -ENOMEM;

	poll_dev->private		= priv;
	poll_dev->poll			= clps711x_keypad_poll;
	poll_dev->poll_interval		= poll_interval;
	poll_dev->input->name		= pdev->name;
	poll_dev->input->dev.parent	= dev;
	poll_dev->input->id.bustype	= BUS_HOST;
	poll_dev->input->id.vendor	= 0x0001;
	poll_dev->input->id.product	= 0x0001;
	poll_dev->input->id.version	= 0x0100;

	err = matrix_keypad_build_keymap(NULL, NULL, priv->row_count,
					 CLPS711X_KEYPAD_COL_COUNT,
					 NULL, poll_dev->input);
	if (err)
		goto out_err;

	input_set_capability(poll_dev->input, EV_MSC, MSC_SCAN);
	if (of_property_read_bool(np, "autorepeat"))
		__set_bit(EV_REP, poll_dev->input->evbit);

	platform_set_drvdata(pdev, poll_dev);

	/* Set all columns to low */
	regmap_update_bits(priv->syscon, SYSCON_OFFSET, SYSCON1_KBDSCAN_MASK,
			   SYSCON1_KBDSCAN(1));

	err = input_register_polled_device(poll_dev);
	if (err)
		goto out_err;

	return 0;

out_err:
	input_free_polled_device(poll_dev);
	return err;
}

__attribute__((used)) static int clps711x_keypad_remove(struct platform_device *pdev)
{
	struct input_polled_dev *poll_dev = platform_get_drvdata(pdev);

	input_unregister_polled_device(poll_dev);
	input_free_polled_device(poll_dev);

	return 0;
}

