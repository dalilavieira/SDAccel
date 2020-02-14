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
typedef  scalar_t__ u8 ;
typedef  size_t u64 ;
struct device_node {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dma_zalloc_coherent (struct device*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpaa_invalidate (void*) ; 
 struct device_node* of_parse_phandle (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_u64 (struct device_node*,char*,size_t*) ; 
 int of_reserved_mem_device_init_by_idx (struct device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  of_reserved_mem_device_release (struct device*) ; 
 int /*<<< orphan*/  prefetch (void*) ; 

__attribute__((used)) static inline void dpaa_flush(void *p)
{
	/*
	 * Only PPC needs to flush the cache currently - on ARM the mapping
	 * is non cacheable
	 */
#ifdef CONFIG_PPC
	flush_dcache_range((unsigned long)p, (unsigned long)p+64);
#endif
}

__attribute__((used)) static inline void dpaa_touch_ro(void *p)
{
#if (L1_CACHE_BYTES == 32)
	prefetch(p+32);
#endif
	prefetch(p);
}

__attribute__((used)) static inline void dpaa_invalidate_touch_ro(void *p)
{
	dpaa_invalidate(p);
	dpaa_touch_ro(p);
}

__attribute__((used)) static inline u8 dpaa_cyc_diff(u8 ringsize, u8 first, u8 last)
{
	/* 'first' is included, 'last' is excluded */
	if (first <= last)
		return last - first;
	return ringsize + last - first;
}

int qbman_init_private_mem(struct device *dev, int idx, dma_addr_t *addr,
				size_t *size)
{
	int ret;
	struct device_node *mem_node;
	u64 size64;

	ret = of_reserved_mem_device_init_by_idx(dev, dev->of_node, idx);
	if (ret) {
		dev_err(dev,
			"of_reserved_mem_device_init_by_idx(%d) failed 0x%x\n",
			idx, ret);
		return -ENODEV;
	}
	mem_node = of_parse_phandle(dev->of_node, "memory-region", 0);
	if (mem_node) {
		ret = of_property_read_u64(mem_node, "size", &size64);
		if (ret) {
			dev_err(dev, "of_address_to_resource fails 0x%x\n",
			        ret);
			return -ENODEV;
		}
		*size = size64;
	} else {
		dev_err(dev, "No memory-region found for index %d\n", idx);
		return -ENODEV;
	}

	if (!dma_zalloc_coherent(dev, *size, addr, 0)) {
		dev_err(dev, "DMA Alloc memory failed\n");
		return -ENODEV;
	}

	/*
	 * Disassociate the reserved memory area from the device
	 * because a device can only have one DMA memory area. This
	 * should be fine since the memory is allocated and initialized
	 * and only ever accessed by the QBMan device from now on
	 */
	of_reserved_mem_device_release(dev);
	return 0;
}

