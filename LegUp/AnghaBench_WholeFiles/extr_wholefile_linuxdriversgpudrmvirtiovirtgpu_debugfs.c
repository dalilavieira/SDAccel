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
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct ttm_buffer_object {int /*<<< orphan*/  vma_node; } ;
struct TYPE_7__ {TYPE_1__* dev; } ;
struct virtio_gpu_object {struct ttm_buffer_object tbo; TYPE_2__ gem_base; } ;
struct TYPE_10__ {int /*<<< orphan*/  sync_seq; int /*<<< orphan*/  last_seq; } ;
struct virtio_gpu_device {TYPE_5__ fence_drv; int /*<<< orphan*/  dev; } ;
struct seq_file {scalar_t__ private; } ;
struct drm_minor {int /*<<< orphan*/  debugfs_root; } ;
struct drm_info_node {TYPE_4__* minor; } ;
struct TYPE_9__ {TYPE_3__* dev; } ;
struct TYPE_8__ {struct virtio_gpu_device* dev_private; } ;
struct TYPE_6__ {struct virtio_gpu_device* dev_private; } ;

/* Variables and functions */
 int ERESTARTSYS ; 
 int /*<<< orphan*/  VIRTIO_GPU_DEBUGFS_ENTRIES ; 
 scalar_t__ atomic64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct virtio_gpu_object*) ; 
 int /*<<< orphan*/  drm_debugfs_create_files (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct drm_minor*) ; 
 int /*<<< orphan*/  drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ttm_bo_reference (struct ttm_buffer_object*) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  virtio_gpu_debugfs_list ; 

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

__attribute__((used)) static int
virtio_gpu_debugfs_irq_info(struct seq_file *m, void *data)
{
	struct drm_info_node *node = (struct drm_info_node *) m->private;
	struct virtio_gpu_device *vgdev = node->minor->dev->dev_private;

	seq_printf(m, "fence %llu %lld\n",
		   (u64)atomic64_read(&vgdev->fence_drv.last_seq),
		   vgdev->fence_drv.sync_seq);
	return 0;
}

int
virtio_gpu_debugfs_init(struct drm_minor *minor)
{
	drm_debugfs_create_files(virtio_gpu_debugfs_list,
				 VIRTIO_GPU_DEBUGFS_ENTRIES,
				 minor->debugfs_root, minor);
	return 0;
}

