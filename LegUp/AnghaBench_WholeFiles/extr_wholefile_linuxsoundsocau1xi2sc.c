#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int msbits; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct au1xpsc_audio_data {unsigned long cfg; int /*<<< orphan*/ * dmaids; scalar_t__ mmio; } ;

/* Variables and functions */
 unsigned long CFG_FM_I2S ; 
 unsigned long CFG_FM_LJ ; 
 unsigned long CFG_FM_MASK ; 
 unsigned long CFG_FM_RJ ; 
 unsigned long CFG_IC ; 
 unsigned long CFG_ICK ; 
 unsigned long CFG_RN ; 
 unsigned long CFG_SZ_16 ; 
 unsigned long CFG_SZ_18 ; 
 unsigned long CFG_SZ_20 ; 
 unsigned long CFG_SZ_24 ; 
 unsigned long CFG_SZ_8 ; 
 unsigned long CFG_SZ_MASK ; 
 unsigned long CFG_TN ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned long EN_CE ; 
 unsigned long EN_D ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2S_CFG ; 
 int I2S_ENABLE ; 
 int /*<<< orphan*/  IORESOURCE_DMA ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int PCM_TX ; 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 size_t SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_RESUME 139 
#define  SNDRV_PCM_TRIGGER_START 138 
#define  SNDRV_PCM_TRIGGER_STOP 137 
#define  SNDRV_PCM_TRIGGER_SUSPEND 136 
#define  SND_SOC_DAIFMT_CBS_CFS 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LSB 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_MSB 130 
#define  SND_SOC_DAIFMT_NB_IF 129 
#define  SND_SOC_DAIFMT_NB_NF 128 
 int SUBSTREAM_TYPE (struct snd_pcm_substream*) ; 
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  au1xi2s_component ; 
 int /*<<< orphan*/  au1xi2s_dai_driver ; 
 scalar_t__ devm_ioremap_nocache (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct au1xpsc_audio_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_request_mem_region (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct au1xpsc_audio_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct au1xpsc_audio_data*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 struct au1xpsc_audio_data* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int /*<<< orphan*/  snd_soc_dai_set_dma_data (struct snd_soc_dai*,struct snd_pcm_substream*,int /*<<< orphan*/ *) ; 
 int snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline unsigned long RD(struct au1xpsc_audio_data *ctx, int reg)
{
	return __raw_readl(ctx->mmio + reg);
}

__attribute__((used)) static inline void WR(struct au1xpsc_audio_data *ctx, int reg, unsigned long v)
{
	__raw_writel(v, ctx->mmio + reg);
	wmb();
}

__attribute__((used)) static int au1xi2s_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
	struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(cpu_dai);
	unsigned long c;
	int ret;

	ret = -EINVAL;
	c = ctx->cfg;

	c &= ~CFG_FM_MASK;
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		c |= CFG_FM_I2S;
		break;
	case SND_SOC_DAIFMT_MSB:
		c |= CFG_FM_RJ;
		break;
	case SND_SOC_DAIFMT_LSB:
		c |= CFG_FM_LJ;
		break;
	default:
		goto out;
	}

	c &= ~(CFG_IC | CFG_ICK);		/* IB-IF */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		c |= CFG_IC | CFG_ICK;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		c |= CFG_IC;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		c |= CFG_ICK;
		break;
	case SND_SOC_DAIFMT_IB_IF:
		break;
	default:
		goto out;
	}

	/* I2S controller only supports master */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:	/* CODEC slave */
		break;
	default:
		goto out;
	}

	ret = 0;
	ctx->cfg = c;
out:
	return ret;
}

__attribute__((used)) static int au1xi2s_trigger(struct snd_pcm_substream *substream,
			   int cmd, struct snd_soc_dai *dai)
{
	struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
	int stype = SUBSTREAM_TYPE(substream);

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
		/* power up */
		WR(ctx, I2S_ENABLE, EN_D | EN_CE);
		WR(ctx, I2S_ENABLE, EN_CE);
		ctx->cfg |= (stype == PCM_TX) ? CFG_TN : CFG_RN;
		WR(ctx, I2S_CFG, ctx->cfg);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
		ctx->cfg &= ~((stype == PCM_TX) ? CFG_TN : CFG_RN);
		WR(ctx, I2S_CFG, ctx->cfg);
		WR(ctx, I2S_ENABLE, EN_D);		/* power off */
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static unsigned long msbits_to_reg(int msbits)
{
	switch (msbits) {
	case 8:
		return CFG_SZ_8;
	case 16:
		return CFG_SZ_16;
	case 18:
		return CFG_SZ_18;
	case 20:
		return CFG_SZ_20;
	case 24:
		return CFG_SZ_24;
	}
	return 0;
}

__attribute__((used)) static int au1xi2s_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
	unsigned long v;

	v = msbits_to_reg(params->msbits);
	if (!v)
		return -EINVAL;

	ctx->cfg &= ~CFG_SZ_MASK;
	ctx->cfg |= v;
	return 0;
}

__attribute__((used)) static int au1xi2s_startup(struct snd_pcm_substream *substream,
			   struct snd_soc_dai *dai)
{
	struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
	snd_soc_dai_set_dma_data(dai, substream, &ctx->dmaids[0]);
	return 0;
}

__attribute__((used)) static int au1xi2s_drvprobe(struct platform_device *pdev)
{
	struct resource *iores, *dmares;
	struct au1xpsc_audio_data *ctx;

	ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!iores)
		return -ENODEV;

	if (!devm_request_mem_region(&pdev->dev, iores->start,
				     resource_size(iores),
				     pdev->name))
		return -EBUSY;

	ctx->mmio = devm_ioremap_nocache(&pdev->dev, iores->start,
					 resource_size(iores));
	if (!ctx->mmio)
		return -EBUSY;

	dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
	if (!dmares)
		return -EBUSY;
	ctx->dmaids[SNDRV_PCM_STREAM_PLAYBACK] = dmares->start;

	dmares = platform_get_resource(pdev, IORESOURCE_DMA, 1);
	if (!dmares)
		return -EBUSY;
	ctx->dmaids[SNDRV_PCM_STREAM_CAPTURE] = dmares->start;

	platform_set_drvdata(pdev, ctx);

	return snd_soc_register_component(&pdev->dev, &au1xi2s_component,
					  &au1xi2s_dai_driver, 1);
}

__attribute__((used)) static int au1xi2s_drvremove(struct platform_device *pdev)
{
	struct au1xpsc_audio_data *ctx = platform_get_drvdata(pdev);

	snd_soc_unregister_component(&pdev->dev);

	WR(ctx, I2S_ENABLE, EN_D);	/* clock off, disable */

	return 0;
}

