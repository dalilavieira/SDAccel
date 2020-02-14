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
typedef  int u32 ;
struct spear_spdif_platform_data {int /*<<< orphan*/  filter; int /*<<< orphan*/  dma_params; } ;
struct TYPE_9__ {int max_burst; int /*<<< orphan*/  addr_width; scalar_t__ addr; int /*<<< orphan*/  data; } ;
struct TYPE_8__ {TYPE_4__* filter_data; } ;
struct TYPE_10__ {int core_freq; int rate; int mute; } ;
struct spdif_out_dev {int running; int /*<<< orphan*/  config; TYPE_4__ dma_params; scalar_t__ clk; scalar_t__ io_base; TYPE_3__ dma_params_tx; TYPE_5__ saved_params; } ;
struct snd_soc_dai {TYPE_3__* playback_dma_data; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_6__ {int* value; } ;
struct TYPE_7__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct resource {scalar_t__ start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int DIV_ROUND_CLOSEST (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DMA_SLAVE_BUSWIDTH_4_BYTES ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 133 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 132 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int SPDIF_DIVIDER_MASK ; 
 int SPDIF_DIVIDER_SHIFT ; 
 int SPDIF_OPMODE_AUD_DATA ; 
 int SPDIF_OPMODE_MASK ; 
 int SPDIF_OPMODE_MUTE_PCM ; 
 int SPDIF_OPMODE_OFF ; 
 scalar_t__ SPDIF_OUT_CFG ; 
 int SPDIF_OUT_CHNLSTA_HW ; 
 scalar_t__ SPDIF_OUT_CTRL ; 
 int SPDIF_OUT_FDMA_TRIG_16 ; 
 scalar_t__ SPDIF_OUT_FIFO_DATA ; 
 scalar_t__ SPDIF_OUT_INT_EN_CLR ; 
 scalar_t__ SPDIF_OUT_INT_STA_CLR ; 
 int SPDIF_OUT_MEMFMT_16_16 ; 
 int SPDIF_OUT_PARITY_HW ; 
 int SPDIF_OUT_RESET ; 
 scalar_t__ SPDIF_OUT_SOFT_RST ; 
 int SPDIF_OUT_USER_HW ; 
 int SPDIF_OUT_VALID_HW ; 
 int SPDIF_STATE_NORMAL ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 int /*<<< orphan*/  clk_get_rate (scalar_t__) ; 
 int /*<<< orphan*/  clk_set_rate (scalar_t__,int) ; 
 struct spear_spdif_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct spdif_out_dev*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct spdif_out_dev* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int devm_spear_pcm_platform_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 struct snd_soc_dai* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int snd_soc_add_dai_controls (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct spdif_out_dev* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int /*<<< orphan*/  spdif_out_component ; 
 int /*<<< orphan*/  spdif_out_controls ; 
 int /*<<< orphan*/  spdif_out_dai ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void spdif_out_configure(struct spdif_out_dev *host)
{
	writel(SPDIF_OUT_RESET, host->io_base + SPDIF_OUT_SOFT_RST);
	mdelay(1);
	writel(readl(host->io_base + SPDIF_OUT_SOFT_RST) & ~SPDIF_OUT_RESET,
			host->io_base + SPDIF_OUT_SOFT_RST);

	writel(SPDIF_OUT_FDMA_TRIG_16 | SPDIF_OUT_MEMFMT_16_16 |
			SPDIF_OUT_VALID_HW | SPDIF_OUT_USER_HW |
			SPDIF_OUT_CHNLSTA_HW | SPDIF_OUT_PARITY_HW,
			host->io_base + SPDIF_OUT_CFG);

	writel(0x7F, host->io_base + SPDIF_OUT_INT_STA_CLR);
	writel(0x7F, host->io_base + SPDIF_OUT_INT_EN_CLR);
}

__attribute__((used)) static int spdif_out_startup(struct snd_pcm_substream *substream,
		struct snd_soc_dai *cpu_dai)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(cpu_dai);
	int ret;

	if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
		return -EINVAL;

	ret = clk_enable(host->clk);
	if (ret)
		return ret;

	host->running = true;
	spdif_out_configure(host);

	return 0;
}

__attribute__((used)) static void spdif_out_shutdown(struct snd_pcm_substream *substream,
		struct snd_soc_dai *dai)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(dai);

	if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
		return;

	clk_disable(host->clk);
	host->running = false;
}

__attribute__((used)) static void spdif_out_clock(struct spdif_out_dev *host, u32 core_freq,
		u32 rate)
{
	u32 divider, ctrl;

	clk_set_rate(host->clk, core_freq);
	divider = DIV_ROUND_CLOSEST(clk_get_rate(host->clk), (rate * 128));

	ctrl = readl(host->io_base + SPDIF_OUT_CTRL);
	ctrl &= ~SPDIF_DIVIDER_MASK;
	ctrl |= (divider << SPDIF_DIVIDER_SHIFT) & SPDIF_DIVIDER_MASK;
	writel(ctrl, host->io_base + SPDIF_OUT_CTRL);
}

__attribute__((used)) static int spdif_out_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(dai);
	u32 rate, core_freq;

	if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
		return -EINVAL;

	rate = params_rate(params);

	switch (rate) {
	case 8000:
	case 16000:
	case 32000:
	case 64000:
		/*
		 * The clock is multiplied by 10 to bring it to feasible range
		 * of frequencies for sscg
		 */
		core_freq = 64000 * 128 * 10;	/* 81.92 MHz */
		break;
	case 5512:
	case 11025:
	case 22050:
	case 44100:
	case 88200:
	case 176400:
		core_freq = 176400 * 128;	/* 22.5792 MHz */
		break;
	case 48000:
	case 96000:
	case 192000:
	default:
		core_freq = 192000 * 128;	/* 24.576 MHz */
		break;
	}

	spdif_out_clock(host, core_freq, rate);
	host->saved_params.core_freq = core_freq;
	host->saved_params.rate = rate;

	return 0;
}

__attribute__((used)) static int spdif_out_trigger(struct snd_pcm_substream *substream, int cmd,
		struct snd_soc_dai *dai)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(dai);
	u32 ctrl;
	int ret = 0;

	if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
		return -EINVAL;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
			ctrl = readl(host->io_base + SPDIF_OUT_CTRL);
			ctrl &= ~SPDIF_OPMODE_MASK;
			if (!host->saved_params.mute)
				ctrl |= SPDIF_OPMODE_AUD_DATA |
					SPDIF_STATE_NORMAL;
			else
				ctrl |= SPDIF_OPMODE_MUTE_PCM;
			writel(ctrl, host->io_base + SPDIF_OUT_CTRL);
		break;

	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		ctrl = readl(host->io_base + SPDIF_OUT_CTRL);
		ctrl &= ~SPDIF_OPMODE_MASK;
		ctrl |= SPDIF_OPMODE_OFF;
		writel(ctrl, host->io_base + SPDIF_OUT_CTRL);
		break;

	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

__attribute__((used)) static int spdif_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(dai);
	u32 val;

	host->saved_params.mute = mute;
	val = readl(host->io_base + SPDIF_OUT_CTRL);
	val &= ~SPDIF_OPMODE_MASK;

	if (mute)
		val |= SPDIF_OPMODE_MUTE_PCM;
	else {
		if (host->running)
			val |= SPDIF_OPMODE_AUD_DATA | SPDIF_STATE_NORMAL;
		else
			val |= SPDIF_OPMODE_OFF;
	}

	writel(val, host->io_base + SPDIF_OUT_CTRL);
	return 0;
}

__attribute__((used)) static int spdif_mute_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(cpu_dai);

	ucontrol->value.integer.value[0] = host->saved_params.mute;
	return 0;
}

__attribute__((used)) static int spdif_mute_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(cpu_dai);

	if (host->saved_params.mute == ucontrol->value.integer.value[0])
		return 0;

	spdif_digital_mute(cpu_dai, ucontrol->value.integer.value[0]);

	return 1;
}

__attribute__((used)) static int spdif_soc_dai_probe(struct snd_soc_dai *dai)
{
	struct spdif_out_dev *host = snd_soc_dai_get_drvdata(dai);

	host->dma_params_tx.filter_data = &host->dma_params;
	dai->playback_dma_data = &host->dma_params_tx;

	return snd_soc_add_dai_controls(dai, spdif_out_controls,
				ARRAY_SIZE(spdif_out_controls));
}

__attribute__((used)) static int spdif_out_probe(struct platform_device *pdev)
{
	struct spdif_out_dev *host;
	struct spear_spdif_platform_data *pdata;
	struct resource *res;
	int ret;

	host = devm_kzalloc(&pdev->dev, sizeof(*host), GFP_KERNEL);
	if (!host)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	host->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(host->io_base))
		return PTR_ERR(host->io_base);

	host->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(host->clk))
		return PTR_ERR(host->clk);

	pdata = dev_get_platdata(&pdev->dev);

	host->dma_params.data = pdata->dma_params;
	host->dma_params.addr = res->start + SPDIF_OUT_FIFO_DATA;
	host->dma_params.max_burst = 16;
	host->dma_params.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;

	dev_set_drvdata(&pdev->dev, host);

	ret = devm_snd_soc_register_component(&pdev->dev, &spdif_out_component,
					      &spdif_out_dai, 1);
	if (ret)
		return ret;

	return devm_spear_pcm_platform_register(&pdev->dev, &host->config,
						pdata->filter);
}

