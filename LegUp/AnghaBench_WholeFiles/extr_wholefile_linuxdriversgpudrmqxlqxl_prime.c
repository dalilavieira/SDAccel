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
typedef  unsigned long uint64_t ;
struct vm_area_struct {int dummy; } ;
typedef  void sg_table ;
struct qxl_memslot {unsigned long high_bits; } ;
struct qxl_device {int main_mem_slot; int surfaces_mem_slot; struct qxl_memslot* mem_slots; } ;
struct TYPE_2__ {unsigned long offset; } ;
struct qxl_bo {scalar_t__ type; TYPE_1__ tbo; } ;
typedef  void drm_gem_object ;
struct drm_device {int dummy; } ;
struct dma_buf_attachment {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,unsigned long) ; 
 int ENOSYS ; 
 void* ERR_PTR (int) ; 
 scalar_t__ QXL_GEM_DOMAIN_VRAM ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 

__attribute__((used)) static inline void *
qxl_fb_virtual_address(struct qxl_device *qdev, unsigned long physical)
{
	DRM_DEBUG_DRIVER("not implemented (%lu)\n", physical);
	return 0;
}

__attribute__((used)) static inline uint64_t
qxl_bo_physical_address(struct qxl_device *qdev, struct qxl_bo *bo,
			unsigned long offset)
{
	int slot_id = bo->type == QXL_GEM_DOMAIN_VRAM ? qdev->main_mem_slot : qdev->surfaces_mem_slot;
	struct qxl_memslot *slot = &(qdev->mem_slots[slot_id]);

	/* TODO - need to hold one of the locks to read tbo.offset */
	return slot->high_bits | (bo->tbo.offset + offset);
}

int qxl_gem_prime_pin(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return -ENOSYS;
}

void qxl_gem_prime_unpin(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
}

struct sg_table *qxl_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENOSYS);
}

struct drm_gem_object *qxl_gem_prime_import_sg_table(
	struct drm_device *dev, struct dma_buf_attachment *attach,
	struct sg_table *table)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENOSYS);
}

void *qxl_gem_prime_vmap(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENOSYS);
}

void qxl_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
	WARN_ONCE(1, "not implemented");
}

int qxl_gem_prime_mmap(struct drm_gem_object *obj,
		       struct vm_area_struct *area)
{
	WARN_ONCE(1, "not implemented");
	return -ENOSYS;
}

