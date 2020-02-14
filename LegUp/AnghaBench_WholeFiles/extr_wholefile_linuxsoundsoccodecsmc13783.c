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
struct snd_soc_dai {scalar_t__ id; struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct mc13783_priv {scalar_t__ adc_ssi_port; scalar_t__ dac_ssi_port; int /*<<< orphan*/  mc13xxx; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 unsigned int AUDIO_BCL_INV ; 
 unsigned int AUDIO_CFS (int) ; 
 unsigned int AUDIO_CFS_INV ; 
 unsigned int AUDIO_CLK (int) ; 
 unsigned int AUDIO_CLK_SEL ; 
 unsigned int AUDIO_CODEC_CDCFS8K16K ; 
 unsigned int AUDIO_CSM ; 
 unsigned int AUDIO_C_CLK_EN ; 
 unsigned int AUDIO_C_RESET ; 
 int AUDIO_SSI_SEL ; 
 int EINVAL ; 
 unsigned int MC13783_AUDIO_CODEC ; 
 unsigned int MC13783_AUDIO_DAC ; 
 unsigned int MC13783_AUDIO_RX0 ; 
 unsigned int MC13783_AUDIO_RX1 ; 
 unsigned int MC13783_AUDIO_TX ; 
 int MC13783_CLK_CLIB ; 
 scalar_t__ MC13783_ID_STEREO_DAC ; 
 scalar_t__ MC13783_SSI1_PORT ; 
 unsigned int MC13783_SSI_NETWORK ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_DAIFMT_CBM_CFM 137 
#define  SND_SOC_DAIFMT_CBM_CFS 136 
#define  SND_SOC_DAIFMT_CBS_CFM 135 
#define  SND_SOC_DAIFMT_CBS_CFS 134 
#define  SND_SOC_DAIFMT_DSP_A 133 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 132 
#define  SND_SOC_DAIFMT_IB_IF 131 
#define  SND_SOC_DAIFMT_IB_NF 130 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 129 
#define  SND_SOC_DAIFMT_NB_NF 128 
 unsigned int SSI_NETWORK_DAC_RXSLOT_0_1 ; 
 unsigned int SSI_NETWORK_DAC_RXSLOT_2_3 ; 
 unsigned int SSI_NETWORK_DAC_RXSLOT_4_5 ; 
 unsigned int SSI_NETWORK_DAC_RXSLOT_6_7 ; 
 unsigned int SSI_NETWORK_DAC_RXSLOT_MASK ; 
 unsigned int SSI_NETWORK_DAC_SLOTS_2 ; 
 unsigned int SSI_NETWORK_DAC_SLOTS_4 ; 
 unsigned int SSI_NETWORK_DAC_SLOTS_8 ; 
 unsigned int SSI_NETWORK_DAC_SLOT_MASK ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned int* mc13783_rates ; 
 unsigned int* mc13783_sysclk ; 
 int /*<<< orphan*/  mc13xxx_reg_rmw (int /*<<< orphan*/ ,unsigned int,int,int) ; 
 int /*<<< orphan*/  mc13xxx_reg_write (int /*<<< orphan*/ ,unsigned int,int) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 struct mc13783_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,unsigned int,unsigned int,unsigned int) ; 

__attribute__((used)) static int mc13783_pcm_hw_params_dac(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	unsigned int rate = params_rate(params);
	int i;

	for (i = 0; i < ARRAY_SIZE(mc13783_rates); i++) {
		if (rate == mc13783_rates[i]) {
			snd_soc_component_update_bits(component, MC13783_AUDIO_DAC,
					0xf << 17, i << 17);
			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int mc13783_pcm_hw_params_codec(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	unsigned int rate = params_rate(params);
	unsigned int val;

	switch (rate) {
	case 8000:
		val = 0;
		break;
	case 16000:
		val = AUDIO_CODEC_CDCFS8K16K;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, MC13783_AUDIO_CODEC, AUDIO_CODEC_CDCFS8K16K,
			val);

	return 0;
}

__attribute__((used)) static int mc13783_pcm_hw_params_sync(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		return mc13783_pcm_hw_params_dac(substream, params, dai);
	else
		return mc13783_pcm_hw_params_codec(substream, params, dai);
}

__attribute__((used)) static int mc13783_set_fmt(struct snd_soc_dai *dai, unsigned int fmt,
			unsigned int reg)
{
	struct snd_soc_component *component = dai->component;
	unsigned int val = 0;
	unsigned int mask = AUDIO_CFS(3) | AUDIO_BCL_INV | AUDIO_CFS_INV |
				AUDIO_CSM | AUDIO_C_CLK_EN | AUDIO_C_RESET;


	/* DAI mode */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		val |= AUDIO_CFS(2);
		break;
	case SND_SOC_DAIFMT_DSP_A:
		val |= AUDIO_CFS(1);
		break;
	default:
		return -EINVAL;
	}

	/* DAI clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		val |= AUDIO_BCL_INV;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		val |= AUDIO_BCL_INV | AUDIO_CFS_INV;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		val |= AUDIO_CFS_INV;
		break;
	}

	/* DAI clock master masks */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		val |= AUDIO_C_CLK_EN;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		val |= AUDIO_CSM;
		break;
	case SND_SOC_DAIFMT_CBM_CFS:
	case SND_SOC_DAIFMT_CBS_CFM:
		return -EINVAL;
	}

	val |= AUDIO_C_RESET;

	snd_soc_component_update_bits(component, reg, mask, val);

	return 0;
}

__attribute__((used)) static int mc13783_set_fmt_async(struct snd_soc_dai *dai, unsigned int fmt)
{
	if (dai->id == MC13783_ID_STEREO_DAC)
		return mc13783_set_fmt(dai, fmt, MC13783_AUDIO_DAC);
	else
		return mc13783_set_fmt(dai, fmt, MC13783_AUDIO_CODEC);
}

__attribute__((used)) static int mc13783_set_fmt_sync(struct snd_soc_dai *dai, unsigned int fmt)
{
	int ret;

	ret = mc13783_set_fmt(dai, fmt, MC13783_AUDIO_DAC);
	if (ret)
		return ret;

	/*
	 * In synchronous mode force the voice codec into slave mode
	 * so that the clock / framesync from the stereo DAC is used
	 */
	fmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
	fmt |= SND_SOC_DAIFMT_CBS_CFS;
	ret = mc13783_set_fmt(dai, fmt, MC13783_AUDIO_CODEC);

	return ret;
}

__attribute__((used)) static int mc13783_set_sysclk(struct snd_soc_dai *dai,
				  int clk_id, unsigned int freq, int dir,
				  unsigned int reg)
{
	struct snd_soc_component *component = dai->component;
	int clk;
	unsigned int val = 0;
	unsigned int mask = AUDIO_CLK(0x7) | AUDIO_CLK_SEL;

	for (clk = 0; clk < ARRAY_SIZE(mc13783_sysclk); clk++) {
		if (mc13783_sysclk[clk] < 0)
			continue;
		if (mc13783_sysclk[clk] == freq)
			break;
	}

	if (clk == ARRAY_SIZE(mc13783_sysclk))
		return -EINVAL;

	if (clk_id == MC13783_CLK_CLIB)
		val |= AUDIO_CLK_SEL;

	val |= AUDIO_CLK(clk);

	snd_soc_component_update_bits(component, reg, mask, val);

	return 0;
}

__attribute__((used)) static int mc13783_set_sysclk_dac(struct snd_soc_dai *dai,
				  int clk_id, unsigned int freq, int dir)
{
	return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_DAC);
}

__attribute__((used)) static int mc13783_set_sysclk_codec(struct snd_soc_dai *dai,
				  int clk_id, unsigned int freq, int dir)
{
	return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_CODEC);
}

__attribute__((used)) static int mc13783_set_sysclk_sync(struct snd_soc_dai *dai,
				  int clk_id, unsigned int freq, int dir)
{
	int ret;

	ret = mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_DAC);
	if (ret)
		return ret;

	return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_CODEC);
}

__attribute__((used)) static int mc13783_set_tdm_slot_dac(struct snd_soc_dai *dai,
	unsigned int tx_mask, unsigned int rx_mask, int slots,
	int slot_width)
{
	struct snd_soc_component *component = dai->component;
	unsigned int val = 0;
	unsigned int mask = SSI_NETWORK_DAC_SLOT_MASK |
				SSI_NETWORK_DAC_RXSLOT_MASK;

	switch (slots) {
	case 2:
		val |= SSI_NETWORK_DAC_SLOTS_2;
		break;
	case 4:
		val |= SSI_NETWORK_DAC_SLOTS_4;
		break;
	case 8:
		val |= SSI_NETWORK_DAC_SLOTS_8;
		break;
	default:
		return -EINVAL;
	}

	switch (rx_mask) {
	case 0x03:
		val |= SSI_NETWORK_DAC_RXSLOT_0_1;
		break;
	case 0x0c:
		val |= SSI_NETWORK_DAC_RXSLOT_2_3;
		break;
	case 0x30:
		val |= SSI_NETWORK_DAC_RXSLOT_4_5;
		break;
	case 0xc0:
		val |= SSI_NETWORK_DAC_RXSLOT_6_7;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, MC13783_SSI_NETWORK, mask, val);

	return 0;
}

__attribute__((used)) static int mc13783_set_tdm_slot_codec(struct snd_soc_dai *dai,
	unsigned int tx_mask, unsigned int rx_mask, int slots,
	int slot_width)
{
	struct snd_soc_component *component = dai->component;
	unsigned int val = 0;
	unsigned int mask = 0x3f;

	if (slots != 4)
		return -EINVAL;

	if (tx_mask != 0x3)
		return -EINVAL;

	val |= (0x00 << 2);	/* primary timeslot RX/TX(?) is 0 */
	val |= (0x01 << 4);	/* secondary timeslot TX is 1 */

	snd_soc_component_update_bits(component, MC13783_SSI_NETWORK, mask, val);

	return 0;
}

__attribute__((used)) static int mc13783_set_tdm_slot_sync(struct snd_soc_dai *dai,
	unsigned int tx_mask, unsigned int rx_mask, int slots,
	int slot_width)
{
	int ret;

	ret = mc13783_set_tdm_slot_dac(dai, tx_mask, rx_mask, slots,
			slot_width);
	if (ret)
		return ret;

	ret = mc13783_set_tdm_slot_codec(dai, tx_mask, rx_mask, slots,
			slot_width);

	return ret;
}

__attribute__((used)) static int mc13783_probe(struct snd_soc_component *component)
{
	struct mc13783_priv *priv = snd_soc_component_get_drvdata(component);

	snd_soc_component_init_regmap(component,
				  dev_get_regmap(component->dev->parent, NULL));

	/* these are the reset values */
	mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_RX0, 0x25893);
	mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_RX1, 0x00d35A);
	mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_TX, 0x420000);
	mc13xxx_reg_write(priv->mc13xxx, MC13783_SSI_NETWORK, 0x013060);
	mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_CODEC, 0x180027);
	mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_DAC, 0x0e0004);

	if (priv->adc_ssi_port == MC13783_SSI1_PORT)
		mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_CODEC,
				AUDIO_SSI_SEL, 0);
	else
		mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_CODEC,
				AUDIO_SSI_SEL, AUDIO_SSI_SEL);

	if (priv->dac_ssi_port == MC13783_SSI1_PORT)
		mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_DAC,
				AUDIO_SSI_SEL, 0);
	else
		mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_DAC,
				AUDIO_SSI_SEL, AUDIO_SSI_SEL);

	return 0;
}

__attribute__((used)) static void mc13783_remove(struct snd_soc_component *component)
{
	struct mc13783_priv *priv = snd_soc_component_get_drvdata(component);

	/* Make sure VAUDIOON is off */
	mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_RX0, 0x3, 0);
}

