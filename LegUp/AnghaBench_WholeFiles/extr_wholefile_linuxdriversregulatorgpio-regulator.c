#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {int dummy; } ;
struct regulator_desc {int type; int n_voltages; TYPE_3__* name; int /*<<< orphan*/ * ops; int /*<<< orphan*/  enable_time; int /*<<< orphan*/  owner; } ;
struct regulator_config {int ena_gpio; int ena_gpio_initialized; int ena_gpio_invert; int ena_gpio_flags; struct device_node* of_node; struct gpio_regulator_data* driver_data; TYPE_2__* init_data; struct device* dev; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct gpio_regulator_state {int dummy; } ;
struct gpio_regulator_data {int nr_states; scalar_t__ state; int nr_gpios; struct regulator_desc desc; TYPE_3__* gpios; TYPE_3__* states; struct gpio_regulator_config* dev; } ;
struct gpio_regulator_config {int enable_high; int enabled_at_boot; int enable_gpio; int nr_gpios; int nr_states; int type; TYPE_2__* init_data; TYPE_4__* gpios; int /*<<< orphan*/  startup_delay; TYPE_4__* states; int /*<<< orphan*/  supply_name; } ;
struct gpio {int dummy; } ;
struct device_node {int dummy; } ;
struct TYPE_11__ {int gpio; int flags; int value; int gpios; int /*<<< orphan*/  label; } ;
struct TYPE_10__ {scalar_t__ gpios; int value; int /*<<< orphan*/  gpio; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
struct TYPE_9__ {TYPE_1__ constraints; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 struct gpio_regulator_config* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIOF_OUT_INIT_HIGH ; 
 int GPIOF_OUT_INIT_LOW ; 
 int INT_MAX ; 
 scalar_t__ IS_ERR (struct gpio_regulator_config*) ; 
 int PTR_ERR (struct gpio_regulator_config*) ; 
#define  REGULATOR_CURRENT 129 
#define  REGULATOR_VOLTAGE 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct gpio_regulator_config* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 void* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free_array (TYPE_3__*,int) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_regulator_current_ops ; 
 int /*<<< orphan*/  gpio_regulator_voltage_ops ; 
 int gpio_request_array (TYPE_3__*,int) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kfree (TYPE_3__*) ; 
 void* kmemdup (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 TYPE_3__* kstrdup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* of_get_named_gpio (struct device_node*,char*,int) ; 
 TYPE_2__* of_get_regulator_init_data (struct device*,struct device_node*,struct regulator_desc const*) ; 
 int of_gpio_count (struct device_node*) ; 
 int of_property_count_u32_elems (struct device_node*,char*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_property_read_u32_index (struct device_node*,char*,int,int*) ; 
 struct gpio_regulator_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct gpio_regulator_data*) ; 
 struct gpio_regulator_data* rdev_get_drvdata (struct regulator_dev*) ; 
 struct gpio_regulator_config* regulator_register (struct regulator_desc*,struct regulator_config*) ; 
 int /*<<< orphan*/  regulator_unregister (struct gpio_regulator_config*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,int) ; 

__attribute__((used)) static int gpio_regulator_get_value(struct regulator_dev *dev)
{
	struct gpio_regulator_data *data = rdev_get_drvdata(dev);
	int ptr;

	for (ptr = 0; ptr < data->nr_states; ptr++)
		if (data->states[ptr].gpios == data->state)
			return data->states[ptr].value;

	return -EINVAL;
}

__attribute__((used)) static int gpio_regulator_set_voltage(struct regulator_dev *dev,
					int min_uV, int max_uV,
					unsigned *selector)
{
	struct gpio_regulator_data *data = rdev_get_drvdata(dev);
	int ptr, target = 0, state, best_val = INT_MAX;

	for (ptr = 0; ptr < data->nr_states; ptr++)
		if (data->states[ptr].value < best_val &&
		    data->states[ptr].value >= min_uV &&
		    data->states[ptr].value <= max_uV) {
			target = data->states[ptr].gpios;
			best_val = data->states[ptr].value;
			if (selector)
				*selector = ptr;
		}

	if (best_val == INT_MAX)
		return -EINVAL;

	for (ptr = 0; ptr < data->nr_gpios; ptr++) {
		state = (target & (1 << ptr)) >> ptr;
		gpio_set_value_cansleep(data->gpios[ptr].gpio, state);
	}
	data->state = target;

	return 0;
}

__attribute__((used)) static int gpio_regulator_list_voltage(struct regulator_dev *dev,
				      unsigned selector)
{
	struct gpio_regulator_data *data = rdev_get_drvdata(dev);

	if (selector >= data->nr_states)
		return -EINVAL;

	return data->states[selector].value;
}

__attribute__((used)) static int gpio_regulator_set_current_limit(struct regulator_dev *dev,
					int min_uA, int max_uA)
{
	struct gpio_regulator_data *data = rdev_get_drvdata(dev);
	int ptr, target = 0, state, best_val = 0;

	for (ptr = 0; ptr < data->nr_states; ptr++)
		if (data->states[ptr].value > best_val &&
		    data->states[ptr].value >= min_uA &&
		    data->states[ptr].value <= max_uA) {
			target = data->states[ptr].gpios;
			best_val = data->states[ptr].value;
		}

	if (best_val == 0)
		return -EINVAL;

	for (ptr = 0; ptr < data->nr_gpios; ptr++) {
		state = (target & (1 << ptr)) >> ptr;
		gpio_set_value_cansleep(data->gpios[ptr].gpio, state);
	}
	data->state = target;

	return 0;
}

__attribute__((used)) static struct gpio_regulator_config *
of_get_gpio_regulator_config(struct device *dev, struct device_node *np,
			     const struct regulator_desc *desc)
{
	struct gpio_regulator_config *config;
	const char *regtype;
	int proplen, gpio, i;
	int ret;

	config = devm_kzalloc(dev,
			sizeof(struct gpio_regulator_config),
			GFP_KERNEL);
	if (!config)
		return ERR_PTR(-ENOMEM);

	config->init_data = of_get_regulator_init_data(dev, np, desc);
	if (!config->init_data)
		return ERR_PTR(-EINVAL);

	config->supply_name = config->init_data->constraints.name;

	if (of_property_read_bool(np, "enable-active-high"))
		config->enable_high = true;

	if (of_property_read_bool(np, "enable-at-boot"))
		config->enabled_at_boot = true;

	of_property_read_u32(np, "startup-delay-us", &config->startup_delay);

	config->enable_gpio = of_get_named_gpio(np, "enable-gpio", 0);
	if (config->enable_gpio < 0 && config->enable_gpio != -ENOENT)
		return ERR_PTR(config->enable_gpio);

	/* Fetch GPIOs. - optional property*/
	ret = of_gpio_count(np);
	if ((ret < 0) && (ret != -ENOENT))
		return ERR_PTR(ret);

	if (ret > 0) {
		config->nr_gpios = ret;
		config->gpios = devm_kcalloc(dev,
					config->nr_gpios, sizeof(struct gpio),
					GFP_KERNEL);
		if (!config->gpios)
			return ERR_PTR(-ENOMEM);

		proplen = of_property_count_u32_elems(np, "gpios-states");
		/* optional property */
		if (proplen < 0)
			proplen = 0;

		if (proplen > 0 && proplen != config->nr_gpios) {
			dev_warn(dev, "gpios <-> gpios-states mismatch\n");
			proplen = 0;
		}

		for (i = 0; i < config->nr_gpios; i++) {
			gpio = of_get_named_gpio(np, "gpios", i);
			if (gpio < 0) {
				if (gpio != -ENOENT)
					return ERR_PTR(gpio);
				break;
			}
			config->gpios[i].gpio = gpio;
			config->gpios[i].label = config->supply_name;
			if (proplen > 0) {
				of_property_read_u32_index(np, "gpios-states",
							   i, &ret);
				if (ret)
					config->gpios[i].flags =
							   GPIOF_OUT_INIT_HIGH;
			}
		}
	}

	/* Fetch states. */
	proplen = of_property_count_u32_elems(np, "states");
	if (proplen < 0) {
		dev_err(dev, "No 'states' property found\n");
		return ERR_PTR(-EINVAL);
	}

	config->states = devm_kcalloc(dev,
				proplen / 2,
				sizeof(struct gpio_regulator_state),
				GFP_KERNEL);
	if (!config->states)
		return ERR_PTR(-ENOMEM);

	for (i = 0; i < proplen / 2; i++) {
		of_property_read_u32_index(np, "states", i * 2,
					   &config->states[i].value);
		of_property_read_u32_index(np, "states", i * 2 + 1,
					   &config->states[i].gpios);
	}
	config->nr_states = i;

	config->type = REGULATOR_VOLTAGE;
	ret = of_property_read_string(np, "regulator-type", &regtype);
	if (ret >= 0) {
		if (!strncmp("voltage", regtype, 7))
			config->type = REGULATOR_VOLTAGE;
		else if (!strncmp("current", regtype, 7))
			config->type = REGULATOR_CURRENT;
		else
			dev_warn(dev, "Unknown regulator-type '%s'\n",
				 regtype);
	}

	return config;
}

__attribute__((used)) static int gpio_regulator_probe(struct platform_device *pdev)
{
	struct gpio_regulator_config *config = dev_get_platdata(&pdev->dev);
	struct device_node *np = pdev->dev.of_node;
	struct gpio_regulator_data *drvdata;
	struct regulator_config cfg = { };
	int ptr, ret, state;

	drvdata = devm_kzalloc(&pdev->dev, sizeof(struct gpio_regulator_data),
			       GFP_KERNEL);
	if (drvdata == NULL)
		return -ENOMEM;

	if (np) {
		config = of_get_gpio_regulator_config(&pdev->dev, np,
						      &drvdata->desc);
		if (IS_ERR(config))
			return PTR_ERR(config);
	}

	drvdata->desc.name = kstrdup(config->supply_name, GFP_KERNEL);
	if (drvdata->desc.name == NULL) {
		dev_err(&pdev->dev, "Failed to allocate supply name\n");
		return -ENOMEM;
	}

	if (config->nr_gpios != 0) {
		drvdata->gpios = kmemdup(config->gpios,
					 config->nr_gpios * sizeof(struct gpio),
					 GFP_KERNEL);
		if (drvdata->gpios == NULL) {
			dev_err(&pdev->dev, "Failed to allocate gpio data\n");
			ret = -ENOMEM;
			goto err_name;
		}

		drvdata->nr_gpios = config->nr_gpios;
		ret = gpio_request_array(drvdata->gpios, drvdata->nr_gpios);
		if (ret) {
			if (ret != -EPROBE_DEFER)
				dev_err(&pdev->dev,
					"Could not obtain regulator setting GPIOs: %d\n",
					ret);
			goto err_memgpio;
		}
	}

	drvdata->states = kmemdup(config->states,
				  config->nr_states *
					 sizeof(struct gpio_regulator_state),
				  GFP_KERNEL);
	if (drvdata->states == NULL) {
		dev_err(&pdev->dev, "Failed to allocate state data\n");
		ret = -ENOMEM;
		goto err_stategpio;
	}
	drvdata->nr_states = config->nr_states;

	drvdata->desc.owner = THIS_MODULE;
	drvdata->desc.enable_time = config->startup_delay;

	/* handle regulator type*/
	switch (config->type) {
	case REGULATOR_VOLTAGE:
		drvdata->desc.type = REGULATOR_VOLTAGE;
		drvdata->desc.ops = &gpio_regulator_voltage_ops;
		drvdata->desc.n_voltages = config->nr_states;
		break;
	case REGULATOR_CURRENT:
		drvdata->desc.type = REGULATOR_CURRENT;
		drvdata->desc.ops = &gpio_regulator_current_ops;
		break;
	default:
		dev_err(&pdev->dev, "No regulator type set\n");
		ret = -EINVAL;
		goto err_memstate;
	}

	/* build initial state from gpio init data. */
	state = 0;
	for (ptr = 0; ptr < drvdata->nr_gpios; ptr++) {
		if (config->gpios[ptr].flags & GPIOF_OUT_INIT_HIGH)
			state |= (1 << ptr);
	}
	drvdata->state = state;

	cfg.dev = &pdev->dev;
	cfg.init_data = config->init_data;
	cfg.driver_data = drvdata;
	cfg.of_node = np;

	if (gpio_is_valid(config->enable_gpio)) {
		cfg.ena_gpio = config->enable_gpio;
		cfg.ena_gpio_initialized = true;
	}
	cfg.ena_gpio_invert = !config->enable_high;
	if (config->enabled_at_boot) {
		if (config->enable_high)
			cfg.ena_gpio_flags |= GPIOF_OUT_INIT_HIGH;
		else
			cfg.ena_gpio_flags |= GPIOF_OUT_INIT_LOW;
	} else {
		if (config->enable_high)
			cfg.ena_gpio_flags |= GPIOF_OUT_INIT_LOW;
		else
			cfg.ena_gpio_flags |= GPIOF_OUT_INIT_HIGH;
	}

	drvdata->dev = regulator_register(&drvdata->desc, &cfg);
	if (IS_ERR(drvdata->dev)) {
		ret = PTR_ERR(drvdata->dev);
		dev_err(&pdev->dev, "Failed to register regulator: %d\n", ret);
		goto err_memstate;
	}

	platform_set_drvdata(pdev, drvdata);

	return 0;

err_memstate:
	kfree(drvdata->states);
err_stategpio:
	gpio_free_array(drvdata->gpios, drvdata->nr_gpios);
err_memgpio:
	kfree(drvdata->gpios);
err_name:
	kfree(drvdata->desc.name);
	return ret;
}

__attribute__((used)) static int gpio_regulator_remove(struct platform_device *pdev)
{
	struct gpio_regulator_data *drvdata = platform_get_drvdata(pdev);

	regulator_unregister(drvdata->dev);

	gpio_free_array(drvdata->gpios, drvdata->nr_gpios);

	kfree(drvdata->states);
	kfree(drvdata->gpios);

	kfree(drvdata->desc.name);

	return 0;
}

