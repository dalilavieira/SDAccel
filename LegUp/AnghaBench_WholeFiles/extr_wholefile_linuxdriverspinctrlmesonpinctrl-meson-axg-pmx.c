#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct pinctrl_gpio_range {int dummy; } ;
struct pinctrl_dev {int dummy; } ;
struct meson_pmx_group {int num_pins; unsigned int* pins; int /*<<< orphan*/  name; scalar_t__ data; } ;
struct meson_pmx_func {int /*<<< orphan*/  name; } ;
struct meson_pmx_bank {unsigned int first; unsigned int last; int reg; int offset; } ;
struct meson_pmx_axg_data {unsigned int func; } ;
struct meson_pinctrl {int /*<<< orphan*/  dev; TYPE_1__* data; int /*<<< orphan*/  reg_mux; } ;
struct meson_axg_pmx_data {int num_pmx_banks; struct meson_pmx_bank* pmx_banks; } ;
struct TYPE_2__ {struct meson_pmx_group* groups; struct meson_pmx_func* funcs; struct meson_axg_pmx_data* pmx_data; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct meson_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int,unsigned int) ; 

__attribute__((used)) static int meson_axg_pmx_get_bank(struct meson_pinctrl *pc,
			unsigned int pin,
			struct meson_pmx_bank **bank)
{
	int i;
	struct meson_axg_pmx_data *pmx = pc->data->pmx_data;

	for (i = 0; i < pmx->num_pmx_banks; i++)
		if (pin >= pmx->pmx_banks[i].first &&
				pin <= pmx->pmx_banks[i].last) {
			*bank = &pmx->pmx_banks[i];
			return 0;
		}

	return -EINVAL;
}

__attribute__((used)) static int meson_pmx_calc_reg_and_offset(struct meson_pmx_bank *bank,
			unsigned int pin, unsigned int *reg,
			unsigned int *offset)
{
	int shift;

	shift = pin - bank->first;

	*reg = bank->reg + (bank->offset + (shift << 2)) / 32;
	*offset = (bank->offset + (shift << 2)) % 32;

	return 0;
}

__attribute__((used)) static int meson_axg_pmx_update_function(struct meson_pinctrl *pc,
			unsigned int pin, unsigned int func)
{
	int ret;
	int reg;
	int offset;
	struct meson_pmx_bank *bank;

	ret = meson_axg_pmx_get_bank(pc, pin, &bank);
	if (ret)
		return ret;

	meson_pmx_calc_reg_and_offset(bank, pin, &reg, &offset);

	ret = regmap_update_bits(pc->reg_mux, reg << 2,
		0xf << offset, (func & 0xf) << offset);

	return ret;
}

__attribute__((used)) static int meson_axg_pmx_set_mux(struct pinctrl_dev *pcdev,
			unsigned int func_num, unsigned int group_num)
{
	int i;
	int ret;
	struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
	struct meson_pmx_func *func = &pc->data->funcs[func_num];
	struct meson_pmx_group *group = &pc->data->groups[group_num];
	struct meson_pmx_axg_data *pmx_data =
		(struct meson_pmx_axg_data *)group->data;

	dev_dbg(pc->dev, "enable function %s, group %s\n", func->name,
		group->name);

	for (i = 0; i < group->num_pins; i++) {
		ret = meson_axg_pmx_update_function(pc, group->pins[i],
			pmx_data->func);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int meson_axg_pmx_request_gpio(struct pinctrl_dev *pcdev,
			struct pinctrl_gpio_range *range, unsigned int offset)
{
	struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);

	return meson_axg_pmx_update_function(pc, offset, 0);
}

