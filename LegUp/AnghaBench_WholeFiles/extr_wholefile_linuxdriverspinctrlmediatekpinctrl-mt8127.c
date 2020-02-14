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
struct regmap {int dummy; } ;
struct platform_device {int dummy; } ;
struct mtk_eint {int dummy; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int PIN_CONFIG_INPUT_ENABLE ; 
 int PIN_CONFIG_INPUT_SCHMITT_ENABLE ; 
 int /*<<< orphan*/  mt8127_ies_set ; 
 int /*<<< orphan*/  mt8127_pinctrl_data ; 
 int /*<<< orphan*/  mt8127_smt_set ; 
 int /*<<< orphan*/  mt8127_spec_pupd ; 
 int mtk_pconf_spec_set_ies_smt_range (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned char,int) ; 
 int mtk_pctrl_init (struct platform_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int mtk_pctrl_spec_pull_set_samereg (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned char,int,unsigned int) ; 

__attribute__((used)) static inline int mtk_eint_do_init(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mtk_eint_do_suspend(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mtk_eint_do_resume(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

int mtk_eint_set_debounce(struct mtk_eint *eint, unsigned long eint_n,
			  unsigned int debounce)
{
	return -EOPNOTSUPP;
}

int mtk_eint_find_irq(struct mtk_eint *eint, unsigned long eint_n)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static int mt8127_spec_pull_set(struct regmap *regmap, unsigned int pin,
		unsigned char align, bool isup, unsigned int r1r0)
{
	return mtk_pctrl_spec_pull_set_samereg(regmap, mt8127_spec_pupd,
		ARRAY_SIZE(mt8127_spec_pupd), pin, align, isup, r1r0);
}

__attribute__((used)) static int mt8127_ies_smt_set(struct regmap *regmap, unsigned int pin,
		unsigned char align, int value, enum pin_config_param arg)
{
	if (arg == PIN_CONFIG_INPUT_ENABLE)
		return mtk_pconf_spec_set_ies_smt_range(regmap, mt8127_ies_set,
			ARRAY_SIZE(mt8127_ies_set), pin, align, value);
	else if (arg == PIN_CONFIG_INPUT_SCHMITT_ENABLE)
		return mtk_pconf_spec_set_ies_smt_range(regmap, mt8127_smt_set,
			ARRAY_SIZE(mt8127_smt_set), pin, align, value);
	return -EINVAL;
}

__attribute__((used)) static int mt8127_pinctrl_probe(struct platform_device *pdev)
{
	return mtk_pctrl_init(pdev, &mt8127_pinctrl_data, NULL);
}

