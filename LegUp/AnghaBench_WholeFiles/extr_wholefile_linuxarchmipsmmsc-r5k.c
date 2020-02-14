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
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned long INDEX_BASE ; 
 int /*<<< orphan*/  R5K_CONF_SE ; 
 int /*<<< orphan*/  R5K_Page_Invalidate_S ; 
 unsigned long SC_PAGE ; 
 int /*<<< orphan*/ * bcops ; 
 int /*<<< orphan*/  cache_op (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  clear_c0_config (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  r5k_sc_ops ; 
 scalar_t__ r5k_sc_probe () ; 
 unsigned long scache_size ; 
 int /*<<< orphan*/  set_c0_config (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void blast_r5000_scache(void)
{
	unsigned long start = INDEX_BASE;
	unsigned long end = start + scache_size;

	while(start < end) {
		cache_op(R5K_Page_Invalidate_S, start);
		start += SC_PAGE;
	}
}

__attribute__((used)) static void r5k_dma_cache_inv_sc(unsigned long addr, unsigned long size)
{
	unsigned long end, a;

	/* Catch bad driver code */
	BUG_ON(size == 0);

	if (size >= scache_size) {
		blast_r5000_scache();
		return;
	}

	/* On the R5000 secondary cache we cannot
	 * invalidate less than a page at a time.
	 * The secondary cache is physically indexed, write-through.
	 */
	a = addr & ~(SC_PAGE - 1);
	end = (addr + size - 1) & ~(SC_PAGE - 1);
	while (a <= end) {
		cache_op(R5K_Page_Invalidate_S, a);
		a += SC_PAGE;
	}
}

__attribute__((used)) static void r5k_sc_enable(void)
{
	unsigned long flags;

	local_irq_save(flags);
	set_c0_config(R5K_CONF_SE);
	blast_r5000_scache();
	local_irq_restore(flags);
}

__attribute__((used)) static void r5k_sc_disable(void)
{
	unsigned long flags;

	local_irq_save(flags);
	blast_r5000_scache();
	clear_c0_config(R5K_CONF_SE);
	local_irq_restore(flags);
}

void r5k_sc_init(void)
{
	if (r5k_sc_probe()) {
		r5k_sc_enable();
		bcops = &r5k_sc_ops;
	}
}

