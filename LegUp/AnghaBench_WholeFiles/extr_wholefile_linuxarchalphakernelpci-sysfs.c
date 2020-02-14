#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct vm_area_struct {unsigned long vm_pgoff; int /*<<< orphan*/  vm_page_prot; scalar_t__ vm_start; scalar_t__ vm_end; } ;
struct resource {int flags; int /*<<< orphan*/  start; } ;
struct TYPE_10__ {int /*<<< orphan*/  kobj; } ;
struct pci_dev {struct bin_attribute** res_attr_wc; struct bin_attribute** res_attr; struct resource* resource; struct pci_controller* sysdata; TYPE_2__ dev; int /*<<< orphan*/  bus; } ;
struct pci_controller {unsigned long sparse_mem_base; unsigned long dense_mem_base; unsigned long sparse_io_base; unsigned long dense_io_base; TYPE_7__* io_space; int /*<<< orphan*/  index; } ;
struct pci_bus_region {unsigned long start; unsigned long end; } ;
struct pci_bus {struct pci_controller* sysdata; TYPE_6__* legacy_io; TYPE_4__* legacy_mem; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_9__ {char* name; int mode; } ;
struct bin_attribute {int (* mmap ) (struct file*,struct kobject*,struct bin_attribute*,struct vm_area_struct*) ;size_t size; struct resource* private; TYPE_1__ attr; } ;
typedef  int loff_t ;
typedef  enum pci_mmap_state { ____Placeholder_pci_mmap_state } pci_mmap_state ;
struct TYPE_16__ {int /*<<< orphan*/  comm; } ;
struct TYPE_15__ {scalar_t__ start; } ;
struct TYPE_13__ {char* name; } ;
struct TYPE_14__ {unsigned long size; TYPE_5__ attr; } ;
struct TYPE_11__ {char* name; } ;
struct TYPE_12__ {unsigned long size; TYPE_3__ attr; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int IORESOURCE_MEM ; 
 unsigned long PAGE_SHIFT ; 
 int PCI_ROM_RESOURCE ; 
 int S_IRUSR ; 
 int S_IWUSR ; 
 int /*<<< orphan*/  WARN (int,char*,int /*<<< orphan*/ ,char*,unsigned long,unsigned long,int /*<<< orphan*/ ,unsigned long,...) ; 
 TYPE_8__* current ; 
 int /*<<< orphan*/  inb (int) ; 
 int /*<<< orphan*/  inl (int) ; 
 int /*<<< orphan*/  inw (int) ; 
 int io_remap_pfn_range (struct vm_area_struct*,scalar_t__,unsigned long,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ iomem_is_exclusive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct bin_attribute*) ; 
 int /*<<< orphan*/  kobj_to_dev (struct kobject*) ; 
 struct bin_attribute* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outl (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outw (int,int /*<<< orphan*/ ) ; 
 int pci_mmap_io ; 
 int pci_mmap_mem ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 int pci_resource_len (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pcibios_resource_to_bus (int /*<<< orphan*/ ,struct pci_bus_region*,struct resource*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,char*) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,struct bin_attribute*) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,struct bin_attribute*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 unsigned long vma_pages (struct vm_area_struct*) ; 

__attribute__((used)) static int hose_mmap_page_range(struct pci_controller *hose,
				struct vm_area_struct *vma,
				enum pci_mmap_state mmap_type, int sparse)
{
	unsigned long base;

	if (mmap_type == pci_mmap_mem)
		base = sparse ? hose->sparse_mem_base : hose->dense_mem_base;
	else
		base = sparse ? hose->sparse_io_base : hose->dense_io_base;

	vma->vm_pgoff += base >> PAGE_SHIFT;

	return io_remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
				  vma->vm_end - vma->vm_start,
				  vma->vm_page_prot);
}

__attribute__((used)) static int __pci_mmap_fits(struct pci_dev *pdev, int num,
			   struct vm_area_struct *vma, int sparse)
{
	unsigned long nr, start, size;
	int shift = sparse ? 5 : 0;

	nr = vma_pages(vma);
	start = vma->vm_pgoff;
	size = ((pci_resource_len(pdev, num) - 1) >> (PAGE_SHIFT - shift)) + 1;

	if (start < size && size - start >= nr)
		return 1;
	WARN(1, "process \"%s\" tried to map%s 0x%08lx-0x%08lx on %s BAR %d "
		"(size 0x%08lx)\n",
		current->comm, sparse ? " sparse" : "", start, start + nr,
		pci_name(pdev), num, size);
	return 0;
}

__attribute__((used)) static int pci_mmap_resource(struct kobject *kobj,
			     struct bin_attribute *attr,
			     struct vm_area_struct *vma, int sparse)
{
	struct pci_dev *pdev = to_pci_dev(kobj_to_dev(kobj));
	struct resource *res = attr->private;
	enum pci_mmap_state mmap_type;
	struct pci_bus_region bar;
	int i;

	for (i = 0; i < PCI_ROM_RESOURCE; i++)
		if (res == &pdev->resource[i])
			break;
	if (i >= PCI_ROM_RESOURCE)
		return -ENODEV;

	if (res->flags & IORESOURCE_MEM && iomem_is_exclusive(res->start))
		return -EINVAL;

	if (!__pci_mmap_fits(pdev, i, vma, sparse))
		return -EINVAL;

	pcibios_resource_to_bus(pdev->bus, &bar, res);
	vma->vm_pgoff += bar.start >> (PAGE_SHIFT - (sparse ? 5 : 0));
	mmap_type = res->flags & IORESOURCE_MEM ? pci_mmap_mem : pci_mmap_io;

	return hose_mmap_page_range(pdev->sysdata, vma, mmap_type, sparse);
}

__attribute__((used)) static int pci_mmap_resource_sparse(struct file *filp, struct kobject *kobj,
				    struct bin_attribute *attr,
				    struct vm_area_struct *vma)
{
	return pci_mmap_resource(kobj, attr, vma, 1);
}

__attribute__((used)) static int pci_mmap_resource_dense(struct file *filp, struct kobject *kobj,
				   struct bin_attribute *attr,
				   struct vm_area_struct *vma)
{
	return pci_mmap_resource(kobj, attr, vma, 0);
}

void pci_remove_resource_files(struct pci_dev *pdev)
{
	int i;

	for (i = 0; i < PCI_ROM_RESOURCE; i++) {
		struct bin_attribute *res_attr;

		res_attr = pdev->res_attr[i];
		if (res_attr) {
			sysfs_remove_bin_file(&pdev->dev.kobj, res_attr);
			kfree(res_attr);
		}

		res_attr = pdev->res_attr_wc[i];
		if (res_attr) {
			sysfs_remove_bin_file(&pdev->dev.kobj, res_attr);
			kfree(res_attr);
		}
	}
}

__attribute__((used)) static int sparse_mem_mmap_fits(struct pci_dev *pdev, int num)
{
	struct pci_bus_region bar;
	struct pci_controller *hose = pdev->sysdata;
	long dense_offset;
	unsigned long sparse_size;

	pcibios_resource_to_bus(pdev->bus, &bar, &pdev->resource[num]);

	/* All core logic chips have 4G sparse address space, except
	   CIA which has 16G (see xxx_SPARSE_MEM and xxx_DENSE_MEM
	   definitions in asm/core_xxx.h files). This corresponds
	   to 128M or 512M of the bus space. */
	dense_offset = (long)(hose->dense_mem_base - hose->sparse_mem_base);
	sparse_size = dense_offset >= 0x400000000UL ? 0x20000000 : 0x8000000;

	return bar.end < sparse_size;
}

__attribute__((used)) static int pci_create_one_attr(struct pci_dev *pdev, int num, char *name,
			       char *suffix, struct bin_attribute *res_attr,
			       unsigned long sparse)
{
	size_t size = pci_resource_len(pdev, num);

	sprintf(name, "resource%d%s", num, suffix);
	res_attr->mmap = sparse ? pci_mmap_resource_sparse :
				  pci_mmap_resource_dense;
	res_attr->attr.name = name;
	res_attr->attr.mode = S_IRUSR | S_IWUSR;
	res_attr->size = sparse ? size << 5 : size;
	res_attr->private = &pdev->resource[num];
	return sysfs_create_bin_file(&pdev->dev.kobj, res_attr);
}

__attribute__((used)) static int pci_create_attr(struct pci_dev *pdev, int num)
{
	/* allocate attribute structure, piggyback attribute name */
	int retval, nlen1, nlen2 = 0, res_count = 1;
	unsigned long sparse_base, dense_base;
	struct bin_attribute *attr;
	struct pci_controller *hose = pdev->sysdata;
	char *suffix, *attr_name;

	suffix = "";	/* Assume bwx machine, normal resourceN files. */
	nlen1 = 10;

	if (pdev->resource[num].flags & IORESOURCE_MEM) {
		sparse_base = hose->sparse_mem_base;
		dense_base = hose->dense_mem_base;
		if (sparse_base && !sparse_mem_mmap_fits(pdev, num)) {
			sparse_base = 0;
			suffix = "_dense";
			nlen1 = 16;	/* resourceN_dense */
		}
	} else {
		sparse_base = hose->sparse_io_base;
		dense_base = hose->dense_io_base;
	}

	if (sparse_base) {
		suffix = "_sparse";
		nlen1 = 17;
		if (dense_base) {
			nlen2 = 16;	/* resourceN_dense */
			res_count = 2;
		}
	}

	attr = kzalloc(sizeof(*attr) * res_count + nlen1 + nlen2, GFP_ATOMIC);
	if (!attr)
		return -ENOMEM;

	/* Create bwx, sparse or single dense file */
	attr_name = (char *)(attr + res_count);
	pdev->res_attr[num] = attr;
	retval = pci_create_one_attr(pdev, num, attr_name, suffix, attr,
				     sparse_base);
	if (retval || res_count == 1)
		return retval;

	/* Create dense file */
	attr_name += nlen1;
	attr++;
	pdev->res_attr_wc[num] = attr;
	return pci_create_one_attr(pdev, num, attr_name, "_dense", attr, 0);
}

int pci_create_resource_files(struct pci_dev *pdev)
{
	int i;
	int retval;

	/* Expose the PCI resources from this device as files */
	for (i = 0; i < PCI_ROM_RESOURCE; i++) {

		/* skip empty resources */
		if (!pci_resource_len(pdev, i))
			continue;

		retval = pci_create_attr(pdev, i);
		if (retval) {
			pci_remove_resource_files(pdev);
			return retval;
		}
	}
	return 0;
}

__attribute__((used)) static int __legacy_mmap_fits(struct pci_controller *hose,
			      struct vm_area_struct *vma,
			      unsigned long res_size, int sparse)
{
	unsigned long nr, start, size;

	nr = vma_pages(vma);
	start = vma->vm_pgoff;
	size = ((res_size - 1) >> PAGE_SHIFT) + 1;

	if (start < size && size - start >= nr)
		return 1;
	WARN(1, "process \"%s\" tried to map%s 0x%08lx-0x%08lx on hose %d "
		"(size 0x%08lx)\n",
		current->comm, sparse ? " sparse" : "", start, start + nr,
		hose->index, size);
	return 0;
}

__attribute__((used)) static inline int has_sparse(struct pci_controller *hose,
			     enum pci_mmap_state mmap_type)
{
	unsigned long base;

	base = (mmap_type == pci_mmap_mem) ? hose->sparse_mem_base :
					     hose->sparse_io_base;

	return base != 0;
}

int pci_mmap_legacy_page_range(struct pci_bus *bus, struct vm_area_struct *vma,
			       enum pci_mmap_state mmap_type)
{
	struct pci_controller *hose = bus->sysdata;
	int sparse = has_sparse(hose, mmap_type);
	unsigned long res_size;

	res_size = (mmap_type == pci_mmap_mem) ? bus->legacy_mem->size :
						 bus->legacy_io->size;
	if (!__legacy_mmap_fits(hose, vma, res_size, sparse))
		return -EINVAL;

	return hose_mmap_page_range(hose, vma, mmap_type, sparse);
}

void pci_adjust_legacy_attr(struct pci_bus *bus, enum pci_mmap_state mmap_type)
{
	struct pci_controller *hose = bus->sysdata;

	if (!has_sparse(hose, mmap_type))
		return;

	if (mmap_type == pci_mmap_mem) {
		bus->legacy_mem->attr.name = "legacy_mem_sparse";
		bus->legacy_mem->size <<= 5;
	} else {
		bus->legacy_io->attr.name = "legacy_io_sparse";
		bus->legacy_io->size <<= 5;
	}
	return;
}

int pci_legacy_read(struct pci_bus *bus, loff_t port, u32 *val, size_t size)
{
	struct pci_controller *hose = bus->sysdata;

	port += hose->io_space->start;

	switch(size) {
	case 1:
		*((u8 *)val) = inb(port);
		return 1;
	case 2:
		if (port & 1)
			return -EINVAL;
		*((u16 *)val) = inw(port);
		return 2;
	case 4:
		if (port & 3)
			return -EINVAL;
		*((u32 *)val) = inl(port);
		return 4;
	}
	return -EINVAL;
}

int pci_legacy_write(struct pci_bus *bus, loff_t port, u32 val, size_t size)
{
	struct pci_controller *hose = bus->sysdata;

	port += hose->io_space->start;

	switch(size) {
	case 1:
		outb(port, val);
		return 1;
	case 2:
		if (port & 1)
			return -EINVAL;
		outw(port, val);
		return 2;
	case 4:
		if (port & 3)
			return -EINVAL;
		outl(port, val);
		return 4;
	}
	return -EINVAL;
}

