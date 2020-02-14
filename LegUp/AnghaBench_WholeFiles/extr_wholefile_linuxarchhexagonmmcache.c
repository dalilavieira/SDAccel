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
struct vm_area_struct {int vm_flags; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int LINESIZE ; 
 int VM_EXEC ; 
 int /*<<< orphan*/  __vmcache_dckill () ; 
 int /*<<< orphan*/  __vmcache_ickill () ; 
 int /*<<< orphan*/  __vmcache_l2kill () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 unsigned long spanlines (unsigned long,unsigned long) ; 

void flush_dcache_range(unsigned long start, unsigned long end)
{
	unsigned long lines = spanlines(start, end-1);
	unsigned long i, flags;

	start &= ~(LINESIZE - 1);

	local_irq_save(flags);

	for (i = 0; i < lines; i++) {
		__asm__ __volatile__ (
		"	dccleaninva(%0);	"
		:
		: "r" (start)
		);
		start += LINESIZE;
	}
	local_irq_restore(flags);
}

void flush_icache_range(unsigned long start, unsigned long end)
{
	unsigned long lines = spanlines(start, end-1);
	unsigned long i, flags;

	start &= ~(LINESIZE - 1);

	local_irq_save(flags);

	for (i = 0; i < lines; i++) {
		__asm__ __volatile__ (
			"	dccleana(%0); "
			"	icinva(%0);	"
			:
			: "r" (start)
		);
		start += LINESIZE;
	}
	__asm__ __volatile__ (
		"isync"
	);
	local_irq_restore(flags);
}

void hexagon_clean_dcache_range(unsigned long start, unsigned long end)
{
	unsigned long lines = spanlines(start, end-1);
	unsigned long i, flags;

	start &= ~(LINESIZE - 1);

	local_irq_save(flags);

	for (i = 0; i < lines; i++) {
		__asm__ __volatile__ (
		"	dccleana(%0);	"
		:
		: "r" (start)
		);
		start += LINESIZE;
	}
	local_irq_restore(flags);
}

void hexagon_inv_dcache_range(unsigned long start, unsigned long end)
{
	unsigned long lines = spanlines(start, end-1);
	unsigned long i, flags;

	start &= ~(LINESIZE - 1);

	local_irq_save(flags);

	for (i = 0; i < lines; i++) {
		__asm__ __volatile__ (
		"	dcinva(%0);	"
		:
		: "r" (start)
		);
		start += LINESIZE;
	}
	local_irq_restore(flags);
}

void flush_cache_all_hexagon(void)
{
	unsigned long flags;
	local_irq_save(flags);
	__vmcache_ickill();
	__vmcache_dckill();
	__vmcache_l2kill();
	local_irq_restore(flags);
	mb();
}

void copy_to_user_page(struct vm_area_struct *vma, struct page *page,
		       unsigned long vaddr, void *dst, void *src, int len)
{
	memcpy(dst, src, len);
	if (vma->vm_flags & VM_EXEC) {
		flush_icache_range((unsigned long) dst,
		(unsigned long) dst + len);
	}
}

