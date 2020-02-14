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
typedef  int u32 ;
struct notifier_block {int dummy; } ;
struct amba_id {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  start; } ;
struct amba_device {int /*<<< orphan*/  dev; int /*<<< orphan*/ * irq; TYPE_1__ res; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int A9_SOURCE ; 
 int CHAN_MASK (int) ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int IPCMMIS (int) ; 
 int IPCMxDCLEAR (int) ; 
 int IPCMxDR (int,int) ; 
 int IPCMxDSET (int) ; 
 int IPCMxMCLEAR (int) ; 
 int IPCMxMSET (int) ; 
 int IPCMxSEND (int) ; 
 int IPCMxSOURCE (int) ; 
 int IPC_RX_MBOX ; 
 int IPC_TX_MBOX ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int M3_SOURCE ; 
 int MBOX_MASK (int) ; 
 int /*<<< orphan*/  atomic_notifier_call_chain (int /*<<< orphan*/ *,int,int*) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ipc_base ; 
 int /*<<< orphan*/  ipc_completion ; 
 int /*<<< orphan*/  ipc_irq ; 
 int /*<<< orphan*/  ipc_m1_lock ; 
 int /*<<< orphan*/  ipc_notifier ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl_relaxed (int /*<<< orphan*/ *) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  resource_size (TYPE_1__*) ; 
 int wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void set_destination(int source, int mbox)
{
	writel_relaxed(CHAN_MASK(source), ipc_base + IPCMxDSET(mbox));
	writel_relaxed(CHAN_MASK(source), ipc_base + IPCMxMSET(mbox));
}

__attribute__((used)) static inline void clear_destination(int source, int mbox)
{
	writel_relaxed(CHAN_MASK(source), ipc_base + IPCMxDCLEAR(mbox));
	writel_relaxed(CHAN_MASK(source), ipc_base + IPCMxMCLEAR(mbox));
}

__attribute__((used)) static void __ipc_send(int mbox, u32 *data)
{
	int i;
	for (i = 0; i < 7; i++)
		writel_relaxed(data[i], ipc_base + IPCMxDR(mbox, i));
	writel_relaxed(0x1, ipc_base + IPCMxSEND(mbox));
}

__attribute__((used)) static u32 __ipc_rcv(int mbox, u32 *data)
{
	int i;
	for (i = 0; i < 7; i++)
		data[i] = readl_relaxed(ipc_base + IPCMxDR(mbox, i));
	return data[1];
}

int pl320_ipc_transmit(u32 *data)
{
	int ret;

	mutex_lock(&ipc_m1_lock);

	init_completion(&ipc_completion);
	__ipc_send(IPC_TX_MBOX, data);
	ret = wait_for_completion_timeout(&ipc_completion,
					  msecs_to_jiffies(1000));
	if (ret == 0) {
		ret = -ETIMEDOUT;
		goto out;
	}

	ret = __ipc_rcv(IPC_TX_MBOX, data);
out:
	mutex_unlock(&ipc_m1_lock);
	return ret;
}

__attribute__((used)) static irqreturn_t ipc_handler(int irq, void *dev)
{
	u32 irq_stat;
	u32 data[7];

	irq_stat = readl_relaxed(ipc_base + IPCMMIS(1));
	if (irq_stat & MBOX_MASK(IPC_TX_MBOX)) {
		writel_relaxed(0, ipc_base + IPCMxSEND(IPC_TX_MBOX));
		complete(&ipc_completion);
	}
	if (irq_stat & MBOX_MASK(IPC_RX_MBOX)) {
		__ipc_rcv(IPC_RX_MBOX, data);
		atomic_notifier_call_chain(&ipc_notifier, data[0], data + 1);
		writel_relaxed(2, ipc_base + IPCMxSEND(IPC_RX_MBOX));
	}

	return IRQ_HANDLED;
}

int pl320_ipc_register_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&ipc_notifier, nb);
}

int pl320_ipc_unregister_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&ipc_notifier, nb);
}

__attribute__((used)) static int pl320_probe(struct amba_device *adev, const struct amba_id *id)
{
	int ret;

	ipc_base = ioremap(adev->res.start, resource_size(&adev->res));
	if (ipc_base == NULL)
		return -ENOMEM;

	writel_relaxed(0, ipc_base + IPCMxSEND(IPC_TX_MBOX));

	ipc_irq = adev->irq[0];
	ret = request_irq(ipc_irq, ipc_handler, 0, dev_name(&adev->dev), NULL);
	if (ret < 0)
		goto err;

	/* Init slow mailbox */
	writel_relaxed(CHAN_MASK(A9_SOURCE),
		       ipc_base + IPCMxSOURCE(IPC_TX_MBOX));
	writel_relaxed(CHAN_MASK(M3_SOURCE),
		       ipc_base + IPCMxDSET(IPC_TX_MBOX));
	writel_relaxed(CHAN_MASK(M3_SOURCE) | CHAN_MASK(A9_SOURCE),
		       ipc_base + IPCMxMSET(IPC_TX_MBOX));

	/* Init receive mailbox */
	writel_relaxed(CHAN_MASK(M3_SOURCE),
		       ipc_base + IPCMxSOURCE(IPC_RX_MBOX));
	writel_relaxed(CHAN_MASK(A9_SOURCE),
		       ipc_base + IPCMxDSET(IPC_RX_MBOX));
	writel_relaxed(CHAN_MASK(M3_SOURCE) | CHAN_MASK(A9_SOURCE),
		       ipc_base + IPCMxMSET(IPC_RX_MBOX));

	return 0;
err:
	iounmap(ipc_base);
	return ret;
}

