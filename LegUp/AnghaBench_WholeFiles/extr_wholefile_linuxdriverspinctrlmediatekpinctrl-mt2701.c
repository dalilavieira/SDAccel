#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct regmap {int dummy; } ;
struct platform_device {int dummy; } ;
struct mtk_eint {int dummy; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;
struct TYPE_8__ {unsigned int pin; int /*<<< orphan*/  offset; int /*<<< orphan*/  bit; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_1__*) ; 
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int PIN_CONFIG_INPUT_ENABLE ; 
 int PIN_CONFIG_INPUT_SCHMITT_ENABLE ; 
 TYPE_1__* mt2701_ies_set ; 
 int /*<<< orphan*/  mt2701_pinctrl_data ; 
 TYPE_1__* mt2701_smt_set ; 
 TYPE_1__* mt2701_spec_pinmux ; 
 TYPE_1__* mt2701_spec_pupd ; 
 int mtk_pconf_spec_set_ies_smt_range (struct regmap*,TYPE_1__*,unsigned int,unsigned int,unsigned char,int) ; 
 int mtk_pctrl_init (struct platform_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int mtk_pctrl_spec_pull_set_samereg (struct regmap*,TYPE_1__*,unsigned int,unsigned int,unsigned char,int,unsigned int) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 

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

__attribute__((used)) static int mt2701_spec_pull_set(struct regmap *regmap, unsigned int pin,
		unsigned char align, bool isup, unsigned int r1r0)
{
	return mtk_pctrl_spec_pull_set_samereg(regmap, mt2701_spec_pupd,
		ARRAY_SIZE(mt2701_spec_pupd), pin, align, isup, r1r0);
}

__attribute__((used)) static int mt2701_ies_smt_set(struct regmap *regmap, unsigned int pin,
		unsigned char align, int value, enum pin_config_param arg)
{
	if (arg == PIN_CONFIG_INPUT_ENABLE)
		return mtk_pconf_spec_set_ies_smt_range(regmap, mt2701_ies_set,
			ARRAY_SIZE(mt2701_ies_set), pin, align, value);
	else if (arg == PIN_CONFIG_INPUT_SCHMITT_ENABLE)
		return mtk_pconf_spec_set_ies_smt_range(regmap, mt2701_smt_set,
			ARRAY_SIZE(mt2701_smt_set), pin, align, value);
	return -EINVAL;
}

__attribute__((used)) static void mt2701_spec_pinmux_set(struct regmap *reg, unsigned int pin,
			unsigned int mode)
{
	unsigned int i, value, mask;
	unsigned int info_num = ARRAY_SIZE(mt2701_spec_pinmux);
	unsigned int spec_flag;

	for (i = 0; i < info_num; i++) {
		if (pin == mt2701_spec_pinmux[i].pin)
			break;
	}

	if (i == info_num)
		return;

	spec_flag = (mode >> 3);
	mask = BIT(mt2701_spec_pinmux[i].bit);
	if (!spec_flag)
		value = mask;
	else
		value = 0;
	regmap_update_bits(reg, mt2701_spec_pinmux[i].offset, mask, value);
}

__attribute__((used)) static void mt2701_spec_dir_set(unsigned int *reg_addr, unsigned int pin)
{
	if (pin > 175)
		*reg_addr += 0x10;
}

__attribute__((used)) static int mt2701_pinctrl_probe(struct platform_device *pdev)
{
	return mtk_pctrl_init(pdev, &mt2701_pinctrl_data, NULL);
}

