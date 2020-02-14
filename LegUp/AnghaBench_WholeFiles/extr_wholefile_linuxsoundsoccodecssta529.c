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
typedef  int u8 ;
typedef  int u32 ;
struct sta529 {int /*<<< orphan*/  regmap; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_MUTE_MSK ; 
 int /*<<< orphan*/  BCLK_TO_FS_MSK ; 
 int /*<<< orphan*/  CAP_FREQ_RANGE_MSK ; 
 int CODEC_MUTE_VAL ; 
 int /*<<< orphan*/  DATA_FORMAT_MSK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int FFX_CLK_DIS ; 
 int FFX_CLK_ENB ; 
 int /*<<< orphan*/  FFX_CLK_MSK ; 
 int /*<<< orphan*/  FFX_MASK ; 
 int FFX_OFF ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2S_DATA_FORMAT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LEFT_J_DATA_FORMAT ; 
 int /*<<< orphan*/  PDATA_LEN_MSK ; 
 int /*<<< orphan*/  PLAY_FREQ_RANGE_MSK ; 
 int /*<<< orphan*/  POWER_CNTLMSAK ; 
 int POWER_STDBY ; 
 int POWER_UP ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RIGHT_J_DATA_FORMAT ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 146 
#define  SND_SOC_BIAS_ON 145 
#define  SND_SOC_BIAS_PREPARE 144 
#define  SND_SOC_BIAS_STANDBY 143 
 int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 142 
#define  SND_SOC_DAIFMT_LEFT_J 141 
#define  SND_SOC_DAIFMT_RIGHT_J 140 
#define  STA529_ADCCFG 139 
#define  STA529_CKOCFG 138 
#define  STA529_FFXCFG0 137 
#define  STA529_FFXCFG1 136 
#define  STA529_LVOL 135 
#define  STA529_MISC 134 
#define  STA529_MVOL 133 
#define  STA529_P2SCFG0 132 
#define  STA529_P2SCFG1 131 
#define  STA529_RVOL 130 
#define  STA529_S2PCFG0 129 
#define  STA529_S2PCFG1 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct sta529* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct sta529*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct sta529* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sta529_component_driver ; 
 int /*<<< orphan*/  sta529_dai ; 
 int /*<<< orphan*/  sta529_regmap ; 

__attribute__((used)) static bool sta529_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {

	case STA529_FFXCFG0:
	case STA529_FFXCFG1:
	case STA529_MVOL:
	case STA529_LVOL:
	case STA529_RVOL:
	case STA529_S2PCFG0:
	case STA529_S2PCFG1:
	case STA529_P2SCFG0:
	case STA529_P2SCFG1:
	case STA529_ADCCFG:
	case STA529_CKOCFG:
	case STA529_MISC:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int sta529_set_bias_level(struct snd_soc_component *component, enum
		snd_soc_bias_level level)
{
	struct sta529 *sta529 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
		snd_soc_component_update_bits(component, STA529_FFXCFG0, POWER_CNTLMSAK,
				POWER_UP);
		snd_soc_component_update_bits(component, STA529_MISC,	FFX_CLK_MSK,
				FFX_CLK_ENB);
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			regcache_sync(sta529->regmap);
		snd_soc_component_update_bits(component, STA529_FFXCFG0,
					POWER_CNTLMSAK, POWER_STDBY);
		/* Making FFX output to zero */
		snd_soc_component_update_bits(component, STA529_FFXCFG0, FFX_MASK,
				FFX_OFF);
		snd_soc_component_update_bits(component, STA529_MISC, FFX_CLK_MSK,
				FFX_CLK_DIS);
		break;
	case SND_SOC_BIAS_OFF:
		break;
	}

	return 0;

}

__attribute__((used)) static int sta529_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	int pdata, play_freq_val, record_freq_val;
	int bclk_to_fs_ratio;

	switch (params_width(params)) {
	case 16:
		pdata = 1;
		bclk_to_fs_ratio = 0;
		break;
	case 24:
		pdata = 2;
		bclk_to_fs_ratio = 1;
		break;
	case 32:
		pdata = 3;
		bclk_to_fs_ratio = 2;
		break;
	default:
		dev_err(component->dev, "Unsupported format\n");
		return -EINVAL;
	}

	switch (params_rate(params)) {
	case 8000:
	case 11025:
		play_freq_val = 0;
		record_freq_val = 2;
		break;
	case 16000:
	case 22050:
		play_freq_val = 1;
		record_freq_val = 0;
		break;

	case 32000:
	case 44100:
	case 48000:
		play_freq_val = 2;
		record_freq_val = 0;
		break;
	default:
		dev_err(component->dev, "Unsupported rate\n");
		return -EINVAL;
	}

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		snd_soc_component_update_bits(component, STA529_S2PCFG1, PDATA_LEN_MSK,
				pdata << 6);
		snd_soc_component_update_bits(component, STA529_S2PCFG1, BCLK_TO_FS_MSK,
				bclk_to_fs_ratio << 4);
		snd_soc_component_update_bits(component, STA529_MISC, PLAY_FREQ_RANGE_MSK,
				play_freq_val << 4);
	} else {
		snd_soc_component_update_bits(component, STA529_P2SCFG1, PDATA_LEN_MSK,
				pdata << 6);
		snd_soc_component_update_bits(component, STA529_P2SCFG1, BCLK_TO_FS_MSK,
				bclk_to_fs_ratio << 4);
		snd_soc_component_update_bits(component, STA529_MISC, CAP_FREQ_RANGE_MSK,
				record_freq_val << 2);
	}

	return 0;
}

__attribute__((used)) static int sta529_mute(struct snd_soc_dai *dai, int mute)
{
	u8 val = 0;

	if (mute)
		val |= CODEC_MUTE_VAL;

	snd_soc_component_update_bits(dai->component, STA529_FFXCFG0, AUDIO_MUTE_MSK, val);

	return 0;
}

__attribute__((used)) static int sta529_set_dai_fmt(struct snd_soc_dai *codec_dai, u32 fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u8 mode = 0;

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_LEFT_J:
		mode = LEFT_J_DATA_FORMAT;
		break;
	case SND_SOC_DAIFMT_I2S:
		mode = I2S_DATA_FORMAT;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		mode = RIGHT_J_DATA_FORMAT;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, STA529_S2PCFG0, DATA_FORMAT_MSK, mode);

	return 0;
}

__attribute__((used)) static int sta529_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct sta529 *sta529;
	int ret;

	sta529 = devm_kzalloc(&i2c->dev, sizeof(struct sta529), GFP_KERNEL);
	if (!sta529)
		return -ENOMEM;

	sta529->regmap = devm_regmap_init_i2c(i2c, &sta529_regmap);
	if (IS_ERR(sta529->regmap)) {
		ret = PTR_ERR(sta529->regmap);
		dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, sta529);

	ret = devm_snd_soc_register_component(&i2c->dev,
			&sta529_component_driver, &sta529_dai, 1);
	if (ret != 0)
		dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);

	return ret;
}

