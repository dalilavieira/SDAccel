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
typedef  int /*<<< orphan*/  u32 ;
struct reset_controller_dev {TYPE_1__* ops; } ;
struct qcom_reset_map {int /*<<< orphan*/  reg; int /*<<< orphan*/  bit; } ;
struct qcom_reset_controller {int /*<<< orphan*/  regmap; struct qcom_reset_map* reset_map; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* deassert ) (struct reset_controller_dev*,unsigned long) ;int /*<<< orphan*/  (* assert ) (struct reset_controller_dev*,unsigned long) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct reset_controller_dev*,unsigned long) ; 
 int /*<<< orphan*/  stub2 (struct reset_controller_dev*,unsigned long) ; 
 struct qcom_reset_controller* to_qcom_reset_controller (struct reset_controller_dev*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int qcom_reset(struct reset_controller_dev *rcdev, unsigned long id)
{
	rcdev->ops->assert(rcdev, id);
	udelay(1);
	rcdev->ops->deassert(rcdev, id);
	return 0;
}

__attribute__((used)) static int
qcom_reset_assert(struct reset_controller_dev *rcdev, unsigned long id)
{
	struct qcom_reset_controller *rst;
	const struct qcom_reset_map *map;
	u32 mask;

	rst = to_qcom_reset_controller(rcdev);
	map = &rst->reset_map[id];
	mask = BIT(map->bit);

	return regmap_update_bits(rst->regmap, map->reg, mask, mask);
}

__attribute__((used)) static int
qcom_reset_deassert(struct reset_controller_dev *rcdev, unsigned long id)
{
	struct qcom_reset_controller *rst;
	const struct qcom_reset_map *map;
	u32 mask;

	rst = to_qcom_reset_controller(rcdev);
	map = &rst->reset_map[id];
	mask = BIT(map->bit);

	return regmap_update_bits(rst->regmap, map->reg, mask, 0);
}

