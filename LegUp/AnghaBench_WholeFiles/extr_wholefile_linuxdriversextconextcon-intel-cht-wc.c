#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct intel_soc_pmic {int /*<<< orphan*/  regmap; } ;
struct cht_wc_extcon_data {int usb_host; unsigned int previous_cable; TYPE_1__* dev; int /*<<< orphan*/  regmap; int /*<<< orphan*/  edev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  CHT_WC_CHGRCTRL0 ; 
 int CHT_WC_CHGRCTRL0_CCSM_OFF_MASK ; 
 int CHT_WC_CHGRCTRL0_SWCONTROL ; 
 int /*<<< orphan*/  CHT_WC_PHYCTRL ; 
 int CHT_WC_PWRSRC_ID_FLOAT ; 
 int CHT_WC_PWRSRC_ID_GND ; 
 int /*<<< orphan*/  CHT_WC_PWRSRC_IRQ ; 
 int /*<<< orphan*/  CHT_WC_PWRSRC_IRQ_MASK ; 
 int /*<<< orphan*/  CHT_WC_PWRSRC_STS ; 
 int CHT_WC_PWRSRC_VBUS ; 
 int /*<<< orphan*/  CHT_WC_USBSRC ; 
 int CHT_WC_USBSRC_STS_FAIL ; 
 int CHT_WC_USBSRC_STS_MASK ; 
 int CHT_WC_USBSRC_STS_SUCCESS ; 
#define  CHT_WC_USBSRC_TYPE_ACA 135 
#define  CHT_WC_USBSRC_TYPE_CDP 134 
#define  CHT_WC_USBSRC_TYPE_DCP 133 
#define  CHT_WC_USBSRC_TYPE_DCP_EXTPHY 132 
#define  CHT_WC_USBSRC_TYPE_FLOAT_DP_DN 131 
 int CHT_WC_USBSRC_TYPE_MASK ; 
#define  CHT_WC_USBSRC_TYPE_MHL 130 
#define  CHT_WC_USBSRC_TYPE_OTHER 129 
#define  CHT_WC_USBSRC_TYPE_SDP 128 
 int CHT_WC_USBSRC_TYPE_SHIFT ; 
 int /*<<< orphan*/  CHT_WC_VBUS_GPIO_CTLO ; 
 int CHT_WC_VBUS_GPIO_CTLO_DIR_OUT ; 
 int CHT_WC_VBUS_GPIO_CTLO_DRV_OD ; 
 int CHT_WC_VBUS_GPIO_CTLO_OUTPUT ; 
 int ENOMEM ; 
 int EXTCON_CHG_USB_ACA ; 
 int EXTCON_CHG_USB_CDP ; 
 int EXTCON_CHG_USB_DCP ; 
 int EXTCON_CHG_USB_SDP ; 
 void* EXTCON_NONE ; 
 unsigned int EXTCON_USB ; 
 unsigned int EXTCON_USB_HOST ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MUX_SEL_PMIC ; 
 int MUX_SEL_SOC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int USB_ID_FLOAT ; 
 int USB_ID_GND ; 
 int USB_RID_A ; 
 int /*<<< orphan*/  cht_wc_extcon_cables ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct intel_soc_pmic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  devm_extcon_dev_allocate (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int devm_extcon_dev_register (TYPE_1__*,int /*<<< orphan*/ ) ; 
 struct cht_wc_extcon_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct cht_wc_extcon_data*) ; 
 int /*<<< orphan*/  extcon_set_state_sync (int /*<<< orphan*/ ,unsigned int,int) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct cht_wc_extcon_data* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cht_wc_extcon_data*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 

__attribute__((used)) static int cht_wc_extcon_get_id(struct cht_wc_extcon_data *ext, int pwrsrc_sts)
{
	if (pwrsrc_sts & CHT_WC_PWRSRC_ID_GND)
		return USB_ID_GND;
	if (pwrsrc_sts & CHT_WC_PWRSRC_ID_FLOAT)
		return USB_ID_FLOAT;

	/*
	 * Once we have iio support for the gpadc we should read the USBID
	 * gpadc channel here and determine ACA role based on that.
	 */
	return USB_ID_FLOAT;
}

__attribute__((used)) static int cht_wc_extcon_get_charger(struct cht_wc_extcon_data *ext,
				     bool ignore_errors)
{
	int ret, usbsrc, status;
	unsigned long timeout;

	/* Charger detection can take upto 600ms, wait 800ms max. */
	timeout = jiffies + msecs_to_jiffies(800);
	do {
		ret = regmap_read(ext->regmap, CHT_WC_USBSRC, &usbsrc);
		if (ret) {
			dev_err(ext->dev, "Error reading usbsrc: %d\n", ret);
			return ret;
		}

		status = usbsrc & CHT_WC_USBSRC_STS_MASK;
		if (status == CHT_WC_USBSRC_STS_SUCCESS ||
		    status == CHT_WC_USBSRC_STS_FAIL)
			break;

		msleep(50); /* Wait a bit before retrying */
	} while (time_before(jiffies, timeout));

	if (status != CHT_WC_USBSRC_STS_SUCCESS) {
		if (ignore_errors)
			return EXTCON_CHG_USB_SDP; /* Save fallback */

		if (status == CHT_WC_USBSRC_STS_FAIL)
			dev_warn(ext->dev, "Could not detect charger type\n");
		else
			dev_warn(ext->dev, "Timeout detecting charger type\n");
		return EXTCON_CHG_USB_SDP; /* Save fallback */
	}

	usbsrc = (usbsrc & CHT_WC_USBSRC_TYPE_MASK) >> CHT_WC_USBSRC_TYPE_SHIFT;
	switch (usbsrc) {
	default:
		dev_warn(ext->dev,
			"Unhandled charger type %d, defaulting to SDP\n",
			 ret);
		/* Fall through, treat as SDP */
	case CHT_WC_USBSRC_TYPE_SDP:
	case CHT_WC_USBSRC_TYPE_FLOAT_DP_DN:
	case CHT_WC_USBSRC_TYPE_OTHER:
		return EXTCON_CHG_USB_SDP;
	case CHT_WC_USBSRC_TYPE_CDP:
		return EXTCON_CHG_USB_CDP;
	case CHT_WC_USBSRC_TYPE_DCP:
	case CHT_WC_USBSRC_TYPE_DCP_EXTPHY:
	case CHT_WC_USBSRC_TYPE_MHL: /* MHL2+ delivers upto 2A, treat as DCP */
		return EXTCON_CHG_USB_DCP;
	case CHT_WC_USBSRC_TYPE_ACA:
		return EXTCON_CHG_USB_ACA;
	}
}

__attribute__((used)) static void cht_wc_extcon_set_phymux(struct cht_wc_extcon_data *ext, u8 state)
{
	int ret;

	ret = regmap_write(ext->regmap, CHT_WC_PHYCTRL, state);
	if (ret)
		dev_err(ext->dev, "Error writing phyctrl: %d\n", ret);
}

__attribute__((used)) static void cht_wc_extcon_set_5v_boost(struct cht_wc_extcon_data *ext,
				       bool enable)
{
	int ret, val;

	/*
	 * The 5V boost converter is enabled through a gpio on the PMIC, since
	 * there currently is no gpio driver we access the gpio reg directly.
	 */
	val = CHT_WC_VBUS_GPIO_CTLO_DRV_OD | CHT_WC_VBUS_GPIO_CTLO_DIR_OUT;
	if (enable)
		val |= CHT_WC_VBUS_GPIO_CTLO_OUTPUT;

	ret = regmap_write(ext->regmap, CHT_WC_VBUS_GPIO_CTLO, val);
	if (ret)
		dev_err(ext->dev, "Error writing Vbus GPIO CTLO: %d\n", ret);
}

__attribute__((used)) static void cht_wc_extcon_set_state(struct cht_wc_extcon_data *ext,
				    unsigned int cable, bool state)
{
	extcon_set_state_sync(ext->edev, cable, state);
	if (cable == EXTCON_CHG_USB_SDP)
		extcon_set_state_sync(ext->edev, EXTCON_USB, state);
}

__attribute__((used)) static void cht_wc_extcon_pwrsrc_event(struct cht_wc_extcon_data *ext)
{
	int ret, pwrsrc_sts, id;
	unsigned int cable = EXTCON_NONE;
	/* Ignore errors in host mode, as the 5v boost converter is on then */
	bool ignore_get_charger_errors = ext->usb_host;

	ret = regmap_read(ext->regmap, CHT_WC_PWRSRC_STS, &pwrsrc_sts);
	if (ret) {
		dev_err(ext->dev, "Error reading pwrsrc status: %d\n", ret);
		return;
	}

	id = cht_wc_extcon_get_id(ext, pwrsrc_sts);
	if (id == USB_ID_GND) {
		/* The 5v boost causes a false VBUS / SDP detect, skip */
		goto charger_det_done;
	}

	/* Plugged into a host/charger or not connected? */
	if (!(pwrsrc_sts & CHT_WC_PWRSRC_VBUS)) {
		/* Route D+ and D- to PMIC for future charger detection */
		cht_wc_extcon_set_phymux(ext, MUX_SEL_PMIC);
		goto set_state;
	}

	ret = cht_wc_extcon_get_charger(ext, ignore_get_charger_errors);
	if (ret >= 0)
		cable = ret;

charger_det_done:
	/* Route D+ and D- to SoC for the host or gadget controller */
	cht_wc_extcon_set_phymux(ext, MUX_SEL_SOC);

set_state:
	if (cable != ext->previous_cable) {
		cht_wc_extcon_set_state(ext, cable, true);
		cht_wc_extcon_set_state(ext, ext->previous_cable, false);
		ext->previous_cable = cable;
	}

	ext->usb_host = ((id == USB_ID_GND) || (id == USB_RID_A));
	extcon_set_state_sync(ext->edev, EXTCON_USB_HOST, ext->usb_host);
}

__attribute__((used)) static irqreturn_t cht_wc_extcon_isr(int irq, void *data)
{
	struct cht_wc_extcon_data *ext = data;
	int ret, irqs;

	ret = regmap_read(ext->regmap, CHT_WC_PWRSRC_IRQ, &irqs);
	if (ret) {
		dev_err(ext->dev, "Error reading irqs: %d\n", ret);
		return IRQ_NONE;
	}

	cht_wc_extcon_pwrsrc_event(ext);

	ret = regmap_write(ext->regmap, CHT_WC_PWRSRC_IRQ, irqs);
	if (ret) {
		dev_err(ext->dev, "Error writing irqs: %d\n", ret);
		return IRQ_NONE;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int cht_wc_extcon_sw_control(struct cht_wc_extcon_data *ext, bool enable)
{
	int ret, mask, val;

	mask = CHT_WC_CHGRCTRL0_SWCONTROL | CHT_WC_CHGRCTRL0_CCSM_OFF_MASK;
	val = enable ? mask : 0;
	ret = regmap_update_bits(ext->regmap, CHT_WC_CHGRCTRL0, mask, val);
	if (ret)
		dev_err(ext->dev, "Error setting sw control: %d\n", ret);

	return ret;
}

__attribute__((used)) static int cht_wc_extcon_probe(struct platform_device *pdev)
{
	struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
	struct cht_wc_extcon_data *ext;
	int irq, ret;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	ext = devm_kzalloc(&pdev->dev, sizeof(*ext), GFP_KERNEL);
	if (!ext)
		return -ENOMEM;

	ext->dev = &pdev->dev;
	ext->regmap = pmic->regmap;
	ext->previous_cable = EXTCON_NONE;

	/* Initialize extcon device */
	ext->edev = devm_extcon_dev_allocate(ext->dev, cht_wc_extcon_cables);
	if (IS_ERR(ext->edev))
		return PTR_ERR(ext->edev);

	/*
	 * When a host-cable is detected the BIOS enables an external 5v boost
	 * converter to power connected devices there are 2 problems with this:
	 * 1) This gets seen by the external battery charger as a valid Vbus
	 *    supply and it then tries to feed Vsys from this creating a
	 *    feedback loop which causes aprox. 300 mA extra battery drain
	 *    (and unless we drive the external-charger-disable pin high it
	 *    also tries to charge the battery causing even more feedback).
	 * 2) This gets seen by the pwrsrc block as a SDP USB Vbus supply
	 * Since the external battery charger has its own 5v boost converter
	 * which does not have these issues, we simply turn the separate
	 * external 5v boost converter off and leave it off entirely.
	 */
	cht_wc_extcon_set_5v_boost(ext, false);

	/* Enable sw control */
	ret = cht_wc_extcon_sw_control(ext, true);
	if (ret)
		return ret;

	/* Register extcon device */
	ret = devm_extcon_dev_register(ext->dev, ext->edev);
	if (ret) {
		dev_err(ext->dev, "Error registering extcon device: %d\n", ret);
		goto disable_sw_control;
	}

	/* Route D+ and D- to PMIC for initial charger detection */
	cht_wc_extcon_set_phymux(ext, MUX_SEL_PMIC);

	/* Get initial state */
	cht_wc_extcon_pwrsrc_event(ext);

	ret = devm_request_threaded_irq(ext->dev, irq, NULL, cht_wc_extcon_isr,
					IRQF_ONESHOT, pdev->name, ext);
	if (ret) {
		dev_err(ext->dev, "Error requesting interrupt: %d\n", ret);
		goto disable_sw_control;
	}

	/* Unmask irqs */
	ret = regmap_write(ext->regmap, CHT_WC_PWRSRC_IRQ_MASK,
			   (int)~(CHT_WC_PWRSRC_VBUS | CHT_WC_PWRSRC_ID_GND |
				  CHT_WC_PWRSRC_ID_FLOAT));
	if (ret) {
		dev_err(ext->dev, "Error writing irq-mask: %d\n", ret);
		goto disable_sw_control;
	}

	platform_set_drvdata(pdev, ext);

	return 0;

disable_sw_control:
	cht_wc_extcon_sw_control(ext, false);
	return ret;
}

__attribute__((used)) static int cht_wc_extcon_remove(struct platform_device *pdev)
{
	struct cht_wc_extcon_data *ext = platform_get_drvdata(pdev);

	cht_wc_extcon_sw_control(ext, false);

	return 0;
}

