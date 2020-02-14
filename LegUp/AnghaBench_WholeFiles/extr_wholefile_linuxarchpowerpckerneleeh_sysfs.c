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
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  sd; } ;
struct TYPE_10__ {TYPE_1__ kobj; } ;
struct pci_dev {TYPE_5__ dev; } ;
struct eeh_dev {int mode; TYPE_2__* pe; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_9__ {int (* get_state ) (TYPE_2__*,int /*<<< orphan*/ *) ;} ;
struct TYPE_8__ {int state; } ;

/* Variables and functions */
 int EEH_DEV_SYSFS ; 
 int EEH_PE_ISOLATED ; 
 size_t EIO ; 
 size_t ENODEV ; 
 int /*<<< orphan*/  dev_attr_eeh_mode ; 
 int /*<<< orphan*/  dev_attr_eeh_pe_config_addr ; 
 int /*<<< orphan*/  dev_attr_eeh_pe_state ; 
 scalar_t__ device_create_file (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  eeh_enabled () ; 
 TYPE_4__* eeh_ops ; 
 scalar_t__ eeh_unfreeze_pe (TYPE_2__*,int) ; 
 struct eeh_dev* pci_dev_to_eeh_dev (struct pci_dev*) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 size_t sprintf (char*,char*,int,int) ; 
 int stub1 (TYPE_2__*,int /*<<< orphan*/ *) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 

__attribute__((used)) static ssize_t eeh_pe_state_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
	int state;

	if (!edev || !edev->pe)
		return -ENODEV;

	state = eeh_ops->get_state(edev->pe, NULL);
	return sprintf(buf, "0x%08x 0x%08x\n",
		       state, edev->pe->state);
}

__attribute__((used)) static ssize_t eeh_pe_state_store(struct device *dev,
				  struct device_attribute *attr,
				  const char *buf, size_t count)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);

	if (!edev || !edev->pe)
		return -ENODEV;

	/* Nothing to do if it's not frozen */
	if (!(edev->pe->state & EEH_PE_ISOLATED))
		return count;

	if (eeh_unfreeze_pe(edev->pe, true))
		return -EIO;

	return count;
}

__attribute__((used)) static inline int eeh_notify_resume_add(struct pci_dev *pdev) { return 0; }

__attribute__((used)) static inline void eeh_notify_resume_remove(struct pci_dev *pdev) { }

void eeh_sysfs_add_device(struct pci_dev *pdev)
{
	struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
	int rc=0;

	if (!eeh_enabled())
		return;

	if (edev && (edev->mode & EEH_DEV_SYSFS))
		return;

	rc += device_create_file(&pdev->dev, &dev_attr_eeh_mode);
	rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
	rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_state);
	rc += eeh_notify_resume_add(pdev);

	if (rc)
		pr_warn("EEH: Unable to create sysfs entries\n");
	else if (edev)
		edev->mode |= EEH_DEV_SYSFS;
}

void eeh_sysfs_remove_device(struct pci_dev *pdev)
{
	struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);

	/*
	 * The parent directory might have been removed. We needn't
	 * continue for that case.
	 */
	if (!pdev->dev.kobj.sd) {
		if (edev)
			edev->mode &= ~EEH_DEV_SYSFS;
		return;
	}

	device_remove_file(&pdev->dev, &dev_attr_eeh_mode);
	device_remove_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
	device_remove_file(&pdev->dev, &dev_attr_eeh_pe_state);

	eeh_notify_resume_remove(pdev);

	if (edev)
		edev->mode &= ~EEH_DEV_SYSFS;
}

