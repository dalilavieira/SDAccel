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
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct mtk_sys_cap {void* hia_ver; void* hw_opt; void* hia_opt; } ;
struct mtk_ring {int cmd_dma; int res_dma; void* cmd_base; void* res_base; void* res_next; void* cmd_next; } ;
struct mtk_cryp {scalar_t__* irq; int /*<<< orphan*/ * dev; scalar_t__ clk_cryp; scalar_t__ base; struct mtk_ring** ring; } ;

/* Variables and functions */
 scalar_t__ AIC_ENABLE_CTRL (int) ; 
 scalar_t__ AIC_ENABLE_SET (int) ; 
 scalar_t__ AIC_G_ACK ; 
 scalar_t__ AIC_G_ENABLE_CTRL ; 
 scalar_t__ AIC_G_ENABLE_SET ; 
 scalar_t__ AIC_G_OPTIONS ; 
 scalar_t__ AIC_G_POL_CTRL ; 
 scalar_t__ AIC_G_TYPE_CTRL ; 
 scalar_t__ AIC_G_VERSION ; 
 scalar_t__ AIC_OPTIONS (int) ; 
 scalar_t__ AIC_POL_CTRL (int) ; 
 scalar_t__ AIC_TYPE_CTRL (int) ; 
 scalar_t__ AIC_VERSION (int) ; 
 scalar_t__ CDR_BASE_ADDR_HI (int) ; 
 scalar_t__ CDR_BASE_ADDR_LO (int) ; 
 scalar_t__ CDR_CFG (int) ; 
 scalar_t__ CDR_DESC_SIZE (int) ; 
 scalar_t__ CDR_DMA_CFG (int) ; 
 scalar_t__ CDR_PREP_COUNT (int) ; 
 scalar_t__ CDR_PREP_PNTR (int) ; 
 scalar_t__ CDR_PROC_COUNT (int) ; 
 scalar_t__ CDR_PROC_PNTR (int) ; 
 scalar_t__ CDR_RING_SIZE (int) ; 
 scalar_t__ CDR_STAT (int) ; 
 scalar_t__ DFE_CFG ; 
 scalar_t__ DFE_PRIO_0 ; 
 scalar_t__ DFE_PRIO_1 ; 
 scalar_t__ DFE_PRIO_2 ; 
 scalar_t__ DFE_PRIO_3 ; 
 scalar_t__ DFE_THR_CTRL ; 
 scalar_t__ DFE_THR_STAT ; 
 scalar_t__ DSE_CFG ; 
 scalar_t__ DSE_PRIO_0 ; 
 scalar_t__ DSE_PRIO_1 ; 
 scalar_t__ DSE_PRIO_2 ; 
 scalar_t__ DSE_PRIO_3 ; 
 scalar_t__ DSE_THR_CTRL ; 
 scalar_t__ DSE_THR_STAT ; 
 int EBUSY ; 
 int EINVAL ; 
 scalar_t__ EIP97_MST_CTRL ; 
 scalar_t__ EIP97_OPTIONS ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HIA_MST_CTRL ; 
 scalar_t__ HIA_OPTIONS ; 
 scalar_t__ HIA_VERSION ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int MTK_AIC_G_CLR ; 
 int MTK_AIC_INT_MSK ; 
 int MTK_AIC_VER11 ; 
 int MTK_AIC_VER12 ; 
 int MTK_AIC_VER_MSK ; 
 int MTK_BURST_SIZE (int) ; 
 int MTK_BURST_SIZE_MSK ; 
 int MTK_CDR_STAT_CLR ; 
 int MTK_CMD_FIFO_SIZE (void*) ; 
 int MTK_CNT_RST ; 
 int MTK_DESC_ATP_PRESENT ; 
 int MTK_DESC_FETCH_SIZE (int) ; 
 int MTK_DESC_FETCH_THRESH (int) ; 
 int MTK_DESC_OFF ; 
 int MTK_DESC_OFFSET (int) ; 
 int MTK_DESC_OVL_IRQ_EN ; 
 int MTK_DESC_RING_SZ ; 
 int MTK_DESC_SIZE (int) ; 
 int MTK_DESC_SZ ; 
 int MTK_DFE_MAX_CTRL (int) ; 
 int MTK_DFE_MIN_CTRL (int) ; 
 scalar_t__ MTK_DFSE_IDLE ; 
 int MTK_DFSE_MAX_DATA (int) ; 
 int MTK_DFSE_MIN_DATA (int) ; 
 scalar_t__ MTK_DFSE_RING_ID (int) ; 
 int MTK_DFSE_THR_CTRL_EN ; 
 int MTK_DFSE_THR_CTRL_RESET ; 
 int MTK_HIA_DATA_WIDTH (void*) ; 
 int MTK_HIA_DMA_LENGTH (void*) ; 
 scalar_t__ MTK_HIA_SIGNATURE ; 
 int MTK_IN_BUF_MAX_THRESH (int) ; 
 int MTK_IN_BUF_MIN_THRESH (int) ; 
 scalar_t__ MTK_IN_DBUF_SIZE (void*) ; 
 scalar_t__ MTK_IN_TBUF_SIZE (void*) ; 
 int MTK_IRQ_NUM ; 
 int MTK_OUT_BUF_MAX_THRESH (int) ; 
 int MTK_OUT_BUF_MIN_THRESH (int) ; 
 scalar_t__ MTK_OUT_DBUF_SIZE (void*) ; 
 int MTK_PE_FATAL_ERR ; 
 int MTK_PE_FATAL_ERR_EN ; 
 int MTK_PE_INPUT_DMA_ERR ; 
 int MTK_PE_INPUT_DMA_ERR_EN ; 
 int MTK_PE_INT_OUT_EN ; 
 int MTK_PE_OUTPUT_DMA_ERR ; 
 int MTK_PE_OUTPUT_DMA_ERR_EN ; 
 int MTK_PE_PKT_PORC_ERR ; 
 int MTK_PE_PKT_PORC_ERR_EN ; 
 int MTK_PE_PKT_TIMEOUT ; 
 int MTK_PE_PKT_TIMEOUT_EN ; 
 int MTK_PE_PROC_HELD ; 
 int MTK_PE_TK_LOC_AVL ; 
 int MTK_PE_TK_TIMEOUT_EN ; 
 int MTK_RDR_PROC_MODE ; 
 int MTK_RDR_PROC_THRESH ; 
 int MTK_RDR_STAT_CLR ; 
 int MTK_RES_FIFO_SIZE (void*) ; 
 int MTK_RING_MAX ; 
 scalar_t__ PE_INTERRUPT_CTRL_STAT ; 
 scalar_t__ PE_IN_DBUF_THRESH ; 
 scalar_t__ PE_IN_TBUF_THRESH ; 
 scalar_t__ PE_OUT_BUF_CTRL ; 
 scalar_t__ PE_OUT_DBUF_THRESH ; 
 scalar_t__ PE_OUT_TBUF_THRESH ; 
 scalar_t__ PE_TOKEN_CTRL_STAT ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ RDR_BASE_ADDR_HI (int) ; 
 scalar_t__ RDR_BASE_ADDR_LO (int) ; 
 scalar_t__ RDR_CFG (int) ; 
 scalar_t__ RDR_DESC_SIZE (int) ; 
 scalar_t__ RDR_DMA_CFG (int) ; 
 scalar_t__ RDR_PREP_COUNT (int) ; 
 scalar_t__ RDR_PREP_PNTR (int) ; 
 scalar_t__ RDR_PROC_COUNT (int) ; 
 scalar_t__ RDR_PROC_PNTR (int) ; 
 scalar_t__ RDR_RING_SIZE (int) ; 
 scalar_t__ RDR_STAT (int) ; 
 scalar_t__ RDR_THRESH (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct mtk_cryp* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int,void*,int) ; 
 void* dma_zalloc_coherent (int /*<<< orphan*/ *,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct mtk_ring*) ; 
 struct mtk_ring* kzalloc (int,int /*<<< orphan*/ ) ; 
 int min (int,int) ; 
 int mtk_cipher_alg_register (struct mtk_cryp*) ; 
 int /*<<< orphan*/  mtk_cipher_alg_release (struct mtk_cryp*) ; 
 int mtk_hash_alg_register (struct mtk_cryp*) ; 
 int /*<<< orphan*/  mtk_hash_alg_release (struct mtk_cryp*) ; 
 struct mtk_cryp* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mtk_cryp*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (int /*<<< orphan*/ *) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void mtk_desc_ring_link(struct mtk_cryp *cryp, u32 mask)
{
	/* Assign rings to DFE/DSE thread and enable it */
	writel(MTK_DFSE_THR_CTRL_EN | mask, cryp->base + DFE_THR_CTRL);
	writel(MTK_DFSE_THR_CTRL_EN | mask, cryp->base + DSE_THR_CTRL);
}

__attribute__((used)) static void mtk_dfe_dse_buf_setup(struct mtk_cryp *cryp,
				  struct mtk_sys_cap *cap)
{
	u32 width = MTK_HIA_DATA_WIDTH(cap->hia_opt) + 2;
	u32 len = MTK_HIA_DMA_LENGTH(cap->hia_opt) - 1;
	u32 ipbuf = min((u32)MTK_IN_DBUF_SIZE(cap->hw_opt) + width, len);
	u32 opbuf = min((u32)MTK_OUT_DBUF_SIZE(cap->hw_opt) + width, len);
	u32 itbuf = min((u32)MTK_IN_TBUF_SIZE(cap->hw_opt) + width, len);

	writel(MTK_DFSE_MIN_DATA(ipbuf - 1) |
	       MTK_DFSE_MAX_DATA(ipbuf) |
	       MTK_DFE_MIN_CTRL(itbuf - 1) |
	       MTK_DFE_MAX_CTRL(itbuf),
	       cryp->base + DFE_CFG);

	writel(MTK_DFSE_MIN_DATA(opbuf - 1) |
	       MTK_DFSE_MAX_DATA(opbuf),
	       cryp->base + DSE_CFG);

	writel(MTK_IN_BUF_MIN_THRESH(ipbuf - 1) |
	       MTK_IN_BUF_MAX_THRESH(ipbuf),
	       cryp->base + PE_IN_DBUF_THRESH);

	writel(MTK_IN_BUF_MIN_THRESH(itbuf - 1) |
	       MTK_IN_BUF_MAX_THRESH(itbuf),
	       cryp->base + PE_IN_TBUF_THRESH);

	writel(MTK_OUT_BUF_MIN_THRESH(opbuf - 1) |
	       MTK_OUT_BUF_MAX_THRESH(opbuf),
	       cryp->base + PE_OUT_DBUF_THRESH);

	writel(0, cryp->base + PE_OUT_TBUF_THRESH);
	writel(0, cryp->base + PE_OUT_BUF_CTRL);
}

__attribute__((used)) static int mtk_dfe_dse_state_check(struct mtk_cryp *cryp)
{
	int ret = -EINVAL;
	u32 val;

	/* Check for completion of all DMA transfers */
	val = readl(cryp->base + DFE_THR_STAT);
	if (MTK_DFSE_RING_ID(val) == MTK_DFSE_IDLE) {
		val = readl(cryp->base + DSE_THR_STAT);
		if (MTK_DFSE_RING_ID(val) == MTK_DFSE_IDLE)
			ret = 0;
	}

	if (!ret) {
		/* Take DFE/DSE thread out of reset */
		writel(0, cryp->base + DFE_THR_CTRL);
		writel(0, cryp->base + DSE_THR_CTRL);
	} else {
		return -EBUSY;
	}

	return 0;
}

__attribute__((used)) static int mtk_dfe_dse_reset(struct mtk_cryp *cryp)
{
	int err;

	/* Reset DSE/DFE and correct system priorities for all rings. */
	writel(MTK_DFSE_THR_CTRL_RESET, cryp->base + DFE_THR_CTRL);
	writel(0, cryp->base + DFE_PRIO_0);
	writel(0, cryp->base + DFE_PRIO_1);
	writel(0, cryp->base + DFE_PRIO_2);
	writel(0, cryp->base + DFE_PRIO_3);

	writel(MTK_DFSE_THR_CTRL_RESET, cryp->base + DSE_THR_CTRL);
	writel(0, cryp->base + DSE_PRIO_0);
	writel(0, cryp->base + DSE_PRIO_1);
	writel(0, cryp->base + DSE_PRIO_2);
	writel(0, cryp->base + DSE_PRIO_3);

	err = mtk_dfe_dse_state_check(cryp);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static void mtk_cmd_desc_ring_setup(struct mtk_cryp *cryp,
				    int i, struct mtk_sys_cap *cap)
{
	/* Full descriptor that fits FIFO minus one */
	u32 count =
		((1 << MTK_CMD_FIFO_SIZE(cap->hia_opt)) / MTK_DESC_SZ) - 1;

	/* Temporarily disable external triggering */
	writel(0, cryp->base + CDR_CFG(i));

	/* Clear CDR count */
	writel(MTK_CNT_RST, cryp->base + CDR_PREP_COUNT(i));
	writel(MTK_CNT_RST, cryp->base + CDR_PROC_COUNT(i));

	writel(0, cryp->base + CDR_PREP_PNTR(i));
	writel(0, cryp->base + CDR_PROC_PNTR(i));
	writel(0, cryp->base + CDR_DMA_CFG(i));

	/* Configure CDR host address space */
	writel(0, cryp->base + CDR_BASE_ADDR_HI(i));
	writel(cryp->ring[i]->cmd_dma, cryp->base + CDR_BASE_ADDR_LO(i));

	writel(MTK_DESC_RING_SZ, cryp->base + CDR_RING_SIZE(i));

	/* Clear and disable all CDR interrupts */
	writel(MTK_CDR_STAT_CLR, cryp->base + CDR_STAT(i));

	/*
	 * Set command descriptor offset and enable additional
	 * token present in descriptor.
	 */
	writel(MTK_DESC_SIZE(MTK_DESC_SZ) |
		   MTK_DESC_OFFSET(MTK_DESC_OFF) |
	       MTK_DESC_ATP_PRESENT,
	       cryp->base + CDR_DESC_SIZE(i));

	writel(MTK_DESC_FETCH_SIZE(count * MTK_DESC_OFF) |
		   MTK_DESC_FETCH_THRESH(count * MTK_DESC_SZ),
		   cryp->base + CDR_CFG(i));
}

__attribute__((used)) static void mtk_res_desc_ring_setup(struct mtk_cryp *cryp,
				    int i, struct mtk_sys_cap *cap)
{
	u32 rndup = 2;
	u32 count = ((1 << MTK_RES_FIFO_SIZE(cap->hia_opt)) / rndup) - 1;

	/* Temporarily disable external triggering */
	writel(0, cryp->base + RDR_CFG(i));

	/* Clear RDR count */
	writel(MTK_CNT_RST, cryp->base + RDR_PREP_COUNT(i));
	writel(MTK_CNT_RST, cryp->base + RDR_PROC_COUNT(i));

	writel(0, cryp->base + RDR_PREP_PNTR(i));
	writel(0, cryp->base + RDR_PROC_PNTR(i));
	writel(0, cryp->base + RDR_DMA_CFG(i));

	/* Configure RDR host address space */
	writel(0, cryp->base + RDR_BASE_ADDR_HI(i));
	writel(cryp->ring[i]->res_dma, cryp->base + RDR_BASE_ADDR_LO(i));

	writel(MTK_DESC_RING_SZ, cryp->base + RDR_RING_SIZE(i));
	writel(MTK_RDR_STAT_CLR, cryp->base + RDR_STAT(i));

	/*
	 * RDR manager generates update interrupts on a per-completed-packet,
	 * and the rd_proc_thresh_irq interrupt is fired when proc_pkt_count
	 * for the RDR exceeds the number of packets.
	 */
	writel(MTK_RDR_PROC_THRESH | MTK_RDR_PROC_MODE,
	       cryp->base + RDR_THRESH(i));

	/*
	 * Configure a threshold and time-out value for the processed
	 * result descriptors (or complete packets) that are written to
	 * the RDR.
	 */
	writel(MTK_DESC_SIZE(MTK_DESC_SZ) | MTK_DESC_OFFSET(MTK_DESC_OFF),
	       cryp->base + RDR_DESC_SIZE(i));

	/*
	 * Configure HIA fetch size and fetch threshold that are used to
	 * fetch blocks of multiple descriptors.
	 */
	writel(MTK_DESC_FETCH_SIZE(count * MTK_DESC_OFF) |
	       MTK_DESC_FETCH_THRESH(count * rndup) |
	       MTK_DESC_OVL_IRQ_EN,
		   cryp->base + RDR_CFG(i));
}

__attribute__((used)) static int mtk_packet_engine_setup(struct mtk_cryp *cryp)
{
	struct mtk_sys_cap cap;
	int i, err;
	u32 val;

	cap.hia_ver = readl(cryp->base + HIA_VERSION);
	cap.hia_opt = readl(cryp->base + HIA_OPTIONS);
	cap.hw_opt = readl(cryp->base + EIP97_OPTIONS);

	if (!(((u16)cap.hia_ver) == MTK_HIA_SIGNATURE))
		return -EINVAL;

	/* Configure endianness conversion method for master (DMA) interface */
	writel(0, cryp->base + EIP97_MST_CTRL);

	/* Set HIA burst size */
	val = readl(cryp->base + HIA_MST_CTRL);
	val &= ~MTK_BURST_SIZE_MSK;
	val |= MTK_BURST_SIZE(5);
	writel(val, cryp->base + HIA_MST_CTRL);

	err = mtk_dfe_dse_reset(cryp);
	if (err) {
		dev_err(cryp->dev, "Failed to reset DFE and DSE.\n");
		return err;
	}

	mtk_dfe_dse_buf_setup(cryp, &cap);

	/* Enable the 4 rings for the packet engines. */
	mtk_desc_ring_link(cryp, 0xf);

	for (i = 0; i < MTK_RING_MAX; i++) {
		mtk_cmd_desc_ring_setup(cryp, i, &cap);
		mtk_res_desc_ring_setup(cryp, i, &cap);
	}

	writel(MTK_PE_TK_LOC_AVL | MTK_PE_PROC_HELD | MTK_PE_TK_TIMEOUT_EN,
	       cryp->base + PE_TOKEN_CTRL_STAT);

	/* Clear all pending interrupts */
	writel(MTK_AIC_G_CLR, cryp->base + AIC_G_ACK);
	writel(MTK_PE_INPUT_DMA_ERR | MTK_PE_OUTPUT_DMA_ERR |
	       MTK_PE_PKT_PORC_ERR | MTK_PE_PKT_TIMEOUT |
	       MTK_PE_FATAL_ERR | MTK_PE_INPUT_DMA_ERR_EN |
	       MTK_PE_OUTPUT_DMA_ERR_EN | MTK_PE_PKT_PORC_ERR_EN |
	       MTK_PE_PKT_TIMEOUT_EN | MTK_PE_FATAL_ERR_EN |
	       MTK_PE_INT_OUT_EN,
	       cryp->base + PE_INTERRUPT_CTRL_STAT);

	return 0;
}

__attribute__((used)) static int mtk_aic_cap_check(struct mtk_cryp *cryp, int hw)
{
	u32 val;

	if (hw == MTK_RING_MAX)
		val = readl(cryp->base + AIC_G_VERSION);
	else
		val = readl(cryp->base + AIC_VERSION(hw));

	val &= MTK_AIC_VER_MSK;
	if (val != MTK_AIC_VER11 && val != MTK_AIC_VER12)
		return -ENXIO;

	if (hw == MTK_RING_MAX)
		val = readl(cryp->base + AIC_G_OPTIONS);
	else
		val = readl(cryp->base + AIC_OPTIONS(hw));

	val &= MTK_AIC_INT_MSK;
	if (!val || val > 32)
		return -ENXIO;

	return 0;
}

__attribute__((used)) static int mtk_aic_init(struct mtk_cryp *cryp, int hw)
{
	int err;

	err = mtk_aic_cap_check(cryp, hw);
	if (err)
		return err;

	/* Disable all interrupts and set initial configuration */
	if (hw == MTK_RING_MAX) {
		writel(0, cryp->base + AIC_G_ENABLE_CTRL);
		writel(0, cryp->base + AIC_G_POL_CTRL);
		writel(0, cryp->base + AIC_G_TYPE_CTRL);
		writel(0, cryp->base + AIC_G_ENABLE_SET);
	} else {
		writel(0, cryp->base + AIC_ENABLE_CTRL(hw));
		writel(0, cryp->base + AIC_POL_CTRL(hw));
		writel(0, cryp->base + AIC_TYPE_CTRL(hw));
		writel(0, cryp->base + AIC_ENABLE_SET(hw));
	}

	return 0;
}

__attribute__((used)) static int mtk_accelerator_init(struct mtk_cryp *cryp)
{
	int i, err;

	/* Initialize advanced interrupt controller(AIC) */
	for (i = 0; i < MTK_IRQ_NUM; i++) {
		err = mtk_aic_init(cryp, i);
		if (err) {
			dev_err(cryp->dev, "Failed to initialize AIC.\n");
			return err;
		}
	}

	/* Initialize packet engine */
	err = mtk_packet_engine_setup(cryp);
	if (err) {
		dev_err(cryp->dev, "Failed to configure packet engine.\n");
		return err;
	}

	return 0;
}

__attribute__((used)) static void mtk_desc_dma_free(struct mtk_cryp *cryp)
{
	int i;

	for (i = 0; i < MTK_RING_MAX; i++) {
		dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
				  cryp->ring[i]->res_base,
				  cryp->ring[i]->res_dma);
		dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
				  cryp->ring[i]->cmd_base,
				  cryp->ring[i]->cmd_dma);
		kfree(cryp->ring[i]);
	}
}

__attribute__((used)) static int mtk_desc_ring_alloc(struct mtk_cryp *cryp)
{
	struct mtk_ring **ring = cryp->ring;
	int i, err = ENOMEM;

	for (i = 0; i < MTK_RING_MAX; i++) {
		ring[i] = kzalloc(sizeof(**ring), GFP_KERNEL);
		if (!ring[i])
			goto err_cleanup;

		ring[i]->cmd_base = dma_zalloc_coherent(cryp->dev,
					   MTK_DESC_RING_SZ,
					   &ring[i]->cmd_dma,
					   GFP_KERNEL);
		if (!ring[i]->cmd_base)
			goto err_cleanup;

		ring[i]->res_base = dma_zalloc_coherent(cryp->dev,
					   MTK_DESC_RING_SZ,
					   &ring[i]->res_dma,
					   GFP_KERNEL);
		if (!ring[i]->res_base)
			goto err_cleanup;

		ring[i]->cmd_next = ring[i]->cmd_base;
		ring[i]->res_next = ring[i]->res_base;
	}
	return 0;

err_cleanup:
	for (; i--; ) {
		dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
				  ring[i]->res_base, ring[i]->res_dma);
		dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
				  ring[i]->cmd_base, ring[i]->cmd_dma);
		kfree(ring[i]);
	}
	return err;
}

__attribute__((used)) static int mtk_crypto_probe(struct platform_device *pdev)
{
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	struct mtk_cryp *cryp;
	int i, err;

	cryp = devm_kzalloc(&pdev->dev, sizeof(*cryp), GFP_KERNEL);
	if (!cryp)
		return -ENOMEM;

	cryp->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(cryp->base))
		return PTR_ERR(cryp->base);

	for (i = 0; i < MTK_IRQ_NUM; i++) {
		cryp->irq[i] = platform_get_irq(pdev, i);
		if (cryp->irq[i] < 0) {
			dev_err(cryp->dev, "no IRQ:%d resource info\n", i);
			return cryp->irq[i];
		}
	}

	cryp->clk_cryp = devm_clk_get(&pdev->dev, "cryp");
	if (IS_ERR(cryp->clk_cryp))
		return -EPROBE_DEFER;

	cryp->dev = &pdev->dev;
	pm_runtime_enable(cryp->dev);
	pm_runtime_get_sync(cryp->dev);

	err = clk_prepare_enable(cryp->clk_cryp);
	if (err)
		goto err_clk_cryp;

	/* Allocate four command/result descriptor rings */
	err = mtk_desc_ring_alloc(cryp);
	if (err) {
		dev_err(cryp->dev, "Unable to allocate descriptor rings.\n");
		goto err_resource;
	}

	/* Initialize hardware modules */
	err = mtk_accelerator_init(cryp);
	if (err) {
		dev_err(cryp->dev, "Failed to initialize cryptographic engine.\n");
		goto err_engine;
	}

	err = mtk_cipher_alg_register(cryp);
	if (err) {
		dev_err(cryp->dev, "Unable to register cipher algorithm.\n");
		goto err_cipher;
	}

	err = mtk_hash_alg_register(cryp);
	if (err) {
		dev_err(cryp->dev, "Unable to register hash algorithm.\n");
		goto err_hash;
	}

	platform_set_drvdata(pdev, cryp);
	return 0;

err_hash:
	mtk_cipher_alg_release(cryp);
err_cipher:
	mtk_dfe_dse_reset(cryp);
err_engine:
	mtk_desc_dma_free(cryp);
err_resource:
	clk_disable_unprepare(cryp->clk_cryp);
err_clk_cryp:
	pm_runtime_put_sync(cryp->dev);
	pm_runtime_disable(cryp->dev);

	return err;
}

__attribute__((used)) static int mtk_crypto_remove(struct platform_device *pdev)
{
	struct mtk_cryp *cryp = platform_get_drvdata(pdev);

	mtk_hash_alg_release(cryp);
	mtk_cipher_alg_release(cryp);
	mtk_desc_dma_free(cryp);

	clk_disable_unprepare(cryp->clk_cryp);

	pm_runtime_put_sync(cryp->dev);
	pm_runtime_disable(cryp->dev);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

