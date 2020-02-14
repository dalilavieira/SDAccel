#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_9__ ;
typedef  struct TYPE_53__   TYPE_8__ ;
typedef  struct TYPE_52__   TYPE_7__ ;
typedef  struct TYPE_51__   TYPE_6__ ;
typedef  struct TYPE_50__   TYPE_5__ ;
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_27__ ;
typedef  struct TYPE_45__   TYPE_26__ ;
typedef  struct TYPE_44__   TYPE_25__ ;
typedef  struct TYPE_43__   TYPE_24__ ;
typedef  struct TYPE_42__   TYPE_23__ ;
typedef  struct TYPE_41__   TYPE_22__ ;
typedef  struct TYPE_40__   TYPE_21__ ;
typedef  struct TYPE_39__   TYPE_20__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_19__ ;
typedef  struct TYPE_36__   TYPE_18__ ;
typedef  struct TYPE_35__   TYPE_17__ ;
typedef  struct TYPE_34__   TYPE_16__ ;
typedef  struct TYPE_33__   TYPE_15__ ;
typedef  struct TYPE_32__   TYPE_14__ ;
typedef  struct TYPE_31__   TYPE_13__ ;
typedef  struct TYPE_30__   TYPE_12__ ;
typedef  struct TYPE_29__   TYPE_11__ ;
typedef  struct TYPE_28__   TYPE_10__ ;

/* Type definitions */
struct io7 {int /*<<< orphan*/  pe; TYPE_24__* csrs; TYPE_25__* ports; } ;
struct ev7_pal_io_subpacket {unsigned long po7_error_sum; int /*<<< orphan*/  member_0; TYPE_20__* ports; int /*<<< orphan*/  po7_err_pkt1; int /*<<< orphan*/  po7_err_pkt0; int /*<<< orphan*/  po7_ugbge_sym; int /*<<< orphan*/  po7_crrct_sym; int /*<<< orphan*/  po7_uncrr_sym; int /*<<< orphan*/  hei_ctl; int /*<<< orphan*/  crd_ctl; int /*<<< orphan*/  hpi_ctl; int /*<<< orphan*/  io7_uph; int /*<<< orphan*/  io_sys_rev; int /*<<< orphan*/  io_asic_rev; } ;
struct ev7_lf_subpackets {TYPE_22__* logout; int /*<<< orphan*/  io_pid; struct ev7_pal_io_subpacket* io; int /*<<< orphan*/ * member_0; TYPE_21__* ev7; scalar_t__* env; } ;
struct el_subpacket {int dummy; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
struct TYPE_45__ {unsigned long csr; } ;
struct TYPE_37__ {int /*<<< orphan*/  csr; } ;
struct TYPE_36__ {int /*<<< orphan*/  csr; } ;
struct TYPE_35__ {int /*<<< orphan*/  csr; } ;
struct TYPE_34__ {int /*<<< orphan*/  csr; } ;
struct TYPE_33__ {int /*<<< orphan*/  csr; } ;
struct TYPE_32__ {int /*<<< orphan*/  csr; } ;
struct TYPE_31__ {int /*<<< orphan*/  csr; } ;
struct TYPE_30__ {int /*<<< orphan*/  csr; } ;
struct TYPE_29__ {int /*<<< orphan*/  csr; } ;
struct TYPE_46__ {TYPE_26__ POx_ERR_SUM; TYPE_19__ POx_TLB_ERR; TYPE_18__ POx_DM_CTRL; TYPE_17__ POx_DM_SIZE; TYPE_16__ POx_DM_DEST; TYPE_15__ POx_DM_SOURCE; TYPE_14__ POx_MULT_ERR; TYPE_13__ POx_FIRST_ERR; TYPE_12__ POx_TRANS_SUM; TYPE_11__ POx_SPL_COMPLT; } ;
typedef  TYPE_27__ io7_ioport_csrs ;
struct TYPE_54__ {int /*<<< orphan*/  csr; } ;
struct TYPE_53__ {int /*<<< orphan*/  csr; } ;
struct TYPE_52__ {int /*<<< orphan*/  csr; } ;
struct TYPE_51__ {int /*<<< orphan*/  csr; } ;
struct TYPE_50__ {int /*<<< orphan*/  csr; } ;
struct TYPE_49__ {int /*<<< orphan*/  csr; } ;
struct TYPE_48__ {int /*<<< orphan*/  csr; } ;
struct TYPE_47__ {int /*<<< orphan*/  csr; } ;
struct TYPE_44__ {int /*<<< orphan*/  enabled; TYPE_27__* csrs; } ;
struct TYPE_42__ {unsigned long csr; } ;
struct TYPE_38__ {int /*<<< orphan*/  csr; } ;
struct TYPE_43__ {TYPE_23__ PO7_ERROR_SUM; TYPE_10__* PO7_ERR_PKT; TYPE_9__ PO7_UGBGE_SYM; TYPE_8__ PO7_CRRCT_SYM; TYPE_7__ PO7_UNCRR_SYM; TYPE_6__ HEI_CTL; TYPE_5__ CRD_CTL; TYPE_4__ HPI_CTL; TYPE_3__ IO7_UPH; TYPE_2__ IO_SYS_REV; TYPE_1__ IO_ASIC_REV; } ;
struct TYPE_41__ {int rbox_int; int /*<<< orphan*/  timestamp; int /*<<< orphan*/  whami; } ;
struct TYPE_40__ {int c_stat; int c_sts; int c_addr; } ;
struct TYPE_39__ {unsigned long pox_err_sum; int /*<<< orphan*/  pox_tlb_err; int /*<<< orphan*/  pox_dm_ctrl; int /*<<< orphan*/  pox_dm_size; int /*<<< orphan*/  pox_dm_dest; int /*<<< orphan*/  pox_dm_source; int /*<<< orphan*/  pox_mult_err; int /*<<< orphan*/  pox_first_err; int /*<<< orphan*/  pox_trans_sum; int /*<<< orphan*/  pox_spl_cmplt; } ;
struct TYPE_28__ {int /*<<< orphan*/  csr; } ;

/* Variables and functions */
 int /*<<< orphan*/  EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE ; 
 int /*<<< orphan*/  EL_TYPE__PAL__ENV__HOT_PLUG ; 
 int IO7_NUM_PORTS ; 
 char* KERN_CRIT ; 
#define  MCHK_DISPOSITION_DISMISS 132 
#define  MCHK_DISPOSITION_REPORT 131 
 int MCHK_DISPOSITION_UNKNOWN_ERROR ; 
#define  SCB_Q_SYSERR 130 
#define  SCB_Q_SYSEVENT 129 
#define  SCB_Q_SYSMCHK 128 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  draina () ; 
 int /*<<< orphan*/  el_print_timestamp (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  el_process_subpacket (struct el_subpacket*) ; 
 char* err_print_prefix ; 
 struct ev7_lf_subpackets* ev7_collect_logout_frame_subpackets (struct el_subpacket*,struct ev7_lf_subpackets*) ; 
 int ev7_lf_env_index (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ev7_machine_check (unsigned long,unsigned long) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 struct io7* marvel_next_io7 (struct io7*) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  memset (struct ev7_pal_io_subpacket*,int,int) ; 
 int /*<<< orphan*/  printk (char*,char*,char*,unsigned int,int) ; 
 scalar_t__ smp_processor_id () ; 
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

__attribute__((used)) static void
marvel_print_680_frame(struct ev7_lf_subpackets *lf_subpackets)
{
#ifdef CONFIG_VERBOSE_MCHECK
	struct ev7_pal_environmental_subpacket *env;
	struct { int type; char *name; } ev_packets[] = {
		{ EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE,
		  "Ambient Temperature" },
		{ EL_TYPE__PAL__ENV__AIRMOVER_FAN,
		  "AirMover / Fan" },
		{ EL_TYPE__PAL__ENV__VOLTAGE,
		  "Voltage" },
		{ EL_TYPE__PAL__ENV__INTRUSION,
		  "Intrusion" },
		{ EL_TYPE__PAL__ENV__POWER_SUPPLY,
		  "Power Supply" },
		{ EL_TYPE__PAL__ENV__LAN,
		  "LAN" },
		{ EL_TYPE__PAL__ENV__HOT_PLUG,
		  "Hot Plug" },
		{ 0, NULL }
	};
	int i;

	for (i = 0; ev_packets[i].type != 0; i++) {
		env = lf_subpackets->env[ev7_lf_env_index(ev_packets[i].type)];
		if (!env)
			continue;

		printk("%s**%s event (cabinet %d, drawer %d)\n",
		       err_print_prefix,
		       ev_packets[i].name,
		       env->cabinet,
		       env->drawer);
		printk("%s   Module Type: 0x%x - Unit ID 0x%x - "
		       "Condition 0x%x\n",
		       err_print_prefix,
		       env->module_type,
		       env->unit_id,
		       env->condition);
	}
#endif /* CONFIG_VERBOSE_MCHECK */
}

__attribute__((used)) static int
marvel_process_680_frame(struct ev7_lf_subpackets *lf_subpackets, int print)
{
	int status = MCHK_DISPOSITION_UNKNOWN_ERROR;
	int i;

	for (i = ev7_lf_env_index(EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE);
	     i <= ev7_lf_env_index(EL_TYPE__PAL__ENV__HOT_PLUG);
	     i++) {
		if (lf_subpackets->env[i])
			status = MCHK_DISPOSITION_REPORT;
	}

	if (print)
		marvel_print_680_frame(lf_subpackets);

	return status;
}

__attribute__((used)) static struct ev7_pal_io_subpacket *
marvel_find_io7_with_error(struct ev7_lf_subpackets *lf_subpackets)
{
	struct ev7_pal_io_subpacket *io = lf_subpackets->io;
	struct io7 *io7;
	int i;

	/*
	 * Caller must provide the packet to fill
	 */
	if (!io)
		return NULL;

	/*
	 * Fill the subpacket with the console's standard fill pattern
	 */
	memset(io, 0x55, sizeof(*io));

	for (io7 = NULL; NULL != (io7 = marvel_next_io7(io7)); ) {
		unsigned long err_sum = 0;

		err_sum |= io7->csrs->PO7_ERROR_SUM.csr;
		for (i = 0; i < IO7_NUM_PORTS; i++) {
			if (!io7->ports[i].enabled)
				continue;
			err_sum |= io7->ports[i].csrs->POx_ERR_SUM.csr;
		}

		/*
		 * Is there at least one error? 
		 */
		if (err_sum & (1UL << 63))
			break;
	}

	/*
	 * Did we find an IO7 with an error?
	 */
	if (!io7)
		return NULL;

	/*
	 * We have an IO7 with an error. 
	 *
	 * Fill in the IO subpacket.
	 */
	io->io_asic_rev   = io7->csrs->IO_ASIC_REV.csr;
	io->io_sys_rev    = io7->csrs->IO_SYS_REV.csr;
	io->io7_uph       = io7->csrs->IO7_UPH.csr;
	io->hpi_ctl       = io7->csrs->HPI_CTL.csr;
	io->crd_ctl       = io7->csrs->CRD_CTL.csr;
	io->hei_ctl       = io7->csrs->HEI_CTL.csr;
	io->po7_error_sum = io7->csrs->PO7_ERROR_SUM.csr;
	io->po7_uncrr_sym = io7->csrs->PO7_UNCRR_SYM.csr;
	io->po7_crrct_sym = io7->csrs->PO7_CRRCT_SYM.csr;
	io->po7_ugbge_sym = io7->csrs->PO7_UGBGE_SYM.csr;
	io->po7_err_pkt0  = io7->csrs->PO7_ERR_PKT[0].csr;
	io->po7_err_pkt1  = io7->csrs->PO7_ERR_PKT[1].csr;
	
	for (i = 0; i < IO7_NUM_PORTS; i++) {
		io7_ioport_csrs *csrs = io7->ports[i].csrs;

		if (!io7->ports[i].enabled)
			continue;

		io->ports[i].pox_err_sum   = csrs->POx_ERR_SUM.csr;
		io->ports[i].pox_tlb_err   = csrs->POx_TLB_ERR.csr;
		io->ports[i].pox_spl_cmplt = csrs->POx_SPL_COMPLT.csr;
		io->ports[i].pox_trans_sum = csrs->POx_TRANS_SUM.csr;
		io->ports[i].pox_first_err = csrs->POx_FIRST_ERR.csr;
		io->ports[i].pox_mult_err  = csrs->POx_MULT_ERR.csr;
		io->ports[i].pox_dm_source = csrs->POx_DM_SOURCE.csr;
		io->ports[i].pox_dm_dest   = csrs->POx_DM_DEST.csr;
		io->ports[i].pox_dm_size   = csrs->POx_DM_SIZE.csr;
		io->ports[i].pox_dm_ctrl   = csrs->POx_DM_CTRL.csr;

		/*
		 * Ack this port's errors, if any. POx_ERR_SUM must be last.
		 *
		 * Most of the error registers get cleared and unlocked when
		 * the associated bits in POx_ERR_SUM are cleared (by writing
		 * 1). POx_TLB_ERR is an exception and must be explicitly 
		 * cleared.
		 */
		csrs->POx_TLB_ERR.csr = io->ports[i].pox_tlb_err;
		csrs->POx_ERR_SUM.csr =	io->ports[i].pox_err_sum;
		mb();
		csrs->POx_ERR_SUM.csr;		
	}

	/*
	 * Ack any port 7 error(s).
	 */
	io7->csrs->PO7_ERROR_SUM.csr = io->po7_error_sum;
	mb();
	io7->csrs->PO7_ERROR_SUM.csr;
	
	/*
	 * Correct the io7_pid.
	 */
	lf_subpackets->io_pid = io7->pe;

	return io;
}

__attribute__((used)) static int
marvel_process_io_error(struct ev7_lf_subpackets *lf_subpackets, int print)
{
	int status = MCHK_DISPOSITION_UNKNOWN_ERROR;

#ifdef CONFIG_VERBOSE_MCHECK
	struct ev7_pal_io_subpacket *io = lf_subpackets->io;
	int i;
#endif /* CONFIG_VERBOSE_MCHECK */

#define MARVEL_IO_ERR_VALID(x)  ((x) & (1UL << 63))

	if (!lf_subpackets->logout || !lf_subpackets->io)
		return status;

	/*
	 * The PALcode only builds an IO subpacket if there is a 
	 * locally connected IO7. In the cases of
	 *	1) a uniprocessor kernel
	 *	2) an mp kernel before the local secondary has called in
	 * error interrupts are all directed to the primary processor.
	 * In that case, we may not have an IO subpacket at all and, event
	 * if we do, it may not be the right now. 
	 *
	 * If the RBOX indicates an I/O error interrupt, make sure we have
	 * the correct IO7 information. If we don't have an IO subpacket
	 * or it's the wrong one, try to find the right one.
	 *
	 * RBOX I/O error interrupts are indicated by RBOX_INT<29> and
	 * RBOX_INT<10>.
	 */
	if ((lf_subpackets->io->po7_error_sum & (1UL << 32)) ||
	    ((lf_subpackets->io->po7_error_sum        |
	      lf_subpackets->io->ports[0].pox_err_sum |
	      lf_subpackets->io->ports[1].pox_err_sum |
	      lf_subpackets->io->ports[2].pox_err_sum |
	      lf_subpackets->io->ports[3].pox_err_sum) & (1UL << 63))) {
		/*
		 * Either we have no IO subpacket or no error is
		 * indicated in the one we do have. Try find the
		 * one with the error.
		 */
		if (!marvel_find_io7_with_error(lf_subpackets))
			return status;
	}

	/*
	 * We have an IO7 indicating an error - we're going to report it
	 */
	status = MCHK_DISPOSITION_REPORT;

#ifdef CONFIG_VERBOSE_MCHECK

	if (!print)
		return status;

	printk("%s*Error occurred on IO7 at PID %u\n", 
	       err_print_prefix, lf_subpackets->io_pid);

	/*
	 * Check port 7 first
	 */
	if (lf_subpackets->io->po7_error_sum & IO7__PO7_ERRSUM__ERR_MASK) {
		marvel_print_po7_err_sum(io);

#if 0
		printk("%s  PORT 7 ERROR:\n"
		       "%s    PO7_ERROR_SUM: %016llx\n"
		       "%s    PO7_UNCRR_SYM: %016llx\n"
		       "%s    PO7_CRRCT_SYM: %016llx\n"
		       "%s    PO7_UGBGE_SYM: %016llx\n"
		       "%s    PO7_ERR_PKT0:  %016llx\n"
		       "%s    PO7_ERR_PKT1:  %016llx\n",
		       err_print_prefix,
		       err_print_prefix, io->po7_error_sum,
		       err_print_prefix, io->po7_uncrr_sym,
		       err_print_prefix, io->po7_crrct_sym,
		       err_print_prefix, io->po7_ugbge_sym,
		       err_print_prefix, io->po7_err_pkt0,
		       err_print_prefix, io->po7_err_pkt1);
#endif
	}

	/*
	 * Then loop through the ports
	 */
	for (i = 0; i < IO7_NUM_PORTS; i++) {
		if (!MARVEL_IO_ERR_VALID(io->ports[i].pox_err_sum))
			continue;

		printk("%s  PID %u PORT %d POx_ERR_SUM: %016llx\n",
		       err_print_prefix, 
		       lf_subpackets->io_pid, i, io->ports[i].pox_err_sum);
		marvel_print_pox_err(io->ports[i].pox_err_sum, &io->ports[i]);

		printk("%s  [ POx_FIRST_ERR: %016llx ]\n",
		       err_print_prefix, io->ports[i].pox_first_err);
		marvel_print_pox_err(io->ports[i].pox_first_err, 
				     &io->ports[i]);

	}


#endif /* CONFIG_VERBOSE_MCHECK */

	return status;
}

__attribute__((used)) static int
marvel_process_logout_frame(struct ev7_lf_subpackets *lf_subpackets, int print)
{
	int status = MCHK_DISPOSITION_UNKNOWN_ERROR;

	/*
	 * I/O error? 
	 */
#define EV7__RBOX_INT__IO_ERROR__MASK 0x20000400ul
	if (lf_subpackets->logout &&
	    (lf_subpackets->logout->rbox_int & 0x20000400ul))
		status = marvel_process_io_error(lf_subpackets, print);

	/*
	 * Probing behind PCI-X bridges can cause machine checks on
	 * Marvel when the probe is handled by the bridge as a split
	 * completion transaction. The symptom is an ERROR_RESPONSE 
	 * to a CONFIG address. Since these errors will happen in
	 * normal operation, dismiss them.
	 *
	 * Dismiss if:
	 *	C_STAT		= 0x14 		(Error Response)
	 *	C_STS<3>	= 0    		(C_ADDR valid)
	 *	C_ADDR<42>	= 1    		(I/O)
	 *	C_ADDR<31:22>	= 111110xxb	(PCI Config space)
	 */
	if (lf_subpackets->ev7 &&
	    (lf_subpackets->ev7->c_stat == 0x14) &&
	    !(lf_subpackets->ev7->c_sts & 0x8) &&
	    ((lf_subpackets->ev7->c_addr & 0x400ff000000ul) 
	     == 0x400fe000000ul))
		status = MCHK_DISPOSITION_DISMISS;

	return status;
}

void
marvel_machine_check(unsigned long vector, unsigned long la_ptr)
{
	struct el_subpacket *el_ptr = (struct el_subpacket *)la_ptr;
	int (*process_frame)(struct ev7_lf_subpackets *, int) = NULL;
	struct ev7_lf_subpackets subpacket_collection = { NULL, };
	struct ev7_pal_io_subpacket scratch_io_packet = { 0, };
	struct ev7_lf_subpackets *lf_subpackets = NULL;
	int disposition = MCHK_DISPOSITION_UNKNOWN_ERROR;
	char *saved_err_prefix = err_print_prefix;
	char *error_type = NULL;

	/*
	 * Sync the processor
	 */
	mb();
	draina();

	switch(vector) {
	case SCB_Q_SYSEVENT:
		process_frame = marvel_process_680_frame;
		error_type = "System Event";
		break;

	case SCB_Q_SYSMCHK:
		process_frame = marvel_process_logout_frame;
		error_type = "System Uncorrectable Error";
		break;

	case SCB_Q_SYSERR:
		process_frame = marvel_process_logout_frame;
		error_type = "System Correctable Error";
		break;

	default:
		/* Don't know it - pass it up.  */
		ev7_machine_check(vector, la_ptr);
		return;
	}	

	/*
	 * A system event or error has occurred, handle it here.
	 *
	 * Any errors in the logout frame have already been cleared by the
	 * PALcode, so just parse it.
	 */
	err_print_prefix = KERN_CRIT;

	/* 
	 * Parse the logout frame without printing first. If the only error(s)
	 * found are classified as "dismissable", then just dismiss them and
	 * don't print any message
	 */
	lf_subpackets = 
		ev7_collect_logout_frame_subpackets(el_ptr,
						    &subpacket_collection);
	if (process_frame && lf_subpackets && lf_subpackets->logout) {
		/*
		 * We might not have the correct (or any) I/O subpacket.
		 * [ See marvel_process_io_error() for explanation. ]
		 * If we don't have one, point the io subpacket in
		 * lf_subpackets at scratch_io_packet so that 
		 * marvel_find_io7_with_error() will have someplace to
		 * store the info.
		 */
		if (!lf_subpackets->io)
			lf_subpackets->io = &scratch_io_packet;

		/*
		 * Default io_pid to the processor reporting the error
		 * [this will get changed in marvel_find_io7_with_error()
		 * if a different one is needed]
		 */
		lf_subpackets->io_pid = lf_subpackets->logout->whami;

		/*
		 * Evaluate the frames.
		 */
		disposition = process_frame(lf_subpackets, 0);
	}
	switch(disposition) {
	case MCHK_DISPOSITION_DISMISS:
		/* Nothing to do. */
		break;

	case MCHK_DISPOSITION_REPORT:
		/* Recognized error, report it. */
		printk("%s*%s (Vector 0x%x) reported on CPU %d\n",
		       err_print_prefix, error_type,
		       (unsigned int)vector, (int)smp_processor_id());
		el_print_timestamp(&lf_subpackets->logout->timestamp);
		process_frame(lf_subpackets, 1);
		break;

	default:
		/* Unknown - dump the annotated subpackets. */
		printk("%s*%s (Vector 0x%x) reported on CPU %d\n",
		       err_print_prefix, error_type,
		       (unsigned int)vector, (int)smp_processor_id());
		el_process_subpacket(el_ptr);
		break;

	}

	err_print_prefix = saved_err_prefix;

        /* Release the logout frame.  */
	wrmces(0x7);
	mb();
}

