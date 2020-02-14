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
struct reset_controller_dev {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct of_phandle_args {unsigned int* args; } ;
struct device_node {int dummy; } ;
struct TYPE_3__ {int of_reset_n_cells; int (* of_xlate ) (struct reset_controller_dev*,struct of_phandle_args const*) ;int /*<<< orphan*/  of_node; int /*<<< orphan*/ * ops; int /*<<< orphan*/  owner; } ;
struct berlin_reset_priv {TYPE_1__ rcdev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 unsigned int BERLIN_MAX_RESETS ; 
 int BIT (unsigned long) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  berlin_reset_ops ; 
 struct berlin_reset_priv* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct device_node* of_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int,int) ; 
 int reset_controller_register (TYPE_1__*) ; 
 int /*<<< orphan*/  syscon_node_to_regmap (struct device_node*) ; 
 struct berlin_reset_priv* to_berlin_reset_priv (struct reset_controller_dev*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int berlin_reset_reset(struct reset_controller_dev *rcdev,
			      unsigned long id)
{
	struct berlin_reset_priv *priv = to_berlin_reset_priv(rcdev);
	int offset = id >> 8;
	int mask = BIT(id & 0x1f);

	regmap_write(priv->regmap, offset, mask);

	/* let the reset be effective */
	udelay(10);

	return 0;
}

__attribute__((used)) static int berlin_reset_xlate(struct reset_controller_dev *rcdev,
			      const struct of_phandle_args *reset_spec)
{
	unsigned offset, bit;

	offset = reset_spec->args[0];
	bit = reset_spec->args[1];

	if (bit >= BERLIN_MAX_RESETS)
		return -EINVAL;

	return (offset << 8) | bit;
}

__attribute__((used)) static int berlin2_reset_probe(struct platform_device *pdev)
{
	struct device_node *parent_np = of_get_parent(pdev->dev.of_node);
	struct berlin_reset_priv *priv;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->regmap = syscon_node_to_regmap(parent_np);
	of_node_put(parent_np);
	if (IS_ERR(priv->regmap))
		return PTR_ERR(priv->regmap);

	priv->rcdev.owner = THIS_MODULE;
	priv->rcdev.ops = &berlin_reset_ops;
	priv->rcdev.of_node = pdev->dev.of_node;
	priv->rcdev.of_reset_n_cells = 2;
	priv->rcdev.of_xlate = berlin_reset_xlate;

	return reset_controller_register(&priv->rcdev);
}

