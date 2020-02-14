#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_12__ {struct device_node* of_node; } ;
struct platform_device {TYPE_4__ dev; } ;
struct i2c_msg {int addr; int flags; int* buf; scalar_t__ len; } ;
struct i2c_adapter {struct dc_i2c* algo_data; } ;
struct device_node {int dummy; } ;
struct TYPE_10__ {struct device_node* of_node; TYPE_4__* parent; } ;
struct TYPE_11__ {struct dc_i2c* algo_data; TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct dc_i2c {scalar_t__ msgbuf_ptr; int state; int last; int error; int frequency; scalar_t__ clk; TYPE_2__ adap; scalar_t__ regs; int /*<<< orphan*/  done; int /*<<< orphan*/  lock; TYPE_4__* dev; struct i2c_msg* msg; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int DEFAULT_FREQ ; 
 unsigned int DIV_ROUND_UP (unsigned long,int) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_NOSTART ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 scalar_t__ II_CLOCKTIME ; 
 int II_CMD_GET_ACK ; 
 int II_CMD_GET_NOACK ; 
 int II_CMD_RESTART ; 
 int II_CMD_SEND_ACK ; 
 int II_CMD_START ; 
 int II_CMD_STATUS_ABORT ; 
 int II_CMD_STATUS_ACK_BAD ; 
 int II_CMD_STOP ; 
 scalar_t__ II_COMMAND ; 
 int II_COMMAND_COMPLETION_STATUS (int) ; 
 int II_COMMAND_GO ; 
 scalar_t__ II_CONTROL ; 
 unsigned int II_CONTROL_LOCAL_RESET ; 
 scalar_t__ II_DATA ; 
 scalar_t__ II_INTENABLE ; 
 scalar_t__ II_INTFLAG_CLEAR ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
#define  STATE_ADDR 132 
 void* STATE_IDLE ; 
#define  STATE_READ 131 
#define  STATE_START 130 
#define  STATE_STOP 129 
#define  STATE_WRITE 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  TIMEOUT_MS ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dc_i2c_algorithm ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 int /*<<< orphan*/  dev_name (TYPE_4__*) ; 
 scalar_t__ devm_clk_get (TYPE_4__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_4__*,struct resource*) ; 
 struct dc_i2c* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_4__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dc_i2c*) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct dc_i2c* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct dc_i2c*) ; 
 int readb_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writeb_relaxed (unsigned int,scalar_t__) ; 

__attribute__((used)) static void dc_i2c_cmd(struct dc_i2c *i2c, u8 cmd)
{
	writeb_relaxed(cmd | II_COMMAND_GO, i2c->regs + II_COMMAND);
}

__attribute__((used)) static u8 dc_i2c_addr_cmd(struct i2c_msg *msg)
{
	u8 addr = (msg->addr & 0x7f) << 1;

	if (msg->flags & I2C_M_RD)
		addr |= 1;

	return addr;
}

__attribute__((used)) static void dc_i2c_data(struct dc_i2c *i2c, u8 data)
{
	writeb_relaxed(data, i2c->regs + II_DATA);
}

__attribute__((used)) static void dc_i2c_write_byte(struct dc_i2c *i2c, u8 byte)
{
	dc_i2c_data(i2c, byte);
	dc_i2c_cmd(i2c, II_CMD_SEND_ACK);
}

__attribute__((used)) static void dc_i2c_write_buf(struct dc_i2c *i2c)
{
	dc_i2c_write_byte(i2c, i2c->msg->buf[i2c->msgbuf_ptr++]);
}

__attribute__((used)) static void dc_i2c_next_read(struct dc_i2c *i2c)
{
	bool last = (i2c->msgbuf_ptr + 1 == i2c->msg->len);

	dc_i2c_cmd(i2c, last ? II_CMD_GET_NOACK : II_CMD_GET_ACK);
}

__attribute__((used)) static void dc_i2c_stop(struct dc_i2c *i2c)
{
	i2c->state = STATE_STOP;
	if (i2c->last)
		dc_i2c_cmd(i2c, II_CMD_STOP);
	else
		complete(&i2c->done);
}

__attribute__((used)) static u8 dc_i2c_read_byte(struct dc_i2c *i2c)
{
	return readb_relaxed(i2c->regs + II_DATA);
}

__attribute__((used)) static void dc_i2c_read_buf(struct dc_i2c *i2c)
{
	i2c->msg->buf[i2c->msgbuf_ptr++] = dc_i2c_read_byte(i2c);
	dc_i2c_next_read(i2c);
}

__attribute__((used)) static void dc_i2c_set_irq(struct dc_i2c *i2c, int enable)
{
	if (enable)
		writeb_relaxed(1, i2c->regs + II_INTFLAG_CLEAR);
	writeb_relaxed(!!enable, i2c->regs + II_INTENABLE);
}

__attribute__((used)) static int dc_i2c_cmd_status(struct dc_i2c *i2c)
{
	u8 cmd = readb_relaxed(i2c->regs + II_COMMAND);

	return II_COMMAND_COMPLETION_STATUS(cmd);
}

__attribute__((used)) static void dc_i2c_start_msg(struct dc_i2c *i2c, int first)
{
	struct i2c_msg *msg = i2c->msg;

	if (!(msg->flags & I2C_M_NOSTART)) {
		i2c->state = STATE_START;
		dc_i2c_cmd(i2c, first ? II_CMD_START : II_CMD_RESTART);
	} else if (msg->flags & I2C_M_RD) {
		i2c->state = STATE_READ;
		dc_i2c_next_read(i2c);
	} else {
		i2c->state = STATE_WRITE;
		dc_i2c_write_buf(i2c);
	}
}

__attribute__((used)) static irqreturn_t dc_i2c_irq(int irq, void *dev_id)
{
	struct dc_i2c *i2c = dev_id;
	int cmd_status = dc_i2c_cmd_status(i2c);
	unsigned long flags;
	u8 addr_cmd;

	writeb_relaxed(1, i2c->regs + II_INTFLAG_CLEAR);

	spin_lock_irqsave(&i2c->lock, flags);

	if (cmd_status == II_CMD_STATUS_ACK_BAD
	    || cmd_status == II_CMD_STATUS_ABORT) {
		i2c->error = -EIO;
		complete(&i2c->done);
		goto out;
	}

	switch (i2c->state) {
	case STATE_START:
		addr_cmd = dc_i2c_addr_cmd(i2c->msg);
		dc_i2c_write_byte(i2c, addr_cmd);
		i2c->state = STATE_ADDR;
		break;
	case STATE_ADDR:
		if (i2c->msg->flags & I2C_M_RD) {
			dc_i2c_next_read(i2c);
			i2c->state = STATE_READ;
			break;
		}
		i2c->state = STATE_WRITE;
		/* fall through */
	case STATE_WRITE:
		if (i2c->msgbuf_ptr < i2c->msg->len)
			dc_i2c_write_buf(i2c);
		else
			dc_i2c_stop(i2c);
		break;
	case STATE_READ:
		if (i2c->msgbuf_ptr < i2c->msg->len)
			dc_i2c_read_buf(i2c);
		else
			dc_i2c_stop(i2c);
		break;
	case STATE_STOP:
		i2c->state = STATE_IDLE;
		complete(&i2c->done);
		break;
	}

out:
	spin_unlock_irqrestore(&i2c->lock, flags);
	return IRQ_HANDLED;
}

__attribute__((used)) static int dc_i2c_xfer_msg(struct dc_i2c *i2c, struct i2c_msg *msg, int first,
			   int last)
{
	unsigned long timeout = msecs_to_jiffies(TIMEOUT_MS);
	unsigned long flags;

	spin_lock_irqsave(&i2c->lock, flags);
	i2c->msg = msg;
	i2c->msgbuf_ptr = 0;
	i2c->last = last;
	i2c->error = 0;

	reinit_completion(&i2c->done);
	dc_i2c_set_irq(i2c, 1);
	dc_i2c_start_msg(i2c, first);
	spin_unlock_irqrestore(&i2c->lock, flags);

	timeout = wait_for_completion_timeout(&i2c->done, timeout);
	dc_i2c_set_irq(i2c, 0);
	if (timeout == 0) {
		i2c->state = STATE_IDLE;
		return -ETIMEDOUT;
	}

	if (i2c->error)
		return i2c->error;

	return 0;
}

__attribute__((used)) static int dc_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	struct dc_i2c *i2c = adap->algo_data;
	int i, ret;

	for (i = 0; i < num; i++) {
		ret = dc_i2c_xfer_msg(i2c, &msgs[i], i == 0, i == num - 1);
		if (ret)
			return ret;
	}

	return num;
}

__attribute__((used)) static int dc_i2c_init_hw(struct dc_i2c *i2c)
{
	unsigned long clk_rate = clk_get_rate(i2c->clk);
	unsigned int clocktime;

	writeb_relaxed(II_CONTROL_LOCAL_RESET, i2c->regs + II_CONTROL);
	udelay(100);
	writeb_relaxed(0, i2c->regs + II_CONTROL);
	udelay(100);

	clocktime = DIV_ROUND_UP(clk_rate, 64 * i2c->frequency);
	if (clocktime < 1 || clocktime > 0xff) {
		dev_err(i2c->dev, "can't set bus speed of %u Hz\n",
			i2c->frequency);
		return -EINVAL;
	}
	writeb_relaxed(clocktime - 1, i2c->regs + II_CLOCKTIME);

	return 0;
}

__attribute__((used)) static u32 dc_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_NOSTART;
}

__attribute__((used)) static int dc_i2c_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct dc_i2c *i2c;
	struct resource *r;
	int ret = 0, irq;

	i2c = devm_kzalloc(&pdev->dev, sizeof(struct dc_i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	if (of_property_read_u32(pdev->dev.of_node, "clock-frequency",
				 &i2c->frequency))
		i2c->frequency = DEFAULT_FREQ;

	i2c->dev = &pdev->dev;
	platform_set_drvdata(pdev, i2c);

	spin_lock_init(&i2c->lock);
	init_completion(&i2c->done);

	i2c->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(i2c->clk))
		return PTR_ERR(i2c->clk);

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c->regs = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(i2c->regs))
		return PTR_ERR(i2c->regs);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	ret = devm_request_irq(&pdev->dev, irq, dc_i2c_irq, 0,
			       dev_name(&pdev->dev), i2c);
	if (ret < 0)
		return ret;

	strlcpy(i2c->adap.name, "Conexant Digicolor I2C adapter",
		sizeof(i2c->adap.name));
	i2c->adap.owner = THIS_MODULE;
	i2c->adap.algo = &dc_i2c_algorithm;
	i2c->adap.dev.parent = &pdev->dev;
	i2c->adap.dev.of_node = np;
	i2c->adap.algo_data = i2c;

	ret = dc_i2c_init_hw(i2c);
	if (ret)
		return ret;

	ret = clk_prepare_enable(i2c->clk);
	if (ret < 0)
		return ret;

	ret = i2c_add_adapter(&i2c->adap);
	if (ret < 0) {
		clk_disable_unprepare(i2c->clk);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int dc_i2c_remove(struct platform_device *pdev)
{
	struct dc_i2c *i2c = platform_get_drvdata(pdev);

	i2c_del_adapter(&i2c->adap);
	clk_disable_unprepare(i2c->clk);

	return 0;
}

