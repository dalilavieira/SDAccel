#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int /*<<< orphan*/  vm_page_prot; int /*<<< orphan*/  vm_start; int /*<<< orphan*/ * vm_ops; } ;
struct resource {unsigned long start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct bcm2835_gpiomem_instance {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  owner; } ;
struct TYPE_8__ {unsigned long gpio_regs_phys; struct device* dev; } ;

/* Variables and functions */
 int DEVICE_MINOR ; 
 int /*<<< orphan*/  DEVICE_NAME ; 
 int EAGAIN ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (void*) ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int alloc_chrdev_region (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 TYPE_4__ bcm2835_gpiomem_cdev ; 
 void* bcm2835_gpiomem_class ; 
 void* bcm2835_gpiomem_dev ; 
 int /*<<< orphan*/  bcm2835_gpiomem_devid ; 
 int /*<<< orphan*/  bcm2835_gpiomem_fops ; 
 int /*<<< orphan*/  bcm2835_gpiomem_vm_ops ; 
 int cdev_add (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cdev_del (TYPE_4__*) ; 
 int /*<<< orphan*/  cdev_init (TYPE_4__*,int /*<<< orphan*/ *) ; 
 void* class_create (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  class_destroy (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 void* device_create (void*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  device_destroy (void*,int /*<<< orphan*/ ) ; 
 int iminor (struct inode*) ; 
 TYPE_1__* inst ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 TYPE_1__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phys_mem_access_prot (struct file*,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ remap_pfn_range (struct vm_area_struct*,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_chrdev_region (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int bcm2835_gpiomem_open(struct inode *inode, struct file *file)
{
	int dev = iminor(inode);
	int ret = 0;

	if (dev != DEVICE_MINOR) {
		dev_err(inst->dev, "Unknown minor device: %d", dev);
		ret = -ENXIO;
	}
	return ret;
}

__attribute__((used)) static int bcm2835_gpiomem_release(struct inode *inode, struct file *file)
{
	int dev = iminor(inode);
	int ret = 0;

	if (dev != DEVICE_MINOR) {
		dev_err(inst->dev, "Unknown minor device %d", dev);
		ret = -ENXIO;
	}
	return ret;
}

__attribute__((used)) static int bcm2835_gpiomem_mmap(struct file *file, struct vm_area_struct *vma)
{
	/* Ignore what the user says - they're getting the GPIO regs
	   whether they like it or not! */
	unsigned long gpio_page = inst->gpio_regs_phys >> PAGE_SHIFT;

	vma->vm_page_prot = phys_mem_access_prot(file, gpio_page,
						 PAGE_SIZE,
						 vma->vm_page_prot);
	vma->vm_ops = &bcm2835_gpiomem_vm_ops;
	if (remap_pfn_range(vma, vma->vm_start,
			gpio_page,
			PAGE_SIZE,
			vma->vm_page_prot)) {
		return -EAGAIN;
	}
	return 0;
}

__attribute__((used)) static int bcm2835_gpiomem_probe(struct platform_device *pdev)
{
	int err;
	void *ptr_err;
	struct device *dev = &pdev->dev;
	struct resource *ioresource;

	/* Allocate buffers and instance data */

	inst = kzalloc(sizeof(struct bcm2835_gpiomem_instance), GFP_KERNEL);

	if (!inst) {
		err = -ENOMEM;
		goto failed_inst_alloc;
	}

	inst->dev = dev;

	ioresource = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (ioresource) {
		inst->gpio_regs_phys = ioresource->start;
	} else {
		dev_err(inst->dev, "failed to get IO resource");
		err = -ENOENT;
		goto failed_get_resource;
	}

	/* Create character device entries */

	err = alloc_chrdev_region(&bcm2835_gpiomem_devid,
				  DEVICE_MINOR, 1, DEVICE_NAME);
	if (err != 0) {
		dev_err(inst->dev, "unable to allocate device number");
		goto failed_alloc_chrdev;
	}
	cdev_init(&bcm2835_gpiomem_cdev, &bcm2835_gpiomem_fops);
	bcm2835_gpiomem_cdev.owner = THIS_MODULE;
	err = cdev_add(&bcm2835_gpiomem_cdev, bcm2835_gpiomem_devid, 1);
	if (err != 0) {
		dev_err(inst->dev, "unable to register device");
		goto failed_cdev_add;
	}

	/* Create sysfs entries */

	bcm2835_gpiomem_class = class_create(THIS_MODULE, DEVICE_NAME);
	ptr_err = bcm2835_gpiomem_class;
	if (IS_ERR(ptr_err))
		goto failed_class_create;

	bcm2835_gpiomem_dev = device_create(bcm2835_gpiomem_class, NULL,
					bcm2835_gpiomem_devid, NULL,
					"gpiomem");
	ptr_err = bcm2835_gpiomem_dev;
	if (IS_ERR(ptr_err))
		goto failed_device_create;

	dev_info(inst->dev, "Initialised: Registers at 0x%08lx",
		inst->gpio_regs_phys);

	return 0;

failed_device_create:
	class_destroy(bcm2835_gpiomem_class);
failed_class_create:
	cdev_del(&bcm2835_gpiomem_cdev);
	err = PTR_ERR(ptr_err);
failed_cdev_add:
	unregister_chrdev_region(bcm2835_gpiomem_devid, 1);
failed_alloc_chrdev:
failed_get_resource:
	kfree(inst);
failed_inst_alloc:
	dev_err(inst->dev, "could not load bcm2835_gpiomem");
	return err;
}

__attribute__((used)) static int bcm2835_gpiomem_remove(struct platform_device *pdev)
{
	struct device *dev = inst->dev;

	kfree(inst);
	device_destroy(bcm2835_gpiomem_class, bcm2835_gpiomem_devid);
	class_destroy(bcm2835_gpiomem_class);
	cdev_del(&bcm2835_gpiomem_cdev);
	unregister_chrdev_region(bcm2835_gpiomem_devid, 1);

	dev_info(dev, "GPIO mem driver removed - OK");
	return 0;
}

