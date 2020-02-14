#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct sdw_slave_id {int /*<<< orphan*/  unique_id; int /*<<< orphan*/  class_id; int /*<<< orphan*/  part_id; int /*<<< orphan*/  mfg_id; } ;
struct TYPE_4__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * bus; struct fwnode_handle* fwnode; int /*<<< orphan*/  parent; } ;
struct sdw_slave {TYPE_1__ dev; int /*<<< orphan*/  node; scalar_t__ dev_num; int /*<<< orphan*/  status; struct sdw_bus* bus; int /*<<< orphan*/  id; } ;
struct sdw_bus {int /*<<< orphan*/  bus_lock; int /*<<< orphan*/  dev; int /*<<< orphan*/  slaves; int /*<<< orphan*/  link_id; } ;
struct fwnode_handle {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SDW_SLAVE_UNATTACHED ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_1__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sdw_slave* dev_to_sdw_dev (struct device*) ; 
 int device_register (TYPE_1__*) ; 
 int /*<<< orphan*/  kfree (struct sdw_slave*) ; 
 struct sdw_slave* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct sdw_slave_id*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_device (TYPE_1__*) ; 
 int /*<<< orphan*/  sdw_bus_type ; 
 int sdw_read (struct sdw_slave*,int /*<<< orphan*/ ) ; 
 int sdw_write (struct sdw_slave*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int sdw_acpi_find_slaves(struct sdw_bus *bus)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int
sdw_update(struct sdw_slave *slave, u32 addr, u8 mask, u8 val)
{
	int tmp;

	tmp = sdw_read(slave, addr);
	if (tmp < 0)
		return tmp;

	tmp = (tmp & ~mask) | val;
	return sdw_write(slave, addr, tmp);
}

__attribute__((used)) static void sdw_slave_release(struct device *dev)
{
	struct sdw_slave *slave = dev_to_sdw_dev(dev);

	kfree(slave);
}

__attribute__((used)) static int sdw_slave_add(struct sdw_bus *bus,
		struct sdw_slave_id *id, struct fwnode_handle *fwnode)
{
	struct sdw_slave *slave;
	int ret;

	slave = kzalloc(sizeof(*slave), GFP_KERNEL);
	if (!slave)
		return -ENOMEM;

	/* Initialize data structure */
	memcpy(&slave->id, id, sizeof(*id));
	slave->dev.parent = bus->dev;
	slave->dev.fwnode = fwnode;

	/* name shall be sdw:link:mfg:part:class:unique */
	dev_set_name(&slave->dev, "sdw:%x:%x:%x:%x:%x",
			bus->link_id, id->mfg_id, id->part_id,
			id->class_id, id->unique_id);

	slave->dev.release = sdw_slave_release;
	slave->dev.bus = &sdw_bus_type;
	slave->bus = bus;
	slave->status = SDW_SLAVE_UNATTACHED;
	slave->dev_num = 0;

	mutex_lock(&bus->bus_lock);
	list_add_tail(&slave->node, &bus->slaves);
	mutex_unlock(&bus->bus_lock);

	ret = device_register(&slave->dev);
	if (ret) {
		dev_err(bus->dev, "Failed to add slave: ret %d\n", ret);

		/*
		 * On err, don't free but drop ref as this will be freed
		 * when release method is invoked.
		 */
		mutex_lock(&bus->bus_lock);
		list_del(&slave->node);
		mutex_unlock(&bus->bus_lock);
		put_device(&slave->dev);
	}

	return ret;
}

