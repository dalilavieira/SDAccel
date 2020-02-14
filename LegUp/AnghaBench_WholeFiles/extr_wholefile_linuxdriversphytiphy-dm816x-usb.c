#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct usb_phy_data {int dummy; } ;
struct usb_otg {int (* set_host ) (struct usb_otg*,struct usb_bus*) ;int (* set_peripheral ) (struct usb_otg*,struct usb_gadget*) ;TYPE_1__* usb_phy; void* state; struct usb_gadget* gadget; struct usb_bus* host; } ;
struct usb_gadget {int dummy; } ;
struct usb_bus {int dummy; } ;
struct resource {int start; } ;
struct TYPE_13__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct phy_provider {int dummy; } ;
typedef  struct phy_provider phy ;
struct of_device_id {struct usb_phy_data* data; } ;
struct TYPE_12__ {char* label; int /*<<< orphan*/  type; struct usb_otg* otg; TYPE_3__* dev; } ;
struct dm816x_usb_phy {int usb_ctrl; int usbphy_ctrl; int instance; struct phy_provider* refclk; TYPE_3__* dev; TYPE_1__ phy; struct phy_provider* syscon; } ;

/* Variables and functions */
 unsigned int DM816X_USBPHY_CTRL_TXPREEMTUNE ; 
 unsigned int DM816X_USBPHY_CTRL_TXRISETUNE ; 
 unsigned int DM816X_USBPHY_CTRL_TXVREFTUNE ; 
 int DM816X_USB_CTRL_PHYCLKSRC ; 
 int DM816X_USB_CTRL_PHYSLEEP0 ; 
 int DM816X_USB_CTRL_PHYSLEEP1 ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct phy_provider*) ; 
 void* OTG_STATE_UNDEFINED ; 
 int PTR_ERR (struct phy_provider*) ; 
 int /*<<< orphan*/  USB_PHY_TYPE_USB2 ; 
 int clk_get_rate (struct phy_provider*) ; 
 int clk_prepare (struct phy_provider*) ; 
 int /*<<< orphan*/  clk_unprepare (struct phy_provider*) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*) ; 
 struct phy_provider* devm_clk_get (TYPE_3__*,char*) ; 
 void* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (TYPE_3__*,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_phy_create (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dm816x_usb_phy_id_table ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 int /*<<< orphan*/  ops ; 
 struct dm816x_usb_phy* phy_get_drvdata (struct phy_provider*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy_provider*,struct dm816x_usb_phy*) ; 
 struct dm816x_usb_phy* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct dm816x_usb_phy*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_3__*) ; 
 int /*<<< orphan*/  regmap_read (struct phy_provider*,int,unsigned int*) ; 
 int regmap_update_bits (struct phy_provider*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_write (struct phy_provider*,int,unsigned int) ; 
 struct phy_provider* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  usb_add_phy_dev (TYPE_1__*) ; 
 int /*<<< orphan*/  usb_remove_phy (TYPE_1__*) ; 

__attribute__((used)) static int dm816x_usb_phy_set_host(struct usb_otg *otg, struct usb_bus *host)
{
	otg->host = host;
	if (!host)
		otg->state = OTG_STATE_UNDEFINED;

	return 0;
}

__attribute__((used)) static int dm816x_usb_phy_set_peripheral(struct usb_otg *otg,
					 struct usb_gadget *gadget)
{
	otg->gadget = gadget;
	if (!gadget)
		otg->state = OTG_STATE_UNDEFINED;

	return 0;
}

__attribute__((used)) static int dm816x_usb_phy_init(struct phy *x)
{
	struct dm816x_usb_phy *phy = phy_get_drvdata(x);
	unsigned int val;
	int error;

	if (clk_get_rate(phy->refclk) != 24000000)
		dev_warn(phy->dev, "nonstandard phy refclk\n");

	/* Set PLL ref clock and put phys to sleep */
	error = regmap_update_bits(phy->syscon, phy->usb_ctrl,
				   DM816X_USB_CTRL_PHYCLKSRC |
				   DM816X_USB_CTRL_PHYSLEEP1 |
				   DM816X_USB_CTRL_PHYSLEEP0,
				   0);
	regmap_read(phy->syscon, phy->usb_ctrl, &val);
	if ((val & 3) != 0)
		dev_info(phy->dev,
			 "Working dm816x USB_CTRL! (0x%08x)\n",
			 val);

	/*
	 * TI kernel sets these values for "symmetrical eye diagram and
	 * better signal quality" so let's assume somebody checked the
	 * values with a scope and set them here too.
	 */
	regmap_read(phy->syscon, phy->usbphy_ctrl, &val);
	val |= DM816X_USBPHY_CTRL_TXRISETUNE |
		DM816X_USBPHY_CTRL_TXVREFTUNE |
		DM816X_USBPHY_CTRL_TXPREEMTUNE;
	regmap_write(phy->syscon, phy->usbphy_ctrl, val);

	return 0;
}

__attribute__((used)) static int dm816x_usb_phy_probe(struct platform_device *pdev)
{
	struct dm816x_usb_phy *phy;
	struct resource *res;
	struct phy *generic_phy;
	struct phy_provider *phy_provider;
	struct usb_otg *otg;
	const struct of_device_id *of_id;
	const struct usb_phy_data *phy_data;
	int error;

	of_id = of_match_device(of_match_ptr(dm816x_usb_phy_id_table),
				&pdev->dev);
	if (!of_id)
		return -EINVAL;

	phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENOENT;

	phy->syscon = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
						      "syscon");
	if (IS_ERR(phy->syscon))
		return PTR_ERR(phy->syscon);

	/*
	 * According to sprs614e.pdf, the first usb_ctrl is shared and
	 * the second instance for usb_ctrl is reserved.. Also the
	 * register bits are different from earlier TRMs.
	 */
	phy->usb_ctrl = 0x20;
	phy->usbphy_ctrl = (res->start & 0xff) + 4;
	if (phy->usbphy_ctrl == 0x2c)
		phy->instance = 1;

	phy_data = of_id->data;

	otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
	if (!otg)
		return -ENOMEM;

	phy->dev = &pdev->dev;
	phy->phy.dev = phy->dev;
	phy->phy.label = "dm8168_usb_phy";
	phy->phy.otg = otg;
	phy->phy.type = USB_PHY_TYPE_USB2;
	otg->set_host = dm816x_usb_phy_set_host;
	otg->set_peripheral = dm816x_usb_phy_set_peripheral;
	otg->usb_phy = &phy->phy;

	platform_set_drvdata(pdev, phy);

	phy->refclk = devm_clk_get(phy->dev, "refclk");
	if (IS_ERR(phy->refclk))
		return PTR_ERR(phy->refclk);
	error = clk_prepare(phy->refclk);
	if (error)
		return error;

	pm_runtime_enable(phy->dev);
	generic_phy = devm_phy_create(phy->dev, NULL, &ops);
	if (IS_ERR(generic_phy))
		return PTR_ERR(generic_phy);

	phy_set_drvdata(generic_phy, phy);

	phy_provider = devm_of_phy_provider_register(phy->dev,
						     of_phy_simple_xlate);
	if (IS_ERR(phy_provider))
		return PTR_ERR(phy_provider);

	usb_add_phy_dev(&phy->phy);

	return 0;
}

__attribute__((used)) static int dm816x_usb_phy_remove(struct platform_device *pdev)
{
	struct dm816x_usb_phy *phy = platform_get_drvdata(pdev);

	usb_remove_phy(&phy->phy);
	pm_runtime_disable(phy->dev);
	clk_unprepare(phy->refclk);

	return 0;
}

