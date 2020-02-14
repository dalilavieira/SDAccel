#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct usb_phy_generic_platform_data {int type; int needs_vcc; void* gpiod_vbus; int /*<<< orphan*/  gpio_reset; scalar_t__ clk_rate; } ;
struct TYPE_3__ {int last_event; char* label; int (* set_suspend ) (struct usb_phy*,int) ;int type; int (* init ) (struct usb_phy*) ;void (* shutdown ) (struct usb_phy*) ;struct usb_otg* otg; struct device* dev; int /*<<< orphan*/  notifier; } ;
struct usb_phy_generic {int vbus_draw_enabled; unsigned int mA; int vbus; TYPE_1__ phy; void* gpiod_vbus; struct device* dev; struct regulator* vcc; struct regulator* clk; void* gpiod_reset; struct regulator* vbus_draw; } ;
struct usb_phy {int /*<<< orphan*/  dev; } ;
struct usb_otg {scalar_t__ state; int (* set_host ) (struct usb_otg*,struct usb_bus*) ;int (* set_peripheral ) (struct usb_otg*,struct usb_gadget*) ;TYPE_1__* usb_phy; struct usb_bus* host; struct usb_gadget* gadget; } ;
struct usb_gadget {int dummy; } ;
struct usb_bus {int dummy; } ;
struct regulator {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum usb_phy_type { ____Placeholder_usb_phy_type } usb_phy_type ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_ASIS ; 
 int /*<<< orphan*/  GPIOF_ACTIVE_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct regulator*) ; 
 scalar_t__ OTG_STATE_B_IDLE ; 
 scalar_t__ OTG_STATE_B_PERIPHERAL ; 
 scalar_t__ OTG_STATE_UNDEFINED ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (struct regulator*) ; 
 int PTR_ERR_OR_ZERO (void*) ; 
 int USB_EVENT_NONE ; 
 int USB_EVENT_VBUS ; 
 int USB_PHY_TYPE_USB2 ; 
 int /*<<< orphan*/  VBUS_IRQ_FLAGS ; 
 int /*<<< orphan*/  atomic_notifier_call_chain (int /*<<< orphan*/ *,int,struct usb_gadget*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct regulator*) ; 
 int clk_prepare_enable (struct regulator*) ; 
 int clk_set_rate (struct regulator*,scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct usb_phy_generic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct usb_phy_generic_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct regulator* devm_clk_get (struct device*,char*) ; 
 int devm_gpio_request_one (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator* devm_regulator_get (struct device*,char*) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct usb_phy_generic*) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 void* gpio_to_desc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_direction_output (void*,int) ; 
 int gpiod_get_value (void*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  gpiod_to_irq (void*) ; 
 int of_property_read_bool (struct device_node*,char*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct platform_device* platform_device_register_simple (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_unregister (struct platform_device*) ; 
 struct usb_phy_generic* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct usb_phy_generic*) ; 
 int regulator_disable (struct regulator*) ; 
 int regulator_enable (struct regulator*) ; 
 int /*<<< orphan*/  regulator_set_current_limit (struct regulator*,int /*<<< orphan*/ ,int) ; 
 int usb_add_phy_dev (TYPE_1__*) ; 
 int /*<<< orphan*/  usb_remove_phy (TYPE_1__*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

struct platform_device *usb_phy_generic_register(void)
{
	return platform_device_register_simple("usb_phy_generic",
			PLATFORM_DEVID_AUTO, NULL, 0);
}

void usb_phy_generic_unregister(struct platform_device *pdev)
{
	platform_device_unregister(pdev);
}

__attribute__((used)) static int nop_set_suspend(struct usb_phy *x, int suspend)
{
	struct usb_phy_generic *nop = dev_get_drvdata(x->dev);

	if (!IS_ERR(nop->clk)) {
		if (suspend)
			clk_disable_unprepare(nop->clk);
		else
			clk_prepare_enable(nop->clk);
	}

	return 0;
}

__attribute__((used)) static void nop_reset(struct usb_phy_generic *nop)
{
	if (!nop->gpiod_reset)
		return;

	gpiod_set_value_cansleep(nop->gpiod_reset, 1);
	usleep_range(10000, 20000);
	gpiod_set_value_cansleep(nop->gpiod_reset, 0);
}

__attribute__((used)) static void nop_set_vbus_draw(struct usb_phy_generic *nop, unsigned mA)
{
	struct regulator *vbus_draw = nop->vbus_draw;
	int enabled;
	int ret;

	if (!vbus_draw)
		return;

	enabled = nop->vbus_draw_enabled;
	if (mA) {
		regulator_set_current_limit(vbus_draw, 0, 1000 * mA);
		if (!enabled) {
			ret = regulator_enable(vbus_draw);
			if (ret < 0)
				return;
			nop->vbus_draw_enabled = 1;
		}
	} else {
		if (enabled) {
			ret = regulator_disable(vbus_draw);
			if (ret < 0)
				return;
			nop->vbus_draw_enabled = 0;
		}
	}
	nop->mA = mA;
}

__attribute__((used)) static irqreturn_t nop_gpio_vbus_thread(int irq, void *data)
{
	struct usb_phy_generic *nop = data;
	struct usb_otg *otg = nop->phy.otg;
	int vbus, status;

	vbus = gpiod_get_value(nop->gpiod_vbus);
	if ((vbus ^ nop->vbus) == 0)
		return IRQ_HANDLED;
	nop->vbus = vbus;

	if (vbus) {
		status = USB_EVENT_VBUS;
		otg->state = OTG_STATE_B_PERIPHERAL;
		nop->phy.last_event = status;

		/* drawing a "unit load" is *always* OK, except for OTG */
		nop_set_vbus_draw(nop, 100);

		atomic_notifier_call_chain(&nop->phy.notifier, status,
					   otg->gadget);
	} else {
		nop_set_vbus_draw(nop, 0);

		status = USB_EVENT_NONE;
		otg->state = OTG_STATE_B_IDLE;
		nop->phy.last_event = status;

		atomic_notifier_call_chain(&nop->phy.notifier, status,
					   otg->gadget);
	}
	return IRQ_HANDLED;
}

int usb_gen_phy_init(struct usb_phy *phy)
{
	struct usb_phy_generic *nop = dev_get_drvdata(phy->dev);
	int ret;

	if (!IS_ERR(nop->vcc)) {
		if (regulator_enable(nop->vcc))
			dev_err(phy->dev, "Failed to enable power\n");
	}

	if (!IS_ERR(nop->clk)) {
		ret = clk_prepare_enable(nop->clk);
		if (ret)
			return ret;
	}

	nop_reset(nop);

	return 0;
}

void usb_gen_phy_shutdown(struct usb_phy *phy)
{
	struct usb_phy_generic *nop = dev_get_drvdata(phy->dev);

	gpiod_set_value_cansleep(nop->gpiod_reset, 1);

	if (!IS_ERR(nop->clk))
		clk_disable_unprepare(nop->clk);

	if (!IS_ERR(nop->vcc)) {
		if (regulator_disable(nop->vcc))
			dev_err(phy->dev, "Failed to disable power\n");
	}
}

__attribute__((used)) static int nop_set_peripheral(struct usb_otg *otg, struct usb_gadget *gadget)
{
	if (!otg)
		return -ENODEV;

	if (!gadget) {
		otg->gadget = NULL;
		return -ENODEV;
	}

	otg->gadget = gadget;
	if (otg->state == OTG_STATE_B_PERIPHERAL)
		atomic_notifier_call_chain(&otg->usb_phy->notifier,
					   USB_EVENT_VBUS, otg->gadget);
	else
		otg->state = OTG_STATE_B_IDLE;
	return 0;
}

__attribute__((used)) static int nop_set_host(struct usb_otg *otg, struct usb_bus *host)
{
	if (!otg)
		return -ENODEV;

	if (!host) {
		otg->host = NULL;
		return -ENODEV;
	}

	otg->host = host;
	return 0;
}

int usb_phy_gen_create_phy(struct device *dev, struct usb_phy_generic *nop,
		struct usb_phy_generic_platform_data *pdata)
{
	enum usb_phy_type type = USB_PHY_TYPE_USB2;
	int err = 0;

	u32 clk_rate = 0;
	bool needs_vcc = false, needs_clk = false;

	if (dev->of_node) {
		struct device_node *node = dev->of_node;

		if (of_property_read_u32(node, "clock-frequency", &clk_rate))
			clk_rate = 0;

		needs_vcc = of_property_read_bool(node, "vcc-supply");
		needs_clk = of_property_read_bool(node, "clocks");
		nop->gpiod_reset = devm_gpiod_get_optional(dev, "reset",
							   GPIOD_ASIS);
		err = PTR_ERR_OR_ZERO(nop->gpiod_reset);
		if (!err) {
			nop->gpiod_vbus = devm_gpiod_get_optional(dev,
							 "vbus-detect",
							 GPIOD_ASIS);
			err = PTR_ERR_OR_ZERO(nop->gpiod_vbus);
		}
	} else if (pdata) {
		type = pdata->type;
		clk_rate = pdata->clk_rate;
		needs_vcc = pdata->needs_vcc;
		if (gpio_is_valid(pdata->gpio_reset)) {
			err = devm_gpio_request_one(dev, pdata->gpio_reset,
						    GPIOF_ACTIVE_LOW,
						    dev_name(dev));
			if (!err)
				nop->gpiod_reset =
					gpio_to_desc(pdata->gpio_reset);
		}
		nop->gpiod_vbus = pdata->gpiod_vbus;
	}

	if (err == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (err) {
		dev_err(dev, "Error requesting RESET or VBUS GPIO\n");
		return err;
	}
	if (nop->gpiod_reset)
		gpiod_direction_output(nop->gpiod_reset, 1);

	nop->phy.otg = devm_kzalloc(dev, sizeof(*nop->phy.otg),
			GFP_KERNEL);
	if (!nop->phy.otg)
		return -ENOMEM;

	nop->clk = devm_clk_get(dev, "main_clk");
	if (IS_ERR(nop->clk)) {
		dev_dbg(dev, "Can't get phy clock: %ld\n",
					PTR_ERR(nop->clk));
		if (needs_clk)
			return PTR_ERR(nop->clk);
	}

	if (!IS_ERR(nop->clk) && clk_rate) {
		err = clk_set_rate(nop->clk, clk_rate);
		if (err) {
			dev_err(dev, "Error setting clock rate\n");
			return err;
		}
	}

	nop->vcc = devm_regulator_get(dev, "vcc");
	if (IS_ERR(nop->vcc)) {
		dev_dbg(dev, "Error getting vcc regulator: %ld\n",
					PTR_ERR(nop->vcc));
		if (needs_vcc)
			return -EPROBE_DEFER;
	}

	nop->dev		= dev;
	nop->phy.dev		= nop->dev;
	nop->phy.label		= "nop-xceiv";
	nop->phy.set_suspend	= nop_set_suspend;
	nop->phy.type		= type;

	nop->phy.otg->state		= OTG_STATE_UNDEFINED;
	nop->phy.otg->usb_phy		= &nop->phy;
	nop->phy.otg->set_host		= nop_set_host;
	nop->phy.otg->set_peripheral	= nop_set_peripheral;

	return 0;
}

__attribute__((used)) static int usb_phy_generic_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct usb_phy_generic	*nop;
	int err;

	nop = devm_kzalloc(dev, sizeof(*nop), GFP_KERNEL);
	if (!nop)
		return -ENOMEM;

	err = usb_phy_gen_create_phy(dev, nop, dev_get_platdata(&pdev->dev));
	if (err)
		return err;
	if (nop->gpiod_vbus) {
		err = devm_request_threaded_irq(&pdev->dev,
						gpiod_to_irq(nop->gpiod_vbus),
						NULL, nop_gpio_vbus_thread,
						VBUS_IRQ_FLAGS, "vbus_detect",
						nop);
		if (err) {
			dev_err(&pdev->dev, "can't request irq %i, err: %d\n",
				gpiod_to_irq(nop->gpiod_vbus), err);
			return err;
		}
		nop->phy.otg->state = gpiod_get_value(nop->gpiod_vbus) ?
			OTG_STATE_B_PERIPHERAL : OTG_STATE_B_IDLE;
	}

	nop->phy.init		= usb_gen_phy_init;
	nop->phy.shutdown	= usb_gen_phy_shutdown;

	err = usb_add_phy_dev(&nop->phy);
	if (err) {
		dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
			err);
		return err;
	}

	platform_set_drvdata(pdev, nop);

	return 0;
}

__attribute__((used)) static int usb_phy_generic_remove(struct platform_device *pdev)
{
	struct usb_phy_generic *nop = platform_get_drvdata(pdev);

	usb_remove_phy(&nop->phy);

	return 0;
}

