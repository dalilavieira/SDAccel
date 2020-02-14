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
struct TYPE_4__ {unsigned int nr_resets; int /*<<< orphan*/  of_node; int /*<<< orphan*/  owner; int /*<<< orphan*/ * ops; } ;
struct uniphier_reset_priv {TYPE_2__ rcdev; struct uniphier_reset_data const* data; struct regmap* regmap; struct device* dev; } ;
typedef  struct uniphier_reset_data {scalar_t__ id; int flags; int /*<<< orphan*/  bit; int /*<<< orphan*/  reg; } const uniphier_reset_data ;
struct reset_controller_dev {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; TYPE_1__* driver; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int UNIPHIER_RESET_ACTIVE_LOW ; 
 scalar_t__ UNIPHIER_RESET_ID_END ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct uniphier_reset_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_reset_controller_register (struct device*,TYPE_2__*) ; 
 unsigned int max (unsigned int,scalar_t__) ; 
 struct uniphier_reset_data const* of_device_get_match_data (struct device*) ; 
 struct device_node* of_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct regmap* syscon_node_to_regmap (struct device_node*) ; 
 struct uniphier_reset_priv* to_uniphier_reset_priv (struct reset_controller_dev*) ; 
 int /*<<< orphan*/  uniphier_reset_ops ; 

__attribute__((used)) static int uniphier_reset_update(struct reset_controller_dev *rcdev,
				 unsigned long id, int assert)
{
	struct uniphier_reset_priv *priv = to_uniphier_reset_priv(rcdev);
	const struct uniphier_reset_data *p;

	for (p = priv->data; p->id != UNIPHIER_RESET_ID_END; p++) {
		unsigned int mask, val;

		if (p->id != id)
			continue;

		mask = BIT(p->bit);

		if (assert)
			val = mask;
		else
			val = ~mask;

		if (p->flags & UNIPHIER_RESET_ACTIVE_LOW)
			val = ~val;

		return regmap_write_bits(priv->regmap, p->reg, mask, val);
	}

	dev_err(priv->dev, "reset_id=%lu was not handled\n", id);
	return -EINVAL;
}

__attribute__((used)) static int uniphier_reset_assert(struct reset_controller_dev *rcdev,
				 unsigned long id)
{
	return uniphier_reset_update(rcdev, id, 1);
}

__attribute__((used)) static int uniphier_reset_deassert(struct reset_controller_dev *rcdev,
				   unsigned long id)
{
	return uniphier_reset_update(rcdev, id, 0);
}

__attribute__((used)) static int uniphier_reset_status(struct reset_controller_dev *rcdev,
				 unsigned long id)
{
	struct uniphier_reset_priv *priv = to_uniphier_reset_priv(rcdev);
	const struct uniphier_reset_data *p;

	for (p = priv->data; p->id != UNIPHIER_RESET_ID_END; p++) {
		unsigned int val;
		int ret, asserted;

		if (p->id != id)
			continue;

		ret = regmap_read(priv->regmap, p->reg, &val);
		if (ret)
			return ret;

		asserted = !!(val & BIT(p->bit));

		if (p->flags & UNIPHIER_RESET_ACTIVE_LOW)
			asserted = !asserted;

		return asserted;
	}

	dev_err(priv->dev, "reset_id=%lu was not found\n", id);
	return -EINVAL;
}

__attribute__((used)) static int uniphier_reset_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct uniphier_reset_priv *priv;
	const struct uniphier_reset_data *p, *data;
	struct regmap *regmap;
	struct device_node *parent;
	unsigned int nr_resets = 0;

	data = of_device_get_match_data(dev);
	if (WARN_ON(!data))
		return -EINVAL;

	parent = of_get_parent(dev->of_node); /* parent should be syscon node */
	regmap = syscon_node_to_regmap(parent);
	of_node_put(parent);
	if (IS_ERR(regmap)) {
		dev_err(dev, "failed to get regmap (error %ld)\n",
			PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	for (p = data; p->id != UNIPHIER_RESET_ID_END; p++)
		nr_resets = max(nr_resets, p->id + 1);

	priv->rcdev.ops = &uniphier_reset_ops;
	priv->rcdev.owner = dev->driver->owner;
	priv->rcdev.of_node = dev->of_node;
	priv->rcdev.nr_resets = nr_resets;
	priv->dev = dev;
	priv->regmap = regmap;
	priv->data = data;

	return devm_reset_controller_register(&pdev->dev, &priv->rcdev);
}

