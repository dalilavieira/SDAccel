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
struct of_device_id {scalar_t__ data; } ;
struct max8997_platform_data {int /*<<< orphan*/  wakeup; int /*<<< orphan*/  ono; } ;
struct max8997_dev {unsigned long type; int* reg_dump; int /*<<< orphan*/  irq; struct i2c_client* rtc; struct i2c_client* haptic; struct i2c_client* muic; struct device* dev; int /*<<< orphan*/  iolock; int /*<<< orphan*/  ono; struct max8997_platform_data* pdata; struct i2c_client* i2c; } ;
struct i2c_device_id {unsigned long driver_data; } ;
struct device {scalar_t__ of_node; } ;
struct i2c_client {int /*<<< orphan*/  adapter; int /*<<< orphan*/  irq; struct device dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct max8997_platform_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_ADDR_HAPTIC ; 
 int /*<<< orphan*/  I2C_ADDR_MUIC ; 
 int /*<<< orphan*/  I2C_ADDR_RTC ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct max8997_platform_data*) ; 
 int MAX8997_MUIC_REG_END ; 
 int MAX8997_REG_PMIC_END ; 
 int PTR_ERR (struct max8997_platform_data*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct max8997_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int /*<<< orphan*/ ) ; 
 scalar_t__ device_may_wakeup (struct device*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct max8997_dev* i2c_get_clientdata (struct i2c_client*) ; 
 void* i2c_new_dummy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max8997_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  irq_of_parse_and_map (scalar_t__,int) ; 
 int /*<<< orphan*/  irq_set_irq_wake (int /*<<< orphan*/ ,int) ; 
 int* max8997_devs ; 
 int* max8997_dumpaddr_haptic ; 
 int* max8997_dumpaddr_muic ; 
 int* max8997_dumpaddr_pmic ; 
 int /*<<< orphan*/  max8997_irq_init (struct max8997_dev*) ; 
 int max8997_irq_resume (struct max8997_dev*) ; 
 int /*<<< orphan*/  max8997_pmic_dt_match ; 
 int mfd_add_devices (struct device*,int,int*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

int max8997_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest)
{
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8997->iolock);
	ret = i2c_smbus_read_byte_data(i2c, reg);
	mutex_unlock(&max8997->iolock);
	if (ret < 0)
		return ret;

	ret &= 0xff;
	*dest = ret;
	return 0;
}

int max8997_bulk_read(struct i2c_client *i2c, u8 reg, int count, u8 *buf)
{
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8997->iolock);
	ret = i2c_smbus_read_i2c_block_data(i2c, reg, count, buf);
	mutex_unlock(&max8997->iolock);
	if (ret < 0)
		return ret;

	return 0;
}

int max8997_write_reg(struct i2c_client *i2c, u8 reg, u8 value)
{
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8997->iolock);
	ret = i2c_smbus_write_byte_data(i2c, reg, value);
	mutex_unlock(&max8997->iolock);
	return ret;
}

int max8997_bulk_write(struct i2c_client *i2c, u8 reg, int count, u8 *buf)
{
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8997->iolock);
	ret = i2c_smbus_write_i2c_block_data(i2c, reg, count, buf);
	mutex_unlock(&max8997->iolock);
	if (ret < 0)
		return ret;

	return 0;
}

int max8997_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask)
{
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8997->iolock);
	ret = i2c_smbus_read_byte_data(i2c, reg);
	if (ret >= 0) {
		u8 old_val = ret & 0xff;
		u8 new_val = (val & mask) | (old_val & (~mask));
		ret = i2c_smbus_write_byte_data(i2c, reg, new_val);
	}
	mutex_unlock(&max8997->iolock);
	return ret;
}

__attribute__((used)) static struct max8997_platform_data *max8997_i2c_parse_dt_pdata(
					struct device *dev)
{
	struct max8997_platform_data *pd;

	pd = devm_kzalloc(dev, sizeof(*pd), GFP_KERNEL);
	if (!pd)
		return ERR_PTR(-ENOMEM);

	pd->ono = irq_of_parse_and_map(dev->of_node, 1);

	/*
	 * ToDo: the 'wakeup' member in the platform data is more of a linux
	 * specfic information. Hence, there is no binding for that yet and
	 * not parsed here.
	 */

	return pd;
}

__attribute__((used)) static inline unsigned long max8997_i2c_get_driver_data(struct i2c_client *i2c,
						const struct i2c_device_id *id)
{
	if (IS_ENABLED(CONFIG_OF) && i2c->dev.of_node) {
		const struct of_device_id *match;
		match = of_match_node(max8997_pmic_dt_match, i2c->dev.of_node);
		return (unsigned long)match->data;
	}
	return id->driver_data;
}

__attribute__((used)) static int max8997_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct max8997_dev *max8997;
	struct max8997_platform_data *pdata = dev_get_platdata(&i2c->dev);
	int ret = 0;

	max8997 = devm_kzalloc(&i2c->dev, sizeof(struct max8997_dev),
				GFP_KERNEL);
	if (max8997 == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, max8997);
	max8997->dev = &i2c->dev;
	max8997->i2c = i2c;
	max8997->type = max8997_i2c_get_driver_data(i2c, id);
	max8997->irq = i2c->irq;

	if (IS_ENABLED(CONFIG_OF) && max8997->dev->of_node) {
		pdata = max8997_i2c_parse_dt_pdata(max8997->dev);
		if (IS_ERR(pdata))
			return PTR_ERR(pdata);
	}

	if (!pdata)
		return ret;

	max8997->pdata = pdata;
	max8997->ono = pdata->ono;

	mutex_init(&max8997->iolock);

	max8997->rtc = i2c_new_dummy(i2c->adapter, I2C_ADDR_RTC);
	if (!max8997->rtc) {
		dev_err(max8997->dev, "Failed to allocate I2C device for RTC\n");
		return -ENODEV;
	}
	i2c_set_clientdata(max8997->rtc, max8997);

	max8997->haptic = i2c_new_dummy(i2c->adapter, I2C_ADDR_HAPTIC);
	if (!max8997->haptic) {
		dev_err(max8997->dev, "Failed to allocate I2C device for Haptic\n");
		ret = -ENODEV;
		goto err_i2c_haptic;
	}
	i2c_set_clientdata(max8997->haptic, max8997);

	max8997->muic = i2c_new_dummy(i2c->adapter, I2C_ADDR_MUIC);
	if (!max8997->muic) {
		dev_err(max8997->dev, "Failed to allocate I2C device for MUIC\n");
		ret = -ENODEV;
		goto err_i2c_muic;
	}
	i2c_set_clientdata(max8997->muic, max8997);

	pm_runtime_set_active(max8997->dev);

	max8997_irq_init(max8997);

	ret = mfd_add_devices(max8997->dev, -1, max8997_devs,
			ARRAY_SIZE(max8997_devs),
			NULL, 0, NULL);
	if (ret < 0) {
		dev_err(max8997->dev, "failed to add MFD devices %d\n", ret);
		goto err_mfd;
	}

	/*
	 * TODO: enable others (flash, muic, rtc, battery, ...) and
	 * check the return value
	 */

	/* MAX8997 has a power button input. */
	device_init_wakeup(max8997->dev, pdata->wakeup);

	return ret;

err_mfd:
	mfd_remove_devices(max8997->dev);
	i2c_unregister_device(max8997->muic);
err_i2c_muic:
	i2c_unregister_device(max8997->haptic);
err_i2c_haptic:
	i2c_unregister_device(max8997->rtc);
	return ret;
}

__attribute__((used)) static int max8997_freeze(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int i;

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_pmic); i++)
		max8997_read_reg(i2c, max8997_dumpaddr_pmic[i],
				&max8997->reg_dump[i]);

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_muic); i++)
		max8997_read_reg(i2c, max8997_dumpaddr_muic[i],
				&max8997->reg_dump[i + MAX8997_REG_PMIC_END]);

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_haptic); i++)
		max8997_read_reg(i2c, max8997_dumpaddr_haptic[i],
				&max8997->reg_dump[i + MAX8997_REG_PMIC_END +
				MAX8997_MUIC_REG_END]);

	return 0;
}

__attribute__((used)) static int max8997_restore(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);
	int i;

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_pmic); i++)
		max8997_write_reg(i2c, max8997_dumpaddr_pmic[i],
				max8997->reg_dump[i]);

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_muic); i++)
		max8997_write_reg(i2c, max8997_dumpaddr_muic[i],
				max8997->reg_dump[i + MAX8997_REG_PMIC_END]);

	for (i = 0; i < ARRAY_SIZE(max8997_dumpaddr_haptic); i++)
		max8997_write_reg(i2c, max8997_dumpaddr_haptic[i],
				max8997->reg_dump[i + MAX8997_REG_PMIC_END +
				MAX8997_MUIC_REG_END]);

	return 0;
}

__attribute__((used)) static int max8997_suspend(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);

	if (device_may_wakeup(dev))
		irq_set_irq_wake(max8997->irq, 1);
	return 0;
}

__attribute__((used)) static int max8997_resume(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8997_dev *max8997 = i2c_get_clientdata(i2c);

	if (device_may_wakeup(dev))
		irq_set_irq_wake(max8997->irq, 0);
	return max8997_irq_resume(max8997);
}

