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
typedef  int u32 ;
struct sst_generic_ipc {struct sst_dsp* dsp; } ;
struct TYPE_4__ {int lpe; } ;
struct sst_dsp {void* thread_context; int intr_status; int /*<<< orphan*/  irq; int /*<<< orphan*/  spinlock; int /*<<< orphan*/  dev; TYPE_2__ addr; TYPE_1__* ops; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {int /*<<< orphan*/  (* ram_read ) (struct sst_dsp*,void*,int,size_t) ;int /*<<< orphan*/  (* ram_write ) (struct sst_dsp*,int,void*,size_t) ;} ;

/* Variables and functions */
 int CNL_ADSPCS_CPA (unsigned int) ; 
 int CNL_ADSPCS_CRST (unsigned int) ; 
 int CNL_ADSPCS_CSTALL (unsigned int) ; 
 int CNL_ADSPCS_SPA (unsigned int) ; 
 int CNL_ADSPIC_IPC ; 
 int CNL_ADSPIS_IPC ; 
 int /*<<< orphan*/  CNL_ADSP_REG_ADSPCS ; 
 int /*<<< orphan*/  CNL_ADSP_REG_ADSPIC ; 
 int /*<<< orphan*/  CNL_ADSP_REG_ADSPIS ; 
 int /*<<< orphan*/  CNL_ADSP_REG_HIPCCTL ; 
 int CNL_ADSP_REG_HIPCCTL_BUSY ; 
 int CNL_ADSP_REG_HIPCCTL_DONE ; 
 int /*<<< orphan*/  CNL_DSP_PD_TO ; 
 int /*<<< orphan*/  CNL_DSP_PU_TO ; 
 int /*<<< orphan*/  CNL_DSP_RESET_TO ; 
 int EIO ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 unsigned int SKL_DSP_CORE0_MASK ; 
 void cnl_ipc_int_disable (struct sst_dsp*) ; 
 void cnl_ipc_op_int_disable (struct sst_dsp*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,unsigned int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct sst_dsp*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int sst_dsp_register_poll (struct sst_dsp*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,char*) ; 
 int sst_dsp_shim_read_unlocked (struct sst_dsp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sst_dsp_shim_update_bits (struct sst_dsp*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  sst_dsp_shim_update_bits_unlocked (struct sst_dsp*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  sst_ipc_fini (struct sst_generic_ipc*) ; 
 int /*<<< orphan*/  stub1 (struct sst_dsp*,int,void*,size_t) ; 
 int /*<<< orphan*/  stub2 (struct sst_dsp*,void*,int,size_t) ; 

__attribute__((used)) static inline void sst_dsp_write(struct sst_dsp *sst, void *src,
	u32 dest_offset, size_t bytes)
{
	sst->ops->ram_write(sst, sst->addr.lpe + dest_offset, src, bytes);
}

__attribute__((used)) static inline void sst_dsp_read(struct sst_dsp *sst, void *dest,
	u32 src_offset, size_t bytes)
{
	sst->ops->ram_read(sst, dest, sst->addr.lpe + src_offset, bytes);
}

__attribute__((used)) static inline void *sst_dsp_get_thread_context(struct sst_dsp *sst)
{
	return sst->thread_context;
}

__attribute__((used)) static int
cnl_dsp_core_set_reset_state(struct sst_dsp *ctx, unsigned int core_mask)
{
	/* update bits */
	sst_dsp_shim_update_bits_unlocked(ctx,
			CNL_ADSP_REG_ADSPCS, CNL_ADSPCS_CRST(core_mask),
			CNL_ADSPCS_CRST(core_mask));

	/* poll with timeout to check if operation successful */
	return sst_dsp_register_poll(ctx,
			CNL_ADSP_REG_ADSPCS,
			CNL_ADSPCS_CRST(core_mask),
			CNL_ADSPCS_CRST(core_mask),
			CNL_DSP_RESET_TO,
			"Set reset");
}

__attribute__((used)) static int
cnl_dsp_core_unset_reset_state(struct sst_dsp *ctx, unsigned int core_mask)
{
	/* update bits */
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPCS,
					CNL_ADSPCS_CRST(core_mask), 0);

	/* poll with timeout to check if operation successful */
	return sst_dsp_register_poll(ctx,
			CNL_ADSP_REG_ADSPCS,
			CNL_ADSPCS_CRST(core_mask),
			0,
			CNL_DSP_RESET_TO,
			"Unset reset");
}

__attribute__((used)) static bool is_cnl_dsp_core_enable(struct sst_dsp *ctx, unsigned int core_mask)
{
	int val;
	bool is_enable;

	val = sst_dsp_shim_read_unlocked(ctx, CNL_ADSP_REG_ADSPCS);

	is_enable = (val & CNL_ADSPCS_CPA(core_mask)) &&
			(val & CNL_ADSPCS_SPA(core_mask)) &&
			!(val & CNL_ADSPCS_CRST(core_mask)) &&
			!(val & CNL_ADSPCS_CSTALL(core_mask));

	dev_dbg(ctx->dev, "DSP core(s) enabled? %d: core_mask %#x\n",
		is_enable, core_mask);

	return is_enable;
}

__attribute__((used)) static int cnl_dsp_reset_core(struct sst_dsp *ctx, unsigned int core_mask)
{
	/* stall core */
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPCS,
			CNL_ADSPCS_CSTALL(core_mask),
			CNL_ADSPCS_CSTALL(core_mask));

	/* set reset state */
	return cnl_dsp_core_set_reset_state(ctx, core_mask);
}

__attribute__((used)) static int cnl_dsp_start_core(struct sst_dsp *ctx, unsigned int core_mask)
{
	int ret;

	/* unset reset state */
	ret = cnl_dsp_core_unset_reset_state(ctx, core_mask);
	if (ret < 0)
		return ret;

	/* run core */
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPCS,
				CNL_ADSPCS_CSTALL(core_mask), 0);

	if (!is_cnl_dsp_core_enable(ctx, core_mask)) {
		cnl_dsp_reset_core(ctx, core_mask);
		dev_err(ctx->dev, "DSP core mask %#x enable failed\n",
			core_mask);
		ret = -EIO;
	}

	return ret;
}

__attribute__((used)) static int cnl_dsp_core_power_up(struct sst_dsp *ctx, unsigned int core_mask)
{
	/* update bits */
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPCS,
					  CNL_ADSPCS_SPA(core_mask),
					  CNL_ADSPCS_SPA(core_mask));

	/* poll with timeout to check if operation successful */
	return sst_dsp_register_poll(ctx, CNL_ADSP_REG_ADSPCS,
				    CNL_ADSPCS_CPA(core_mask),
				    CNL_ADSPCS_CPA(core_mask),
				    CNL_DSP_PU_TO,
				    "Power up");
}

__attribute__((used)) static int cnl_dsp_core_power_down(struct sst_dsp *ctx, unsigned int core_mask)
{
	/* update bits */
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPCS,
					CNL_ADSPCS_SPA(core_mask), 0);

	/* poll with timeout to check if operation successful */
	return sst_dsp_register_poll(ctx,
			CNL_ADSP_REG_ADSPCS,
			CNL_ADSPCS_CPA(core_mask),
			0,
			CNL_DSP_PD_TO,
			"Power down");
}

int cnl_dsp_enable_core(struct sst_dsp *ctx, unsigned int core_mask)
{
	int ret;

	/* power up */
	ret = cnl_dsp_core_power_up(ctx, core_mask);
	if (ret < 0) {
		dev_dbg(ctx->dev, "DSP core mask %#x power up failed",
			core_mask);
		return ret;
	}

	return cnl_dsp_start_core(ctx, core_mask);
}

int cnl_dsp_disable_core(struct sst_dsp *ctx, unsigned int core_mask)
{
	int ret;

	ret = cnl_dsp_reset_core(ctx, core_mask);
	if (ret < 0) {
		dev_err(ctx->dev, "DSP core mask %#x reset failed\n",
			core_mask);
		return ret;
	}

	/* power down core*/
	ret = cnl_dsp_core_power_down(ctx, core_mask);
	if (ret < 0) {
		dev_err(ctx->dev, "DSP core mask %#x power down failed\n",
			core_mask);
		return ret;
	}

	if (is_cnl_dsp_core_enable(ctx, core_mask)) {
		dev_err(ctx->dev, "DSP core mask %#x disable failed\n",
			core_mask);
		ret = -EIO;
	}

	return ret;
}

irqreturn_t cnl_dsp_sst_interrupt(int irq, void *dev_id)
{
	struct sst_dsp *ctx = dev_id;
	u32 val;
	irqreturn_t ret = IRQ_NONE;

	spin_lock(&ctx->spinlock);

	val = sst_dsp_shim_read_unlocked(ctx, CNL_ADSP_REG_ADSPIS);
	ctx->intr_status = val;

	if (val == 0xffffffff) {
		spin_unlock(&ctx->spinlock);
		return IRQ_NONE;
	}

	if (val & CNL_ADSPIS_IPC) {
		cnl_ipc_int_disable(ctx);
		ret = IRQ_WAKE_THREAD;
	}

	spin_unlock(&ctx->spinlock);

	return ret;
}

void cnl_dsp_free(struct sst_dsp *dsp)
{
	cnl_ipc_int_disable(dsp);

	free_irq(dsp->irq, dsp);
	cnl_ipc_op_int_disable(dsp);
	cnl_dsp_disable_core(dsp, SKL_DSP_CORE0_MASK);
}

void cnl_ipc_int_enable(struct sst_dsp *ctx)
{
	sst_dsp_shim_update_bits(ctx, CNL_ADSP_REG_ADSPIC,
				 CNL_ADSPIC_IPC, CNL_ADSPIC_IPC);
}

void cnl_ipc_int_disable(struct sst_dsp *ctx)
{
	sst_dsp_shim_update_bits_unlocked(ctx, CNL_ADSP_REG_ADSPIC,
					  CNL_ADSPIC_IPC, 0);
}

void cnl_ipc_op_int_enable(struct sst_dsp *ctx)
{
	/* enable IPC DONE interrupt */
	sst_dsp_shim_update_bits(ctx, CNL_ADSP_REG_HIPCCTL,
				 CNL_ADSP_REG_HIPCCTL_DONE,
				 CNL_ADSP_REG_HIPCCTL_DONE);

	/* enable IPC BUSY interrupt */
	sst_dsp_shim_update_bits(ctx, CNL_ADSP_REG_HIPCCTL,
				 CNL_ADSP_REG_HIPCCTL_BUSY,
				 CNL_ADSP_REG_HIPCCTL_BUSY);
}

void cnl_ipc_op_int_disable(struct sst_dsp *ctx)
{
	/* disable IPC DONE interrupt */
	sst_dsp_shim_update_bits(ctx, CNL_ADSP_REG_HIPCCTL,
				 CNL_ADSP_REG_HIPCCTL_DONE, 0);

	/* disable IPC BUSY interrupt */
	sst_dsp_shim_update_bits(ctx, CNL_ADSP_REG_HIPCCTL,
				 CNL_ADSP_REG_HIPCCTL_BUSY, 0);
}

bool cnl_ipc_int_status(struct sst_dsp *ctx)
{
	return sst_dsp_shim_read_unlocked(ctx, CNL_ADSP_REG_ADSPIS) &
							CNL_ADSPIS_IPC;
}

void cnl_ipc_free(struct sst_generic_ipc *ipc)
{
	cnl_ipc_op_int_disable(ipc->dsp);
	sst_ipc_fini(ipc);
}

