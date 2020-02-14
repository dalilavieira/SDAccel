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
typedef  int /*<<< orphan*/  u32 ;
struct pt_regs {int /*<<< orphan*/  cp0_badvaddr; int /*<<< orphan*/  cp0_cause; int /*<<< orphan*/  cp0_status; int /*<<< orphan*/  cp0_epc; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned int BONITO_INTEDGE ; 
 unsigned int BONITO_INTEN ; 
 unsigned int BONITO_INTISR ; 
 unsigned int BONITO_INTPOL ; 
 unsigned int BONITO_INTSTEER ; 
 unsigned int BONITO_PCIBADADDR ; 
 unsigned int BONITO_PCICMD ; 
 int BONITO_PCIMAP_CFG ; 
 unsigned int BONITO_PCIMSTAT ; 
 int /*<<< orphan*/  GT_CPUERR_ADDRHI_OFS ; 
 int /*<<< orphan*/  GT_CPUERR_ADDRLO_OFS ; 
 int /*<<< orphan*/  GT_INTRCAUSE_OFS ; 
 int /*<<< orphan*/  GT_PCI0_IACK_OFS ; 
 void* GT_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
#define  MIPS_REVISION_SCON_BONITO 133 
#define  MIPS_REVISION_SCON_GT64120 132 
#define  MIPS_REVISION_SCON_ROCIT 131 
#define  MIPS_REVISION_SCON_SOCIT 130 
#define  MIPS_REVISION_SCON_SOCITSC 129 
#define  MIPS_REVISION_SCON_SOCITSCP 128 
 int /*<<< orphan*/  MSC01_PCI_IACK ; 
 int /*<<< orphan*/  MSC_READ (int /*<<< orphan*/ ,int) ; 
 int __raw_readl (int /*<<< orphan*/ *) ; 
 scalar_t__ _pcictrl_bonito_pcicfg ; 
 int /*<<< orphan*/  die (char*,struct pt_regs*) ; 
 struct pt_regs* get_irq_regs () ; 
 int /*<<< orphan*/  iob () ; 
 int /*<<< orphan*/  ll_msc_irq () ; 
 int mips_revision_sconid ; 
 int /*<<< orphan*/  pr_emerg (char*,...) ; 

__attribute__((used)) static inline int mips_pcibios_iack(void)
{
	int irq;

	/*
	 * Determine highest priority pending interrupt by performing
	 * a PCI Interrupt Acknowledge cycle.
	 */
	switch (mips_revision_sconid) {
	case MIPS_REVISION_SCON_SOCIT:
	case MIPS_REVISION_SCON_ROCIT:
	case MIPS_REVISION_SCON_SOCITSC:
	case MIPS_REVISION_SCON_SOCITSCP:
		MSC_READ(MSC01_PCI_IACK, irq);
		irq &= 0xff;
		break;
	case MIPS_REVISION_SCON_GT64120:
		irq = GT_READ(GT_PCI0_IACK_OFS);
		irq &= 0xff;
		break;
	case MIPS_REVISION_SCON_BONITO:
		/* The following will generate a PCI IACK cycle on the
		 * Bonito controller. It's a little bit kludgy, but it
		 * was the easiest way to implement it in hardware at
		 * the given time.
		 */
		BONITO_PCIMAP_CFG = 0x20000;

		/* Flush Bonito register block */
		(void) BONITO_PCIMAP_CFG;
		iob();	  /* sync */

		irq = __raw_readl((u32 *)_pcictrl_bonito_pcicfg);
		iob();	  /* sync */
		irq &= 0xff;
		BONITO_PCIMAP_CFG = 0;
		break;
	default:
		pr_emerg("Unknown system controller.\n");
		return -1;
	}
	return irq;
}

__attribute__((used)) static void corehi_irqdispatch(void)
{
	unsigned int intedge, intsteer, pcicmd, pcibadaddr;
	unsigned int pcimstat, intisr, inten, intpol;
	unsigned int intrcause, datalo, datahi;
	struct pt_regs *regs = get_irq_regs();

	pr_emerg("CoreHI interrupt, shouldn't happen, we die here!\n");
	pr_emerg("epc	 : %08lx\nStatus: %08lx\n"
		 "Cause : %08lx\nbadVaddr : %08lx\n",
		 regs->cp0_epc, regs->cp0_status,
		 regs->cp0_cause, regs->cp0_badvaddr);

	/* Read all the registers and then print them as there is a
	   problem with interspersed printk's upsetting the Bonito controller.
	   Do it for the others too.
	*/

	switch (mips_revision_sconid) {
	case MIPS_REVISION_SCON_SOCIT:
	case MIPS_REVISION_SCON_ROCIT:
	case MIPS_REVISION_SCON_SOCITSC:
	case MIPS_REVISION_SCON_SOCITSCP:
		ll_msc_irq();
		break;
	case MIPS_REVISION_SCON_GT64120:
		intrcause = GT_READ(GT_INTRCAUSE_OFS);
		datalo = GT_READ(GT_CPUERR_ADDRLO_OFS);
		datahi = GT_READ(GT_CPUERR_ADDRHI_OFS);
		pr_emerg("GT_INTRCAUSE = %08x\n", intrcause);
		pr_emerg("GT_CPUERR_ADDR = %02x%08x\n",
				datahi, datalo);
		break;
	case MIPS_REVISION_SCON_BONITO:
		pcibadaddr = BONITO_PCIBADADDR;
		pcimstat = BONITO_PCIMSTAT;
		intisr = BONITO_INTISR;
		inten = BONITO_INTEN;
		intpol = BONITO_INTPOL;
		intedge = BONITO_INTEDGE;
		intsteer = BONITO_INTSTEER;
		pcicmd = BONITO_PCICMD;
		pr_emerg("BONITO_INTISR = %08x\n", intisr);
		pr_emerg("BONITO_INTEN = %08x\n", inten);
		pr_emerg("BONITO_INTPOL = %08x\n", intpol);
		pr_emerg("BONITO_INTEDGE = %08x\n", intedge);
		pr_emerg("BONITO_INTSTEER = %08x\n", intsteer);
		pr_emerg("BONITO_PCICMD = %08x\n", pcicmd);
		pr_emerg("BONITO_PCIBADADDR = %08x\n", pcibadaddr);
		pr_emerg("BONITO_PCIMSTAT = %08x\n", pcimstat);
		break;
	}

	die("CoreHi interrupt", regs);
}

__attribute__((used)) static irqreturn_t corehi_handler(int irq, void *dev_id)
{
	corehi_irqdispatch();
	return IRQ_HANDLED;
}

