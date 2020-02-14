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
struct rpi_firmware {int dummy; } ;
struct TYPE_2__ {int base; int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get_direction ) (struct gpio_chip*,unsigned int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int can_sleep; int /*<<< orphan*/  ngpio; struct device_node* of_node; int /*<<< orphan*/  owner; int /*<<< orphan*/  label; struct device* parent; } ;
struct rpi_exp_gpio {TYPE_1__ gc; struct rpi_firmware* fw; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct gpio_set_config {unsigned int gpio; int polarity; int state; int /*<<< orphan*/  direction; scalar_t__ term_pull_up; scalar_t__ term_en; } ;
struct gpio_get_set_state {unsigned int gpio; int polarity; int state; int /*<<< orphan*/  direction; scalar_t__ term_pull_up; scalar_t__ term_en; } ;
struct gpio_get_config {unsigned int gpio; int polarity; int state; int /*<<< orphan*/  direction; scalar_t__ term_pull_up; scalar_t__ term_en; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  set_out ;
typedef  int /*<<< orphan*/  set_in ;
typedef  int /*<<< orphan*/  set ;
typedef  int /*<<< orphan*/  get ;

/* Variables and functions */
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MODULE_NAME ; 
 int /*<<< orphan*/  NUM_GPIO ; 
 int RPI_EXP_GPIO_BASE ; 
 int /*<<< orphan*/  RPI_EXP_GPIO_DIR_IN ; 
 int /*<<< orphan*/  RPI_EXP_GPIO_DIR_OUT ; 
 int /*<<< orphan*/  RPI_FIRMWARE_GET_GPIO_CONFIG ; 
 int /*<<< orphan*/  RPI_FIRMWARE_GET_GPIO_STATE ; 
 int /*<<< orphan*/  RPI_FIRMWARE_SET_GPIO_CONFIG ; 
 int /*<<< orphan*/  RPI_FIRMWARE_SET_GPIO_STATE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int devm_gpiochip_add_data (struct device*,TYPE_1__*,struct rpi_exp_gpio*) ; 
 struct rpi_exp_gpio* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct rpi_exp_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 struct device_node* of_get_parent (struct device_node*) ; 
 struct rpi_firmware* rpi_firmware_get (struct device_node*) ; 
 int rpi_firmware_property (struct rpi_firmware*,int /*<<< orphan*/ ,struct gpio_set_config*,int) ; 

__attribute__((used)) static int rpi_exp_gpio_get_polarity(struct gpio_chip *gc, unsigned int off)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_get_config get;
	int ret;

	gpio = gpiochip_get_data(gc);

	get.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_GET_GPIO_CONFIG,
				    &get, sizeof(get));
	if (ret || get.gpio != 0) {
		dev_err(gc->parent, "Failed to get GPIO %u config (%d %x)\n",
			off, ret, get.gpio);
		return ret ? ret : -EIO;
	}
	return get.polarity;
}

__attribute__((used)) static int rpi_exp_gpio_dir_in(struct gpio_chip *gc, unsigned int off)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_set_config set_in;
	int ret;

	gpio = gpiochip_get_data(gc);

	set_in.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */
	set_in.direction = RPI_EXP_GPIO_DIR_IN;
	set_in.term_en = 0;		/* termination disabled */
	set_in.term_pull_up = 0;	/* n/a as termination disabled */
	set_in.state = 0;		/* n/a as configured as an input */

	ret = rpi_exp_gpio_get_polarity(gc, off);
	if (ret < 0)
		return ret;
	set_in.polarity = ret;		/* Retain existing setting */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_SET_GPIO_CONFIG,
				    &set_in, sizeof(set_in));
	if (ret || set_in.gpio != 0) {
		dev_err(gc->parent, "Failed to set GPIO %u to input (%d %x)\n",
			off, ret, set_in.gpio);
		return ret ? ret : -EIO;
	}
	return 0;
}

__attribute__((used)) static int rpi_exp_gpio_dir_out(struct gpio_chip *gc, unsigned int off, int val)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_set_config set_out;
	int ret;

	gpio = gpiochip_get_data(gc);

	set_out.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */
	set_out.direction = RPI_EXP_GPIO_DIR_OUT;
	set_out.term_en = 0;		/* n/a as an output */
	set_out.term_pull_up = 0;	/* n/a as termination disabled */
	set_out.state = val;		/* Output state */

	ret = rpi_exp_gpio_get_polarity(gc, off);
	if (ret < 0)
		return ret;
	set_out.polarity = ret;		/* Retain existing setting */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_SET_GPIO_CONFIG,
				    &set_out, sizeof(set_out));
	if (ret || set_out.gpio != 0) {
		dev_err(gc->parent, "Failed to set GPIO %u to output (%d %x)\n",
			off, ret, set_out.gpio);
		return ret ? ret : -EIO;
	}
	return 0;
}

__attribute__((used)) static int rpi_exp_gpio_get_direction(struct gpio_chip *gc, unsigned int off)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_get_config get;
	int ret;

	gpio = gpiochip_get_data(gc);

	get.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_GET_GPIO_CONFIG,
				    &get, sizeof(get));
	if (ret || get.gpio != 0) {
		dev_err(gc->parent,
			"Failed to get GPIO %u config (%d %x)\n", off, ret,
			get.gpio);
		return ret ? ret : -EIO;
	}
	return !get.direction;
}

__attribute__((used)) static int rpi_exp_gpio_get(struct gpio_chip *gc, unsigned int off)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_get_set_state get;
	int ret;

	gpio = gpiochip_get_data(gc);

	get.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */
	get.state = 0;		/* storage for returned value */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_GET_GPIO_STATE,
					 &get, sizeof(get));
	if (ret || get.gpio != 0) {
		dev_err(gc->parent,
			"Failed to get GPIO %u state (%d %x)\n", off, ret,
			get.gpio);
		return ret ? ret : -EIO;
	}
	return !!get.state;
}

__attribute__((used)) static void rpi_exp_gpio_set(struct gpio_chip *gc, unsigned int off, int val)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_get_set_state set;
	int ret;

	gpio = gpiochip_get_data(gc);

	set.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */
	set.state = val;	/* Output state */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_SET_GPIO_STATE,
					 &set, sizeof(set));
	if (ret || set.gpio != 0)
		dev_err(gc->parent,
			"Failed to set GPIO %u state (%d %x)\n", off, ret,
			set.gpio);
}

__attribute__((used)) static int rpi_exp_gpio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct device_node *fw_node;
	struct rpi_firmware *fw;
	struct rpi_exp_gpio *rpi_gpio;

	fw_node = of_get_parent(np);
	if (!fw_node) {
		dev_err(dev, "Missing firmware node\n");
		return -ENOENT;
	}

	fw = rpi_firmware_get(fw_node);
	if (!fw)
		return -EPROBE_DEFER;

	rpi_gpio = devm_kzalloc(dev, sizeof(*rpi_gpio), GFP_KERNEL);
	if (!rpi_gpio)
		return -ENOMEM;

	rpi_gpio->fw = fw;
	rpi_gpio->gc.parent = dev;
	rpi_gpio->gc.label = MODULE_NAME;
	rpi_gpio->gc.owner = THIS_MODULE;
	rpi_gpio->gc.of_node = np;
	rpi_gpio->gc.base = -1;
	rpi_gpio->gc.ngpio = NUM_GPIO;

	rpi_gpio->gc.direction_input = rpi_exp_gpio_dir_in;
	rpi_gpio->gc.direction_output = rpi_exp_gpio_dir_out;
	rpi_gpio->gc.get_direction = rpi_exp_gpio_get_direction;
	rpi_gpio->gc.get = rpi_exp_gpio_get;
	rpi_gpio->gc.set = rpi_exp_gpio_set;
	rpi_gpio->gc.can_sleep = true;

	return devm_gpiochip_add_data(dev, &rpi_gpio->gc, rpi_gpio);
}

