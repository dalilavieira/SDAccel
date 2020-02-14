#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {struct module* owner; int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct snd_seq_driver {scalar_t__ argsize; TYPE_2__ driver; int /*<<< orphan*/  id; } ;
struct TYPE_8__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * bus; int /*<<< orphan*/ * parent; int /*<<< orphan*/  driver; } ;
struct snd_seq_device {char const* id; scalar_t__ argsize; int device; TYPE_1__ dev; struct snd_card* card; int /*<<< orphan*/  (* private_free ) (struct snd_seq_device*) ;} ;
struct snd_device_ops {int (* dev_free ) (struct snd_device*) ;int (* dev_register ) (struct snd_device*) ;int (* dev_disconnect ) (struct snd_device*) ;} ;
struct snd_device {struct snd_seq_device* device_data; } ;
struct snd_card {int /*<<< orphan*/  number; int /*<<< orphan*/  card_dev; } ;
struct module {int dummy; } ;
struct device_driver {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SNDRV_DEV_SEQUENCER ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  cancel_autoload_drivers () ; 
 int /*<<< orphan*/  dev_set_name (TYPE_1__*,char*,char const*,int /*<<< orphan*/ ,int) ; 
 int device_add (TYPE_1__*) ; 
 int /*<<< orphan*/  device_del (TYPE_1__*) ; 
 int /*<<< orphan*/  device_initialize (TYPE_1__*) ; 
 int driver_register (TYPE_2__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_2__*) ; 
 int /*<<< orphan*/  kfree (struct snd_seq_device*) ; 
 struct snd_seq_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (TYPE_1__*) ; 
 int /*<<< orphan*/  queue_autoload_drivers () ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int snd_device_new (struct snd_card*,int /*<<< orphan*/ ,struct snd_seq_device*,struct snd_device_ops*) ; 
 int /*<<< orphan*/  snd_seq_bus_type ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  stub1 (struct snd_seq_device*) ; 
 struct snd_seq_device* to_seq_dev (struct device*) ; 
 struct snd_seq_driver* to_seq_drv (struct device_driver*) ; 

__attribute__((used)) static int snd_seq_bus_match(struct device *dev, struct device_driver *drv)
{
	struct snd_seq_device *sdev = to_seq_dev(dev);
	struct snd_seq_driver *sdrv = to_seq_drv(drv);

	return strcmp(sdrv->id, sdev->id) == 0 &&
		sdrv->argsize == sdev->argsize;
}

__attribute__((used)) static int snd_seq_device_dev_free(struct snd_device *device)
{
	struct snd_seq_device *dev = device->device_data;

	cancel_autoload_drivers();
	put_device(&dev->dev);
	return 0;
}

__attribute__((used)) static int snd_seq_device_dev_register(struct snd_device *device)
{
	struct snd_seq_device *dev = device->device_data;
	int err;

	err = device_add(&dev->dev);
	if (err < 0)
		return err;
	if (!dev->dev.driver)
		queue_autoload_drivers();
	return 0;
}

__attribute__((used)) static int snd_seq_device_dev_disconnect(struct snd_device *device)
{
	struct snd_seq_device *dev = device->device_data;

	device_del(&dev->dev);
	return 0;
}

__attribute__((used)) static void snd_seq_dev_release(struct device *dev)
{
	struct snd_seq_device *sdev = to_seq_dev(dev);

	if (sdev->private_free)
		sdev->private_free(sdev);
	kfree(sdev);
}

int snd_seq_device_new(struct snd_card *card, int device, const char *id,
		       int argsize, struct snd_seq_device **result)
{
	struct snd_seq_device *dev;
	int err;
	static struct snd_device_ops dops = {
		.dev_free = snd_seq_device_dev_free,
		.dev_register = snd_seq_device_dev_register,
		.dev_disconnect = snd_seq_device_dev_disconnect,
	};

	if (result)
		*result = NULL;

	if (snd_BUG_ON(!id))
		return -EINVAL;

	dev = kzalloc(sizeof(*dev) + argsize, GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	/* set up device info */
	dev->card = card;
	dev->device = device;
	dev->id = id;
	dev->argsize = argsize;

	device_initialize(&dev->dev);
	dev->dev.parent = &card->card_dev;
	dev->dev.bus = &snd_seq_bus_type;
	dev->dev.release = snd_seq_dev_release;
	dev_set_name(&dev->dev, "%s-%d-%d", dev->id, card->number, device);

	/* add this device to the list */
	err = snd_device_new(card, SNDRV_DEV_SEQUENCER, dev, &dops);
	if (err < 0) {
		put_device(&dev->dev);
		return err;
	}
	
	if (result)
		*result = dev;

	return 0;
}

int __snd_seq_driver_register(struct snd_seq_driver *drv, struct module *mod)
{
	if (WARN_ON(!drv->driver.name || !drv->id))
		return -EINVAL;
	drv->driver.bus = &snd_seq_bus_type;
	drv->driver.owner = mod;
	return driver_register(&drv->driver);
}

void snd_seq_driver_unregister(struct snd_seq_driver *drv)
{
	driver_unregister(&drv->driver);
}

