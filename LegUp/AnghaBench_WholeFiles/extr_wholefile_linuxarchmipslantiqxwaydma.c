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
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct ltq_dma_channel {int nr; int phys; int /*<<< orphan*/  desc_base; int /*<<< orphan*/  dev; scalar_t__ desc; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int DMA_2W_BURST ; 
 int DMA_CHAN_ON ; 
 int DMA_CHAN_RST ; 
 int DMA_CLK_DIV4 ; 
 int DMA_DESCPT ; 
 int DMA_ETOP_ENDIANNESS ; 
 int DMA_IRQ_ACK ; 
 int DMA_MAX_CHANNEL ; 
 int DMA_PDEN ; 
 int DMA_POLL ; 
#define  DMA_PORT_DEU 129 
#define  DMA_PORT_ETOP 128 
 int DMA_RESET ; 
 int DMA_TX ; 
 int DMA_WEIGHT ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int LTQ_DESC_NUM ; 
 int LTQ_DESC_SIZE ; 
 int /*<<< orphan*/  LTQ_DMA_CCTRL ; 
 int /*<<< orphan*/  LTQ_DMA_CDBA ; 
 int /*<<< orphan*/  LTQ_DMA_CDLEN ; 
 int /*<<< orphan*/  LTQ_DMA_CIE ; 
 int /*<<< orphan*/  LTQ_DMA_CIS ; 
 int /*<<< orphan*/  LTQ_DMA_CPOLL ; 
 int /*<<< orphan*/  LTQ_DMA_CS ; 
 int /*<<< orphan*/  LTQ_DMA_CTRL ; 
 int /*<<< orphan*/  LTQ_DMA_ID ; 
 int /*<<< orphan*/  LTQ_DMA_IRNEN ; 
 int /*<<< orphan*/  LTQ_DMA_PCTRL ; 
 int /*<<< orphan*/  LTQ_DMA_PS ; 
 int /*<<< orphan*/  clk_enable (struct clk*) ; 
 struct clk* clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,unsigned int,unsigned int,unsigned int) ; 
 struct clk* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dma_zalloc_coherent (int /*<<< orphan*/ ,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_dma_lock ; 
 struct clk* ltq_dma_membase ; 
 int ltq_dma_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_dma_w32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_dma_w32_mask (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wmb () ; 

void
ltq_dma_enable_irq(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32_mask(0, 1 << ch->nr, LTQ_DMA_IRNEN);
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_disable_irq(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32_mask(1 << ch->nr, 0, LTQ_DMA_IRNEN);
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_ack_irq(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32(DMA_IRQ_ACK, LTQ_DMA_CIS);
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_open(struct ltq_dma_channel *ch)
{
	unsigned long flag;

	spin_lock_irqsave(&ltq_dma_lock, flag);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32_mask(0, DMA_CHAN_ON, LTQ_DMA_CCTRL);
	ltq_dma_w32_mask(0, 1 << ch->nr, LTQ_DMA_IRNEN);
	spin_unlock_irqrestore(&ltq_dma_lock, flag);
}

void
ltq_dma_close(struct ltq_dma_channel *ch)
{
	unsigned long flag;

	spin_lock_irqsave(&ltq_dma_lock, flag);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32_mask(DMA_CHAN_ON, 0, LTQ_DMA_CCTRL);
	ltq_dma_w32_mask(1 << ch->nr, 0, LTQ_DMA_IRNEN);
	spin_unlock_irqrestore(&ltq_dma_lock, flag);
}

__attribute__((used)) static void
ltq_dma_alloc(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	ch->desc = 0;
	ch->desc_base = dma_zalloc_coherent(ch->dev,
				LTQ_DESC_NUM * LTQ_DESC_SIZE,
				&ch->phys, GFP_ATOMIC);

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(ch->nr, LTQ_DMA_CS);
	ltq_dma_w32(ch->phys, LTQ_DMA_CDBA);
	ltq_dma_w32(LTQ_DESC_NUM, LTQ_DMA_CDLEN);
	ltq_dma_w32_mask(DMA_CHAN_ON, 0, LTQ_DMA_CCTRL);
	wmb();
	ltq_dma_w32_mask(0, DMA_CHAN_RST, LTQ_DMA_CCTRL);
	while (ltq_dma_r32(LTQ_DMA_CCTRL) & DMA_CHAN_RST)
		;
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_alloc_tx(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	ltq_dma_alloc(ch);

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(DMA_DESCPT, LTQ_DMA_CIE);
	ltq_dma_w32_mask(0, 1 << ch->nr, LTQ_DMA_IRNEN);
	ltq_dma_w32(DMA_WEIGHT | DMA_TX, LTQ_DMA_CCTRL);
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_alloc_rx(struct ltq_dma_channel *ch)
{
	unsigned long flags;

	ltq_dma_alloc(ch);

	spin_lock_irqsave(&ltq_dma_lock, flags);
	ltq_dma_w32(DMA_DESCPT, LTQ_DMA_CIE);
	ltq_dma_w32_mask(0, 1 << ch->nr, LTQ_DMA_IRNEN);
	ltq_dma_w32(DMA_WEIGHT, LTQ_DMA_CCTRL);
	spin_unlock_irqrestore(&ltq_dma_lock, flags);
}

void
ltq_dma_free(struct ltq_dma_channel *ch)
{
	if (!ch->desc_base)
		return;
	ltq_dma_close(ch);
	dma_free_coherent(ch->dev, LTQ_DESC_NUM * LTQ_DESC_SIZE,
		ch->desc_base, ch->phys);
}

void
ltq_dma_init_port(int p)
{
	ltq_dma_w32(p, LTQ_DMA_PS);
	switch (p) {
	case DMA_PORT_ETOP:
		/*
		 * Tell the DMA engine to swap the endianness of data frames and
		 * drop packets if the channel arbitration fails.
		 */
		ltq_dma_w32_mask(0, DMA_ETOP_ENDIANNESS | DMA_PDEN,
			LTQ_DMA_PCTRL);
		break;

	case DMA_PORT_DEU:
		ltq_dma_w32((DMA_2W_BURST << 4) | (DMA_2W_BURST << 2),
			LTQ_DMA_PCTRL);
		break;

	default:
		break;
	}
}

__attribute__((used)) static int
ltq_dma_init(struct platform_device *pdev)
{
	struct clk *clk;
	struct resource *res;
	unsigned id;
	int i;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ltq_dma_membase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ltq_dma_membase))
		panic("Failed to remap dma resource");

	/* power up and reset the dma engine */
	clk = clk_get(&pdev->dev, NULL);
	if (IS_ERR(clk))
		panic("Failed to get dma clock");

	clk_enable(clk);
	ltq_dma_w32_mask(0, DMA_RESET, LTQ_DMA_CTRL);

	/* disable all interrupts */
	ltq_dma_w32(0, LTQ_DMA_IRNEN);

	/* reset/configure each channel */
	for (i = 0; i < DMA_MAX_CHANNEL; i++) {
		ltq_dma_w32(i, LTQ_DMA_CS);
		ltq_dma_w32(DMA_CHAN_RST, LTQ_DMA_CCTRL);
		ltq_dma_w32(DMA_POLL | DMA_CLK_DIV4, LTQ_DMA_CPOLL);
		ltq_dma_w32_mask(DMA_CHAN_ON, 0, LTQ_DMA_CCTRL);
	}

	id = ltq_dma_r32(LTQ_DMA_ID);
	dev_info(&pdev->dev,
		"Init done - hw rev: %X, ports: %d, channels: %d\n",
		id & 0x1f, (id >> 16) & 0xf, id >> 20);

	return 0;
}

