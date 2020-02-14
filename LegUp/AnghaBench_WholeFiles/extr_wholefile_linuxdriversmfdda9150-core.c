#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct i2c_msg {int len; int* buf; scalar_t__ flags; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  adapter; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  addr; } ;
struct device {int dummy; } ;
struct da9150_pdata {int irq_base; int /*<<< orphan*/  fg_pdata; } ;
struct da9150_fg_pdata {int dummy; } ;
struct da9150 {int irq_base; struct i2c_client* core_qif; int /*<<< orphan*/ * dev; int /*<<< orphan*/  regmap_irq_data; int /*<<< orphan*/  irq; int /*<<< orphan*/  regmap; } ;
struct TYPE_4__ {int pdata_size; int /*<<< orphan*/  platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_1__*) ; 
#define  DA9150_ADETD_STAT 178 
#define  DA9150_ADETVB_CFG_C 177 
#define  DA9150_ADET_CMPSTAT 176 
#define  DA9150_ADET_CTRL_A 175 
#define  DA9150_CC_IAVG_RES_A 174 
#define  DA9150_CC_IAVG_RES_B 173 
#define  DA9150_CC_ICHG_RES_A 172 
#define  DA9150_CC_ICHG_RES_B 171 
 int DA9150_CONFIG_D ; 
#define  DA9150_CONTROL_B 170 
#define  DA9150_CONTROL_C 169 
 int DA9150_CORE2WIRE_CTRL_A ; 
#define  DA9150_CORE2WIRE_STAT_A 168 
#define  DA9150_COREBTLD_STAT_A 167 
 int DA9150_CORE_BASE_ADDR_MASK ; 
#define  DA9150_CORE_DATA_A 166 
#define  DA9150_CORE_DATA_B 165 
#define  DA9150_CORE_DATA_C 164 
#define  DA9150_CORE_DATA_D 163 
 int DA9150_DISABLE_MASK ; 
#define  DA9150_EVENT_E 162 
#define  DA9150_EVENT_F 161 
#define  DA9150_EVENT_G 160 
#define  DA9150_EVENT_H 159 
#define  DA9150_FAULT_LOG_A 158 
#define  DA9150_FAULT_LOG_B 157 
#define  DA9150_FG_CTRL_B 156 
 size_t DA9150_FG_IDX ; 
#define  DA9150_FW_CTRL_B 155 
#define  DA9150_FW_CTRL_C 154 
#define  DA9150_GPADC_CMAN 153 
#define  DA9150_GPADC_CRES_A 152 
#define  DA9150_GPADC_CRES_B 151 
#define  DA9150_GPADC_MAN 150 
#define  DA9150_GPADC_RES_A 149 
#define  DA9150_GPADC_RES_B 148 
#define  DA9150_PAGE_CON 147 
#define  DA9150_PPR_TCTR_B 146 
 int DA9150_QIF_I2C_ADDR_LSB ; 
#define  DA9150_STATUS_A 145 
#define  DA9150_STATUS_B 144 
#define  DA9150_STATUS_C 143 
#define  DA9150_STATUS_D 142 
#define  DA9150_STATUS_E 141 
#define  DA9150_STATUS_F 140 
#define  DA9150_STATUS_G 139 
#define  DA9150_STATUS_H 138 
#define  DA9150_STATUS_I 137 
#define  DA9150_STATUS_J 136 
#define  DA9150_STATUS_K 135 
#define  DA9150_STATUS_L 134 
#define  DA9150_STATUS_N 133 
#define  DA9150_TAUX_CTRL_A 132 
#define  DA9150_TAUX_VALUE_H 131 
#define  DA9150_TAUX_VALUE_L 130 
#define  DA9150_TBAT_RES_A 129 
#define  DA9150_TBAT_RES_B 128 
 int DA9150_WKUP_PM_EN_MASK ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ I2C_M_RD ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_1__* da9150_devs ; 
 int /*<<< orphan*/  da9150_regmap_config ; 
 int /*<<< orphan*/  da9150_regmap_irq_chip ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct da9150_pdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct da9150* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  enable_irq_wake (int /*<<< orphan*/ ) ; 
 struct da9150* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da9150*) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 int regmap_add_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int,int*,int) ; 
 int /*<<< orphan*/  regmap_del_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_irq_chip_get_base (int /*<<< orphan*/ ) ; 
 int regmap_raw_write (int /*<<< orphan*/ ,int,int const*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int da9150_i2c_read_device(struct i2c_client *client, u8 addr, int count,
				  u8 *buf)
{
	struct i2c_msg xfer;
	int ret;

	/*
	 * Read is split into two transfers as device expects STOP/START rather
	 * than repeated start to carry out this kind of access.
	 */

	/* Write address */
	xfer.addr = client->addr;
	xfer.flags = 0;
	xfer.len = 1;
	xfer.buf = &addr;

	ret = i2c_transfer(client->adapter, &xfer, 1);
	if (ret != 1) {
		if (ret < 0)
			return ret;
		else
			return -EIO;
	}

	/* Read data */
	xfer.addr = client->addr;
	xfer.flags = I2C_M_RD;
	xfer.len = count;
	xfer.buf = buf;

	ret = i2c_transfer(client->adapter, &xfer, 1);
	if (ret == 1)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int da9150_i2c_write_device(struct i2c_client *client, u8 addr,
				   int count, const u8 *buf)
{
	struct i2c_msg xfer;
	u8 *reg_data;
	int ret;

	reg_data = kzalloc(1 + count, GFP_KERNEL);
	if (!reg_data)
		return -ENOMEM;

	reg_data[0] = addr;
	memcpy(&reg_data[1], buf, count);

	/* Write address & data */
	xfer.addr = client->addr;
	xfer.flags = 0;
	xfer.len = 1 + count;
	xfer.buf = reg_data;

	ret = i2c_transfer(client->adapter, &xfer, 1);
	kfree(reg_data);
	if (ret == 1)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static bool da9150_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA9150_PAGE_CON:
	case DA9150_STATUS_A:
	case DA9150_STATUS_B:
	case DA9150_STATUS_C:
	case DA9150_STATUS_D:
	case DA9150_STATUS_E:
	case DA9150_STATUS_F:
	case DA9150_STATUS_G:
	case DA9150_STATUS_H:
	case DA9150_STATUS_I:
	case DA9150_STATUS_J:
	case DA9150_STATUS_K:
	case DA9150_STATUS_L:
	case DA9150_STATUS_N:
	case DA9150_FAULT_LOG_A:
	case DA9150_FAULT_LOG_B:
	case DA9150_EVENT_E:
	case DA9150_EVENT_F:
	case DA9150_EVENT_G:
	case DA9150_EVENT_H:
	case DA9150_CONTROL_B:
	case DA9150_CONTROL_C:
	case DA9150_GPADC_MAN:
	case DA9150_GPADC_RES_A:
	case DA9150_GPADC_RES_B:
	case DA9150_ADETVB_CFG_C:
	case DA9150_ADETD_STAT:
	case DA9150_ADET_CMPSTAT:
	case DA9150_ADET_CTRL_A:
	case DA9150_PPR_TCTR_B:
	case DA9150_COREBTLD_STAT_A:
	case DA9150_CORE_DATA_A:
	case DA9150_CORE_DATA_B:
	case DA9150_CORE_DATA_C:
	case DA9150_CORE_DATA_D:
	case DA9150_CORE2WIRE_STAT_A:
	case DA9150_FW_CTRL_C:
	case DA9150_FG_CTRL_B:
	case DA9150_FW_CTRL_B:
	case DA9150_GPADC_CMAN:
	case DA9150_GPADC_CRES_A:
	case DA9150_GPADC_CRES_B:
	case DA9150_CC_ICHG_RES_A:
	case DA9150_CC_ICHG_RES_B:
	case DA9150_CC_IAVG_RES_A:
	case DA9150_CC_IAVG_RES_B:
	case DA9150_TAUX_CTRL_A:
	case DA9150_TAUX_VALUE_H:
	case DA9150_TAUX_VALUE_L:
	case DA9150_TBAT_RES_A:
	case DA9150_TBAT_RES_B:
		return true;
	default:
		return false;
	}
}

void da9150_read_qif(struct da9150 *da9150, u8 addr, int count, u8 *buf)
{
	int ret;

	ret = da9150_i2c_read_device(da9150->core_qif, addr, count, buf);
	if (ret < 0)
		dev_err(da9150->dev, "Failed to read from QIF 0x%x: %d\n",
			addr, ret);
}

void da9150_write_qif(struct da9150 *da9150, u8 addr, int count, const u8 *buf)
{
	int ret;

	ret = da9150_i2c_write_device(da9150->core_qif, addr, count, buf);
	if (ret < 0)
		dev_err(da9150->dev, "Failed to write to QIF 0x%x: %d\n",
			addr, ret);
}

u8 da9150_reg_read(struct da9150 *da9150, u16 reg)
{
	int val, ret;

	ret = regmap_read(da9150->regmap, reg, &val);
	if (ret)
		dev_err(da9150->dev, "Failed to read from reg 0x%x: %d\n",
			reg, ret);

	return (u8) val;
}

void da9150_reg_write(struct da9150 *da9150, u16 reg, u8 val)
{
	int ret;

	ret = regmap_write(da9150->regmap, reg, val);
	if (ret)
		dev_err(da9150->dev, "Failed to write to reg 0x%x: %d\n",
			reg, ret);
}

void da9150_set_bits(struct da9150 *da9150, u16 reg, u8 mask, u8 val)
{
	int ret;

	ret = regmap_update_bits(da9150->regmap, reg, mask, val);
	if (ret)
		dev_err(da9150->dev, "Failed to set bits in reg 0x%x: %d\n",
			reg, ret);
}

void da9150_bulk_read(struct da9150 *da9150, u16 reg, int count, u8 *buf)
{
	int ret;

	ret = regmap_bulk_read(da9150->regmap, reg, buf, count);
	if (ret)
		dev_err(da9150->dev, "Failed to bulk read from reg 0x%x: %d\n",
			reg, ret);
}

void da9150_bulk_write(struct da9150 *da9150, u16 reg, int count, const u8 *buf)
{
	int ret;

	ret = regmap_raw_write(da9150->regmap, reg, buf, count);
	if (ret)
		dev_err(da9150->dev, "Failed to bulk write to reg 0x%x %d\n",
			reg, ret);
}

__attribute__((used)) static int da9150_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct da9150 *da9150;
	struct da9150_pdata *pdata = dev_get_platdata(&client->dev);
	int qif_addr;
	int ret;

	da9150 = devm_kzalloc(&client->dev, sizeof(*da9150), GFP_KERNEL);
	if (!da9150)
		return -ENOMEM;

	da9150->dev = &client->dev;
	da9150->irq = client->irq;
	i2c_set_clientdata(client, da9150);

	da9150->regmap = devm_regmap_init_i2c(client, &da9150_regmap_config);
	if (IS_ERR(da9150->regmap)) {
		ret = PTR_ERR(da9150->regmap);
		dev_err(da9150->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	/* Setup secondary I2C interface for QIF access */
	qif_addr = da9150_reg_read(da9150, DA9150_CORE2WIRE_CTRL_A);
	qif_addr = (qif_addr & DA9150_CORE_BASE_ADDR_MASK) >> 1;
	qif_addr |= DA9150_QIF_I2C_ADDR_LSB;
	da9150->core_qif = i2c_new_dummy(client->adapter, qif_addr);
	if (!da9150->core_qif) {
		dev_err(da9150->dev, "Failed to attach QIF client\n");
		return -ENODEV;
	}

	i2c_set_clientdata(da9150->core_qif, da9150);

	if (pdata) {
		da9150->irq_base = pdata->irq_base;

		da9150_devs[DA9150_FG_IDX].platform_data = pdata->fg_pdata;
		da9150_devs[DA9150_FG_IDX].pdata_size =
			sizeof(struct da9150_fg_pdata);
	} else {
		da9150->irq_base = -1;
	}

	ret = regmap_add_irq_chip(da9150->regmap, da9150->irq,
				  IRQF_TRIGGER_LOW | IRQF_ONESHOT,
				  da9150->irq_base, &da9150_regmap_irq_chip,
				  &da9150->regmap_irq_data);
	if (ret) {
		dev_err(da9150->dev, "Failed to add regmap irq chip: %d\n",
			ret);
		goto regmap_irq_fail;
	}


	da9150->irq_base = regmap_irq_chip_get_base(da9150->regmap_irq_data);

	enable_irq_wake(da9150->irq);

	ret = mfd_add_devices(da9150->dev, -1, da9150_devs,
			      ARRAY_SIZE(da9150_devs), NULL,
			      da9150->irq_base, NULL);
	if (ret) {
		dev_err(da9150->dev, "Failed to add child devices: %d\n", ret);
		goto mfd_fail;
	}

	return 0;

mfd_fail:
	regmap_del_irq_chip(da9150->irq, da9150->regmap_irq_data);
regmap_irq_fail:
	i2c_unregister_device(da9150->core_qif);

	return ret;
}

__attribute__((used)) static int da9150_remove(struct i2c_client *client)
{
	struct da9150 *da9150 = i2c_get_clientdata(client);

	regmap_del_irq_chip(da9150->irq, da9150->regmap_irq_data);
	mfd_remove_devices(da9150->dev);
	i2c_unregister_device(da9150->core_qif);

	return 0;
}

__attribute__((used)) static void da9150_shutdown(struct i2c_client *client)
{
	struct da9150 *da9150 = i2c_get_clientdata(client);

	/* Make sure we have a wakup source for the device */
	da9150_set_bits(da9150, DA9150_CONFIG_D,
			DA9150_WKUP_PM_EN_MASK,
			DA9150_WKUP_PM_EN_MASK);

	/* Set device to DISABLED mode */
	da9150_set_bits(da9150, DA9150_CONTROL_C,
			DA9150_DISABLE_MASK, DA9150_DISABLE_MASK);
}

