#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {struct nvkm_device* device; } ;
struct nvbios_therm_sensor {int /*<<< orphan*/  offset_constant; } ;
struct nvkm_therm {struct i2c_client* ic; TYPE_4__ subdev; struct nvbios_therm_sensor bios_sensor; } ;
struct TYPE_6__ {int /*<<< orphan*/  member_0; } ;
struct nvkm_i2c_bus_probe {int member_1; TYPE_2__ member_0; } ;
struct nvkm_i2c_bus {int /*<<< orphan*/  i2c; } ;
struct nvkm_i2c {int dummy; } ;
struct nvkm_device {struct nvkm_i2c* i2c; struct nvkm_bios* bios; } ;
struct nvkm_bios {int dummy; } ;
struct nvbios_extdev_func {int addr; } ;
struct TYPE_5__ {int /*<<< orphan*/  driver; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct i2c_board_info {int /*<<< orphan*/  addr; int /*<<< orphan*/  type; } ;
struct TYPE_7__ {scalar_t__ (* detect ) (struct i2c_client*,struct i2c_board_info*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  I2C_BOARD_INFO (char*,int) ; 
 int /*<<< orphan*/  I2C_MODULE_PREFIX ; 
 int /*<<< orphan*/  NVBIOS_EXTDEV_ADT7473 ; 
 int /*<<< orphan*/  NVBIOS_EXTDEV_LM89 ; 
 int /*<<< orphan*/  NVKM_I2C_BUS_PRI ; 
 struct i2c_client* i2c_new_device (int /*<<< orphan*/ *,struct i2c_board_info*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 struct nvkm_i2c_bus_probe* nv_board_infos ; 
 int /*<<< orphan*/  nvbios_extdev_find (struct nvkm_bios*,int /*<<< orphan*/ ,struct nvbios_extdev_func*) ; 
 int /*<<< orphan*/  nvkm_debug (TYPE_4__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nvkm_i2c_bus* nvkm_i2c_bus_find (struct nvkm_i2c*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_i2c_bus_probe (struct nvkm_i2c_bus*,char*,struct nvkm_i2c_bus_probe*,int (*) (struct nvkm_i2c_bus*,struct i2c_board_info*,void*),struct nvkm_therm*) ; 
 int /*<<< orphan*/  request_module (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ stub1 (struct i2c_client*,struct i2c_board_info*) ; 
 TYPE_3__* to_i2c_driver (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
probe_monitoring_device(struct nvkm_i2c_bus *bus,
			struct i2c_board_info *info, void *data)
{
	struct nvkm_therm *therm = data;
	struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
	struct i2c_client *client;

	request_module("%s%s", I2C_MODULE_PREFIX, info->type);

	client = i2c_new_device(&bus->i2c, info);
	if (!client)
		return false;

	if (!client->dev.driver ||
	    to_i2c_driver(client->dev.driver)->detect(client, info)) {
		i2c_unregister_device(client);
		return false;
	}

	nvkm_debug(&therm->subdev,
		   "Found an %s at address 0x%x (controlled by lm_sensors, "
		   "temp offset %+i C)\n",
		   info->type, info->addr, sensor->offset_constant);
	therm->ic = client;
	return true;
}

void
nvkm_therm_ic_ctor(struct nvkm_therm *therm)
{
	struct nvkm_device *device = therm->subdev.device;
	struct nvkm_bios *bios = device->bios;
	struct nvkm_i2c *i2c = device->i2c;
	struct nvkm_i2c_bus *bus;
	struct nvbios_extdev_func extdev_entry;

	bus = nvkm_i2c_bus_find(i2c, NVKM_I2C_BUS_PRI);
	if (!bus)
		return;

	if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_LM89, &extdev_entry)) {
		struct nvkm_i2c_bus_probe board[] = {
		  { { I2C_BOARD_INFO("lm90", extdev_entry.addr >> 1) }, 0},
		  { }
		};

		nvkm_i2c_bus_probe(bus, "monitoring device", board,
				   probe_monitoring_device, therm);
		if (therm->ic)
			return;
	}

	if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_ADT7473, &extdev_entry)) {
		struct nvkm_i2c_bus_probe board[] = {
		  { { I2C_BOARD_INFO("adt7473", extdev_entry.addr >> 1) }, 20 },
		  { }
		};

		nvkm_i2c_bus_probe(bus, "monitoring device", board,
				   probe_monitoring_device, therm);
		if (therm->ic)
			return;
	}

	/* The vbios doesn't provide the address of an exisiting monitoring
	   device. Let's try our static list.
	 */
	nvkm_i2c_bus_probe(bus, "monitoring device", nv_board_infos,
			   probe_monitoring_device, therm);
}

