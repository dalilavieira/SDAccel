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
struct lp8788_platform_data {int (* init_func ) (struct lp8788*) ;} ;
struct lp8788 {int /*<<< orphan*/ * dev; struct lp8788_platform_data* pdata; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct lp8788_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct lp8788* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct lp8788* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lp8788*) ; 
 int /*<<< orphan*/  lp8788_devs ; 
 int /*<<< orphan*/  lp8788_irq_exit (struct lp8788*) ; 
 int lp8788_irq_init (struct lp8788*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lp8788_regmap_config ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int,int*,size_t) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 
 int stub1 (struct lp8788*) ; 

int lp8788_read_byte(struct lp8788 *lp, u8 reg, u8 *data)
{
	int ret;
	unsigned int val;

	ret = regmap_read(lp->regmap, reg, &val);
	if (ret < 0) {
		dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
		return ret;
	}

	*data = (u8)val;
	return 0;
}

int lp8788_read_multi_bytes(struct lp8788 *lp, u8 reg, u8 *data, size_t count)
{
	return regmap_bulk_read(lp->regmap, reg, data, count);
}

int lp8788_write_byte(struct lp8788 *lp, u8 reg, u8 data)
{
	return regmap_write(lp->regmap, reg, data);
}

int lp8788_update_bits(struct lp8788 *lp, u8 reg, u8 mask, u8 data)
{
	return regmap_update_bits(lp->regmap, reg, mask, data);
}

__attribute__((used)) static int lp8788_platform_init(struct lp8788 *lp)
{
	struct lp8788_platform_data *pdata = lp->pdata;

	return (pdata && pdata->init_func) ? pdata->init_func(lp) : 0;
}

__attribute__((used)) static int lp8788_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
	struct lp8788 *lp;
	struct lp8788_platform_data *pdata = dev_get_platdata(&cl->dev);
	int ret;

	lp = devm_kzalloc(&cl->dev, sizeof(struct lp8788), GFP_KERNEL);
	if (!lp)
		return -ENOMEM;

	lp->regmap = devm_regmap_init_i2c(cl, &lp8788_regmap_config);
	if (IS_ERR(lp->regmap)) {
		ret = PTR_ERR(lp->regmap);
		dev_err(&cl->dev, "regmap init i2c err: %d\n", ret);
		return ret;
	}

	lp->pdata = pdata;
	lp->dev = &cl->dev;
	i2c_set_clientdata(cl, lp);

	ret = lp8788_platform_init(lp);
	if (ret)
		return ret;

	ret = lp8788_irq_init(lp, cl->irq);
	if (ret)
		return ret;

	return mfd_add_devices(lp->dev, -1, lp8788_devs,
			       ARRAY_SIZE(lp8788_devs), NULL, 0, NULL);
}

__attribute__((used)) static int lp8788_remove(struct i2c_client *cl)
{
	struct lp8788 *lp = i2c_get_clientdata(cl);

	mfd_remove_devices(lp->dev);
	lp8788_irq_exit(lp);
	return 0;
}

