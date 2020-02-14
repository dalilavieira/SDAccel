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
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/ * bus; } ;
struct lm_driver {int (* probe ) (struct lm_device*) ;TYPE_3__ drv; int /*<<< orphan*/  (* remove ) (struct lm_device*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
struct TYPE_10__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * bus; } ;
struct lm_device {TYPE_1__ resource; TYPE_5__ dev; int /*<<< orphan*/  id; } ;
struct device_driver {int dummy; } ;
struct device {int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_name (TYPE_5__*) ; 
 int dev_set_name (TYPE_5__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_5__*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  iomem_resource ; 
 int /*<<< orphan*/  kfree (struct lm_device*) ; 
 int /*<<< orphan*/  lm_bustype ; 
 int /*<<< orphan*/  release_resource (TYPE_1__*) ; 
 int request_resource (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int stub1 (struct lm_device*) ; 
 int /*<<< orphan*/  stub2 (struct lm_device*) ; 
 struct lm_device* to_lm_device (struct device*) ; 
 struct lm_driver* to_lm_driver (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lm_match(struct device *dev, struct device_driver *drv)
{
	return 1;
}

__attribute__((used)) static int lm_bus_probe(struct device *dev)
{
	struct lm_device *lmdev = to_lm_device(dev);
	struct lm_driver *lmdrv = to_lm_driver(dev->driver);

	return lmdrv->probe(lmdev);
}

__attribute__((used)) static int lm_bus_remove(struct device *dev)
{
	struct lm_device *lmdev = to_lm_device(dev);
	struct lm_driver *lmdrv = to_lm_driver(dev->driver);

	if (lmdrv->remove)
		lmdrv->remove(lmdev);
	return 0;
}

int lm_driver_register(struct lm_driver *drv)
{
	drv->drv.bus = &lm_bustype;
	return driver_register(&drv->drv);
}

void lm_driver_unregister(struct lm_driver *drv)
{
	driver_unregister(&drv->drv);
}

__attribute__((used)) static void lm_device_release(struct device *dev)
{
	struct lm_device *d = to_lm_device(dev);

	kfree(d);
}

int lm_device_register(struct lm_device *dev)
{
	int ret;

	dev->dev.release = lm_device_release;
	dev->dev.bus = &lm_bustype;

	ret = dev_set_name(&dev->dev, "lm%d", dev->id);
	if (ret)
		return ret;
	dev->resource.name = dev_name(&dev->dev);

	ret = request_resource(&iomem_resource, &dev->resource);
	if (ret == 0) {
		ret = device_register(&dev->dev);
		if (ret)
			release_resource(&dev->resource);
	}
	return ret;
}

