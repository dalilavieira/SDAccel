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
struct video_phy_desc {struct exynos_mipi_phy_desc* data; } ;
struct regmap {scalar_t__ power_count; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
struct phy {scalar_t__ power_count; } ;
struct of_phandle_args {size_t* args; } ;
struct mipi_phy_device_desc {unsigned int num_regmaps; size_t num_phys; int /*<<< orphan*/ * phys; int /*<<< orphan*/ * regmap_names; } ;
struct exynos_mipi_video_phy {size_t num_phys; TYPE_1__* phys; int /*<<< orphan*/  slock; struct regmap** regmaps; } ;
struct exynos_mipi_phy_desc {size_t enable_map; size_t resetn_map; size_t coupled_phy_id; int /*<<< orphan*/  enable_val; int /*<<< orphan*/  enable_reg; int /*<<< orphan*/  resetn_val; int /*<<< orphan*/  resetn_reg; } ;
struct device_node {int dummy; } ;
struct TYPE_2__ {unsigned int index; int /*<<< orphan*/ * data; struct regmap* phy; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 struct regmap* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,unsigned int) ; 
 struct exynos_mipi_video_phy* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct exynos_mipi_video_phy*) ; 
 struct exynos_mipi_video_phy* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,struct regmap* (*) (struct device*,struct of_phandle_args*)) ; 
 struct regmap* devm_phy_create (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exynos_mipi_video_phy_ops ; 
 struct mipi_phy_device_desc* of_device_get_match_data (struct device*) ; 
 struct video_phy_desc* phy_get_drvdata (struct regmap*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct regmap*,TYPE_1__*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 struct regmap* syscon_regmap_lookup_by_phandle (struct device_node*,int /*<<< orphan*/ ) ; 
 struct exynos_mipi_video_phy* to_mipi_video_phy (struct video_phy_desc*) ; 

__attribute__((used)) static int __set_phy_state(const struct exynos_mipi_phy_desc *data,
			   struct exynos_mipi_video_phy *state, unsigned int on)
{
	struct regmap *enable_map = state->regmaps[data->enable_map];
	struct regmap *resetn_map = state->regmaps[data->resetn_map];

	spin_lock(&state->slock);

	/* disable in PMU sysreg */
	if (!on && data->coupled_phy_id >= 0 &&
	    state->phys[data->coupled_phy_id].phy->power_count == 0)
		regmap_update_bits(enable_map, data->enable_reg,
				   data->enable_val, 0);
	/* PHY reset */
	if (on)
		regmap_update_bits(resetn_map, data->resetn_reg,
				   data->resetn_val, data->resetn_val);
	else
		regmap_update_bits(resetn_map, data->resetn_reg,
				   data->resetn_val, 0);
	/* enable in PMU sysreg */
	if (on)
		regmap_update_bits(enable_map, data->enable_reg,
				   data->enable_val, data->enable_val);

	spin_unlock(&state->slock);

	return 0;
}

__attribute__((used)) static int exynos_mipi_video_phy_power_on(struct phy *phy)
{
	struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
	struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);

	return __set_phy_state(phy_desc->data, state, 1);
}

__attribute__((used)) static int exynos_mipi_video_phy_power_off(struct phy *phy)
{
	struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
	struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);

	return __set_phy_state(phy_desc->data, state, 0);
}

__attribute__((used)) static struct phy *exynos_mipi_video_phy_xlate(struct device *dev,
					struct of_phandle_args *args)
{
	struct exynos_mipi_video_phy *state = dev_get_drvdata(dev);

	if (WARN_ON(args->args[0] >= state->num_phys))
		return ERR_PTR(-ENODEV);

	return state->phys[args->args[0]].phy;
}

__attribute__((used)) static int exynos_mipi_video_phy_probe(struct platform_device *pdev)
{
	const struct mipi_phy_device_desc *phy_dev;
	struct exynos_mipi_video_phy *state;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct phy_provider *phy_provider;
	unsigned int i;

	phy_dev = of_device_get_match_data(dev);
	if (!phy_dev)
		return -ENODEV;

	state = devm_kzalloc(dev, sizeof(*state), GFP_KERNEL);
	if (!state)
		return -ENOMEM;

	for (i = 0; i < phy_dev->num_regmaps; i++) {
		state->regmaps[i] = syscon_regmap_lookup_by_phandle(np,
						phy_dev->regmap_names[i]);
		if (IS_ERR(state->regmaps[i]))
			return PTR_ERR(state->regmaps[i]);
	}
	state->num_phys = phy_dev->num_phys;
	spin_lock_init(&state->slock);

	dev_set_drvdata(dev, state);

	for (i = 0; i < state->num_phys; i++) {
		struct phy *phy = devm_phy_create(dev, NULL,
						  &exynos_mipi_video_phy_ops);
		if (IS_ERR(phy)) {
			dev_err(dev, "failed to create PHY %d\n", i);
			return PTR_ERR(phy);
		}

		state->phys[i].phy = phy;
		state->phys[i].index = i;
		state->phys[i].data = &phy_dev->phys[i];
		phy_set_drvdata(phy, &state->phys[i]);
	}

	phy_provider = devm_of_phy_provider_register(dev,
					exynos_mipi_video_phy_xlate);

	return PTR_ERR_OR_ZERO(phy_provider);
}

