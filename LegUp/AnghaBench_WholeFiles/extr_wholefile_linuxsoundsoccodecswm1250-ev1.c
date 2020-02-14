#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct wm1250_priv {TYPE_1__* gpios; } ;
struct wm1250_ev1_pdata {int* gpios; } ;
struct snd_soc_dai {int /*<<< orphan*/  component; } ;
struct snd_soc_component {int /*<<< orphan*/ * dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_4__ {int gpio; void* flags; int /*<<< orphan*/  label; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* GPIOF_OUT_INIT_HIGH ; 
 void* GPIOF_OUT_INIT_LOW ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 size_t WM1250_EV1_GPIO_CLK_ENA ; 
 size_t WM1250_EV1_GPIO_CLK_SEL0 ; 
 size_t WM1250_EV1_GPIO_CLK_SEL1 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct wm1250_priv* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct wm1250_ev1_pdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct wm1250_priv*) ; 
 struct wm1250_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpio_free_array (TYPE_1__*,int) ; 
 int gpio_request_array (TYPE_1__*,int) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 struct wm1250_priv* snd_soc_component_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm1250_ev1 ; 
 int /*<<< orphan*/  wm1250_ev1_dai ; 
 int /*<<< orphan*/ * wm1250_gpio_names ; 

__attribute__((used)) static int wm1250_ev1_set_bias_level(struct snd_soc_component *component,
				     enum snd_soc_bias_level level)
{
	struct wm1250_priv *wm1250 = dev_get_drvdata(component->dev);
	int ena;

	if (wm1250)
		ena = wm1250->gpios[WM1250_EV1_GPIO_CLK_ENA].gpio;
	else
		ena = -1;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		break;

	case SND_SOC_BIAS_STANDBY:
		if (ena >= 0)
			gpio_set_value_cansleep(ena, 1);
		break;

	case SND_SOC_BIAS_OFF:
		if (ena >= 0)
			gpio_set_value_cansleep(ena, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int wm1250_ev1_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct wm1250_priv *wm1250 = snd_soc_component_get_drvdata(dai->component);

	switch (params_rate(params)) {
	case 8000:
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL0].gpio,
			       1);
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL1].gpio,
			       1);
		break;
	case 16000:
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL0].gpio,
			       0);
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL1].gpio,
			       1);
		break;
	case 32000:
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL0].gpio,
			       1);
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL1].gpio,
			       0);
		break;
	case 64000:
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL0].gpio,
			       0);
		gpio_set_value(wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL1].gpio,
			       0);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm1250_ev1_pdata(struct i2c_client *i2c)
{
	struct wm1250_ev1_pdata *pdata = dev_get_platdata(&i2c->dev);
	struct wm1250_priv *wm1250;
	int i, ret;

	if (!pdata)
		return 0;

	wm1250 = devm_kzalloc(&i2c->dev, sizeof(*wm1250), GFP_KERNEL);
	if (!wm1250) {
		ret = -ENOMEM;
		goto err;
	}

	for (i = 0; i < ARRAY_SIZE(wm1250->gpios); i++) {
		wm1250->gpios[i].gpio = pdata->gpios[i];
		wm1250->gpios[i].label = wm1250_gpio_names[i];
		wm1250->gpios[i].flags = GPIOF_OUT_INIT_LOW;
	}
	wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL0].flags = GPIOF_OUT_INIT_HIGH;
	wm1250->gpios[WM1250_EV1_GPIO_CLK_SEL1].flags = GPIOF_OUT_INIT_HIGH;

	ret = gpio_request_array(wm1250->gpios, ARRAY_SIZE(wm1250->gpios));
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to get GPIOs: %d\n", ret);
		goto err;
	}

	dev_set_drvdata(&i2c->dev, wm1250);

	return ret;

err:
	return ret;
}

__attribute__((used)) static void wm1250_ev1_free(struct i2c_client *i2c)
{
	struct wm1250_priv *wm1250 = dev_get_drvdata(&i2c->dev);

	if (wm1250)
		gpio_free_array(wm1250->gpios, ARRAY_SIZE(wm1250->gpios));
}

__attribute__((used)) static int wm1250_ev1_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *i2c_id)
{
	int id, board, rev, ret;

	dev_set_drvdata(&i2c->dev, NULL);

	board = i2c_smbus_read_byte_data(i2c, 0);
	if (board < 0) {
		dev_err(&i2c->dev, "Failed to read ID: %d\n", board);
		return board;
	}

	id = (board & 0xfe) >> 2;
	rev = board & 0x3;

	if (id != 1) {
		dev_err(&i2c->dev, "Unknown board ID %d\n", id);
		return -ENODEV;
	}

	dev_info(&i2c->dev, "revision %d\n", rev + 1);

	ret = wm1250_ev1_pdata(i2c);
	if (ret != 0)
		return ret;

	ret = devm_snd_soc_register_component(&i2c->dev, &soc_component_dev_wm1250_ev1,
				     &wm1250_ev1_dai, 1);
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
		wm1250_ev1_free(i2c);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int wm1250_ev1_remove(struct i2c_client *i2c)
{
	wm1250_ev1_free(i2c);

	return 0;
}

