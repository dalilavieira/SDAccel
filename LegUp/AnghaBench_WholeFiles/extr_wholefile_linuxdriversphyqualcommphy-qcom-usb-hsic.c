#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct ulpi {TYPE_1__ dev; } ;
struct qcom_usb_hsic_phy {struct pinctrl_state* phy; struct pinctrl_state* cal_sleep_clk; struct pinctrl_state* cal_clk; struct pinctrl_state* phy_clk; struct pinctrl_state* pctl; struct ulpi* ulpi; } ;
struct pinctrl_state {int dummy; } ;
struct phy_provider {int dummy; } ;
struct phy {int dummy; } ;
typedef  struct pinctrl_state clk ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct pinctrl_state*) ; 
 int /*<<< orphan*/  PINCTRL_STATE_DEFAULT ; 
 int PTR_ERR (struct pinctrl_state*) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 int /*<<< orphan*/  ULPI_CLR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ULPI_HSIC_CFG ; 
 int /*<<< orphan*/  ULPI_HSIC_IO_CAL ; 
 int /*<<< orphan*/  ULPI_IFC_CTRL ; 
 int ULPI_IFC_CTRL_AUTORESUME ; 
 int /*<<< orphan*/  ULPI_SET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct pinctrl_state*) ; 
 int clk_prepare_enable (struct pinctrl_state*) ; 
 struct pinctrl_state* devm_clk_get (TYPE_1__*,char*) ; 
 struct qcom_usb_hsic_phy* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (TYPE_1__*,int /*<<< orphan*/ ) ; 
 struct pinctrl_state* devm_phy_create (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct pinctrl_state* devm_pinctrl_get (TYPE_1__*) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 struct qcom_usb_hsic_phy* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct pinctrl_state*,struct qcom_usb_hsic_phy*) ; 
 struct pinctrl_state* pinctrl_lookup_state (struct pinctrl_state*,int /*<<< orphan*/ ) ; 
 int pinctrl_select_state (struct pinctrl_state*,struct pinctrl_state*) ; 
 int /*<<< orphan*/  qcom_usb_hsic_phy_ops ; 
 int /*<<< orphan*/  ulpi_set_drvdata (struct ulpi*,struct qcom_usb_hsic_phy*) ; 
 int ulpi_write (struct ulpi*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int qcom_usb_hsic_phy_power_on(struct phy *phy)
{
	struct qcom_usb_hsic_phy *uphy = phy_get_drvdata(phy);
	struct ulpi *ulpi = uphy->ulpi;
	struct pinctrl_state *pins_default;
	int ret;

	ret = clk_prepare_enable(uphy->phy_clk);
	if (ret)
		return ret;

	ret = clk_prepare_enable(uphy->cal_clk);
	if (ret)
		goto err_cal;

	ret = clk_prepare_enable(uphy->cal_sleep_clk);
	if (ret)
		goto err_sleep;

	/* Set periodic calibration interval to ~2.048sec in HSIC_IO_CAL_REG */
	ret = ulpi_write(ulpi, ULPI_HSIC_IO_CAL, 0xff);
	if (ret)
		goto err_ulpi;

	/* Enable periodic IO calibration in HSIC_CFG register */
	ret = ulpi_write(ulpi, ULPI_HSIC_CFG, 0xa8);
	if (ret)
		goto err_ulpi;

	/* Configure pins for HSIC functionality */
	pins_default = pinctrl_lookup_state(uphy->pctl, PINCTRL_STATE_DEFAULT);
	if (IS_ERR(pins_default))
		return PTR_ERR(pins_default);

	ret = pinctrl_select_state(uphy->pctl, pins_default);
	if (ret)
		goto err_ulpi;

	 /* Enable HSIC mode in HSIC_CFG register */
	ret = ulpi_write(ulpi, ULPI_SET(ULPI_HSIC_CFG), 0x01);
	if (ret)
		goto err_ulpi;

	/* Disable auto-resume */
	ret = ulpi_write(ulpi, ULPI_CLR(ULPI_IFC_CTRL),
			 ULPI_IFC_CTRL_AUTORESUME);
	if (ret)
		goto err_ulpi;

	return ret;
err_ulpi:
	clk_disable_unprepare(uphy->cal_sleep_clk);
err_sleep:
	clk_disable_unprepare(uphy->cal_clk);
err_cal:
	clk_disable_unprepare(uphy->phy_clk);
	return ret;
}

__attribute__((used)) static int qcom_usb_hsic_phy_power_off(struct phy *phy)
{
	struct qcom_usb_hsic_phy *uphy = phy_get_drvdata(phy);

	clk_disable_unprepare(uphy->cal_sleep_clk);
	clk_disable_unprepare(uphy->cal_clk);
	clk_disable_unprepare(uphy->phy_clk);

	return 0;
}

__attribute__((used)) static int qcom_usb_hsic_phy_probe(struct ulpi *ulpi)
{
	struct qcom_usb_hsic_phy *uphy;
	struct phy_provider *p;
	struct clk *clk;

	uphy = devm_kzalloc(&ulpi->dev, sizeof(*uphy), GFP_KERNEL);
	if (!uphy)
		return -ENOMEM;
	ulpi_set_drvdata(ulpi, uphy);

	uphy->ulpi = ulpi;
	uphy->pctl = devm_pinctrl_get(&ulpi->dev);
	if (IS_ERR(uphy->pctl))
		return PTR_ERR(uphy->pctl);

	uphy->phy_clk = clk = devm_clk_get(&ulpi->dev, "phy");
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	uphy->cal_clk = clk = devm_clk_get(&ulpi->dev, "cal");
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	uphy->cal_sleep_clk = clk = devm_clk_get(&ulpi->dev, "cal_sleep");
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	uphy->phy = devm_phy_create(&ulpi->dev, ulpi->dev.of_node,
				    &qcom_usb_hsic_phy_ops);
	if (IS_ERR(uphy->phy))
		return PTR_ERR(uphy->phy);
	phy_set_drvdata(uphy->phy, uphy);

	p = devm_of_phy_provider_register(&ulpi->dev, of_phy_simple_xlate);
	return PTR_ERR_OR_ZERO(p);
}

