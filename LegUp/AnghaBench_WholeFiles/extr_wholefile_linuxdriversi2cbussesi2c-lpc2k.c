#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_14__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; TYPE_5__* parent; } ;
struct TYPE_13__ {TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; int /*<<< orphan*/  owner; } ;
struct lpc2k_i2c {size_t msg_idx; int is_last; int msg_status; scalar_t__ irq; scalar_t__ clk; TYPE_2__ adap; scalar_t__ base; int /*<<< orphan*/  wait; struct i2c_msg* msg; } ;
struct i2c_msg {size_t len; int* buf; int flags; } ;
struct i2c_adapter {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EAGAIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FAST_MODE_DUTY ; 
 int I2C_FAST_MODE_PLUS_DUTY ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 int I2C_STD_MODE_DUTY ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int LPC24XX_AA ; 
 int LPC24XX_CLEAR_ALL ; 
 scalar_t__ LPC24XX_I2ADDR ; 
 scalar_t__ LPC24XX_I2CONCLR ; 
 scalar_t__ LPC24XX_I2CONSET ; 
 scalar_t__ LPC24XX_I2DAT ; 
 int LPC24XX_I2EN ; 
 scalar_t__ LPC24XX_I2SCLH ; 
 scalar_t__ LPC24XX_I2SCLL ; 
 scalar_t__ LPC24XX_I2STAT ; 
 int LPC24XX_SI ; 
 int LPC24XX_STA ; 
 int LPC24XX_STO ; 
 int LPC24XX_STO_AA ; 
#define  MR_ADDR_R_ACK 138 
#define  MR_ADDR_R_NACK 137 
#define  MR_DATA_R_ACK 136 
#define  MR_DATA_R_NACK 135 
#define  MX_ADDR_W_ACK 134 
#define  MX_ADDR_W_NACK 133 
#define  MX_DATA_W_ACK 132 
#define  MX_DATA_W_NACK 131 
#define  M_DATA_ARB_LOST 130 
 int M_I2C_IDLE ; 
#define  M_REPSTART 129 
#define  M_START 128 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_5__*) ; 
 scalar_t__ devm_clk_get (TYPE_5__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_5__*,struct resource*) ; 
 struct lpc2k_i2c* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_5__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lpc2k_i2c*) ; 
 int /*<<< orphan*/  disable_irq_nosync (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 unsigned char i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 struct lpc2k_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_lpc2k_algorithm ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_2__*,struct lpc2k_i2c*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 struct lpc2k_i2c* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lpc2k_i2c*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,unsigned long) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void i2c_lpc2k_reset(struct lpc2k_i2c *i2c)
{
	/* Will force clear all statuses */
	writel(LPC24XX_CLEAR_ALL, i2c->base + LPC24XX_I2CONCLR);
	writel(0, i2c->base + LPC24XX_I2ADDR);
	writel(LPC24XX_I2EN, i2c->base + LPC24XX_I2CONSET);
}

__attribute__((used)) static int i2c_lpc2k_clear_arb(struct lpc2k_i2c *i2c)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(1000);

	/*
	 * If the transfer needs to abort for some reason, we'll try to
	 * force a stop condition to clear any pending bus conditions
	 */
	writel(LPC24XX_STO, i2c->base + LPC24XX_I2CONSET);

	/* Wait for status change */
	while (readl(i2c->base + LPC24XX_I2STAT) != M_I2C_IDLE) {
		if (time_after(jiffies, timeout)) {
			/* Bus was not idle, try to reset adapter */
			i2c_lpc2k_reset(i2c);
			return -EBUSY;
		}

		cpu_relax();
	}

	return 0;
}

__attribute__((used)) static void i2c_lpc2k_pump_msg(struct lpc2k_i2c *i2c)
{
	unsigned char data;
	u32 status;

	/*
	 * I2C in the LPC2xxx series is basically a state machine.
	 * Just run through the steps based on the current status.
	 */
	status = readl(i2c->base + LPC24XX_I2STAT);

	switch (status) {
	case M_START:
	case M_REPSTART:
		/* Start bit was just sent out, send out addr and dir */
		data = i2c_8bit_addr_from_msg(i2c->msg);

		writel(data, i2c->base + LPC24XX_I2DAT);
		writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
		break;

	case MX_ADDR_W_ACK:
	case MX_DATA_W_ACK:
		/*
		 * Address or data was sent out with an ACK. If there is more
		 * data to send, send it now
		 */
		if (i2c->msg_idx < i2c->msg->len) {
			writel(i2c->msg->buf[i2c->msg_idx],
			       i2c->base + LPC24XX_I2DAT);
		} else if (i2c->is_last) {
			/* Last message, send stop */
			writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
			writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
			i2c->msg_status = 0;
			disable_irq_nosync(i2c->irq);
		} else {
			i2c->msg_status = 0;
			disable_irq_nosync(i2c->irq);
		}

		i2c->msg_idx++;
		break;

	case MR_ADDR_R_ACK:
		/* Receive first byte from slave */
		if (i2c->msg->len == 1) {
			/* Last byte, return NACK */
			writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONCLR);
		} else {
			/* Not last byte, return ACK */
			writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONSET);
		}

		writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
		break;

	case MR_DATA_R_NACK:
		/*
		 * The I2C shows NACK status on reads, so we need to accept
		 * the NACK as an ACK here. This should be ok, as the real
		 * BACK would of been caught on the address write.
		 */
	case MR_DATA_R_ACK:
		/* Data was received */
		if (i2c->msg_idx < i2c->msg->len) {
			i2c->msg->buf[i2c->msg_idx] =
					readl(i2c->base + LPC24XX_I2DAT);
		}

		/* If transfer is done, send STOP */
		if (i2c->msg_idx >= i2c->msg->len - 1 && i2c->is_last) {
			writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
			writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
			i2c->msg_status = 0;
		}

		/* Message is done */
		if (i2c->msg_idx >= i2c->msg->len - 1) {
			i2c->msg_status = 0;
			disable_irq_nosync(i2c->irq);
		}

		/*
		 * One pre-last data input, send NACK to tell the slave that
		 * this is going to be the last data byte to be transferred.
		 */
		if (i2c->msg_idx >= i2c->msg->len - 2) {
			/* One byte left to receive - NACK */
			writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONCLR);
		} else {
			/* More than one byte left to receive - ACK */
			writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONSET);
		}

		writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
		i2c->msg_idx++;
		break;

	case MX_ADDR_W_NACK:
	case MX_DATA_W_NACK:
	case MR_ADDR_R_NACK:
		/* NACK processing is done */
		writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
		i2c->msg_status = -ENXIO;
		disable_irq_nosync(i2c->irq);
		break;

	case M_DATA_ARB_LOST:
		/* Arbitration lost */
		i2c->msg_status = -EAGAIN;

		/* Release the I2C bus */
		writel(LPC24XX_STA | LPC24XX_STO, i2c->base + LPC24XX_I2CONCLR);
		disable_irq_nosync(i2c->irq);
		break;

	default:
		/* Unexpected statuses */
		i2c->msg_status = -EIO;
		disable_irq_nosync(i2c->irq);
		break;
	}

	/* Exit on failure or all bytes transferred */
	if (i2c->msg_status != -EBUSY)
		wake_up(&i2c->wait);

	/*
	 * If `msg_status` is zero, then `lpc2k_process_msg()`
	 * is responsible for clearing the SI flag.
	 */
	if (i2c->msg_status != 0)
		writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
}

__attribute__((used)) static int lpc2k_process_msg(struct lpc2k_i2c *i2c, int msgidx)
{
	/* A new transfer is kicked off by initiating a start condition */
	if (!msgidx) {
		writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONSET);
	} else {
		/*
		 * A multi-message I2C transfer continues where the
		 * previous I2C transfer left off and uses the
		 * current condition of the I2C adapter.
		 */
		if (unlikely(i2c->msg->flags & I2C_M_NOSTART)) {
			WARN_ON(i2c->msg->len == 0);

			if (!(i2c->msg->flags & I2C_M_RD)) {
				/* Start transmit of data */
				writel(i2c->msg->buf[0],
				       i2c->base + LPC24XX_I2DAT);
				i2c->msg_idx++;
			}
		} else {
			/* Start or repeated start */
			writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONSET);
		}

		writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
	}

	enable_irq(i2c->irq);

	/* Wait for transfer completion */
	if (wait_event_timeout(i2c->wait, i2c->msg_status != -EBUSY,
			       msecs_to_jiffies(1000)) == 0) {
		disable_irq_nosync(i2c->irq);

		return -ETIMEDOUT;
	}

	return i2c->msg_status;
}

__attribute__((used)) static int i2c_lpc2k_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
			  int msg_num)
{
	struct lpc2k_i2c *i2c = i2c_get_adapdata(adap);
	int ret, i;
	u32 stat;

	/* Check for bus idle condition */
	stat = readl(i2c->base + LPC24XX_I2STAT);
	if (stat != M_I2C_IDLE) {
		/* Something is holding the bus, try to clear it */
		return i2c_lpc2k_clear_arb(i2c);
	}

	/* Process a single message at a time */
	for (i = 0; i < msg_num; i++) {
		/* Save message pointer and current message data index */
		i2c->msg = &msgs[i];
		i2c->msg_idx = 0;
		i2c->msg_status = -EBUSY;
		i2c->is_last = (i == (msg_num - 1));

		ret = lpc2k_process_msg(i2c, i);
		if (ret)
			return ret;
	}

	return msg_num;
}

__attribute__((used)) static irqreturn_t i2c_lpc2k_handler(int irq, void *dev_id)
{
	struct lpc2k_i2c *i2c = dev_id;

	if (readl(i2c->base + LPC24XX_I2CONSET) & LPC24XX_SI) {
		i2c_lpc2k_pump_msg(i2c);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static u32 i2c_lpc2k_functionality(struct i2c_adapter *adap)
{
	/* Only emulated SMBus for now */
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int i2c_lpc2k_probe(struct platform_device *pdev)
{
	struct lpc2k_i2c *i2c;
	struct resource *res;
	u32 bus_clk_rate;
	u32 scl_high;
	u32 clkrate;
	int ret;

	i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(i2c->base))
		return PTR_ERR(i2c->base);

	i2c->irq = platform_get_irq(pdev, 0);
	if (i2c->irq < 0) {
		dev_err(&pdev->dev, "can't get interrupt resource\n");
		return i2c->irq;
	}

	init_waitqueue_head(&i2c->wait);

	i2c->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(i2c->clk)) {
		dev_err(&pdev->dev, "error getting clock\n");
		return PTR_ERR(i2c->clk);
	}

	ret = clk_prepare_enable(i2c->clk);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable clock.\n");
		return ret;
	}

	ret = devm_request_irq(&pdev->dev, i2c->irq, i2c_lpc2k_handler, 0,
			       dev_name(&pdev->dev), i2c);
	if (ret < 0) {
		dev_err(&pdev->dev, "can't request interrupt.\n");
		goto fail_clk;
	}

	disable_irq_nosync(i2c->irq);

	/* Place controller is a known state */
	i2c_lpc2k_reset(i2c);

	ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
				   &bus_clk_rate);
	if (ret)
		bus_clk_rate = 100000; /* 100 kHz default clock rate */

	clkrate = clk_get_rate(i2c->clk);
	if (clkrate == 0) {
		dev_err(&pdev->dev, "can't get I2C base clock\n");
		ret = -EINVAL;
		goto fail_clk;
	}

	/* Setup I2C dividers to generate clock with proper duty cycle */
	clkrate = clkrate / bus_clk_rate;
	if (bus_clk_rate <= 100000)
		scl_high = (clkrate * I2C_STD_MODE_DUTY) / 100;
	else if (bus_clk_rate <= 400000)
		scl_high = (clkrate * I2C_FAST_MODE_DUTY) / 100;
	else
		scl_high = (clkrate * I2C_FAST_MODE_PLUS_DUTY) / 100;

	writel(scl_high, i2c->base + LPC24XX_I2SCLH);
	writel(clkrate - scl_high, i2c->base + LPC24XX_I2SCLL);

	platform_set_drvdata(pdev, i2c);

	i2c_set_adapdata(&i2c->adap, i2c);
	i2c->adap.owner = THIS_MODULE;
	strlcpy(i2c->adap.name, "LPC2K I2C adapter", sizeof(i2c->adap.name));
	i2c->adap.algo = &i2c_lpc2k_algorithm;
	i2c->adap.dev.parent = &pdev->dev;
	i2c->adap.dev.of_node = pdev->dev.of_node;

	ret = i2c_add_adapter(&i2c->adap);
	if (ret < 0)
		goto fail_clk;

	dev_info(&pdev->dev, "LPC2K I2C adapter\n");

	return 0;

fail_clk:
	clk_disable_unprepare(i2c->clk);
	return ret;
}

__attribute__((used)) static int i2c_lpc2k_remove(struct platform_device *dev)
{
	struct lpc2k_i2c *i2c = platform_get_drvdata(dev);

	i2c_del_adapter(&i2c->adap);
	clk_disable_unprepare(i2c->clk);

	return 0;
}

