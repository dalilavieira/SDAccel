#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct gpio_chip {int (* get ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int can_sleep; int base; int ngpio; int /*<<< orphan*/  owner; struct device* parent; int /*<<< orphan*/  label; } ;
struct sbsm_data {int is_ltc1760; int cur_chan; int last_state; int last_state_cont; int supported_bats; TYPE_2__* muxc; int /*<<< orphan*/  psy; struct i2c_client* client; struct gpio_chip chip; } ;
struct power_supply_desc {int name; } ;
struct power_supply_config {int /*<<< orphan*/  of_node; struct sbsm_data* drv_data; } ;
struct power_supply {int dummy; } ;
struct i2c_mux_core {int dummy; } ;
struct i2c_driver {int /*<<< orphan*/  (* alert ) (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct device {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; scalar_t__ driver; } ;
struct i2c_client {int addr; struct device dev; int /*<<< orphan*/  name; } ;
struct i2c_adapter {int dummy; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
typedef  enum i2c_alert_protocol { ____Placeholder_i2c_alert_protocol } i2c_alert_protocol ;
struct TYPE_6__ {struct sbsm_data* priv; TYPE_1__** adapter; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPFNOSUPPORT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_MUX_LOCKED ; 
 int /*<<< orphan*/  I2C_PROTOCOL_SMBUS_ALERT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int POWER_SUPPLY_CHARGE_TYPE_FAST ; 
 int POWER_SUPPLY_CHARGE_TYPE_NONE ; 
 int POWER_SUPPLY_CHARGE_TYPE_TRICKLE ; 
#define  POWER_SUPPLY_PROP_CHARGE_TYPE 129 
#define  POWER_SUPPLY_PROP_ONLINE 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SBSM_BIT_AC_PRESENT ; 
 int SBSM_BIT_TURBO ; 
 int SBSM_CMD_BATSYSINFO ; 
 int SBSM_CMD_BATSYSSTATE ; 
 int SBSM_CMD_BATSYSSTATECONT ; 
 int SBSM_CMD_LTC ; 
 int SBSM_MASK_BAT_SUPPORTED ; 
 int SBSM_MASK_CHARGE_BAT ; 
 int SBSM_MAX_BATS ; 
 int SBSM_RETRY_CNT ; 
 int SBSM_SMB_BAT_OFFSET ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_for_each_child (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int (*) (struct device*,void*)) ; 
 int /*<<< orphan*/  device_lock (struct device*) ; 
 int /*<<< orphan*/  device_property_present (struct device*,char*) ; 
 int /*<<< orphan*/  device_unlock (struct device*) ; 
 int devm_gpiochip_add_data (struct device*,struct gpio_chip*,struct sbsm_data*) ; 
 int devm_kasprintf (struct device*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct power_supply_desc* devm_kmemdup (struct device*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct sbsm_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_power_supply_register (struct device*,struct power_supply_desc*,struct power_supply_config*) ; 
 struct sbsm_data* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct sbsm_data* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_mux_add_adapter (TYPE_2__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 TYPE_2__* i2c_mux_alloc (struct i2c_adapter*,struct device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct i2c_mux_core*,int),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (TYPE_2__*) ; 
 struct sbsm_data* i2c_mux_priv (struct i2c_mux_core*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct sbsm_data*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int,int) ; 
 struct i2c_client* i2c_verify_client (struct device*) ; 
 int /*<<< orphan*/  power_supply_changed (int /*<<< orphan*/ ) ; 
 struct sbsm_data* power_supply_get_drvdata (struct power_supply*) ; 
 int /*<<< orphan*/  sbsm_default_psy_desc ; 
 int /*<<< orphan*/  strstr (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 
 struct i2c_driver* to_i2c_driver (scalar_t__) ; 

__attribute__((used)) static int sbsm_read_word(struct i2c_client *client, u8 address)
{
	int reg, retries;

	for (retries = SBSM_RETRY_CNT; retries > 0; retries--) {
		reg = i2c_smbus_read_word_data(client, address);
		if (reg >= 0)
			break;
	}

	if (reg < 0) {
		dev_err(&client->dev, "failed to read register 0x%02x\n",
			address);
	}

	return reg;
}

__attribute__((used)) static int sbsm_write_word(struct i2c_client *client, u8 address, u16 word)
{
	int ret, retries;

	for (retries = SBSM_RETRY_CNT; retries > 0; retries--) {
		ret = i2c_smbus_write_word_data(client, address, word);
		if (ret >= 0)
			break;
	}
	if (ret < 0)
		dev_err(&client->dev, "failed to write to register 0x%02x\n",
			address);

	return ret;
}

__attribute__((used)) static int sbsm_get_property(struct power_supply *psy,
			     enum power_supply_property psp,
			     union power_supply_propval *val)
{
	struct sbsm_data *data = power_supply_get_drvdata(psy);
	int regval = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		regval = sbsm_read_word(data->client, SBSM_CMD_BATSYSSTATECONT);
		if (regval < 0)
			return regval;
		val->intval = !!(regval & SBSM_BIT_AC_PRESENT);
		break;

	case POWER_SUPPLY_PROP_CHARGE_TYPE:
		regval = sbsm_read_word(data->client, SBSM_CMD_BATSYSSTATE);
		if (regval < 0)
			return regval;

		if ((regval & SBSM_MASK_CHARGE_BAT) == 0) {
			val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
			return 0;
		}
		val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;

		if (data->is_ltc1760) {
			/* charge mode fast if turbo is active */
			regval = sbsm_read_word(data->client, SBSM_CMD_LTC);
			if (regval < 0)
				return regval;
			else if (regval & SBSM_BIT_TURBO)
				val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
		}
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int sbsm_prop_is_writeable(struct power_supply *psy,
				  enum power_supply_property psp)
{
	struct sbsm_data *data = power_supply_get_drvdata(psy);

	return (psp == POWER_SUPPLY_PROP_CHARGE_TYPE) && data->is_ltc1760;
}

__attribute__((used)) static int sbsm_set_property(struct power_supply *psy,
			     enum power_supply_property psp,
			     const union power_supply_propval *val)
{
	struct sbsm_data *data = power_supply_get_drvdata(psy);
	int ret = -EINVAL;
	u16 regval;

	switch (psp) {
	case POWER_SUPPLY_PROP_CHARGE_TYPE:
		/* write 1 to TURBO if type fast is given */
		if (!data->is_ltc1760)
			break;
		regval = val->intval ==
			 POWER_SUPPLY_CHARGE_TYPE_FAST ? SBSM_BIT_TURBO : 0;
		ret = sbsm_write_word(data->client, SBSM_CMD_LTC, regval);
		break;

	default:
		break;
	}

	return ret;
}

__attribute__((used)) static int sbsm_select(struct i2c_mux_core *muxc, u32 chan)
{
	struct sbsm_data *data = i2c_mux_priv(muxc);
	struct device *dev = &data->client->dev;
	int ret = 0;
	u16 reg;

	if (data->cur_chan == chan)
		return ret;

	/* chan goes from 1 ... 4 */
	reg = BIT(SBSM_SMB_BAT_OFFSET + chan);
	ret = sbsm_write_word(data->client, SBSM_CMD_BATSYSSTATE, reg);
	if (ret)
		dev_err(dev, "Failed to select channel %i\n", chan);
	else
		data->cur_chan = chan;

	return ret;
}

__attribute__((used)) static int sbsm_gpio_get_value(struct gpio_chip *gc, unsigned int off)
{
	struct sbsm_data *data = gpiochip_get_data(gc);
	int ret;

	ret = sbsm_read_word(data->client, SBSM_CMD_BATSYSSTATE);
	if (ret < 0)
		return ret;

	return ret & BIT(off);
}

__attribute__((used)) static int sbsm_gpio_direction_input(struct gpio_chip *gc, unsigned int off)
{
	return 0;
}

__attribute__((used)) static int sbsm_do_alert(struct device *dev, void *d)
{
	struct i2c_client *client = i2c_verify_client(dev);
	struct i2c_driver *driver;

	if (!client || client->addr != 0x0b)
		return 0;

	device_lock(dev);
	if (client->dev.driver) {
		driver = to_i2c_driver(client->dev.driver);
		if (driver->alert)
			driver->alert(client, I2C_PROTOCOL_SMBUS_ALERT, 0);
		else
			dev_warn(&client->dev, "no driver alert()!\n");
	} else {
		dev_dbg(&client->dev, "alert with no driver\n");
	}
	device_unlock(dev);

	return -EBUSY;
}

__attribute__((used)) static void sbsm_alert(struct i2c_client *client, enum i2c_alert_protocol prot,
		       unsigned int d)
{
	struct sbsm_data *sbsm = i2c_get_clientdata(client);

	int ret, i, irq_bat = 0, state = 0;

	ret = sbsm_read_word(sbsm->client, SBSM_CMD_BATSYSSTATE);
	if (ret >= 0) {
		irq_bat = ret ^ sbsm->last_state;
		sbsm->last_state = ret;
		state = ret;
	}

	ret = sbsm_read_word(sbsm->client, SBSM_CMD_BATSYSSTATECONT);
	if ((ret >= 0) &&
	    ((ret ^ sbsm->last_state_cont) & SBSM_BIT_AC_PRESENT)) {
		irq_bat |= sbsm->supported_bats & state;
		power_supply_changed(sbsm->psy);
	}
	sbsm->last_state_cont = ret;

	for (i = 0; i < SBSM_MAX_BATS; i++) {
		if (irq_bat & BIT(i)) {
			device_for_each_child(&sbsm->muxc->adapter[i]->dev,
					      NULL, sbsm_do_alert);
		}
	}
}

__attribute__((used)) static int sbsm_gpio_setup(struct sbsm_data *data)
{
	struct gpio_chip *gc = &data->chip;
	struct i2c_client *client = data->client;
	struct device *dev = &client->dev;
	int ret;

	if (!device_property_present(dev, "gpio-controller"))
		return 0;

	ret  = sbsm_read_word(client, SBSM_CMD_BATSYSSTATE);
	if (ret < 0)
		return ret;
	data->last_state = ret;

	ret  = sbsm_read_word(client, SBSM_CMD_BATSYSSTATECONT);
	if (ret < 0)
		return ret;
	data->last_state_cont = ret;

	gc->get = sbsm_gpio_get_value;
	gc->direction_input  = sbsm_gpio_direction_input;
	gc->can_sleep = true;
	gc->base = -1;
	gc->ngpio = SBSM_MAX_BATS;
	gc->label = client->name;
	gc->parent = dev;
	gc->owner = THIS_MODULE;

	ret = devm_gpiochip_add_data(dev, gc, data);
	if (ret) {
		dev_err(dev, "devm_gpiochip_add_data failed: %d\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int sbsm_probe(struct i2c_client *client,
		      const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	struct sbsm_data *data;
	struct device *dev = &client->dev;
	struct power_supply_desc *psy_desc;
	struct power_supply_config psy_cfg = {};
	int ret = 0, i;

	/* Device listens only at address 0x0a */
	if (client->addr != 0x0a)
		return -EINVAL;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
		return -EPFNOSUPPORT;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);

	data->client = client;
	data->is_ltc1760 = !!strstr(id->name, "ltc1760");

	ret  = sbsm_read_word(client, SBSM_CMD_BATSYSINFO);
	if (ret < 0)
		return ret;
	data->supported_bats = ret & SBSM_MASK_BAT_SUPPORTED;
	data->muxc = i2c_mux_alloc(adapter, dev, SBSM_MAX_BATS, 0,
				   I2C_MUX_LOCKED, &sbsm_select, NULL);
	if (!data->muxc) {
		dev_err(dev, "failed to alloc i2c mux\n");
		ret = -ENOMEM;
		goto err_mux_alloc;
	}
	data->muxc->priv = data;

	/* register muxed i2c channels. One for each supported battery */
	for (i = 0; i < SBSM_MAX_BATS; ++i) {
		if (data->supported_bats & BIT(i)) {
			ret = i2c_mux_add_adapter(data->muxc, 0, i + 1, 0);
			if (ret)
				break;
		}
	}
	if (ret) {
		dev_err(dev, "failed to register i2c mux channel %d\n", i + 1);
		goto err_mux_register;
	}

	psy_desc = devm_kmemdup(dev, &sbsm_default_psy_desc,
				sizeof(struct power_supply_desc),
				GFP_KERNEL);
	if (!psy_desc) {
		ret = -ENOMEM;
		goto err_psy;
	}

	psy_desc->name = devm_kasprintf(dev, GFP_KERNEL, "sbsm-%s",
					dev_name(&client->dev));
	if (!psy_desc->name) {
		ret = -ENOMEM;
		goto err_psy;
	}
	ret = sbsm_gpio_setup(data);
	if (ret < 0)
		goto err_psy;

	psy_cfg.drv_data = data;
	psy_cfg.of_node = dev->of_node;
	data->psy = devm_power_supply_register(dev, psy_desc, &psy_cfg);
	if (IS_ERR(data->psy)) {
		ret = PTR_ERR(data->psy);
		dev_err(dev, "failed to register power supply %s\n",
			psy_desc->name);
		goto err_psy;
	}

	return 0;

err_psy:
err_mux_register:
	i2c_mux_del_adapters(data->muxc);

err_mux_alloc:
	return ret;
}

__attribute__((used)) static int sbsm_remove(struct i2c_client *client)
{
	struct sbsm_data *data = i2c_get_clientdata(client);

	i2c_mux_del_adapters(data->muxc);
	return 0;
}

