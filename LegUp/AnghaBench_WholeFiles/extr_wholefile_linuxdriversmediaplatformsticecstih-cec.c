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
struct stih_cec {int irq_status; scalar_t__ irq; int /*<<< orphan*/  notifier; int /*<<< orphan*/  adap; scalar_t__ clk; scalar_t__ regs; struct device* dev; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
struct cec_msg {int len; int* msg; } ;
struct cec_adapter {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int BIT (int) ; 
 scalar_t__ CEC_ADDR_TABLE ; 
 int CEC_BIT_HPULSE_03MS ; 
 int CEC_BIT_LPULSE_03MS ; 
 scalar_t__ CEC_BIT_PULSE_THRESH ; 
 scalar_t__ CEC_BIT_TOUT_THRESH ; 
 int /*<<< orphan*/  CEC_CAP_DEFAULTS ; 
 scalar_t__ CEC_CLK_DIV ; 
 scalar_t__ CEC_CTRL ; 
 scalar_t__ CEC_DATA_ARRAY_CTRL ; 
 scalar_t__ CEC_DATA_ARRAY_STATUS ; 
 int CEC_DBIT_TOUT_28MS ; 
 int CEC_EN ; 
 int CEC_ERROR_IRQ_EN ; 
 int CEC_IN_FILTER_EN ; 
 scalar_t__ CEC_IRQ_CTRL ; 
 int CEC_LOG_ADDR_INVALID ; 
 int /*<<< orphan*/  CEC_MAX_LOG_ADDRS ; 
 int /*<<< orphan*/  CEC_NAME ; 
 int CEC_RX_ARRAY_EN ; 
 scalar_t__ CEC_RX_DATA_BASE ; 
 int CEC_RX_DONE_IRQ_EN ; 
 int CEC_RX_DONE_STS ; 
 int CEC_RX_EOM_IRQ_EN ; 
 int CEC_RX_ERROR_MAX ; 
 int CEC_RX_ERROR_MIN ; 
 int CEC_RX_RESET_EN ; 
 int CEC_RX_SOM_IRQ_EN ; 
 int CEC_SBIT_TOUT_47MS ; 
 scalar_t__ CEC_STATUS ; 
 int CEC_TX_ACK_GET_STS ; 
 int CEC_TX_ARB_ERROR ; 
 scalar_t__ CEC_TX_ARRAY_CTRL ; 
 int CEC_TX_ARRAY_EN ; 
 int CEC_TX_AUTO_EOM_EN ; 
 int CEC_TX_AUTO_SOM_EN ; 
 scalar_t__ CEC_TX_CTRL ; 
 scalar_t__ CEC_TX_DATA_BASE ; 
 int CEC_TX_DONE_IRQ_EN ; 
 int CEC_TX_DONE_STS ; 
 int CEC_TX_ERROR ; 
 int CEC_TX_START ; 
 int /*<<< orphan*/  CEC_TX_STATUS_ARB_LOST ; 
 int /*<<< orphan*/  CEC_TX_STATUS_ERROR ; 
 int /*<<< orphan*/  CEC_TX_STATUS_NACK ; 
 int /*<<< orphan*/  CEC_TX_STATUS_OK ; 
 int CEC_TX_STOP_ON_NACK ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_allocate_adapter (int /*<<< orphan*/ *,struct stih_cec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_delete_adapter (int /*<<< orphan*/ ) ; 
 struct stih_cec* cec_get_drvdata (struct cec_adapter*) ; 
 int /*<<< orphan*/  cec_notifier_get (struct device*) ; 
 int /*<<< orphan*/  cec_notifier_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_received_msg (int /*<<< orphan*/ ,struct cec_msg*) ; 
 int cec_register_adapter (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  cec_register_cec_notifier (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_transmit_attempt_done (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_unregister_adapter (int /*<<< orphan*/ ) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ devm_clk_get (struct device*,char*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct stih_cec* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct stih_cec*) ; 
 struct platform_device* of_find_device_by_node (struct device_node*) ; 
 struct device_node* of_parse_phandle (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct stih_cec* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stih_cec*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  sti_cec_adap_ops ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int stih_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
	struct stih_cec *cec = cec_get_drvdata(adap);

	if (enable) {
		/* The doc says (input TCLK_PERIOD * CEC_CLK_DIV) = 0.1ms */
		unsigned long clk_freq = clk_get_rate(cec->clk);
		u32 cec_clk_div = clk_freq / 10000;

		writel(cec_clk_div, cec->regs + CEC_CLK_DIV);

		/* Configuration of the durations activating a timeout */
		writel(CEC_SBIT_TOUT_47MS | (CEC_DBIT_TOUT_28MS << 4),
		       cec->regs + CEC_BIT_TOUT_THRESH);

		/* Configuration of the smallest allowed duration for pulses */
		writel(CEC_BIT_LPULSE_03MS | CEC_BIT_HPULSE_03MS,
		       cec->regs + CEC_BIT_PULSE_THRESH);

		/* Minimum received bit period threshold */
		writel(BIT(5) | BIT(7), cec->regs + CEC_TX_CTRL);

		/* Configuration of transceiver data arrays */
		writel(CEC_TX_ARRAY_EN | CEC_RX_ARRAY_EN | CEC_TX_STOP_ON_NACK,
		       cec->regs + CEC_DATA_ARRAY_CTRL);

		/* Configuration of the control bits for CEC Transceiver */
		writel(CEC_IN_FILTER_EN | CEC_EN | CEC_RX_RESET_EN,
		       cec->regs + CEC_CTRL);

		/* Clear logical addresses */
		writel(0, cec->regs + CEC_ADDR_TABLE);

		/* Clear the status register */
		writel(0x0, cec->regs + CEC_STATUS);

		/* Enable the interrupts */
		writel(CEC_TX_DONE_IRQ_EN | CEC_RX_DONE_IRQ_EN |
		       CEC_RX_SOM_IRQ_EN | CEC_RX_EOM_IRQ_EN |
		       CEC_ERROR_IRQ_EN,
		       cec->regs + CEC_IRQ_CTRL);

	} else {
		/* Clear logical addresses */
		writel(0, cec->regs + CEC_ADDR_TABLE);

		/* Clear the status register */
		writel(0x0, cec->regs + CEC_STATUS);

		/* Disable the interrupts */
		writel(0, cec->regs + CEC_IRQ_CTRL);
	}

	return 0;
}

__attribute__((used)) static int stih_cec_adap_log_addr(struct cec_adapter *adap, u8 logical_addr)
{
	struct stih_cec *cec = cec_get_drvdata(adap);
	u32 reg = readl(cec->regs + CEC_ADDR_TABLE);

	reg |= 1 << logical_addr;

	if (logical_addr == CEC_LOG_ADDR_INVALID)
		reg = 0;

	writel(reg, cec->regs + CEC_ADDR_TABLE);

	return 0;
}

__attribute__((used)) static int stih_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,
				  u32 signal_free_time, struct cec_msg *msg)
{
	struct stih_cec *cec = cec_get_drvdata(adap);
	int i;

	/* Copy message into registers */
	for (i = 0; i < msg->len; i++)
		writeb(msg->msg[i], cec->regs + CEC_TX_DATA_BASE + i);

	/*
	 * Start transmission, configure hardware to add start and stop bits
	 * Signal free time is handled by the hardware
	 */
	writel(CEC_TX_AUTO_SOM_EN | CEC_TX_AUTO_EOM_EN | CEC_TX_START |
	       msg->len, cec->regs + CEC_TX_ARRAY_CTRL);

	return 0;
}

__attribute__((used)) static void stih_tx_done(struct stih_cec *cec, u32 status)
{
	if (status & CEC_TX_ERROR) {
		cec_transmit_attempt_done(cec->adap, CEC_TX_STATUS_ERROR);
		return;
	}

	if (status & CEC_TX_ARB_ERROR) {
		cec_transmit_attempt_done(cec->adap, CEC_TX_STATUS_ARB_LOST);
		return;
	}

	if (!(status & CEC_TX_ACK_GET_STS)) {
		cec_transmit_attempt_done(cec->adap, CEC_TX_STATUS_NACK);
		return;
	}

	cec_transmit_attempt_done(cec->adap, CEC_TX_STATUS_OK);
}

__attribute__((used)) static void stih_rx_done(struct stih_cec *cec, u32 status)
{
	struct cec_msg msg = {};
	u8 i;

	if (status & CEC_RX_ERROR_MIN)
		return;

	if (status & CEC_RX_ERROR_MAX)
		return;

	msg.len = readl(cec->regs + CEC_DATA_ARRAY_STATUS) & 0x1f;

	if (!msg.len)
		return;

	if (msg.len > 16)
		msg.len = 16;

	for (i = 0; i < msg.len; i++)
		msg.msg[i] = readl(cec->regs + CEC_RX_DATA_BASE + i);

	cec_received_msg(cec->adap, &msg);
}

__attribute__((used)) static irqreturn_t stih_cec_irq_handler_thread(int irq, void *priv)
{
	struct stih_cec *cec = priv;

	if (cec->irq_status & CEC_TX_DONE_STS)
		stih_tx_done(cec, cec->irq_status);

	if (cec->irq_status & CEC_RX_DONE_STS)
		stih_rx_done(cec, cec->irq_status);

	cec->irq_status = 0;

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t stih_cec_irq_handler(int irq, void *priv)
{
	struct stih_cec *cec = priv;

	cec->irq_status = readl(cec->regs + CEC_STATUS);
	writel(cec->irq_status, cec->regs + CEC_STATUS);

	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static int stih_cec_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct stih_cec *cec;
	struct device_node *np;
	struct platform_device *hdmi_dev;
	int ret;

	cec = devm_kzalloc(dev, sizeof(*cec), GFP_KERNEL);
	if (!cec)
		return -ENOMEM;

	np = of_parse_phandle(pdev->dev.of_node, "hdmi-phandle", 0);

	if (!np) {
		dev_err(&pdev->dev, "Failed to find hdmi node in device tree\n");
		return -ENODEV;
	}

	hdmi_dev = of_find_device_by_node(np);
	if (!hdmi_dev)
		return -EPROBE_DEFER;

	cec->notifier = cec_notifier_get(&hdmi_dev->dev);
	if (!cec->notifier)
		return -ENOMEM;

	cec->dev = dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	cec->regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(cec->regs))
		return PTR_ERR(cec->regs);

	cec->irq = platform_get_irq(pdev, 0);
	if (cec->irq < 0)
		return cec->irq;

	ret = devm_request_threaded_irq(dev, cec->irq, stih_cec_irq_handler,
					stih_cec_irq_handler_thread, 0,
					pdev->name, cec);
	if (ret)
		return ret;

	cec->clk = devm_clk_get(dev, "cec-clk");
	if (IS_ERR(cec->clk)) {
		dev_err(dev, "Cannot get cec clock\n");
		return PTR_ERR(cec->clk);
	}

	cec->adap = cec_allocate_adapter(&sti_cec_adap_ops, cec,
			CEC_NAME, CEC_CAP_DEFAULTS, CEC_MAX_LOG_ADDRS);
	ret = PTR_ERR_OR_ZERO(cec->adap);
	if (ret)
		return ret;

	ret = cec_register_adapter(cec->adap, &pdev->dev);
	if (ret) {
		cec_delete_adapter(cec->adap);
		return ret;
	}

	cec_register_cec_notifier(cec->adap, cec->notifier);

	platform_set_drvdata(pdev, cec);
	return 0;
}

__attribute__((used)) static int stih_cec_remove(struct platform_device *pdev)
{
	struct stih_cec *cec = platform_get_drvdata(pdev);

	cec_unregister_adapter(cec->adap);
	cec_notifier_put(cec->notifier);

	return 0;
}

