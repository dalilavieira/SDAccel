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
struct dma_map_ops {int /*<<< orphan*/  (* dma_supported ) (struct device*,int /*<<< orphan*/ ) ;} ;
struct device {int /*<<< orphan*/ * dma_mask; } ;

/* Variables and functions */
 struct dma_map_ops const sba_dma_ops ; 
 int /*<<< orphan*/  stub1 (struct device*,int /*<<< orphan*/ ) ; 
 struct dma_map_ops const swiotlb_dma_ops ; 

__attribute__((used)) static inline int use_swiotlb(struct device *dev)
{
	return dev && dev->dma_mask &&
		!sba_dma_ops.dma_supported(dev, *dev->dma_mask);
}

const struct dma_map_ops *hwsw_dma_get_ops(struct device *dev)
{
	if (use_swiotlb(dev))
		return &swiotlb_dma_ops;
	return &sba_dma_ops;
}

