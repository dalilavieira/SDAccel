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
struct usb4604 {int mode; struct device* dev; struct gpio_desc* gpio_reset; } ;
struct i2c_device_id {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {struct device dev; } ;
struct gpio_desc {int dummy; } ;
struct device_node {int dummy; } ;
typedef  enum usb4604_mode { ____Placeholder_usb4604_mode } usb4604_mode ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int PTR_ERR (struct gpio_desc*) ; 
#define  USB4604_MODE_HUB 129 
#define  USB4604_MODE_STANDBY 128 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct gpio_desc* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct usb4604* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (struct gpio_desc*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct usb4604*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static void usb4604_reset(struct usb4604 *hub, int state)
{
	gpiod_set_value_cansleep(hub->gpio_reset, state);

	/* Wait for i2c logic to come up */
	if (state)
		msleep(250);
}

__attribute__((used)) static int usb4604_connect(struct usb4604 *hub)
{
	struct device *dev = hub->dev;
	struct i2c_client *client = to_i2c_client(dev);
	int err;
	u8 connect_cmd[] = { 0xaa, 0x55, 0x00 };

	usb4604_reset(hub, 1);

	err = i2c_master_send(client, connect_cmd, ARRAY_SIZE(connect_cmd));
	if (err < 0) {
		usb4604_reset(hub, 0);
		return err;
	}

	hub->mode = USB4604_MODE_HUB;
	dev_dbg(dev, "switched to HUB mode\n");

	return 0;
}

__attribute__((used)) static int usb4604_switch_mode(struct usb4604 *hub, enum usb4604_mode mode)
{
	struct device *dev = hub->dev;
	int err = 0;

	switch (mode) {
	case USB4604_MODE_HUB:
		err = usb4604_connect(hub);
		break;

	case USB4604_MODE_STANDBY:
		usb4604_reset(hub, 0);
		dev_dbg(dev, "switched to STANDBY mode\n");
		break;

	default:
		dev_err(dev, "unknown mode is requested\n");
		err = -EINVAL;
		break;
	}

	return err;
}

__attribute__((used)) static int usb4604_probe(struct usb4604 *hub)
{
	struct device *dev = hub->dev;
	struct device_node *np = dev->of_node;
	struct gpio_desc *gpio;
	u32 mode = USB4604_MODE_HUB;

	gpio = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(gpio))
		return PTR_ERR(gpio);
	hub->gpio_reset = gpio;

	if (of_property_read_u32(np, "initial-mode", &hub->mode))
		hub->mode = mode;

	return usb4604_switch_mode(hub, hub->mode);
}

__attribute__((used)) static int usb4604_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct usb4604 *hub;

	hub = devm_kzalloc(&i2c->dev, sizeof(*hub), GFP_KERNEL);
	if (!hub)
		return -ENOMEM;

	i2c_set_clientdata(i2c, hub);
	hub->dev = &i2c->dev;

	return usb4604_probe(hub);
}

