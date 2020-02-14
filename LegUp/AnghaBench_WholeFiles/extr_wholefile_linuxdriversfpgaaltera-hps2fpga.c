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
typedef  int u32 ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct fpga_bridge {struct altera_hps2fpga_data* priv; } ;
struct altera_hps2fpga_data {int remap_mask; int /*<<< orphan*/  clk; int /*<<< orphan*/  name; int /*<<< orphan*/  l3reg; int /*<<< orphan*/  bridge_reset; } ;

/* Variables and functions */
 int ALT_L3_REMAP_MPUZERO_MSK ; 
 int /*<<< orphan*/  ALT_L3_REMAP_OFST ; 
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  altera_fpga_of_match ; 
 int /*<<< orphan*/  altera_hps2fpga_br_ops ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 struct fpga_bridge* fpga_bridge_create (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct altera_hps2fpga_data*) ; 
 int /*<<< orphan*/  fpga_bridge_free (struct fpga_bridge*) ; 
 int fpga_bridge_register (struct fpga_bridge*) ; 
 int /*<<< orphan*/  fpga_bridge_unregister (struct fpga_bridge*) ; 
 int /*<<< orphan*/  l3_remap_lock ; 
 int l3_remap_shadow ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int /*<<< orphan*/  of_reset_control_get_exclusive_by_index (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct fpga_bridge* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fpga_bridge*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int reset_control_assert (int /*<<< orphan*/ ) ; 
 int reset_control_deassert (int /*<<< orphan*/ ) ; 
 int reset_control_status (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_compatible (char*) ; 

__attribute__((used)) static int alt_hps2fpga_enable_show(struct fpga_bridge *bridge)
{
	struct altera_hps2fpga_data *priv = bridge->priv;

	return reset_control_status(priv->bridge_reset);
}

__attribute__((used)) static int _alt_hps2fpga_enable_set(struct altera_hps2fpga_data *priv,
				    bool enable)
{
	unsigned long flags;
	int ret;

	/* bring bridge out of reset */
	if (enable)
		ret = reset_control_deassert(priv->bridge_reset);
	else
		ret = reset_control_assert(priv->bridge_reset);
	if (ret)
		return ret;

	/* Allow bridge to be visible to L3 masters or not */
	if (priv->remap_mask) {
		spin_lock_irqsave(&l3_remap_lock, flags);
		l3_remap_shadow |= ALT_L3_REMAP_MPUZERO_MSK;

		if (enable)
			l3_remap_shadow |= priv->remap_mask;
		else
			l3_remap_shadow &= ~priv->remap_mask;

		ret = regmap_write(priv->l3reg, ALT_L3_REMAP_OFST,
				   l3_remap_shadow);
		spin_unlock_irqrestore(&l3_remap_lock, flags);
	}

	return ret;
}

__attribute__((used)) static int alt_hps2fpga_enable_set(struct fpga_bridge *bridge, bool enable)
{
	return _alt_hps2fpga_enable_set(bridge->priv, enable);
}

__attribute__((used)) static int alt_fpga_bridge_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct altera_hps2fpga_data *priv;
	const struct of_device_id *of_id;
	struct fpga_bridge *br;
	u32 enable;
	int ret;

	of_id = of_match_device(altera_fpga_of_match, dev);
	if (!of_id) {
		dev_err(dev, "failed to match device\n");
		return -ENODEV;
	}

	priv = (struct altera_hps2fpga_data *)of_id->data;

	priv->bridge_reset = of_reset_control_get_exclusive_by_index(dev->of_node,
								     0);
	if (IS_ERR(priv->bridge_reset)) {
		dev_err(dev, "Could not get %s reset control\n", priv->name);
		return PTR_ERR(priv->bridge_reset);
	}

	if (priv->remap_mask) {
		priv->l3reg = syscon_regmap_lookup_by_compatible("altr,l3regs");
		if (IS_ERR(priv->l3reg)) {
			dev_err(dev, "regmap for altr,l3regs lookup failed\n");
			return PTR_ERR(priv->l3reg);
		}
	}

	priv->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(priv->clk)) {
		dev_err(dev, "no clock specified\n");
		return PTR_ERR(priv->clk);
	}

	ret = clk_prepare_enable(priv->clk);
	if (ret) {
		dev_err(dev, "could not enable clock\n");
		return -EBUSY;
	}

	if (!of_property_read_u32(dev->of_node, "bridge-enable", &enable)) {
		if (enable > 1) {
			dev_warn(dev, "invalid bridge-enable %u > 1\n", enable);
		} else {
			dev_info(dev, "%s bridge\n",
				 (enable ? "enabling" : "disabling"));

			ret = _alt_hps2fpga_enable_set(priv, enable);
			if (ret)
				goto err;
		}
	}

	br = fpga_bridge_create(dev, priv->name, &altera_hps2fpga_br_ops, priv);
	if (!br) {
		ret = -ENOMEM;
		goto err;
	}

	platform_set_drvdata(pdev, br);

	ret = fpga_bridge_register(br);
	if (ret)
		goto err_free;

	return 0;

err_free:
	fpga_bridge_free(br);
err:
	clk_disable_unprepare(priv->clk);

	return ret;
}

__attribute__((used)) static int alt_fpga_bridge_remove(struct platform_device *pdev)
{
	struct fpga_bridge *bridge = platform_get_drvdata(pdev);
	struct altera_hps2fpga_data *priv = bridge->priv;

	fpga_bridge_unregister(bridge);

	clk_disable_unprepare(priv->clk);

	return 0;
}

