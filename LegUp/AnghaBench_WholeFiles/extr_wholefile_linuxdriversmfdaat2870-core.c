#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct aat2870_platform_data {int en_pin; int num_subdevs; TYPE_1__* subdevs; int /*<<< orphan*/  (* uninit ) (struct aat2870_data*) ;int /*<<< orphan*/  (* init ) (struct aat2870_data*) ;} ;
struct aat2870_data {scalar_t__ en_pin; int is_enable; int (* read ) (struct aat2870_data*,size_t,size_t*) ;int (* write ) (struct aat2870_data*,size_t,size_t) ;int (* update ) (struct aat2870_data*,size_t,size_t,size_t) ;int /*<<< orphan*/  (* uninit ) (struct aat2870_data*) ;int /*<<< orphan*/ * dev; int /*<<< orphan*/  (* init ) (struct aat2870_data*) ;int /*<<< orphan*/  io_lock; TYPE_3__* reg_cache; struct i2c_client* client; } ;
struct TYPE_8__ {size_t value; int /*<<< orphan*/  writeable; int /*<<< orphan*/  readable; } ;
struct TYPE_7__ {scalar_t__ id; int /*<<< orphan*/  platform_data; int /*<<< orphan*/  name; } ;
struct TYPE_6__ {scalar_t__ id; int /*<<< orphan*/  platform_data; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 size_t AAT2870_REG_NUM ; 
 int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 TYPE_2__* aat2870_devs ; 
 TYPE_3__* aat2870_regs ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,size_t,size_t) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct aat2870_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct aat2870_data*) ; 
 int devm_gpio_request_one (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,char*) ; 
 struct aat2870_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (scalar_t__,int) ; 
 struct aat2870_data* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_recv (struct i2c_client*,size_t*,int) ; 
 int i2c_master_send (struct i2c_client*,size_t*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct aat2870_data*) ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct aat2870_data*) ; 
 int /*<<< orphan*/  stub2 (struct aat2870_data*) ; 

__attribute__((used)) static int __aat2870_read(struct aat2870_data *aat2870, u8 addr, u8 *val)
{
	int ret;

	if (addr >= AAT2870_REG_NUM) {
		dev_err(aat2870->dev, "Invalid address, 0x%02x\n", addr);
		return -EINVAL;
	}

	if (!aat2870->reg_cache[addr].readable) {
		*val = aat2870->reg_cache[addr].value;
		goto out;
	}

	ret = i2c_master_send(aat2870->client, &addr, 1);
	if (ret < 0)
		return ret;
	if (ret != 1)
		return -EIO;

	ret = i2c_master_recv(aat2870->client, val, 1);
	if (ret < 0)
		return ret;
	if (ret != 1)
		return -EIO;

out:
	dev_dbg(aat2870->dev, "read: addr=0x%02x, val=0x%02x\n", addr, *val);
	return 0;
}

__attribute__((used)) static int __aat2870_write(struct aat2870_data *aat2870, u8 addr, u8 val)
{
	u8 msg[2];
	int ret;

	if (addr >= AAT2870_REG_NUM) {
		dev_err(aat2870->dev, "Invalid address, 0x%02x\n", addr);
		return -EINVAL;
	}

	if (!aat2870->reg_cache[addr].writeable) {
		dev_err(aat2870->dev, "Address 0x%02x is not writeable\n",
			addr);
		return -EINVAL;
	}

	msg[0] = addr;
	msg[1] = val;
	ret = i2c_master_send(aat2870->client, msg, 2);
	if (ret < 0)
		return ret;
	if (ret != 2)
		return -EIO;

	aat2870->reg_cache[addr].value = val;

	dev_dbg(aat2870->dev, "write: addr=0x%02x, val=0x%02x\n", addr, val);
	return 0;
}

__attribute__((used)) static int aat2870_read(struct aat2870_data *aat2870, u8 addr, u8 *val)
{
	int ret;

	mutex_lock(&aat2870->io_lock);
	ret = __aat2870_read(aat2870, addr, val);
	mutex_unlock(&aat2870->io_lock);

	return ret;
}

__attribute__((used)) static int aat2870_write(struct aat2870_data *aat2870, u8 addr, u8 val)
{
	int ret;

	mutex_lock(&aat2870->io_lock);
	ret = __aat2870_write(aat2870, addr, val);
	mutex_unlock(&aat2870->io_lock);

	return ret;
}

__attribute__((used)) static int aat2870_update(struct aat2870_data *aat2870, u8 addr, u8 mask,
			  u8 val)
{
	int change;
	u8 old_val, new_val;
	int ret;

	mutex_lock(&aat2870->io_lock);

	ret = __aat2870_read(aat2870, addr, &old_val);
	if (ret)
		goto out_unlock;

	new_val = (old_val & ~mask) | (val & mask);
	change = old_val != new_val;
	if (change)
		ret = __aat2870_write(aat2870, addr, new_val);

out_unlock:
	mutex_unlock(&aat2870->io_lock);

	return ret;
}

__attribute__((used)) static inline void aat2870_enable(struct aat2870_data *aat2870)
{
	if (aat2870->en_pin >= 0)
		gpio_set_value(aat2870->en_pin, 1);

	aat2870->is_enable = 1;
}

__attribute__((used)) static inline void aat2870_disable(struct aat2870_data *aat2870)
{
	if (aat2870->en_pin >= 0)
		gpio_set_value(aat2870->en_pin, 0);

	aat2870->is_enable = 0;
}

__attribute__((used)) static inline void aat2870_init_debugfs(struct aat2870_data *aat2870)
{
}

__attribute__((used)) static inline void aat2870_uninit_debugfs(struct aat2870_data *aat2870)
{
}

__attribute__((used)) static int aat2870_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct aat2870_platform_data *pdata = dev_get_platdata(&client->dev);
	struct aat2870_data *aat2870;
	int i, j;
	int ret = 0;

	aat2870 = devm_kzalloc(&client->dev, sizeof(struct aat2870_data),
				GFP_KERNEL);
	if (!aat2870)
		return -ENOMEM;

	aat2870->dev = &client->dev;
	dev_set_drvdata(aat2870->dev, aat2870);

	aat2870->client = client;
	i2c_set_clientdata(client, aat2870);

	aat2870->reg_cache = aat2870_regs;

	if (pdata->en_pin < 0)
		aat2870->en_pin = -1;
	else
		aat2870->en_pin = pdata->en_pin;

	aat2870->init = pdata->init;
	aat2870->uninit = pdata->uninit;
	aat2870->read = aat2870_read;
	aat2870->write = aat2870_write;
	aat2870->update = aat2870_update;

	mutex_init(&aat2870->io_lock);

	if (aat2870->init)
		aat2870->init(aat2870);

	if (aat2870->en_pin >= 0) {
		ret = devm_gpio_request_one(&client->dev, aat2870->en_pin,
					GPIOF_OUT_INIT_HIGH, "aat2870-en");
		if (ret < 0) {
			dev_err(&client->dev,
				"Failed to request GPIO %d\n", aat2870->en_pin);
			return ret;
		}
	}

	aat2870_enable(aat2870);

	for (i = 0; i < pdata->num_subdevs; i++) {
		for (j = 0; j < ARRAY_SIZE(aat2870_devs); j++) {
			if ((pdata->subdevs[i].id == aat2870_devs[j].id) &&
					!strcmp(pdata->subdevs[i].name,
						aat2870_devs[j].name)) {
				aat2870_devs[j].platform_data =
					pdata->subdevs[i].platform_data;
				break;
			}
		}
	}

	ret = mfd_add_devices(aat2870->dev, 0, aat2870_devs,
			      ARRAY_SIZE(aat2870_devs), NULL, 0, NULL);
	if (ret != 0) {
		dev_err(aat2870->dev, "Failed to add subdev: %d\n", ret);
		goto out_disable;
	}

	aat2870_init_debugfs(aat2870);

	return 0;

out_disable:
	aat2870_disable(aat2870);
	return ret;
}

__attribute__((used)) static int aat2870_i2c_remove(struct i2c_client *client)
{
	struct aat2870_data *aat2870 = i2c_get_clientdata(client);

	aat2870_uninit_debugfs(aat2870);

	mfd_remove_devices(aat2870->dev);
	aat2870_disable(aat2870);
	if (aat2870->uninit)
		aat2870->uninit(aat2870);

	return 0;
}

