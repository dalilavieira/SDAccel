#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_17__ {int /*<<< orphan*/  num_controls; int /*<<< orphan*/  controls; } ;
struct tas571x_private {unsigned int format; TYPE_6__* supplies; TYPE_5__* chip; TYPE_8__ component_driver; void* regmap; void* reset_gpio; void* pdn_gpio; void* mclk; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_13__ {long* value; } ;
struct TYPE_14__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_11__ {int max; scalar_t__ min; } ;
struct TYPE_12__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct of_device_id {TYPE_5__* data; } ;
struct i2c_msg {int len; unsigned int* buf; void* flags; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  send_buf ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_16__ {int /*<<< orphan*/  supply; } ;
struct TYPE_15__ {int vol_reg_size; int num_supply_names; int /*<<< orphan*/  num_controls; int /*<<< orphan*/  controls; int /*<<< orphan*/  regmap_config; int /*<<< orphan*/ * supply_names; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct i2c_msg*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 void* I2C_M_RD ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
#define  SND_SOC_BIAS_OFF 144 
#define  SND_SOC_BIAS_ON 143 
#define  SND_SOC_BIAS_PREPARE 142 
#define  SND_SOC_BIAS_STANDBY 141 
 int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 140 
#define  SND_SOC_DAIFMT_LEFT_J 139 
#define  SND_SOC_DAIFMT_RIGHT_J 138 
#define  TAS5717_CH1_LEFT_CH_MIX_REG 137 
#define  TAS5717_CH1_RIGHT_CH_MIX_REG 136 
#define  TAS5717_CH2_LEFT_CH_MIX_REG 135 
#define  TAS5717_CH2_RIGHT_CH_MIX_REG 134 
#define  TAS571X_CH1_VOL_REG 133 
#define  TAS571X_CH2_VOL_REG 132 
#define  TAS571X_CH4_SRC_SELECT_REG 131 
#define  TAS571X_INPUT_MUX_REG 130 
 int TAS571X_MAX_SUPPLIES ; 
#define  TAS571X_MVOL_REG 129 
 int /*<<< orphan*/  TAS571X_OSC_TRIM_REG ; 
#define  TAS571X_PWM_MUX_REG 128 
 int TAS571X_SDI_FMT_MASK ; 
 int const TAS571X_SDI_REG ; 
 int /*<<< orphan*/  TAS571X_SYS_CTRL_2_REG ; 
 int /*<<< orphan*/  TAS571X_SYS_CTRL_2_SDN_MASK ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 void* devm_clk_get (struct device*,char*) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct tas571x_private* devm_kzalloc (struct device*,int,int) ; 
 void* devm_regmap_init (struct device*,int /*<<< orphan*/ *,struct i2c_client*,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_6__*) ; 
 int devm_snd_soc_register_component (struct device*,TYPE_8__*,int /*<<< orphan*/ *,int) ; 
 long get_unaligned_be32 (unsigned int*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int /*<<< orphan*/ ) ; 
 struct tas571x_private* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_send (struct i2c_client*,unsigned int*,size_t) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tas571x_private*) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  kfree (unsigned int*) ; 
 unsigned int* kzalloc (unsigned int,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_8__*,int /*<<< orphan*/ *,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  put_unaligned_be32 (long const,unsigned int*) ; 
 int regmap_update_bits (void*,int const,int,int) ; 
 int regmap_write (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_6__*) ; 
 int regulator_bulk_enable (int,TYPE_6__*) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct tas571x_private* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  tas571x_component ; 
 int /*<<< orphan*/  tas571x_dai ; 
 int /*<<< orphan*/  tas571x_of_match ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int tas571x_register_size(struct tas571x_private *priv, unsigned int reg)
{
	switch (reg) {
	case TAS571X_MVOL_REG:
	case TAS571X_CH1_VOL_REG:
	case TAS571X_CH2_VOL_REG:
		return priv->chip->vol_reg_size;
	case TAS571X_INPUT_MUX_REG:
	case TAS571X_CH4_SRC_SELECT_REG:
	case TAS571X_PWM_MUX_REG:
	case TAS5717_CH1_RIGHT_CH_MIX_REG:
	case TAS5717_CH1_LEFT_CH_MIX_REG:
	case TAS5717_CH2_LEFT_CH_MIX_REG:
	case TAS5717_CH2_RIGHT_CH_MIX_REG:
		return 4;
	default:
		return 1;
	}
}

__attribute__((used)) static int tas571x_reg_write(void *context, unsigned int reg,
			     unsigned int value)
{
	struct i2c_client *client = context;
	struct tas571x_private *priv = i2c_get_clientdata(client);
	unsigned int i, size;
	uint8_t buf[5];
	int ret;

	size = tas571x_register_size(priv, reg);
	buf[0] = reg;

	for (i = size; i >= 1; --i) {
		buf[i] = value;
		value >>= 8;
	}

	ret = i2c_master_send(client, buf, size + 1);
	if (ret == size + 1)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int tas571x_reg_read(void *context, unsigned int reg,
			    unsigned int *value)
{
	struct i2c_client *client = context;
	struct tas571x_private *priv = i2c_get_clientdata(client);
	uint8_t send_buf, recv_buf[4];
	struct i2c_msg msgs[2];
	unsigned int size;
	unsigned int i;
	int ret;

	size = tas571x_register_size(priv, reg);
	send_buf = reg;

	msgs[0].addr = client->addr;
	msgs[0].len = sizeof(send_buf);
	msgs[0].buf = &send_buf;
	msgs[0].flags = 0;

	msgs[1].addr = client->addr;
	msgs[1].len = size;
	msgs[1].buf = recv_buf;
	msgs[1].flags = I2C_M_RD;

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
	if (ret < 0)
		return ret;
	else if (ret != ARRAY_SIZE(msgs))
		return -EIO;

	*value = 0;

	for (i = 0; i < size; i++) {
		*value <<= 8;
		*value |= recv_buf[i];
	}

	return 0;
}

__attribute__((used)) static int tas571x_reg_write_multiword(struct i2c_client *client,
		unsigned int reg, const long values[], size_t len)
{
	size_t i;
	uint8_t *buf, *p;
	int ret;
	size_t send_size = 1 + len * sizeof(uint32_t);

	buf = kzalloc(send_size, GFP_KERNEL | GFP_DMA);
	if (!buf)
		return -ENOMEM;
	buf[0] = reg;

	for (i = 0, p = buf + 1; i < len; i++, p += sizeof(uint32_t))
		put_unaligned_be32(values[i], p);

	ret = i2c_master_send(client, buf, send_size);

	kfree(buf);

	if (ret == send_size)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int tas571x_reg_read_multiword(struct i2c_client *client,
		unsigned int reg, long values[], size_t len)
{
	unsigned int i;
	uint8_t send_buf;
	uint8_t *recv_buf, *p;
	struct i2c_msg msgs[2];
	unsigned int recv_size = len * sizeof(uint32_t);
	int ret;

	recv_buf = kzalloc(recv_size, GFP_KERNEL | GFP_DMA);
	if (!recv_buf)
		return -ENOMEM;

	send_buf = reg;

	msgs[0].addr = client->addr;
	msgs[0].len = sizeof(send_buf);
	msgs[0].buf = &send_buf;
	msgs[0].flags = 0;

	msgs[1].addr = client->addr;
	msgs[1].len = recv_size;
	msgs[1].buf = recv_buf;
	msgs[1].flags = I2C_M_RD;

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
	if (ret < 0)
		goto err_ret;
	else if (ret != ARRAY_SIZE(msgs)) {
		ret = -EIO;
		goto err_ret;
	}

	for (i = 0, p = recv_buf; i < len; i++, p += sizeof(uint32_t))
		values[i] = get_unaligned_be32(p);

err_ret:
	kfree(recv_buf);
	return ret;
}

__attribute__((used)) static int tas571x_coefficient_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info *uinfo)
{
	int numcoef = kcontrol->private_value >> 16;

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = numcoef;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 0xffffffff;
	return 0;
}

__attribute__((used)) static int tas571x_coefficient_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct i2c_client *i2c = to_i2c_client(component->dev);
	int numcoef = kcontrol->private_value >> 16;
	int index = kcontrol->private_value & 0xffff;

	return tas571x_reg_read_multiword(i2c, index,
		ucontrol->value.integer.value, numcoef);
}

__attribute__((used)) static int tas571x_coefficient_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct i2c_client *i2c = to_i2c_client(component->dev);
	int numcoef = kcontrol->private_value >> 16;
	int index = kcontrol->private_value & 0xffff;

	return tas571x_reg_write_multiword(i2c, index,
		ucontrol->value.integer.value, numcoef);
}

__attribute__((used)) static int tas571x_set_dai_fmt(struct snd_soc_dai *dai, unsigned int format)
{
	struct tas571x_private *priv = snd_soc_component_get_drvdata(dai->component);

	priv->format = format;

	return 0;
}

__attribute__((used)) static int tas571x_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct tas571x_private *priv = snd_soc_component_get_drvdata(dai->component);
	u32 val;

	switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		val = 0x00;
		break;
	case SND_SOC_DAIFMT_I2S:
		val = 0x03;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		val = 0x06;
		break;
	default:
		return -EINVAL;
	}

	if (params_width(params) >= 24)
		val += 2;
	else if (params_width(params) >= 20)
		val += 1;

	return regmap_update_bits(priv->regmap, TAS571X_SDI_REG,
				  TAS571X_SDI_FMT_MASK, val);
}

__attribute__((used)) static int tas571x_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u8 sysctl2;
	int ret;

	sysctl2 = mute ? TAS571X_SYS_CTRL_2_SDN_MASK : 0;

	ret = snd_soc_component_update_bits(component,
			    TAS571X_SYS_CTRL_2_REG,
		     TAS571X_SYS_CTRL_2_SDN_MASK,
		     sysctl2);
	usleep_range(1000, 2000);

	return ret;
}

__attribute__((used)) static int tas571x_set_bias_level(struct snd_soc_component *component,
				  enum snd_soc_bias_level level)
{
	struct tas571x_private *priv = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			if (!IS_ERR(priv->mclk)) {
				ret = clk_prepare_enable(priv->mclk);
				if (ret) {
					dev_err(component->dev,
						"Failed to enable master clock: %d\n",
						ret);
					return ret;
				}
			}
		}
		break;
	case SND_SOC_BIAS_OFF:
		if (!IS_ERR(priv->mclk))
			clk_disable_unprepare(priv->mclk);
		break;
	}

	return 0;
}

__attribute__((used)) static int tas571x_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct tas571x_private *priv;
	struct device *dev = &client->dev;
	const struct of_device_id *of_id;
	int i, ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	i2c_set_clientdata(client, priv);

	of_id = of_match_device(tas571x_of_match, dev);
	if (of_id)
		priv->chip = of_id->data;
	else
		priv->chip = (void *) id->driver_data;

	priv->mclk = devm_clk_get(dev, "mclk");
	if (IS_ERR(priv->mclk) && PTR_ERR(priv->mclk) != -ENOENT) {
		dev_err(dev, "Failed to request mclk: %ld\n",
			PTR_ERR(priv->mclk));
		return PTR_ERR(priv->mclk);
	}

	if (WARN_ON(priv->chip->num_supply_names > TAS571X_MAX_SUPPLIES))
		return -EINVAL;
	for (i = 0; i < priv->chip->num_supply_names; i++)
		priv->supplies[i].supply = priv->chip->supply_names[i];

	ret = devm_regulator_bulk_get(dev, priv->chip->num_supply_names,
				      priv->supplies);
	if (ret) {
		dev_err(dev, "Failed to get supplies: %d\n", ret);
		return ret;
	}
	ret = regulator_bulk_enable(priv->chip->num_supply_names,
				    priv->supplies);
	if (ret) {
		dev_err(dev, "Failed to enable supplies: %d\n", ret);
		return ret;
	}

	priv->regmap = devm_regmap_init(dev, NULL, client,
					priv->chip->regmap_config);
	if (IS_ERR(priv->regmap))
		return PTR_ERR(priv->regmap);

	priv->pdn_gpio = devm_gpiod_get_optional(dev, "pdn", GPIOD_OUT_LOW);
	if (IS_ERR(priv->pdn_gpio)) {
		dev_err(dev, "error requesting pdn_gpio: %ld\n",
			PTR_ERR(priv->pdn_gpio));
		return PTR_ERR(priv->pdn_gpio);
	}

	priv->reset_gpio = devm_gpiod_get_optional(dev, "reset",
						   GPIOD_OUT_HIGH);
	if (IS_ERR(priv->reset_gpio)) {
		dev_err(dev, "error requesting reset_gpio: %ld\n",
			PTR_ERR(priv->reset_gpio));
		return PTR_ERR(priv->reset_gpio);
	} else if (priv->reset_gpio) {
		/* pulse the active low reset line for ~100us */
		usleep_range(100, 200);
		gpiod_set_value(priv->reset_gpio, 0);
		usleep_range(13500, 20000);
	}

	ret = regmap_write(priv->regmap, TAS571X_OSC_TRIM_REG, 0);
	if (ret)
		return ret;

	usleep_range(50000, 60000);

	memcpy(&priv->component_driver, &tas571x_component, sizeof(priv->component_driver));
	priv->component_driver.controls = priv->chip->controls;
	priv->component_driver.num_controls = priv->chip->num_controls;

	if (priv->chip->vol_reg_size == 2) {
		/*
		 * The master volume defaults to 0x3ff (mute), but we ignore
		 * (zero) the LSB because the hardware step size is 0.125 dB
		 * and TLV_DB_SCALE_ITEM has a resolution of 0.01 dB.
		 */
		ret = regmap_update_bits(priv->regmap, TAS571X_MVOL_REG, 1, 0);
		if (ret)
			return ret;
	}

	return devm_snd_soc_register_component(&client->dev,
				      &priv->component_driver,
				      &tas571x_dai, 1);
}

__attribute__((used)) static int tas571x_i2c_remove(struct i2c_client *client)
{
	struct tas571x_private *priv = i2c_get_clientdata(client);

	regulator_bulk_disable(priv->chip->num_supply_names, priv->supplies);

	return 0;
}

