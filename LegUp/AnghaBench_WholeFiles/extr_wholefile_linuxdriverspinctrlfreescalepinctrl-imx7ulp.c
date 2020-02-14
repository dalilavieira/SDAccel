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
struct platform_device {int dummy; } ;
struct pinctrl_gpio_range {int dummy; } ;
struct pinctrl_dev {int dummy; } ;
struct imx_pinctrl {scalar_t__ base; struct imx_pin_reg* pin_regs; } ;
struct imx_pin_reg {int mux_reg; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;

/* Variables and functions */
 int BM_IBE_ENABLED ; 
 int BM_LK_ENABLED ; 
 int BM_OBE_ENABLED ; 
 int BM_PULL_ENABLED ; 
 int EINVAL ; 
 int PIN_CONFIG_BIAS_PULL_DOWN ; 
 int PIN_CONFIG_BIAS_PULL_UP ; 
 int /*<<< orphan*/  imx7ulp_pinctrl_info ; 
 int imx_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int pinconf_to_config_argument (unsigned long) ; 
 int pinconf_to_config_param (unsigned long) ; 
 struct imx_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void imx7ulp_cfg_params_fixup(unsigned long *configs,
				    unsigned int num_configs,
				    u32 *raw_config)
{
	enum pin_config_param param;
	u32 param_val;
	int i;

	/* lock field disabled */
	*raw_config &= ~BM_LK_ENABLED;

	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		param_val = pinconf_to_config_argument(configs[i]);

		if ((param == PIN_CONFIG_BIAS_PULL_UP) ||
		    (param == PIN_CONFIG_BIAS_PULL_DOWN)) {
			/* pull enabled */
			*raw_config |= BM_PULL_ENABLED;

			return;
		}
	}
}

__attribute__((used)) static int imx7ulp_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
					  struct pinctrl_gpio_range *range,
					  unsigned offset, bool input)
{
	struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
	const struct imx_pin_reg *pin_reg;
	u32 reg;

	pin_reg = &ipctl->pin_regs[offset];
	if (pin_reg->mux_reg == -1)
		return -EINVAL;

	reg = readl(ipctl->base + pin_reg->mux_reg);
	if (input)
		reg = (reg & ~BM_OBE_ENABLED) | BM_IBE_ENABLED;
	else
		reg = (reg & ~BM_IBE_ENABLED) | BM_OBE_ENABLED;
	writel(reg, ipctl->base + pin_reg->mux_reg);

	return 0;
}

__attribute__((used)) static int imx7ulp_pinctrl_probe(struct platform_device *pdev)
{
	return imx_pinctrl_probe(pdev, &imx7ulp_pinctrl_info);
}

