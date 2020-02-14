#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_7__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct dw_hdmi_cec_data {int /*<<< orphan*/  hdmi; TYPE_1__* ops; int /*<<< orphan*/  irq; } ;
struct TYPE_10__ {unsigned int len; scalar_t__* msg; } ;
struct dw_hdmi_cec {int addresses; int tx_done; int rx_done; int /*<<< orphan*/  notify; struct cec_adapter* adap; int /*<<< orphan*/  irq; int /*<<< orphan*/  hdmi; TYPE_1__* ops; TYPE_7__ rx_msg; int /*<<< orphan*/  tx_status; } ;
struct cec_msg {unsigned int len; scalar_t__* msg; } ;
struct cec_adapter {int /*<<< orphan*/  owner; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_8__ {scalar_t__ (* read ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* enable ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* disable ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write ) (int /*<<< orphan*/ ,scalar_t__,int) ;} ;

/* Variables and functions */
 int BIT (int) ; 
 int CEC_CAP_LOG_ADDRS ; 
 int CEC_CAP_PASSTHROUGH ; 
 int CEC_CAP_RC ; 
 int CEC_CAP_TRANSMIT ; 
 unsigned int CEC_CTRL_IMMED ; 
 unsigned int CEC_CTRL_NORMAL ; 
 unsigned int CEC_CTRL_RETRY ; 
 unsigned int CEC_CTRL_START ; 
 scalar_t__ CEC_LOG_ADDR_INVALID ; 
 int /*<<< orphan*/  CEC_MAX_LOG_ADDRS ; 
#define  CEC_SIGNAL_FREE_TIME_NEW_INITIATOR 130 
#define  CEC_SIGNAL_FREE_TIME_NEXT_XFER 129 
#define  CEC_SIGNAL_FREE_TIME_RETRY 128 
 unsigned int CEC_STAT_DONE ; 
 unsigned int CEC_STAT_EOM ; 
 unsigned int CEC_STAT_ERROR_INIT ; 
 unsigned int CEC_STAT_NACK ; 
 int /*<<< orphan*/  CEC_TX_STATUS_ERROR ; 
 int /*<<< orphan*/  CEC_TX_STATUS_NACK ; 
 int /*<<< orphan*/  CEC_TX_STATUS_OK ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HDMI_CEC_ADDR_H ; 
 int HDMI_CEC_ADDR_L ; 
 int HDMI_CEC_CTRL ; 
 int HDMI_CEC_LOCK ; 
 int HDMI_CEC_MASK ; 
 int HDMI_CEC_POLARITY ; 
 int HDMI_CEC_RX_CNT ; 
 unsigned int HDMI_CEC_RX_DATA0 ; 
 int HDMI_CEC_TX_CNT ; 
 unsigned int HDMI_CEC_TX_DATA0 ; 
 int HDMI_IH_CEC_STAT0 ; 
 int HDMI_IH_MUTE_CEC_STAT0 ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (struct cec_adapter*) ; 
 int PTR_ERR (struct cec_adapter*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct cec_adapter* cec_allocate_adapter (int /*<<< orphan*/ *,struct dw_hdmi_cec*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_delete_adapter (struct cec_adapter*) ; 
 struct dw_hdmi_cec* cec_get_drvdata (struct cec_adapter*) ; 
 int /*<<< orphan*/  cec_notifier_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_notifier_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_received_msg (struct cec_adapter*,TYPE_7__*) ; 
 int cec_register_adapter (struct cec_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_register_cec_notifier (struct cec_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_transmit_attempt_done (struct cec_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_unregister_adapter (struct cec_adapter*) ; 
 struct dw_hdmi_cec_data* dev_get_platdata (TYPE_2__*) ; 
 int devm_add_action (TYPE_2__*,void (*) (void*),struct dw_hdmi_cec*) ; 
 struct dw_hdmi_cec* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_remove_action (TYPE_2__*,void (*) (void*),struct dw_hdmi_cec*) ; 
 int devm_request_threaded_irq (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct cec_adapter*) ; 
 int /*<<< orphan*/  dw_hdmi_cec_ops ; 
 struct dw_hdmi_cec* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct dw_hdmi_cec*) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 int /*<<< orphan*/  smp_wmb () ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,scalar_t__,int) ; 
 scalar_t__ stub2 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dw_hdmi_write(struct dw_hdmi_cec *cec, u8 val, int offset)
{
	cec->ops->write(cec->hdmi, val, offset);
}

__attribute__((used)) static u8 dw_hdmi_read(struct dw_hdmi_cec *cec, int offset)
{
	return cec->ops->read(cec->hdmi, offset);
}

__attribute__((used)) static int dw_hdmi_cec_log_addr(struct cec_adapter *adap, u8 logical_addr)
{
	struct dw_hdmi_cec *cec = cec_get_drvdata(adap);

	if (logical_addr == CEC_LOG_ADDR_INVALID)
		cec->addresses = 0;
	else
		cec->addresses |= BIT(logical_addr) | BIT(15);

	dw_hdmi_write(cec, cec->addresses & 255, HDMI_CEC_ADDR_L);
	dw_hdmi_write(cec, cec->addresses >> 8, HDMI_CEC_ADDR_H);

	return 0;
}

__attribute__((used)) static int dw_hdmi_cec_transmit(struct cec_adapter *adap, u8 attempts,
				u32 signal_free_time, struct cec_msg *msg)
{
	struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
	unsigned int i, ctrl;

	switch (signal_free_time) {
	case CEC_SIGNAL_FREE_TIME_RETRY:
		ctrl = CEC_CTRL_RETRY;
		break;
	case CEC_SIGNAL_FREE_TIME_NEW_INITIATOR:
	default:
		ctrl = CEC_CTRL_NORMAL;
		break;
	case CEC_SIGNAL_FREE_TIME_NEXT_XFER:
		ctrl = CEC_CTRL_IMMED;
		break;
	}

	for (i = 0; i < msg->len; i++)
		dw_hdmi_write(cec, msg->msg[i], HDMI_CEC_TX_DATA0 + i);

	dw_hdmi_write(cec, msg->len, HDMI_CEC_TX_CNT);
	dw_hdmi_write(cec, ctrl | CEC_CTRL_START, HDMI_CEC_CTRL);

	return 0;
}

__attribute__((used)) static irqreturn_t dw_hdmi_cec_hardirq(int irq, void *data)
{
	struct cec_adapter *adap = data;
	struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
	unsigned int stat = dw_hdmi_read(cec, HDMI_IH_CEC_STAT0);
	irqreturn_t ret = IRQ_HANDLED;

	if (stat == 0)
		return IRQ_NONE;

	dw_hdmi_write(cec, stat, HDMI_IH_CEC_STAT0);

	if (stat & CEC_STAT_ERROR_INIT) {
		cec->tx_status = CEC_TX_STATUS_ERROR;
		cec->tx_done = true;
		ret = IRQ_WAKE_THREAD;
	} else if (stat & CEC_STAT_DONE) {
		cec->tx_status = CEC_TX_STATUS_OK;
		cec->tx_done = true;
		ret = IRQ_WAKE_THREAD;
	} else if (stat & CEC_STAT_NACK) {
		cec->tx_status = CEC_TX_STATUS_NACK;
		cec->tx_done = true;
		ret = IRQ_WAKE_THREAD;
	}

	if (stat & CEC_STAT_EOM) {
		unsigned int len, i;

		len = dw_hdmi_read(cec, HDMI_CEC_RX_CNT);
		if (len > sizeof(cec->rx_msg.msg))
			len = sizeof(cec->rx_msg.msg);

		for (i = 0; i < len; i++)
			cec->rx_msg.msg[i] =
				dw_hdmi_read(cec, HDMI_CEC_RX_DATA0 + i);

		dw_hdmi_write(cec, 0, HDMI_CEC_LOCK);

		cec->rx_msg.len = len;
		smp_wmb();
		cec->rx_done = true;

		ret = IRQ_WAKE_THREAD;
	}

	return ret;
}

__attribute__((used)) static irqreturn_t dw_hdmi_cec_thread(int irq, void *data)
{
	struct cec_adapter *adap = data;
	struct dw_hdmi_cec *cec = cec_get_drvdata(adap);

	if (cec->tx_done) {
		cec->tx_done = false;
		cec_transmit_attempt_done(adap, cec->tx_status);
	}
	if (cec->rx_done) {
		cec->rx_done = false;
		smp_rmb();
		cec_received_msg(adap, &cec->rx_msg);
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int dw_hdmi_cec_enable(struct cec_adapter *adap, bool enable)
{
	struct dw_hdmi_cec *cec = cec_get_drvdata(adap);

	if (!enable) {
		dw_hdmi_write(cec, ~0, HDMI_CEC_MASK);
		dw_hdmi_write(cec, ~0, HDMI_IH_MUTE_CEC_STAT0);
		dw_hdmi_write(cec, 0, HDMI_CEC_POLARITY);

		cec->ops->disable(cec->hdmi);
	} else {
		unsigned int irqs;

		dw_hdmi_write(cec, 0, HDMI_CEC_CTRL);
		dw_hdmi_write(cec, ~0, HDMI_IH_CEC_STAT0);
		dw_hdmi_write(cec, 0, HDMI_CEC_LOCK);

		dw_hdmi_cec_log_addr(cec->adap, CEC_LOG_ADDR_INVALID);

		cec->ops->enable(cec->hdmi);

		irqs = CEC_STAT_ERROR_INIT | CEC_STAT_NACK | CEC_STAT_EOM |
		       CEC_STAT_DONE;
		dw_hdmi_write(cec, irqs, HDMI_CEC_POLARITY);
		dw_hdmi_write(cec, ~irqs, HDMI_CEC_MASK);
		dw_hdmi_write(cec, ~irqs, HDMI_IH_MUTE_CEC_STAT0);
	}
	return 0;
}

__attribute__((used)) static void dw_hdmi_cec_del(void *data)
{
	struct dw_hdmi_cec *cec = data;

	cec_delete_adapter(cec->adap);
}

__attribute__((used)) static int dw_hdmi_cec_probe(struct platform_device *pdev)
{
	struct dw_hdmi_cec_data *data = dev_get_platdata(&pdev->dev);
	struct dw_hdmi_cec *cec;
	int ret;

	if (!data)
		return -ENXIO;

	/*
	 * Our device is just a convenience - we want to link to the real
	 * hardware device here, so that userspace can see the association
	 * between the HDMI hardware and its associated CEC chardev.
	 */
	cec = devm_kzalloc(&pdev->dev, sizeof(*cec), GFP_KERNEL);
	if (!cec)
		return -ENOMEM;

	cec->irq = data->irq;
	cec->ops = data->ops;
	cec->hdmi = data->hdmi;

	platform_set_drvdata(pdev, cec);

	dw_hdmi_write(cec, 0, HDMI_CEC_TX_CNT);
	dw_hdmi_write(cec, ~0, HDMI_CEC_MASK);
	dw_hdmi_write(cec, ~0, HDMI_IH_MUTE_CEC_STAT0);
	dw_hdmi_write(cec, 0, HDMI_CEC_POLARITY);

	cec->adap = cec_allocate_adapter(&dw_hdmi_cec_ops, cec, "dw_hdmi",
					 CEC_CAP_LOG_ADDRS | CEC_CAP_TRANSMIT |
					 CEC_CAP_RC | CEC_CAP_PASSTHROUGH,
					 CEC_MAX_LOG_ADDRS);
	if (IS_ERR(cec->adap))
		return PTR_ERR(cec->adap);

	/* override the module pointer */
	cec->adap->owner = THIS_MODULE;

	ret = devm_add_action(&pdev->dev, dw_hdmi_cec_del, cec);
	if (ret) {
		cec_delete_adapter(cec->adap);
		return ret;
	}

	ret = devm_request_threaded_irq(&pdev->dev, cec->irq,
					dw_hdmi_cec_hardirq,
					dw_hdmi_cec_thread, IRQF_SHARED,
					"dw-hdmi-cec", cec->adap);
	if (ret < 0)
		return ret;

	cec->notify = cec_notifier_get(pdev->dev.parent);
	if (!cec->notify)
		return -ENOMEM;

	ret = cec_register_adapter(cec->adap, pdev->dev.parent);
	if (ret < 0) {
		cec_notifier_put(cec->notify);
		return ret;
	}

	/*
	 * CEC documentation says we must not call cec_delete_adapter
	 * after a successful call to cec_register_adapter().
	 */
	devm_remove_action(&pdev->dev, dw_hdmi_cec_del, cec);

	cec_register_cec_notifier(cec->adap, cec->notify);

	return 0;
}

__attribute__((used)) static int dw_hdmi_cec_remove(struct platform_device *pdev)
{
	struct dw_hdmi_cec *cec = platform_get_drvdata(pdev);

	cec_unregister_adapter(cec->adap);
	cec_notifier_put(cec->notify);

	return 0;
}

