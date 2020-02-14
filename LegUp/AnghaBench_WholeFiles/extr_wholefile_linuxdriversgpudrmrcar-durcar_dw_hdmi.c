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
struct rcar_hdmi_phy_params {unsigned long mpixelclock; int /*<<< orphan*/  div; int /*<<< orphan*/  curr_gmp; int /*<<< orphan*/  opmode_div; } ;
struct platform_device {int dummy; } ;
struct dw_hdmi_plat_data {int dummy; } ;
struct dw_hdmi {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct dw_hdmi*) ; 
 int PTR_ERR (struct dw_hdmi*) ; 
 int /*<<< orphan*/  RCAR_HDMI_PHY_OPMODE_PLLCFG ; 
 int /*<<< orphan*/  RCAR_HDMI_PHY_PLLCURRGMPCTRL ; 
 int /*<<< orphan*/  RCAR_HDMI_PHY_PLLDIVCTRL ; 
 int /*<<< orphan*/  dw_hdmi_phy_i2c_write (struct dw_hdmi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dw_hdmi* dw_hdmi_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dw_hdmi_remove (struct dw_hdmi*) ; 
 struct dw_hdmi* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct dw_hdmi*) ; 
 int /*<<< orphan*/  rcar_dw_hdmi_plat_data ; 
 struct rcar_hdmi_phy_params* rcar_hdmi_phy_params ; 

__attribute__((used)) static int rcar_hdmi_phy_configure(struct dw_hdmi *hdmi,
				   const struct dw_hdmi_plat_data *pdata,
				   unsigned long mpixelclock)
{
	const struct rcar_hdmi_phy_params *params = rcar_hdmi_phy_params;

	for (; params->mpixelclock != ~0UL; ++params) {
		if (mpixelclock <= params->mpixelclock)
			break;
	}

	if (params->mpixelclock == ~0UL)
		return -EINVAL;

	dw_hdmi_phy_i2c_write(hdmi, params->opmode_div,
			      RCAR_HDMI_PHY_OPMODE_PLLCFG);
	dw_hdmi_phy_i2c_write(hdmi, params->curr_gmp,
			      RCAR_HDMI_PHY_PLLCURRGMPCTRL);
	dw_hdmi_phy_i2c_write(hdmi, params->div, RCAR_HDMI_PHY_PLLDIVCTRL);

	return 0;
}

__attribute__((used)) static int rcar_dw_hdmi_probe(struct platform_device *pdev)
{
	struct dw_hdmi *hdmi;

	hdmi = dw_hdmi_probe(pdev, &rcar_dw_hdmi_plat_data);
	if (IS_ERR(hdmi))
		return PTR_ERR(hdmi);

	platform_set_drvdata(pdev, hdmi);

	return 0;
}

__attribute__((used)) static int rcar_dw_hdmi_remove(struct platform_device *pdev)
{
	struct dw_hdmi *hdmi = platform_get_drvdata(pdev);

	dw_hdmi_remove(hdmi);

	return 0;
}

