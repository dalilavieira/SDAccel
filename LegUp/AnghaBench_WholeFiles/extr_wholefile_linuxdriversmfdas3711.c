#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct i2c_device_id {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {TYPE_1__ dev; scalar_t__ irq; } ;
struct device {int dummy; } ;
struct as3711_platform_data {int /*<<< orphan*/  backlight; int /*<<< orphan*/  regulator; } ;
struct as3711 {TYPE_1__* dev; int /*<<< orphan*/  regmap; } ;
struct TYPE_12__ {int pdata_size; int /*<<< orphan*/ * platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_2__*) ; 
#define  AS3711_ASIC_ID_1 160 
#define  AS3711_ASIC_ID_2 159 
 size_t AS3711_BACKLIGHT ; 
#define  AS3711_CHARGER_STATUS_1 158 
#define  AS3711_CHARGER_STATUS_2 157 
#define  AS3711_CURR1_VALUE 156 
#define  AS3711_CURR2_VALUE 155 
#define  AS3711_CURR3_VALUE 154 
#define  AS3711_CURR_CONTROL 153 
#define  AS3711_GPIO_SIGNAL_IN 152 
#define  AS3711_GPIO_SIGNAL_OUT 151 
#define  AS3711_INTERRUPT_STATUS_1 150 
#define  AS3711_INTERRUPT_STATUS_2 149 
#define  AS3711_INTERRUPT_STATUS_3 148 
#define  AS3711_LDO_1_VOLTAGE 147 
#define  AS3711_LDO_2_VOLTAGE 146 
#define  AS3711_LDO_3_VOLTAGE 145 
#define  AS3711_LDO_4_VOLTAGE 144 
#define  AS3711_LDO_5_VOLTAGE 143 
#define  AS3711_LDO_6_VOLTAGE 142 
#define  AS3711_LDO_7_VOLTAGE 141 
#define  AS3711_LDO_8_VOLTAGE 140 
 size_t AS3711_REGULATOR ; 
#define  AS3711_REG_STATUS 139 
#define  AS3711_SD_1_VOLTAGE 138 
#define  AS3711_SD_2_VOLTAGE 137 
#define  AS3711_SD_3_VOLTAGE 136 
#define  AS3711_SD_4_VOLTAGE 135 
#define  AS3711_SD_CONTROL 134 
#define  AS3711_SD_CONTROL_1 133 
#define  AS3711_SD_CONTROL_2 132 
#define  AS3711_STEPUP_CONTROL_1 131 
#define  AS3711_STEPUP_CONTROL_2 130 
#define  AS3711_STEPUP_CONTROL_4 129 
#define  AS3711_STEPUP_CONTROL_5 128 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  as3711_regmap_config ; 
 TYPE_2__* as3711_subdevs ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct as3711_platform_data* dev_get_platdata (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_notice (TYPE_1__*,char*) ; 
 void* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (TYPE_1__*,int,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct as3711*) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 

__attribute__((used)) static bool as3711_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AS3711_GPIO_SIGNAL_IN:
	case AS3711_INTERRUPT_STATUS_1:
	case AS3711_INTERRUPT_STATUS_2:
	case AS3711_INTERRUPT_STATUS_3:
	case AS3711_CHARGER_STATUS_1:
	case AS3711_CHARGER_STATUS_2:
	case AS3711_REG_STATUS:
		return true;
	}
	return false;
}

__attribute__((used)) static bool as3711_precious_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AS3711_INTERRUPT_STATUS_1:
	case AS3711_INTERRUPT_STATUS_2:
	case AS3711_INTERRUPT_STATUS_3:
		return true;
	}
	return false;
}

__attribute__((used)) static bool as3711_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AS3711_SD_1_VOLTAGE:
	case AS3711_SD_2_VOLTAGE:
	case AS3711_SD_3_VOLTAGE:
	case AS3711_SD_4_VOLTAGE:
	case AS3711_LDO_1_VOLTAGE:
	case AS3711_LDO_2_VOLTAGE:
	case AS3711_LDO_3_VOLTAGE:
	case AS3711_LDO_4_VOLTAGE:
	case AS3711_LDO_5_VOLTAGE:
	case AS3711_LDO_6_VOLTAGE:
	case AS3711_LDO_7_VOLTAGE:
	case AS3711_LDO_8_VOLTAGE:
	case AS3711_SD_CONTROL:
	case AS3711_GPIO_SIGNAL_OUT:
	case AS3711_GPIO_SIGNAL_IN:
	case AS3711_SD_CONTROL_1:
	case AS3711_SD_CONTROL_2:
	case AS3711_CURR_CONTROL:
	case AS3711_CURR1_VALUE:
	case AS3711_CURR2_VALUE:
	case AS3711_CURR3_VALUE:
	case AS3711_STEPUP_CONTROL_1:
	case AS3711_STEPUP_CONTROL_2:
	case AS3711_STEPUP_CONTROL_4:
	case AS3711_STEPUP_CONTROL_5:
	case AS3711_REG_STATUS:
	case AS3711_INTERRUPT_STATUS_1:
	case AS3711_INTERRUPT_STATUS_2:
	case AS3711_INTERRUPT_STATUS_3:
	case AS3711_CHARGER_STATUS_1:
	case AS3711_CHARGER_STATUS_2:
	case AS3711_ASIC_ID_1:
	case AS3711_ASIC_ID_2:
		return true;
	}
	return false;
}

__attribute__((used)) static int as3711_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct as3711 *as3711;
	struct as3711_platform_data *pdata;
	unsigned int id1, id2;
	int ret;

	if (!client->dev.of_node) {
		pdata = dev_get_platdata(&client->dev);
		if (!pdata)
			dev_dbg(&client->dev, "Platform data not found\n");
	} else {
		pdata = devm_kzalloc(&client->dev,
				     sizeof(*pdata), GFP_KERNEL);
		if (!pdata)
			return -ENOMEM;
	}

	as3711 = devm_kzalloc(&client->dev, sizeof(struct as3711), GFP_KERNEL);
	if (!as3711)
		return -ENOMEM;

	as3711->dev = &client->dev;
	i2c_set_clientdata(client, as3711);

	if (client->irq)
		dev_notice(&client->dev, "IRQ not supported yet\n");

	as3711->regmap = devm_regmap_init_i2c(client, &as3711_regmap_config);
	if (IS_ERR(as3711->regmap)) {
		ret = PTR_ERR(as3711->regmap);
		dev_err(&client->dev,
			"regmap initialization failed: %d\n", ret);
		return ret;
	}

	ret = regmap_read(as3711->regmap, AS3711_ASIC_ID_1, &id1);
	if (!ret)
		ret = regmap_read(as3711->regmap, AS3711_ASIC_ID_2, &id2);
	if (ret < 0) {
		dev_err(&client->dev, "regmap_read() failed: %d\n", ret);
		return ret;
	}
	if (id1 != 0x8b)
		return -ENODEV;
	dev_info(as3711->dev, "AS3711 detected: %x:%x\n", id1, id2);

	/*
	 * We can reuse as3711_subdevs[],
	 * it will be copied in mfd_add_devices()
	 */
	if (pdata) {
		as3711_subdevs[AS3711_REGULATOR].platform_data =
			&pdata->regulator;
		as3711_subdevs[AS3711_REGULATOR].pdata_size =
			sizeof(pdata->regulator);
		as3711_subdevs[AS3711_BACKLIGHT].platform_data =
			&pdata->backlight;
		as3711_subdevs[AS3711_BACKLIGHT].pdata_size =
			sizeof(pdata->backlight);
	} else {
		as3711_subdevs[AS3711_REGULATOR].platform_data = NULL;
		as3711_subdevs[AS3711_REGULATOR].pdata_size = 0;
		as3711_subdevs[AS3711_BACKLIGHT].platform_data = NULL;
		as3711_subdevs[AS3711_BACKLIGHT].pdata_size = 0;
	}

	ret = devm_mfd_add_devices(as3711->dev, -1, as3711_subdevs,
				   ARRAY_SIZE(as3711_subdevs), NULL, 0, NULL);
	if (ret < 0)
		dev_err(&client->dev, "add mfd devices failed: %d\n", ret);

	return ret;
}

