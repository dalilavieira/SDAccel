#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int uint ;
typedef  int u32 ;
struct psb_mmu_pt {int hw_context; int invalid_pde; int invalid_pte; int pd_mask; int clflush_add; scalar_t__ count; int index; int* v; int bif_ctrl; int /*<<< orphan*/  sem; struct psb_mmu_pt* driver; void* p; int /*<<< orphan*/  lock; scalar_t__ has_clflush; int /*<<< orphan*/ * msvdx_mmu_invaldc; int /*<<< orphan*/  needs_tlbflush; struct psb_mmu_pt* default_pd; struct drm_device* dev; struct psb_mmu_pt* pd; struct psb_mmu_pt** tables; void* dummy_pt; void* dummy_page; } ;
struct psb_mmu_pd {int hw_context; int invalid_pde; int invalid_pte; int pd_mask; int clflush_add; scalar_t__ count; int index; int* v; int bif_ctrl; int /*<<< orphan*/  sem; struct psb_mmu_pd* driver; void* p; int /*<<< orphan*/  lock; scalar_t__ has_clflush; int /*<<< orphan*/ * msvdx_mmu_invaldc; int /*<<< orphan*/  needs_tlbflush; struct psb_mmu_pd* default_pd; struct drm_device* dev; struct psb_mmu_pd* pd; struct psb_mmu_pd** tables; void* dummy_pt; void* dummy_page; } ;
struct psb_mmu_driver {int hw_context; int invalid_pde; int invalid_pte; int pd_mask; int clflush_add; scalar_t__ count; int index; int* v; int bif_ctrl; int /*<<< orphan*/  sem; struct psb_mmu_driver* driver; void* p; int /*<<< orphan*/  lock; scalar_t__ has_clflush; int /*<<< orphan*/ * msvdx_mmu_invaldc; int /*<<< orphan*/  needs_tlbflush; struct psb_mmu_driver* default_pd; struct drm_device* dev; struct psb_mmu_driver* pd; struct psb_mmu_driver** tables; void* dummy_pt; void* dummy_page; } ;
struct pci_dev {int dummy; } ;
struct page {int dummy; } ;
struct gma_encoder {int dummy; } ;
struct drm_psb_private {int vdc_reg; int aux_reg; } ;
struct drm_display_mode {int clock; int private_flags; } ;
struct drm_device {struct drm_psb_private* dev_private; } ;
struct drm_connector {int dummy; } ;
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int /*<<< orphan*/  atomic_t ;
struct TYPE_2__ {struct gma_encoder* encoder; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_DMA32 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_MASK ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_SHIFT ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 int PSB_CR_BIF_CTRL ; 
 int PSB_CR_BIF_DIR_LIST_BASE0 ; 
 int PSB_CR_BIF_DIR_LIST_BASE1 ; 
 int PSB_MMU_CACHED_MEMORY ; 
 int PSB_MMU_RO_MEMORY ; 
 int PSB_MMU_WO_MEMORY ; 
 unsigned long PSB_PDE_MASK ; 
 int PSB_PDE_SHIFT ; 
 int PSB_PTE_CACHED ; 
 int PSB_PTE_RO ; 
 int PSB_PTE_SHIFT ; 
 int PSB_PTE_VALID ; 
 int PSB_PTE_WO ; 
 void* PSB_RSGX32 (int) ; 
 int /*<<< orphan*/  PSB_WSGX32 (int,int) ; 
 int REG_READ (int) ; 
 int REG_READ_AUX (int) ; 
 int /*<<< orphan*/  REG_WRITE (int,int) ; 
 int /*<<< orphan*/  REG_WRITE_AUX (int,int) ; 
 int _PSB_CB_CTRL_CLEAR_FAULT ; 
 int _PSB_CB_CTRL_FLUSH ; 
 int _PSB_CB_CTRL_INVALDC ; 
 int /*<<< orphan*/  __free_page (void*) ; 
 void* alloc_page (int /*<<< orphan*/ ) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  clear_page (int*) ; 
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_ttm_cache_flush () ; 
 int /*<<< orphan*/  init_rwsem (int /*<<< orphan*/ *) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite16 (int,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int,int) ; 
 int /*<<< orphan*/  kfree (struct psb_mmu_pt*) ; 
 struct psb_mmu_pt* kmalloc (int,int /*<<< orphan*/ ) ; 
 int* kmap (void*) ; 
 void* kmap_atomic (void*) ; 
 int /*<<< orphan*/  kunmap (void*) ; 
 int /*<<< orphan*/  kunmap_atomic (int*) ; 
 int page_to_pfn (void*) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__* to_gma_connector (struct drm_connector*) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vfree (struct psb_mmu_pt**) ; 
 struct psb_mmu_pt** vmalloc_user (int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline void
psb_intel_mode_set_pixel_multiplier(struct drm_display_mode *mode,
				int multiplier)
{
	mode->clock *= multiplier;
	mode->private_flags |= multiplier;
}

__attribute__((used)) static inline int
psb_intel_mode_get_pixel_multiplier(const struct drm_display_mode *mode)
{
	return (mode->private_flags & INTEL_MODE_PIXEL_MULTIPLIER_MASK)
	       >> INTEL_MODE_PIXEL_MULTIPLIER_SHIFT;
}

__attribute__((used)) static inline struct gma_encoder *gma_attached_encoder(
						struct drm_connector *connector)
{
	return to_gma_connector(connector)->encoder;
}

extern inline void psb_intel_opregion_asle_intr(struct drm_device *dev)
{
}

extern inline void psb_intel_opregion_init(struct drm_device *dev)
{
}

extern inline void psb_intel_opregion_fini(struct drm_device *dev)
{
}

extern inline int psb_intel_opregion_setup(struct drm_device *dev)
{
	return 0;
}

extern inline void psb_intel_opregion_enable_asle(struct drm_device *dev)
{
}

__attribute__((used)) static inline struct drm_psb_private *psb_priv(struct drm_device *dev)
{
	return (struct drm_psb_private *) dev->dev_private;
}

__attribute__((used)) static inline u32 MRST_MSG_READ32(int domain, uint port, uint offset)
{
	int mcr = (0xD0<<24) | (port << 16) | (offset << 8);
	uint32_t ret_val = 0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_read_config_dword(pci_root, 0xD4, &ret_val);
	pci_dev_put(pci_root);
	return ret_val;
}

__attribute__((used)) static inline void MRST_MSG_WRITE32(int domain, uint port, uint offset,
				    u32 value)
{
	int mcr = (0xE0<<24) | (port << 16) | (offset << 8) | 0xF0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD4, value);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_dev_put(pci_root);
}

__attribute__((used)) static inline u32 MDFLD_MSG_READ32(int domain, uint port, uint offset)
{
	int mcr = (0x10<<24) | (port << 16) | (offset << 8);
	uint32_t ret_val = 0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_read_config_dword(pci_root, 0xD4, &ret_val);
	pci_dev_put(pci_root);
	return ret_val;
}

__attribute__((used)) static inline void MDFLD_MSG_WRITE32(int domain, uint port, uint offset,
				     u32 value)
{
	int mcr = (0x11<<24) | (port << 16) | (offset << 8) | 0xF0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD4, value);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_dev_put(pci_root);
}

__attribute__((used)) static inline uint32_t REGISTER_READ(struct drm_device *dev, uint32_t reg)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	return ioread32(dev_priv->vdc_reg + reg);
}

__attribute__((used)) static inline uint32_t REGISTER_READ_AUX(struct drm_device *dev, uint32_t reg)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	return ioread32(dev_priv->aux_reg + reg);
}

__attribute__((used)) static inline uint32_t REGISTER_READ_WITH_AUX(struct drm_device *dev,
					      uint32_t reg, int aux)
{
	uint32_t val;

	if (aux)
		val = REG_READ_AUX(reg);
	else
		val = REG_READ(reg);

	return val;
}

__attribute__((used)) static inline void REGISTER_WRITE(struct drm_device *dev, uint32_t reg,
				  uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite32((val), dev_priv->vdc_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE_AUX(struct drm_device *dev, uint32_t reg,
				      uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite32((val), dev_priv->aux_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE_WITH_AUX(struct drm_device *dev, uint32_t reg,
				      uint32_t val, int aux)
{
	if (aux)
		REG_WRITE_AUX(reg, val);
	else
		REG_WRITE(reg, val);
}

__attribute__((used)) static inline void REGISTER_WRITE16(struct drm_device *dev,
					uint32_t reg, uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite16((val), dev_priv->vdc_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE8(struct drm_device *dev,
				       uint32_t reg, uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite8((val), dev_priv->vdc_reg + (reg));
}

__attribute__((used)) static inline uint32_t psb_mmu_pt_index(uint32_t offset)
{
	return (offset >> PSB_PTE_SHIFT) & 0x3FF;
}

__attribute__((used)) static inline uint32_t psb_mmu_pd_index(uint32_t offset)
{
	return offset >> PSB_PDE_SHIFT;
}

__attribute__((used)) static inline void psb_mmu_clflush(struct psb_mmu_driver *driver, void *addr)
{;
}

__attribute__((used)) static void psb_mmu_flush_pd_locked(struct psb_mmu_driver *driver, int force)
{
	struct drm_device *dev = driver->dev;
	struct drm_psb_private *dev_priv = dev->dev_private;

	if (atomic_read(&driver->needs_tlbflush) || force) {
		uint32_t val = PSB_RSGX32(PSB_CR_BIF_CTRL);
		PSB_WSGX32(val | _PSB_CB_CTRL_INVALDC, PSB_CR_BIF_CTRL);

		/* Make sure data cache is turned off before enabling it */
		wmb();
		PSB_WSGX32(val & ~_PSB_CB_CTRL_INVALDC, PSB_CR_BIF_CTRL);
		(void)PSB_RSGX32(PSB_CR_BIF_CTRL);
		if (driver->msvdx_mmu_invaldc)
			atomic_set(driver->msvdx_mmu_invaldc, 1);
	}
	atomic_set(&driver->needs_tlbflush, 0);
}

void psb_mmu_flush(struct psb_mmu_driver *driver)
{
	struct drm_device *dev = driver->dev;
	struct drm_psb_private *dev_priv = dev->dev_private;
	uint32_t val;

	down_write(&driver->sem);
	val = PSB_RSGX32(PSB_CR_BIF_CTRL);
	if (atomic_read(&driver->needs_tlbflush))
		PSB_WSGX32(val | _PSB_CB_CTRL_INVALDC, PSB_CR_BIF_CTRL);
	else
		PSB_WSGX32(val | _PSB_CB_CTRL_FLUSH, PSB_CR_BIF_CTRL);

	/* Make sure data cache is turned off and MMU is flushed before
	   restoring bank interface control register */
	wmb();
	PSB_WSGX32(val & ~(_PSB_CB_CTRL_FLUSH | _PSB_CB_CTRL_INVALDC),
		   PSB_CR_BIF_CTRL);
	(void)PSB_RSGX32(PSB_CR_BIF_CTRL);

	atomic_set(&driver->needs_tlbflush, 0);
	if (driver->msvdx_mmu_invaldc)
		atomic_set(driver->msvdx_mmu_invaldc, 1);
	up_write(&driver->sem);
}

void psb_mmu_set_pd_context(struct psb_mmu_pd *pd, int hw_context)
{
	struct drm_device *dev = pd->driver->dev;
	struct drm_psb_private *dev_priv = dev->dev_private;
	uint32_t offset = (hw_context == 0) ? PSB_CR_BIF_DIR_LIST_BASE0 :
			  PSB_CR_BIF_DIR_LIST_BASE1 + hw_context * 4;

	down_write(&pd->driver->sem);
	PSB_WSGX32(page_to_pfn(pd->p) << PAGE_SHIFT, offset);
	wmb();
	psb_mmu_flush_pd_locked(pd->driver, 1);
	pd->hw_context = hw_context;
	up_write(&pd->driver->sem);

}

__attribute__((used)) static inline unsigned long psb_pd_addr_end(unsigned long addr,
					    unsigned long end)
{
	addr = (addr + PSB_PDE_MASK + 1) & ~PSB_PDE_MASK;
	return (addr < end) ? addr : end;
}

__attribute__((used)) static inline uint32_t psb_mmu_mask_pte(uint32_t pfn, int type)
{
	uint32_t mask = PSB_PTE_VALID;

	if (type & PSB_MMU_CACHED_MEMORY)
		mask |= PSB_PTE_CACHED;
	if (type & PSB_MMU_RO_MEMORY)
		mask |= PSB_PTE_RO;
	if (type & PSB_MMU_WO_MEMORY)
		mask |= PSB_PTE_WO;

	return (pfn << PAGE_SHIFT) | mask;
}

struct psb_mmu_pd *psb_mmu_alloc_pd(struct psb_mmu_driver *driver,
				    int trap_pagefaults, int invalid_type)
{
	struct psb_mmu_pd *pd = kmalloc(sizeof(*pd), GFP_KERNEL);
	uint32_t *v;
	int i;

	if (!pd)
		return NULL;

	pd->p = alloc_page(GFP_DMA32);
	if (!pd->p)
		goto out_err1;
	pd->dummy_pt = alloc_page(GFP_DMA32);
	if (!pd->dummy_pt)
		goto out_err2;
	pd->dummy_page = alloc_page(GFP_DMA32);
	if (!pd->dummy_page)
		goto out_err3;

	if (!trap_pagefaults) {
		pd->invalid_pde = psb_mmu_mask_pte(page_to_pfn(pd->dummy_pt),
						   invalid_type);
		pd->invalid_pte = psb_mmu_mask_pte(page_to_pfn(pd->dummy_page),
						   invalid_type);
	} else {
		pd->invalid_pde = 0;
		pd->invalid_pte = 0;
	}

	v = kmap(pd->dummy_pt);
	for (i = 0; i < (PAGE_SIZE / sizeof(uint32_t)); ++i)
		v[i] = pd->invalid_pte;

	kunmap(pd->dummy_pt);

	v = kmap(pd->p);
	for (i = 0; i < (PAGE_SIZE / sizeof(uint32_t)); ++i)
		v[i] = pd->invalid_pde;

	kunmap(pd->p);

	clear_page(kmap(pd->dummy_page));
	kunmap(pd->dummy_page);

	pd->tables = vmalloc_user(sizeof(struct psb_mmu_pt *) * 1024);
	if (!pd->tables)
		goto out_err4;

	pd->hw_context = -1;
	pd->pd_mask = PSB_PTE_VALID;
	pd->driver = driver;

	return pd;

out_err4:
	__free_page(pd->dummy_page);
out_err3:
	__free_page(pd->dummy_pt);
out_err2:
	__free_page(pd->p);
out_err1:
	kfree(pd);
	return NULL;
}

__attribute__((used)) static void psb_mmu_free_pt(struct psb_mmu_pt *pt)
{
	__free_page(pt->p);
	kfree(pt);
}

void psb_mmu_free_pagedir(struct psb_mmu_pd *pd)
{
	struct psb_mmu_driver *driver = pd->driver;
	struct drm_device *dev = driver->dev;
	struct drm_psb_private *dev_priv = dev->dev_private;
	struct psb_mmu_pt *pt;
	int i;

	down_write(&driver->sem);
	if (pd->hw_context != -1) {
		PSB_WSGX32(0, PSB_CR_BIF_DIR_LIST_BASE0 + pd->hw_context * 4);
		psb_mmu_flush_pd_locked(driver, 1);
	}

	/* Should take the spinlock here, but we don't need to do that
	   since we have the semaphore in write mode. */

	for (i = 0; i < 1024; ++i) {
		pt = pd->tables[i];
		if (pt)
			psb_mmu_free_pt(pt);
	}

	vfree(pd->tables);
	__free_page(pd->dummy_page);
	__free_page(pd->dummy_pt);
	__free_page(pd->p);
	kfree(pd);
	up_write(&driver->sem);
}

__attribute__((used)) static struct psb_mmu_pt *psb_mmu_alloc_pt(struct psb_mmu_pd *pd)
{
	struct psb_mmu_pt *pt = kmalloc(sizeof(*pt), GFP_KERNEL);
	void *v;
	uint32_t clflush_add = pd->driver->clflush_add >> PAGE_SHIFT;
	uint32_t clflush_count = PAGE_SIZE / clflush_add;
	spinlock_t *lock = &pd->driver->lock;
	uint8_t *clf;
	uint32_t *ptes;
	int i;

	if (!pt)
		return NULL;

	pt->p = alloc_page(GFP_DMA32);
	if (!pt->p) {
		kfree(pt);
		return NULL;
	}

	spin_lock(lock);

	v = kmap_atomic(pt->p);
	clf = (uint8_t *) v;
	ptes = (uint32_t *) v;
	for (i = 0; i < (PAGE_SIZE / sizeof(uint32_t)); ++i)
		*ptes++ = pd->invalid_pte;

#if defined(CONFIG_X86)
	if (pd->driver->has_clflush && pd->hw_context != -1) {
		mb();
		for (i = 0; i < clflush_count; ++i) {
			psb_clflush(clf);
			clf += clflush_add;
		}
		mb();
	}
#endif
	kunmap_atomic(v);
	spin_unlock(lock);

	pt->count = 0;
	pt->pd = pd;
	pt->index = 0;

	return pt;
}

struct psb_mmu_pt *psb_mmu_pt_alloc_map_lock(struct psb_mmu_pd *pd,
					     unsigned long addr)
{
	uint32_t index = psb_mmu_pd_index(addr);
	struct psb_mmu_pt *pt;
	uint32_t *v;
	spinlock_t *lock = &pd->driver->lock;

	spin_lock(lock);
	pt = pd->tables[index];
	while (!pt) {
		spin_unlock(lock);
		pt = psb_mmu_alloc_pt(pd);
		if (!pt)
			return NULL;
		spin_lock(lock);

		if (pd->tables[index]) {
			spin_unlock(lock);
			psb_mmu_free_pt(pt);
			spin_lock(lock);
			pt = pd->tables[index];
			continue;
		}

		v = kmap_atomic(pd->p);
		pd->tables[index] = pt;
		v[index] = (page_to_pfn(pt->p) << 12) | pd->pd_mask;
		pt->index = index;
		kunmap_atomic((void *) v);

		if (pd->hw_context != -1) {
			psb_mmu_clflush(pd->driver, (void *)&v[index]);
			atomic_set(&pd->driver->needs_tlbflush, 1);
		}
	}
	pt->v = kmap_atomic(pt->p);
	return pt;
}

__attribute__((used)) static struct psb_mmu_pt *psb_mmu_pt_map_lock(struct psb_mmu_pd *pd,
					      unsigned long addr)
{
	uint32_t index = psb_mmu_pd_index(addr);
	struct psb_mmu_pt *pt;
	spinlock_t *lock = &pd->driver->lock;

	spin_lock(lock);
	pt = pd->tables[index];
	if (!pt) {
		spin_unlock(lock);
		return NULL;
	}
	pt->v = kmap_atomic(pt->p);
	return pt;
}

__attribute__((used)) static void psb_mmu_pt_unmap_unlock(struct psb_mmu_pt *pt)
{
	struct psb_mmu_pd *pd = pt->pd;
	uint32_t *v;

	kunmap_atomic(pt->v);
	if (pt->count == 0) {
		v = kmap_atomic(pd->p);
		v[pt->index] = pd->invalid_pde;
		pd->tables[pt->index] = NULL;

		if (pd->hw_context != -1) {
			psb_mmu_clflush(pd->driver, (void *)&v[pt->index]);
			atomic_set(&pd->driver->needs_tlbflush, 1);
		}
		kunmap_atomic(v);
		spin_unlock(&pd->driver->lock);
		psb_mmu_free_pt(pt);
		return;
	}
	spin_unlock(&pd->driver->lock);
}

__attribute__((used)) static inline void psb_mmu_set_pte(struct psb_mmu_pt *pt, unsigned long addr,
				   uint32_t pte)
{
	pt->v[psb_mmu_pt_index(addr)] = pte;
}

__attribute__((used)) static inline void psb_mmu_invalidate_pte(struct psb_mmu_pt *pt,
					  unsigned long addr)
{
	pt->v[psb_mmu_pt_index(addr)] = pt->pd->invalid_pte;
}

struct psb_mmu_pd *psb_mmu_get_default_pd(struct psb_mmu_driver *driver)
{
	struct psb_mmu_pd *pd;

	down_read(&driver->sem);
	pd = driver->default_pd;
	up_read(&driver->sem);

	return pd;
}

uint32_t psb_get_default_pd_addr(struct psb_mmu_driver *driver)
{
	struct psb_mmu_pd *pd;

	pd = psb_mmu_get_default_pd(driver);
	return page_to_pfn(pd->p) << PAGE_SHIFT;
}

void psb_mmu_driver_takedown(struct psb_mmu_driver *driver)
{
	struct drm_device *dev = driver->dev;
	struct drm_psb_private *dev_priv = dev->dev_private;

	PSB_WSGX32(driver->bif_ctrl, PSB_CR_BIF_CTRL);
	psb_mmu_free_pagedir(driver->default_pd);
	kfree(driver);
}

struct psb_mmu_driver *psb_mmu_driver_init(struct drm_device *dev,
					   int trap_pagefaults,
					   int invalid_type,
					   atomic_t *msvdx_mmu_invaldc)
{
	struct psb_mmu_driver *driver;
	struct drm_psb_private *dev_priv = dev->dev_private;

	driver = kmalloc(sizeof(*driver), GFP_KERNEL);

	if (!driver)
		return NULL;

	driver->dev = dev;
	driver->default_pd = psb_mmu_alloc_pd(driver, trap_pagefaults,
					      invalid_type);
	if (!driver->default_pd)
		goto out_err1;

	spin_lock_init(&driver->lock);
	init_rwsem(&driver->sem);
	down_write(&driver->sem);
	atomic_set(&driver->needs_tlbflush, 1);
	driver->msvdx_mmu_invaldc = msvdx_mmu_invaldc;

	driver->bif_ctrl = PSB_RSGX32(PSB_CR_BIF_CTRL);
	PSB_WSGX32(driver->bif_ctrl | _PSB_CB_CTRL_CLEAR_FAULT,
		   PSB_CR_BIF_CTRL);
	PSB_WSGX32(driver->bif_ctrl & ~_PSB_CB_CTRL_CLEAR_FAULT,
		   PSB_CR_BIF_CTRL);

	driver->has_clflush = 0;

#if defined(CONFIG_X86)
	if (boot_cpu_has(X86_FEATURE_CLFLUSH)) {
		uint32_t tfms, misc, cap0, cap4, clflush_size;

		/*
		 * clflush size is determined at kernel setup for x86_64 but not
		 * for i386. We have to do it here.
		 */

		cpuid(0x00000001, &tfms, &misc, &cap0, &cap4);
		clflush_size = ((misc >> 8) & 0xff) * 8;
		driver->has_clflush = 1;
		driver->clflush_add =
		    PAGE_SIZE * clflush_size / sizeof(uint32_t);
		driver->clflush_mask = driver->clflush_add - 1;
		driver->clflush_mask = ~driver->clflush_mask;
	}
#endif

	up_write(&driver->sem);
	return driver;

out_err1:
	kfree(driver);
	return NULL;
}

__attribute__((used)) static void psb_mmu_flush_ptes(struct psb_mmu_pd *pd, unsigned long address,
			       uint32_t num_pages, uint32_t desired_tile_stride,
			       uint32_t hw_tile_stride)
{
	drm_ttm_cache_flush();
}

void psb_mmu_remove_pfn_sequence(struct psb_mmu_pd *pd,
				 unsigned long address, uint32_t num_pages)
{
	struct psb_mmu_pt *pt;
	unsigned long addr;
	unsigned long end;
	unsigned long next;
	unsigned long f_address = address;

	down_read(&pd->driver->sem);

	addr = address;
	end = addr + (num_pages << PAGE_SHIFT);

	do {
		next = psb_pd_addr_end(addr, end);
		pt = psb_mmu_pt_alloc_map_lock(pd, addr);
		if (!pt)
			goto out;
		do {
			psb_mmu_invalidate_pte(pt, addr);
			--pt->count;
		} while (addr += PAGE_SIZE, addr < next);
		psb_mmu_pt_unmap_unlock(pt);

	} while (addr = next, next != end);

out:
	if (pd->hw_context != -1)
		psb_mmu_flush_ptes(pd, f_address, num_pages, 1, 1);

	up_read(&pd->driver->sem);

	if (pd->hw_context != -1)
		psb_mmu_flush(pd->driver);

	return;
}

void psb_mmu_remove_pages(struct psb_mmu_pd *pd, unsigned long address,
			  uint32_t num_pages, uint32_t desired_tile_stride,
			  uint32_t hw_tile_stride)
{
	struct psb_mmu_pt *pt;
	uint32_t rows = 1;
	uint32_t i;
	unsigned long addr;
	unsigned long end;
	unsigned long next;
	unsigned long add;
	unsigned long row_add;
	unsigned long f_address = address;

	if (hw_tile_stride)
		rows = num_pages / desired_tile_stride;
	else
		desired_tile_stride = num_pages;

	add = desired_tile_stride << PAGE_SHIFT;
	row_add = hw_tile_stride << PAGE_SHIFT;

	down_read(&pd->driver->sem);

	/* Make sure we only need to flush this processor's cache */

	for (i = 0; i < rows; ++i) {

		addr = address;
		end = addr + add;

		do {
			next = psb_pd_addr_end(addr, end);
			pt = psb_mmu_pt_map_lock(pd, addr);
			if (!pt)
				continue;
			do {
				psb_mmu_invalidate_pte(pt, addr);
				--pt->count;

			} while (addr += PAGE_SIZE, addr < next);
			psb_mmu_pt_unmap_unlock(pt);

		} while (addr = next, next != end);
		address += row_add;
	}
	if (pd->hw_context != -1)
		psb_mmu_flush_ptes(pd, f_address, num_pages,
				   desired_tile_stride, hw_tile_stride);

	up_read(&pd->driver->sem);

	if (pd->hw_context != -1)
		psb_mmu_flush(pd->driver);
}

int psb_mmu_insert_pfn_sequence(struct psb_mmu_pd *pd, uint32_t start_pfn,
				unsigned long address, uint32_t num_pages,
				int type)
{
	struct psb_mmu_pt *pt;
	uint32_t pte;
	unsigned long addr;
	unsigned long end;
	unsigned long next;
	unsigned long f_address = address;
	int ret = -ENOMEM;

	down_read(&pd->driver->sem);

	addr = address;
	end = addr + (num_pages << PAGE_SHIFT);

	do {
		next = psb_pd_addr_end(addr, end);
		pt = psb_mmu_pt_alloc_map_lock(pd, addr);
		if (!pt) {
			ret = -ENOMEM;
			goto out;
		}
		do {
			pte = psb_mmu_mask_pte(start_pfn++, type);
			psb_mmu_set_pte(pt, addr, pte);
			pt->count++;
		} while (addr += PAGE_SIZE, addr < next);
		psb_mmu_pt_unmap_unlock(pt);

	} while (addr = next, next != end);
	ret = 0;

out:
	if (pd->hw_context != -1)
		psb_mmu_flush_ptes(pd, f_address, num_pages, 1, 1);

	up_read(&pd->driver->sem);

	if (pd->hw_context != -1)
		psb_mmu_flush(pd->driver);

	return 0;
}

int psb_mmu_insert_pages(struct psb_mmu_pd *pd, struct page **pages,
			 unsigned long address, uint32_t num_pages,
			 uint32_t desired_tile_stride, uint32_t hw_tile_stride,
			 int type)
{
	struct psb_mmu_pt *pt;
	uint32_t rows = 1;
	uint32_t i;
	uint32_t pte;
	unsigned long addr;
	unsigned long end;
	unsigned long next;
	unsigned long add;
	unsigned long row_add;
	unsigned long f_address = address;
	int ret = -ENOMEM;

	if (hw_tile_stride) {
		if (num_pages % desired_tile_stride != 0)
			return -EINVAL;
		rows = num_pages / desired_tile_stride;
	} else {
		desired_tile_stride = num_pages;
	}

	add = desired_tile_stride << PAGE_SHIFT;
	row_add = hw_tile_stride << PAGE_SHIFT;

	down_read(&pd->driver->sem);

	for (i = 0; i < rows; ++i) {

		addr = address;
		end = addr + add;

		do {
			next = psb_pd_addr_end(addr, end);
			pt = psb_mmu_pt_alloc_map_lock(pd, addr);
			if (!pt)
				goto out;
			do {
				pte = psb_mmu_mask_pte(page_to_pfn(*pages++),
						       type);
				psb_mmu_set_pte(pt, addr, pte);
				pt->count++;
			} while (addr += PAGE_SIZE, addr < next);
			psb_mmu_pt_unmap_unlock(pt);

		} while (addr = next, next != end);

		address += row_add;
	}

	ret = 0;
out:
	if (pd->hw_context != -1)
		psb_mmu_flush_ptes(pd, f_address, num_pages,
				   desired_tile_stride, hw_tile_stride);

	up_read(&pd->driver->sem);

	if (pd->hw_context != -1)
		psb_mmu_flush(pd->driver);

	return ret;
}

int psb_mmu_virtual_to_pfn(struct psb_mmu_pd *pd, uint32_t virtual,
			   unsigned long *pfn)
{
	int ret;
	struct psb_mmu_pt *pt;
	uint32_t tmp;
	spinlock_t *lock = &pd->driver->lock;

	down_read(&pd->driver->sem);
	pt = psb_mmu_pt_map_lock(pd, virtual);
	if (!pt) {
		uint32_t *v;

		spin_lock(lock);
		v = kmap_atomic(pd->p);
		tmp = v[psb_mmu_pd_index(virtual)];
		kunmap_atomic(v);
		spin_unlock(lock);

		if (tmp != pd->invalid_pde || !(tmp & PSB_PTE_VALID) ||
		    !(pd->invalid_pte & PSB_PTE_VALID)) {
			ret = -EINVAL;
			goto out;
		}
		ret = 0;
		*pfn = pd->invalid_pte >> PAGE_SHIFT;
		goto out;
	}
	tmp = pt->v[psb_mmu_pt_index(virtual)];
	if (!(tmp & PSB_PTE_VALID)) {
		ret = -EINVAL;
	} else {
		ret = 0;
		*pfn = tmp >> PAGE_SHIFT;
	}
	psb_mmu_pt_unmap_unlock(pt);
out:
	up_read(&pd->driver->sem);
	return ret;
}

