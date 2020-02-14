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
typedef  int umode_t ;
typedef  long u32 ;
struct thermal_cooling_device {struct mlxreg_fan* devdata; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct mlxreg_fan_tacho {int connected; scalar_t__ mask; int /*<<< orphan*/  reg; } ;
struct TYPE_2__ {int connected; int /*<<< orphan*/  reg; } ;
struct mlxreg_fan {unsigned long* cooling_levels; struct device* cdev; int /*<<< orphan*/  regmap; int /*<<< orphan*/ * dev; scalar_t__ divider; scalar_t__ samples; TYPE_1__ pwm; struct mlxreg_fan_tacho* tacho; } ;
struct mlxreg_core_platform_data {int counter; int /*<<< orphan*/  regmap; struct mlxreg_core_data* data; } ;
struct mlxreg_core_data {int /*<<< orphan*/  label; scalar_t__ bit; scalar_t__ mask; int /*<<< orphan*/  reg; } ;
struct device {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_THERMAL ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct device*) ; 
 scalar_t__ IS_REACHABLE (int /*<<< orphan*/ ) ; 
 long MLXREG_FAN_GET_FAULT (long,scalar_t__) ; 
 long MLXREG_FAN_GET_RPM (long,scalar_t__,scalar_t__) ; 
 long MLXREG_FAN_MAX_DUTY ; 
 unsigned long MLXREG_FAN_MAX_STATE ; 
 int MLXREG_FAN_MAX_TACHO ; 
 long MLXREG_FAN_MIN_DUTY ; 
 unsigned long MLXREG_FAN_PWM_DUTY2STATE (long) ; 
 long MLXREG_FAN_PWM_STATE2DUTY (unsigned long) ; 
 unsigned long MLXREG_FAN_SPEED_MAX ; 
 unsigned long MLXREG_FAN_SPEED_MIN ; 
 int MLXREG_FAN_SPEED_MIN_LEVEL ; 
 scalar_t__ MLXREG_FAN_TACHO_DIVIDER_DEF ; 
 scalar_t__ MLXREG_FAN_TACHO_SAMPLES_PER_PULSE_DEF ; 
 int PTR_ERR (struct device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct mlxreg_fan* dev_get_drvdata (struct device*) ; 
 struct mlxreg_core_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct device* devm_hwmon_device_register_with_info (int /*<<< orphan*/ *,char*,struct mlxreg_fan*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct mlxreg_fan* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
#define  hwmon_fan 132 
#define  hwmon_fan_fault 131 
#define  hwmon_fan_input 130 
#define  hwmon_pwm 129 
#define  hwmon_pwm_input 128 
 int /*<<< orphan*/  mlxreg_fan_cooling_ops ; 
 int /*<<< orphan*/  mlxreg_fan_hwmon_chip_info ; 
 struct mlxreg_fan* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mlxreg_fan*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,long*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,long) ; 
 scalar_t__ strnstr (int /*<<< orphan*/ ,char*,int) ; 
 struct device* thermal_cooling_device_register (char*,struct mlxreg_fan*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  thermal_cooling_device_unregister (struct device*) ; 

__attribute__((used)) static int
mlxreg_fan_read(struct device *dev, enum hwmon_sensor_types type, u32 attr,
		int channel, long *val)
{
	struct mlxreg_fan *fan = dev_get_drvdata(dev);
	struct mlxreg_fan_tacho *tacho;
	u32 regval;
	int err;

	switch (type) {
	case hwmon_fan:
		tacho = &fan->tacho[channel];
		switch (attr) {
		case hwmon_fan_input:
			err = regmap_read(fan->regmap, tacho->reg, &regval);
			if (err)
				return err;

			*val = MLXREG_FAN_GET_RPM(regval, fan->divider,
						  fan->samples);
			break;

		case hwmon_fan_fault:
			err = regmap_read(fan->regmap, tacho->reg, &regval);
			if (err)
				return err;

			*val = MLXREG_FAN_GET_FAULT(regval, tacho->mask);
			break;

		default:
			return -EOPNOTSUPP;
		}
		break;

	case hwmon_pwm:
		switch (attr) {
		case hwmon_pwm_input:
			err = regmap_read(fan->regmap, fan->pwm.reg, &regval);
			if (err)
				return err;

			*val = regval;
			break;

		default:
			return -EOPNOTSUPP;
		}
		break;

	default:
		return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static int
mlxreg_fan_write(struct device *dev, enum hwmon_sensor_types type, u32 attr,
		 int channel, long val)
{
	struct mlxreg_fan *fan = dev_get_drvdata(dev);

	switch (type) {
	case hwmon_pwm:
		switch (attr) {
		case hwmon_pwm_input:
			if (val < MLXREG_FAN_MIN_DUTY ||
			    val > MLXREG_FAN_MAX_DUTY)
				return -EINVAL;
			return regmap_write(fan->regmap, fan->pwm.reg, val);
		default:
			return -EOPNOTSUPP;
		}
		break;

	default:
		return -EOPNOTSUPP;
	}

	return -EOPNOTSUPP;
}

__attribute__((used)) static umode_t
mlxreg_fan_is_visible(const void *data, enum hwmon_sensor_types type, u32 attr,
		      int channel)
{
	switch (type) {
	case hwmon_fan:
		if (!(((struct mlxreg_fan *)data)->tacho[channel].connected))
			return 0;

		switch (attr) {
		case hwmon_fan_input:
		case hwmon_fan_fault:
			return 0444;
		default:
			break;
		}
		break;

	case hwmon_pwm:
		if (!(((struct mlxreg_fan *)data)->pwm.connected))
			return 0;

		switch (attr) {
		case hwmon_pwm_input:
			return 0644;
		default:
			break;
		}
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int mlxreg_fan_get_max_state(struct thermal_cooling_device *cdev,
				    unsigned long *state)
{
	*state = MLXREG_FAN_MAX_STATE;
	return 0;
}

__attribute__((used)) static int mlxreg_fan_get_cur_state(struct thermal_cooling_device *cdev,
				    unsigned long *state)

{
	struct mlxreg_fan *fan = cdev->devdata;
	u32 regval;
	int err;

	err = regmap_read(fan->regmap, fan->pwm.reg, &regval);
	if (err) {
		dev_err(fan->dev, "Failed to query PWM duty\n");
		return err;
	}

	*state = MLXREG_FAN_PWM_DUTY2STATE(regval);

	return 0;
}

__attribute__((used)) static int mlxreg_fan_set_cur_state(struct thermal_cooling_device *cdev,
				    unsigned long state)

{
	struct mlxreg_fan *fan = cdev->devdata;
	unsigned long cur_state;
	u32 regval;
	int i;
	int err;

	/*
	 * Verify if this request is for changing allowed FAN dynamical
	 * minimum. If it is - update cooling levels accordingly and update
	 * state, if current state is below the newly requested minimum state.
	 * For example, if current state is 5, and minimal state is to be
	 * changed from 4 to 6, fan->cooling_levels[0 to 5] will be changed all
	 * from 4 to 6. And state 5 (fan->cooling_levels[4]) should be
	 * overwritten.
	 */
	if (state >= MLXREG_FAN_SPEED_MIN && state <= MLXREG_FAN_SPEED_MAX) {
		state -= MLXREG_FAN_MAX_STATE;
		for (i = 0; i < state; i++)
			fan->cooling_levels[i] = state;
		for (i = state; i <= MLXREG_FAN_MAX_STATE; i++)
			fan->cooling_levels[i] = i;

		err = regmap_read(fan->regmap, fan->pwm.reg, &regval);
		if (err) {
			dev_err(fan->dev, "Failed to query PWM duty\n");
			return err;
		}

		cur_state = MLXREG_FAN_PWM_DUTY2STATE(regval);
		if (state < cur_state)
			return 0;

		state = cur_state;
	}

	if (state > MLXREG_FAN_MAX_STATE)
		return -EINVAL;

	/* Normalize the state to the valid speed range. */
	state = fan->cooling_levels[state];
	err = regmap_write(fan->regmap, fan->pwm.reg,
			   MLXREG_FAN_PWM_STATE2DUTY(state));
	if (err) {
		dev_err(fan->dev, "Failed to write PWM duty\n");
		return err;
	}
	return 0;
}

__attribute__((used)) static int mlxreg_fan_config(struct mlxreg_fan *fan,
			     struct mlxreg_core_platform_data *pdata)
{
	struct mlxreg_core_data *data = pdata->data;
	bool configured = false;
	int tacho_num = 0, i;

	fan->samples = MLXREG_FAN_TACHO_SAMPLES_PER_PULSE_DEF;
	fan->divider = MLXREG_FAN_TACHO_DIVIDER_DEF;
	for (i = 0; i < pdata->counter; i++, data++) {
		if (strnstr(data->label, "tacho", sizeof(data->label))) {
			if (tacho_num == MLXREG_FAN_MAX_TACHO) {
				dev_err(fan->dev, "too many tacho entries: %s\n",
					data->label);
				return -EINVAL;
			}
			fan->tacho[tacho_num].reg = data->reg;
			fan->tacho[tacho_num].mask = data->mask;
			fan->tacho[tacho_num++].connected = true;
		} else if (strnstr(data->label, "pwm", sizeof(data->label))) {
			if (fan->pwm.connected) {
				dev_err(fan->dev, "duplicate pwm entry: %s\n",
					data->label);
				return -EINVAL;
			}
			fan->pwm.reg = data->reg;
			fan->pwm.connected = true;
		} else if (strnstr(data->label, "conf", sizeof(data->label))) {
			if (configured) {
				dev_err(fan->dev, "duplicate conf entry: %s\n",
					data->label);
				return -EINVAL;
			}
			/* Validate that conf parameters are not zeros. */
			if (!data->mask || !data->bit) {
				dev_err(fan->dev, "invalid conf entry params: %s\n",
					data->label);
				return -EINVAL;
			}
			fan->samples = data->mask;
			fan->divider = data->bit;
			configured = true;
		} else {
			dev_err(fan->dev, "invalid label: %s\n", data->label);
			return -EINVAL;
		}
	}

	/* Init cooling levels per PWM state. */
	for (i = 0; i < MLXREG_FAN_SPEED_MIN_LEVEL; i++)
		fan->cooling_levels[i] = MLXREG_FAN_SPEED_MIN_LEVEL;
	for (i = MLXREG_FAN_SPEED_MIN_LEVEL; i <= MLXREG_FAN_MAX_STATE; i++)
		fan->cooling_levels[i] = i;

	return 0;
}

__attribute__((used)) static int mlxreg_fan_probe(struct platform_device *pdev)
{
	struct mlxreg_core_platform_data *pdata;
	struct mlxreg_fan *fan;
	struct device *hwm;
	int err;

	pdata = dev_get_platdata(&pdev->dev);
	if (!pdata) {
		dev_err(&pdev->dev, "Failed to get platform data.\n");
		return -EINVAL;
	}

	fan = devm_kzalloc(&pdev->dev, sizeof(*fan), GFP_KERNEL);
	if (!fan)
		return -ENOMEM;

	fan->dev = &pdev->dev;
	fan->regmap = pdata->regmap;
	platform_set_drvdata(pdev, fan);

	err = mlxreg_fan_config(fan, pdata);
	if (err)
		return err;

	hwm = devm_hwmon_device_register_with_info(&pdev->dev, "mlxreg_fan",
						   fan,
						   &mlxreg_fan_hwmon_chip_info,
						   NULL);
	if (IS_ERR(hwm)) {
		dev_err(&pdev->dev, "Failed to register hwmon device\n");
		return PTR_ERR(hwm);
	}

	if (IS_REACHABLE(CONFIG_THERMAL)) {
		fan->cdev = thermal_cooling_device_register("mlxreg_fan", fan,
						&mlxreg_fan_cooling_ops);
		if (IS_ERR(fan->cdev)) {
			dev_err(&pdev->dev, "Failed to register cooling device\n");
			return PTR_ERR(fan->cdev);
		}
	}

	return 0;
}

__attribute__((used)) static int mlxreg_fan_remove(struct platform_device *pdev)
{
	struct mlxreg_fan *fan = platform_get_drvdata(pdev);

	if (IS_REACHABLE(CONFIG_THERMAL))
		thermal_cooling_device_unregister(fan->cdev);

	return 0;
}

