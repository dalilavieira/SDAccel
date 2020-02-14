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
struct tegra124_cpufreq_priv {struct clk* vdd_cpu_reg; struct clk* cpu_clk; struct clk* dfll_clk; struct clk* pllx_clk; struct clk* pllp_clk; struct clk* cpufreq_dt_pdev; } ;
struct platform_device_info {char* name; int /*<<< orphan*/ * parent; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct clk*) ; 
 struct clk* clk_get_parent (struct clk*) ; 
 int /*<<< orphan*/  clk_get_rate (struct clk*) ; 
 int clk_prepare_enable (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 int /*<<< orphan*/  clk_set_parent (struct clk*,struct clk*) ; 
 int clk_set_rate (struct clk*,int /*<<< orphan*/ ) ; 
 struct tegra124_cpufreq_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct device* get_cpu_device (int /*<<< orphan*/ ) ; 
 void* of_clk_get_by_name (struct device_node*,char*) ; 
 struct device_node* of_cpu_device_node_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct clk* platform_device_register_full (struct platform_device_info*) ; 
 int /*<<< orphan*/  platform_device_unregister (struct clk*) ; 
 struct tegra124_cpufreq_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tegra124_cpufreq_priv*) ; 
 struct clk* regulator_get (struct device*,char*) ; 
 int /*<<< orphan*/  regulator_put (struct clk*) ; 
 int /*<<< orphan*/  regulator_sync_voltage (struct clk*) ; 

__attribute__((used)) static int tegra124_cpu_switch_to_dfll(struct tegra124_cpufreq_priv *priv)
{
	struct clk *orig_parent;
	int ret;

	ret = clk_set_rate(priv->dfll_clk, clk_get_rate(priv->cpu_clk));
	if (ret)
		return ret;

	orig_parent = clk_get_parent(priv->cpu_clk);
	clk_set_parent(priv->cpu_clk, priv->pllp_clk);

	ret = clk_prepare_enable(priv->dfll_clk);
	if (ret)
		goto out;

	clk_set_parent(priv->cpu_clk, priv->dfll_clk);

	return 0;

out:
	clk_set_parent(priv->cpu_clk, orig_parent);

	return ret;
}

__attribute__((used)) static void tegra124_cpu_switch_to_pllx(struct tegra124_cpufreq_priv *priv)
{
	clk_set_parent(priv->cpu_clk, priv->pllp_clk);
	clk_disable_unprepare(priv->dfll_clk);
	regulator_sync_voltage(priv->vdd_cpu_reg);
	clk_set_parent(priv->cpu_clk, priv->pllx_clk);
}

__attribute__((used)) static int tegra124_cpufreq_probe(struct platform_device *pdev)
{
	struct tegra124_cpufreq_priv *priv;
	struct device_node *np;
	struct device *cpu_dev;
	struct platform_device_info cpufreq_dt_devinfo = {};
	int ret;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	cpu_dev = get_cpu_device(0);
	if (!cpu_dev)
		return -ENODEV;

	np = of_cpu_device_node_get(0);
	if (!np)
		return -ENODEV;

	priv->vdd_cpu_reg = regulator_get(cpu_dev, "vdd-cpu");
	if (IS_ERR(priv->vdd_cpu_reg)) {
		ret = PTR_ERR(priv->vdd_cpu_reg);
		goto out_put_np;
	}

	priv->cpu_clk = of_clk_get_by_name(np, "cpu_g");
	if (IS_ERR(priv->cpu_clk)) {
		ret = PTR_ERR(priv->cpu_clk);
		goto out_put_vdd_cpu_reg;
	}

	priv->dfll_clk = of_clk_get_by_name(np, "dfll");
	if (IS_ERR(priv->dfll_clk)) {
		ret = PTR_ERR(priv->dfll_clk);
		goto out_put_cpu_clk;
	}

	priv->pllx_clk = of_clk_get_by_name(np, "pll_x");
	if (IS_ERR(priv->pllx_clk)) {
		ret = PTR_ERR(priv->pllx_clk);
		goto out_put_dfll_clk;
	}

	priv->pllp_clk = of_clk_get_by_name(np, "pll_p");
	if (IS_ERR(priv->pllp_clk)) {
		ret = PTR_ERR(priv->pllp_clk);
		goto out_put_pllx_clk;
	}

	ret = tegra124_cpu_switch_to_dfll(priv);
	if (ret)
		goto out_put_pllp_clk;

	cpufreq_dt_devinfo.name = "cpufreq-dt";
	cpufreq_dt_devinfo.parent = &pdev->dev;

	priv->cpufreq_dt_pdev =
		platform_device_register_full(&cpufreq_dt_devinfo);
	if (IS_ERR(priv->cpufreq_dt_pdev)) {
		ret = PTR_ERR(priv->cpufreq_dt_pdev);
		goto out_switch_to_pllx;
	}

	platform_set_drvdata(pdev, priv);

	of_node_put(np);

	return 0;

out_switch_to_pllx:
	tegra124_cpu_switch_to_pllx(priv);
out_put_pllp_clk:
	clk_put(priv->pllp_clk);
out_put_pllx_clk:
	clk_put(priv->pllx_clk);
out_put_dfll_clk:
	clk_put(priv->dfll_clk);
out_put_cpu_clk:
	clk_put(priv->cpu_clk);
out_put_vdd_cpu_reg:
	regulator_put(priv->vdd_cpu_reg);
out_put_np:
	of_node_put(np);

	return ret;
}

__attribute__((used)) static int tegra124_cpufreq_remove(struct platform_device *pdev)
{
	struct tegra124_cpufreq_priv *priv = platform_get_drvdata(pdev);

	platform_device_unregister(priv->cpufreq_dt_pdev);
	tegra124_cpu_switch_to_pllx(priv);

	clk_put(priv->pllp_clk);
	clk_put(priv->pllx_clk);
	clk_put(priv->dfll_clk);
	clk_put(priv->cpu_clk);
	regulator_put(priv->vdd_cpu_reg);

	return 0;
}

