#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct ulpi_ops {int (* read ) (struct device*,int) ;int (* write ) (struct device*,int,int) ;} ;
struct TYPE_14__ {int /*<<< orphan*/ * bus; struct module* owner; } ;
struct ulpi_driver {int (* probe ) (struct ulpi*) ;TYPE_4__ driver; int /*<<< orphan*/  (* remove ) (struct ulpi*) ;struct ulpi_device_id* id_table; } ;
struct ulpi_device_id {scalar_t__ vendor; scalar_t__ product; } ;
struct TYPE_13__ {struct device_node* of_node; int /*<<< orphan*/ * type; int /*<<< orphan*/ * bus; struct device* parent; } ;
struct TYPE_12__ {scalar_t__ vendor; scalar_t__ product; } ;
struct ulpi {TYPE_3__ dev; struct ulpi_ops const* ops; TYPE_2__ id; } ;
struct module {int dummy; } ;
struct kobj_uevent_env {int dummy; } ;
struct device_node {int dummy; } ;
struct device_driver {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {TYPE_1__* parent; scalar_t__ of_node; struct device_driver* driver; } ;
typedef  int ssize_t ;
struct TYPE_11__ {scalar_t__ of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_COMPANION (struct device*) ; 
 int /*<<< orphan*/  ACPI_COMPANION_SET (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ulpi* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int ULPI_PRODUCT_ID_HIGH ; 
 int ULPI_PRODUCT_ID_LOW ; 
 int ULPI_SCRATCH ; 
 int ULPI_VENDOR_ID_HIGH ; 
 int ULPI_VENDOR_ID_LOW ; 
 scalar_t__ add_uevent_var (struct kobj_uevent_env*,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_3__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_3__*) ; 
 int /*<<< orphan*/  device_unregister (TYPE_3__*) ; 
 int driver_register (TYPE_4__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_4__*) ; 
 int /*<<< orphan*/  kfree (struct ulpi*) ; 
 struct ulpi* kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_clk_set_defaults (scalar_t__,int) ; 
 int of_device_modalias (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_device_request_module (TYPE_3__*) ; 
 int of_device_uevent_modalias (struct device*,struct kobj_uevent_env*) ; 
 int of_driver_match_device (struct device*,struct device_driver*) ; 
 struct device_node* of_get_child_by_name (scalar_t__,char*) ; 
 struct device_node* of_get_next_available_child (struct device_node*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  request_module (char*,int,scalar_t__) ; 
 int sprintf (char*,char*,scalar_t__,scalar_t__) ; 
 int stub1 (struct device*,int) ; 
 int stub2 (struct device*,int,int) ; 
 int stub3 (struct ulpi*) ; 
 int /*<<< orphan*/  stub4 (struct ulpi*) ; 
 struct ulpi* to_ulpi_dev (struct device*) ; 
 struct ulpi_driver* to_ulpi_driver (struct device_driver*) ; 
 int /*<<< orphan*/  ulpi_bus ; 
 int /*<<< orphan*/  ulpi_dev_type ; 

int ulpi_read(struct ulpi *ulpi, u8 addr)
{
	return ulpi->ops->read(ulpi->dev.parent, addr);
}

int ulpi_write(struct ulpi *ulpi, u8 addr, u8 val)
{
	return ulpi->ops->write(ulpi->dev.parent, addr, val);
}

__attribute__((used)) static int ulpi_match(struct device *dev, struct device_driver *driver)
{
	struct ulpi_driver *drv = to_ulpi_driver(driver);
	struct ulpi *ulpi = to_ulpi_dev(dev);
	const struct ulpi_device_id *id;

	/* Some ULPI devices don't have a vendor id so rely on OF match */
	if (ulpi->id.vendor == 0)
		return of_driver_match_device(dev, driver);

	for (id = drv->id_table; id->vendor; id++)
		if (id->vendor == ulpi->id.vendor &&
		    id->product == ulpi->id.product)
			return 1;

	return 0;
}

__attribute__((used)) static int ulpi_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	struct ulpi *ulpi = to_ulpi_dev(dev);
	int ret;

	ret = of_device_uevent_modalias(dev, env);
	if (ret != -ENODEV)
		return ret;

	if (add_uevent_var(env, "MODALIAS=ulpi:v%04xp%04x",
			   ulpi->id.vendor, ulpi->id.product))
		return -ENOMEM;
	return 0;
}

__attribute__((used)) static int ulpi_probe(struct device *dev)
{
	struct ulpi_driver *drv = to_ulpi_driver(dev->driver);
	int ret;

	ret = of_clk_set_defaults(dev->of_node, false);
	if (ret < 0)
		return ret;

	return drv->probe(to_ulpi_dev(dev));
}

__attribute__((used)) static int ulpi_remove(struct device *dev)
{
	struct ulpi_driver *drv = to_ulpi_driver(dev->driver);

	if (drv->remove)
		drv->remove(to_ulpi_dev(dev));

	return 0;
}

__attribute__((used)) static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	int len;
	struct ulpi *ulpi = to_ulpi_dev(dev);

	len = of_device_modalias(dev, buf, PAGE_SIZE);
	if (len != -ENODEV)
		return len;

	return sprintf(buf, "ulpi:v%04xp%04x\n",
		       ulpi->id.vendor, ulpi->id.product);
}

__attribute__((used)) static void ulpi_dev_release(struct device *dev)
{
	kfree(to_ulpi_dev(dev));
}

int __ulpi_register_driver(struct ulpi_driver *drv, struct module *module)
{
	if (!drv->probe)
		return -EINVAL;

	drv->driver.owner = module;
	drv->driver.bus = &ulpi_bus;

	return driver_register(&drv->driver);
}

void ulpi_unregister_driver(struct ulpi_driver *drv)
{
	driver_unregister(&drv->driver);
}

__attribute__((used)) static int ulpi_of_register(struct ulpi *ulpi)
{
	struct device_node *np = NULL, *child;
	struct device *parent;

	/* Find a ulpi bus underneath the parent or the grandparent */
	parent = ulpi->dev.parent;
	if (parent->of_node)
		np = of_get_child_by_name(parent->of_node, "ulpi");
	else if (parent->parent && parent->parent->of_node)
		np = of_get_child_by_name(parent->parent->of_node, "ulpi");
	if (!np)
		return 0;

	child = of_get_next_available_child(np, NULL);
	of_node_put(np);
	if (!child)
		return -EINVAL;

	ulpi->dev.of_node = child;

	return 0;
}

__attribute__((used)) static int ulpi_read_id(struct ulpi *ulpi)
{
	int ret;

	/* Test the interface */
	ret = ulpi_write(ulpi, ULPI_SCRATCH, 0xaa);
	if (ret < 0)
		goto err;

	ret = ulpi_read(ulpi, ULPI_SCRATCH);
	if (ret < 0)
		return ret;

	if (ret != 0xaa)
		goto err;

	ulpi->id.vendor = ulpi_read(ulpi, ULPI_VENDOR_ID_LOW);
	ulpi->id.vendor |= ulpi_read(ulpi, ULPI_VENDOR_ID_HIGH) << 8;

	ulpi->id.product = ulpi_read(ulpi, ULPI_PRODUCT_ID_LOW);
	ulpi->id.product |= ulpi_read(ulpi, ULPI_PRODUCT_ID_HIGH) << 8;

	/* Some ULPI devices don't have a vendor id so rely on OF match */
	if (ulpi->id.vendor == 0)
		goto err;

	request_module("ulpi:v%04xp%04x", ulpi->id.vendor, ulpi->id.product);
	return 0;
err:
	of_device_request_module(&ulpi->dev);
	return 0;
}

__attribute__((used)) static int ulpi_register(struct device *dev, struct ulpi *ulpi)
{
	int ret;

	ulpi->dev.parent = dev; /* needed early for ops */
	ulpi->dev.bus = &ulpi_bus;
	ulpi->dev.type = &ulpi_dev_type;
	dev_set_name(&ulpi->dev, "%s.ulpi", dev_name(dev));

	ACPI_COMPANION_SET(&ulpi->dev, ACPI_COMPANION(dev));

	ret = ulpi_of_register(ulpi);
	if (ret)
		return ret;

	ret = ulpi_read_id(ulpi);
	if (ret)
		return ret;

	ret = device_register(&ulpi->dev);
	if (ret)
		return ret;

	dev_dbg(&ulpi->dev, "registered ULPI PHY: vendor %04x, product %04x\n",
		ulpi->id.vendor, ulpi->id.product);

	return 0;
}

struct ulpi *ulpi_register_interface(struct device *dev,
				     const struct ulpi_ops *ops)
{
	struct ulpi *ulpi;
	int ret;

	ulpi = kzalloc(sizeof(*ulpi), GFP_KERNEL);
	if (!ulpi)
		return ERR_PTR(-ENOMEM);

	ulpi->ops = ops;

	ret = ulpi_register(dev, ulpi);
	if (ret) {
		kfree(ulpi);
		return ERR_PTR(ret);
	}

	return ulpi;
}

void ulpi_unregister_interface(struct ulpi *ulpi)
{
	of_node_put(ulpi->dev.of_node);
	device_unregister(&ulpi->dev);
}

