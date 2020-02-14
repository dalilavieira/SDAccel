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
 unsigned int IMCR_CCFG ; 
 unsigned int IMCR_L1DCFG ; 
 unsigned int IMCR_L1DIBAR ; 
 unsigned int IMCR_L1DINV ; 
 unsigned int IMCR_L1DIWC ; 
 unsigned int IMCR_L1DWB ; 
 unsigned int IMCR_L1DWBAR ; 
 unsigned int IMCR_L1DWBINV ; 
 unsigned int IMCR_L1DWIBAR ; 
 unsigned int IMCR_L1DWIWC ; 
 unsigned int IMCR_L1DWWC ; 
 unsigned int IMCR_L1PCFG ; 
 unsigned int IMCR_L1PIBAR ; 
 unsigned int IMCR_L1PINV ; 
 unsigned int IMCR_L1PIWC ; 
 unsigned int IMCR_L2IBAR ; 
 unsigned int IMCR_L2IWC ; 
 unsigned int IMCR_L2WB ; 
 unsigned int IMCR_L2WBAR ; 
 unsigned int IMCR_L2WBINV ; 
 unsigned int IMCR_L2WIBAR ; 
 unsigned int IMCR_L2WIWC ; 
 unsigned int IMCR_L2WWC ; 
 unsigned long IMCR_MAR_BASE ; 
 int L2_CACHE_ALIGN_CNT (unsigned int) ; 
 int L2_CACHE_ALIGN_LOW (unsigned int) ; 
 int /*<<< orphan*/  cache_lock ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int imcr_get (unsigned int) ; 
 int /*<<< orphan*/  imcr_set (unsigned int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void cache_block_operation_wait(unsigned int wc_reg)
{
	/* Wait for completion */
	while (imcr_get(wc_reg))
		cpu_relax();
}

__attribute__((used)) static void cache_block_operation(unsigned int *start,
				  unsigned int *end,
				  unsigned int bar_reg,
				  unsigned int wc_reg)
{
	unsigned long flags;
	unsigned int wcnt =
		(L2_CACHE_ALIGN_CNT((unsigned int) end)
		 - L2_CACHE_ALIGN_LOW((unsigned int) start)) >> 2;
	unsigned int wc = 0;

	for (; wcnt; wcnt -= wc, start += wc) {
loop:
		spin_lock_irqsave(&cache_lock, flags);

		/*
		 * If another cache operation is occurring
		 */
		if (unlikely(imcr_get(wc_reg))) {
			spin_unlock_irqrestore(&cache_lock, flags);

			/* Wait for previous operation completion */
			cache_block_operation_wait(wc_reg);

			/* Try again */
			goto loop;
		}

		imcr_set(bar_reg, L2_CACHE_ALIGN_LOW((unsigned int) start));

		if (wcnt > 0xffff)
			wc = 0xffff;
		else
			wc = wcnt;

		/* Set word count value in the WC register */
		imcr_set(wc_reg, wc & 0xffff);

		spin_unlock_irqrestore(&cache_lock, flags);

		/* Wait for completion */
		cache_block_operation_wait(wc_reg);
	}
}

__attribute__((used)) static void cache_block_operation_nowait(unsigned int *start,
					 unsigned int *end,
					 unsigned int bar_reg,
					 unsigned int wc_reg)
{
	unsigned long flags;
	unsigned int wcnt =
		(L2_CACHE_ALIGN_CNT((unsigned int) end)
		 - L2_CACHE_ALIGN_LOW((unsigned int) start)) >> 2;
	unsigned int wc = 0;

	for (; wcnt; wcnt -= wc, start += wc) {

		spin_lock_irqsave(&cache_lock, flags);

		imcr_set(bar_reg, L2_CACHE_ALIGN_LOW((unsigned int) start));

		if (wcnt > 0xffff)
			wc = 0xffff;
		else
			wc = wcnt;

		/* Set word count value in the WC register */
		imcr_set(wc_reg, wc & 0xffff);

		spin_unlock_irqrestore(&cache_lock, flags);

		/* Don't wait for completion on last cache operation */
		if (wcnt > 0xffff)
			cache_block_operation_wait(wc_reg);
	}
}

void L1_cache_off(void)
{
	unsigned int dummy;

	imcr_set(IMCR_L1PCFG, 0);
	dummy = imcr_get(IMCR_L1PCFG);

	imcr_set(IMCR_L1DCFG, 0);
	dummy = imcr_get(IMCR_L1DCFG);
}

void L1_cache_on(void)
{
	unsigned int dummy;

	imcr_set(IMCR_L1PCFG, 7);
	dummy = imcr_get(IMCR_L1PCFG);

	imcr_set(IMCR_L1DCFG, 7);
	dummy = imcr_get(IMCR_L1DCFG);
}

void L1P_cache_global_invalidate(void)
{
	unsigned int set = 1;
	imcr_set(IMCR_L1PINV, set);
	while (imcr_get(IMCR_L1PINV) & 1)
		cpu_relax();
}

void L1D_cache_global_invalidate(void)
{
	unsigned int set = 1;
	imcr_set(IMCR_L1DINV, set);
	while (imcr_get(IMCR_L1DINV) & 1)
		cpu_relax();
}

void L1D_cache_global_writeback(void)
{
	unsigned int set = 1;
	imcr_set(IMCR_L1DWB, set);
	while (imcr_get(IMCR_L1DWB) & 1)
		cpu_relax();
}

void L1D_cache_global_writeback_invalidate(void)
{
	unsigned int set = 1;
	imcr_set(IMCR_L1DWBINV, set);
	while (imcr_get(IMCR_L1DWBINV) & 1)
		cpu_relax();
}

void L2_cache_set_mode(unsigned int mode)
{
	unsigned int ccfg = imcr_get(IMCR_CCFG);

	/* Clear and set the L2MODE bits in CCFG */
	ccfg &= ~7;
	ccfg |= (mode & 7);
	imcr_set(IMCR_CCFG, ccfg);
	ccfg = imcr_get(IMCR_CCFG);
}

void L2_cache_global_writeback_invalidate(void)
{
	imcr_set(IMCR_L2WBINV, 1);
	while (imcr_get(IMCR_L2WBINV))
		cpu_relax();
}

void L2_cache_global_writeback(void)
{
	imcr_set(IMCR_L2WB, 1);
	while (imcr_get(IMCR_L2WB))
		cpu_relax();
}

void enable_caching(unsigned long start, unsigned long end)
{
	unsigned int mar = IMCR_MAR_BASE + ((start >> 24) << 2);
	unsigned int mar_e = IMCR_MAR_BASE + ((end >> 24) << 2);

	for (; mar <= mar_e; mar += 4)
		imcr_set(mar, imcr_get(mar) | 1);
}

void disable_caching(unsigned long start, unsigned long end)
{
	unsigned int mar = IMCR_MAR_BASE + ((start >> 24) << 2);
	unsigned int mar_e = IMCR_MAR_BASE + ((end >> 24) << 2);

	for (; mar <= mar_e; mar += 4)
		imcr_set(mar, imcr_get(mar) & ~1);
}

void L1P_cache_block_invalidate(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L1PIBAR, IMCR_L1PIWC);
}

void L1D_cache_block_invalidate(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L1DIBAR, IMCR_L1DIWC);
}

void L1D_cache_block_writeback_invalidate(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L1DWIBAR, IMCR_L1DWIWC);
}

void L1D_cache_block_writeback(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L1DWBAR, IMCR_L1DWWC);
}

void L2_cache_block_invalidate(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L2IBAR, IMCR_L2IWC);
}

void L2_cache_block_writeback(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L2WBAR, IMCR_L2WWC);
}

void L2_cache_block_writeback_invalidate(unsigned int start, unsigned int end)
{
	cache_block_operation((unsigned int *) start,
			      (unsigned int *) end,
			      IMCR_L2WIBAR, IMCR_L2WIWC);
}

void L2_cache_block_invalidate_nowait(unsigned int start, unsigned int end)
{
	cache_block_operation_nowait((unsigned int *) start,
				     (unsigned int *) end,
				     IMCR_L2IBAR, IMCR_L2IWC);
}

void L2_cache_block_writeback_nowait(unsigned int start, unsigned int end)
{
	cache_block_operation_nowait((unsigned int *) start,
				     (unsigned int *) end,
				     IMCR_L2WBAR, IMCR_L2WWC);
}

void L2_cache_block_writeback_invalidate_nowait(unsigned int start,
						unsigned int end)
{
	cache_block_operation_nowait((unsigned int *) start,
				     (unsigned int *) end,
				     IMCR_L2WIBAR, IMCR_L2WIWC);
}

