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
struct snd_soc_pcm_runtime {int dummy; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct axg_fifo {int /*<<< orphan*/  pclk; int /*<<< orphan*/  map; } ;

/* Variables and functions */
 int AXG_FIFO_MIN_CNT ; 
 int CTRL0_TODDR_EXT_SIGNED ; 
 int CTRL0_TODDR_LSB_POS (unsigned int) ; 
 int CTRL0_TODDR_LSB_POS_MASK ; 
 int CTRL0_TODDR_MSB_POS (unsigned int) ; 
 int CTRL0_TODDR_MSB_POS_MASK ; 
 int CTRL0_TODDR_PP_MODE ; 
 int CTRL0_TODDR_SEL_RESAMPLE ; 
 int CTRL0_TODDR_TYPE (unsigned int) ; 
 int CTRL0_TODDR_TYPE_MASK ; 
 int CTRL1_THRESHOLD (unsigned int) ; 
 int CTRL1_THRESHOLD_MASK ; 
 int EINVAL ; 
 int /*<<< orphan*/  FIFO_CTRL0 ; 
 int /*<<< orphan*/  FIFO_CTRL1 ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_CAPTURE ; 
 int axg_fifo_pcm_new (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int params_physical_width (struct snd_pcm_hw_params*) ; 
 unsigned int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct axg_fifo* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 

__attribute__((used)) static int axg_toddr_pcm_new(struct snd_soc_pcm_runtime *rtd,
			     struct snd_soc_dai *dai)
{
	return axg_fifo_pcm_new(rtd, SNDRV_PCM_STREAM_CAPTURE);
}

__attribute__((used)) static int axg_toddr_dai_hw_params(struct snd_pcm_substream *substream,
				   struct snd_pcm_hw_params *params,
				   struct snd_soc_dai *dai)
{
	struct axg_fifo *fifo = snd_soc_dai_get_drvdata(dai);
	unsigned int type, width, msb = 31;

	/*
	 * NOTE:
	 * Almost all backend will place the MSB at bit 31, except SPDIF Input
	 * which will put it at index 28. When adding support for the SPDIF
	 * Input, we'll need to find which type of backend we are connected to.
	 */

	switch (params_physical_width(params)) {
	case 8:
		type = 0; /* 8 samples of 8 bits */
		break;
	case 16:
		type = 2; /* 4 samples of 16 bits - right justified */
		break;
	case 32:
		type = 4; /* 2 samples of 32 bits - right justified */
		break;
	default:
		return -EINVAL;
	}

	width = params_width(params);

	regmap_update_bits(fifo->map, FIFO_CTRL0,
			   CTRL0_TODDR_TYPE_MASK |
			   CTRL0_TODDR_MSB_POS_MASK |
			   CTRL0_TODDR_LSB_POS_MASK,
			   CTRL0_TODDR_TYPE(type) |
			   CTRL0_TODDR_MSB_POS(msb) |
			   CTRL0_TODDR_LSB_POS(msb - (width - 1)));

	return 0;
}

__attribute__((used)) static int axg_toddr_dai_startup(struct snd_pcm_substream *substream,
				 struct snd_soc_dai *dai)
{
	struct axg_fifo *fifo = snd_soc_dai_get_drvdata(dai);
	unsigned int fifo_threshold;
	int ret;

	/* Enable pclk to access registers and clock the fifo ip */
	ret = clk_prepare_enable(fifo->pclk);
	if (ret)
		return ret;

	/* Select orginal data - resampling not supported ATM */
	regmap_update_bits(fifo->map, FIFO_CTRL0, CTRL0_TODDR_SEL_RESAMPLE, 0);

	/* Only signed format are supported ATM */
	regmap_update_bits(fifo->map, FIFO_CTRL0, CTRL0_TODDR_EXT_SIGNED,
			   CTRL0_TODDR_EXT_SIGNED);

	/* Apply single buffer mode to the interface */
	regmap_update_bits(fifo->map, FIFO_CTRL0, CTRL0_TODDR_PP_MODE, 0);

	/* TODDR does not have a configurable fifo depth */
	fifo_threshold = AXG_FIFO_MIN_CNT - 1;
	regmap_update_bits(fifo->map, FIFO_CTRL1, CTRL1_THRESHOLD_MASK,
			   CTRL1_THRESHOLD(fifo_threshold));

	return 0;
}

__attribute__((used)) static void axg_toddr_dai_shutdown(struct snd_pcm_substream *substream,
				   struct snd_soc_dai *dai)
{
	struct axg_fifo *fifo = snd_soc_dai_get_drvdata(dai);

	clk_disable_unprepare(fifo->pclk);
}

