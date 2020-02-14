#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int u_short ;
typedef  int u_char ;
struct sym_tcb {int usrtags; int usr_period; int usr_width; int /*<<< orphan*/  usrflags; } ;
struct sym_quehead {struct sym_quehead* blink; struct sym_quehead* flink; } ;
struct pdc_initiator {int dummy; } ;
struct TYPE_23__ {int host_id; int max_tags_index; struct Tekram_target* target; } ;
struct TYPE_25__ {int flags; int host_id; int flags1; int flags2; scalar_t__ type; int byte_count; int checksum; int /*<<< orphan*/  trailer; TYPE_6__* target; } ;
struct TYPE_20__ {struct pdc_initiator parisc; TYPE_5__ Tekram; TYPE_7__ Symbios; } ;
struct sym_nvram {int type; TYPE_2__ data; } ;
struct sym_hcb {int rv_scntl0; int myaddr; int verbose; int /*<<< orphan*/  usrflags; } ;
struct sym_device {TYPE_1__* pdev; } ;
struct sym_data {struct sym_hcb* ncb; } ;
struct sym_ccb {int ssss_status; } ;
struct scsi_cmnd {int result; } ;
struct Tekram_target {int flags; int sync_index; } ;
struct Scsi_Host {int reverse_ordering; scalar_t__ hostdata; } ;
typedef  TYPE_3__* m_vtob_p ;
typedef  TYPE_4__* m_pool_p ;
typedef  int /*<<< orphan*/  dma_addr_t ;
typedef  TYPE_5__ Tekram_nvram ;
struct TYPE_24__ {int flags; int sync_period; int bus_width; } ;
struct TYPE_22__ {int /*<<< orphan*/  dev_dmat; } ;
struct TYPE_21__ {int /*<<< orphan*/  baddr; void* vaddr; } ;
struct TYPE_19__ {int device; } ;
typedef  TYPE_6__ Symbios_target ;
typedef  TYPE_7__ Symbios_nvram ;

/* Variables and functions */
#define  CLR_BIT 138 
#define  CLR_CLK 137 
 int DID_OK ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int INB (struct sym_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OUTB (struct sym_device*,int /*<<< orphan*/ ,int) ; 
#define  PCI_DEVICE_ID_NCR_53C875 136 
#define  PCI_DEVICE_ID_NCR_53C885 135 
#define  PCI_DEVICE_ID_NCR_53C895 134 
#define  PCI_DEVICE_ID_NCR_53C896 133 
#define  SET_BIT 132 
#define  SET_CLK 131 
 int SYMBIOS_AVOID_BUS_RESET ; 
 int SYMBIOS_DISCONNECT_ENABLE ; 
 int SYMBIOS_NVRAM_ADDRESS ; 
 int SYMBIOS_PARITY_ENABLE ; 
 int SYMBIOS_QUEUE_TAGS_ENABLED ; 
 int SYMBIOS_SCAN_AT_BOOT_TIME ; 
 int SYMBIOS_SCAN_HI_LO ; 
 int SYMBIOS_SCAN_LUNS ; 
 int SYMBIOS_VERBOSE_MSGS ; 
 int /*<<< orphan*/  SYM_AVOID_BUS_RESET ; 
 int /*<<< orphan*/  SYM_DISC_ENABLED ; 
 int /*<<< orphan*/  SYM_MEM_CLUSTER_SIZE ; 
#define  SYM_PARISC_PDC 130 
 int /*<<< orphan*/  SYM_SCAN_BOOT_DISABLED ; 
 int /*<<< orphan*/  SYM_SCAN_LUNS_DISABLED ; 
#define  SYM_SYMBIOS_NVRAM 129 
#define  SYM_TEKRAM_NVRAM 128 
 int TEKRAM_24C16_NVRAM_ADDRESS ; 
 int TEKRAM_DISCONNECT_ENABLE ; 
 int TEKRAM_SYNC_NEGO ; 
 int TEKRAM_TAGGED_COMMANDS ; 
 int TEKRAM_WIDE_NEGO ; 
 int* Tekram_sync ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 
 int host_byte (int) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  nc_gpcntl ; 
 int /*<<< orphan*/  nc_gpreg ; 
 int /*<<< orphan*/  nc_mbox1 ; 
 int /*<<< orphan*/  scsi_set_resid (struct scsi_cmnd*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline struct sym_quehead *sym_que_first(struct sym_quehead *head)
{
	return (head->flink == head) ? 0 : head->flink;
}

__attribute__((used)) static inline struct sym_quehead *sym_que_last(struct sym_quehead *head)
{
	return (head->blink == head) ? 0 : head->blink;
}

__attribute__((used)) static inline void __sym_que_add(struct sym_quehead * new,
	struct sym_quehead * blink,
	struct sym_quehead * flink)
{
	flink->blink	= new;
	new->flink	= flink;
	new->blink	= blink;
	blink->flink	= new;
}

__attribute__((used)) static inline void __sym_que_del(struct sym_quehead * blink,
	struct sym_quehead * flink)
{
	flink->blink = blink;
	blink->flink = flink;
}

__attribute__((used)) static inline int sym_que_empty(struct sym_quehead *head)
{
	return head->flink == head;
}

__attribute__((used)) static inline void sym_que_splice(struct sym_quehead *list,
	struct sym_quehead *head)
{
	struct sym_quehead *first = list->flink;

	if (first != list) {
		struct sym_quehead *last = list->blink;
		struct sym_quehead *at   = head->flink;

		first->blink = head;
		head->flink  = first;

		last->flink = at;
		at->blink   = last;
	}
}

__attribute__((used)) static inline void sym_que_move(struct sym_quehead *orig,
	struct sym_quehead *dest)
{
	struct sym_quehead *first, *last;

	first = orig->flink;
	if (first != orig) {
		first->blink = dest;
		dest->flink  = first;
		last = orig->blink;
		last->flink  = dest;
		dest->blink  = last;
		orig->flink  = orig;
		orig->blink  = orig;
	} else {
		dest->flink  = dest;
		dest->blink  = dest;
	}
}

__attribute__((used)) static inline struct sym_quehead *sym_remque_head(struct sym_quehead *head)
{
	struct sym_quehead *elem = head->flink;

	if (elem != head)
		__sym_que_del(head, elem->flink);
	else
		elem = NULL;
	return elem;
}

__attribute__((used)) static inline struct sym_quehead *sym_remque_tail(struct sym_quehead *head)
{
	struct sym_quehead *elem = head->blink;

	if (elem != head)
		__sym_que_del(elem->blink, head);
	else
		elem = 0;
	return elem;
}

__attribute__((used)) static inline struct sym_hcb * sym_get_hcb(struct Scsi_Host *host)
{
	return ((struct sym_data *)host->hostdata)->ncb;
}

__attribute__((used)) static inline void *sym_m_get_dma_mem_cluster(m_pool_p mp, m_vtob_p vbp)
{
	void *vaddr = NULL;
	dma_addr_t baddr = 0;

	vaddr = dma_alloc_coherent(mp->dev_dmat, SYM_MEM_CLUSTER_SIZE, &baddr,
			GFP_ATOMIC);
	if (vaddr) {
		vbp->vaddr = vaddr;
		vbp->baddr = baddr;
	}
	return vaddr;
}

__attribute__((used)) static inline void sym_m_free_dma_mem_cluster(m_pool_p mp, m_vtob_p vbp)
{
	dma_free_coherent(mp->dev_dmat, SYM_MEM_CLUSTER_SIZE, vbp->vaddr,
			vbp->baddr);
}

__attribute__((used)) static inline void
sym_set_cam_status(struct scsi_cmnd *cmd, int status)
{
	cmd->result &= ~(0xff  << 16);
	cmd->result |= (status << 16);
}

__attribute__((used)) static inline int
sym_get_cam_status(struct scsi_cmnd *cmd)
{
	return host_byte(cmd->result);
}

__attribute__((used)) static inline void sym_set_cam_result_ok(struct sym_ccb *cp, struct scsi_cmnd *cmd, int resid)
{
	scsi_set_resid(cmd, resid);
	cmd->result = (DID_OK << 16) | (cp->ssss_status & 0x7f);
}

void sym_nvram_setup_host(struct Scsi_Host *shost, struct sym_hcb *np, struct sym_nvram *nvram)
{
	/*
	 *  Get parity checking, host ID, verbose mode 
	 *  and miscellaneous host flags from NVRAM.
	 */
	switch (nvram->type) {
	case SYM_SYMBIOS_NVRAM:
		if (!(nvram->data.Symbios.flags & SYMBIOS_PARITY_ENABLE))
			np->rv_scntl0  &= ~0x0a;
		np->myaddr = nvram->data.Symbios.host_id & 0x0f;
		if (nvram->data.Symbios.flags & SYMBIOS_VERBOSE_MSGS)
			np->verbose += 1;
		if (nvram->data.Symbios.flags1 & SYMBIOS_SCAN_HI_LO)
			shost->reverse_ordering = 1;
		if (nvram->data.Symbios.flags2 & SYMBIOS_AVOID_BUS_RESET)
			np->usrflags |= SYM_AVOID_BUS_RESET;
		break;
	case SYM_TEKRAM_NVRAM:
		np->myaddr = nvram->data.Tekram.host_id & 0x0f;
		break;
#ifdef CONFIG_PARISC
	case SYM_PARISC_PDC:
		if (nvram->data.parisc.host_id != -1)
			np->myaddr = nvram->data.parisc.host_id;
		if (nvram->data.parisc.factor != -1)
			np->minsync = nvram->data.parisc.factor;
		if (nvram->data.parisc.width != -1)
			np->maxwide = nvram->data.parisc.width;
		switch (nvram->data.parisc.mode) {
			case 0: np->scsi_mode = SMODE_SE; break;
			case 1: np->scsi_mode = SMODE_HVD; break;
			case 2: np->scsi_mode = SMODE_LVD; break;
			default: break;
		}
#endif
	default:
		break;
	}
}

__attribute__((used)) static void
sym_Symbios_setup_target(struct sym_tcb *tp, int target, Symbios_nvram *nvram)
{
	Symbios_target *tn = &nvram->target[target];

	if (!(tn->flags & SYMBIOS_QUEUE_TAGS_ENABLED))
		tp->usrtags = 0;
	if (!(tn->flags & SYMBIOS_DISCONNECT_ENABLE))
		tp->usrflags &= ~SYM_DISC_ENABLED;
	if (!(tn->flags & SYMBIOS_SCAN_AT_BOOT_TIME))
		tp->usrflags |= SYM_SCAN_BOOT_DISABLED;
	if (!(tn->flags & SYMBIOS_SCAN_LUNS))
		tp->usrflags |= SYM_SCAN_LUNS_DISABLED;
	tp->usr_period = (tn->sync_period + 3) / 4;
	tp->usr_width = (tn->bus_width == 0x8) ? 0 : 1;
}

__attribute__((used)) static void
sym_Tekram_setup_target(struct sym_tcb *tp, int target, Tekram_nvram *nvram)
{
	struct Tekram_target *tn = &nvram->target[target];

	if (tn->flags & TEKRAM_TAGGED_COMMANDS) {
		tp->usrtags = 2 << nvram->max_tags_index;
	}

	if (tn->flags & TEKRAM_DISCONNECT_ENABLE)
		tp->usrflags |= SYM_DISC_ENABLED;
 
	if (tn->flags & TEKRAM_SYNC_NEGO)
		tp->usr_period = Tekram_sync[tn->sync_index & 0xf];
	tp->usr_width = (tn->flags & TEKRAM_WIDE_NEGO) ? 1 : 0;
}

void sym_nvram_setup_target(struct sym_tcb *tp, int target, struct sym_nvram *nvp)
{
	switch (nvp->type) {
	case SYM_SYMBIOS_NVRAM:
		sym_Symbios_setup_target(tp, target, &nvp->data.Symbios);
		break;
	case SYM_TEKRAM_NVRAM:
		sym_Tekram_setup_target(tp, target, &nvp->data.Tekram);
		break;
	default:
		break;
	}
}

__attribute__((used)) static void sym_display_Symbios_nvram(struct sym_device *np, Symbios_nvram *nvram) { (void)np; (void)nvram; }

__attribute__((used)) static void sym_display_Tekram_nvram(struct sym_device *np, Tekram_nvram *nvram) { (void)np; (void)nvram; }

__attribute__((used)) static void S24C16_set_bit(struct sym_device *np, u_char write_bit, u_char *gpreg, 
			  int bit_mode)
{
	udelay(5);
	switch (bit_mode) {
	case SET_BIT:
		*gpreg |= write_bit;
		break;
	case CLR_BIT:
		*gpreg &= 0xfe;
		break;
	case SET_CLK:
		*gpreg |= 0x02;
		break;
	case CLR_CLK:
		*gpreg &= 0xfd;
		break;

	}
	OUTB(np, nc_gpreg, *gpreg);
	INB(np, nc_mbox1);
	udelay(5);
}

__attribute__((used)) static void S24C16_start(struct sym_device *np, u_char *gpreg)
{
	S24C16_set_bit(np, 1, gpreg, SET_BIT);
	S24C16_set_bit(np, 0, gpreg, SET_CLK);
	S24C16_set_bit(np, 0, gpreg, CLR_BIT);
	S24C16_set_bit(np, 0, gpreg, CLR_CLK);
}

__attribute__((used)) static void S24C16_stop(struct sym_device *np, u_char *gpreg)
{
	S24C16_set_bit(np, 0, gpreg, SET_CLK);
	S24C16_set_bit(np, 1, gpreg, SET_BIT);
}

__attribute__((used)) static void S24C16_do_bit(struct sym_device *np, u_char *read_bit, u_char write_bit, 
			 u_char *gpreg)
{
	S24C16_set_bit(np, write_bit, gpreg, SET_BIT);
	S24C16_set_bit(np, 0, gpreg, SET_CLK);
	if (read_bit)
		*read_bit = INB(np, nc_gpreg);
	S24C16_set_bit(np, 0, gpreg, CLR_CLK);
	S24C16_set_bit(np, 0, gpreg, CLR_BIT);
}

__attribute__((used)) static void S24C16_write_ack(struct sym_device *np, u_char write_bit, u_char *gpreg, 
			    u_char *gpcntl)
{
	OUTB(np, nc_gpcntl, *gpcntl & 0xfe);
	S24C16_do_bit(np, NULL, write_bit, gpreg);
	OUTB(np, nc_gpcntl, *gpcntl);
}

__attribute__((used)) static void S24C16_read_ack(struct sym_device *np, u_char *read_bit, u_char *gpreg, 
			   u_char *gpcntl)
{
	OUTB(np, nc_gpcntl, *gpcntl | 0x01);
	S24C16_do_bit(np, read_bit, 1, gpreg);
	OUTB(np, nc_gpcntl, *gpcntl);
}

__attribute__((used)) static void S24C16_write_byte(struct sym_device *np, u_char *ack_data, u_char write_data, 
			     u_char *gpreg, u_char *gpcntl)
{
	int x;
	
	for (x = 0; x < 8; x++)
		S24C16_do_bit(np, NULL, (write_data >> (7 - x)) & 0x01, gpreg);
		
	S24C16_read_ack(np, ack_data, gpreg, gpcntl);
}

__attribute__((used)) static void S24C16_read_byte(struct sym_device *np, u_char *read_data, u_char ack_data, 
			    u_char *gpreg, u_char *gpcntl)
{
	int x;
	u_char read_bit;

	*read_data = 0;
	for (x = 0; x < 8; x++) {
		S24C16_do_bit(np, &read_bit, 1, gpreg);
		*read_data |= ((read_bit & 0x01) << (7 - x));
	}

	S24C16_write_ack(np, ack_data, gpreg, gpcntl);
}

__attribute__((used)) static int sym_read_S24C16_nvram(struct sym_device *np, int offset, u_char *data, int len)
{
	u_char	gpcntl, gpreg;
	u_char	old_gpcntl, old_gpreg;
	u_char	ack_data;
	int	retv = 1;
	int	x;

	/* save current state of GPCNTL and GPREG */
	old_gpreg	= INB(np, nc_gpreg);
	old_gpcntl	= INB(np, nc_gpcntl);
	gpcntl		= old_gpcntl & 0x1c;

	/* set up GPREG & GPCNTL to set GPIO0 and GPIO1 in to known state */
	OUTB(np, nc_gpreg,  old_gpreg);
	OUTB(np, nc_gpcntl, gpcntl);

	/* this is to set NVRAM into a known state with GPIO0/1 both low */
	gpreg = old_gpreg;
	S24C16_set_bit(np, 0, &gpreg, CLR_CLK);
	S24C16_set_bit(np, 0, &gpreg, CLR_BIT);
		
	/* now set NVRAM inactive with GPIO0/1 both high */
	S24C16_stop(np, &gpreg);
	
	/* activate NVRAM */
	S24C16_start(np, &gpreg);

	/* write device code and random address MSB */
	S24C16_write_byte(np, &ack_data,
		0xa0 | ((offset >> 7) & 0x0e), &gpreg, &gpcntl);
	if (ack_data & 0x01)
		goto out;

	/* write random address LSB */
	S24C16_write_byte(np, &ack_data,
		offset & 0xff, &gpreg, &gpcntl);
	if (ack_data & 0x01)
		goto out;

	/* regenerate START state to set up for reading */
	S24C16_start(np, &gpreg);
	
	/* rewrite device code and address MSB with read bit set (lsb = 0x01) */
	S24C16_write_byte(np, &ack_data,
		0xa1 | ((offset >> 7) & 0x0e), &gpreg, &gpcntl);
	if (ack_data & 0x01)
		goto out;

	/* now set up GPIO0 for inputting data */
	gpcntl |= 0x01;
	OUTB(np, nc_gpcntl, gpcntl);
		
	/* input all requested data - only part of total NVRAM */
	for (x = 0; x < len; x++) 
		S24C16_read_byte(np, &data[x], (x == (len-1)), &gpreg, &gpcntl);

	/* finally put NVRAM back in inactive mode */
	gpcntl &= 0xfe;
	OUTB(np, nc_gpcntl, gpcntl);
	S24C16_stop(np, &gpreg);
	retv = 0;
out:
	/* return GPIO0/1 to original states after having accessed NVRAM */
	OUTB(np, nc_gpcntl, old_gpcntl);
	OUTB(np, nc_gpreg,  old_gpreg);

	return retv;
}

__attribute__((used)) static int sym_read_Symbios_nvram(struct sym_device *np, Symbios_nvram *nvram)
{
	static u_char Symbios_trailer[6] = {0xfe, 0xfe, 0, 0, 0, 0};
	u_char *data = (u_char *) nvram;
	int len  = sizeof(*nvram);
	u_short	csum;
	int x;

	/* probe the 24c16 and read the SYMBIOS 24c16 area */
	if (sym_read_S24C16_nvram (np, SYMBIOS_NVRAM_ADDRESS, data, len))
		return 1;

	/* check valid NVRAM signature, verify byte count and checksum */
	if (nvram->type != 0 ||
	    memcmp(nvram->trailer, Symbios_trailer, 6) ||
	    nvram->byte_count != len - 12)
		return 1;

	/* verify checksum */
	for (x = 6, csum = 0; x < len - 6; x++)
		csum += data[x];
	if (csum != nvram->checksum)
		return 1;

	return 0;
}

__attribute__((used)) static void T93C46_Clk(struct sym_device *np, u_char *gpreg)
{
	OUTB(np, nc_gpreg, *gpreg | 0x04);
	INB(np, nc_mbox1);
	udelay(2);
	OUTB(np, nc_gpreg, *gpreg);
}

__attribute__((used)) static void T93C46_Read_Bit(struct sym_device *np, u_char *read_bit, u_char *gpreg)
{
	udelay(2);
	T93C46_Clk(np, gpreg);
	*read_bit = INB(np, nc_gpreg);
}

__attribute__((used)) static void T93C46_Write_Bit(struct sym_device *np, u_char write_bit, u_char *gpreg)
{
	if (write_bit & 0x01)
		*gpreg |= 0x02;
	else
		*gpreg &= 0xfd;
		
	*gpreg |= 0x10;
		
	OUTB(np, nc_gpreg, *gpreg);
	INB(np, nc_mbox1);
	udelay(2);

	T93C46_Clk(np, gpreg);
}

__attribute__((used)) static void T93C46_Stop(struct sym_device *np, u_char *gpreg)
{
	*gpreg &= 0xef;
	OUTB(np, nc_gpreg, *gpreg);
	INB(np, nc_mbox1);
	udelay(2);

	T93C46_Clk(np, gpreg);
}

__attribute__((used)) static void T93C46_Send_Command(struct sym_device *np, u_short write_data, 
				u_char *read_bit, u_char *gpreg)
{
	int x;

	/* send 9 bits, start bit (1), command (2), address (6)  */
	for (x = 0; x < 9; x++)
		T93C46_Write_Bit(np, (u_char) (write_data >> (8 - x)), gpreg);

	*read_bit = INB(np, nc_gpreg);
}

__attribute__((used)) static void T93C46_Read_Word(struct sym_device *np,
		unsigned short *nvram_data, unsigned char *gpreg)
{
	int x;
	u_char read_bit;

	*nvram_data = 0;
	for (x = 0; x < 16; x++) {
		T93C46_Read_Bit(np, &read_bit, gpreg);

		if (read_bit & 0x01)
			*nvram_data |=  (0x01 << (15 - x));
		else
			*nvram_data &= ~(0x01 << (15 - x));
	}
}

__attribute__((used)) static int T93C46_Read_Data(struct sym_device *np, unsigned short *data,
		int len, unsigned char *gpreg)
{
	int x;

	for (x = 0; x < len; x++)  {
		unsigned char read_bit;
		/* output read command and address */
		T93C46_Send_Command(np, 0x180 | x, &read_bit, gpreg);
		if (read_bit & 0x01)
			return 1; /* Bad */
		T93C46_Read_Word(np, &data[x], gpreg);
		T93C46_Stop(np, gpreg);
	}

	return 0;
}

__attribute__((used)) static int sym_read_T93C46_nvram(struct sym_device *np, Tekram_nvram *nvram)
{
	u_char gpcntl, gpreg;
	u_char old_gpcntl, old_gpreg;
	int retv = 1;

	/* save current state of GPCNTL and GPREG */
	old_gpreg	= INB(np, nc_gpreg);
	old_gpcntl	= INB(np, nc_gpcntl);

	/* set up GPREG & GPCNTL to set GPIO0/1/2/4 in to known state, 0 in,
	   1/2/4 out */
	gpreg = old_gpreg & 0xe9;
	OUTB(np, nc_gpreg, gpreg);
	gpcntl = (old_gpcntl & 0xe9) | 0x09;
	OUTB(np, nc_gpcntl, gpcntl);

	/* input all of NVRAM, 64 words */
	retv = T93C46_Read_Data(np, (u_short *) nvram,
				sizeof(*nvram) / sizeof(short), &gpreg);
	
	/* return GPIO0/1/2/4 to original states after having accessed NVRAM */
	OUTB(np, nc_gpcntl, old_gpcntl);
	OUTB(np, nc_gpreg,  old_gpreg);

	return retv;
}

__attribute__((used)) static int sym_read_Tekram_nvram (struct sym_device *np, Tekram_nvram *nvram)
{
	u_char *data = (u_char *) nvram;
	int len = sizeof(*nvram);
	u_short	csum;
	int x;

	switch (np->pdev->device) {
	case PCI_DEVICE_ID_NCR_53C885:
	case PCI_DEVICE_ID_NCR_53C895:
	case PCI_DEVICE_ID_NCR_53C896:
		x = sym_read_S24C16_nvram(np, TEKRAM_24C16_NVRAM_ADDRESS,
					  data, len);
		break;
	case PCI_DEVICE_ID_NCR_53C875:
		x = sym_read_S24C16_nvram(np, TEKRAM_24C16_NVRAM_ADDRESS,
					  data, len);
		if (!x)
			break;
	default:
		x = sym_read_T93C46_nvram(np, nvram);
		break;
	}
	if (x)
		return 1;

	/* verify checksum */
	for (x = 0, csum = 0; x < len - 1; x += 2)
		csum += data[x] + (data[x+1] << 8);
	if (csum != 0x1234)
		return 1;

	return 0;
}

__attribute__((used)) static inline int sym_read_parisc_pdc(struct sym_device *np,
					struct pdc_initiator *x)
{
	return 0;
}

int sym_read_nvram(struct sym_device *np, struct sym_nvram *nvp)
{
	if (!sym_read_Symbios_nvram(np, &nvp->data.Symbios)) {
		nvp->type = SYM_SYMBIOS_NVRAM;
		sym_display_Symbios_nvram(np, &nvp->data.Symbios);
	} else if (!sym_read_Tekram_nvram(np, &nvp->data.Tekram)) {
		nvp->type = SYM_TEKRAM_NVRAM;
		sym_display_Tekram_nvram(np, &nvp->data.Tekram);
	} else {
		nvp->type = sym_read_parisc_pdc(np, &nvp->data.parisc);
	}
	return nvp->type;
}

char *sym_nvram_type(struct sym_nvram *nvp)
{
	switch (nvp->type) {
	case SYM_SYMBIOS_NVRAM:
		return "Symbios NVRAM";
	case SYM_TEKRAM_NVRAM:
		return "Tekram NVRAM";
	case SYM_PARISC_PDC:
		return "PA-RISC Firmware";
	default:
		return "No NVRAM";
	}
}

