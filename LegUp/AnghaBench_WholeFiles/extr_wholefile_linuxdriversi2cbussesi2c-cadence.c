#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_22__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_13__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {scalar_t__ start; } ;
struct TYPE_28__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct of_device_id {struct cdns_platform_data* data; } ;
struct notifier_block {int dummy; } ;
struct i2c_msg {int addr; int len; int flags; int /*<<< orphan*/ * buf; } ;
struct TYPE_25__ {TYPE_3__* parent; } ;
struct i2c_adapter {TYPE_1__ dev; struct cdns_i2c* algo_data; int /*<<< orphan*/  timeout; } ;
struct clk_notifier_data {unsigned long new_rate; unsigned long old_rate; } ;
struct cdns_platform_data {int quirks; } ;
struct TYPE_26__ {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct TYPE_27__ {TYPE_3__* parent; int /*<<< orphan*/  of_node; } ;
struct TYPE_24__ {int retries; int /*<<< orphan*/  name; TYPE_2__ dev; struct cdns_i2c* algo_data; int /*<<< orphan*/  timeout; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; } ;
struct cdns_i2c {int curr_recv_count; int recv_count; int quirks; int bus_hold_flag; int send_count; unsigned int err_status; unsigned long i2c_clk; unsigned long input_clk; unsigned long irq; int /*<<< orphan*/  clk; TYPE_22__ clk_rate_change_nb; TYPE_13__ adap; TYPE_3__* dev; int /*<<< orphan*/  xfer_done; int /*<<< orphan*/  membase; struct i2c_msg* p_msg; int /*<<< orphan*/ * p_send_buf; int /*<<< orphan*/ * p_recv_buf; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
#define  ABORT_RATE_CHANGE 130 
 int CDNS_I2C_ADDR_MASK ; 
 int /*<<< orphan*/  CDNS_I2C_ADDR_OFFSET ; 
 int CDNS_I2C_BROKEN_HOLD_BIT ; 
 int CDNS_I2C_CR_ACK_EN ; 
 unsigned int CDNS_I2C_CR_CLR_FIFO ; 
 unsigned int CDNS_I2C_CR_DIVA_MASK ; 
 unsigned int CDNS_I2C_CR_DIVA_SHIFT ; 
 unsigned int CDNS_I2C_CR_DIVB_MASK ; 
 unsigned int CDNS_I2C_CR_DIVB_SHIFT ; 
 int CDNS_I2C_CR_HOLD ; 
 int CDNS_I2C_CR_MS ; 
 int CDNS_I2C_CR_NEA ; 
 int /*<<< orphan*/  CDNS_I2C_CR_OFFSET ; 
 unsigned int CDNS_I2C_CR_RW ; 
 int /*<<< orphan*/  CDNS_I2C_DATA_OFFSET ; 
 unsigned long CDNS_I2C_DIVA_MAX ; 
 unsigned long CDNS_I2C_DIVB_MAX ; 
 int CDNS_I2C_ENABLED_INTR_MASK ; 
 int CDNS_I2C_FIFO_DEPTH ; 
 int /*<<< orphan*/  CDNS_I2C_IDR_OFFSET ; 
 int /*<<< orphan*/  CDNS_I2C_IER_OFFSET ; 
 int /*<<< orphan*/  CDNS_I2C_ISR_OFFSET ; 
 int CDNS_I2C_IXR_ALL_INTR_MASK ; 
 unsigned int CDNS_I2C_IXR_ARB_LOST ; 
 unsigned int CDNS_I2C_IXR_COMP ; 
 unsigned int CDNS_I2C_IXR_DATA ; 
 unsigned int CDNS_I2C_IXR_ERR_INTR_MASK ; 
 unsigned int CDNS_I2C_IXR_NACK ; 
 unsigned long CDNS_I2C_SPEED_DEFAULT ; 
 unsigned long CDNS_I2C_SPEED_MAX ; 
 int CDNS_I2C_SR_BA ; 
 int /*<<< orphan*/  CDNS_I2C_SR_OFFSET ; 
 int CDNS_I2C_SR_RXDV ; 
 int /*<<< orphan*/  CDNS_I2C_TIMEOUT ; 
 int CDNS_I2C_TIMEOUT_MAX ; 
 int /*<<< orphan*/  CDNS_I2C_TIME_OUT_OFFSET ; 
 int CDNS_I2C_TRANSFER_SIZE ; 
 int /*<<< orphan*/  CDNS_I2C_XFER_SIZE_OFFSET ; 
 int /*<<< orphan*/  CNDS_I2C_PM_TIMEOUT ; 
 unsigned int DIV_ROUND_UP (unsigned long,int) ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EAGAIN ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_10BIT_ADDR ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_M_RD ; 
 int I2C_M_RECV_LEN ; 
 int I2C_M_TEN ; 
 int I2C_SMBUS_BLOCK_MAX ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 int NOTIFY_STOP ; 
#define  POST_RATE_CHANGE 129 
#define  PRE_RATE_CHANGE 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  cdns_i2c_algo ; 
 int /*<<< orphan*/  cdns_i2c_of_match ; 
 int cdns_i2c_readreg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cdns_i2c_writereg (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 unsigned long clk_get_rate (int /*<<< orphan*/ ) ; 
 scalar_t__ clk_notifier_register (int /*<<< orphan*/ ,TYPE_22__*) ; 
 int /*<<< orphan*/  clk_notifier_unregister (int /*<<< orphan*/ ,TYPE_22__*) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,int,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (TYPE_3__*,struct resource*) ; 
 struct cdns_i2c* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_3__*,unsigned long,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct cdns_i2c*) ; 
 int i2c_add_adapter (TYPE_13__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_13__*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned long*) ; 
 struct cdns_i2c* platform_get_drvdata (struct platform_device*) ; 
 unsigned long platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cdns_i2c*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_3__*) ; 
 int pm_runtime_get_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (TYPE_3__*) ; 
 scalar_t__ pm_runtime_suspended (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (TYPE_3__*) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,unsigned long) ; 
 struct cdns_i2c* to_cdns_i2c (struct notifier_block*) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cdns_i2c_clear_bus_hold(struct cdns_i2c *id)
{
	u32 reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	if (reg & CDNS_I2C_CR_HOLD)
		cdns_i2c_writereg(reg & ~CDNS_I2C_CR_HOLD, CDNS_I2C_CR_OFFSET);
}

__attribute__((used)) static inline bool cdns_is_holdquirk(struct cdns_i2c *id, bool hold_wrkaround)
{
	return (hold_wrkaround &&
		(id->curr_recv_count == CDNS_I2C_FIFO_DEPTH + 1));
}

__attribute__((used)) static irqreturn_t cdns_i2c_isr(int irq, void *ptr)
{
	unsigned int isr_status, avail_bytes, updatetx;
	unsigned int bytes_to_send;
	bool hold_quirk;
	struct cdns_i2c *id = ptr;
	/* Signal completion only after everything is updated */
	int done_flag = 0;
	irqreturn_t status = IRQ_NONE;

	isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
	cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);

	/* Handling nack and arbitration lost interrupt */
	if (isr_status & (CDNS_I2C_IXR_NACK | CDNS_I2C_IXR_ARB_LOST)) {
		done_flag = 1;
		status = IRQ_HANDLED;
	}

	/*
	 * Check if transfer size register needs to be updated again for a
	 * large data receive operation.
	 */
	updatetx = 0;
	if (id->recv_count > id->curr_recv_count)
		updatetx = 1;

	hold_quirk = (id->quirks & CDNS_I2C_BROKEN_HOLD_BIT) && updatetx;

	/* When receiving, handle data interrupt and completion interrupt */
	if (id->p_recv_buf &&
	    ((isr_status & CDNS_I2C_IXR_COMP) ||
	     (isr_status & CDNS_I2C_IXR_DATA))) {
		/* Read data if receive data valid is set */
		while (cdns_i2c_readreg(CDNS_I2C_SR_OFFSET) &
		       CDNS_I2C_SR_RXDV) {
			/*
			 * Clear hold bit that was set for FIFO control if
			 * RX data left is less than FIFO depth, unless
			 * repeated start is selected.
			 */
			if ((id->recv_count < CDNS_I2C_FIFO_DEPTH) &&
			    !id->bus_hold_flag)
				cdns_i2c_clear_bus_hold(id);

			*(id->p_recv_buf)++ =
				cdns_i2c_readreg(CDNS_I2C_DATA_OFFSET);
			id->recv_count--;
			id->curr_recv_count--;

			if (cdns_is_holdquirk(id, hold_quirk))
				break;
		}

		/*
		 * The controller sends NACK to the slave when transfer size
		 * register reaches zero without considering the HOLD bit.
		 * This workaround is implemented for large data transfers to
		 * maintain transfer size non-zero while performing a large
		 * receive operation.
		 */
		if (cdns_is_holdquirk(id, hold_quirk)) {
			/* wait while fifo is full */
			while (cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET) !=
			       (id->curr_recv_count - CDNS_I2C_FIFO_DEPTH))
				;

			/*
			 * Check number of bytes to be received against maximum
			 * transfer size and update register accordingly.
			 */
			if (((int)(id->recv_count) - CDNS_I2C_FIFO_DEPTH) >
			    CDNS_I2C_TRANSFER_SIZE) {
				cdns_i2c_writereg(CDNS_I2C_TRANSFER_SIZE,
						  CDNS_I2C_XFER_SIZE_OFFSET);
				id->curr_recv_count = CDNS_I2C_TRANSFER_SIZE +
						      CDNS_I2C_FIFO_DEPTH;
			} else {
				cdns_i2c_writereg(id->recv_count -
						  CDNS_I2C_FIFO_DEPTH,
						  CDNS_I2C_XFER_SIZE_OFFSET);
				id->curr_recv_count = id->recv_count;
			}
		} else if (id->recv_count && !hold_quirk &&
						!id->curr_recv_count) {

			/* Set the slave address in address register*/
			cdns_i2c_writereg(id->p_msg->addr & CDNS_I2C_ADDR_MASK,
						CDNS_I2C_ADDR_OFFSET);

			if (id->recv_count > CDNS_I2C_TRANSFER_SIZE) {
				cdns_i2c_writereg(CDNS_I2C_TRANSFER_SIZE,
						CDNS_I2C_XFER_SIZE_OFFSET);
				id->curr_recv_count = CDNS_I2C_TRANSFER_SIZE;
			} else {
				cdns_i2c_writereg(id->recv_count,
						CDNS_I2C_XFER_SIZE_OFFSET);
				id->curr_recv_count = id->recv_count;
			}
		}

		/* Clear hold (if not repeated start) and signal completion */
		if ((isr_status & CDNS_I2C_IXR_COMP) && !id->recv_count) {
			if (!id->bus_hold_flag)
				cdns_i2c_clear_bus_hold(id);
			done_flag = 1;
		}

		status = IRQ_HANDLED;
	}

	/* When sending, handle transfer complete interrupt */
	if ((isr_status & CDNS_I2C_IXR_COMP) && !id->p_recv_buf) {
		/*
		 * If there is more data to be sent, calculate the
		 * space available in FIFO and fill with that many bytes.
		 */
		if (id->send_count) {
			avail_bytes = CDNS_I2C_FIFO_DEPTH -
			    cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET);
			if (id->send_count > avail_bytes)
				bytes_to_send = avail_bytes;
			else
				bytes_to_send = id->send_count;

			while (bytes_to_send--) {
				cdns_i2c_writereg(
					(*(id->p_send_buf)++),
					 CDNS_I2C_DATA_OFFSET);
				id->send_count--;
			}
		} else {
			/*
			 * Signal the completion of transaction and
			 * clear the hold bus bit if there are no
			 * further messages to be processed.
			 */
			done_flag = 1;
		}
		if (!id->send_count && !id->bus_hold_flag)
			cdns_i2c_clear_bus_hold(id);

		status = IRQ_HANDLED;
	}

	/* Update the status for errors */
	id->err_status = isr_status & CDNS_I2C_IXR_ERR_INTR_MASK;
	if (id->err_status)
		status = IRQ_HANDLED;

	if (done_flag)
		complete(&id->xfer_done);

	return status;
}

__attribute__((used)) static void cdns_i2c_mrecv(struct cdns_i2c *id)
{
	unsigned int ctrl_reg;
	unsigned int isr_status;

	id->p_recv_buf = id->p_msg->buf;
	id->recv_count = id->p_msg->len;

	/* Put the controller in master receive mode and clear the FIFO */
	ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	ctrl_reg |= CDNS_I2C_CR_RW | CDNS_I2C_CR_CLR_FIFO;

	if (id->p_msg->flags & I2C_M_RECV_LEN)
		id->recv_count = I2C_SMBUS_BLOCK_MAX + 1;

	id->curr_recv_count = id->recv_count;

	/*
	 * Check for the message size against FIFO depth and set the
	 * 'hold bus' bit if it is greater than FIFO depth.
	 */
	if ((id->recv_count > CDNS_I2C_FIFO_DEPTH)  || id->bus_hold_flag)
		ctrl_reg |= CDNS_I2C_CR_HOLD;
	else
		ctrl_reg = ctrl_reg & ~CDNS_I2C_CR_HOLD;

	cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);

	/* Clear the interrupts in interrupt status register */
	isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
	cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);

	/*
	 * The no. of bytes to receive is checked against the limit of
	 * max transfer size. Set transfer size register with no of bytes
	 * receive if it is less than transfer size and transfer size if
	 * it is more. Enable the interrupts.
	 */
	if (id->recv_count > CDNS_I2C_TRANSFER_SIZE) {
		cdns_i2c_writereg(CDNS_I2C_TRANSFER_SIZE,
				  CDNS_I2C_XFER_SIZE_OFFSET);
		id->curr_recv_count = CDNS_I2C_TRANSFER_SIZE;
	} else {
		cdns_i2c_writereg(id->recv_count, CDNS_I2C_XFER_SIZE_OFFSET);
	}

	/* Set the slave address in address register - triggers operation */
	cdns_i2c_writereg(id->p_msg->addr & CDNS_I2C_ADDR_MASK,
						CDNS_I2C_ADDR_OFFSET);
	/* Clear the bus hold flag if bytes to receive is less than FIFO size */
	if (!id->bus_hold_flag &&
		((id->p_msg->flags & I2C_M_RECV_LEN) != I2C_M_RECV_LEN) &&
		(id->recv_count <= CDNS_I2C_FIFO_DEPTH))
			cdns_i2c_clear_bus_hold(id);
	cdns_i2c_writereg(CDNS_I2C_ENABLED_INTR_MASK, CDNS_I2C_IER_OFFSET);
}

__attribute__((used)) static void cdns_i2c_msend(struct cdns_i2c *id)
{
	unsigned int avail_bytes;
	unsigned int bytes_to_send;
	unsigned int ctrl_reg;
	unsigned int isr_status;

	id->p_recv_buf = NULL;
	id->p_send_buf = id->p_msg->buf;
	id->send_count = id->p_msg->len;

	/* Set the controller in Master transmit mode and clear the FIFO. */
	ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	ctrl_reg &= ~CDNS_I2C_CR_RW;
	ctrl_reg |= CDNS_I2C_CR_CLR_FIFO;

	/*
	 * Check for the message size against FIFO depth and set the
	 * 'hold bus' bit if it is greater than FIFO depth.
	 */
	if ((id->send_count > CDNS_I2C_FIFO_DEPTH) || id->bus_hold_flag)
		ctrl_reg |= CDNS_I2C_CR_HOLD;
	else
		ctrl_reg = ctrl_reg & ~CDNS_I2C_CR_HOLD;

	cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);

	/* Clear the interrupts in interrupt status register. */
	isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
	cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);

	/*
	 * Calculate the space available in FIFO. Check the message length
	 * against the space available, and fill the FIFO accordingly.
	 * Enable the interrupts.
	 */
	avail_bytes = CDNS_I2C_FIFO_DEPTH -
				cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET);

	if (id->send_count > avail_bytes)
		bytes_to_send = avail_bytes;
	else
		bytes_to_send = id->send_count;

	while (bytes_to_send--) {
		cdns_i2c_writereg((*(id->p_send_buf)++), CDNS_I2C_DATA_OFFSET);
		id->send_count--;
	}

	/*
	 * Clear the bus hold flag if there is no more data
	 * and if it is the last message.
	 */
	if (!id->bus_hold_flag && !id->send_count)
		cdns_i2c_clear_bus_hold(id);
	/* Set the slave address in address register - triggers operation. */
	cdns_i2c_writereg(id->p_msg->addr & CDNS_I2C_ADDR_MASK,
						CDNS_I2C_ADDR_OFFSET);

	cdns_i2c_writereg(CDNS_I2C_ENABLED_INTR_MASK, CDNS_I2C_IER_OFFSET);
}

__attribute__((used)) static void cdns_i2c_master_reset(struct i2c_adapter *adap)
{
	struct cdns_i2c *id = adap->algo_data;
	u32 regval;

	/* Disable the interrupts */
	cdns_i2c_writereg(CDNS_I2C_IXR_ALL_INTR_MASK, CDNS_I2C_IDR_OFFSET);
	/* Clear the hold bit and fifos */
	regval = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	regval &= ~CDNS_I2C_CR_HOLD;
	regval |= CDNS_I2C_CR_CLR_FIFO;
	cdns_i2c_writereg(regval, CDNS_I2C_CR_OFFSET);
	/* Update the transfercount register to zero */
	cdns_i2c_writereg(0, CDNS_I2C_XFER_SIZE_OFFSET);
	/* Clear the interupt status register */
	regval = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
	cdns_i2c_writereg(regval, CDNS_I2C_ISR_OFFSET);
	/* Clear the status register */
	regval = cdns_i2c_readreg(CDNS_I2C_SR_OFFSET);
	cdns_i2c_writereg(regval, CDNS_I2C_SR_OFFSET);
}

__attribute__((used)) static int cdns_i2c_process_msg(struct cdns_i2c *id, struct i2c_msg *msg,
		struct i2c_adapter *adap)
{
	unsigned long time_left;
	u32 reg;

	id->p_msg = msg;
	id->err_status = 0;
	reinit_completion(&id->xfer_done);

	/* Check for the TEN Bit mode on each msg */
	reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	if (msg->flags & I2C_M_TEN) {
		if (reg & CDNS_I2C_CR_NEA)
			cdns_i2c_writereg(reg & ~CDNS_I2C_CR_NEA,
					CDNS_I2C_CR_OFFSET);
	} else {
		if (!(reg & CDNS_I2C_CR_NEA))
			cdns_i2c_writereg(reg | CDNS_I2C_CR_NEA,
					CDNS_I2C_CR_OFFSET);
	}

	/* Check for the R/W flag on each msg */
	if (msg->flags & I2C_M_RD)
		cdns_i2c_mrecv(id);
	else
		cdns_i2c_msend(id);

	/* Wait for the signal of completion */
	time_left = wait_for_completion_timeout(&id->xfer_done, adap->timeout);
	if (time_left == 0) {
		cdns_i2c_master_reset(adap);
		dev_err(id->adap.dev.parent,
				"timeout waiting on completion\n");
		return -ETIMEDOUT;
	}

	cdns_i2c_writereg(CDNS_I2C_IXR_ALL_INTR_MASK,
			  CDNS_I2C_IDR_OFFSET);

	/* If it is bus arbitration error, try again */
	if (id->err_status & CDNS_I2C_IXR_ARB_LOST)
		return -EAGAIN;

	return 0;
}

__attribute__((used)) static int cdns_i2c_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
				int num)
{
	int ret, count;
	u32 reg;
	struct cdns_i2c *id = adap->algo_data;
	bool hold_quirk;

	ret = pm_runtime_get_sync(id->dev);
	if (ret < 0)
		return ret;
	/* Check if the bus is free */
	if (cdns_i2c_readreg(CDNS_I2C_SR_OFFSET) & CDNS_I2C_SR_BA) {
		ret = -EAGAIN;
		goto out;
	}

	hold_quirk = !!(id->quirks & CDNS_I2C_BROKEN_HOLD_BIT);
	/*
	 * Set the flag to one when multiple messages are to be
	 * processed with a repeated start.
	 */
	if (num > 1) {
		/*
		 * This controller does not give completion interrupt after a
		 * master receive message if HOLD bit is set (repeated start),
		 * resulting in SW timeout. Hence, if a receive message is
		 * followed by any other message, an error is returned
		 * indicating that this sequence is not supported.
		 */
		for (count = 0; (count < num - 1 && hold_quirk); count++) {
			if (msgs[count].flags & I2C_M_RD) {
				dev_warn(adap->dev.parent,
					 "Can't do repeated start after a receive message\n");
				ret = -EOPNOTSUPP;
				goto out;
			}
		}
		id->bus_hold_flag = 1;
		reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
		reg |= CDNS_I2C_CR_HOLD;
		cdns_i2c_writereg(reg, CDNS_I2C_CR_OFFSET);
	} else {
		id->bus_hold_flag = 0;
	}

	/* Process the msg one by one */
	for (count = 0; count < num; count++, msgs++) {
		if (count == (num - 1))
			id->bus_hold_flag = 0;

		ret = cdns_i2c_process_msg(id, msgs, adap);
		if (ret)
			goto out;

		/* Report the other error interrupts to application */
		if (id->err_status) {
			cdns_i2c_master_reset(adap);

			if (id->err_status & CDNS_I2C_IXR_NACK) {
				ret = -ENXIO;
				goto out;
			}
			ret = -EIO;
			goto out;
		}
	}

	ret = num;
out:
	pm_runtime_mark_last_busy(id->dev);
	pm_runtime_put_autosuspend(id->dev);
	return ret;
}

__attribute__((used)) static u32 cdns_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR |
		(I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK) |
		I2C_FUNC_SMBUS_BLOCK_DATA;
}

__attribute__((used)) static int cdns_i2c_calc_divs(unsigned long *f, unsigned long input_clk,
		unsigned int *a, unsigned int *b)
{
	unsigned long fscl = *f, best_fscl = *f, actual_fscl, temp;
	unsigned int div_a, div_b, calc_div_a = 0, calc_div_b = 0;
	unsigned int last_error, current_error;

	/* calculate (divisor_a+1) x (divisor_b+1) */
	temp = input_clk / (22 * fscl);

	/*
	 * If the calculated value is negative or 0, the fscl input is out of
	 * range. Return error.
	 */
	if (!temp || (temp > (CDNS_I2C_DIVA_MAX * CDNS_I2C_DIVB_MAX)))
		return -EINVAL;

	last_error = -1;
	for (div_a = 0; div_a < CDNS_I2C_DIVA_MAX; div_a++) {
		div_b = DIV_ROUND_UP(input_clk, 22 * fscl * (div_a + 1));

		if ((div_b < 1) || (div_b > CDNS_I2C_DIVB_MAX))
			continue;
		div_b--;

		actual_fscl = input_clk / (22 * (div_a + 1) * (div_b + 1));

		if (actual_fscl > fscl)
			continue;

		current_error = ((actual_fscl > fscl) ? (actual_fscl - fscl) :
							(fscl - actual_fscl));

		if (last_error > current_error) {
			calc_div_a = div_a;
			calc_div_b = div_b;
			best_fscl = actual_fscl;
			last_error = current_error;
		}
	}

	*a = calc_div_a;
	*b = calc_div_b;
	*f = best_fscl;

	return 0;
}

__attribute__((used)) static int cdns_i2c_setclk(unsigned long clk_in, struct cdns_i2c *id)
{
	unsigned int div_a, div_b;
	unsigned int ctrl_reg;
	int ret = 0;
	unsigned long fscl = id->i2c_clk;

	ret = cdns_i2c_calc_divs(&fscl, clk_in, &div_a, &div_b);
	if (ret)
		return ret;

	ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
	ctrl_reg &= ~(CDNS_I2C_CR_DIVA_MASK | CDNS_I2C_CR_DIVB_MASK);
	ctrl_reg |= ((div_a << CDNS_I2C_CR_DIVA_SHIFT) |
			(div_b << CDNS_I2C_CR_DIVB_SHIFT));
	cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);

	return 0;
}

__attribute__((used)) static int cdns_i2c_clk_notifier_cb(struct notifier_block *nb, unsigned long
		event, void *data)
{
	struct clk_notifier_data *ndata = data;
	struct cdns_i2c *id = to_cdns_i2c(nb);

	if (pm_runtime_suspended(id->dev))
		return NOTIFY_OK;

	switch (event) {
	case PRE_RATE_CHANGE:
	{
		unsigned long input_clk = ndata->new_rate;
		unsigned long fscl = id->i2c_clk;
		unsigned int div_a, div_b;
		int ret;

		ret = cdns_i2c_calc_divs(&fscl, input_clk, &div_a, &div_b);
		if (ret) {
			dev_warn(id->adap.dev.parent,
					"clock rate change rejected\n");
			return NOTIFY_STOP;
		}

		/* scale up */
		if (ndata->new_rate > ndata->old_rate)
			cdns_i2c_setclk(ndata->new_rate, id);

		return NOTIFY_OK;
	}
	case POST_RATE_CHANGE:
		id->input_clk = ndata->new_rate;
		/* scale down */
		if (ndata->new_rate < ndata->old_rate)
			cdns_i2c_setclk(ndata->new_rate, id);
		return NOTIFY_OK;
	case ABORT_RATE_CHANGE:
		/* scale up */
		if (ndata->new_rate > ndata->old_rate)
			cdns_i2c_setclk(ndata->old_rate, id);
		return NOTIFY_OK;
	default:
		return NOTIFY_DONE;
	}
}

__attribute__((used)) static int cdns_i2c_probe(struct platform_device *pdev)
{
	struct resource *r_mem;
	struct cdns_i2c *id;
	int ret;
	const struct of_device_id *match;

	id = devm_kzalloc(&pdev->dev, sizeof(*id), GFP_KERNEL);
	if (!id)
		return -ENOMEM;

	id->dev = &pdev->dev;
	platform_set_drvdata(pdev, id);

	match = of_match_node(cdns_i2c_of_match, pdev->dev.of_node);
	if (match && match->data) {
		const struct cdns_platform_data *data = match->data;
		id->quirks = data->quirks;
	}

	r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	id->membase = devm_ioremap_resource(&pdev->dev, r_mem);
	if (IS_ERR(id->membase))
		return PTR_ERR(id->membase);

	id->irq = platform_get_irq(pdev, 0);

	id->adap.owner = THIS_MODULE;
	id->adap.dev.of_node = pdev->dev.of_node;
	id->adap.algo = &cdns_i2c_algo;
	id->adap.timeout = CDNS_I2C_TIMEOUT;
	id->adap.retries = 3;		/* Default retry value. */
	id->adap.algo_data = id;
	id->adap.dev.parent = &pdev->dev;
	init_completion(&id->xfer_done);
	snprintf(id->adap.name, sizeof(id->adap.name),
		 "Cadence I2C at %08lx", (unsigned long)r_mem->start);

	id->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(id->clk)) {
		dev_err(&pdev->dev, "input clock not found.\n");
		return PTR_ERR(id->clk);
	}
	ret = clk_prepare_enable(id->clk);
	if (ret)
		dev_err(&pdev->dev, "Unable to enable clock.\n");

	pm_runtime_enable(id->dev);
	pm_runtime_set_autosuspend_delay(id->dev, CNDS_I2C_PM_TIMEOUT);
	pm_runtime_use_autosuspend(id->dev);
	pm_runtime_set_active(id->dev);

	id->clk_rate_change_nb.notifier_call = cdns_i2c_clk_notifier_cb;
	if (clk_notifier_register(id->clk, &id->clk_rate_change_nb))
		dev_warn(&pdev->dev, "Unable to register clock notifier.\n");
	id->input_clk = clk_get_rate(id->clk);

	ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
			&id->i2c_clk);
	if (ret || (id->i2c_clk > CDNS_I2C_SPEED_MAX))
		id->i2c_clk = CDNS_I2C_SPEED_DEFAULT;

	cdns_i2c_writereg(CDNS_I2C_CR_ACK_EN | CDNS_I2C_CR_NEA | CDNS_I2C_CR_MS,
			  CDNS_I2C_CR_OFFSET);

	ret = cdns_i2c_setclk(id->input_clk, id);
	if (ret) {
		dev_err(&pdev->dev, "invalid SCL clock: %u Hz\n", id->i2c_clk);
		ret = -EINVAL;
		goto err_clk_dis;
	}

	ret = devm_request_irq(&pdev->dev, id->irq, cdns_i2c_isr, 0,
				 DRIVER_NAME, id);
	if (ret) {
		dev_err(&pdev->dev, "cannot get irq %d\n", id->irq);
		goto err_clk_dis;
	}

	/*
	 * Cadence I2C controller has a bug wherein it generates
	 * invalid read transaction after HW timeout in master receiver mode.
	 * HW timeout is not used by this driver and the interrupt is disabled.
	 * But the feature itself cannot be disabled. Hence maximum value
	 * is written to this register to reduce the chances of error.
	 */
	cdns_i2c_writereg(CDNS_I2C_TIMEOUT_MAX, CDNS_I2C_TIME_OUT_OFFSET);

	ret = i2c_add_adapter(&id->adap);
	if (ret < 0)
		goto err_clk_dis;

	dev_info(&pdev->dev, "%u kHz mmio %08lx irq %d\n",
		 id->i2c_clk / 1000, (unsigned long)r_mem->start, id->irq);

	return 0;

err_clk_dis:
	clk_disable_unprepare(id->clk);
	pm_runtime_set_suspended(&pdev->dev);
	pm_runtime_disable(&pdev->dev);
	return ret;
}

__attribute__((used)) static int cdns_i2c_remove(struct platform_device *pdev)
{
	struct cdns_i2c *id = platform_get_drvdata(pdev);

	i2c_del_adapter(&id->adap);
	clk_notifier_unregister(id->clk, &id->clk_rate_change_nb);
	clk_disable_unprepare(id->clk);
	pm_runtime_disable(&pdev->dev);

	return 0;
}

