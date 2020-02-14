#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct rockchip_mbox_msg {scalar_t__ rx_size; int cmd; } ;
struct rockchip_mbox_data {int num_chans; } ;
struct rockchip_mbox_chan {int idx; int irq; struct rockchip_mbox_msg* msg; struct rockchip_mbox* mb; } ;
struct TYPE_13__ {int num_chans; int txdone_irq; int /*<<< orphan*/ * ops; TYPE_4__* dev; int /*<<< orphan*/ * chans; } ;
struct rockchip_mbox {scalar_t__ buf_size; TYPE_2__ mbox; struct rockchip_mbox_chan* chans; scalar_t__ pclk; scalar_t__ mbox_base; } ;
struct resource {int dummy; } ;
struct TYPE_14__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_4__ dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct mbox_chan {TYPE_1__* mbox; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_12__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MAILBOX_A2B_CMD (size_t) ; 
 scalar_t__ MAILBOX_A2B_DAT (size_t) ; 
 scalar_t__ MAILBOX_B2A_INTEN ; 
 scalar_t__ MAILBOX_B2A_STATUS ; 
 int PTR_ERR (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_4__*,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 struct rockchip_mbox* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_4__*) ; 
 scalar_t__ devm_clk_get (TYPE_4__*,char*) ; 
 scalar_t__ devm_ioremap_resource (TYPE_4__*,struct resource*) ; 
 void* devm_kcalloc (TYPE_4__*,int,int,int /*<<< orphan*/ ) ; 
 struct rockchip_mbox* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_4__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct rockchip_mbox*) ; 
 int /*<<< orphan*/  mbox_chan_received_data (int /*<<< orphan*/ *,struct rockchip_mbox_msg*) ; 
 int mbox_controller_register (TYPE_2__*) ; 
 int /*<<< orphan*/  mbox_controller_unregister (TYPE_2__*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rockchip_mbox* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rockchip_mbox*) ; 
 int readl_relaxed (scalar_t__) ; 
 scalar_t__ resource_size (struct resource*) ; 
 int /*<<< orphan*/  rockchip_mbox_chan_ops ; 
 int /*<<< orphan*/  rockchip_mbox_of_match ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int rockchip_mbox_send_data(struct mbox_chan *chan, void *data)
{
	struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);
	struct rockchip_mbox_msg *msg = data;
	struct rockchip_mbox_chan *chans = mb->chans;

	if (!msg)
		return -EINVAL;

	if (msg->rx_size > mb->buf_size) {
		dev_err(mb->mbox.dev, "Transmit size over buf size(%d)\n",
			mb->buf_size);
		return -EINVAL;
	}

	dev_dbg(mb->mbox.dev, "Chan[%d]: A2B message, cmd 0x%08x\n",
		chans->idx, msg->cmd);

	mb->chans[chans->idx].msg = msg;

	writel_relaxed(msg->cmd, mb->mbox_base + MAILBOX_A2B_CMD(chans->idx));
	writel_relaxed(msg->rx_size, mb->mbox_base +
		       MAILBOX_A2B_DAT(chans->idx));

	return 0;
}

__attribute__((used)) static int rockchip_mbox_startup(struct mbox_chan *chan)
{
	struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);

	/* Enable all B2A interrupts */
	writel_relaxed((1 << mb->mbox.num_chans) - 1,
		       mb->mbox_base + MAILBOX_B2A_INTEN);

	return 0;
}

__attribute__((used)) static void rockchip_mbox_shutdown(struct mbox_chan *chan)
{
	struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);
	struct rockchip_mbox_chan *chans = mb->chans;

	/* Disable all B2A interrupts */
	writel_relaxed(0, mb->mbox_base + MAILBOX_B2A_INTEN);

	mb->chans[chans->idx].msg = NULL;
}

__attribute__((used)) static irqreturn_t rockchip_mbox_irq(int irq, void *dev_id)
{
	int idx;
	struct rockchip_mbox *mb = (struct rockchip_mbox *)dev_id;
	u32 status = readl_relaxed(mb->mbox_base + MAILBOX_B2A_STATUS);

	for (idx = 0; idx < mb->mbox.num_chans; idx++) {
		if ((status & (1 << idx)) && (irq == mb->chans[idx].irq)) {
			/* Clear mbox interrupt */
			writel_relaxed(1 << idx,
				       mb->mbox_base + MAILBOX_B2A_STATUS);
			return IRQ_WAKE_THREAD;
		}
	}

	return IRQ_NONE;
}

__attribute__((used)) static irqreturn_t rockchip_mbox_isr(int irq, void *dev_id)
{
	int idx;
	struct rockchip_mbox_msg *msg = NULL;
	struct rockchip_mbox *mb = (struct rockchip_mbox *)dev_id;

	for (idx = 0; idx < mb->mbox.num_chans; idx++) {
		if (irq != mb->chans[idx].irq)
			continue;

		msg = mb->chans[idx].msg;
		if (!msg) {
			dev_err(mb->mbox.dev,
				"Chan[%d]: B2A message is NULL\n", idx);
			break; /* spurious */
		}

		mbox_chan_received_data(&mb->mbox.chans[idx], msg);
		mb->chans[idx].msg = NULL;

		dev_dbg(mb->mbox.dev, "Chan[%d]: B2A message, cmd 0x%08x\n",
			idx, msg->cmd);

		break;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int rockchip_mbox_probe(struct platform_device *pdev)
{
	struct rockchip_mbox *mb;
	const struct of_device_id *match;
	const struct rockchip_mbox_data *drv_data;
	struct resource *res;
	int ret, irq, i;

	if (!pdev->dev.of_node)
		return -ENODEV;

	match = of_match_node(rockchip_mbox_of_match, pdev->dev.of_node);
	drv_data = (const struct rockchip_mbox_data *)match->data;

	mb = devm_kzalloc(&pdev->dev, sizeof(*mb), GFP_KERNEL);
	if (!mb)
		return -ENOMEM;

	mb->chans = devm_kcalloc(&pdev->dev, drv_data->num_chans,
				 sizeof(*mb->chans), GFP_KERNEL);
	if (!mb->chans)
		return -ENOMEM;

	mb->mbox.chans = devm_kcalloc(&pdev->dev, drv_data->num_chans,
				      sizeof(*mb->mbox.chans), GFP_KERNEL);
	if (!mb->mbox.chans)
		return -ENOMEM;

	platform_set_drvdata(pdev, mb);

	mb->mbox.dev = &pdev->dev;
	mb->mbox.num_chans = drv_data->num_chans;
	mb->mbox.ops = &rockchip_mbox_chan_ops;
	mb->mbox.txdone_irq = true;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENODEV;

	mb->mbox_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mb->mbox_base))
		return PTR_ERR(mb->mbox_base);

	/* Each channel has two buffers for A2B and B2A */
	mb->buf_size = (size_t)resource_size(res) / (drv_data->num_chans * 2);

	mb->pclk = devm_clk_get(&pdev->dev, "pclk_mailbox");
	if (IS_ERR(mb->pclk)) {
		ret = PTR_ERR(mb->pclk);
		dev_err(&pdev->dev, "failed to get pclk_mailbox clock: %d\n",
			ret);
		return ret;
	}

	ret = clk_prepare_enable(mb->pclk);
	if (ret) {
		dev_err(&pdev->dev, "failed to enable pclk: %d\n", ret);
		return ret;
	}

	for (i = 0; i < mb->mbox.num_chans; i++) {
		irq = platform_get_irq(pdev, i);
		if (irq < 0)
			return irq;

		ret = devm_request_threaded_irq(&pdev->dev, irq,
						rockchip_mbox_irq,
						rockchip_mbox_isr, IRQF_ONESHOT,
						dev_name(&pdev->dev), mb);
		if (ret < 0)
			return ret;

		mb->chans[i].idx = i;
		mb->chans[i].irq = irq;
		mb->chans[i].mb = mb;
		mb->chans[i].msg = NULL;
	}

	ret = mbox_controller_register(&mb->mbox);
	if (ret < 0)
		dev_err(&pdev->dev, "Failed to register mailbox: %d\n", ret);

	return ret;
}

__attribute__((used)) static int rockchip_mbox_remove(struct platform_device *pdev)
{
	struct rockchip_mbox *mb = platform_get_drvdata(pdev);

	if (!mb)
		return -EINVAL;

	mbox_controller_unregister(&mb->mbox);

	return 0;
}

