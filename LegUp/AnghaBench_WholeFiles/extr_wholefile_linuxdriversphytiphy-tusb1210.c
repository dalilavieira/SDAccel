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
typedef  int u8 ;
struct ulpi {int /*<<< orphan*/  dev; } ;
struct tusb1210 {int vendor_specific2; void* phy; struct ulpi* ulpi; void* gpio_cs; void* gpio_reset; } ;
struct phy {int dummy; } ;
typedef  enum phy_mode { ____Placeholder_phy_mode } phy_mode ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
#define  PHY_MODE_USB_DEVICE 129 
#define  PHY_MODE_USB_HOST 128 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  TUSB1210_VENDOR_SPECIFIC2 ; 
 int TUSB1210_VENDOR_SPECIFIC2_DP_SHIFT ; 
 int TUSB1210_VENDOR_SPECIFIC2_IHSTX_SHIFT ; 
 int TUSB1210_VENDOR_SPECIFIC2_ZHSDRV_SHIFT ; 
 int /*<<< orphan*/  ULPI_OTG_CTRL ; 
 int ULPI_OTG_CTRL_DM_PULLDOWN ; 
 int ULPI_OTG_CTRL_DP_PULLDOWN ; 
 int ULPI_OTG_CTRL_DRVVBUS ; 
 int ULPI_OTG_CTRL_DRVVBUS_EXT ; 
 int ULPI_OTG_CTRL_ID_PULLUP ; 
 int /*<<< orphan*/  device_property_read_u8 (int /*<<< orphan*/ *,char*,int*) ; 
 void* devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct tusb1210* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 struct tusb1210* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_ops ; 
 int /*<<< orphan*/  phy_set_drvdata (void*,struct tusb1210*) ; 
 struct tusb1210* ulpi_get_drvdata (struct ulpi*) ; 
 void* ulpi_phy_create (struct ulpi*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ulpi_phy_destroy (struct ulpi*,void*) ; 
 int ulpi_read (struct ulpi*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ulpi_set_drvdata (struct ulpi*,struct tusb1210*) ; 
 int ulpi_write (struct ulpi*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int tusb1210_power_on(struct phy *phy)
{
	struct tusb1210 *tusb = phy_get_drvdata(phy);

	gpiod_set_value_cansleep(tusb->gpio_reset, 1);
	gpiod_set_value_cansleep(tusb->gpio_cs, 1);

	/* Restore the optional eye diagram optimization value */
	if (tusb->vendor_specific2)
		ulpi_write(tusb->ulpi, TUSB1210_VENDOR_SPECIFIC2,
			   tusb->vendor_specific2);

	return 0;
}

__attribute__((used)) static int tusb1210_power_off(struct phy *phy)
{
	struct tusb1210 *tusb = phy_get_drvdata(phy);

	gpiod_set_value_cansleep(tusb->gpio_reset, 0);
	gpiod_set_value_cansleep(tusb->gpio_cs, 0);

	return 0;
}

__attribute__((used)) static int tusb1210_set_mode(struct phy *phy, enum phy_mode mode)
{
	struct tusb1210 *tusb = phy_get_drvdata(phy);
	int ret;

	ret = ulpi_read(tusb->ulpi, ULPI_OTG_CTRL);
	if (ret < 0)
		return ret;

	switch (mode) {
	case PHY_MODE_USB_HOST:
		ret |= (ULPI_OTG_CTRL_DRVVBUS_EXT
			| ULPI_OTG_CTRL_ID_PULLUP
			| ULPI_OTG_CTRL_DP_PULLDOWN
			| ULPI_OTG_CTRL_DM_PULLDOWN);
		ulpi_write(tusb->ulpi, ULPI_OTG_CTRL, ret);
		ret |= ULPI_OTG_CTRL_DRVVBUS;
		break;
	case PHY_MODE_USB_DEVICE:
		ret &= ~(ULPI_OTG_CTRL_DRVVBUS
			 | ULPI_OTG_CTRL_DP_PULLDOWN
			 | ULPI_OTG_CTRL_DM_PULLDOWN);
		ulpi_write(tusb->ulpi, ULPI_OTG_CTRL, ret);
		ret &= ~ULPI_OTG_CTRL_DRVVBUS_EXT;
		break;
	default:
		/* nothing */
		return 0;
	}

	return ulpi_write(tusb->ulpi, ULPI_OTG_CTRL, ret);
}

__attribute__((used)) static int tusb1210_probe(struct ulpi *ulpi)
{
	struct tusb1210 *tusb;
	u8 val, reg;

	tusb = devm_kzalloc(&ulpi->dev, sizeof(*tusb), GFP_KERNEL);
	if (!tusb)
		return -ENOMEM;

	tusb->gpio_reset = devm_gpiod_get_optional(&ulpi->dev, "reset",
						   GPIOD_OUT_LOW);
	if (IS_ERR(tusb->gpio_reset))
		return PTR_ERR(tusb->gpio_reset);

	gpiod_set_value_cansleep(tusb->gpio_reset, 1);

	tusb->gpio_cs = devm_gpiod_get_optional(&ulpi->dev, "cs",
						GPIOD_OUT_LOW);
	if (IS_ERR(tusb->gpio_cs))
		return PTR_ERR(tusb->gpio_cs);

	gpiod_set_value_cansleep(tusb->gpio_cs, 1);

	/*
	 * VENDOR_SPECIFIC2 register in TUSB1210 can be used for configuring eye
	 * diagram optimization and DP/DM swap.
	 */

	/* High speed output drive strength configuration */
	device_property_read_u8(&ulpi->dev, "ihstx", &val);
	reg = val << TUSB1210_VENDOR_SPECIFIC2_IHSTX_SHIFT;

	/* High speed output impedance configuration */
	device_property_read_u8(&ulpi->dev, "zhsdrv", &val);
	reg |= val << TUSB1210_VENDOR_SPECIFIC2_ZHSDRV_SHIFT;

	/* DP/DM swap control */
	device_property_read_u8(&ulpi->dev, "datapolarity", &val);
	reg |= val << TUSB1210_VENDOR_SPECIFIC2_DP_SHIFT;

	if (reg) {
		ulpi_write(ulpi, TUSB1210_VENDOR_SPECIFIC2, reg);
		tusb->vendor_specific2 = reg;
	}

	tusb->phy = ulpi_phy_create(ulpi, &phy_ops);
	if (IS_ERR(tusb->phy))
		return PTR_ERR(tusb->phy);

	tusb->ulpi = ulpi;

	phy_set_drvdata(tusb->phy, tusb);
	ulpi_set_drvdata(ulpi, tusb);
	return 0;
}

__attribute__((used)) static void tusb1210_remove(struct ulpi *ulpi)
{
	struct tusb1210 *tusb = ulpi_get_drvdata(ulpi);

	ulpi_phy_destroy(ulpi, tusb->phy);
}

