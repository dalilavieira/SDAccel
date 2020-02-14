#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct irq_data {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_8__ {struct device_node* of_node; } ;
struct i2c_client {int irq; TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct as3722 {unsigned long irq_flags; int chip_irq; TYPE_1__* dev; int /*<<< orphan*/  irq_data; void* en_ac_ok_pwr_on; int /*<<< orphan*/  regmap; void* en_intern_i2c_pullup; void* en_intern_int_pullup; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AS3722_ASIC_ID1_REG ; 
 int /*<<< orphan*/  AS3722_ASIC_ID2_REG ; 
 int AS3722_CTRL_SEQU1_AC_OK_PWR_ON ; 
 int /*<<< orphan*/  AS3722_CTRL_SEQU1_REG ; 
 int AS3722_DEVICE_ID ; 
 int AS3722_I2C_PULL_UP ; 
 int AS3722_INT_PULL_UP ; 
 int /*<<< orphan*/  AS3722_IOVOLTAGE_REG ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long IRQF_ONESHOT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  as3722_devs ; 
 int /*<<< orphan*/  as3722_irq_chip ; 
 int as3722_read (struct as3722*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  as3722_regmap_config ; 
 int as3722_update_bits (struct as3722*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_1__*,int) ; 
 struct as3722* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (TYPE_1__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_regmap_add_irq_chip (TYPE_1__*,int /*<<< orphan*/ ,int,unsigned long,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct as3722*) ; 
 struct irq_data* irq_get_irq_data (int) ; 
 unsigned long irqd_get_trigger_type (struct irq_data*) ; 
 void* of_property_read_bool (struct device_node*,char*) ; 
 int /*<<< orphan*/  regmap_irq_get_domain (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int as3722_check_device_id(struct as3722 *as3722)
{
	u32 val;
	int ret;

	/* Check that this is actually a AS3722 */
	ret = as3722_read(as3722, AS3722_ASIC_ID1_REG, &val);
	if (ret < 0) {
		dev_err(as3722->dev, "ASIC_ID1 read failed: %d\n", ret);
		return ret;
	}

	if (val != AS3722_DEVICE_ID) {
		dev_err(as3722->dev, "Device is not AS3722, ID is 0x%x\n", val);
		return -ENODEV;
	}

	ret = as3722_read(as3722, AS3722_ASIC_ID2_REG, &val);
	if (ret < 0) {
		dev_err(as3722->dev, "ASIC_ID2 read failed: %d\n", ret);
		return ret;
	}

	dev_info(as3722->dev, "AS3722 with revision 0x%x found\n", val);
	return 0;
}

__attribute__((used)) static int as3722_configure_pullups(struct as3722 *as3722)
{
	int ret;
	u32 val = 0;

	if (as3722->en_intern_int_pullup)
		val |= AS3722_INT_PULL_UP;
	if (as3722->en_intern_i2c_pullup)
		val |= AS3722_I2C_PULL_UP;

	ret = as3722_update_bits(as3722, AS3722_IOVOLTAGE_REG,
			AS3722_INT_PULL_UP | AS3722_I2C_PULL_UP, val);
	if (ret < 0)
		dev_err(as3722->dev, "IOVOLTAGE_REG update failed: %d\n", ret);
	return ret;
}

__attribute__((used)) static int as3722_i2c_of_probe(struct i2c_client *i2c,
			struct as3722 *as3722)
{
	struct device_node *np = i2c->dev.of_node;
	struct irq_data *irq_data;

	if (!np) {
		dev_err(&i2c->dev, "Device Tree not found\n");
		return -EINVAL;
	}

	irq_data = irq_get_irq_data(i2c->irq);
	if (!irq_data) {
		dev_err(&i2c->dev, "Invalid IRQ: %d\n", i2c->irq);
		return -EINVAL;
	}

	as3722->en_intern_int_pullup = of_property_read_bool(np,
					"ams,enable-internal-int-pullup");
	as3722->en_intern_i2c_pullup = of_property_read_bool(np,
					"ams,enable-internal-i2c-pullup");
	as3722->en_ac_ok_pwr_on = of_property_read_bool(np,
					"ams,enable-ac-ok-power-on");
	as3722->irq_flags = irqd_get_trigger_type(irq_data);
	dev_dbg(&i2c->dev, "IRQ flags are 0x%08lx\n", as3722->irq_flags);
	return 0;
}

__attribute__((used)) static int as3722_i2c_probe(struct i2c_client *i2c,
			const struct i2c_device_id *id)
{
	struct as3722 *as3722;
	unsigned long irq_flags;
	int ret;
	u8 val = 0;

	as3722 = devm_kzalloc(&i2c->dev, sizeof(struct as3722), GFP_KERNEL);
	if (!as3722)
		return -ENOMEM;

	as3722->dev = &i2c->dev;
	as3722->chip_irq = i2c->irq;
	i2c_set_clientdata(i2c, as3722);

	ret = as3722_i2c_of_probe(i2c, as3722);
	if (ret < 0)
		return ret;

	as3722->regmap = devm_regmap_init_i2c(i2c, &as3722_regmap_config);
	if (IS_ERR(as3722->regmap)) {
		ret = PTR_ERR(as3722->regmap);
		dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
		return ret;
	}

	ret = as3722_check_device_id(as3722);
	if (ret < 0)
		return ret;

	irq_flags = as3722->irq_flags | IRQF_ONESHOT;
	ret = devm_regmap_add_irq_chip(as3722->dev, as3722->regmap,
				       as3722->chip_irq,
				       irq_flags, -1, &as3722_irq_chip,
				       &as3722->irq_data);
	if (ret < 0) {
		dev_err(as3722->dev, "Failed to add regmap irq: %d\n", ret);
		return ret;
	}

	ret = as3722_configure_pullups(as3722);
	if (ret < 0)
		return ret;

	if (as3722->en_ac_ok_pwr_on)
		val = AS3722_CTRL_SEQU1_AC_OK_PWR_ON;
	ret = as3722_update_bits(as3722, AS3722_CTRL_SEQU1_REG,
			AS3722_CTRL_SEQU1_AC_OK_PWR_ON, val);
	if (ret < 0) {
		dev_err(as3722->dev, "CTRLsequ1 update failed: %d\n", ret);
		return ret;
	}

	ret = devm_mfd_add_devices(&i2c->dev, -1, as3722_devs,
				   ARRAY_SIZE(as3722_devs), NULL, 0,
				   regmap_irq_get_domain(as3722->irq_data));
	if (ret) {
		dev_err(as3722->dev, "Failed to add MFD devices: %d\n", ret);
		return ret;
	}

	device_init_wakeup(as3722->dev, true);

	dev_dbg(as3722->dev, "AS3722 core driver initialized successfully\n");
	return 0;
}

