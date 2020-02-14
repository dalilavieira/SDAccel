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
struct device {int dummy; } ;
typedef  int phys_addr_t ;
typedef  int dma_addr_t ;

/* Variables and functions */
 scalar_t__ CRIME_HI_MEM_BASE ; 
 int RAM_OFFSET_MASK ; 

dma_addr_t __phys_to_dma(struct device *dev, phys_addr_t paddr)
{
	dma_addr_t dma_addr = paddr & RAM_OFFSET_MASK;

	if (!dev)
		dma_addr += CRIME_HI_MEM_BASE;
	return dma_addr;
}

phys_addr_t __dma_to_phys(struct device *dev, dma_addr_t dma_addr)
{
	phys_addr_t paddr = dma_addr & RAM_OFFSET_MASK;

	if (dma_addr >= 256*1024*1024)
		paddr += CRIME_HI_MEM_BASE;
	return paddr;
}

