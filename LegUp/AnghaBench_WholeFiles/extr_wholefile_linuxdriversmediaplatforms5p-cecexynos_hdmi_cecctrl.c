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
typedef  int u8 ;
typedef  int u32 ;
struct s5p_cec_dev {int /*<<< orphan*/  dev; scalar_t__ reg; int /*<<< orphan*/  pmu; } ;

/* Variables and functions */
 int CEC_DIV_RATIO ; 
 int CEC_FILTER_THRESHOLD ; 
 char CEC_MESSAGE_BROADCAST ; 
 char CEC_MESSAGE_BROADCAST_MASK ; 
 int /*<<< orphan*/  EXYNOS_HDMI_PHY_CONTROL ; 
 scalar_t__ S5P_CEC_DIVISOR_0 ; 
 scalar_t__ S5P_CEC_DIVISOR_1 ; 
 scalar_t__ S5P_CEC_DIVISOR_2 ; 
 scalar_t__ S5P_CEC_DIVISOR_3 ; 
 scalar_t__ S5P_CEC_IRQ_CLEAR ; 
 scalar_t__ S5P_CEC_IRQ_MASK ; 
 int S5P_CEC_IRQ_RX_DONE ; 
 int S5P_CEC_IRQ_RX_ERROR ; 
 int S5P_CEC_IRQ_TX_DONE ; 
 int S5P_CEC_IRQ_TX_ERROR ; 
 scalar_t__ S5P_CEC_LOGIC_ADDR ; 
 scalar_t__ S5P_CEC_RX_BUFF0 ; 
 scalar_t__ S5P_CEC_RX_CTRL ; 
 int S5P_CEC_RX_CTRL_ENABLE ; 
 int S5P_CEC_RX_CTRL_RESET ; 
 scalar_t__ S5P_CEC_RX_FILTER_CTRL ; 
 scalar_t__ S5P_CEC_RX_FILTER_TH ; 
 scalar_t__ S5P_CEC_STATUS_0 ; 
 scalar_t__ S5P_CEC_STATUS_1 ; 
 scalar_t__ S5P_CEC_STATUS_2 ; 
 scalar_t__ S5P_CEC_STATUS_3 ; 
 scalar_t__ S5P_CEC_TX_BUFF0 ; 
 scalar_t__ S5P_CEC_TX_BYTES ; 
 scalar_t__ S5P_CEC_TX_CTRL ; 
 int S5P_CEC_TX_CTRL_BCAST ; 
 int S5P_CEC_TX_CTRL_RESET ; 
 int S5P_CEC_TX_CTRL_START ; 
 scalar_t__ S5P_CEC_TX_STAT1 ; 
 int S5P_HDMI_FIN ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int readb (scalar_t__) ; 
 scalar_t__ regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 scalar_t__ regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

void s5p_cec_set_divider(struct s5p_cec_dev *cec)
{
	u32 div_ratio, div_val;
	unsigned int reg;

	div_ratio  = S5P_HDMI_FIN / CEC_DIV_RATIO - 1;

	if (regmap_read(cec->pmu, EXYNOS_HDMI_PHY_CONTROL, &reg)) {
		dev_err(cec->dev, "failed to read phy control\n");
		return;
	}

	reg = (reg & ~(0x3FF << 16)) | (div_ratio << 16);

	if (regmap_write(cec->pmu, EXYNOS_HDMI_PHY_CONTROL, reg)) {
		dev_err(cec->dev, "failed to write phy control\n");
		return;
	}

	div_val = CEC_DIV_RATIO * 0.00005 - 1;

	writeb(0x0, cec->reg + S5P_CEC_DIVISOR_3);
	writeb(0x0, cec->reg + S5P_CEC_DIVISOR_2);
	writeb(0x0, cec->reg + S5P_CEC_DIVISOR_1);
	writeb(div_val, cec->reg + S5P_CEC_DIVISOR_0);
}

void s5p_cec_enable_rx(struct s5p_cec_dev *cec)
{
	u8 reg;

	reg = readb(cec->reg + S5P_CEC_RX_CTRL);
	reg |= S5P_CEC_RX_CTRL_ENABLE;
	writeb(reg, cec->reg + S5P_CEC_RX_CTRL);
}

void s5p_cec_mask_rx_interrupts(struct s5p_cec_dev *cec)
{
	u8 reg;

	reg = readb(cec->reg + S5P_CEC_IRQ_MASK);
	reg |= S5P_CEC_IRQ_RX_DONE;
	reg |= S5P_CEC_IRQ_RX_ERROR;
	writeb(reg, cec->reg + S5P_CEC_IRQ_MASK);
}

void s5p_cec_unmask_rx_interrupts(struct s5p_cec_dev *cec)
{
	u8 reg;

	reg = readb(cec->reg + S5P_CEC_IRQ_MASK);
	reg &= ~S5P_CEC_IRQ_RX_DONE;
	reg &= ~S5P_CEC_IRQ_RX_ERROR;
	writeb(reg, cec->reg + S5P_CEC_IRQ_MASK);
}

void s5p_cec_mask_tx_interrupts(struct s5p_cec_dev *cec)
{
	u8 reg;

	reg = readb(cec->reg + S5P_CEC_IRQ_MASK);
	reg |= S5P_CEC_IRQ_TX_DONE;
	reg |= S5P_CEC_IRQ_TX_ERROR;
	writeb(reg, cec->reg + S5P_CEC_IRQ_MASK);
}

void s5p_cec_unmask_tx_interrupts(struct s5p_cec_dev *cec)
{
	u8 reg;

	reg = readb(cec->reg + S5P_CEC_IRQ_MASK);
	reg &= ~S5P_CEC_IRQ_TX_DONE;
	reg &= ~S5P_CEC_IRQ_TX_ERROR;
	writeb(reg, cec->reg + S5P_CEC_IRQ_MASK);
}

void s5p_cec_reset(struct s5p_cec_dev *cec)
{
	u8 reg;

	writeb(S5P_CEC_RX_CTRL_RESET, cec->reg + S5P_CEC_RX_CTRL);
	writeb(S5P_CEC_TX_CTRL_RESET, cec->reg + S5P_CEC_TX_CTRL);

	reg = readb(cec->reg + 0xc4);
	reg &= ~0x1;
	writeb(reg, cec->reg + 0xc4);
}

void s5p_cec_tx_reset(struct s5p_cec_dev *cec)
{
	writeb(S5P_CEC_TX_CTRL_RESET, cec->reg + S5P_CEC_TX_CTRL);
}

void s5p_cec_rx_reset(struct s5p_cec_dev *cec)
{
	u8 reg;

	writeb(S5P_CEC_RX_CTRL_RESET, cec->reg + S5P_CEC_RX_CTRL);

	reg = readb(cec->reg + 0xc4);
	reg &= ~0x1;
	writeb(reg, cec->reg + 0xc4);
}

void s5p_cec_threshold(struct s5p_cec_dev *cec)
{
	writeb(CEC_FILTER_THRESHOLD, cec->reg + S5P_CEC_RX_FILTER_TH);
	writeb(0, cec->reg + S5P_CEC_RX_FILTER_CTRL);
}

void s5p_cec_copy_packet(struct s5p_cec_dev *cec, char *data,
			 size_t count, u8 retries)
{
	int i = 0;
	u8 reg;

	while (i < count) {
		writeb(data[i], cec->reg + (S5P_CEC_TX_BUFF0 + (i * 4)));
		i++;
	}

	writeb(count, cec->reg + S5P_CEC_TX_BYTES);
	reg = readb(cec->reg + S5P_CEC_TX_CTRL);
	reg |= S5P_CEC_TX_CTRL_START;
	reg &= ~0x70;
	reg |= retries << 4;

	if ((data[0] & CEC_MESSAGE_BROADCAST_MASK) == CEC_MESSAGE_BROADCAST) {
		dev_dbg(cec->dev, "Broadcast");
		reg |= S5P_CEC_TX_CTRL_BCAST;
	} else {
		dev_dbg(cec->dev, "No Broadcast");
		reg &= ~S5P_CEC_TX_CTRL_BCAST;
	}

	writeb(reg, cec->reg + S5P_CEC_TX_CTRL);
	dev_dbg(cec->dev, "cec-tx: cec count (%zu): %*ph", count,
		(int)count, data);
}

void s5p_cec_set_addr(struct s5p_cec_dev *cec, u32 addr)
{
	writeb(addr & 0x0F, cec->reg + S5P_CEC_LOGIC_ADDR);
}

u32 s5p_cec_get_status(struct s5p_cec_dev *cec)
{
	u32 status = 0;

	status = readb(cec->reg + S5P_CEC_STATUS_0) & 0xf;
	status |= (readb(cec->reg + S5P_CEC_TX_STAT1) & 0xf) << 4;
	status |= readb(cec->reg + S5P_CEC_STATUS_1) << 8;
	status |= readb(cec->reg + S5P_CEC_STATUS_2) << 16;
	status |= readb(cec->reg + S5P_CEC_STATUS_3) << 24;

	dev_dbg(cec->dev, "status = 0x%x!\n", status);

	return status;
}

void s5p_clr_pending_tx(struct s5p_cec_dev *cec)
{
	writeb(S5P_CEC_IRQ_TX_DONE | S5P_CEC_IRQ_TX_ERROR,
	       cec->reg + S5P_CEC_IRQ_CLEAR);
}

void s5p_clr_pending_rx(struct s5p_cec_dev *cec)
{
	writeb(S5P_CEC_IRQ_RX_DONE | S5P_CEC_IRQ_RX_ERROR,
	       cec->reg + S5P_CEC_IRQ_CLEAR);
}

void s5p_cec_get_rx_buf(struct s5p_cec_dev *cec, u32 size, u8 *buffer)
{
	u32 i = 0;
	char debug[40];

	while (i < size) {
		buffer[i] = readb(cec->reg + S5P_CEC_RX_BUFF0 + (i * 4));
		sprintf(debug + i * 2, "%02x ", buffer[i]);
		i++;
	}
	dev_dbg(cec->dev, "cec-rx: cec size(%d): %s", size, debug);
}

