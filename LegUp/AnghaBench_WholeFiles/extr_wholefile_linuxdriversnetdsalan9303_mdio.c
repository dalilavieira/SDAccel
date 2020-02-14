#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int u16 ;
struct TYPE_15__ {int /*<<< orphan*/  of_node; } ;
struct mdio_device {TYPE_7__ dev; TYPE_1__* bus; } ;
struct TYPE_14__ {int /*<<< orphan*/ * ops; TYPE_7__* dev; int /*<<< orphan*/  regmap; } ;
struct lan9303_mdio {TYPE_5__ chip; struct mdio_device* device; } ;
struct lan9303 {TYPE_7__* dev; } ;
struct TYPE_13__ {int (* read ) (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  mdio_lock; int /*<<< orphan*/  (* write ) (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PHY_ADDR (int) ; 
 int /*<<< orphan*/  PHY_REG (int) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_7__*,char*,int) ; 
 struct lan9303_mdio* dev_get_drvdata (TYPE_7__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_7__*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_7__*,struct lan9303_mdio*) ; 
 struct lan9303_mdio* devm_kzalloc (TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init (TYPE_7__*,int /*<<< orphan*/ *,struct lan9303_mdio*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lan9303_mdio_phy_ops ; 
 int /*<<< orphan*/  lan9303_mdio_regmap_config ; 
 int lan9303_probe (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lan9303_remove (TYPE_5__*) ; 
 int mdiobus_read_nested (TYPE_1__*,int,int) ; 
 int mdiobus_write_nested (TYPE_1__*,int,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int stub2 (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lan9303_mdio_real_write(struct mdio_device *mdio, int reg, u16 val)
{
	mdio->bus->write(mdio->bus, PHY_ADDR(reg), PHY_REG(reg), val);
}

__attribute__((used)) static int lan9303_mdio_write(void *ctx, uint32_t reg, uint32_t val)
{
	struct lan9303_mdio *sw_dev = (struct lan9303_mdio *)ctx;

	reg <<= 2; /* reg num to offset */
	mutex_lock(&sw_dev->device->bus->mdio_lock);
	lan9303_mdio_real_write(sw_dev->device, reg, val & 0xffff);
	lan9303_mdio_real_write(sw_dev->device, reg + 2, (val >> 16) & 0xffff);
	mutex_unlock(&sw_dev->device->bus->mdio_lock);

	return 0;
}

__attribute__((used)) static u16 lan9303_mdio_real_read(struct mdio_device *mdio, int reg)
{
	return mdio->bus->read(mdio->bus, PHY_ADDR(reg), PHY_REG(reg));
}

__attribute__((used)) static int lan9303_mdio_read(void *ctx, uint32_t reg, uint32_t *val)
{
	struct lan9303_mdio *sw_dev = (struct lan9303_mdio *)ctx;

	reg <<= 2; /* reg num to offset */
	mutex_lock(&sw_dev->device->bus->mdio_lock);
	*val = lan9303_mdio_real_read(sw_dev->device, reg);
	*val |= (lan9303_mdio_real_read(sw_dev->device, reg + 2) << 16);
	mutex_unlock(&sw_dev->device->bus->mdio_lock);

	return 0;
}

__attribute__((used)) static int lan9303_mdio_phy_write(struct lan9303 *chip, int phy, int reg,
				  u16 val)
{
	struct lan9303_mdio *sw_dev = dev_get_drvdata(chip->dev);

	return mdiobus_write_nested(sw_dev->device->bus, phy, reg, val);
}

__attribute__((used)) static int lan9303_mdio_phy_read(struct lan9303 *chip, int phy,  int reg)
{
	struct lan9303_mdio *sw_dev = dev_get_drvdata(chip->dev);

	return mdiobus_read_nested(sw_dev->device->bus, phy, reg);
}

__attribute__((used)) static int lan9303_mdio_probe(struct mdio_device *mdiodev)
{
	struct lan9303_mdio *sw_dev;
	int ret;

	sw_dev = devm_kzalloc(&mdiodev->dev, sizeof(struct lan9303_mdio),
			      GFP_KERNEL);
	if (!sw_dev)
		return -ENOMEM;

	sw_dev->chip.regmap = devm_regmap_init(&mdiodev->dev, NULL, sw_dev,
					       &lan9303_mdio_regmap_config);
	if (IS_ERR(sw_dev->chip.regmap)) {
		ret = PTR_ERR(sw_dev->chip.regmap);
		dev_err(&mdiodev->dev, "regmap init failed: %d\n", ret);
		return ret;
	}

	/* link forward and backward */
	sw_dev->device = mdiodev;
	dev_set_drvdata(&mdiodev->dev, sw_dev);
	sw_dev->chip.dev = &mdiodev->dev;

	sw_dev->chip.ops = &lan9303_mdio_phy_ops;

	ret = lan9303_probe(&sw_dev->chip, mdiodev->dev.of_node);
	if (ret != 0)
		return ret;

	dev_info(&mdiodev->dev, "LAN9303 MDIO driver loaded successfully\n");

	return 0;
}

__attribute__((used)) static void lan9303_mdio_remove(struct mdio_device *mdiodev)
{
	struct lan9303_mdio *sw_dev = dev_get_drvdata(&mdiodev->dev);

	if (!sw_dev)
		return;

	lan9303_remove(&sw_dev->chip);
}

