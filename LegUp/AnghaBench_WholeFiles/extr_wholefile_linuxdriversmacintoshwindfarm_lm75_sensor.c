#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct wf_sensor {int /*<<< orphan*/  name; TYPE_2__* ops; } ;
struct TYPE_8__ {char const* name; int /*<<< orphan*/ * ops; } ;
struct wf_lm75_sensor {int inited; int ds1775; TYPE_3__ sens; struct i2c_client* i2c; } ;
struct wf_control {TYPE_1__* ops; } ;
struct i2c_device_id {int driver_data; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {TYPE_5__ dev; int /*<<< orphan*/  addr; } ;
typedef  int s32 ;
struct TYPE_7__ {int (* get_value ) (struct wf_sensor*,int*) ;} ;
struct TYPE_6__ {int (* get_max ) (struct wf_control*) ;int (* set_value ) (struct wf_control*,int) ;int (* get_min ) (struct wf_control*) ;int (* get_value ) (struct wf_control*,int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*,char const*,...) ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_warn (TYPE_5__*,char*) ; 
 struct wf_lm75_sensor* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct wf_lm75_sensor*) ; 
 int /*<<< orphan*/  i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  kfree (struct wf_lm75_sensor*) ; 
 struct wf_lm75_sensor* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 char* of_get_property (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int stub1 (struct wf_control*) ; 
 int stub2 (struct wf_control*,int) ; 
 int stub3 (struct wf_control*) ; 
 int stub4 (struct wf_control*,int) ; 
 int stub5 (struct wf_control*,int) ; 
 int stub6 (struct wf_control*,int*) ; 
 int stub7 (struct wf_control*) ; 
 int stub8 (struct wf_control*) ; 
 int stub9 (struct wf_sensor*,int*) ; 
 int /*<<< orphan*/  wf_lm75_ops ; 
 int wf_register_sensor (TYPE_3__*) ; 
 struct wf_lm75_sensor* wf_to_lm75 (struct wf_sensor*) ; 
 int /*<<< orphan*/  wf_unregister_sensor (TYPE_3__*) ; 

__attribute__((used)) static inline int wf_control_set_max(struct wf_control *ct)
{
	s32 vmax = ct->ops->get_max(ct);
	return ct->ops->set_value(ct, vmax);
}

__attribute__((used)) static inline int wf_control_set_min(struct wf_control *ct)
{
	s32 vmin = ct->ops->get_min(ct);
	return ct->ops->set_value(ct, vmin);
}

__attribute__((used)) static inline int wf_control_set(struct wf_control *ct, s32 val)
{
	return ct->ops->set_value(ct, val);
}

__attribute__((used)) static inline int wf_control_get(struct wf_control *ct, s32 *val)
{
	return ct->ops->get_value(ct, val);
}

__attribute__((used)) static inline s32 wf_control_get_min(struct wf_control *ct)
{
	return ct->ops->get_min(ct);
}

__attribute__((used)) static inline s32 wf_control_get_max(struct wf_control *ct)
{
	return ct->ops->get_max(ct);
}

__attribute__((used)) static inline int wf_sensor_get(struct wf_sensor *sr, s32 *val)
{
	return sr->ops->get_value(sr, val);
}

__attribute__((used)) static int wf_lm75_get(struct wf_sensor *sr, s32 *value)
{
	struct wf_lm75_sensor *lm = wf_to_lm75(sr);
	s32 data;

	if (lm->i2c == NULL)
		return -ENODEV;

	/* Init chip if necessary */
	if (!lm->inited) {
		u8 cfg_new, cfg = (u8)i2c_smbus_read_byte_data(lm->i2c, 1);

		DBG("wf_lm75: Initializing %s, cfg was: %02x\n",
		    sr->name, cfg);

		/* clear shutdown bit, keep other settings as left by
		 * the firmware for now
		 */
		cfg_new = cfg & ~0x01;
		i2c_smbus_write_byte_data(lm->i2c, 1, cfg_new);
		lm->inited = 1;

		/* If we just powered it up, let's wait 200 ms */
		msleep(200);
	}

	/* Read temperature register */
	data = (s32)le16_to_cpu(i2c_smbus_read_word_data(lm->i2c, 0));
	data <<= 8;
	*value = data;

	return 0;
}

__attribute__((used)) static void wf_lm75_release(struct wf_sensor *sr)
{
	struct wf_lm75_sensor *lm = wf_to_lm75(sr);

	kfree(lm);
}

__attribute__((used)) static int wf_lm75_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{	
	struct wf_lm75_sensor *lm;
	int rc, ds1775 = id->driver_data;
	const char *name, *loc;

	DBG("wf_lm75: creating  %s device at address 0x%02x\n",
	    ds1775 ? "ds1775" : "lm75", client->addr);

	loc = of_get_property(client->dev.of_node, "hwsensor-location", NULL);
	if (!loc) {
		dev_warn(&client->dev, "Missing hwsensor-location property!\n");
		return -ENXIO;
	}

	/* Usual rant about sensor names not beeing very consistent in
	 * the device-tree, oh well ...
	 * Add more entries below as you deal with more setups
	 */
	if (!strcmp(loc, "Hard drive") || !strcmp(loc, "DRIVE BAY"))
		name = "hd-temp";
	else if (!strcmp(loc, "Incoming Air Temp"))
		name = "incoming-air-temp";
	else if (!strcmp(loc, "ODD Temp"))
		name = "optical-drive-temp";
	else if (!strcmp(loc, "HD Temp"))
		name = "hard-drive-temp";
	else if (!strcmp(loc, "PCI SLOTS"))
		name = "slots-temp";
	else if (!strcmp(loc, "CPU A INLET"))
		name = "cpu-inlet-temp-0";
	else if (!strcmp(loc, "CPU B INLET"))
		name = "cpu-inlet-temp-1";
	else
		return -ENXIO;
 	

	lm = kzalloc(sizeof(struct wf_lm75_sensor), GFP_KERNEL);
	if (lm == NULL)
		return -ENODEV;

	lm->inited = 0;
	lm->ds1775 = ds1775;
	lm->i2c = client;
	lm->sens.name = name;
	lm->sens.ops = &wf_lm75_ops;
	i2c_set_clientdata(client, lm);

	rc = wf_register_sensor(&lm->sens);
	if (rc)
		kfree(lm);
	return rc;
}

__attribute__((used)) static int wf_lm75_remove(struct i2c_client *client)
{
	struct wf_lm75_sensor *lm = i2c_get_clientdata(client);

	DBG("wf_lm75: i2c detatch called for %s\n", lm->sens.name);

	/* Mark client detached */
	lm->i2c = NULL;

	/* release sensor */
	wf_unregister_sensor(&lm->sens);

	return 0;
}

