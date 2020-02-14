#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  unsigned long u64 ;
typedef  int u32 ;
struct TYPE_3__ {int mem_type; } ;
struct ttm_buffer_object {unsigned long offset; unsigned long num_pages; TYPE_1__ mem; int /*<<< orphan*/  vma_node; } ;
struct qxl_surface {int dummy; } ;
struct qxl_memslot {unsigned long high_bits; } ;
struct TYPE_4__ {int /*<<< orphan*/  objects; int /*<<< orphan*/  mutex; } ;
struct qxl_device {int main_mem_slot; int surfaces_mem_slot; TYPE_2__ gem; struct qxl_memslot* mem_slots; } ;
struct drm_gem_object {struct drm_device* dev; } ;
struct qxl_bo {scalar_t__ type; int /*<<< orphan*/  list; struct drm_gem_object gem_base; struct ttm_buffer_object tbo; } ;
struct drm_file {int dummy; } ;
struct drm_device {scalar_t__ dev_private; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,unsigned long) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,int,int,int,int) ; 
 int ENOMEM ; 
 int ERESTARTSYS ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 unsigned long PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 scalar_t__ QXL_GEM_DOMAIN_VRAM ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct qxl_bo*) ; 
 int drm_gem_handle_create (struct drm_file*,struct drm_gem_object*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_gem_object_put_unlocked (struct drm_gem_object*) ; 
 unsigned long drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 struct qxl_bo* gem_to_qxl_bo (struct drm_gem_object*) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int qxl_bo_create (struct qxl_device*,int,int,int,int,struct qxl_surface*,struct qxl_bo**) ; 
 int /*<<< orphan*/  qxl_bo_force_delete (struct qxl_device*) ; 
 int /*<<< orphan*/  qxl_surface_evict (struct qxl_device*,struct qxl_bo*,int) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 int ttm_bo_wait (struct ttm_buffer_object*,int,int) ; 
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

void qxl_gem_object_free(struct drm_gem_object *gobj)
{
	struct qxl_bo *qobj = gem_to_qxl_bo(gobj);
	struct qxl_device *qdev;
	struct ttm_buffer_object *tbo;

	qdev = (struct qxl_device *)gobj->dev->dev_private;

	qxl_surface_evict(qdev, qobj, false);

	tbo = &qobj->tbo;
	ttm_bo_unref(&tbo);
}

int qxl_gem_object_create(struct qxl_device *qdev, int size,
			  int alignment, int initial_domain,
			  bool discardable, bool kernel,
			  struct qxl_surface *surf,
			  struct drm_gem_object **obj)
{
	struct qxl_bo *qbo;
	int r;

	*obj = NULL;
	/* At least align on page size */
	if (alignment < PAGE_SIZE)
		alignment = PAGE_SIZE;
	r = qxl_bo_create(qdev, size, kernel, false, initial_domain, surf, &qbo);
	if (r) {
		if (r != -ERESTARTSYS)
			DRM_ERROR(
			"Failed to allocate GEM object (%d, %d, %u, %d)\n",
				  size, initial_domain, alignment, r);
		return r;
	}
	*obj = &qbo->gem_base;

	mutex_lock(&qdev->gem.mutex);
	list_add_tail(&qbo->list, &qdev->gem.objects);
	mutex_unlock(&qdev->gem.mutex);

	return 0;
}

int qxl_gem_object_create_with_handle(struct qxl_device *qdev,
				      struct drm_file *file_priv,
				      u32 domain,
				      size_t size,
				      struct qxl_surface *surf,
				      struct qxl_bo **qobj,
				      uint32_t *handle)
{
	struct drm_gem_object *gobj;
	int r;

	BUG_ON(!qobj);
	BUG_ON(!handle);

	r = qxl_gem_object_create(qdev, size, 0,
				  domain,
				  false, false, surf,
				  &gobj);
	if (r)
		return -ENOMEM;
	r = drm_gem_handle_create(file_priv, gobj, handle);
	if (r)
		return r;
	/* drop reference from allocate - handle holds it now */
	*qobj = gem_to_qxl_bo(gobj);
	drm_gem_object_put_unlocked(gobj);
	return 0;
}

int qxl_gem_object_open(struct drm_gem_object *obj, struct drm_file *file_priv)
{
	return 0;
}

void qxl_gem_object_close(struct drm_gem_object *obj,
			  struct drm_file *file_priv)
{
}

void qxl_gem_init(struct qxl_device *qdev)
{
	INIT_LIST_HEAD(&qdev->gem.objects);
}

void qxl_gem_fini(struct qxl_device *qdev)
{
	qxl_bo_force_delete(qdev);
}

