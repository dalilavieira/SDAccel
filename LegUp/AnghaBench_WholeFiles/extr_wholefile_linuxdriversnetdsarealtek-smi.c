#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct realtek_smi_variant {scalar_t__ cmd_read; scalar_t__ cmd_write; int /*<<< orphan*/  ds_ops; TYPE_1__* ops; int /*<<< orphan*/  clk_delay; } ;
struct realtek_smi {scalar_t__ cmd_read; scalar_t__ cmd_write; void* reset; TYPE_3__* slave_mii_bus; TYPE_4__* ds; int /*<<< orphan*/  num_ports; TYPE_1__* ops; int /*<<< orphan*/  leds_disabled; void* mdio; void* mdc; int /*<<< orphan*/  lock; int /*<<< orphan*/  clk_delay; struct device* dev; void* map; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct mii_bus {struct realtek_smi* priv; } ;
struct device_node {int dummy; } ;
struct TYPE_11__ {int index; int /*<<< orphan*/  ops; struct realtek_smi* priv; TYPE_3__* slave_mii_bus; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct TYPE_10__ {char* name; int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int /*<<< orphan*/ ) ;int id; TYPE_2__ dev; struct device* parent; struct realtek_smi* priv; } ;
struct TYPE_8__ {int (* phy_read ) (struct realtek_smi*,int,int) ;int (* phy_write ) (struct realtek_smi*,int,int,int /*<<< orphan*/ ) ;int (* detect ) (struct realtek_smi*) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 int PTR_ERR (void*) ; 
 int REALTEK_SMI_ACK_RETRY_COUNT ; 
 int /*<<< orphan*/  REALTEK_SMI_HW_START_DELAY ; 
 int /*<<< orphan*/  REALTEK_SMI_HW_STOP_DELAY ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct realtek_smi* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct realtek_smi*) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct realtek_smi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 TYPE_3__* devm_mdiobus_alloc (struct device*) ; 
 void* devm_regmap_init (struct device*,int /*<<< orphan*/ *,struct realtek_smi*,int /*<<< orphan*/ *) ; 
 int dsa_register_switch (TYPE_4__*) ; 
 TYPE_4__* dsa_switch_alloc (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dsa_unregister_switch (TYPE_4__*) ; 
 int /*<<< orphan*/  gpiod_direction_input (void*) ; 
 int /*<<< orphan*/  gpiod_direction_output (void*,int) ; 
 int /*<<< orphan*/  gpiod_get_value (void*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ndelay (int /*<<< orphan*/ ) ; 
 struct realtek_smi_variant* of_device_get_match_data (struct device*) ; 
 struct device_node* of_get_compatible_child (struct device_node*,char*) ; 
 int of_mdiobus_register (TYPE_3__*,struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_property_read_bool (struct device_node*,char*) ; 
 int /*<<< orphan*/  realtek_smi_mdio_regmap_config ; 
 int /*<<< orphan*/  snprintf (int,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct realtek_smi*,int,int) ; 
 int stub2 (struct realtek_smi*,int,int,int /*<<< orphan*/ ) ; 
 int stub3 (struct realtek_smi*) ; 

__attribute__((used)) static inline void realtek_smi_clk_delay(struct realtek_smi *smi)
{
	ndelay(smi->clk_delay);
}

__attribute__((used)) static void realtek_smi_start(struct realtek_smi *smi)
{
	/* Set GPIO pins to output mode, with initial state:
	 * SCK = 0, SDA = 1
	 */
	gpiod_direction_output(smi->mdc, 0);
	gpiod_direction_output(smi->mdio, 1);
	realtek_smi_clk_delay(smi);

	/* CLK 1: 0 -> 1, 1 -> 0 */
	gpiod_set_value(smi->mdc, 1);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 0);
	realtek_smi_clk_delay(smi);

	/* CLK 2: */
	gpiod_set_value(smi->mdc, 1);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdio, 0);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 0);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdio, 1);
}

__attribute__((used)) static void realtek_smi_stop(struct realtek_smi *smi)
{
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdio, 0);
	gpiod_set_value(smi->mdc, 1);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdio, 1);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 1);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 0);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 1);

	/* Add a click */
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 0);
	realtek_smi_clk_delay(smi);
	gpiod_set_value(smi->mdc, 1);

	/* Set GPIO pins to input mode */
	gpiod_direction_input(smi->mdio);
	gpiod_direction_input(smi->mdc);
}

__attribute__((used)) static void realtek_smi_write_bits(struct realtek_smi *smi, u32 data, u32 len)
{
	for (; len > 0; len--) {
		realtek_smi_clk_delay(smi);

		/* Prepare data */
		gpiod_set_value(smi->mdio, !!(data & (1 << (len - 1))));
		realtek_smi_clk_delay(smi);

		/* Clocking */
		gpiod_set_value(smi->mdc, 1);
		realtek_smi_clk_delay(smi);
		gpiod_set_value(smi->mdc, 0);
	}
}

__attribute__((used)) static void realtek_smi_read_bits(struct realtek_smi *smi, u32 len, u32 *data)
{
	gpiod_direction_input(smi->mdio);

	for (*data = 0; len > 0; len--) {
		u32 u;

		realtek_smi_clk_delay(smi);

		/* Clocking */
		gpiod_set_value(smi->mdc, 1);
		realtek_smi_clk_delay(smi);
		u = !!gpiod_get_value(smi->mdio);
		gpiod_set_value(smi->mdc, 0);

		*data |= (u << (len - 1));
	}

	gpiod_direction_output(smi->mdio, 0);
}

__attribute__((used)) static int realtek_smi_wait_for_ack(struct realtek_smi *smi)
{
	int retry_cnt;

	retry_cnt = 0;
	do {
		u32 ack;

		realtek_smi_read_bits(smi, 1, &ack);
		if (ack == 0)
			break;

		if (++retry_cnt > REALTEK_SMI_ACK_RETRY_COUNT) {
			dev_err(smi->dev, "ACK timeout\n");
			return -ETIMEDOUT;
		}
	} while (1);

	return 0;
}

__attribute__((used)) static int realtek_smi_write_byte(struct realtek_smi *smi, u8 data)
{
	realtek_smi_write_bits(smi, data, 8);
	return realtek_smi_wait_for_ack(smi);
}

__attribute__((used)) static int realtek_smi_write_byte_noack(struct realtek_smi *smi, u8 data)
{
	realtek_smi_write_bits(smi, data, 8);
	return 0;
}

__attribute__((used)) static int realtek_smi_read_byte0(struct realtek_smi *smi, u8 *data)
{
	u32 t;

	/* Read data */
	realtek_smi_read_bits(smi, 8, &t);
	*data = (t & 0xff);

	/* Send an ACK */
	realtek_smi_write_bits(smi, 0x00, 1);

	return 0;
}

__attribute__((used)) static int realtek_smi_read_byte1(struct realtek_smi *smi, u8 *data)
{
	u32 t;

	/* Read data */
	realtek_smi_read_bits(smi, 8, &t);
	*data = (t & 0xff);

	/* Send an ACK */
	realtek_smi_write_bits(smi, 0x01, 1);

	return 0;
}

__attribute__((used)) static int realtek_smi_read_reg(struct realtek_smi *smi, u32 addr, u32 *data)
{
	unsigned long flags;
	u8 lo = 0;
	u8 hi = 0;
	int ret;

	spin_lock_irqsave(&smi->lock, flags);

	realtek_smi_start(smi);

	/* Send READ command */
	ret = realtek_smi_write_byte(smi, smi->cmd_read);
	if (ret)
		goto out;

	/* Set ADDR[7:0] */
	ret = realtek_smi_write_byte(smi, addr & 0xff);
	if (ret)
		goto out;

	/* Set ADDR[15:8] */
	ret = realtek_smi_write_byte(smi, addr >> 8);
	if (ret)
		goto out;

	/* Read DATA[7:0] */
	realtek_smi_read_byte0(smi, &lo);
	/* Read DATA[15:8] */
	realtek_smi_read_byte1(smi, &hi);

	*data = ((u32)lo) | (((u32)hi) << 8);

	ret = 0;

 out:
	realtek_smi_stop(smi);
	spin_unlock_irqrestore(&smi->lock, flags);

	return ret;
}

__attribute__((used)) static int realtek_smi_write_reg(struct realtek_smi *smi,
				 u32 addr, u32 data, bool ack)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&smi->lock, flags);

	realtek_smi_start(smi);

	/* Send WRITE command */
	ret = realtek_smi_write_byte(smi, smi->cmd_write);
	if (ret)
		goto out;

	/* Set ADDR[7:0] */
	ret = realtek_smi_write_byte(smi, addr & 0xff);
	if (ret)
		goto out;

	/* Set ADDR[15:8] */
	ret = realtek_smi_write_byte(smi, addr >> 8);
	if (ret)
		goto out;

	/* Write DATA[7:0] */
	ret = realtek_smi_write_byte(smi, data & 0xff);
	if (ret)
		goto out;

	/* Write DATA[15:8] */
	if (ack)
		ret = realtek_smi_write_byte(smi, data >> 8);
	else
		ret = realtek_smi_write_byte_noack(smi, data >> 8);
	if (ret)
		goto out;

	ret = 0;

 out:
	realtek_smi_stop(smi);
	spin_unlock_irqrestore(&smi->lock, flags);

	return ret;
}

int realtek_smi_write_reg_noack(struct realtek_smi *smi, u32 addr,
				u32 data)
{
	return realtek_smi_write_reg(smi, addr, data, false);
}

__attribute__((used)) static int realtek_smi_write(void *ctx, u32 reg, u32 val)
{
	struct realtek_smi *smi = ctx;

	return realtek_smi_write_reg(smi, reg, val, true);
}

__attribute__((used)) static int realtek_smi_read(void *ctx, u32 reg, u32 *val)
{
	struct realtek_smi *smi = ctx;

	return realtek_smi_read_reg(smi, reg, val);
}

__attribute__((used)) static int realtek_smi_mdio_read(struct mii_bus *bus, int addr, int regnum)
{
	struct realtek_smi *smi = bus->priv;

	return smi->ops->phy_read(smi, addr, regnum);
}

__attribute__((used)) static int realtek_smi_mdio_write(struct mii_bus *bus, int addr, int regnum,
				  u16 val)
{
	struct realtek_smi *smi = bus->priv;

	return smi->ops->phy_write(smi, addr, regnum, val);
}

int realtek_smi_setup_mdio(struct realtek_smi *smi)
{
	struct device_node *mdio_np;
	int ret;

	mdio_np = of_get_compatible_child(smi->dev->of_node, "realtek,smi-mdio");
	if (!mdio_np) {
		dev_err(smi->dev, "no MDIO bus node\n");
		return -ENODEV;
	}

	smi->slave_mii_bus = devm_mdiobus_alloc(smi->dev);
	if (!smi->slave_mii_bus) {
		ret = -ENOMEM;
		goto err_put_node;
	}
	smi->slave_mii_bus->priv = smi;
	smi->slave_mii_bus->name = "SMI slave MII";
	smi->slave_mii_bus->read = realtek_smi_mdio_read;
	smi->slave_mii_bus->write = realtek_smi_mdio_write;
	snprintf(smi->slave_mii_bus->id, MII_BUS_ID_SIZE, "SMI-%d",
		 smi->ds->index);
	smi->slave_mii_bus->dev.of_node = mdio_np;
	smi->slave_mii_bus->parent = smi->dev;
	smi->ds->slave_mii_bus = smi->slave_mii_bus;

	ret = of_mdiobus_register(smi->slave_mii_bus, mdio_np);
	if (ret) {
		dev_err(smi->dev, "unable to register MDIO bus %s\n",
			smi->slave_mii_bus->id);
		goto err_put_node;
	}

	return 0;

err_put_node:
	of_node_put(mdio_np);

	return ret;
}

__attribute__((used)) static int realtek_smi_probe(struct platform_device *pdev)
{
	const struct realtek_smi_variant *var;
	struct device *dev = &pdev->dev;
	struct realtek_smi *smi;
	struct device_node *np;
	int ret;

	var = of_device_get_match_data(dev);
	np = dev->of_node;

	smi = devm_kzalloc(dev, sizeof(*smi), GFP_KERNEL);
	if (!smi)
		return -ENOMEM;
	smi->map = devm_regmap_init(dev, NULL, smi,
				    &realtek_smi_mdio_regmap_config);
	if (IS_ERR(smi->map)) {
		ret = PTR_ERR(smi->map);
		dev_err(dev, "regmap init failed: %d\n", ret);
		return ret;
	}

	/* Link forward and backward */
	smi->dev = dev;
	smi->clk_delay = var->clk_delay;
	smi->cmd_read = var->cmd_read;
	smi->cmd_write = var->cmd_write;
	smi->ops = var->ops;

	dev_set_drvdata(dev, smi);
	spin_lock_init(&smi->lock);

	/* TODO: if power is software controlled, set up any regulators here */

	/* Assert then deassert RESET */
	smi->reset = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(smi->reset)) {
		dev_err(dev, "failed to get RESET GPIO\n");
		return PTR_ERR(smi->reset);
	}
	msleep(REALTEK_SMI_HW_STOP_DELAY);
	gpiod_set_value(smi->reset, 0);
	msleep(REALTEK_SMI_HW_START_DELAY);
	dev_info(dev, "deasserted RESET\n");

	/* Fetch MDIO pins */
	smi->mdc = devm_gpiod_get_optional(dev, "mdc", GPIOD_OUT_LOW);
	if (IS_ERR(smi->mdc))
		return PTR_ERR(smi->mdc);
	smi->mdio = devm_gpiod_get_optional(dev, "mdio", GPIOD_OUT_LOW);
	if (IS_ERR(smi->mdio))
		return PTR_ERR(smi->mdio);

	smi->leds_disabled = of_property_read_bool(np, "realtek,disable-leds");

	ret = smi->ops->detect(smi);
	if (ret) {
		dev_err(dev, "unable to detect switch\n");
		return ret;
	}

	smi->ds = dsa_switch_alloc(dev, smi->num_ports);
	if (!smi->ds)
		return -ENOMEM;
	smi->ds->priv = smi;

	smi->ds->ops = var->ds_ops;
	ret = dsa_register_switch(smi->ds);
	if (ret) {
		dev_err(dev, "unable to register switch ret = %d\n", ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static int realtek_smi_remove(struct platform_device *pdev)
{
	struct realtek_smi *smi = dev_get_drvdata(&pdev->dev);

	dsa_unregister_switch(smi->ds);
	if (smi->slave_mii_bus)
		of_node_put(smi->slave_mii_bus->dev.of_node);
	gpiod_set_value(smi->reset, 1);

	return 0;
}

