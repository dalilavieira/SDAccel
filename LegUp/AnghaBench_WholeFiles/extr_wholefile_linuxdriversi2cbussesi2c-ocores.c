#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct ocores_i2c_platform_data {int reg_shift; int reg_io_width; int clock_khz; int big_endian; int num_devices; scalar_t__ devices; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; struct device* parent; } ;
struct TYPE_8__ {TYPE_1__ dev; } ;
struct ocores_i2c {int reg_shift; void (* setreg ) (struct ocores_i2c*,int,int) ;int (* getreg ) (struct ocores_i2c*,int) ;scalar_t__ state; int pos; int nmsgs; int ip_clock_khz; int bus_clock_khz; int reg_io_width; scalar_t__ clk; TYPE_2__ adap; int /*<<< orphan*/  wait; scalar_t__ base; struct i2c_msg* msg; } ;
struct i2c_msg {int flags; int* buf; int len; } ;
struct i2c_adapter {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HZ ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int OCI2C_CMD ; 
 int OCI2C_CMD_IACK ; 
 int OCI2C_CMD_READ_ACK ; 
 int OCI2C_CMD_READ_NACK ; 
 int OCI2C_CMD_START ; 
 int OCI2C_CMD_STOP ; 
 int OCI2C_CMD_WRITE ; 
 int OCI2C_CONTROL ; 
 int OCI2C_CTRL_EN ; 
 int OCI2C_CTRL_IEN ; 
 int OCI2C_DATA ; 
 int OCI2C_PREHIGH ; 
 int OCI2C_PRELOW ; 
 int OCI2C_STATUS ; 
 int OCI2C_STAT_ARBLOST ; 
 int OCI2C_STAT_NACK ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ STATE_DONE ; 
 scalar_t__ STATE_ERROR ; 
 scalar_t__ STATE_READ ; 
 scalar_t__ STATE_START ; 
 scalar_t__ STATE_WRITE ; 
 int abs (int) ; 
 int clamp (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct ocores_i2c_platform_data* dev_get_platdata (struct device*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct ocores_i2c* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ocores_i2c*) ; 
 int i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 struct ocores_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_new_device (TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_2__*,struct ocores_i2c*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int ioread16 (scalar_t__) ; 
 int ioread16be (scalar_t__) ; 
 int ioread32 (scalar_t__) ; 
 int ioread32be (scalar_t__) ; 
 int ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite16 (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite16be (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (int,scalar_t__) ; 
 TYPE_2__ ocores_adapter ; 
 int ocores_i2c_of_probe (struct platform_device*,struct ocores_i2c*) ; 
 int of_device_is_big_endian (int /*<<< orphan*/ ) ; 
 struct ocores_i2c* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ocores_i2c*) ; 
 void stub1 (struct ocores_i2c*,int,int) ; 
 int stub2 (struct ocores_i2c*,int) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void oc_setreg_8(struct ocores_i2c *i2c, int reg, u8 value)
{
	iowrite8(value, i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static void oc_setreg_16(struct ocores_i2c *i2c, int reg, u8 value)
{
	iowrite16(value, i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static void oc_setreg_32(struct ocores_i2c *i2c, int reg, u8 value)
{
	iowrite32(value, i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static void oc_setreg_16be(struct ocores_i2c *i2c, int reg, u8 value)
{
	iowrite16be(value, i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static void oc_setreg_32be(struct ocores_i2c *i2c, int reg, u8 value)
{
	iowrite32be(value, i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline u8 oc_getreg_8(struct ocores_i2c *i2c, int reg)
{
	return ioread8(i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline u8 oc_getreg_16(struct ocores_i2c *i2c, int reg)
{
	return ioread16(i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline u8 oc_getreg_32(struct ocores_i2c *i2c, int reg)
{
	return ioread32(i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline u8 oc_getreg_16be(struct ocores_i2c *i2c, int reg)
{
	return ioread16be(i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline u8 oc_getreg_32be(struct ocores_i2c *i2c, int reg)
{
	return ioread32be(i2c->base + (reg << i2c->reg_shift));
}

__attribute__((used)) static inline void oc_setreg(struct ocores_i2c *i2c, int reg, u8 value)
{
	i2c->setreg(i2c, reg, value);
}

__attribute__((used)) static inline u8 oc_getreg(struct ocores_i2c *i2c, int reg)
{
	return i2c->getreg(i2c, reg);
}

__attribute__((used)) static void ocores_process(struct ocores_i2c *i2c)
{
	struct i2c_msg *msg = i2c->msg;
	u8 stat = oc_getreg(i2c, OCI2C_STATUS);

	if ((i2c->state == STATE_DONE) || (i2c->state == STATE_ERROR)) {
		/* stop has been sent */
		oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_IACK);
		wake_up(&i2c->wait);
		return;
	}

	/* error? */
	if (stat & OCI2C_STAT_ARBLOST) {
		i2c->state = STATE_ERROR;
		oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
		return;
	}

	if ((i2c->state == STATE_START) || (i2c->state == STATE_WRITE)) {
		i2c->state =
			(msg->flags & I2C_M_RD) ? STATE_READ : STATE_WRITE;

		if (stat & OCI2C_STAT_NACK) {
			i2c->state = STATE_ERROR;
			oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
			return;
		}
	} else
		msg->buf[i2c->pos++] = oc_getreg(i2c, OCI2C_DATA);

	/* end of msg? */
	if (i2c->pos == msg->len) {
		i2c->nmsgs--;
		i2c->msg++;
		i2c->pos = 0;
		msg = i2c->msg;

		if (i2c->nmsgs) {	/* end? */
			/* send start? */
			if (!(msg->flags & I2C_M_NOSTART)) {
				u8 addr = i2c_8bit_addr_from_msg(msg);

				i2c->state = STATE_START;

				oc_setreg(i2c, OCI2C_DATA, addr);
				oc_setreg(i2c, OCI2C_CMD,  OCI2C_CMD_START);
				return;
			} else
				i2c->state = (msg->flags & I2C_M_RD)
					? STATE_READ : STATE_WRITE;
		} else {
			i2c->state = STATE_DONE;
			oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
			return;
		}
	}

	if (i2c->state == STATE_READ) {
		oc_setreg(i2c, OCI2C_CMD, i2c->pos == (msg->len-1) ?
			  OCI2C_CMD_READ_NACK : OCI2C_CMD_READ_ACK);
	} else {
		oc_setreg(i2c, OCI2C_DATA, msg->buf[i2c->pos++]);
		oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_WRITE);
	}
}

__attribute__((used)) static irqreturn_t ocores_isr(int irq, void *dev_id)
{
	struct ocores_i2c *i2c = dev_id;

	ocores_process(i2c);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ocores_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	struct ocores_i2c *i2c = i2c_get_adapdata(adap);

	i2c->msg = msgs;
	i2c->pos = 0;
	i2c->nmsgs = num;
	i2c->state = STATE_START;

	oc_setreg(i2c, OCI2C_DATA, i2c_8bit_addr_from_msg(i2c->msg));
	oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_START);

	if (wait_event_timeout(i2c->wait, (i2c->state == STATE_ERROR) ||
			       (i2c->state == STATE_DONE), HZ))
		return (i2c->state == STATE_DONE) ? num : -EIO;
	else
		return -ETIMEDOUT;
}

__attribute__((used)) static int ocores_init(struct device *dev, struct ocores_i2c *i2c)
{
	int prescale;
	int diff;
	u8 ctrl = oc_getreg(i2c, OCI2C_CONTROL);

	/* make sure the device is disabled */
	oc_setreg(i2c, OCI2C_CONTROL, ctrl & ~(OCI2C_CTRL_EN|OCI2C_CTRL_IEN));

	prescale = (i2c->ip_clock_khz / (5 * i2c->bus_clock_khz)) - 1;
	prescale = clamp(prescale, 0, 0xffff);

	diff = i2c->ip_clock_khz / (5 * (prescale + 1)) - i2c->bus_clock_khz;
	if (abs(diff) > i2c->bus_clock_khz / 10) {
		dev_err(dev,
			"Unsupported clock settings: core: %d KHz, bus: %d KHz\n",
			i2c->ip_clock_khz, i2c->bus_clock_khz);
		return -EINVAL;
	}

	oc_setreg(i2c, OCI2C_PRELOW, prescale & 0xff);
	oc_setreg(i2c, OCI2C_PREHIGH, prescale >> 8);

	/* Init the device */
	oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_IACK);
	oc_setreg(i2c, OCI2C_CONTROL, ctrl | OCI2C_CTRL_IEN | OCI2C_CTRL_EN);

	return 0;
}

__attribute__((used)) static u32 ocores_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int ocores_i2c_probe(struct platform_device *pdev)
{
	struct ocores_i2c *i2c;
	struct ocores_i2c_platform_data *pdata;
	struct resource *res;
	int irq;
	int ret;
	int i;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(i2c->base))
		return PTR_ERR(i2c->base);

	pdata = dev_get_platdata(&pdev->dev);
	if (pdata) {
		i2c->reg_shift = pdata->reg_shift;
		i2c->reg_io_width = pdata->reg_io_width;
		i2c->ip_clock_khz = pdata->clock_khz;
		i2c->bus_clock_khz = 100;
	} else {
		ret = ocores_i2c_of_probe(pdev, i2c);
		if (ret)
			return ret;
	}

	if (i2c->reg_io_width == 0)
		i2c->reg_io_width = 1; /* Set to default value */

	if (!i2c->setreg || !i2c->getreg) {
		bool be = pdata ? pdata->big_endian :
			of_device_is_big_endian(pdev->dev.of_node);

		switch (i2c->reg_io_width) {
		case 1:
			i2c->setreg = oc_setreg_8;
			i2c->getreg = oc_getreg_8;
			break;

		case 2:
			i2c->setreg = be ? oc_setreg_16be : oc_setreg_16;
			i2c->getreg = be ? oc_getreg_16be : oc_getreg_16;
			break;

		case 4:
			i2c->setreg = be ? oc_setreg_32be : oc_setreg_32;
			i2c->getreg = be ? oc_getreg_32be : oc_getreg_32;
			break;

		default:
			dev_err(&pdev->dev, "Unsupported I/O width (%d)\n",
				i2c->reg_io_width);
			ret = -EINVAL;
			goto err_clk;
		}
	}

	ret = ocores_init(&pdev->dev, i2c);
	if (ret)
		goto err_clk;

	init_waitqueue_head(&i2c->wait);
	ret = devm_request_irq(&pdev->dev, irq, ocores_isr, 0,
			       pdev->name, i2c);
	if (ret) {
		dev_err(&pdev->dev, "Cannot claim IRQ\n");
		goto err_clk;
	}

	/* hook up driver to tree */
	platform_set_drvdata(pdev, i2c);
	i2c->adap = ocores_adapter;
	i2c_set_adapdata(&i2c->adap, i2c);
	i2c->adap.dev.parent = &pdev->dev;
	i2c->adap.dev.of_node = pdev->dev.of_node;

	/* add i2c adapter to i2c tree */
	ret = i2c_add_adapter(&i2c->adap);
	if (ret)
		goto err_clk;

	/* add in known devices to the bus */
	if (pdata) {
		for (i = 0; i < pdata->num_devices; i++)
			i2c_new_device(&i2c->adap, pdata->devices + i);
	}

	return 0;

err_clk:
	clk_disable_unprepare(i2c->clk);
	return ret;
}

__attribute__((used)) static int ocores_i2c_remove(struct platform_device *pdev)
{
	struct ocores_i2c *i2c = platform_get_drvdata(pdev);

	/* disable i2c logic */
	oc_setreg(i2c, OCI2C_CONTROL, oc_getreg(i2c, OCI2C_CONTROL)
		  & ~(OCI2C_CTRL_EN|OCI2C_CTRL_IEN));

	/* remove adapter & data */
	i2c_del_adapter(&i2c->adap);

	if (!IS_ERR(i2c->clk))
		clk_disable_unprepare(i2c->clk);

	return 0;
}

