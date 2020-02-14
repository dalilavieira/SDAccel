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
struct module {int dummy; } ;
struct TYPE_3__ {struct module* owner; int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct mdev_driver {int (* probe ) (struct device*) ;TYPE_1__ driver; int /*<<< orphan*/  name; int /*<<< orphan*/  (* remove ) (struct device*) ;} ;
struct mdev_device {int /*<<< orphan*/  dev; } ;
struct iommu_group {int dummy; } ;
struct device {int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct iommu_group*) ; 
 int PTR_ERR (struct iommu_group*) ; 
 int bus_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int driver_register (TYPE_1__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_1__*) ; 
 int iommu_group_add_device (struct iommu_group*,int /*<<< orphan*/ *) ; 
 struct iommu_group* iommu_group_alloc () ; 
 int /*<<< orphan*/  iommu_group_id (struct iommu_group*) ; 
 int /*<<< orphan*/  iommu_group_put (struct iommu_group*) ; 
 int /*<<< orphan*/  iommu_group_remove_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mdev_bus_type ; 
 int stub1 (struct device*) ; 
 int /*<<< orphan*/  stub2 (struct device*) ; 
 struct mdev_device* to_mdev_device (struct device*) ; 
 struct mdev_driver* to_mdev_driver (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mdev_attach_iommu(struct mdev_device *mdev)
{
	int ret;
	struct iommu_group *group;

	group = iommu_group_alloc();
	if (IS_ERR(group))
		return PTR_ERR(group);

	ret = iommu_group_add_device(group, &mdev->dev);
	if (!ret)
		dev_info(&mdev->dev, "MDEV: group_id = %d\n",
			 iommu_group_id(group));

	iommu_group_put(group);
	return ret;
}

__attribute__((used)) static void mdev_detach_iommu(struct mdev_device *mdev)
{
	iommu_group_remove_device(&mdev->dev);
	dev_info(&mdev->dev, "MDEV: detaching iommu\n");
}

__attribute__((used)) static int mdev_probe(struct device *dev)
{
	struct mdev_driver *drv = to_mdev_driver(dev->driver);
	struct mdev_device *mdev = to_mdev_device(dev);
	int ret;

	ret = mdev_attach_iommu(mdev);
	if (ret)
		return ret;

	if (drv && drv->probe) {
		ret = drv->probe(dev);
		if (ret)
			mdev_detach_iommu(mdev);
	}

	return ret;
}

__attribute__((used)) static int mdev_remove(struct device *dev)
{
	struct mdev_driver *drv = to_mdev_driver(dev->driver);
	struct mdev_device *mdev = to_mdev_device(dev);

	if (drv && drv->remove)
		drv->remove(dev);

	mdev_detach_iommu(mdev);

	return 0;
}

int mdev_register_driver(struct mdev_driver *drv, struct module *owner)
{
	/* initialize common driver fields */
	drv->driver.name = drv->name;
	drv->driver.bus = &mdev_bus_type;
	drv->driver.owner = owner;

	/* register with core */
	return driver_register(&drv->driver);
}

void mdev_unregister_driver(struct mdev_driver *drv)
{
	driver_unregister(&drv->driver);
}

int mdev_bus_register(void)
{
	return bus_register(&mdev_bus_type);
}

void mdev_bus_unregister(void)
{
	bus_unregister(&mdev_bus_type);
}

