#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct snd_soc_dai {TYPE_2__* component; int /*<<< orphan*/  dev; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct si476x_core {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int EINVAL ; 
 int SI476X_DAUDIO_MODE_DSP_A ; 
 int SI476X_DAUDIO_MODE_DSP_B ; 
 int SI476X_DAUDIO_MODE_I2S ; 
 int SI476X_DAUDIO_MODE_IB ; 
 int SI476X_DAUDIO_MODE_IF ; 
 int SI476X_DAUDIO_MODE_LEFT_J ; 
 int SI476X_DAUDIO_MODE_RIGHT_J ; 
 int /*<<< orphan*/  SI476X_DIGITAL_IO_OUTPUT_FORMAT ; 
 int /*<<< orphan*/  SI476X_DIGITAL_IO_OUTPUT_FORMAT_MASK ; 
 int /*<<< orphan*/  SI476X_DIGITAL_IO_OUTPUT_SAMPLE_RATE ; 
 int /*<<< orphan*/  SI476X_DIGITAL_IO_OUTPUT_WIDTH_MASK ; 
 int SI476X_DIGITAL_IO_SAMPLE_SIZE_SHIFT ; 
 int SI476X_DIGITAL_IO_SLOT_SIZE_SHIFT ; 
 int SI476X_PCM_FORMAT_S16_LE ; 
 int SI476X_PCM_FORMAT_S20_3LE ; 
 int SI476X_PCM_FORMAT_S24_LE ; 
 int SI476X_PCM_FORMAT_S8 ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFS ; 
#define  SND_SOC_DAIFMT_DSP_A 136 
#define  SND_SOC_DAIFMT_DSP_B 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 struct si476x_core* i2c_mfd_cell_to_core (int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  si476x_core_lock (struct si476x_core*) ; 
 int /*<<< orphan*/  si476x_core_unlock (struct si476x_core*) ; 
 int /*<<< orphan*/  si476x_dai ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int snd_soc_component_update_bits (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int snd_soc_component_write (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_si476x ; 

__attribute__((used)) static int si476x_codec_set_dai_fmt(struct snd_soc_dai *codec_dai,
				    unsigned int fmt)
{
	struct si476x_core *core = i2c_mfd_cell_to_core(codec_dai->dev);
	int err;
	u16 format = 0;

	if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
		return -EINVAL;

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_DSP_A:
		format |= SI476X_DAUDIO_MODE_DSP_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		format |= SI476X_DAUDIO_MODE_DSP_B;
		break;
	case SND_SOC_DAIFMT_I2S:
		format |= SI476X_DAUDIO_MODE_I2S;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		format |= SI476X_DAUDIO_MODE_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		format |= SI476X_DAUDIO_MODE_LEFT_J;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_DSP_A:
	case SND_SOC_DAIFMT_DSP_B:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			break;
		case SND_SOC_DAIFMT_IB_NF:
			format |= SI476X_DAUDIO_MODE_IB;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_RIGHT_J:
	case SND_SOC_DAIFMT_LEFT_J:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			break;
		case SND_SOC_DAIFMT_IB_IF:
			format |= SI476X_DAUDIO_MODE_IB |
				SI476X_DAUDIO_MODE_IF;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			format |= SI476X_DAUDIO_MODE_IB;
			break;
		case SND_SOC_DAIFMT_NB_IF:
			format |= SI476X_DAUDIO_MODE_IF;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	si476x_core_lock(core);

	err = snd_soc_component_update_bits(codec_dai->component, SI476X_DIGITAL_IO_OUTPUT_FORMAT,
				  SI476X_DIGITAL_IO_OUTPUT_FORMAT_MASK,
				  format);

	si476x_core_unlock(core);

	if (err < 0) {
		dev_err(codec_dai->component->dev, "Failed to set output format\n");
		return err;
	}

	return 0;
}

__attribute__((used)) static int si476x_codec_hw_params(struct snd_pcm_substream *substream,
				  struct snd_pcm_hw_params *params,
				  struct snd_soc_dai *dai)
{
	struct si476x_core *core = i2c_mfd_cell_to_core(dai->dev);
	int rate, width, err;

	rate = params_rate(params);
	if (rate < 32000 || rate > 48000) {
		dev_err(dai->component->dev, "Rate: %d is not supported\n", rate);
		return -EINVAL;
	}

	switch (params_width(params)) {
	case 8:
		width = SI476X_PCM_FORMAT_S8;
		break;
	case 16:
		width = SI476X_PCM_FORMAT_S16_LE;
		break;
	case 20:
		width = SI476X_PCM_FORMAT_S20_3LE;
		break;
	case 24:
		width = SI476X_PCM_FORMAT_S24_LE;
		break;
	default:
		return -EINVAL;
	}

	si476x_core_lock(core);

	err = snd_soc_component_write(dai->component, SI476X_DIGITAL_IO_OUTPUT_SAMPLE_RATE,
			    rate);
	if (err < 0) {
		dev_err(dai->component->dev, "Failed to set sample rate\n");
		goto out;
	}

	err = snd_soc_component_update_bits(dai->component, SI476X_DIGITAL_IO_OUTPUT_FORMAT,
				  SI476X_DIGITAL_IO_OUTPUT_WIDTH_MASK,
				  (width << SI476X_DIGITAL_IO_SLOT_SIZE_SHIFT) |
				  (width << SI476X_DIGITAL_IO_SAMPLE_SIZE_SHIFT));
	if (err < 0) {
		dev_err(dai->component->dev, "Failed to set output width\n");
		goto out;
	}

out:
	si476x_core_unlock(core);

	return err;
}

__attribute__((used)) static int si476x_probe(struct snd_soc_component *component)
{
	snd_soc_component_init_regmap(component,
				dev_get_regmap(component->dev->parent, NULL));

	return 0;
}

__attribute__((used)) static int si476x_platform_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
				      &soc_component_dev_si476x,
				      &si476x_dai, 1);
}

