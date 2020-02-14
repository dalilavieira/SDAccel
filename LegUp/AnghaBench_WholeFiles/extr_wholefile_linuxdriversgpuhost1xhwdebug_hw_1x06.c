#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct seq_file {int dummy; } ;
struct push_buffer {int dummy; } ;
struct output {int dummy; } ;
struct host1x_syncpt {int client_managed; scalar_t__ id; int /*<<< orphan*/  host; int /*<<< orphan*/  max_val; int /*<<< orphan*/  min_val; } ;
struct host1x_job {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  mapped; } ;
struct host1x_cdma {TYPE_4__ push_buffer; } ;
struct host1x_channel {int /*<<< orphan*/  id; struct host1x_cdma cdma; int /*<<< orphan*/  dev; } ;
struct host1x {TYPE_3__* debug_op; TYPE_2__* cdma_pb_op; TYPE_1__* cdma_op; TYPE_7__* channel_op; TYPE_6__* intr_op; TYPE_5__* syncpt_op; } ;
struct dentry {int dummy; } ;
typedef  scalar_t__ s32 ;
struct TYPE_14__ {int (* init ) (struct host1x_channel*,struct host1x*,unsigned int) ;int (* submit ) (struct host1x_job*) ;} ;
struct TYPE_13__ {int (* init_host_sync ) (struct host1x*,scalar_t__,void (*) (struct work_struct*)) ;int (* free_syncpt_irq ) (struct host1x*) ;int /*<<< orphan*/  (* disable_all_syncpt_intrs ) (struct host1x*) ;int /*<<< orphan*/  (* disable_syncpt_intr ) (struct host1x*,unsigned int) ;int /*<<< orphan*/  (* enable_syncpt_intr ) (struct host1x*,unsigned int) ;int /*<<< orphan*/  (* set_syncpt_threshold ) (struct host1x*,unsigned int,scalar_t__) ;} ;
struct TYPE_12__ {scalar_t__ (* load ) (struct host1x_syncpt*) ;int (* cpu_incr ) (struct host1x_syncpt*) ;void (* assign_to_channel ) (struct host1x_syncpt*,struct host1x_channel*) ;void (* enable_protection ) (struct host1x*) ;int /*<<< orphan*/  (* load_wait_base ) (struct host1x_syncpt*) ;int /*<<< orphan*/  (* restore_wait_base ) (struct host1x_syncpt*) ;int /*<<< orphan*/  (* restore ) (struct host1x_syncpt*) ;} ;
struct TYPE_10__ {int /*<<< orphan*/  (* show_mlocks ) (struct host1x*,struct output*) ;int /*<<< orphan*/  (* show_channel_fifo ) (struct host1x*,struct host1x_channel*,struct output*) ;int /*<<< orphan*/  (* show_channel_cdma ) (struct host1x*,struct host1x_channel*,struct output*) ;int /*<<< orphan*/  (* debug_init ) (struct dentry*) ;} ;
struct TYPE_9__ {int /*<<< orphan*/  (* init ) (struct push_buffer*) ;} ;
struct TYPE_8__ {int (* timeout_init ) (struct host1x_cdma*,unsigned int) ;int /*<<< orphan*/  (* timeout_cpu_incr ) (struct host1x_cdma*,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ;int /*<<< orphan*/  (* resume ) (struct host1x_cdma*,scalar_t__) ;int /*<<< orphan*/  (* freeze ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* timeout_destroy ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* flush ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* stop ) (struct host1x_cdma*) ;int /*<<< orphan*/  (* start ) (struct host1x_cdma*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  HOST1X_CHANNEL_CHANNELSTAT ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_CMDFIFO_RDATA ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_CMDFIFO_STAT ; 
 scalar_t__ HOST1X_CHANNEL_CMDFIFO_STAT_EMPTY ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_CMDP_CLASS ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_CMDP_OFFSET ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_DMACTRL ; 
 scalar_t__ HOST1X_CHANNEL_DMACTRL_DMASTOP ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_DMAGET ; 
 int /*<<< orphan*/  HOST1X_CHANNEL_DMAPUT ; 
 scalar_t__ HOST1X_CLASS_HOST1X ; 
 int /*<<< orphan*/  HOST1X_HV_CMDFIFO_PEEK_CTRL ; 
 scalar_t__ HOST1X_HV_CMDFIFO_PEEK_CTRL_ADDR (scalar_t__) ; 
 scalar_t__ HOST1X_HV_CMDFIFO_PEEK_CTRL_CHANNEL (int /*<<< orphan*/ ) ; 
 scalar_t__ HOST1X_HV_CMDFIFO_PEEK_CTRL_ENABLE ; 
 int /*<<< orphan*/  HOST1X_HV_CMDFIFO_PEEK_PTRS ; 
 scalar_t__ HOST1X_HV_CMDFIFO_PEEK_PTRS_RD_PTR_V (scalar_t__) ; 
 scalar_t__ HOST1X_HV_CMDFIFO_PEEK_PTRS_WR_PTR_V (scalar_t__) ; 
 int /*<<< orphan*/  HOST1X_HV_CMDFIFO_PEEK_READ ; 
 int /*<<< orphan*/  HOST1X_HV_CMDFIFO_SETUP (int /*<<< orphan*/ ) ; 
 scalar_t__ HOST1X_HV_CMDFIFO_SETUP_BASE_V (scalar_t__) ; 
 scalar_t__ HOST1X_HV_CMDFIFO_SETUP_LIMIT_V (scalar_t__) ; 
 int /*<<< orphan*/  HOST1X_HV_ICG_EN_OVERRIDE ; 
 scalar_t__ HOST1X_UCLASS_WAIT_SYNCPT ; 
 scalar_t__ INVALID_PAYLOAD ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 scalar_t__ host1x_ch_readl (struct host1x_channel*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  host1x_debug_cont (struct output*,char*,...) ; 
 int /*<<< orphan*/  host1x_debug_output (struct output*,char*,...) ; 
 scalar_t__ host1x_hypervisor_readl (struct host1x*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  host1x_hypervisor_writel (struct host1x*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ host1x_syncpt_nb_pts (int /*<<< orphan*/ ) ; 
 scalar_t__ host1x_syncpt_read_max (struct host1x_syncpt*) ; 
 int /*<<< orphan*/  pr_cont (char*,char const*) ; 
 int /*<<< orphan*/  pr_info (char*,char const*) ; 
 int /*<<< orphan*/  seq_write (struct seq_file*,char const*,size_t) ; 
 unsigned int show_channel_command (struct output*,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  show_channel_gathers (struct output*,struct host1x_cdma*) ; 
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
 int /*<<< orphan*/  stub22 (struct host1x_cdma*,scalar_t__) ; 
 int /*<<< orphan*/  stub23 (struct host1x_cdma*,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub24 (struct push_buffer*) ; 
 int /*<<< orphan*/  stub25 (struct dentry*) ; 
 int /*<<< orphan*/  stub26 (struct host1x*,struct host1x_channel*,struct output*) ; 
 int /*<<< orphan*/  stub27 (struct host1x*,struct host1x_channel*,struct output*) ; 
 int /*<<< orphan*/  stub28 (struct host1x*,struct output*) ; 
 int /*<<< orphan*/  stub3 (struct host1x_syncpt*) ; 
 scalar_t__ stub4 (struct host1x_syncpt*) ; 
 int stub5 (struct host1x_syncpt*) ; 
 void stub6 (struct host1x_syncpt*,struct host1x_channel*) ; 
 void stub7 (struct host1x*) ; 
 int stub8 (struct host1x*,scalar_t__,void (*) (struct work_struct*)) ; 
 int /*<<< orphan*/  stub9 (struct host1x*,unsigned int,scalar_t__) ; 

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

__attribute__((used)) static inline void write_to_seqfile(void *ctx, const char *str, size_t len,
				    bool cont)
{
	seq_write((struct seq_file *)ctx, str, len);
}

__attribute__((used)) static inline void write_to_printk(void *ctx, const char *str, size_t len,
				   bool cont)
{
	if (cont)
		pr_cont("%s", str);
	else
		pr_info("%s", str);
}

__attribute__((used)) static void host1x_debug_show_channel_cdma(struct host1x *host,
					   struct host1x_channel *ch,
					   struct output *o)
{
	struct host1x_cdma *cdma = &ch->cdma;
	u32 dmaput, dmaget, dmactrl;
	u32 offset, class;
	u32 ch_stat;

	dmaput = host1x_ch_readl(ch, HOST1X_CHANNEL_DMAPUT);
	dmaget = host1x_ch_readl(ch, HOST1X_CHANNEL_DMAGET);
	dmactrl = host1x_ch_readl(ch, HOST1X_CHANNEL_DMACTRL);
	offset = host1x_ch_readl(ch, HOST1X_CHANNEL_CMDP_OFFSET);
	class = host1x_ch_readl(ch, HOST1X_CHANNEL_CMDP_CLASS);
	ch_stat = host1x_ch_readl(ch, HOST1X_CHANNEL_CHANNELSTAT);

	host1x_debug_output(o, "%u-%s: ", ch->id, dev_name(ch->dev));

	if (dmactrl & HOST1X_CHANNEL_DMACTRL_DMASTOP ||
	    !ch->cdma.push_buffer.mapped) {
		host1x_debug_output(o, "inactive\n\n");
		return;
	}

	if (class == HOST1X_CLASS_HOST1X && offset == HOST1X_UCLASS_WAIT_SYNCPT)
		host1x_debug_output(o, "waiting on syncpt\n");
	else
		host1x_debug_output(o, "active class %02x, offset %04x\n",
				    class, offset);

	host1x_debug_output(o, "DMAPUT %08x, DMAGET %08x, DMACTL %08x\n",
			    dmaput, dmaget, dmactrl);
	host1x_debug_output(o, "CHANNELSTAT %02x\n", ch_stat);

	show_channel_gathers(o, cdma);
	host1x_debug_output(o, "\n");
}

__attribute__((used)) static void host1x_debug_show_channel_fifo(struct host1x *host,
					   struct host1x_channel *ch,
					   struct output *o)
{
	u32 val, rd_ptr, wr_ptr, start, end;
	u32 payload = INVALID_PAYLOAD;
	unsigned int data_count = 0;

	host1x_debug_output(o, "%u: fifo:\n", ch->id);

	val = host1x_ch_readl(ch, HOST1X_CHANNEL_CMDFIFO_STAT);
	host1x_debug_output(o, "CMDFIFO_STAT %08x\n", val);
	if (val & HOST1X_CHANNEL_CMDFIFO_STAT_EMPTY) {
		host1x_debug_output(o, "[empty]\n");
		return;
	}

	val = host1x_ch_readl(ch, HOST1X_CHANNEL_CMDFIFO_RDATA);
	host1x_debug_output(o, "CMDFIFO_RDATA %08x\n", val);

	/* Peek pointer values are invalid during SLCG, so disable it */
	host1x_hypervisor_writel(host, 0x1, HOST1X_HV_ICG_EN_OVERRIDE);

	val = 0;
	val |= HOST1X_HV_CMDFIFO_PEEK_CTRL_ENABLE;
	val |= HOST1X_HV_CMDFIFO_PEEK_CTRL_CHANNEL(ch->id);
	host1x_hypervisor_writel(host, val, HOST1X_HV_CMDFIFO_PEEK_CTRL);

	val = host1x_hypervisor_readl(host, HOST1X_HV_CMDFIFO_PEEK_PTRS);
	rd_ptr = HOST1X_HV_CMDFIFO_PEEK_PTRS_RD_PTR_V(val);
	wr_ptr = HOST1X_HV_CMDFIFO_PEEK_PTRS_WR_PTR_V(val);

	val = host1x_hypervisor_readl(host, HOST1X_HV_CMDFIFO_SETUP(ch->id));
	start = HOST1X_HV_CMDFIFO_SETUP_BASE_V(val);
	end = HOST1X_HV_CMDFIFO_SETUP_LIMIT_V(val);

	do {
		val = 0;
		val |= HOST1X_HV_CMDFIFO_PEEK_CTRL_ENABLE;
		val |= HOST1X_HV_CMDFIFO_PEEK_CTRL_CHANNEL(ch->id);
		val |= HOST1X_HV_CMDFIFO_PEEK_CTRL_ADDR(rd_ptr);
		host1x_hypervisor_writel(host, val,
					 HOST1X_HV_CMDFIFO_PEEK_CTRL);

		val = host1x_hypervisor_readl(host,
					      HOST1X_HV_CMDFIFO_PEEK_READ);

		if (!data_count) {
			host1x_debug_output(o, "%03x 0x%08x: ",
					    rd_ptr - start, val);
			data_count = show_channel_command(o, val, &payload);
		} else {
			host1x_debug_cont(o, "%08x%s", val,
					  data_count > 1 ? ", " : "])\n");
			data_count--;
		}

		if (rd_ptr == end)
			rd_ptr = start;
		else
			rd_ptr++;
	} while (rd_ptr != wr_ptr);

	if (data_count)
		host1x_debug_cont(o, ", ...])\n");
	host1x_debug_output(o, "\n");

	host1x_hypervisor_writel(host, 0x0, HOST1X_HV_CMDFIFO_PEEK_CTRL);
	host1x_hypervisor_writel(host, 0x0, HOST1X_HV_ICG_EN_OVERRIDE);
}

__attribute__((used)) static void host1x_debug_show_mlocks(struct host1x *host, struct output *o)
{
	/* TODO */
}

