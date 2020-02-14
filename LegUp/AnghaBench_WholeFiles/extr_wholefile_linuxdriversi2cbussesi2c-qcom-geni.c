#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_15__ ;
typedef  struct TYPE_37__   TYPE_14__ ;
typedef  struct TYPE_36__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  val ;
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_40__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct i2c_msg {scalar_t__ len; int addr; int flags; int* buf; } ;
struct i2c_adapter {int dummy; } ;
struct TYPE_38__ {TYPE_2__* dev; scalar_t__ clk; scalar_t__ base; int /*<<< orphan*/  wrapper; } ;
struct TYPE_39__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct TYPE_36__ {int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/ * algo; } ;
struct geni_i2c_dev {scalar_t__ clk_freq_out; int err; scalar_t__ cur_rd; int tx_wm; scalar_t__ cur_wr; int irq; int suspended; TYPE_15__ se; TYPE_11__ adap; int /*<<< orphan*/  lock; int /*<<< orphan*/  done; struct i2c_msg* cur; struct geni_i2c_clk_fld const* clk_fld; } ;
typedef  struct geni_i2c_clk_fld {scalar_t__ clk_freq_out; int clk_div; int t_high_cnt; int t_low_cnt; int t_cycle_cnt; } const geni_i2c_clk_fld ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum geni_se_xfer_mode { ____Placeholder_geni_se_xfer_mode } geni_se_xfer_mode ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_37__ {int err; int msg; } ;

/* Variables and functions */
 unsigned long ABORT_TIMEOUT ; 
 int ARB_LOST ; 
 int ARRAY_SIZE (struct geni_i2c_clk_fld const*) ; 
 int /*<<< orphan*/  BITS_PER_BYTE ; 
 int BUS_PROTO ; 
 int CLK_DIV_SHFT ; 
 int DM_I2C_CB_ERR ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int GENI_ABORT_DONE ; 
 int GENI_ILLEGAL_CMD ; 
 int GENI_OVERRUN ; 
 scalar_t__ GENI_SER_M_CLK_CFG ; 
 int GENI_SE_DMA ; 
 int GENI_SE_FIFO ; 
 int GENI_SE_I2C ; 
 int GENI_TIMEOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GP_IRQ0 ; 
 int HIGH_COUNTER_SHFT ; 
 int /*<<< orphan*/  I2C_AUTO_SUSPEND_DELAY ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  I2C_READ ; 
 int /*<<< orphan*/  I2C_WRITE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ KHZ (int) ; 
 int LOW_COUNTER_SHFT ; 
 int M_CMD_ABORT_EN ; 
 int M_CMD_DONE_EN ; 
 int M_CMD_FAILURE_EN ; 
 int M_CMD_OVERRUN_EN ; 
 int M_GP_IRQ_0_EN ; 
 int M_GP_IRQ_1_EN ; 
 int M_GP_IRQ_3_EN ; 
 int M_GP_IRQ_4_EN ; 
 int M_ILLEGAL_CMD_EN ; 
 int M_RX_FIFO_LAST_EN ; 
 int M_RX_FIFO_WATERMARK_EN ; 
 int M_TX_FIFO_WATERMARK_EN ; 
 int NACK ; 
 int /*<<< orphan*/  PACKING_BYTES_PW ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long RST_TIMEOUT ; 
 int RX_DMA_DONE ; 
 int RX_FIFO_WC_MSK ; 
 int RX_RESET_DONE ; 
 int SER_CLK_EN ; 
 scalar_t__ SE_DMA_RX_FSM_RST ; 
 scalar_t__ SE_DMA_RX_IRQ_CLR ; 
 scalar_t__ SE_DMA_RX_IRQ_STAT ; 
 scalar_t__ SE_DMA_TX_FSM_RST ; 
 scalar_t__ SE_DMA_TX_IRQ_CLR ; 
 scalar_t__ SE_DMA_TX_IRQ_STAT ; 
 scalar_t__ SE_GENI_CLK_SEL ; 
 scalar_t__ SE_GENI_DMA_MODE_EN ; 
 scalar_t__ SE_GENI_IOS ; 
 scalar_t__ SE_GENI_M_CMD0 ; 
 scalar_t__ SE_GENI_M_IRQ_CLEAR ; 
 scalar_t__ SE_GENI_M_IRQ_STATUS ; 
 scalar_t__ SE_GENI_RX_FIFO_STATUS ; 
 scalar_t__ SE_GENI_RX_FIFOn ; 
 scalar_t__ SE_GENI_STATUS ; 
 scalar_t__ SE_GENI_TX_FIFO_STATUS ; 
 scalar_t__ SE_GENI_TX_FIFOn ; 
 scalar_t__ SE_GENI_TX_WATERMARK_REG ; 
 scalar_t__ SE_I2C_RX_TRANS_LEN ; 
 scalar_t__ SE_I2C_SCL_COUNTERS ; 
 scalar_t__ SE_I2C_TX_TRANS_LEN ; 
 int SLV_ADDR_MSK ; 
 int SLV_ADDR_SHFT ; 
 int STOP_STRETCH ; 
 int TX_DMA_DONE ; 
 int TX_RESET_DONE ; 
 unsigned long XFER_TIMEOUT ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*) ; 
 int device_property_read_u32 (TYPE_2__*,char*,scalar_t__*) ; 
 scalar_t__ devm_clk_get (TYPE_2__*,char*) ; 
 scalar_t__ devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 struct geni_i2c_dev* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct geni_i2c_dev*) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int /*<<< orphan*/  geni_i2c_algo ; 
 struct geni_i2c_clk_fld const* geni_i2c_clk_map ; 
 int /*<<< orphan*/  geni_se_abort_m_cmd (TYPE_15__*) ; 
 int /*<<< orphan*/  geni_se_config_packing (TYPE_15__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int geni_se_get_tx_fifo_depth (TYPE_15__*) ; 
 int /*<<< orphan*/  geni_se_init (TYPE_15__*,int,int) ; 
 int geni_se_read_proto (TYPE_15__*) ; 
 int geni_se_resources_off (TYPE_15__*) ; 
 int geni_se_resources_on (TYPE_15__*) ; 
 int geni_se_rx_dma_prep (TYPE_15__*,void*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  geni_se_rx_dma_unprep (TYPE_15__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  geni_se_select_mode (TYPE_15__*,int) ; 
 int /*<<< orphan*/  geni_se_setup_m_cmd (TYPE_15__*,int /*<<< orphan*/ ,int) ; 
 int geni_se_tx_dma_prep (TYPE_15__*,void*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  geni_se_tx_dma_unprep (TYPE_15__*,int /*<<< orphan*/ ,int) ; 
 TYPE_14__* gi2c_log ; 
 int i2c_add_adapter (TYPE_11__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_11__*) ; 
 struct geni_i2c_dev* i2c_get_adapdata (struct i2c_adapter*) ; 
 void* i2c_get_dma_safe_msg_buf (struct i2c_msg*,int) ; 
 int /*<<< orphan*/  i2c_put_dma_safe_msg_buf (void*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_11__*,struct geni_i2c_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 struct geni_i2c_dev* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct geni_i2c_dev*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_2__*) ; 
 int pm_runtime_get_sync (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (TYPE_2__*) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int geni_i2c_clk_map_idx(struct geni_i2c_dev *gi2c)
{
	int i;
	const struct geni_i2c_clk_fld *itr = geni_i2c_clk_map;

	for (i = 0; i < ARRAY_SIZE(geni_i2c_clk_map); i++, itr++) {
		if (itr->clk_freq_out == gi2c->clk_freq_out) {
			gi2c->clk_fld = itr;
			return 0;
		}
	}
	return -EINVAL;
}

__attribute__((used)) static void qcom_geni_i2c_conf(struct geni_i2c_dev *gi2c)
{
	const struct geni_i2c_clk_fld *itr = gi2c->clk_fld;
	u32 val;

	writel_relaxed(0, gi2c->se.base + SE_GENI_CLK_SEL);

	val = (itr->clk_div << CLK_DIV_SHFT) | SER_CLK_EN;
	writel_relaxed(val, gi2c->se.base + GENI_SER_M_CLK_CFG);

	val = itr->t_high_cnt << HIGH_COUNTER_SHFT;
	val |= itr->t_low_cnt << LOW_COUNTER_SHFT;
	val |= itr->t_cycle_cnt;
	writel_relaxed(val, gi2c->se.base + SE_I2C_SCL_COUNTERS);
}

__attribute__((used)) static void geni_i2c_err_misc(struct geni_i2c_dev *gi2c)
{
	u32 m_cmd = readl_relaxed(gi2c->se.base + SE_GENI_M_CMD0);
	u32 m_stat = readl_relaxed(gi2c->se.base + SE_GENI_M_IRQ_STATUS);
	u32 geni_s = readl_relaxed(gi2c->se.base + SE_GENI_STATUS);
	u32 geni_ios = readl_relaxed(gi2c->se.base + SE_GENI_IOS);
	u32 dma = readl_relaxed(gi2c->se.base + SE_GENI_DMA_MODE_EN);
	u32 rx_st, tx_st;

	if (dma) {
		rx_st = readl_relaxed(gi2c->se.base + SE_DMA_RX_IRQ_STAT);
		tx_st = readl_relaxed(gi2c->se.base + SE_DMA_TX_IRQ_STAT);
	} else {
		rx_st = readl_relaxed(gi2c->se.base + SE_GENI_RX_FIFO_STATUS);
		tx_st = readl_relaxed(gi2c->se.base + SE_GENI_TX_FIFO_STATUS);
	}
	dev_dbg(gi2c->se.dev, "DMA:%d tx_stat:0x%x, rx_stat:0x%x, irq-stat:0x%x\n",
		dma, tx_st, rx_st, m_stat);
	dev_dbg(gi2c->se.dev, "m_cmd:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
		m_cmd, geni_s, geni_ios);
}

__attribute__((used)) static void geni_i2c_err(struct geni_i2c_dev *gi2c, int err)
{
	if (!gi2c->err)
		gi2c->err = gi2c_log[err].err;
	if (gi2c->cur)
		dev_dbg(gi2c->se.dev, "len:%d, slv-addr:0x%x, RD/WR:%d\n",
			gi2c->cur->len, gi2c->cur->addr, gi2c->cur->flags);

	if (err != NACK && err != GENI_ABORT_DONE) {
		dev_err(gi2c->se.dev, "%s\n", gi2c_log[err].msg);
		geni_i2c_err_misc(gi2c);
	}
}

__attribute__((used)) static irqreturn_t geni_i2c_irq(int irq, void *dev)
{
	struct geni_i2c_dev *gi2c = dev;
	int j;
	u32 m_stat;
	u32 rx_st;
	u32 dm_tx_st;
	u32 dm_rx_st;
	u32 dma;
	struct i2c_msg *cur;
	unsigned long flags;

	spin_lock_irqsave(&gi2c->lock, flags);
	m_stat = readl_relaxed(gi2c->se.base + SE_GENI_M_IRQ_STATUS);
	rx_st = readl_relaxed(gi2c->se.base + SE_GENI_RX_FIFO_STATUS);
	dm_tx_st = readl_relaxed(gi2c->se.base + SE_DMA_TX_IRQ_STAT);
	dm_rx_st = readl_relaxed(gi2c->se.base + SE_DMA_RX_IRQ_STAT);
	dma = readl_relaxed(gi2c->se.base + SE_GENI_DMA_MODE_EN);
	cur = gi2c->cur;

	if (!cur ||
	    m_stat & (M_CMD_FAILURE_EN | M_CMD_ABORT_EN) ||
	    dm_rx_st & (DM_I2C_CB_ERR)) {
		if (m_stat & M_GP_IRQ_1_EN)
			geni_i2c_err(gi2c, NACK);
		if (m_stat & M_GP_IRQ_3_EN)
			geni_i2c_err(gi2c, BUS_PROTO);
		if (m_stat & M_GP_IRQ_4_EN)
			geni_i2c_err(gi2c, ARB_LOST);
		if (m_stat & M_CMD_OVERRUN_EN)
			geni_i2c_err(gi2c, GENI_OVERRUN);
		if (m_stat & M_ILLEGAL_CMD_EN)
			geni_i2c_err(gi2c, GENI_ILLEGAL_CMD);
		if (m_stat & M_CMD_ABORT_EN)
			geni_i2c_err(gi2c, GENI_ABORT_DONE);
		if (m_stat & M_GP_IRQ_0_EN)
			geni_i2c_err(gi2c, GP_IRQ0);

		/* Disable the TX Watermark interrupt to stop TX */
		if (!dma)
			writel_relaxed(0, gi2c->se.base +
					   SE_GENI_TX_WATERMARK_REG);
		goto irqret;
	}

	if (dma) {
		dev_dbg(gi2c->se.dev, "i2c dma tx:0x%x, dma rx:0x%x\n",
			dm_tx_st, dm_rx_st);
		goto irqret;
	}

	if (cur->flags & I2C_M_RD &&
	    m_stat & (M_RX_FIFO_WATERMARK_EN | M_RX_FIFO_LAST_EN)) {
		u32 rxcnt = rx_st & RX_FIFO_WC_MSK;

		for (j = 0; j < rxcnt; j++) {
			u32 val;
			int p = 0;

			val = readl_relaxed(gi2c->se.base + SE_GENI_RX_FIFOn);
			while (gi2c->cur_rd < cur->len && p < sizeof(val)) {
				cur->buf[gi2c->cur_rd++] = val & 0xff;
				val >>= 8;
				p++;
			}
			if (gi2c->cur_rd == cur->len)
				break;
		}
	} else if (!(cur->flags & I2C_M_RD) &&
		   m_stat & M_TX_FIFO_WATERMARK_EN) {
		for (j = 0; j < gi2c->tx_wm; j++) {
			u32 temp;
			u32 val = 0;
			int p = 0;

			while (gi2c->cur_wr < cur->len && p < sizeof(val)) {
				temp = cur->buf[gi2c->cur_wr++];
				val |= temp << (p * 8);
				p++;
			}
			writel_relaxed(val, gi2c->se.base + SE_GENI_TX_FIFOn);
			/* TX Complete, Disable the TX Watermark interrupt */
			if (gi2c->cur_wr == cur->len) {
				writel_relaxed(0, gi2c->se.base +
						SE_GENI_TX_WATERMARK_REG);
				break;
			}
		}
	}
irqret:
	if (m_stat)
		writel_relaxed(m_stat, gi2c->se.base + SE_GENI_M_IRQ_CLEAR);

	if (dma) {
		if (dm_tx_st)
			writel_relaxed(dm_tx_st, gi2c->se.base +
						SE_DMA_TX_IRQ_CLR);
		if (dm_rx_st)
			writel_relaxed(dm_rx_st, gi2c->se.base +
						SE_DMA_RX_IRQ_CLR);
	}
	/* if this is err with done-bit not set, handle that through timeout. */
	if (m_stat & M_CMD_DONE_EN || m_stat & M_CMD_ABORT_EN)
		complete(&gi2c->done);
	else if (dm_tx_st & TX_DMA_DONE || dm_tx_st & TX_RESET_DONE)
		complete(&gi2c->done);
	else if (dm_rx_st & RX_DMA_DONE || dm_rx_st & RX_RESET_DONE)
		complete(&gi2c->done);

	spin_unlock_irqrestore(&gi2c->lock, flags);
	return IRQ_HANDLED;
}

__attribute__((used)) static void geni_i2c_abort_xfer(struct geni_i2c_dev *gi2c)
{
	u32 val;
	unsigned long time_left = ABORT_TIMEOUT;
	unsigned long flags;

	spin_lock_irqsave(&gi2c->lock, flags);
	geni_i2c_err(gi2c, GENI_TIMEOUT);
	gi2c->cur = NULL;
	geni_se_abort_m_cmd(&gi2c->se);
	spin_unlock_irqrestore(&gi2c->lock, flags);
	do {
		time_left = wait_for_completion_timeout(&gi2c->done, time_left);
		val = readl_relaxed(gi2c->se.base + SE_GENI_M_IRQ_STATUS);
	} while (!(val & M_CMD_ABORT_EN) && time_left);

	if (!(val & M_CMD_ABORT_EN))
		dev_err(gi2c->se.dev, "Timeout abort_m_cmd\n");
}

__attribute__((used)) static void geni_i2c_rx_fsm_rst(struct geni_i2c_dev *gi2c)
{
	u32 val;
	unsigned long time_left = RST_TIMEOUT;

	writel_relaxed(1, gi2c->se.base + SE_DMA_RX_FSM_RST);
	do {
		time_left = wait_for_completion_timeout(&gi2c->done, time_left);
		val = readl_relaxed(gi2c->se.base + SE_DMA_RX_IRQ_STAT);
	} while (!(val & RX_RESET_DONE) && time_left);

	if (!(val & RX_RESET_DONE))
		dev_err(gi2c->se.dev, "Timeout resetting RX_FSM\n");
}

__attribute__((used)) static void geni_i2c_tx_fsm_rst(struct geni_i2c_dev *gi2c)
{
	u32 val;
	unsigned long time_left = RST_TIMEOUT;

	writel_relaxed(1, gi2c->se.base + SE_DMA_TX_FSM_RST);
	do {
		time_left = wait_for_completion_timeout(&gi2c->done, time_left);
		val = readl_relaxed(gi2c->se.base + SE_DMA_TX_IRQ_STAT);
	} while (!(val & TX_RESET_DONE) && time_left);

	if (!(val & TX_RESET_DONE))
		dev_err(gi2c->se.dev, "Timeout resetting TX_FSM\n");
}

__attribute__((used)) static int geni_i2c_rx_one_msg(struct geni_i2c_dev *gi2c, struct i2c_msg *msg,
				u32 m_param)
{
	dma_addr_t rx_dma;
	enum geni_se_xfer_mode mode;
	unsigned long time_left = XFER_TIMEOUT;
	void *dma_buf;

	gi2c->cur = msg;
	mode = GENI_SE_FIFO;
	dma_buf = i2c_get_dma_safe_msg_buf(msg, 32);
	if (dma_buf)
		mode = GENI_SE_DMA;

	geni_se_select_mode(&gi2c->se, mode);
	writel_relaxed(msg->len, gi2c->se.base + SE_I2C_RX_TRANS_LEN);
	geni_se_setup_m_cmd(&gi2c->se, I2C_READ, m_param);
	if (mode == GENI_SE_DMA) {
		int ret;

		ret = geni_se_rx_dma_prep(&gi2c->se, dma_buf, msg->len,
								&rx_dma);
		if (ret) {
			mode = GENI_SE_FIFO;
			geni_se_select_mode(&gi2c->se, mode);
			i2c_put_dma_safe_msg_buf(dma_buf, msg, false);
		}
	}

	time_left = wait_for_completion_timeout(&gi2c->done, XFER_TIMEOUT);
	if (!time_left)
		geni_i2c_abort_xfer(gi2c);

	gi2c->cur_rd = 0;
	if (mode == GENI_SE_DMA) {
		if (gi2c->err)
			geni_i2c_rx_fsm_rst(gi2c);
		geni_se_rx_dma_unprep(&gi2c->se, rx_dma, msg->len);
		i2c_put_dma_safe_msg_buf(dma_buf, msg, !gi2c->err);
	}
	return gi2c->err;
}

__attribute__((used)) static int geni_i2c_tx_one_msg(struct geni_i2c_dev *gi2c, struct i2c_msg *msg,
				u32 m_param)
{
	dma_addr_t tx_dma;
	enum geni_se_xfer_mode mode;
	unsigned long time_left;
	void *dma_buf;

	gi2c->cur = msg;
	mode = GENI_SE_FIFO;
	dma_buf = i2c_get_dma_safe_msg_buf(msg, 32);
	if (dma_buf)
		mode = GENI_SE_DMA;

	geni_se_select_mode(&gi2c->se, mode);
	writel_relaxed(msg->len, gi2c->se.base + SE_I2C_TX_TRANS_LEN);
	geni_se_setup_m_cmd(&gi2c->se, I2C_WRITE, m_param);
	if (mode == GENI_SE_DMA) {
		int ret;

		ret = geni_se_tx_dma_prep(&gi2c->se, dma_buf, msg->len,
								&tx_dma);
		if (ret) {
			mode = GENI_SE_FIFO;
			geni_se_select_mode(&gi2c->se, mode);
			i2c_put_dma_safe_msg_buf(dma_buf, msg, false);
		}
	}

	if (mode == GENI_SE_FIFO) /* Get FIFO IRQ */
		writel_relaxed(1, gi2c->se.base + SE_GENI_TX_WATERMARK_REG);

	time_left = wait_for_completion_timeout(&gi2c->done, XFER_TIMEOUT);
	if (!time_left)
		geni_i2c_abort_xfer(gi2c);

	gi2c->cur_wr = 0;
	if (mode == GENI_SE_DMA) {
		if (gi2c->err)
			geni_i2c_tx_fsm_rst(gi2c);
		geni_se_tx_dma_unprep(&gi2c->se, tx_dma, msg->len);
		i2c_put_dma_safe_msg_buf(dma_buf, msg, !gi2c->err);
	}
	return gi2c->err;
}

__attribute__((used)) static int geni_i2c_xfer(struct i2c_adapter *adap,
			 struct i2c_msg msgs[],
			 int num)
{
	struct geni_i2c_dev *gi2c = i2c_get_adapdata(adap);
	int i, ret;

	gi2c->err = 0;
	reinit_completion(&gi2c->done);
	ret = pm_runtime_get_sync(gi2c->se.dev);
	if (ret < 0) {
		dev_err(gi2c->se.dev, "error turning SE resources:%d\n", ret);
		pm_runtime_put_noidle(gi2c->se.dev);
		/* Set device in suspended since resume failed */
		pm_runtime_set_suspended(gi2c->se.dev);
		return ret;
	}

	qcom_geni_i2c_conf(gi2c);
	for (i = 0; i < num; i++) {
		u32 m_param = i < (num - 1) ? STOP_STRETCH : 0;

		m_param |= ((msgs[i].addr << SLV_ADDR_SHFT) & SLV_ADDR_MSK);

		if (msgs[i].flags & I2C_M_RD)
			ret = geni_i2c_rx_one_msg(gi2c, &msgs[i], m_param);
		else
			ret = geni_i2c_tx_one_msg(gi2c, &msgs[i], m_param);

		if (ret)
			break;
	}
	if (ret == 0)
		ret = num;

	pm_runtime_mark_last_busy(gi2c->se.dev);
	pm_runtime_put_autosuspend(gi2c->se.dev);
	gi2c->cur = NULL;
	gi2c->err = 0;
	return ret;
}

__attribute__((used)) static u32 geni_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}

__attribute__((used)) static int geni_i2c_probe(struct platform_device *pdev)
{
	struct geni_i2c_dev *gi2c;
	struct resource *res;
	u32 proto, tx_depth;
	int ret;

	gi2c = devm_kzalloc(&pdev->dev, sizeof(*gi2c), GFP_KERNEL);
	if (!gi2c)
		return -ENOMEM;

	gi2c->se.dev = &pdev->dev;
	gi2c->se.wrapper = dev_get_drvdata(pdev->dev.parent);
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	gi2c->se.base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(gi2c->se.base))
		return PTR_ERR(gi2c->se.base);

	gi2c->se.clk = devm_clk_get(&pdev->dev, "se");
	if (IS_ERR(gi2c->se.clk)) {
		ret = PTR_ERR(gi2c->se.clk);
		dev_err(&pdev->dev, "Err getting SE Core clk %d\n", ret);
		return ret;
	}

	ret = device_property_read_u32(&pdev->dev, "clock-frequency",
							&gi2c->clk_freq_out);
	if (ret) {
		dev_info(&pdev->dev,
			"Bus frequency not specified, default to 100kHz.\n");
		gi2c->clk_freq_out = KHZ(100);
	}

	gi2c->irq = platform_get_irq(pdev, 0);
	if (gi2c->irq < 0) {
		dev_err(&pdev->dev, "IRQ error for i2c-geni\n");
		return gi2c->irq;
	}

	ret = geni_i2c_clk_map_idx(gi2c);
	if (ret) {
		dev_err(&pdev->dev, "Invalid clk frequency %d Hz: %d\n",
			gi2c->clk_freq_out, ret);
		return ret;
	}

	gi2c->adap.algo = &geni_i2c_algo;
	init_completion(&gi2c->done);
	spin_lock_init(&gi2c->lock);
	platform_set_drvdata(pdev, gi2c);
	ret = devm_request_irq(&pdev->dev, gi2c->irq, geni_i2c_irq,
			       IRQF_TRIGGER_HIGH, "i2c_geni", gi2c);
	if (ret) {
		dev_err(&pdev->dev, "Request_irq failed:%d: err:%d\n",
			gi2c->irq, ret);
		return ret;
	}
	/* Disable the interrupt so that the system can enter low-power mode */
	disable_irq(gi2c->irq);
	i2c_set_adapdata(&gi2c->adap, gi2c);
	gi2c->adap.dev.parent = &pdev->dev;
	gi2c->adap.dev.of_node = pdev->dev.of_node;
	strlcpy(gi2c->adap.name, "Geni-I2C", sizeof(gi2c->adap.name));

	ret = geni_se_resources_on(&gi2c->se);
	if (ret) {
		dev_err(&pdev->dev, "Error turning on resources %d\n", ret);
		return ret;
	}
	proto = geni_se_read_proto(&gi2c->se);
	tx_depth = geni_se_get_tx_fifo_depth(&gi2c->se);
	if (proto != GENI_SE_I2C) {
		dev_err(&pdev->dev, "Invalid proto %d\n", proto);
		geni_se_resources_off(&gi2c->se);
		return -ENXIO;
	}
	gi2c->tx_wm = tx_depth - 1;
	geni_se_init(&gi2c->se, gi2c->tx_wm, tx_depth);
	geni_se_config_packing(&gi2c->se, BITS_PER_BYTE, PACKING_BYTES_PW,
							true, true, true);
	ret = geni_se_resources_off(&gi2c->se);
	if (ret) {
		dev_err(&pdev->dev, "Error turning off resources %d\n", ret);
		return ret;
	}

	dev_dbg(&pdev->dev, "i2c fifo/se-dma mode. fifo depth:%d\n", tx_depth);

	gi2c->suspended = 1;
	pm_runtime_set_suspended(gi2c->se.dev);
	pm_runtime_set_autosuspend_delay(gi2c->se.dev, I2C_AUTO_SUSPEND_DELAY);
	pm_runtime_use_autosuspend(gi2c->se.dev);
	pm_runtime_enable(gi2c->se.dev);

	ret = i2c_add_adapter(&gi2c->adap);
	if (ret) {
		dev_err(&pdev->dev, "Error adding i2c adapter %d\n", ret);
		pm_runtime_disable(gi2c->se.dev);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int geni_i2c_remove(struct platform_device *pdev)
{
	struct geni_i2c_dev *gi2c = platform_get_drvdata(pdev);

	i2c_del_adapter(&gi2c->adap);
	pm_runtime_disable(gi2c->se.dev);
	return 0;
}

