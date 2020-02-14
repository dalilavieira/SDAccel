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
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct arche_apb_ctrl_drvdata {int init_disabled; scalar_t__ state; unsigned int resetn_gpio; unsigned int spi_en_gpio; unsigned int clk_en_gpio; int spi_en_polarity_high; unsigned int boot_ret_gpio; int pwroff_gpio; void* pin_default; void* pinctrl; void* vio; void* vcore; void* pwrdn_gpio; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
#define  ARCHE_PLATFORM_STATE_ACTIVE 131 
#define  ARCHE_PLATFORM_STATE_FW_FLASHING 130 
#define  ARCHE_PLATFORM_STATE_OFF 129 
#define  ARCHE_PLATFORM_STATE_STANDBY 128 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long GPIOF_IN ; 
 unsigned long GPIOF_OUT_INIT_HIGH ; 
 unsigned long GPIOF_OUT_INIT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
static  void apb_bootret_deassert (struct device*) ; 
 int /*<<< orphan*/  dev_attr_state ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct arche_apb_ctrl_drvdata* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_gpio_free (struct device*,unsigned int) ; 
 int devm_gpio_request_one (struct device*,int,unsigned long,char*) ; 
 struct arche_apb_ctrl_drvdata* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_pinctrl_get (struct device*) ; 
 void* devm_regulator_get (struct device*,char*) ; 
 scalar_t__ gpio_is_valid (unsigned int) ; 
 int /*<<< orphan*/  gpio_set_value (unsigned int,int) ; 
 void* of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 void* pinctrl_lookup_state (void*,char*) ; 
 struct arche_apb_ctrl_drvdata* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct arche_apb_ctrl_drvdata*) ; 
 int /*<<< orphan*/  regulator_disable (void*) ; 
 int regulator_enable (void*) ; 
 scalar_t__ regulator_is_enabled (void*) ; 
 size_t sprintf (char*,char*,...) ; 
 scalar_t__ sysfs_streq (char const*,char*) ; 
 struct platform_device* to_platform_device (struct device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline void deassert_reset(unsigned int gpio)
{
	gpio_set_value(gpio, 1);
}

__attribute__((used)) static inline void assert_reset(unsigned int gpio)
{
	gpio_set_value(gpio, 0);
}

__attribute__((used)) static int coldboot_seq(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct arche_apb_ctrl_drvdata *apb = platform_get_drvdata(pdev);
	int ret;

	if (apb->init_disabled ||
	    apb->state == ARCHE_PLATFORM_STATE_ACTIVE)
		return 0;

	/* Hold APB in reset state */
	assert_reset(apb->resetn_gpio);

	if (apb->state == ARCHE_PLATFORM_STATE_FW_FLASHING &&
	    gpio_is_valid(apb->spi_en_gpio))
		devm_gpio_free(dev, apb->spi_en_gpio);

	/* Enable power to APB */
	if (!IS_ERR(apb->vcore)) {
		ret = regulator_enable(apb->vcore);
		if (ret) {
			dev_err(dev, "failed to enable core regulator\n");
			return ret;
		}
	}

	if (!IS_ERR(apb->vio)) {
		ret = regulator_enable(apb->vio);
		if (ret) {
			dev_err(dev, "failed to enable IO regulator\n");
			return ret;
		}
	}

	apb_bootret_deassert(dev);

	/* On DB3 clock was not mandatory */
	if (gpio_is_valid(apb->clk_en_gpio))
		gpio_set_value(apb->clk_en_gpio, 1);

	usleep_range(100, 200);

	/* deassert reset to APB : Active-low signal */
	deassert_reset(apb->resetn_gpio);

	apb->state = ARCHE_PLATFORM_STATE_ACTIVE;

	return 0;
}

__attribute__((used)) static int fw_flashing_seq(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct arche_apb_ctrl_drvdata *apb = platform_get_drvdata(pdev);
	int ret;

	if (apb->init_disabled ||
	    apb->state == ARCHE_PLATFORM_STATE_FW_FLASHING)
		return 0;

	ret = regulator_enable(apb->vcore);
	if (ret) {
		dev_err(dev, "failed to enable core regulator\n");
		return ret;
	}

	ret = regulator_enable(apb->vio);
	if (ret) {
		dev_err(dev, "failed to enable IO regulator\n");
		return ret;
	}

	if (gpio_is_valid(apb->spi_en_gpio)) {
		unsigned long flags;

		if (apb->spi_en_polarity_high)
			flags = GPIOF_OUT_INIT_HIGH;
		else
			flags = GPIOF_OUT_INIT_LOW;

		ret = devm_gpio_request_one(dev, apb->spi_en_gpio,
					    flags, "apb_spi_en");
		if (ret) {
			dev_err(dev, "Failed requesting SPI bus en gpio %d\n",
				apb->spi_en_gpio);
			return ret;
		}
	}

	/* for flashing device should be in reset state */
	assert_reset(apb->resetn_gpio);
	apb->state = ARCHE_PLATFORM_STATE_FW_FLASHING;

	return 0;
}

__attribute__((used)) static int standby_boot_seq(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct arche_apb_ctrl_drvdata *apb = platform_get_drvdata(pdev);

	if (apb->init_disabled)
		return 0;

	/*
	 * Even if it is in OFF state,
	 * then we do not want to change the state
	 */
	if (apb->state == ARCHE_PLATFORM_STATE_STANDBY ||
	    apb->state == ARCHE_PLATFORM_STATE_OFF)
		return 0;

	if (apb->state == ARCHE_PLATFORM_STATE_FW_FLASHING &&
	    gpio_is_valid(apb->spi_en_gpio))
		devm_gpio_free(dev, apb->spi_en_gpio);

	/*
	 * As per WDM spec, do nothing
	 *
	 * Pasted from WDM spec,
	 *  - A falling edge on POWEROFF_L is detected (a)
	 *  - WDM enters standby mode, but no output signals are changed
	 */

	/* TODO: POWEROFF_L is input to WDM module  */
	apb->state = ARCHE_PLATFORM_STATE_STANDBY;
	return 0;
}

__attribute__((used)) static void poweroff_seq(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct arche_apb_ctrl_drvdata *apb = platform_get_drvdata(pdev);

	if (apb->init_disabled || apb->state == ARCHE_PLATFORM_STATE_OFF)
		return;

	if (apb->state == ARCHE_PLATFORM_STATE_FW_FLASHING &&
	    gpio_is_valid(apb->spi_en_gpio))
		devm_gpio_free(dev, apb->spi_en_gpio);

	/* disable the clock */
	if (gpio_is_valid(apb->clk_en_gpio))
		gpio_set_value(apb->clk_en_gpio, 0);

	if (!IS_ERR(apb->vcore) && regulator_is_enabled(apb->vcore) > 0)
		regulator_disable(apb->vcore);

	if (!IS_ERR(apb->vio) && regulator_is_enabled(apb->vio) > 0)
		regulator_disable(apb->vio);

	/* As part of exit, put APB back in reset state */
	assert_reset(apb->resetn_gpio);
	apb->state = ARCHE_PLATFORM_STATE_OFF;

	/* TODO: May have to send an event to SVC about this exit */
}

__attribute__((used)) static void apb_bootret_deassert(struct device *dev)
{
	struct arche_apb_ctrl_drvdata *apb = dev_get_drvdata(dev);

	gpio_set_value(apb->boot_ret_gpio, 0);
}

int apb_ctrl_coldboot(struct device *dev)
{
	return coldboot_seq(to_platform_device(dev));
}

int apb_ctrl_fw_flashing(struct device *dev)
{
	return fw_flashing_seq(to_platform_device(dev));
}

int apb_ctrl_standby_boot(struct device *dev)
{
	return standby_boot_seq(to_platform_device(dev));
}

void apb_ctrl_poweroff(struct device *dev)
{
	poweroff_seq(to_platform_device(dev));
}

__attribute__((used)) static ssize_t state_store(struct device *dev,
			   struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct arche_apb_ctrl_drvdata *apb = platform_get_drvdata(pdev);
	int ret = 0;
	bool is_disabled;

	if (sysfs_streq(buf, "off")) {
		if (apb->state == ARCHE_PLATFORM_STATE_OFF)
			return count;

		poweroff_seq(pdev);
	} else if (sysfs_streq(buf, "active")) {
		if (apb->state == ARCHE_PLATFORM_STATE_ACTIVE)
			return count;

		poweroff_seq(pdev);
		is_disabled = apb->init_disabled;
		apb->init_disabled = false;
		ret = coldboot_seq(pdev);
		if (ret)
			apb->init_disabled = is_disabled;
	} else if (sysfs_streq(buf, "standby")) {
		if (apb->state == ARCHE_PLATFORM_STATE_STANDBY)
			return count;

		ret = standby_boot_seq(pdev);
	} else if (sysfs_streq(buf, "fw_flashing")) {
		if (apb->state == ARCHE_PLATFORM_STATE_FW_FLASHING)
			return count;

		/*
		 * First we want to make sure we power off everything
		 * and then enter FW flashing state
		 */
		poweroff_seq(pdev);
		ret = fw_flashing_seq(pdev);
	} else {
		dev_err(dev, "unknown state\n");
		ret = -EINVAL;
	}

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t state_show(struct device *dev,
			  struct device_attribute *attr, char *buf)
{
	struct arche_apb_ctrl_drvdata *apb = dev_get_drvdata(dev);

	switch (apb->state) {
	case ARCHE_PLATFORM_STATE_OFF:
		return sprintf(buf, "off%s\n",
				apb->init_disabled ? ",disabled" : "");
	case ARCHE_PLATFORM_STATE_ACTIVE:
		return sprintf(buf, "active\n");
	case ARCHE_PLATFORM_STATE_STANDBY:
		return sprintf(buf, "standby\n");
	case ARCHE_PLATFORM_STATE_FW_FLASHING:
		return sprintf(buf, "fw_flashing\n");
	default:
		return sprintf(buf, "unknown state\n");
	}
}

__attribute__((used)) static int apb_ctrl_get_devtree_data(struct platform_device *pdev,
				     struct arche_apb_ctrl_drvdata *apb)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	int ret;

	apb->resetn_gpio = of_get_named_gpio(np, "reset-gpios", 0);
	if (apb->resetn_gpio < 0) {
		dev_err(dev, "failed to get reset gpio\n");
		return apb->resetn_gpio;
	}
	ret = devm_gpio_request_one(dev, apb->resetn_gpio,
				    GPIOF_OUT_INIT_LOW, "apb-reset");
	if (ret) {
		dev_err(dev, "Failed requesting reset gpio %d\n",
			apb->resetn_gpio);
		return ret;
	}

	apb->boot_ret_gpio = of_get_named_gpio(np, "boot-ret-gpios", 0);
	if (apb->boot_ret_gpio < 0) {
		dev_err(dev, "failed to get boot retention gpio\n");
		return apb->boot_ret_gpio;
	}
	ret = devm_gpio_request_one(dev, apb->boot_ret_gpio,
				    GPIOF_OUT_INIT_LOW, "boot retention");
	if (ret) {
		dev_err(dev, "Failed requesting bootret gpio %d\n",
			apb->boot_ret_gpio);
		return ret;
	}

	/* It's not mandatory to support power management interface */
	apb->pwroff_gpio = of_get_named_gpio(np, "pwr-off-gpios", 0);
	if (apb->pwroff_gpio < 0) {
		dev_err(dev, "failed to get power off gpio\n");
		return apb->pwroff_gpio;
	}
	ret = devm_gpio_request_one(dev, apb->pwroff_gpio,
				    GPIOF_IN, "pwroff_n");
	if (ret) {
		dev_err(dev, "Failed requesting pwroff_n gpio %d\n",
			apb->pwroff_gpio);
		return ret;
	}

	/* Do not make clock mandatory as of now (for DB3) */
	apb->clk_en_gpio = of_get_named_gpio(np, "clock-en-gpio", 0);
	if (apb->clk_en_gpio < 0) {
		dev_warn(dev, "failed to get clock en gpio\n");
	} else if (gpio_is_valid(apb->clk_en_gpio)) {
		ret = devm_gpio_request_one(dev, apb->clk_en_gpio,
					    GPIOF_OUT_INIT_LOW, "apb_clk_en");
		if (ret) {
			dev_warn(dev, "Failed requesting APB clock en gpio %d\n",
				 apb->clk_en_gpio);
			return ret;
		}
	}

	apb->pwrdn_gpio = of_get_named_gpio(np, "pwr-down-gpios", 0);
	if (apb->pwrdn_gpio < 0)
		dev_warn(dev, "failed to get power down gpio\n");

	/* Regulators are optional, as we may have fixed supply coming in */
	apb->vcore = devm_regulator_get(dev, "vcore");
	if (IS_ERR(apb->vcore))
		dev_warn(dev, "no core regulator found\n");

	apb->vio = devm_regulator_get(dev, "vio");
	if (IS_ERR(apb->vio))
		dev_warn(dev, "no IO regulator found\n");

	apb->pinctrl = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR(apb->pinctrl)) {
		dev_err(&pdev->dev, "could not get pinctrl handle\n");
		return PTR_ERR(apb->pinctrl);
	}
	apb->pin_default = pinctrl_lookup_state(apb->pinctrl, "default");
	if (IS_ERR(apb->pin_default)) {
		dev_err(&pdev->dev, "could not get default pin state\n");
		return PTR_ERR(apb->pin_default);
	}

	/* Only applicable for platform >= V2 */
	apb->spi_en_gpio = of_get_named_gpio(np, "spi-en-gpio", 0);
	if (apb->spi_en_gpio >= 0) {
		if (of_property_read_bool(pdev->dev.of_node,
					  "spi-en-active-high"))
			apb->spi_en_polarity_high = true;
	}

	return 0;
}

__attribute__((used)) static int arche_apb_ctrl_probe(struct platform_device *pdev)
{
	int ret;
	struct arche_apb_ctrl_drvdata *apb;
	struct device *dev = &pdev->dev;

	apb = devm_kzalloc(&pdev->dev, sizeof(*apb), GFP_KERNEL);
	if (!apb)
		return -ENOMEM;

	ret = apb_ctrl_get_devtree_data(pdev, apb);
	if (ret) {
		dev_err(dev, "failed to get apb devicetree data %d\n", ret);
		return ret;
	}

	/* Initially set APB to OFF state */
	apb->state = ARCHE_PLATFORM_STATE_OFF;
	/* Check whether device needs to be enabled on boot */
	if (of_property_read_bool(pdev->dev.of_node, "arche,init-disable"))
		apb->init_disabled = true;

	platform_set_drvdata(pdev, apb);

	/* Create sysfs interface to allow user to change state dynamically */
	ret = device_create_file(dev, &dev_attr_state);
	if (ret) {
		dev_err(dev, "failed to create state file in sysfs\n");
		return ret;
	}

	dev_info(&pdev->dev, "Device registered successfully\n");
	return 0;
}

__attribute__((used)) static int arche_apb_ctrl_remove(struct platform_device *pdev)
{
	device_remove_file(&pdev->dev, &dev_attr_state);
	poweroff_seq(pdev);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

