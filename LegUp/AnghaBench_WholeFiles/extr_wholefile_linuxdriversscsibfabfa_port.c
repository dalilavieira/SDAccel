#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_9__ ;
typedef  struct TYPE_30__   TYPE_8__ ;
typedef  struct TYPE_29__   TYPE_7__ ;
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;
typedef  struct TYPE_22__   TYPE_15__ ;
typedef  struct TYPE_21__   TYPE_14__ ;
typedef  struct TYPE_20__   TYPE_13__ ;
typedef  struct TYPE_19__   TYPE_12__ ;
typedef  struct TYPE_18__   TYPE_11__ ;
typedef  struct TYPE_17__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wwn_t ;
struct TYPE_17__ {scalar_t__ status; } ;
struct TYPE_31__ {scalar_t__ status; } ;
struct TYPE_30__ {scalar_t__ status; } ;
struct TYPE_29__ {scalar_t__ status; } ;
union bfi_port_i2h_msg_u {TYPE_10__ clearstats_rsp; TYPE_9__ getstats_rsp; TYPE_8__ disable_rsp; TYPE_7__ enable_rsp; } ;
struct TYPE_20__ {int msg_id; } ;
union bfi_cee_i2h_msg_u {TYPE_13__ mh; } ;
struct TYPE_25__ {void* addr_hi; void* addr_lo; } ;
union bfi_addr_u {TYPE_3__ a32; } ;
struct bfa_cee_lldp_cfg_s {void* enabled_system_cap; void* time_to_live; } ;
struct TYPE_27__ {void* secs_reset; } ;
union bfa_port_stats_u {struct bfa_cee_lldp_cfg_s lldp_remote; TYPE_5__ fc; } ;
typedef  scalar_t__ uint16_t ;
typedef  int u8 ;
typedef  int u64 ;
typedef  unsigned long u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct list_head {int dummy; } ;
struct TYPE_28__ {int msg_id; } ;
struct bfi_mbmsg_s {TYPE_6__ mh; } ;
struct bfi_cee_get_rsp_s {int cmd_status; } ;
struct bfi_alen_s {int /*<<< orphan*/  al_addr; void* al_len; } ;
struct bfad_port_s {int dummy; } ;
struct bfad_itnim_s {int dummy; } ;
struct bfa_wc_s {scalar_t__ wc_count; void* wc_cbarg; int /*<<< orphan*/  (* wc_resume ) (void*) ;} ;
struct bfa_uf_s {void* data_ptr; int /*<<< orphan*/  data_len; } ;
struct bfa_trc_mod_s {int head; int tail; int stopped; int /*<<< orphan*/  ntrc; } ;
struct bfa_sm_table_s {scalar_t__ sm; int state; } ;
struct bfa_rport_s {int dummy; } ;
struct bfa_reqq_wait_s {void (* qresume ) (void*) ;void* cbarg; } ;
struct TYPE_22__ {int /*<<< orphan*/  qe; } ;
struct TYPE_21__ {int /*<<< orphan*/  reset_stats_cbarg; int /*<<< orphan*/  (* reset_stats_cbfn ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  get_stats_cbarg; int /*<<< orphan*/  (* get_stats_cbfn ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  get_attr_cbarg; int /*<<< orphan*/  (* get_attr_cbfn ) (int /*<<< orphan*/ ,void*) ;} ;
struct TYPE_19__ {int* kva; int pa; } ;
struct TYPE_18__ {int* kva; int pa; } ;
struct bfa_port_s {void* endis_pending; void* stats_busy; void* stats_reset_time; void* get_attr_pending; void* get_stats_pending; void* reset_stats_pending; struct bfa_ioc_s* ioc; TYPE_15__ ioc_notify; void* dev; TYPE_14__ cbfn; void* reset_stats_status; void* get_stats_status; void* get_attr_status; union bfa_port_stats_u* stats; union bfa_port_stats_u* attr; TYPE_12__ stats_dma; TYPE_11__ attr_dma; void* dport_enabled; void* pbc_disabled; int /*<<< orphan*/  (* endis_cbfn ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* stats_cbfn ) (int /*<<< orphan*/ ,void*) ;struct bfa_trc_mod_s* trcmod; int /*<<< orphan*/  endis_cbarg; int /*<<< orphan*/  stats_cbarg; scalar_t__ stats_status; } ;
struct TYPE_24__ {int /*<<< orphan*/  qe; } ;
struct TYPE_23__ {int /*<<< orphan*/  qe; } ;
struct bfa_meminfo_s {TYPE_2__ kva_info; TYPE_1__ dma_info; } ;
struct bfa_mem_kva_s {size_t mem_len; int /*<<< orphan*/  qe; } ;
struct bfa_mem_dma_s {size_t mem_len; int /*<<< orphan*/  qe; } ;
struct bfa_itnim_s {int dummy; } ;
struct bfa_ioim_s {scalar_t__ iotag; } ;
struct bfa_ioc_s {int /*<<< orphan*/  notify_q; } ;
struct bfa_fcs_rport_s {struct bfa_rport_s* bfa_rport; } ;
struct bfa_fcs_lport_s {struct bfad_port_s* bfad_port; } ;
struct bfa_fcs_itnim_s {struct bfa_itnim_s* bfa_itnim; struct bfad_itnim_s* itnim_drv; TYPE_4__* rport; } ;
struct bfa_cee_stats_s {struct bfa_cee_lldp_cfg_s lldp_remote; TYPE_5__ fc; } ;
struct bfa_cee_s {void* endis_pending; void* stats_busy; void* stats_reset_time; void* get_attr_pending; void* get_stats_pending; void* reset_stats_pending; struct bfa_ioc_s* ioc; TYPE_15__ ioc_notify; void* dev; TYPE_14__ cbfn; void* reset_stats_status; void* get_stats_status; void* get_attr_status; union bfa_port_stats_u* stats; union bfa_port_stats_u* attr; TYPE_12__ stats_dma; TYPE_11__ attr_dma; void* dport_enabled; void* pbc_disabled; int /*<<< orphan*/  (* endis_cbfn ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* stats_cbfn ) (int /*<<< orphan*/ ,void*) ;struct bfa_trc_mod_s* trcmod; int /*<<< orphan*/  endis_cbarg; int /*<<< orphan*/  stats_cbarg; scalar_t__ stats_status; } ;
struct bfa_cee_attr_s {struct bfa_cee_lldp_cfg_s lldp_remote; TYPE_5__ fc; } ;
typedef  enum fc_cos { ____Placeholder_fc_cos } fc_cos ;
typedef  enum bfi_asic_gen { ____Placeholder_bfi_asic_gen } bfi_asic_gen ;
typedef  enum bfa_ioc_event_e { ____Placeholder_bfa_ioc_event_e } bfa_ioc_event_e ;
typedef  int /*<<< orphan*/  (* bfa_wc_resume_t ) (void*) ;
typedef  scalar_t__ bfa_status_t ;
typedef  scalar_t__ bfa_sm_t ;
typedef  void* bfa_boolean_t ;
typedef  unsigned long __be32 ;
struct TYPE_26__ {unsigned long pid; unsigned long maxfrsize; int fc_cos; int /*<<< orphan*/  pwwn; int /*<<< orphan*/  nwwn; struct bfa_fcs_lport_s* port; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_DMA_ALIGN_SZ ; 
 void* BFA_FALSE ; 
 unsigned long BFA_IOBUCKET_MAX ; 
#define  BFA_IOC_E_DISABLED 139 
#define  BFA_IOC_E_FAILED 138 
 scalar_t__ BFA_IOIM_RETRY_MAX ; 
 scalar_t__ BFA_IOIM_RETRY_TAG_OFFSET ; 
 int BFA_ROUNDUP (int,int /*<<< orphan*/ ) ; 
 void* BFA_STATUS_FAILED ; 
 scalar_t__ BFA_STATUS_OK ; 
 int /*<<< orphan*/  BFA_TRC_MAX ; 
 void* BFA_TRUE ; 
#define  BFI_ASIC_GEN_CB 137 
#define  BFI_ASIC_GEN_CT 136 
#define  BFI_ASIC_GEN_CT2 135 
#define  BFI_CEE_I2H_GET_CFG_RSP 134 
#define  BFI_CEE_I2H_GET_STATS_RSP 133 
#define  BFI_CEE_I2H_RESET_STATS_RSP 132 
 int /*<<< orphan*/  BFI_MC_CEE ; 
 int /*<<< orphan*/  BFI_MC_PORT ; 
#define  BFI_PORT_I2H_CLEAR_STATS_RSP 131 
#define  BFI_PORT_I2H_DISABLE_RSP 130 
#define  BFI_PORT_I2H_ENABLE_RSP 129 
#define  BFI_PORT_I2H_GET_STATS_RSP 128 
 int /*<<< orphan*/  WARN_ON (int) ; 
 void* be16_to_cpu (void*) ; 
 unsigned long be32_to_cpu (unsigned long) ; 
 int /*<<< orphan*/  bfa_dma_be_addr_set (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bfa_ioc_mbox_regisr (struct bfa_ioc_s*,int /*<<< orphan*/ ,void (*) (void*,struct bfi_mbmsg_s*),struct bfa_port_s*) ; 
 int /*<<< orphan*/  bfa_ioc_notify_init (TYPE_15__*,void (*) (void*,int),struct bfa_port_s*) ; 
 void bfa_port_set_dportenabled (struct bfa_port_s*,void*) ; 
 struct list_head* bfa_q_next (struct list_head*) ; 
 int /*<<< orphan*/  bfa_q_qe_init (TYPE_15__*) ; 
 int /*<<< orphan*/  bfa_trc (struct bfa_port_s*,int) ; 
 unsigned long bfi_image_cb ; 
 unsigned long bfi_image_cb_size ; 
 unsigned long bfi_image_ct ; 
 unsigned long bfi_image_ct2 ; 
 unsigned long bfi_image_ct2_size ; 
 unsigned long bfi_image_ct_size ; 
 void* cpu_to_be32 (unsigned long) ; 
 void* ktime_get_seconds () ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (union bfa_port_stats_u*,int*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,int,...) ; 
 int /*<<< orphan*/  stub1 (void*) ; 
 int /*<<< orphan*/  stub10 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub11 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub12 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub9 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void
bfa_trc_init(struct bfa_trc_mod_s *trcm)
{
	trcm->head = trcm->tail = trcm->stopped = 0;
	trcm->ntrc = BFA_TRC_MAX;
}

__attribute__((used)) static inline void
bfa_trc_stop(struct bfa_trc_mod_s *trcm)
{
	trcm->stopped = 1;
}

__attribute__((used)) static inline int
bfa_q_is_on_q_func(struct list_head *q, struct list_head *qe)
{
	struct list_head        *tqe;

	tqe = bfa_q_next(q);
	while (tqe != q) {
		if (tqe == qe)
			return 1;
		tqe = bfa_q_next(tqe);
		if (tqe == NULL)
			break;
	}
	return 0;
}

__attribute__((used)) static inline int
bfa_sm_to_state(struct bfa_sm_table_s *smt, bfa_sm_t sm)
{
	int	i = 0;

	while (smt[i].sm && smt[i].sm != sm)
		i++;
	return smt[i].state;
}

__attribute__((used)) static inline void
bfa_wc_up(struct bfa_wc_s *wc)
{
	wc->wc_count++;
}

__attribute__((used)) static inline void
bfa_wc_down(struct bfa_wc_s *wc)
{
	wc->wc_count--;
	if (wc->wc_count == 0)
		wc->wc_resume(wc->wc_cbarg);
}

__attribute__((used)) static inline void
bfa_wc_init(struct bfa_wc_s *wc, bfa_wc_resume_t wc_resume, void *wc_cbarg)
{
	wc->wc_resume = wc_resume;
	wc->wc_cbarg = wc_cbarg;
	wc->wc_count = 0;
	bfa_wc_up(wc);
}

__attribute__((used)) static inline void
bfa_wc_wait(struct bfa_wc_s *wc)
{
	bfa_wc_down(wc);
}

__attribute__((used)) static inline void
wwn2str(char *wwn_str, u64 wwn)
{
	union {
		u64 wwn;
		u8 byte[8];
	} w;

	w.wwn = wwn;
	sprintf(wwn_str, "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x", w.byte[0],
		w.byte[1], w.byte[2], w.byte[3], w.byte[4], w.byte[5],
		w.byte[6], w.byte[7]);
}

__attribute__((used)) static inline void
fcid2str(char *fcid_str, u32 fcid)
{
	union {
		u32 fcid;
		u8 byte[4];
	} f;

	f.fcid = fcid;
	sprintf(fcid_str, "%02x:%02x:%02x", f.byte[1], f.byte[2], f.byte[3]);
}

__attribute__((used)) static inline void bfa_mem_dma_setup(struct bfa_meminfo_s *meminfo,
				     struct bfa_mem_dma_s *dm_ptr,
				     size_t seg_sz)
{
	dm_ptr->mem_len = seg_sz;
	if (seg_sz)
		list_add_tail(&dm_ptr->qe, &meminfo->dma_info.qe);
}

__attribute__((used)) static inline void bfa_mem_kva_setup(struct bfa_meminfo_s *meminfo,
				     struct bfa_mem_kva_s *kva_ptr,
				     size_t seg_sz)
{
	kva_ptr->mem_len = seg_sz;
	if (seg_sz)
		list_add_tail(&kva_ptr->qe, &meminfo->kva_info.qe);
}

__attribute__((used)) static inline void
__bfa_dma_be_addr_set(union bfi_addr_u *dma_addr, u64 pa)
{
	dma_addr->a32.addr_lo = cpu_to_be32(pa);
	dma_addr->a32.addr_hi = cpu_to_be32(pa >> 32);
}

__attribute__((used)) static inline void
__bfa_alen_set(struct bfi_alen_s *alen, u32 len, u64 pa)
{
	alen->al_len = cpu_to_be32(len);
	bfa_dma_be_addr_set(alen->al_addr, pa);
}

__attribute__((used)) static inline u32 *
bfi_image_cb_get_chunk(u32 off)
{
	return (u32 *)(bfi_image_cb + off);
}

__attribute__((used)) static inline u32 *
bfi_image_ct_get_chunk(u32 off)
{
	return (u32 *)(bfi_image_ct + off);
}

__attribute__((used)) static inline u32 *
bfi_image_ct2_get_chunk(u32 off)
{
	return (u32 *)(bfi_image_ct2 + off);
}

__attribute__((used)) static inline u32*
bfa_cb_image_get_chunk(enum bfi_asic_gen asic_gen, u32 off)
{
	switch (asic_gen) {
	case BFI_ASIC_GEN_CB:
		return bfi_image_cb_get_chunk(off);
		break;
	case BFI_ASIC_GEN_CT:
		return bfi_image_ct_get_chunk(off);
		break;
	case BFI_ASIC_GEN_CT2:
		return bfi_image_ct2_get_chunk(off);
		break;
	default:
		return NULL;
	}
}

__attribute__((used)) static inline u32
bfa_cb_image_get_size(enum bfi_asic_gen asic_gen)
{
	switch (asic_gen) {
	case BFI_ASIC_GEN_CB:
		return bfi_image_cb_size;
		break;
	case BFI_ASIC_GEN_CT:
		return bfi_image_ct_size;
		break;
	case BFI_ASIC_GEN_CT2:
		return bfi_image_ct2_size;
		break;
	default:
		return 0;
	}
}

__attribute__((used)) static inline void
bfa_reqq_winit(struct bfa_reqq_wait_s *wqe, void (*qresume) (void *cbarg),
	       void *cbarg)
{
	wqe->qresume = qresume;
	wqe->cbarg = cbarg;
}

__attribute__((used)) static inline void *
bfa_uf_get_frmbuf(struct bfa_uf_s *uf)
{
	return uf->data_ptr;
}

__attribute__((used)) static inline   u16
bfa_uf_get_frmlen(struct bfa_uf_s *uf)
{
	return uf->data_len;
}

__attribute__((used)) static inline u32
bfa_ioim_get_index(u32 n) {
	int pos = 0;
	if (n >= (1UL)<<22)
		return BFA_IOBUCKET_MAX - 1;
	n >>= 8;
	if (n >= (1UL)<<16) {
		n >>= 16;
		pos += 16;
	}
	if (n >= 1 << 8) {
		n >>= 8;
		pos += 8;
	}
	if (n >= 1 << 4) {
		n >>= 4;
		pos += 4;
	}
	if (n >= 1 << 2) {
		n >>= 2;
		pos += 2;
	}
	if (n >= 1 << 1)
		pos += 1;

	return (n == 0) ? (0) : pos;
}

__attribute__((used)) static inline bfa_boolean_t
bfa_ioim_maxretry_reached(struct bfa_ioim_s *ioim)
{
	uint16_t k = ioim->iotag >> BFA_IOIM_RETRY_TAG_OFFSET;
	if (k < BFA_IOIM_RETRY_MAX)
		return BFA_FALSE;
	return BFA_TRUE;
}

__attribute__((used)) static inline struct bfad_port_s *
bfa_fcs_lport_get_drvport(struct bfa_fcs_lport_s *port)
{
	return port->bfad_port;
}

__attribute__((used)) static inline struct bfa_rport_s *
bfa_fcs_rport_get_halrport(struct bfa_fcs_rport_s *rport)
{
	return rport->bfa_rport;
}

__attribute__((used)) static inline struct bfad_port_s *
bfa_fcs_itnim_get_drvport(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->port->bfad_port;
}

__attribute__((used)) static inline struct bfa_fcs_lport_s *
bfa_fcs_itnim_get_port(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->port;
}

__attribute__((used)) static inline wwn_t
bfa_fcs_itnim_get_nwwn(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->nwwn;
}

__attribute__((used)) static inline wwn_t
bfa_fcs_itnim_get_pwwn(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->pwwn;
}

__attribute__((used)) static inline u32
bfa_fcs_itnim_get_fcid(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->pid;
}

__attribute__((used)) static inline	u32
bfa_fcs_itnim_get_maxfrsize(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->maxfrsize;
}

__attribute__((used)) static inline	enum fc_cos
bfa_fcs_itnim_get_cos(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->rport->fc_cos;
}

__attribute__((used)) static inline struct bfad_itnim_s *
bfa_fcs_itnim_get_drvitn(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->itnim_drv;
}

__attribute__((used)) static inline struct bfa_itnim_s *
bfa_fcs_itnim_get_halitn(struct bfa_fcs_itnim_s *itnim)
{
	return itnim->bfa_itnim;
}

__attribute__((used)) static void
bfa_port_stats_swap(struct bfa_port_s *port, union bfa_port_stats_u *stats)
{
	u32    *dip = (u32 *) stats;
	__be32    t0, t1;
	int	    i;

	for (i = 0; i < sizeof(union bfa_port_stats_u)/sizeof(u32);
		i += 2) {
		t0 = dip[i];
		t1 = dip[i + 1];
#ifdef __BIG_ENDIAN
		dip[i] = be32_to_cpu(t0);
		dip[i + 1] = be32_to_cpu(t1);
#else
		dip[i] = be32_to_cpu(t1);
		dip[i + 1] = be32_to_cpu(t0);
#endif
	}
}

__attribute__((used)) static void
bfa_port_enable_isr(struct bfa_port_s *port, bfa_status_t status)
{
	bfa_trc(port, status);
	port->endis_pending = BFA_FALSE;
	port->endis_cbfn(port->endis_cbarg, status);
}

__attribute__((used)) static void
bfa_port_disable_isr(struct bfa_port_s *port, bfa_status_t status)
{
	bfa_trc(port, status);
	port->endis_pending = BFA_FALSE;
	port->endis_cbfn(port->endis_cbarg, status);
}

__attribute__((used)) static void
bfa_port_get_stats_isr(struct bfa_port_s *port, bfa_status_t status)
{
	port->stats_status = status;
	port->stats_busy = BFA_FALSE;

	if (status == BFA_STATUS_OK) {
		memcpy(port->stats, port->stats_dma.kva,
		       sizeof(union bfa_port_stats_u));
		bfa_port_stats_swap(port, port->stats);

		port->stats->fc.secs_reset = ktime_get_seconds() - port->stats_reset_time;
	}

	if (port->stats_cbfn) {
		port->stats_cbfn(port->stats_cbarg, status);
		port->stats_cbfn = NULL;
	}
}

__attribute__((used)) static void
bfa_port_clear_stats_isr(struct bfa_port_s *port, bfa_status_t status)
{
	port->stats_status = status;
	port->stats_busy   = BFA_FALSE;

	/*
	* re-initialize time stamp for stats reset
	*/
	port->stats_reset_time = ktime_get_seconds();

	if (port->stats_cbfn) {
		port->stats_cbfn(port->stats_cbarg, status);
		port->stats_cbfn = NULL;
	}
}

__attribute__((used)) static void
bfa_port_isr(void *cbarg, struct bfi_mbmsg_s *m)
{
	struct bfa_port_s *port = (struct bfa_port_s *) cbarg;
	union bfi_port_i2h_msg_u *i2hmsg;

	i2hmsg = (union bfi_port_i2h_msg_u *) m;
	bfa_trc(port, m->mh.msg_id);

	switch (m->mh.msg_id) {
	case BFI_PORT_I2H_ENABLE_RSP:
		if (port->endis_pending == BFA_FALSE)
			break;
		bfa_port_enable_isr(port, i2hmsg->enable_rsp.status);
		break;

	case BFI_PORT_I2H_DISABLE_RSP:
		if (port->endis_pending == BFA_FALSE)
			break;
		bfa_port_disable_isr(port, i2hmsg->disable_rsp.status);
		break;

	case BFI_PORT_I2H_GET_STATS_RSP:
		/* Stats busy flag is still set? (may be cmd timed out) */
		if (port->stats_busy == BFA_FALSE)
			break;
		bfa_port_get_stats_isr(port, i2hmsg->getstats_rsp.status);
		break;

	case BFI_PORT_I2H_CLEAR_STATS_RSP:
		if (port->stats_busy == BFA_FALSE)
			break;
		bfa_port_clear_stats_isr(port, i2hmsg->clearstats_rsp.status);
		break;

	default:
		WARN_ON(1);
	}
}

u32
bfa_port_meminfo(void)
{
	return BFA_ROUNDUP(sizeof(union bfa_port_stats_u), BFA_DMA_ALIGN_SZ);
}

void
bfa_port_mem_claim(struct bfa_port_s *port, u8 *dma_kva, u64 dma_pa)
{
	port->stats_dma.kva = dma_kva;
	port->stats_dma.pa  = dma_pa;
}

void
bfa_port_notify(void *arg, enum bfa_ioc_event_e event)
{
	struct bfa_port_s *port = (struct bfa_port_s *) arg;

	switch (event) {
	case BFA_IOC_E_DISABLED:
	case BFA_IOC_E_FAILED:
		/* Fail any pending get_stats/clear_stats requests */
		if (port->stats_busy) {
			if (port->stats_cbfn)
				port->stats_cbfn(port->stats_cbarg,
						BFA_STATUS_FAILED);
			port->stats_cbfn = NULL;
			port->stats_busy = BFA_FALSE;
		}

		/* Clear any enable/disable is pending */
		if (port->endis_pending) {
			if (port->endis_cbfn)
				port->endis_cbfn(port->endis_cbarg,
						BFA_STATUS_FAILED);
			port->endis_cbfn = NULL;
			port->endis_pending = BFA_FALSE;
		}

		/* clear D-port mode */
		if (port->dport_enabled)
			bfa_port_set_dportenabled(port, BFA_FALSE);
		break;
	default:
		break;
	}
}

void
bfa_port_attach(struct bfa_port_s *port, struct bfa_ioc_s *ioc,
		 void *dev, struct bfa_trc_mod_s *trcmod)
{
	WARN_ON(!port);

	port->dev    = dev;
	port->ioc    = ioc;
	port->trcmod = trcmod;

	port->stats_busy = BFA_FALSE;
	port->endis_pending = BFA_FALSE;
	port->stats_cbfn = NULL;
	port->endis_cbfn = NULL;
	port->pbc_disabled = BFA_FALSE;
	port->dport_enabled = BFA_FALSE;

	bfa_ioc_mbox_regisr(port->ioc, BFI_MC_PORT, bfa_port_isr, port);
	bfa_q_qe_init(&port->ioc_notify);
	bfa_ioc_notify_init(&port->ioc_notify, bfa_port_notify, port);
	list_add_tail(&port->ioc_notify.qe, &port->ioc->notify_q);

	/*
	 * initialize time stamp for stats reset
	 */
	port->stats_reset_time = ktime_get_seconds();

	bfa_trc(port, 0);
}

void
bfa_port_set_dportenabled(struct bfa_port_s *port, bfa_boolean_t enabled)
{
	port->dport_enabled = enabled;
}

__attribute__((used)) static void
bfa_cee_get_attr_isr(struct bfa_cee_s *cee, bfa_status_t status)
{
	struct bfa_cee_lldp_cfg_s *lldp_cfg = &cee->attr->lldp_remote;

	cee->get_attr_status = status;
	bfa_trc(cee, 0);
	if (status == BFA_STATUS_OK) {
		bfa_trc(cee, 0);
		memcpy(cee->attr, cee->attr_dma.kva,
			sizeof(struct bfa_cee_attr_s));
		lldp_cfg->time_to_live = be16_to_cpu(lldp_cfg->time_to_live);
		lldp_cfg->enabled_system_cap =
				be16_to_cpu(lldp_cfg->enabled_system_cap);
	}
	cee->get_attr_pending = BFA_FALSE;
	if (cee->cbfn.get_attr_cbfn) {
		bfa_trc(cee, 0);
		cee->cbfn.get_attr_cbfn(cee->cbfn.get_attr_cbarg, status);
	}
}

__attribute__((used)) static void
bfa_cee_get_stats_isr(struct bfa_cee_s *cee, bfa_status_t status)
{
	u32 *buffer;
	int i;

	cee->get_stats_status = status;
	bfa_trc(cee, 0);
	if (status == BFA_STATUS_OK) {
		bfa_trc(cee, 0);
		memcpy(cee->stats, cee->stats_dma.kva,
			sizeof(struct bfa_cee_stats_s));
		/* swap the cee stats */
		buffer = (u32 *)cee->stats;
		for (i = 0; i < (sizeof(struct bfa_cee_stats_s) /
				 sizeof(u32)); i++)
			buffer[i] = cpu_to_be32(buffer[i]);
	}
	cee->get_stats_pending = BFA_FALSE;
	bfa_trc(cee, 0);
	if (cee->cbfn.get_stats_cbfn) {
		bfa_trc(cee, 0);
		cee->cbfn.get_stats_cbfn(cee->cbfn.get_stats_cbarg, status);
	}
}

__attribute__((used)) static void
bfa_cee_reset_stats_isr(struct bfa_cee_s *cee, bfa_status_t status)
{
	cee->reset_stats_status = status;
	cee->reset_stats_pending = BFA_FALSE;
	if (cee->cbfn.reset_stats_cbfn)
		cee->cbfn.reset_stats_cbfn(cee->cbfn.reset_stats_cbarg, status);
}

u32
bfa_cee_meminfo(void)
{
	return BFA_ROUNDUP(sizeof(struct bfa_cee_attr_s), BFA_DMA_ALIGN_SZ) +
		BFA_ROUNDUP(sizeof(struct bfa_cee_stats_s), BFA_DMA_ALIGN_SZ);
}

void
bfa_cee_mem_claim(struct bfa_cee_s *cee, u8 *dma_kva, u64 dma_pa)
{
	cee->attr_dma.kva = dma_kva;
	cee->attr_dma.pa = dma_pa;
	cee->stats_dma.kva = dma_kva + BFA_ROUNDUP(
			     sizeof(struct bfa_cee_attr_s), BFA_DMA_ALIGN_SZ);
	cee->stats_dma.pa = dma_pa + BFA_ROUNDUP(
			     sizeof(struct bfa_cee_attr_s), BFA_DMA_ALIGN_SZ);
	cee->attr = (struct bfa_cee_attr_s *) dma_kva;
	cee->stats = (struct bfa_cee_stats_s *) (dma_kva + BFA_ROUNDUP(
			sizeof(struct bfa_cee_attr_s), BFA_DMA_ALIGN_SZ));
}

void
bfa_cee_isr(void *cbarg, struct bfi_mbmsg_s *m)
{
	union bfi_cee_i2h_msg_u *msg;
	struct bfi_cee_get_rsp_s *get_rsp;
	struct bfa_cee_s *cee = (struct bfa_cee_s *) cbarg;
	msg = (union bfi_cee_i2h_msg_u *) m;
	get_rsp = (struct bfi_cee_get_rsp_s *) m;
	bfa_trc(cee, msg->mh.msg_id);
	switch (msg->mh.msg_id) {
	case BFI_CEE_I2H_GET_CFG_RSP:
		bfa_trc(cee, get_rsp->cmd_status);
		bfa_cee_get_attr_isr(cee, get_rsp->cmd_status);
		break;
	case BFI_CEE_I2H_GET_STATS_RSP:
		bfa_cee_get_stats_isr(cee, get_rsp->cmd_status);
		break;
	case BFI_CEE_I2H_RESET_STATS_RSP:
		bfa_cee_reset_stats_isr(cee, get_rsp->cmd_status);
		break;
	default:
		WARN_ON(1);
	}
}

void
bfa_cee_notify(void *arg, enum bfa_ioc_event_e event)
{
	struct bfa_cee_s *cee = (struct bfa_cee_s *) arg;

	bfa_trc(cee, event);

	switch (event) {
	case BFA_IOC_E_DISABLED:
	case BFA_IOC_E_FAILED:
		if (cee->get_attr_pending == BFA_TRUE) {
			cee->get_attr_status = BFA_STATUS_FAILED;
			cee->get_attr_pending  = BFA_FALSE;
			if (cee->cbfn.get_attr_cbfn) {
				cee->cbfn.get_attr_cbfn(
					cee->cbfn.get_attr_cbarg,
					BFA_STATUS_FAILED);
			}
		}
		if (cee->get_stats_pending == BFA_TRUE) {
			cee->get_stats_status = BFA_STATUS_FAILED;
			cee->get_stats_pending  = BFA_FALSE;
			if (cee->cbfn.get_stats_cbfn) {
				cee->cbfn.get_stats_cbfn(
				cee->cbfn.get_stats_cbarg,
				BFA_STATUS_FAILED);
			}
		}
		if (cee->reset_stats_pending == BFA_TRUE) {
			cee->reset_stats_status = BFA_STATUS_FAILED;
			cee->reset_stats_pending  = BFA_FALSE;
			if (cee->cbfn.reset_stats_cbfn) {
				cee->cbfn.reset_stats_cbfn(
				cee->cbfn.reset_stats_cbarg,
				BFA_STATUS_FAILED);
			}
		}
		break;

	default:
		break;
	}
}

void
bfa_cee_attach(struct bfa_cee_s *cee, struct bfa_ioc_s *ioc,
		void *dev)
{
	WARN_ON(cee == NULL);
	cee->dev = dev;
	cee->ioc = ioc;

	bfa_ioc_mbox_regisr(cee->ioc, BFI_MC_CEE, bfa_cee_isr, cee);
	bfa_q_qe_init(&cee->ioc_notify);
	bfa_ioc_notify_init(&cee->ioc_notify, bfa_cee_notify, cee);
	list_add_tail(&cee->ioc_notify.qe, &cee->ioc->notify_q);
}

