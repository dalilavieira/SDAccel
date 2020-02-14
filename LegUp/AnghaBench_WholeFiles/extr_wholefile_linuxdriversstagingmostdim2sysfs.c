#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  groups; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  dev_attr_groups ; 
 int device_register (struct device*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int dim2_sysfs_get_state_cb () ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

__attribute__((used)) static ssize_t state_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	bool state = dim2_sysfs_get_state_cb();

	return sprintf(buf, "%s\n", state ? "locked" : "");
}

int dim2_sysfs_probe(struct device *dev)
{
	dev->groups = dev_attr_groups;
	return device_register(dev);
}

void dim2_sysfs_destroy(struct device *dev)
{
	device_unregister(dev);
}

