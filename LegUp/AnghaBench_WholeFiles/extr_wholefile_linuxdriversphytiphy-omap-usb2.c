#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct usb_phy_data {int flags; int /*<<< orphan*/  power_off; int /*<<< orphan*/  power_on; int /*<<< orphan*/  mask; int /*<<< orphan*/  label; } ;
struct usb_phy {int /*<<< orphan*/  type; struct usb_otg* otg; int /*<<< orphan*/  label; TYPE_1__* dev; } ;
struct usb_otg {int (* set_host ) (struct usb_otg*,struct usb_bus*) ;int (* set_peripheral ) (struct usb_otg*,struct usb_gadget*) ;int (* set_vbus ) (struct usb_otg*,int) ;int (* start_srp ) (struct usb_otg*) ;struct usb_phy* usb_phy; void* state; struct usb_gadget* gadget; struct usb_bus* host; } ;
struct usb_gadget {int dummy; } ;
struct usb_bus {int dummy; } ;
struct resource {int dummy; } ;
struct TYPE_13__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct phy_provider {int /*<<< orphan*/  type; struct usb_otg* otg; int /*<<< orphan*/  label; TYPE_1__* dev; } ;
struct phy_companion {int (* set_vbus ) (struct phy_companion*,int) ;int (* start_srp ) (struct phy_companion*) ;} ;
struct phy {int /*<<< orphan*/  type; struct usb_otg* otg; int /*<<< orphan*/  label; TYPE_1__* dev; } ;
struct omap_usb {int flags; TYPE_1__* dev; struct usb_phy phy; struct usb_phy* optclk; struct usb_phy* wkupclk; int /*<<< orphan*/  power_reg; TYPE_1__* control_dev; struct usb_phy* syscon_phy_power; struct usb_phy* phy_base; int /*<<< orphan*/  power_off; int /*<<< orphan*/  power_on; int /*<<< orphan*/  mask; struct phy_companion* comparator; } ;
struct of_device_id {scalar_t__ data; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct usb_phy*) ; 
 int OMAP_USB2_CALIBRATE_FALSE_DISCONNECT ; 
 int OMAP_USB2_HAS_SET_VBUS ; 
 int OMAP_USB2_HAS_START_SRP ; 
 void* OTG_STATE_UNDEFINED ; 
 int PTR_ERR (struct usb_phy*) ; 
 int /*<<< orphan*/  USB2PHY_ANA_CONFIG1 ; 
 int /*<<< orphan*/  USB2PHY_DISCON_BYP_LATCH ; 
 int /*<<< orphan*/  USB_PHY_TYPE_USB2 ; 
 int /*<<< orphan*/  clk_disable (struct usb_phy*) ; 
 int clk_enable (struct usb_phy*) ; 
 int /*<<< orphan*/  clk_prepare (struct usb_phy*) ; 
 int /*<<< orphan*/  clk_unprepare (struct usb_phy*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 void* devm_clk_get (TYPE_1__*,char*) ; 
 struct usb_phy* devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 void* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct usb_phy* devm_of_phy_provider_register (TYPE_1__*,int /*<<< orphan*/ ) ; 
 struct usb_phy* devm_phy_create (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct platform_device* of_find_device_by_node (struct device_node*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 scalar_t__ of_property_read_u32_index (struct device_node*,char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  omap_control_phy_power (TYPE_1__*,int) ; 
 int /*<<< orphan*/  omap_usb2_id_table ; 
 int /*<<< orphan*/  omap_usb_readl (struct usb_phy*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_usb_writel (struct usb_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ops ; 
 struct omap_usb* phy_get_drvdata (struct usb_phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct usb_phy*,struct omap_usb*) ; 
 struct omap_usb* phy_to_omapusb (struct usb_phy*) ; 
 struct omap_usb* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct omap_usb*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_1__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_1__*) ; 
 int regmap_update_bits (struct usb_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (struct phy_companion*,int) ; 
 int stub2 (struct phy_companion*) ; 
 struct usb_phy* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 
 int /*<<< orphan*/  usb_add_phy_dev (struct usb_phy*) ; 
 struct usb_phy* usb_get_phy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_remove_phy (struct usb_phy*) ; 

int omap_usb2_set_comparator(struct phy_companion *comparator)
{
	struct omap_usb	*phy;
	struct usb_phy	*x = usb_get_phy(USB_PHY_TYPE_USB2);

	if (IS_ERR(x))
		return -ENODEV;

	phy = phy_to_omapusb(x);
	phy->comparator = comparator;
	return 0;
}

__attribute__((used)) static int omap_usb_set_vbus(struct usb_otg *otg, bool enabled)
{
	struct omap_usb *phy = phy_to_omapusb(otg->usb_phy);

	if (!phy->comparator)
		return -ENODEV;

	return phy->comparator->set_vbus(phy->comparator, enabled);
}

__attribute__((used)) static int omap_usb_start_srp(struct usb_otg *otg)
{
	struct omap_usb *phy = phy_to_omapusb(otg->usb_phy);

	if (!phy->comparator)
		return -ENODEV;

	return phy->comparator->start_srp(phy->comparator);
}

__attribute__((used)) static int omap_usb_set_host(struct usb_otg *otg, struct usb_bus *host)
{
	otg->host = host;
	if (!host)
		otg->state = OTG_STATE_UNDEFINED;

	return 0;
}

__attribute__((used)) static int omap_usb_set_peripheral(struct usb_otg *otg,
		struct usb_gadget *gadget)
{
	otg->gadget = gadget;
	if (!gadget)
		otg->state = OTG_STATE_UNDEFINED;

	return 0;
}

__attribute__((used)) static int omap_usb_phy_power(struct omap_usb *phy, int on)
{
	u32 val;
	int ret;

	if (!phy->syscon_phy_power) {
		omap_control_phy_power(phy->control_dev, on);
		return 0;
	}

	if (on)
		val = phy->power_on;
	else
		val = phy->power_off;

	ret = regmap_update_bits(phy->syscon_phy_power, phy->power_reg,
				 phy->mask, val);
	return ret;
}

__attribute__((used)) static int omap_usb_power_off(struct phy *x)
{
	struct omap_usb *phy = phy_get_drvdata(x);

	return omap_usb_phy_power(phy, false);
}

__attribute__((used)) static int omap_usb_power_on(struct phy *x)
{
	struct omap_usb *phy = phy_get_drvdata(x);

	return omap_usb_phy_power(phy, true);
}

__attribute__((used)) static int omap_usb2_disable_clocks(struct omap_usb *phy)
{
	clk_disable(phy->wkupclk);
	if (!IS_ERR(phy->optclk))
		clk_disable(phy->optclk);

	return 0;
}

__attribute__((used)) static int omap_usb2_enable_clocks(struct omap_usb *phy)
{
	int ret;

	ret = clk_enable(phy->wkupclk);
	if (ret < 0) {
		dev_err(phy->dev, "Failed to enable wkupclk %d\n", ret);
		goto err0;
	}

	if (!IS_ERR(phy->optclk)) {
		ret = clk_enable(phy->optclk);
		if (ret < 0) {
			dev_err(phy->dev, "Failed to enable optclk %d\n", ret);
			goto err1;
		}
	}

	return 0;

err1:
	clk_disable(phy->wkupclk);

err0:
	return ret;
}

__attribute__((used)) static int omap_usb_init(struct phy *x)
{
	struct omap_usb *phy = phy_get_drvdata(x);
	u32 val;

	omap_usb2_enable_clocks(phy);

	if (phy->flags & OMAP_USB2_CALIBRATE_FALSE_DISCONNECT) {
		/*
		 *
		 * Reduce the sensitivity of internal PHY by enabling the
		 * DISCON_BYP_LATCH of the USB2PHY_ANA_CONFIG1 register. This
		 * resolves issues with certain devices which can otherwise
		 * be prone to false disconnects.
		 *
		 */
		val = omap_usb_readl(phy->phy_base, USB2PHY_ANA_CONFIG1);
		val |= USB2PHY_DISCON_BYP_LATCH;
		omap_usb_writel(phy->phy_base, USB2PHY_ANA_CONFIG1, val);
	}

	return 0;
}

__attribute__((used)) static int omap_usb_exit(struct phy *x)
{
	struct omap_usb *phy = phy_get_drvdata(x);

	return omap_usb2_disable_clocks(phy);
}

__attribute__((used)) static int omap_usb2_probe(struct platform_device *pdev)
{
	struct omap_usb	*phy;
	struct phy *generic_phy;
	struct resource *res;
	struct phy_provider *phy_provider;
	struct usb_otg *otg;
	struct device_node *node = pdev->dev.of_node;
	struct device_node *control_node;
	struct platform_device *control_pdev;
	const struct of_device_id *of_id;
	struct usb_phy_data *phy_data;

	of_id = of_match_device(omap_usb2_id_table, &pdev->dev);

	if (!of_id)
		return -EINVAL;

	phy_data = (struct usb_phy_data *)of_id->data;

	phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
	if (!otg)
		return -ENOMEM;

	phy->dev		= &pdev->dev;

	phy->phy.dev		= phy->dev;
	phy->phy.label		= phy_data->label;
	phy->phy.otg		= otg;
	phy->phy.type		= USB_PHY_TYPE_USB2;
	phy->mask		= phy_data->mask;
	phy->power_on		= phy_data->power_on;
	phy->power_off		= phy_data->power_off;

	if (phy_data->flags & OMAP_USB2_CALIBRATE_FALSE_DISCONNECT) {
		res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
		phy->phy_base = devm_ioremap_resource(&pdev->dev, res);
		if (IS_ERR(phy->phy_base))
			return PTR_ERR(phy->phy_base);
		phy->flags |= OMAP_USB2_CALIBRATE_FALSE_DISCONNECT;
	}

	phy->syscon_phy_power = syscon_regmap_lookup_by_phandle(node,
							"syscon-phy-power");
	if (IS_ERR(phy->syscon_phy_power)) {
		dev_dbg(&pdev->dev,
			"can't get syscon-phy-power, using control device\n");
		phy->syscon_phy_power = NULL;

		control_node = of_parse_phandle(node, "ctrl-module", 0);
		if (!control_node) {
			dev_err(&pdev->dev,
				"Failed to get control device phandle\n");
			return -EINVAL;
		}

		control_pdev = of_find_device_by_node(control_node);
		if (!control_pdev) {
			dev_err(&pdev->dev, "Failed to get control device\n");
			return -EINVAL;
		}
		phy->control_dev = &control_pdev->dev;
	} else {
		if (of_property_read_u32_index(node,
					       "syscon-phy-power", 1,
					       &phy->power_reg)) {
			dev_err(&pdev->dev,
				"couldn't get power reg. offset\n");
			return -EINVAL;
		}
	}

	otg->set_host		= omap_usb_set_host;
	otg->set_peripheral	= omap_usb_set_peripheral;
	if (phy_data->flags & OMAP_USB2_HAS_SET_VBUS)
		otg->set_vbus		= omap_usb_set_vbus;
	if (phy_data->flags & OMAP_USB2_HAS_START_SRP)
		otg->start_srp		= omap_usb_start_srp;
	otg->usb_phy		= &phy->phy;

	platform_set_drvdata(pdev, phy);
	pm_runtime_enable(phy->dev);

	generic_phy = devm_phy_create(phy->dev, NULL, &ops);
	if (IS_ERR(generic_phy)) {
		pm_runtime_disable(phy->dev);
		return PTR_ERR(generic_phy);
	}

	phy_set_drvdata(generic_phy, phy);
	omap_usb_power_off(generic_phy);

	phy_provider = devm_of_phy_provider_register(phy->dev,
			of_phy_simple_xlate);
	if (IS_ERR(phy_provider)) {
		pm_runtime_disable(phy->dev);
		return PTR_ERR(phy_provider);
	}

	phy->wkupclk = devm_clk_get(phy->dev, "wkupclk");
	if (IS_ERR(phy->wkupclk)) {
		dev_warn(&pdev->dev, "unable to get wkupclk, trying old name\n");
		phy->wkupclk = devm_clk_get(phy->dev, "usb_phy_cm_clk32k");
		if (IS_ERR(phy->wkupclk)) {
			dev_err(&pdev->dev, "unable to get usb_phy_cm_clk32k\n");
			pm_runtime_disable(phy->dev);
			return PTR_ERR(phy->wkupclk);
		} else {
			dev_warn(&pdev->dev,
				 "found usb_phy_cm_clk32k, please fix DTS\n");
		}
	}
	clk_prepare(phy->wkupclk);

	phy->optclk = devm_clk_get(phy->dev, "refclk");
	if (IS_ERR(phy->optclk)) {
		dev_dbg(&pdev->dev, "unable to get refclk, trying old name\n");
		phy->optclk = devm_clk_get(phy->dev, "usb_otg_ss_refclk960m");
		if (IS_ERR(phy->optclk)) {
			dev_dbg(&pdev->dev,
				"unable to get usb_otg_ss_refclk960m\n");
		} else {
			dev_warn(&pdev->dev,
				 "found usb_otg_ss_refclk960m, please fix DTS\n");
		}
	}

	if (!IS_ERR(phy->optclk))
		clk_prepare(phy->optclk);

	usb_add_phy_dev(&phy->phy);

	return 0;
}

__attribute__((used)) static int omap_usb2_remove(struct platform_device *pdev)
{
	struct omap_usb	*phy = platform_get_drvdata(pdev);

	clk_unprepare(phy->wkupclk);
	if (!IS_ERR(phy->optclk))
		clk_unprepare(phy->optclk);
	usb_remove_phy(&phy->phy);
	pm_runtime_disable(phy->dev);

	return 0;
}

