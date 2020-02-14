#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct ev7_pal_zbox_subpacket {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  subpacket_count; int /*<<< orphan*/  halt_code; int /*<<< orphan*/  exc_addr; int /*<<< orphan*/  timestamp; int /*<<< orphan*/  rbox_whami; int /*<<< orphan*/  whami; } ;
struct TYPE_8__ {TYPE_3__ logout; } ;
struct ev7_pal_subpacket {TYPE_4__ by_type; } ;
struct ev7_pal_rbox_subpacket {int dummy; } ;
struct ev7_pal_processor_subpacket {int dummy; } ;
struct ev7_pal_logout_subpacket {int subpacket_count; } ;
struct ev7_pal_io_subpacket {int dummy; } ;
struct ev7_pal_environmental_subpacket {int dummy; } ;
struct ev7_lf_subpackets {struct ev7_pal_environmental_subpacket** env; struct ev7_pal_io_subpacket* io; struct ev7_pal_zbox_subpacket* zbox; struct ev7_pal_rbox_subpacket* rbox; struct ev7_pal_processor_subpacket* ev7; struct ev7_pal_logout_subpacket* logout; } ;
struct TYPE_5__ {scalar_t__ data_start; } ;
struct TYPE_6__ {TYPE_1__ raw; } ;
struct el_subpacket {scalar_t__ class; scalar_t__ type; scalar_t__ length; TYPE_2__ by_type; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 scalar_t__ EL_CLASS__HEADER ; 
 scalar_t__ EL_CLASS__PAL ; 
 scalar_t__ EL_TYPE__HEADER__LOGOUT_FRAME ; 
#define  EL_TYPE__PAL__ENV__AIRMOVER_FAN 139 
#define  EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE 138 
#define  EL_TYPE__PAL__ENV__HOT_PLUG 137 
#define  EL_TYPE__PAL__ENV__INTRUSION 136 
#define  EL_TYPE__PAL__ENV__LAN 135 
#define  EL_TYPE__PAL__ENV__POWER_SUPPLY 134 
#define  EL_TYPE__PAL__ENV__VOLTAGE 133 
#define  EL_TYPE__PAL__EV7_IO 132 
#define  EL_TYPE__PAL__EV7_PROCESSOR 131 
#define  EL_TYPE__PAL__EV7_RBOX 130 
#define  EL_TYPE__PAL__EV7_ZBOX 129 
#define  EL_TYPE__PAL__LOGOUT_FRAME 128 
 char* KERN_CRIT ; 
 unsigned long SCB_Q_PROCERR ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  draina () ; 
 int /*<<< orphan*/  el_annotate_subpacket (struct el_subpacket*) ; 
 int /*<<< orphan*/  el_print_timestamp (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  el_process_subpacket (struct el_subpacket*) ; 
 int /*<<< orphan*/  el_process_subpackets (struct el_subpacket*,int /*<<< orphan*/ ) ; 
 char* err_print_prefix ; 
 size_t ev7_lf_env_index (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  printk (char*,char*,...) ; 
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

struct ev7_lf_subpackets *
ev7_collect_logout_frame_subpackets(struct el_subpacket *el_ptr,
				    struct ev7_lf_subpackets *lf_subpackets)
{
	struct el_subpacket *subpacket;
	int i;

	/*
	 * A Marvel machine check frame is always packaged in an
	 * el_subpacket of class HEADER, type LOGOUT_FRAME.
	 */
	if (el_ptr->class != EL_CLASS__HEADER || 
	    el_ptr->type != EL_TYPE__HEADER__LOGOUT_FRAME)
		return NULL;

	/*
	 * It is a logout frame header. Look at the one subpacket.
	 */
	el_ptr = (struct el_subpacket *)
		((unsigned long)el_ptr + el_ptr->length);

	/*
	 * It has to be class PAL, type LOGOUT_FRAME.
	 */
	if (el_ptr->class != EL_CLASS__PAL ||
	    el_ptr->type != EL_TYPE__PAL__LOGOUT_FRAME)
		return NULL;

	lf_subpackets->logout = (struct ev7_pal_logout_subpacket *)
		el_ptr->by_type.raw.data_start;

	/*
	 * Process the subpackets.
	 */
	subpacket = (struct el_subpacket *)
		((unsigned long)el_ptr + el_ptr->length);
	for (i = 0;
	     subpacket && i < lf_subpackets->logout->subpacket_count;
	     subpacket = (struct el_subpacket *)
		     ((unsigned long)subpacket + subpacket->length), i++) {
		/*
		 * All subpackets should be class PAL.
		 */
		if (subpacket->class != EL_CLASS__PAL) {
			printk("%s**UNEXPECTED SUBPACKET CLASS %d "
			       "IN LOGOUT FRAME (packet %d\n",
			       err_print_prefix, subpacket->class, i);
			return NULL;
		}

		/*
		 * Remember the subpacket.
		 */
		switch(subpacket->type) {
		case EL_TYPE__PAL__EV7_PROCESSOR:
			lf_subpackets->ev7 =
				(struct ev7_pal_processor_subpacket *)
				subpacket->by_type.raw.data_start;
			break;

		case EL_TYPE__PAL__EV7_RBOX:
			lf_subpackets->rbox = (struct ev7_pal_rbox_subpacket *)
				subpacket->by_type.raw.data_start;
			break;

		case EL_TYPE__PAL__EV7_ZBOX:
			lf_subpackets->zbox = (struct ev7_pal_zbox_subpacket *)
				subpacket->by_type.raw.data_start;
			break;

		case EL_TYPE__PAL__EV7_IO:
			lf_subpackets->io = (struct ev7_pal_io_subpacket *)
				subpacket->by_type.raw.data_start;
			break;

		case EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE:
		case EL_TYPE__PAL__ENV__AIRMOVER_FAN:
		case EL_TYPE__PAL__ENV__VOLTAGE:
		case EL_TYPE__PAL__ENV__INTRUSION:
		case EL_TYPE__PAL__ENV__POWER_SUPPLY:
		case EL_TYPE__PAL__ENV__LAN:
		case EL_TYPE__PAL__ENV__HOT_PLUG:
			lf_subpackets->env[ev7_lf_env_index(subpacket->type)] =
 				(struct ev7_pal_environmental_subpacket *)
				subpacket->by_type.raw.data_start;
			break;
				
		default:
			/*
			 * Don't know what kind of frame this is.
			 */
			return NULL;
		}
	}

	return lf_subpackets;
}

void
ev7_machine_check(unsigned long vector, unsigned long la_ptr)
{
	struct el_subpacket *el_ptr = (struct el_subpacket *)la_ptr;
	char *saved_err_prefix = err_print_prefix;

	/*
	 * Sync the processor
	 */
	mb();
	draina();

	err_print_prefix = KERN_CRIT;
	printk("%s*CPU %s Error (Vector 0x%x) reported on CPU %d\n",
	       err_print_prefix, 
	       (vector == SCB_Q_PROCERR) ? "Correctable" : "Uncorrectable",
	       (unsigned int)vector, (int)smp_processor_id());
	el_process_subpacket(el_ptr);
	err_print_prefix = saved_err_prefix;

	/* 
	 * Release the logout frame 
	 */
	wrmces(0x7);
	mb();
}

__attribute__((used)) static struct el_subpacket *
ev7_process_pal_subpacket(struct el_subpacket *header)
{
	struct ev7_pal_subpacket *packet;

	if (header->class != EL_CLASS__PAL) {
		printk("%s  ** Unexpected header CLASS %d TYPE %d, aborting\n",
		       err_print_prefix,
		       header->class, header->type);
		return NULL;
	}

	packet = (struct ev7_pal_subpacket *)header->by_type.raw.data_start;

	switch(header->type) {
	case EL_TYPE__PAL__LOGOUT_FRAME:
		printk("%s*** MCHK occurred on LPID %lld (RBOX %llx)\n",
		       err_print_prefix,
		       packet->by_type.logout.whami, 
		       packet->by_type.logout.rbox_whami);
		el_print_timestamp(&packet->by_type.logout.timestamp);
		printk("%s  EXC_ADDR: %016llx\n"
		         "  HALT_CODE: %llx\n",
		       err_print_prefix,
		       packet->by_type.logout.exc_addr,
		       packet->by_type.logout.halt_code);
		el_process_subpackets(header,
                                      packet->by_type.logout.subpacket_count);
		break;
	default:
		printk("%s  ** PAL TYPE %d SUBPACKET\n", 
		       err_print_prefix,
		       header->type);
		el_annotate_subpacket(header);
		break;
	}
	
	return (struct el_subpacket *)((unsigned long)header + header->length);
}

