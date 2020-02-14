#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_12__ {TYPE_3__** attrs; } ;
struct mlxreg_io_priv_data {int /*<<< orphan*/  hwmon; TYPE_6__** groups; struct platform_device* pdev; TYPE_7__* pdata; TYPE_6__ group; TYPE_3__** mlxreg_io_attr; TYPE_1__* mlxreg_io_dev_attr; } ;
struct mlxreg_core_data {int mask; int /*<<< orphan*/  mode; int /*<<< orphan*/  label; int /*<<< orphan*/  reg; scalar_t__ bit; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_13__ {int counter; struct mlxreg_core_data* data; void* regmap; } ;
struct TYPE_10__ {scalar_t__ name; int /*<<< orphan*/  mode; } ;
struct TYPE_11__ {TYPE_3__ attr; } ;
struct TYPE_9__ {int index; } ;
struct TYPE_8__ {int index; TYPE_4__ dev_attr; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 size_t MLXREG_IO_ATT_SIZE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct mlxreg_io_priv_data* dev_get_drvdata (struct device*) ; 
 TYPE_7__* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct mlxreg_io_priv_data*) ; 
 int /*<<< orphan*/  devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,char*,struct mlxreg_io_priv_data*,TYPE_6__**) ; 
 scalar_t__ devm_kasprintf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__** devm_kcalloc (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 struct mlxreg_io_priv_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int kstrtou32 (char const*,size_t,int*) ; 
 int /*<<< orphan*/  memcpy (TYPE_4__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mlxreg_io_devattr_rw ; 
 int regmap_read (void*,int /*<<< orphan*/ ,int*) ; 
 int regmap_write (void*,int /*<<< orphan*/ ,int) ; 
 int rol32 (int,scalar_t__) ; 
 int ror32 (int,scalar_t__) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  sysfs_attr_init (TYPE_3__*) ; 
 TYPE_2__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int
mlxreg_io_get_reg(void *regmap, struct mlxreg_core_data *data, u32 in_val,
		  bool rw_flag, u32 *regval)
{
	int ret;

	ret = regmap_read(regmap, data->reg, regval);
	if (ret)
		goto access_error;

	/*
	 * There are three kinds of attributes: single bit, full register's
	 * bits and bit sequence. For the first kind field mask indicates which
	 * bits are not related and field bit is set zero. For the second kind
	 * field mask is set to zero and field bit is set with all bits one.
	 * No special handling for such kind of attributes - pass value as is.
	 * For the third kind, field mask indicates which bits are related and
	 * field bit is set to the first bit number (from 1 to 32) is the bit
	 * sequence.
	 */
	if (!data->bit) {
		/* Single bit. */
		if (rw_flag) {
			/* For show: expose effective bit value as 0 or 1. */
			*regval = !!(*regval & ~data->mask);
		} else {
			/* For store: set effective bit value. */
			*regval &= data->mask;
			if (in_val)
				*regval |= ~data->mask;
		}
	} else if (data->mask) {
		/* Bit sequence. */
		if (rw_flag) {
			/* For show: mask and shift right. */
			*regval = ror32(*regval & data->mask, (data->bit - 1));
		} else {
			/* For store: shift to the position and mask. */
			in_val = rol32(in_val, data->bit - 1) & data->mask;
			/* Clear relevant bits and set them to new value. */
			*regval = (*regval & ~data->mask) | in_val;
		}
	}

access_error:
	return ret;
}

__attribute__((used)) static ssize_t
mlxreg_io_attr_show(struct device *dev, struct device_attribute *attr,
		    char *buf)
{
	struct mlxreg_io_priv_data *priv = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	struct mlxreg_core_data *data = priv->pdata->data + index;
	u32 regval = 0;
	int ret;

	ret = mlxreg_io_get_reg(priv->pdata->regmap, data, 0, true, &regval);
	if (ret)
		goto access_error;

	return sprintf(buf, "%u\n", regval);

access_error:
	return ret;
}

__attribute__((used)) static ssize_t
mlxreg_io_attr_store(struct device *dev, struct device_attribute *attr,
		     const char *buf, size_t len)
{
	struct mlxreg_io_priv_data *priv = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	struct mlxreg_core_data *data = priv->pdata->data + index;
	u32 input_val, regval;
	int ret;

	if (len > MLXREG_IO_ATT_SIZE)
		return -EINVAL;

	/* Convert buffer to input value. */
	ret = kstrtou32(buf, len, &input_val);
	if (ret)
		return ret;

	ret = mlxreg_io_get_reg(priv->pdata->regmap, data, input_val, false,
				&regval);
	if (ret)
		goto access_error;

	ret = regmap_write(priv->pdata->regmap, data->reg, regval);
	if (ret)
		goto access_error;

	return len;

access_error:
	dev_err(&priv->pdev->dev, "Bus access error\n");
	return ret;
}

__attribute__((used)) static int mlxreg_io_attr_init(struct mlxreg_io_priv_data *priv)
{
	int i;

	priv->group.attrs = devm_kcalloc(&priv->pdev->dev,
					 priv->pdata->counter,
					 sizeof(struct attribute *),
					 GFP_KERNEL);
	if (!priv->group.attrs)
		return -ENOMEM;

	for (i = 0; i < priv->pdata->counter; i++) {
		priv->mlxreg_io_attr[i] =
				&priv->mlxreg_io_dev_attr[i].dev_attr.attr;
		memcpy(&priv->mlxreg_io_dev_attr[i].dev_attr,
		       &mlxreg_io_devattr_rw, sizeof(struct device_attribute));

		/* Set attribute name as a label. */
		priv->mlxreg_io_attr[i]->name =
				devm_kasprintf(&priv->pdev->dev, GFP_KERNEL,
					       priv->pdata->data[i].label);

		if (!priv->mlxreg_io_attr[i]->name) {
			dev_err(&priv->pdev->dev, "Memory allocation failed for sysfs attribute %d.\n",
				i + 1);
			return -ENOMEM;
		}

		priv->mlxreg_io_dev_attr[i].dev_attr.attr.mode =
						priv->pdata->data[i].mode;
		priv->mlxreg_io_dev_attr[i].dev_attr.attr.name =
					priv->mlxreg_io_attr[i]->name;
		priv->mlxreg_io_dev_attr[i].index = i;
		sysfs_attr_init(&priv->mlxreg_io_dev_attr[i].dev_attr.attr);
	}

	priv->group.attrs = priv->mlxreg_io_attr;
	priv->groups[0] = &priv->group;
	priv->groups[1] = NULL;

	return 0;
}

__attribute__((used)) static int mlxreg_io_probe(struct platform_device *pdev)
{
	struct mlxreg_io_priv_data *priv;
	int err;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->pdata = dev_get_platdata(&pdev->dev);
	if (!priv->pdata) {
		dev_err(&pdev->dev, "Failed to get platform data.\n");
		return -EINVAL;
	}

	priv->pdev = pdev;

	err = mlxreg_io_attr_init(priv);
	if (err) {
		dev_err(&priv->pdev->dev, "Failed to allocate attributes: %d\n",
			err);
		return err;
	}

	priv->hwmon = devm_hwmon_device_register_with_groups(&pdev->dev,
							     "mlxreg_io",
							      priv,
							      priv->groups);
	if (IS_ERR(priv->hwmon)) {
		dev_err(&pdev->dev, "Failed to register hwmon device %ld\n",
			PTR_ERR(priv->hwmon));
		return PTR_ERR(priv->hwmon);
	}

	dev_set_drvdata(&pdev->dev, priv);

	return 0;
}

