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
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_card {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PXA_SSP_CLK_AUDIO ; 
 int /*<<< orphan*/  WM9713_PCMCLK_DIV ; 
 int /*<<< orphan*/  WM9713_PCMCLK_PLL_DIV ; 
 int /*<<< orphan*/  WM9713_PCMDIV (unsigned int) ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int clk_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  clk_get_rate (int /*<<< orphan*/ ) ; 
 scalar_t__ clk_pout ; 
 int /*<<< orphan*/  clk_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pout ; 
 int snd_soc_dai_set_clkdiv (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dai_set_pll (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int zylonite_wm9713_init(struct snd_soc_pcm_runtime *rtd)
{
	if (clk_pout)
		snd_soc_dai_set_pll(rtd->codec_dai, 0, 0,
				    clk_get_rate(pout), 0);

	return 0;
}

__attribute__((used)) static int zylonite_voice_hw_params(struct snd_pcm_substream *substream,
				    struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	unsigned int wm9713_div = 0;
	int ret = 0;
	int rate = params_rate(params);

	/* Only support ratios that we can generate neatly from the AC97
	 * based master clock - in particular, this excludes 44.1kHz.
	 * In most applications the voice DAC will be used for telephony
	 * data so multiples of 8kHz will be the common case.
	 */
	switch (rate) {
	case 8000:
		wm9713_div = 12;
		break;
	case 16000:
		wm9713_div = 6;
		break;
	case 48000:
		wm9713_div = 2;
		break;
	default:
		/* Don't support OSS emulation */
		return -EINVAL;
	}

	ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_AUDIO, 0, 1);
	if (ret < 0)
		return ret;

	if (clk_pout)
		ret = snd_soc_dai_set_clkdiv(codec_dai, WM9713_PCMCLK_PLL_DIV,
					     WM9713_PCMDIV(wm9713_div));
	else
		ret = snd_soc_dai_set_clkdiv(codec_dai, WM9713_PCMCLK_DIV,
					     WM9713_PCMDIV(wm9713_div));
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int zylonite_probe(struct snd_soc_card *card)
{
	int ret;

	if (clk_pout) {
		pout = clk_get(NULL, "CLK_POUT");
		if (IS_ERR(pout)) {
			dev_err(card->dev, "Unable to obtain CLK_POUT: %ld\n",
				PTR_ERR(pout));
			return PTR_ERR(pout);
		}

		ret = clk_enable(pout);
		if (ret != 0) {
			dev_err(card->dev, "Unable to enable CLK_POUT: %d\n",
				ret);
			clk_put(pout);
			return ret;
		}

		dev_dbg(card->dev, "MCLK enabled at %luHz\n",
			clk_get_rate(pout));
	}

	return 0;
}

__attribute__((used)) static int zylonite_remove(struct snd_soc_card *card)
{
	if (clk_pout) {
		clk_disable(pout);
		clk_put(pout);
	}

	return 0;
}

__attribute__((used)) static int zylonite_suspend_post(struct snd_soc_card *card)
{
	if (clk_pout)
		clk_disable(pout);

	return 0;
}

__attribute__((used)) static int zylonite_resume_pre(struct snd_soc_card *card)
{
	int ret = 0;

	if (clk_pout) {
		ret = clk_enable(pout);
		if (ret != 0)
			dev_err(card->dev, "Unable to enable CLK_POUT: %d\n",
				ret);
	}

	return ret;
}

