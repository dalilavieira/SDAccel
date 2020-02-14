#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wait_queue_head_t ;
union qxl_release_info {unsigned long next; } ;
typedef  int uint8_t ;
typedef  unsigned long uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  unsigned long u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct ttm_mem_reg {unsigned long start; size_t mem_type; } ;
struct qxl_ring_header {int notify_on_prod; scalar_t__ prod; scalar_t__ cons; scalar_t__ num_items; scalar_t__ notify_on_cons; } ;
struct ring {int* elements; struct qxl_ring_header header; } ;
struct qxl_surface_create {scalar_t__ width; scalar_t__ height; unsigned long mem; int /*<<< orphan*/  type; void* flags; int /*<<< orphan*/  stride; int /*<<< orphan*/  format; } ;
struct TYPE_19__ {scalar_t__ width; scalar_t__ height; unsigned long data; int /*<<< orphan*/  stride; int /*<<< orphan*/  format; } ;
struct TYPE_20__ {TYPE_6__ surface_create; } ;
struct qxl_surface_cmd {int surface_id; union qxl_release_info release_info; void* type; TYPE_7__ u; void* flags; } ;
struct qxl_ring {int n_elements; int element_size; int prod_notify; int /*<<< orphan*/  lock; struct ring* ring; int /*<<< orphan*/ * push_event; } ;
struct qxl_release {unsigned long release_offset; int type; int surface_release_id; struct qxl_bo* release_bo; } ;
struct qxl_rect {scalar_t__ left; scalar_t__ top; scalar_t__ right; scalar_t__ bottom; } ;
struct qxl_memslot {unsigned long high_bits; } ;
struct qxl_device {int main_mem_slot; int surfaces_mem_slot; long io_base; int last_sent_io_cmd; int primary_created; int last_alloced_surf_id; int /*<<< orphan*/  surf_evict_mutex; int /*<<< orphan*/  surf_id_idr_lock; int /*<<< orphan*/  surf_id_idr; TYPE_9__* rom; struct qxl_memslot* mem_slots; TYPE_3__* ram_header; int /*<<< orphan*/  update_area_mutex; int /*<<< orphan*/  async_io_mutex; int /*<<< orphan*/  irq_received_io_cmd; int /*<<< orphan*/  io_cmd_event; struct qxl_ring* release_ring; int /*<<< orphan*/  gc_work; struct qxl_ring* cursor_ring; struct qxl_ring* command_ring; } ;
struct qxl_command {unsigned long data; scalar_t__ type; } ;
struct TYPE_15__ {int /*<<< orphan*/  mem_type; } ;
struct TYPE_13__ {unsigned long offset; unsigned long num_pages; TYPE_5__* bdev; TYPE_2__ mem; int /*<<< orphan*/  vma_node; } ;
struct TYPE_21__ {scalar_t__ width; scalar_t__ height; int /*<<< orphan*/  stride; int /*<<< orphan*/  format; } ;
struct TYPE_14__ {struct drm_device* dev; } ;
struct qxl_bo {scalar_t__ type; int hw_surf_alloc; int surface_id; TYPE_10__ tbo; TYPE_8__ surf; struct qxl_release* surf_create; int /*<<< orphan*/  kptr; struct qxl_bo* shadow; scalar_t__ is_primary; TYPE_1__ gem_base; } ;
struct drm_device {int /*<<< orphan*/  dev; } ;
struct TYPE_22__ {scalar_t__ n_surfaces; } ;
struct TYPE_18__ {TYPE_4__* man; } ;
struct TYPE_17__ {unsigned long gpu_offset; } ;
struct TYPE_16__ {int update_surface; struct qxl_surface_create create_surface; struct qxl_rect update_area; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,...) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int EINVAL ; 
 int ERESTARTSYS ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GFP_NOWAIT ; 
 int HZ ; 
 unsigned long PAGE_SHIFT ; 
 scalar_t__ QXL_CMD_SURFACE ; 
 scalar_t__ QXL_GEM_DOMAIN_VRAM ; 
 long QXL_IO_CREATE_PRIMARY_ASYNC ; 
 long QXL_IO_DESTROY_PRIMARY_ASYNC ; 
 long QXL_IO_FLUSH_RELEASE ; 
 long QXL_IO_FLUSH_SURFACES_ASYNC ; 
 long QXL_IO_MEMSLOT_ADD_ASYNC ; 
 long QXL_IO_MONITORS_CONFIG_ASYNC ; 
 long QXL_IO_NOTIFY_OOM ; 
 long QXL_IO_RESET ; 
 long QXL_IO_UPDATE_AREA_ASYNC ; 
#define  QXL_RELEASE_CURSOR_CMD 130 
#define  QXL_RELEASE_DRAWABLE 129 
#define  QXL_RELEASE_SURFACE_CMD 128 
 void* QXL_SURFACE_CMD_CREATE ; 
 void* QXL_SURFACE_CMD_DESTROY ; 
 void* QXL_SURF_FLAG_KEEP_DATA ; 
 int /*<<< orphan*/  QXL_SURF_TYPE_PRIMARY ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct qxl_bo*) ; 
 int /*<<< orphan*/  drm_can_sleep () ; 
 unsigned long drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush_work (int /*<<< orphan*/ *) ; 
 int idr_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* idr_find (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  idr_preload (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_preload_end () ; 
 int /*<<< orphan*/  idr_remove (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  idr_replace (int /*<<< orphan*/ *,struct qxl_bo*,int) ; 
 int /*<<< orphan*/  kfree (struct qxl_ring*) ; 
 struct qxl_ring* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,long) ; 
 int qxl_alloc_surface_release_reserved (struct qxl_device*,void*,struct qxl_release*,struct qxl_release**) ; 
 int qxl_bo_create (struct qxl_device*,unsigned long,int,int,scalar_t__,int /*<<< orphan*/ *,struct qxl_bo**) ; 
 int /*<<< orphan*/  qxl_bo_unref (struct qxl_bo**) ; 
static  int qxl_reap_surface_id (struct qxl_device*,int) ; 
 int /*<<< orphan*/  qxl_release_fence_buffer_objects (struct qxl_release*) ; 
 int /*<<< orphan*/  qxl_release_free (struct qxl_device*,struct qxl_release*) ; 
 struct qxl_release* qxl_release_from_id_locked (struct qxl_device*,unsigned long) ; 
 int qxl_release_list_add (struct qxl_release*,struct qxl_bo*) ; 
 union qxl_release_info* qxl_release_map (struct qxl_device*,struct qxl_release*) ; 
 int qxl_release_reserve_list (struct qxl_release*,int) ; 
 int /*<<< orphan*/  qxl_release_unmap (struct qxl_device*,struct qxl_release*,union qxl_release_info*) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int ttm_bo_reserve (TYPE_10__*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (TYPE_10__*) ; 
 int ttm_bo_wait (TYPE_10__*,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,int) ; 
 int wait_event_interruptible (int /*<<< orphan*/ ,int) ; 
 int wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int) ; 
 int wait_event_timeout (int /*<<< orphan*/ ,int,int) ; 

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

void qxl_ring_free(struct qxl_ring *ring)
{
	kfree(ring);
}

void qxl_ring_init_hdr(struct qxl_ring *ring)
{
	ring->ring->header.notify_on_prod = ring->n_elements;
}

struct qxl_ring *
qxl_ring_create(struct qxl_ring_header *header,
		int element_size,
		int n_elements,
		int prod_notify,
		bool set_prod_notify,
		wait_queue_head_t *push_event)
{
	struct qxl_ring *ring;

	ring = kmalloc(sizeof(*ring), GFP_KERNEL);
	if (!ring)
		return NULL;

	ring->ring = (struct ring *)header;
	ring->element_size = element_size;
	ring->n_elements = n_elements;
	ring->prod_notify = prod_notify;
	ring->push_event = push_event;
	if (set_prod_notify)
		qxl_ring_init_hdr(ring);
	spin_lock_init(&ring->lock);
	return ring;
}

__attribute__((used)) static int qxl_check_header(struct qxl_ring *ring)
{
	int ret;
	struct qxl_ring_header *header = &(ring->ring->header);
	unsigned long flags;
	spin_lock_irqsave(&ring->lock, flags);
	ret = header->prod - header->cons < header->num_items;
	if (ret == 0)
		header->notify_on_cons = header->cons + 1;
	spin_unlock_irqrestore(&ring->lock, flags);
	return ret;
}

int qxl_check_idle(struct qxl_ring *ring)
{
	int ret;
	struct qxl_ring_header *header = &(ring->ring->header);
	unsigned long flags;
	spin_lock_irqsave(&ring->lock, flags);
	ret = header->prod == header->cons;
	spin_unlock_irqrestore(&ring->lock, flags);
	return ret;
}

int qxl_ring_push(struct qxl_ring *ring,
		  const void *new_elt, bool interruptible)
{
	struct qxl_ring_header *header = &(ring->ring->header);
	uint8_t *elt;
	int idx, ret;
	unsigned long flags;
	spin_lock_irqsave(&ring->lock, flags);
	if (header->prod - header->cons == header->num_items) {
		header->notify_on_cons = header->cons + 1;
		mb();
		spin_unlock_irqrestore(&ring->lock, flags);
		if (!drm_can_sleep()) {
			while (!qxl_check_header(ring))
				udelay(1);
		} else {
			if (interruptible) {
				ret = wait_event_interruptible(*ring->push_event,
							       qxl_check_header(ring));
				if (ret)
					return ret;
			} else {
				wait_event(*ring->push_event,
					   qxl_check_header(ring));
			}

		}
		spin_lock_irqsave(&ring->lock, flags);
	}

	idx = header->prod & (ring->n_elements - 1);
	elt = ring->ring->elements + idx * ring->element_size;

	memcpy((void *)elt, new_elt, ring->element_size);

	header->prod++;

	mb();

	if (header->prod == header->notify_on_prod)
		outb(0, ring->prod_notify);

	spin_unlock_irqrestore(&ring->lock, flags);
	return 0;
}

__attribute__((used)) static bool qxl_ring_pop(struct qxl_ring *ring,
			 void *element)
{
	volatile struct qxl_ring_header *header = &(ring->ring->header);
	volatile uint8_t *ring_elt;
	int idx;
	unsigned long flags;
	spin_lock_irqsave(&ring->lock, flags);
	if (header->cons == header->prod) {
		header->notify_on_prod = header->cons + 1;
		spin_unlock_irqrestore(&ring->lock, flags);
		return false;
	}

	idx = header->cons & (ring->n_elements - 1);
	ring_elt = ring->ring->elements + idx * ring->element_size;

	memcpy(element, (void *)ring_elt, ring->element_size);

	header->cons++;

	spin_unlock_irqrestore(&ring->lock, flags);
	return true;
}

int
qxl_push_command_ring_release(struct qxl_device *qdev, struct qxl_release *release,
			      uint32_t type, bool interruptible)
{
	struct qxl_command cmd;

	cmd.type = type;
	cmd.data = qxl_bo_physical_address(qdev, release->release_bo, release->release_offset);

	return qxl_ring_push(qdev->command_ring, &cmd, interruptible);
}

int
qxl_push_cursor_ring_release(struct qxl_device *qdev, struct qxl_release *release,
			     uint32_t type, bool interruptible)
{
	struct qxl_command cmd;

	cmd.type = type;
	cmd.data = qxl_bo_physical_address(qdev, release->release_bo, release->release_offset);

	return qxl_ring_push(qdev->cursor_ring, &cmd, interruptible);
}

bool qxl_queue_garbage_collect(struct qxl_device *qdev, bool flush)
{
	if (!qxl_check_idle(qdev->release_ring)) {
		schedule_work(&qdev->gc_work);
		if (flush)
			flush_work(&qdev->gc_work);
		return true;
	}
	return false;
}

int qxl_garbage_collect(struct qxl_device *qdev)
{
	struct qxl_release *release;
	uint64_t id, next_id;
	int i = 0;
	union qxl_release_info *info;

	while (qxl_ring_pop(qdev->release_ring, &id)) {
		DRM_DEBUG_DRIVER("popped %lld\n", id);
		while (id) {
			release = qxl_release_from_id_locked(qdev, id);
			if (release == NULL)
				break;

			info = qxl_release_map(qdev, release);
			next_id = info->next;
			qxl_release_unmap(qdev, release, info);

			DRM_DEBUG_DRIVER("popped %lld, next %lld\n", id,
					 next_id);

			switch (release->type) {
			case QXL_RELEASE_DRAWABLE:
			case QXL_RELEASE_SURFACE_CMD:
			case QXL_RELEASE_CURSOR_CMD:
				break;
			default:
				DRM_ERROR("unexpected release type\n");
				break;
			}
			id = next_id;

			qxl_release_free(qdev, release);
			++i;
		}
	}

	DRM_DEBUG_DRIVER("%d\n", i);

	return i;
}

int qxl_alloc_bo_reserved(struct qxl_device *qdev,
			  struct qxl_release *release,
			  unsigned long size,
			  struct qxl_bo **_bo)
{
	struct qxl_bo *bo;
	int ret;

	ret = qxl_bo_create(qdev, size, false /* not kernel - device */,
			    false, QXL_GEM_DOMAIN_VRAM, NULL, &bo);
	if (ret) {
		DRM_ERROR("failed to allocate VRAM BO\n");
		return ret;
	}
	ret = qxl_release_list_add(release, bo);
	if (ret)
		goto out_unref;

	*_bo = bo;
	return 0;
out_unref:
	qxl_bo_unref(&bo);
	return ret;
}

__attribute__((used)) static int wait_for_io_cmd_user(struct qxl_device *qdev, uint8_t val, long port, bool intr)
{
	int irq_num;
	long addr = qdev->io_base + port;
	int ret;

	mutex_lock(&qdev->async_io_mutex);
	irq_num = atomic_read(&qdev->irq_received_io_cmd);
	if (qdev->last_sent_io_cmd > irq_num) {
		if (intr)
			ret = wait_event_interruptible_timeout(qdev->io_cmd_event,
							       atomic_read(&qdev->irq_received_io_cmd) > irq_num, 5*HZ);
		else
			ret = wait_event_timeout(qdev->io_cmd_event,
						 atomic_read(&qdev->irq_received_io_cmd) > irq_num, 5*HZ);
		/* 0 is timeout, just bail the "hw" has gone away */
		if (ret <= 0)
			goto out;
		irq_num = atomic_read(&qdev->irq_received_io_cmd);
	}
	outb(val, addr);
	qdev->last_sent_io_cmd = irq_num + 1;
	if (intr)
		ret = wait_event_interruptible_timeout(qdev->io_cmd_event,
						       atomic_read(&qdev->irq_received_io_cmd) > irq_num, 5*HZ);
	else
		ret = wait_event_timeout(qdev->io_cmd_event,
					 atomic_read(&qdev->irq_received_io_cmd) > irq_num, 5*HZ);
out:
	if (ret > 0)
		ret = 0;
	mutex_unlock(&qdev->async_io_mutex);
	return ret;
}

__attribute__((used)) static void wait_for_io_cmd(struct qxl_device *qdev, uint8_t val, long port)
{
	int ret;

restart:
	ret = wait_for_io_cmd_user(qdev, val, port, false);
	if (ret == -ERESTARTSYS)
		goto restart;
}

int qxl_io_update_area(struct qxl_device *qdev, struct qxl_bo *surf,
			const struct qxl_rect *area)
{
	int surface_id;
	uint32_t surface_width, surface_height;
	int ret;

	if (!surf->hw_surf_alloc)
		DRM_ERROR("got io update area with no hw surface\n");

	if (surf->is_primary)
		surface_id = 0;
	else
		surface_id = surf->surface_id;
	surface_width = surf->surf.width;
	surface_height = surf->surf.height;

	if (area->left < 0 || area->top < 0 ||
	    area->right > surface_width || area->bottom > surface_height)
		return -EINVAL;

	mutex_lock(&qdev->update_area_mutex);
	qdev->ram_header->update_area = *area;
	qdev->ram_header->update_surface = surface_id;
	ret = wait_for_io_cmd_user(qdev, 0, QXL_IO_UPDATE_AREA_ASYNC, true);
	mutex_unlock(&qdev->update_area_mutex);
	return ret;
}

void qxl_io_notify_oom(struct qxl_device *qdev)
{
	outb(0, qdev->io_base + QXL_IO_NOTIFY_OOM);
}

void qxl_io_flush_release(struct qxl_device *qdev)
{
	outb(0, qdev->io_base + QXL_IO_FLUSH_RELEASE);
}

void qxl_io_flush_surfaces(struct qxl_device *qdev)
{
	wait_for_io_cmd(qdev, 0, QXL_IO_FLUSH_SURFACES_ASYNC);
}

void qxl_io_destroy_primary(struct qxl_device *qdev)
{
	wait_for_io_cmd(qdev, 0, QXL_IO_DESTROY_PRIMARY_ASYNC);
	qdev->primary_created = false;
}

void qxl_io_create_primary(struct qxl_device *qdev,
			   unsigned offset, struct qxl_bo *bo)
{
	struct qxl_surface_create *create;

	DRM_DEBUG_DRIVER("qdev %p, ram_header %p\n", qdev, qdev->ram_header);
	create = &qdev->ram_header->create_surface;
	create->format = bo->surf.format;
	create->width = bo->surf.width;
	create->height = bo->surf.height;
	create->stride = bo->surf.stride;
	if (bo->shadow) {
		create->mem = qxl_bo_physical_address(qdev, bo->shadow, offset);
	} else {
		create->mem = qxl_bo_physical_address(qdev, bo, offset);
	}

	DRM_DEBUG_DRIVER("mem = %llx, from %p\n", create->mem, bo->kptr);

	create->flags = QXL_SURF_FLAG_KEEP_DATA;
	create->type = QXL_SURF_TYPE_PRIMARY;

	wait_for_io_cmd(qdev, 0, QXL_IO_CREATE_PRIMARY_ASYNC);
	qdev->primary_created = true;
}

void qxl_io_memslot_add(struct qxl_device *qdev, uint8_t id)
{
	DRM_DEBUG_DRIVER("qxl_memslot_add %d\n", id);
	wait_for_io_cmd(qdev, id, QXL_IO_MEMSLOT_ADD_ASYNC);
}

void qxl_io_reset(struct qxl_device *qdev)
{
	outb(0, qdev->io_base + QXL_IO_RESET);
}

void qxl_io_monitors_config(struct qxl_device *qdev)
{
	wait_for_io_cmd(qdev, 0, QXL_IO_MONITORS_CONFIG_ASYNC);
}

int qxl_surface_id_alloc(struct qxl_device *qdev,
		      struct qxl_bo *surf)
{
	uint32_t handle;
	int idr_ret;
	int count = 0;
again:
	idr_preload(GFP_ATOMIC);
	spin_lock(&qdev->surf_id_idr_lock);
	idr_ret = idr_alloc(&qdev->surf_id_idr, NULL, 1, 0, GFP_NOWAIT);
	spin_unlock(&qdev->surf_id_idr_lock);
	idr_preload_end();
	if (idr_ret < 0)
		return idr_ret;
	handle = idr_ret;

	if (handle >= qdev->rom->n_surfaces) {
		count++;
		spin_lock(&qdev->surf_id_idr_lock);
		idr_remove(&qdev->surf_id_idr, handle);
		spin_unlock(&qdev->surf_id_idr_lock);
		qxl_reap_surface_id(qdev, 2);
		goto again;
	}
	surf->surface_id = handle;

	spin_lock(&qdev->surf_id_idr_lock);
	qdev->last_alloced_surf_id = handle;
	spin_unlock(&qdev->surf_id_idr_lock);
	return 0;
}

void qxl_surface_id_dealloc(struct qxl_device *qdev,
			    uint32_t surface_id)
{
	spin_lock(&qdev->surf_id_idr_lock);
	idr_remove(&qdev->surf_id_idr, surface_id);
	spin_unlock(&qdev->surf_id_idr_lock);
}

int qxl_hw_surface_alloc(struct qxl_device *qdev,
			 struct qxl_bo *surf,
			 struct ttm_mem_reg *new_mem)
{
	struct qxl_surface_cmd *cmd;
	struct qxl_release *release;
	int ret;

	if (surf->hw_surf_alloc)
		return 0;

	ret = qxl_alloc_surface_release_reserved(qdev, QXL_SURFACE_CMD_CREATE,
						 NULL,
						 &release);
	if (ret)
		return ret;

	ret = qxl_release_reserve_list(release, true);
	if (ret)
		return ret;

	cmd = (struct qxl_surface_cmd *)qxl_release_map(qdev, release);
	cmd->type = QXL_SURFACE_CMD_CREATE;
	cmd->flags = QXL_SURF_FLAG_KEEP_DATA;
	cmd->u.surface_create.format = surf->surf.format;
	cmd->u.surface_create.width = surf->surf.width;
	cmd->u.surface_create.height = surf->surf.height;
	cmd->u.surface_create.stride = surf->surf.stride;
	if (new_mem) {
		int slot_id = surf->type == QXL_GEM_DOMAIN_VRAM ? qdev->main_mem_slot : qdev->surfaces_mem_slot;
		struct qxl_memslot *slot = &(qdev->mem_slots[slot_id]);

		/* TODO - need to hold one of the locks to read tbo.offset */
		cmd->u.surface_create.data = slot->high_bits;

		cmd->u.surface_create.data |= (new_mem->start << PAGE_SHIFT) + surf->tbo.bdev->man[new_mem->mem_type].gpu_offset;
	} else
		cmd->u.surface_create.data = qxl_bo_physical_address(qdev, surf, 0);
	cmd->surface_id = surf->surface_id;
	qxl_release_unmap(qdev, release, &cmd->release_info);

	surf->surf_create = release;

	/* no need to add a release to the fence for this surface bo,
	   since it is only released when we ask to destroy the surface
	   and it would never signal otherwise */
	qxl_push_command_ring_release(qdev, release, QXL_CMD_SURFACE, false);
	qxl_release_fence_buffer_objects(release);

	surf->hw_surf_alloc = true;
	spin_lock(&qdev->surf_id_idr_lock);
	idr_replace(&qdev->surf_id_idr, surf, surf->surface_id);
	spin_unlock(&qdev->surf_id_idr_lock);
	return 0;
}

int qxl_hw_surface_dealloc(struct qxl_device *qdev,
			   struct qxl_bo *surf)
{
	struct qxl_surface_cmd *cmd;
	struct qxl_release *release;
	int ret;
	int id;

	if (!surf->hw_surf_alloc)
		return 0;

	ret = qxl_alloc_surface_release_reserved(qdev, QXL_SURFACE_CMD_DESTROY,
						 surf->surf_create,
						 &release);
	if (ret)
		return ret;

	surf->surf_create = NULL;
	/* remove the surface from the idr, but not the surface id yet */
	spin_lock(&qdev->surf_id_idr_lock);
	idr_replace(&qdev->surf_id_idr, NULL, surf->surface_id);
	spin_unlock(&qdev->surf_id_idr_lock);
	surf->hw_surf_alloc = false;

	id = surf->surface_id;
	surf->surface_id = 0;

	release->surface_release_id = id;
	cmd = (struct qxl_surface_cmd *)qxl_release_map(qdev, release);
	cmd->type = QXL_SURFACE_CMD_DESTROY;
	cmd->surface_id = id;
	qxl_release_unmap(qdev, release, &cmd->release_info);

	qxl_push_command_ring_release(qdev, release, QXL_CMD_SURFACE, false);

	qxl_release_fence_buffer_objects(release);

	return 0;
}

__attribute__((used)) static int qxl_update_surface(struct qxl_device *qdev, struct qxl_bo *surf)
{
	struct qxl_rect rect;
	int ret;

	/* if we are evicting, we need to make sure the surface is up
	   to date */
	rect.left = 0;
	rect.right = surf->surf.width;
	rect.top = 0;
	rect.bottom = surf->surf.height;
retry:
	ret = qxl_io_update_area(qdev, surf, &rect);
	if (ret == -ERESTARTSYS)
		goto retry;
	return ret;
}

__attribute__((used)) static void qxl_surface_evict_locked(struct qxl_device *qdev, struct qxl_bo *surf, bool do_update_area)
{
	/* no need to update area if we are just freeing the surface normally */
	if (do_update_area)
		qxl_update_surface(qdev, surf);

	/* nuke the surface id at the hw */
	qxl_hw_surface_dealloc(qdev, surf);
}

void qxl_surface_evict(struct qxl_device *qdev, struct qxl_bo *surf, bool do_update_area)
{
	mutex_lock(&qdev->surf_evict_mutex);
	qxl_surface_evict_locked(qdev, surf, do_update_area);
	mutex_unlock(&qdev->surf_evict_mutex);
}

__attribute__((used)) static int qxl_reap_surf(struct qxl_device *qdev, struct qxl_bo *surf, bool stall)
{
	int ret;

	ret = qxl_bo_reserve(surf, false);
	if (ret)
		return ret;

	if (stall)
		mutex_unlock(&qdev->surf_evict_mutex);

	ret = ttm_bo_wait(&surf->tbo, true, !stall);

	if (stall)
		mutex_lock(&qdev->surf_evict_mutex);
	if (ret) {
		qxl_bo_unreserve(surf);
		return ret;
	}

	qxl_surface_evict_locked(qdev, surf, true);
	qxl_bo_unreserve(surf);
	return 0;
}

__attribute__((used)) static int qxl_reap_surface_id(struct qxl_device *qdev, int max_to_reap)
{
	int num_reaped = 0;
	int i, ret;
	bool stall = false;
	int start = 0;

	mutex_lock(&qdev->surf_evict_mutex);
again:

	spin_lock(&qdev->surf_id_idr_lock);
	start = qdev->last_alloced_surf_id + 1;
	spin_unlock(&qdev->surf_id_idr_lock);

	for (i = start; i < start + qdev->rom->n_surfaces; i++) {
		void *objptr;
		int surfid = i % qdev->rom->n_surfaces;

		/* this avoids the case where the objects is in the
		   idr but has been evicted half way - its makes
		   the idr lookup atomic with the eviction */
		spin_lock(&qdev->surf_id_idr_lock);
		objptr = idr_find(&qdev->surf_id_idr, surfid);
		spin_unlock(&qdev->surf_id_idr_lock);

		if (!objptr)
			continue;

		ret = qxl_reap_surf(qdev, objptr, stall);
		if (ret == 0)
			num_reaped++;
		if (num_reaped >= max_to_reap)
			break;
	}
	if (num_reaped == 0 && stall == false) {
		stall = true;
		goto again;
	}

	mutex_unlock(&qdev->surf_evict_mutex);
	if (num_reaped) {
		usleep_range(500, 1000);
		qxl_queue_garbage_collect(qdev, true);
	}

	return 0;
}

