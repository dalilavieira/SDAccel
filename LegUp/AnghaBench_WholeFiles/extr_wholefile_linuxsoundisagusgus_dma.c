#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int dma1; int dma_flags; int dma_shared; void (* interrupt_handler_dma_write ) (struct snd_gus_card*) ;struct snd_gf1_dma_block* dma_data_pcm_last; struct snd_gf1_dma_block* dma_data_pcm; struct snd_gf1_dma_block* dma_data_synth_last; struct snd_gf1_dma_block* dma_data_synth; int /*<<< orphan*/  (* dma_ack ) (struct snd_gus_card*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  dma_private_data; scalar_t__ enh_mode; } ;
struct snd_gus_card {int /*<<< orphan*/  dma_lock; TYPE_1__ gf1; int /*<<< orphan*/  dma_mutex; int /*<<< orphan*/  reg_lock; } ;
struct snd_gf1_dma_block {unsigned int addr; unsigned long buf_addr; unsigned int count; scalar_t__ cmd; struct snd_gf1_dma_block* next; scalar_t__ buffer; int /*<<< orphan*/  private_data; int /*<<< orphan*/  (* ack ) (struct snd_gus_card*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_MODE_READ ; 
 int /*<<< orphan*/  DMA_MODE_WRITE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned char SNDRV_GF1_DMA_16BIT ; 
 unsigned short SNDRV_GF1_DMA_ENABLE ; 
 unsigned char SNDRV_GF1_DMA_READ ; 
 int SNDRV_GF1_DMA_TRIGGER ; 
 unsigned char SNDRV_GF1_DMA_WIDTH16 ; 
 int /*<<< orphan*/  SNDRV_GF1_GB_DRAM_DMA_CONTROL ; 
 int /*<<< orphan*/  SNDRV_GF1_GB_DRAM_DMA_HIGH ; 
 int /*<<< orphan*/  SNDRV_GF1_GW_DRAM_DMA_LOW ; 
 int /*<<< orphan*/  SNDRV_GF1_HANDLER_DMA_WRITE ; 
 int /*<<< orphan*/  kfree (struct snd_gf1_dma_block*) ; 
 struct snd_gf1_dma_block* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_dma_disable (int) ; 
 int /*<<< orphan*/  snd_dma_program (int,unsigned long,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_gf1_look8 (struct snd_gus_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_gf1_set_default_handlers (struct snd_gus_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_gf1_write16 (struct snd_gus_card*,int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  snd_gf1_write8 (struct snd_gus_card*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  snd_printd (char*,unsigned int) ; 
 int /*<<< orphan*/  snd_printdd (char*,long,...) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct snd_gus_card*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void snd_gf1_dma_ack(struct snd_gus_card * gus)
{
	unsigned long flags;

	spin_lock_irqsave(&gus->reg_lock, flags);
	snd_gf1_write8(gus, SNDRV_GF1_GB_DRAM_DMA_CONTROL, 0x00);
	snd_gf1_look8(gus, SNDRV_GF1_GB_DRAM_DMA_CONTROL);
	spin_unlock_irqrestore(&gus->reg_lock, flags);
}

__attribute__((used)) static void snd_gf1_dma_program(struct snd_gus_card * gus,
				unsigned int addr,
				unsigned long buf_addr,
				unsigned int count,
				unsigned int cmd)
{
	unsigned long flags;
	unsigned int address;
	unsigned char dma_cmd;
	unsigned int address_high;

	snd_printdd("dma_transfer: addr=0x%x, buf=0x%lx, count=0x%x\n",
		    addr, buf_addr, count);

	if (gus->gf1.dma1 > 3) {
		if (gus->gf1.enh_mode) {
			address = addr >> 1;
		} else {
			if (addr & 0x1f) {
				snd_printd("snd_gf1_dma_transfer: unaligned address (0x%x)?\n", addr);
				return;
			}
			address = (addr & 0x000c0000) | ((addr & 0x0003ffff) >> 1);
		}
	} else {
		address = addr;
	}

	dma_cmd = SNDRV_GF1_DMA_ENABLE | (unsigned short) cmd;
#if 0
	dma_cmd |= 0x08;
#endif
	if (dma_cmd & SNDRV_GF1_DMA_16BIT) {
		count++;
		count &= ~1;	/* align */
	}
	if (gus->gf1.dma1 > 3) {
		dma_cmd |= SNDRV_GF1_DMA_WIDTH16;
		count++;
		count &= ~1;	/* align */
	}
	snd_gf1_dma_ack(gus);
	snd_dma_program(gus->gf1.dma1, buf_addr, count, dma_cmd & SNDRV_GF1_DMA_READ ? DMA_MODE_READ : DMA_MODE_WRITE);
#if 0
	snd_printk(KERN_DEBUG "address = 0x%x, count = 0x%x, dma_cmd = 0x%x\n",
		   address << 1, count, dma_cmd);
#endif
	spin_lock_irqsave(&gus->reg_lock, flags);
	if (gus->gf1.enh_mode) {
		address_high = ((address >> 16) & 0x000000f0) | (address & 0x0000000f);
		snd_gf1_write16(gus, SNDRV_GF1_GW_DRAM_DMA_LOW, (unsigned short) (address >> 4));
		snd_gf1_write8(gus, SNDRV_GF1_GB_DRAM_DMA_HIGH, (unsigned char) address_high);
	} else
		snd_gf1_write16(gus, SNDRV_GF1_GW_DRAM_DMA_LOW, (unsigned short) (address >> 4));
	snd_gf1_write8(gus, SNDRV_GF1_GB_DRAM_DMA_CONTROL, dma_cmd);
	spin_unlock_irqrestore(&gus->reg_lock, flags);
}

__attribute__((used)) static struct snd_gf1_dma_block *snd_gf1_dma_next_block(struct snd_gus_card * gus)
{
	struct snd_gf1_dma_block *block;

	/* PCM block have bigger priority than synthesizer one */
	if (gus->gf1.dma_data_pcm) {
		block = gus->gf1.dma_data_pcm;
		if (gus->gf1.dma_data_pcm_last == block) {
			gus->gf1.dma_data_pcm =
			gus->gf1.dma_data_pcm_last = NULL;
		} else {
			gus->gf1.dma_data_pcm = block->next;
		}
	} else if (gus->gf1.dma_data_synth) {
		block = gus->gf1.dma_data_synth;
		if (gus->gf1.dma_data_synth_last == block) {
			gus->gf1.dma_data_synth =
			gus->gf1.dma_data_synth_last = NULL;
		} else {
			gus->gf1.dma_data_synth = block->next;
		}
	} else {
		block = NULL;
	}
	if (block) {
		gus->gf1.dma_ack = block->ack;
		gus->gf1.dma_private_data = block->private_data;
	}
	return block;
}

__attribute__((used)) static void snd_gf1_dma_interrupt(struct snd_gus_card * gus)
{
	struct snd_gf1_dma_block *block;

	snd_gf1_dma_ack(gus);
	if (gus->gf1.dma_ack)
		gus->gf1.dma_ack(gus, gus->gf1.dma_private_data);
	spin_lock(&gus->dma_lock);
	if (gus->gf1.dma_data_pcm == NULL &&
	    gus->gf1.dma_data_synth == NULL) {
	    	gus->gf1.dma_ack = NULL;
		gus->gf1.dma_flags &= ~SNDRV_GF1_DMA_TRIGGER;
		spin_unlock(&gus->dma_lock);
		return;
	}
	block = snd_gf1_dma_next_block(gus);
	spin_unlock(&gus->dma_lock);
	snd_gf1_dma_program(gus, block->addr, block->buf_addr, block->count, (unsigned short) block->cmd);
	kfree(block);
#if 0
	snd_printd(KERN_DEBUG "program dma (IRQ) - "
		   "addr = 0x%x, buffer = 0x%lx, count = 0x%x, cmd = 0x%x\n",
		   block->addr, block->buf_addr, block->count, block->cmd);
#endif
}

int snd_gf1_dma_init(struct snd_gus_card * gus)
{
	mutex_lock(&gus->dma_mutex);
	gus->gf1.dma_shared++;
	if (gus->gf1.dma_shared > 1) {
		mutex_unlock(&gus->dma_mutex);
		return 0;
	}
	gus->gf1.interrupt_handler_dma_write = snd_gf1_dma_interrupt;
	gus->gf1.dma_data_pcm = 
	gus->gf1.dma_data_pcm_last =
	gus->gf1.dma_data_synth = 
	gus->gf1.dma_data_synth_last = NULL;
	mutex_unlock(&gus->dma_mutex);
	return 0;
}

int snd_gf1_dma_done(struct snd_gus_card * gus)
{
	struct snd_gf1_dma_block *block;

	mutex_lock(&gus->dma_mutex);
	gus->gf1.dma_shared--;
	if (!gus->gf1.dma_shared) {
		snd_dma_disable(gus->gf1.dma1);
		snd_gf1_set_default_handlers(gus, SNDRV_GF1_HANDLER_DMA_WRITE);
		snd_gf1_dma_ack(gus);
		while ((block = gus->gf1.dma_data_pcm)) {
			gus->gf1.dma_data_pcm = block->next;
			kfree(block);
		}
		while ((block = gus->gf1.dma_data_synth)) {
			gus->gf1.dma_data_synth = block->next;
			kfree(block);
		}
		gus->gf1.dma_data_pcm_last =
		gus->gf1.dma_data_synth_last = NULL;
	}
	mutex_unlock(&gus->dma_mutex);
	return 0;
}

int snd_gf1_dma_transfer_block(struct snd_gus_card * gus,
			       struct snd_gf1_dma_block * __block,
			       int atomic,
			       int synth)
{
	unsigned long flags;
	struct snd_gf1_dma_block *block;

	block = kmalloc(sizeof(*block), atomic ? GFP_ATOMIC : GFP_KERNEL);
	if (!block)
		return -ENOMEM;

	*block = *__block;
	block->next = NULL;

	snd_printdd("addr = 0x%x, buffer = 0x%lx, count = 0x%x, cmd = 0x%x\n",
		    block->addr, (long) block->buffer, block->count,
		    block->cmd);

	snd_printdd("gus->gf1.dma_data_pcm_last = 0x%lx\n",
		    (long)gus->gf1.dma_data_pcm_last);
	snd_printdd("gus->gf1.dma_data_pcm = 0x%lx\n",
		    (long)gus->gf1.dma_data_pcm);

	spin_lock_irqsave(&gus->dma_lock, flags);
	if (synth) {
		if (gus->gf1.dma_data_synth_last) {
			gus->gf1.dma_data_synth_last->next = block;
			gus->gf1.dma_data_synth_last = block;
		} else {
			gus->gf1.dma_data_synth = 
			gus->gf1.dma_data_synth_last = block;
		}
	} else {
		if (gus->gf1.dma_data_pcm_last) {
			gus->gf1.dma_data_pcm_last->next = block;
			gus->gf1.dma_data_pcm_last = block;
		} else {
			gus->gf1.dma_data_pcm = 
			gus->gf1.dma_data_pcm_last = block;
		}
	}
	if (!(gus->gf1.dma_flags & SNDRV_GF1_DMA_TRIGGER)) {
		gus->gf1.dma_flags |= SNDRV_GF1_DMA_TRIGGER;
		block = snd_gf1_dma_next_block(gus);
		spin_unlock_irqrestore(&gus->dma_lock, flags);
		if (block == NULL)
			return 0;
		snd_gf1_dma_program(gus, block->addr, block->buf_addr, block->count, (unsigned short) block->cmd);
		kfree(block);
		return 0;
	}
	spin_unlock_irqrestore(&gus->dma_lock, flags);
	return 0;
}

