#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct superhyway_driver {int (* probe ) (struct superhyway_device*,struct superhyway_device_id const*) ;struct superhyway_device_id* id_table; TYPE_3__ drv; int /*<<< orphan*/  name; int /*<<< orphan*/  (* remove ) (struct superhyway_device*) ;} ;
struct superhyway_device_id {scalar_t__ id; } ;
struct TYPE_7__ {int id; } ;
struct TYPE_10__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * bus; int /*<<< orphan*/ * parent; } ;
struct TYPE_8__ {int mod_id; } ;
struct superhyway_device {unsigned long start; int end; TYPE_1__ id; struct superhyway_device* resource; TYPE_5__ dev; int /*<<< orphan*/  name; TYPE_2__ vcr; struct superhyway_bus* bus; } ;
struct superhyway_bus {int dummy; } ;
struct resource {int dummy; } ;
struct device_driver {int dummy; } ;
struct device {struct device_driver* driver; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_set_name (TYPE_5__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_5__*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  kfree (struct superhyway_device*) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,int) ; 
 int stub1 (struct superhyway_device*,struct superhyway_device_id const*) ; 
 int /*<<< orphan*/  stub2 (struct superhyway_device*) ; 
 int /*<<< orphan*/  superhyway_bus_device ; 
 int /*<<< orphan*/  superhyway_bus_type ; 
 int /*<<< orphan*/  superhyway_devices ; 
 int /*<<< orphan*/  superhyway_read_vcr (struct superhyway_device*,unsigned long,TYPE_2__*) ; 
 struct superhyway_device* to_superhyway_device (struct device*) ; 
 struct superhyway_driver* to_superhyway_driver (struct device_driver*) ; 

__attribute__((used)) static void superhyway_device_release(struct device *dev)
{
	struct superhyway_device *sdev = to_superhyway_device(dev);

	kfree(sdev->resource);
	kfree(sdev);
}

int superhyway_add_device(unsigned long base, struct superhyway_device *sdev,
			  struct superhyway_bus *bus)
{
	struct superhyway_device *dev = sdev;

	if (!dev) {
		dev = kzalloc(sizeof(struct superhyway_device), GFP_KERNEL);
		if (!dev)
			return -ENOMEM;

	}

	dev->bus = bus;
	superhyway_read_vcr(dev, base, &dev->vcr);

	if (!dev->resource) {
		dev->resource = kzalloc(sizeof(struct resource), GFP_KERNEL);
		if (!dev->resource) {
			kfree(dev);
			return -ENOMEM;
		}

		dev->resource->name	= dev->name;
		dev->resource->start	= base;
		dev->resource->end	= dev->resource->start + 0x01000000;
	}

	dev->dev.parent		= &superhyway_bus_device;
	dev->dev.bus		= &superhyway_bus_type;
	dev->dev.release	= superhyway_device_release;
	dev->id.id		= dev->vcr.mod_id;

	sprintf(dev->name, "SuperHyway device %04x", dev->id.id);
	dev_set_name(&dev->dev, "%02x", superhyway_devices);

	superhyway_devices++;

	return device_register(&dev->dev);
}

int superhyway_add_devices(struct superhyway_bus *bus,
			   struct superhyway_device **devices,
			   int nr_devices)
{
	int i, ret = 0;

	for (i = 0; i < nr_devices; i++) {
		struct superhyway_device *dev = devices[i];
		ret |= superhyway_add_device(dev->resource[0].start, dev, bus);
	}

	return ret;
}

__attribute__((used)) static const struct superhyway_device_id *
superhyway_match_id(const struct superhyway_device_id *ids,
		    struct superhyway_device *dev)
{
	while (ids->id) {
		if (ids->id == dev->id.id)
			return ids;

		ids++;
	}

	return NULL;
}

__attribute__((used)) static int superhyway_device_probe(struct device *dev)
{
	struct superhyway_device *shyway_dev = to_superhyway_device(dev);
	struct superhyway_driver *shyway_drv = to_superhyway_driver(dev->driver);

	if (shyway_drv && shyway_drv->probe) {
		const struct superhyway_device_id *id;

		id = superhyway_match_id(shyway_drv->id_table, shyway_dev);
		if (id)
			return shyway_drv->probe(shyway_dev, id);
	}

	return -ENODEV;
}

__attribute__((used)) static int superhyway_device_remove(struct device *dev)
{
	struct superhyway_device *shyway_dev = to_superhyway_device(dev);
	struct superhyway_driver *shyway_drv = to_superhyway_driver(dev->driver);

	if (shyway_drv && shyway_drv->remove) {
		shyway_drv->remove(shyway_dev);
		return 0;
	}

	return -ENODEV;
}

int superhyway_register_driver(struct superhyway_driver *drv)
{
	drv->drv.name	= drv->name;
	drv->drv.bus	= &superhyway_bus_type;

	return driver_register(&drv->drv);
}

void superhyway_unregister_driver(struct superhyway_driver *drv)
{
	driver_unregister(&drv->drv);
}

__attribute__((used)) static int superhyway_bus_match(struct device *dev, struct device_driver *drv)
{
	struct superhyway_device *shyway_dev = to_superhyway_device(dev);
	struct superhyway_driver *shyway_drv = to_superhyway_driver(drv);
	const struct superhyway_device_id *ids = shyway_drv->id_table;

	if (!ids)
		return -EINVAL;
	if (superhyway_match_id(ids, shyway_dev))
		return 1;

	return -ENODEV;
}

