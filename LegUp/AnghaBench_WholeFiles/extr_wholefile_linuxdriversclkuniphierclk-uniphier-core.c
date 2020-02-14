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
struct TYPE_2__ {int /*<<< orphan*/  mux; int /*<<< orphan*/  gate; int /*<<< orphan*/  rate; int /*<<< orphan*/  factor; int /*<<< orphan*/  cpugear; } ;
struct uniphier_clk_data {int type; size_t idx; scalar_t__ name; TYPE_1__ data; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
struct clk_hw_onecell_data {int num; struct regmap** hws; } ;
typedef  struct regmap clk_hw ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 struct regmap* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
#define  UNIPHIER_CLK_TYPE_CPUGEAR 132 
#define  UNIPHIER_CLK_TYPE_FIXED_FACTOR 131 
#define  UNIPHIER_CLK_TYPE_FIXED_RATE 130 
#define  UNIPHIER_CLK_TYPE_GATE 129 
#define  UNIPHIER_CLK_TYPE_MUX 128 
 scalar_t__ WARN (scalar_t__,char*,scalar_t__) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,scalar_t__,size_t) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct clk_hw_onecell_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int max (int,size_t) ; 
 int of_clk_add_hw_provider (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct clk_hw_onecell_data*) ; 
 int /*<<< orphan*/  of_clk_del_provider (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_clk_hw_onecell_get ; 
 struct uniphier_clk_data* of_device_get_match_data (struct device*) ; 
 struct device_node* of_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct regmap* syscon_node_to_regmap (struct device_node*) ; 
 struct regmap* uniphier_clk_register_cpugear (struct device*,struct regmap*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct regmap* uniphier_clk_register_fixed_factor (struct device*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct regmap* uniphier_clk_register_fixed_rate (struct device*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct regmap* uniphier_clk_register_gate (struct device*,struct regmap*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct regmap* uniphier_clk_register_mux (struct device*,struct regmap*,scalar_t__,int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct clk_hw *uniphier_clk_register(struct device *dev,
					    struct regmap *regmap,
					const struct uniphier_clk_data *data)
{
	switch (data->type) {
	case UNIPHIER_CLK_TYPE_CPUGEAR:
		return uniphier_clk_register_cpugear(dev, regmap, data->name,
						     &data->data.cpugear);
	case UNIPHIER_CLK_TYPE_FIXED_FACTOR:
		return uniphier_clk_register_fixed_factor(dev, data->name,
							  &data->data.factor);
	case UNIPHIER_CLK_TYPE_FIXED_RATE:
		return uniphier_clk_register_fixed_rate(dev, data->name,
							&data->data.rate);
	case UNIPHIER_CLK_TYPE_GATE:
		return uniphier_clk_register_gate(dev, regmap, data->name,
						  &data->data.gate);
	case UNIPHIER_CLK_TYPE_MUX:
		return uniphier_clk_register_mux(dev, regmap, data->name,
						 &data->data.mux);
	default:
		dev_err(dev, "unsupported clock type\n");
		return ERR_PTR(-EINVAL);
	}
}

__attribute__((used)) static int uniphier_clk_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct clk_hw_onecell_data *hw_data;
	const struct uniphier_clk_data *p, *data;
	struct regmap *regmap;
	struct device_node *parent;
	int clk_num = 0;

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

	for (p = data; p->name; p++)
		clk_num = max(clk_num, p->idx + 1);

	hw_data = devm_kzalloc(dev,
			sizeof(*hw_data) + clk_num * sizeof(struct clk_hw *),
			GFP_KERNEL);
	if (!hw_data)
		return -ENOMEM;

	hw_data->num = clk_num;

	/* avoid returning NULL for unused idx */
	while (--clk_num >= 0)
		hw_data->hws[clk_num] = ERR_PTR(-EINVAL);

	for (p = data; p->name; p++) {
		struct clk_hw *hw;

		dev_dbg(dev, "register %s (index=%d)\n", p->name, p->idx);
		hw = uniphier_clk_register(dev, regmap, p);
		if (WARN(IS_ERR(hw), "failed to register %s", p->name))
			continue;

		if (p->idx >= 0)
			hw_data->hws[p->idx] = hw;
	}

	return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
				      hw_data);
}

__attribute__((used)) static int uniphier_clk_remove(struct platform_device *pdev)
{
	of_clk_del_provider(pdev->dev.of_node);

	return 0;
}

