#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; struct snd_soc_dai* codec_dai; TYPE_1__* card; } ;
struct snd_soc_dapm_widget {int dummy; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_card {struct snd_soc_dapm_context dapm; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_7__ {int* item; } ;
struct TYPE_6__ {scalar_t__* value; } ;
struct TYPE_8__ {TYPE_3__ enumerated; TYPE_2__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_5__ {struct snd_soc_dapm_context dapm; } ;

/* Variables and functions */
 int /*<<< orphan*/  EGPIO_MAGICIAN_EP_POWER ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_IN_SEL1 ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_MIC_POWER ; 
 int /*<<< orphan*/  EGPIO_MAGICIAN_SPK_POWER ; 
#define  MAGICIAN_MIC 129 
#define  MAGICIAN_MIC_EXT 128 
 int /*<<< orphan*/  PXA2XX_I2S_SYSCLK ; 
 int /*<<< orphan*/  PXA_SSP_CLK_AUDIO ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 int SND_SOC_DAIFMT_CBS_CFS ; 
 int SND_SOC_DAIFMT_DSP_A ; 
 int SND_SOC_DAIFMT_MSB ; 
 int SND_SOC_DAIFMT_NB_IF ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 scalar_t__ magician_hp_switch ; 
 int magician_in_sel ; 
 scalar_t__ magician_spk_switch ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 unsigned int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_fmt (struct snd_soc_dai*,int) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_enable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_lock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_unlock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_sync_unlocked (struct snd_soc_dapm_context*) ; 

__attribute__((used)) static void magician_ext_control(struct snd_soc_dapm_context *dapm)
{

	snd_soc_dapm_mutex_lock(dapm);

	if (magician_spk_switch)
		snd_soc_dapm_enable_pin_unlocked(dapm, "Speaker");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "Speaker");
	if (magician_hp_switch)
		snd_soc_dapm_enable_pin_unlocked(dapm, "Headphone Jack");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");

	switch (magician_in_sel) {
	case MAGICIAN_MIC:
		snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Mic");
		snd_soc_dapm_enable_pin_unlocked(dapm, "Call Mic");
		break;
	case MAGICIAN_MIC_EXT:
		snd_soc_dapm_disable_pin_unlocked(dapm, "Call Mic");
		snd_soc_dapm_enable_pin_unlocked(dapm, "Headset Mic");
		break;
	}

	snd_soc_dapm_sync_unlocked(dapm);

	snd_soc_dapm_mutex_unlock(dapm);
}

__attribute__((used)) static int magician_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;

	/* check the jack status at stream startup */
	magician_ext_control(&rtd->card->dapm);

	return 0;
}

__attribute__((used)) static int magician_playback_hw_params(struct snd_pcm_substream *substream,
				       struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	unsigned int width;
	int ret = 0;

	/* set codec DAI configuration */
	ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_MSB |
			SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
	if (ret < 0)
		return ret;

	/* set cpu DAI configuration */
	ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_NB_IF | SND_SOC_DAIFMT_CBS_CFS);
	if (ret < 0)
		return ret;

	width = snd_pcm_format_physical_width(params_format(params));
	ret = snd_soc_dai_set_tdm_slot(cpu_dai, 1, 0, 1, width);
	if (ret < 0)
		return ret;

	/* set audio clock as clock source */
	ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_AUDIO, 0,
			SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int magician_capture_hw_params(struct snd_pcm_substream *substream,
				      struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	int ret = 0;

	/* set codec DAI configuration */
	ret = snd_soc_dai_set_fmt(codec_dai,
			SND_SOC_DAIFMT_MSB | SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS);
	if (ret < 0)
		return ret;

	/* set cpu DAI configuration */
	ret = snd_soc_dai_set_fmt(cpu_dai,
			SND_SOC_DAIFMT_MSB | SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS);
	if (ret < 0)
		return ret;

	/* set the I2S system clock as output */
	ret = snd_soc_dai_set_sysclk(cpu_dai, PXA2XX_I2S_SYSCLK, 0,
			SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int magician_get_hp(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = magician_hp_switch;
	return 0;
}

__attribute__((used)) static int magician_set_hp(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (magician_hp_switch == ucontrol->value.integer.value[0])
		return 0;

	magician_hp_switch = ucontrol->value.integer.value[0];
	magician_ext_control(&card->dapm);
	return 1;
}

__attribute__((used)) static int magician_get_spk(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = magician_spk_switch;
	return 0;
}

__attribute__((used)) static int magician_set_spk(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (magician_spk_switch == ucontrol->value.integer.value[0])
		return 0;

	magician_spk_switch = ucontrol->value.integer.value[0];
	magician_ext_control(&card->dapm);
	return 1;
}

__attribute__((used)) static int magician_get_input(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.enumerated.item[0] = magician_in_sel;
	return 0;
}

__attribute__((used)) static int magician_set_input(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *ucontrol)
{
	if (magician_in_sel == ucontrol->value.enumerated.item[0])
		return 0;

	magician_in_sel = ucontrol->value.enumerated.item[0];

	switch (magician_in_sel) {
	case MAGICIAN_MIC:
		gpio_set_value(EGPIO_MAGICIAN_IN_SEL1, 1);
		break;
	case MAGICIAN_MIC_EXT:
		gpio_set_value(EGPIO_MAGICIAN_IN_SEL1, 0);
	}

	return 1;
}

__attribute__((used)) static int magician_spk_power(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *k, int event)
{
	gpio_set_value(EGPIO_MAGICIAN_SPK_POWER, SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

__attribute__((used)) static int magician_hp_power(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *k, int event)
{
	gpio_set_value(EGPIO_MAGICIAN_EP_POWER, SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

__attribute__((used)) static int magician_mic_bias(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *k, int event)
{
	gpio_set_value(EGPIO_MAGICIAN_MIC_POWER, SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

