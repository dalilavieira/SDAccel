#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct of_device_id {scalar_t__ data; } ;
struct max8998_platform_data {int /*<<< orphan*/  wakeup; int /*<<< orphan*/  irq_base; int /*<<< orphan*/  ono; } ;
struct max8998_dev {unsigned long type; int /*<<< orphan*/  irq; struct i2c_client* rtc; struct device* dev; int /*<<< orphan*/  wakeup; int /*<<< orphan*/  iolock; int /*<<< orphan*/  irq_base; int /*<<< orphan*/  ono; struct max8998_platform_data* pdata; struct i2c_client* i2c; } ;
struct i2c_device_id {unsigned long driver_data; } ;
struct device {scalar_t__ of_node; } ;
struct i2c_client {struct device dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  irq; } ;
struct TYPE_6__ {int addr; int val; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct max8998_platform_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct max8998_platform_data*) ; 
 int PTR_ERR (struct max8998_platform_data*) ; 
 int /*<<< orphan*/  RTC_I2C_ADDR ; 
#define  TYPE_LP3974 129 
#define  TYPE_MAX8998 128 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct max8998_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int /*<<< orphan*/ ) ; 
 scalar_t__ device_may_wakeup (struct device*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct max8998_dev* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max8998_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  irq_of_parse_and_map (scalar_t__,int) ; 
 int /*<<< orphan*/  irq_set_irq_wake (int /*<<< orphan*/ ,int) ; 
 TYPE_1__* lp3974_devs ; 
 TYPE_1__* max8998_devs ; 
 int /*<<< orphan*/  max8998_dt_match ; 
 TYPE_1__* max8998_dump ; 
 int /*<<< orphan*/  max8998_irq_exit (struct max8998_dev*) ; 
 int /*<<< orphan*/  max8998_irq_init (struct max8998_dev*) ; 
 int max8998_irq_resume (struct max8998_dev*) ; 
 int mfd_add_devices (struct device*,int,TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

int max8998_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest)
{
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8998->iolock);
	ret = i2c_smbus_read_byte_data(i2c, reg);
	mutex_unlock(&max8998->iolock);
	if (ret < 0)
		return ret;

	ret &= 0xff;
	*dest = ret;
	return 0;
}

int max8998_bulk_read(struct i2c_client *i2c, u8 reg, int count, u8 *buf)
{
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8998->iolock);
	ret = i2c_smbus_read_i2c_block_data(i2c, reg, count, buf);
	mutex_unlock(&max8998->iolock);
	if (ret < 0)
		return ret;

	return 0;
}

int max8998_write_reg(struct i2c_client *i2c, u8 reg, u8 value)
{
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8998->iolock);
	ret = i2c_smbus_write_byte_data(i2c, reg, value);
	mutex_unlock(&max8998->iolock);
	return ret;
}

int max8998_bulk_write(struct i2c_client *i2c, u8 reg, int count, u8 *buf)
{
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8998->iolock);
	ret = i2c_smbus_write_i2c_block_data(i2c, reg, count, buf);
	mutex_unlock(&max8998->iolock);
	if (ret < 0)
		return ret;

	return 0;
}

int max8998_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask)
{
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);
	int ret;

	mutex_lock(&max8998->iolock);
	ret = i2c_smbus_read_byte_data(i2c, reg);
	if (ret >= 0) {
		u8 old_val = ret & 0xff;
		u8 new_val = (val & mask) | (old_val & (~mask));
		ret = i2c_smbus_write_byte_data(i2c, reg, new_val);
	}
	mutex_unlock(&max8998->iolock);
	return ret;
}

__attribute__((used)) static struct max8998_platform_data *max8998_i2c_parse_dt_pdata(
							struct device *dev)
{
	struct max8998_platform_data *pd;

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

__attribute__((used)) static inline unsigned long max8998_i2c_get_driver_data(struct i2c_client *i2c,
						const struct i2c_device_id *id)
{
	if (IS_ENABLED(CONFIG_OF) && i2c->dev.of_node) {
		const struct of_device_id *match;
		match = of_match_node(max8998_dt_match, i2c->dev.of_node);
		return (unsigned long)match->data;
	}

	return id->driver_data;
}

__attribute__((used)) static int max8998_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct max8998_platform_data *pdata = dev_get_platdata(&i2c->dev);
	struct max8998_dev *max8998;
	int ret = 0;

	max8998 = devm_kzalloc(&i2c->dev, sizeof(struct max8998_dev),
				GFP_KERNEL);
	if (max8998 == NULL)
		return -ENOMEM;

	if (IS_ENABLED(CONFIG_OF) && i2c->dev.of_node) {
		pdata = max8998_i2c_parse_dt_pdata(&i2c->dev);
		if (IS_ERR(pdata))
			return PTR_ERR(pdata);
	}

	i2c_set_clientdata(i2c, max8998);
	max8998->dev = &i2c->dev;
	max8998->i2c = i2c;
	max8998->irq = i2c->irq;
	max8998->type = max8998_i2c_get_driver_data(i2c, id);
	max8998->pdata = pdata;
	if (pdata) {
		max8998->ono = pdata->ono;
		max8998->irq_base = pdata->irq_base;
		max8998->wakeup = pdata->wakeup;
	}
	mutex_init(&max8998->iolock);

	max8998->rtc = i2c_new_dummy(i2c->adapter, RTC_I2C_ADDR);
	if (!max8998->rtc) {
		dev_err(&i2c->dev, "Failed to allocate I2C device for RTC\n");
		return -ENODEV;
	}
	i2c_set_clientdata(max8998->rtc, max8998);

	max8998_irq_init(max8998);

	pm_runtime_set_active(max8998->dev);

	switch (max8998->type) {
	case TYPE_LP3974:
		ret = mfd_add_devices(max8998->dev, -1,
				      lp3974_devs, ARRAY_SIZE(lp3974_devs),
				      NULL, 0, NULL);
		break;
	case TYPE_MAX8998:
		ret = mfd_add_devices(max8998->dev, -1,
				      max8998_devs, ARRAY_SIZE(max8998_devs),
				      NULL, 0, NULL);
		break;
	default:
		ret = -EINVAL;
	}

	if (ret < 0)
		goto err;

	device_init_wakeup(max8998->dev, max8998->wakeup);

	return ret;

err:
	mfd_remove_devices(max8998->dev);
	max8998_irq_exit(max8998);
	i2c_unregister_device(max8998->rtc);
	return ret;
}

__attribute__((used)) static int max8998_suspend(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);

	if (device_may_wakeup(dev))
		irq_set_irq_wake(max8998->irq, 1);
	return 0;
}

__attribute__((used)) static int max8998_resume(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct max8998_dev *max8998 = i2c_get_clientdata(i2c);

	if (device_may_wakeup(dev))
		irq_set_irq_wake(max8998->irq, 0);
	/*
	 * In LP3974, if IRQ registers are not "read & clear"
	 * when it's set during sleep, the interrupt becomes
	 * disabled.
	 */
	return max8998_irq_resume(i2c_get_clientdata(i2c));
}

__attribute__((used)) static int max8998_freeze(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	int i;

	for (i = 0; i < ARRAY_SIZE(max8998_dump); i++)
		max8998_read_reg(i2c, max8998_dump[i].addr,
				&max8998_dump[i].val);

	return 0;
}

__attribute__((used)) static int max8998_restore(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	int i;

	for (i = 0; i < ARRAY_SIZE(max8998_dump); i++)
		max8998_write_reg(i2c, max8998_dump[i].addr,
				max8998_dump[i].val);

	return 0;
}

