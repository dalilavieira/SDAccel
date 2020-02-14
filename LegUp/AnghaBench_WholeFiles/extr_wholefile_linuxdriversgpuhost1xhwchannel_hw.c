#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct push_buffer {int dummy; } ;
struct output {int dummy; } ;
struct host1x_waitlist {int dummy; } ;
struct host1x_syncpt {int client_managed; scalar_t__ id; TYPE_6__* base; int /*<<< orphan*/  host; int /*<<< orphan*/  max_val; int /*<<< orphan*/  min_val; } ;
struct host1x_job_gather {int base; int offset; struct host1x_bo* bo; int /*<<< orphan*/  words; } ;
struct host1x_job {unsigned int num_gathers; int syncpt_id; int syncpt_incrs; int syncpt_end; scalar_t__ class; scalar_t__ serialize; int /*<<< orphan*/  num_relocs; struct host1x_channel* channel; struct host1x_job_gather* gathers; } ;
struct host1x_cdma {int dummy; } ;
struct host1x_channel {scalar_t__ regs; int /*<<< orphan*/  submitlock; struct device* dev; struct host1x_cdma cdma; } ;
struct host1x_bo {int dummy; } ;
struct host1x {scalar_t__ regs; struct host1x_syncpt* syncpt; TYPE_5__* debug_op; TYPE_4__* cdma_pb_op; TYPE_3__* cdma_op; TYPE_2__* channel_op; TYPE_1__* intr_op; TYPE_7__* syncpt_op; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct dentry {int dummy; } ;
typedef  scalar_t__ s32 ;
struct TYPE_16__ {struct device* dev; } ;
struct TYPE_15__ {int (* load ) (struct host1x_syncpt*) ;int (* cpu_incr ) (struct host1x_syncpt*) ;void (* assign_to_channel ) (struct host1x_syncpt*,struct host1x_channel*) ;void (* enable_protection ) (struct host1x*) ;int /*<<< orphan*/  (* load_wait_base ) (struct host1x_syncpt*) ;int /*<<< orphan*/  (* restore_wait_base ) (struct host1x_syncpt*) ;int /*<<< orphan*/  (* restore ) (struct host1x_syncpt*) ;} ;
struct TYPE_14__ {unsigned int id; } ;
struct TYPE_13__ {int /*<<< orphan*/  (* show_mlocks ) (struct host1x*,struct output*) ;int /*<<< orphan*/  (* show_channel_fifo ) (struct host1x*,struct host1x_channel*,struct output*) ;int /*<<< orphan*/  (* show_channel_cdma ) (struct host1x*,struct host1x_channel*,struct output*) ;int /*<<< orphan*/  (* debug_init ) (struct dentry*) ;} ;
struct TYPE_12__ {int /*<<< orphan*/  (* init ) (struct push_buffer*) ;} ;
struct TYPE_11__ {int (* timeout_init ) (struct host1x_cdma*,unsigned int) ;int /*<<< orphan*/  (* timeout_cpu_incr ) (struct host1x_cdma*,int,int,int,int) ;int /*<<< orphan*/  (* resume ) (struct host1x_cdma*,int) ;int /*<<< orphan*/  (* freeze ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* timeout_destroy ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* flush ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* stop ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* start ) (struct host1x_cdma*) ;} ;
struct TYPE_10__ {int (* init ) (struct host1x_channel*,struct host1x*,unsigned int) ;int (* submit ) (struct host1x_job*) ;} ;
struct TYPE_9__ {int (* init_host_sync ) (struct host1x*,int,void (*) (struct work_struct*)) ;int (* free_syncpt_irq ) (struct host1x*) ;int /*<<< orphan*/  (* disable_all_syncpt_intrs ) (struct host1x*) ;int /*<<< orphan*/  (* disable_syncpt_intr ) (struct host1x*,unsigned int) ;int /*<<< orphan*/  (* enable_syncpt_intr ) (struct host1x*,unsigned int) ;int /*<<< orphan*/  (* set_syncpt_threshold ) (struct host1x*,unsigned int,int) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int HOST1X_CHANNEL_SIZE ; 
 scalar_t__ HOST1X_CLASS_HOST1X ; 
 int /*<<< orphan*/  HOST1X_INTR_ACTION_SUBMIT_COMPLETE ; 
 int HOST1X_OPCODE_NOP ; 
 int /*<<< orphan*/  HOST1X_UCLASS_LOAD_SYNCPT_BASE ; 
 int HOST1X_UCLASS_LOAD_SYNCPT_BASE_BASE_INDX_F (unsigned int) ; 
 int HOST1X_UCLASS_LOAD_SYNCPT_BASE_VALUE_F (int) ; 
 scalar_t__ TRACE_MAX_LENGTH ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 TYPE_8__* cdma_to_channel (struct host1x_cdma*) ; 
 struct host1x* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 void* host1x_bo_mmap (struct host1x_bo*) ; 
 int /*<<< orphan*/  host1x_bo_munmap (struct host1x_bo*,void*) ; 
 int host1x_cdma_begin (struct host1x_cdma*,struct host1x_job*) ; 
 int /*<<< orphan*/  host1x_cdma_end (struct host1x_cdma*,struct host1x_job*) ; 
 int /*<<< orphan*/  host1x_cdma_push (struct host1x_cdma*,int,int) ; 
 int host1x_class_host_wait_syncpt (int,void*) ; 
 scalar_t__ host1x_debug_trace_cmdbuf ; 
 int host1x_intr_add_action (struct host1x*,struct host1x_syncpt*,int,int /*<<< orphan*/ ,struct host1x_channel*,struct host1x_waitlist*,int /*<<< orphan*/ *) ; 
 int host1x_opcode_gather (int /*<<< orphan*/ ) ; 
 int host1x_opcode_setclass (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int host1x_syncpt_incr_max (struct host1x_syncpt*,int) ; 
 scalar_t__ host1x_syncpt_nb_pts (int /*<<< orphan*/ ) ; 
 void* host1x_syncpt_read_max (struct host1x_syncpt*) ; 
 int /*<<< orphan*/  host1x_uclass_wait_syncpt_r () ; 
 int /*<<< orphan*/  kfree (struct host1x_waitlist*) ; 
 struct host1x_waitlist* kzalloc (int,int /*<<< orphan*/ ) ; 
 int min (int,scalar_t__) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 int /*<<< orphan*/  stub1 (struct host1x_syncpt*) ; 
 int /*<<< orphan*/  stub10 (struct host1x*,unsigned int) ; 
 int /*<<< orphan*/  stub11 (struct host1x*,unsigned int) ; 
 int /*<<< orphan*/  stub12 (struct host1x*) ; 
 int stub13 (struct host1x*) ; 
 int stub14 (struct host1x_channel*,struct host1x*,unsigned int) ; 
 int stub15 (struct host1x_job*) ; 
 int /*<<< orphan*/  stub16 (struct host1x_cdma*) ; 
 int /*<<< orphan*/  stub17 (struct host1x_cdma*) ; 
 int /*<<< orphan*/  stub18 (struct host1x_cdma*) ; 
 int stub19 (struct host1x_cdma*,unsigned int) ; 
 int /*<<< orphan*/  stub2 (struct host1x_syncpt*) ; 
 int /*<<< orphan*/  stub20 (struct host1x_cdma*) ; 
 int /*<<< orphan*/  stub21 (struct host1x_cdma*) ; 
 int /*<<< orphan*/  stub22 (struct host1x_cdma*,int) ; 
 int /*<<< orphan*/  stub23 (struct host1x_cdma*,int,int,int,int) ; 
 int /*<<< orphan*/  stub24 (struct push_buffer*) ; 
 int /*<<< orphan*/  stub25 (struct dentry*) ; 
 int /*<<< orphan*/  stub26 (struct host1x*,struct host1x_channel*,struct output*) ; 
 int /*<<< orphan*/  stub27 (struct host1x*,struct host1x_channel*,struct output*) ; 
 int /*<<< orphan*/  stub28 (struct host1x*,struct output*) ; 
 int /*<<< orphan*/  stub3 (struct host1x_syncpt*) ; 
 int stub4 (struct host1x_syncpt*) ; 
 int stub5 (struct host1x_syncpt*) ; 
 void stub6 (struct host1x_syncpt*,struct host1x_channel*) ; 
 void stub7 (struct host1x*) ; 
 int stub8 (struct host1x*,int,void (*) (struct work_struct*)) ; 
 int /*<<< orphan*/  stub9 (struct host1x*,unsigned int,int) ; 
 int /*<<< orphan*/  trace_host1x_cdma_push_gather (int /*<<< orphan*/ ,struct host1x_bo*,int,int,void*) ; 
 int /*<<< orphan*/  trace_host1x_channel_submit (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  trace_host1x_channel_submitted (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static inline bool host1x_syncpt_check_max(struct host1x_syncpt *sp, u32 real)
{
	u32 max;
	if (sp->client_managed)
		return true;
	max = host1x_syncpt_read_max(sp);
	return (s32)(max - real) >= 0;
}

__attribute__((used)) static inline bool host1x_syncpt_client_managed(struct host1x_syncpt *sp)
{
	return sp->client_managed;
}

__attribute__((used)) static inline bool host1x_syncpt_idle(struct host1x_syncpt *sp)
{
	int min, max;
	smp_rmb();
	min = atomic_read(&sp->min_val);
	max = atomic_read(&sp->max_val);
	return (min == max);
}

__attribute__((used)) static inline int host1x_syncpt_is_valid(struct host1x_syncpt *sp)
{
	return sp->id < host1x_syncpt_nb_pts(sp->host);
}

__attribute__((used)) static inline void host1x_hw_syncpt_restore(struct host1x *host,
					    struct host1x_syncpt *sp)
{
	host->syncpt_op->restore(sp);
}

__attribute__((used)) static inline void host1x_hw_syncpt_restore_wait_base(struct host1x *host,
						      struct host1x_syncpt *sp)
{
	host->syncpt_op->restore_wait_base(sp);
}

__attribute__((used)) static inline void host1x_hw_syncpt_load_wait_base(struct host1x *host,
						   struct host1x_syncpt *sp)
{
	host->syncpt_op->load_wait_base(sp);
}

__attribute__((used)) static inline u32 host1x_hw_syncpt_load(struct host1x *host,
					struct host1x_syncpt *sp)
{
	return host->syncpt_op->load(sp);
}

__attribute__((used)) static inline int host1x_hw_syncpt_cpu_incr(struct host1x *host,
					    struct host1x_syncpt *sp)
{
	return host->syncpt_op->cpu_incr(sp);
}

__attribute__((used)) static inline void host1x_hw_syncpt_assign_to_channel(
	struct host1x *host, struct host1x_syncpt *sp,
	struct host1x_channel *ch)
{
	return host->syncpt_op->assign_to_channel(sp, ch);
}

__attribute__((used)) static inline void host1x_hw_syncpt_enable_protection(struct host1x *host)
{
	return host->syncpt_op->enable_protection(host);
}

__attribute__((used)) static inline int host1x_hw_intr_init_host_sync(struct host1x *host, u32 cpm,
			void (*syncpt_thresh_work)(struct work_struct *))
{
	return host->intr_op->init_host_sync(host, cpm, syncpt_thresh_work);
}

__attribute__((used)) static inline void host1x_hw_intr_set_syncpt_threshold(struct host1x *host,
						       unsigned int id,
						       u32 thresh)
{
	host->intr_op->set_syncpt_threshold(host, id, thresh);
}

__attribute__((used)) static inline void host1x_hw_intr_enable_syncpt_intr(struct host1x *host,
						     unsigned int id)
{
	host->intr_op->enable_syncpt_intr(host, id);
}

__attribute__((used)) static inline void host1x_hw_intr_disable_syncpt_intr(struct host1x *host,
						      unsigned int id)
{
	host->intr_op->disable_syncpt_intr(host, id);
}

__attribute__((used)) static inline void host1x_hw_intr_disable_all_syncpt_intrs(struct host1x *host)
{
	host->intr_op->disable_all_syncpt_intrs(host);
}

__attribute__((used)) static inline int host1x_hw_intr_free_syncpt_irq(struct host1x *host)
{
	return host->intr_op->free_syncpt_irq(host);
}

__attribute__((used)) static inline int host1x_hw_channel_init(struct host1x *host,
					 struct host1x_channel *channel,
					 unsigned int id)
{
	return host->channel_op->init(channel, host, id);
}

__attribute__((used)) static inline int host1x_hw_channel_submit(struct host1x *host,
					   struct host1x_job *job)
{
	return host->channel_op->submit(job);
}

__attribute__((used)) static inline void host1x_hw_cdma_start(struct host1x *host,
					struct host1x_cdma *cdma)
{
	host->cdma_op->start(cdma);
}

__attribute__((used)) static inline void host1x_hw_cdma_stop(struct host1x *host,
				       struct host1x_cdma *cdma)
{
	host->cdma_op->stop(cdma);
}

__attribute__((used)) static inline void host1x_hw_cdma_flush(struct host1x *host,
					struct host1x_cdma *cdma)
{
	host->cdma_op->flush(cdma);
}

__attribute__((used)) static inline int host1x_hw_cdma_timeout_init(struct host1x *host,
					      struct host1x_cdma *cdma,
					      unsigned int syncpt)
{
	return host->cdma_op->timeout_init(cdma, syncpt);
}

__attribute__((used)) static inline void host1x_hw_cdma_timeout_destroy(struct host1x *host,
						  struct host1x_cdma *cdma)
{
	host->cdma_op->timeout_destroy(cdma);
}

__attribute__((used)) static inline void host1x_hw_cdma_freeze(struct host1x *host,
					 struct host1x_cdma *cdma)
{
	host->cdma_op->freeze(cdma);
}

__attribute__((used)) static inline void host1x_hw_cdma_resume(struct host1x *host,
					 struct host1x_cdma *cdma, u32 getptr)
{
	host->cdma_op->resume(cdma, getptr);
}

__attribute__((used)) static inline void host1x_hw_cdma_timeout_cpu_incr(struct host1x *host,
						   struct host1x_cdma *cdma,
						   u32 getptr,
						   u32 syncpt_incrs,
						   u32 syncval, u32 nr_slots)
{
	host->cdma_op->timeout_cpu_incr(cdma, getptr, syncpt_incrs, syncval,
					nr_slots);
}

__attribute__((used)) static inline void host1x_hw_pushbuffer_init(struct host1x *host,
					     struct push_buffer *pb)
{
	host->cdma_pb_op->init(pb);
}

__attribute__((used)) static inline void host1x_hw_debug_init(struct host1x *host, struct dentry *de)
{
	if (host->debug_op && host->debug_op->debug_init)
		host->debug_op->debug_init(de);
}

__attribute__((used)) static inline void host1x_hw_show_channel_cdma(struct host1x *host,
					       struct host1x_channel *channel,
					       struct output *o)
{
	host->debug_op->show_channel_cdma(host, channel, o);
}

__attribute__((used)) static inline void host1x_hw_show_channel_fifo(struct host1x *host,
					       struct host1x_channel *channel,
					       struct output *o)
{
	host->debug_op->show_channel_fifo(host, channel, o);
}

__attribute__((used)) static inline void host1x_hw_show_mlocks(struct host1x *host, struct output *o)
{
	host->debug_op->show_mlocks(host, o);
}

__attribute__((used)) static void trace_write_gather(struct host1x_cdma *cdma, struct host1x_bo *bo,
			       u32 offset, u32 words)
{
	struct device *dev = cdma_to_channel(cdma)->dev;
	void *mem = NULL;

	if (host1x_debug_trace_cmdbuf)
		mem = host1x_bo_mmap(bo);

	if (mem) {
		u32 i;
		/*
		 * Write in batches of 128 as there seems to be a limit
		 * of how much you can output to ftrace at once.
		 */
		for (i = 0; i < words; i += TRACE_MAX_LENGTH) {
			u32 num_words = min(words - i, TRACE_MAX_LENGTH);

			offset += i * sizeof(u32);

			trace_host1x_cdma_push_gather(dev_name(dev), bo,
						      num_words, offset,
						      mem);
		}

		host1x_bo_munmap(bo, mem);
	}
}

__attribute__((used)) static void submit_gathers(struct host1x_job *job)
{
	struct host1x_cdma *cdma = &job->channel->cdma;
	unsigned int i;

	for (i = 0; i < job->num_gathers; i++) {
		struct host1x_job_gather *g = &job->gathers[i];
		u32 op1 = host1x_opcode_gather(g->words);
		u32 op2 = g->base + g->offset;

		trace_write_gather(cdma, g->bo, g->offset, op1 & 0xffff);
		host1x_cdma_push(cdma, op1, op2);
	}
}

__attribute__((used)) static inline void synchronize_syncpt_base(struct host1x_job *job)
{
	struct host1x *host = dev_get_drvdata(job->channel->dev->parent);
	struct host1x_syncpt *sp = host->syncpt + job->syncpt_id;
	unsigned int id;
	u32 value;

	value = host1x_syncpt_read_max(sp);
	id = sp->base->id;

	host1x_cdma_push(&job->channel->cdma,
			 host1x_opcode_setclass(HOST1X_CLASS_HOST1X,
				HOST1X_UCLASS_LOAD_SYNCPT_BASE, 1),
			 HOST1X_UCLASS_LOAD_SYNCPT_BASE_BASE_INDX_F(id) |
			 HOST1X_UCLASS_LOAD_SYNCPT_BASE_VALUE_F(value));
}

__attribute__((used)) static int channel_submit(struct host1x_job *job)
{
	struct host1x_channel *ch = job->channel;
	struct host1x_syncpt *sp;
	u32 user_syncpt_incrs = job->syncpt_incrs;
	u32 prev_max = 0;
	u32 syncval;
	int err;
	struct host1x_waitlist *completed_waiter = NULL;
	struct host1x *host = dev_get_drvdata(ch->dev->parent);

	sp = host->syncpt + job->syncpt_id;
	trace_host1x_channel_submit(dev_name(ch->dev),
				    job->num_gathers, job->num_relocs,
				    job->syncpt_id, job->syncpt_incrs);

	/* before error checks, return current max */
	prev_max = job->syncpt_end = host1x_syncpt_read_max(sp);

	/* get submit lock */
	err = mutex_lock_interruptible(&ch->submitlock);
	if (err)
		goto error;

	completed_waiter = kzalloc(sizeof(*completed_waiter), GFP_KERNEL);
	if (!completed_waiter) {
		mutex_unlock(&ch->submitlock);
		err = -ENOMEM;
		goto error;
	}

	/* begin a CDMA submit */
	err = host1x_cdma_begin(&ch->cdma, job);
	if (err) {
		mutex_unlock(&ch->submitlock);
		goto error;
	}

	if (job->serialize) {
		/*
		 * Force serialization by inserting a host wait for the
		 * previous job to finish before this one can commence.
		 */
		host1x_cdma_push(&ch->cdma,
				 host1x_opcode_setclass(HOST1X_CLASS_HOST1X,
					host1x_uclass_wait_syncpt_r(), 1),
				 host1x_class_host_wait_syncpt(job->syncpt_id,
					host1x_syncpt_read_max(sp)));
	}

	/* Synchronize base register to allow using it for relative waiting */
	if (sp->base)
		synchronize_syncpt_base(job);

	syncval = host1x_syncpt_incr_max(sp, user_syncpt_incrs);

	host1x_hw_syncpt_assign_to_channel(host, sp, ch);

	job->syncpt_end = syncval;

	/* add a setclass for modules that require it */
	if (job->class)
		host1x_cdma_push(&ch->cdma,
				 host1x_opcode_setclass(job->class, 0, 0),
				 HOST1X_OPCODE_NOP);

	submit_gathers(job);

	/* end CDMA submit & stash pinned hMems into sync queue */
	host1x_cdma_end(&ch->cdma, job);

	trace_host1x_channel_submitted(dev_name(ch->dev), prev_max, syncval);

	/* schedule a submit complete interrupt */
	err = host1x_intr_add_action(host, sp, syncval,
				     HOST1X_INTR_ACTION_SUBMIT_COMPLETE, ch,
				     completed_waiter, NULL);
	completed_waiter = NULL;
	WARN(err, "Failed to set submit complete interrupt");

	mutex_unlock(&ch->submitlock);

	return 0;

error:
	kfree(completed_waiter);
	return err;
}

__attribute__((used)) static void enable_gather_filter(struct host1x *host,
				 struct host1x_channel *ch)
{
#if HOST1X_HW >= 6
	u32 val;

	if (!host->hv_regs)
		return;

	val = host1x_hypervisor_readl(
		host, HOST1X_HV_CH_KERNEL_FILTER_GBUFFER(ch->id / 32));
	val |= BIT(ch->id % 32);
	host1x_hypervisor_writel(
		host, val, HOST1X_HV_CH_KERNEL_FILTER_GBUFFER(ch->id / 32));
#elif HOST1X_HW >= 4
	host1x_ch_writel(ch,
			 HOST1X_CHANNEL_CHANNELCTRL_KERNEL_FILTER_GBUFFER(1),
			 HOST1X_CHANNEL_CHANNELCTRL);
#endif
}

__attribute__((used)) static int host1x_channel_init(struct host1x_channel *ch, struct host1x *dev,
			       unsigned int index)
{
	ch->regs = dev->regs + index * HOST1X_CHANNEL_SIZE;
	enable_gather_filter(dev, ch);
	return 0;
}

