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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct mlxreg_led_priv_data {int /*<<< orphan*/  access_lock; struct mlxreg_core_platform_data* pdata; struct platform_device* pdev; } ;
struct led_classdev {int brightness; int (* brightness_set_blocking ) (struct led_classdev*,int) ;int (* brightness_get ) (struct led_classdev*) ;int (* blink_set ) (struct led_classdev*,unsigned long*,unsigned long*) ;int /*<<< orphan*/  dev; int /*<<< orphan*/  flags; int /*<<< orphan*/  max_brightness; int /*<<< orphan*/  name; } ;
struct mlxreg_led_data {int base_color; struct mlxreg_core_data* data; int /*<<< orphan*/  led_cdev_name; struct mlxreg_led_priv_data* data_parent; struct led_classdev led_cdev; } ;
struct mlxreg_core_platform_data {int counter; struct mlxreg_core_data* data; int /*<<< orphan*/  regmap; } ;
struct mlxreg_core_data {int mask; char* label; int /*<<< orphan*/  reg; scalar_t__ bit; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LED_CORE_SUSPENDRESUME ; 
 int LED_FULL ; 
 int LED_OFF ; 
 int /*<<< orphan*/  LED_ON ; 
 int MLXREG_LED_AMBER_SOLID ; 
 unsigned long MLXREG_LED_BLINK_3HZ ; 
 unsigned long MLXREG_LED_BLINK_6HZ ; 
 int MLXREG_LED_GREEN_SOLID ; 
 int MLXREG_LED_IS_OFF ; 
 int MLXREG_LED_OFFSET_BLINK_3HZ ; 
 int MLXREG_LED_OFFSET_BLINK_6HZ ; 
 int MLXREG_LED_RED_SOLID ; 
 struct mlxreg_led_data* cdev_to_priv (struct led_classdev*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct mlxreg_led_priv_data* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct mlxreg_core_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_led_classdev_register (int /*<<< orphan*/ *,struct led_classdev*) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int rol32 (int,scalar_t__) ; 
 int ror32 (int,scalar_t__) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,char*,char*) ; 
 scalar_t__ strstr (char*,char*) ; 

__attribute__((used)) static int
mlxreg_led_store_hw(struct mlxreg_led_data *led_data, u8 vset)
{
	struct mlxreg_led_priv_data *priv = led_data->data_parent;
	struct mlxreg_core_platform_data *led_pdata = priv->pdata;
	struct mlxreg_core_data *data = led_data->data;
	u32 regval;
	u32 nib;
	int ret;

	/*
	 * Each LED is controlled through low or high nibble of the relevant
	 * register byte. Register offset is specified by off parameter.
	 * Parameter vset provides color code: 0x0 for off, 0x5 for solid red,
	 * 0x6 for 3Hz blink red, 0xd for solid green, 0xe for 3Hz blink
	 * green.
	 * Parameter mask specifies which nibble is used for specific LED: mask
	 * 0xf0 - lower nibble is to be used (bits from 0 to 3), mask 0x0f -
	 * higher nibble (bits from 4 to 7).
	 */
	mutex_lock(&priv->access_lock);

	ret = regmap_read(led_pdata->regmap, data->reg, &regval);
	if (ret)
		goto access_error;

	nib = (ror32(data->mask, data->bit) == 0xf0) ? rol32(vset, data->bit) :
	      rol32(vset, data->bit + 4);
	regval = (regval & data->mask) | nib;

	ret = regmap_write(led_pdata->regmap, data->reg, regval);

access_error:
	mutex_unlock(&priv->access_lock);

	return ret;
}

__attribute__((used)) static enum led_brightness
mlxreg_led_get_hw(struct mlxreg_led_data *led_data)
{
	struct mlxreg_led_priv_data *priv = led_data->data_parent;
	struct mlxreg_core_platform_data *led_pdata = priv->pdata;
	struct mlxreg_core_data *data = led_data->data;
	u32 regval;
	int err;

	/*
	 * Each LED is controlled through low or high nibble of the relevant
	 * register byte. Register offset is specified by off parameter.
	 * Parameter vset provides color code: 0x0 for off, 0x5 for solid red,
	 * 0x6 for 3Hz blink red, 0xd for solid green, 0xe for 3Hz blink
	 * green.
	 * Parameter mask specifies which nibble is used for specific LED: mask
	 * 0xf0 - lower nibble is to be used (bits from 0 to 3), mask 0x0f -
	 * higher nibble (bits from 4 to 7).
	 */
	err = regmap_read(led_pdata->regmap, data->reg, &regval);
	if (err < 0) {
		dev_warn(led_data->led_cdev.dev, "Failed to get current brightness, error: %d\n",
			 err);
		/* Assume the LED is OFF */
		return LED_OFF;
	}

	regval = regval & ~data->mask;
	regval = (ror32(data->mask, data->bit) == 0xf0) ? ror32(regval,
		 data->bit) : ror32(regval, data->bit + 4);
	if (regval >= led_data->base_color &&
	    regval <= (led_data->base_color + MLXREG_LED_OFFSET_BLINK_6HZ))
		return LED_FULL;

	return LED_OFF;
}

__attribute__((used)) static int
mlxreg_led_brightness_set(struct led_classdev *cled, enum led_brightness value)
{
	struct mlxreg_led_data *led_data = cdev_to_priv(cled);

	if (value)
		return mlxreg_led_store_hw(led_data, led_data->base_color);
	else
		return mlxreg_led_store_hw(led_data, MLXREG_LED_IS_OFF);
}

__attribute__((used)) static enum led_brightness
mlxreg_led_brightness_get(struct led_classdev *cled)
{
	struct mlxreg_led_data *led_data = cdev_to_priv(cled);

	return mlxreg_led_get_hw(led_data);
}

__attribute__((used)) static int
mlxreg_led_blink_set(struct led_classdev *cled, unsigned long *delay_on,
		     unsigned long *delay_off)
{
	struct mlxreg_led_data *led_data = cdev_to_priv(cled);
	int err;

	/*
	 * HW supports two types of blinking: full (6Hz) and half (3Hz).
	 * For delay on/off zero LED is setting to solid color. For others
	 * combination blinking is to be controlled by the software timer.
	 */
	if (!(*delay_on == 0 && *delay_off == 0) &&
	    !(*delay_on == MLXREG_LED_BLINK_3HZ &&
	      *delay_off == MLXREG_LED_BLINK_3HZ) &&
	    !(*delay_on == MLXREG_LED_BLINK_6HZ &&
	      *delay_off == MLXREG_LED_BLINK_6HZ))
		return -EINVAL;

	if (*delay_on == MLXREG_LED_BLINK_6HZ)
		err = mlxreg_led_store_hw(led_data, led_data->base_color +
					  MLXREG_LED_OFFSET_BLINK_6HZ);
	else if (*delay_on == MLXREG_LED_BLINK_3HZ)
		err = mlxreg_led_store_hw(led_data, led_data->base_color +
					  MLXREG_LED_OFFSET_BLINK_3HZ);
	else
		err = mlxreg_led_store_hw(led_data, led_data->base_color);

	return err;
}

__attribute__((used)) static int mlxreg_led_config(struct mlxreg_led_priv_data *priv)
{
	struct mlxreg_core_platform_data *led_pdata = priv->pdata;
	struct mlxreg_core_data *data = led_pdata->data;
	struct mlxreg_led_data *led_data;
	struct led_classdev *led_cdev;
	enum led_brightness brightness;
	int i;
	int err;

	for (i = 0; i < led_pdata->counter; i++, data++) {
		led_data = devm_kzalloc(&priv->pdev->dev, sizeof(*led_data),
					GFP_KERNEL);
		if (!led_data)
			return -ENOMEM;

		led_cdev = &led_data->led_cdev;
		led_data->data_parent = priv;
		if (strstr(data->label, "red") ||
		    strstr(data->label, "orange")) {
			brightness = LED_OFF;
			led_data->base_color = MLXREG_LED_RED_SOLID;
		} else if (strstr(data->label, "amber")) {
			brightness = LED_OFF;
			led_data->base_color = MLXREG_LED_AMBER_SOLID;
		} else {
			brightness = LED_OFF;
			led_data->base_color = MLXREG_LED_GREEN_SOLID;
		}
		sprintf(led_data->led_cdev_name, "%s:%s", "mlxreg",
			data->label);
		led_cdev->name = led_data->led_cdev_name;
		led_cdev->brightness = brightness;
		led_cdev->max_brightness = LED_ON;
		led_cdev->brightness_set_blocking =
						mlxreg_led_brightness_set;
		led_cdev->brightness_get = mlxreg_led_brightness_get;
		led_cdev->blink_set = mlxreg_led_blink_set;
		led_cdev->flags = LED_CORE_SUSPENDRESUME;
		led_data->data = data;
		err = devm_led_classdev_register(&priv->pdev->dev, led_cdev);
		if (err)
			return err;

		if (led_cdev->brightness)
			mlxreg_led_brightness_set(led_cdev,
						  led_cdev->brightness);
		dev_info(led_cdev->dev, "label: %s, mask: 0x%02x, offset:0x%02x\n",
			 data->label, data->mask, data->reg);
	}

	return 0;
}

__attribute__((used)) static int mlxreg_led_probe(struct platform_device *pdev)
{
	struct mlxreg_core_platform_data *led_pdata;
	struct mlxreg_led_priv_data *priv;

	led_pdata = dev_get_platdata(&pdev->dev);
	if (!led_pdata) {
		dev_err(&pdev->dev, "Failed to get platform data.\n");
		return -EINVAL;
	}

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	mutex_init(&priv->access_lock);
	priv->pdev = pdev;
	priv->pdata = led_pdata;

	return mlxreg_led_config(priv);
}

__attribute__((used)) static int mlxreg_led_remove(struct platform_device *pdev)
{
	struct mlxreg_led_priv_data *priv = dev_get_drvdata(&pdev->dev);

	mutex_destroy(&priv->access_lock);

	return 0;
}

