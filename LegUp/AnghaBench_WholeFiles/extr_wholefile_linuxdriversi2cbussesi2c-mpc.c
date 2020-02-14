#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct resource {scalar_t__ start; } ;
struct TYPE_12__ {struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct of_device_id {struct mpc_i2c_data* data; } ;
struct mpc_i2c_data {int /*<<< orphan*/  (* setup ) (struct device_node*,struct mpc_i2c*,int) ;} ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct TYPE_13__ {unsigned int timeout; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct mpc_i2c {int interrupt; int real_clk; scalar_t__ base; scalar_t__ irq; struct clk* clk_per; TYPE_3__ adap; TYPE_2__* dev; int /*<<< orphan*/  queue; } ;
struct i2c_msg {int flags; int len; int addr; int* buf; } ;
struct i2c_adapter {int dummy; } ;
struct device_node {int dummy; } ;
struct clk {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int CCR_MEN ; 
 int CCR_MIEN ; 
 int CCR_MSTA ; 
 int CCR_MTX ; 
 int CCR_RSTA ; 
 int CCR_TXAK ; 
 int CSR_MAL ; 
 int CSR_MBB ; 
 int CSR_MCF ; 
 int CSR_MIF ; 
 int CSR_RXAK ; 
 int EAGAIN ; 
 int EINTR ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long HZ ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BLOCK_PROC_CALL ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_FUNC_SMBUS_READ_BLOCK_DATA ; 
 int I2C_M_RD ; 
 int I2C_M_RECV_LEN ; 
 int I2C_SMBUS_BLOCK_MAX ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IS_ERR (struct clk*) ; 
 int MPC_I2C_CLOCK_LEGACY ; 
 int MPC_I2C_CLOCK_PRESERVE ; 
 scalar_t__ MPC_I2C_CR ; 
 scalar_t__ MPC_I2C_DR ; 
 scalar_t__ MPC_I2C_SR ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct clk*) ; 
 int clk_prepare_enable (struct clk*) ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int) ; 
 struct clk* devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct mpc_i2c*) ; 
 int i2c_add_adapter (TYPE_3__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_3__*) ; 
 struct mpc_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_3__*,struct mpc_i2c*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  irq_dispose_mapping (scalar_t__) ; 
 scalar_t__ irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kfree (struct mpc_i2c*) ; 
 struct mpc_i2c* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpc_i2c_of_match ; 
 TYPE_3__ mpc_ops ; 
 int /*<<< orphan*/  of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 int* of_get_property (struct device_node*,char*,int*) ; 
 scalar_t__ of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  of_node_get (struct device_node*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 struct mpc_i2c* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mpc_i2c*) ; 
 int readb (scalar_t__) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct mpc_i2c*) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  scnprintf (int /*<<< orphan*/ ,int,char*,unsigned long long) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct device_node*,struct mpc_i2c*,int) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ unlikely (int) ; 
 int wait_event_timeout (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writeb (int const,scalar_t__) ; 

__attribute__((used)) static inline void writeccr(struct mpc_i2c *i2c, u32 x)
{
	writeb(x, i2c->base + MPC_I2C_CR);
}

__attribute__((used)) static irqreturn_t mpc_i2c_isr(int irq, void *dev_id)
{
	struct mpc_i2c *i2c = dev_id;
	if (readb(i2c->base + MPC_I2C_SR) & CSR_MIF) {
		/* Read again to allow register to stabilise */
		i2c->interrupt = readb(i2c->base + MPC_I2C_SR);
		writeb(0, i2c->base + MPC_I2C_SR);
		wake_up(&i2c->queue);
		return IRQ_HANDLED;
	}
	return IRQ_NONE;
}

__attribute__((used)) static void mpc_i2c_fixup(struct mpc_i2c *i2c)
{
	int k;
	u32 delay_val = 1000000 / i2c->real_clk + 1;

	if (delay_val < 2)
		delay_val = 2;

	for (k = 9; k; k--) {
		writeccr(i2c, 0);
		writeccr(i2c, CCR_MSTA | CCR_MTX | CCR_MEN);
		readb(i2c->base + MPC_I2C_DR);
		writeccr(i2c, CCR_MEN);
		udelay(delay_val << 1);
	}
}

__attribute__((used)) static int i2c_wait(struct mpc_i2c *i2c, unsigned timeout, int writing)
{
	unsigned long orig_jiffies = jiffies;
	u32 cmd_err;
	int result = 0;

	if (!i2c->irq) {
		while (!(readb(i2c->base + MPC_I2C_SR) & CSR_MIF)) {
			schedule();
			if (time_after(jiffies, orig_jiffies + timeout)) {
				dev_dbg(i2c->dev, "timeout\n");
				writeccr(i2c, 0);
				result = -ETIMEDOUT;
				break;
			}
		}
		cmd_err = readb(i2c->base + MPC_I2C_SR);
		writeb(0, i2c->base + MPC_I2C_SR);
	} else {
		/* Interrupt mode */
		result = wait_event_timeout(i2c->queue,
			(i2c->interrupt & CSR_MIF), timeout);

		if (unlikely(!(i2c->interrupt & CSR_MIF))) {
			dev_dbg(i2c->dev, "wait timeout\n");
			writeccr(i2c, 0);
			result = -ETIMEDOUT;
		}

		cmd_err = i2c->interrupt;
		i2c->interrupt = 0;
	}

	if (result < 0)
		return result;

	if (!(cmd_err & CSR_MCF)) {
		dev_dbg(i2c->dev, "unfinished\n");
		return -EIO;
	}

	if (cmd_err & CSR_MAL) {
		dev_dbg(i2c->dev, "MAL\n");
		return -EAGAIN;
	}

	if (writing && (cmd_err & CSR_RXAK)) {
		dev_dbg(i2c->dev, "No RXAK\n");
		/* generate stop */
		writeccr(i2c, CCR_MEN);
		return -ENXIO;
	}
	return 0;
}

__attribute__((used)) static void mpc_i2c_setup_52xx(struct device_node *node,
					 struct mpc_i2c *i2c,
					 u32 clock)
{
}

__attribute__((used)) static void mpc_i2c_setup_512x(struct device_node *node,
					 struct mpc_i2c *i2c,
					 u32 clock)
{
}

__attribute__((used)) static void mpc_i2c_setup_8xxx(struct device_node *node,
					 struct mpc_i2c *i2c,
					 u32 clock)
{
}

__attribute__((used)) static void mpc_i2c_start(struct mpc_i2c *i2c)
{
	/* Clear arbitration */
	writeb(0, i2c->base + MPC_I2C_SR);
	/* Start with MEN */
	writeccr(i2c, CCR_MEN);
}

__attribute__((used)) static void mpc_i2c_stop(struct mpc_i2c *i2c)
{
	writeccr(i2c, CCR_MEN);
}

__attribute__((used)) static int mpc_write(struct mpc_i2c *i2c, int target,
		     const u8 *data, int length, int restart)
{
	int i, result;
	unsigned timeout = i2c->adap.timeout;
	u32 flags = restart ? CCR_RSTA : 0;

	/* Start as master */
	writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_MTX | flags);
	/* Write target byte */
	writeb((target << 1), i2c->base + MPC_I2C_DR);

	result = i2c_wait(i2c, timeout, 1);
	if (result < 0)
		return result;

	for (i = 0; i < length; i++) {
		/* Write data byte */
		writeb(data[i], i2c->base + MPC_I2C_DR);

		result = i2c_wait(i2c, timeout, 1);
		if (result < 0)
			return result;
	}

	return 0;
}

__attribute__((used)) static int mpc_read(struct mpc_i2c *i2c, int target,
		    u8 *data, int length, int restart, bool recv_len)
{
	unsigned timeout = i2c->adap.timeout;
	int i, result;
	u32 flags = restart ? CCR_RSTA : 0;

	/* Switch to read - restart */
	writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_MTX | flags);
	/* Write target address byte - this time with the read flag set */
	writeb((target << 1) | 1, i2c->base + MPC_I2C_DR);

	result = i2c_wait(i2c, timeout, 1);
	if (result < 0)
		return result;

	if (length) {
		if (length == 1 && !recv_len)
			writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_TXAK);
		else
			writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA);
		/* Dummy read */
		readb(i2c->base + MPC_I2C_DR);
	}

	for (i = 0; i < length; i++) {
		u8 byte;

		result = i2c_wait(i2c, timeout, 0);
		if (result < 0)
			return result;

		/*
		 * For block reads, we have to know the total length (1st byte)
		 * before we can determine if we are done.
		 */
		if (i || !recv_len) {
			/* Generate txack on next to last byte */
			if (i == length - 2)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_TXAK);
			/* Do not generate stop on last byte */
			if (i == length - 1)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_MTX);
		}

		byte = readb(i2c->base + MPC_I2C_DR);

		/*
		 * Adjust length if first received byte is length.
		 * The length is 1 length byte plus actually data length
		 */
		if (i == 0 && recv_len) {
			if (byte == 0 || byte > I2C_SMBUS_BLOCK_MAX)
				return -EPROTO;
			length += byte;
			/*
			 * For block reads, generate txack here if data length
			 * is 1 byte (total length is 2 bytes).
			 */
			if (length == 2)
				writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
					 | CCR_TXAK);
		}
		data[i] = byte;
	}

	return length;
}

__attribute__((used)) static int mpc_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	struct i2c_msg *pmsg;
	int i;
	int ret = 0;
	unsigned long orig_jiffies = jiffies;
	struct mpc_i2c *i2c = i2c_get_adapdata(adap);

	mpc_i2c_start(i2c);

	/* Allow bus up to 1s to become not busy */
	while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
		if (signal_pending(current)) {
			dev_dbg(i2c->dev, "Interrupted\n");
			writeccr(i2c, 0);
			return -EINTR;
		}
		if (time_after(jiffies, orig_jiffies + HZ)) {
			u8 status = readb(i2c->base + MPC_I2C_SR);

			dev_dbg(i2c->dev, "timeout\n");
			if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
				writeb(status & ~CSR_MAL,
				       i2c->base + MPC_I2C_SR);
				mpc_i2c_fixup(i2c);
			}
			return -EIO;
		}
		schedule();
	}

	for (i = 0; ret >= 0 && i < num; i++) {
		pmsg = &msgs[i];
		dev_dbg(i2c->dev,
			"Doing %s %d bytes to 0x%02x - %d of %d messages\n",
			pmsg->flags & I2C_M_RD ? "read" : "write",
			pmsg->len, pmsg->addr, i + 1, num);
		if (pmsg->flags & I2C_M_RD) {
			bool recv_len = pmsg->flags & I2C_M_RECV_LEN;

			ret = mpc_read(i2c, pmsg->addr, pmsg->buf, pmsg->len, i,
				       recv_len);
			if (recv_len && ret > 0)
				pmsg->len = ret;
		} else {
			ret =
			    mpc_write(i2c, pmsg->addr, pmsg->buf, pmsg->len, i);
		}
	}
	mpc_i2c_stop(i2c); /* Initiate STOP */
	orig_jiffies = jiffies;
	/* Wait until STOP is seen, allow up to 1 s */
	while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
		if (time_after(jiffies, orig_jiffies + HZ)) {
			u8 status = readb(i2c->base + MPC_I2C_SR);

			dev_dbg(i2c->dev, "timeout\n");
			if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
				writeb(status & ~CSR_MAL,
				       i2c->base + MPC_I2C_SR);
				mpc_i2c_fixup(i2c);
			}
			return -EIO;
		}
		cond_resched();
	}
	return (ret < 0) ? ret : num;
}

__attribute__((used)) static u32 mpc_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL
	  | I2C_FUNC_SMBUS_READ_BLOCK_DATA | I2C_FUNC_SMBUS_BLOCK_PROC_CALL;
}

__attribute__((used)) static int fsl_i2c_probe(struct platform_device *op)
{
	const struct of_device_id *match;
	struct mpc_i2c *i2c;
	const u32 *prop;
	u32 clock = MPC_I2C_CLOCK_LEGACY;
	int result = 0;
	int plen;
	struct resource res;
	struct clk *clk;
	int err;

	match = of_match_device(mpc_i2c_of_match, &op->dev);
	if (!match)
		return -EINVAL;

	i2c = kzalloc(sizeof(*i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	i2c->dev = &op->dev; /* for debug and error output */

	init_waitqueue_head(&i2c->queue);

	i2c->base = of_iomap(op->dev.of_node, 0);
	if (!i2c->base) {
		dev_err(i2c->dev, "failed to map controller\n");
		result = -ENOMEM;
		goto fail_map;
	}

	i2c->irq = irq_of_parse_and_map(op->dev.of_node, 0);
	if (i2c->irq) { /* no i2c->irq implies polling */
		result = request_irq(i2c->irq, mpc_i2c_isr,
				     IRQF_SHARED, "i2c-mpc", i2c);
		if (result < 0) {
			dev_err(i2c->dev, "failed to attach interrupt\n");
			goto fail_request;
		}
	}

	/*
	 * enable clock for the I2C peripheral (non fatal),
	 * keep a reference upon successful allocation
	 */
	clk = devm_clk_get(&op->dev, NULL);
	if (!IS_ERR(clk)) {
		err = clk_prepare_enable(clk);
		if (err) {
			dev_err(&op->dev, "failed to enable clock\n");
			goto fail_request;
		} else {
			i2c->clk_per = clk;
		}
	}

	if (of_property_read_bool(op->dev.of_node, "fsl,preserve-clocking")) {
		clock = MPC_I2C_CLOCK_PRESERVE;
	} else {
		prop = of_get_property(op->dev.of_node, "clock-frequency",
					&plen);
		if (prop && plen == sizeof(u32))
			clock = *prop;
	}

	if (match->data) {
		const struct mpc_i2c_data *data = match->data;
		data->setup(op->dev.of_node, i2c, clock);
	} else {
		/* Backwards compatibility */
		if (of_get_property(op->dev.of_node, "dfsrr", NULL))
			mpc_i2c_setup_8xxx(op->dev.of_node, i2c, clock);
	}

	prop = of_get_property(op->dev.of_node, "fsl,timeout", &plen);
	if (prop && plen == sizeof(u32)) {
		mpc_ops.timeout = *prop * HZ / 1000000;
		if (mpc_ops.timeout < 5)
			mpc_ops.timeout = 5;
	}
	dev_info(i2c->dev, "timeout %u us\n", mpc_ops.timeout * 1000000 / HZ);

	platform_set_drvdata(op, i2c);

	i2c->adap = mpc_ops;
	of_address_to_resource(op->dev.of_node, 0, &res);
	scnprintf(i2c->adap.name, sizeof(i2c->adap.name),
		  "MPC adapter at 0x%llx", (unsigned long long)res.start);
	i2c_set_adapdata(&i2c->adap, i2c);
	i2c->adap.dev.parent = &op->dev;
	i2c->adap.dev.of_node = of_node_get(op->dev.of_node);

	result = i2c_add_adapter(&i2c->adap);
	if (result < 0)
		goto fail_add;

	return result;

 fail_add:
	if (i2c->clk_per)
		clk_disable_unprepare(i2c->clk_per);
	free_irq(i2c->irq, i2c);
 fail_request:
	irq_dispose_mapping(i2c->irq);
	iounmap(i2c->base);
 fail_map:
	kfree(i2c);
	return result;
}

__attribute__((used)) static int fsl_i2c_remove(struct platform_device *op)
{
	struct mpc_i2c *i2c = platform_get_drvdata(op);

	i2c_del_adapter(&i2c->adap);

	if (i2c->clk_per)
		clk_disable_unprepare(i2c->clk_per);

	if (i2c->irq)
		free_irq(i2c->irq, i2c);

	irq_dispose_mapping(i2c->irq);
	iounmap(i2c->base);
	kfree(i2c);
	return 0;
}

