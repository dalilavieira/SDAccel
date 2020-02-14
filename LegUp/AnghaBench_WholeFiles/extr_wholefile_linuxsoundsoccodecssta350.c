#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct sta350_priv {int* coef_shadow; unsigned int mclk; unsigned int format; void* regmap; TYPE_3__* supplies; void* gpiod_power_down; void* gpiod_nreset; struct sta350_platform_data* pdata; int /*<<< orphan*/  coeff_lock; } ;
struct sta350_platform_data {int ffx_power_output_mode; int drop_compensation_ns; int output_conf; int ch1_output_mapping; int ch2_output_mapping; int ch3_output_mapping; int powerdown_delay_divider; scalar_t__ powerdown_master_vol; scalar_t__ noise_shape_dc_cut; scalar_t__ bridge_immediate_off; scalar_t__ activate_mute_output; scalar_t__ invalid_input_detect_mute; scalar_t__ distortion_compensation; scalar_t__ odd_pwm_speed_mode; scalar_t__ am_reduction_mode; scalar_t__ max_power_correction; scalar_t__ max_power_use_mpcc; scalar_t__ oc_warning_adjustment; int /*<<< orphan*/  fault_detect_recovery; int /*<<< orphan*/  thermal_warning_adjustment; int /*<<< orphan*/  thermal_warning_recovery; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_8__ {unsigned int* data; } ;
struct TYPE_9__ {TYPE_1__ bytes; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct snd_ctl_elem_info {int count; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_10__ {unsigned int fs; int ir; int /*<<< orphan*/  supply; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_BYTES ; 
#define  SND_SOC_BIAS_OFF 137 
#define  SND_SOC_BIAS_ON 136 
#define  SND_SOC_BIAS_PREPARE 135 
#define  SND_SOC_BIAS_STANDBY 134 
#define  SND_SOC_DAIFMT_CBS_CFS 133 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 scalar_t__ STA350_B1CF1 ; 
 scalar_t__ STA350_B1CF2 ; 
 scalar_t__ STA350_B1CF3 ; 
 int /*<<< orphan*/  STA350_C1CFG ; 
 int /*<<< orphan*/  STA350_C2CFG ; 
 int /*<<< orphan*/  STA350_C3CFG ; 
 scalar_t__ STA350_CFADDR2 ; 
 scalar_t__ STA350_CFUD ; 
 int STA350_COEF_COUNT ; 
 int /*<<< orphan*/  STA350_CONFA ; 
 int STA350_CONFA_FDRB ; 
 int STA350_CONFA_IR_MASK ; 
 int STA350_CONFA_IR_SHIFT ; 
 int STA350_CONFA_MCS_MASK ; 
 int STA350_CONFA_MCS_SHIFT ; 
 int STA350_CONFA_TWAB ; 
 int STA350_CONFA_TWRB ; 
 int /*<<< orphan*/  STA350_CONFB ; 
 unsigned int STA350_CONFB_C1IM ; 
 unsigned int STA350_CONFB_C2IM ; 
 int STA350_CONFB_SAIFB ; 
 int STA350_CONFB_SAI_MASK ; 
 int /*<<< orphan*/  STA350_CONFC ; 
 int STA350_CONFC_CSZ_MASK ; 
 int STA350_CONFC_CSZ_SHIFT ; 
 int STA350_CONFC_OCRB ; 
 int STA350_CONFC_OM_MASK ; 
 int STA350_CONFC_OM_SHIFT ; 
 int /*<<< orphan*/  STA350_CONFE ; 
 int STA350_CONFE_AME ; 
 int STA350_CONFE_DCCV ; 
 int STA350_CONFE_MPC ; 
 int STA350_CONFE_MPCV ; 
 int STA350_CONFE_PWMS ; 
 int /*<<< orphan*/  STA350_CONFF ; 
 int STA350_CONFF_EAPD ; 
 int STA350_CONFF_IDE ; 
 int STA350_CONFF_OCFG_MASK ; 
 int STA350_CONFF_OCFG_SHIFT ; 
 int STA350_CONFF_PWDN ; 
 int STA350_CxCFG_OM_MASK ; 
 int STA350_CxCFG_OM_SHIFT ; 
 int /*<<< orphan*/  STA350_MISC1 ; 
 int STA350_MISC1_BRIDGOFF ; 
 int STA350_MISC1_CPWMEN ; 
 int STA350_MISC1_NSHHPEN ; 
 int STA350_MISC1_RPDNEN ; 
 int /*<<< orphan*/  STA350_MISC2 ; 
 int STA350_MISC2_PNDLSL_MASK ; 
 int STA350_MISC2_PNDLSL_SHIFT ; 
 scalar_t__ STA350_MMUTE ; 
 unsigned int STA350_MMUTE_MMUTE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct sta350_platform_data* dev_get_platdata (struct device*) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct sta350_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_3__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct sta350_priv*) ; 
 TYPE_3__* interpolation_ratios ; 
 unsigned int** mcs_ratio_table ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int regcache_sync (void*) ; 
 int /*<<< orphan*/  regmap_read (void*,scalar_t__,unsigned int*) ; 
 int regmap_update_bits (void*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (void*,scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_3__*) ; 
 int regulator_bulk_enable (int,TYPE_3__*) ; 
 int /*<<< orphan*/  snd_soc_component_force_bias_level (struct snd_soc_component*,int const) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct sta350_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  sta350_component ; 
 int /*<<< orphan*/  sta350_dai ; 
 int /*<<< orphan*/  sta350_regmap ; 
 int /*<<< orphan*/ * sta350_supply_names ; 

__attribute__((used)) static int sta350_coefficient_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info *uinfo)
{
	int numcoef = kcontrol->private_value >> 16;
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
	uinfo->count = 3 * numcoef;
	return 0;
}

__attribute__((used)) static int sta350_coefficient_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	int numcoef = kcontrol->private_value >> 16;
	int index = kcontrol->private_value & 0xffff;
	unsigned int cfud, val;
	int i, ret = 0;

	mutex_lock(&sta350->coeff_lock);

	/* preserve reserved bits in STA350_CFUD */
	regmap_read(sta350->regmap, STA350_CFUD, &cfud);
	cfud &= 0xf0;
	/*
	 * chip documentation does not say if the bits are self clearing,
	 * so do it explicitly
	 */
	regmap_write(sta350->regmap, STA350_CFUD, cfud);

	regmap_write(sta350->regmap, STA350_CFADDR2, index);
	if (numcoef == 1) {
		regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x04);
	} else if (numcoef == 5) {
		regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x08);
	} else {
		ret = -EINVAL;
		goto exit_unlock;
	}

	for (i = 0; i < 3 * numcoef; i++) {
		regmap_read(sta350->regmap, STA350_B1CF1 + i, &val);
		ucontrol->value.bytes.data[i] = val;
	}

exit_unlock:
	mutex_unlock(&sta350->coeff_lock);

	return ret;
}

__attribute__((used)) static int sta350_coefficient_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	int numcoef = kcontrol->private_value >> 16;
	int index = kcontrol->private_value & 0xffff;
	unsigned int cfud;
	int i;

	/* preserve reserved bits in STA350_CFUD */
	regmap_read(sta350->regmap, STA350_CFUD, &cfud);
	cfud &= 0xf0;
	/*
	 * chip documentation does not say if the bits are self clearing,
	 * so do it explicitly
	 */
	regmap_write(sta350->regmap, STA350_CFUD, cfud);

	regmap_write(sta350->regmap, STA350_CFADDR2, index);
	for (i = 0; i < numcoef && (index + i < STA350_COEF_COUNT); i++)
		sta350->coef_shadow[index + i] =
			  (ucontrol->value.bytes.data[3 * i] << 16)
			| (ucontrol->value.bytes.data[3 * i + 1] << 8)
			| (ucontrol->value.bytes.data[3 * i + 2]);
	for (i = 0; i < 3 * numcoef; i++)
		regmap_write(sta350->regmap, STA350_B1CF1 + i,
			     ucontrol->value.bytes.data[i]);
	if (numcoef == 1)
		regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x01);
	else if (numcoef == 5)
		regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x02);
	else
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int sta350_sync_coef_shadow(struct snd_soc_component *component)
{
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	unsigned int cfud;
	int i;

	/* preserve reserved bits in STA350_CFUD */
	regmap_read(sta350->regmap, STA350_CFUD, &cfud);
	cfud &= 0xf0;

	for (i = 0; i < STA350_COEF_COUNT; i++) {
		regmap_write(sta350->regmap, STA350_CFADDR2, i);
		regmap_write(sta350->regmap, STA350_B1CF1,
			     (sta350->coef_shadow[i] >> 16) & 0xff);
		regmap_write(sta350->regmap, STA350_B1CF2,
			     (sta350->coef_shadow[i] >> 8) & 0xff);
		regmap_write(sta350->regmap, STA350_B1CF3,
			     (sta350->coef_shadow[i]) & 0xff);
		/*
		 * chip documentation does not say if the bits are
		 * self-clearing, so do it explicitly
		 */
		regmap_write(sta350->regmap, STA350_CFUD, cfud);
		regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x01);
	}
	return 0;
}

__attribute__((used)) static int sta350_cache_sync(struct snd_soc_component *component)
{
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	unsigned int mute;
	int rc;

	/* mute during register sync */
	regmap_read(sta350->regmap, STA350_CFUD, &mute);
	regmap_write(sta350->regmap, STA350_MMUTE, mute | STA350_MMUTE_MMUTE);
	sta350_sync_coef_shadow(component);
	rc = regcache_sync(sta350->regmap);
	regmap_write(sta350->regmap, STA350_MMUTE, mute);
	return rc;
}

__attribute__((used)) static int sta350_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);

	dev_dbg(component->dev, "mclk=%u\n", freq);
	sta350->mclk = freq;

	return 0;
}

__attribute__((used)) static int sta350_set_dai_fmt(struct snd_soc_dai *codec_dai,
			      unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	unsigned int confb = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_RIGHT_J:
	case SND_SOC_DAIFMT_LEFT_J:
		sta350->format = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		confb |= STA350_CONFB_C2IM;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		confb |= STA350_CONFB_C1IM;
		break;
	default:
		return -EINVAL;
	}

	return regmap_update_bits(sta350->regmap, STA350_CONFB,
				  STA350_CONFB_C1IM | STA350_CONFB_C2IM, confb);
}

__attribute__((used)) static int sta350_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	int i, mcs = -EINVAL, ir = -EINVAL;
	unsigned int confa, confb;
	unsigned int rate, ratio;
	int ret;

	if (!sta350->mclk) {
		dev_err(component->dev,
			"sta350->mclk is unset. Unable to determine ratio\n");
		return -EIO;
	}

	rate = params_rate(params);
	ratio = sta350->mclk / rate;
	dev_dbg(component->dev, "rate: %u, ratio: %u\n", rate, ratio);

	for (i = 0; i < ARRAY_SIZE(interpolation_ratios); i++) {
		if (interpolation_ratios[i].fs == rate) {
			ir = interpolation_ratios[i].ir;
			break;
		}
	}

	if (ir < 0) {
		dev_err(component->dev, "Unsupported samplerate: %u\n", rate);
		return -EINVAL;
	}

	for (i = 0; i < 6; i++) {
		if (mcs_ratio_table[ir][i] == ratio) {
			mcs = i;
			break;
		}
	}

	if (mcs < 0) {
		dev_err(component->dev, "Unresolvable ratio: %u\n", ratio);
		return -EINVAL;
	}

	confa = (ir << STA350_CONFA_IR_SHIFT) |
		(mcs << STA350_CONFA_MCS_SHIFT);
	confb = 0;

	switch (params_width(params)) {
	case 24:
		dev_dbg(component->dev, "24bit\n");
		/* fall through */
	case 32:
		dev_dbg(component->dev, "24bit or 32bit\n");
		switch (sta350->format) {
		case SND_SOC_DAIFMT_I2S:
			confb |= 0x0;
			break;
		case SND_SOC_DAIFMT_LEFT_J:
			confb |= 0x1;
			break;
		case SND_SOC_DAIFMT_RIGHT_J:
			confb |= 0x2;
			break;
		}

		break;
	case 20:
		dev_dbg(component->dev, "20bit\n");
		switch (sta350->format) {
		case SND_SOC_DAIFMT_I2S:
			confb |= 0x4;
			break;
		case SND_SOC_DAIFMT_LEFT_J:
			confb |= 0x5;
			break;
		case SND_SOC_DAIFMT_RIGHT_J:
			confb |= 0x6;
			break;
		}

		break;
	case 18:
		dev_dbg(component->dev, "18bit\n");
		switch (sta350->format) {
		case SND_SOC_DAIFMT_I2S:
			confb |= 0x8;
			break;
		case SND_SOC_DAIFMT_LEFT_J:
			confb |= 0x9;
			break;
		case SND_SOC_DAIFMT_RIGHT_J:
			confb |= 0xa;
			break;
		}

		break;
	case 16:
		dev_dbg(component->dev, "16bit\n");
		switch (sta350->format) {
		case SND_SOC_DAIFMT_I2S:
			confb |= 0x0;
			break;
		case SND_SOC_DAIFMT_LEFT_J:
			confb |= 0xd;
			break;
		case SND_SOC_DAIFMT_RIGHT_J:
			confb |= 0xe;
			break;
		}

		break;
	default:
		return -EINVAL;
	}

	ret = regmap_update_bits(sta350->regmap, STA350_CONFA,
				 STA350_CONFA_MCS_MASK | STA350_CONFA_IR_MASK,
				 confa);
	if (ret < 0)
		return ret;

	ret = regmap_update_bits(sta350->regmap, STA350_CONFB,
				 STA350_CONFB_SAI_MASK | STA350_CONFB_SAIFB,
				 confb);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int sta350_startup_sequence(struct sta350_priv *sta350)
{
	if (sta350->gpiod_power_down)
		gpiod_set_value(sta350->gpiod_power_down, 1);

	if (sta350->gpiod_nreset) {
		gpiod_set_value(sta350->gpiod_nreset, 0);
		mdelay(1);
		gpiod_set_value(sta350->gpiod_nreset, 1);
		mdelay(1);
	}

	return 0;
}

__attribute__((used)) static int sta350_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	int ret;

	dev_dbg(component->dev, "level = %d\n", level);
	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		/* Full power on */
		regmap_update_bits(sta350->regmap, STA350_CONFF,
				   STA350_CONFF_PWDN | STA350_CONFF_EAPD,
				   STA350_CONFF_PWDN | STA350_CONFF_EAPD);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			ret = regulator_bulk_enable(
				ARRAY_SIZE(sta350->supplies),
				sta350->supplies);
			if (ret < 0) {
				dev_err(component->dev,
					"Failed to enable supplies: %d\n",
					ret);
				return ret;
			}
			sta350_startup_sequence(sta350);
			sta350_cache_sync(component);
		}

		/* Power down */
		regmap_update_bits(sta350->regmap, STA350_CONFF,
				   STA350_CONFF_PWDN | STA350_CONFF_EAPD,
				   0);

		break;

	case SND_SOC_BIAS_OFF:
		/* The chip runs through the power down sequence for us */
		regmap_update_bits(sta350->regmap, STA350_CONFF,
				   STA350_CONFF_PWDN | STA350_CONFF_EAPD, 0);

		/* power down: low */
		if (sta350->gpiod_power_down)
			gpiod_set_value(sta350->gpiod_power_down, 0);

		if (sta350->gpiod_nreset)
			gpiod_set_value(sta350->gpiod_nreset, 0);

		regulator_bulk_disable(ARRAY_SIZE(sta350->supplies),
				       sta350->supplies);
		break;
	}
	return 0;
}

__attribute__((used)) static int sta350_probe(struct snd_soc_component *component)
{
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);
	struct sta350_platform_data *pdata = sta350->pdata;
	int i, ret = 0, thermal = 0;

	ret = regulator_bulk_enable(ARRAY_SIZE(sta350->supplies),
				    sta350->supplies);
	if (ret < 0) {
		dev_err(component->dev, "Failed to enable supplies: %d\n", ret);
		return ret;
	}

	ret = sta350_startup_sequence(sta350);
	if (ret < 0) {
		dev_err(component->dev, "Failed to startup device\n");
		return ret;
	}

	/* CONFA */
	if (!pdata->thermal_warning_recovery)
		thermal |= STA350_CONFA_TWAB;
	if (!pdata->thermal_warning_adjustment)
		thermal |= STA350_CONFA_TWRB;
	if (!pdata->fault_detect_recovery)
		thermal |= STA350_CONFA_FDRB;
	regmap_update_bits(sta350->regmap, STA350_CONFA,
			   STA350_CONFA_TWAB | STA350_CONFA_TWRB |
			   STA350_CONFA_FDRB,
			   thermal);

	/* CONFC */
	regmap_update_bits(sta350->regmap, STA350_CONFC,
			   STA350_CONFC_OM_MASK,
			   pdata->ffx_power_output_mode
				<< STA350_CONFC_OM_SHIFT);
	regmap_update_bits(sta350->regmap, STA350_CONFC,
			   STA350_CONFC_CSZ_MASK,
			   pdata->drop_compensation_ns
				<< STA350_CONFC_CSZ_SHIFT);
	regmap_update_bits(sta350->regmap,
			   STA350_CONFC,
			   STA350_CONFC_OCRB,
			   pdata->oc_warning_adjustment ?
				STA350_CONFC_OCRB : 0);

	/* CONFE */
	regmap_update_bits(sta350->regmap, STA350_CONFE,
			   STA350_CONFE_MPCV,
			   pdata->max_power_use_mpcc ?
				STA350_CONFE_MPCV : 0);
	regmap_update_bits(sta350->regmap, STA350_CONFE,
			   STA350_CONFE_MPC,
			   pdata->max_power_correction ?
				STA350_CONFE_MPC : 0);
	regmap_update_bits(sta350->regmap, STA350_CONFE,
			   STA350_CONFE_AME,
			   pdata->am_reduction_mode ?
				STA350_CONFE_AME : 0);
	regmap_update_bits(sta350->regmap, STA350_CONFE,
			   STA350_CONFE_PWMS,
			   pdata->odd_pwm_speed_mode ?
				STA350_CONFE_PWMS : 0);
	regmap_update_bits(sta350->regmap, STA350_CONFE,
			   STA350_CONFE_DCCV,
			   pdata->distortion_compensation ?
				STA350_CONFE_DCCV : 0);
	/*  CONFF */
	regmap_update_bits(sta350->regmap, STA350_CONFF,
			   STA350_CONFF_IDE,
			   pdata->invalid_input_detect_mute ?
				STA350_CONFF_IDE : 0);
	regmap_update_bits(sta350->regmap, STA350_CONFF,
			   STA350_CONFF_OCFG_MASK,
			   pdata->output_conf
				<< STA350_CONFF_OCFG_SHIFT);

	/* channel to output mapping */
	regmap_update_bits(sta350->regmap, STA350_C1CFG,
			   STA350_CxCFG_OM_MASK,
			   pdata->ch1_output_mapping
				<< STA350_CxCFG_OM_SHIFT);
	regmap_update_bits(sta350->regmap, STA350_C2CFG,
			   STA350_CxCFG_OM_MASK,
			   pdata->ch2_output_mapping
				<< STA350_CxCFG_OM_SHIFT);
	regmap_update_bits(sta350->regmap, STA350_C3CFG,
			   STA350_CxCFG_OM_MASK,
			   pdata->ch3_output_mapping
				<< STA350_CxCFG_OM_SHIFT);

	/* miscellaneous registers */
	regmap_update_bits(sta350->regmap, STA350_MISC1,
			   STA350_MISC1_CPWMEN,
			   pdata->activate_mute_output ?
				STA350_MISC1_CPWMEN : 0);
	regmap_update_bits(sta350->regmap, STA350_MISC1,
			   STA350_MISC1_BRIDGOFF,
			   pdata->bridge_immediate_off ?
				STA350_MISC1_BRIDGOFF : 0);
	regmap_update_bits(sta350->regmap, STA350_MISC1,
			   STA350_MISC1_NSHHPEN,
			   pdata->noise_shape_dc_cut ?
				STA350_MISC1_NSHHPEN : 0);
	regmap_update_bits(sta350->regmap, STA350_MISC1,
			   STA350_MISC1_RPDNEN,
			   pdata->powerdown_master_vol ?
				STA350_MISC1_RPDNEN: 0);

	regmap_update_bits(sta350->regmap, STA350_MISC2,
			   STA350_MISC2_PNDLSL_MASK,
			   pdata->powerdown_delay_divider
				<< STA350_MISC2_PNDLSL_SHIFT);

	/* initialize coefficient shadow RAM with reset values */
	for (i = 4; i <= 49; i += 5)
		sta350->coef_shadow[i] = 0x400000;
	for (i = 50; i <= 54; i++)
		sta350->coef_shadow[i] = 0x7fffff;
	sta350->coef_shadow[55] = 0x5a9df7;
	sta350->coef_shadow[56] = 0x7fffff;
	sta350->coef_shadow[59] = 0x7fffff;
	sta350->coef_shadow[60] = 0x400000;
	sta350->coef_shadow[61] = 0x400000;

	snd_soc_component_force_bias_level(component, SND_SOC_BIAS_STANDBY);
	/* Bias level configuration will have done an extra enable */
	regulator_bulk_disable(ARRAY_SIZE(sta350->supplies), sta350->supplies);

	return 0;
}

__attribute__((used)) static void sta350_remove(struct snd_soc_component *component)
{
	struct sta350_priv *sta350 = snd_soc_component_get_drvdata(component);

	regulator_bulk_disable(ARRAY_SIZE(sta350->supplies), sta350->supplies);
}

__attribute__((used)) static int sta350_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct device *dev = &i2c->dev;
	struct sta350_priv *sta350;
	int ret, i;

	sta350 = devm_kzalloc(dev, sizeof(struct sta350_priv), GFP_KERNEL);
	if (!sta350)
		return -ENOMEM;

	mutex_init(&sta350->coeff_lock);
	sta350->pdata = dev_get_platdata(dev);

#ifdef CONFIG_OF
	if (dev->of_node) {
		ret = sta350_probe_dt(dev, sta350);
		if (ret < 0)
			return ret;
	}
#endif

	/* GPIOs */
	sta350->gpiod_nreset = devm_gpiod_get_optional(dev, "reset",
						       GPIOD_OUT_LOW);
	if (IS_ERR(sta350->gpiod_nreset))
		return PTR_ERR(sta350->gpiod_nreset);

	sta350->gpiod_power_down = devm_gpiod_get_optional(dev, "power-down",
							   GPIOD_OUT_LOW);
	if (IS_ERR(sta350->gpiod_power_down))
		return PTR_ERR(sta350->gpiod_power_down);

	/* regulators */
	for (i = 0; i < ARRAY_SIZE(sta350->supplies); i++)
		sta350->supplies[i].supply = sta350_supply_names[i];

	ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(sta350->supplies),
				      sta350->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to request supplies: %d\n", ret);
		return ret;
	}

	sta350->regmap = devm_regmap_init_i2c(i2c, &sta350_regmap);
	if (IS_ERR(sta350->regmap)) {
		ret = PTR_ERR(sta350->regmap);
		dev_err(dev, "Failed to init regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, sta350);

	ret = devm_snd_soc_register_component(dev, &sta350_component, &sta350_dai, 1);
	if (ret < 0)
		dev_err(dev, "Failed to register component (%d)\n", ret);

	return ret;
}

__attribute__((used)) static int sta350_i2c_remove(struct i2c_client *client)
{
	return 0;
}

