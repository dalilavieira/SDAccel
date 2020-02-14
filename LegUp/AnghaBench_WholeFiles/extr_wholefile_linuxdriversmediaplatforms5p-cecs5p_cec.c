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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct TYPE_2__ {int len; int /*<<< orphan*/  msg; int /*<<< orphan*/  rx_status; } ;
struct s5p_cec_dev {int tx; scalar_t__ rx; scalar_t__ irq; int /*<<< orphan*/ * notifier; int /*<<< orphan*/  adap; int /*<<< orphan*/  reg; int /*<<< orphan*/  pmu; int /*<<< orphan*/  clk; struct device* dev; TYPE_1__ msg; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
struct cec_msg {int /*<<< orphan*/  len; int /*<<< orphan*/  msg; } ;
struct cec_adapter {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int CEC_CAP_DEFAULTS ; 
 int CEC_CAP_NEEDS_HPD ; 
 int /*<<< orphan*/  CEC_NAME ; 
 int /*<<< orphan*/  CEC_RX_STATUS_OK ; 
 int CEC_STATUS_RX_DONE ; 
 int CEC_STATUS_RX_ERROR ; 
 int CEC_STATUS_TX_DONE ; 
 int CEC_STATUS_TX_ERROR ; 
 int CEC_STATUS_TX_NACK ; 
 int CEC_TX_STATUS_ERROR ; 
 int CEC_TX_STATUS_MAX_RETRIES ; 
 int CEC_TX_STATUS_NACK ; 
 int CEC_TX_STATUS_OK ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
#define  STATE_BUSY 131 
#define  STATE_DONE 130 
#define  STATE_ERROR 129 
 scalar_t__ STATE_IDLE ; 
#define  STATE_NACK 128 
 int /*<<< orphan*/  cec_allocate_adapter (int /*<<< orphan*/ *,struct s5p_cec_dev*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  cec_delete_adapter (int /*<<< orphan*/ ) ; 
 struct s5p_cec_dev* cec_get_drvdata (struct cec_adapter*) ; 
 int /*<<< orphan*/ * cec_notifier_get (struct device*) ; 
 int /*<<< orphan*/  cec_notifier_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cec_received_msg (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int cec_register_adapter (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  cec_register_cec_notifier (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cec_transmit_done (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cec_unregister_adapter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,char*) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 struct s5p_cec_dev* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  max (int,scalar_t__) ; 
 struct platform_device* of_find_device_by_node (struct device_node*) ; 
 struct device_node* of_parse_phandle (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 struct s5p_cec_dev* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  s5p_cec_adap_ops ; 
 int /*<<< orphan*/  s5p_cec_copy_packet (struct s5p_cec_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s5p_cec_enable_rx (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_get_rx_buf (struct s5p_cec_dev*,int,int /*<<< orphan*/ ) ; 
 int s5p_cec_get_status (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_mask_rx_interrupts (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_mask_tx_interrupts (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_reset (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_rx_reset (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_set_addr (struct s5p_cec_dev*,scalar_t__) ; 
 int /*<<< orphan*/  s5p_cec_set_divider (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_threshold (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_unmask_rx_interrupts (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_cec_unmask_tx_interrupts (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_clr_pending_rx (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  s5p_clr_pending_tx (struct s5p_cec_dev*) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int s5p_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
	struct s5p_cec_dev *cec = cec_get_drvdata(adap);

	if (enable) {
		pm_runtime_get_sync(cec->dev);

		s5p_cec_reset(cec);

		s5p_cec_set_divider(cec);
		s5p_cec_threshold(cec);

		s5p_cec_unmask_tx_interrupts(cec);
		s5p_cec_unmask_rx_interrupts(cec);
		s5p_cec_enable_rx(cec);
	} else {
		s5p_cec_mask_tx_interrupts(cec);
		s5p_cec_mask_rx_interrupts(cec);
		pm_runtime_disable(cec->dev);
	}

	return 0;
}

__attribute__((used)) static int s5p_cec_adap_log_addr(struct cec_adapter *adap, u8 addr)
{
	struct s5p_cec_dev *cec = cec_get_drvdata(adap);

	s5p_cec_set_addr(cec, addr);
	return 0;
}

__attribute__((used)) static int s5p_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,
				 u32 signal_free_time, struct cec_msg *msg)
{
	struct s5p_cec_dev *cec = cec_get_drvdata(adap);

	/*
	 * Unclear if 0 retries are allowed by the hardware, so have 1 as
	 * the minimum.
	 */
	s5p_cec_copy_packet(cec, msg->msg, msg->len, max(1, attempts - 1));
	return 0;
}

__attribute__((used)) static irqreturn_t s5p_cec_irq_handler(int irq, void *priv)
{
	struct s5p_cec_dev *cec = priv;
	u32 status = 0;

	status = s5p_cec_get_status(cec);

	dev_dbg(cec->dev, "irq received\n");

	if (status & CEC_STATUS_TX_DONE) {
		if (status & CEC_STATUS_TX_NACK) {
			dev_dbg(cec->dev, "CEC_STATUS_TX_NACK set\n");
			cec->tx = STATE_NACK;
		} else if (status & CEC_STATUS_TX_ERROR) {
			dev_dbg(cec->dev, "CEC_STATUS_TX_ERROR set\n");
			cec->tx = STATE_ERROR;
		} else {
			dev_dbg(cec->dev, "CEC_STATUS_TX_DONE\n");
			cec->tx = STATE_DONE;
		}
		s5p_clr_pending_tx(cec);
	}

	if (status & CEC_STATUS_RX_DONE) {
		if (status & CEC_STATUS_RX_ERROR) {
			dev_dbg(cec->dev, "CEC_STATUS_RX_ERROR set\n");
			s5p_cec_rx_reset(cec);
			s5p_cec_enable_rx(cec);
		} else {
			dev_dbg(cec->dev, "CEC_STATUS_RX_DONE set\n");
			if (cec->rx != STATE_IDLE)
				dev_dbg(cec->dev, "Buffer overrun (worker did not process previous message)\n");
			cec->rx = STATE_BUSY;
			cec->msg.len = status >> 24;
			cec->msg.rx_status = CEC_RX_STATUS_OK;
			s5p_cec_get_rx_buf(cec, cec->msg.len,
					cec->msg.msg);
			cec->rx = STATE_DONE;
			s5p_cec_enable_rx(cec);
		}
		/* Clear interrupt pending bit */
		s5p_clr_pending_rx(cec);
	}
	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t s5p_cec_irq_handler_thread(int irq, void *priv)
{
	struct s5p_cec_dev *cec = priv;

	dev_dbg(cec->dev, "irq processing thread\n");
	switch (cec->tx) {
	case STATE_DONE:
		cec_transmit_done(cec->adap, CEC_TX_STATUS_OK, 0, 0, 0, 0);
		cec->tx = STATE_IDLE;
		break;
	case STATE_NACK:
		cec_transmit_done(cec->adap,
			CEC_TX_STATUS_MAX_RETRIES | CEC_TX_STATUS_NACK,
			0, 1, 0, 0);
		cec->tx = STATE_IDLE;
		break;
	case STATE_ERROR:
		cec_transmit_done(cec->adap,
			CEC_TX_STATUS_MAX_RETRIES | CEC_TX_STATUS_ERROR,
			0, 0, 0, 1);
		cec->tx = STATE_IDLE;
		break;
	case STATE_BUSY:
		dev_err(cec->dev, "state set to busy, this should not occur here\n");
		break;
	default:
		break;
	}

	switch (cec->rx) {
	case STATE_DONE:
		cec_received_msg(cec->adap, &cec->msg);
		cec->rx = STATE_IDLE;
		break;
	default:
		break;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int s5p_cec_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np;
	struct platform_device *hdmi_dev;
	struct resource *res;
	struct s5p_cec_dev *cec;
	bool needs_hpd = of_property_read_bool(pdev->dev.of_node, "needs-hpd");
	int ret;

	np = of_parse_phandle(pdev->dev.of_node, "hdmi-phandle", 0);

	if (!np) {
		dev_err(&pdev->dev, "Failed to find hdmi node in device tree\n");
		return -ENODEV;
	}
	hdmi_dev = of_find_device_by_node(np);
	if (hdmi_dev == NULL)
		return -EPROBE_DEFER;

	cec = devm_kzalloc(&pdev->dev, sizeof(*cec), GFP_KERNEL);
	if (!cec)
		return -ENOMEM;

	cec->dev = dev;

	cec->irq = platform_get_irq(pdev, 0);
	if (cec->irq < 0)
		return cec->irq;

	ret = devm_request_threaded_irq(dev, cec->irq, s5p_cec_irq_handler,
		s5p_cec_irq_handler_thread, 0, pdev->name, cec);
	if (ret)
		return ret;

	cec->clk = devm_clk_get(dev, "hdmicec");
	if (IS_ERR(cec->clk))
		return PTR_ERR(cec->clk);

	cec->pmu = syscon_regmap_lookup_by_phandle(dev->of_node,
						 "samsung,syscon-phandle");
	if (IS_ERR(cec->pmu))
		return -EPROBE_DEFER;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	cec->reg = devm_ioremap_resource(dev, res);
	if (IS_ERR(cec->reg))
		return PTR_ERR(cec->reg);

	cec->notifier = cec_notifier_get(&hdmi_dev->dev);
	if (cec->notifier == NULL)
		return -ENOMEM;

	cec->adap = cec_allocate_adapter(&s5p_cec_adap_ops, cec, CEC_NAME,
		CEC_CAP_DEFAULTS | (needs_hpd ? CEC_CAP_NEEDS_HPD : 0), 1);
	ret = PTR_ERR_OR_ZERO(cec->adap);
	if (ret)
		return ret;

	ret = cec_register_adapter(cec->adap, &pdev->dev);
	if (ret)
		goto err_delete_adapter;

	cec_register_cec_notifier(cec->adap, cec->notifier);

	platform_set_drvdata(pdev, cec);
	pm_runtime_enable(dev);

	dev_dbg(dev, "successfully probed\n");
	return 0;

err_delete_adapter:
	cec_delete_adapter(cec->adap);
	return ret;
}

__attribute__((used)) static int s5p_cec_remove(struct platform_device *pdev)
{
	struct s5p_cec_dev *cec = platform_get_drvdata(pdev);

	cec_unregister_adapter(cec->adap);
	cec_notifier_put(cec->notifier);
	pm_runtime_disable(&pdev->dev);
	return 0;
}

