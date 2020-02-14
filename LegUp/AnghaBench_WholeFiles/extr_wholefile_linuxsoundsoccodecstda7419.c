#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct tda7419_vol_control {scalar_t__ reg; scalar_t__ rreg; int min; unsigned int mask; int thresh; unsigned int invert; int /*<<< orphan*/  max; } ;
struct tda7419_data {int /*<<< orphan*/  regmap; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_9__ {int* value; } ;
struct TYPE_10__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_7__ {int min; int /*<<< orphan*/  max; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  def; int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_5__*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int abs (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct tda7419_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tda7419_data*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int snd_soc_component_read (struct snd_soc_component*,unsigned int,int*) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,unsigned int,unsigned int,int) ; 
 int /*<<< orphan*/  tda7419_component_driver ; 
 int /*<<< orphan*/  tda7419_regmap_config ; 
 TYPE_5__* tda7419_regmap_defaults ; 

__attribute__((used)) static bool tda7419_readable_reg(struct device *dev, unsigned int reg)
{
	return false;
}

__attribute__((used)) static inline bool tda7419_vol_is_stereo(struct tda7419_vol_control *tvc)
{
	if (tvc->reg == tvc->rreg)
		return false;

	return true;
}

__attribute__((used)) static int tda7419_vol_info(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_info *uinfo)
{
	struct tda7419_vol_control *tvc =
		(struct tda7419_vol_control *)kcontrol->private_value;

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = tda7419_vol_is_stereo(tvc) ? 2 : 1;
	uinfo->value.integer.min = tvc->min;
	uinfo->value.integer.max = tvc->max;

	return 0;
}

__attribute__((used)) static inline int tda7419_vol_get_value(int val, unsigned int mask,
					int min, int thresh,
					unsigned int invert)
{
	val &= mask;
	if (val < thresh) {
		if (invert)
			val = 0 - val;
	} else if (val > thresh) {
		if (invert)
			val = val - thresh;
		else
			val = thresh - val;
	}

	if (val < min)
		val = min;

	return val;
}

__attribute__((used)) static int tda7419_vol_get(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
	struct tda7419_vol_control *tvc =
		(struct tda7419_vol_control *)kcontrol->private_value;
	unsigned int reg = tvc->reg;
	unsigned int rreg = tvc->rreg;
	unsigned int mask = tvc->mask;
	int min = tvc->min;
	int thresh = tvc->thresh;
	unsigned int invert = tvc->invert;
	int val;
	int ret;

	ret = snd_soc_component_read(component, reg, &val);
	if (ret < 0)
		return ret;
	ucontrol->value.integer.value[0] =
		tda7419_vol_get_value(val, mask, min, thresh, invert);

	if (tda7419_vol_is_stereo(tvc)) {
		ret = snd_soc_component_read(component, rreg, &val);
		if (ret < 0)
			return ret;
		ucontrol->value.integer.value[1] =
			tda7419_vol_get_value(val, mask, min, thresh, invert);
	}

	return 0;
}

__attribute__((used)) static inline int tda7419_vol_put_value(int val, int thresh,
					unsigned int invert)
{
	if (val < 0) {
		if (invert)
			val = abs(val);
		else
			val = thresh - val;
	} else if ((val > 0) && invert) {
		val += thresh;
	}

	return val;
}

__attribute__((used)) static int tda7419_vol_put(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component =
		snd_kcontrol_chip(kcontrol);
	struct tda7419_vol_control *tvc =
		(struct tda7419_vol_control *)kcontrol->private_value;
	unsigned int reg = tvc->reg;
	unsigned int rreg = tvc->rreg;
	unsigned int mask = tvc->mask;
	int thresh = tvc->thresh;
	unsigned int invert = tvc->invert;
	int val;
	int ret;

	val = tda7419_vol_put_value(ucontrol->value.integer.value[0],
				    thresh, invert);
	ret = snd_soc_component_update_bits(component, reg,
					    mask, val);
	if (ret < 0)
		return ret;

	if (tda7419_vol_is_stereo(tvc)) {
		val = tda7419_vol_put_value(ucontrol->value.integer.value[1],
					    thresh, invert);
		ret = snd_soc_component_update_bits(component, rreg,
						    mask, val);
	}

	return ret;
}

__attribute__((used)) static int tda7419_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	struct tda7419_data *tda7419;
	int i, ret;

	tda7419 = devm_kzalloc(&i2c->dev,
			       sizeof(struct tda7419_data),
			       GFP_KERNEL);
	if (tda7419 == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, tda7419);

	tda7419->regmap = devm_regmap_init_i2c(i2c, &tda7419_regmap_config);
	if (IS_ERR(tda7419->regmap)) {
		ret = PTR_ERR(tda7419->regmap);
		dev_err(&i2c->dev, "error initializing regmap: %d\n",
				ret);
		return ret;
	}

	/*
	 * Reset registers to power-on defaults. The part does not provide a
	 * soft-reset function and the registers are not readable. This ensures
	 * that the cache matches register contents even if the registers have
	 * been previously initialized and not power cycled before probe.
	 */
	for (i = 0; i < ARRAY_SIZE(tda7419_regmap_defaults); i++)
		regmap_write(tda7419->regmap,
			     tda7419_regmap_defaults[i].reg,
			     tda7419_regmap_defaults[i].def);

	ret = devm_snd_soc_register_component(&i2c->dev,
		&tda7419_component_driver, NULL, 0);
	if (ret < 0) {
		dev_err(&i2c->dev, "error registering component: %d\n",
				ret);
	}

	return ret;
}

