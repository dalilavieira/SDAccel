#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_77__   TYPE_9__ ;
typedef  struct TYPE_76__   TYPE_8__ ;
typedef  struct TYPE_75__   TYPE_7__ ;
typedef  struct TYPE_74__   TYPE_6__ ;
typedef  struct TYPE_73__   TYPE_5__ ;
typedef  struct TYPE_72__   TYPE_4__ ;
typedef  struct TYPE_71__   TYPE_3__ ;
typedef  struct TYPE_70__   TYPE_2__ ;
typedef  struct TYPE_69__   TYPE_22__ ;
typedef  struct TYPE_68__   TYPE_21__ ;
typedef  struct TYPE_67__   TYPE_20__ ;
typedef  struct TYPE_66__   TYPE_1__ ;
typedef  struct TYPE_65__   TYPE_19__ ;
typedef  struct TYPE_64__   TYPE_18__ ;
typedef  struct TYPE_63__   TYPE_17__ ;
typedef  struct TYPE_62__   TYPE_16__ ;
typedef  struct TYPE_61__   TYPE_15__ ;
typedef  struct TYPE_60__   TYPE_14__ ;
typedef  struct TYPE_59__   TYPE_13__ ;
typedef  struct TYPE_58__   TYPE_12__ ;
typedef  struct TYPE_57__   TYPE_11__ ;
typedef  struct TYPE_56__   TYPE_10__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct dwc_otg_hcd_pipe_info {int ep_num; int pipe_type; int mps; int dev_addr; scalar_t__ pipe_dir; } ;
struct dwc_otg_hcd {TYPE_14__* otg_dev; } ;
struct device {int dummy; } ;
struct TYPE_66__ {scalar_t__ prtovrcurrchng; scalar_t__ prtenchng; scalar_t__ prtconndet; scalar_t__ prtena; } ;
struct TYPE_61__ {int d32; TYPE_1__ b; } ;
typedef  TYPE_15__ hprt0_data_t ;
typedef  int /*<<< orphan*/  dwc_otg_qtd_t ;
struct TYPE_62__ {int /*<<< orphan*/  qtd_list; } ;
typedef  TYPE_16__ dwc_otg_qh_t ;
struct TYPE_63__ {int /*<<< orphan*/  lock; } ;
typedef  TYPE_17__ dwc_otg_hcd_t ;
struct TYPE_64__ {TYPE_5__** out_ep_regs; TYPE_3__* dev_global_regs; TYPE_2__** in_ep_regs; } ;
typedef  TYPE_18__ dwc_otg_dev_if_t ;
struct TYPE_65__ {TYPE_11__* pcd_cb; TYPE_10__* hcd_cb; TYPE_9__* core_global_regs; TYPE_8__* host_if; scalar_t__ pti_enh_enable; scalar_t__ multiproc_int_enable; TYPE_18__* dev_if; } ;
typedef  TYPE_19__ dwc_otg_core_if_t ;
typedef  int /*<<< orphan*/  dwc_irqflags_t ;
struct TYPE_67__ {size_t hc_num; } ;
typedef  TYPE_20__ dwc_hc_t ;
struct TYPE_68__ {size_t num; } ;
typedef  TYPE_21__ dwc_ep_t ;
struct TYPE_72__ {int pktdrpsts; } ;
struct TYPE_69__ {int d32; TYPE_4__ b; } ;
typedef  TYPE_22__ doepmsk_data_t ;
struct TYPE_77__ {int /*<<< orphan*/  gintsts; int /*<<< orphan*/  gotgint; int /*<<< orphan*/  gintmsk; } ;
struct TYPE_76__ {TYPE_7__** hc_regs; TYPE_6__* host_global_regs; int /*<<< orphan*/ * hprt0; } ;
struct TYPE_75__ {int /*<<< orphan*/  hcint; } ;
struct TYPE_74__ {int /*<<< orphan*/  haint; } ;
struct TYPE_73__ {int /*<<< orphan*/  doepint; } ;
struct TYPE_71__ {int /*<<< orphan*/  doepmsk; int /*<<< orphan*/ * doepeachintmsk; int /*<<< orphan*/  dtknqr4_fifoemptymsk; int /*<<< orphan*/  diepmsk; int /*<<< orphan*/ * diepeachintmsk; int /*<<< orphan*/  daintmsk; int /*<<< orphan*/  daint; int /*<<< orphan*/  deachintmsk; int /*<<< orphan*/  deachint; } ;
struct TYPE_70__ {int /*<<< orphan*/  diepint; } ;
struct TYPE_59__ {TYPE_12__* platformdev; } ;
struct TYPE_60__ {TYPE_13__ os_dep; } ;
struct TYPE_58__ {struct device dev; } ;
struct TYPE_57__ {int /*<<< orphan*/  p; int /*<<< orphan*/  (* resume_wakeup ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* suspend ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* stop ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* start ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_56__ {int /*<<< orphan*/  p; int /*<<< orphan*/  (* resume_wakeup ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* session_start ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* disconnect ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* stop ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* start ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 scalar_t__ DWC_ALLOC (int) ; 
 scalar_t__ DWC_ALLOC_ATOMIC (int) ; 
 int /*<<< orphan*/  DWC_CIRCLEQ_REMOVE (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DWC_FREE (int /*<<< orphan*/ *) ; 
 int DWC_HFNUM_MAX_FRNUM ; 
 int DWC_READ_REG32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DWC_SPINLOCK_IRQSAVE (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DWC_SPINUNLOCK_IRQRESTORE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ UE_BULK ; 
 scalar_t__ UE_CONTROL ; 
 scalar_t__ UE_DIR_IN ; 
 scalar_t__ UE_INTERRUPT ; 
 scalar_t__ UE_ISOCHRONOUS ; 
 int /*<<< orphan*/  dwc_otg_hcd_qh_free (TYPE_17__*,TYPE_16__*) ; 
 int /*<<< orphan*/  dwc_otg_hcd_qh_remove (TYPE_17__*,TYPE_16__*) ; 
 int g_dbg_lvl ; 
 int /*<<< orphan*/  qtd_list_entry ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t SET_DEBUG_LEVEL(const uint32_t new)
{
	uint32_t old = g_dbg_lvl;
	g_dbg_lvl = new;
	return old;
}

__attribute__((used)) static inline uint32_t dwc_otg_read_hprt0(dwc_otg_core_if_t * _core_if)
{
	hprt0_data_t hprt0;
	hprt0.d32 = DWC_READ_REG32(_core_if->host_if->hprt0);
	hprt0.b.prtena = 0;
	hprt0.b.prtconndet = 0;
	hprt0.b.prtenchng = 0;
	hprt0.b.prtovrcurrchng = 0;
	return hprt0.d32;
}

__attribute__((used)) static inline uint32_t dwc_otg_read_core_intr(dwc_otg_core_if_t * core_if)
{
	return (DWC_READ_REG32(&core_if->core_global_regs->gintsts) &
		DWC_READ_REG32(&core_if->core_global_regs->gintmsk));
}

__attribute__((used)) static inline uint32_t dwc_otg_read_otg_intr(dwc_otg_core_if_t * core_if)
{
	return (DWC_READ_REG32(&core_if->core_global_regs->gotgint));
}

__attribute__((used)) static inline uint32_t dwc_otg_read_dev_all_in_ep_intr(dwc_otg_core_if_t *
						       core_if)
{

	uint32_t v;

	if (core_if->multiproc_int_enable) {
		v = DWC_READ_REG32(&core_if->dev_if->
				   dev_global_regs->deachint) &
		    DWC_READ_REG32(&core_if->
				   dev_if->dev_global_regs->deachintmsk);
	} else {
		v = DWC_READ_REG32(&core_if->dev_if->dev_global_regs->daint) &
		    DWC_READ_REG32(&core_if->dev_if->dev_global_regs->daintmsk);
	}
	return (v & 0xffff);
}

__attribute__((used)) static inline uint32_t dwc_otg_read_dev_all_out_ep_intr(dwc_otg_core_if_t *
							core_if)
{
	uint32_t v;

	if (core_if->multiproc_int_enable) {
		v = DWC_READ_REG32(&core_if->dev_if->
				   dev_global_regs->deachint) &
		    DWC_READ_REG32(&core_if->
				   dev_if->dev_global_regs->deachintmsk);
	} else {
		v = DWC_READ_REG32(&core_if->dev_if->dev_global_regs->daint) &
		    DWC_READ_REG32(&core_if->dev_if->dev_global_regs->daintmsk);
	}

	return ((v & 0xffff0000) >> 16);
}

__attribute__((used)) static inline uint32_t dwc_otg_read_dev_in_ep_intr(dwc_otg_core_if_t * core_if,
						   dwc_ep_t * ep)
{
	dwc_otg_dev_if_t *dev_if = core_if->dev_if;
	uint32_t v, msk, emp;

	if (core_if->multiproc_int_enable) {
		msk =
		    DWC_READ_REG32(&dev_if->
				   dev_global_regs->diepeachintmsk[ep->num]);
		emp =
		    DWC_READ_REG32(&dev_if->
				   dev_global_regs->dtknqr4_fifoemptymsk);
		msk |= ((emp >> ep->num) & 0x1) << 7;
		v = DWC_READ_REG32(&dev_if->in_ep_regs[ep->num]->diepint) & msk;
	} else {
		msk = DWC_READ_REG32(&dev_if->dev_global_regs->diepmsk);
		emp =
		    DWC_READ_REG32(&dev_if->
				   dev_global_regs->dtknqr4_fifoemptymsk);
		msk |= ((emp >> ep->num) & 0x1) << 7;
		v = DWC_READ_REG32(&dev_if->in_ep_regs[ep->num]->diepint) & msk;
	}

	return v;
}

__attribute__((used)) static inline uint32_t dwc_otg_read_dev_out_ep_intr(dwc_otg_core_if_t *
						    _core_if, dwc_ep_t * _ep)
{
	dwc_otg_dev_if_t *dev_if = _core_if->dev_if;
	uint32_t v;
	doepmsk_data_t msk = {.d32 = 0 };

	if (_core_if->multiproc_int_enable) {
		msk.d32 =
		    DWC_READ_REG32(&dev_if->
				   dev_global_regs->doepeachintmsk[_ep->num]);
		if (_core_if->pti_enh_enable) {
			msk.b.pktdrpsts = 1;
		}
		v = DWC_READ_REG32(&dev_if->
				   out_ep_regs[_ep->num]->doepint) & msk.d32;
	} else {
		msk.d32 = DWC_READ_REG32(&dev_if->dev_global_regs->doepmsk);
		if (_core_if->pti_enh_enable) {
			msk.b.pktdrpsts = 1;
		}
		v = DWC_READ_REG32(&dev_if->
				   out_ep_regs[_ep->num]->doepint) & msk.d32;
	}
	return v;
}

__attribute__((used)) static inline uint32_t dwc_otg_read_host_all_channels_intr(dwc_otg_core_if_t *
							   _core_if)
{
	return (DWC_READ_REG32(&_core_if->host_if->host_global_regs->haint));
}

__attribute__((used)) static inline uint32_t dwc_otg_read_host_channel_intr(dwc_otg_core_if_t *
						      _core_if, dwc_hc_t * _hc)
{
	return (DWC_READ_REG32
		(&_core_if->host_if->hc_regs[_hc->hc_num]->hcint));
}

__attribute__((used)) static inline uint32_t dwc_otg_mode(dwc_otg_core_if_t * _core_if)
{
	return (DWC_READ_REG32(&_core_if->core_global_regs->gintsts) & 0x1);
}

__attribute__((used)) static inline void cil_hcd_start(dwc_otg_core_if_t * core_if)
{
	if (core_if->hcd_cb && core_if->hcd_cb->start) {
		core_if->hcd_cb->start(core_if->hcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_hcd_stop(dwc_otg_core_if_t * core_if)
{
	if (core_if->hcd_cb && core_if->hcd_cb->stop) {
		core_if->hcd_cb->stop(core_if->hcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_hcd_disconnect(dwc_otg_core_if_t * core_if)
{
	if (core_if->hcd_cb && core_if->hcd_cb->disconnect) {
		core_if->hcd_cb->disconnect(core_if->hcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_hcd_session_start(dwc_otg_core_if_t * core_if)
{
	if (core_if->hcd_cb && core_if->hcd_cb->session_start) {
		core_if->hcd_cb->session_start(core_if->hcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_hcd_resume(dwc_otg_core_if_t * core_if)
{
	if (core_if->hcd_cb && core_if->hcd_cb->resume_wakeup) {
		core_if->hcd_cb->resume_wakeup(core_if->hcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_pcd_start(dwc_otg_core_if_t * core_if)
{
	if (core_if->pcd_cb && core_if->pcd_cb->start) {
		core_if->pcd_cb->start(core_if->pcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_pcd_stop(dwc_otg_core_if_t * core_if)
{
	if (core_if->pcd_cb && core_if->pcd_cb->stop) {
		core_if->pcd_cb->stop(core_if->pcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_pcd_suspend(dwc_otg_core_if_t * core_if)
{
	if (core_if->pcd_cb && core_if->pcd_cb->suspend) {
		core_if->pcd_cb->suspend(core_if->pcd_cb->p);
	}
}

__attribute__((used)) static inline void cil_pcd_resume(dwc_otg_core_if_t * core_if)
{
	if (core_if->pcd_cb && core_if->pcd_cb->resume_wakeup) {
		core_if->pcd_cb->resume_wakeup(core_if->pcd_cb->p);
	}
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_get_ep_num(struct dwc_otg_hcd_pipe_info *pipe)
{
	return pipe->ep_num;
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_get_pipe_type(struct dwc_otg_hcd_pipe_info
						*pipe)
{
	return pipe->pipe_type;
}

__attribute__((used)) static inline uint16_t dwc_otg_hcd_get_mps(struct dwc_otg_hcd_pipe_info *pipe)
{
	return pipe->mps;
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_get_dev_addr(struct dwc_otg_hcd_pipe_info
					       *pipe)
{
	return pipe->dev_addr;
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_isoc(struct dwc_otg_hcd_pipe_info
					       *pipe)
{
	return (pipe->pipe_type == UE_ISOCHRONOUS);
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_int(struct dwc_otg_hcd_pipe_info
					      *pipe)
{
	return (pipe->pipe_type == UE_INTERRUPT);
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_bulk(struct dwc_otg_hcd_pipe_info
					       *pipe)
{
	return (pipe->pipe_type == UE_BULK);
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_control(struct dwc_otg_hcd_pipe_info
						  *pipe)
{
	return (pipe->pipe_type == UE_CONTROL);
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_in(struct dwc_otg_hcd_pipe_info *pipe)
{
	return (pipe->pipe_dir == UE_DIR_IN);
}

__attribute__((used)) static inline uint8_t dwc_otg_hcd_is_pipe_out(struct dwc_otg_hcd_pipe_info
					      *pipe)
{
	return (!dwc_otg_hcd_is_pipe_in(pipe));
}

__attribute__((used)) static inline void dwc_otg_hcd_fill_pipe(struct dwc_otg_hcd_pipe_info *pipe,
					 uint8_t devaddr, uint8_t ep_num,
					 uint8_t pipe_type, uint8_t pipe_dir,
					 uint16_t mps)
{
	pipe->dev_addr = devaddr;
	pipe->ep_num = ep_num;
	pipe->pipe_type = pipe_type;
	pipe->pipe_dir = pipe_dir;
	pipe->mps = mps;
}

__attribute__((used)) static inline struct device *dwc_otg_hcd_to_dev(struct dwc_otg_hcd *hcd)
{
	return &hcd->otg_dev->os_dep.platformdev->dev;
}

__attribute__((used)) static inline void dwc_otg_hcd_qh_remove_and_free(dwc_otg_hcd_t * hcd,
						  dwc_otg_qh_t * qh)
{
	dwc_irqflags_t flags;
	DWC_SPINLOCK_IRQSAVE(hcd->lock, &flags);
	dwc_otg_hcd_qh_remove(hcd, qh);
	DWC_SPINUNLOCK_IRQRESTORE(hcd->lock, flags);
	dwc_otg_hcd_qh_free(hcd, qh);
}

__attribute__((used)) static inline dwc_otg_qh_t *dwc_otg_hcd_qh_alloc(int atomic_alloc)
{
	if (atomic_alloc)
		return (dwc_otg_qh_t *) DWC_ALLOC_ATOMIC(sizeof(dwc_otg_qh_t));
	else
		return (dwc_otg_qh_t *) DWC_ALLOC(sizeof(dwc_otg_qh_t));
}

__attribute__((used)) static inline dwc_otg_qtd_t *dwc_otg_hcd_qtd_alloc(int atomic_alloc)
{
	if (atomic_alloc)
		return (dwc_otg_qtd_t *) DWC_ALLOC_ATOMIC(sizeof(dwc_otg_qtd_t));
	else
		return (dwc_otg_qtd_t *) DWC_ALLOC(sizeof(dwc_otg_qtd_t));
}

__attribute__((used)) static inline void dwc_otg_hcd_qtd_free(dwc_otg_qtd_t * qtd)
{
	DWC_FREE(qtd);
}

__attribute__((used)) static inline void dwc_otg_hcd_qtd_remove(dwc_otg_hcd_t * hcd,
					  dwc_otg_qtd_t * qtd,
					  dwc_otg_qh_t * qh)
{
	DWC_CIRCLEQ_REMOVE(&qh->qtd_list, qtd, qtd_list_entry);
}

__attribute__((used)) static inline void dwc_otg_hcd_qtd_remove_and_free(dwc_otg_hcd_t * hcd,
						   dwc_otg_qtd_t * qtd,
						   dwc_otg_qh_t * qh)
{
	dwc_otg_hcd_qtd_remove(hcd, qtd, qh);
	dwc_otg_hcd_qtd_free(qtd);
}

__attribute__((used)) static inline int dwc_frame_num_le(uint16_t frame1, uint16_t frame2)
{
	return ((frame2 - frame1) & DWC_HFNUM_MAX_FRNUM) <=
	    (DWC_HFNUM_MAX_FRNUM >> 1);
}

__attribute__((used)) static inline int dwc_frame_num_gt(uint16_t frame1, uint16_t frame2)
{
	return (frame1 != frame2) &&
	    (((frame1 - frame2) & DWC_HFNUM_MAX_FRNUM) <
	     (DWC_HFNUM_MAX_FRNUM >> 1));
}

__attribute__((used)) static inline uint16_t dwc_frame_num_inc(uint16_t frame, uint16_t inc)
{
	return (frame + inc) & DWC_HFNUM_MAX_FRNUM;
}

__attribute__((used)) static inline uint16_t dwc_full_frame_num(uint16_t frame)
{
	return (frame & DWC_HFNUM_MAX_FRNUM) >> 3;
}

__attribute__((used)) static inline uint16_t dwc_micro_frame_num(uint16_t frame)
{
	return frame & 0x7;
}

