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
struct starfire_irqinfo {unsigned long hwmid; unsigned long* imap_slots; unsigned long* tregs; int upaid; struct starfire_irqinfo* next; } ;
typedef  int s32 ;
typedef  scalar_t__ phandle ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct starfire_irqinfo* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  printk (char*) ; 
 scalar_t__ prom_finddevice (char*) ; 
 int /*<<< orphan*/  prom_halt () ; 
 int /*<<< orphan*/  prom_printf (char*,...) ; 
 struct starfire_irqinfo* sflist ; 
 int this_is_starfire ; 
 scalar_t__ upa_readl (unsigned long) ; 
 int /*<<< orphan*/  upa_writel (unsigned int,unsigned long) ; 

void check_if_starfire(void)
{
	phandle ssnode = prom_finddevice("/ssp-serial");
	if (ssnode != 0 && (s32)ssnode != -1)
		this_is_starfire = 1;
}

void starfire_hookup(int upaid)
{
	struct starfire_irqinfo *p;
	unsigned long treg_base, hwmid, i;

	p = kmalloc(sizeof(*p), GFP_KERNEL);
	if (!p) {
		prom_printf("starfire_hookup: No memory, this is insane.\n");
		prom_halt();
	}
	treg_base = 0x100fc000000UL;
	hwmid = ((upaid & 0x3c) << 1) |
		((upaid & 0x40) >> 4) |
		(upaid & 0x3);
	p->hwmid = hwmid;
	treg_base += (hwmid << 33UL);
	treg_base += 0x200UL;
	for (i = 0; i < 32; i++) {
		p->imap_slots[i] = 0UL;
		p->tregs[i] = treg_base + (i * 0x10UL);
		/* Lets play it safe and not overwrite existing mappings */
		if (upa_readl(p->tregs[i]) != 0)
			p->imap_slots[i] = 0xdeadbeaf;
	}
	p->upaid = upaid;
	p->next = sflist;
	sflist = p;
}

unsigned int starfire_translate(unsigned long imap,
				unsigned int upaid)
{
	struct starfire_irqinfo *p;
	unsigned int bus_hwmid;
	unsigned int i;

	bus_hwmid = (((unsigned long)imap) >> 33) & 0x7f;
	for (p = sflist; p != NULL; p = p->next)
		if (p->hwmid == bus_hwmid)
			break;
	if (p == NULL) {
		prom_printf("XFIRE: Cannot find irqinfo for imap %016lx\n",
			    ((unsigned long)imap));
		prom_halt();
	}
	for (i = 0; i < 32; i++) {
		if (p->imap_slots[i] == imap ||
		    p->imap_slots[i] == 0UL)
			break;
	}
	if (i == 32) {
		printk("starfire_translate: Are you kidding me?\n");
		panic("Lucy in the sky....");
	}
	p->imap_slots[i] = imap;

	/* map to real upaid */
	upaid = (((upaid & 0x3c) << 1) |
		 ((upaid & 0x40) >> 4) |
		 (upaid & 0x3));

	upa_writel(upaid, p->tregs[i]);

	return i;
}

