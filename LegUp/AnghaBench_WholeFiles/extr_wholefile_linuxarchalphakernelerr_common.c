#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  second; int /*<<< orphan*/  minute; int /*<<< orphan*/  hour; int /*<<< orphan*/  year; int /*<<< orphan*/  day; int /*<<< orphan*/  month; } ;
union el_timestamp {TYPE_6__ b; scalar_t__ as_int; } ;
struct el_subpacket_handler {scalar_t__ class; struct el_subpacket* (* handler ) (struct el_subpacket*) ;struct el_subpacket_handler* next; } ;
struct el_subpacket_annotation {scalar_t__ class; scalar_t__ type; scalar_t__ revision; char** annotation; int description; struct el_subpacket_annotation* next; } ;
struct TYPE_10__ {int frame_length; } ;
struct TYPE_9__ {int frame_length; int frame_packet_count; union el_timestamp timestamp; } ;
struct TYPE_8__ {int frame_length; int frame_packet_count; union el_timestamp timestamp; } ;
struct TYPE_7__ {int frame_length; int frame_packet_count; } ;
struct TYPE_11__ {TYPE_4__ logout_header; TYPE_3__ err_halt; TYPE_2__ sys_event; TYPE_1__ sys_err; } ;
struct el_subpacket {int class; scalar_t__ type; unsigned long length; scalar_t__ revision; TYPE_5__ by_type; } ;
struct el_common {size_t size; size_t proc_offset; unsigned long sys_offset; int /*<<< orphan*/  frame_rev; int /*<<< orphan*/  code; scalar_t__ err2; scalar_t__ retry; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
#define  EL_CLASS__HEADER 133 
#define  EL_CLASS__TERMINATION 132 
#define  EL_TYPE__HEADER__HALT_FRAME 131 
#define  EL_TYPE__HEADER__LOGOUT_FRAME 130 
#define  EL_TYPE__HEADER__SYSTEM_ERROR_FRAME 129 
#define  EL_TYPE__HEADER__SYSTEM_EVENT_FRAME 128 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 void el_print_timestamp (union el_timestamp*) ; 
 struct el_subpacket* el_process_subpacket (struct el_subpacket*) ; 
 void el_process_subpackets (struct el_subpacket*,int) ; 
 int /*<<< orphan*/  err_print_prefix ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,...) ; 
 struct el_subpacket* stub1 (struct el_subpacket*) ; 
 struct el_subpacket_annotation* subpacket_annotation_list ; 
 struct el_subpacket_handler* subpacket_handler_list ; 

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

void
mchk_dump_mem(void *data, size_t length, char **annotation)
{
	unsigned long *ldata = data;
	size_t i;
	
	for (i = 0; (i * sizeof(*ldata)) < length; i++) {
		if (annotation && !annotation[i]) 
			annotation = NULL;
		printk("%s    %08x: %016lx    %s\n",
		       err_print_prefix,
		       (unsigned)(i * sizeof(*ldata)), ldata[i],
		       annotation ? annotation[i] : "");
	}
}

void
mchk_dump_logout_frame(struct el_common *mchk_header)
{
	printk("%s  -- Frame Header --\n"
	         "    Frame Size:   %d (0x%x) bytes\n"
	         "    Flags:        %s%s\n"
	         "    MCHK Code:    0x%x\n"
	         "    Frame Rev:    %d\n"
	         "    Proc Offset:  0x%08x\n"
	         "    Sys Offset:   0x%08x\n"
  	         "  -- Processor Region --\n",
	       err_print_prefix, 
	       mchk_header->size, mchk_header->size,
	       mchk_header->retry ? "RETRY " : "", 
  	         mchk_header->err2 ? "SECOND_ERR " : "",
	       mchk_header->code,
	       mchk_header->frame_rev,
	       mchk_header->proc_offset,
	       mchk_header->sys_offset);

	mchk_dump_mem((void *)
		      ((unsigned long)mchk_header + mchk_header->proc_offset),
		      mchk_header->sys_offset - mchk_header->proc_offset,
		      NULL);
	
	printk("%s  -- System Region --\n", err_print_prefix);
	mchk_dump_mem((void *)
		      ((unsigned long)mchk_header + mchk_header->sys_offset),
		      mchk_header->size - mchk_header->sys_offset,
		      NULL);
	printk("%s  -- End of Frame --\n", err_print_prefix);
}

__attribute__((used)) static struct el_subpacket *
el_process_header_subpacket(struct el_subpacket *header)
{
	union el_timestamp timestamp;
	char *name = "UNKNOWN EVENT";
	int packet_count = 0;
	int length = 0;

	if (header->class != EL_CLASS__HEADER) {
		printk("%s** Unexpected header CLASS %d TYPE %d, aborting\n",
		       err_print_prefix,
		       header->class, header->type);
		return NULL;
	}

	switch(header->type) {
	case EL_TYPE__HEADER__SYSTEM_ERROR_FRAME:
		name = "SYSTEM ERROR";
		length = header->by_type.sys_err.frame_length;
		packet_count = 
			header->by_type.sys_err.frame_packet_count;
		timestamp.as_int = 0;
		break;
	case EL_TYPE__HEADER__SYSTEM_EVENT_FRAME:
		name = "SYSTEM EVENT";
		length = header->by_type.sys_event.frame_length;
		packet_count = 
			header->by_type.sys_event.frame_packet_count;
		timestamp = header->by_type.sys_event.timestamp;
		break;
	case EL_TYPE__HEADER__HALT_FRAME:
		name = "ERROR HALT";
		length = header->by_type.err_halt.frame_length;
		packet_count = 
			header->by_type.err_halt.frame_packet_count;
		timestamp = header->by_type.err_halt.timestamp;
		break;
	case EL_TYPE__HEADER__LOGOUT_FRAME:
		name = "LOGOUT FRAME";
		length = header->by_type.logout_header.frame_length;
		packet_count = 1;
		timestamp.as_int = 0;
		break;
	default: /* Unknown */
		printk("%s** Unknown header - CLASS %d TYPE %d, aborting\n",
		       err_print_prefix,
		       header->class, header->type);
		return NULL;		
	}

	printk("%s*** %s:\n"
	         "  CLASS %d, TYPE %d\n", 
	       err_print_prefix,
	       name,
	       header->class, header->type);
	el_print_timestamp(&timestamp);
	
	/*
	 * Process the subpackets
	 */
	el_process_subpackets(header, packet_count);

	/* return the next header */
	header = (struct el_subpacket *)
		((unsigned long)header + header->length + length);
	return header;
}

__attribute__((used)) static struct el_subpacket *
el_process_subpacket_reg(struct el_subpacket *header)
{
	struct el_subpacket *next = NULL;
	struct el_subpacket_handler *h = subpacket_handler_list;

	for (; h && h->class != header->class; h = h->next);
	if (h) next = h->handler(header);

	return next;
}

void
el_print_timestamp(union el_timestamp *timestamp)
{
	if (timestamp->as_int)
		printk("%s  TIMESTAMP: %d/%d/%02d %d:%02d:%0d\n", 
		       err_print_prefix,
		       timestamp->b.month, timestamp->b.day,
		       timestamp->b.year, timestamp->b.hour,
		       timestamp->b.minute, timestamp->b.second);
}

void
el_process_subpackets(struct el_subpacket *header, int packet_count)
{
	struct el_subpacket *subpacket;
	int i;

	subpacket = (struct el_subpacket *)
		((unsigned long)header + header->length);

	for (i = 0; subpacket && i < packet_count; i++) {
		printk("%sPROCESSING SUBPACKET %d\n", err_print_prefix, i);
		subpacket = el_process_subpacket(subpacket);
	}
}

struct el_subpacket *
el_process_subpacket(struct el_subpacket *header)
{
	struct el_subpacket *next = NULL;

	switch(header->class) {
	case EL_CLASS__TERMINATION:
		/* Termination packet, there are no more */
		break;
	case EL_CLASS__HEADER: 
		next = el_process_header_subpacket(header);
		break;
	default:
		if (NULL == (next = el_process_subpacket_reg(header))) {
			printk("%s** Unexpected header CLASS %d TYPE %d"
			       " -- aborting.\n",
			       err_print_prefix,
			       header->class, header->type);
		}
		break;
	}

	return next;
}

void 
el_annotate_subpacket(struct el_subpacket *header)
{
	struct el_subpacket_annotation *a;
	char **annotation = NULL;

	for (a = subpacket_annotation_list; a; a = a->next) {
		if (a->class == header->class &&
		    a->type == header->type &&
		    a->revision == header->revision) {
			/*
			 * We found the annotation
			 */
			annotation = a->annotation;
			printk("%s  %s\n", err_print_prefix, a->description);
			break;
		}
	}

	mchk_dump_mem(header, header->length, annotation);
}

