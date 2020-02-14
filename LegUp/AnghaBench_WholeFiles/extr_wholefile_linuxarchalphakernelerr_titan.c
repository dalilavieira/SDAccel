#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
struct TYPE_3__ {scalar_t__ data_start; scalar_t__ cpuid; } ;
struct TYPE_4__ {TYPE_1__ regatta_frame; } ;
struct el_subpacket {int type; scalar_t__ length; TYPE_2__ by_type; int /*<<< orphan*/  class; } ;
struct el_common {scalar_t__ sys_offset; } ;
struct el_TITAN_sysdata_mcheck {unsigned long c_misc; unsigned long p0_serror; unsigned long p0_gperror; unsigned long p0_aperror; unsigned long p0_agperror; unsigned long p1_serror; unsigned long p1_gperror; unsigned long p1_aperror; unsigned long p1_agperror; int c_dirx; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 int /*<<< orphan*/  EL_CLASS__REGATTA_FAMILY ; 
#define  EL_TYPE__REGATTA__ENVIRONMENTAL_FRAME 132 
#define  EL_TYPE__REGATTA__PROCESSOR_DBL_ERROR_HALT 131 
#define  EL_TYPE__REGATTA__PROCESSOR_ERROR_FRAME 130 
#define  EL_TYPE__REGATTA__SYSTEM_DBL_ERROR_HALT 129 
#define  EL_TYPE__REGATTA__SYSTEM_ERROR_FRAME 128 
 int EXTRACT (unsigned long,int /*<<< orphan*/ ) ; 
 char* KERN_CRIT ; 
 int MCHK_DISPOSITION_DISMISS ; 
 int MCHK_DISPOSITION_REPORT ; 
 int MCHK_DISPOSITION_UNKNOWN_ERROR ; 
 unsigned long SCB_Q_SYSERR ; 
 unsigned long SCB_Q_SYSMCHK ; 
 int /*<<< orphan*/  TITAN__PCHIP_PERROR__ADDR ; 
 int /*<<< orphan*/  TITAN__PCHIP_PERROR__CMD ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  draina () ; 
 int /*<<< orphan*/  el_annotate_subpacket (struct el_subpacket*) ; 
 char* err_print_prefix ; 
 int /*<<< orphan*/  ev6_machine_check (unsigned long,unsigned long) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  printk (char*,char*,...) ; 
 int /*<<< orphan*/  privateer_process_logout_frame (struct el_common*,int) ; 
 scalar_t__ smp_processor_id () ; 
 int /*<<< orphan*/  titan_dispatch_irqs (unsigned long) ; 
 int /*<<< orphan*/  wrmces (int) ; 

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
titan_parse_c_misc(u64 c_misc, int print)
{
#ifdef CONFIG_VERBOSE_MCHECK
	char *src;
	int nxs = 0;
#endif
	int status = MCHK_DISPOSITION_REPORT;

#define TITAN__CCHIP_MISC__NXM		(1UL << 28)
#define TITAN__CCHIP_MISC__NXS__S	(29)
#define TITAN__CCHIP_MISC__NXS__M	(0x7)

	if (!(c_misc & TITAN__CCHIP_MISC__NXM))
		return MCHK_DISPOSITION_UNKNOWN_ERROR;

#ifdef CONFIG_VERBOSE_MCHECK
	if (!print)
		return status;

	nxs = EXTRACT(c_misc, TITAN__CCHIP_MISC__NXS);
	switch(nxs) {
	case 0:	/* CPU 0 */
	case 1:	/* CPU 1 */
	case 2:	/* CPU 2 */
	case 3:	/* CPU 3 */
		src = "CPU";
		/* num is already the CPU number */
		break;
	case 4:	/* Pchip 0 */
	case 5:	/* Pchip 1 */
		src = "Pchip";
		nxs -= 4;
		break;
	default:/* reserved */
		src = "Unknown, NXS =";
		/* leave num untouched */
		break;
	}

	printk("%s    Non-existent memory access from: %s %d\n", 
	       err_print_prefix, src, nxs);
#endif /* CONFIG_VERBOSE_MCHECK */

	return status;
}

__attribute__((used)) static int
titan_parse_p_serror(int which, u64 serror, int print)
{
	int status = MCHK_DISPOSITION_REPORT;

#ifdef CONFIG_VERBOSE_MCHECK
	static const char * const serror_src[] = {
		"GPCI", "APCI", "AGP HP", "AGP LP"
	};
	static const char * const serror_cmd[] = {
		"DMA Read", "DMA RMW", "SGTE Read", "Reserved"
	};
#endif /* CONFIG_VERBOSE_MCHECK */

#define TITAN__PCHIP_SERROR__LOST_UECC	(1UL << 0)
#define TITAN__PCHIP_SERROR__UECC	(1UL << 1)
#define TITAN__PCHIP_SERROR__CRE	(1UL << 2)
#define TITAN__PCHIP_SERROR__NXIO	(1UL << 3)
#define TITAN__PCHIP_SERROR__LOST_CRE	(1UL << 4)
#define TITAN__PCHIP_SERROR__ECCMASK	(TITAN__PCHIP_SERROR__UECC |	  \
					 TITAN__PCHIP_SERROR__CRE)
#define TITAN__PCHIP_SERROR__ERRMASK	(TITAN__PCHIP_SERROR__LOST_UECC | \
					 TITAN__PCHIP_SERROR__UECC |	  \
					 TITAN__PCHIP_SERROR__CRE |	  \
					 TITAN__PCHIP_SERROR__NXIO |	  \
					 TITAN__PCHIP_SERROR__LOST_CRE)
#define TITAN__PCHIP_SERROR__SRC__S	(52)
#define TITAN__PCHIP_SERROR__SRC__M	(0x3)
#define TITAN__PCHIP_SERROR__CMD__S	(54)
#define TITAN__PCHIP_SERROR__CMD__M	(0x3)
#define TITAN__PCHIP_SERROR__SYN__S	(56)
#define TITAN__PCHIP_SERROR__SYN__M	(0xff)
#define TITAN__PCHIP_SERROR__ADDR__S	(15)
#define TITAN__PCHIP_SERROR__ADDR__M	(0xffffffffUL)

	if (!(serror & TITAN__PCHIP_SERROR__ERRMASK))
		return MCHK_DISPOSITION_UNKNOWN_ERROR;

#ifdef CONFIG_VERBOSE_MCHECK
	if (!print)
		return status;

	printk("%s  PChip %d SERROR: %016llx\n",
	       err_print_prefix, which, serror);
	if (serror & TITAN__PCHIP_SERROR__ECCMASK) {
		printk("%s    %sorrectable ECC Error:\n"
		       "      Source: %-6s  Command: %-8s  Syndrome: 0x%08x\n"
		       "      Address: 0x%llx\n",
		       err_print_prefix,
		       (serror & TITAN__PCHIP_SERROR__UECC) ? "Unc" : "C",
		       serror_src[EXTRACT(serror, TITAN__PCHIP_SERROR__SRC)],
		       serror_cmd[EXTRACT(serror, TITAN__PCHIP_SERROR__CMD)],
		       (unsigned)EXTRACT(serror, TITAN__PCHIP_SERROR__SYN),
		       EXTRACT(serror, TITAN__PCHIP_SERROR__ADDR));
	}
	if (serror & TITAN__PCHIP_SERROR__NXIO)
		printk("%s    Non Existent I/O Error\n", err_print_prefix);
	if (serror & TITAN__PCHIP_SERROR__LOST_UECC)
		printk("%s    Lost Uncorrectable ECC Error\n", 
		       err_print_prefix);
	if (serror & TITAN__PCHIP_SERROR__LOST_CRE)
		printk("%s    Lost Correctable ECC Error\n", err_print_prefix);
#endif /* CONFIG_VERBOSE_MCHECK */

	return status;
}

__attribute__((used)) static int 
titan_parse_p_perror(int which, int port, u64 perror, int print)
{
	int cmd;
	unsigned long addr;
	int status = MCHK_DISPOSITION_REPORT;

#ifdef CONFIG_VERBOSE_MCHECK
	static const char * const perror_cmd[] = {
		"Interrupt Acknowledge", "Special Cycle",
		"I/O Read",		"I/O Write",
		"Reserved",		"Reserved",
		"Memory Read",		"Memory Write",
		"Reserved",		"Reserved",
		"Configuration Read",	"Configuration Write",
		"Memory Read Multiple",	"Dual Address Cycle",
		"Memory Read Line",	"Memory Write and Invalidate"
	};
#endif /* CONFIG_VERBOSE_MCHECK */

#define TITAN__PCHIP_PERROR__LOST	(1UL << 0)
#define TITAN__PCHIP_PERROR__SERR	(1UL << 1)
#define TITAN__PCHIP_PERROR__PERR	(1UL << 2)
#define TITAN__PCHIP_PERROR__DCRTO	(1UL << 3)
#define TITAN__PCHIP_PERROR__SGE	(1UL << 4)
#define TITAN__PCHIP_PERROR__APE	(1UL << 5)
#define TITAN__PCHIP_PERROR__TA		(1UL << 6)
#define TITAN__PCHIP_PERROR__DPE	(1UL << 7)
#define TITAN__PCHIP_PERROR__NDS	(1UL << 8)
#define TITAN__PCHIP_PERROR__IPTPR	(1UL << 9)
#define TITAN__PCHIP_PERROR__IPTPW	(1UL << 10)
#define TITAN__PCHIP_PERROR__ERRMASK	(TITAN__PCHIP_PERROR__LOST |	\
					 TITAN__PCHIP_PERROR__SERR |	\
					 TITAN__PCHIP_PERROR__PERR |	\
					 TITAN__PCHIP_PERROR__DCRTO |	\
					 TITAN__PCHIP_PERROR__SGE |	\
					 TITAN__PCHIP_PERROR__APE |	\
					 TITAN__PCHIP_PERROR__TA |	\
					 TITAN__PCHIP_PERROR__DPE |	\
					 TITAN__PCHIP_PERROR__NDS |	\
					 TITAN__PCHIP_PERROR__IPTPR |	\
					 TITAN__PCHIP_PERROR__IPTPW)
#define TITAN__PCHIP_PERROR__DAC	(1UL << 47)
#define TITAN__PCHIP_PERROR__MWIN	(1UL << 48)
#define TITAN__PCHIP_PERROR__CMD__S	(52)
#define TITAN__PCHIP_PERROR__CMD__M	(0x0f)
#define TITAN__PCHIP_PERROR__ADDR__S	(14)
#define TITAN__PCHIP_PERROR__ADDR__M	(0x1fffffffful)

	if (!(perror & TITAN__PCHIP_PERROR__ERRMASK))
		return MCHK_DISPOSITION_UNKNOWN_ERROR;

	cmd = EXTRACT(perror, TITAN__PCHIP_PERROR__CMD);
	addr = EXTRACT(perror, TITAN__PCHIP_PERROR__ADDR) << 2;

	/*
	 * Initializing the BIOS on a video card on a bus without
	 * a south bridge (subtractive decode agent) can result in 
	 * master aborts as the BIOS probes the capabilities of the
	 * card. XFree86 does such initialization. If the error
	 * is a master abort (No DevSel as PCI Master) and the command
	 * is an I/O read or write below the address where we start
	 * assigning PCI I/O spaces (SRM uses 0x1000), then mark the
	 * error as dismissable so starting XFree86 doesn't result
	 * in a series of uncorrectable errors being reported. Also
	 * dismiss master aborts to VGA frame buffer space
	 * (0xA0000 - 0xC0000) and legacy BIOS space (0xC0000 - 0x100000)
	 * for the same reason.
	 *
	 * Also mark the error dismissible if it looks like the right
	 * error but only the Lost bit is set. Since the BIOS initialization
	 * can cause multiple master aborts and the error interrupt can
	 * be handled on a different CPU than the BIOS code is run on,
	 * it is possible for a second master abort to occur between the
	 * time the PALcode reads PERROR and the time it writes PERROR
	 * to acknowledge the error. If this timing happens, a second
	 * error will be signalled after the first, and if no additional
	 * errors occur, will look like a Lost error with no additional 
	 * errors on the same transaction as the previous error.
	 */
	if (((perror & TITAN__PCHIP_PERROR__NDS) || 
	     ((perror & TITAN__PCHIP_PERROR__ERRMASK) == 
	      TITAN__PCHIP_PERROR__LOST)) &&
	    ((((cmd & 0xE) == 2) && (addr < 0x1000)) ||
	     (((cmd & 0xE) == 6) && (addr >= 0xA0000) && (addr < 0x100000)))) {
		status = MCHK_DISPOSITION_DISMISS;
	}

#ifdef CONFIG_VERBOSE_MCHECK
	if (!print) 
		return status;

	printk("%s  PChip %d %cPERROR: %016llx\n",
	       err_print_prefix, which, 
	       port ? 'A' : 'G', perror);
	if (perror & TITAN__PCHIP_PERROR__IPTPW)
		printk("%s    Invalid Peer-to-Peer Write\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__IPTPR)
		printk("%s    Invalid Peer-to-Peer Read\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__NDS)
		printk("%s    No DEVSEL as PCI Master [Master Abort]\n",
		       err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__DPE)
		printk("%s    Data Parity Error\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__TA)
		printk("%s    Target Abort\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__APE)
		printk("%s    Address Parity Error\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__SGE)
		printk("%s    Scatter-Gather Error, Invalid PTE\n", 
		       err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__DCRTO)
		printk("%s    Delayed-Completion Retry Timeout\n", 
		       err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__PERR)
		printk("%s    PERR Asserted\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__SERR)
		printk("%s    SERR Asserted\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__LOST)
		printk("%s    Lost Error\n", err_print_prefix);
	printk("%s      Command: 0x%x - %s\n"
		 "      Address: 0x%lx\n",
	       err_print_prefix,
	       cmd, perror_cmd[cmd],
	       addr);
	if (perror & TITAN__PCHIP_PERROR__DAC)
		printk("%s      Dual Address Cycle\n", err_print_prefix);
	if (perror & TITAN__PCHIP_PERROR__MWIN)
		printk("%s      Hit in Monster Window\n", err_print_prefix);
#endif /* CONFIG_VERBOSE_MCHECK */

	return status;
}

__attribute__((used)) static int
titan_parse_p_agperror(int which, u64 agperror, int print)
{
	int status = MCHK_DISPOSITION_REPORT;
#ifdef CONFIG_VERBOSE_MCHECK
	int cmd, len;
	unsigned long addr;

	static const char * const agperror_cmd[] = {
		"Read (low-priority)",	"Read (high-priority)",
		"Write (low-priority)",	"Write (high-priority)",
		"Reserved",		"Reserved",
		"Flush",		"Fence"
	};
#endif /* CONFIG_VERBOSE_MCHECK */

#define TITAN__PCHIP_AGPERROR__LOST	(1UL << 0)
#define TITAN__PCHIP_AGPERROR__LPQFULL	(1UL << 1)
#define TITAN__PCHIP_AGPERROR__HPQFULL	(1UL << 2)
#define TITAN__PCHIP_AGPERROR__RESCMD	(1UL << 3)
#define TITAN__PCHIP_AGPERROR__IPTE	(1UL << 4)
#define TITAN__PCHIP_AGPERROR__PTP	(1UL << 5)
#define TITAN__PCHIP_AGPERROR__NOWINDOW	(1UL << 6)
#define TITAN__PCHIP_AGPERROR__ERRMASK	(TITAN__PCHIP_AGPERROR__LOST |    \
					 TITAN__PCHIP_AGPERROR__LPQFULL | \
					 TITAN__PCHIP_AGPERROR__HPQFULL | \
					 TITAN__PCHIP_AGPERROR__RESCMD |  \
					 TITAN__PCHIP_AGPERROR__IPTE |    \
					 TITAN__PCHIP_AGPERROR__PTP |     \
					 TITAN__PCHIP_AGPERROR__NOWINDOW)
#define TITAN__PCHIP_AGPERROR__DAC	(1UL << 48)
#define TITAN__PCHIP_AGPERROR__MWIN	(1UL << 49)
#define TITAN__PCHIP_AGPERROR__FENCE	(1UL << 59)
#define TITAN__PCHIP_AGPERROR__CMD__S	(50)
#define TITAN__PCHIP_AGPERROR__CMD__M	(0x07)
#define TITAN__PCHIP_AGPERROR__ADDR__S	(15)
#define TITAN__PCHIP_AGPERROR__ADDR__M  (0xffffffffUL)
#define TITAN__PCHIP_AGPERROR__LEN__S	(53)
#define TITAN__PCHIP_AGPERROR__LEN__M	(0x3f)

	if (!(agperror & TITAN__PCHIP_AGPERROR__ERRMASK))
		return MCHK_DISPOSITION_UNKNOWN_ERROR;

#ifdef CONFIG_VERBOSE_MCHECK
	if (!print)
		return status;

	cmd = EXTRACT(agperror, TITAN__PCHIP_AGPERROR__CMD);
	addr = EXTRACT(agperror, TITAN__PCHIP_AGPERROR__ADDR) << 3;
	len = EXTRACT(agperror, TITAN__PCHIP_AGPERROR__LEN);

	printk("%s  PChip %d AGPERROR: %016llx\n", err_print_prefix,
	       which, agperror);
	if (agperror & TITAN__PCHIP_AGPERROR__NOWINDOW)
		printk("%s    No Window\n", err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__PTP)
		printk("%s    Peer-to-Peer set\n", err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__IPTE)
		printk("%s    Invalid PTE\n", err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__RESCMD)
		printk("%s    Reserved Command\n", err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__HPQFULL)
		printk("%s    HP Transaction Received while Queue Full\n", 
		       err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__LPQFULL)
		printk("%s    LP Transaction Received while Queue Full\n", 
		       err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__LOST)
		printk("%s    Lost Error\n", err_print_prefix);
	printk("%s      Command: 0x%x - %s, %d Quadwords%s\n"
		 "      Address: 0x%lx\n",
	       err_print_prefix, cmd, agperror_cmd[cmd], len,
	       (agperror & TITAN__PCHIP_AGPERROR__FENCE) ? ", FENCE" : "",
	       addr);
	if (agperror & TITAN__PCHIP_AGPERROR__DAC)
		printk("%s      Dual Address Cycle\n", err_print_prefix);
	if (agperror & TITAN__PCHIP_AGPERROR__MWIN)
		printk("%s      Hit in Monster Window\n", err_print_prefix);
#endif /* CONFIG_VERBOSE_MCHECK */

	return status;
}

__attribute__((used)) static int
titan_parse_p_chip(int which, u64 serror, u64 gperror, 
		   u64 aperror, u64 agperror, int print)
{
	int status = MCHK_DISPOSITION_UNKNOWN_ERROR;
	status |= titan_parse_p_serror(which, serror, print);
	status |= titan_parse_p_perror(which, 0, gperror, print);
	status |= titan_parse_p_perror(which, 1, aperror, print);
	status |= titan_parse_p_agperror(which, agperror, print);
	return status;
}

int
titan_process_logout_frame(struct el_common *mchk_header, int print)
{
	struct el_TITAN_sysdata_mcheck *tmchk =
		(struct el_TITAN_sysdata_mcheck *)
		((unsigned long)mchk_header + mchk_header->sys_offset);
	int status = MCHK_DISPOSITION_UNKNOWN_ERROR;

	status |= titan_parse_c_misc(tmchk->c_misc, print);
	status |= titan_parse_p_chip(0, tmchk->p0_serror, tmchk->p0_gperror,
				     tmchk->p0_aperror, tmchk->p0_agperror, 
				     print);
	status |= titan_parse_p_chip(1, tmchk->p1_serror, tmchk->p1_gperror,
				     tmchk->p1_aperror, tmchk->p1_agperror, 
				     print);

	return status;
}

void
titan_machine_check(unsigned long vector, unsigned long la_ptr)
{
	struct el_common *mchk_header = (struct el_common *)la_ptr;
	struct el_TITAN_sysdata_mcheck *tmchk =
		(struct el_TITAN_sysdata_mcheck *)
		((unsigned long)mchk_header + mchk_header->sys_offset);
	u64 irqmask;

	/*
	 * Mask of Titan interrupt sources which are reported as machine checks
	 *
	 * 63 - CChip Error
	 * 62 - PChip 0 H_Error
	 * 61 - PChip 1 H_Error
	 * 60 - PChip 0 C_Error
	 * 59 - PChip 1 C_Error
	 */
#define TITAN_MCHECK_INTERRUPT_MASK	0xF800000000000000UL

	/*
	 * Sync the processor
	 */
	mb();
	draina();
	
	/*
	 * Only handle system errors here 
	 */
	if ((vector != SCB_Q_SYSMCHK) && (vector != SCB_Q_SYSERR)) {
		ev6_machine_check(vector, la_ptr);
		return;
	}

	/* 
	 * It's a system error, handle it here
	 *
	 * The PALcode has already cleared the error, so just parse it
	 */
	
	/* 
	 * Parse the logout frame without printing first. If the only error(s)
	 * found are classified as "dismissable", then just dismiss them and
	 * don't print any message
	 */
	if (titan_process_logout_frame(mchk_header, 0) != 
	    MCHK_DISPOSITION_DISMISS) {
		char *saved_err_prefix = err_print_prefix;
		err_print_prefix = KERN_CRIT;

		/*
		 * Either a nondismissable error was detected or no
		 * recognized error was detected  in the logout frame 
		 * -- report the error in either case
		 */
		printk("%s"
		       "*System %s Error (Vector 0x%x) reported on CPU %d:\n", 
		       err_print_prefix,
		       (vector == SCB_Q_SYSERR)?"Correctable":"Uncorrectable",
		       (unsigned int)vector, (int)smp_processor_id());
		
#ifdef CONFIG_VERBOSE_MCHECK
		titan_process_logout_frame(mchk_header, alpha_verbose_mcheck);
		if (alpha_verbose_mcheck)
			dik_show_regs(get_irq_regs(), NULL);
#endif /* CONFIG_VERBOSE_MCHECK */

		err_print_prefix = saved_err_prefix;

		/*
		 * Convert any pending interrupts which report as system
		 * machine checks to interrupts
		 */
		irqmask = tmchk->c_dirx & TITAN_MCHECK_INTERRUPT_MASK;
		titan_dispatch_irqs(irqmask);
	}	


	/* 
	 * Release the logout frame 
	 */
	wrmces(0x7);
	mb();
}

__attribute__((used)) static struct el_subpacket *
el_process_regatta_subpacket(struct el_subpacket *header)
{
	if (header->class != EL_CLASS__REGATTA_FAMILY) {
		printk("%s  ** Unexpected header CLASS %d TYPE %d, aborting\n",
		       err_print_prefix,
		       header->class, header->type);
		return NULL;
	}

	switch(header->type) {
	case EL_TYPE__REGATTA__PROCESSOR_ERROR_FRAME:
	case EL_TYPE__REGATTA__SYSTEM_ERROR_FRAME:
	case EL_TYPE__REGATTA__ENVIRONMENTAL_FRAME:
	case EL_TYPE__REGATTA__PROCESSOR_DBL_ERROR_HALT:
	case EL_TYPE__REGATTA__SYSTEM_DBL_ERROR_HALT:
		printk("%s  ** Occurred on CPU %d:\n", 
		       err_print_prefix,
		       (int)header->by_type.regatta_frame.cpuid);
		privateer_process_logout_frame((struct el_common *)
			header->by_type.regatta_frame.data_start, 1);
		break;
	default:
		printk("%s  ** REGATTA TYPE %d SUBPACKET\n", 
		       err_print_prefix, header->type);
		el_annotate_subpacket(header);
		break;
	}


	return (struct el_subpacket *)((unsigned long)header + header->length);
}

