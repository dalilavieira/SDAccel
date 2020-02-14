#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ u32 ;
struct mantis_pci {scalar_t__ buf_dma; scalar_t__ risc_dma; scalar_t__ last_block; scalar_t__ busy_block; int /*<<< orphan*/ * buf_cpu; int /*<<< orphan*/  demux; struct mantis_hwconfig* hwconfig; int /*<<< orphan*/ * risc_cpu; int /*<<< orphan*/  pdev; int /*<<< orphan*/  intmask_lock; } ;
struct mantis_hwconfig {scalar_t__ ts_size; } ;

/* Variables and functions */
 int ENOMEM ; 
 size_t MANTIS_BLOCK_BYTES ; 
 scalar_t__ MANTIS_BLOCK_COUNT ; 
 int /*<<< orphan*/  MANTIS_BUF_SIZE ; 
 scalar_t__ MANTIS_DCAP_EN ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_DMA_CTL ; 
 scalar_t__ MANTIS_DMA_TR_BYTES ; 
 scalar_t__ MANTIS_DMA_TR_UNITS ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 scalar_t__ MANTIS_FIFO_EN ; 
 int /*<<< orphan*/  MANTIS_GPIF_ADDR ; 
 scalar_t__ MANTIS_GPIF_HIFRDWRN ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 scalar_t__ MANTIS_INT_RISCEN ; 
 scalar_t__ MANTIS_INT_RISCI ; 
 int /*<<< orphan*/  MANTIS_INT_STAT ; 
 scalar_t__ MANTIS_RISC_EN ; 
 int /*<<< orphan*/  MANTIS_RISC_SIZE ; 
 int /*<<< orphan*/  MANTIS_RISC_START ; 
 int /*<<< orphan*/  RISC_FLUSH (scalar_t__) ; 
 int /*<<< orphan*/  RISC_INSTR (scalar_t__,scalar_t__) ; 
 scalar_t__ RISC_IRQ ; 
 scalar_t__ RISC_JUMP ; 
 scalar_t__ RISC_STATUS (scalar_t__) ; 
 scalar_t__ RISC_WRITE ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 int /*<<< orphan*/  dvb_dmx_swfilter (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  dvb_dmx_swfilter_204 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t) ; 
 scalar_t__ mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (scalar_t__,int /*<<< orphan*/ ) ; 
 void* pci_alloc_consistent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  pci_free_consistent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t) ; 

__attribute__((used)) static inline void mantis_mask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) & ~mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static inline void mantis_unmask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) | mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

int mantis_dma_exit(struct mantis_pci *mantis)
{
	if (mantis->buf_cpu) {
		dprintk(MANTIS_ERROR, 1,
			"DMA=0x%lx cpu=0x%p size=%d",
			(unsigned long) mantis->buf_dma,
			 mantis->buf_cpu,
			 MANTIS_BUF_SIZE);

		pci_free_consistent(mantis->pdev, MANTIS_BUF_SIZE,
				    mantis->buf_cpu, mantis->buf_dma);

		mantis->buf_cpu = NULL;
	}
	if (mantis->risc_cpu) {
		dprintk(MANTIS_ERROR, 1,
			"RISC=0x%lx cpu=0x%p size=%lx",
			(unsigned long) mantis->risc_dma,
			mantis->risc_cpu,
			MANTIS_RISC_SIZE);

		pci_free_consistent(mantis->pdev, MANTIS_RISC_SIZE,
				    mantis->risc_cpu, mantis->risc_dma);

		mantis->risc_cpu = NULL;
	}

	return 0;
}

__attribute__((used)) static inline int mantis_alloc_buffers(struct mantis_pci *mantis)
{
	if (!mantis->buf_cpu) {
		mantis->buf_cpu = pci_alloc_consistent(mantis->pdev,
						       MANTIS_BUF_SIZE,
						       &mantis->buf_dma);
		if (!mantis->buf_cpu) {
			dprintk(MANTIS_ERROR, 1,
				"DMA buffer allocation failed");

			goto err;
		}
		dprintk(MANTIS_ERROR, 1,
			"DMA=0x%lx cpu=0x%p size=%d",
			(unsigned long) mantis->buf_dma,
			mantis->buf_cpu, MANTIS_BUF_SIZE);
	}
	if (!mantis->risc_cpu) {
		mantis->risc_cpu = pci_alloc_consistent(mantis->pdev,
							MANTIS_RISC_SIZE,
							&mantis->risc_dma);

		if (!mantis->risc_cpu) {
			dprintk(MANTIS_ERROR, 1,
				"RISC program allocation failed");

			mantis_dma_exit(mantis);

			goto err;
		}
		dprintk(MANTIS_ERROR, 1,
			"RISC=0x%lx cpu=0x%p size=%lx",
			(unsigned long) mantis->risc_dma,
			mantis->risc_cpu, MANTIS_RISC_SIZE);
	}

	return 0;
err:
	dprintk(MANTIS_ERROR, 1, "Out of memory (?) .....");
	return -ENOMEM;
}

int mantis_dma_init(struct mantis_pci *mantis)
{
	int err;

	dprintk(MANTIS_DEBUG, 1, "Mantis DMA init");
	err = mantis_alloc_buffers(mantis);
	if (err < 0) {
		dprintk(MANTIS_ERROR, 1, "Error allocating DMA buffer");

		/* Stop RISC Engine */
		mmwrite(0, MANTIS_DMA_CTL);

		return err;
	}

	return 0;
}

__attribute__((used)) static inline void mantis_risc_program(struct mantis_pci *mantis)
{
	u32 buf_pos = 0;
	u32 line, step;
	u32 risc_pos;

	dprintk(MANTIS_DEBUG, 1, "Mantis create RISC program");
	RISC_FLUSH(risc_pos);

	dprintk(MANTIS_DEBUG, 1, "risc len lines %u, bytes per line %u, bytes per DMA tr %u",
		MANTIS_BLOCK_COUNT, MANTIS_BLOCK_BYTES, MANTIS_DMA_TR_BYTES);

	for (line = 0; line < MANTIS_BLOCK_COUNT; line++) {
		for (step = 0; step < MANTIS_DMA_TR_UNITS; step++) {
			dprintk(MANTIS_DEBUG, 1, "RISC PROG line=[%d], step=[%d]", line, step);
			if (step == 0) {
				RISC_INSTR(risc_pos, RISC_WRITE	|
					   RISC_IRQ	|
					   RISC_STATUS(line) |
					   MANTIS_DMA_TR_BYTES);
			} else {
				RISC_INSTR(risc_pos, RISC_WRITE | MANTIS_DMA_TR_BYTES);
			}
			RISC_INSTR(risc_pos, mantis->buf_dma + buf_pos);
			buf_pos += MANTIS_DMA_TR_BYTES;
		  }
	}
	RISC_INSTR(risc_pos, RISC_JUMP);
	RISC_INSTR(risc_pos, mantis->risc_dma);
}

void mantis_dma_start(struct mantis_pci *mantis)
{
	dprintk(MANTIS_DEBUG, 1, "Mantis Start DMA engine");

	mantis_risc_program(mantis);
	mmwrite(mantis->risc_dma, MANTIS_RISC_START);
	mmwrite(mmread(MANTIS_GPIF_ADDR) | MANTIS_GPIF_HIFRDWRN, MANTIS_GPIF_ADDR);

	mmwrite(0, MANTIS_DMA_CTL);
	mantis->last_block = mantis->busy_block = 0;

	mantis_unmask_ints(mantis, MANTIS_INT_RISCI);

	mmwrite(MANTIS_FIFO_EN | MANTIS_DCAP_EN
			       | MANTIS_RISC_EN, MANTIS_DMA_CTL);

}

void mantis_dma_stop(struct mantis_pci *mantis)
{
	dprintk(MANTIS_DEBUG, 1, "Mantis Stop DMA engine");

	mmwrite((mmread(MANTIS_GPIF_ADDR) & (~(MANTIS_GPIF_HIFRDWRN))), MANTIS_GPIF_ADDR);

	mmwrite((mmread(MANTIS_DMA_CTL) & ~(MANTIS_FIFO_EN |
					    MANTIS_DCAP_EN |
					    MANTIS_RISC_EN)), MANTIS_DMA_CTL);

	mmwrite(mmread(MANTIS_INT_STAT), MANTIS_INT_STAT);

	mantis_mask_ints(mantis, MANTIS_INT_RISCI | MANTIS_INT_RISCEN);
}

void mantis_dma_xfer(unsigned long data)
{
	struct mantis_pci *mantis = (struct mantis_pci *) data;
	struct mantis_hwconfig *config = mantis->hwconfig;

	while (mantis->last_block != mantis->busy_block) {
		dprintk(MANTIS_DEBUG, 1, "last block=[%d] finished block=[%d]",
			mantis->last_block, mantis->busy_block);

		(config->ts_size ? dvb_dmx_swfilter_204 : dvb_dmx_swfilter)
		(&mantis->demux, &mantis->buf_cpu[mantis->last_block * MANTIS_BLOCK_BYTES], MANTIS_BLOCK_BYTES);
		mantis->last_block = (mantis->last_block + 1) % MANTIS_BLOCK_COUNT;
	}
}

