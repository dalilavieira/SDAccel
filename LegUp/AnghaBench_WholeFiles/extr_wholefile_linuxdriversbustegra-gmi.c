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
struct tegra_gmi {int snor_timing0; int snor_timing1; int snor_config; struct device* dev; scalar_t__ rst; scalar_t__ clk; scalar_t__ base; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOVERFLOW ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int TEGRA_GMI_ADV_ACTIVE_HIGH ; 
 int TEGRA_GMI_ADV_WIDTH (int) ; 
 int TEGRA_GMI_BUS_WIDTH_32BIT ; 
 int TEGRA_GMI_CE_WIDTH (int) ; 
 scalar_t__ TEGRA_GMI_CONFIG ; 
 int TEGRA_GMI_CONFIG_GO ; 
 int TEGRA_GMI_CS_ACTIVE_HIGH ; 
 int TEGRA_GMI_CS_SELECT (int) ; 
 int TEGRA_GMI_HOLD_WIDTH (int) ; 
 int TEGRA_GMI_MAX_CHIP_SELECT ; 
 int TEGRA_GMI_MUXED_WIDTH (int) ; 
 int TEGRA_GMI_MUX_MODE ; 
 int TEGRA_GMI_OE_ACTIVE_HIGH ; 
 int TEGRA_GMI_OE_WIDTH (int) ; 
 int TEGRA_GMI_RDY_ACTIVE_HIGH ; 
 int TEGRA_GMI_RDY_BEFORE_DATA ; 
 scalar_t__ TEGRA_GMI_TIMING0 ; 
 scalar_t__ TEGRA_GMI_TIMING1 ; 
 int TEGRA_GMI_WAIT_WIDTH (int) ; 
 int TEGRA_GMI_WE_WIDTH (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 scalar_t__ devm_clk_get (struct device*,char*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct tegra_gmi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_reset_control_get (struct device*,char*) ; 
 int of_get_child_count (int /*<<< orphan*/ ) ; 
 struct device_node* of_get_next_available_child (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_platform_default_populate (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct device*) ; 
 int /*<<< orphan*/  of_platform_depopulate (struct device*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int of_property_read_u32_array (struct device_node*,char*,int*,int) ; 
 struct tegra_gmi* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tegra_gmi*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  reset_control_assert (scalar_t__) ; 
 int /*<<< orphan*/  reset_control_deassert (scalar_t__) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int tegra_gmi_enable(struct tegra_gmi *gmi)
{
	int err;

	err = clk_prepare_enable(gmi->clk);
	if (err < 0) {
		dev_err(gmi->dev, "failed to enable clock: %d\n", err);
		return err;
	}

	reset_control_assert(gmi->rst);
	usleep_range(2000, 4000);
	reset_control_deassert(gmi->rst);

	writel(gmi->snor_timing0, gmi->base + TEGRA_GMI_TIMING0);
	writel(gmi->snor_timing1, gmi->base + TEGRA_GMI_TIMING1);

	gmi->snor_config |= TEGRA_GMI_CONFIG_GO;
	writel(gmi->snor_config, gmi->base + TEGRA_GMI_CONFIG);

	return 0;
}

__attribute__((used)) static void tegra_gmi_disable(struct tegra_gmi *gmi)
{
	u32 config;

	/* stop GMI operation */
	config = readl(gmi->base + TEGRA_GMI_CONFIG);
	config &= ~TEGRA_GMI_CONFIG_GO;
	writel(config, gmi->base + TEGRA_GMI_CONFIG);

	reset_control_assert(gmi->rst);
	clk_disable_unprepare(gmi->clk);
}

__attribute__((used)) static int tegra_gmi_parse_dt(struct tegra_gmi *gmi)
{
	struct device_node *child;
	u32 property, ranges[4];
	int err;

	child = of_get_next_available_child(gmi->dev->of_node, NULL);
	if (!child) {
		dev_err(gmi->dev, "no child nodes found\n");
		return -ENODEV;
	}

	/*
	 * We currently only support one child device due to lack of
	 * chip-select address decoding. Which means that we only have one
	 * chip-select line from the GMI controller.
	 */
	if (of_get_child_count(gmi->dev->of_node) > 1)
		dev_warn(gmi->dev, "only one child device is supported.");

	if (of_property_read_bool(child, "nvidia,snor-data-width-32bit"))
		gmi->snor_config |= TEGRA_GMI_BUS_WIDTH_32BIT;

	if (of_property_read_bool(child, "nvidia,snor-mux-mode"))
		gmi->snor_config |= TEGRA_GMI_MUX_MODE;

	if (of_property_read_bool(child, "nvidia,snor-rdy-active-before-data"))
		gmi->snor_config |= TEGRA_GMI_RDY_BEFORE_DATA;

	if (of_property_read_bool(child, "nvidia,snor-rdy-active-high"))
		gmi->snor_config |= TEGRA_GMI_RDY_ACTIVE_HIGH;

	if (of_property_read_bool(child, "nvidia,snor-adv-active-high"))
		gmi->snor_config |= TEGRA_GMI_ADV_ACTIVE_HIGH;

	if (of_property_read_bool(child, "nvidia,snor-oe-active-high"))
		gmi->snor_config |= TEGRA_GMI_OE_ACTIVE_HIGH;

	if (of_property_read_bool(child, "nvidia,snor-cs-active-high"))
		gmi->snor_config |= TEGRA_GMI_CS_ACTIVE_HIGH;

	/* Decode the CS# */
	err = of_property_read_u32_array(child, "ranges", ranges, 4);
	if (err < 0) {
		/* Invalid binding */
		if (err == -EOVERFLOW) {
			dev_err(gmi->dev,
				"failed to decode CS: invalid ranges length\n");
			goto error_cs;
		}

		/*
		 * If we reach here it means that the child node has an empty
		 * ranges or it does not exist at all. Attempt to decode the
		 * CS# from the reg property instead.
		 */
		err = of_property_read_u32(child, "reg", &property);
		if (err < 0) {
			dev_err(gmi->dev,
				"failed to decode CS: no reg property found\n");
			goto error_cs;
		}
	} else {
		property = ranges[1];
	}

	/* Valid chip selects are CS0-CS7 */
	if (property >= TEGRA_GMI_MAX_CHIP_SELECT) {
		dev_err(gmi->dev, "invalid chip select: %d", property);
		err = -EINVAL;
		goto error_cs;
	}

	gmi->snor_config |= TEGRA_GMI_CS_SELECT(property);

	/* The default values that are provided below are reset values */
	if (!of_property_read_u32(child, "nvidia,snor-muxed-width", &property))
		gmi->snor_timing0 |= TEGRA_GMI_MUXED_WIDTH(property);
	else
		gmi->snor_timing0 |= TEGRA_GMI_MUXED_WIDTH(1);

	if (!of_property_read_u32(child, "nvidia,snor-hold-width", &property))
		gmi->snor_timing0 |= TEGRA_GMI_HOLD_WIDTH(property);
	else
		gmi->snor_timing0 |= TEGRA_GMI_HOLD_WIDTH(1);

	if (!of_property_read_u32(child, "nvidia,snor-adv-width", &property))
		gmi->snor_timing0 |= TEGRA_GMI_ADV_WIDTH(property);
	else
		gmi->snor_timing0 |= TEGRA_GMI_ADV_WIDTH(1);

	if (!of_property_read_u32(child, "nvidia,snor-ce-width", &property))
		gmi->snor_timing0 |= TEGRA_GMI_CE_WIDTH(property);
	else
		gmi->snor_timing0 |= TEGRA_GMI_CE_WIDTH(4);

	if (!of_property_read_u32(child, "nvidia,snor-we-width", &property))
		gmi->snor_timing1 |= TEGRA_GMI_WE_WIDTH(property);
	else
		gmi->snor_timing1 |= TEGRA_GMI_WE_WIDTH(1);

	if (!of_property_read_u32(child, "nvidia,snor-oe-width", &property))
		gmi->snor_timing1 |= TEGRA_GMI_OE_WIDTH(property);
	else
		gmi->snor_timing1 |= TEGRA_GMI_OE_WIDTH(1);

	if (!of_property_read_u32(child, "nvidia,snor-wait-width", &property))
		gmi->snor_timing1 |= TEGRA_GMI_WAIT_WIDTH(property);
	else
		gmi->snor_timing1 |= TEGRA_GMI_WAIT_WIDTH(3);

error_cs:
	of_node_put(child);
	return err;
}

__attribute__((used)) static int tegra_gmi_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct tegra_gmi *gmi;
	struct resource *res;
	int err;

	gmi = devm_kzalloc(dev, sizeof(*gmi), GFP_KERNEL);
	if (!gmi)
		return -ENOMEM;

	gmi->dev = dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	gmi->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(gmi->base))
		return PTR_ERR(gmi->base);

	gmi->clk = devm_clk_get(dev, "gmi");
	if (IS_ERR(gmi->clk)) {
		dev_err(dev, "can not get clock\n");
		return PTR_ERR(gmi->clk);
	}

	gmi->rst = devm_reset_control_get(dev, "gmi");
	if (IS_ERR(gmi->rst)) {
		dev_err(dev, "can not get reset\n");
		return PTR_ERR(gmi->rst);
	}

	err = tegra_gmi_parse_dt(gmi);
	if (err)
		return err;

	err = tegra_gmi_enable(gmi);
	if (err < 0)
		return err;

	err = of_platform_default_populate(dev->of_node, NULL, dev);
	if (err < 0) {
		dev_err(dev, "fail to create devices.\n");
		tegra_gmi_disable(gmi);
		return err;
	}

	platform_set_drvdata(pdev, gmi);

	return 0;
}

__attribute__((used)) static int tegra_gmi_remove(struct platform_device *pdev)
{
	struct tegra_gmi *gmi = platform_get_drvdata(pdev);

	of_platform_depopulate(gmi->dev);
	tegra_gmi_disable(gmi);

	return 0;
}

