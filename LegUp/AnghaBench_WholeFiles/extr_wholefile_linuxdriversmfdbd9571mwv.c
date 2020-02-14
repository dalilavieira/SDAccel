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
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; struct device dev; } ;
struct bd9571mwv {int /*<<< orphan*/  irq_data; int /*<<< orphan*/  irq; struct device* dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BD9571MWV_PRODUCT_CODE ; 
 unsigned int BD9571MWV_PRODUCT_CODE_VAL ; 
 int /*<<< orphan*/  BD9571MWV_PRODUCT_REVISION ; 
 int /*<<< orphan*/  BD9571MWV_VENDOR_CODE ; 
 unsigned int BD9571MWV_VENDOR_CODE_VAL ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bd9571mwv_cells ; 
 int /*<<< orphan*/  bd9571mwv_irq_chip ; 
 int /*<<< orphan*/  bd9571mwv_regmap_config ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,unsigned int) ; 
 struct bd9571mwv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct bd9571mwv* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct bd9571mwv*) ; 
 int mfd_add_devices (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_add_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_del_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_irq_get_domain (int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int bd9571mwv_identify(struct bd9571mwv *bd)
{
	struct device *dev = bd->dev;
	unsigned int value;
	int ret;

	ret = regmap_read(bd->regmap, BD9571MWV_VENDOR_CODE, &value);
	if (ret) {
		dev_err(dev, "Failed to read vendor code register (ret=%i)\n",
			ret);
		return ret;
	}

	if (value != BD9571MWV_VENDOR_CODE_VAL) {
		dev_err(dev, "Invalid vendor code ID %02x (expected %02x)\n",
			value, BD9571MWV_VENDOR_CODE_VAL);
		return -EINVAL;
	}

	ret = regmap_read(bd->regmap, BD9571MWV_PRODUCT_CODE, &value);
	if (ret) {
		dev_err(dev, "Failed to read product code register (ret=%i)\n",
			ret);
		return ret;
	}

	if (value != BD9571MWV_PRODUCT_CODE_VAL) {
		dev_err(dev, "Invalid product code ID %02x (expected %02x)\n",
			value, BD9571MWV_PRODUCT_CODE_VAL);
		return -EINVAL;
	}

	ret = regmap_read(bd->regmap, BD9571MWV_PRODUCT_REVISION, &value);
	if (ret) {
		dev_err(dev, "Failed to read revision register (ret=%i)\n",
			ret);
		return ret;
	}

	dev_info(dev, "Device: BD9571MWV rev. %d\n", value & 0xff);

	return 0;
}

__attribute__((used)) static int bd9571mwv_probe(struct i2c_client *client,
			  const struct i2c_device_id *ids)
{
	struct bd9571mwv *bd;
	int ret;

	bd = devm_kzalloc(&client->dev, sizeof(*bd), GFP_KERNEL);
	if (!bd)
		return -ENOMEM;

	i2c_set_clientdata(client, bd);
	bd->dev = &client->dev;
	bd->irq = client->irq;

	bd->regmap = devm_regmap_init_i2c(client, &bd9571mwv_regmap_config);
	if (IS_ERR(bd->regmap)) {
		dev_err(bd->dev, "Failed to initialize register map\n");
		return PTR_ERR(bd->regmap);
	}

	ret = bd9571mwv_identify(bd);
	if (ret)
		return ret;

	ret = regmap_add_irq_chip(bd->regmap, bd->irq, IRQF_ONESHOT, 0,
				  &bd9571mwv_irq_chip, &bd->irq_data);
	if (ret) {
		dev_err(bd->dev, "Failed to register IRQ chip\n");
		return ret;
	}

	ret = mfd_add_devices(bd->dev, PLATFORM_DEVID_AUTO, bd9571mwv_cells,
			      ARRAY_SIZE(bd9571mwv_cells), NULL, 0,
			      regmap_irq_get_domain(bd->irq_data));
	if (ret) {
		regmap_del_irq_chip(bd->irq, bd->irq_data);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bd9571mwv_remove(struct i2c_client *client)
{
	struct bd9571mwv *bd = i2c_get_clientdata(client);

	regmap_del_irq_chip(bd->irq, bd->irq_data);

	return 0;
}

