#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct vm_area_struct {unsigned long long vm_start; unsigned long long vm_end; } ;
struct TYPE_6__ {scalar_t__ tidr; } ;
struct task_struct {TYPE_3__ thread; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {scalar_t__ id; } ;
struct mm_struct {int /*<<< orphan*/  mmap_sem; TYPE_2__ context; } ;
struct cxllib_xsl_config {scalar_t__ dra; int /*<<< orphan*/  bar_addr; int /*<<< orphan*/  log_bar_size; int /*<<< orphan*/  version; int /*<<< orphan*/  dsnctl; } ;
struct cxllib_pe_attributes {scalar_t__ tid; scalar_t__ pid; int /*<<< orphan*/  lpid; int /*<<< orphan*/  sr; } ;
struct cxl_afu {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct cxl {TYPE_1__ dev; } ;
typedef  enum cxllib_mode { ____Placeholder_cxllib_mode } cxllib_mode ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_FTR_HVMODE ; 
 int /*<<< orphan*/  CXL_CAPI_WINDOW_LOG_SIZE ; 
 int /*<<< orphan*/  CXL_CAPI_WINDOW_START ; 
 unsigned long long CXL_DUMMY_READ_ALIGN ; 
 unsigned long long CXL_DUMMY_READ_SIZE ; 
 scalar_t__ CXL_INVALID_DRA ; 
#define  CXL_MODE_CXL 129 
 unsigned long CXL_MODE_DMA_TVT1 ; 
#define  CXL_MODE_PCI 128 
 unsigned long CXL_REAL_MODE ; 
 unsigned long CXL_TRANSLATED_MODE ; 
 int /*<<< orphan*/  CXL_XSL_CONFIG_CURRENT_VERSION ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int EBUSY ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  OPAL_PHB_CAPI_MODE_DMA_TVT1 ; 
 int /*<<< orphan*/  OPAL_PHB_CAPI_MODE_SNOOP_OFF ; 
 int /*<<< orphan*/  OPAL_PHB_CAPI_MODE_SNOOP_ON ; 
 int /*<<< orphan*/  SPRN_LPID ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ cpu_has_feature (int /*<<< orphan*/ ) ; 
 int cxl_calc_capp_routing (struct pci_dev*,unsigned long long*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  cxl_calculate_sr (int,int /*<<< orphan*/ ,int,int) ; 
 int cxl_get_xsl9_dsnctl (struct pci_dev*,unsigned long long,int /*<<< orphan*/ *) ; 
 int cxl_handle_mm_fault (struct mm_struct*,unsigned long long,unsigned long long) ; 
 int /*<<< orphan*/  cxl_is_power9 () ; 
 scalar_t__ cxl_slot_is_switched (struct pci_dev*) ; 
 int dma_set_mask (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dra_mutex ; 
 scalar_t__ dummy_read_addr ; 
 struct vm_area_struct* find_vma (struct mm_struct*,unsigned long long) ; 
 struct mm_struct* get_task_mm (struct task_struct*) ; 
 scalar_t__ kzalloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmput (struct mm_struct*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_channel_offline (struct pci_dev*) ; 
 int pnv_phb_to_cxl_mode (struct pci_dev*,int /*<<< orphan*/ ) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 
 scalar_t__ virt_to_phys (void*) ; 
 unsigned long vma_kernel_pagesize (struct vm_area_struct*) ; 

__attribute__((used)) static inline bool cxl_adapter_link_ok(struct cxl *cxl, struct cxl_afu *afu)
{
	struct pci_dev *pdev;

	if (cpu_has_feature(CPU_FTR_HVMODE)) {
		pdev = to_pci_dev(cxl->dev.parent);
		return !pci_channel_offline(pdev);
	}
	return true;
}

bool cxllib_slot_is_supported(struct pci_dev *dev, unsigned long flags)
{
	int rc;
	u32 phb_index;
	u64 chip_id, capp_unit_id;

	/* No flags currently supported */
	if (flags)
		return false;

	if (!cpu_has_feature(CPU_FTR_HVMODE))
		return false;

	if (!cxl_is_power9())
		return false;

	if (cxl_slot_is_switched(dev))
		return false;

	/* on p9, some pci slots are not connected to a CAPP unit */
	rc = cxl_calc_capp_routing(dev, &chip_id, &phb_index, &capp_unit_id);
	if (rc)
		return false;

	return true;
}

__attribute__((used)) static int allocate_dummy_read_buf(void)
{
	u64 buf, vaddr;
	size_t buf_size;

	/*
	 * Dummy read buffer is 128-byte long, aligned on a
	 * 256-byte boundary and we need the physical address.
	 */
	buf_size = CXL_DUMMY_READ_SIZE + (1ull << CXL_DUMMY_READ_ALIGN);
	buf = (u64) kzalloc(buf_size, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	vaddr = (buf + (1ull << CXL_DUMMY_READ_ALIGN) - 1) &
					(~0ull << CXL_DUMMY_READ_ALIGN);

	WARN((vaddr + CXL_DUMMY_READ_SIZE) > (buf + buf_size),
		"Dummy read buffer alignment issue");
	dummy_read_addr = virt_to_phys((void *) vaddr);
	return 0;
}

int cxllib_get_xsl_config(struct pci_dev *dev, struct cxllib_xsl_config *cfg)
{
	int rc;
	u32 phb_index;
	u64 chip_id, capp_unit_id;

	if (!cpu_has_feature(CPU_FTR_HVMODE))
		return -EINVAL;

	mutex_lock(&dra_mutex);
	if (dummy_read_addr == CXL_INVALID_DRA) {
		rc = allocate_dummy_read_buf();
		if (rc) {
			mutex_unlock(&dra_mutex);
			return rc;
		}
	}
	mutex_unlock(&dra_mutex);

	rc = cxl_calc_capp_routing(dev, &chip_id, &phb_index, &capp_unit_id);
	if (rc)
		return rc;

	rc = cxl_get_xsl9_dsnctl(dev, capp_unit_id, &cfg->dsnctl);
	if (rc)
		return rc;

	cfg->version  = CXL_XSL_CONFIG_CURRENT_VERSION;
	cfg->log_bar_size = CXL_CAPI_WINDOW_LOG_SIZE;
	cfg->bar_addr = CXL_CAPI_WINDOW_START;
	cfg->dra = dummy_read_addr;
	return 0;
}

int cxllib_switch_phb_mode(struct pci_dev *dev, enum cxllib_mode mode,
			unsigned long flags)
{
	int rc = 0;

	if (!cpu_has_feature(CPU_FTR_HVMODE))
		return -EINVAL;

	switch (mode) {
	case CXL_MODE_PCI:
		/*
		 * We currently don't support going back to PCI mode
		 * However, we'll turn the invalidations off, so that
		 * the firmware doesn't have to ack them and can do
		 * things like reset, etc.. with no worries.
		 * So always return EPERM (can't go back to PCI) or
		 * EBUSY if we couldn't even turn off snooping
		 */
		rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_SNOOP_OFF);
		if (rc)
			rc = -EBUSY;
		else
			rc = -EPERM;
		break;
	case CXL_MODE_CXL:
		/* DMA only supported on TVT1 for the time being */
		if (flags != CXL_MODE_DMA_TVT1)
			return -EINVAL;
		rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_DMA_TVT1);
		if (rc)
			return rc;
		rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_SNOOP_ON);
		break;
	default:
		rc = -EINVAL;
	}
	return rc;
}

int cxllib_set_device_dma(struct pci_dev *dev, unsigned long flags)
{
	int rc;

	if (flags)
		return -EINVAL;

	rc = dma_set_mask(&dev->dev, DMA_BIT_MASK(64));
	return rc;
}

int cxllib_get_PE_attributes(struct task_struct *task,
			     unsigned long translation_mode,
			     struct cxllib_pe_attributes *attr)
{
	struct mm_struct *mm = NULL;

	if (translation_mode != CXL_TRANSLATED_MODE &&
		translation_mode != CXL_REAL_MODE)
		return -EINVAL;

	attr->sr = cxl_calculate_sr(false,
				task == NULL,
				translation_mode == CXL_REAL_MODE,
				true);
	attr->lpid = mfspr(SPRN_LPID);
	if (task) {
		mm = get_task_mm(task);
		if (mm == NULL)
			return -EINVAL;
		/*
		 * Caller is keeping a reference on mm_users for as long
		 * as XSL uses the memory context
		 */
		attr->pid = mm->context.id;
		mmput(mm);
		attr->tid = task->thread.tidr;
	} else {
		attr->pid = 0;
		attr->tid = 0;
	}
	return 0;
}

__attribute__((used)) static int get_vma_info(struct mm_struct *mm, u64 addr,
			u64 *vma_start, u64 *vma_end,
			unsigned long *page_size)
{
	struct vm_area_struct *vma = NULL;
	int rc = 0;

	down_read(&mm->mmap_sem);

	vma = find_vma(mm, addr);
	if (!vma) {
		rc = -EFAULT;
		goto out;
	}
	*page_size = vma_kernel_pagesize(vma);
	*vma_start = vma->vm_start;
	*vma_end = vma->vm_end;
out:
	up_read(&mm->mmap_sem);
	return rc;
}

int cxllib_handle_fault(struct mm_struct *mm, u64 addr, u64 size, u64 flags)
{
	int rc;
	u64 dar, vma_start, vma_end;
	unsigned long page_size;

	if (mm == NULL)
		return -EFAULT;

	/*
	 * The buffer we have to process can extend over several pages
	 * and may also cover several VMAs.
	 * We iterate over all the pages. The page size could vary
	 * between VMAs.
	 */
	rc = get_vma_info(mm, addr, &vma_start, &vma_end, &page_size);
	if (rc)
		return rc;

	for (dar = (addr & ~(page_size - 1)); dar < (addr + size);
	     dar += page_size) {
		if (dar < vma_start || dar >= vma_end) {
			/*
			 * We don't hold the mm->mmap_sem semaphore
			 * while iterating, since the semaphore is
			 * required by one of the lower-level page
			 * fault processing functions and it could
			 * create a deadlock.
			 *
			 * It means the VMAs can be altered between 2
			 * loop iterations and we could theoretically
			 * miss a page (however unlikely). But that's
			 * not really a problem, as the driver will
			 * retry access, get another page fault on the
			 * missing page and call us again.
			 */
			rc = get_vma_info(mm, dar, &vma_start, &vma_end,
					&page_size);
			if (rc)
				return rc;
		}

		rc = cxl_handle_mm_fault(mm, flags, dar);
		if (rc)
			return -EFAULT;
	}
	return 0;
}

