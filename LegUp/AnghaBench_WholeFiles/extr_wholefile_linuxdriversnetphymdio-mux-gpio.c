#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct mdio_mux_gpio_state* platform_data; int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct mdio_mux_gpio_state {int* values; struct gpio_descs* gpios; int /*<<< orphan*/  mux_handle; } ;
struct gpio_descs {unsigned int ndescs; int /*<<< orphan*/  desc; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct gpio_descs*) ; 
 int PTR_ERR (struct gpio_descs*) ; 
 struct mdio_mux_gpio_state* dev_get_platdata (TYPE_1__*) ; 
 struct mdio_mux_gpio_state* devm_kzalloc (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct gpio_descs* gpiod_get_array (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_put_array (struct gpio_descs*) ; 
 int /*<<< orphan*/  gpiod_set_array_value_cansleep (unsigned int,int /*<<< orphan*/ ,int*) ; 
 int mdio_mux_init (TYPE_1__*,int /*<<< orphan*/ ,int (*) (int,int,void*),int /*<<< orphan*/ *,struct mdio_mux_gpio_state*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mdio_mux_uninit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  struct_size (struct mdio_mux_gpio_state*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  values ; 

__attribute__((used)) static int mdio_mux_gpio_switch_fn(int current_child, int desired_child,
				   void *data)
{
	struct mdio_mux_gpio_state *s = data;
	unsigned int n;

	if (current_child == desired_child)
		return 0;

	for (n = 0; n < s->gpios->ndescs; n++)
		s->values[n] = (desired_child >> n) & 1;

	gpiod_set_array_value_cansleep(s->gpios->ndescs, s->gpios->desc,
				       s->values);

	return 0;
}

__attribute__((used)) static int mdio_mux_gpio_probe(struct platform_device *pdev)
{
	struct mdio_mux_gpio_state *s;
	struct gpio_descs *gpios;
	int r;

	gpios = gpiod_get_array(&pdev->dev, NULL, GPIOD_OUT_LOW);
	if (IS_ERR(gpios))
		return PTR_ERR(gpios);

	s = devm_kzalloc(&pdev->dev, struct_size(s, values, gpios->ndescs),
			 GFP_KERNEL);
	if (!s) {
		gpiod_put_array(gpios);
		return -ENOMEM;
	}

	s->gpios = gpios;

	r = mdio_mux_init(&pdev->dev, pdev->dev.of_node,
			  mdio_mux_gpio_switch_fn, &s->mux_handle, s, NULL);

	if (r != 0) {
		gpiod_put_array(s->gpios);
		return r;
	}

	pdev->dev.platform_data = s;
	return 0;
}

__attribute__((used)) static int mdio_mux_gpio_remove(struct platform_device *pdev)
{
	struct mdio_mux_gpio_state *s = dev_get_platdata(&pdev->dev);
	mdio_mux_uninit(s->mux_handle);
	gpiod_put_array(s->gpios);
	return 0;
}

