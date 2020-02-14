#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {TYPE_2__* capture_dma_data; TYPE_1__* playback_dma_data; } ;
struct snd_pcm_substream {int stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int /*<<< orphan*/ * filter_data; } ;
struct TYPE_3__ {int /*<<< orphan*/ * filter_data; } ;
struct ep93xx_i2s_info {unsigned int regs; unsigned int mclk; unsigned int sclk; unsigned int lrclk; TYPE_2__ dma_params_rx; TYPE_1__ dma_params_tx; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_SND_EP93XX_SOC_I2S_WATCHDOG ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned int EP93XX_I2S_CLKCFG_CKP ; 
 unsigned int EP93XX_I2S_CLKCFG_LRS ; 
 unsigned int EP93XX_I2S_CLKCFG_MASTER ; 
 unsigned int EP93XX_I2S_CLKCFG_REL ; 
 unsigned int EP93XX_I2S_GLCTRL ; 
 unsigned int EP93XX_I2S_GLSTS ; 
 int EP93XX_I2S_GLSTS_TX0_FIFO_FULL ; 
 unsigned int EP93XX_I2S_I2STX0LFT ; 
 unsigned int EP93XX_I2S_I2STX0RT ; 
 unsigned int EP93XX_I2S_RX0EN ; 
 unsigned int EP93XX_I2S_RXCLKCFG ; 
 unsigned int EP93XX_I2S_RXLINCTRLDATA ; 
 unsigned int EP93XX_I2S_RXLINCTRLDATA_R_JUST ; 
 unsigned int EP93XX_I2S_RXWRDLEN ; 
 unsigned int EP93XX_I2S_TX0EN ; 
 unsigned int EP93XX_I2S_TXCLKCFG ; 
 unsigned int EP93XX_I2S_TXCTRL ; 
 unsigned int EP93XX_I2S_TXCTRL_TXEMPTY_LVL ; 
 unsigned int EP93XX_I2S_TXCTRL_TXUFIE ; 
 unsigned int EP93XX_I2S_TXLINCTRLDATA ; 
 unsigned int EP93XX_I2S_TXLINCTRLDATA_R_JUST ; 
 unsigned int EP93XX_I2S_TXWRDLEN ; 
 unsigned int EP93XX_I2S_WRDLEN_16 ; 
 unsigned int EP93XX_I2S_WRDLEN_24 ; 
 unsigned int EP93XX_I2S_WRDLEN_32 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 int PTR_ERR (unsigned int) ; 
#define  SNDRV_PCM_FORMAT_S16_LE 139 
#define  SNDRV_PCM_FORMAT_S24_LE 138 
#define  SNDRV_PCM_FORMAT_S32_LE 137 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 int SNDRV_PCM_STREAM_PLAYBACK ; 
 int SND_SOC_CLOCK_IN ; 
#define  SND_SOC_DAIFMT_CBM_CFM 136 
#define  SND_SOC_DAIFMT_CBS_CFS 135 
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
 int __raw_readl (unsigned int) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  clk_disable (unsigned int) ; 
 int /*<<< orphan*/  clk_enable (unsigned int) ; 
 void* clk_get (int /*<<< orphan*/ *,char*) ; 
 unsigned int clk_get_rate (unsigned int) ; 
 int /*<<< orphan*/  clk_put (unsigned int) ; 
 int clk_set_rate (unsigned int,unsigned int) ; 
 struct ep93xx_i2s_info* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct ep93xx_i2s_info*) ; 
 int devm_ep93xx_pcm_platform_register (int /*<<< orphan*/ *) ; 
 unsigned int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct ep93xx_i2s_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ep93xx_i2s_info*) ; 
 int /*<<< orphan*/  ep93xx_i2s_component ; 
 int /*<<< orphan*/  ep93xx_i2s_dai ; 
 int /*<<< orphan*/ * ep93xx_i2s_dma_data ; 
 int params_format (struct snd_pcm_hw_params*) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ep93xx_i2s_info* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void ep93xx_i2s_write_reg(struct ep93xx_i2s_info *info,
					unsigned reg, unsigned val)
{
	__raw_writel(val, info->regs + reg);
}

__attribute__((used)) static inline unsigned ep93xx_i2s_read_reg(struct ep93xx_i2s_info *info,
					   unsigned reg)
{
	return __raw_readl(info->regs + reg);
}

__attribute__((used)) static void ep93xx_i2s_enable(struct ep93xx_i2s_info *info, int stream)
{
	unsigned base_reg;

	if ((ep93xx_i2s_read_reg(info, EP93XX_I2S_TX0EN) & 0x1) == 0 &&
	    (ep93xx_i2s_read_reg(info, EP93XX_I2S_RX0EN) & 0x1) == 0) {
		/* Enable clocks */
		clk_enable(info->mclk);
		clk_enable(info->sclk);
		clk_enable(info->lrclk);

		/* Enable i2s */
		ep93xx_i2s_write_reg(info, EP93XX_I2S_GLCTRL, 1);
	}

	/* Enable fifo */
	if (stream == SNDRV_PCM_STREAM_PLAYBACK)
		base_reg = EP93XX_I2S_TX0EN;
	else
		base_reg = EP93XX_I2S_RX0EN;
	ep93xx_i2s_write_reg(info, base_reg, 1);

	/* Enable TX IRQs (FIFO empty or underflow) */
	if (IS_ENABLED(CONFIG_SND_EP93XX_SOC_I2S_WATCHDOG) &&
	    stream == SNDRV_PCM_STREAM_PLAYBACK)
		ep93xx_i2s_write_reg(info, EP93XX_I2S_TXCTRL,
				     EP93XX_I2S_TXCTRL_TXEMPTY_LVL |
				     EP93XX_I2S_TXCTRL_TXUFIE);
}

__attribute__((used)) static void ep93xx_i2s_disable(struct ep93xx_i2s_info *info, int stream)
{
	unsigned base_reg;

	/* Disable IRQs */
	if (IS_ENABLED(CONFIG_SND_EP93XX_SOC_I2S_WATCHDOG) &&
	    stream == SNDRV_PCM_STREAM_PLAYBACK)
		ep93xx_i2s_write_reg(info, EP93XX_I2S_TXCTRL, 0);

	/* Disable fifo */
	if (stream == SNDRV_PCM_STREAM_PLAYBACK)
		base_reg = EP93XX_I2S_TX0EN;
	else
		base_reg = EP93XX_I2S_RX0EN;
	ep93xx_i2s_write_reg(info, base_reg, 0);

	if ((ep93xx_i2s_read_reg(info, EP93XX_I2S_TX0EN) & 0x1) == 0 &&
	    (ep93xx_i2s_read_reg(info, EP93XX_I2S_RX0EN) & 0x1) == 0) {
		/* Disable i2s */
		ep93xx_i2s_write_reg(info, EP93XX_I2S_GLCTRL, 0);

		/* Disable clocks */
		clk_disable(info->lrclk);
		clk_disable(info->sclk);
		clk_disable(info->mclk);
	}
}

__attribute__((used)) static irqreturn_t ep93xx_i2s_interrupt(int irq, void *dev_id)
{
	struct ep93xx_i2s_info *info = dev_id;

	/* Disable FIFO */
	ep93xx_i2s_write_reg(info, EP93XX_I2S_TX0EN, 0);
	/*
	 * Fill TX FIFO with zeroes, this way we can defer next IRQs as much as
	 * possible and get more time for DMA to catch up. Actually there are
	 * only 8 samples in this FIFO, so even on 8kHz maximum deferral here is
	 * 1ms.
	 */
	while (!(ep93xx_i2s_read_reg(info, EP93XX_I2S_GLSTS) &
		 EP93XX_I2S_GLSTS_TX0_FIFO_FULL)) {
		ep93xx_i2s_write_reg(info, EP93XX_I2S_I2STX0LFT, 0);
		ep93xx_i2s_write_reg(info, EP93XX_I2S_I2STX0RT, 0);
	}
	/* Re-enable FIFO */
	ep93xx_i2s_write_reg(info, EP93XX_I2S_TX0EN, 1);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ep93xx_i2s_dai_probe(struct snd_soc_dai *dai)
{
	struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);

	info->dma_params_tx.filter_data =
		&ep93xx_i2s_dma_data[SNDRV_PCM_STREAM_PLAYBACK];
	info->dma_params_rx.filter_data =
		&ep93xx_i2s_dma_data[SNDRV_PCM_STREAM_CAPTURE];

	dai->playback_dma_data = &info->dma_params_tx;
	dai->capture_dma_data = &info->dma_params_rx;

	return 0;
}

__attribute__((used)) static void ep93xx_i2s_shutdown(struct snd_pcm_substream *substream,
				struct snd_soc_dai *dai)
{
	struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);

	ep93xx_i2s_disable(info, substream->stream);
}

__attribute__((used)) static int ep93xx_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
				  unsigned int fmt)
{
	struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(cpu_dai);
	unsigned int clk_cfg;
	unsigned int txlin_ctrl = 0;
	unsigned int rxlin_ctrl = 0;

	clk_cfg  = ep93xx_i2s_read_reg(info, EP93XX_I2S_RXCLKCFG);

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		clk_cfg |= EP93XX_I2S_CLKCFG_REL;
		break;

	case SND_SOC_DAIFMT_LEFT_J:
		clk_cfg &= ~EP93XX_I2S_CLKCFG_REL;
		break;

	case SND_SOC_DAIFMT_RIGHT_J:
		clk_cfg &= ~EP93XX_I2S_CLKCFG_REL;
		rxlin_ctrl |= EP93XX_I2S_RXLINCTRLDATA_R_JUST;
		txlin_ctrl |= EP93XX_I2S_TXLINCTRLDATA_R_JUST;
		break;

	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		/* CPU is master */
		clk_cfg |= EP93XX_I2S_CLKCFG_MASTER;
		break;

	case SND_SOC_DAIFMT_CBM_CFM:
		/* Codec is master */
		clk_cfg &= ~EP93XX_I2S_CLKCFG_MASTER;
		break;

	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		/* Negative bit clock, lrclk low on left word */
		clk_cfg &= ~(EP93XX_I2S_CLKCFG_CKP | EP93XX_I2S_CLKCFG_LRS);
		break;

	case SND_SOC_DAIFMT_NB_IF:
		/* Negative bit clock, lrclk low on right word */
		clk_cfg &= ~EP93XX_I2S_CLKCFG_CKP;
		clk_cfg |= EP93XX_I2S_CLKCFG_LRS;
		break;

	case SND_SOC_DAIFMT_IB_NF:
		/* Positive bit clock, lrclk low on left word */
		clk_cfg |= EP93XX_I2S_CLKCFG_CKP;
		clk_cfg &= ~EP93XX_I2S_CLKCFG_LRS;
		break;

	case SND_SOC_DAIFMT_IB_IF:
		/* Positive bit clock, lrclk low on right word */
		clk_cfg |= EP93XX_I2S_CLKCFG_CKP | EP93XX_I2S_CLKCFG_LRS;
		break;
	}

	/* Write new register values */
	ep93xx_i2s_write_reg(info, EP93XX_I2S_RXCLKCFG, clk_cfg);
	ep93xx_i2s_write_reg(info, EP93XX_I2S_TXCLKCFG, clk_cfg);
	ep93xx_i2s_write_reg(info, EP93XX_I2S_RXLINCTRLDATA, rxlin_ctrl);
	ep93xx_i2s_write_reg(info, EP93XX_I2S_TXLINCTRLDATA, txlin_ctrl);
	return 0;
}

__attribute__((used)) static int ep93xx_i2s_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
	unsigned word_len, div, sdiv, lrdiv;
	int err;

	switch (params_format(params)) {
	case SNDRV_PCM_FORMAT_S16_LE:
		word_len = EP93XX_I2S_WRDLEN_16;
		break;

	case SNDRV_PCM_FORMAT_S24_LE:
		word_len = EP93XX_I2S_WRDLEN_24;
		break;

	case SNDRV_PCM_FORMAT_S32_LE:
		word_len = EP93XX_I2S_WRDLEN_32;
		break;

	default:
		return -EINVAL;
	}

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		ep93xx_i2s_write_reg(info, EP93XX_I2S_TXWRDLEN, word_len);
	else
		ep93xx_i2s_write_reg(info, EP93XX_I2S_RXWRDLEN, word_len);

	/*
	 * EP93xx I2S module can be setup so SCLK / LRCLK value can be
	 * 32, 64, 128. MCLK / SCLK value can be 2 and 4.
	 * We set LRCLK equal to `rate' and minimum SCLK / LRCLK 
	 * value is 64, because our sample size is 32 bit * 2 channels.
	 * I2S standard permits us to transmit more bits than
	 * the codec uses.
	 */
	div = clk_get_rate(info->mclk) / params_rate(params);
	sdiv = 4;
	if (div > (256 + 512) / 2) {
		lrdiv = 128;
	} else {
		lrdiv = 64;
		if (div < (128 + 256) / 2)
			sdiv = 2;
	}

	err = clk_set_rate(info->sclk, clk_get_rate(info->mclk) / sdiv);
	if (err)
		return err;

	err = clk_set_rate(info->lrclk, clk_get_rate(info->sclk) / lrdiv);
	if (err)
		return err;

	ep93xx_i2s_enable(info, substream->stream);
	return 0;
}

__attribute__((used)) static int ep93xx_i2s_set_sysclk(struct snd_soc_dai *cpu_dai, int clk_id,
				 unsigned int freq, int dir)
{
	struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(cpu_dai);

	if (dir == SND_SOC_CLOCK_IN || clk_id != 0)
		return -EINVAL;

	return clk_set_rate(info->mclk, freq);
}

__attribute__((used)) static int ep93xx_i2s_probe(struct platform_device *pdev)
{
	struct ep93xx_i2s_info *info;
	struct resource *res;
	int err;

	info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	info->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(info->regs))
		return PTR_ERR(info->regs);

	if (IS_ENABLED(CONFIG_SND_EP93XX_SOC_I2S_WATCHDOG)) {
		int irq = platform_get_irq(pdev, 0);
		if (irq <= 0)
			return irq < 0 ? irq : -ENODEV;

		err = devm_request_irq(&pdev->dev, irq, ep93xx_i2s_interrupt, 0,
				       pdev->name, info);
		if (err)
			return err;
	}

	info->mclk = clk_get(&pdev->dev, "mclk");
	if (IS_ERR(info->mclk)) {
		err = PTR_ERR(info->mclk);
		goto fail;
	}

	info->sclk = clk_get(&pdev->dev, "sclk");
	if (IS_ERR(info->sclk)) {
		err = PTR_ERR(info->sclk);
		goto fail_put_mclk;
	}

	info->lrclk = clk_get(&pdev->dev, "lrclk");
	if (IS_ERR(info->lrclk)) {
		err = PTR_ERR(info->lrclk);
		goto fail_put_sclk;
	}

	dev_set_drvdata(&pdev->dev, info);

	err = snd_soc_register_component(&pdev->dev, &ep93xx_i2s_component,
					 &ep93xx_i2s_dai, 1);
	if (err)
		goto fail_put_lrclk;

	err = devm_ep93xx_pcm_platform_register(&pdev->dev);
	if (err)
		goto fail_unregister;

	return 0;

fail_unregister:
	snd_soc_unregister_component(&pdev->dev);
fail_put_lrclk:
	clk_put(info->lrclk);
fail_put_sclk:
	clk_put(info->sclk);
fail_put_mclk:
	clk_put(info->mclk);
fail:
	return err;
}

__attribute__((used)) static int ep93xx_i2s_remove(struct platform_device *pdev)
{
	struct ep93xx_i2s_info *info = dev_get_drvdata(&pdev->dev);

	snd_soc_unregister_component(&pdev->dev);
	clk_put(info->lrclk);
	clk_put(info->sclk);
	clk_put(info->mclk);
	return 0;
}

