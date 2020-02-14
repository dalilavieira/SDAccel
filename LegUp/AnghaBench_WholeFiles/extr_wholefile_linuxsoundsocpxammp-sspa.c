#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
struct sspa_priv {unsigned int sysclk; unsigned int audio_clk; unsigned int dai_fmt; struct ssp_device* sspa; struct snd_dmaengine_dai_dma_data* dma_params; int /*<<< orphan*/  running_cnt; } ;
struct ssp_device {unsigned int mmio_base; unsigned int clk; scalar_t__ phys_base; TYPE_1__* pdev; } ;
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {size_t stream; struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_dmaengine_dai_dma_data {scalar_t__ addr; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (unsigned int) ; 
#define  MMP_SSPA_CLK 147 
#define  MMP_SSPA_CLK_AUDIO 146 
#define  MMP_SSPA_CLK_PLL 145 
#define  MMP_SSPA_CLK_VCXO 144 
#define  MMP_SYSCLK 143 
 int PTR_ERR (unsigned int) ; 
#define  SNDRV_PCM_FORMAT_S16_LE 142 
#define  SNDRV_PCM_FORMAT_S20_3LE 141 
#define  SNDRV_PCM_FORMAT_S24_3LE 140 
#define  SNDRV_PCM_FORMAT_S32_LE 139 
#define  SNDRV_PCM_FORMAT_S8 138 
 size_t SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 137 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 136 
#define  SNDRV_PCM_TRIGGER_RESUME 135 
#define  SNDRV_PCM_TRIGGER_START 134 
#define  SNDRV_PCM_TRIGGER_STOP 133 
#define  SNDRV_PCM_TRIGGER_SUSPEND 132 
#define  SND_SOC_DAIFMT_CBM_CFM 131 
#define  SND_SOC_DAIFMT_CBS_CFS 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 128 
 int /*<<< orphan*/  SSPA_CTL_16_BITS ; 
 int /*<<< orphan*/  SSPA_CTL_20_BITS ; 
 int /*<<< orphan*/  SSPA_CTL_24_BITS ; 
 int /*<<< orphan*/  SSPA_CTL_32_BITS ; 
 int /*<<< orphan*/  SSPA_CTL_8_BITS ; 
 unsigned int SSPA_CTL_XDATDLY (int) ; 
 unsigned int SSPA_CTL_XFRLEN1 (scalar_t__) ; 
 unsigned int SSPA_CTL_XFRLEN1_MASK ; 
 unsigned int SSPA_CTL_XSSZ1 (int /*<<< orphan*/ ) ; 
 unsigned int SSPA_CTL_XSSZ1_MASK ; 
 unsigned int SSPA_CTL_XWDLEN1 (int /*<<< orphan*/ ) ; 
 unsigned int SSPA_CTL_XWDLEN1_MASK ; 
 unsigned int SSPA_RXCTL ; 
 scalar_t__ SSPA_RXD ; 
 unsigned int SSPA_RXFIFO_UL ; 
 unsigned int SSPA_RXSP ; 
 unsigned int SSPA_SP_FFLUSH ; 
 unsigned int SSPA_SP_FSP ; 
 unsigned int SSPA_SP_FWID (int) ; 
 unsigned int SSPA_SP_MSL ; 
 unsigned int SSPA_SP_S_EN ; 
 unsigned int SSPA_SP_S_RST ; 
 unsigned int SSPA_SP_WEN ; 
 unsigned int SSPA_TXCTL ; 
 scalar_t__ SSPA_TXD ; 
 unsigned int SSPA_TXFIFO_LL ; 
 unsigned int SSPA_TXSP ; 
 unsigned int SSPA_TXSP_FPER (int) ; 
 unsigned int __raw_readl (unsigned int) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  clk_disable (unsigned int) ; 
 int /*<<< orphan*/  clk_enable (unsigned int) ; 
 void* clk_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  clk_put (unsigned int) ; 
 int clk_set_rate (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct sspa_priv* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 unsigned int devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct snd_dmaengine_dai_dma_data* devm_kcalloc (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mmp_sspa_component ; 
 int /*<<< orphan*/  mmp_sspa_dai ; 
 scalar_t__ params_channels (struct snd_pcm_hw_params*) ; 
 int params_format (struct snd_pcm_hw_params*) ; 
 struct sspa_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sspa_priv*) ; 
 struct sspa_priv* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int /*<<< orphan*/  snd_soc_dai_set_dma_data (struct snd_soc_dai*,struct snd_pcm_substream*,struct snd_dmaengine_dai_dma_data*) ; 
 int /*<<< orphan*/  snd_soc_dai_set_drvdata (struct snd_soc_dai*,struct sspa_priv*) ; 

__attribute__((used)) static void mmp_sspa_write_reg(struct ssp_device *sspa, u32 reg, u32 val)
{
	__raw_writel(val, sspa->mmio_base + reg);
}

__attribute__((used)) static u32 mmp_sspa_read_reg(struct ssp_device *sspa, u32 reg)
{
	return __raw_readl(sspa->mmio_base + reg);
}

__attribute__((used)) static void mmp_sspa_tx_enable(struct ssp_device *sspa)
{
	unsigned int sspa_sp;

	sspa_sp = mmp_sspa_read_reg(sspa, SSPA_TXSP);
	sspa_sp |= SSPA_SP_S_EN;
	sspa_sp |= SSPA_SP_WEN;
	mmp_sspa_write_reg(sspa, SSPA_TXSP, sspa_sp);
}

__attribute__((used)) static void mmp_sspa_tx_disable(struct ssp_device *sspa)
{
	unsigned int sspa_sp;

	sspa_sp = mmp_sspa_read_reg(sspa, SSPA_TXSP);
	sspa_sp &= ~SSPA_SP_S_EN;
	sspa_sp |= SSPA_SP_WEN;
	mmp_sspa_write_reg(sspa, SSPA_TXSP, sspa_sp);
}

__attribute__((used)) static void mmp_sspa_rx_enable(struct ssp_device *sspa)
{
	unsigned int sspa_sp;

	sspa_sp = mmp_sspa_read_reg(sspa, SSPA_RXSP);
	sspa_sp |= SSPA_SP_S_EN;
	sspa_sp |= SSPA_SP_WEN;
	mmp_sspa_write_reg(sspa, SSPA_RXSP, sspa_sp);
}

__attribute__((used)) static void mmp_sspa_rx_disable(struct ssp_device *sspa)
{
	unsigned int sspa_sp;

	sspa_sp = mmp_sspa_read_reg(sspa, SSPA_RXSP);
	sspa_sp &= ~SSPA_SP_S_EN;
	sspa_sp |= SSPA_SP_WEN;
	mmp_sspa_write_reg(sspa, SSPA_RXSP, sspa_sp);
}

__attribute__((used)) static int mmp_sspa_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	struct sspa_priv *priv = snd_soc_dai_get_drvdata(dai);

	clk_enable(priv->sysclk);
	clk_enable(priv->sspa->clk);

	return 0;
}

__attribute__((used)) static void mmp_sspa_shutdown(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	struct sspa_priv *priv = snd_soc_dai_get_drvdata(dai);

	clk_disable(priv->sspa->clk);
	clk_disable(priv->sysclk);

}

__attribute__((used)) static int mmp_sspa_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
				    int clk_id, unsigned int freq, int dir)
{
	struct sspa_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
	int ret = 0;

	switch (clk_id) {
	case MMP_SSPA_CLK_AUDIO:
		ret = clk_set_rate(priv->audio_clk, freq);
		if (ret)
			return ret;
		break;
	case MMP_SSPA_CLK_PLL:
	case MMP_SSPA_CLK_VCXO:
		/* not support yet */
		return -EINVAL;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int mmp_sspa_set_dai_pll(struct snd_soc_dai *cpu_dai, int pll_id,
				 int source, unsigned int freq_in,
				 unsigned int freq_out)
{
	struct sspa_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
	int ret = 0;

	switch (pll_id) {
	case MMP_SYSCLK:
		ret = clk_set_rate(priv->sysclk, freq_out);
		if (ret)
			return ret;
		break;
	case MMP_SSPA_CLK:
		ret = clk_set_rate(priv->sspa->clk, freq_out);
		if (ret)
			return ret;
		break;
	default:
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static int mmp_sspa_set_dai_fmt(struct snd_soc_dai *cpu_dai,
				 unsigned int fmt)
{
	struct sspa_priv *sspa_priv = snd_soc_dai_get_drvdata(cpu_dai);
	struct ssp_device *sspa = sspa_priv->sspa;
	u32 sspa_sp, sspa_ctrl;

	/* check if we need to change anything at all */
	if (sspa_priv->dai_fmt == fmt)
		return 0;

	/* we can only change the settings if the port is not in use */
	if ((mmp_sspa_read_reg(sspa, SSPA_TXSP) & SSPA_SP_S_EN) ||
	    (mmp_sspa_read_reg(sspa, SSPA_RXSP) & SSPA_SP_S_EN)) {
		dev_err(&sspa->pdev->dev,
			"can't change hardware dai format: stream is in use\n");
		return -EINVAL;
	}

	/* reset port settings */
	sspa_sp   = SSPA_SP_WEN | SSPA_SP_S_RST | SSPA_SP_FFLUSH;
	sspa_ctrl = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		sspa_sp |= SSPA_SP_MSL;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		sspa_sp |= SSPA_SP_FSP;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		sspa_sp |= SSPA_TXSP_FPER(63);
		sspa_sp |= SSPA_SP_FWID(31);
		sspa_ctrl |= SSPA_CTL_XDATDLY(1);
		break;
	default:
		return -EINVAL;
	}

	mmp_sspa_write_reg(sspa, SSPA_TXSP, sspa_sp);
	mmp_sspa_write_reg(sspa, SSPA_RXSP, sspa_sp);

	sspa_sp &= ~(SSPA_SP_S_RST | SSPA_SP_FFLUSH);
	mmp_sspa_write_reg(sspa, SSPA_TXSP, sspa_sp);
	mmp_sspa_write_reg(sspa, SSPA_RXSP, sspa_sp);

	/*
	 * FIXME: hw issue, for the tx serial port,
	 * can not config the master/slave mode;
	 * so must clean this bit.
	 * The master/slave mode has been set in the
	 * rx port.
	 */
	sspa_sp &= ~SSPA_SP_MSL;
	mmp_sspa_write_reg(sspa, SSPA_TXSP, sspa_sp);

	mmp_sspa_write_reg(sspa, SSPA_TXCTL, sspa_ctrl);
	mmp_sspa_write_reg(sspa, SSPA_RXCTL, sspa_ctrl);

	/* Since we are configuring the timings for the format by hand
	 * we have to defer some things until hw_params() where we
	 * know parameters like the sample size.
	 */
	sspa_priv->dai_fmt = fmt;
	return 0;
}

__attribute__((used)) static int mmp_sspa_hw_params(struct snd_pcm_substream *substream,
			       struct snd_pcm_hw_params *params,
			       struct snd_soc_dai *dai)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct sspa_priv *sspa_priv = snd_soc_dai_get_drvdata(dai);
	struct ssp_device *sspa = sspa_priv->sspa;
	struct snd_dmaengine_dai_dma_data *dma_params;
	u32 sspa_ctrl;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		sspa_ctrl = mmp_sspa_read_reg(sspa, SSPA_TXCTL);
	else
		sspa_ctrl = mmp_sspa_read_reg(sspa, SSPA_RXCTL);

	sspa_ctrl &= ~SSPA_CTL_XFRLEN1_MASK;
	sspa_ctrl |= SSPA_CTL_XFRLEN1(params_channels(params) - 1);
	sspa_ctrl &= ~SSPA_CTL_XWDLEN1_MASK;
	sspa_ctrl |= SSPA_CTL_XWDLEN1(SSPA_CTL_32_BITS);
	sspa_ctrl &= ~SSPA_CTL_XSSZ1_MASK;

	switch (params_format(params)) {
	case SNDRV_PCM_FORMAT_S8:
		sspa_ctrl |= SSPA_CTL_XSSZ1(SSPA_CTL_8_BITS);
		break;
	case SNDRV_PCM_FORMAT_S16_LE:
		sspa_ctrl |= SSPA_CTL_XSSZ1(SSPA_CTL_16_BITS);
		break;
	case SNDRV_PCM_FORMAT_S20_3LE:
		sspa_ctrl |= SSPA_CTL_XSSZ1(SSPA_CTL_20_BITS);
		break;
	case SNDRV_PCM_FORMAT_S24_3LE:
		sspa_ctrl |= SSPA_CTL_XSSZ1(SSPA_CTL_24_BITS);
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
		sspa_ctrl |= SSPA_CTL_XSSZ1(SSPA_CTL_32_BITS);
		break;
	default:
		return -EINVAL;
	}

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		mmp_sspa_write_reg(sspa, SSPA_TXCTL, sspa_ctrl);
		mmp_sspa_write_reg(sspa, SSPA_TXFIFO_LL, 0x1);
	} else {
		mmp_sspa_write_reg(sspa, SSPA_RXCTL, sspa_ctrl);
		mmp_sspa_write_reg(sspa, SSPA_RXFIFO_UL, 0x0);
	}

	dma_params = &sspa_priv->dma_params[substream->stream];
	dma_params->addr = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ?
				(sspa->phys_base + SSPA_TXD) :
				(sspa->phys_base + SSPA_RXD);
	snd_soc_dai_set_dma_data(cpu_dai, substream, dma_params);
	return 0;
}

__attribute__((used)) static int mmp_sspa_trigger(struct snd_pcm_substream *substream, int cmd,
			     struct snd_soc_dai *dai)
{
	struct sspa_priv *sspa_priv = snd_soc_dai_get_drvdata(dai);
	struct ssp_device *sspa = sspa_priv->sspa;
	int ret = 0;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		/*
		 * whatever playback or capture, must enable rx.
		 * this is a hw issue, so need check if rx has been
		 * enabled or not; if has been enabled by another
		 * stream, do not enable again.
		 */
		if (!sspa_priv->running_cnt)
			mmp_sspa_rx_enable(sspa);

		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
			mmp_sspa_tx_enable(sspa);

		sspa_priv->running_cnt++;
		break;

	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		sspa_priv->running_cnt--;

		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
			mmp_sspa_tx_disable(sspa);

		/* have no capture stream, disable rx port */
		if (!sspa_priv->running_cnt)
			mmp_sspa_rx_disable(sspa);
		break;

	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int mmp_sspa_probe(struct snd_soc_dai *dai)
{
	struct sspa_priv *priv = dev_get_drvdata(dai->dev);

	snd_soc_dai_set_drvdata(dai, priv);
	return 0;

}

__attribute__((used)) static int asoc_mmp_sspa_probe(struct platform_device *pdev)
{
	struct sspa_priv *priv;
	struct resource *res;

	priv = devm_kzalloc(&pdev->dev,
				sizeof(struct sspa_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->sspa = devm_kzalloc(&pdev->dev,
				sizeof(struct ssp_device), GFP_KERNEL);
	if (priv->sspa == NULL)
		return -ENOMEM;

	priv->dma_params = devm_kcalloc(&pdev->dev,
			2, sizeof(struct snd_dmaengine_dai_dma_data),
			GFP_KERNEL);
	if (priv->dma_params == NULL)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->sspa->mmio_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->sspa->mmio_base))
		return PTR_ERR(priv->sspa->mmio_base);

	priv->sspa->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(priv->sspa->clk))
		return PTR_ERR(priv->sspa->clk);

	priv->audio_clk = clk_get(NULL, "mmp-audio");
	if (IS_ERR(priv->audio_clk))
		return PTR_ERR(priv->audio_clk);

	priv->sysclk = clk_get(NULL, "mmp-sysclk");
	if (IS_ERR(priv->sysclk)) {
		clk_put(priv->audio_clk);
		return PTR_ERR(priv->sysclk);
	}
	clk_enable(priv->audio_clk);
	priv->dai_fmt = (unsigned int) -1;
	platform_set_drvdata(pdev, priv);

	return devm_snd_soc_register_component(&pdev->dev, &mmp_sspa_component,
					       &mmp_sspa_dai, 1);
}

__attribute__((used)) static int asoc_mmp_sspa_remove(struct platform_device *pdev)
{
	struct sspa_priv *priv = platform_get_drvdata(pdev);

	clk_disable(priv->audio_clk);
	clk_put(priv->audio_clk);
	clk_put(priv->sysclk);
	return 0;
}

