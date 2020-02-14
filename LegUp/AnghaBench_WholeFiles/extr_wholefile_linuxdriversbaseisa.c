#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  name; int /*<<< orphan*/ * bus; } ;
struct isa_driver {int (* probe ) (struct device*,int /*<<< orphan*/ ) ;int (* remove ) (struct device*,int /*<<< orphan*/ ) ;int (* suspend ) (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* resume ) (struct device*,int /*<<< orphan*/ ) ;struct device* devices; TYPE_3__ driver; int /*<<< orphan*/  (* shutdown ) (struct device*,int /*<<< orphan*/ ) ;scalar_t__ (* match ) (struct device*,int /*<<< orphan*/ ) ;} ;
struct device {void (* release ) (struct device*) ;struct isa_driver* platform_data; int /*<<< orphan*/  coherent_dma_mask; int /*<<< orphan*/ * dma_mask; int /*<<< orphan*/ * bus; int /*<<< orphan*/ * parent; } ;
struct isa_dev {unsigned int id; struct device dev; struct device* next; } ;
struct device_driver {int dummy; } ;
typedef  int /*<<< orphan*/  pm_message_t ;
struct TYPE_5__ {struct device* next; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_set_name (struct device*,char*,int /*<<< orphan*/ ,unsigned int) ; 
 int device_register (struct device*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  isa_bus ; 
 int /*<<< orphan*/  isa_bus_type ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 struct isa_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 scalar_t__ stub1 (struct device*,int /*<<< orphan*/ ) ; 
 int stub2 (struct device*,int /*<<< orphan*/ ) ; 
 int stub3 (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (struct device*,int /*<<< orphan*/ ) ; 
 int stub5 (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub6 (struct device*,int /*<<< orphan*/ ) ; 
 TYPE_1__* to_isa_dev (struct device*) ; 
 struct isa_driver* to_isa_driver (struct device_driver*) ; 

__attribute__((used)) static int isa_bus_match(struct device *dev, struct device_driver *driver)
{
	struct isa_driver *isa_driver = to_isa_driver(driver);

	if (dev->platform_data == isa_driver) {
		if (!isa_driver->match ||
			isa_driver->match(dev, to_isa_dev(dev)->id))
			return 1;
		dev->platform_data = NULL;
	}
	return 0;
}

__attribute__((used)) static int isa_bus_probe(struct device *dev)
{
	struct isa_driver *isa_driver = dev->platform_data;

	if (isa_driver && isa_driver->probe)
		return isa_driver->probe(dev, to_isa_dev(dev)->id);

	return 0;
}

__attribute__((used)) static int isa_bus_remove(struct device *dev)
{
	struct isa_driver *isa_driver = dev->platform_data;

	if (isa_driver && isa_driver->remove)
		return isa_driver->remove(dev, to_isa_dev(dev)->id);

	return 0;
}

__attribute__((used)) static void isa_bus_shutdown(struct device *dev)
{
	struct isa_driver *isa_driver = dev->platform_data;

	if (isa_driver && isa_driver->shutdown)
		isa_driver->shutdown(dev, to_isa_dev(dev)->id);
}

__attribute__((used)) static int isa_bus_suspend(struct device *dev, pm_message_t state)
{
	struct isa_driver *isa_driver = dev->platform_data;

	if (isa_driver && isa_driver->suspend)
		return isa_driver->suspend(dev, to_isa_dev(dev)->id, state);

	return 0;
}

__attribute__((used)) static int isa_bus_resume(struct device *dev)
{
	struct isa_driver *isa_driver = dev->platform_data;

	if (isa_driver && isa_driver->resume)
		return isa_driver->resume(dev, to_isa_dev(dev)->id);

	return 0;
}

__attribute__((used)) static void isa_dev_release(struct device *dev)
{
	kfree(to_isa_dev(dev));
}

void isa_unregister_driver(struct isa_driver *isa_driver)
{
	struct device *dev = isa_driver->devices;

	while (dev) {
		struct device *tmp = to_isa_dev(dev)->next;
		device_unregister(dev);
		dev = tmp;
	}
	driver_unregister(&isa_driver->driver);
}

int isa_register_driver(struct isa_driver *isa_driver, unsigned int ndev)
{
	int error;
	unsigned int id;

	isa_driver->driver.bus	= &isa_bus_type;
	isa_driver->devices	= NULL;

	error = driver_register(&isa_driver->driver);
	if (error)
		return error;

	for (id = 0; id < ndev; id++) {
		struct isa_dev *isa_dev;

		isa_dev = kzalloc(sizeof *isa_dev, GFP_KERNEL);
		if (!isa_dev) {
			error = -ENOMEM;
			break;
		}

		isa_dev->dev.parent	= &isa_bus;
		isa_dev->dev.bus	= &isa_bus_type;

		dev_set_name(&isa_dev->dev, "%s.%u",
			     isa_driver->driver.name, id);
		isa_dev->dev.platform_data	= isa_driver;
		isa_dev->dev.release		= isa_dev_release;
		isa_dev->id			= id;

		isa_dev->dev.coherent_dma_mask = DMA_BIT_MASK(24);
		isa_dev->dev.dma_mask = &isa_dev->dev.coherent_dma_mask;

		error = device_register(&isa_dev->dev);
		if (error) {
			put_device(&isa_dev->dev);
			break;
		}

		if (isa_dev->dev.platform_data) {
			isa_dev->next = isa_driver->devices;
			isa_driver->devices = &isa_dev->dev;
		} else
			device_unregister(&isa_dev->dev);
	}

	if (!error && !isa_driver->devices)
		error = -ENODEV;

	if (error)
		isa_unregister_driver(isa_driver);

	return error;
}

