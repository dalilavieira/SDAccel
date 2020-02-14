#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int diff_mode; } ;
struct wm8741_priv {TYPE_1__ pdata; } ;
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_card* card; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai_link {struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_soc_card {TYPE_5__* dev; TYPE_3__* dai_link; struct snd_card* snd_card; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {TYPE_2__* vd; } ;
struct snd_card {int dummy; } ;
struct TYPE_14__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_13__ {TYPE_5__* dev; } ;
struct TYPE_12__ {int /*<<< orphan*/  name; } ;
struct TYPE_11__ {void* access; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EFAULT ; 
 int EINVAL ; 
 int EPROBE_DEFER ; 
 void* SNDRV_CTL_ELEM_ACCESS_READWRITE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 int /*<<< orphan*/  WM8741_DACLLSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACLMSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACRLSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACRMSB_ATTENUATION ; 
#define  WM8741_DIFF_MODE_MONO_LEFT 131 
#define  WM8741_DIFF_MODE_MONO_RIGHT 130 
#define  WM8741_DIFF_MODE_STEREO 129 
#define  WM8741_DIFF_MODE_STEREO_REVERSED 128 
 int /*<<< orphan*/  WM8741_FORMAT_CONTROL ; 
 int WM8741_IWL_MASK ; 
 int /*<<< orphan*/  WM8741_MODE_CONTROL_1 ; 
 int WM8741_OSR_MASK ; 
 int WM8741_UPDATELL ; 
 int WM8741_UPDATELM ; 
 int WM8741_UPDATERL ; 
 int WM8741_UPDATERM ; 
 int WM8804_MCLKDIV_128FS ; 
 int WM8804_MCLKDIV_256FS ; 
 int /*<<< orphan*/  WM8804_MCLK_DIV ; 
 int /*<<< orphan*/  WM8804_PWRDN ; 
 int /*<<< orphan*/  WM8804_SPDTX4 ; 
 int /*<<< orphan*/  WM8804_TX_CLKSRC_PLL ; 
 int /*<<< orphan*/  dev_dbg (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_5__*,char*,...) ; 
 int devm_snd_soc_register_card (TYPE_5__*,TYPE_4__*) ; 
 TYPE_4__ digidac1_soundcard ; 
 struct snd_soc_dai_link* digidac1_soundcard_dai ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int samplerate ; 
 int /*<<< orphan*/  snd_ctl_remove (struct snd_card*,struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol* snd_soc_card_get_kcontrol (struct snd_soc_card*,char*) ; 
 struct wm8741_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_dai_set_bclk_ratio (struct snd_soc_dai*,int) ; 
 int /*<<< orphan*/  snd_soc_dai_set_clkdiv (struct snd_soc_dai*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_soc_dai_set_pll (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,long) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w8741_snd_controls_mono_left ; 
 int /*<<< orphan*/  w8741_snd_controls_mono_right ; 
 int /*<<< orphan*/  w8741_snd_controls_stereo ; 

__attribute__((used)) static int w8741_add_controls(struct snd_soc_component *component)
{
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	switch (wm8741->pdata.diff_mode) {
	case WM8741_DIFF_MODE_STEREO:
	case WM8741_DIFF_MODE_STEREO_REVERSED:
		snd_soc_add_component_controls(component,
				w8741_snd_controls_stereo,
				ARRAY_SIZE(w8741_snd_controls_stereo));
		break;
	case WM8741_DIFF_MODE_MONO_LEFT:
		snd_soc_add_component_controls(component,
				w8741_snd_controls_mono_left,
				ARRAY_SIZE(w8741_snd_controls_mono_left));
		break;
	case WM8741_DIFF_MODE_MONO_RIGHT:
		snd_soc_add_component_controls(component,
				w8741_snd_controls_mono_right,
				ARRAY_SIZE(w8741_snd_controls_mono_right));
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int digidac1_soundcard_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_pcm_runtime *wm8741_rtd;
	struct snd_soc_component *wm8741_component;
	struct snd_card *sound_card = card->snd_card;
	struct snd_kcontrol *kctl;
	int ret;

	wm8741_rtd = snd_soc_get_pcm_runtime(card, card->dai_link[1].name);
	if (!wm8741_rtd) {
		dev_warn(card->dev, "digidac1_soundcard_init: couldn't get wm8741 rtd\n");
		return -EFAULT;
	}
	wm8741_component = wm8741_rtd->codec_dai->component;
	ret = w8741_add_controls(wm8741_component);
	if (ret < 0)
		dev_warn(card->dev, "Failed to add new wm8741 controls: %d\n",
		ret);

	/* enable TX output */
	snd_soc_component_update_bits(component, WM8804_PWRDN, 0x4, 0x0);

	kctl = snd_soc_card_get_kcontrol(card,
		"Playback Volume");
	if (kctl) {
		kctl->vd[0].access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
		snd_ctl_remove(sound_card, kctl);
		}
	kctl = snd_soc_card_get_kcontrol(card,
		"Fine Playback Volume");
	if (kctl) {
		kctl->vd[0].access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
		snd_ctl_remove(sound_card, kctl);
		}
	return 0;
}

__attribute__((used)) static int digidac1_soundcard_startup(struct snd_pcm_substream *substream)
{
	/* turn on wm8804 digital output */
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_pcm_runtime *wm8741_rtd;
	struct snd_soc_component *wm8741_component;

	snd_soc_component_update_bits(component, WM8804_PWRDN, 0x3c, 0x00);
	wm8741_rtd = snd_soc_get_pcm_runtime(card, card->dai_link[1].name);
	if (!wm8741_rtd) {
		dev_warn(card->dev, "digidac1_soundcard_startup: couldn't get WM8741 rtd\n");
		return -EFAULT;
	}
	wm8741_component = wm8741_rtd->codec_dai->component;

	/* latch wm8741 level */
	snd_soc_component_update_bits(wm8741_component, WM8741_DACLLSB_ATTENUATION,
		WM8741_UPDATELL, WM8741_UPDATELL);
	snd_soc_component_update_bits(wm8741_component, WM8741_DACLMSB_ATTENUATION,
		WM8741_UPDATELM, WM8741_UPDATELM);
	snd_soc_component_update_bits(wm8741_component, WM8741_DACRLSB_ATTENUATION,
		WM8741_UPDATERL, WM8741_UPDATERL);
	snd_soc_component_update_bits(wm8741_component, WM8741_DACRMSB_ATTENUATION,
		WM8741_UPDATERM, WM8741_UPDATERM);

	return 0;
}

__attribute__((used)) static void digidac1_soundcard_shutdown(struct snd_pcm_substream *substream)
{
	/* turn off wm8804 digital output */
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;

	snd_soc_component_update_bits(component, WM8804_PWRDN, 0x3c, 0x3c);
}

__attribute__((used)) static int digidac1_soundcard_hw_params(struct snd_pcm_substream *substream,
				       struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_pcm_runtime *wm8741_rtd;
	struct snd_soc_component *wm8741_component;

	int sysclk = 27000000;
	long mclk_freq = 0;
	int mclk_div = 1;
	int sampling_freq = 1;
	int ret;

	wm8741_rtd = snd_soc_get_pcm_runtime(card, card->dai_link[1].name);
	if (!wm8741_rtd) {
		dev_warn(card->dev, "digidac1_soundcard_hw_params: couldn't get WM8741 rtd\n");
		return -EFAULT;
	}
	wm8741_component = wm8741_rtd->codec_dai->component;
	samplerate = params_rate(params);

	if (samplerate <= 96000) {
		mclk_freq = samplerate*256;
		mclk_div = WM8804_MCLKDIV_256FS;
	} else {
		mclk_freq = samplerate*128;
		mclk_div = WM8804_MCLKDIV_128FS;
		}

	switch (samplerate) {
	case 32000:
		sampling_freq = 0x03;
		break;
	case 44100:
		sampling_freq = 0x00;
		break;
	case 48000:
		sampling_freq = 0x02;
		break;
	case 88200:
		sampling_freq = 0x08;
		break;
	case 96000:
		sampling_freq = 0x0a;
		break;
	case 176400:
		sampling_freq = 0x0c;
		break;
	case 192000:
		sampling_freq = 0x0e;
		break;
	default:
		dev_err(card->dev,
		"Failed to set WM8804 SYSCLK, unsupported samplerate %d\n",
		samplerate);
	}

	snd_soc_dai_set_clkdiv(codec_dai, WM8804_MCLK_DIV, mclk_div);
	snd_soc_dai_set_pll(codec_dai, 0, 0, sysclk, mclk_freq);

	ret = snd_soc_dai_set_sysclk(codec_dai, WM8804_TX_CLKSRC_PLL,
		sysclk, SND_SOC_CLOCK_OUT);
	if (ret < 0) {
		dev_err(card->dev,
		"Failed to set WM8804 SYSCLK: %d\n", ret);
		return ret;
	}
	/* Enable wm8804 TX output */
	snd_soc_component_update_bits(component, WM8804_PWRDN, 0x4, 0x0);

	/* wm8804 Power on */
	snd_soc_component_update_bits(component, WM8804_PWRDN, 0x9, 0);

	/* wm8804 set sampling frequency status bits */
	snd_soc_component_update_bits(component, WM8804_SPDTX4, 0x0f, sampling_freq);

	/* Now update wm8741 registers for the correct oversampling */
	if (samplerate <= 48000)
		snd_soc_component_update_bits(wm8741_component, WM8741_MODE_CONTROL_1,
		 WM8741_OSR_MASK, 0x00);
	else if (samplerate <= 96000)
		snd_soc_component_update_bits(wm8741_component, WM8741_MODE_CONTROL_1,
		 WM8741_OSR_MASK, 0x20);
	else
		snd_soc_component_update_bits(wm8741_component, WM8741_MODE_CONTROL_1,
		 WM8741_OSR_MASK, 0x40);

	/* wm8741 bit size */
	switch (params_width(params)) {
	case 16:
		snd_soc_component_update_bits(wm8741_component, WM8741_FORMAT_CONTROL,
		 WM8741_IWL_MASK, 0x00);
		break;
	case 20:
		snd_soc_component_update_bits(wm8741_component, WM8741_FORMAT_CONTROL,
		 WM8741_IWL_MASK, 0x01);
		break;
	case 24:
		snd_soc_component_update_bits(wm8741_component, WM8741_FORMAT_CONTROL,
		 WM8741_IWL_MASK, 0x02);
		break;
	case 32:
		snd_soc_component_update_bits(wm8741_component, WM8741_FORMAT_CONTROL,
		 WM8741_IWL_MASK, 0x03);
		break;
	default:
		dev_dbg(card->dev, "wm8741_hw_params:    Unsupported bit size param = %d",
			params_width(params));
		return -EINVAL;
	}

	return snd_soc_dai_set_bclk_ratio(cpu_dai, 64);
}

__attribute__((used)) static int digidac1_soundcard_probe(struct platform_device *pdev)
{
	int ret = 0;

	digidac1_soundcard.dev = &pdev->dev;

	if (pdev->dev.of_node) {
		struct device_node *i2s_node;
		struct snd_soc_dai_link *dai = &digidac1_soundcard_dai[0];

		i2s_node = of_parse_phandle(pdev->dev.of_node,
					"i2s-controller", 0);

		if (i2s_node) {
			dai->cpu_dai_name = NULL;
			dai->cpu_of_node = i2s_node;
			dai->platform_name = NULL;
			dai->platform_of_node = i2s_node;
		}
	}

	ret = devm_snd_soc_register_card(&pdev->dev, &digidac1_soundcard);
	if (ret && ret != -EPROBE_DEFER)
		dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
			ret);

	return ret;
}

