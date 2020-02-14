#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_16__ {struct TYPE_16__* parent; } ;
struct TYPE_15__ {TYPE_5__ dev; int /*<<< orphan*/  nr; } ;
struct synquacer_i2c {int msg_idx; int msg_num; int msg_ptr; int base; int state; int pclkrate; int speed_khz; unsigned long timeout_ms; int pclk; TYPE_1__ adapter; int /*<<< orphan*/  completion; TYPE_5__* dev; int /*<<< orphan*/  irq; struct i2c_msg* msg; scalar_t__ is_suspended; } ;
struct resource {int dummy; } ;
struct platform_device {TYPE_5__ dev; int /*<<< orphan*/  id; } ;
struct i2c_msg {int len; int addr; int flags; unsigned char* buf; } ;
struct i2c_adapter {int retries; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned long DIV_ROUND_UP (int,int) ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int) ; 
 int /*<<< orphan*/  IS_ERR_OR_NULL (int) ; 
 int PTR_ERR (int) ; 
 void* STATE_IDLE ; 
#define  STATE_READ 132 
#define  STATE_START 131 
#define  STATE_WRITE 130 
 unsigned char SYNQUACER_I2C_BCR_ACK ; 
 unsigned char SYNQUACER_I2C_BCR_BEIE ; 
 unsigned char SYNQUACER_I2C_BCR_BER ; 
 unsigned char SYNQUACER_I2C_BCR_INTE ; 
 unsigned char SYNQUACER_I2C_BCR_MSS ; 
 unsigned char SYNQUACER_I2C_BCR_SCC ; 
 unsigned char SYNQUACER_I2C_BSR_AL ; 
 unsigned char SYNQUACER_I2C_BSR_BB ; 
 unsigned char SYNQUACER_I2C_BSR_FBT ; 
 unsigned char SYNQUACER_I2C_BSR_LRB ; 
 unsigned char SYNQUACER_I2C_BUS_CLK_FR (int) ; 
 unsigned char SYNQUACER_I2C_CCR_CS_FAST_MAX_18M (int) ; 
 unsigned char SYNQUACER_I2C_CCR_CS_FAST_MIN_18M (int) ; 
 unsigned char SYNQUACER_I2C_CCR_CS_STD_MAX_18M (int) ; 
 unsigned char SYNQUACER_I2C_CCR_CS_STD_MIN_18M (int) ; 
 unsigned char SYNQUACER_I2C_CCR_EN ; 
 unsigned char SYNQUACER_I2C_CCR_FM ; 
 int SYNQUACER_I2C_CLK_RATE_18M ; 
 unsigned char SYNQUACER_I2C_CSR_CS_FAST_MAX_18M (int) ; 
 unsigned char SYNQUACER_I2C_CSR_CS_FAST_MIN_18M (int) ; 
 unsigned char SYNQUACER_I2C_CSR_CS_STD_MAX_18M (int) ; 
 unsigned char SYNQUACER_I2C_CSR_CS_STD_MIN_18M (int) ; 
 int SYNQUACER_I2C_MAX_CLK_RATE ; 
 int SYNQUACER_I2C_MIN_CLK_RATE ; 
 int SYNQUACER_I2C_REG_ADR ; 
 int SYNQUACER_I2C_REG_BC2R ; 
 int SYNQUACER_I2C_REG_BCR ; 
 int SYNQUACER_I2C_REG_BSR ; 
 int SYNQUACER_I2C_REG_CCR ; 
 int SYNQUACER_I2C_REG_CSR ; 
 int SYNQUACER_I2C_REG_DAR ; 
 int SYNQUACER_I2C_REG_FSR ; 
#define  SYNQUACER_I2C_SPEED_FM 129 
#define  SYNQUACER_I2C_SPEED_SM 128 
 int /*<<< orphan*/  WAIT_PCLK (int,int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 int clk_get_rate (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_5__*) ; 
 int /*<<< orphan*/  device_property_read_u32 (TYPE_5__*,char*,int*) ; 
 int devm_clk_get (TYPE_5__*,char*) ; 
 int devm_ioremap_resource (TYPE_5__*,struct resource*) ; 
 struct synquacer_i2c* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct synquacer_i2c*) ; 
 unsigned char i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int i2c_acpi_find_bus_speed (TYPE_5__*) ; 
 int i2c_add_numbered_adapter (TYPE_1__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_1__*) ; 
 struct synquacer_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_1__*,struct synquacer_i2c*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned long) ; 
 struct synquacer_i2c* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct synquacer_i2c*) ; 
 unsigned char readb (int) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 TYPE_1__ synquacer_i2c_ops ; 
 int /*<<< orphan*/  udelay (unsigned long) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (unsigned char,int) ; 

__attribute__((used)) static inline int is_lastmsg(struct synquacer_i2c *i2c)
{
	return i2c->msg_idx >= (i2c->msg_num - 1);
}

__attribute__((used)) static inline int is_msglast(struct synquacer_i2c *i2c)
{
	return i2c->msg_ptr == (i2c->msg->len - 1);
}

__attribute__((used)) static inline int is_msgend(struct synquacer_i2c *i2c)
{
	return i2c->msg_ptr >= i2c->msg->len;
}

__attribute__((used)) static inline unsigned long calc_timeout_ms(struct synquacer_i2c *i2c,
					    struct i2c_msg *msgs,
					    int num)
{
	unsigned long bit_count = 0;
	int i;

	for (i = 0; i < num; i++, msgs++)
		bit_count += msgs->len;

	return DIV_ROUND_UP((bit_count * 9 + num * 10) * 3, 200) + 10;
}

__attribute__((used)) static void synquacer_i2c_stop(struct synquacer_i2c *i2c, int ret)
{
	/*
	 * clear IRQ (INT=0, BER=0)
	 * set Stop Condition (MSS=0)
	 * Interrupt Disable
	 */
	writeb(0, i2c->base + SYNQUACER_I2C_REG_BCR);

	i2c->state = STATE_IDLE;

	i2c->msg_ptr = 0;
	i2c->msg = NULL;
	i2c->msg_idx++;
	i2c->msg_num = 0;
	if (ret)
		i2c->msg_idx = ret;

	complete(&i2c->completion);
}

__attribute__((used)) static void synquacer_i2c_hw_init(struct synquacer_i2c *i2c)
{
	unsigned char ccr_cs, csr_cs;
	u32 rt = i2c->pclkrate;

	/* Set own Address */
	writeb(0, i2c->base + SYNQUACER_I2C_REG_ADR);

	/* Set PCLK frequency */
	writeb(SYNQUACER_I2C_BUS_CLK_FR(i2c->pclkrate),
	       i2c->base + SYNQUACER_I2C_REG_FSR);

	switch (i2c->speed_khz) {
	case SYNQUACER_I2C_SPEED_FM:
		if (i2c->pclkrate <= SYNQUACER_I2C_CLK_RATE_18M) {
			ccr_cs = SYNQUACER_I2C_CCR_CS_FAST_MAX_18M(rt);
			csr_cs = SYNQUACER_I2C_CSR_CS_FAST_MAX_18M(rt);
		} else {
			ccr_cs = SYNQUACER_I2C_CCR_CS_FAST_MIN_18M(rt);
			csr_cs = SYNQUACER_I2C_CSR_CS_FAST_MIN_18M(rt);
		}

		/* Set Clock and enable, Set fast mode */
		writeb(ccr_cs | SYNQUACER_I2C_CCR_FM |
		       SYNQUACER_I2C_CCR_EN,
		       i2c->base + SYNQUACER_I2C_REG_CCR);
		writeb(csr_cs, i2c->base + SYNQUACER_I2C_REG_CSR);
		break;
	case SYNQUACER_I2C_SPEED_SM:
		if (i2c->pclkrate <= SYNQUACER_I2C_CLK_RATE_18M) {
			ccr_cs = SYNQUACER_I2C_CCR_CS_STD_MAX_18M(rt);
			csr_cs = SYNQUACER_I2C_CSR_CS_STD_MAX_18M(rt);
		} else {
			ccr_cs = SYNQUACER_I2C_CCR_CS_STD_MIN_18M(rt);
			csr_cs = SYNQUACER_I2C_CSR_CS_STD_MIN_18M(rt);
		}

		/* Set Clock and enable, Set standard mode */
		writeb(ccr_cs | SYNQUACER_I2C_CCR_EN,
		      i2c->base + SYNQUACER_I2C_REG_CCR);
		writeb(csr_cs, i2c->base + SYNQUACER_I2C_REG_CSR);
		break;
	default:
		WARN_ON(1);
	}

	/* clear IRQ (INT=0, BER=0), Interrupt Disable */
	writeb(0, i2c->base + SYNQUACER_I2C_REG_BCR);
	writeb(0, i2c->base + SYNQUACER_I2C_REG_BC2R);
}

__attribute__((used)) static void synquacer_i2c_hw_reset(struct synquacer_i2c *i2c)
{
	/* Disable clock */
	writeb(0, i2c->base + SYNQUACER_I2C_REG_CCR);
	writeb(0, i2c->base + SYNQUACER_I2C_REG_CSR);

	WAIT_PCLK(100, i2c->pclkrate);
}

__attribute__((used)) static int synquacer_i2c_master_start(struct synquacer_i2c *i2c,
				      struct i2c_msg *pmsg)
{
	unsigned char bsr, bcr;

	writeb(i2c_8bit_addr_from_msg(pmsg), i2c->base + SYNQUACER_I2C_REG_DAR);

	dev_dbg(i2c->dev, "slave:0x%02x\n", pmsg->addr);

	/* Generate Start Condition */
	bsr = readb(i2c->base + SYNQUACER_I2C_REG_BSR);
	bcr = readb(i2c->base + SYNQUACER_I2C_REG_BCR);
	dev_dbg(i2c->dev, "bsr:0x%02x, bcr:0x%02x\n", bsr, bcr);

	if ((bsr & SYNQUACER_I2C_BSR_BB) &&
	    !(bcr & SYNQUACER_I2C_BCR_MSS)) {
		dev_dbg(i2c->dev, "bus is busy");
		return -EBUSY;
	}

	if (bsr & SYNQUACER_I2C_BSR_BB) { /* Bus is busy */
		dev_dbg(i2c->dev, "Continuous Start");
		writeb(bcr | SYNQUACER_I2C_BCR_SCC,
		       i2c->base + SYNQUACER_I2C_REG_BCR);
	} else {
		if (bcr & SYNQUACER_I2C_BCR_MSS) {
			dev_dbg(i2c->dev, "not in master mode");
			return -EAGAIN;
		}
		dev_dbg(i2c->dev, "Start Condition");
		/* Start Condition + Enable Interrupts */
		writeb(bcr | SYNQUACER_I2C_BCR_MSS |
		       SYNQUACER_I2C_BCR_INTE | SYNQUACER_I2C_BCR_BEIE,
		       i2c->base + SYNQUACER_I2C_REG_BCR);
	}

	WAIT_PCLK(10, i2c->pclkrate);

	/* get BSR & BCR registers */
	bsr = readb(i2c->base + SYNQUACER_I2C_REG_BSR);
	bcr = readb(i2c->base + SYNQUACER_I2C_REG_BCR);
	dev_dbg(i2c->dev, "bsr:0x%02x, bcr:0x%02x\n", bsr, bcr);

	if ((bsr & SYNQUACER_I2C_BSR_AL) ||
	    !(bcr & SYNQUACER_I2C_BCR_MSS)) {
		dev_dbg(i2c->dev, "arbitration lost\n");
		return -EAGAIN;
	}

	return 0;
}

__attribute__((used)) static int synquacer_i2c_doxfer(struct synquacer_i2c *i2c,
				struct i2c_msg *msgs, int num)
{
	unsigned char bsr;
	unsigned long timeout;
	int ret;

	if (i2c->is_suspended)
		return -EBUSY;

	synquacer_i2c_hw_init(i2c);
	bsr = readb(i2c->base + SYNQUACER_I2C_REG_BSR);
	if (bsr & SYNQUACER_I2C_BSR_BB) {
		dev_err(i2c->dev, "cannot get bus (bus busy)\n");
		return -EBUSY;
	}

	reinit_completion(&i2c->completion);

	i2c->msg = msgs;
	i2c->msg_num = num;
	i2c->msg_ptr = 0;
	i2c->msg_idx = 0;
	i2c->state = STATE_START;

	ret = synquacer_i2c_master_start(i2c, i2c->msg);
	if (ret < 0) {
		dev_dbg(i2c->dev, "Address failed: (%d)\n", ret);
		return ret;
	}

	timeout = wait_for_completion_timeout(&i2c->completion,
					msecs_to_jiffies(i2c->timeout_ms));
	if (timeout == 0) {
		dev_dbg(i2c->dev, "timeout\n");
		return -EAGAIN;
	}

	ret = i2c->msg_idx;
	if (ret != num) {
		dev_dbg(i2c->dev, "incomplete xfer (%d)\n", ret);
		return -EAGAIN;
	}

	/* wait 2 clock periods to ensure the stop has been through the bus */
	udelay(DIV_ROUND_UP(2 * 1000, i2c->speed_khz));

	return 0;
}

__attribute__((used)) static irqreturn_t synquacer_i2c_isr(int irq, void *dev_id)
{
	struct synquacer_i2c *i2c = dev_id;

	unsigned char byte;
	unsigned char bsr, bcr;
	int ret;

	bcr = readb(i2c->base + SYNQUACER_I2C_REG_BCR);
	bsr = readb(i2c->base + SYNQUACER_I2C_REG_BSR);
	dev_dbg(i2c->dev, "bsr:0x%02x, bcr:0x%02x\n", bsr, bcr);

	if (bcr & SYNQUACER_I2C_BCR_BER) {
		dev_err(i2c->dev, "bus error\n");
		synquacer_i2c_stop(i2c, -EAGAIN);
		goto out;
	}
	if ((bsr & SYNQUACER_I2C_BSR_AL) ||
	    !(bcr & SYNQUACER_I2C_BCR_MSS)) {
		dev_dbg(i2c->dev, "arbitration lost\n");
		synquacer_i2c_stop(i2c, -EAGAIN);
		goto out;
	}

	switch (i2c->state) {
	case STATE_START:
		if (bsr & SYNQUACER_I2C_BSR_LRB) {
			dev_dbg(i2c->dev, "ack was not received\n");
			synquacer_i2c_stop(i2c, -EAGAIN);
			goto out;
		}

		if (i2c->msg->flags & I2C_M_RD)
			i2c->state = STATE_READ;
		else
			i2c->state = STATE_WRITE;

		if (is_lastmsg(i2c) && i2c->msg->len == 0) {
			synquacer_i2c_stop(i2c, 0);
			goto out;
		}

		if (i2c->state == STATE_READ)
			goto prepare_read;

		/* fallthru */

	case STATE_WRITE:
		if (bsr & SYNQUACER_I2C_BSR_LRB) {
			dev_dbg(i2c->dev, "WRITE: No Ack\n");
			synquacer_i2c_stop(i2c, -EAGAIN);
			goto out;
		}

		if (!is_msgend(i2c)) {
			writeb(i2c->msg->buf[i2c->msg_ptr++],
			       i2c->base + SYNQUACER_I2C_REG_DAR);

			/* clear IRQ, and continue */
			writeb(SYNQUACER_I2C_BCR_BEIE |
			       SYNQUACER_I2C_BCR_MSS |
			       SYNQUACER_I2C_BCR_INTE,
			       i2c->base + SYNQUACER_I2C_REG_BCR);
			break;
		}
		if (is_lastmsg(i2c)) {
			synquacer_i2c_stop(i2c, 0);
			break;
		}
		dev_dbg(i2c->dev, "WRITE: Next Message\n");

		i2c->msg_ptr = 0;
		i2c->msg_idx++;
		i2c->msg++;

		/* send the new start */
		ret = synquacer_i2c_master_start(i2c, i2c->msg);
		if (ret < 0) {
			dev_dbg(i2c->dev, "restart error (%d)\n", ret);
			synquacer_i2c_stop(i2c, -EAGAIN);
			break;
		}
		i2c->state = STATE_START;
		break;

	case STATE_READ:
		byte = readb(i2c->base + SYNQUACER_I2C_REG_DAR);
		if (!(bsr & SYNQUACER_I2C_BSR_FBT)) /* data */
			i2c->msg->buf[i2c->msg_ptr++] = byte;
		else /* address */
			dev_dbg(i2c->dev, "address:0x%02x. ignore it.\n", byte);

prepare_read:
		if (is_msglast(i2c)) {
			writeb(SYNQUACER_I2C_BCR_MSS |
			       SYNQUACER_I2C_BCR_BEIE |
			       SYNQUACER_I2C_BCR_INTE,
			       i2c->base + SYNQUACER_I2C_REG_BCR);
			break;
		}
		if (!is_msgend(i2c)) {
			writeb(SYNQUACER_I2C_BCR_MSS |
			       SYNQUACER_I2C_BCR_BEIE |
			       SYNQUACER_I2C_BCR_INTE |
			       SYNQUACER_I2C_BCR_ACK,
			       i2c->base + SYNQUACER_I2C_REG_BCR);
			break;
		}
		if (is_lastmsg(i2c)) {
			/* last message, send stop and complete */
			dev_dbg(i2c->dev, "READ: Send Stop\n");
			synquacer_i2c_stop(i2c, 0);
			break;
		}
		dev_dbg(i2c->dev, "READ: Next Transfer\n");

		i2c->msg_ptr = 0;
		i2c->msg_idx++;
		i2c->msg++;

		ret = synquacer_i2c_master_start(i2c, i2c->msg);
		if (ret < 0) {
			dev_dbg(i2c->dev, "restart error (%d)\n", ret);
			synquacer_i2c_stop(i2c, -EAGAIN);
		} else {
			i2c->state = STATE_START;
		}
		break;
	default:
		dev_err(i2c->dev, "called in err STATE (%d)\n", i2c->state);
		break;
	}

out:
	WAIT_PCLK(10, i2c->pclkrate);
	return IRQ_HANDLED;
}

__attribute__((used)) static int synquacer_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
			      int num)
{
	struct synquacer_i2c *i2c;
	int retry;
	int ret;

	i2c = i2c_get_adapdata(adap);
	i2c->timeout_ms = calc_timeout_ms(i2c, msgs, num);

	dev_dbg(i2c->dev, "calculated timeout %d ms\n", i2c->timeout_ms);

	for (retry = 0; retry <= adap->retries; retry++) {
		ret = synquacer_i2c_doxfer(i2c, msgs, num);
		if (ret != -EAGAIN)
			return ret;

		dev_dbg(i2c->dev, "Retrying transmission (%d)\n", retry);

		synquacer_i2c_hw_reset(i2c);
	}
	return -EIO;
}

__attribute__((used)) static u32 synquacer_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int synquacer_i2c_probe(struct platform_device *pdev)
{
	struct synquacer_i2c *i2c;
	struct resource *r;
	u32 bus_speed;
	int ret;

	i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	bus_speed = i2c_acpi_find_bus_speed(&pdev->dev);
	if (!bus_speed)
		device_property_read_u32(&pdev->dev, "clock-frequency",
					 &bus_speed);

	device_property_read_u32(&pdev->dev, "socionext,pclk-rate",
				 &i2c->pclkrate);

	i2c->pclk = devm_clk_get(&pdev->dev, "pclk");
	if (IS_ERR(i2c->pclk) && PTR_ERR(i2c->pclk) == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (!IS_ERR_OR_NULL(i2c->pclk)) {
		dev_dbg(&pdev->dev, "clock source %p\n", i2c->pclk);

		ret = clk_prepare_enable(i2c->pclk);
		if (ret) {
			dev_err(&pdev->dev, "failed to enable clock (%d)\n",
				ret);
			return ret;
		}
		i2c->pclkrate = clk_get_rate(i2c->pclk);
	}

	if (i2c->pclkrate < SYNQUACER_I2C_MIN_CLK_RATE ||
	    i2c->pclkrate > SYNQUACER_I2C_MAX_CLK_RATE) {
		dev_err(&pdev->dev, "PCLK missing or out of range (%d)\n",
			i2c->pclkrate);
		return -EINVAL;
	}

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c->base = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(i2c->base))
		return PTR_ERR(i2c->base);

	i2c->irq = platform_get_irq(pdev, 0);
	if (i2c->irq < 0) {
		dev_err(&pdev->dev, "no IRQ resource found\n");
		return -ENODEV;
	}

	ret = devm_request_irq(&pdev->dev, i2c->irq, synquacer_i2c_isr,
			       0, dev_name(&pdev->dev), i2c);
	if (ret < 0) {
		dev_err(&pdev->dev, "cannot claim IRQ %d\n", i2c->irq);
		return ret;
	}

	i2c->state = STATE_IDLE;
	i2c->dev = &pdev->dev;
	i2c->adapter = synquacer_i2c_ops;
	i2c_set_adapdata(&i2c->adapter, i2c);
	i2c->adapter.dev.parent = &pdev->dev;
	i2c->adapter.nr = pdev->id;
	init_completion(&i2c->completion);

	if (bus_speed < 400000)
		i2c->speed_khz = SYNQUACER_I2C_SPEED_SM;
	else
		i2c->speed_khz = SYNQUACER_I2C_SPEED_FM;

	synquacer_i2c_hw_init(i2c);

	ret = i2c_add_numbered_adapter(&i2c->adapter);
	if (ret) {
		dev_err(&pdev->dev, "failed to add bus to i2c core\n");
		return ret;
	}

	platform_set_drvdata(pdev, i2c);

	dev_info(&pdev->dev, "%s: synquacer_i2c adapter\n",
		 dev_name(&i2c->adapter.dev));

	return 0;
}

__attribute__((used)) static int synquacer_i2c_remove(struct platform_device *pdev)
{
	struct synquacer_i2c *i2c = platform_get_drvdata(pdev);

	i2c_del_adapter(&i2c->adapter);
	if (!IS_ERR(i2c->pclk))
		clk_disable_unprepare(i2c->pclk);

	return 0;
}

