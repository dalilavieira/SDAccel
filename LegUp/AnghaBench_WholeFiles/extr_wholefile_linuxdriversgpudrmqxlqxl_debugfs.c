#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long uint64_t ;
typedef  unsigned long u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct qxl_memslot {unsigned long high_bits; } ;
struct qxl_device {int main_mem_slot; int surfaces_mem_slot; unsigned int debugfs_count; TYPE_3__* debugfs; struct qxl_memslot* mem_slots; } ;
struct TYPE_8__ {int /*<<< orphan*/  mem_type; } ;
struct TYPE_10__ {unsigned long offset; unsigned long num_pages; TYPE_2__ mem; int /*<<< orphan*/  vma_node; } ;
struct TYPE_7__ {struct drm_device* dev; } ;
struct qxl_bo {scalar_t__ type; TYPE_4__ tbo; TYPE_1__ gem_base; } ;
struct drm_minor {int dummy; } ;
struct drm_info_list {int dummy; } ;
struct drm_device {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {unsigned int num_files; struct drm_info_list* files; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,unsigned long) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int EINVAL ; 
 int ERESTARTSYS ; 
 unsigned long PAGE_SHIFT ; 
 unsigned int QXL_DEBUGFS_MAX_COMPONENTS ; 
 scalar_t__ QXL_GEM_DOMAIN_VRAM ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct qxl_bo*) ; 
 unsigned long drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 int ttm_bo_reserve (TYPE_4__*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (TYPE_4__*) ; 
 int ttm_bo_wait (TYPE_4__*,int,int) ; 
 scalar_t__ unlikely (int) ; 

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

__attribute__((used)) static inline int qxl_bo_reserve(struct qxl_bo *bo, bool no_wait)
{
	int r;

	r = ttm_bo_reserve(&bo->tbo, true, no_wait, NULL);
	if (unlikely(r != 0)) {
		if (r != -ERESTARTSYS) {
			struct drm_device *ddev = bo->gem_base.dev;
			dev_err(ddev->dev, "%p reserve failed\n", bo);
		}
		return r;
	}
	return 0;
}

__attribute__((used)) static inline void qxl_bo_unreserve(struct qxl_bo *bo)
{
	ttm_bo_unreserve(&bo->tbo);
}

__attribute__((used)) static inline u64 qxl_bo_gpu_offset(struct qxl_bo *bo)
{
	return bo->tbo.offset;
}

__attribute__((used)) static inline unsigned long qxl_bo_size(struct qxl_bo *bo)
{
	return bo->tbo.num_pages << PAGE_SHIFT;
}

__attribute__((used)) static inline u64 qxl_bo_mmap_offset(struct qxl_bo *bo)
{
	return drm_vma_node_offset_addr(&bo->tbo.vma_node);
}

__attribute__((used)) static inline int qxl_bo_wait(struct qxl_bo *bo, u32 *mem_type,
			      bool no_wait)
{
	int r;

	r = ttm_bo_reserve(&bo->tbo, true, no_wait, NULL);
	if (unlikely(r != 0)) {
		if (r != -ERESTARTSYS) {
			struct drm_device *ddev = bo->gem_base.dev;
			dev_err(ddev->dev, "%p reserve failed for wait\n",
				bo);
		}
		return r;
	}
	if (mem_type)
		*mem_type = bo->tbo.mem.mem_type;

	r = ttm_bo_wait(&bo->tbo, true, no_wait);
	ttm_bo_unreserve(&bo->tbo);
	return r;
}

int
qxl_debugfs_init(struct drm_minor *minor)
{
#if defined(CONFIG_DEBUG_FS)
	int r;
	struct qxl_device *dev =
		(struct qxl_device *) minor->dev->dev_private;

	drm_debugfs_create_files(qxl_debugfs_list, QXL_DEBUGFS_ENTRIES,
				 minor->debugfs_root, minor);

	r = qxl_ttm_debugfs_init(dev);
	if (r) {
		DRM_ERROR("Failed to init TTM debugfs\n");
		return r;
	}
#endif
	return 0;
}

int qxl_debugfs_add_files(struct qxl_device *qdev,
			  struct drm_info_list *files,
			  unsigned nfiles)
{
	unsigned i;

	for (i = 0; i < qdev->debugfs_count; i++) {
		if (qdev->debugfs[i].files == files) {
			/* Already registered */
			return 0;
		}
	}

	i = qdev->debugfs_count + 1;
	if (i > QXL_DEBUGFS_MAX_COMPONENTS) {
		DRM_ERROR("Reached maximum number of debugfs components.\n");
		DRM_ERROR("Report so we increase QXL_DEBUGFS_MAX_COMPONENTS.\n");
		return -EINVAL;
	}
	qdev->debugfs[qdev->debugfs_count].files = files;
	qdev->debugfs[qdev->debugfs_count].num_files = nfiles;
	qdev->debugfs_count = i;
#if defined(CONFIG_DEBUG_FS)
	drm_debugfs_create_files(files, nfiles,
				 qdev->ddev.primary->debugfs_root,
				 qdev->ddev.primary);
#endif
	return 0;
}

