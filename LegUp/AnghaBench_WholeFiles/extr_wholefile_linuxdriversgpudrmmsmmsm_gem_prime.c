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
struct vm_area_struct {int /*<<< orphan*/  vm_private_data; } ;
struct timespec {int dummy; } ;
struct sg_table {int dummy; } ;
struct reservation_object {int dummy; } ;
struct msm_rd_state {int dummy; } ;
struct msm_gem_submit {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  import_attach; int /*<<< orphan*/  dma_buf; TYPE_1__* dev; } ;
struct msm_gem_object {scalar_t__ madv; scalar_t__ vmap_count; struct reservation_object* resv; int /*<<< orphan*/  pages; scalar_t__ vaddr; TYPE_2__ base; scalar_t__ sgt; int /*<<< orphan*/ * gpu; } ;
struct msm_drm_private {int dummy; } ;
struct drm_gem_object {int size; int /*<<< orphan*/  import_attach; } ;
struct drm_device {int dummy; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dmabuf; } ;
typedef  int /*<<< orphan*/  ktime_t ;
struct TYPE_3__ {int /*<<< orphan*/  struct_mutex; } ;

/* Variables and functions */
 int ALIGN (int,int) ; 
 scalar_t__ MSM_MADV_DONTNEED ; 
 int PAGE_SHIFT ; 
 scalar_t__ WARN_ON (int) ; 
 int drm_gem_mmap_obj (struct drm_gem_object*,int,struct vm_area_struct*) ; 
 struct sg_table* drm_prime_pages_to_sg (int /*<<< orphan*/ ,int) ; 
 scalar_t__ ktime_compare (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get () ; 
 int /*<<< orphan*/  ktime_sub (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 struct timespec ktime_to_timespec (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msm_gem_get_pages (struct drm_gem_object*) ; 
 void* msm_gem_get_vaddr (struct drm_gem_object*) ; 
 struct drm_gem_object* msm_gem_import (struct drm_device*,int /*<<< orphan*/ ,struct sg_table*) ; 
 int msm_gem_mmap_obj (int /*<<< orphan*/ ,struct vm_area_struct*) ; 
 int /*<<< orphan*/  msm_gem_put_pages (struct drm_gem_object*) ; 
 int /*<<< orphan*/  msm_gem_put_vaddr (struct drm_gem_object*) ; 
 int /*<<< orphan*/  mutex_is_locked (int /*<<< orphan*/ *) ; 
 unsigned long timespec_to_jiffies (struct timespec*) ; 
 struct msm_gem_object* to_msm_bo (struct drm_gem_object*) ; 

__attribute__((used)) static inline int msm_debugfs_late_init(struct drm_device *dev) { return 0; }

__attribute__((used)) static inline void msm_rd_dump_submit(struct msm_rd_state *rd, struct msm_gem_submit *submit,
		const char *fmt, ...) {}

__attribute__((used)) static inline void msm_rd_debugfs_cleanup(struct msm_drm_private *priv) {}

__attribute__((used)) static inline void msm_perf_debugfs_cleanup(struct msm_drm_private *priv) {}

__attribute__((used)) static inline int align_pitch(int width, int bpp)
{
	int bytespp = (bpp + 7) / 8;
	/* adreno needs pitch aligned to 32 pixels: */
	return bytespp * ALIGN(width, 32);
}

__attribute__((used)) static inline unsigned long timeout_to_jiffies(const ktime_t *timeout)
{
	ktime_t now = ktime_get();
	unsigned long remaining_jiffies;

	if (ktime_compare(*timeout, now) < 0) {
		remaining_jiffies = 0;
	} else {
		ktime_t rem = ktime_sub(*timeout, now);
		struct timespec ts = ktime_to_timespec(rem);
		remaining_jiffies = timespec_to_jiffies(&ts);
	}

	return remaining_jiffies;
}

__attribute__((used)) static inline bool is_active(struct msm_gem_object *msm_obj)
{
	return msm_obj->gpu != NULL;
}

__attribute__((used)) static inline bool is_purgeable(struct msm_gem_object *msm_obj)
{
	WARN_ON(!mutex_is_locked(&msm_obj->base.dev->struct_mutex));
	return (msm_obj->madv == MSM_MADV_DONTNEED) && msm_obj->sgt &&
			!msm_obj->base.dma_buf && !msm_obj->base.import_attach;
}

__attribute__((used)) static inline bool is_vunmapable(struct msm_gem_object *msm_obj)
{
	return (msm_obj->vmap_count == 0) && msm_obj->vaddr;
}

struct sg_table *msm_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
	struct msm_gem_object *msm_obj = to_msm_bo(obj);
	int npages = obj->size >> PAGE_SHIFT;

	if (WARN_ON(!msm_obj->pages))  /* should have already pinned! */
		return NULL;

	return drm_prime_pages_to_sg(msm_obj->pages, npages);
}

void *msm_gem_prime_vmap(struct drm_gem_object *obj)
{
	return msm_gem_get_vaddr(obj);
}

void msm_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
	msm_gem_put_vaddr(obj);
}

int msm_gem_prime_mmap(struct drm_gem_object *obj, struct vm_area_struct *vma)
{
	int ret;

	ret = drm_gem_mmap_obj(obj, obj->size, vma);
	if (ret < 0)
		return ret;

	return msm_gem_mmap_obj(vma->vm_private_data, vma);
}

struct drm_gem_object *msm_gem_prime_import_sg_table(struct drm_device *dev,
		struct dma_buf_attachment *attach, struct sg_table *sg)
{
	return msm_gem_import(dev, attach->dmabuf, sg);
}

int msm_gem_prime_pin(struct drm_gem_object *obj)
{
	if (!obj->import_attach)
		msm_gem_get_pages(obj);
	return 0;
}

void msm_gem_prime_unpin(struct drm_gem_object *obj)
{
	if (!obj->import_attach)
		msm_gem_put_pages(obj);
}

struct reservation_object *msm_gem_prime_res_obj(struct drm_gem_object *obj)
{
	struct msm_gem_object *msm_obj = to_msm_bo(obj);

	return msm_obj->resv;
}

