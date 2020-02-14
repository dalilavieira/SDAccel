#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct gen_pool {int dummy; } ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {scalar_t__ sram_dma; } ;

/* Variables and functions */
 TYPE_1__ davinci_soc_info ; 
 void* gen_pool_dma_alloc (struct gen_pool*,size_t,scalar_t__*) ; 
 int /*<<< orphan*/  gen_pool_free (struct gen_pool*,unsigned long,size_t) ; 
 struct gen_pool* sram_pool ; 

struct gen_pool *sram_get_gen_pool(void)
{
	return sram_pool;
}

void *sram_alloc(size_t len, dma_addr_t *dma)
{
	dma_addr_t dma_base = davinci_soc_info.sram_dma;

	if (dma)
		*dma = 0;
	if (!sram_pool || (dma && !dma_base))
		return NULL;

	return gen_pool_dma_alloc(sram_pool, len, dma);

}

void sram_free(void *addr, size_t len)
{
	gen_pool_free(sram_pool, (unsigned long) addr, len);
}

