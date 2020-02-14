#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_2__* card; struct snd_soc_dai* codec_dai; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct platform_device {int dummy; } ;
struct imx_pcm_fiq_params {int dummy; } ;
struct imx_dma_data {int dma_request; int peripheral_type; int /*<<< orphan*/  priority; } ;
typedef  scalar_t__ snd_pcm_format_t ;
typedef  enum sdma_peripheral_type { ____Placeholder_sdma_peripheral_type } sdma_peripheral_type ;
struct TYPE_8__ {int /*<<< orphan*/  dapm; } ;
struct TYPE_7__ {unsigned int rate; scalar_t__ format; unsigned int channels; int /*<<< orphan*/  clkdiv; int /*<<< orphan*/  lr_rate; int /*<<< orphan*/  bclkdiv; int /*<<< orphan*/  sysclk; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  DMA_PRIO_HIGH ; 
 int EINVAL ; 
 int ENODEV ; 
 int SND_JACK_BTN_0 ; 
 int SND_JACK_HEADPHONE ; 
 int SND_JACK_MICROPHONE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  WM8350_ADCLR_CLKDIV ; 
 int /*<<< orphan*/  WM8350_ADC_CLKDIV ; 
 int /*<<< orphan*/  WM8350_BCLK_CLKDIV ; 
 int /*<<< orphan*/  WM8350_DACLR_CLKDIV ; 
 int /*<<< orphan*/  WM8350_DAC_CLKDIV ; 
 int /*<<< orphan*/  WM8350_JDR ; 
 int /*<<< orphan*/  WM8350_MCLK_SEL_PLL_MCLK ; 
 int /*<<< orphan*/  hp_jack ; 
 TYPE_1__* hp_jack_pins ; 
 int /*<<< orphan*/  mic_jack ; 
 TYPE_1__* mic_jack_pins ; 
 unsigned int params_channels (struct snd_pcm_hw_params*) ; 
 scalar_t__ params_format (struct snd_pcm_hw_params*) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_soc_card_jack_new (TYPE_2__*,char*,int,int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  snd_soc_dai_set_clkdiv (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dai_set_pll (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dapm_force_enable_pin (int /*<<< orphan*/ *,char*) ; 
 TYPE_1__* wm8350_audio ; 
 int /*<<< orphan*/  wm8350_hp_jack_detect (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  wm8350_mic_jack_detect (struct snd_soc_component*,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static inline void
imx_pcm_dma_params_init_data(struct imx_dma_data *dma_data,
	int dma, enum sdma_peripheral_type peripheral_type)
{
	dma_data->dma_request = dma;
	dma_data->priority = DMA_PRIO_HIGH;
	dma_data->peripheral_type = peripheral_type;
}

__attribute__((used)) static inline int imx_pcm_dma_init(struct platform_device *pdev, size_t size)
{
	return -ENODEV;
}

__attribute__((used)) static inline int imx_pcm_fiq_init(struct platform_device *pdev,
		struct imx_pcm_fiq_params *params)
{
	return -ENODEV;
}

__attribute__((used)) static inline void imx_pcm_fiq_exit(struct platform_device *pdev)
{
}

__attribute__((used)) static int wm1133_ev1_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	int i, found = 0;
	snd_pcm_format_t format = params_format(params);
	unsigned int rate = params_rate(params);
	unsigned int channels = params_channels(params);

	/* find the correct audio parameters */
	for (i = 0; i < ARRAY_SIZE(wm8350_audio); i++) {
		if (rate == wm8350_audio[i].rate &&
		    format == wm8350_audio[i].format &&
		    channels == wm8350_audio[i].channels) {
			found = 1;
			break;
		}
	}
	if (!found)
		return -EINVAL;

	/* codec FLL input is 14.75 MHz from MCLK */
	snd_soc_dai_set_pll(codec_dai, 0, 0, 14750000, wm8350_audio[i].sysclk);

	/* TODO: The SSI driver should figure this out for us */
	switch (channels) {
	case 2:
		snd_soc_dai_set_tdm_slot(cpu_dai, 0x3, 0x3, 2, 0);
		break;
	case 1:
		snd_soc_dai_set_tdm_slot(cpu_dai, 0x1, 0x1, 1, 0);
		break;
	default:
		return -EINVAL;
	}

	/* set MCLK as the codec system clock for DAC and ADC */
	snd_soc_dai_set_sysclk(codec_dai, WM8350_MCLK_SEL_PLL_MCLK,
			       wm8350_audio[i].sysclk, SND_SOC_CLOCK_IN);

	/* set codec BCLK division for sample rate */
	snd_soc_dai_set_clkdiv(codec_dai, WM8350_BCLK_CLKDIV,
			       wm8350_audio[i].bclkdiv);

	/* DAI is synchronous and clocked with DAC LRCLK & ADC LRC */
	snd_soc_dai_set_clkdiv(codec_dai,
			       WM8350_DACLR_CLKDIV, wm8350_audio[i].lr_rate);
	snd_soc_dai_set_clkdiv(codec_dai,
			       WM8350_ADCLR_CLKDIV, wm8350_audio[i].lr_rate);

	/* now configure DAC and ADC clocks */
	snd_soc_dai_set_clkdiv(codec_dai,
			       WM8350_DAC_CLKDIV, wm8350_audio[i].clkdiv);

	snd_soc_dai_set_clkdiv(codec_dai,
			       WM8350_ADC_CLKDIV, wm8350_audio[i].clkdiv);

	return 0;
}

__attribute__((used)) static int wm1133_ev1_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;

	/* Headphone jack detection */
	snd_soc_card_jack_new(rtd->card, "Headphone", SND_JACK_HEADPHONE,
			      &hp_jack, hp_jack_pins, ARRAY_SIZE(hp_jack_pins));
	wm8350_hp_jack_detect(component, WM8350_JDR, &hp_jack, SND_JACK_HEADPHONE);

	/* Microphone jack detection */
	snd_soc_card_jack_new(rtd->card, "Microphone",
			      SND_JACK_MICROPHONE | SND_JACK_BTN_0, &mic_jack,
			      mic_jack_pins, ARRAY_SIZE(mic_jack_pins));
	wm8350_mic_jack_detect(component, &mic_jack, SND_JACK_MICROPHONE,
			       SND_JACK_BTN_0);

	snd_soc_dapm_force_enable_pin(&rtd->card->dapm, "Mic Bias");

	return 0;
}

