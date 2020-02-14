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
struct TYPE_3__ {int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct dio_driver {int (* probe ) (struct dio_dev*,struct dio_device_id const*) ;struct dio_device_id* id_table; TYPE_1__ driver; int /*<<< orphan*/  name; } ;
struct dio_device_id {int id; } ;
struct dio_dev {int id; struct dio_driver* driver; } ;
struct device_driver {int dummy; } ;
struct device {struct device_driver* driver; } ;

/* Variables and functions */
 scalar_t__ DIO_NEEDSSECID (int) ; 
 int DIO_WILDCARD ; 
 int /*<<< orphan*/  dio_bus_type ; 
 int driver_register (TYPE_1__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_1__*) ; 
 int stub1 (struct dio_dev*,struct dio_device_id const*) ; 
 struct dio_dev* to_dio_dev (struct device*) ; 
 struct dio_driver* to_dio_driver (struct device_driver*) ; 

const struct dio_device_id *
dio_match_device(const struct dio_device_id *ids,
		   const struct dio_dev *d)
{
	while (ids->id) {
		if (ids->id == DIO_WILDCARD)
			return ids;
		if (DIO_NEEDSSECID(ids->id & 0xff)) {
			if (ids->id == d->id)
				return ids;
		} else {
			if ((ids->id & 0xff) == (d->id & 0xff))
				return ids;
		}
		ids++;
	}
	return NULL;
}

__attribute__((used)) static int dio_device_probe(struct device *dev)
{
	int error = 0;
	struct dio_driver *drv = to_dio_driver(dev->driver);
	struct dio_dev *d = to_dio_dev(dev);

	if (!d->driver && drv->probe) {
		const struct dio_device_id *id;

		id = dio_match_device(drv->id_table, d);
		if (id)
			error = drv->probe(d, id);
		if (error >= 0) {
			d->driver = drv;
			error = 0;
		}
	}
	return error;
}

int dio_register_driver(struct dio_driver *drv)
{
	/* initialize common driver fields */
	drv->driver.name = drv->name;
	drv->driver.bus = &dio_bus_type;

	/* register with core */
	return driver_register(&drv->driver);
}

void dio_unregister_driver(struct dio_driver *drv)
{
	driver_unregister(&drv->driver);
}

__attribute__((used)) static int dio_bus_match(struct device *dev, struct device_driver *drv)
{
	struct dio_dev *d = to_dio_dev(dev);
	struct dio_driver *dio_drv = to_dio_driver(drv);
	const struct dio_device_id *ids = dio_drv->id_table;

	if (!ids)
		return 0;

	return dio_match_device(ids, d) ? 1 : 0;
}

