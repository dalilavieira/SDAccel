#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct TYPE_6__ {scalar_t__ puint_mb_R; int spu_cfg_RW; int /*<<< orphan*/  mfc_control_RW; scalar_t__ spu_privcntl_RW; } ;
struct spu_problem_collapsed {scalar_t__ mb_stat_R; scalar_t__ pu_mb_R; scalar_t__ spu_npc_RW; scalar_t__ spu_status_R; scalar_t__ spu_runcntl_RW; scalar_t__ dma_tagstatus_R; scalar_t__ dma_qstatus_R; scalar_t__ dma_querytype_RW; scalar_t__ dma_querymask_RW; } ;
struct TYPE_5__ {scalar_t__ mfc_sr1_RW; int /*<<< orphan*/  int_mask_class2_RW; int /*<<< orphan*/  int_stat_class2_RW; } ;
struct spu_state {scalar_t__* spu_chnlcnt_RW; scalar_t__* spu_chnldata_RW; TYPE_3__ priv2; int /*<<< orphan*/  register_lock; struct spu_problem_collapsed prob; TYPE_2__ priv1; TYPE_1__* lscsa; scalar_t__* spu_mailbox_data; } ;
struct spu_context {struct spu_state csa; } ;
struct mfc_dma_command {int dummy; } ;
typedef  int __poll_t ;
struct TYPE_4__ {char* ls; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CLASS2_ENABLE_MAILBOX_INTR ; 
 int /*<<< orphan*/  CLASS2_ENABLE_MAILBOX_THRESHOLD_INTR ; 
 int /*<<< orphan*/  CLASS2_MAILBOX_INTR ; 
 int /*<<< orphan*/  CLASS2_MAILBOX_THRESHOLD_INTR ; 
 int EAGAIN ; 
 int EPOLLIN ; 
 int EPOLLOUT ; 
 int EPOLLRDNORM ; 
 int EPOLLWRNORM ; 
 int /*<<< orphan*/  MFC_CNTL_RESTART_DMA_COMMAND ; 
 scalar_t__ MFC_PU_INT_MAILBOX_AVAILABLE_EVENT ; 
 scalar_t__ MFC_PU_MAILBOX_AVAILABLE_EVENT ; 
 scalar_t__ MFC_SIGNAL_1_EVENT ; 
 scalar_t__ MFC_SIGNAL_2_EVENT ; 
 scalar_t__ MFC_SPU_MAILBOX_WRITTEN_EVENT ; 
 scalar_t__ MFC_STATE1_MASTER_RUN_CONTROL_MASK ; 
 scalar_t__ SPU_RUNCNTL_RUNNABLE ; 
 scalar_t__ SPU_RUNCNTL_STOP ; 
 int SPU_STATUS_INVALID_CH ; 
 int SPU_STATUS_INVALID_INSTR ; 
 int SPU_STATUS_RUNNING ; 
 int SPU_STATUS_SINGLE_STEP ; 
 int SPU_STATUS_STOPPED_BY_HALT ; 
 int SPU_STATUS_STOPPED_BY_STOP ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gen_spu_event(struct spu_context *ctx, u32 event)
{
	u64 ch0_cnt;
	u64 ch0_data;
	u64 ch1_data;

	ch0_cnt = ctx->csa.spu_chnlcnt_RW[0];
	ch0_data = ctx->csa.spu_chnldata_RW[0];
	ch1_data = ctx->csa.spu_chnldata_RW[1];
	ctx->csa.spu_chnldata_RW[0] |= event;
	if ((ch0_cnt == 0) && !(ch0_data & event) && (ch1_data & event)) {
		ctx->csa.spu_chnlcnt_RW[0] = 1;
	}
}

__attribute__((used)) static int spu_backing_mbox_read(struct spu_context *ctx, u32 * data)
{
	u32 mbox_stat;
	int ret = 0;

	spin_lock(&ctx->csa.register_lock);
	mbox_stat = ctx->csa.prob.mb_stat_R;
	if (mbox_stat & 0x0000ff) {
		/* Read the first available word.
		 * Implementation note: the depth
		 * of pu_mb_R is currently 1.
		 */
		*data = ctx->csa.prob.pu_mb_R;
		ctx->csa.prob.mb_stat_R &= ~(0x0000ff);
		ctx->csa.spu_chnlcnt_RW[28] = 1;
		gen_spu_event(ctx, MFC_PU_MAILBOX_AVAILABLE_EVENT);
		ret = 4;
	}
	spin_unlock(&ctx->csa.register_lock);
	return ret;
}

__attribute__((used)) static u32 spu_backing_mbox_stat_read(struct spu_context *ctx)
{
	return ctx->csa.prob.mb_stat_R;
}

__attribute__((used)) static __poll_t spu_backing_mbox_stat_poll(struct spu_context *ctx,
					  __poll_t events)
{
	__poll_t ret;
	u32 stat;

	ret = 0;
	spin_lock_irq(&ctx->csa.register_lock);
	stat = ctx->csa.prob.mb_stat_R;

	/* if the requested event is there, return the poll
	   mask, otherwise enable the interrupt to get notified,
	   but first mark any pending interrupts as done so
	   we don't get woken up unnecessarily */

	if (events & (EPOLLIN | EPOLLRDNORM)) {
		if (stat & 0xff0000)
			ret |= EPOLLIN | EPOLLRDNORM;
		else {
			ctx->csa.priv1.int_stat_class2_RW &=
				~CLASS2_MAILBOX_INTR;
			ctx->csa.priv1.int_mask_class2_RW |=
				CLASS2_ENABLE_MAILBOX_INTR;
		}
	}
	if (events & (EPOLLOUT | EPOLLWRNORM)) {
		if (stat & 0x00ff00)
			ret = EPOLLOUT | EPOLLWRNORM;
		else {
			ctx->csa.priv1.int_stat_class2_RW &=
				~CLASS2_MAILBOX_THRESHOLD_INTR;
			ctx->csa.priv1.int_mask_class2_RW |=
				CLASS2_ENABLE_MAILBOX_THRESHOLD_INTR;
		}
	}
	spin_unlock_irq(&ctx->csa.register_lock);
	return ret;
}

__attribute__((used)) static int spu_backing_ibox_read(struct spu_context *ctx, u32 * data)
{
	int ret;

	spin_lock(&ctx->csa.register_lock);
	if (ctx->csa.prob.mb_stat_R & 0xff0000) {
		/* Read the first available word.
		 * Implementation note: the depth
		 * of puint_mb_R is currently 1.
		 */
		*data = ctx->csa.priv2.puint_mb_R;
		ctx->csa.prob.mb_stat_R &= ~(0xff0000);
		ctx->csa.spu_chnlcnt_RW[30] = 1;
		gen_spu_event(ctx, MFC_PU_INT_MAILBOX_AVAILABLE_EVENT);
		ret = 4;
	} else {
		/* make sure we get woken up by the interrupt */
		ctx->csa.priv1.int_mask_class2_RW |= CLASS2_ENABLE_MAILBOX_INTR;
		ret = 0;
	}
	spin_unlock(&ctx->csa.register_lock);
	return ret;
}

__attribute__((used)) static int spu_backing_wbox_write(struct spu_context *ctx, u32 data)
{
	int ret;

	spin_lock(&ctx->csa.register_lock);
	if ((ctx->csa.prob.mb_stat_R) & 0x00ff00) {
		int slot = ctx->csa.spu_chnlcnt_RW[29];
		int avail = (ctx->csa.prob.mb_stat_R & 0x00ff00) >> 8;

		/* We have space to write wbox_data.
		 * Implementation note: the depth
		 * of spu_mb_W is currently 4.
		 */
		BUG_ON(avail != (4 - slot));
		ctx->csa.spu_mailbox_data[slot] = data;
		ctx->csa.spu_chnlcnt_RW[29] = ++slot;
		ctx->csa.prob.mb_stat_R &= ~(0x00ff00);
		ctx->csa.prob.mb_stat_R |= (((4 - slot) & 0xff) << 8);
		gen_spu_event(ctx, MFC_SPU_MAILBOX_WRITTEN_EVENT);
		ret = 4;
	} else {
		/* make sure we get woken up by the interrupt when space
		   becomes available */
		ctx->csa.priv1.int_mask_class2_RW |=
			CLASS2_ENABLE_MAILBOX_THRESHOLD_INTR;
		ret = 0;
	}
	spin_unlock(&ctx->csa.register_lock);
	return ret;
}

__attribute__((used)) static u32 spu_backing_signal1_read(struct spu_context *ctx)
{
	return ctx->csa.spu_chnldata_RW[3];
}

__attribute__((used)) static void spu_backing_signal1_write(struct spu_context *ctx, u32 data)
{
	spin_lock(&ctx->csa.register_lock);
	if (ctx->csa.priv2.spu_cfg_RW & 0x1)
		ctx->csa.spu_chnldata_RW[3] |= data;
	else
		ctx->csa.spu_chnldata_RW[3] = data;
	ctx->csa.spu_chnlcnt_RW[3] = 1;
	gen_spu_event(ctx, MFC_SIGNAL_1_EVENT);
	spin_unlock(&ctx->csa.register_lock);
}

__attribute__((used)) static u32 spu_backing_signal2_read(struct spu_context *ctx)
{
	return ctx->csa.spu_chnldata_RW[4];
}

__attribute__((used)) static void spu_backing_signal2_write(struct spu_context *ctx, u32 data)
{
	spin_lock(&ctx->csa.register_lock);
	if (ctx->csa.priv2.spu_cfg_RW & 0x2)
		ctx->csa.spu_chnldata_RW[4] |= data;
	else
		ctx->csa.spu_chnldata_RW[4] = data;
	ctx->csa.spu_chnlcnt_RW[4] = 1;
	gen_spu_event(ctx, MFC_SIGNAL_2_EVENT);
	spin_unlock(&ctx->csa.register_lock);
}

__attribute__((used)) static void spu_backing_signal1_type_set(struct spu_context *ctx, u64 val)
{
	u64 tmp;

	spin_lock(&ctx->csa.register_lock);
	tmp = ctx->csa.priv2.spu_cfg_RW;
	if (val)
		tmp |= 1;
	else
		tmp &= ~1;
	ctx->csa.priv2.spu_cfg_RW = tmp;
	spin_unlock(&ctx->csa.register_lock);
}

__attribute__((used)) static u64 spu_backing_signal1_type_get(struct spu_context *ctx)
{
	return ((ctx->csa.priv2.spu_cfg_RW & 1) != 0);
}

__attribute__((used)) static void spu_backing_signal2_type_set(struct spu_context *ctx, u64 val)
{
	u64 tmp;

	spin_lock(&ctx->csa.register_lock);
	tmp = ctx->csa.priv2.spu_cfg_RW;
	if (val)
		tmp |= 2;
	else
		tmp &= ~2;
	ctx->csa.priv2.spu_cfg_RW = tmp;
	spin_unlock(&ctx->csa.register_lock);
}

__attribute__((used)) static u64 spu_backing_signal2_type_get(struct spu_context *ctx)
{
	return ((ctx->csa.priv2.spu_cfg_RW & 2) != 0);
}

__attribute__((used)) static u32 spu_backing_npc_read(struct spu_context *ctx)
{
	return ctx->csa.prob.spu_npc_RW;
}

__attribute__((used)) static void spu_backing_npc_write(struct spu_context *ctx, u32 val)
{
	ctx->csa.prob.spu_npc_RW = val;
}

__attribute__((used)) static u32 spu_backing_status_read(struct spu_context *ctx)
{
	return ctx->csa.prob.spu_status_R;
}

__attribute__((used)) static char *spu_backing_get_ls(struct spu_context *ctx)
{
	return ctx->csa.lscsa->ls;
}

__attribute__((used)) static void spu_backing_privcntl_write(struct spu_context *ctx, u64 val)
{
	ctx->csa.priv2.spu_privcntl_RW = val;
}

__attribute__((used)) static u32 spu_backing_runcntl_read(struct spu_context *ctx)
{
	return ctx->csa.prob.spu_runcntl_RW;
}

__attribute__((used)) static void spu_backing_runcntl_write(struct spu_context *ctx, u32 val)
{
	spin_lock(&ctx->csa.register_lock);
	ctx->csa.prob.spu_runcntl_RW = val;
	if (val & SPU_RUNCNTL_RUNNABLE) {
		ctx->csa.prob.spu_status_R &=
			~SPU_STATUS_STOPPED_BY_STOP &
			~SPU_STATUS_STOPPED_BY_HALT &
			~SPU_STATUS_SINGLE_STEP &
			~SPU_STATUS_INVALID_INSTR &
			~SPU_STATUS_INVALID_CH;
		ctx->csa.prob.spu_status_R |= SPU_STATUS_RUNNING;
	} else {
		ctx->csa.prob.spu_status_R &= ~SPU_STATUS_RUNNING;
	}
	spin_unlock(&ctx->csa.register_lock);
}

__attribute__((used)) static void spu_backing_runcntl_stop(struct spu_context *ctx)
{
	spu_backing_runcntl_write(ctx, SPU_RUNCNTL_STOP);
}

__attribute__((used)) static void spu_backing_master_start(struct spu_context *ctx)
{
	struct spu_state *csa = &ctx->csa;
	u64 sr1;

	spin_lock(&csa->register_lock);
	sr1 = csa->priv1.mfc_sr1_RW | MFC_STATE1_MASTER_RUN_CONTROL_MASK;
	csa->priv1.mfc_sr1_RW = sr1;
	spin_unlock(&csa->register_lock);
}

__attribute__((used)) static void spu_backing_master_stop(struct spu_context *ctx)
{
	struct spu_state *csa = &ctx->csa;
	u64 sr1;

	spin_lock(&csa->register_lock);
	sr1 = csa->priv1.mfc_sr1_RW & ~MFC_STATE1_MASTER_RUN_CONTROL_MASK;
	csa->priv1.mfc_sr1_RW = sr1;
	spin_unlock(&csa->register_lock);
}

__attribute__((used)) static int spu_backing_set_mfc_query(struct spu_context * ctx, u32 mask,
					u32 mode)
{
	struct spu_problem_collapsed *prob = &ctx->csa.prob;
	int ret;

	spin_lock(&ctx->csa.register_lock);
	ret = -EAGAIN;
	if (prob->dma_querytype_RW)
		goto out;
	ret = 0;
	/* FIXME: what are the side-effects of this? */
	prob->dma_querymask_RW = mask;
	prob->dma_querytype_RW = mode;
	/* In the current implementation, the SPU context is always
	 * acquired in runnable state when new bits are added to the
	 * mask (tagwait), so it's sufficient just to mask
	 * dma_tagstatus_R with the 'mask' parameter here.
	 */
	ctx->csa.prob.dma_tagstatus_R &= mask;
out:
	spin_unlock(&ctx->csa.register_lock);

	return ret;
}

__attribute__((used)) static u32 spu_backing_read_mfc_tagstatus(struct spu_context * ctx)
{
	return ctx->csa.prob.dma_tagstatus_R;
}

__attribute__((used)) static u32 spu_backing_get_mfc_free_elements(struct spu_context *ctx)
{
	return ctx->csa.prob.dma_qstatus_R;
}

__attribute__((used)) static int spu_backing_send_mfc_command(struct spu_context *ctx,
					struct mfc_dma_command *cmd)
{
	int ret;

	spin_lock(&ctx->csa.register_lock);
	ret = -EAGAIN;
	/* FIXME: set up priv2->puq */
	spin_unlock(&ctx->csa.register_lock);

	return ret;
}

__attribute__((used)) static void spu_backing_restart_dma(struct spu_context *ctx)
{
	ctx->csa.priv2.mfc_control_RW |= MFC_CNTL_RESTART_DMA_COMMAND;
}

