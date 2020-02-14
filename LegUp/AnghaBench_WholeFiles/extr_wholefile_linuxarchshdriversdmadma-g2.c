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
struct dma_info {struct dma_channel* channels; } ;
struct dma_channel {unsigned int chan; int sar; int dar; int count; int mode; int /*<<< orphan*/  wait_queue; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {TYPE_2__* channel; TYPE_1__* status; } ;
struct TYPE_5__ {int chan_enable; int xfer_enable; int g2_addr; int root_addr; int size; int direction; int ctrl; } ;
struct TYPE_4__ {int status; } ;

/* Variables and functions */
 int EINVAL ; 
 int G2_NR_DMA_CHANNELS ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  flush_icache_range (unsigned long,int) ; 
 int g2_bytes_remaining (int) ; 
 TYPE_3__* g2_dma ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  pr_debug (char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  printk (char*,int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t g2_dma_interrupt(int irq, void *dev_id)
{
	int i;

	for (i = 0; i < G2_NR_DMA_CHANNELS; i++) {
		if (g2_dma->status[i].status & 0x20000000) {
			unsigned int bytes = g2_bytes_remaining(i);

			if (likely(bytes == 0)) {
				struct dma_info *info = dev_id;
				struct dma_channel *chan = info->channels + i;

				wake_up(&chan->wait_queue);

				return IRQ_HANDLED;
			}
		}
	}

	return IRQ_NONE;
}

__attribute__((used)) static int g2_enable_dma(struct dma_channel *chan)
{
	unsigned int chan_nr = chan->chan;

	g2_dma->channel[chan_nr].chan_enable = 1;
	g2_dma->channel[chan_nr].xfer_enable = 1;

	return 0;
}

__attribute__((used)) static int g2_disable_dma(struct dma_channel *chan)
{
	unsigned int chan_nr = chan->chan;

	g2_dma->channel[chan_nr].chan_enable = 0;
	g2_dma->channel[chan_nr].xfer_enable = 0;

	return 0;
}

__attribute__((used)) static int g2_xfer_dma(struct dma_channel *chan)
{
	unsigned int chan_nr = chan->chan;

	if (chan->sar & 31) {
		printk("g2dma: unaligned source 0x%lx\n", chan->sar);
		return -EINVAL;
	}

	if (chan->dar & 31) {
		printk("g2dma: unaligned dest 0x%lx\n", chan->dar);
		return -EINVAL;
	}

	/* Align the count */
	if (chan->count & 31)
		chan->count = (chan->count + (32 - 1)) & ~(32 - 1);

	/* Fixup destination */
	chan->dar += 0xa0800000;

	/* Fixup direction */
	chan->mode = !chan->mode;

	flush_icache_range((unsigned long)chan->sar, chan->count);

	g2_disable_dma(chan);

	g2_dma->channel[chan_nr].g2_addr   = chan->dar & 0x1fffffe0;
	g2_dma->channel[chan_nr].root_addr = chan->sar & 0x1fffffe0;
	g2_dma->channel[chan_nr].size	   = (chan->count & ~31) | 0x80000000;
	g2_dma->channel[chan_nr].direction = chan->mode;

	/*
	 * bit 0 - ???
	 * bit 1 - if set, generate a hardware event on transfer completion
	 * bit 2 - ??? something to do with suspend?
	 */
	g2_dma->channel[chan_nr].ctrl	= 5; /* ?? */

	g2_enable_dma(chan);

	/* debug cruft */
	pr_debug("count, sar, dar, mode, ctrl, chan, xfer: %ld, 0x%08lx, "
		 "0x%08lx, %ld, %ld, %ld, %ld\n",
		 g2_dma->channel[chan_nr].size,
		 g2_dma->channel[chan_nr].root_addr,
		 g2_dma->channel[chan_nr].g2_addr,
		 g2_dma->channel[chan_nr].direction,
		 g2_dma->channel[chan_nr].ctrl,
		 g2_dma->channel[chan_nr].chan_enable,
		 g2_dma->channel[chan_nr].xfer_enable);

	return 0;
}

__attribute__((used)) static int g2_get_residue(struct dma_channel *chan)
{
	return g2_bytes_remaining(chan->chan);
}

