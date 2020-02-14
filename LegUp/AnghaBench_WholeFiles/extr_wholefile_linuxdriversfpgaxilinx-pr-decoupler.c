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
typedef  scalar_t__ u32 ;
struct xlnx_pr_decoupler_data {scalar_t__ clk; scalar_t__ io_base; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct fpga_bridge {struct xlnx_pr_decoupler_data* priv; } ;

/* Variables and functions */
 scalar_t__ CTRL_CMD_COUPLE ; 
 scalar_t__ CTRL_CMD_DECOUPLE ; 
 scalar_t__ CTRL_OFFSET ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  clk_unprepare (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct xlnx_pr_decoupler_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct fpga_bridge* fpga_bridge_create (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct xlnx_pr_decoupler_data*) ; 
 int fpga_bridge_register (struct fpga_bridge*) ; 
 int /*<<< orphan*/  fpga_bridge_unregister (struct fpga_bridge*) ; 
 struct fpga_bridge* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fpga_bridge*) ; 
 scalar_t__ readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  xlnx_pr_decoupler_br_ops ; 

__attribute__((used)) static inline void xlnx_pr_decoupler_write(struct xlnx_pr_decoupler_data *d,
					   u32 offset, u32 val)
{
	writel(val, d->io_base + offset);
}

__attribute__((used)) static inline u32 xlnx_pr_decouple_read(const struct xlnx_pr_decoupler_data *d,
					u32 offset)
{
	return readl(d->io_base + offset);
}

__attribute__((used)) static int xlnx_pr_decoupler_enable_set(struct fpga_bridge *bridge, bool enable)
{
	int err;
	struct xlnx_pr_decoupler_data *priv = bridge->priv;

	err = clk_enable(priv->clk);
	if (err)
		return err;

	if (enable)
		xlnx_pr_decoupler_write(priv, CTRL_OFFSET, CTRL_CMD_COUPLE);
	else
		xlnx_pr_decoupler_write(priv, CTRL_OFFSET, CTRL_CMD_DECOUPLE);

	clk_disable(priv->clk);

	return 0;
}

__attribute__((used)) static int xlnx_pr_decoupler_enable_show(struct fpga_bridge *bridge)
{
	const struct xlnx_pr_decoupler_data *priv = bridge->priv;
	u32 status;
	int err;

	err = clk_enable(priv->clk);
	if (err)
		return err;

	status = readl(priv->io_base);

	clk_disable(priv->clk);

	return !status;
}

__attribute__((used)) static int xlnx_pr_decoupler_probe(struct platform_device *pdev)
{
	struct xlnx_pr_decoupler_data *priv;
	struct fpga_bridge *br;
	int err;
	struct resource *res;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->io_base))
		return PTR_ERR(priv->io_base);

	priv->clk = devm_clk_get(&pdev->dev, "aclk");
	if (IS_ERR(priv->clk)) {
		dev_err(&pdev->dev, "input clock not found\n");
		return PTR_ERR(priv->clk);
	}

	err = clk_prepare_enable(priv->clk);
	if (err) {
		dev_err(&pdev->dev, "unable to enable clock\n");
		return err;
	}

	clk_disable(priv->clk);

	br = fpga_bridge_create(&pdev->dev, "Xilinx PR Decoupler",
				&xlnx_pr_decoupler_br_ops, priv);
	if (!br) {
		err = -ENOMEM;
		goto err_clk;
	}

	platform_set_drvdata(pdev, br);

	err = fpga_bridge_register(br);
	if (err) {
		dev_err(&pdev->dev, "unable to register Xilinx PR Decoupler");
		goto err_clk;
	}

	return 0;

err_clk:
	clk_unprepare(priv->clk);

	return err;
}

__attribute__((used)) static int xlnx_pr_decoupler_remove(struct platform_device *pdev)
{
	struct fpga_bridge *bridge = platform_get_drvdata(pdev);
	struct xlnx_pr_decoupler_data *p = bridge->priv;

	fpga_bridge_unregister(bridge);

	clk_unprepare(p->clk);

	return 0;
}

