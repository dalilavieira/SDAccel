#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_9__ ;
typedef  struct TYPE_26__   TYPE_8__ ;
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_12__ ;
typedef  struct TYPE_17__   TYPE_10__ ;

/* Type definitions */
struct snd_soc_pcm_stream {int formats; int rate_max; int rate_min; int /*<<< orphan*/  rates; } ;
struct snd_soc_pcm_runtime {struct snd_soc_card* card; TYPE_9__* cpu_dai; TYPE_8__* codec_dai; } ;
struct snd_soc_dai_link {struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; } ;
struct snd_soc_card {TYPE_12__* dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_mask {int dummy; } ;
struct TYPE_21__ {int /*<<< orphan*/  name; } ;
struct snd_kcontrol {unsigned int private_value; TYPE_3__ id; } ;
struct TYPE_22__ {unsigned int* value; } ;
struct TYPE_23__ {TYPE_4__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_19__ {int max; scalar_t__ min; } ;
struct TYPE_20__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_18__ {scalar_t__ of_node; } ;
struct i2c_client {TYPE_12__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_27__ {TYPE_6__* driver; } ;
struct TYPE_26__ {TYPE_7__* driver; } ;
struct TYPE_25__ {struct snd_soc_pcm_stream playback; } ;
struct TYPE_24__ {struct snd_soc_pcm_stream playback; } ;
struct TYPE_17__ {TYPE_12__* dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int EPROBE_DEFER ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int /*<<< orphan*/  NANO_CFG ; 
 unsigned int NANO_CFG_BLINK ; 
 unsigned int NANO_CFG_CLK22 ; 
 unsigned int NANO_CFG_CLK24 ; 
 unsigned int NANO_CFG_DSD ; 
 unsigned int NANO_CFG_ENA ; 
 unsigned int NANO_CFG_MULT1 ; 
 unsigned int NANO_CFG_MULT16 ; 
 unsigned int NANO_CFG_MULT2 ; 
 unsigned int NANO_CFG_MULT4 ; 
 unsigned int NANO_CFG_MULT8 ; 
 unsigned int NANO_CFG_OFF ; 
 unsigned int NANO_CTRL2_VAL ; 
 unsigned int NANO_DAC_CTRL2 ; 
 unsigned int NANO_DAC_LATT ; 
 unsigned int NANO_DAC_RATT ; 
 int /*<<< orphan*/  NANO_ID ; 
 unsigned int NANO_ID_VAL ; 
 int /*<<< orphan*/  NANO_SPI_ADDR ; 
 int /*<<< orphan*/  NANO_SPI_DATA ; 
 unsigned int NANO_SPI_WRITE ; 
 int /*<<< orphan*/  NANO_STATUS ; 
 unsigned int NANO_STATUS_CLK ; 
 int /*<<< orphan*/  NANO_VER ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int SNDRV_PCM_FMTBIT_DSD_U32_LE ; 
 int SNDRV_PCM_FMTBIT_S32_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_FORMAT_DSD_U32_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_FORMAT_S32_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_FORMAT ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  SNDRV_PCM_RATE_KNOT ; 
 int /*<<< orphan*/  dev_dbg (TYPE_12__*,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (TYPE_12__*,char*,int) ; 
 int /*<<< orphan*/  dev_notice (TYPE_12__*,char*,...) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_card (TYPE_12__*,TYPE_10__*) ; 
 struct snd_mask* hw_param_mask (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 TYPE_10__ nano_player_card ; 
 int /*<<< orphan*/  nano_player_constraint_rates ; 
 struct snd_soc_dai_link nano_player_link ; 
 int /*<<< orphan*/  nano_player_regmap ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,unsigned int) ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_mask_none (struct snd_mask*) ; 
 int /*<<< orphan*/  snd_mask_set (struct snd_mask*,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_mask_test (struct snd_mask*,int /*<<< orphan*/ ) ; 
 int snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct regmap* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (TYPE_10__*,struct regmap*) ; 
 int snd_soc_dai_set_bclk_ratio (TYPE_9__*,unsigned int) ; 
 scalar_t__ strstr (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int nano_player_spi_write(struct regmap *map,
				 unsigned int reg, unsigned int val)
{
	/* indirect register access */
	regmap_write(map, NANO_SPI_DATA, val);
	regmap_write(map, NANO_SPI_ADDR, reg | NANO_SPI_WRITE);
	return 0;
}

__attribute__((used)) static int nano_player_ctrl_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *uinfo)
{
	/* describe control element */
	if (strstr(kcontrol->id.name, "Volume")) {
		uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
		uinfo->count = 1;
		uinfo->value.integer.min = 0;
		uinfo->value.integer.max = 100;
	} else {
		uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
		uinfo->count = 1;
		uinfo->value.integer.min = 0;
		uinfo->value.integer.max = 1;
	}

	return 0;
}

__attribute__((used)) static int nano_player_ctrl_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	/* program control value to hardware */
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
	struct regmap *regmap = snd_soc_card_get_drvdata(card);

	if (strstr(kcontrol->id.name, "Volume")) {
		unsigned int vol = ucontrol->value.integer.value[0];
		unsigned int att = 255 - (2 * (100 - vol));

		nano_player_spi_write(regmap, NANO_DAC_LATT, att);
		nano_player_spi_write(regmap, NANO_DAC_RATT, att);
		kcontrol->private_value = vol;
	} else {
		unsigned int mute = ucontrol->value.integer.value[0];
		unsigned int reg = NANO_CTRL2_VAL | mute;

		nano_player_spi_write(regmap, NANO_DAC_CTRL2, reg);
		kcontrol->private_value = mute;
	}
	return 0;
}

__attribute__((used)) static int nano_player_ctrl_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	/* return last programmed value */
	ucontrol->value.integer.value[0] = kcontrol->private_value;
	return 0;
}

__attribute__((used)) static int nano_player_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_card *card = rtd->card;
	struct regmap *regmap = snd_soc_card_get_drvdata(card);
	struct snd_soc_pcm_stream *cpu = &rtd->cpu_dai->driver->playback;
	struct snd_soc_pcm_stream *codec = &rtd->codec_dai->driver->playback;
	unsigned int sample_bits = 32;
	unsigned int val;

	/* configure cpu dai */
	cpu->formats |= SNDRV_PCM_FMTBIT_DSD_U32_LE;
	cpu->rate_max = 768000;

	/* configure dummy codec dai */
	codec->rate_min = 44100;
	codec->rates = SNDRV_PCM_RATE_KNOT;
	codec->formats = SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_DSD_U32_LE;

	/* configure max supported rate */
	regmap_read(regmap, NANO_STATUS, &val);
	if (val & NANO_STATUS_CLK) {
		dev_notice(card->dev, "Board with fast clocks installed\n");
		codec->rate_max = 768000;
	} else {
		dev_notice(card->dev, "Board with normal clocks installed\n");
		codec->rate_max = 384000;
	}

	/* frame length enforced by hardware */
	return snd_soc_dai_set_bclk_ratio(rtd->cpu_dai, sample_bits * 2);
}

__attribute__((used)) static int nano_player_startup(struct snd_pcm_substream *substream)
{
	return snd_pcm_hw_constraint_list(substream->runtime, 0,
					  SNDRV_PCM_HW_PARAM_RATE,
					  &nano_player_constraint_rates);
}

__attribute__((used)) static int nano_player_hw_params(struct snd_pcm_substream *substream,
				 struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;
	struct regmap *regmap = snd_soc_card_get_drvdata(card);
	unsigned int config = NANO_CFG_ENA;
	struct snd_mask *fmt;

	/* configure PCM or DSD */
	fmt = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
	if (snd_mask_test(fmt, SNDRV_PCM_FORMAT_DSD_U32_LE)) {
		/* embed DSD in PCM data */
		snd_mask_none(fmt);
		snd_mask_set(fmt, SNDRV_PCM_FORMAT_S32_LE);
		/* enable DSD mode */
		config |= NANO_CFG_DSD;
	}

	/* configure clocks */
	switch (params_rate(params)) {
	case 44100:
		config |= NANO_CFG_MULT1 | NANO_CFG_CLK22;
		break;
	case 88200:
		config |= NANO_CFG_MULT2 | NANO_CFG_CLK22;
		break;
	case 176400:
		config |= NANO_CFG_MULT4 | NANO_CFG_CLK22;
		break;
	case 352800:
		config |= NANO_CFG_MULT8 | NANO_CFG_CLK22;
		break;
	case 705600:
		config |= NANO_CFG_MULT16 | NANO_CFG_CLK22;
		break;
	case 48000:
		config |= NANO_CFG_MULT1 | NANO_CFG_CLK24;
		break;
	case 96000:
		config |= NANO_CFG_MULT2 | NANO_CFG_CLK24;
		break;
	case 192000:
		config |= NANO_CFG_MULT4 | NANO_CFG_CLK24;
		break;
	case 384000:
		config |= NANO_CFG_MULT8 | NANO_CFG_CLK24;
		break;
	case 768000:
		config |= NANO_CFG_MULT16 | NANO_CFG_CLK24;
		break;
	default:
		return -EINVAL;
	}

	dev_dbg(card->dev, "Send CFG register 0x%02X\n", config);
	return regmap_write(regmap, NANO_CFG, config);
}

__attribute__((used)) static int nano_player_card_probe(struct snd_soc_card *card)
{
	struct regmap *regmap = snd_soc_card_get_drvdata(card);
	unsigned int val;

	/* check hardware integrity */
	regmap_read(regmap, NANO_ID, &val);
	if (val != NANO_ID_VAL) {
		dev_err(card->dev, "Invalid ID register 0x%02X\n", val);
		return -ENODEV;
	}

	/* report version to the user */
	regmap_read(regmap, NANO_VER, &val);
	dev_notice(card->dev, "Started 3Dlab Nano Player driver (v%d)\n", val);

	/* enable internal audio bus and blink status LED */
	return regmap_write(regmap, NANO_CFG, NANO_CFG_ENA | NANO_CFG_BLINK);
}

__attribute__((used)) static int nano_player_card_remove(struct snd_soc_card *card)
{
	/* disable internal audio bus */
	struct regmap *regmap = snd_soc_card_get_drvdata(card);

	return regmap_write(regmap, NANO_CFG, NANO_CFG_OFF);
}

__attribute__((used)) static int nano_player_i2c_probe(struct i2c_client *i2c,
				 const struct i2c_device_id *id)
{
	struct regmap *regmap;
	int ret;

	regmap = devm_regmap_init_i2c(i2c, &nano_player_regmap);
	if (IS_ERR(regmap)) {
		ret = PTR_ERR(regmap);
		dev_err(&i2c->dev, "Failed to init regmap %d\n", ret);
		return ret;
	}

	if (i2c->dev.of_node) {
		struct snd_soc_dai_link *dai = &nano_player_link;
		struct device_node *node;

		/* cpu handle configured by device tree */
		node = of_parse_phandle(i2c->dev.of_node, "i2s-controller", 0);
		if (node) {
			dai->platform_name = NULL;
			dai->platform_of_node = node;
			dai->cpu_dai_name = NULL;
			dai->cpu_of_node = node;
		}
	}

	nano_player_card.dev = &i2c->dev;
	snd_soc_card_set_drvdata(&nano_player_card, regmap);
	ret = devm_snd_soc_register_card(&i2c->dev, &nano_player_card);

	if (ret && ret != -EPROBE_DEFER)
		dev_err(&i2c->dev, "Failed to register card %d\n", ret);

	return ret;
}

