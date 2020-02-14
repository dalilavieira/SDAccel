#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u8 ;
struct tps65217 {unsigned int irq_mask; int irq; int /*<<< orphan*/ * irq_domain; TYPE_2__* dev; int /*<<< orphan*/  regmap; int /*<<< orphan*/  irq_lock; } ;
struct irq_domain {struct tps65217* host_data; } ;
struct irq_data {int hwirq; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {int irq; TYPE_2__ dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
struct TYPE_10__ {scalar_t__ num_resources; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 unsigned int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned int TPS65217_CHIPID_CHIP_MASK ; 
 unsigned int TPS65217_CHIPID_REV_MASK ; 
 unsigned int TPS65217_INT_MASK ; 
 unsigned int TPS65217_INT_SHIFT ; 
 int TPS65217_NUM_IRQ ; 
 unsigned int TPS65217_PASSWORD_REGS_UNLOCK ; 
#define  TPS65217_PROTECT_L1 131 
#define  TPS65217_PROTECT_L2 130 
#define  TPS65217_PROTECT_NONE 129 
 unsigned int TPS65217_REG_CHIPID ; 
#define  TPS65217_REG_INT 128 
 unsigned int TPS65217_REG_PASSWORD ; 
 unsigned int TPS65217_REG_STATUS ; 
 unsigned int TPS65217_STATUS_OFF ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 struct tps65217* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (TYPE_2__*,int,TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (TYPE_2__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct tps65217*) ; 
 int /*<<< orphan*/  enable_irq_wake (int) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_nested_irq (unsigned int) ; 
 struct tps65217* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tps65217*) ; 
 struct tps65217* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  irq_dispose_mapping (unsigned int) ; 
 int /*<<< orphan*/ * irq_domain_add_linear (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,struct tps65217*) ; 
 int /*<<< orphan*/  irq_domain_remove (int /*<<< orphan*/ *) ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct tps65217*) ; 
 int /*<<< orphan*/  irq_set_nested_thread (unsigned int,int) ; 
 int /*<<< orphan*/  irq_set_noprobe (unsigned int) ; 
 int /*<<< orphan*/  irq_set_parent (unsigned int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  tps65217_irq_chip ; 
 int /*<<< orphan*/  tps65217_irq_domain_ops ; 
 int tps65217_reg_read (struct tps65217*,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  tps65217_regmap_config ; 
 int tps65217_set_bits (struct tps65217*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 TYPE_1__* tps65217s ; 

__attribute__((used)) static void tps65217_irq_lock(struct irq_data *data)
{
	struct tps65217 *tps = irq_data_get_irq_chip_data(data);

	mutex_lock(&tps->irq_lock);
}

__attribute__((used)) static void tps65217_irq_sync_unlock(struct irq_data *data)
{
	struct tps65217 *tps = irq_data_get_irq_chip_data(data);
	int ret;

	ret = tps65217_set_bits(tps, TPS65217_REG_INT, TPS65217_INT_MASK,
				tps->irq_mask, TPS65217_PROTECT_NONE);
	if (ret != 0)
		dev_err(tps->dev, "Failed to sync IRQ masks\n");

	mutex_unlock(&tps->irq_lock);
}

__attribute__((used)) static void tps65217_irq_enable(struct irq_data *data)
{
	struct tps65217 *tps = irq_data_get_irq_chip_data(data);
	u8 mask = BIT(data->hwirq) << TPS65217_INT_SHIFT;

	tps->irq_mask &= ~mask;
}

__attribute__((used)) static void tps65217_irq_disable(struct irq_data *data)
{
	struct tps65217 *tps = irq_data_get_irq_chip_data(data);
	u8 mask = BIT(data->hwirq) << TPS65217_INT_SHIFT;

	tps->irq_mask |= mask;
}

__attribute__((used)) static irqreturn_t tps65217_irq_thread(int irq, void *data)
{
	struct tps65217 *tps = data;
	unsigned int status;
	bool handled = false;
	int i;
	int ret;

	ret = tps65217_reg_read(tps, TPS65217_REG_INT, &status);
	if (ret < 0) {
		dev_err(tps->dev, "Failed to read IRQ status: %d\n",
			ret);
		return IRQ_NONE;
	}

	for (i = 0; i < TPS65217_NUM_IRQ; i++) {
		if (status & BIT(i)) {
			handle_nested_irq(irq_find_mapping(tps->irq_domain, i));
			handled = true;
		}
	}

	if (handled)
		return IRQ_HANDLED;

	return IRQ_NONE;
}

__attribute__((used)) static int tps65217_irq_map(struct irq_domain *h, unsigned int virq,
			irq_hw_number_t hw)
{
	struct tps65217 *tps = h->host_data;

	irq_set_chip_data(virq, tps);
	irq_set_chip_and_handler(virq, &tps65217_irq_chip, handle_edge_irq);
	irq_set_nested_thread(virq, 1);
	irq_set_parent(virq, tps->irq);
	irq_set_noprobe(virq);

	return 0;
}

__attribute__((used)) static int tps65217_irq_init(struct tps65217 *tps, int irq)
{
	int ret;

	mutex_init(&tps->irq_lock);
	tps->irq = irq;

	/* Mask all interrupt sources */
	tps->irq_mask = TPS65217_INT_MASK;
	tps65217_set_bits(tps, TPS65217_REG_INT, TPS65217_INT_MASK,
			  TPS65217_INT_MASK, TPS65217_PROTECT_NONE);

	tps->irq_domain = irq_domain_add_linear(tps->dev->of_node,
		TPS65217_NUM_IRQ, &tps65217_irq_domain_ops, tps);
	if (!tps->irq_domain) {
		dev_err(tps->dev, "Could not create IRQ domain\n");
		return -ENOMEM;
	}

	ret = devm_request_threaded_irq(tps->dev, irq, NULL,
					tps65217_irq_thread, IRQF_ONESHOT,
					"tps65217-irq", tps);
	if (ret) {
		dev_err(tps->dev, "Failed to request IRQ %d: %d\n",
			irq, ret);
		return ret;
	}

	enable_irq_wake(irq);

	return 0;
}

int tps65217_reg_read(struct tps65217 *tps, unsigned int reg,
			unsigned int *val)
{
	return regmap_read(tps->regmap, reg, val);
}

int tps65217_reg_write(struct tps65217 *tps, unsigned int reg,
			unsigned int val, unsigned int level)
{
	int ret;
	unsigned int xor_reg_val;

	switch (level) {
	case TPS65217_PROTECT_NONE:
		return regmap_write(tps->regmap, reg, val);
	case TPS65217_PROTECT_L1:
		xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
		ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
							xor_reg_val);
		if (ret < 0)
			return ret;

		return regmap_write(tps->regmap, reg, val);
	case TPS65217_PROTECT_L2:
		xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
		ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
							xor_reg_val);
		if (ret < 0)
			return ret;
		ret = regmap_write(tps->regmap, reg, val);
		if (ret < 0)
			return ret;
		ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
							xor_reg_val);
		if (ret < 0)
			return ret;
		return regmap_write(tps->regmap, reg, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tps65217_update_bits(struct tps65217 *tps, unsigned int reg,
		unsigned int mask, unsigned int val, unsigned int level)
{
	int ret;
	unsigned int data;

	ret = tps65217_reg_read(tps, reg, &data);
	if (ret) {
		dev_err(tps->dev, "Read from reg 0x%x failed\n", reg);
		return ret;
	}

	data &= ~mask;
	data |= val & mask;

	ret = tps65217_reg_write(tps, reg, data, level);
	if (ret)
		dev_err(tps->dev, "Write for reg 0x%x failed\n", reg);

	return ret;
}

int tps65217_set_bits(struct tps65217 *tps, unsigned int reg,
		unsigned int mask, unsigned int val, unsigned int level)
{
	return tps65217_update_bits(tps, reg, mask, val, level);
}

int tps65217_clear_bits(struct tps65217 *tps, unsigned int reg,
		unsigned int mask, unsigned int level)
{
	return tps65217_update_bits(tps, reg, mask, 0, level);
}

__attribute__((used)) static bool tps65217_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case TPS65217_REG_INT:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int tps65217_probe(struct i2c_client *client)
{
	struct tps65217 *tps;
	unsigned int version;
	bool status_off = false;
	int ret;

	status_off = of_property_read_bool(client->dev.of_node,
					   "ti,pmic-shutdown-controller");

	tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
	if (!tps)
		return -ENOMEM;

	i2c_set_clientdata(client, tps);
	tps->dev = &client->dev;

	tps->regmap = devm_regmap_init_i2c(client, &tps65217_regmap_config);
	if (IS_ERR(tps->regmap)) {
		ret = PTR_ERR(tps->regmap);
		dev_err(tps->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	if (client->irq) {
		tps65217_irq_init(tps, client->irq);
	} else {
		int i;

		/* Don't tell children about IRQ resources which won't fire */
		for (i = 0; i < ARRAY_SIZE(tps65217s); i++)
			tps65217s[i].num_resources = 0;
	}

	ret = devm_mfd_add_devices(tps->dev, -1, tps65217s,
				   ARRAY_SIZE(tps65217s), NULL, 0,
				   tps->irq_domain);
	if (ret < 0) {
		dev_err(tps->dev, "mfd_add_devices failed: %d\n", ret);
		return ret;
	}

	ret = tps65217_reg_read(tps, TPS65217_REG_CHIPID, &version);
	if (ret < 0) {
		dev_err(tps->dev, "Failed to read revision register: %d\n",
			ret);
		return ret;
	}

	/* Set the PMIC to shutdown on PWR_EN toggle */
	if (status_off) {
		ret = tps65217_set_bits(tps, TPS65217_REG_STATUS,
				TPS65217_STATUS_OFF, TPS65217_STATUS_OFF,
				TPS65217_PROTECT_NONE);
		if (ret)
			dev_warn(tps->dev, "unable to set the status OFF\n");
	}

	dev_info(tps->dev, "TPS65217 ID %#x version 1.%d\n",
			(version & TPS65217_CHIPID_CHIP_MASK) >> 4,
			version & TPS65217_CHIPID_REV_MASK);

	return 0;
}

__attribute__((used)) static int tps65217_remove(struct i2c_client *client)
{
	struct tps65217 *tps = i2c_get_clientdata(client);
	unsigned int virq;
	int i;

	for (i = 0; i < TPS65217_NUM_IRQ; i++) {
		virq = irq_find_mapping(tps->irq_domain, i);
		if (virq)
			irq_dispose_mapping(virq);
	}

	irq_domain_remove(tps->irq_domain);
	tps->irq_domain = NULL;

	return 0;
}

