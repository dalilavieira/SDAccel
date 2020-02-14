#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vm_fault_t ;
struct vm_fault {unsigned long pgoff; int /*<<< orphan*/  address; struct vm_area_struct* vma; } ;
struct vm_area_struct {unsigned long vm_pgoff; int vm_flags; struct ocxl_afu* vm_private_data; int /*<<< orphan*/ * vm_ops; int /*<<< orphan*/  vm_page_prot; } ;
struct TYPE_6__ {char* name; int mode; } ;
struct TYPE_7__ {unsigned long size; size_t (* read ) (struct file*,struct kobject*,struct bin_attribute*,char*,scalar_t__,size_t) ;int (* mmap ) (struct file*,struct kobject*,struct bin_attribute*,struct vm_area_struct*) ;TYPE_2__ attr; } ;
struct TYPE_5__ {scalar_t__ global_mmio_size; int /*<<< orphan*/  version_minor; int /*<<< orphan*/  version_major; int /*<<< orphan*/  pp_mmio_stride; } ;
struct ocxl_afu {scalar_t__ global_mmio_ptr; unsigned long global_mmio_start; TYPE_3__ attr_global_mmio; int /*<<< orphan*/  dev; TYPE_1__ config; int /*<<< orphan*/  pasid_max; int /*<<< orphan*/  pasid_count; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  VM_FAULT_SIGBUS ; 
 int VM_IO ; 
 int VM_PFNMAP ; 
 int /*<<< orphan*/ * afu_attrs ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int device_create_bin_file (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_bin_file (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  global_mmio_vmops ; 
 struct device* kobj_to_dev (struct kobject*) ; 
 int /*<<< orphan*/  memcpy_fromio (char*,scalar_t__,size_t) ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 size_t scnprintf (char*,int /*<<< orphan*/ ,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  sysfs_attr_init (TYPE_2__*) ; 
 struct ocxl_afu* to_ocxl_afu (struct device*) ; 
 unsigned long vma_pages (struct vm_area_struct*) ; 
 int /*<<< orphan*/  vmf_insert_pfn (struct vm_area_struct*,int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static ssize_t global_mmio_size_show(struct device *device,
				struct device_attribute *attr,
				char *buf)
{
	struct ocxl_afu *afu = to_ocxl_afu(device);

	return scnprintf(buf, PAGE_SIZE, "%d\n",
			afu->config.global_mmio_size);
}

__attribute__((used)) static ssize_t pp_mmio_size_show(struct device *device,
				struct device_attribute *attr,
				char *buf)
{
	struct ocxl_afu *afu = to_ocxl_afu(device);

	return scnprintf(buf, PAGE_SIZE, "%d\n",
			afu->config.pp_mmio_stride);
}

__attribute__((used)) static ssize_t afu_version_show(struct device *device,
				struct device_attribute *attr,
				char *buf)
{
	struct ocxl_afu *afu = to_ocxl_afu(device);

	return scnprintf(buf, PAGE_SIZE, "%hhu:%hhu\n",
			afu->config.version_major,
			afu->config.version_minor);
}

__attribute__((used)) static ssize_t contexts_show(struct device *device,
		struct device_attribute *attr,
		char *buf)
{
	struct ocxl_afu *afu = to_ocxl_afu(device);

	return scnprintf(buf, PAGE_SIZE, "%d/%d\n",
			afu->pasid_count, afu->pasid_max);
}

__attribute__((used)) static ssize_t global_mmio_read(struct file *filp, struct kobject *kobj,
				struct bin_attribute *bin_attr, char *buf,
				loff_t off, size_t count)
{
	struct ocxl_afu *afu = to_ocxl_afu(kobj_to_dev(kobj));

	if (count == 0 || off < 0 ||
		off >= afu->config.global_mmio_size)
		return 0;
	memcpy_fromio(buf, afu->global_mmio_ptr + off, count);
	return count;
}

__attribute__((used)) static vm_fault_t global_mmio_fault(struct vm_fault *vmf)
{
	struct vm_area_struct *vma = vmf->vma;
	struct ocxl_afu *afu = vma->vm_private_data;
	unsigned long offset;

	if (vmf->pgoff >= (afu->config.global_mmio_size >> PAGE_SHIFT))
		return VM_FAULT_SIGBUS;

	offset = vmf->pgoff;
	offset += (afu->global_mmio_start >> PAGE_SHIFT);
	return vmf_insert_pfn(vma, vmf->address, offset);
}

__attribute__((used)) static int global_mmio_mmap(struct file *filp, struct kobject *kobj,
			struct bin_attribute *bin_attr,
			struct vm_area_struct *vma)
{
	struct ocxl_afu *afu = to_ocxl_afu(kobj_to_dev(kobj));

	if ((vma_pages(vma) + vma->vm_pgoff) >
		(afu->config.global_mmio_size >> PAGE_SHIFT))
		return -EINVAL;

	vma->vm_flags |= VM_IO | VM_PFNMAP;
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	vma->vm_ops = &global_mmio_vmops;
	vma->vm_private_data = afu;
	return 0;
}

int ocxl_sysfs_add_afu(struct ocxl_afu *afu)
{
	int i, rc;

	for (i = 0; i < ARRAY_SIZE(afu_attrs); i++) {
		rc = device_create_file(&afu->dev, &afu_attrs[i]);
		if (rc)
			goto err;
	}

	sysfs_attr_init(&afu->attr_global_mmio.attr);
	afu->attr_global_mmio.attr.name = "global_mmio_area";
	afu->attr_global_mmio.attr.mode = 0600;
	afu->attr_global_mmio.size = afu->config.global_mmio_size;
	afu->attr_global_mmio.read = global_mmio_read;
	afu->attr_global_mmio.mmap = global_mmio_mmap;
	rc = device_create_bin_file(&afu->dev, &afu->attr_global_mmio);
	if (rc) {
		dev_err(&afu->dev,
			"Unable to create global mmio attr for afu: %d\n",
			rc);
		goto err;
	}

	return 0;

err:
	for (i--; i >= 0; i--)
		device_remove_file(&afu->dev, &afu_attrs[i]);
	return rc;
}

void ocxl_sysfs_remove_afu(struct ocxl_afu *afu)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(afu_attrs); i++)
		device_remove_file(&afu->dev, &afu_attrs[i]);
	device_remove_bin_file(&afu->dev, &afu->attr_global_mmio);
}

