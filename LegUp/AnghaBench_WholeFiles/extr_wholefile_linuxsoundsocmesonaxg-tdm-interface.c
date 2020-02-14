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
typedef  int /*<<< orphan*/  u32 ;
struct snd_soc_dai_driver {int dummy; } ;
struct snd_soc_dai {void* playback_dma_data; scalar_t__ playback_widget; void* capture_dma_data; scalar_t__ capture_widget; struct device* dev; TYPE_1__* component; TYPE_4__* driver; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct axg_tdm_stream {void* channels; void* width; int /*<<< orphan*/  physical_width; int /*<<< orphan*/ * mask; } ;
struct axg_tdm_iface {unsigned int slots; int slot_width; unsigned int mclk_rate; unsigned int fmt; unsigned long rate; int /*<<< orphan*/ * mclk; int /*<<< orphan*/ * lrclk; int /*<<< orphan*/ * sclk; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_7__ {unsigned int channels_max; } ;
struct TYPE_6__ {unsigned int channels_max; } ;
struct TYPE_8__ {TYPE_3__ capture; TYPE_2__ playback; } ;
struct TYPE_5__ {scalar_t__ active; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int AXG_TDM_NUM_LANES ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_BIAS_OFF 138 
#define  SND_SOC_BIAS_ON 137 
#define  SND_SOC_BIAS_PREPARE 136 
#define  SND_SOC_BIAS_STANDBY 135 
 int SND_SOC_CLOCK_OUT ; 
 unsigned int SND_SOC_DAIFMT_CBM_CFS ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFM ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFS ; 
#define  SND_SOC_DAIFMT_DSP_A 134 
#define  SND_SOC_DAIFMT_DSP_B 133 
 int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 132 
 unsigned int SND_SOC_DAIFMT_IB_IF ; 
 unsigned int SND_SOC_DAIFMT_IB_NF ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_NB_IF ; 
#define  SND_SOC_DAIFMT_RIGHT_J 130 
#define  SND_SOC_DAI_FORMAT_DSP_A 129 
#define  SND_SOC_DAI_FORMAT_DSP_B 128 
 int /*<<< orphan*/  axg_tdm_iface_component_drv ; 
 int /*<<< orphan*/ * axg_tdm_iface_dai_drv ; 
 void* axg_tdm_stream_alloc (struct axg_tdm_iface*) ; 
 int /*<<< orphan*/  axg_tdm_stream_free (void*) ; 
 int axg_tdm_stream_start (struct axg_tdm_stream*) ; 
 int /*<<< orphan*/  axg_tdm_stream_stop (struct axg_tdm_stream*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ *) ; 
 int clk_prepare_enable (int /*<<< orphan*/ *) ; 
 int clk_set_duty_cycle (int /*<<< orphan*/ *,unsigned int,int) ; 
 int clk_set_phase (int /*<<< orphan*/ *,int) ; 
 int clk_set_rate (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 void* devm_clk_get (struct device*,char*) ; 
 struct snd_soc_dai_driver* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct axg_tdm_iface* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,struct snd_soc_dai_driver*,int) ; 
 scalar_t__ hweight32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct snd_soc_dai_driver*,int /*<<< orphan*/ *,int) ; 
 void* params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_physical_width (struct snd_pcm_hw_params*) ; 
 unsigned long params_rate (struct snd_pcm_hw_params*) ; 
 void* params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct axg_tdm_iface*) ; 
 int snd_pcm_hw_constraint_single (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct axg_tdm_iface* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct axg_tdm_stream* snd_soc_dai_get_dma_data (struct snd_soc_dai*,struct snd_pcm_substream*) ; 
 struct axg_tdm_iface* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 

__attribute__((used)) static inline bool axg_tdm_lrclk_invert(unsigned int fmt)
{
	return (fmt & SND_SOC_DAIFMT_I2S) ^
		!!(fmt & (SND_SOC_DAIFMT_IB_IF | SND_SOC_DAIFMT_NB_IF));
}

__attribute__((used)) static inline bool axg_tdm_sclk_invert(unsigned int fmt)
{
	return fmt & (SND_SOC_DAIFMT_IB_IF | SND_SOC_DAIFMT_IB_NF);
}

__attribute__((used)) static inline int axg_tdm_stream_reset(struct axg_tdm_stream *ts)
{
	axg_tdm_stream_stop(ts);
	return axg_tdm_stream_start(ts);
}

__attribute__((used)) static unsigned int axg_tdm_slots_total(u32 *mask)
{
	unsigned int slots = 0;
	int i;

	if (!mask)
		return 0;

	/* Count the total number of slots provided by all 4 lanes */
	for (i = 0; i < AXG_TDM_NUM_LANES; i++)
		slots += hweight32(mask[i]);

	return slots;
}

int axg_tdm_set_tdm_slots(struct snd_soc_dai *dai, u32 *tx_mask,
			  u32 *rx_mask, unsigned int slots,
			  unsigned int slot_width)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	struct axg_tdm_stream *tx = (struct axg_tdm_stream *)
		dai->playback_dma_data;
	struct axg_tdm_stream *rx = (struct axg_tdm_stream *)
		dai->capture_dma_data;
	unsigned int tx_slots, rx_slots;

	tx_slots = axg_tdm_slots_total(tx_mask);
	rx_slots = axg_tdm_slots_total(rx_mask);

	/* We should at least have a slot for a valid interface */
	if (!tx_slots && !rx_slots) {
		dev_err(dai->dev, "interface has no slot\n");
		return -EINVAL;
	}

	/*
	 * Amend the dai driver channel number and let dpcm channel merge do
	 * its job
	 */
	if (tx) {
		tx->mask = tx_mask;
		dai->driver->playback.channels_max = tx_slots;
	}

	if (rx) {
		rx->mask = rx_mask;
		dai->driver->capture.channels_max = rx_slots;
	}

	iface->slots = slots;

	switch (slot_width) {
	case 0:
		/* defaults width to 32 if not provided */
		iface->slot_width = 32;
		break;
	case 8:
	case 16:
	case 24:
	case 32:
		iface->slot_width = slot_width;
		break;
	default:
		dev_err(dai->dev, "unsupported slot width: %d\n", slot_width);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_set_sysclk(struct snd_soc_dai *dai, int clk_id,
				    unsigned int freq, int dir)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	int ret = -ENOTSUPP;

	if (dir == SND_SOC_CLOCK_OUT && clk_id == 0) {
		if (!iface->mclk) {
			dev_warn(dai->dev, "master clock not provided\n");
		} else {
			ret = clk_set_rate(iface->mclk, freq);
			if (!ret)
				iface->mclk_rate = freq;
		}
	}

	return ret;
}

__attribute__((used)) static int axg_tdm_iface_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);

	/* These modes are not supported */
	if (fmt & (SND_SOC_DAIFMT_CBS_CFM | SND_SOC_DAIFMT_CBM_CFS)) {
		dev_err(dai->dev, "only CBS_CFS and CBM_CFM are supported\n");
		return -EINVAL;
	}

	/* If the TDM interface is the clock master, it requires mclk */
	if (!iface->mclk && (fmt & SND_SOC_DAIFMT_CBS_CFS)) {
		dev_err(dai->dev, "cpu clock master: mclk missing\n");
		return -ENODEV;
	}

	iface->fmt = fmt;
	return 0;
}

__attribute__((used)) static int axg_tdm_iface_startup(struct snd_pcm_substream *substream,
				 struct snd_soc_dai *dai)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	struct axg_tdm_stream *ts =
		snd_soc_dai_get_dma_data(dai, substream);
	int ret;

	if (!axg_tdm_slots_total(ts->mask)) {
		dev_err(dai->dev, "interface has not slots\n");
		return -EINVAL;
	}

	/* Apply component wide rate symmetry */
	if (dai->component->active) {
		ret = snd_pcm_hw_constraint_single(substream->runtime,
						   SNDRV_PCM_HW_PARAM_RATE,
						   iface->rate);
		if (ret < 0) {
			dev_err(dai->dev,
				"can't set iface rate constraint\n");
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_set_stream(struct snd_pcm_substream *substream,
				    struct snd_pcm_hw_params *params,
				    struct snd_soc_dai *dai)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	struct axg_tdm_stream *ts = snd_soc_dai_get_dma_data(dai, substream);
	unsigned int channels = params_channels(params);
	unsigned int width = params_width(params);

	/* Save rate and sample_bits for component symmetry */
	iface->rate = params_rate(params);

	/* Make sure this interface can cope with the stream */
	if (axg_tdm_slots_total(ts->mask) < channels) {
		dev_err(dai->dev, "not enough slots for channels\n");
		return -EINVAL;
	}

	if (iface->slot_width < width) {
		dev_err(dai->dev, "incompatible slots width for stream\n");
		return -EINVAL;
	}

	/* Save the parameter for tdmout/tdmin widgets */
	ts->physical_width = params_physical_width(params);
	ts->width = params_width(params);
	ts->channels = params_channels(params);

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_set_lrclk(struct snd_soc_dai *dai,
				   struct snd_pcm_hw_params *params)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	unsigned int ratio_num;
	int ret;

	ret = clk_set_rate(iface->lrclk, params_rate(params));
	if (ret) {
		dev_err(dai->dev, "setting sample clock failed: %d\n", ret);
		return ret;
	}

	switch (iface->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		/* 50% duty cycle ratio */
		ratio_num = 1;
		break;

	case SND_SOC_DAIFMT_DSP_A:
	case SND_SOC_DAIFMT_DSP_B:
		/*
		 * A zero duty cycle ratio will result in setting the mininum
		 * ratio possible which, for this clock, is 1 cycle of the
		 * parent bclk clock high and the rest low, This is exactly
		 * what we want here.
		 */
		ratio_num = 0;
		break;

	default:
		return -EINVAL;
	}

	ret = clk_set_duty_cycle(iface->lrclk, ratio_num, 2);
	if (ret) {
		dev_err(dai->dev,
			"setting sample clock duty cycle failed: %d\n", ret);
		return ret;
	}

	/* Set sample clock inversion */
	ret = clk_set_phase(iface->lrclk,
			    axg_tdm_lrclk_invert(iface->fmt) ? 180 : 0);
	if (ret) {
		dev_err(dai->dev,
			"setting sample clock phase failed: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_set_sclk(struct snd_soc_dai *dai,
				  struct snd_pcm_hw_params *params)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	unsigned long srate;
	int ret;

	srate = iface->slots * iface->slot_width * params_rate(params);

	if (!iface->mclk_rate) {
		/* If no specific mclk is requested, default to bit clock * 4 */
		clk_set_rate(iface->mclk, 4 * srate);
	} else {
		/* Check if we can actually get the bit clock from mclk */
		if (iface->mclk_rate % srate) {
			dev_err(dai->dev,
				"can't derive sclk %lu from mclk %lu\n",
				srate, iface->mclk_rate);
			return -EINVAL;
		}
	}

	ret = clk_set_rate(iface->sclk, srate);
	if (ret) {
		dev_err(dai->dev, "setting bit clock failed: %d\n", ret);
		return ret;
	}

	/* Set the bit clock inversion */
	ret = clk_set_phase(iface->sclk,
			    axg_tdm_sclk_invert(iface->fmt) ? 0 : 180);
	if (ret) {
		dev_err(dai->dev, "setting bit clock phase failed: %d\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int axg_tdm_iface_hw_params(struct snd_pcm_substream *substream,
				   struct snd_pcm_hw_params *params,
				   struct snd_soc_dai *dai)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);
	int ret;

	switch (iface->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		if (iface->slots > 2) {
			dev_err(dai->dev, "bad slot number for format: %d\n",
				iface->slots);
			return -EINVAL;
		}
		break;

	case SND_SOC_DAI_FORMAT_DSP_A:
	case SND_SOC_DAI_FORMAT_DSP_B:
		break;

	default:
		dev_err(dai->dev, "unsupported dai format\n");
		return -EINVAL;
	}

	ret = axg_tdm_iface_set_stream(substream, params, dai);
	if (ret)
		return ret;

	if (iface->fmt & SND_SOC_DAIFMT_CBS_CFS) {
		ret = axg_tdm_iface_set_sclk(dai, params);
		if (ret)
			return ret;

		ret = axg_tdm_iface_set_lrclk(dai, params);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_hw_free(struct snd_pcm_substream *substream,
				 struct snd_soc_dai *dai)
{
	struct axg_tdm_stream *ts = snd_soc_dai_get_dma_data(dai, substream);

	/* Stop all attached formatters */
	axg_tdm_stream_stop(ts);

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_prepare(struct snd_pcm_substream *substream,
				 struct snd_soc_dai *dai)
{
	struct axg_tdm_stream *ts = snd_soc_dai_get_dma_data(dai, substream);

	/* Force all attached formatters to update */
	return axg_tdm_stream_reset(ts);
}

__attribute__((used)) static int axg_tdm_iface_remove_dai(struct snd_soc_dai *dai)
{
	if (dai->capture_dma_data)
		axg_tdm_stream_free(dai->capture_dma_data);

	if (dai->playback_dma_data)
		axg_tdm_stream_free(dai->playback_dma_data);

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_probe_dai(struct snd_soc_dai *dai)
{
	struct axg_tdm_iface *iface = snd_soc_dai_get_drvdata(dai);

	if (dai->capture_widget) {
		dai->capture_dma_data = axg_tdm_stream_alloc(iface);
		if (!dai->capture_dma_data)
			return -ENOMEM;
	}

	if (dai->playback_widget) {
		dai->playback_dma_data = axg_tdm_stream_alloc(iface);
		if (!dai->playback_dma_data) {
			axg_tdm_iface_remove_dai(dai);
			return -ENOMEM;
		}
	}

	return 0;
}

__attribute__((used)) static int axg_tdm_iface_set_bias_level(struct snd_soc_component *component,
					enum snd_soc_bias_level level)
{
	struct axg_tdm_iface *iface = snd_soc_component_get_drvdata(component);
	enum snd_soc_bias_level now =
		snd_soc_component_get_bias_level(component);
	int ret = 0;

	switch (level) {
	case SND_SOC_BIAS_PREPARE:
		if (now == SND_SOC_BIAS_STANDBY)
			ret = clk_prepare_enable(iface->mclk);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (now == SND_SOC_BIAS_PREPARE)
			clk_disable_unprepare(iface->mclk);
		break;

	case SND_SOC_BIAS_OFF:
	case SND_SOC_BIAS_ON:
		break;
	}

	return ret;
}

__attribute__((used)) static int axg_tdm_iface_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct snd_soc_dai_driver *dai_drv;
	struct axg_tdm_iface *iface;
	int ret, i;

	iface = devm_kzalloc(dev, sizeof(*iface), GFP_KERNEL);
	if (!iface)
		return -ENOMEM;
	platform_set_drvdata(pdev, iface);

	/*
	 * Duplicate dai driver: depending on the slot masks configuration
	 * We'll change the number of channel provided by DAI stream, so dpcm
	 * channel merge can be done properly
	 */
	dai_drv = devm_kcalloc(dev, ARRAY_SIZE(axg_tdm_iface_dai_drv),
			       sizeof(*dai_drv), GFP_KERNEL);
	if (!dai_drv)
		return -ENOMEM;

	for (i = 0; i < ARRAY_SIZE(axg_tdm_iface_dai_drv); i++)
		memcpy(&dai_drv[i], &axg_tdm_iface_dai_drv[i],
		       sizeof(*dai_drv));

	/* Bit clock provided on the pad */
	iface->sclk = devm_clk_get(dev, "sclk");
	if (IS_ERR(iface->sclk)) {
		ret = PTR_ERR(iface->sclk);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "failed to get sclk: %d\n", ret);
		return ret;
	}

	/* Sample clock provided on the pad */
	iface->lrclk = devm_clk_get(dev, "lrclk");
	if (IS_ERR(iface->lrclk)) {
		ret = PTR_ERR(iface->lrclk);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "failed to get lrclk: %d\n", ret);
		return ret;
	}

	/*
	 * mclk maybe be missing when the cpu dai is in slave mode and
	 * the codec does not require it to provide a master clock.
	 * At this point, ignore the error if mclk is missing. We'll
	 * throw an error if the cpu dai is master and mclk is missing
	 */
	iface->mclk = devm_clk_get(dev, "mclk");
	if (IS_ERR(iface->mclk)) {
		ret = PTR_ERR(iface->mclk);
		if (ret == -ENOENT) {
			iface->mclk = NULL;
		} else {
			if (ret != -EPROBE_DEFER)
				dev_err(dev, "failed to get mclk: %d\n", ret);
			return ret;
		}
	}

	return devm_snd_soc_register_component(dev,
					&axg_tdm_iface_component_drv, dai_drv,
					ARRAY_SIZE(axg_tdm_iface_dai_drv));
}

