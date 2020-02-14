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
typedef  int u8 ;
typedef  int u16 ;
typedef  int /*<<< orphan*/  t ;
struct tps6524x {int* tx_buf; int len; int bits_per_word; int* rx_buf; int /*<<< orphan*/ * rdev; TYPE_2__* desc; int /*<<< orphan*/  lock; struct spi_device* spi; struct device* dev; } ;
struct field {int reg; int shift; int mask; } ;
struct supply_info {int n_voltages; int n_ilimsels; int* ilimsels; int /*<<< orphan*/  voltages; int /*<<< orphan*/  name; struct field enable; struct field ilimsel; struct field voltage; } ;
struct spi_transfer {int* tx_buf; int len; int bits_per_word; int* rx_buf; int /*<<< orphan*/ * rdev; TYPE_2__* desc; int /*<<< orphan*/  lock; struct spi_device* spi; struct device* dev; } ;
struct spi_message {int dummy; } ;
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct regulator_init_data {int dummy; } ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {struct tps6524x* driver_data; struct regulator_init_data* init_data; struct device* dev; } ;
struct TYPE_4__ {int id; int n_voltages; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; int /*<<< orphan*/ * ops; int /*<<< orphan*/  volt_table; int /*<<< orphan*/  name; } ;
struct TYPE_3__ {int n_voltages; } ;

/* Variables and functions */
 int CMD_READ (int) ; 
 int CMD_WRITE (int) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EOVERFLOW ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int N_REGULATORS ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int REG_WRITE_ENABLE ; 
 int STAT_CLK ; 
 int STAT_INVALID ; 
 int STAT_WP ; 
 int STAT_WRITE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct regulator_init_data* dev_get_platdata (struct device*) ; 
 struct tps6524x* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regulator_register (struct device*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  memset (struct tps6524x*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct tps6524x* rdev_get_drvdata (struct regulator_dev*) ; 
 size_t rdev_get_id (struct regulator_dev*) ; 
 int /*<<< orphan*/  regulator_ops ; 
 int /*<<< orphan*/  spi_message_add_tail (struct tps6524x*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct tps6524x*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 struct supply_info* supply_info ; 

__attribute__((used)) static int __read_reg(struct tps6524x *hw, int reg)
{
	int error = 0;
	u16 cmd = CMD_READ(reg), in;
	u8 status;
	struct spi_message m;
	struct spi_transfer t[3];

	spi_message_init(&m);
	memset(t, 0, sizeof(t));

	t[0].tx_buf = &cmd;
	t[0].len = 2;
	t[0].bits_per_word = 12;
	spi_message_add_tail(&t[0], &m);

	t[1].rx_buf = &in;
	t[1].len = 2;
	t[1].bits_per_word = 16;
	spi_message_add_tail(&t[1], &m);

	t[2].rx_buf = &status;
	t[2].len = 1;
	t[2].bits_per_word = 4;
	spi_message_add_tail(&t[2], &m);

	error = spi_sync(hw->spi, &m);
	if (error < 0)
		return error;

	dev_dbg(hw->dev, "read reg %d, data %x, status %x\n",
		reg, in, status);

	if (!(status & STAT_CLK) || (status & STAT_WRITE))
		return -EIO;

	if (status & STAT_INVALID)
		return -EINVAL;

	return in;
}

__attribute__((used)) static int read_reg(struct tps6524x *hw, int reg)
{
	int ret;

	mutex_lock(&hw->lock);
	ret = __read_reg(hw, reg);
	mutex_unlock(&hw->lock);

	return ret;
}

__attribute__((used)) static int __write_reg(struct tps6524x *hw, int reg, int val)
{
	int error = 0;
	u16 cmd = CMD_WRITE(reg), out = val;
	u8 status;
	struct spi_message m;
	struct spi_transfer t[3];

	spi_message_init(&m);
	memset(t, 0, sizeof(t));

	t[0].tx_buf = &cmd;
	t[0].len = 2;
	t[0].bits_per_word = 12;
	spi_message_add_tail(&t[0], &m);

	t[1].tx_buf = &out;
	t[1].len = 2;
	t[1].bits_per_word = 16;
	spi_message_add_tail(&t[1], &m);

	t[2].rx_buf = &status;
	t[2].len = 1;
	t[2].bits_per_word = 4;
	spi_message_add_tail(&t[2], &m);

	error = spi_sync(hw->spi, &m);
	if (error < 0)
		return error;

	dev_dbg(hw->dev, "wrote reg %d, data %x, status %x\n",
		reg, out, status);

	if (!(status & STAT_CLK) || !(status & STAT_WRITE))
		return -EIO;

	if (status & (STAT_INVALID | STAT_WP))
		return -EINVAL;

	return error;
}

__attribute__((used)) static int __rmw_reg(struct tps6524x *hw, int reg, int mask, int val)
{
	int ret;

	ret = __read_reg(hw, reg);
	if (ret < 0)
		return ret;

	ret &= ~mask;
	ret |= val;

	ret = __write_reg(hw, reg, ret);

	return (ret < 0) ? ret : 0;
}

__attribute__((used)) static int rmw_protect(struct tps6524x *hw, int reg, int mask, int val)
{
	int ret;

	mutex_lock(&hw->lock);

	ret = __write_reg(hw, REG_WRITE_ENABLE, 1);
	if (ret) {
		dev_err(hw->dev, "failed to set write enable\n");
		goto error;
	}

	ret = __rmw_reg(hw, reg, mask, val);
	if (ret)
		dev_err(hw->dev, "failed to rmw register %d\n", reg);

	ret = __write_reg(hw, REG_WRITE_ENABLE, 0);
	if (ret) {
		dev_err(hw->dev, "failed to clear write enable\n");
		goto error;
	}

error:
	mutex_unlock(&hw->lock);

	return ret;
}

__attribute__((used)) static int read_field(struct tps6524x *hw, const struct field *field)
{
	int tmp;

	tmp = read_reg(hw, field->reg);
	if (tmp < 0)
		return tmp;

	return (tmp >> field->shift) & field->mask;
}

__attribute__((used)) static int write_field(struct tps6524x *hw, const struct field *field,
		       int val)
{
	if (val & ~field->mask)
		return -EOVERFLOW;

	return rmw_protect(hw, field->reg,
				    field->mask << field->shift,
				    val << field->shift);
}

__attribute__((used)) static int set_voltage_sel(struct regulator_dev *rdev, unsigned selector)
{
	const struct supply_info *info;
	struct tps6524x *hw;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	if (rdev->desc->n_voltages == 1)
		return -EINVAL;

	return write_field(hw, &info->voltage, selector);
}

__attribute__((used)) static int get_voltage_sel(struct regulator_dev *rdev)
{
	const struct supply_info *info;
	struct tps6524x *hw;
	int ret;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	if (rdev->desc->n_voltages == 1)
		return 0;

	ret = read_field(hw, &info->voltage);
	if (ret < 0)
		return ret;
	if (WARN_ON(ret >= info->n_voltages))
		return -EIO;

	return ret;
}

__attribute__((used)) static int set_current_limit(struct regulator_dev *rdev, int min_uA,
			     int max_uA)
{
	const struct supply_info *info;
	struct tps6524x *hw;
	int i;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	if (info->n_ilimsels == 1)
		return -EINVAL;

	for (i = info->n_ilimsels - 1; i >= 0; i--) {
		if (min_uA <= info->ilimsels[i] &&
		    max_uA >= info->ilimsels[i])
			return write_field(hw, &info->ilimsel, i);
	}

	return -EINVAL;
}

__attribute__((used)) static int get_current_limit(struct regulator_dev *rdev)
{
	const struct supply_info *info;
	struct tps6524x *hw;
	int ret;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	if (info->n_ilimsels == 1)
		return info->ilimsels[0];

	ret = read_field(hw, &info->ilimsel);
	if (ret < 0)
		return ret;
	if (WARN_ON(ret >= info->n_ilimsels))
		return -EIO;

	return info->ilimsels[ret];
}

__attribute__((used)) static int enable_supply(struct regulator_dev *rdev)
{
	const struct supply_info *info;
	struct tps6524x *hw;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	return write_field(hw, &info->enable, 1);
}

__attribute__((used)) static int disable_supply(struct regulator_dev *rdev)
{
	const struct supply_info *info;
	struct tps6524x *hw;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	return write_field(hw, &info->enable, 0);
}

__attribute__((used)) static int is_supply_enabled(struct regulator_dev *rdev)
{
	const struct supply_info *info;
	struct tps6524x *hw;

	hw	= rdev_get_drvdata(rdev);
	info	= &supply_info[rdev_get_id(rdev)];

	return read_field(hw, &info->enable);
}

__attribute__((used)) static int pmic_probe(struct spi_device *spi)
{
	struct tps6524x *hw;
	struct device *dev = &spi->dev;
	const struct supply_info *info = supply_info;
	struct regulator_init_data *init_data;
	struct regulator_config config = { };
	int i;

	init_data = dev_get_platdata(dev);
	if (!init_data) {
		dev_err(dev, "could not find regulator platform data\n");
		return -EINVAL;
	}

	hw = devm_kzalloc(&spi->dev, sizeof(struct tps6524x), GFP_KERNEL);
	if (!hw)
		return -ENOMEM;

	spi_set_drvdata(spi, hw);

	memset(hw, 0, sizeof(struct tps6524x));
	hw->dev = dev;
	hw->spi = spi;
	mutex_init(&hw->lock);

	for (i = 0; i < N_REGULATORS; i++, info++, init_data++) {
		hw->desc[i].name	= info->name;
		hw->desc[i].id		= i;
		hw->desc[i].n_voltages	= info->n_voltages;
		hw->desc[i].volt_table	= info->voltages;
		hw->desc[i].ops		= &regulator_ops;
		hw->desc[i].type	= REGULATOR_VOLTAGE;
		hw->desc[i].owner	= THIS_MODULE;

		config.dev = dev;
		config.init_data = init_data;
		config.driver_data = hw;

		hw->rdev[i] = devm_regulator_register(dev, &hw->desc[i],
						      &config);
		if (IS_ERR(hw->rdev[i]))
			return PTR_ERR(hw->rdev[i]);
	}

	return 0;
}

