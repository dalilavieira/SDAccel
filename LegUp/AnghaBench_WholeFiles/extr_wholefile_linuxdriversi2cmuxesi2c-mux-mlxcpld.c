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
union i2c_smbus_data {scalar_t__ byte; } ;
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
struct mlxcpld_mux_plat_data {int num_adaps; int* adap_ids; int /*<<< orphan*/  sel_reg_addr; } ;
struct mlxcpld_mux {scalar_t__ last_chan; struct i2c_client* client; } ;
struct i2c_mux_core {struct i2c_adapter* parent; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;
struct i2c_client {TYPE_1__ dev; int /*<<< orphan*/  flags; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {int dummy; } ;

/* Variables and functions */
 int CPLD_MUX_MAX_NCHANS ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_SMBUS_WRITE ; 
 int __i2c_smbus_xfer (struct i2c_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,union i2c_smbus_data*) ; 
 struct mlxcpld_mux_plat_data* dev_get_platdata (TYPE_1__*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct i2c_mux_core* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_mux_add_adapter (struct i2c_mux_core*,int,int,int /*<<< orphan*/ ) ; 
 struct i2c_mux_core* i2c_mux_alloc (struct i2c_adapter*,TYPE_1__*,int,int,int /*<<< orphan*/ ,int (*) (struct i2c_mux_core*,scalar_t__),int (*) (struct i2c_mux_core*,scalar_t__)) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (struct i2c_mux_core*) ; 
 struct mlxcpld_mux* i2c_mux_priv (struct i2c_mux_core*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct i2c_mux_core*) ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlxcpld_mux_reg_write(struct i2c_adapter *adap,
				 struct i2c_client *client, u8 val)
{
	struct mlxcpld_mux_plat_data *pdata = dev_get_platdata(&client->dev);
	union i2c_smbus_data data = { .byte = val };

	return __i2c_smbus_xfer(adap, client->addr, client->flags,
				I2C_SMBUS_WRITE, pdata->sel_reg_addr,
				I2C_SMBUS_BYTE_DATA, &data);
}

__attribute__((used)) static int mlxcpld_mux_select_chan(struct i2c_mux_core *muxc, u32 chan)
{
	struct mlxcpld_mux *data = i2c_mux_priv(muxc);
	struct i2c_client *client = data->client;
	u8 regval = chan + 1;
	int err = 0;

	/* Only select the channel if its different from the last channel */
	if (data->last_chan != regval) {
		err = mlxcpld_mux_reg_write(muxc->parent, client, regval);
		data->last_chan = err < 0 ? 0 : regval;
	}

	return err;
}

__attribute__((used)) static int mlxcpld_mux_deselect(struct i2c_mux_core *muxc, u32 chan)
{
	struct mlxcpld_mux *data = i2c_mux_priv(muxc);
	struct i2c_client *client = data->client;

	/* Deselect active channel */
	data->last_chan = 0;

	return mlxcpld_mux_reg_write(muxc->parent, client, data->last_chan);
}

__attribute__((used)) static int mlxcpld_mux_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
	struct mlxcpld_mux_plat_data *pdata = dev_get_platdata(&client->dev);
	struct i2c_mux_core *muxc;
	int num, force;
	struct mlxcpld_mux *data;
	int err;

	if (!pdata)
		return -EINVAL;

	if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
		return -ENODEV;

	muxc = i2c_mux_alloc(adap, &client->dev, CPLD_MUX_MAX_NCHANS,
			     sizeof(*data), 0, mlxcpld_mux_select_chan,
			     mlxcpld_mux_deselect);
	if (!muxc)
		return -ENOMEM;

	data = i2c_mux_priv(muxc);
	i2c_set_clientdata(client, muxc);
	data->client = client;
	data->last_chan = 0; /* force the first selection */

	/* Create an adapter for each channel. */
	for (num = 0; num < CPLD_MUX_MAX_NCHANS; num++) {
		if (num >= pdata->num_adaps)
			/* discard unconfigured channels */
			break;

		force = pdata->adap_ids[num];

		err = i2c_mux_add_adapter(muxc, force, num, 0);
		if (err)
			goto virt_reg_failed;
	}

	return 0;

virt_reg_failed:
	i2c_mux_del_adapters(muxc);
	return err;
}

__attribute__((used)) static int mlxcpld_mux_remove(struct i2c_client *client)
{
	struct i2c_mux_core *muxc = i2c_get_clientdata(client);

	i2c_mux_del_adapters(muxc);
	return 0;
}

