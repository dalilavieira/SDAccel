#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_12__ {int diff_mode; } ;
struct wm8741_priv {unsigned int sysclk; TYPE_2__ pdata; int /*<<< orphan*/  supplies; TYPE_1__* sysclk_constraints; } ;
struct wm8741_platform_data {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {scalar_t__ of_node; } ;
struct TYPE_11__ {int count; scalar_t__* list; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_DAIFMT_CBS_CFS 141 
#define  SND_SOC_DAIFMT_DSP_A 140 
#define  SND_SOC_DAIFMT_DSP_B 139 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 138 
#define  SND_SOC_DAIFMT_IB_IF 137 
#define  SND_SOC_DAIFMT_IB_NF 136 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 135 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 134 
#define  SND_SOC_DAIFMT_NB_NF 133 
#define  SND_SOC_DAIFMT_RIGHT_J 132 
 unsigned int WM8741_BCP_MASK ; 
 int /*<<< orphan*/  WM8741_DACLLSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACLMSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACRLSB_ATTENUATION ; 
 int /*<<< orphan*/  WM8741_DACRMSB_ATTENUATION ; 
 unsigned int WM8741_DIFF_MASK ; 
#define  WM8741_DIFF_MODE_MONO_LEFT 131 
#define  WM8741_DIFF_MODE_MONO_RIGHT 130 
#define  WM8741_DIFF_MODE_STEREO 129 
#define  WM8741_DIFF_MODE_STEREO_REVERSED 128 
 unsigned int WM8741_DIFF_SHIFT ; 
 unsigned int WM8741_FMT_MASK ; 
 int /*<<< orphan*/  WM8741_FORMAT_CONTROL ; 
 unsigned int WM8741_IWL_MASK ; 
 unsigned int WM8741_LRP_MASK ; 
 int /*<<< orphan*/  WM8741_MODE_CONTROL_2 ; 
 int /*<<< orphan*/  WM8741_RESET ; 
 unsigned int WM8741_UPDATELL ; 
 unsigned int WM8741_UPDATELM ; 
 unsigned int WM8741_UPDATERL ; 
 unsigned int WM8741_UPDATERM ; 
 TYPE_1__ constraints_11289 ; 
 TYPE_1__ constraints_12288 ; 
 TYPE_1__ constraints_16384 ; 
 TYPE_1__ constraints_16934 ; 
 TYPE_1__ constraints_18432 ; 
 TYPE_1__ constraints_22579 ; 
 TYPE_1__ constraints_24576 ; 
 TYPE_1__ constraints_36864 ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 struct wm8741_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,struct wm8741_platform_data const*,int) ; 
 scalar_t__ of_property_read_u32 (scalar_t__,char*,int*) ; 
 scalar_t__ params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regulator_bulk_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct wm8741_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8741_snd_controls_mono_left ; 
 int /*<<< orphan*/  wm8741_snd_controls_mono_right ; 
 int /*<<< orphan*/  wm8741_snd_controls_stereo ; 

__attribute__((used)) static int wm8741_reset(struct snd_soc_component *component)
{
	return snd_soc_component_write(component, WM8741_RESET, 0);
}

__attribute__((used)) static int wm8741_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	if (wm8741->sysclk)
		snd_pcm_hw_constraint_list(substream->runtime, 0,
				SNDRV_PCM_HW_PARAM_RATE,
				wm8741->sysclk_constraints);

	return 0;
}

__attribute__((used)) static int wm8741_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);
	unsigned int iface;
	int i;

	/* The set of sample rates that can be supported depends on the
	 * MCLK supplied to the CODEC - enforce this.
	 */
	if (!wm8741->sysclk) {
		dev_err(component->dev,
			"No MCLK configured, call set_sysclk() on init or in hw_params\n");
		return -EINVAL;
	}

	/* Find a supported LRCLK rate */
	for (i = 0; i < wm8741->sysclk_constraints->count; i++) {
		if (wm8741->sysclk_constraints->list[i] == params_rate(params))
			break;
	}

	if (i == wm8741->sysclk_constraints->count) {
		dev_err(component->dev, "LRCLK %d unsupported with MCLK %d\n",
			params_rate(params), wm8741->sysclk);
		return -EINVAL;
	}

	/* bit size */
	switch (params_width(params)) {
	case 16:
		iface = 0x0;
		break;
	case 20:
		iface = 0x1;
		break;
	case 24:
		iface = 0x2;
		break;
	case 32:
		iface = 0x3;
		break;
	default:
		dev_dbg(component->dev, "wm8741_hw_params:    Unsupported bit size param = %d",
			params_width(params));
		return -EINVAL;
	}

	dev_dbg(component->dev, "wm8741_hw_params:    bit size param = %d, rate param = %d",
		params_width(params), params_rate(params));

	snd_soc_component_update_bits(component, WM8741_FORMAT_CONTROL, WM8741_IWL_MASK,
			    iface);

	return 0;
}

__attribute__((used)) static int wm8741_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	dev_dbg(component->dev, "wm8741_set_dai_sysclk info: freq=%dHz\n", freq);

	switch (freq) {
	case 0:
		wm8741->sysclk_constraints = NULL;
		break;
	case 11289600:
		wm8741->sysclk_constraints = &constraints_11289;
		break;
	case 12288000:
		wm8741->sysclk_constraints = &constraints_12288;
		break;
	case 16384000:
		wm8741->sysclk_constraints = &constraints_16384;
		break;
	case 16934400:
		wm8741->sysclk_constraints = &constraints_16934;
		break;
	case 18432000:
		wm8741->sysclk_constraints = &constraints_18432;
		break;
	case 22579200:
	case 33868800:
		wm8741->sysclk_constraints = &constraints_22579;
		break;
	case 24576000:
		wm8741->sysclk_constraints = &constraints_24576;
		break;
	case 36864000:
		wm8741->sysclk_constraints = &constraints_36864;
		break;
	default:
		return -EINVAL;
	}

	wm8741->sysclk = freq;
	return 0;
}

__attribute__((used)) static int wm8741_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	unsigned int iface;

	/* check master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		iface = 0x08;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		iface = 0x00;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface = 0x04;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		iface = 0x0C;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		iface = 0x1C;
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_NB_IF:
		iface |= 0x10;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		iface |= 0x20;
		break;
	case SND_SOC_DAIFMT_IB_IF:
		iface |= 0x30;
		break;
	default:
		return -EINVAL;
	}


	dev_dbg(component->dev, "wm8741_set_dai_fmt:    Format=%x, Clock Inv=%x\n",
				fmt & SND_SOC_DAIFMT_FORMAT_MASK,
				((fmt & SND_SOC_DAIFMT_INV_MASK)));

	snd_soc_component_update_bits(component, WM8741_FORMAT_CONTROL,
			    WM8741_BCP_MASK | WM8741_LRP_MASK | WM8741_FMT_MASK,
			    iface);

	return 0;
}

__attribute__((used)) static int wm8741_configure(struct snd_soc_component *component)
{
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	/* Configure differential mode */
	switch (wm8741->pdata.diff_mode) {
	case WM8741_DIFF_MODE_STEREO:
	case WM8741_DIFF_MODE_STEREO_REVERSED:
	case WM8741_DIFF_MODE_MONO_LEFT:
	case WM8741_DIFF_MODE_MONO_RIGHT:
		snd_soc_component_update_bits(component, WM8741_MODE_CONTROL_2,
				WM8741_DIFF_MASK,
				wm8741->pdata.diff_mode << WM8741_DIFF_SHIFT);
		break;
	default:
		return -EINVAL;
	}

	/* Change some default settings - latch VU */
	snd_soc_component_update_bits(component, WM8741_DACLLSB_ATTENUATION,
			WM8741_UPDATELL, WM8741_UPDATELL);
	snd_soc_component_update_bits(component, WM8741_DACLMSB_ATTENUATION,
			WM8741_UPDATELM, WM8741_UPDATELM);
	snd_soc_component_update_bits(component, WM8741_DACRLSB_ATTENUATION,
			WM8741_UPDATERL, WM8741_UPDATERL);
	snd_soc_component_update_bits(component, WM8741_DACRMSB_ATTENUATION,
			WM8741_UPDATERM, WM8741_UPDATERM);

	return 0;
}

__attribute__((used)) static int wm8741_add_controls(struct snd_soc_component *component)
{
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	switch (wm8741->pdata.diff_mode) {
	case WM8741_DIFF_MODE_STEREO:
	case WM8741_DIFF_MODE_STEREO_REVERSED:
		snd_soc_add_component_controls(component,
				wm8741_snd_controls_stereo,
				ARRAY_SIZE(wm8741_snd_controls_stereo));
		break;
	case WM8741_DIFF_MODE_MONO_LEFT:
		snd_soc_add_component_controls(component,
				wm8741_snd_controls_mono_left,
				ARRAY_SIZE(wm8741_snd_controls_mono_left));
		break;
	case WM8741_DIFF_MODE_MONO_RIGHT:
		snd_soc_add_component_controls(component,
				wm8741_snd_controls_mono_right,
				ARRAY_SIZE(wm8741_snd_controls_mono_right));
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm8741_probe(struct snd_soc_component *component)
{
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);
	int ret = 0;

	ret = regulator_bulk_enable(ARRAY_SIZE(wm8741->supplies),
				    wm8741->supplies);
	if (ret != 0) {
		dev_err(component->dev, "Failed to enable supplies: %d\n", ret);
		goto err_get;
	}

	ret = wm8741_reset(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset\n");
		goto err_enable;
	}

	ret = wm8741_configure(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to change default settings\n");
		goto err_enable;
	}

	ret = wm8741_add_controls(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to add controls\n");
		goto err_enable;
	}

	dev_dbg(component->dev, "Successful registration\n");
	return ret;

err_enable:
	regulator_bulk_disable(ARRAY_SIZE(wm8741->supplies), wm8741->supplies);
err_get:
	return ret;
}

__attribute__((used)) static void wm8741_remove(struct snd_soc_component *component)
{
	struct wm8741_priv *wm8741 = snd_soc_component_get_drvdata(component);

	regulator_bulk_disable(ARRAY_SIZE(wm8741->supplies), wm8741->supplies);
}

__attribute__((used)) static int wm8741_set_pdata(struct device *dev, struct wm8741_priv *wm8741)
{
	const struct wm8741_platform_data *pdata = dev_get_platdata(dev);
	u32 diff_mode;

	if (dev->of_node) {
		if (of_property_read_u32(dev->of_node, "diff-mode", &diff_mode)
				>= 0)
			wm8741->pdata.diff_mode = diff_mode;
	} else {
		if (pdata != NULL)
			memcpy(&wm8741->pdata, pdata, sizeof(wm8741->pdata));
	}

	return 0;
}

