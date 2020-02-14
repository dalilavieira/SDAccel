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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_8__ {int src_maxburst; int dst_maxburst; int device_fc; int /*<<< orphan*/  direction; void* dst_addr_width; void* src_addr_width; scalar_t__ src_addr; } ;
struct TYPE_7__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  wait; TYPE_4__ config; int /*<<< orphan*/  chan; int /*<<< orphan*/ * virt; int /*<<< orphan*/  phys; } ;
struct tegra_fuse {int /*<<< orphan*/  (* read ) (struct tegra_fuse*,unsigned int) ;TYPE_3__ apbdma; int /*<<< orphan*/  dev; int /*<<< orphan*/  clk; scalar_t__ phys; scalar_t__ base; } ;
struct dma_chan {TYPE_2__* device; } ;
struct dma_async_tx_descriptor {void (* callback ) (void*) ;struct tegra_fuse* callback_param; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  dma_cap_mask_t ;
struct TYPE_6__ {TYPE_1__* dev; } ;
struct TYPE_5__ {struct device_node* of_node; } ;

/* Variables and functions */
 unsigned long DMA_CTRL_ACK ; 
 int /*<<< orphan*/  DMA_DEV_TO_MEM ; 
 unsigned long DMA_PREP_INTERRUPT ; 
 int /*<<< orphan*/  DMA_SLAVE ; 
 void* DMA_SLAVE_BUSWIDTH_4_BYTES ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 scalar_t__ FUSE_BEGIN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ WARN (int,char*) ; 
 int /*<<< orphan*/  __dma_request_channel (int /*<<< orphan*/ *,int (*) (struct dma_chan*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dma_alloc_coherent (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_async_issue_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_cap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_cap_zero (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_release_channel (int /*<<< orphan*/ ) ; 
 struct dma_async_tx_descriptor* dmaengine_prep_slave_single (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,unsigned long) ; 
 int dmaengine_slave_config (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  dmaengine_submit (struct dma_async_tx_descriptor*) ; 
 int /*<<< orphan*/  dmaengine_terminate_all (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_device_is_compatible (struct device_node*,char*) ; 
 int /*<<< orphan*/  readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 tegra20_fuse_read_early(struct tegra_fuse *fuse, unsigned int offset)
{
	return readl_relaxed(fuse->base + FUSE_BEGIN + offset);
}

__attribute__((used)) static void apb_dma_complete(void *args)
{
	struct tegra_fuse *fuse = args;

	complete(&fuse->apbdma.wait);
}

__attribute__((used)) static u32 tegra20_fuse_read(struct tegra_fuse *fuse, unsigned int offset)
{
	unsigned long flags = DMA_PREP_INTERRUPT | DMA_CTRL_ACK;
	struct dma_async_tx_descriptor *dma_desc;
	unsigned long time_left;
	u32 value = 0;
	int err;

	mutex_lock(&fuse->apbdma.lock);

	fuse->apbdma.config.src_addr = fuse->phys + FUSE_BEGIN + offset;

	err = dmaengine_slave_config(fuse->apbdma.chan, &fuse->apbdma.config);
	if (err)
		goto out;

	dma_desc = dmaengine_prep_slave_single(fuse->apbdma.chan,
					       fuse->apbdma.phys,
					       sizeof(u32), DMA_DEV_TO_MEM,
					       flags);
	if (!dma_desc)
		goto out;

	dma_desc->callback = apb_dma_complete;
	dma_desc->callback_param = fuse;

	reinit_completion(&fuse->apbdma.wait);

	clk_prepare_enable(fuse->clk);

	dmaengine_submit(dma_desc);
	dma_async_issue_pending(fuse->apbdma.chan);
	time_left = wait_for_completion_timeout(&fuse->apbdma.wait,
						msecs_to_jiffies(50));

	if (WARN(time_left == 0, "apb read dma timed out"))
		dmaengine_terminate_all(fuse->apbdma.chan);
	else
		value = *fuse->apbdma.virt;

	clk_disable_unprepare(fuse->clk);

out:
	mutex_unlock(&fuse->apbdma.lock);
	return value;
}

__attribute__((used)) static bool dma_filter(struct dma_chan *chan, void *filter_param)
{
	struct device_node *np = chan->device->dev->of_node;

	return of_device_is_compatible(np, "nvidia,tegra20-apbdma");
}

__attribute__((used)) static int tegra20_fuse_probe(struct tegra_fuse *fuse)
{
	dma_cap_mask_t mask;

	dma_cap_zero(mask);
	dma_cap_set(DMA_SLAVE, mask);

	fuse->apbdma.chan = __dma_request_channel(&mask, dma_filter, NULL);
	if (!fuse->apbdma.chan)
		return -EPROBE_DEFER;

	fuse->apbdma.virt = dma_alloc_coherent(fuse->dev, sizeof(u32),
					       &fuse->apbdma.phys,
					       GFP_KERNEL);
	if (!fuse->apbdma.virt) {
		dma_release_channel(fuse->apbdma.chan);
		return -ENOMEM;
	}

	fuse->apbdma.config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	fuse->apbdma.config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	fuse->apbdma.config.src_maxburst = 1;
	fuse->apbdma.config.dst_maxburst = 1;
	fuse->apbdma.config.direction = DMA_DEV_TO_MEM;
	fuse->apbdma.config.device_fc = false;

	init_completion(&fuse->apbdma.wait);
	mutex_init(&fuse->apbdma.lock);
	fuse->read = tegra20_fuse_read;

	return 0;
}

