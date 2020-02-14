#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u32 ;
struct timespec64 {int dummy; } ;
struct timespec {int dummy; } ;
struct etnaviv_gpu {int mmio; int completed_fence; int /*<<< orphan*/  dev; } ;
struct etnaviv_cmdbuf_suballoc {int paddr; int iova; int free_space; int /*<<< orphan*/  free_event; int /*<<< orphan*/  lock; int /*<<< orphan*/  granule_map; scalar_t__ vaddr; struct etnaviv_gpu* gpu; int /*<<< orphan*/  vram_node; } ;
struct etnaviv_cmdbuf {int size; int suballoc_offset; struct etnaviv_cmdbuf_suballoc* suballoc; scalar_t__ vaddr; } ;
typedef  scalar_t__ s32 ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int ALIGN (int,int) ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct etnaviv_cmdbuf_suballoc* ERR_PTR (int /*<<< orphan*/ ) ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 size_t SIZE_MAX ; 
 int SUBALLOC_GRANULE ; 
 int /*<<< orphan*/  SUBALLOC_GRANULES ; 
 int /*<<< orphan*/  SUBALLOC_SIZE ; 
 int bitmap_find_free_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bitmap_release_region (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ dma_alloc_wc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_wc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int etnaviv_iommu_get_suballoc_va (struct etnaviv_gpu*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  etnaviv_iommu_put_suballoc_va (struct etnaviv_gpu*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct etnaviv_cmdbuf_suballoc*) ; 
 int /*<<< orphan*/  ktime_get_ts64 (struct timespec64*) ; 
 struct etnaviv_cmdbuf_suballoc* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int order_base_2 (int) ; 
 int readl (int) ; 
 scalar_t__ timespec64_compare (struct timespec64*,struct timespec64*) ; 
 struct timespec64 timespec64_sub (struct timespec64,struct timespec64) ; 
 unsigned long timespec64_to_jiffies (struct timespec64*) ; 
 struct timespec64 timespec_to_timespec64 (struct timespec const) ; 
 int wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up_all (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline size_t size_vstruct(size_t nelem, size_t elem_size, size_t base)
{
	if (elem_size && nelem > (SIZE_MAX - base) / elem_size)
		return 0;
	return base + nelem * elem_size;
}

__attribute__((used)) static inline bool fence_after(u32 a, u32 b)
{
	return (s32)(a - b) > 0;
}

__attribute__((used)) static inline bool fence_after_eq(u32 a, u32 b)
{
	return (s32)(a - b) >= 0;
}

__attribute__((used)) static inline unsigned long etnaviv_timeout_to_jiffies(
	const struct timespec *timeout)
{
	struct timespec64 ts, to;

	to = timespec_to_timespec64(*timeout);

	ktime_get_ts64(&ts);

	/* timeouts before "now" have already expired */
	if (timespec64_compare(&to, &ts) <= 0)
		return 0;

	ts = timespec64_sub(to, ts);

	return timespec64_to_jiffies(&ts);
}

__attribute__((used)) static inline void gpu_write(struct etnaviv_gpu *gpu, u32 reg, u32 data)
{
	writel(data, gpu->mmio + reg);
}

__attribute__((used)) static inline u32 gpu_read(struct etnaviv_gpu *gpu, u32 reg)
{
	return readl(gpu->mmio + reg);
}

__attribute__((used)) static inline bool fence_completed(struct etnaviv_gpu *gpu, u32 fence)
{
	return fence_after_eq(gpu->completed_fence, fence);
}

struct etnaviv_cmdbuf_suballoc *
etnaviv_cmdbuf_suballoc_new(struct etnaviv_gpu * gpu)
{
	struct etnaviv_cmdbuf_suballoc *suballoc;
	int ret;

	suballoc = kzalloc(sizeof(*suballoc), GFP_KERNEL);
	if (!suballoc)
		return ERR_PTR(-ENOMEM);

	suballoc->gpu = gpu;
	mutex_init(&suballoc->lock);
	init_waitqueue_head(&suballoc->free_event);

	suballoc->vaddr = dma_alloc_wc(gpu->dev, SUBALLOC_SIZE,
				       &suballoc->paddr, GFP_KERNEL);
	if (!suballoc->vaddr)
		goto free_suballoc;

	ret = etnaviv_iommu_get_suballoc_va(gpu, suballoc->paddr,
					    &suballoc->vram_node, SUBALLOC_SIZE,
					    &suballoc->iova);
	if (ret)
		goto free_dma;

	return suballoc;

free_dma:
	dma_free_wc(gpu->dev, SUBALLOC_SIZE, suballoc->vaddr, suballoc->paddr);
free_suballoc:
	kfree(suballoc);

	return NULL;
}

void etnaviv_cmdbuf_suballoc_destroy(struct etnaviv_cmdbuf_suballoc *suballoc)
{
	etnaviv_iommu_put_suballoc_va(suballoc->gpu, &suballoc->vram_node,
				      SUBALLOC_SIZE, suballoc->iova);
	dma_free_wc(suballoc->gpu->dev, SUBALLOC_SIZE, suballoc->vaddr,
		    suballoc->paddr);
	kfree(suballoc);
}

int etnaviv_cmdbuf_init(struct etnaviv_cmdbuf_suballoc *suballoc,
			struct etnaviv_cmdbuf *cmdbuf, u32 size)
{
	int granule_offs, order, ret;

	cmdbuf->suballoc = suballoc;
	cmdbuf->size = size;

	order = order_base_2(ALIGN(size, SUBALLOC_GRANULE) / SUBALLOC_GRANULE);
retry:
	mutex_lock(&suballoc->lock);
	granule_offs = bitmap_find_free_region(suballoc->granule_map,
					SUBALLOC_GRANULES, order);
	if (granule_offs < 0) {
		suballoc->free_space = 0;
		mutex_unlock(&suballoc->lock);
		ret = wait_event_interruptible_timeout(suballoc->free_event,
						       suballoc->free_space,
						       msecs_to_jiffies(10 * 1000));
		if (!ret) {
			dev_err(suballoc->gpu->dev,
				"Timeout waiting for cmdbuf space\n");
			return -ETIMEDOUT;
		}
		goto retry;
	}
	mutex_unlock(&suballoc->lock);
	cmdbuf->suballoc_offset = granule_offs * SUBALLOC_GRANULE;
	cmdbuf->vaddr = suballoc->vaddr + cmdbuf->suballoc_offset;

	return 0;
}

void etnaviv_cmdbuf_free(struct etnaviv_cmdbuf *cmdbuf)
{
	struct etnaviv_cmdbuf_suballoc *suballoc = cmdbuf->suballoc;
	int order = order_base_2(ALIGN(cmdbuf->size, SUBALLOC_GRANULE) /
				 SUBALLOC_GRANULE);

	mutex_lock(&suballoc->lock);
	bitmap_release_region(suballoc->granule_map,
			      cmdbuf->suballoc_offset / SUBALLOC_GRANULE,
			      order);
	suballoc->free_space = 1;
	mutex_unlock(&suballoc->lock);
	wake_up_all(&suballoc->free_event);
}

u32 etnaviv_cmdbuf_get_va(struct etnaviv_cmdbuf *buf)
{
	return buf->suballoc->iova + buf->suballoc_offset;
}

dma_addr_t etnaviv_cmdbuf_get_pa(struct etnaviv_cmdbuf *buf)
{
	return buf->suballoc->paddr + buf->suballoc_offset;
}

