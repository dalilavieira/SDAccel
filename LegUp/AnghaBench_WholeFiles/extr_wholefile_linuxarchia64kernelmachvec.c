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
struct scatterlist {int dummy; } ;
struct device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  mb () ; 

void
machvec_setup (char **arg)
{
}

void
machvec_timer_interrupt (int irq, void *dev_id)
{
}

void
machvec_dma_sync_single(struct device *hwdev, dma_addr_t dma_handle, size_t size,
			enum dma_data_direction dir)
{
	mb();
}

void
machvec_dma_sync_sg(struct device *hwdev, struct scatterlist *sg, int n,
		    enum dma_data_direction dir)
{
	mb();
}

