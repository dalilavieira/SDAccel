#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct rpisense_js {struct platform_device* pdev; int /*<<< orphan*/ * keys_desc; } ;
struct TYPE_4__ {struct platform_device* pdev; } ;
struct rpisense {int /*<<< orphan*/ * dev; struct i2c_client* i2c_client; struct rpisense_js joystick; TYPE_2__ framebuffer; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int RPISENSE_VER ; 
 int RPISENSE_WAI ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct rpisense* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gpio_to_desc (int) ; 
 struct rpisense* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_send (struct i2c_client*,char const*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct rpisense*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int platform_device_add (struct platform_device*) ; 
 struct platform_device* platform_device_alloc (char const*,int) ; 
 int /*<<< orphan*/  platform_device_put (struct platform_device*) ; 
 int /*<<< orphan*/  platform_device_unregister (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rpisense*) ; 
 struct rpisense* rpisense ; 
 int rpisense_reg_read (struct rpisense*,int) ; 

__attribute__((used)) static void rpisense_client_dev_register(struct rpisense *rpisense,
					 const char *name,
					 struct platform_device **pdev)
{
	int ret;

	*pdev = platform_device_alloc(name, -1);
	if (*pdev == NULL) {
		dev_err(rpisense->dev, "Failed to allocate %s\n", name);
		return;
	}

	(*pdev)->dev.parent = rpisense->dev;
	platform_set_drvdata(*pdev, rpisense);
	ret = platform_device_add(*pdev);
	if (ret != 0) {
		dev_err(rpisense->dev, "Failed to register %s: %d\n",
			name, ret);
		platform_device_put(*pdev);
		*pdev = NULL;
	}
}

__attribute__((used)) static int rpisense_probe(struct i2c_client *i2c,
			       const struct i2c_device_id *id)
{
	int ret;
	struct rpisense_js *rpisense_js;

	rpisense = devm_kzalloc(&i2c->dev, sizeof(struct rpisense), GFP_KERNEL);
	if (rpisense == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, rpisense);
	rpisense->dev = &i2c->dev;
	rpisense->i2c_client = i2c;

	ret = rpisense_reg_read(rpisense, RPISENSE_WAI);
	if (ret > 0) {
		if (ret != 's')
			return -EINVAL;
	} else {
		return ret;
	}
	ret = rpisense_reg_read(rpisense, RPISENSE_VER);
	if (ret < 0)
		return ret;

	dev_info(rpisense->dev,
		 "Raspberry Pi Sense HAT firmware version %i\n", ret);

	rpisense_js = &rpisense->joystick;
	rpisense_js->keys_desc = devm_gpiod_get(&i2c->dev,
						"keys-int", GPIOD_IN);
	if (IS_ERR(rpisense_js->keys_desc)) {
		dev_warn(&i2c->dev, "Failed to get keys-int descriptor.\n");
		rpisense_js->keys_desc = gpio_to_desc(23);
		if (rpisense_js->keys_desc == NULL) {
			dev_err(&i2c->dev, "GPIO23 fallback failed.\n");
			return PTR_ERR(rpisense_js->keys_desc);
		}
	}
	rpisense_client_dev_register(rpisense, "rpi-sense-js",
				     &(rpisense->joystick.pdev));
	rpisense_client_dev_register(rpisense, "rpi-sense-fb",
				     &(rpisense->framebuffer.pdev));

	return 0;
}

__attribute__((used)) static int rpisense_remove(struct i2c_client *i2c)
{
	struct rpisense *rpisense = i2c_get_clientdata(i2c);

	platform_device_unregister(rpisense->joystick.pdev);
	return 0;
}

struct rpisense *rpisense_get_dev(void)
{
	return rpisense;
}

s32 rpisense_reg_read(struct rpisense *rpisense, int reg)
{
	int ret = i2c_smbus_read_byte_data(rpisense->i2c_client, reg);

	if (ret < 0)
		dev_err(rpisense->dev, "Read from reg %d failed\n", reg);
	/* Due to the BCM270x I2C clock stretching bug, some values
	 * may have MSB set. Clear it to avoid incorrect values.
	 * */
	return ret & 0x7F;
}

int rpisense_block_write(struct rpisense *rpisense, const char *buf, int count)
{
	int ret = i2c_master_send(rpisense->i2c_client, buf, count);

	if (ret < 0)
		dev_err(rpisense->dev, "Block write failed\n");
	return ret;
}

