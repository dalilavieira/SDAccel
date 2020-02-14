#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {void (* release ) (struct device*) ;int /*<<< orphan*/  of_node; int /*<<< orphan*/ * bus; int /*<<< orphan*/ * parent; } ;
struct sdio_func {int class; int vendor; int device; TYPE_2__ dev; int /*<<< orphan*/  num; struct mmc_card* card; struct sdio_func* tmpbuf; struct sdio_func* info; scalar_t__ irq_handler; } ;
struct TYPE_12__ {int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct sdio_driver {int (* probe ) (struct sdio_func*,struct sdio_device_id const*) ;TYPE_3__ drv; int /*<<< orphan*/  name; int /*<<< orphan*/  (* remove ) (struct sdio_func*) ;struct sdio_device_id* id_table; } ;
struct sdio_device_id {scalar_t__ class; scalar_t__ vendor; scalar_t__ device; } ;
struct mmc_request {int dummy; } ;
struct mmc_host {int caps; TYPE_1__* ops; } ;
struct mmc_card {struct mmc_host* host; int /*<<< orphan*/  dev; } ;
struct kobj_uevent_env {int dummy; } ;
struct device_driver {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {struct device_driver* driver; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  scalar_t__ __u8 ;
typedef  scalar_t__ __u16 ;
struct TYPE_10__ {int /*<<< orphan*/  (* post_req ) (struct mmc_host*,struct mmc_request*,int) ;int /*<<< orphan*/  (* pre_req ) (struct mmc_host*,struct mmc_request*) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 struct sdio_func* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MMC_CAP_POWER_OFF_CARD ; 
 scalar_t__ SDIO_ANY_ID ; 
 int /*<<< orphan*/  __mmc_claim_host (struct mmc_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ add_uevent_var (struct kobj_uevent_env*,char*,scalar_t__,...) ; 
 int bus_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_unregister (int /*<<< orphan*/ *) ; 
 int dev_pm_domain_attach (struct device*,int) ; 
 int /*<<< orphan*/  dev_pm_domain_detach (struct device*,int) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_2__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sdio_func* dev_to_sdio_func (struct device*) ; 
 int device_add (TYPE_2__*) ; 
 int /*<<< orphan*/  device_del (TYPE_2__*) ; 
 int /*<<< orphan*/  device_enable_async_suspend (TYPE_2__*) ; 
 int /*<<< orphan*/  device_initialize (TYPE_2__*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  kfree (struct sdio_func*) ; 
 struct sdio_func* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct sdio_func* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_card_id (struct mmc_card*) ; 
 int /*<<< orphan*/  mmc_of_find_child_device (struct mmc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (unsigned int) ; 
 int /*<<< orphan*/  of_node_put (int /*<<< orphan*/ ) ; 
 int pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (TYPE_2__*) ; 
 int /*<<< orphan*/  sdio_bus_type ; 
 int /*<<< orphan*/  sdio_claim_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_free_func_cis (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_func_present (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_func_set_present (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_release_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_release_irq (struct sdio_func*) ; 
 int sdio_set_block_size (struct sdio_func*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,int) ; 
 int /*<<< orphan*/  stub1 (struct mmc_host*,struct mmc_request*) ; 
 int /*<<< orphan*/  stub2 (struct mmc_host*,struct mmc_request*,int) ; 
 int stub3 (struct sdio_func*,struct sdio_device_id const*) ; 
 int /*<<< orphan*/  stub4 (struct sdio_func*) ; 
 struct sdio_driver* to_sdio_driver (struct device_driver*) ; 
 int /*<<< orphan*/  usleep_range (unsigned int,unsigned int) ; 

__attribute__((used)) static inline void mmc_delay(unsigned int ms)
{
	if (ms <= 20)
		usleep_range(ms * 1000, ms * 1250);
	else
		msleep(ms);
}

__attribute__((used)) static inline void mmc_register_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_unregister_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_claim_host(struct mmc_host *host)
{
	__mmc_claim_host(host, NULL, NULL);
}

__attribute__((used)) static inline void mmc_pre_req(struct mmc_host *host, struct mmc_request *mrq)
{
	if (host->ops->pre_req)
		host->ops->pre_req(host, mrq);
}

__attribute__((used)) static inline void mmc_post_req(struct mmc_host *host, struct mmc_request *mrq,
				int err)
{
	if (host->ops->post_req)
		host->ops->post_req(host, mrq, err);
}

__attribute__((used)) static ssize_t modalias_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct sdio_func *func = dev_to_sdio_func (dev);

	return sprintf(buf, "sdio:c%02Xv%04Xd%04X\n",
			func->class, func->vendor, func->device);
}

__attribute__((used)) static const struct sdio_device_id *sdio_match_one(struct sdio_func *func,
	const struct sdio_device_id *id)
{
	if (id->class != (__u8)SDIO_ANY_ID && id->class != func->class)
		return NULL;
	if (id->vendor != (__u16)SDIO_ANY_ID && id->vendor != func->vendor)
		return NULL;
	if (id->device != (__u16)SDIO_ANY_ID && id->device != func->device)
		return NULL;
	return id;
}

__attribute__((used)) static const struct sdio_device_id *sdio_match_device(struct sdio_func *func,
	struct sdio_driver *sdrv)
{
	const struct sdio_device_id *ids;

	ids = sdrv->id_table;

	if (ids) {
		while (ids->class || ids->vendor || ids->device) {
			if (sdio_match_one(func, ids))
				return ids;
			ids++;
		}
	}

	return NULL;
}

__attribute__((used)) static int sdio_bus_match(struct device *dev, struct device_driver *drv)
{
	struct sdio_func *func = dev_to_sdio_func(dev);
	struct sdio_driver *sdrv = to_sdio_driver(drv);

	if (sdio_match_device(func, sdrv))
		return 1;

	return 0;
}

__attribute__((used)) static int
sdio_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	struct sdio_func *func = dev_to_sdio_func(dev);

	if (add_uevent_var(env,
			"SDIO_CLASS=%02X", func->class))
		return -ENOMEM;

	if (add_uevent_var(env, 
			"SDIO_ID=%04X:%04X", func->vendor, func->device))
		return -ENOMEM;

	if (add_uevent_var(env,
			"MODALIAS=sdio:c%02Xv%04Xd%04X",
			func->class, func->vendor, func->device))
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static int sdio_bus_probe(struct device *dev)
{
	struct sdio_driver *drv = to_sdio_driver(dev->driver);
	struct sdio_func *func = dev_to_sdio_func(dev);
	const struct sdio_device_id *id;
	int ret;

	id = sdio_match_device(func, drv);
	if (!id)
		return -ENODEV;

	ret = dev_pm_domain_attach(dev, false);
	if (ret)
		return ret;

	/* Unbound SDIO functions are always suspended.
	 * During probe, the function is set active and the usage count
	 * is incremented.  If the driver supports runtime PM,
	 * it should call pm_runtime_put_noidle() in its probe routine and
	 * pm_runtime_get_noresume() in its remove routine.
	 */
	if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD) {
		ret = pm_runtime_get_sync(dev);
		if (ret < 0)
			goto disable_runtimepm;
	}

	/* Set the default block size so the driver is sure it's something
	 * sensible. */
	sdio_claim_host(func);
	ret = sdio_set_block_size(func, 0);
	sdio_release_host(func);
	if (ret)
		goto disable_runtimepm;

	ret = drv->probe(func, id);
	if (ret)
		goto disable_runtimepm;

	return 0;

disable_runtimepm:
	if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_put_noidle(dev);
	dev_pm_domain_detach(dev, false);
	return ret;
}

__attribute__((used)) static int sdio_bus_remove(struct device *dev)
{
	struct sdio_driver *drv = to_sdio_driver(dev->driver);
	struct sdio_func *func = dev_to_sdio_func(dev);
	int ret = 0;

	/* Make sure card is powered before invoking ->remove() */
	if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_get_sync(dev);

	drv->remove(func);

	if (func->irq_handler) {
		pr_warn("WARNING: driver %s did not remove its interrupt handler!\n",
			drv->name);
		sdio_claim_host(func);
		sdio_release_irq(func);
		sdio_release_host(func);
	}

	/* First, undo the increment made directly above */
	if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_put_noidle(dev);

	/* Then undo the runtime PM settings in sdio_bus_probe() */
	if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_put_sync(dev);

	dev_pm_domain_detach(dev, false);

	return ret;
}

int sdio_register_bus(void)
{
	return bus_register(&sdio_bus_type);
}

void sdio_unregister_bus(void)
{
	bus_unregister(&sdio_bus_type);
}

int sdio_register_driver(struct sdio_driver *drv)
{
	drv->drv.name = drv->name;
	drv->drv.bus = &sdio_bus_type;
	return driver_register(&drv->drv);
}

void sdio_unregister_driver(struct sdio_driver *drv)
{
	drv->drv.bus = &sdio_bus_type;
	driver_unregister(&drv->drv);
}

__attribute__((used)) static void sdio_release_func(struct device *dev)
{
	struct sdio_func *func = dev_to_sdio_func(dev);

	sdio_free_func_cis(func);

	kfree(func->info);
	kfree(func->tmpbuf);
	kfree(func);
}

struct sdio_func *sdio_alloc_func(struct mmc_card *card)
{
	struct sdio_func *func;

	func = kzalloc(sizeof(struct sdio_func), GFP_KERNEL);
	if (!func)
		return ERR_PTR(-ENOMEM);

	/*
	 * allocate buffer separately to make sure it's properly aligned for
	 * DMA usage (incl. 64 bit DMA)
	 */
	func->tmpbuf = kmalloc(4, GFP_KERNEL);
	if (!func->tmpbuf) {
		kfree(func);
		return ERR_PTR(-ENOMEM);
	}

	func->card = card;

	device_initialize(&func->dev);

	func->dev.parent = &card->dev;
	func->dev.bus = &sdio_bus_type;
	func->dev.release = sdio_release_func;

	return func;
}

__attribute__((used)) static inline void sdio_acpi_set_handle(struct sdio_func *func) {}

__attribute__((used)) static void sdio_set_of_node(struct sdio_func *func)
{
	struct mmc_host *host = func->card->host;

	func->dev.of_node = mmc_of_find_child_device(host, func->num);
}

int sdio_add_func(struct sdio_func *func)
{
	int ret;

	dev_set_name(&func->dev, "%s:%d", mmc_card_id(func->card), func->num);

	sdio_set_of_node(func);
	sdio_acpi_set_handle(func);
	device_enable_async_suspend(&func->dev);
	ret = device_add(&func->dev);
	if (ret == 0)
		sdio_func_set_present(func);

	return ret;
}

void sdio_remove_func(struct sdio_func *func)
{
	if (!sdio_func_present(func))
		return;

	device_del(&func->dev);
	of_node_put(func->dev.of_node);
	put_device(&func->dev);
}

