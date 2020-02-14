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

/* Variables and functions */
 unsigned long IO_TLB_DEFAULT_SIZE ; 
 unsigned long IO_TLB_SHIFT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ SWIOTLB_FORCE ; 
 scalar_t__ io_tlb_end ; 
 unsigned long io_tlb_nslabs ; 
 scalar_t__ io_tlb_start ; 
 unsigned int max_segment ; 
 scalar_t__ no_iotlb_memory ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long long,unsigned long long,unsigned long) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 unsigned int rounddown (unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ swiotlb_force ; 

unsigned long swiotlb_nr_tbl(void)
{
	return io_tlb_nslabs;
}

unsigned int swiotlb_max_segment(void)
{
	return max_segment;
}

void swiotlb_set_max_segment(unsigned int val)
{
	if (swiotlb_force == SWIOTLB_FORCE)
		max_segment = 1;
	else
		max_segment = rounddown(val, PAGE_SIZE);
}

unsigned long swiotlb_size_or_default(void)
{
	unsigned long size;

	size = io_tlb_nslabs << IO_TLB_SHIFT;

	return size ? size : (IO_TLB_DEFAULT_SIZE);
}

void swiotlb_print_info(void)
{
	unsigned long bytes = io_tlb_nslabs << IO_TLB_SHIFT;

	if (no_iotlb_memory) {
		pr_warn("No low mem\n");
		return;
	}

	pr_info("mapped [mem %#010llx-%#010llx] (%luMB)\n",
	       (unsigned long long)io_tlb_start,
	       (unsigned long long)io_tlb_end,
	       bytes >> 20);
}

