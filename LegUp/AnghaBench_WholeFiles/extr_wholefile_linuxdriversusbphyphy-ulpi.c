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
typedef  int u32 ;
struct usb_phy_io_ops {int dummy; } ;
struct usb_phy {int flags; char* label; int (* init ) (struct usb_phy*) ;struct usb_otg* otg; struct usb_phy_io_ops* io_ops; } ;
struct usb_otg {int (* set_host ) (struct usb_otg*,struct usb_bus*) ;int (* set_vbus ) (struct usb_otg*,int) ;struct usb_phy* usb_phy; struct usb_bus* host; } ;
struct usb_bus {int dummy; } ;
struct TYPE_3__ {scalar_t__ id; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ULPI_FC_FS4LS ; 
 int ULPI_FC_HS ; 
 int ULPI_FC_LS ; 
 int ULPI_FC_OP_DIS_NRZI ; 
 int ULPI_FC_OP_NODRV ; 
 int ULPI_FC_OP_NSYNC_NEOP ; 
 int ULPI_FC_TERMSEL ; 
 scalar_t__ ULPI_FUNC_CTRL ; 
 unsigned int ULPI_FUNC_CTRL_FS4LS ; 
 unsigned int ULPI_FUNC_CTRL_FULL_SPEED ; 
 unsigned int ULPI_FUNC_CTRL_HIGH_SPEED ; 
 unsigned int ULPI_FUNC_CTRL_LOW_SPEED ; 
 unsigned int ULPI_FUNC_CTRL_OPMODE_DISABLE_NRZI ; 
 unsigned int ULPI_FUNC_CTRL_OPMODE_NONDRIVING ; 
 unsigned int ULPI_FUNC_CTRL_OPMODE_NORMAL ; 
 unsigned int ULPI_FUNC_CTRL_OPMODE_NOSYNC_NOEOP ; 
 unsigned int ULPI_FUNC_CTRL_SUSPENDM ; 
 unsigned int ULPI_FUNC_CTRL_TERMSELECT ; 
 int ULPI_IC_3PIN_SERIAL ; 
 int ULPI_IC_6PIN_SERIAL ; 
 int ULPI_IC_AUTORESUME ; 
 int ULPI_IC_CARKIT ; 
 int ULPI_IC_EXTVBUS_INDINV ; 
 int ULPI_IC_IND_PASSTHRU ; 
 int ULPI_IC_PROTECT_DIS ; 
 scalar_t__ ULPI_ID (int,int) ; 
 scalar_t__ ULPI_IFC_CTRL ; 
 unsigned int ULPI_IFC_CTRL_3_PIN_SERIAL_MODE ; 
 unsigned int ULPI_IFC_CTRL_6_PIN_SERIAL_MODE ; 
 unsigned int ULPI_IFC_CTRL_AUTORESUME ; 
 unsigned int ULPI_IFC_CTRL_CARKITMODE ; 
 unsigned int ULPI_IFC_CTRL_EXTERNAL_VBUS ; 
 unsigned int ULPI_IFC_CTRL_PASSTHRU ; 
 unsigned int ULPI_IFC_CTRL_PROTECT_IFC_DISABLE ; 
 scalar_t__ ULPI_OTG_CTRL ; 
 unsigned int ULPI_OTG_CTRL_DM_PULLDOWN ; 
 unsigned int ULPI_OTG_CTRL_DP_PULLDOWN ; 
 unsigned int ULPI_OTG_CTRL_DRVVBUS ; 
 unsigned int ULPI_OTG_CTRL_DRVVBUS_EXT ; 
 unsigned int ULPI_OTG_CTRL_EXTVBUSIND ; 
 unsigned int ULPI_OTG_CTRL_ID_PULLUP ; 
 int ULPI_OTG_DM_PULLDOWN_DIS ; 
 int ULPI_OTG_DP_PULLDOWN_DIS ; 
 int ULPI_OTG_DRVVBUS ; 
 int ULPI_OTG_DRVVBUS_EXT ; 
 int ULPI_OTG_EXTVBUSIND ; 
 int ULPI_OTG_ID_PULLUP ; 
 scalar_t__ ULPI_PRODUCT_ID_HIGH ; 
 scalar_t__ ULPI_SCRATCH ; 
 int /*<<< orphan*/  kfree (struct usb_phy*) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 TYPE_1__* ulpi_ids ; 
 void* usb_phy_io_read (struct usb_phy*,scalar_t__) ; 
 int usb_phy_io_write (struct usb_phy*,unsigned int,scalar_t__) ; 

__attribute__((used)) static int ulpi_set_otg_flags(struct usb_phy *phy)
{
	unsigned int flags = ULPI_OTG_CTRL_DP_PULLDOWN |
			     ULPI_OTG_CTRL_DM_PULLDOWN;

	if (phy->flags & ULPI_OTG_ID_PULLUP)
		flags |= ULPI_OTG_CTRL_ID_PULLUP;

	/*
	 * ULPI Specification rev.1.1 default
	 * for Dp/DmPulldown is enabled.
	 */
	if (phy->flags & ULPI_OTG_DP_PULLDOWN_DIS)
		flags &= ~ULPI_OTG_CTRL_DP_PULLDOWN;

	if (phy->flags & ULPI_OTG_DM_PULLDOWN_DIS)
		flags &= ~ULPI_OTG_CTRL_DM_PULLDOWN;

	if (phy->flags & ULPI_OTG_EXTVBUSIND)
		flags |= ULPI_OTG_CTRL_EXTVBUSIND;

	return usb_phy_io_write(phy, flags, ULPI_OTG_CTRL);
}

__attribute__((used)) static int ulpi_set_fc_flags(struct usb_phy *phy)
{
	unsigned int flags = 0;

	/*
	 * ULPI Specification rev.1.1 default
	 * for XcvrSelect is Full Speed.
	 */
	if (phy->flags & ULPI_FC_HS)
		flags |= ULPI_FUNC_CTRL_HIGH_SPEED;
	else if (phy->flags & ULPI_FC_LS)
		flags |= ULPI_FUNC_CTRL_LOW_SPEED;
	else if (phy->flags & ULPI_FC_FS4LS)
		flags |= ULPI_FUNC_CTRL_FS4LS;
	else
		flags |= ULPI_FUNC_CTRL_FULL_SPEED;

	if (phy->flags & ULPI_FC_TERMSEL)
		flags |= ULPI_FUNC_CTRL_TERMSELECT;

	/*
	 * ULPI Specification rev.1.1 default
	 * for OpMode is Normal Operation.
	 */
	if (phy->flags & ULPI_FC_OP_NODRV)
		flags |= ULPI_FUNC_CTRL_OPMODE_NONDRIVING;
	else if (phy->flags & ULPI_FC_OP_DIS_NRZI)
		flags |= ULPI_FUNC_CTRL_OPMODE_DISABLE_NRZI;
	else if (phy->flags & ULPI_FC_OP_NSYNC_NEOP)
		flags |= ULPI_FUNC_CTRL_OPMODE_NOSYNC_NOEOP;
	else
		flags |= ULPI_FUNC_CTRL_OPMODE_NORMAL;

	/*
	 * ULPI Specification rev.1.1 default
	 * for SuspendM is Powered.
	 */
	flags |= ULPI_FUNC_CTRL_SUSPENDM;

	return usb_phy_io_write(phy, flags, ULPI_FUNC_CTRL);
}

__attribute__((used)) static int ulpi_set_ic_flags(struct usb_phy *phy)
{
	unsigned int flags = 0;

	if (phy->flags & ULPI_IC_AUTORESUME)
		flags |= ULPI_IFC_CTRL_AUTORESUME;

	if (phy->flags & ULPI_IC_EXTVBUS_INDINV)
		flags |= ULPI_IFC_CTRL_EXTERNAL_VBUS;

	if (phy->flags & ULPI_IC_IND_PASSTHRU)
		flags |= ULPI_IFC_CTRL_PASSTHRU;

	if (phy->flags & ULPI_IC_PROTECT_DIS)
		flags |= ULPI_IFC_CTRL_PROTECT_IFC_DISABLE;

	return usb_phy_io_write(phy, flags, ULPI_IFC_CTRL);
}

__attribute__((used)) static int ulpi_set_flags(struct usb_phy *phy)
{
	int ret;

	ret = ulpi_set_otg_flags(phy);
	if (ret)
		return ret;

	ret = ulpi_set_ic_flags(phy);
	if (ret)
		return ret;

	return ulpi_set_fc_flags(phy);
}

__attribute__((used)) static int ulpi_check_integrity(struct usb_phy *phy)
{
	int ret, i;
	unsigned int val = 0x55;

	for (i = 0; i < 2; i++) {
		ret = usb_phy_io_write(phy, val, ULPI_SCRATCH);
		if (ret < 0)
			return ret;

		ret = usb_phy_io_read(phy, ULPI_SCRATCH);
		if (ret < 0)
			return ret;

		if (ret != val) {
			pr_err("ULPI integrity check: failed!");
			return -ENODEV;
		}
		val = val << 1;
	}

	pr_info("ULPI integrity check: passed.\n");

	return 0;
}

__attribute__((used)) static int ulpi_init(struct usb_phy *phy)
{
	int i, vid, pid, ret;
	u32 ulpi_id = 0;

	for (i = 0; i < 4; i++) {
		ret = usb_phy_io_read(phy, ULPI_PRODUCT_ID_HIGH - i);
		if (ret < 0)
			return ret;
		ulpi_id = (ulpi_id << 8) | ret;
	}
	vid = ulpi_id & 0xffff;
	pid = ulpi_id >> 16;

	pr_info("ULPI transceiver vendor/product ID 0x%04x/0x%04x\n", vid, pid);

	for (i = 0; i < ARRAY_SIZE(ulpi_ids); i++) {
		if (ulpi_ids[i].id == ULPI_ID(vid, pid)) {
			pr_info("Found %s ULPI transceiver.\n",
				ulpi_ids[i].name);
			break;
		}
	}

	ret = ulpi_check_integrity(phy);
	if (ret)
		return ret;

	return ulpi_set_flags(phy);
}

__attribute__((used)) static int ulpi_set_host(struct usb_otg *otg, struct usb_bus *host)
{
	struct usb_phy *phy = otg->usb_phy;
	unsigned int flags = usb_phy_io_read(phy, ULPI_IFC_CTRL);

	if (!host) {
		otg->host = NULL;
		return 0;
	}

	otg->host = host;

	flags &= ~(ULPI_IFC_CTRL_6_PIN_SERIAL_MODE |
		   ULPI_IFC_CTRL_3_PIN_SERIAL_MODE |
		   ULPI_IFC_CTRL_CARKITMODE);

	if (phy->flags & ULPI_IC_6PIN_SERIAL)
		flags |= ULPI_IFC_CTRL_6_PIN_SERIAL_MODE;
	else if (phy->flags & ULPI_IC_3PIN_SERIAL)
		flags |= ULPI_IFC_CTRL_3_PIN_SERIAL_MODE;
	else if (phy->flags & ULPI_IC_CARKIT)
		flags |= ULPI_IFC_CTRL_CARKITMODE;

	return usb_phy_io_write(phy, flags, ULPI_IFC_CTRL);
}

__attribute__((used)) static int ulpi_set_vbus(struct usb_otg *otg, bool on)
{
	struct usb_phy *phy = otg->usb_phy;
	unsigned int flags = usb_phy_io_read(phy, ULPI_OTG_CTRL);

	flags &= ~(ULPI_OTG_CTRL_DRVVBUS | ULPI_OTG_CTRL_DRVVBUS_EXT);

	if (on) {
		if (phy->flags & ULPI_OTG_DRVVBUS)
			flags |= ULPI_OTG_CTRL_DRVVBUS;

		if (phy->flags & ULPI_OTG_DRVVBUS_EXT)
			flags |= ULPI_OTG_CTRL_DRVVBUS_EXT;
	}

	return usb_phy_io_write(phy, flags, ULPI_OTG_CTRL);
}

struct usb_phy *
otg_ulpi_create(struct usb_phy_io_ops *ops,
		unsigned int flags)
{
	struct usb_phy *phy;
	struct usb_otg *otg;

	phy = kzalloc(sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return NULL;

	otg = kzalloc(sizeof(*otg), GFP_KERNEL);
	if (!otg) {
		kfree(phy);
		return NULL;
	}

	phy->label	= "ULPI";
	phy->flags	= flags;
	phy->io_ops	= ops;
	phy->otg	= otg;
	phy->init	= ulpi_init;

	otg->usb_phy	= phy;
	otg->set_host	= ulpi_set_host;
	otg->set_vbus	= ulpi_set_vbus;

	return phy;
}

