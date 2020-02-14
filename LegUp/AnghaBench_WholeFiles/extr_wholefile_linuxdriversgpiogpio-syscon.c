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
typedef  unsigned int u32 ;
struct TYPE_4__ {int base; int (* get ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int /*<<< orphan*/  ngpio; int /*<<< orphan*/  label; int /*<<< orphan*/  owner; struct device* parent; } ;
struct syscon_gpio_priv {unsigned int dreg_offset; unsigned int dir_reg_offset; TYPE_2__ chip; TYPE_1__* data; int /*<<< orphan*/  syscon; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;
struct device_node {scalar_t__ parent; } ;
struct TYPE_3__ {unsigned int dat_bit_offset; int flags; unsigned int dir_bit_offset; int /*<<< orphan*/  (* set ) (struct gpio_chip*,unsigned int,int) ;int /*<<< orphan*/  bit_count; scalar_t__ compatible; } ;

/* Variables and functions */
 unsigned int BIT (unsigned int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO_SYSCON_FEAT_DIR ; 
 int GPIO_SYSCON_FEAT_IN ; 
 int GPIO_SYSCON_FEAT_OUT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned int KEYSTONE_LOCK_BIT ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned int SYSCON_REG_BITS ; 
 unsigned int SYSCON_REG_SIZE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int devm_gpiochip_add_data (struct device*,TYPE_2__*,struct syscon_gpio_priv*) ; 
 struct syscon_gpio_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct syscon_gpio_priv* gpiochip_get_data (struct gpio_chip*) ; 
 TYPE_1__* of_device_get_match_data (struct device*) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,unsigned int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct syscon_gpio_priv*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  stub1 (struct gpio_chip*,unsigned int,int) ; 
 int /*<<< orphan*/  syscon_node_to_regmap (scalar_t__) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_compatible (scalar_t__) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static int syscon_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int val, offs;
	int ret;

	offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;

	ret = regmap_read(priv->syscon,
			  (offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE, &val);
	if (ret)
		return ret;

	return !!(val & BIT(offs % SYSCON_REG_BITS));
}

__attribute__((used)) static void syscon_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int offs;

	offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;

	regmap_update_bits(priv->syscon,
			   (offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
			   BIT(offs % SYSCON_REG_BITS),
			   val ? BIT(offs % SYSCON_REG_BITS) : 0);
}

__attribute__((used)) static int syscon_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);

	if (priv->data->flags & GPIO_SYSCON_FEAT_DIR) {
		unsigned int offs;

		offs = priv->dir_reg_offset +
		       priv->data->dir_bit_offset + offset;

		regmap_update_bits(priv->syscon,
				   (offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
				   BIT(offs % SYSCON_REG_BITS), 0);
	}

	return 0;
}

__attribute__((used)) static int syscon_gpio_dir_out(struct gpio_chip *chip, unsigned offset, int val)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);

	if (priv->data->flags & GPIO_SYSCON_FEAT_DIR) {
		unsigned int offs;

		offs = priv->dir_reg_offset +
		       priv->data->dir_bit_offset + offset;

		regmap_update_bits(priv->syscon,
				   (offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
				   BIT(offs % SYSCON_REG_BITS),
				   BIT(offs % SYSCON_REG_BITS));
	}

	priv->data->set(chip, offset, val);

	return 0;
}

__attribute__((used)) static void rockchip_gpio_set(struct gpio_chip *chip, unsigned int offset,
			      int val)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int offs;
	u8 bit;
	u32 data;
	int ret;

	offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;
	bit = offs % SYSCON_REG_BITS;
	data = (val ? BIT(bit) : 0) | BIT(bit + 16);
	ret = regmap_write(priv->syscon,
			   (offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
			   data);
	if (ret < 0)
		dev_err(chip->parent, "gpio write failed ret(%d)\n", ret);
}

__attribute__((used)) static void keystone_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
	struct syscon_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int offs;
	int ret;

	offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;

	if (!val)
		return;

	ret = regmap_update_bits(
			priv->syscon,
			(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
			BIT(offs % SYSCON_REG_BITS) | KEYSTONE_LOCK_BIT,
			BIT(offs % SYSCON_REG_BITS) | KEYSTONE_LOCK_BIT);
	if (ret < 0)
		dev_err(chip->parent, "gpio write failed ret(%d)\n", ret);
}

__attribute__((used)) static int syscon_gpio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct syscon_gpio_priv *priv;
	struct device_node *np = dev->of_node;
	int ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->data = of_device_get_match_data(dev);

	if (priv->data->compatible) {
		priv->syscon = syscon_regmap_lookup_by_compatible(
					priv->data->compatible);
		if (IS_ERR(priv->syscon))
			return PTR_ERR(priv->syscon);
	} else {
		priv->syscon =
			syscon_regmap_lookup_by_phandle(np, "gpio,syscon-dev");
		if (IS_ERR(priv->syscon) && np->parent)
			priv->syscon = syscon_node_to_regmap(np->parent);
		if (IS_ERR(priv->syscon))
			return PTR_ERR(priv->syscon);

		ret = of_property_read_u32_index(np, "gpio,syscon-dev", 1,
						 &priv->dreg_offset);
		if (ret)
			dev_err(dev, "can't read the data register offset!\n");

		priv->dreg_offset <<= 3;

		ret = of_property_read_u32_index(np, "gpio,syscon-dev", 2,
						 &priv->dir_reg_offset);
		if (ret)
			dev_dbg(dev, "can't read the dir register offset!\n");

		priv->dir_reg_offset <<= 3;
	}

	priv->chip.parent = dev;
	priv->chip.owner = THIS_MODULE;
	priv->chip.label = dev_name(dev);
	priv->chip.base = -1;
	priv->chip.ngpio = priv->data->bit_count;
	priv->chip.get = syscon_gpio_get;
	if (priv->data->flags & GPIO_SYSCON_FEAT_IN)
		priv->chip.direction_input = syscon_gpio_dir_in;
	if (priv->data->flags & GPIO_SYSCON_FEAT_OUT) {
		priv->chip.set = priv->data->set ? : syscon_gpio_set;
		priv->chip.direction_output = syscon_gpio_dir_out;
	}

	platform_set_drvdata(pdev, priv);

	return devm_gpiochip_add_data(&pdev->dev, &priv->chip, priv);
}

