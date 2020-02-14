#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct snd_kcontrol_new {int /*<<< orphan*/  name; } ;
struct snd_kcontrol {unsigned int private_value; struct oxygen* private_data; } ;
struct TYPE_9__ {scalar_t__* item; } ;
struct TYPE_8__ {unsigned int* value; } ;
struct TYPE_10__ {TYPE_4__ enumerated; TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_6__ {int min; int max; } ;
struct TYPE_7__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; void* type; } ;
struct oxygen {int /*<<< orphan*/  card; int /*<<< orphan*/  mutex; struct dg* model_data; } ;
struct dg {int* cs4245_shadow; scalar_t__ output_sel; char** input_vol; unsigned int input_sel; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 scalar_t__ CAPTURE_SRC_FP_MIC ; 
 scalar_t__ CAPTURE_SRC_LINE ; 
 scalar_t__ CAPTURE_SRC_MIC ; 
 size_t CS4245_ADC_CTRL ; 
 size_t CS4245_ANALOG_IN ; 
 int CS4245_A_OUT_SEL_DAC ; 
 int CS4245_A_OUT_SEL_MASK ; 
 size_t CS4245_DAC_A_CTRL ; 
 size_t CS4245_DAC_B_CTRL ; 
 size_t CS4245_DAC_CTRL_1 ; 
 int CS4245_HPF_FREEZE ; 
 int CS4245_MUTE_DAC ; 
 size_t CS4245_PGA_A_CTRL ; 
 size_t CS4245_PGA_B_CTRL ; 
 char CS4245_SEL_INPUT_1 ; 
 char CS4245_SEL_INPUT_2 ; 
 char CS4245_SEL_INPUT_4 ; 
 char CS4245_SEL_MASK ; 
 size_t CS4245_SIGNAL_SEL ; 
 int EINVAL ; 
 int GPIO_HP_REAR ; 
 unsigned int OXYGEN_GPIO_DATA ; 
 scalar_t__ PLAYBACK_DST_HP ; 
 scalar_t__ PLAYBACK_DST_HP_FP ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int cs4245_write_spi (struct oxygen*,size_t) ; 
 int /*<<< orphan*/ * dg_controls ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  oxygen_update_dac_routing (struct oxygen*) ; 
 int /*<<< orphan*/  oxygen_write16_masked (struct oxygen*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write32_masked (struct oxygen*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write8_masked (struct oxygen*,unsigned int,int,int) ; 
 int /*<<< orphan*/  oxygen_write_ac97_masked (struct oxygen*,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const* const*) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct oxygen*) ; 
 int /*<<< orphan*/  strncmp (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static inline void oxygen_set_bits8(struct oxygen *chip,
				    unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits16(struct oxygen *chip,
				     unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits32(struct oxygen *chip,
				     unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_clear_bits8(struct oxygen *chip,
				      unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits16(struct oxygen *chip,
				       unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits32(struct oxygen *chip,
				       unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_ac97_set_bits(struct oxygen *chip, unsigned int codec,
					unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, value, value);
}

__attribute__((used)) static inline void oxygen_ac97_clear_bits(struct oxygen *chip,
					  unsigned int codec,
					  unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, 0, value);
}

__attribute__((used)) static int output_select_apply(struct oxygen *chip)
{
	struct dg *data = chip->model_data;

	data->cs4245_shadow[CS4245_SIGNAL_SEL] &= ~CS4245_A_OUT_SEL_MASK;
	if (data->output_sel == PLAYBACK_DST_HP) {
		/* mute FP (aux output) amplifier, switch rear jack to CS4245 */
		oxygen_set_bits8(chip, OXYGEN_GPIO_DATA, GPIO_HP_REAR);
	} else if (data->output_sel == PLAYBACK_DST_HP_FP) {
		/*
		 * Unmute FP amplifier, switch rear jack to CS4361;
		 * I2S channels 2,3,4 should be inactive.
		 */
		oxygen_clear_bits8(chip, OXYGEN_GPIO_DATA, GPIO_HP_REAR);
		data->cs4245_shadow[CS4245_SIGNAL_SEL] |= CS4245_A_OUT_SEL_DAC;
	} else {
		/*
		 * 2.0, 4.0, 5.1: switch to CS4361, mute FP amp.,
		 * and change playback routing.
		 */
		oxygen_clear_bits8(chip, OXYGEN_GPIO_DATA, GPIO_HP_REAR);
	}
	return cs4245_write_spi(chip, CS4245_SIGNAL_SEL);
}

__attribute__((used)) static int output_select_info(struct snd_kcontrol *ctl,
			      struct snd_ctl_elem_info *info)
{
	static const char *const names[3] = {
		"Stereo Headphones",
		"Stereo Headphones FP",
		"Multichannel",
	};

	return snd_ctl_enum_info(info, 1, 3, names);
}

__attribute__((used)) static int output_select_get(struct snd_kcontrol *ctl,
			     struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;

	mutex_lock(&chip->mutex);
	value->value.enumerated.item[0] = data->output_sel;
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int output_select_put(struct snd_kcontrol *ctl,
			     struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	unsigned int new = value->value.enumerated.item[0];
	int changed = 0;
	int ret;

	mutex_lock(&chip->mutex);
	if (data->output_sel != new) {
		data->output_sel = new;
		ret = output_select_apply(chip);
		changed = ret >= 0 ? 1 : ret;
		oxygen_update_dac_routing(chip);
	}
	mutex_unlock(&chip->mutex);

	return changed;
}

__attribute__((used)) static int hp_stereo_volume_info(struct snd_kcontrol *ctl,
				struct snd_ctl_elem_info *info)
{
	info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	info->count = 2;
	info->value.integer.min = 0;
	info->value.integer.max = 255;
	return 0;
}

__attribute__((used)) static int hp_stereo_volume_get(struct snd_kcontrol *ctl,
				struct snd_ctl_elem_value *val)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	unsigned int tmp;

	mutex_lock(&chip->mutex);
	tmp = (~data->cs4245_shadow[CS4245_DAC_A_CTRL]) & 255;
	val->value.integer.value[0] = tmp;
	tmp = (~data->cs4245_shadow[CS4245_DAC_B_CTRL]) & 255;
	val->value.integer.value[1] = tmp;
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int hp_stereo_volume_put(struct snd_kcontrol *ctl,
				struct snd_ctl_elem_value *val)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	int ret;
	int changed = 0;
	long new1 = val->value.integer.value[0];
	long new2 = val->value.integer.value[1];

	if ((new1 > 255) || (new1 < 0) || (new2 > 255) || (new2 < 0))
		return -EINVAL;

	mutex_lock(&chip->mutex);
	if ((data->cs4245_shadow[CS4245_DAC_A_CTRL] != ~new1) ||
	    (data->cs4245_shadow[CS4245_DAC_B_CTRL] != ~new2)) {
		data->cs4245_shadow[CS4245_DAC_A_CTRL] = ~new1;
		data->cs4245_shadow[CS4245_DAC_B_CTRL] = ~new2;
		ret = cs4245_write_spi(chip, CS4245_DAC_A_CTRL);
		if (ret >= 0)
			ret = cs4245_write_spi(chip, CS4245_DAC_B_CTRL);
		changed = ret >= 0 ? 1 : ret;
	}
	mutex_unlock(&chip->mutex);

	return changed;
}

__attribute__((used)) static int hp_mute_get(struct snd_kcontrol *ctl,
			struct snd_ctl_elem_value *val)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;

	mutex_lock(&chip->mutex);
	val->value.integer.value[0] =
		!(data->cs4245_shadow[CS4245_DAC_CTRL_1] & CS4245_MUTE_DAC);
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int hp_mute_put(struct snd_kcontrol *ctl,
			struct snd_ctl_elem_value *val)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	int ret;
	int changed;

	if (val->value.integer.value[0] > 1)
		return -EINVAL;
	mutex_lock(&chip->mutex);
	data->cs4245_shadow[CS4245_DAC_CTRL_1] &= ~CS4245_MUTE_DAC;
	data->cs4245_shadow[CS4245_DAC_CTRL_1] |=
		(~val->value.integer.value[0] << 2) & CS4245_MUTE_DAC;
	ret = cs4245_write_spi(chip, CS4245_DAC_CTRL_1);
	changed = ret >= 0 ? 1 : ret;
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int input_volume_apply(struct oxygen *chip, char left, char right)
{
	struct dg *data = chip->model_data;
	int ret;

	data->cs4245_shadow[CS4245_PGA_A_CTRL] = left;
	data->cs4245_shadow[CS4245_PGA_B_CTRL] = right;
	ret = cs4245_write_spi(chip, CS4245_PGA_A_CTRL);
	if (ret < 0)
		return ret;
	return cs4245_write_spi(chip, CS4245_PGA_B_CTRL);
}

__attribute__((used)) static int input_vol_info(struct snd_kcontrol *ctl,
			  struct snd_ctl_elem_info *info)
{
	info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	info->count = 2;
	info->value.integer.min = 2 * -12;
	info->value.integer.max = 2 * 12;
	return 0;
}

__attribute__((used)) static int input_vol_get(struct snd_kcontrol *ctl,
			 struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	unsigned int idx = ctl->private_value;

	mutex_lock(&chip->mutex);
	value->value.integer.value[0] = data->input_vol[idx][0];
	value->value.integer.value[1] = data->input_vol[idx][1];
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int input_vol_put(struct snd_kcontrol *ctl,
			 struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	unsigned int idx = ctl->private_value;
	int changed = 0;
	int ret = 0;

	if (value->value.integer.value[0] < 2 * -12 ||
	    value->value.integer.value[0] > 2 * 12 ||
	    value->value.integer.value[1] < 2 * -12 ||
	    value->value.integer.value[1] > 2 * 12)
		return -EINVAL;
	mutex_lock(&chip->mutex);
	changed = data->input_vol[idx][0] != value->value.integer.value[0] ||
		  data->input_vol[idx][1] != value->value.integer.value[1];
	if (changed) {
		data->input_vol[idx][0] = value->value.integer.value[0];
		data->input_vol[idx][1] = value->value.integer.value[1];
		if (idx == data->input_sel) {
			ret = input_volume_apply(chip,
				data->input_vol[idx][0],
				data->input_vol[idx][1]);
		}
		changed = ret >= 0 ? 1 : ret;
	}
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int input_source_apply(struct oxygen *chip)
{
	struct dg *data = chip->model_data;

	data->cs4245_shadow[CS4245_ANALOG_IN] &= ~CS4245_SEL_MASK;
	if (data->input_sel == CAPTURE_SRC_FP_MIC)
		data->cs4245_shadow[CS4245_ANALOG_IN] |= CS4245_SEL_INPUT_2;
	else if (data->input_sel == CAPTURE_SRC_LINE)
		data->cs4245_shadow[CS4245_ANALOG_IN] |= CS4245_SEL_INPUT_4;
	else if (data->input_sel != CAPTURE_SRC_MIC)
		data->cs4245_shadow[CS4245_ANALOG_IN] |= CS4245_SEL_INPUT_1;
	return cs4245_write_spi(chip, CS4245_ANALOG_IN);
}

__attribute__((used)) static int input_sel_info(struct snd_kcontrol *ctl,
			  struct snd_ctl_elem_info *info)
{
	static const char *const names[4] = {
		"Mic", "Front Mic", "Line", "Aux"
	};

	return snd_ctl_enum_info(info, 1, 4, names);
}

__attribute__((used)) static int input_sel_get(struct snd_kcontrol *ctl,
			 struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;

	mutex_lock(&chip->mutex);
	value->value.enumerated.item[0] = data->input_sel;
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int input_sel_put(struct snd_kcontrol *ctl,
			 struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	int changed;
	int ret;

	if (value->value.enumerated.item[0] > 3)
		return -EINVAL;

	mutex_lock(&chip->mutex);
	changed = value->value.enumerated.item[0] != data->input_sel;
	if (changed) {
		data->input_sel = value->value.enumerated.item[0];

		ret = input_source_apply(chip);
		if (ret >= 0)
			ret = input_volume_apply(chip,
				data->input_vol[data->input_sel][0],
				data->input_vol[data->input_sel][1]);
		changed = ret >= 0 ? 1 : ret;
	}
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int hpf_info(struct snd_kcontrol *ctl, struct snd_ctl_elem_info *info)
{
	static const char *const names[2] = { "Active", "Frozen" };

	return snd_ctl_enum_info(info, 1, 2, names);
}

__attribute__((used)) static int hpf_get(struct snd_kcontrol *ctl, struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;

	value->value.enumerated.item[0] =
		!!(data->cs4245_shadow[CS4245_ADC_CTRL] & CS4245_HPF_FREEZE);
	return 0;
}

__attribute__((used)) static int hpf_put(struct snd_kcontrol *ctl, struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	struct dg *data = chip->model_data;
	u8 reg;
	int changed;

	mutex_lock(&chip->mutex);
	reg = data->cs4245_shadow[CS4245_ADC_CTRL] & ~CS4245_HPF_FREEZE;
	if (value->value.enumerated.item[0])
		reg |= CS4245_HPF_FREEZE;
	changed = reg != data->cs4245_shadow[CS4245_ADC_CTRL];
	if (changed) {
		data->cs4245_shadow[CS4245_ADC_CTRL] = reg;
		cs4245_write_spi(chip, CS4245_ADC_CTRL);
	}
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int dg_control_filter(struct snd_kcontrol_new *template)
{
	if (!strncmp(template->name, "Master Playback ", 16))
		return 1;
	return 0;
}

__attribute__((used)) static int dg_mixer_init(struct oxygen *chip)
{
	unsigned int i;
	int err;

	output_select_apply(chip);
	input_source_apply(chip);
	oxygen_update_dac_routing(chip);

	for (i = 0; i < ARRAY_SIZE(dg_controls); ++i) {
		err = snd_ctl_add(chip->card,
				  snd_ctl_new1(&dg_controls[i], chip));
		if (err < 0)
			return err;
	}

	return 0;
}

