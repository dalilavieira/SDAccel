#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
struct power_supply_config {int /*<<< orphan*/  num_supplicants; int /*<<< orphan*/  supplied_to; } ;
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct power_supply {TYPE_1__ dev; } ;
struct TYPE_12__ {int /*<<< orphan*/  parent; struct max8925_power_pdata* platform_data; } ;
struct platform_device {TYPE_4__ dev; } ;
struct max8925_power_pdata {int topoff_threshold; int fast_charge; int /*<<< orphan*/  no_insert_detect; int /*<<< orphan*/  no_temp_support; int /*<<< orphan*/  (* set_charger ) (int) ;scalar_t__ batt_detect; int /*<<< orphan*/  num_supplicants; int /*<<< orphan*/  supplied_to; } ;
struct max8925_power_info {int ac_online; int usb_online; int bat_online; int topoff_threshold; int fast_charge; TYPE_3__* battery; TYPE_3__* usb; TYPE_3__* ac; int /*<<< orphan*/  no_insert_detect; int /*<<< orphan*/  no_temp_support; int /*<<< orphan*/  (* set_charger ) (int) ;scalar_t__ batt_detect; int /*<<< orphan*/  adc; int /*<<< orphan*/  gpm; struct max8925_chip* chip; } ;
struct max8925_chip {int irq_base; int /*<<< orphan*/  adc; int /*<<< orphan*/  i2c; int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
struct TYPE_10__ {TYPE_4__* parent; } ;
struct TYPE_11__ {TYPE_2__ dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODATA ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 int MAX8925_ADC_ISNS ; 
 int MAX8925_ADC_VBBATT ; 
 int MAX8925_ADC_VCHG ; 
 int MAX8925_ADC_VMBATT ; 
 int MAX8925_CHG_AC_RANGE_MASK ; 
 int /*<<< orphan*/  MAX8925_CHG_CNTL1 ; 
 int MAX8925_CHG_MBDET ; 
 int /*<<< orphan*/  MAX8925_CHG_STATUS ; 
 int MAX8925_CHG_STAT_EN_MASK ; 
 int MAX8925_CHG_STAT_MODE_MASK ; 
 int MAX8925_CMD_ISNS ; 
 int MAX8925_CMD_VBBATT ; 
 int MAX8925_CMD_VCHG ; 
 int MAX8925_CMD_VMBATT ; 
#define  MAX8925_IRQ_VCHG_DC_F 147 
#define  MAX8925_IRQ_VCHG_DC_OVP 146 
#define  MAX8925_IRQ_VCHG_DC_R 145 
#define  MAX8925_IRQ_VCHG_DONE 144 
#define  MAX8925_IRQ_VCHG_RST 143 
#define  MAX8925_IRQ_VCHG_SYSLOW_F 142 
#define  MAX8925_IRQ_VCHG_SYSLOW_R 141 
#define  MAX8925_IRQ_VCHG_THM_OK_F 140 
#define  MAX8925_IRQ_VCHG_THM_OK_R 139 
#define  MAX8925_IRQ_VCHG_TMR_FAULT 138 
#define  MAX8925_IRQ_VCHG_TOPOFF 137 
#define  MEASURE_ISNS 136 
#define  MEASURE_VBBATT 135 
#define  MEASURE_VCHG 134 
#define  MEASURE_VMBATT 133 
 int POWER_SUPPLY_CHARGE_TYPE_FAST ; 
 int POWER_SUPPLY_CHARGE_TYPE_NONE ; 
 int POWER_SUPPLY_CHARGE_TYPE_TRICKLE ; 
#define  POWER_SUPPLY_PROP_CHARGE_TYPE 132 
#define  POWER_SUPPLY_PROP_CURRENT_NOW 131 
#define  POWER_SUPPLY_PROP_ONLINE 130 
#define  POWER_SUPPLY_PROP_STATUS 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int PTR_ERR (TYPE_3__*) ; 
 int /*<<< orphan*/  REQUEST_IRQ (int const,char*) ; 
 int /*<<< orphan*/  ac_desc ; 
 int /*<<< orphan*/  battery_desc ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 void* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*) ; 
 struct max8925_power_info* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct max8925_power_info*) ; 
 int /*<<< orphan*/  max8925_bulk_read (int /*<<< orphan*/ ,int,int,unsigned char*) ; 
 int max8925_reg_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max8925_reg_write (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max8925_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct max8925_power_info* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max8925_power_info*) ; 
 void* power_supply_register (TYPE_4__*,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  stub1 (int) ; 
 int /*<<< orphan*/  stub2 (int) ; 
 int /*<<< orphan*/  usb_desc ; 

__attribute__((used)) static int __set_charger(struct max8925_power_info *info, int enable)
{
	struct max8925_chip *chip = info->chip;
	if (enable) {
		/* enable charger in platform */
		if (info->set_charger)
			info->set_charger(1);
		/* enable charger */
		max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 0);
	} else {
		/* disable charge */
		max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 1 << 7);
		if (info->set_charger)
			info->set_charger(0);
	}
	dev_dbg(chip->dev, "%s\n", (enable) ? "Enable charger"
		: "Disable charger");
	return 0;
}

__attribute__((used)) static irqreturn_t max8925_charger_handler(int irq, void *data)
{
	struct max8925_power_info *info = (struct max8925_power_info *)data;
	struct max8925_chip *chip = info->chip;

	switch (irq - chip->irq_base) {
	case MAX8925_IRQ_VCHG_DC_R:
		info->ac_online = 1;
		__set_charger(info, 1);
		dev_dbg(chip->dev, "Adapter inserted\n");
		break;
	case MAX8925_IRQ_VCHG_DC_F:
		info->ac_online = 0;
		__set_charger(info, 0);
		dev_dbg(chip->dev, "Adapter removed\n");
		break;
	case MAX8925_IRQ_VCHG_THM_OK_F:
		/* Battery is not ready yet */
		dev_dbg(chip->dev, "Battery temperature is out of range\n");
	case MAX8925_IRQ_VCHG_DC_OVP:
		dev_dbg(chip->dev, "Error detection\n");
		__set_charger(info, 0);
		break;
	case MAX8925_IRQ_VCHG_THM_OK_R:
		/* Battery is ready now */
		dev_dbg(chip->dev, "Battery temperature is in range\n");
		break;
	case MAX8925_IRQ_VCHG_SYSLOW_R:
		/* VSYS is low */
		dev_info(chip->dev, "Sys power is too low\n");
		break;
	case MAX8925_IRQ_VCHG_SYSLOW_F:
		dev_dbg(chip->dev, "Sys power is above low threshold\n");
		break;
	case MAX8925_IRQ_VCHG_DONE:
		__set_charger(info, 0);
		dev_dbg(chip->dev, "Charging is done\n");
		break;
	case MAX8925_IRQ_VCHG_TOPOFF:
		dev_dbg(chip->dev, "Charging in top-off mode\n");
		break;
	case MAX8925_IRQ_VCHG_TMR_FAULT:
		__set_charger(info, 0);
		dev_dbg(chip->dev, "Safe timer is expired\n");
		break;
	case MAX8925_IRQ_VCHG_RST:
		__set_charger(info, 0);
		dev_dbg(chip->dev, "Charger is reset\n");
		break;
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int start_measure(struct max8925_power_info *info, int type)
{
	unsigned char buf[2] = {0, 0};
	int meas_cmd;
	int meas_reg = 0, ret;

	switch (type) {
	case MEASURE_VCHG:
		meas_cmd = MAX8925_CMD_VCHG;
		meas_reg = MAX8925_ADC_VCHG;
		break;
	case MEASURE_VBBATT:
		meas_cmd = MAX8925_CMD_VBBATT;
		meas_reg = MAX8925_ADC_VBBATT;
		break;
	case MEASURE_VMBATT:
		meas_cmd = MAX8925_CMD_VMBATT;
		meas_reg = MAX8925_ADC_VMBATT;
		break;
	case MEASURE_ISNS:
		meas_cmd = MAX8925_CMD_ISNS;
		meas_reg = MAX8925_ADC_ISNS;
		break;
	default:
		return -EINVAL;
	}

	max8925_reg_write(info->adc, meas_cmd, 0);
	max8925_bulk_read(info->adc, meas_reg, 2, buf);
	ret = ((buf[0]<<8) | buf[1]) >> 4;

	return ret;
}

__attribute__((used)) static int max8925_ac_get_prop(struct power_supply *psy,
			       enum power_supply_property psp,
			       union power_supply_propval *val)
{
	struct max8925_power_info *info = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = info->ac_online;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		if (info->ac_online) {
			ret = start_measure(info, MEASURE_VCHG);
			if (ret >= 0) {
				val->intval = ret * 2000;	/* unit is uV */
				goto out;
			}
		}
		ret = -ENODATA;
		break;
	default:
		ret = -ENODEV;
		break;
	}
out:
	return ret;
}

__attribute__((used)) static int max8925_usb_get_prop(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct max8925_power_info *info = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = info->usb_online;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		if (info->usb_online) {
			ret = start_measure(info, MEASURE_VCHG);
			if (ret >= 0) {
				val->intval = ret * 2000;	/* unit is uV */
				goto out;
			}
		}
		ret = -ENODATA;
		break;
	default:
		ret = -ENODEV;
		break;
	}
out:
	return ret;
}

__attribute__((used)) static int max8925_bat_get_prop(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct max8925_power_info *info = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = info->bat_online;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		if (info->bat_online) {
			ret = start_measure(info, MEASURE_VMBATT);
			if (ret >= 0) {
				val->intval = ret * 2000;	/* unit is uV */
				ret = 0;
				break;
			}
		}
		ret = -ENODATA;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		if (info->bat_online) {
			ret = start_measure(info, MEASURE_ISNS);
			if (ret >= 0) {
				/* assume r_sns is 0.02 */
				ret = ((ret * 6250) - 3125) /* uA */;
				val->intval = 0;
				if (ret > 0)
					val->intval = ret; /* unit is mA */
				ret = 0;
				break;
			}
		}
		ret = -ENODATA;
		break;
	case POWER_SUPPLY_PROP_CHARGE_TYPE:
		if (!info->bat_online) {
			ret = -ENODATA;
			break;
		}
		ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
		ret = (ret & MAX8925_CHG_STAT_MODE_MASK) >> 2;
		switch (ret) {
		case 1:
			val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
			break;
		case 0:
		case 2:
			val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
			break;
		case 3:
			val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
			break;
		}
		ret = 0;
		break;
	case POWER_SUPPLY_PROP_STATUS:
		if (!info->bat_online) {
			ret = -ENODATA;
			break;
		}
		ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
		if (info->usb_online || info->ac_online) {
			val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
			if (ret & MAX8925_CHG_STAT_EN_MASK)
				val->intval = POWER_SUPPLY_STATUS_CHARGING;
		} else
			val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
		ret = 0;
		break;
	default:
		ret = -ENODEV;
		break;
	}
	return ret;
}

__attribute__((used)) static int max8925_init_charger(struct max8925_chip *chip,
					  struct max8925_power_info *info)
{
	int ret;

	REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_OVP, "ac-ovp");
	if (!info->no_insert_detect) {
		REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_F, "ac-remove");
		REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_R, "ac-insert");
	}
	if (!info->no_temp_support) {
		REQUEST_IRQ(MAX8925_IRQ_VCHG_THM_OK_R, "batt-temp-in-range");
		REQUEST_IRQ(MAX8925_IRQ_VCHG_THM_OK_F, "batt-temp-out-range");
	}
	REQUEST_IRQ(MAX8925_IRQ_VCHG_SYSLOW_F, "vsys-high");
	REQUEST_IRQ(MAX8925_IRQ_VCHG_SYSLOW_R, "vsys-low");
	REQUEST_IRQ(MAX8925_IRQ_VCHG_RST, "charger-reset");
	REQUEST_IRQ(MAX8925_IRQ_VCHG_DONE, "charger-done");
	REQUEST_IRQ(MAX8925_IRQ_VCHG_TOPOFF, "charger-topoff");
	REQUEST_IRQ(MAX8925_IRQ_VCHG_TMR_FAULT, "charger-timer-expire");

	info->usb_online = 0;
	info->bat_online = 0;

	/* check for power - can miss interrupt at boot time */
	if (start_measure(info, MEASURE_VCHG) * 2000 > 500000)
		info->ac_online = 1;
	else
		info->ac_online = 0;

	ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
	if (ret >= 0) {
		/*
		 * If battery detection is enabled, ID pin of battery is
		 * connected to MBDET pin of MAX8925. It could be used to
		 * detect battery presence.
		 * Otherwise, we have to assume that battery is always on.
		 */
		if (info->batt_detect)
			info->bat_online = (ret & MAX8925_CHG_MBDET) ? 0 : 1;
		else
			info->bat_online = 1;
		if (ret & MAX8925_CHG_AC_RANGE_MASK)
			info->ac_online = 1;
		else
			info->ac_online = 0;
	}
	/* disable charge */
	max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 1 << 7);
	/* set charging current in charge topoff mode */
	max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 3 << 5,
			 info->topoff_threshold << 5);
	/* set charing current in fast charge mode */
	max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 7, info->fast_charge);

	return 0;
}

__attribute__((used)) static int max8925_deinit_charger(struct max8925_power_info *info)
{
	struct max8925_chip *chip = info->chip;
	int irq;

	irq = chip->irq_base + MAX8925_IRQ_VCHG_DC_OVP;
	for (; irq <= chip->irq_base + MAX8925_IRQ_VCHG_TMR_FAULT; irq++)
		free_irq(irq, info);

	return 0;
}

__attribute__((used)) static struct max8925_power_pdata *
max8925_power_dt_init(struct platform_device *pdev)
{
	return pdev->dev.platform_data;
}

__attribute__((used)) static int max8925_power_probe(struct platform_device *pdev)
{
	struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct power_supply_config psy_cfg = {}; /* Only for ac and usb */
	struct max8925_power_pdata *pdata = NULL;
	struct max8925_power_info *info;
	int ret;

	pdata = max8925_power_dt_init(pdev);
	if (!pdata) {
		dev_err(&pdev->dev, "platform data isn't assigned to "
			"power supply\n");
		return -EINVAL;
	}

	info = devm_kzalloc(&pdev->dev, sizeof(struct max8925_power_info),
				GFP_KERNEL);
	if (!info)
		return -ENOMEM;
	info->chip = chip;
	info->gpm = chip->i2c;
	info->adc = chip->adc;
	platform_set_drvdata(pdev, info);

	psy_cfg.supplied_to = pdata->supplied_to;
	psy_cfg.num_supplicants = pdata->num_supplicants;

	info->ac = power_supply_register(&pdev->dev, &ac_desc, &psy_cfg);
	if (IS_ERR(info->ac)) {
		ret = PTR_ERR(info->ac);
		goto out;
	}
	info->ac->dev.parent = &pdev->dev;

	info->usb = power_supply_register(&pdev->dev, &usb_desc, &psy_cfg);
	if (IS_ERR(info->usb)) {
		ret = PTR_ERR(info->usb);
		goto out_unregister_ac;
	}
	info->usb->dev.parent = &pdev->dev;

	info->battery = power_supply_register(&pdev->dev, &battery_desc, NULL);
	if (IS_ERR(info->battery)) {
		ret = PTR_ERR(info->battery);
		goto out_unregister_usb;
	}
	info->battery->dev.parent = &pdev->dev;

	info->batt_detect = pdata->batt_detect;
	info->topoff_threshold = pdata->topoff_threshold;
	info->fast_charge = pdata->fast_charge;
	info->set_charger = pdata->set_charger;
	info->no_temp_support = pdata->no_temp_support;
	info->no_insert_detect = pdata->no_insert_detect;

	max8925_init_charger(chip, info);
	return 0;
out_unregister_usb:
	power_supply_unregister(info->usb);
out_unregister_ac:
	power_supply_unregister(info->ac);
out:
	return ret;
}

__attribute__((used)) static int max8925_power_remove(struct platform_device *pdev)
{
	struct max8925_power_info *info = platform_get_drvdata(pdev);

	if (info) {
		power_supply_unregister(info->ac);
		power_supply_unregister(info->usb);
		power_supply_unregister(info->battery);
		max8925_deinit_charger(info);
	}
	return 0;
}

