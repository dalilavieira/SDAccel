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
struct meson_pinctrl {int /*<<< orphan*/  reg_mux; int /*<<< orphan*/  dev; TYPE_1__* data; } ;
struct meson8_pmx_data {int reg; int /*<<< orphan*/  bit; scalar_t__ is_gpio; } ;
struct TYPE_2__ {int num_groups; struct meson_pmx_group* groups; struct meson_pmx_func* funcs; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct meson_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void meson8_pmx_disable_other_groups(struct meson_pinctrl *pc,
					    unsigned int pin, int sel_group)
{
	struct meson_pmx_group *group;
	struct meson8_pmx_data *pmx_data;
	int i, j;

	for (i = 0; i < pc->data->num_groups; i++) {
		group = &pc->data->groups[i];
		pmx_data = (struct meson8_pmx_data *)group->data;
		if (pmx_data->is_gpio || i == sel_group)
			continue;

		for (j = 0; j < group->num_pins; j++) {
			if (group->pins[j] == pin) {
				/* We have found a group using the pin */
				regmap_update_bits(pc->reg_mux,
						   pmx_data->reg * 4,
						   BIT(pmx_data->bit), 0);
			}
		}
	}
}

__attribute__((used)) static int meson8_pmx_set_mux(struct pinctrl_dev *pcdev, unsigned func_num,
			      unsigned group_num)
{
	struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
	struct meson_pmx_func *func = &pc->data->funcs[func_num];
	struct meson_pmx_group *group = &pc->data->groups[group_num];
	struct meson8_pmx_data *pmx_data =
		(struct meson8_pmx_data *)group->data;
	int i, ret = 0;

	dev_dbg(pc->dev, "enable function %s, group %s\n", func->name,
		group->name);

	/*
	 * Disable groups using the same pin.
	 * The selected group is not disabled to avoid glitches.
	 */
	for (i = 0; i < group->num_pins; i++)
		meson8_pmx_disable_other_groups(pc, group->pins[i], group_num);

	/* Function 0 (GPIO) doesn't need any additional setting */
	if (func_num)
		ret = regmap_update_bits(pc->reg_mux, pmx_data->reg * 4,
					 BIT(pmx_data->bit),
					 BIT(pmx_data->bit));

	return ret;
}

__attribute__((used)) static int meson8_pmx_request_gpio(struct pinctrl_dev *pcdev,
				   struct pinctrl_gpio_range *range,
				   unsigned offset)
{
	struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);

	meson8_pmx_disable_other_groups(pc, offset, -1);

	return 0;
}

