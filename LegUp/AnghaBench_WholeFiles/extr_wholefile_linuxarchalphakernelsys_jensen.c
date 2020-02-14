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
struct irq_data {int irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int /*<<< orphan*/  i8259a_disable_irq (struct irq_data*) ; 
 int /*<<< orphan*/  i8259a_enable_irq (struct irq_data*) ; 
 int /*<<< orphan*/  i8259a_mask_and_ack_irq (struct irq_data*) ; 
 int /*<<< orphan*/  inb (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_has_action (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 

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

__attribute__((used)) static void
jensen_local_enable(struct irq_data *d)
{
	/* the parport is really hw IRQ 1, silly Jensen.  */
	if (d->irq == 7)
		i8259a_enable_irq(d);
}

__attribute__((used)) static void
jensen_local_disable(struct irq_data *d)
{
	/* the parport is really hw IRQ 1, silly Jensen.  */
	if (d->irq == 7)
		i8259a_disable_irq(d);
}

__attribute__((used)) static void
jensen_local_mask_ack(struct irq_data *d)
{
	/* the parport is really hw IRQ 1, silly Jensen.  */
	if (d->irq == 7)
		i8259a_mask_and_ack_irq(d);
}

__attribute__((used)) static void 
jensen_device_interrupt(unsigned long vector)
{
	int irq;

	switch (vector) {
	case 0x660:
		printk("Whee.. NMI received. Probable hardware error\n");
		printk("61=%02x, 461=%02x\n", inb(0x61), inb(0x461));
		return;

	/* local device interrupts: */
	case 0x900: irq = 4; break;		/* com1 -> irq 4 */
	case 0x920: irq = 3; break;		/* com2 -> irq 3 */
	case 0x980: irq = 1; break;		/* kbd -> irq 1 */
	case 0x990: irq = 9; break;		/* mouse -> irq 9 */

	default:
		if (vector > 0x900) {
			printk("Unknown local interrupt %lx\n", vector);
			return;
		}

		irq = (vector - 0x800) >> 4;
		if (irq == 1)
			irq = 7;
		break;
	}

	/* If there is no handler yet... */
	if (!irq_has_action(irq)) {
	    /* If it is a local interrupt that cannot be masked... */
	    if (vector >= 0x900)
	    {
	        /* Clear keyboard/mouse state */
	    	inb(0x64);
		inb(0x60);
		/* Reset serial ports */
		inb(0x3fa);
		inb(0x2fa);
		outb(0x0c, 0x3fc);
		outb(0x0c, 0x2fc);
		/* Clear NMI */
		outb(0,0x61);
		outb(0,0x461);
	    }
	}

#if 0
        /* A useful bit of code to find out if an interrupt is going wild.  */
        {
          static unsigned int last_msg = 0, last_cc = 0;
          static int last_irq = -1, count = 0;
          unsigned int cc;

          __asm __volatile("rpcc %0" : "=r"(cc));
          ++count;
#define JENSEN_CYCLES_PER_SEC	(150000000)
          if (cc - last_msg > ((JENSEN_CYCLES_PER_SEC) * 3) ||
	      irq != last_irq) {
                printk(KERN_CRIT " irq %d count %d cc %u @ %lx\n",
                       irq, count, cc-last_cc, get_irq_regs()->pc);
                count = 0;
                last_msg = cc;
                last_irq = irq;
          }
          last_cc = cc;
        }
#endif

	handle_irq(irq);
}

