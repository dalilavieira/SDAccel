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
typedef  int /*<<< orphan*/  u64 ;
struct vm_area_struct {int dummy; } ;
struct ttm_buffer_object {int /*<<< orphan*/  vma_node; } ;
struct TYPE_4__ {TYPE_1__* dev; } ;
struct virtio_gpu_object {struct ttm_buffer_object tbo; TYPE_2__ gem_base; } ;
struct virtio_gpu_device {int /*<<< orphan*/  dev; } ;
typedef  void sg_table ;
typedef  void drm_gem_object ;
struct drm_device {int dummy; } ;
struct dma_buf_attachment {int dummy; } ;
struct TYPE_3__ {struct virtio_gpu_device* dev_private; } ;

/* Variables and functions */
 int ENODEV ; 
 int ERESTARTSYS ; 
 void* ERR_PTR (int) ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct virtio_gpu_object*) ; 
 int /*<<< orphan*/  drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_reference (struct ttm_buffer_object*) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline struct virtio_gpu_object*
virtio_gpu_object_ref(struct virtio_gpu_object *bo)
{
	ttm_bo_reference(&bo->tbo);
	return bo;
}

__attribute__((used)) static inline void virtio_gpu_object_unref(struct virtio_gpu_object **bo)
{
	struct ttm_buffer_object *tbo;

	if ((*bo) == NULL)
		return;
	tbo = &((*bo)->tbo);
	ttm_bo_unref(&tbo);
	if (tbo == NULL)
		*bo = NULL;
}

__attribute__((used)) static inline u64 virtio_gpu_object_mmap_offset(struct virtio_gpu_object *bo)
{
	return drm_vma_node_offset_addr(&bo->tbo.vma_node);
}

__attribute__((used)) static inline int virtio_gpu_object_reserve(struct virtio_gpu_object *bo,
					 bool no_wait)
{
	int r;

	r = ttm_bo_reserve(&bo->tbo, true, no_wait, NULL);
	if (unlikely(r != 0)) {
		if (r != -ERESTARTSYS) {
			struct virtio_gpu_device *qdev =
				bo->gem_base.dev->dev_private;
			dev_err(qdev->dev, "%p reserve failed\n", bo);
		}
		return r;
	}
	return 0;
}

__attribute__((used)) static inline void virtio_gpu_object_unreserve(struct virtio_gpu_object *bo)
{
	ttm_bo_unreserve(&bo->tbo);
}

int virtgpu_gem_prime_pin(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return -ENODEV;
}

void virtgpu_gem_prime_unpin(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
}

struct sg_table *virtgpu_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENODEV);
}

struct drm_gem_object *virtgpu_gem_prime_import_sg_table(
	struct drm_device *dev, struct dma_buf_attachment *attach,
	struct sg_table *table)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENODEV);
}

void *virtgpu_gem_prime_vmap(struct drm_gem_object *obj)
{
	WARN_ONCE(1, "not implemented");
	return ERR_PTR(-ENODEV);
}

void virtgpu_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
	WARN_ONCE(1, "not implemented");
}

int virtgpu_gem_prime_mmap(struct drm_gem_object *obj,
		       struct vm_area_struct *area)
{
	return -ENODEV;
}

