#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct timer_list {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct mbox_chan {struct altera_mbox* con_priv; } ;
struct TYPE_3__ {int num_chans; int txdone_irq; int txdone_poll; int /*<<< orphan*/  txpoll_period; int /*<<< orphan*/ * ops; struct mbox_chan* chans; int /*<<< orphan*/ * dev; } ;
struct altera_mbox {int intr_mode; scalar_t__ irq; int is_sender; TYPE_1__ controller; int /*<<< orphan*/ * dev; scalar_t__ mbox_base; int /*<<< orphan*/  rxpoll_timer; struct mbox_chan* chan; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INT_PENDING_MSK ; 
 int INT_SPACE_MSK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MAILBOX_CMD_REG ; 
 scalar_t__ MAILBOX_INTMASK_REG ; 
 scalar_t__ MAILBOX_PTR_REG ; 
 scalar_t__ MAILBOX_STS_REG ; 
 size_t MBOX_CMD ; 
 int MBOX_FULL (int) ; 
 int MBOX_PENDING (int) ; 
 int /*<<< orphan*/  MBOX_POLLING_MS ; 
 size_t MBOX_PTR ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  altera_mbox_ops ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct mbox_chan*) ; 
 struct altera_mbox* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 struct altera_mbox* mbox ; 
 int /*<<< orphan*/  mbox_chan_received_data (struct mbox_chan*,void*) ; 
 int /*<<< orphan*/  mbox_chan_txdone (struct mbox_chan*,int /*<<< orphan*/ ) ; 
 int mbox_controller_register (TYPE_1__*) ; 
 int /*<<< orphan*/  mbox_controller_unregister (TYPE_1__*) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 struct altera_mbox* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct altera_mbox*) ; 
 int readl_relaxed (scalar_t__) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct mbox_chan*) ; 
 int /*<<< orphan*/  rxpoll_timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static struct altera_mbox *mbox_chan_to_altera_mbox(struct mbox_chan *chan)
{
	if (!chan || !chan->con_priv)
		return NULL;

	return (struct altera_mbox *)chan->con_priv;
}

__attribute__((used)) static inline int altera_mbox_full(struct altera_mbox *mbox)
{
	u32 status;

	status = readl_relaxed(mbox->mbox_base + MAILBOX_STS_REG);
	return MBOX_FULL(status);
}

__attribute__((used)) static inline int altera_mbox_pending(struct altera_mbox *mbox)
{
	u32 status;

	status = readl_relaxed(mbox->mbox_base + MAILBOX_STS_REG);
	return MBOX_PENDING(status);
}

__attribute__((used)) static void altera_mbox_rx_intmask(struct altera_mbox *mbox, bool enable)
{
	u32 mask;

	mask = readl_relaxed(mbox->mbox_base + MAILBOX_INTMASK_REG);
	if (enable)
		mask |= INT_PENDING_MSK;
	else
		mask &= ~INT_PENDING_MSK;
	writel_relaxed(mask, mbox->mbox_base + MAILBOX_INTMASK_REG);
}

__attribute__((used)) static void altera_mbox_tx_intmask(struct altera_mbox *mbox, bool enable)
{
	u32 mask;

	mask = readl_relaxed(mbox->mbox_base + MAILBOX_INTMASK_REG);
	if (enable)
		mask |= INT_SPACE_MSK;
	else
		mask &= ~INT_SPACE_MSK;
	writel_relaxed(mask, mbox->mbox_base + MAILBOX_INTMASK_REG);
}

__attribute__((used)) static bool altera_mbox_is_sender(struct altera_mbox *mbox)
{
	u32 reg;
	/* Write a magic number to PTR register and read back this register.
	 * This register is read-write if it is a sender.
	 */
	#define MBOX_MAGIC	0xA5A5AA55
	writel_relaxed(MBOX_MAGIC, mbox->mbox_base + MAILBOX_PTR_REG);
	reg = readl_relaxed(mbox->mbox_base + MAILBOX_PTR_REG);
	if (reg == MBOX_MAGIC) {
		/* Clear to 0 */
		writel_relaxed(0, mbox->mbox_base + MAILBOX_PTR_REG);
		return true;
	}
	return false;
}

__attribute__((used)) static void altera_mbox_rx_data(struct mbox_chan *chan)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
	u32 data[2];

	if (altera_mbox_pending(mbox)) {
		data[MBOX_PTR] =
			readl_relaxed(mbox->mbox_base + MAILBOX_PTR_REG);
		data[MBOX_CMD] =
			readl_relaxed(mbox->mbox_base + MAILBOX_CMD_REG);
		mbox_chan_received_data(chan, (void *)data);
	}
}

__attribute__((used)) static void altera_mbox_poll_rx(struct timer_list *t)
{
	struct altera_mbox *mbox = from_timer(mbox, t, rxpoll_timer);

	altera_mbox_rx_data(mbox->chan);

	mod_timer(&mbox->rxpoll_timer,
		  jiffies + msecs_to_jiffies(MBOX_POLLING_MS));
}

__attribute__((used)) static irqreturn_t altera_mbox_tx_interrupt(int irq, void *p)
{
	struct mbox_chan *chan = (struct mbox_chan *)p;
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	altera_mbox_tx_intmask(mbox, false);
	mbox_chan_txdone(chan, 0);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t altera_mbox_rx_interrupt(int irq, void *p)
{
	struct mbox_chan *chan = (struct mbox_chan *)p;

	altera_mbox_rx_data(chan);
	return IRQ_HANDLED;
}

__attribute__((used)) static int altera_mbox_startup_sender(struct mbox_chan *chan)
{
	int ret;
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	if (mbox->intr_mode) {
		ret = request_irq(mbox->irq, altera_mbox_tx_interrupt, 0,
				  DRIVER_NAME, chan);
		if (unlikely(ret)) {
			dev_err(mbox->dev,
				"failed to register mailbox interrupt:%d\n",
				ret);
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int altera_mbox_startup_receiver(struct mbox_chan *chan)
{
	int ret;
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	if (mbox->intr_mode) {
		ret = request_irq(mbox->irq, altera_mbox_rx_interrupt, 0,
				  DRIVER_NAME, chan);
		if (unlikely(ret)) {
			mbox->intr_mode = false;
			goto polling; /* use polling if failed */
		}

		altera_mbox_rx_intmask(mbox, true);
		return 0;
	}

polling:
	/* Setup polling timer */
	mbox->chan = chan;
	timer_setup(&mbox->rxpoll_timer, altera_mbox_poll_rx, 0);
	mod_timer(&mbox->rxpoll_timer,
		  jiffies + msecs_to_jiffies(MBOX_POLLING_MS));

	return 0;
}

__attribute__((used)) static int altera_mbox_send_data(struct mbox_chan *chan, void *data)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
	u32 *udata = (u32 *)data;

	if (!mbox || !data)
		return -EINVAL;
	if (!mbox->is_sender) {
		dev_warn(mbox->dev,
			 "failed to send. This is receiver mailbox.\n");
		return -EINVAL;
	}

	if (altera_mbox_full(mbox))
		return -EBUSY;

	/* Enable interrupt before send */
	if (mbox->intr_mode)
		altera_mbox_tx_intmask(mbox, true);

	/* Pointer register must write before command register */
	writel_relaxed(udata[MBOX_PTR], mbox->mbox_base + MAILBOX_PTR_REG);
	writel_relaxed(udata[MBOX_CMD], mbox->mbox_base + MAILBOX_CMD_REG);

	return 0;
}

__attribute__((used)) static bool altera_mbox_last_tx_done(struct mbox_chan *chan)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	/* Return false if mailbox is full */
	return altera_mbox_full(mbox) ? false : true;
}

__attribute__((used)) static bool altera_mbox_peek_data(struct mbox_chan *chan)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	return altera_mbox_pending(mbox) ? true : false;
}

__attribute__((used)) static int altera_mbox_startup(struct mbox_chan *chan)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
	int ret = 0;

	if (!mbox)
		return -EINVAL;

	if (mbox->is_sender)
		ret = altera_mbox_startup_sender(chan);
	else
		ret = altera_mbox_startup_receiver(chan);

	return ret;
}

__attribute__((used)) static void altera_mbox_shutdown(struct mbox_chan *chan)
{
	struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);

	if (mbox->intr_mode) {
		/* Unmask all interrupt masks */
		writel_relaxed(~0, mbox->mbox_base + MAILBOX_INTMASK_REG);
		free_irq(mbox->irq, chan);
	} else if (!mbox->is_sender) {
		del_timer_sync(&mbox->rxpoll_timer);
	}
}

__attribute__((used)) static int altera_mbox_probe(struct platform_device *pdev)
{
	struct altera_mbox *mbox;
	struct resource	*regs;
	struct mbox_chan *chans;
	int ret;

	mbox = devm_kzalloc(&pdev->dev, sizeof(*mbox),
			    GFP_KERNEL);
	if (!mbox)
		return -ENOMEM;

	/* Allocated one channel */
	chans = devm_kzalloc(&pdev->dev, sizeof(*chans), GFP_KERNEL);
	if (!chans)
		return -ENOMEM;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	mbox->mbox_base = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(mbox->mbox_base))
		return PTR_ERR(mbox->mbox_base);

	/* Check is it a sender or receiver? */
	mbox->is_sender = altera_mbox_is_sender(mbox);

	mbox->irq = platform_get_irq(pdev, 0);
	if (mbox->irq >= 0)
		mbox->intr_mode = true;

	mbox->dev = &pdev->dev;

	/* Hardware supports only one channel. */
	chans[0].con_priv = mbox;
	mbox->controller.dev = mbox->dev;
	mbox->controller.num_chans = 1;
	mbox->controller.chans = chans;
	mbox->controller.ops = &altera_mbox_ops;

	if (mbox->is_sender) {
		if (mbox->intr_mode) {
			mbox->controller.txdone_irq = true;
		} else {
			mbox->controller.txdone_poll = true;
			mbox->controller.txpoll_period = MBOX_POLLING_MS;
		}
	}

	ret = mbox_controller_register(&mbox->controller);
	if (ret) {
		dev_err(&pdev->dev, "Register mailbox failed\n");
		goto err;
	}

	platform_set_drvdata(pdev, mbox);
err:
	return ret;
}

__attribute__((used)) static int altera_mbox_remove(struct platform_device *pdev)
{
	struct altera_mbox *mbox = platform_get_drvdata(pdev);

	if (!mbox)
		return -EINVAL;

	mbox_controller_unregister(&mbox->controller);

	return 0;
}

