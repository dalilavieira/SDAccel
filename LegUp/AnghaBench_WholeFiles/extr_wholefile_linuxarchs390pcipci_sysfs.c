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
struct zpci_report_error_header {int dummy; } ;
struct zpci_dev {int /*<<< orphan*/  fid; int /*<<< orphan*/  fh; int /*<<< orphan*/  util_str; int /*<<< orphan*/  bus; } ;
struct pci_dev {int dummy; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int /*<<< orphan*/  device_remove_file_self (struct device*,struct device_attribute*) ; 
 struct device* kobj_to_dev (struct kobject*) ; 
 size_t memory_read_from_buffer (char*,size_t,scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_lock_rescan_remove () ; 
 int /*<<< orphan*/  pci_rescan_bus (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_stop_and_remove_bus_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_unlock_rescan_remove () ; 
 int sclp_pci_report (struct zpci_report_error_header*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 
 struct zpci_dev* to_zpci (struct pci_dev*) ; 
 int zpci_disable_device (struct zpci_dev*) ; 
 int zpci_enable_device (struct zpci_dev*) ; 

__attribute__((used)) static ssize_t recover_store(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	struct zpci_dev *zdev = to_zpci(pdev);
	int ret;

	if (!device_remove_file_self(dev, attr))
		return count;

	pci_lock_rescan_remove();
	pci_stop_and_remove_bus_device(pdev);
	ret = zpci_disable_device(zdev);
	if (ret)
		goto error;

	ret = zpci_enable_device(zdev);
	if (ret)
		goto error;

	pci_rescan_bus(zdev->bus);
	pci_unlock_rescan_remove();

	return count;

error:
	pci_unlock_rescan_remove();
	return ret;
}

__attribute__((used)) static ssize_t util_string_read(struct file *filp, struct kobject *kobj,
				struct bin_attribute *attr, char *buf,
				loff_t off, size_t count)
{
	struct device *dev = kobj_to_dev(kobj);
	struct pci_dev *pdev = to_pci_dev(dev);
	struct zpci_dev *zdev = to_zpci(pdev);

	return memory_read_from_buffer(buf, count, &off, zdev->util_str,
				       sizeof(zdev->util_str));
}

__attribute__((used)) static ssize_t report_error_write(struct file *filp, struct kobject *kobj,
				  struct bin_attribute *attr, char *buf,
				  loff_t off, size_t count)
{
	struct zpci_report_error_header *report = (void *) buf;
	struct device *dev = kobj_to_dev(kobj);
	struct pci_dev *pdev = to_pci_dev(dev);
	struct zpci_dev *zdev = to_zpci(pdev);
	int ret;

	if (off || (count < sizeof(*report)))
		return -EINVAL;

	ret = sclp_pci_report(report, zdev->fh, zdev->fid);

	return ret ? ret : count;
}

