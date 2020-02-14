#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct regulator_init_data {int dummy; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {struct ad5398_chip_info* driver_data; struct regulator_init_data* init_data; int /*<<< orphan*/ * dev; } ;
struct i2c_device_id {int name; scalar_t__ driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct ad5398_current_data_format {int min_uA; int max_uA; int current_bits; unsigned int current_offset; } ;
struct ad5398_chip_info {unsigned int max_uA; unsigned int min_uA; unsigned int current_level; unsigned short current_mask; unsigned short current_offset; int /*<<< orphan*/  rdev; struct i2c_client* client; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 unsigned short AD5398_CURRENT_EN_MASK ; 
 unsigned int DIV_ROUND_UP (int,unsigned int) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_1__ ad5398_reg ; 
 unsigned short be16_to_cpu (unsigned short) ; 
 unsigned short cpu_to_be16 (unsigned short const) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct regulator_init_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct ad5398_chip_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regulator_register (int /*<<< orphan*/ *,TYPE_1__*,struct regulator_config*) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int i2c_master_send (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ad5398_chip_info*) ; 
 struct ad5398_chip_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int ad5398_calc_current(struct ad5398_chip_info *chip,
	unsigned selector)
{
	unsigned range_uA = chip->max_uA - chip->min_uA;

	return chip->min_uA + (selector * range_uA / chip->current_level);
}

__attribute__((used)) static int ad5398_read_reg(struct i2c_client *client, unsigned short *data)
{
	unsigned short val;
	int ret;

	ret = i2c_master_recv(client, (char *)&val, 2);
	if (ret < 0) {
		dev_err(&client->dev, "I2C read error\n");
		return ret;
	}
	*data = be16_to_cpu(val);

	return ret;
}

__attribute__((used)) static int ad5398_write_reg(struct i2c_client *client, const unsigned short data)
{
	unsigned short val;
	int ret;

	val = cpu_to_be16(data);
	ret = i2c_master_send(client, (char *)&val, 2);
	if (ret != 2) {
		dev_err(&client->dev, "I2C write error\n");
		return ret < 0 ? ret : -EIO;
	}

	return 0;
}

__attribute__((used)) static int ad5398_get_current_limit(struct regulator_dev *rdev)
{
	struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
	struct i2c_client *client = chip->client;
	unsigned short data;
	int ret;

	ret = ad5398_read_reg(client, &data);
	if (ret < 0)
		return ret;

	ret = (data & chip->current_mask) >> chip->current_offset;

	return ad5398_calc_current(chip, ret);
}

__attribute__((used)) static int ad5398_set_current_limit(struct regulator_dev *rdev, int min_uA, int max_uA)
{
	struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
	struct i2c_client *client = chip->client;
	unsigned range_uA = chip->max_uA - chip->min_uA;
	unsigned selector;
	unsigned short data;
	int ret;

	if (min_uA < chip->min_uA)
		min_uA = chip->min_uA;
	if (max_uA > chip->max_uA)
		max_uA = chip->max_uA;

	if (min_uA > chip->max_uA || max_uA < chip->min_uA)
		return -EINVAL;

	selector = DIV_ROUND_UP((min_uA - chip->min_uA) * chip->current_level,
				range_uA);
	if (ad5398_calc_current(chip, selector) > max_uA)
		return -EINVAL;

	dev_dbg(&client->dev, "changing current %duA\n",
		ad5398_calc_current(chip, selector));

	/* read chip enable bit */
	ret = ad5398_read_reg(client, &data);
	if (ret < 0)
		return ret;

	/* prepare register data */
	selector = (selector << chip->current_offset) & chip->current_mask;
	data = (unsigned short)selector | (data & AD5398_CURRENT_EN_MASK);

	/* write the new current value back as well as enable bit */
	ret = ad5398_write_reg(client, data);

	return ret;
}

__attribute__((used)) static int ad5398_is_enabled(struct regulator_dev *rdev)
{
	struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
	struct i2c_client *client = chip->client;
	unsigned short data;
	int ret;

	ret = ad5398_read_reg(client, &data);
	if (ret < 0)
		return ret;

	if (data & AD5398_CURRENT_EN_MASK)
		return 1;
	else
		return 0;
}

__attribute__((used)) static int ad5398_enable(struct regulator_dev *rdev)
{
	struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
	struct i2c_client *client = chip->client;
	unsigned short data;
	int ret;

	ret = ad5398_read_reg(client, &data);
	if (ret < 0)
		return ret;

	if (data & AD5398_CURRENT_EN_MASK)
		return 0;

	data |= AD5398_CURRENT_EN_MASK;

	ret = ad5398_write_reg(client, data);

	return ret;
}

__attribute__((used)) static int ad5398_disable(struct regulator_dev *rdev)
{
	struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
	struct i2c_client *client = chip->client;
	unsigned short data;
	int ret;

	ret = ad5398_read_reg(client, &data);
	if (ret < 0)
		return ret;

	if (!(data & AD5398_CURRENT_EN_MASK))
		return 0;

	data &= ~AD5398_CURRENT_EN_MASK;

	ret = ad5398_write_reg(client, data);

	return ret;
}

__attribute__((used)) static int ad5398_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct regulator_init_data *init_data = dev_get_platdata(&client->dev);
	struct regulator_config config = { };
	struct ad5398_chip_info *chip;
	const struct ad5398_current_data_format *df =
			(struct ad5398_current_data_format *)id->driver_data;

	if (!init_data)
		return -EINVAL;

	chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	config.dev = &client->dev;
	config.init_data = init_data;
	config.driver_data = chip;

	chip->client = client;

	chip->min_uA = df->min_uA;
	chip->max_uA = df->max_uA;
	chip->current_level = 1 << df->current_bits;
	chip->current_offset = df->current_offset;
	chip->current_mask = (chip->current_level - 1) << chip->current_offset;

	chip->rdev = devm_regulator_register(&client->dev, &ad5398_reg,
					     &config);
	if (IS_ERR(chip->rdev)) {
		dev_err(&client->dev, "failed to register %s %s\n",
			id->name, ad5398_reg.name);
		return PTR_ERR(chip->rdev);
	}

	i2c_set_clientdata(client, chip);
	dev_dbg(&client->dev, "%s regulator driver is registered.\n", id->name);
	return 0;
}

