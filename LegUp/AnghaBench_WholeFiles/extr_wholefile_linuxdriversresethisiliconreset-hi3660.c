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
struct reset_controller_dev {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct of_phandle_args {unsigned int* args; } ;
struct TYPE_2__ {int of_reset_n_cells; int (* of_xlate ) (struct reset_controller_dev*,struct of_phandle_args const*) ;struct device_node* of_node; int /*<<< orphan*/ * ops; } ;
struct hi3660_reset_controller {TYPE_1__ rst; int /*<<< orphan*/  map; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 unsigned int BIT (unsigned long) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct hi3660_reset_controller* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hi3660_reset_ops ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int reset_controller_register (TYPE_1__*) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 
 struct hi3660_reset_controller* to_hi3660_reset_controller (struct reset_controller_dev*) ; 

__attribute__((used)) static int hi3660_reset_program_hw(struct reset_controller_dev *rcdev,
				   unsigned long idx, bool assert)
{
	struct hi3660_reset_controller *rc = to_hi3660_reset_controller(rcdev);
	unsigned int offset = idx >> 8;
	unsigned int mask = BIT(idx & 0x1f);

	if (assert)
		return regmap_write(rc->map, offset, mask);
	else
		return regmap_write(rc->map, offset + 4, mask);
}

__attribute__((used)) static int hi3660_reset_assert(struct reset_controller_dev *rcdev,
			       unsigned long idx)
{
	return hi3660_reset_program_hw(rcdev, idx, true);
}

__attribute__((used)) static int hi3660_reset_deassert(struct reset_controller_dev *rcdev,
				 unsigned long idx)
{
	return hi3660_reset_program_hw(rcdev, idx, false);
}

__attribute__((used)) static int hi3660_reset_dev(struct reset_controller_dev *rcdev,
			    unsigned long idx)
{
	int err;

	err = hi3660_reset_assert(rcdev, idx);
	if (err)
		return err;

	return hi3660_reset_deassert(rcdev, idx);
}

__attribute__((used)) static int hi3660_reset_xlate(struct reset_controller_dev *rcdev,
			      const struct of_phandle_args *reset_spec)
{
	unsigned int offset, bit;

	offset = reset_spec->args[0];
	bit = reset_spec->args[1];

	return (offset << 8) | bit;
}

__attribute__((used)) static int hi3660_reset_probe(struct platform_device *pdev)
{
	struct hi3660_reset_controller *rc;
	struct device_node *np = pdev->dev.of_node;
	struct device *dev = &pdev->dev;

	rc = devm_kzalloc(dev, sizeof(*rc), GFP_KERNEL);
	if (!rc)
		return -ENOMEM;

	rc->map = syscon_regmap_lookup_by_phandle(np, "hisi,rst-syscon");
	if (IS_ERR(rc->map)) {
		dev_err(dev, "failed to get hi3660,rst-syscon\n");
		return PTR_ERR(rc->map);
	}

	rc->rst.ops = &hi3660_reset_ops,
	rc->rst.of_node = np;
	rc->rst.of_reset_n_cells = 2;
	rc->rst.of_xlate = hi3660_reset_xlate;

	return reset_controller_register(&rc->rst);
}

