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
typedef  scalar_t__ u32 ;
struct syscfg_reset_controller_data {int nr_channels; TYPE_1__* channels; int /*<<< orphan*/  wait_for_ack; scalar_t__ active_low; } ;
struct TYPE_6__ {int nr_resets; int /*<<< orphan*/  of_node; int /*<<< orphan*/ * ops; } ;
struct syscfg_reset_controller {TYPE_3__ rst; struct syscfg_reset_channel* channels; scalar_t__ active_low; } ;
struct syscfg_reset_channel {struct regmap_field* ack; struct regmap_field* reset; } ;
struct reset_controller_dev {unsigned long nr_resets; } ;
struct regmap_field {int dummy; } ;
typedef  struct regmap_field regmap ;
struct device {TYPE_2__* driver; int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {struct syscfg_reset_controller_data* data; } ;
struct TYPE_5__ {int /*<<< orphan*/  of_match_table; } ;
struct TYPE_4__ {char* compatible; int /*<<< orphan*/  ack; int /*<<< orphan*/  reset; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETIME ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap_field*) ; 
 int PTR_ERR (struct regmap_field*) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 struct syscfg_reset_channel* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct syscfg_reset_controller* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap_field* devm_regmap_field_alloc (struct device*,struct regmap_field*,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int regmap_field_read (struct regmap_field*,scalar_t__*) ; 
 int regmap_field_write (struct regmap_field*,scalar_t__) ; 
 int reset_controller_register (TYPE_3__*) ; 
 int /*<<< orphan*/  syscfg_reset_ops ; 
 struct regmap_field* syscon_regmap_lookup_by_compatible (char const*) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 struct syscfg_reset_controller* to_syscfg_reset_controller (struct reset_controller_dev*) ; 

__attribute__((used)) static int syscfg_reset_program_hw(struct reset_controller_dev *rcdev,
				   unsigned long idx, int assert)
{
	struct syscfg_reset_controller *rst = to_syscfg_reset_controller(rcdev);
	const struct syscfg_reset_channel *ch;
	u32 ctrl_val = rst->active_low ? !assert : !!assert;
	int err;

	if (idx >= rcdev->nr_resets)
		return -EINVAL;

	ch = &rst->channels[idx];

	err = regmap_field_write(ch->reset, ctrl_val);
	if (err)
		return err;

	if (ch->ack) {
		unsigned long timeout = jiffies + msecs_to_jiffies(1000);
		u32 ack_val;

		while (true) {
			err = regmap_field_read(ch->ack, &ack_val);
			if (err)
				return err;

			if (ack_val == ctrl_val)
				break;

			if (time_after(jiffies, timeout))
				return -ETIME;

			cpu_relax();
		}
	}

	return 0;
}

__attribute__((used)) static int syscfg_reset_assert(struct reset_controller_dev *rcdev,
			       unsigned long idx)
{
	return syscfg_reset_program_hw(rcdev, idx, true);
}

__attribute__((used)) static int syscfg_reset_deassert(struct reset_controller_dev *rcdev,
				 unsigned long idx)
{
	return syscfg_reset_program_hw(rcdev, idx, false);
}

__attribute__((used)) static int syscfg_reset_dev(struct reset_controller_dev *rcdev,
			    unsigned long idx)
{
	int err;

	err = syscfg_reset_assert(rcdev, idx);
	if (err)
		return err;

	return syscfg_reset_deassert(rcdev, idx);
}

__attribute__((used)) static int syscfg_reset_status(struct reset_controller_dev *rcdev,
			       unsigned long idx)
{
	struct syscfg_reset_controller *rst = to_syscfg_reset_controller(rcdev);
	const struct syscfg_reset_channel *ch;
	u32 ret_val = 0;
	int err;

	if (idx >= rcdev->nr_resets)
		return -EINVAL;

	ch = &rst->channels[idx];
	if (ch->ack)
		err = regmap_field_read(ch->ack, &ret_val);
	else
		err = regmap_field_read(ch->reset, &ret_val);
	if (err)
		return err;

	return rst->active_low ? !ret_val : !!ret_val;
}

__attribute__((used)) static int syscfg_reset_controller_register(struct device *dev,
				const struct syscfg_reset_controller_data *data)
{
	struct syscfg_reset_controller *rc;
	int i, err;

	rc = devm_kzalloc(dev, sizeof(*rc), GFP_KERNEL);
	if (!rc)
		return -ENOMEM;

	rc->channels = devm_kcalloc(dev, data->nr_channels,
				    sizeof(*rc->channels), GFP_KERNEL);
	if (!rc->channels)
		return -ENOMEM;

	rc->rst.ops = &syscfg_reset_ops,
	rc->rst.of_node = dev->of_node;
	rc->rst.nr_resets = data->nr_channels;
	rc->active_low = data->active_low;

	for (i = 0; i < data->nr_channels; i++) {
		struct regmap *map;
		struct regmap_field *f;
		const char *compatible = data->channels[i].compatible;

		map = syscon_regmap_lookup_by_compatible(compatible);
		if (IS_ERR(map))
			return PTR_ERR(map);

		f = devm_regmap_field_alloc(dev, map, data->channels[i].reset);
		if (IS_ERR(f))
			return PTR_ERR(f);

		rc->channels[i].reset = f;

		if (!data->wait_for_ack)
			continue;

		f = devm_regmap_field_alloc(dev, map, data->channels[i].ack);
		if (IS_ERR(f))
			return PTR_ERR(f);

		rc->channels[i].ack = f;
	}

	err = reset_controller_register(&rc->rst);
	if (!err)
		dev_info(dev, "registered\n");

	return err;
}

int syscfg_reset_probe(struct platform_device *pdev)
{
	struct device *dev = pdev ? &pdev->dev : NULL;
	const struct of_device_id *match;

	if (!dev || !dev->driver)
		return -ENODEV;

	match = of_match_device(dev->driver->of_match_table, dev);
	if (!match || !match->data)
		return -EINVAL;

	return syscfg_reset_controller_register(dev, match->data);
}

