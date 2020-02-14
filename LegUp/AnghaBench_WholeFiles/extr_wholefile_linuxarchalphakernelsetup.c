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
struct notifier_block {int dummy; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 int NOTIFY_DONE ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __halt () ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 scalar_t__ alpha_using_srm ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 scalar_t__ srmcons_output ; 

__attribute__((used)) static inline void find_console_vga_hose(void) { }

__attribute__((used)) static inline void locate_and_init_vga(void *(*sel_func)(void *, void *)) { }

__attribute__((used)) static inline int
__alpha_remap_area_pages(unsigned long address, unsigned long phys_addr,
			 unsigned long size, unsigned long flags)
{
	pgprot_t prot;

	prot = __pgprot(_PAGE_VALID | _PAGE_ASM | _PAGE_KRE
			| _PAGE_KWE | flags);
	return ioremap_page_range(address, address + size, phys_addr, prot);
}

__attribute__((used)) static int
alpha_panic_event(struct notifier_block *this, unsigned long event, void *ptr)
{
#if 1
	/* FIXME FIXME FIXME */
	/* If we are using SRM and serial console, just hard halt here. */
	if (alpha_using_srm && srmcons_output)
		__halt();
#endif
        return NOTIFY_DONE;
}

