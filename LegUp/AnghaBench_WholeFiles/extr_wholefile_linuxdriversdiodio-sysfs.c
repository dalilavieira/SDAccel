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
struct device {int dummy; } ;
struct dio_dev {int id; int ipl; char* name; struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  dev_attr_id ; 
 int /*<<< orphan*/  dev_attr_ipl ; 
 int /*<<< orphan*/  dev_attr_name ; 
 int /*<<< orphan*/  dev_attr_resource ; 
 int /*<<< orphan*/  dev_attr_secid ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ dio_resource_end (struct dio_dev*) ; 
 int /*<<< orphan*/  dio_resource_flags (struct dio_dev*) ; 
 scalar_t__ dio_resource_start (struct dio_dev*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 struct dio_dev* to_dio_dev (struct device*) ; 

__attribute__((used)) static ssize_t dio_show_id(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dio_dev *d;

	d = to_dio_dev(dev);
	return sprintf(buf, "0x%02x\n", (d->id & 0xff));
}

__attribute__((used)) static ssize_t dio_show_ipl(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dio_dev *d;

	d = to_dio_dev(dev);
	return sprintf(buf, "0x%02x\n", d->ipl);
}

__attribute__((used)) static ssize_t dio_show_secid(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dio_dev *d;

	d = to_dio_dev(dev);
	return sprintf(buf, "0x%02x\n", ((d->id >> 8)& 0xff));
}

__attribute__((used)) static ssize_t dio_show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dio_dev *d;

	d = to_dio_dev(dev);
	return sprintf(buf, "%s\n", d->name);
}

__attribute__((used)) static ssize_t dio_show_resource(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dio_dev *d = to_dio_dev(dev);

	return sprintf(buf, "0x%08lx 0x%08lx 0x%08lx\n",
		       (unsigned long)dio_resource_start(d),
		       (unsigned long)dio_resource_end(d),
		       dio_resource_flags(d));
}

int dio_create_sysfs_dev_files(struct dio_dev *d)
{
	struct device *dev = &d->dev;
	int error;

	/* current configuration's attributes */
	if ((error = device_create_file(dev, &dev_attr_id)) ||
	    (error = device_create_file(dev, &dev_attr_ipl)) ||
	    (error = device_create_file(dev, &dev_attr_secid)) ||
	    (error = device_create_file(dev, &dev_attr_name)) ||
	    (error = device_create_file(dev, &dev_attr_resource)))
		return error;

	return 0;
}

