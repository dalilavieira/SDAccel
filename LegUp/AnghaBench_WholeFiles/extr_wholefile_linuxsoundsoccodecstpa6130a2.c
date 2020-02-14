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
struct tpa6130a2_platform_data {scalar_t__ power_gpio; } ;
struct tpa6130a2_data {scalar_t__ power_gpio; scalar_t__ id; int /*<<< orphan*/  regmap; int /*<<< orphan*/  supply; struct device* dev; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {struct device_node* of_node; struct tpa6130a2_platform_data* platform_data; } ;
struct i2c_client {struct device dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ SND_SOC_DAPM_EVENT_ON (int) ; 
#define  TPA6130A2 129 
 int /*<<< orphan*/  TPA6130A2_REG_VERSION ; 
 unsigned int TPA6130A2_VERSION_MASK ; 
#define  TPA6140A2 128 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,unsigned int) ; 
 int devm_gpio_request (struct device*,scalar_t__,char*) ; 
 struct tpa6130a2_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regulator_get (struct device*,char const*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  gpio_direction_output (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (scalar_t__,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tpa6130a2_data*) ; 
 scalar_t__ of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regcache_cache_only (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  regcache_mark_dirty (int /*<<< orphan*/ ) ; 
 int regcache_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct tpa6130a2_data* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tpa6130a2_component_driver ; 
 int /*<<< orphan*/  tpa6130a2_controls ; 
 int /*<<< orphan*/  tpa6130a2_regmap_config ; 
 int /*<<< orphan*/  tpa6140a2_controls ; 

__attribute__((used)) static int tpa6130a2_power(struct tpa6130a2_data *data, bool enable)
{
	int ret = 0, ret2;

	if (enable) {
		ret = regulator_enable(data->supply);
		if (ret != 0) {
			dev_err(data->dev,
				"Failed to enable supply: %d\n", ret);
			return ret;
		}
		/* Power on */
		if (data->power_gpio >= 0)
			gpio_set_value(data->power_gpio, 1);

		/* Sync registers */
		regcache_cache_only(data->regmap, false);
		ret = regcache_sync(data->regmap);
		if (ret != 0) {
			dev_err(data->dev,
				"Failed to sync registers: %d\n", ret);
			regcache_cache_only(data->regmap, true);
			if (data->power_gpio >= 0)
				gpio_set_value(data->power_gpio, 0);
			ret2 = regulator_disable(data->supply);
			if (ret2 != 0)
				dev_err(data->dev,
					"Failed to disable supply: %d\n", ret2);
			return ret;
		}
	} else {
		/* Powered off device does not retain registers. While device
		 * is off, any register updates (i.e. volume changes) should
		 * happen in cache only.
		 */
		regcache_mark_dirty(data->regmap);
		regcache_cache_only(data->regmap, true);

		/* Power off */
		if (data->power_gpio >= 0)
			gpio_set_value(data->power_gpio, 0);

		ret = regulator_disable(data->supply);
		if (ret != 0) {
			dev_err(data->dev,
				"Failed to disable supply: %d\n", ret);
			return ret;
		}
	}

	return ret;
}

__attribute__((used)) static int tpa6130a2_power_event(struct snd_soc_dapm_widget *w,
				 struct snd_kcontrol *kctrl, int event)
{
	struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
	struct tpa6130a2_data *data = snd_soc_component_get_drvdata(c);

	if (SND_SOC_DAPM_EVENT_ON(event)) {
		/* Before widget power up: turn chip on, sync registers */
		return tpa6130a2_power(data, true);
	} else {
		/* After widget power down: turn chip off */
		return tpa6130a2_power(data, false);
	}
}

__attribute__((used)) static int tpa6130a2_component_probe(struct snd_soc_component *component)
{
	struct tpa6130a2_data *data = snd_soc_component_get_drvdata(component);

	if (data->id == TPA6140A2)
		return snd_soc_add_component_controls(component,
			tpa6140a2_controls, ARRAY_SIZE(tpa6140a2_controls));
	else
		return snd_soc_add_component_controls(component,
			tpa6130a2_controls, ARRAY_SIZE(tpa6130a2_controls));
}

__attribute__((used)) static int tpa6130a2_probe(struct i2c_client *client,
			   const struct i2c_device_id *id)
{
	struct device *dev;
	struct tpa6130a2_data *data;
	struct tpa6130a2_platform_data *pdata = client->dev.platform_data;
	struct device_node *np = client->dev.of_node;
	const char *regulator;
	unsigned int version;
	int ret;

	dev = &client->dev;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->dev = dev;

	data->regmap = devm_regmap_init_i2c(client, &tpa6130a2_regmap_config);
	if (IS_ERR(data->regmap))
		return PTR_ERR(data->regmap);

	if (pdata) {
		data->power_gpio = pdata->power_gpio;
	} else if (np) {
		data->power_gpio = of_get_named_gpio(np, "power-gpio", 0);
	} else {
		dev_err(dev, "Platform data not set\n");
		dump_stack();
		return -ENODEV;
	}

	i2c_set_clientdata(client, data);

	data->id = id->driver_data;

	if (data->power_gpio >= 0) {
		ret = devm_gpio_request(dev, data->power_gpio,
					"tpa6130a2 enable");
		if (ret < 0) {
			dev_err(dev, "Failed to request power GPIO (%d)\n",
				data->power_gpio);
			return ret;
		}
		gpio_direction_output(data->power_gpio, 0);
	}

	switch (data->id) {
	default:
		dev_warn(dev, "Unknown TPA model (%d). Assuming 6130A2\n",
			 data->id);
		/* fall through */
	case TPA6130A2:
		regulator = "Vdd";
		break;
	case TPA6140A2:
		regulator = "AVdd";
		break;
	}

	data->supply = devm_regulator_get(dev, regulator);
	if (IS_ERR(data->supply)) {
		ret = PTR_ERR(data->supply);
		dev_err(dev, "Failed to request supply: %d\n", ret);
		return ret;
	}

	ret = tpa6130a2_power(data, true);
	if (ret != 0)
		return ret;


	/* Read version */
	regmap_read(data->regmap, TPA6130A2_REG_VERSION, &version);
	version &= TPA6130A2_VERSION_MASK;
	if ((version != 1) && (version != 2))
		dev_warn(dev, "UNTESTED version detected (%d)\n", version);

	/* Disable the chip */
	ret = tpa6130a2_power(data, false);
	if (ret != 0)
		return ret;

	return devm_snd_soc_register_component(&client->dev,
			&tpa6130a2_component_driver, NULL, 0);
}

