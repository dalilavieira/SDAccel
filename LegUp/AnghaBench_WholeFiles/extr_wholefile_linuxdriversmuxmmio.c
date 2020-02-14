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
struct regmap_field {int /*<<< orphan*/ * ops; struct mux_control* mux; } ;
struct regmap {int /*<<< orphan*/ * ops; struct mux_control* mux; } ;
struct reg_field {int reg; int msb; int lsb; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct mux_control {int states; int idle_state; struct regmap_field* chip; } ;
struct mux_chip {int /*<<< orphan*/ * ops; struct mux_control* mux; } ;
struct device_node {int /*<<< orphan*/  parent; } ;
typedef  int s32 ;

/* Variables and functions */
 int EINVAL ; 
 int GENMASK (int,int) ; 
 scalar_t__ IS_ERR (struct regmap_field*) ; 
 int MUX_IDLE_AS_IS ; 
 int PTR_ERR (struct regmap_field*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 struct regmap_field* devm_mux_chip_alloc (struct device*,int,int) ; 
 int devm_mux_chip_register (struct device*,struct regmap_field*) ; 
 struct regmap_field* devm_regmap_field_alloc (struct device*,struct regmap_field*,struct reg_field) ; 
 int ffs (int) ; 
 int fls (int) ; 
 struct regmap_field** mux_chip_priv (struct regmap_field*) ; 
 size_t mux_control_get_index (struct mux_control*) ; 
 int /*<<< orphan*/  mux_mmio_ops ; 
 int of_property_count_u32_elems (struct device_node*,char*) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,int*) ; 
 int regmap_field_write (struct regmap_field*,int) ; 
 struct regmap_field* syscon_node_to_regmap (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mux_mmio_set(struct mux_control *mux, int state)
{
	struct regmap_field **fields = mux_chip_priv(mux->chip);

	return regmap_field_write(fields[mux_control_get_index(mux)], state);
}

__attribute__((used)) static int mux_mmio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct regmap_field **fields;
	struct mux_chip *mux_chip;
	struct regmap *regmap;
	int num_fields;
	int ret;
	int i;

	regmap = syscon_node_to_regmap(np->parent);
	if (IS_ERR(regmap)) {
		ret = PTR_ERR(regmap);
		dev_err(dev, "failed to get regmap: %d\n", ret);
		return ret;
	}

	ret = of_property_count_u32_elems(np, "mux-reg-masks");
	if (ret == 0 || ret % 2)
		ret = -EINVAL;
	if (ret < 0) {
		dev_err(dev, "mux-reg-masks property missing or invalid: %d\n",
			ret);
		return ret;
	}
	num_fields = ret / 2;

	mux_chip = devm_mux_chip_alloc(dev, num_fields, num_fields *
				       sizeof(*fields));
	if (IS_ERR(mux_chip))
		return PTR_ERR(mux_chip);

	fields = mux_chip_priv(mux_chip);

	for (i = 0; i < num_fields; i++) {
		struct mux_control *mux = &mux_chip->mux[i];
		struct reg_field field;
		s32 idle_state = MUX_IDLE_AS_IS;
		u32 reg, mask;
		int bits;

		ret = of_property_read_u32_index(np, "mux-reg-masks",
						 2 * i, &reg);
		if (!ret)
			ret = of_property_read_u32_index(np, "mux-reg-masks",
							 2 * i + 1, &mask);
		if (ret < 0) {
			dev_err(dev, "bitfield %d: failed to read mux-reg-masks property: %d\n",
				i, ret);
			return ret;
		}

		field.reg = reg;
		field.msb = fls(mask) - 1;
		field.lsb = ffs(mask) - 1;

		if (mask != GENMASK(field.msb, field.lsb)) {
			dev_err(dev, "bitfield %d: invalid mask 0x%x\n",
				i, mask);
			return -EINVAL;
		}

		fields[i] = devm_regmap_field_alloc(dev, regmap, field);
		if (IS_ERR(fields[i])) {
			ret = PTR_ERR(fields[i]);
			dev_err(dev, "bitfield %d: failed allocate: %d\n",
				i, ret);
			return ret;
		}

		bits = 1 + field.msb - field.lsb;
		mux->states = 1 << bits;

		of_property_read_u32_index(np, "idle-states", i,
					   (u32 *)&idle_state);
		if (idle_state != MUX_IDLE_AS_IS) {
			if (idle_state < 0 || idle_state >= mux->states) {
				dev_err(dev, "bitfield: %d: out of range idle state %d\n",
					i, idle_state);
				return -EINVAL;
			}

			mux->idle_state = idle_state;
		}
	}

	mux_chip->ops = &mux_mmio_ops;

	return devm_mux_chip_register(dev, mux_chip);
}

